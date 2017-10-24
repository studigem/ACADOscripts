#include "acado_common.h"
#include <math.h>
#include <string.h>
#include <stdbool.h>

bool check_line_seg( const double *pos, const double *vel, const double *params );
bool check_curve_seg( const double *pos, const double *vel, const double *params );

void rhs( const real_t *in, real_t *out ){

/* for manual input indexing ... */

const int minus_NU = 0;

/* optimized intermediate calculations */

const double t2 = cos(in[4]);
const double t22 = sin(in[4]);

const double alpha = -in[4]+in[7];

double Vsafe = in[3];
if (Vsafe<1.0) Vsafe = 1.0;

const double n_dot = in[32]+Vsafe*t2*cos(in[5]);
const double e_dot = in[33]+Vsafe*t2*sin(in[5]);
const double d_dot = in[34]-Vsafe*t22;

/* begin manual input !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

// CHECK SEGMENT SWITCHING CONDITIONS //TODO: put this in a function!
const int idx_OD_0 = ACADO_NX+ACADO_NU-minus_NU;
bool b_switch_segment = false;
int pparam_sel = 0;
double sw_dot = 0.0;
if ( in[ACADO_NX-1] < 0.05 ) { // check x_sw
    const double vel[3] = {n_dot,e_dot,d_dot};
    if ( in[idx_OD_0] < 0.5 ) { // path type
        b_switch_segment = check_line_seg( &in[0], &vel[0], &in[idx_OD_0] );
    } else if (in[idx_OD_0] < 1.5 ) {
        b_switch_segment = check_curve_seg( &in[0], &vel[0], &in[idx_OD_0] );
    }
} else {
    b_switch_segment = true;
}
if (b_switch_segment) {
    pparam_sel = 7;
    sw_dot = 1.0;
} 

/* end manual input !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

const double t23 = in[11]*in[11];
const double t24 = 1.0/Vsafe;
const double t25 = Vsafe*Vsafe;
const double t26 = alpha*alpha;
const double t27 = in[11]*8.61861E1;
const double t28 = in[11]*t23*2.501023E2;
const double t36 = t23*3.05322E1;
const double t29 = t27+t28-t36;
const double t30 = alpha*5.0996;
const double t31 = t26*(-5.343)+t30+1.7E1/3.2E1;
const double t32 = t25*t31*2.38875E-1;
const double t33 = cos(alpha);
const double t34 = 1.0/t33;
const double t35 = sin(alpha);
const double t37 = t24*t29*t34*t35;
const double t38 = t32+t37;
const double t39 = cos(in[6]);
const double t40 = sin(in[6]);

/* rhs */

out[0] = n_dot;
out[1] = e_dot;
out[2] = d_dot;
out[3] = t22*(-9.81E2/1.0E2)+t24*t29*(2.0E1/5.3E1)-t25*(alpha*2.5491E-1+t26*2.7337+6.4105E-2)*9.014150943396226E-2;
out[4] = -t24*(t2*(9.81E2/1.0E2)-t38*t39*(2.0E1/5.3E1));
out[5] = (t24*t38*t40*(2.0E1/5.3E1))/t2;
out[6] = in[8];
out[7] = in[9]*t39-in[10]*t40;
out[8] = in[6]*(-1.24716E1)-in[8]*7.4252+in[10]*1.0069+in[14]*1.24716E1;
out[9] = -t25*(alpha*1.9303E-1+in[7]*1.8359E-1+in[9]*4.6239E-2-in[15]*1.8359E-1-9.4955E-4);
out[10] = in[6]*5.7996-in[10]*9.5153+in[14]*1.5967;
out[11] = in[11]*(-4.143016944939305)+in[13]*4.143016944939305;
out[12] = sw_dot;

}

void rhs_eval( real_t *in, real_t *out ){

/* for manual input indexing ... */

const int minus_NU = 0;

/* optimized intermediate calculations */

const double t2 = cos(in[4]);
const double t22 = sin(in[4]);

const double alpha = -in[4]+in[7];

double Vsafe = in[3];
if (Vsafe<1.0) Vsafe = 1.0;

const double n_dot = in[32]+Vsafe*t2*cos(in[5]);
const double e_dot = in[33]+Vsafe*t2*sin(in[5]);
const double d_dot = in[34]-Vsafe*t22;

/* begin manual input !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

// CHECK SEGMENT SWITCHING CONDITIONS //TODO: put this in a function!
const int idx_OD_0 = ACADO_NX+ACADO_NU-minus_NU;
bool b_switch_segment = false;
int pparam_sel = 0;
double sw_dot = 0.0;
if ( in[ACADO_NX-1] < 0.05 ) { // check x_sw
    const double vel[3] = {n_dot,e_dot,d_dot};
    if ( in[idx_OD_0] < 0.5 ) { // path type
        b_switch_segment = check_line_seg( &in[0], &vel[0], &in[idx_OD_0] );
    } else if (in[idx_OD_0] < 1.5 ) {
        b_switch_segment = check_curve_seg( &in[0], &vel[0], &in[idx_OD_0] );
    }
} else {
    b_switch_segment = true;
}
if (b_switch_segment) {
    pparam_sel = 7;
    sw_dot = 1.0;
} 

/* end manual input !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

const double t23 = in[11]*in[11];
const double t24 = 1.0/Vsafe;
const double t25 = Vsafe*Vsafe;
const double t26 = alpha*alpha;
const double t27 = in[11]*8.61861E1;
const double t28 = in[11]*t23*2.501023E2;
const double t36 = t23*3.05322E1;
const double t29 = t27+t28-t36;
const double t30 = alpha*5.0996;
const double t31 = t26*(-5.343)+t30+1.7E1/3.2E1;
const double t32 = t25*t31*2.38875E-1;
const double t33 = cos(alpha);
const double t34 = 1.0/t33;
const double t35 = sin(alpha);
const double t37 = t24*t29*t34*t35;
const double t38 = t32+t37;
const double t39 = cos(in[6]);
const double t40 = sin(in[6]);

/* rhs */

out[0] = n_dot;
out[1] = e_dot;
out[2] = d_dot;
out[3] = t22*(-9.81E2/1.0E2)+t24*t29*(2.0E1/5.3E1)-t25*(alpha*2.5491E-1+t26*2.7337+6.4105E-2)*9.014150943396226E-2;
out[4] = -t24*(t2*(9.81E2/1.0E2)-t38*t39*(2.0E1/5.3E1));
out[5] = (t24*t38*t40*(2.0E1/5.3E1))/t2;
out[6] = in[8];
out[7] = in[9]*t39-in[10]*t40;
out[8] = in[6]*(-1.24716E1)-in[8]*7.4252+in[10]*1.0069+in[14]*1.24716E1;
out[9] = -t25*(alpha*1.9303E-1+in[7]*1.8359E-1+in[9]*4.6239E-2-in[15]*1.8359E-1-9.4955E-4);
out[10] = in[6]*5.7996-in[10]*9.5153+in[14]*1.5967;
out[11] = in[11]*(-4.143016944939305)+in[13]*4.143016944939305;
out[12] = sw_dot;

}

