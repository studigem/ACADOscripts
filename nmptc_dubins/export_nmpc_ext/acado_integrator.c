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


#include "acado_common.h"


void solve_dim14_triangular( real_t* const A, real_t* const b )
{

b[13] = b[13]/A[195];
b[12] -= + A[181]*b[13];
b[12] = b[12]/A[180];
b[11] -= + A[167]*b[13];
b[11] -= + A[166]*b[12];
b[11] = b[11]/A[165];
b[10] -= + A[153]*b[13];
b[10] -= + A[152]*b[12];
b[10] -= + A[151]*b[11];
b[10] = b[10]/A[150];
b[9] -= + A[139]*b[13];
b[9] -= + A[138]*b[12];
b[9] -= + A[137]*b[11];
b[9] -= + A[136]*b[10];
b[9] = b[9]/A[135];
b[8] -= + A[125]*b[13];
b[8] -= + A[124]*b[12];
b[8] -= + A[123]*b[11];
b[8] -= + A[122]*b[10];
b[8] -= + A[121]*b[9];
b[8] = b[8]/A[120];
b[7] -= + A[111]*b[13];
b[7] -= + A[110]*b[12];
b[7] -= + A[109]*b[11];
b[7] -= + A[108]*b[10];
b[7] -= + A[107]*b[9];
b[7] -= + A[106]*b[8];
b[7] = b[7]/A[105];
b[6] -= + A[97]*b[13];
b[6] -= + A[96]*b[12];
b[6] -= + A[95]*b[11];
b[6] -= + A[94]*b[10];
b[6] -= + A[93]*b[9];
b[6] -= + A[92]*b[8];
b[6] -= + A[91]*b[7];
b[6] = b[6]/A[90];
b[5] -= + A[83]*b[13];
b[5] -= + A[82]*b[12];
b[5] -= + A[81]*b[11];
b[5] -= + A[80]*b[10];
b[5] -= + A[79]*b[9];
b[5] -= + A[78]*b[8];
b[5] -= + A[77]*b[7];
b[5] -= + A[76]*b[6];
b[5] = b[5]/A[75];
b[4] -= + A[69]*b[13];
b[4] -= + A[68]*b[12];
b[4] -= + A[67]*b[11];
b[4] -= + A[66]*b[10];
b[4] -= + A[65]*b[9];
b[4] -= + A[64]*b[8];
b[4] -= + A[63]*b[7];
b[4] -= + A[62]*b[6];
b[4] -= + A[61]*b[5];
b[4] = b[4]/A[60];
b[3] -= + A[55]*b[13];
b[3] -= + A[54]*b[12];
b[3] -= + A[53]*b[11];
b[3] -= + A[52]*b[10];
b[3] -= + A[51]*b[9];
b[3] -= + A[50]*b[8];
b[3] -= + A[49]*b[7];
b[3] -= + A[48]*b[6];
b[3] -= + A[47]*b[5];
b[3] -= + A[46]*b[4];
b[3] = b[3]/A[45];
b[2] -= + A[41]*b[13];
b[2] -= + A[40]*b[12];
b[2] -= + A[39]*b[11];
b[2] -= + A[38]*b[10];
b[2] -= + A[37]*b[9];
b[2] -= + A[36]*b[8];
b[2] -= + A[35]*b[7];
b[2] -= + A[34]*b[6];
b[2] -= + A[33]*b[5];
b[2] -= + A[32]*b[4];
b[2] -= + A[31]*b[3];
b[2] = b[2]/A[30];
b[1] -= + A[27]*b[13];
b[1] -= + A[26]*b[12];
b[1] -= + A[25]*b[11];
b[1] -= + A[24]*b[10];
b[1] -= + A[23]*b[9];
b[1] -= + A[22]*b[8];
b[1] -= + A[21]*b[7];
b[1] -= + A[20]*b[6];
b[1] -= + A[19]*b[5];
b[1] -= + A[18]*b[4];
b[1] -= + A[17]*b[3];
b[1] -= + A[16]*b[2];
b[1] = b[1]/A[15];
b[0] -= + A[13]*b[13];
b[0] -= + A[12]*b[12];
b[0] -= + A[11]*b[11];
b[0] -= + A[10]*b[10];
b[0] -= + A[9]*b[9];
b[0] -= + A[8]*b[8];
b[0] -= + A[7]*b[7];
b[0] -= + A[6]*b[6];
b[0] -= + A[5]*b[5];
b[0] -= + A[4]*b[4];
b[0] -= + A[3]*b[3];
b[0] -= + A[2]*b[2];
b[0] -= + A[1]*b[1];
b[0] = b[0]/A[0];
}

