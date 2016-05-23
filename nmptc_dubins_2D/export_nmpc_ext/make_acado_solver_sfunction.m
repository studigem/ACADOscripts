%
%    This file was auto-generated by ACADO Code Generation Tool.
%    
%    ACADO Code Generation tool is a sub-package of ACADO toolkit --
%    A Toolkit for Automatic Control and Dynamic Optimization.
%    Copyright (C) 2008-2014 by Boris Houska, Hans Joachim Ferreau,
%    Milan Vukov, Rien Quirynen, KU Leuven.
%    Developed within the Optimization in Engineering Center (OPTEC)
%    under supervision of Moritz Diehl. All rights reserved.
%    
%    ACADO Toolkit is free software; you can redistribute it and/or
%    modify it under the terms of the GNU Lesser General Public
%    License as published by the Free Software Foundation; either
%    version 3 of the License, or (at your option) any later version.
%    
%    ACADO Toolkit is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
%    Lesser General Public License for more details.
%    
%    You should have received a copy of the GNU Lesser General Public
%    License along with ACADO Toolkit; if not, write to the Free Software
%    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
%    


%% Legacy code wrapper for the ACADO CGT generated OCP solver

% Dimensions
acado_N   = 30;
acado_NX  = 5;
acado_NDX = 0;
acado_NXA = 0;
acado_NU  = 1;
acado_NOD = 22;
acado_NY  = 6;
acado_NYN = 6;

acado_QP_SOLVER                   = 'QPOASES';
acado_INITIAL_STATE_FIXED         = 1;
acado_WEIGHTING_MATRICES_TYPE     = 2;
acado_HARDCODED_CONSTRAINT_VALUES = 1;
acado_USE_ARRIVAL_COST            = 0;
acado_COMPUTE_COVARIANCE_MATRIX   = 0;

aSfunName  = 'acado_solver_sfun';
aRealT     = 'double';
aHeaderFile = 'acado_solver_sfunction.h';

%% Define busses

clear avCells aInput aOutput acadodata acadoinput acadooutput;

% Define ACADOvariables bus:
avCells = {'acadodata', aHeaderFile, '', 'Auto', '-1', {}};