void rhs_jac( const real_t *in, real_t *out ){

/* rhs_jac */
 
double f_Delta_m[ACADO_NX];
double f_Delta_p[ACADO_NX];
double in_Delta[ACADO_NX+ACADO_NU+ACADO_NOD];
memcpy(in_Delta, in, sizeof(in_Delta));
const double Delta = 0.00001;
const double Delta2 = 2.0 * Delta;
 
int i;
int j;
for (i = 0; i < (ACADO_NX+ACADO_NU); i=i+1) {
 
    in_Delta[i] = in[i] - Delta;
    rhs_eval( in_Delta, f_Delta_m );
    in_Delta[i] = in[i] + Delta;
    rhs_eval( in_Delta, f_Delta_p );
    in_Delta[i] = in[i];
 
    for (j = 0; j < ACADO_NX; j=j+1) {
        out[j*(ACADO_NX+ACADO_NU)+i] = (f_Delta_p[j] - f_Delta_m[j]) / Delta2;
    }
 
}

}

void lsq_obj_eval( real_t *in, real_t *out ){

/* for manual input indexing ... */

const int minus_NU = 0;

/* optimized intermediate calculations */

const double t2 = cos(in[4]);

const double alpha = -in[4]+in[7];

double Vsafe = in[3];
if (Vsafe<1.0) Vsafe = 1.0;

const double n_dot = in[32]+Vsafe*t2*cos(in[5]);
const double e_dot = in[33]+Vsafe*t2*sin(in[5]);
const double d_dot = in[34]-Vsafe*sin(in[4]);

/* begin manual input !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

// CHECK SEGMENT SWITCHING CONDITIONS //TODO: put this in a function!
const int idx_OD_0 = ACADO_NX+ACADO_NU-minus_NU;
bool b_switch_segment = false;
int pparam_sel = 0;
double sw_dot = 0.0;
if ( in[ACADO_NX-1] < 0.05 ) { // check x_sw
    const double vel[3] = {n_dot,e_dot,d_dot};
    if ( in[idx_OD_0] < 0.5 ) { // path type
        b_switch_segment = check_line_seg( &in[0], &vel[0], &in[idx_OD_0] );
    } else if (in[idx_OD_0] < 1.5 ) {
        b_switch_segment = check_curve_seg( &in[0], &vel[0], &in[idx_OD_0] );
    }
} else {
    b_switch_segment = true;
}
if (b_switch_segment) {
    pparam_sel = 7;
    sw_dot = 1.0;
} 

double p_n = 0.0;
double p_e = 0.0;
double p_d = 0.0;
double tP_n = 1.0;
double tP_e = 0.0;
double tP_d = 0.0;

const double pparam_type = in[idx_OD_0+pparam_sel];

double phi_ff = 0.0;

// LINE SEGMENT
if ( pparam_type < 0.5 ) {

    // calculate tangent
    double tP_n = cos(in[idx_OD_0+pparam_sel+6])*cos(in[idx_OD_0+pparam_sel+5]);
    double tP_e = cos(in[idx_OD_0+pparam_sel+6])*sin(in[idx_OD_0+pparam_sel+5]);
    double tP_d = -sin(in[idx_OD_0+pparam_sel+6]);
    
    // dot product
    const double dot_tP_bp = tP_n*(in[0] - in[idx_OD_0+pparam_sel+1]) + tP_e*(in[1] - in[idx_OD_0+pparam_sel+2]) + tP_d*(in[2] - in[idx_OD_0+pparam_sel+3]);
    
    // point on track
    p_n = in[idx_OD_0+pparam_sel+1] + dot_tP_bp * tP_n;
    p_e = in[idx_OD_0+pparam_sel+2] + dot_tP_bp * tP_e;
    p_d = in[idx_OD_0+pparam_sel+3] + dot_tP_bp * tP_d;
    
    // feed forward
    phi_ff = 0.0;
    
// ARC SEGMENT
} else if ( pparam_type < 1.5 ) {

// variable definitions
//     const double pparam_cc_n = in[idx_OD_0+pparam_sel+1];
//     const double pparam_cc_e = in[idx_OD_0+pparam_sel+2];
//     const double pparam_cc_d = in[idx_OD_0+pparam_sel+3];
//     const double pparam_R = fabs(in[idx_OD_0+pparam_sel+4]);
    const double pparam_ldir = (in[idx_OD_0+pparam_sel+4]<0.0) ? -1.0 : 1.0;
//     const double pparam_Chi = in[idx_OD_0+pparam_sel+5];
//     const double pparam_Gam = in[idx_OD_0+pparam_sel+6];
    double Gam_temp = in[idx_OD_0+pparam_sel+6];

    // calculate closest point on loiter circle
    const double cr_n = in[0] - in[idx_OD_0+pparam_sel+1];
    const double cr_e = in[1] - in[idx_OD_0+pparam_sel+2];
    const double norm_cr = sqrt( cr_n*cr_n + cr_e*cr_e );
    double cr_n_unit;
    double cr_e_unit;
    if (norm_cr>0.1) {
        cr_n_unit = cr_n / norm_cr;
        cr_e_unit = cr_e / norm_cr;
    }
    else {
        cr_n_unit = 0.0;
        cr_e_unit = 0.0;
    }
    p_n = fabs(in[idx_OD_0+pparam_sel+4]) * cr_n_unit + in[idx_OD_0+pparam_sel+1];
    p_e = fabs(in[idx_OD_0+pparam_sel+4]) * cr_e_unit + in[idx_OD_0+pparam_sel+2];

    // calculate tangent
    tP_n = pparam_ldir * -cr_e_unit;
    tP_e = pparam_ldir * cr_n_unit;
    
    // angular position
    const double xi_pos = atan2(cr_e_unit, cr_n_unit);
    
    // angular exit
    double xi_exit = in[idx_OD_0+pparam_sel+5] - pparam_ldir * 1.570796326794897;
    if (xi_exit>3.141592653589793) {
        xi_exit = xi_exit - 6.283185307179586;
    }
    else if (xi_exit<-3.141592653589793) {
        xi_exit = xi_exit + 6.283185307179586;
    }
    
    // angular travel (back calculated) from exit [0,2pi)
    double delta_xi = pparam_ldir * (xi_exit - xi_pos);
    if (delta_xi >= 6.28318530718) delta_xi = 0.0;
    if (delta_xi < 0.0) delta_xi = delta_xi + 6.28318530718;

    // closest point on nearest spiral leg and tangent down component
    if (fabs(in[idx_OD_0+pparam_sel+6]) < 0.001) {

        p_d = in[idx_OD_0+pparam_sel+3];
        tP_d = 0.0;

    } else {

        const double RtanGam = fabs(in[idx_OD_0+pparam_sel+4]) * tan(in[idx_OD_0+pparam_sel+6]);

        // height down from exit
        const double delta_d_xi = delta_xi * RtanGam;

        // nearest spiral leg
        const double delta_d_k = round( (in[2] - (in[idx_OD_0+pparam_sel+3] + delta_d_xi)) / (6.28318530718*RtanGam) ) * 6.28318530718*RtanGam;
        
        // closest point on nearest spiral leg
        p_d = in[idx_OD_0+pparam_sel+3] + delta_d_k + delta_d_xi;
        
        // cap end point
        if ((p_d - in[idx_OD_0+pparam_sel+3]) * in[idx_OD_0+pparam_sel+6] < 0.0) {
            p_d = in[idx_OD_0+pparam_sel+3];
            tP_d = 0.0;
            Gam_temp = 0.0;
        }
        else {
            tP_d = -sin(in[idx_OD_0+pparam_sel+6]);
        }
        
    }
    
    if (fabs(tP_n)<0.01 && fabs(tP_e)<0.01) { // should always have lateral-directional references on curve (this is only when we hit the center of the circle)
        tP_n=1.0;
        tP_e=0.0;
    }
    
    // Normalize tP
    tP_n = tP_n * cos(Gam_temp);
    tP_e = tP_e * cos(Gam_temp);
    
    // feed forward
    phi_ff = atan((n_dot*n_dot+e_dot*e_dot)/in[idx_OD_0+pparam_sel+4]/9.81);
    
// LOITER UNLIM
} else if ( pparam_type < 2.5 ) {

    const double pparam_ldir = (in[idx_OD_0+pparam_sel+4]<0.0) ? -1.0 : 1.0;

    // calculate closest point on loiter circle
    const double cr_n = in[0] - in[idx_OD_0+pparam_sel+1];
    const double cr_e = in[1] - in[idx_OD_0+pparam_sel+2];
    const double norm_cr = sqrt( cr_n*cr_n + cr_e*cr_e );
    double cr_n_unit;
    double cr_e_unit;
    if (norm_cr>0.1) {
        cr_n_unit = cr_n / norm_cr;
        cr_e_unit = cr_e / norm_cr;
    }
    else {
        cr_n_unit = 0.0;
        cr_e_unit = 0.0;
    }
    p_n = fabs(in[idx_OD_0+pparam_sel+4]) * cr_n_unit + in[idx_OD_0+pparam_sel+1];
    p_e = fabs(in[idx_OD_0+pparam_sel+4]) * cr_e_unit + in[idx_OD_0+pparam_sel+2];

    // calculate tangent
    tP_n = pparam_ldir * -cr_e_unit;
    tP_e = pparam_ldir * cr_n_unit;
    
    p_d = in[idx_OD_0+pparam_sel+3];
    tP_d = 0.0;
    
    if (fabs(tP_n)<0.01 && fabs(tP_e)<0.01) { // should always have lateral-directional references on curve (this is only when we hit the center of the circle)
        tP_n=1.0;
        tP_e=0.0;
    }
    
    // feed forward
    phi_ff = atan((n_dot*n_dot+e_dot*e_dot)/in[idx_OD_0+pparam_sel+4]/9.81);
}

/* end manual input !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

const double t3 = in[1]-p_e;
const double t4 = in[0]-p_n;
const double norm_rp_ne = sqrt(t3*t3+t4*t4);

double rp_n_unit;
double rp_e_unit;
if (norm_rp_ne < 0.00001) {
    rp_n_unit = 0.0;
    rp_e_unit = 0.0;
} else {
    rp_n_unit = -t4/norm_rp_ne;
    rp_e_unit = -t3/norm_rp_ne;
}

const double t6 = -in[2]+p_d;

double sgn_rp = 0.0;
if (t6>0.0) {
    sgn_rp = 1.0;
} else if (t6<0.0) {
    sgn_rp = -1.0;
}

const double t16 = e_dot*e_dot;
const double t17 = n_dot*n_dot;
const double t18 = t16+t17;

const double e_lat = t4*tP_e-t3*tP_n;

double e_b_lat;
if (t18>1.0) {
    e_b_lat = sqrt(t18)*in[38];                               
} else {
    e_b_lat = in[38]*(1.0/2.0)+in[38]*t18*(1.0/2.0);
}
double sat_e_lat = fabs(e_lat)/e_b_lat;
if (sat_e_lat>1.0) sat_e_lat = 1.0;

// const double t7 = sat_e_lat-1.0;
// const double t8 = t7*t7;
// const double t9 = 3.141592653589793*t8*(1.0/2.0);
// const double t10 = cos(t9);
// const double t11 = sin(t9);

const double e_lon = t6;

// double e_b_lon;
// if (fabs(d_dot)>1.0) {
//     e_b_lon = fabs(d_dot)*in[39];                               
// } else {
//     e_b_lon = in[39]*(1.0/2.0)+in[39]*fabs(d_dot)*(1.0/2.0);
// }
// double sat_e_lon = fabs(e_lon)/e_b_lon;
// if (sat_e_lon>1.0) sat_e_lon = 1.0;

// double sat_e_lon = fabs(e_lon)/in[39];
// if (sat_e_lon>1.0) sat_e_lon = 1.0;
// 
// const double t12 = sat_e_lon-1.0;
// const double t13 = t12*t12;
// const double t14 = 3.141592653589793*t13*(1.0/2.0);
// const double t15 = sin(t14);

// const double atan2_01 = atan2(rp_e_unit*t10+t11*tP_e, rp_n_unit*t10+t11*tP_n);
// const double atan2_02 = atan2(e_dot, n_dot);
// double eta_lat = atan2_01-atan2_02;
// if (eta_lat>3.141592653589793) {
//     eta_lat = eta_lat - 6.283185307179586;
// }
// else if (eta_lat<-3.141592653589793) {
//     eta_lat = eta_lat + 6.283185307179586;
// }

// const double atan2_03 = atan2(-t15*tP_d-sgn_rp*cos(t14), t15*sqrt(tP_e*tP_e+tP_n*tP_n));
// const double atan2_04 = atan2(-d_dot, sqrt(t18));
// double eta_lon = atan2_03-atan2_04;
// if (eta_lon>3.141592653589793) {
//     eta_lon = eta_lon - 6.283185307179586;
// }
// else if (eta_lon<-3.141592653589793) {
//     eta_lon = eta_lon + 6.283185307179586;
// }

const double norm_vG_lat = sqrt(t18);
// // double eta_lat;
// // double tt1;
// // double tt2;
// // const double tt3 = (rp_n_unit*t10+t11*tP_n)*e_dot-(rp_e_unit*t10+t11*tP_e)*n_dot;
// // if (norm_vG_lat<0.00001) {
// // 
// //     eta_lat = 0.0;
// // }
// // else if (norm_vG_lat<1.0) {
// // //     eta_lat = sqrt(-(norm_vG_lat-2.0)*(norm_vG_lat-n_dot*(rp_n_unit*t10+t11*tP_n)-e_dot*(rp_e_unit*t10+t11*tP_e))/2.0);
// //     const double VG1 = 0.5-0.5*cos(3.141592653589793*norm_vG_lat);
// //     const double VG1_VG = VG1/norm_vG_lat;
// //     
// //     tt1 = VG1*(rp_e_unit*t10+t11*tP_e)-e_dot*VG1_VG;
// //     tt2 = VG1*(rp_n_unit*t10+t11*tP_n)-n_dot*VG1_VG;
// // 
// //     eta_lat = (((tt3<0.0) ? -1.0 : 1.0)*sqrt(tt1*tt1+tt2*tt2)/2.0);
// // }
// // else {
// // //     eta_lat = sqrt((norm_vG_lat*(1.0/2.0)-n_dot*(rp_n_unit*t10+t11*tP_n)*(1.0/2.0)-e_dot*(rp_e_unit*t10+t11*tP_e)*(1.0/2.0))/norm_vG_lat);
// //     tt1 = norm_vG_lat*(rp_e_unit*t10+t11*tP_e)-e_dot;
// //     tt2 = norm_vG_lat*(rp_n_unit*t10+t11*tP_n)-n_dot;
// //     
// //     eta_lat = (((tt3<0.0) ? -1.0 : 1.0)*sqrt(tt1*tt1+tt2*tt2)/norm_vG_lat/2.0);
// // //     eta_lat = (sqrt(tt1*tt1+tt2*tt2)/norm_vG_lat/2.0);
// // 
// // }
const double thetal=-sat_e_lat*(sat_e_lat-2.0);
const double ln=(1.0-thetal)*tP_n/sqrt(tP_e*tP_e+tP_n*tP_n)+thetal*rp_n_unit;
const double le=(1.0-thetal)*tP_e/sqrt(tP_e*tP_e+tP_n*tP_n)+thetal*rp_e_unit;
// const double tt1 = norm_vG_lat*ln-n_dot;
// const double tt2 = norm_vG_lat*le-e_dot;
// const double eta_lat = sqrt(tt1*tt1 + tt2*tt2)/norm_vG_lat/2.0;

const double atan2_01 = atan2(le, ln);
const double atan2_02 = atan2(e_dot, n_dot);
double eta_lat = atan2_01-atan2_02;
if (eta_lat>3.141592653589793) {
    eta_lat = eta_lat - 6.283185307179586;
}
else if (eta_lat<-3.141592653589793) {
    eta_lat = eta_lat + 6.283185307179586;
}


const double norm_vG_lon = sqrt(t18+d_dot*d_dot);
// double eta_lon;
// if (norm_vG_lon<1.0) {
//     eta_lon = sqrt(-(norm_vG_lon-2.0)*(norm_vG_lon-t15*sqrt(tP_e*tP_e+tP_n*tP_n)*norm_vG_lat-d_dot*(-t15*tP_d-sgn_rp*cos(t14)))/2.0);
// }
// else {
//     eta_lon = sqrt((norm_vG_lon*(1.0/2.0)-norm_vG_lat*t15*sqrt(tP_e*tP_e+tP_n*tP_n)*(1.0/2.0)-d_dot*(-t15*tP_d-sgn_rp*cos(t14))*(1.0/2.0))/norm_vG_lon);
// }

// const double d_dot_max = 3.0;
// sat_e_lon = e_lon/in[39];
// if (sat_e_lon>1.0) sat_e_lon = 1.0;
// if (sat_e_lon<-1.0) sat_e_lon = -1.0;
// const double eta_lon = sqrt((sat_e_lon*d_dot_max - d_dot)/d_dot_max);

double ddot_sp = norm_vG_lon*tP_d/sqrt(tP_e*tP_e+tP_n*tP_n);
const double ddot_clmb = 3.5;
const double ddot_sink = 1.5;
if (ddot_sp>1.4) ddot_sp=1.4;
if (ddot_sp<-3.4) ddot_sp=-3.4;
double eta_lon;
double sat_e_lon;
double thetal_lon;
if (e_lon<0.0) {
    sat_e_lon = fabs(e_lon/in[39]/(-ddot_clmb-ddot_sp));
    if (sat_e_lon>1.0) sat_e_lon=1.0;
    thetal_lon = -sat_e_lon*(sat_e_lon-2.0);
    eta_lon = ((-ddot_clmb-ddot_sp)*thetal_lon + ddot_sp - d_dot)/(ddot_clmb+ddot_sink);
}
else {
    sat_e_lon = fabs(e_lon/in[39]/(ddot_sink-ddot_sp));
    if (sat_e_lon>1.0) sat_e_lon=1.0;
    thetal_lon = -sat_e_lon*(sat_e_lon-2.0);
    eta_lon = ((ddot_sink-ddot_sp)*thetal_lon + ddot_sp - d_dot)/(ddot_clmb+ddot_sink);
}

const double t19 = alpha-in[35]+in[37];
const double t20 = 1.0/(in[37]*in[37]);
const double t21 = -alpha+in[36]+in[37];

double a_soft;
if (alpha>(in[35]-in[37])) {
    a_soft=(t19*t19)*t20;
}
else if (alpha>(in[36]+in[37])) {
    a_soft=0.0;
}
else {
    a_soft=t20*(t21*t21);
}

/* outputs */

out[0] = eta_lat;
out[1] = eta_lon;
out[2] = Vsafe;
out[3] = in[8];
out[4] = in[9];
out[5] = in[10];
out[6] = a_soft;
out[7] = in[11]*(-4.143016944939305)+in[13]*4.143016944939305;
out[8] = in[13];
if (phi_ff>0.523598775598299) phi_ff = 0.523598775598299;
else if (phi_ff<-0.523598775598299) phi_ff = -0.523598775598299;
out[9] = in[14] - (0.5+0.5*cos(sat_e_lat*3.141592653589793))*phi_ff;
out[10] = in[15];

}

