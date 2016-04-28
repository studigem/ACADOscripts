% Techpod NMPC simulation
% -----------------------
close all; clear all; clc;

% load aircraft parameters
load parameters_2016.03.06_1709.mat
for i = 1:length(parameters)
    eval([parameters(i).Name,' = ',num2str(parameters(i).Value),';'])
end

% initial conditions
N       = 20;
n_U     = 5;

% L1 guidance
L1p_lon     = 10;
L1d_lon     = 0.1;
kilon       = 0.01;
intg_lon    = 0;%-8.3e-3;
theta_cmd_min = -25*pi/180;
theta_cmd_max = 25*pi/180;

L1p_lat     = 25;
L1d_lat     = 0.707;
kilat       = 0;
intg_lat    = 0;
phi_cmd_min = -45*pi/180;
phi_cmd_max = 45*pi/180;

% other guidance
V_cmd       = 13;
theta_cmd = 0;
phi_cmd = 0;
intg_V      = 0;
kiV         = 0.01;

defpaths

% weighting matrices
% Aw2 = 0;
% Bw2 = 0;
% Cw2 = 0;
% Dw2 = 1;
Aw2 = -8;
Bw2 = 1;
Cw2 = -127;
Dw2 = 16;

Aw3 = -0.4;
Bw3 = 10.2;
Cw3 = -0.3;
Dw3 = 8;
% Aw3 = 0;
% Bw3 = 0;
% Cw3 = 0;
% Dw3 = 0;

% wind
wn=1.5;
we=-2;
wd=1;

% states
n = 0;
e = 0;
d = 0;
pp = [n,e,d];

% acado inputs
input.od    = repmat([Aw2, Bw2, Cw2, Dw2, Aw3, Bw3, Cw3, Dw3, kiV],N+1,1);

% X0          = ...
%     [13*cos(0.0805), 0, 13*sin(0.0805), ... % body velocities
%      zeros(1,3), ...                        % body angular rates
%      0, 0.0805, 0, ...                      % euler angles
%      0, ...                                 % slack dummy
%      intg_V, intg_gam, ...                  % integrators
%      zeros(1,4)];                           % weighting matrix states
 
% input.x  	= repmat(X0,N+1,1);

% U0          = [0.39, -0.0189, 0, 0, 0];
% input.u     = repmat(U0,N,1);

load initXU;
% initXh = [initXh(:,1:8), zeros(N+1,7)];
% input.x = initXh;%[initXh, zeros(N+1,1)];%; repmat(initXh(end,:),0,1)];
% X0      = initXh(1,:);
% input.u = [initUh; repmat(initUh(end,:),0,1)];
initXh = [repmat(initXh(end,1:8),N+1,1), zeros(N+1,11)];
input.x = repmat(initXh(end,:),N+1,1);%[initXh, zeros(N+1,1)];%; repmat(initXh(end,:),0,1)];
X0      = initXh(1,:);
input.u = repmat(initUh(end,:),N,1);

uT = input.u(end,4);

yref        = [V_cmd, theta_cmd, phi_cmd, 0, 0, 0, 0, zeros(1,4)]; %zeros(1,4);%
input.y     = [repmat(yref,N,1), zeros(N,n_U)];
% input.y     = [repmat(yref,N,1), repmat(U0,N,1)];
input.yN    = input.y(1,1:11)';

Q_output    = [50 500 250 1500 1 10 1 .5 .5 .5 .5];
R_controls  = [1 1 1 1, 2000];

input.W     = diag([Q_output, R_controls]);
input.WN    = diag(Q_output);
% input.W = diag([0.01 5 0.1 100 0.001 1 1 1 0.1]);
% input.WN = diag([0.01 5 0.1 100]);

% simulation
T0      = 0;
Tf      = 60;
Ts      = 0.05;
time    = T0:Ts:Tf;
KKT_MPC = []; INFO_MPC = []; controls_MPC = [];

% initial simout
simout      = [13, 0, 0.0805, zeros(1,3), 0, 0.0805, 0, n, e, d, 0];
psi = simout(9);
d_states    = [zeros(1,9), 13, 0, 0, 0];
pth_idx     = 1;

pth_Racpt = 20;
pth_Aacpt = 30*pi/180;
in_trans = false;
seg_term = false;
trans_count = 0;
N_trans = 1;

