% / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 
% / / / DEPRECATED / / / DEPRECATED / / / DEPRECATED / / / DEPRECATED / / /
% / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 
function [out,aux] = eval_obj(in, len_idx_n, len_idx_e, defines)

USE_EXP_SOFT_COST = defines(1);
USE_OCC_GRAD_AS_GUIDANCE = defines(2);

% DEFINE INPUTS -- this is just simply easier to read.. */
    
idx_shift = 0;
% if (endterm_eval) idx_shift = -ACADO_NU; % this is an end term evaluation - dont consider the controls

% states */
r_n = in(1+0);
r_e = in(1+1);
r_d = in(1+2);
v = in(1+3);
gamma = in(1+4);
xi = in(1+5);
phi = in(1+6);
theta = in(1+7);
n_p = in(1+8);

% controls */ % NOTE: these just dont get used if in end term eval
u_T = in(1+9);
phi_ref = in(1+10);
theta_ref = in(1+11);

% online data */

% environment
%rho = in(1+12-idx_shift);

% disturbances
w_n = in(1+13-idx_shift);
w_e = in(1+14-idx_shift);
w_d = in(1+15-idx_shift);

% path reference
b_n = in(1+16-idx_shift);
b_e = in(1+17-idx_shift);
b_d = in(1+18-idx_shift);
Gamma_p = in(1+19-idx_shift);
chi_p = in(1+20-idx_shift);

% guidance
T_b_lat = in(1+21-idx_shift);
T_b_lon = in(1+22-idx_shift);
gamma_app_max = in(1+23-idx_shift);

% control augmented attitude time constants and gains
% tau_phi = in(1+24-idx_shift);
% tau_theta = in(1+25-idx_shift);
% k_phi = in(1+26-idx_shift);
% k_theta = in(1+27-idx_shift);

% angle of attack soft constraint
delta_aoa = in(1+28-idx_shift);
aoa_m = in(1+29-idx_shift);
aoa_p = in(1+30-idx_shift);
log_sqrt_w_over_sig1_aoa = in(1+31-idx_shift);
one_over_sqrt_w_aoa = in(1+32-idx_shift);

% height soft constraint 
h_offset = in(1+33-idx_shift);
delta_h = in(1+34-idx_shift);
delta_y = in(1+35-idx_shift);
log_sqrt_w_over_sig1_h = in(1+36-idx_shift);
one_over_sqrt_w_h = in(1+37-idx_shift);

% radial soft constraint
r_offset = in(1+38-idx_shift);
delta_r0 = in(1+39-idx_shift);
k_r = in(1+40-idx_shift);
log_sqrt_w_over_sig1_r = in(1+41-idx_shift);
one_over_sqrt_w_r = in(1+42-idx_shift);

% terrain lookup
terr_local_origin_n = in(1+43-idx_shift);
terr_local_origin_e = in(1+44-idx_shift);
terr_dis = in(1+45-idx_shift);
%terrain_data = in(1+46-idx_shift);
IDX_TERR_DATA = 1+46-idx_shift;
 
% INTERMEDIATE CALCULATIONS */ 
 
% ground speed */
v_cos_gamma = v*cos(gamma);
cos_xi = cos(xi);
sin_xi = sin(xi);
v_n = v_cos_gamma*cos_xi;
v_e = v_cos_gamma*sin_xi;
v_d = -v*sin(gamma);
vG_n = v_n + w_n;
vG_e = v_e + w_e;
vG_d = v_d + w_d;
vG_sq = vG_n*vG_n + vG_e*vG_e + vG_d*vG_d;
vG_norm = sqrt(vG_sq);

% unit ground speed */
if (vG_norm < 0.01)
    one_over_vG_norm = 100.0;
else
    one_over_vG_norm = 1.0 / vG_norm;
end
vG_n_unit = vG_n * one_over_vG_norm;
vG_e_unit = vG_e * one_over_vG_norm;
vG_d_unit = vG_d * one_over_vG_norm;

    % TERRAIN - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