idx = 1;
avCells{ 6 }{ idx } = {'x', [1, (acado_N + 1) * acado_NX], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1; 
avCells{ 6 }{ idx } = {'u', [1, acado_N * acado_NU], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;

if acado_NXA > 0
    avCells{ 6 }{ idx } = {'z', [1, acado_N * acado_NXA], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
end;

if acado_NOD > 0
    avCells{ 6 }{ idx } = {'od', [1, (acado_N + 1) * acado_NOD], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
end;

avCells{ 6 }{ idx } = {'y', [1, acado_N * acado_NY], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1; 
avCells{ 6 }{ idx } = {'yN', [1, acado_NYN], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;

if acado_WEIGHTING_MATRICES_TYPE == 1
    avCells{ 6 }{ idx } = {'W', [1, acado_NY * acado_NY], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
elseif acado_WEIGHTING_MATRICES_TYPE == 2
    avCells{ 6 }{ idx } = {'W', [1, acado_NY * acado_N * acado_NY], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
end;

if acado_WEIGHTING_MATRICES_TYPE ~= 0
    avCells{ 6 }{ idx } = {'WN', [1, acado_NYN * acado_NYN], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
end;

if acado_USE_ARRIVAL_COST == 1
	avCells{ 6 }{ idx } = {'xAC', [1, acado_NX], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
	avCells{ 6 }{ idx } = {'SAC', [1, acado_NX * acado_NX], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
	avCells{ 6 }{ idx } = {'WL', [1, acado_NX * acado_NX], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
end;

if acado_INITIAL_STATE_FIXED == 1
    avCells{ 6 }{ idx } = {'x0', [1, acado_NX], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
end;

if acado_COMPUTE_COVARIANCE_MATRIX == 1
    avCells{ 6 }{ idx } = {'sigmaN', [1, acado_NX * acado_NX], aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; idx = idx + 1;
end;

% Define input bus for the Simulink component:
aInput = { ...
	'acadoinput', aHeaderFile, '', ...
	{
		{'control', 1, 'int32', -1, 'real', 'Sample', 'Fixed', [], []}; ...
		{'shifting', 1, 'int32', -1, 'real', 'Sample', 'Fixed', [], []}; ...
		{'initialization', 1, 'int32', -1, 'real', 'Sample', 'Fixed', [], []}; ...
		{'data', 1, 'acadodata', -1, 'real', 'Sample', 'Fixed', [], []}; ...
	}
	};

% Define output bus for the Simulink component:
aOutput = { ...
	'acadooutput', aHeaderFile, '', ...
	{
		{'status', 1, 'int32', -1, 'real', 'Sample', 'Fixed', [], []}; ...
		{'kktValue', 1, aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; ...
		{'objValue', 1, aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; ...
		{'execTime', 1, aRealT, -1, 'real', 'Sample', 'Fixed', [], []}; ...
		{'data', 1, 'acadodata', -1, 'real', 'Sample', 'Fixed', [], []}; ...
	}
	};

% Generate all structures
Simulink.Bus.cellToObject( {avCells, aInput, aOutput} );

%% Define S-function wrapper

clear acadoDef;

acadoDef = legacy_code('initialize');

if strcmp(acado_QP_SOLVER, 'QPOASES')
	acadoDef.Options.language = 'C++';
elseif strcmp(acado_QP_SOLVER, 'QPDUNES')
	acadoDef.Options.language = 'C';
else
	error('Unknown QP solver')
end;


% Define the S-function name
acadoDef.SFunctionName = aSfunName;

% Define source files
acadoDef.SourceFiles = { ...
	'acado_solver.c', ...
	'acado_integrator.c', ...
	'acado_auxiliary_functions.c', ...
	'acado_solver_sfunction.c' ...
	};
	
if strcmp(acado_QP_SOLVER, 'QPOASES')
	acadoDef.SourceFiles{end + 1} = 'acado_qpoases_interface.cpp';

	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/QProblem.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/QProblemB.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/Bounds.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/Constraints.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/SubjectTo.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/Indexlist.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/CyclingManager.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/Utils.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/MessageHandling.cpp';
	acadoDef.SourceFiles{end + 1} = 'qpoases/SRC/EXTRAS/SolutionAnalysis.cpp';
elseif strcmp(acado_QP_SOLVER, 'QPDUNES')
	acadoDef.SourceFiles{end + 1} = 'qpdunes/src/dual_qp.c';
	acadoDef.SourceFiles{end + 1} = 'qpdunes/src/matrix_vector.c';
	acadoDef.SourceFiles{end + 1} = 'qpdunes/src/setup_qp.c';
	acadoDef.SourceFiles{end + 1} = 'qpdunes/src/stage_qp_solver_clipping.c';
	acadoDef.SourceFiles{end + 1} = 'qpdunes/src/utils.c';
else
	error('Unknown QP solver')
end;

% Define header files
acadoDef.HeaderFiles = {'acado_common.h', aHeaderFile};

% Define include folders
if strcmp(acado_QP_SOLVER, 'QPOASES')
	acadoDef.IncPaths = { ...
    	'qpoases', ...
		'qpoases/INCLUDE', ...
		'qpoases/SRC' ...
	};
elseif strcmp(acado_QP_SOLVER, 'QPDUNES')
	acadoDef.IncPaths = { ...
		'qpdunes/include', ...
	};
else
	error('Unknown QP solver')
end;

% link against some libs maybe
ldFlags = '';
if (isunix() && ~ismac())
%	ldFlags = [ldFlags ' -lrt'];
elseif (ispc)
    ldFlags = [ldFlags ' -DWIN32'];
end;

% Add an extra option for qpOASES
iFlags = '';
if (~strcmp(aSfunName, 'acado_solver_sfun')) && (strcmp(acado_QP_SOLVER, 'QPOASES'))
    iFlags = '-DQPOASES_CUSTOM_INTERFACE=\"acado_qpoases_interface.hpp\"';    
end;
if strcmp(acado_QP_SOLVER, 'QPDUNES')
	iFlags = '-D__SIMPLE_BOUNDS_ONLY__';
end;

% Define output function declaration
acadoDef.OutputFcnSpec = [ ...
	'acado_step(' ... % Wrapper function name
	'acadoinput u1[1], ' ...	% Input argument
	'acadooutput y1[1])' ...	% Output argument
	];
% Define init function declaration
acadoDef.StartFcnSpec     = 'acado_initialize( void )';
% Define terminate function declaration
acadoDef.TerminateFcnSpec = 'acado_cleanup( void )';

%% Generate S-function source file
legacy_code('sfcn_cmex_generate', acadoDef);

%% Compile the code
legacy_code('compile', acadoDef, {iFlags, ldFlags});

%% Generate a TLC file and simulation block
legacy_code('slblock_generate', acadoDef);
legacy_code('sfcn_tlc_generate', acadoDef);
% Mandatory, because not all the source and header files are in the same folder
legacy_code('rtwmakecfg_generate', acadoDef);

%% Remove dependency on the header file and regenerate the Simulink structures

avCells{ 2 } = '';
aInput{ 2 } = '';
aOutput{ 2 } = '';

% Generate all structures
Simulink.Bus.cellToObject( {avCells, aInput, aOutput} );

%% Clear byproducts
clear aInput aOutput avCells idx iFlags ldFlags aSfunName aRealT aHeaderFile;
