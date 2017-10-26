% NMPC Simulation
% ----------------
close all; clear all; clc;

% initial conditions
N = 40;
n_U = 3;
n_X = 13; % number of nmpc states
n_Y = 9+4;
n_Z = 4;

Ts_step = 0.1; % step size in nmpc

% track
defpaths

pparams = [paths(1).pparam1, ...
    paths(1).pparam2, ...
    paths(1).pparam3, ...
    paths(1).pparam4, ...
    paths(1).pparam5, ...
    paths(1).pparam6, ...
    paths(1).pparam7];
pparams_next = [paths(2).pparam1, ...
    paths(2).pparam2, ...
    paths(2).pparam3, ...
    paths(2).pparam4, ...
    paths(2).pparam5, ...
    paths(2).pparam6, ...
    paths(2).pparam7];

% wind
wn=0;
we=0;
wd=0;

% params
R_acpt = 30;                    % switching acceptance radius
ceta_acpt = 0.8;                % switching acceptance cosine of error angle
alpha_p_co = deg2rad(8);        % angle of attack upper cut-off
alpha_m_co = deg2rad(-3);       % angle of attack lower cut-off
alpha_delta_co = deg2rad(2);    % angle of attack cut-off transition length

% model parameters
load parameters_20161209.mat;

u_trim = [0.375, 0, 1.7*pi/180];

% initial conditions
ic_u    = u_trim;
ic_ned  = [-150, 0, 0];
ic_vV   = [13.5, 0, 0];
ic_att  = [0, 0];
ic_attdot = [0, 0, 0];
ic_augm = [ic_u(1), 0];
ic_od   = [pparams, pparams_next, R_acpt, ceta_acpt, ...
    wn, we, wd, ...
    alpha_p_co, alpha_m_co, alpha_delta_co];

% acado inputs
nmpc_ic.x   = [ic_ned,ic_vV,ic_att,ic_attdot,ic_augm]; 
nmpc_ic.u   = ic_u;
yref        = [0 0, 0 0, 13.5, 0 0 0, 0];%-0.764
zref        = [0, u_trim];

Q_scale     = [1 1, 1 1,...
                1, deg2rad(50) deg2rad(50) deg2rad(50), 1];
R_scale     = [1, 1 deg2rad(30) deg2rad(15)];

Q_output    = [100 100, 100 100, 30000, 200 110 5, 200]./Q_scale.^2;
QN_output   = [100 100, 100 100, 30000, 200 110 5, 200]./Q_scale.^2;
R_controls  = [100 200 100 220]./R_scale.^2;

input.x     = repmat(nmpc_ic.x, N+1,1);
input.u     = repmat(nmpc_ic.u, N,1);
input.y     = repmat([yref, zref], N,1);
input.yN    = input.y(1, 1:length(yref))';
input.od    = repmat(ic_od, N+1, 1);
input.W     = repmat(diag([Q_output, R_controls]), [N 1]);
input.WN    = diag(QN_output);

% simulation
T0      = 0;
Tf      = 15;
Ts      = 0.01;
time    = T0:Ts:Tf;
KKT_MPC = []; INFO_MPC = []; controls_MPC = [];

Ts_nmpc = 0.05; % interval between nmpc calls

% initial simout
X0          = nmpc_ic.x;
simout      = nmpc_ic.x(1:12);
states      = simout;
d_states    = [...
    ic_vV(1)*cos(ic_vV(3))*cos(ic_vV(2))+wn, ...
    ic_vV(1)*sin(ic_vV(3))*cos(ic_vV(2))+we, ...
    -ic_vV(1)*sin(ic_vV(2))+wd, ...
    0,0,0, ...
    0,0, ...
    0,0,0, ...
    0,0];
U0 = ic_u;
path_idx = 1;
endofwaypoints=false;
for k = 1:length(time)
    
    % check path
    if pparams(1) < 0.5
        path_checks(k) = check_line_seg(states(1:3),d_states(1:3),ic_od(1:end));
    elseif pparams(1) < 1.5
        path_checks(k) = check_curve_seg(states(1:3),d_states(1:3),ic_od(1:end));
    elseif pparams(1) < 2.5
        path_checks(k) = false;
%         [p1] = set_position_setpoint(states(3),abs(wd),yref(3)*sin(alpha_p_co-alpha_delta_co),pparams(4),Ts_step,N);
%         
%         ic_od = [pparams(1:3),p1,pparams(5:7), pparams_next, R_acpt, ceta_acpt, ...
%                 wn, we, wd, ...
%                 alpha_p_co, alpha_m_co, alpha_delta_co, ...
%                 T_b_lat, T_b_lon];
%         input.od = repmat(ic_od, N+1, 1);
    else
        path_checks(k) = false;
    end
    if path_checks(k)
        if path_idx<length(paths)-1
            for i = 1:length(pparams)
                pparams(i) = pparams_next(i);
                eval(['pparams_next(i) = paths(path_idx+2).pparam',int2str(i),';']);
            end
            path_idx = path_idx + 1;
            ic_od = [pparams, pparams_next, R_acpt, ceta_acpt, ...
                wn, we, wd, ...
                alpha_p_co, alpha_m_co, alpha_delta_co];
            input.od = repmat(ic_od, N+1, 1);
            X0(end) = 0; % sw
            output.x(:,end)=zeros(N+1,1);
        elseif ~endofwaypoints
            endofwaypoints=true;
            for i = 1:length(pparams)
                pparams(i) = pparams_next(i);
            end
            path_idx = path_idx + 1;
            ic_od = [pparams, pparams_next, R_acpt, ceta_acpt, ...
                wn, we, wd, ...
                alpha_p_co, alpha_m_co, alpha_delta_co];
            input.od = repmat(ic_od, N+1, 1);
            X0(end) = 0; % sw
            output.x(:,end)=zeros(N+1,1);
        end
    end
    
    % motor failure
%     if k>25*1/Ts
%         input.W = repmat(diag([Q_output, R_controls(1), 1000000, R_controls(3:4)]), [N 1]);
%         input.y     = repmat([yref, zref(1), 0, zref(3:4)], N,1);
%         X0(12) = 0;
%         states(12) = 0;
%     end
    
    % measure
    input.x0    = X0';
%     input.x0(6) = input.x0(6)+deg2rad(2);
    
    if time(k)==floor(time(k)/Ts_nmpc)*Ts_nmpc
    
        %  - - - - - START NMPC - - - - -
        st_nmpc = tic;

         % shift initial states and controls
        if k > 1
            input.x     = output.x;
            input.u     = output.u;
        end

        % generate controls
        output = acado_nmpc_3dhl_ev_step(input);

        U0  = output.u(1,:);

        % record info
        INFO_MPC = [INFO_MPC; output.info];
        KKT_MPC = [KKT_MPC; output.info.kktValue];

        % augmented states measurement update
        X0(12:13) = output.x(1,12:13) + (output.x(2,12:13) - output.x(1,12:13))*Ts_nmpc/Ts_step;

        tsolve(k) = toc(st_nmpc);
    
    end
    % - - - - - END NMPC - - - - -
    
    % apply control
    [d_states, simout]  = uav_dyn(time(k), states, U0, [wn,we,wd], parameters);

    % integration (model propagation)
    states = states + d_states*Ts;
    
    % measurement update
    X0(1:11) = simout(1:11);
    
    if time(k)>12
        stopp=1;
    end
    
    % record states/controls
    X_rec(k,:) = [simout, X0(13)];
    horiz_rec(:,k,:) = output.x(:,:);
    horiz_rec_U(:,k,:) = output.u(:,:);
    U_rec(k,:) = U0;
    [out,aux] = eval_obj([X0,U0,ic_od],[n_X,n_U]);
    Y_rec(k,:) = out;
    aux_rec(k,:) = aux;

end

plotsim