% cast ray along ground speed vector to check for occlusions

% unit ray vector
v_ray = [vG_e_unit; vG_n_unit; -vG_d_unit]; % in ENU

% radial buffer zone
delta_r = vG_sq * k_r + delta_r0;

% adjusted radial offset
r_offset_1 = vG_sq * k_r + r_offset;

% ray length
d_ray = delta_r + r_offset_1 + terr_dis;

% ray start ENU
r0 = [r_e; r_n; -r_d];
% ray end ENU
r1 = [r0(1) + v_ray(1) * d_ray; r0(2) + v_ray(2) * d_ray; r0(3) + v_ray(3) * d_ray];

[occ_detected, d_occ, p_occ, p1, p2, p3] = castray(r0, r1, v_ray, ...
    terr_local_origin_n, terr_local_origin_e, len_idx_n, len_idx_e, terr_dis, in(IDX_TERR_DATA:end));
p1(1) = p1(1) + terr_local_origin_e;
p1(2) = p1(2) + terr_local_origin_n;
p2(1) = p2(1) + terr_local_origin_e;
p2(2) = p2(2) + terr_local_origin_n;
p3(1) = p3(1) + terr_local_origin_e;
p3(2) = p3(2) + terr_local_origin_n;
p_occ(1) = p_occ(1) + terr_local_origin_e;
p_occ(2) = p_occ(2) + terr_local_origin_n;

% SOFT CONSTRAINTS - - - - - - - - - - - - - - - - - - - - - - - - -*/
    
    % angle of attack */
    aoa = theta - gamma;
    sig_aoa = 0.0;
    prio_aoa = 1.0;
    jac_sig_aoa = [0.0, 0.0];
    
    % height */
    h = -r_d;
    sig_h = 0.0;
    sig_h_temp = 0.0;
    prio_h = 1.0;
    jac_sig_h = [0.0, 0.0, 0.0, 0.0];
    jac_sig_h_temp = [0.0, 0.0, 0.0, 0.0];
    
    % radial cost */
    sig_r = 0.0;
    prio_r = 1.0;
    jac_sig_r = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0];