for k = 1:length(time)
    
    %  - - - - - START NMPC - - - - -
    
    st_nmpc = tic;
    
    % measure
    input.x0    = X0';
    
    % guidance        
    
        
    if ~in_trans

        if paths(pth_idx).pparam1 == 0

            % calculate vector from waypoint a to b
            v_bb = [paths(pth_idx).pparam5, paths(pth_idx).pparam6, paths(pth_idx).pparam7] - [paths(pth_idx).pparam2, paths(pth_idx).pparam3, paths(pth_idx).pparam4];
            normv_bb = norm(v_bb);

            % calculate closest point on line a->b
            aa_pp       = pp - [paths(pth_idx).pparam2, paths(pth_idx).pparam3, paths(pth_idx).pparam4];

            % calculate projected 1-D distance along track
            p_track    = dot(v_bb, aa_pp) / normv_bb;

            seg_term = p_track > normv_bb - pth_Racpt && ...
                norm(cross(v_bb, d_states(10:12))) / normv_bb / norm(d_states(10:12)) < pth_Aacpt && ...
                pth_idx<length(paths);

        elseif paths(pth_idx).pparam1 == 1

            bb = [paths(pth_idx).pparam2, paths(pth_idx).pparam3, paths(pth_idx).pparam4] + paths(pth_idx).pparam5 * ...
                [cos(paths(pth_idx).pparam8 + paths(pth_idx).pparam6 * paths(pth_idx).pparam9), ...
                sin(paths(pth_idx).pparam8 + paths(pth_idx).pparam6 * paths(pth_idx).pparam9), ...
                -tan(paths(pth_idx).pparam7) * paths(pth_idx).pparam9];
        
            xiend = paths(pth_idx).pparam8 + paths(pth_idx).pparam6 * (paths(pth_idx).pparam9 + pi/2);
        
            v_bb = [cos(xiend), sin(xiend), -sin(paths(pth_idx).pparam7)];
        
            seg_term = norm(bb - pp) < pth_Racpt && ...
                norm(cross(v_bb, d_states(10:12))) / norm(v_bb) / norm(d_states(10:12)) < pth_Aacpt && ...
                pth_idx<length(paths);
            
        end

    end

    if seg_term || in_trans

        if ~in_trans
            in_trans = true;
            trans_count = 1;
        else
            trans_count = trans_count + 1;
        end

        % path current ----------------------------------------------------
        if paths(pth_idx).pparam1 == 0
            
            [theta_cmd_0, phi_cmd_0, etalon_0, etalat_0] = ...
                L1guide_line(pp, d_states(10:12), ...
                [paths(pth_idx).pparam2, paths(pth_idx).pparam3, paths(pth_idx).pparam4], ...
                [paths(pth_idx).pparam5, paths(pth_idx).pparam6, paths(pth_idx).pparam7], ...
                L1p_lon, L1d_lon, intg_lon, ...
                L1p_lat, L1d_lat, intg_lat, ...
                theta_cmd_min, theta_cmd_max, phi_cmd_min, phi_cmd_max);
        
        elseif paths(pth_idx).pparam1 == 1
                
            [theta_cmd_0, phi_cmd_0, etalon_0, etalat_0] = ...
                L1guide_spiral(pp, d_states(10:12), ...
                [paths(pth_idx).pparam2, paths(pth_idx).pparam3, paths(pth_idx).pparam4], ...
                paths(pth_idx).pparam5, paths(pth_idx).pparam6, paths(pth_idx).pparam8, paths(pth_idx).pparam7, ...
                L1p_lon, L1d_lon, intg_lon, ...
                L1p_lat, L1d_lat, intg_lat,...
                theta_cmd_min, theta_cmd_max, phi_cmd_min, phi_cmd_max, paths(pth_idx).pparam9);
            
        end
        
        % path next -------------------------------------------------------
        if paths(pth_idx+1).pparam1 == 0
            
            [theta_cmd_1, phi_cmd_1, etalon_1, etalat_1] = ...
                L1guide_line(pp, d_states(10:12), ...
                [paths(pth_idx+1).pparam2, paths(pth_idx+1).pparam3, paths(pth_idx+1).pparam4], ...
                [paths(pth_idx+1).pparam5, paths(pth_idx+1).pparam6, paths(pth_idx+1).pparam7], ...
                L1p_lon, L1d_lon, intg_lon, ...
                L1p_lat, L1d_lat, intg_lat, ...
                theta_cmd_min, theta_cmd_max, phi_cmd_min, phi_cmd_max);
        
        elseif paths(pth_idx+1).pparam1 == 1
                
            [theta_cmd_1, phi_cmd_1, etalon_1, etalat_1] = ...
                L1guide_spiral(pp, d_states(10:12), ...
                [paths(pth_idx+1).pparam2, paths(pth_idx+1).pparam3, paths(pth_idx+1).pparam4], ...
                paths(pth_idx+1).pparam5, paths(pth_idx+1).pparam6, paths(pth_idx+1).pparam8, paths(pth_idx+1).pparam7, ...
                L1p_lon, L1d_lon, intg_lon, ...
                L1p_lat, L1d_lat, intg_lat,...
                theta_cmd_min, theta_cmd_max, phi_cmd_min, phi_cmd_max, paths(pth_idx+1).pparam9);
            
        end
        
        gam_trans = trans_count / N_trans;
        one_m_gam_trans = (1 - gam_trans);
        
        theta_cmd   = one_m_gam_trans * theta_cmd_0 + gam_trans * theta_cmd_1;
        phi_cmd     = one_m_gam_trans * phi_cmd_0 + gam_trans * phi_cmd_1;
        etalon      = one_m_gam_trans * etalon_0 + gam_trans * etalon_1;
        etalat      = one_m_gam_trans * etalat_0 + gam_trans * etalat_1;

        if trans_count >= N_trans
            pth_idx = pth_idx + 1;
            trans_count = 0;
            in_trans = false;
            seg_term = false;
        end
        
    else

        if paths(pth_idx).pparam1 == 0
            
            [theta_cmd, phi_cmd, etalon, etalat] = ...
                L1guide_line(pp, d_states(10:12), ...
                [paths(pth_idx).pparam2, paths(pth_idx).pparam3, paths(pth_idx).pparam4], ...
                [paths(pth_idx).pparam5, paths(pth_idx).pparam6, paths(pth_idx).pparam7], ...
                L1p_lon, L1d_lon, intg_lon, ...
                L1p_lat, L1d_lat, intg_lat, ...
                theta_cmd_min, theta_cmd_max, phi_cmd_min, phi_cmd_max);
        
        elseif paths(pth_idx).pparam1 == 1
                
            [theta_cmd, phi_cmd, etalon, etalat] = ...
                L1guide_spiral(pp, d_states(10:12), ...
                [paths(pth_idx).pparam2, paths(pth_idx).pparam3, paths(pth_idx).pparam4], ...
                paths(pth_idx).pparam5, paths(pth_idx).pparam6, paths(pth_idx).pparam8, paths(pth_idx).pparam7, ...
                L1p_lon, L1d_lon, intg_lon, ...
                L1p_lat, L1d_lat, intg_lat,...
                theta_cmd_min, theta_cmd_max, phi_cmd_min, phi_cmd_max, paths(pth_idx).pparam9);
            
        else
            
            theta_cmd = 0; phi_cmd = 0; etalon = 0; etalat = 0;
            
        end

    end

    intg_lon = intg_lon + kilon * etalon * Ts;
    intg_lat = intg_lat + kilat * etalat * Ts;

    input.od    = repmat([Aw2, Bw2, Cw2, Dw2, Aw3, Bw3, Cw3, Dw3, kiV],N+1,1);
    yref        = [V_cmd, theta_cmd, phi_cmd, 0, 0, 0, 0, zeros(1,4)]; 