real_t solve_dim14_system( real_t* const A, real_t* const b, int* const rk_perm )
{
real_t det;

int i;
int j;
int k;

int indexMax;

int intSwap;

real_t valueMax;

real_t temp;

for (i = 0; i < 14; ++i)
{
rk_perm[i] = i;
}
det = 1.0000000000000000e+00;
for( i=0; i < (13); i++ ) {
	indexMax = i;
	valueMax = fabs(A[i*14+i]);
	for( j=(i+1); j < 14; j++ ) {
		temp = fabs(A[j*14+i]);
		if( temp > valueMax ) {
			indexMax = j;
			valueMax = temp;
		}
	}
	if( indexMax > i ) {
for (k = 0; k < 14; ++k)
{
	acadoWorkspace.rk_dim14_swap = A[i*14+k];
	A[i*14+k] = A[indexMax*14+k];
	A[indexMax*14+k] = acadoWorkspace.rk_dim14_swap;
}
	acadoWorkspace.rk_dim14_swap = b[i];
	b[i] = b[indexMax];
	b[indexMax] = acadoWorkspace.rk_dim14_swap;
	intSwap = rk_perm[i];
	rk_perm[i] = rk_perm[indexMax];
	rk_perm[indexMax] = intSwap;
	}
	det *= A[i*14+i];
	for( j=i+1; j < 14; j++ ) {
		A[j*14+i] = -A[j*14+i]/A[i*14+i];
		for( k=i+1; k < 14; k++ ) {
			A[j*14+k] += A[j*14+i] * A[i*14+k];
		}
		b[j] += A[j*14+i] * b[i];
	}
}
det *= A[195];
det = fabs(det);
solve_dim14_triangular( A, b );
return det;
}