if USE_EXP_SOFT_COST % EXPONENTIAL COST */
    
    % angle of attack objective / jacobian - - - - - - - - - - - - - - -*/
    
    if ~(one_over_sqrt_w_aoa<0.0)
    
        % positive bound */
        sig_aoa_p = exp((aoa - aoa_p)/delta_aoa*log_sqrt_w_over_sig1_aoa);

        % negative bound */
        sig_aoa_m = exp(-(aoa - aoa_m)/delta_aoa*log_sqrt_w_over_sig1_aoa);

        % combined */
        sig_aoa = sig_aoa_p + sig_aoa_m;

    %     % jacobian */
    %     jac_sig_aoa_exp(jac_sig_aoa, delta_aoa, log_sqrt_w_over_sig1_aoa, ...
    %         sig_aoa_m, sig_aoa_p);

        % prioritization */
        prio_aoa = 1.0; %1.0 - ((sig_aoa*one_over_sqrt_w_aoa > 1.0) ? 1.0 : sig_aoa*one_over_sqrt_w_aoa);*/
    end

    
    % height objective / jacobian - - - - - - - - - - - - - - - - - - - */
    
    if ~(one_over_sqrt_w_h<0.0)
        
        % lookup 2.5d grid (CENTER) */
        sgn_n = 0.0;
        sgn_e = 0.0;
        [idx_q, dn, de] = lookup_terrain_idx(r_n, r_e, terr_local_origin_n, terr_local_origin_e, terr_dis);
        % bi-linear interpolation */
        h12 = (1-dn)*in(IDX_TERR_DATA+idx_q(1)) + dn*in(IDX_TERR_DATA+idx_q(2));
        h34 = (1-dn)*in(IDX_TERR_DATA+idx_q(3)) + dn*in(IDX_TERR_DATA+idx_q(4));
        h_terr = (1-de)*h12 + de*h34;
        % objective / jacobian */
        sig_h = exp(-(h - h_terr - h_offset)/delta_h*log_sqrt_w_over_sig1_h);
    %     jac_sig_h_exp(jac_sig_h,
    %         de, delta_h, delta_y,
    %         in(IDX_TERR_DATA+idx_q(1)), h12, in(IDX_TERR_DATA+idx_q(2)), in(IDX_TERR_DATA+idx_q(3)),
    %         h34, in(IDX_TERR_DATA+idx_q(4)), log_sqrt_w_over_sig1_h,
    %         sgn_e, sgn_n, sig_h,
    %         terr_dis, xi);

        % lookup 2.5d grid (LEFT side) */
        sgn_n = 1.0;
        sgn_e = -1.0;
        [idx_q, dn, de] = lookup_terrain_idx(r_n + sgn_n*sin_xi * delta_y, r_e + sgn_e*cos_xi * delta_y, terr_local_origin_n, terr_local_origin_e, terr_dis);
        % bi-linear interpolation */
        h12 = (1-dn)*in(IDX_TERR_DATA+idx_q(1)) + dn*in(IDX_TERR_DATA+idx_q(2));
        h34 = (1-dn)*in(IDX_TERR_DATA+idx_q(3)) + dn*in(IDX_TERR_DATA+idx_q(4));
        h_terr = (1-de)*h12 + de*h34;
        % objective / jacobian */
        sig_h_temp = exp(-(h - h_terr - h_offset)/delta_h*log_sqrt_w_over_sig1_h);
    %     jac_sig_h_exp(jac_sig_h_temp,
    %         de, delta_h, delta_y,
    %         in(IDX_TERR_DATA+idx_q(1)), h12, in(IDX_TERR_DATA+idx_q(2)), in(IDX_TERR_DATA+idx_q(3)),
    %         h34, in(IDX_TERR_DATA+idx_q(4)), log_sqrt_w_over_sig1_h,
    %         sgn_e, sgn_n, sig_h_temp,
    %         terr_dis, xi);
        sig_h = sig_h + sig_h_temp;
    %     jac_sig_h(1) += jac_sig_h_temp(1);
    %     jac_sig_h(2) += jac_sig_h_temp(2);
    %     jac_sig_h(3) += jac_sig_h_temp(3);
    %     jac_sig_h(4) += jac_sig_h_temp(4);

        % lookup 2.5d grid (RIGHT side) */
        sgn_n = -1.0;
        sgn_e = 1.0;
        [idx_q, dn, de] = lookup_terrain_idx(r_n + sgn_n*sin_xi * delta_y, r_e + sgn_e*cos_xi * delta_y, terr_local_origin_n, terr_local_origin_e, terr_dis);
        % bi-linear interpolation */
        h12 = (1-dn)*in(IDX_TERR_DATA+idx_q(1)) + dn*in(IDX_TERR_DATA+idx_q(2));
        h34 = (1-dn)*in(IDX_TERR_DATA+idx_q(3)) + dn*in(IDX_TERR_DATA+idx_q(4));
        h_terr = (1-de)*h12 + de*h34;
        % objective / jacobian */
        sig_h_temp = exp(-(h - h_terr - h_offset)/delta_h*log_sqrt_w_over_sig1_h);
    %     jac_sig_h_exp(jac_sig_h_temp,
    %         de, delta_h, delta_y,
    %         in(IDX_TERR_DATA+idx_q(1)), h12, in(IDX_TERR_DATA+idx_q(2)), in(IDX_TERR_DATA+idx_q(3)),
    %         h34, in(IDX_TERR_DATA+idx_q(4)), log_sqrt_w_over_sig1_h,
    %         sgn_e, sgn_n, sig_h_temp,
    %         terr_dis, xi);
        sig_h = sig_h + sig_h_temp;
    %     jac_sig_h(1) += jac_sig_h_temp(1);
    %     jac_sig_h(2) += jac_sig_h_temp(2);
    %     jac_sig_h(3) += jac_sig_h_temp(3);
    %     jac_sig_h(4) += jac_sig_h_temp(4);

        % prioritization */
        prio_h = 1.0 - min(sig_h*one_over_sqrt_w_h, 1.0);
    else
        [idx_q, dn, de] = lookup_terrain_idx(r_n, r_e, terr_local_origin_n, terr_local_origin_e, terr_dis);
        % bi-linear interpolation */
        h12 = (1-dn)*in(IDX_TERR_DATA+idx_q(1)) + dn*in(IDX_TERR_DATA+idx_q(2));
        h34 = (1-dn)*in(IDX_TERR_DATA+idx_q(3)) + dn*in(IDX_TERR_DATA+idx_q(4));
        h_terr = (1-de)*h12 + de*h34;
    end

    
    % radial objective / jacobian - - - - - - - - - - - - - - - - - - - */
    
    if ~(one_over_sqrt_w_r<0.0) && occ_detected>0
        
        % objective */
        sig_r = exp(-(d_occ - r_offset_1)/delta_r*log_sqrt_w_over_sig1_r);

        % prioritization */
        prio_r = 1.0 - min(sig_r*one_over_sqrt_w_r, 1.0);

        % jacobian */
        if (occ_detected==2)
            jac_sig_r = jac_sig_r_tl_exp( ...
                r_n, r_e, r_d, ...
                v, gamma, xi, ...
                w_e, w_n, w_d, ...
                terr_dis, ...
                p1(1), p1(2), p1(3), ...
                p2(1), p2(2), p2(3), ...
                p3(1), p3(2), p3(3), ...
                r_offset, delta_r0, k_r, ...
                log_sqrt_w_over_sig1_r, sig_r, ...
                d_occ, delta_r, ...
                vG_sq, vG_norm, ...
                vG_n, vG_e, vG_d);
        elseif (occ_detected==1)
            jac_sig_r = jac_sig_r_br_exp( ...
                r_n, r_e, r_d, ...
                v, gamma, xi, ...
                w_e, w_n, w_d, ...
                terr_dis, ...
                p1(1), p1(2), p1(3), ...
                p2(1), p2(2), p2(3), ...
                p3(1), p3(2), p3(3), ...
                r_offset, delta_r0, k_r, ...
                log_sqrt_w_over_sig1_r, sig_r, ...
                d_occ, delta_r, ...
                vG_sq, vG_norm, ...
                vG_n, vG_e, vG_d);
        end
        jac_sig_r(4) = 0.0;
        jac_sig_r(5) = 0.0;
        jac_sig_r(6) = 0.0;
    else
        d_occ = NaN; % for plotting
    end
    
    