void evaluateLSQ( const real_t *in, real_t *out ){

double in_Delta[ACADO_NX+ACADO_NU+ACADO_NOD];
memcpy(in_Delta, in, sizeof(in_Delta));
lsq_obj_eval( in_Delta, out );
 
/* lsq_obj jacobians */
 
double f_Delta_m[ACADO_NY];
double f_Delta_p[ACADO_NY];
const double Delta = 0.00001;
const double Delta2 = 2.0 * Delta;
 
int i;
int j;
for (i = 0; i < ACADO_NX; i=i+1) {
 
    in_Delta[i] = in[i] - Delta;
    lsq_obj_eval( in_Delta, f_Delta_m );
    in_Delta[i] = in[i] + Delta;
    lsq_obj_eval( in_Delta, f_Delta_p );
    in_Delta[i] = in[i];
 
    for (j = 0; j < ACADO_NY; j=j+1) {
        out[ACADO_NY+j*ACADO_NX+i] = (f_Delta_p[j] - f_Delta_m[j]) / Delta2;
    }
 
}
 
for (i = 0; i < ACADO_NU; i=i+1) {
 
    in_Delta[i+ACADO_NX] = in[i+ACADO_NX] - Delta;
    lsq_obj_eval( in_Delta, f_Delta_m );
    in_Delta[i+ACADO_NX] = in[i+ACADO_NX] + Delta;
    lsq_obj_eval( in_Delta, f_Delta_p );
    in_Delta[i+ACADO_NX] = in[i+ACADO_NX];
 
    for (j = 0; j < ACADO_NY; j=j+1) {
        out[ACADO_NY+ACADO_NY*ACADO_NX+j*ACADO_NU+i] = (f_Delta_p[j] - f_Delta_m[j]) / Delta2;
    }
 
}

}