void solve_dim14_system_reuse( real_t* const A, real_t* const b, int* const rk_perm )
{

acadoWorkspace.rk_dim14_bPerm[0] = b[rk_perm[0]];
acadoWorkspace.rk_dim14_bPerm[1] = b[rk_perm[1]];
acadoWorkspace.rk_dim14_bPerm[2] = b[rk_perm[2]];
acadoWorkspace.rk_dim14_bPerm[3] = b[rk_perm[3]];
acadoWorkspace.rk_dim14_bPerm[4] = b[rk_perm[4]];
acadoWorkspace.rk_dim14_bPerm[5] = b[rk_perm[5]];
acadoWorkspace.rk_dim14_bPerm[6] = b[rk_perm[6]];
acadoWorkspace.rk_dim14_bPerm[7] = b[rk_perm[7]];
acadoWorkspace.rk_dim14_bPerm[8] = b[rk_perm[8]];
acadoWorkspace.rk_dim14_bPerm[9] = b[rk_perm[9]];
acadoWorkspace.rk_dim14_bPerm[10] = b[rk_perm[10]];
acadoWorkspace.rk_dim14_bPerm[11] = b[rk_perm[11]];
acadoWorkspace.rk_dim14_bPerm[12] = b[rk_perm[12]];
acadoWorkspace.rk_dim14_bPerm[13] = b[rk_perm[13]];
acadoWorkspace.rk_dim14_bPerm[1] += A[14]*acadoWorkspace.rk_dim14_bPerm[0];

acadoWorkspace.rk_dim14_bPerm[2] += A[28]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[2] += A[29]*acadoWorkspace.rk_dim14_bPerm[1];

acadoWorkspace.rk_dim14_bPerm[3] += A[42]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[3] += A[43]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[3] += A[44]*acadoWorkspace.rk_dim14_bPerm[2];

acadoWorkspace.rk_dim14_bPerm[4] += A[56]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[4] += A[57]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[4] += A[58]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[4] += A[59]*acadoWorkspace.rk_dim14_bPerm[3];

acadoWorkspace.rk_dim14_bPerm[5] += A[70]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[5] += A[71]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[5] += A[72]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[5] += A[73]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[5] += A[74]*acadoWorkspace.rk_dim14_bPerm[4];

acadoWorkspace.rk_dim14_bPerm[6] += A[84]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[6] += A[85]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[6] += A[86]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[6] += A[87]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[6] += A[88]*acadoWorkspace.rk_dim14_bPerm[4];
acadoWorkspace.rk_dim14_bPerm[6] += A[89]*acadoWorkspace.rk_dim14_bPerm[5];

acadoWorkspace.rk_dim14_bPerm[7] += A[98]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[7] += A[99]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[7] += A[100]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[7] += A[101]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[7] += A[102]*acadoWorkspace.rk_dim14_bPerm[4];
acadoWorkspace.rk_dim14_bPerm[7] += A[103]*acadoWorkspace.rk_dim14_bPerm[5];
acadoWorkspace.rk_dim14_bPerm[7] += A[104]*acadoWorkspace.rk_dim14_bPerm[6];

acadoWorkspace.rk_dim14_bPerm[8] += A[112]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[8] += A[113]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[8] += A[114]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[8] += A[115]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[8] += A[116]*acadoWorkspace.rk_dim14_bPerm[4];
acadoWorkspace.rk_dim14_bPerm[8] += A[117]*acadoWorkspace.rk_dim14_bPerm[5];
acadoWorkspace.rk_dim14_bPerm[8] += A[118]*acadoWorkspace.rk_dim14_bPerm[6];
acadoWorkspace.rk_dim14_bPerm[8] += A[119]*acadoWorkspace.rk_dim14_bPerm[7];

acadoWorkspace.rk_dim14_bPerm[9] += A[126]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[9] += A[127]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[9] += A[128]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[9] += A[129]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[9] += A[130]*acadoWorkspace.rk_dim14_bPerm[4];
acadoWorkspace.rk_dim14_bPerm[9] += A[131]*acadoWorkspace.rk_dim14_bPerm[5];
acadoWorkspace.rk_dim14_bPerm[9] += A[132]*acadoWorkspace.rk_dim14_bPerm[6];
acadoWorkspace.rk_dim14_bPerm[9] += A[133]*acadoWorkspace.rk_dim14_bPerm[7];
acadoWorkspace.rk_dim14_bPerm[9] += A[134]*acadoWorkspace.rk_dim14_bPerm[8];

acadoWorkspace.rk_dim14_bPerm[10] += A[140]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[10] += A[141]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[10] += A[142]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[10] += A[143]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[10] += A[144]*acadoWorkspace.rk_dim14_bPerm[4];
acadoWorkspace.rk_dim14_bPerm[10] += A[145]*acadoWorkspace.rk_dim14_bPerm[5];
acadoWorkspace.rk_dim14_bPerm[10] += A[146]*acadoWorkspace.rk_dim14_bPerm[6];
acadoWorkspace.rk_dim14_bPerm[10] += A[147]*acadoWorkspace.rk_dim14_bPerm[7];
acadoWorkspace.rk_dim14_bPerm[10] += A[148]*acadoWorkspace.rk_dim14_bPerm[8];
acadoWorkspace.rk_dim14_bPerm[10] += A[149]*acadoWorkspace.rk_dim14_bPerm[9];

acadoWorkspace.rk_dim14_bPerm[11] += A[154]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[11] += A[155]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[11] += A[156]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[11] += A[157]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[11] += A[158]*acadoWorkspace.rk_dim14_bPerm[4];
acadoWorkspace.rk_dim14_bPerm[11] += A[159]*acadoWorkspace.rk_dim14_bPerm[5];
acadoWorkspace.rk_dim14_bPerm[11] += A[160]*acadoWorkspace.rk_dim14_bPerm[6];
acadoWorkspace.rk_dim14_bPerm[11] += A[161]*acadoWorkspace.rk_dim14_bPerm[7];
acadoWorkspace.rk_dim14_bPerm[11] += A[162]*acadoWorkspace.rk_dim14_bPerm[8];
acadoWorkspace.rk_dim14_bPerm[11] += A[163]*acadoWorkspace.rk_dim14_bPerm[9];
acadoWorkspace.rk_dim14_bPerm[11] += A[164]*acadoWorkspace.rk_dim14_bPerm[10];

acadoWorkspace.rk_dim14_bPerm[12] += A[168]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[12] += A[169]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[12] += A[170]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[12] += A[171]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[12] += A[172]*acadoWorkspace.rk_dim14_bPerm[4];
acadoWorkspace.rk_dim14_bPerm[12] += A[173]*acadoWorkspace.rk_dim14_bPerm[5];
acadoWorkspace.rk_dim14_bPerm[12] += A[174]*acadoWorkspace.rk_dim14_bPerm[6];
acadoWorkspace.rk_dim14_bPerm[12] += A[175]*acadoWorkspace.rk_dim14_bPerm[7];
acadoWorkspace.rk_dim14_bPerm[12] += A[176]*acadoWorkspace.rk_dim14_bPerm[8];
acadoWorkspace.rk_dim14_bPerm[12] += A[177]*acadoWorkspace.rk_dim14_bPerm[9];
acadoWorkspace.rk_dim14_bPerm[12] += A[178]*acadoWorkspace.rk_dim14_bPerm[10];
acadoWorkspace.rk_dim14_bPerm[12] += A[179]*acadoWorkspace.rk_dim14_bPerm[11];

acadoWorkspace.rk_dim14_bPerm[13] += A[182]*acadoWorkspace.rk_dim14_bPerm[0];
acadoWorkspace.rk_dim14_bPerm[13] += A[183]*acadoWorkspace.rk_dim14_bPerm[1];
acadoWorkspace.rk_dim14_bPerm[13] += A[184]*acadoWorkspace.rk_dim14_bPerm[2];
acadoWorkspace.rk_dim14_bPerm[13] += A[185]*acadoWorkspace.rk_dim14_bPerm[3];
acadoWorkspace.rk_dim14_bPerm[13] += A[186]*acadoWorkspace.rk_dim14_bPerm[4];
acadoWorkspace.rk_dim14_bPerm[13] += A[187]*acadoWorkspace.rk_dim14_bPerm[5];
acadoWorkspace.rk_dim14_bPerm[13] += A[188]*acadoWorkspace.rk_dim14_bPerm[6];
acadoWorkspace.rk_dim14_bPerm[13] += A[189]*acadoWorkspace.rk_dim14_bPerm[7];
acadoWorkspace.rk_dim14_bPerm[13] += A[190]*acadoWorkspace.rk_dim14_bPerm[8];
acadoWorkspace.rk_dim14_bPerm[13] += A[191]*acadoWorkspace.rk_dim14_bPerm[9];
acadoWorkspace.rk_dim14_bPerm[13] += A[192]*acadoWorkspace.rk_dim14_bPerm[10];
acadoWorkspace.rk_dim14_bPerm[13] += A[193]*acadoWorkspace.rk_dim14_bPerm[11];
acadoWorkspace.rk_dim14_bPerm[13] += A[194]*acadoWorkspace.rk_dim14_bPerm[12];


solve_dim14_triangular( A, acadoWorkspace.rk_dim14_bPerm );
b[0] = acadoWorkspace.rk_dim14_bPerm[0];
b[1] = acadoWorkspace.rk_dim14_bPerm[1];
b[2] = acadoWorkspace.rk_dim14_bPerm[2];
b[3] = acadoWorkspace.rk_dim14_bPerm[3];
b[4] = acadoWorkspace.rk_dim14_bPerm[4];
b[5] = acadoWorkspace.rk_dim14_bPerm[5];
b[6] = acadoWorkspace.rk_dim14_bPerm[6];
b[7] = acadoWorkspace.rk_dim14_bPerm[7];
b[8] = acadoWorkspace.rk_dim14_bPerm[8];
b[9] = acadoWorkspace.rk_dim14_bPerm[9];
b[10] = acadoWorkspace.rk_dim14_bPerm[10];
b[11] = acadoWorkspace.rk_dim14_bPerm[11];
b[12] = acadoWorkspace.rk_dim14_bPerm[12];
b[13] = acadoWorkspace.rk_dim14_bPerm[13];
}