else % CUBIC COST */
    
    % angle of attack objective / jacobian - - - - - - - - - - - - - - -*/
    
    % positive bound */
    if (aoa_p - aoa < delta_aoa)
        sig_aoa = (delta_aoa - (aoa_p - aoa)) / delta_aoa;
        sig_aoa = sig_aoa * sig_aoa * sig_aoa;
        jac_sig_aoa_p_cubic(jac_sig_aoa, aoa, aoa_p, delta_aoa);
    end
    % negative bound */
    if (aoa - aoa_m < delta_aoa)
        sig_aoa = (delta_aoa - (aoa - aoa_m)) / delta_aoa;
        sig_aoa = sig_aoa * sig_aoa * sig_aoa;
        jac_sig_aoa_m_cubic(jac_sig_aoa, aoa, aoa_m, delta_aoa);
    end
    % prioritization */
    prio_aoa = 1.0;%1.0 - ((sig_aoa > 1.0) ? 1.0 : sig_aoa); */
    
    
    % height objective / jacobian - - - - - - - - - - - - - - - - - - - */

    % lookup 2.5d grid (CENTER) */
    one_over_deltah = 1.0 / delta_h;
    sgn_n = 0.0;
    sgn_e = 0.0;
    [idx_q, dn, de] = lookup_terrain_idx(r_n, r_e, terr_local_origin_n, terr_local_origin_e, terr_dis);
    % bi-linear interpolation */
    h12 = (1-dn)*in(IDX_TERR_DATA+idx_q(1)) + dn*in(IDX_TERR_DATA+idx_q(2));
    h34 = (1-dn)*in(IDX_TERR_DATA+idx_q(3)) + dn*in(IDX_TERR_DATA+idx_q(4));
    h_terr = (1-de)*h12 + de*h34;
    % objective / jacobian */
    arg_sig_h = delta_h - (h - h_terr - h_offset);
    if (arg_sig_h > 0.0)
        sig_h = arg_sig_h * one_over_deltah;
        sig_h = sig_h * sig_h * sig_h;