void lsq_objN_eval( real_t *in, real_t *out ){

/* for manual input indexing ... */

const int minus_NU = ACADO_NU;

/* optimized intermediate calculations */

const double t2 = cos(in[4]);

const double alpha = -in[4]+in[7];

double Vsafe = in[3];
if (Vsafe<1.0) Vsafe = 1.0;

const double n_dot = in[29]+Vsafe*t2*cos(in[5]);
const double e_dot = in[30]+Vsafe*t2*sin(in[5]);
const double d_dot = in[31]-Vsafe*sin(in[4]);

/* begin manual input !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

// CHECK SEGMENT SWITCHING CONDITIONS //TODO: put this in a function!
const int idx_OD_0 = ACADO_NX+ACADO_NU-minus_NU;
bool b_switch_segment = false;
int pparam_sel = 0;
double sw_dot = 0.0;
if ( in[ACADO_NX-1] < 0.05 ) { // check x_sw
    const double vel[3] = {n_dot,e_dot,d_dot};
    if ( in[idx_OD_0] < 0.5 ) { // path type
        b_switch_segment = check_line_seg( &in[0], &vel[0], &in[idx_OD_0] );
    } else if (in[idx_OD_0] < 1.5 ) {
        b_switch_segment = check_curve_seg( &in[0], &vel[0], &in[idx_OD_0] );
    }
} else {
    b_switch_segment = true;
}
if (b_switch_segment) {
    pparam_sel = 7;
    sw_dot = 1.0;
} 

double p_n = 0.0;
double p_e = 0.0;
double p_d = 0.0;
double tP_n = 1.0;
double tP_e = 0.0;
double tP_d = 0.0;

const double pparam_type = in[idx_OD_0+pparam_sel];

// LINE SEGMENT
if ( pparam_type < 0.5 ) {

    // calculate tangent
    double tP_n = cos(in[idx_OD_0+pparam_sel+6])*cos(in[idx_OD_0+pparam_sel+5]);
    double tP_e = cos(in[idx_OD_0+pparam_sel+6])*sin(in[idx_OD_0+pparam_sel+5]);
    double tP_d = -sin(in[idx_OD_0+pparam_sel+6]);
    
    // dot product
    const double dot_tP_bp = tP_n*(in[0] - in[idx_OD_0+pparam_sel+1]) + tP_e*(in[1] - in[idx_OD_0+pparam_sel+2]) + tP_d*(in[2] - in[idx_OD_0+pparam_sel+3]);
    
    // point on track
    p_n = in[idx_OD_0+pparam_sel+1] + dot_tP_bp * tP_n;
    p_e = in[idx_OD_0+pparam_sel+2] + dot_tP_bp * tP_e;
    p_d = in[idx_OD_0+pparam_sel+3] + dot_tP_bp * tP_d;
    
// ARC SEGMENT
} else if ( pparam_type < 1.5 ) {

// variable definitions
//     const double pparam_cc_n = in[idx_OD_0+pparam_sel+1];
//     const double pparam_cc_e = in[idx_OD_0+pparam_sel+2];
//     const double pparam_cc_d = in[idx_OD_0+pparam_sel+3];
//     const double pparam_R = fabs(in[idx_OD_0+pparam_sel+4]);
    const double pparam_ldir = (in[idx_OD_0+pparam_sel+4]<0.0) ? -1.0 : 1.0;
//     const double pparam_Chi = in[idx_OD_0+pparam_sel+5];
//     const double pparam_Gam = in[idx_OD_0+pparam_sel+6];
    double Gam_temp = in[idx_OD_0+pparam_sel+6];

    // calculate closest point on loiter circle
    const double cr_n = in[0] - in[idx_OD_0+pparam_sel+1];
    const double cr_e = in[1] - in[idx_OD_0+pparam_sel+2];
    const double norm_cr = sqrt( cr_n*cr_n + cr_e*cr_e );
    double cr_n_unit;
    double cr_e_unit;
    if (norm_cr>0.1) {
        cr_n_unit = cr_n / norm_cr;
        cr_e_unit = cr_e / norm_cr;
    }
    else {
        cr_n_unit = 0.0;
        cr_e_unit = 0.0;
    }
    p_n = fabs(in[idx_OD_0+pparam_sel+4]) * cr_n_unit + in[idx_OD_0+pparam_sel+1];
    p_e = fabs(in[idx_OD_0+pparam_sel+4]) * cr_e_unit + in[idx_OD_0+pparam_sel+2];

    // calculate tangent
    tP_n = pparam_ldir * -cr_e_unit;
    tP_e = pparam_ldir * cr_n_unit;
    
    // angular position
    const double xi_pos = atan2(cr_e_unit, cr_n_unit);
    
    // angular exit
    double xi_exit = in[idx_OD_0+pparam_sel+5] - pparam_ldir * 1.570796326794897;
    if (xi_exit>3.141592653589793) {
        xi_exit = xi_exit - 6.283185307179586;
    }
    else if (xi_exit<-3.141592653589793) {
        xi_exit = xi_exit + 6.283185307179586;
    }
    
    // angular travel (back calculated) from exit [0,2pi)
    double delta_xi = pparam_ldir * (xi_exit - xi_pos);
    if (delta_xi >= 6.28318530718) delta_xi = 0.0;
    if (delta_xi < 0.0) delta_xi = delta_xi + 6.28318530718;

    // closest point on nearest spiral leg and tangent down component
    if (fabs(in[idx_OD_0+pparam_sel+6]) < 0.001) {

        p_d = in[idx_OD_0+pparam_sel+3];
        tP_d = 0.0;

    } else {

        const double RtanGam = fabs(in[idx_OD_0+pparam_sel+4]) * tan(in[idx_OD_0+pparam_sel+6]);

        // height down from exit
        const double delta_d_xi = delta_xi * RtanGam;

        // nearest spiral leg
        const double delta_d_k = round( (in[2] - (in[idx_OD_0+pparam_sel+3] + delta_d_xi)) / (6.28318530718*RtanGam) ) * 6.28318530718*RtanGam;
        
        // closest point on nearest spiral leg
        p_d = in[idx_OD_0+pparam_sel+3] + delta_d_k + delta_d_xi;
        
        // cap end point
        if ((p_d - in[idx_OD_0+pparam_sel+3]) * in[idx_OD_0+pparam_sel+6] < 0.0) {
            p_d = in[idx_OD_0+pparam_sel+3];
            tP_d = 0.0;
            Gam_temp = 0.0;
        }
        else {
            tP_d = -sin(in[idx_OD_0+pparam_sel+6]);
        }
        
    }
    
    if (fabs(tP_n)<0.01 && fabs(tP_e)<0.01) { // should always have lateral-directional references on curve (this is only when we hit the center of the circle)
        tP_n=1.0;
        tP_e=0.0;
    }
    
    // Normalize tP
    tP_n = tP_n * cos(Gam_temp);
    tP_e = tP_e * cos(Gam_temp);
    
// LOITER UNLIM
} else if ( pparam_type < 2.5 ) {

    const double pparam_ldir = (in[idx_OD_0+pparam_sel+4]<0.0) ? -1.0 : 1.0;

    // calculate closest point on loiter circle
    const double cr_n = in[0] - in[idx_OD_0+pparam_sel+1];
    const double cr_e = in[1] - in[idx_OD_0+pparam_sel+2];
    const double norm_cr = sqrt( cr_n*cr_n + cr_e*cr_e );
    double cr_n_unit;
    double cr_e_unit;
    if (norm_cr>0.1) {
        cr_n_unit = cr_n / norm_cr;
        cr_e_unit = cr_e / norm_cr;
    }
    else {
        cr_n_unit = 0.0;
        cr_e_unit = 0.0;
    }
    p_n = fabs(in[idx_OD_0+pparam_sel+4]) * cr_n_unit + in[idx_OD_0+pparam_sel+1];
    p_e = fabs(in[idx_OD_0+pparam_sel+4]) * cr_e_unit + in[idx_OD_0+pparam_sel+2];

    // calculate tangent
    tP_n = pparam_ldir * -cr_e_unit;
    tP_e = pparam_ldir * cr_n_unit;
    
    p_d = in[idx_OD_0+pparam_sel+3];
    tP_d = 0.0;
    
    if (fabs(tP_n)<0.01 && fabs(tP_e)<0.01) { // should always have lateral-directional references on curve (this is only when we hit the center of the circle)
        tP_n=1.0;
        tP_e=0.0;
    }
}

/* end manual input !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

const double t3 = in[1]-p_e;
const double t4 = in[0]-p_n;
const double norm_rp_ne = sqrt(t3*t3+t4*t4);

double rp_n_unit;
double rp_e_unit;
if (norm_rp_ne < 0.00001) {
    rp_n_unit = 0.0;
    rp_e_unit = 0.0;
} else {
    rp_n_unit = -t4/norm_rp_ne;
    rp_e_unit = -t3/norm_rp_ne;
}

const double t6 = -in[2]+p_d;

double sgn_rp = 0.0;
if (t6>0.0) {
    sgn_rp = 1.0;
} else if (t6<0.0) {
    sgn_rp = -1.0;
}

const double t16 = e_dot*e_dot;
const double t17 = n_dot*n_dot;
const double t18 = t16+t17;

const double e_lat = t4*tP_e-t3*tP_n;

double e_b_lat;
if (t18>1.0) {
    e_b_lat = sqrt(t18)*in[35];                               
} else {
    e_b_lat = in[35]*(1.0/2.0)+in[35]*t18*(1.0/2.0);
}
double sat_e_lat = fabs(e_lat)/e_b_lat;
if (sat_e_lat>1.0) sat_e_lat = 1.0;

// const double t7 = sat_e_lat-1.0;
// const double t8 = t7*t7;
// const double t9 = 3.141592653589793*t8*(1.0/2.0);
// const double t10 = cos(t9);
// const double t11 = sin(t9);

const double e_lon = t6;

// double e_b_lon;
// if (fabs(d_dot)>1.0) {
//     e_b_lon = fabs(d_dot)*in[36];                               
// } else {
//     e_b_lon = in[36]*(1.0/2.0)+in[36]*fabs(d_dot)*(1.0/2.0);
// }
// double sat_e_lon = fabs(e_lon)/e_b_lon;
// if (sat_e_lon>1.0) sat_e_lon = 1.0;

// double sat_e_lon = fabs(e_lon)/in[36];
// if (sat_e_lon>1.0) sat_e_lon = 1.0;
// 
// const double t12 = sat_e_lon-1.0;
// const double t13 = t12*t12;
// const double t14 = 3.141592653589793*t13*(1.0/2.0);
// const double t15 = sin(t14);

// const double atan2_01 = atan2(rp_e_unit*t10+t11*tP_e, rp_n_unit*t10+t11*tP_n);
// const double atan2_02 = atan2(e_dot, n_dot);
// double eta_lat = atan2_01-atan2_02;
// if (eta_lat>3.141592653589793) {
//     eta_lat = eta_lat - 6.283185307179586;
// }
// else if (eta_lat<-3.141592653589793) {
//     eta_lat = eta_lat + 6.283185307179586;
// }
// 
// const double atan2_03 = atan2(-t15*tP_d-sgn_rp*cos(t14), t15*sqrt(tP_e*tP_e+tP_n*tP_n));
// const double atan2_04 = atan2(-d_dot, sqrt(t18));
// double eta_lon = atan2_03-atan2_04;
// if (eta_lon>3.141592653589793) {
//     eta_lon = eta_lon - 6.283185307179586;
// }
// else if (eta_lon<-3.141592653589793) {
//     eta_lon = eta_lon + 6.283185307179586;
// }

const double norm_vG_lat = sqrt(t18);
// double eta_lat;
// double tt1;
// double tt2;
// const double tt3 = (rp_n_unit*t10+t11*tP_n)*e_dot-(rp_e_unit*t10+t11*tP_e)*n_dot;
// if (norm_vG_lat<0.00001) {
// 
//     eta_lat = 0.0;
// }
// else if (norm_vG_lat<1.0) {
// //     eta_lat = sqrt(-(norm_vG_lat-2.0)*(norm_vG_lat-n_dot*(rp_n_unit*t10+t11*tP_n)-e_dot*(rp_e_unit*t10+t11*tP_e))/2.0);
//     const double VG1 = 0.5-0.5*cos(3.141592653589793*norm_vG_lat);
//     const double VG1_VG = VG1/norm_vG_lat;
//     
//     tt1 = VG1*(rp_e_unit*t10+t11*tP_e)-e_dot*VG1_VG;
//     tt2 = VG1*(rp_n_unit*t10+t11*tP_n)-n_dot*VG1_VG;
// 
//     eta_lat = (((tt3<0.0) ? -1.0 : 1.0)*sqrt(tt1*tt1+tt2*tt2)/2.0);
// }
// else {
// //     eta_lat = sqrt((norm_vG_lat*(1.0/2.0)-n_dot*(rp_n_unit*t10+t11*tP_n)*(1.0/2.0)-e_dot*(rp_e_unit*t10+t11*tP_e)*(1.0/2.0))/norm_vG_lat);
//     tt1 = norm_vG_lat*(rp_e_unit*t10+t11*tP_e)-e_dot;
//     tt2 = norm_vG_lat*(rp_n_unit*t10+t11*tP_n)-n_dot;
//     
//     eta_lat = (((tt3<0.0) ? -1.0 : 1.0)*sqrt(tt1*tt1+tt2*tt2)/norm_vG_lat/2.0);
// //     eta_lat = (sqrt(tt1*tt1+tt2*tt2)/norm_vG_lat/2.0);
// }

const double thetal=-sat_e_lat*(sat_e_lat-2.0);
const double ln=(1.0-thetal)*tP_n/sqrt(tP_e*tP_e+tP_n*tP_n)+thetal*rp_n_unit;
const double le=(1.0-thetal)*tP_e/sqrt(tP_e*tP_e+tP_n*tP_n)+thetal*rp_e_unit;
// const double tt1 = norm_vG_lat*ln-n_dot;
// const double tt2 = norm_vG_lat*le-e_dot;
// const double eta_lat = sqrt(tt1*tt1 + tt2*tt2)/norm_vG_lat/2.0;

const double atan2_01 = atan2(le, ln);
const double atan2_02 = atan2(e_dot, n_dot);
double eta_lat = atan2_01-atan2_02;
if (eta_lat>3.141592653589793) {
    eta_lat = eta_lat - 6.283185307179586;
}
else if (eta_lat<-3.141592653589793) {
    eta_lat = eta_lat + 6.283185307179586;
}

const double norm_vG_lon = sqrt(t18+d_dot*d_dot);
// double eta_lon;
// if (norm_vG_lon<1.0) {
//     eta_lon = sqrt(-(norm_vG_lon-2.0)*(norm_vG_lon-t15*sqrt(tP_e*tP_e+tP_n*tP_n)*norm_vG_lat-d_dot*(-t15*tP_d-sgn_rp*cos(t14)))/2.0);
// }
// else {
//     eta_lon = sqrt((norm_vG_lon*(1.0/2.0)-norm_vG_lat*t15*sqrt(tP_e*tP_e+tP_n*tP_n)*(1.0/2.0)-d_dot*(-t15*tP_d-sgn_rp*cos(t14))*(1.0/2.0))/norm_vG_lon);
// }

// const double d_dot_max = 3.0;
// sat_e_lon = e_lon/in[36]/;
// if (sat_e_lon>1.0) sat_e_lon = 1.0;
// if (sat_e_lon<-1.0) sat_e_lon = -1.0;
// const double eta_lon = (sat_e_lon*d_dot_max - d_dot)/d_dot_max;

double ddot_sp = norm_vG_lon*tP_d/sqrt(tP_e*tP_e+tP_n*tP_n);
const double ddot_clmb = 3.5;
const double ddot_sink = 1.5;
if (ddot_sp>1.4) ddot_sp=1.4;
if (ddot_sp<-3.4) ddot_sp=-3.4;
double eta_lon;
double sat_e_lon;
double thetal_lon;
if (e_lon<0.0) {
    sat_e_lon = fabs(e_lon/in[36]/(-ddot_clmb-ddot_sp));
    if (sat_e_lon>1.0) sat_e_lon=1.0;
    thetal_lon = -sat_e_lon*(sat_e_lon-2.0);
    eta_lon = ((-ddot_clmb-ddot_sp)*thetal_lon + ddot_sp - d_dot)/(ddot_clmb+ddot_sink);
}
else {
    sat_e_lon = fabs(e_lon/in[36]/(ddot_sink-ddot_sp));
    if (sat_e_lon>1.0) sat_e_lon=1.0;
    thetal_lon = -sat_e_lon*(sat_e_lon-2.0);
    eta_lon = ((ddot_sink-ddot_sp)*thetal_lon + ddot_sp - d_dot)/(ddot_clmb+ddot_sink);
}

const double t19 = alpha-in[32]+in[34];
const double t20 = 1.0/(in[34]*in[34]);
const double t21 = -alpha+in[33]+in[34];

double a_soft;
if (alpha>(in[32]-in[34])) {
    a_soft=(t19*t19)*t20;
}
else if (alpha>(in[33]+in[34])) {
    a_soft=0.0;
}
else {
    a_soft=t20*(t21*t21);
}

/* outputs */

out[0] = eta_lat;
out[1] = eta_lon;
out[2] = Vsafe;
out[3] = in[8];
out[4] = in[9];
out[5] = in[10];
out[6] = a_soft;

}