%     input.y     = [repmat(yref,N,1), input.u]; //NO. this doesnt make
%     sense with z's
    input.y     = [repmat(yref,N,1), zeros(N,5)];
    input.yN    = input.y(end,1:11)';
    
    % generate controls
    output      = acado_nmpc_step(input);
    U0          = output.u(1,:);
    
    % record info
    INFO_MPC    = [INFO_MPC; output.info];
    KKT_MPC     = [KKT_MPC; output.info.kktValue];
    
    % record states/controls
    X_rec(k,:)       = [simout, X0(10)];
    Y_rec(k,:)       = [V_cmd, theta_cmd, phi_cmd, intg_lon, intg_lat, etalon, etalat];
    U_rec(k,:)       = U0;
    
    % shift initial states and controls
    input.x     = [output.x(2:N+1,:); output.x(N+1,:)];
    input.u     = [output.u(2:N,:); output.u(N,:)];
    X0(9:15)   = output.x(2,9:15);

    tsolve(k) = toc(st_nmpc);
    
    % - - - - - END NMPC - - - - -
    
    % apply control
    [d_states, simout]  = techpod_nonlin_model_13DoF(time(1), [X0(1:8), psi, pp, uT], U0(1:4), ...
        cD0, cDa, cDa2, ...
        cL0, cLa, cLa2, cLa3, ...
        cm0, cma, cmq, cmde, ...
        cT0, cT1, cT2, tauT, ...
        clb, clp, clr, clda, ...
        cYb, ...
        cnb, cnp, cnr, cndr, ...
        wn, we, wd);

    % integration (model propagation)
    X0(1:8) = X0(1:8) + d_states(1:8)*Ts;
    psi = psi + d_states(9)*Ts;
    pp = pp + d_states(10:12)*Ts;
    uT = uT + d_states(13)*Ts;
    
end

plotsim