%         jac_sig_h_cubic(jac_sig_h,
%             de, delta_h, delta_y,
%             in(IDX_TERR_DATA+idx_q(1)), h12, in(IDX_TERR_DATA+idx_q(2)), in(IDX_TERR_DATA+idx_q(3)),
%             h34, in(IDX_TERR_DATA+idx_q(4)), h_offset,
%             r_d, sgn_e, sgn_n,
%             terr_dis, xi);
    end
    
    % lookup 2.5d grid (LEFT side) */
    sgn_n = 1.0;
    sgn_e = -1.0;
    [idx_q, dn, de] = lookup_terrain_idx(r_n + sgn_n*sin_xi * delta_y, r_e + sgn_e*cos_xi * delta_y, terr_local_origin_n, terr_local_origin_e, terr_dis);
    % bi-linear interpolation */
    h12 = (1-dn)*in(IDX_TERR_DATA+idx_q(1)) + dn*in(IDX_TERR_DATA+idx_q(2));
    h34 = (1-dn)*in(IDX_TERR_DATA+idx_q(3)) + dn*in(IDX_TERR_DATA+idx_q(4));
    h_terr = (1-de)*h12 + de*h34;
    % objective / jacobian */
    arg_sig_h = delta_h - (h - h_terr - h_offset);
    if (arg_sig_h > 0.0)
        sig_h_temp = arg_sig_h * one_over_deltah;
        sig_h_temp = sig_h_temp * sig_h_temp * sig_h_temp;
%         jac_sig_h_cubic(jac_sig_h_temp,
%             de, delta_h, delta_y,
%             in(IDX_TERR_DATA+idx_q(1)), h12, in(IDX_TERR_DATA+idx_q(2)), in(IDX_TERR_DATA+idx_q(3)),
%             h34, in(IDX_TERR_DATA+idx_q(4)), h_offset,
%             r_d, sgn_e, sgn_n,
%             terr_dis, xi);
    end
    sig_h = sig_h + sig_h_temp;
%     jac_sig_h = jac_sig_h + jac_sig_h_temp;

    % lookup 2.5d grid (RIGHT side) */
    sgn_n = -1.0;
    sgn_e = 1.0;
    [idx_q, dn, de] = lookup_terrain_idx(r_n + sgn_n*sin_xi * delta_y, r_e + sgn_e*cos_xi * delta_y, terr_local_origin_n, terr_local_origin_e, terr_dis);
    % bi-linear interpolation */
    h12 = (1-dn)*in(IDX_TERR_DATA+idx_q(1)) + dn*in(IDX_TERR_DATA+idx_q(2));
    h34 = (1-dn)*in(IDX_TERR_DATA+idx_q(3)) + dn*in(IDX_TERR_DATA+idx_q(4));
    h_terr = (1-de)*h12 + de*h34;
    % objective / jacobian */
    arg_sig_h = delta_h - (h - h_terr - h_offset);
    if (arg_sig_h > 0.0)
        sig_h_temp = arg_sig_h * one_over_deltah;
        sig_h_temp = sig_h_temp * sig_h_temp * sig_h_temp;
%         jac_sig_h_cubic(jac_sig_h_temp,
%             de, delta_h, delta_y,
%             in(IDX_TERR_DATA+idx_q(1)), h12, in(IDX_TERR_DATA+idx_q(2)), in(IDX_TERR_DATA+idx_q(3)),
%             h34, in(IDX_TERR_DATA+idx_q(4)), h_offset,
%             r_d, sgn_e, sgn_n,
%             terr_dis, xi);
    end
    sig_h = sig_h + sig_h_temp;
%     jac_sig_h = jac_sig_h + jac_sig_h_temp;
    
    % prioritization */
    prio_h = 1.0 - min(sig_h, 1.0);

    
    % radial objective / jacobian - - - - - - - - - - - - - - - - - - - */
    
    % objective */
    if (occ_detected>0)
        sig_r = constrain(delta_r - (d_occ - r_offset), 0.0, delta_r) / delta_r;
        sig_r = sig_r*sig_r*sig_r;
    end
    
    % prioritization */
    prio_r = 1.0 - min(sig_r, 1.0);

    % jacobian */
    if (occ_detected==2) 
        jac_sig_r = jac_sig_r_tl_cubic( ...
            r_n, r_e, r_d, ...
            v, gamma, xi, ...
            w_e, w_n, w_d, ...
            terr_dis, ...
            p1(1), p1(2), p1(3), ...
            p2(1), p2(2), p2(3), ...
            p3(1), p3(2), p3(3), ...
            r_offset, delta_r0, k_r, ...
            sig_r, d_occ, delta_r, ...
        	vG_sq, vG_norm, ...
        	vG_n, vG_e, vG_d);
    elseif (occ_detected==1)
        jac_sig_r = jac_sig_r_br_cubic( ...
            r_n, r_e, r_d, ...
            v, gamma, xi, ...
            w_e, w_n, w_d, ...
            terr_dis, ...
            p1(1), p1(2), p1(3), ...
            p2(1), p2(2), p2(3), ...
            p3(1), p3(2), p3(3), ...
            r_offset, delta_r0, k_r, ...
            sig_r, d_occ, delta_r, ...
        	vG_sq, vG_norm, ...
        	vG_n, vG_e, vG_d);
    end
    jac_sig_r(4) = 0.0;
    jac_sig_r(5) = 0.0;
    jac_sig_r(6) = 0.0;
    
end
    
    % GUIDANCE - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
    
    % path following - - - - - - - - - - - - - - - - - - - - - - - - - -*/
    
    % path tangent unit vector  */
    tP_n_bar = cos(chi_p);
    tP_e_bar = sin(chi_p);
    
    % "closest" point on track */
    tp_dot_br = tP_n_bar*(r_n-b_n) + tP_e_bar*(r_e-b_e);
    tp_dot_br_n = tp_dot_br*tP_n_bar;
    tp_dot_br_e = tp_dot_br*tP_e_bar;
    p_lat = tp_dot_br_n*tP_n_bar + tp_dot_br_e*tP_e_bar;
    p_d = b_d - p_lat*tan(Gamma_p);
        
    % position error */
    e_lat = (r_n-b_n)*tP_e_bar - (r_e-b_e)*tP_n_bar;
    e_lon = p_d - r_d;
    
    % lateral-directional error boundary */
    e_b_lat = T_b_lat * sqrt(vG_n*vG_n + vG_e*vG_e);
    
    % course approach angle */
    chi_app = atan(pi/2*e_lat/e_b_lat);
    
    % longitudinal error boundary */
    if (abs(vG_d) < 1.0)
        e_b_lon = T_b_lon * 0.5 * (1.0 + vG_d*vG_d); % vG_d may be zero */
    else 
        e_b_lon = T_b_lon * abs(vG_d);
    end
    
    % flight path approach angle */
    Gamma_app = -gamma_app_max * atan(pi/2*e_lon/e_b_lon);
    
    % normalized ground velocity setpoint */
    v_cos_gamma = cos(Gamma_p + Gamma_app);
    vP_n_unit = v_cos_gamma*cos(chi_p + chi_app);
    vP_e_unit = v_cos_gamma*sin(chi_p + chi_app);
    vP_d_unit = -sin(Gamma_p + Gamma_app);
    
    % terrain considerations - - - - - - - - - - - - - - - - - - - - - -*/
    