/** Matrix of size: 2 x 2 (row major format) */
static const real_t Ah_mat[ 4 ] = 
{ 2.5000000000000001e-02, 5.3867513459481292e-02, 
-3.8675134594812867e-03, 2.5000000000000001e-02 };


/* Fixed step size:0.1 */
int integrate( real_t* const rk_eta, int resetIntegrator )
{
int error;

int i;
int j;
int k;
int run;
int run1;
int tmp_index1;
int tmp_index2;

real_t det;

acadoWorkspace.rk_ttt = 0.0000000000000000e+00;
acadoWorkspace.rk_xxx[7] = rk_eta[70];
acadoWorkspace.rk_xxx[8] = rk_eta[71];
acadoWorkspace.rk_xxx[9] = rk_eta[72];
acadoWorkspace.rk_xxx[10] = rk_eta[73];
acadoWorkspace.rk_xxx[11] = rk_eta[74];
acadoWorkspace.rk_xxx[12] = rk_eta[75];
acadoWorkspace.rk_xxx[13] = rk_eta[76];
acadoWorkspace.rk_xxx[14] = rk_eta[77];
acadoWorkspace.rk_xxx[15] = rk_eta[78];
acadoWorkspace.rk_xxx[16] = rk_eta[79];
acadoWorkspace.rk_xxx[17] = rk_eta[80];
acadoWorkspace.rk_xxx[18] = rk_eta[81];
acadoWorkspace.rk_xxx[19] = rk_eta[82];
acadoWorkspace.rk_xxx[20] = rk_eta[83];
acadoWorkspace.rk_xxx[21] = rk_eta[84];
acadoWorkspace.rk_xxx[22] = rk_eta[85];
acadoWorkspace.rk_xxx[23] = rk_eta[86];
acadoWorkspace.rk_xxx[24] = rk_eta[87];
acadoWorkspace.rk_xxx[25] = rk_eta[88];
acadoWorkspace.rk_xxx[26] = rk_eta[89];
acadoWorkspace.rk_xxx[27] = rk_eta[90];
acadoWorkspace.rk_xxx[28] = rk_eta[91];
acadoWorkspace.rk_xxx[29] = rk_eta[92];
acadoWorkspace.rk_xxx[30] = rk_eta[93];
acadoWorkspace.rk_xxx[31] = rk_eta[94];
acadoWorkspace.rk_xxx[32] = rk_eta[95];

for (run = 0; run < 1; ++run)
{
if( resetIntegrator ) {
for (i = 0; i < 1; ++i)
{
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 7; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + Ah_mat[run1 * 2]*acadoWorkspace.rk_kkk[tmp_index1 * 2];
acadoWorkspace.rk_xxx[j] += + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
rhs_jac( acadoWorkspace.rk_xxx, &(acadoWorkspace.rk_diffsTemp2[ run1 * 63 ]) );
for (j = 0; j < 7; ++j)
{
tmp_index1 = (run1 * 7) + (j);
acadoWorkspace.rk_A[tmp_index1 * 14] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 1] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 2] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 3] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 4] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 5] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 6] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 6)];
if( 0 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 14) + (j)] -= 1.0000000000000000e+00;
acadoWorkspace.rk_A[tmp_index1 * 14 + 7] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 8] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 9] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 10] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 11] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 12] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 13] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 6)];
if( 1 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 14) + (j + 7)] -= 1.0000000000000000e+00;
}
rhs( acadoWorkspace.rk_xxx, acadoWorkspace.rk_rhsTemp );
acadoWorkspace.rk_b[run1 * 7] = acadoWorkspace.rk_kkk[run1] - acadoWorkspace.rk_rhsTemp[0];
acadoWorkspace.rk_b[run1 * 7 + 1] = acadoWorkspace.rk_kkk[run1 + 2] - acadoWorkspace.rk_rhsTemp[1];
acadoWorkspace.rk_b[run1 * 7 + 2] = acadoWorkspace.rk_kkk[run1 + 4] - acadoWorkspace.rk_rhsTemp[2];
acadoWorkspace.rk_b[run1 * 7 + 3] = acadoWorkspace.rk_kkk[run1 + 6] - acadoWorkspace.rk_rhsTemp[3];
acadoWorkspace.rk_b[run1 * 7 + 4] = acadoWorkspace.rk_kkk[run1 + 8] - acadoWorkspace.rk_rhsTemp[4];
acadoWorkspace.rk_b[run1 * 7 + 5] = acadoWorkspace.rk_kkk[run1 + 10] - acadoWorkspace.rk_rhsTemp[5];
acadoWorkspace.rk_b[run1 * 7 + 6] = acadoWorkspace.rk_kkk[run1 + 12] - acadoWorkspace.rk_rhsTemp[6];
}
det = solve_dim14_system( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim14_perm );
for (j = 0; j < 2; ++j)
{
acadoWorkspace.rk_kkk[j] += acadoWorkspace.rk_b[j * 7];
acadoWorkspace.rk_kkk[j + 2] += acadoWorkspace.rk_b[j * 7 + 1];
acadoWorkspace.rk_kkk[j + 4] += acadoWorkspace.rk_b[j * 7 + 2];
acadoWorkspace.rk_kkk[j + 6] += acadoWorkspace.rk_b[j * 7 + 3];
acadoWorkspace.rk_kkk[j + 8] += acadoWorkspace.rk_b[j * 7 + 4];
acadoWorkspace.rk_kkk[j + 10] += acadoWorkspace.rk_b[j * 7 + 5];
acadoWorkspace.rk_kkk[j + 12] += acadoWorkspace.rk_b[j * 7 + 6];
}
}
}
for (i = 0; i < 5; ++i)
{
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 7; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + Ah_mat[run1 * 2]*acadoWorkspace.rk_kkk[tmp_index1 * 2];
acadoWorkspace.rk_xxx[j] += + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
rhs( acadoWorkspace.rk_xxx, acadoWorkspace.rk_rhsTemp );
acadoWorkspace.rk_b[run1 * 7] = acadoWorkspace.rk_kkk[run1] - acadoWorkspace.rk_rhsTemp[0];
acadoWorkspace.rk_b[run1 * 7 + 1] = acadoWorkspace.rk_kkk[run1 + 2] - acadoWorkspace.rk_rhsTemp[1];
acadoWorkspace.rk_b[run1 * 7 + 2] = acadoWorkspace.rk_kkk[run1 + 4] - acadoWorkspace.rk_rhsTemp[2];
acadoWorkspace.rk_b[run1 * 7 + 3] = acadoWorkspace.rk_kkk[run1 + 6] - acadoWorkspace.rk_rhsTemp[3];
acadoWorkspace.rk_b[run1 * 7 + 4] = acadoWorkspace.rk_kkk[run1 + 8] - acadoWorkspace.rk_rhsTemp[4];
acadoWorkspace.rk_b[run1 * 7 + 5] = acadoWorkspace.rk_kkk[run1 + 10] - acadoWorkspace.rk_rhsTemp[5];
acadoWorkspace.rk_b[run1 * 7 + 6] = acadoWorkspace.rk_kkk[run1 + 12] - acadoWorkspace.rk_rhsTemp[6];
}
solve_dim14_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim14_perm );
for (j = 0; j < 2; ++j)
{
acadoWorkspace.rk_kkk[j] += acadoWorkspace.rk_b[j * 7];
acadoWorkspace.rk_kkk[j + 2] += acadoWorkspace.rk_b[j * 7 + 1];
acadoWorkspace.rk_kkk[j + 4] += acadoWorkspace.rk_b[j * 7 + 2];
acadoWorkspace.rk_kkk[j + 6] += acadoWorkspace.rk_b[j * 7 + 3];
acadoWorkspace.rk_kkk[j + 8] += acadoWorkspace.rk_b[j * 7 + 4];
acadoWorkspace.rk_kkk[j + 10] += acadoWorkspace.rk_b[j * 7 + 5];
acadoWorkspace.rk_kkk[j + 12] += acadoWorkspace.rk_b[j * 7 + 6];
}
}
for (run1 = 0; run1 < 2; ++run1)
{
for (j = 0; j < 7; ++j)
{
acadoWorkspace.rk_xxx[j] = rk_eta[j];
tmp_index1 = j;
acadoWorkspace.rk_xxx[j] += + Ah_mat[run1 * 2]*acadoWorkspace.rk_kkk[tmp_index1 * 2];
acadoWorkspace.rk_xxx[j] += + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_kkk[tmp_index1 * 2 + 1];
}
rhs_jac( acadoWorkspace.rk_xxx, &(acadoWorkspace.rk_diffsTemp2[ run1 * 63 ]) );
for (j = 0; j < 7; ++j)
{
tmp_index1 = (run1 * 7) + (j);
acadoWorkspace.rk_A[tmp_index1 * 14] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 1] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 2] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 3] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 4] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 5] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 6] = + Ah_mat[run1 * 2]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 6)];
if( 0 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 14) + (j)] -= 1.0000000000000000e+00;
acadoWorkspace.rk_A[tmp_index1 * 14 + 7] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 8] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 1)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 9] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 2)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 10] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 3)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 11] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 4)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 12] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 5)];
acadoWorkspace.rk_A[tmp_index1 * 14 + 13] = + Ah_mat[run1 * 2 + 1]*acadoWorkspace.rk_diffsTemp2[(run1 * 63) + (j * 9 + 6)];
if( 1 == run1 ) acadoWorkspace.rk_A[(tmp_index1 * 14) + (j + 7)] -= 1.0000000000000000e+00;
}
}
for (run1 = 0; run1 < 7; ++run1)
{
for (i = 0; i < 2; ++i)
{
acadoWorkspace.rk_b[i * 7] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1)];
acadoWorkspace.rk_b[i * 7 + 1] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 9)];
acadoWorkspace.rk_b[i * 7 + 2] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 18)];
acadoWorkspace.rk_b[i * 7 + 3] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 27)];
acadoWorkspace.rk_b[i * 7 + 4] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 36)];
acadoWorkspace.rk_b[i * 7 + 5] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 45)];
acadoWorkspace.rk_b[i * 7 + 6] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (run1 + 54)];
}
if( 0 == run1 ) {
det = solve_dim14_system( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim14_perm );
}
 else {
solve_dim14_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim14_perm );
}
for (i = 0; i < 2; ++i)
{
acadoWorkspace.rk_diffK[i] = acadoWorkspace.rk_b[i * 7];
acadoWorkspace.rk_diffK[i + 2] = acadoWorkspace.rk_b[i * 7 + 1];
acadoWorkspace.rk_diffK[i + 4] = acadoWorkspace.rk_b[i * 7 + 2];
acadoWorkspace.rk_diffK[i + 6] = acadoWorkspace.rk_b[i * 7 + 3];
acadoWorkspace.rk_diffK[i + 8] = acadoWorkspace.rk_b[i * 7 + 4];
acadoWorkspace.rk_diffK[i + 10] = acadoWorkspace.rk_b[i * 7 + 5];
acadoWorkspace.rk_diffK[i + 12] = acadoWorkspace.rk_b[i * 7 + 6];
}
for (i = 0; i < 7; ++i)
{
acadoWorkspace.rk_diffsNew2[(i * 9) + (run1)] = (i == run1-0);
acadoWorkspace.rk_diffsNew2[(i * 9) + (run1)] += + acadoWorkspace.rk_diffK[i * 2]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_diffK[i * 2 + 1]*(real_t)5.0000000000000003e-02;
}
}
for (run1 = 0; run1 < 2; ++run1)
{
for (i = 0; i < 2; ++i)
{
for (j = 0; j < 7; ++j)
{
tmp_index1 = (i * 7) + (j);
tmp_index2 = (run1) + (j * 9);
acadoWorkspace.rk_b[tmp_index1] = - acadoWorkspace.rk_diffsTemp2[(i * 63) + (tmp_index2 + 7)];
}
}
solve_dim14_system_reuse( acadoWorkspace.rk_A, acadoWorkspace.rk_b, acadoWorkspace.rk_dim14_perm );
for (i = 0; i < 2; ++i)
{
acadoWorkspace.rk_diffK[i] = acadoWorkspace.rk_b[i * 7];
acadoWorkspace.rk_diffK[i + 2] = acadoWorkspace.rk_b[i * 7 + 1];
acadoWorkspace.rk_diffK[i + 4] = acadoWorkspace.rk_b[i * 7 + 2];
acadoWorkspace.rk_diffK[i + 6] = acadoWorkspace.rk_b[i * 7 + 3];
acadoWorkspace.rk_diffK[i + 8] = acadoWorkspace.rk_b[i * 7 + 4];
acadoWorkspace.rk_diffK[i + 10] = acadoWorkspace.rk_b[i * 7 + 5];
acadoWorkspace.rk_diffK[i + 12] = acadoWorkspace.rk_b[i * 7 + 6];
}
for (i = 0; i < 7; ++i)
{
acadoWorkspace.rk_diffsNew2[(i * 9) + (run1 + 7)] = + acadoWorkspace.rk_diffK[i * 2]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_diffK[i * 2 + 1]*(real_t)5.0000000000000003e-02;
}
}
rk_eta[0] += + acadoWorkspace.rk_kkk[0]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_kkk[1]*(real_t)5.0000000000000003e-02;
rk_eta[1] += + acadoWorkspace.rk_kkk[2]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_kkk[3]*(real_t)5.0000000000000003e-02;
rk_eta[2] += + acadoWorkspace.rk_kkk[4]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_kkk[5]*(real_t)5.0000000000000003e-02;
rk_eta[3] += + acadoWorkspace.rk_kkk[6]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_kkk[7]*(real_t)5.0000000000000003e-02;
rk_eta[4] += + acadoWorkspace.rk_kkk[8]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_kkk[9]*(real_t)5.0000000000000003e-02;
rk_eta[5] += + acadoWorkspace.rk_kkk[10]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_kkk[11]*(real_t)5.0000000000000003e-02;
rk_eta[6] += + acadoWorkspace.rk_kkk[12]*(real_t)5.0000000000000003e-02 + acadoWorkspace.rk_kkk[13]*(real_t)5.0000000000000003e-02;
for (i = 0; i < 7; ++i)
{
for (j = 0; j < 7; ++j)
{
tmp_index2 = (j) + (i * 7);
rk_eta[tmp_index2 + 7] = acadoWorkspace.rk_diffsNew2[(i * 9) + (j)];
}
for (j = 0; j < 2; ++j)
{
tmp_index2 = (j) + (i * 2);
rk_eta[tmp_index2 + 56] = acadoWorkspace.rk_diffsNew2[(i * 9) + (j + 7)];
}
}
resetIntegrator = 0;
acadoWorkspace.rk_ttt += 1.0000000000000000e+00;
}
for (i = 0; i < 7; ++i)
{
}
if( det < 1e-12 ) {
error = 2;
} else if( det < 1e-6 ) {
error = 1;
} else {
error = 0;
}
return error;
}


