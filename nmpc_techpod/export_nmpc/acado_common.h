/*
 *    This file was auto-generated by ACADO Code Generation Tool.
 *    
 *    ACADO Code Generation tool is a sub-package of ACADO toolkit --
 *    A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-2014 by Boris Houska, Hans Joachim Ferreau,
 *    Milan Vukov, Rien Quirynen, KU Leuven.
 *    Developed within the Optimization in Engineering Center (OPTEC)
 *    under supervision of Moritz Diehl. All rights reserved.
 *    
 *    ACADO Toolkit is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *    
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *    
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with ACADO Toolkit; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *    
 */


#ifndef ACADO_COMMON_H
#define ACADO_COMMON_H

#include <math.h>
#include <string.h>

#ifndef __MATLAB__
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#endif /* __MATLAB__ */

/** \defgroup ACADO ACADO CGT generated module. */
/** @{ */

/** qpOASES QP solver indicator. */
#define ACADO_QPOASES 0
/** FORCES QP solver indicator.*/
#define ACADO_FORCES  1
/** qpDUNES QP solver indicator.*/
#define ACADO_QPDUNES 2
/** HPMPC QP solver indicator. */
#define ACADO_HPMPC 3
/** Indicator for determining the QP solver used by the ACADO solver code. */
#define ACADO_QP_SOLVER ACADO_QPOASES

#include "acado_qpoases_interface.hpp"


/*
 * Common definitions
 */
/** User defined block based condensing. */
#define ACADO_BLOCK_CONDENSING 0
/** Compute covariance matrix of the last state estimate. */
#define ACADO_COMPUTE_COVARIANCE_MATRIX 0
/** Flag indicating whether constraint values are hard-coded or not. */
#define ACADO_HARDCODED_CONSTRAINT_VALUES 1
/** Indicator for fixed initial state. */
#define ACADO_INITIAL_STATE_FIXED 1
/** Number of control/estimation intervals. */
#define ACADO_N 10
/** Number of online data values. */
#define ACADO_NOD 5
/** Number of control variables. */
#define ACADO_NU 5
/** Number of differential variables. */
#define ACADO_NX 15
/** Number of algebraic variables. */
#define ACADO_NXA 0
/** Number of differential derivative variables. */
#define ACADO_NXD 0
/** Number of references/measurements per node on the first N nodes. */
#define ACADO_NY 12
/** Number of references/measurements on the last (N + 1)st node. */
#define ACADO_NYN 7
/** Total number of QP optimization variables. */
#define ACADO_QP_NV 50
/** Number of integration steps per shooting interval. */
#define ACADO_RK_NIS 1
/** Number of Runge-Kutta stages per integration step. */
#define ACADO_RK_NSTAGES 2
/** Providing interface for arrival cost. */
#define ACADO_USE_ARRIVAL_COST 0
/** Indicator for usage of non-hard-coded linear terms in the objective. */
#define ACADO_USE_LINEAR_TERMS 0
/** Indicator for type of fixed weighting matrices. */
#define ACADO_WEIGHTING_MATRICES_TYPE 1


/*
 * Globally used structure definitions
 */

/** The structure containing the user data.
 * 
 *  Via this structure the user "communicates" with the solver code.
 */
typedef struct ACADOvariables_
{
int dummy;
/** Matrix of size: 11 x 15 (row major format)
 * 
 *  Matrix containing 11 differential variable vectors.
 */
real_t x[ 165 ];

/** Matrix of size: 10 x 5 (row major format)
 * 
 *  Matrix containing 10 control variable vectors.
 */
real_t u[ 50 ];

/** Matrix of size: 11 x 5 (row major format)
 * 
 *  Matrix containing 11 online data vectors.
 */
real_t od[ 55 ];

/** Column vector of size: 120
 * 
 *  Matrix containing 10 reference/measurement vectors of size 12 for first 10 nodes.
 */
real_t y[ 120 ];

/** Column vector of size: 7
 * 
 *  Reference/measurement vector for the 11. node.
 */
real_t yN[ 7 ];

/** Matrix of size: 12 x 12 (row major format) */
real_t W[ 144 ];

/** Matrix of size: 7 x 7 (row major format) */
real_t WN[ 49 ];

/** Column vector of size: 15
 * 
 *  Current state feedback vector.
 */
real_t x0[ 15 ];


} ACADOvariables;

/** Private workspace used by the auto-generated code.
 * 
 *  Data members of this structure are private to the solver.
 *  In other words, the user code should not modify values of this 
 *  structure. 
 */
typedef struct ACADOworkspace_
{
real_t rk_dim30_swap;

/** Column vector of size: 30 */
real_t rk_dim30_bPerm[ 30 ];

/** Column vector of size: 797 */
real_t acado_aux[ 797 ];

real_t rk_ttt;

/** Row vector of size: 25 */
real_t rk_xxx[ 25 ];

/** Matrix of size: 15 x 2 (row major format) */
real_t rk_kkk[ 30 ];

/** Matrix of size: 30 x 30 (row major format) */
real_t rk_A[ 900 ];

/** Column vector of size: 30 */
real_t rk_b[ 30 ];

/** Row vector of size: 30 */
int rk_dim30_perm[ 30 ];

/** Column vector of size: 15 */
real_t rk_rhsTemp[ 15 ];

/** Matrix of size: 2 x 300 (row major format) */
real_t rk_diffsTemp2[ 600 ];

/** Matrix of size: 15 x 2 (row major format) */
real_t rk_diffK[ 30 ];

/** Matrix of size: 15 x 20 (row major format) */
real_t rk_diffsNew2[ 300 ];

/** Row vector of size: 325 */
real_t state[ 325 ];

/** Column vector of size: 150 */
real_t d[ 150 ];

/** Column vector of size: 120 */
real_t Dy[ 120 ];

/** Column vector of size: 7 */
real_t DyN[ 7 ];

/** Matrix of size: 150 x 15 (row major format) */
real_t evGx[ 2250 ];

/** Matrix of size: 150 x 5 (row major format) */
real_t evGu[ 750 ];

/** Column vector of size: 48 */
real_t objAuxVar[ 48 ];

/** Row vector of size: 25 */
real_t objValueIn[ 25 ];

/** Row vector of size: 252 */
real_t objValueOut[ 252 ];

/** Matrix of size: 150 x 15 (row major format) */
real_t Q1[ 2250 ];

/** Matrix of size: 150 x 12 (row major format) */
real_t Q2[ 1800 ];

/** Matrix of size: 50 x 5 (row major format) */
real_t R1[ 250 ];

/** Matrix of size: 50 x 12 (row major format) */
real_t R2[ 600 ];

/** Matrix of size: 150 x 5 (row major format) */
real_t S1[ 750 ];

/** Matrix of size: 15 x 15 (row major format) */
real_t QN1[ 225 ];

/** Matrix of size: 15 x 7 (row major format) */
real_t QN2[ 105 ];

/** Column vector of size: 12 */
real_t conAuxVar[ 12 ];

/** Row vector of size: 25 */
real_t conValueIn[ 25 ];

/** Row vector of size: 32 */
real_t conValueOut[ 32 ];

/** Column vector of size: 20 */
real_t evH[ 20 ];

/** Matrix of size: 20 x 15 (row major format) */
real_t evHx[ 300 ];

/** Column vector of size: 2 */
real_t evHxd[ 2 ];

/** Column vector of size: 15 */
real_t Dx0[ 15 ];

/** Matrix of size: 15 x 15 (row major format) */
real_t T[ 225 ];

/** Matrix of size: 825 x 5 (row major format) */
real_t E[ 4125 ];

/** Matrix of size: 825 x 5 (row major format) */
real_t QE[ 4125 ];

/** Column vector of size: 150 */
real_t Qd[ 150 ];

/** Column vector of size: 165 */
real_t QDy[ 165 ];

/** Matrix of size: 50 x 15 (row major format) */
real_t H10[ 750 ];

/** Matrix of size: 20 x 15 (row major format) */
real_t A01[ 300 ];

/** Column vector of size: 20 */
real_t pacA01Dx0[ 20 ];

/** Matrix of size: 50 x 50 (row major format) */
real_t H[ 2500 ];

/** Matrix of size: 40 x 50 (row major format) */
real_t A[ 2000 ];

/** Column vector of size: 50 */
real_t g[ 50 ];

/** Column vector of size: 50 */
real_t lb[ 50 ];

/** Column vector of size: 50 */
real_t ub[ 50 ];

/** Column vector of size: 40 */
real_t lbA[ 40 ];

/** Column vector of size: 40 */
real_t ubA[ 40 ];

/** Column vector of size: 50 */
real_t x[ 50 ];

/** Column vector of size: 90 */
real_t y[ 90 ];


} ACADOworkspace;

/* 
 * Forward function declarations. 
 */


/** Performs the integration and sensitivity propagation for one shooting interval.
 *
 *  \param rk_eta Working array of size 25 to pass the input values and return the results.
 *  \param resetIntegrator The internal memory of the integrator can be reset.
 *
 *  \return Status code of the integrator.
 */
int integrate( real_t* const rk_eta, int resetIntegrator );

/** Export of an ACADO symbolic function.
 *
 *  \param in Input to the exported function.
 *  \param out Output of the exported function.
 */
void acado_rhs(const real_t* in, real_t* out);

/** Preparation step of the RTI scheme.
 *
 *  \return Status of the integration module. =0: OK, otherwise the error code.
 */
int preparationStep(  );

/** Feedback/estimation step of the RTI scheme.
 *
 *  \return Status code of the qpOASES QP solver.
 */
int feedbackStep(  );

/** Solver initialization. Must be called once before any other function call.
 *
 *  \return =0: OK, otherwise an error code of a QP solver.
 */
int initializeSolver(  );

/** Initialize shooting nodes by a forward simulation starting from the first node.
 */
void initializeNodesByForwardSimulation(  );

/** Shift differential variables vector by one interval.
 *
 *  \param strategy Shifting strategy: 1. Initialize node 11 with xEnd. 2. Initialize node 11 by forward simulation.
 *  \param xEnd Value for the x vector on the last node. If =0 the old value is used.
 *  \param uEnd Value for the u vector on the second to last node. If =0 the old value is used.
 */
void shiftStates( int strategy, real_t* const xEnd, real_t* const uEnd );

/** Shift controls vector by one interval.
 *
 *  \param uEnd Value for the u vector on the second to last node. If =0 the old value is used.
 */
void shiftControls( real_t* const uEnd );

/** Get the KKT tolerance of the current iterate.
 *
 *  \return The KKT tolerance value.
 */
real_t getKKT(  );

/** Calculate the objective value.
 *
 *  \return Value of the objective function.
 */
real_t getObjective(  );


/* 
 * Extern declarations. 
 */

extern ACADOworkspace acadoWorkspace;
extern ACADOvariables acadoVariables;

/** @} */

#ifndef __MATLAB__
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
#endif /* __MATLAB__ */

#endif /* ACADO_COMMON_H */