if USE_OCC_GRAD_AS_GUIDANCE %XXX: maybe make this an online param */
    
    % terrain avoidance velocity setpoint
    norm_jac_sig_r = sqrt(jac_sig_r(1)*jac_sig_r(1) + jac_sig_r(2)*jac_sig_r(2) + jac_sig_r(3)*jac_sig_r(3));
    if (norm_jac_sig_r > 0.0001)
        one_over_norm_jac_sig_r = 1.0/norm_jac_sig_r;
    else
        one_over_norm_jac_sig_r = 10000.0;
    end
    v_occ_n_unit = -jac_sig_r(1) * one_over_norm_jac_sig_r;
    v_occ_e_unit = -jac_sig_r(2) * one_over_norm_jac_sig_r;
    v_occ_d_unit = -jac_sig_r(3) * one_over_norm_jac_sig_r;
    
    % velocity errors */
    vcmd_n_unit = vP_n_unit * prio_r + (1.0-prio_r) * v_occ_n_unit;
    vcmd_e_unit = vP_e_unit * prio_r + (1.0-prio_r) * v_occ_e_unit;
    vcmd_d_unit = vP_d_unit * prio_r + (1.0-prio_r) * v_occ_d_unit;
    e_v_n = vcmd_n_unit - vG_n_unit; 
    e_v_e = vcmd_e_unit - vG_e_unit; 
    e_v_d = vcmd_d_unit - vG_d_unit;
    
else
    
    v_occ_n_unit = NaN;
    v_occ_e_unit = NaN;
    v_occ_d_unit = NaN;
    
    % velocity errors */
    vcmd_n_unit = vP_n_unit;
    vcmd_e_unit = vP_e_unit;
    vcmd_d_unit = vP_d_unit;
    e_v_n = (vP_n_unit - vG_n_unit) * prio_r;
    e_v_e = (vP_e_unit - vG_e_unit) * prio_r;
    e_v_d = (vP_d_unit - vG_d_unit) * prio_r;
    
end

% state output 
out(1) = e_v_n * prio_aoa * prio_h;
out(2) = e_v_e * prio_aoa * prio_h;
out(3) = e_v_d * prio_aoa * prio_h;
out(4) = v;
out(5) = phi;
out(6) = theta;
out(7) = sig_aoa; 
out(8) = sig_h * prio_aoa;
out(9) = sig_r * prio_aoa;

% control output
out(10) = u_T;
out(11) = phi_ref;
out(12) = theta_ref;

aux = [h_terr, e_lat, e_lon, e_v_n, e_v_e, e_v_d, ...       % 1-6
    sig_aoa, sig_h, prio_aoa, prio_h, prio_aoa * prio_h, ...% 7-11
    Gamma_app, chi_app, Gamma_p, chi_p, ...                 % 12-15
    occ_detected, sig_r, jac_sig_r, delta_r, prio_r, ...    % 16-25
    vP_n_unit, vP_e_unit, vP_d_unit, ...                    % 26-28
    v_occ_n_unit, v_occ_e_unit, v_occ_d_unit, ...           % 29-31
    vcmd_n_unit, vcmd_e_unit, vcmd_d_unit, ...              % 32-34
    cos(Gamma_p)*cos(chi_p), ...                            % 35
    cos(Gamma_p)*sin(chi_p), ...                            % 36
    -sin(Gamma_p), ...                                      % 37
    d_occ,r_offset_1];                                      % 38-39

end