void evaluateLSQEndTerm( const real_t *in, real_t *out ){

double in_Delta[ACADO_NX+ACADO_NOD];
memcpy(in_Delta, in, sizeof(in_Delta));
lsq_objN_eval( in_Delta, out );
 
/* lsq_objN jacobians */
 
double f_Delta_m[ACADO_NYN];
double f_Delta_p[ACADO_NYN];
const double Delta = 0.00001;
const double Delta2 = 2.0 * Delta;
 
int i;
int j;
for (i = 0; i < ACADO_NX; i=i+1) {
 
    in_Delta[i] = in[i] - Delta;
    lsq_objN_eval( in_Delta, f_Delta_m );
    in_Delta[i] = in[i] + Delta;
    lsq_objN_eval( in_Delta, f_Delta_p );
    in_Delta[i] = in[i];
 
    for (j = 0; j < ACADO_NYN; j=j+1) {
        out[ACADO_NYN+j*ACADO_NX+i] = (f_Delta_p[j] - f_Delta_m[j]) / Delta2;
    }
 
}

}

/* begin inline functions !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

bool check_line_seg( const double *pos, const double *vel, const double *params ) {
    
    // tB
    const double tB_n = cos(params[6])*cos(params[5]);
    const double tB_e = cos(params[6])*sin(params[5]);
    const double tB_d = -sin(params[6]);

    // r - b
    const double br_n = pos[0] - params[1];
    const double br_e = pos[1] - params[2];
    const double br_d = pos[2] - params[3];
    
    // dot( (r-b) , tB )
    const double dot_brtB = br_n * tB_n + br_e * tB_e + br_d * tB_d;
    
    // check travel 
    return ( dot_brtB > 0.0 );
    
}

bool check_curve_seg( const double *pos, const double *vel, const double *params ) {
    
    // tB
    const double tB_n = cos(params[6])*cos(params[5]);
    const double tB_e = cos(params[6])*sin(params[5]);
    const double tB_d = -sin(params[6]);

    // r - b
    const double rot90 = (params[4]<0.0) ? -1.570796326794897 : 1.570796326794897;
    const double br_n = pos[0] - (params[1] + fabs(params[4]) * cos(params[5] - rot90));
    const double br_e = pos[1] - (params[2] + fabs(params[4]) * sin(params[5] - rot90));
    const double br_d = pos[2] - params[3];
    
    // bearing : dot( v , tB ) (lat)
    const double dot_vtB = vel[0] * tB_n + vel[1] * tB_e;
    
    // travel : dot( (r-b) , tB ) (lat)
    const double dot_brtB = br_n * tB_n + br_e * tB_e;
    
    // proximity : norm( r-b ) (lat)
    const double norm_br = sqrt( br_n*br_n + br_e*br_e );
    
    // proximity : norm( r-b ) (lon)
    const double norm_br_d = fabs(br_d);
    
    // check (1) proximity, (2) bearing, (3) travel 
    return ( norm_br < params[14] && norm_br_d < 10.0 && dot_vtB > params[15]*sqrt(vel[0]*vel[0]+vel[1]*vel[1]) && dot_brtB > 0.0 );
}

/* end inline functions !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */