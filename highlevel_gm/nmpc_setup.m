% -------------------------------------------------------------------------
% Fixed-wing Local Re-planning w/ Obstacle Avoidance
% -------------------------------------------------------------------------
clc;
clear all;
close all;

Ts = 0.1; % model discretization step [0.1 s]
N = 100; % horizon

% STATES - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
DifferentialState n; % northing [m]
DifferentialState e; % easting [m]
DifferentialState d; % downing [m]
DifferentialState gamma; % flight path angle [rad]
DifferentialState xi; % heading angle [rad]
DifferentialState mu; % bank angle [rad]

% CONTROLS - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Control gamma_ref; % flight path angle reference
Control mu_ref; % bank angle reference

% ONLINE DATA - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

% flight condition
OnlineData v;

% disturbances
OnlineData wn;
OnlineData we;
OnlineData wd;

% path reference
OnlineData bn;
OnlineData be;
OnlineData bd;
OnlineData gamma_p;
OnlineData chi_p;

% MODEL -------------------------------------------------------------------

% model parameters
tau_gamma = 1;
tau_mu = 0.7;

% constants
g = 9.81; % acceleration of gravity [m/s2]

% state differentials
dot_n = v*cos(gamma)*cos(xi) + wn;
dot_e = v*cos(gamma)*sin(xi) + we;
dot_d = -v*sin(gamma) + wd;
dot_gamma = (gamma_ref - gamma)/tau_gamma;
dot_xi = g*tan(mu)/v/cos(gamma);
dot_mu = (mu_ref - mu)/tau_mu;

% ode
f = acado.DifferentialEquation;
f.add(dot(n) == dot_n);
f.add(dot(e) == dot_e);
f.add(dot(d) == dot_d);
f.add(dot(gamma) == dot_gamma);
f.add(dot(xi) == dot_xi);
f.add(dot(mu) == dot_mu);

% OPTIMAL CONTROL PROBLEM -------------------------------------------------

% lengths
n_X = length(diffStates);   % states
n_U = length(controls);     % controls
n_Y = 2;                    % outputs
n_Z = 4;                    % objectives
n_OD = 9;

acadoSet('problemname', 'nmpc');

% optimal control problem
ocp = acado.OCP( 0.0, N*Ts, N );

% external objective function
Q = eye(n_Y+n_Z,n_Y+n_Z);
Q = acado.BMatrix(Q);
QN = eye(n_Y,n_Y);
QN = acado.BMatrix(QN);

ocp.minimizeLSQ( Q, 'evaluateLSQ' );
ocp.minimizeLSQEndTerm( QN, 'evaluateLSQEndTerm' );
% ocp.setModel('model', 'rhs', 'rhs_jac');
% ocp.setDimensions( n_X, n_U, n_OD, 0 );

% hard coded constraints
ddot_clmb = 4;
ddot_sink = 2;
mu_lim = deg2rad(45);

ocp.subjectTo( f );
ocp.subjectTo( -ddot_sink <= v * sin(gamma_ref) <= ddot_clmb );
ocp.subjectTo( -mu_lim <= mu_ref <= mu_lim );

setNOD(ocp, 9);

% export settings
nmpc = acado.OCPexport( ocp );
nmpc.set( 'HESSIAN_APPROXIMATION', 'GAUSS_NEWTON' );
nmpc.set( 'DISCRETIZATION_TYPE', 'MULTIPLE_SHOOTING' );
nmpc.set( 'SPARSE_QP_SOLUTION', 'FULL_CONDENSING' );
nmpc.set( 'INTEGRATOR_TYPE', 'INT_IRK_GL4' );
nmpc.set( 'NUM_INTEGRATOR_STEPS', N  );
nmpc.set( 'QP_SOLVER', 'QP_QPOASES' );
nmpc.set( 'HOTSTART_QP', 'YES' );
nmpc.set( 'LEVENBERG_MARQUARDT', 1e-10 );
nmpc.set( 'CG_HARDCODE_CONSTRAINT_VALUES', 'YES' );
nmpc.set( 'CG_USE_VARIABLE_WEIGHTING_MATRIX', 'YES' );
nmpc.set( 'GENERATE_MAKE_FILE', 'NO' );
nmpc.set( 'GENERATE_TEST_FILE', 'NO' );
nmpc.set( 'GENERATE_SIMULINK_INTERFACE', 'NO' );

% export
copyfile('../acado/external_packages/qpoases', ...
    'export_nmpc/qpoases')
nmpc.exportCode( 'export_nmpc' );

cd export_nmpc
make_acado_solver('../acado_nmpc_step', 'lsq_objective.c')
cd ..