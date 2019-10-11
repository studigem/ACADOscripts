function out = jac_sig_r_br_exp(r_n,r_e,r_d,v,gamma,xi,w_e,w_n,w_d,terr_dis,p1_n,p1_e,p1_h,p2_n,p2_e,p2_h,p3_n,p3_e,p3_h,r_offset,delta_r0,k_r,log_sqrt_w_over_sig1_r,sig_r,d_occ,delta_r,vG_sq,vG,vG_n,vG_e,vG_d)
%JAC_SIG_R_BR_EXP
%    OUT = JAC_SIG_R_BR_EXP(R_N,R_E,R_D,V,GAMMA,XI,W_E,W_N,W_D,TERR_DIS,P1_N,P1_E,P1_H,P2_N,P2_E,P2_H,P3_N,P3_E,P3_H,R_OFFSET,DELTA_R0,K_R,LOG_SQRT_W_OVER_SIG1_R,SIG_R,D_OCC,DELTA_R,VG_SQ,VG,VG_N,VG_E,VG_D)

%    This function was generated by the Symbolic Math Toolbox version 7.1.
%    11-Oct-2019 01:12:11

t2 = p2_h-p3_h;
t3 = 1.0./delta_r;
t4 = p1_h-p2_h;
t5 = terr_dis.^2;
t6 = t4.*terr_dis.*vG_e;
t7 = t2.*terr_dis.*vG_n;
t10 = t5.*vG_d;
t8 = t6+t7-t10;
t9 = 1.0./t8;
t11 = cos(gamma);
t12 = sin(gamma);
t13 = cos(xi);
t14 = sin(xi);
t15 = t11.*t13.*vG_n.*2.0;
t16 = t11.*t14.*vG_e.*2.0;
t17 = t15+t16-t12.*vG_d.*2.0;
t18 = 1.0./vG;
t19 = p1_h+r_d;
t20 = t5.*t19;
t21 = p1_h.*t5;
t22 = p1_e-r_e;
t23 = t4.*t22.*terr_dis;
t24 = p1_n-r_n;
t25 = t2.*t24.*terr_dis;
t26 = t20+t21+t23+t25;
t27 = 1.0./delta_r.^2;
t28 = d_occ-r_offset;
t29 = t11.*v.*vG_d.*2.0;
t30 = t12.*t13.*v.*vG_n.*2.0;
t31 = t12.*t14.*v.*vG_e.*2.0;
t32 = t29+t30+t31;
t33 = t11.*t13.*v.*vG_e.*2.0;
t34 = t33-t11.*t14.*v.*vG_n.*2.0;
out = [log_sqrt_w_over_sig1_r.*sig_r.*t2.*t3.*t9.*terr_dis.*vG,log_sqrt_w_over_sig1_r.*sig_r.*t3.*t4.*t9.*terr_dis.*vG,-log_sqrt_w_over_sig1_r.*sig_r.*t3.*t5.*t9.*vG,sig_r.*(log_sqrt_w_over_sig1_r.*t3.*(d_occ.*t9.*(t5.*t12+t2.*t11.*t13.*terr_dis+t4.*t11.*t14.*terr_dis)-t9.*t17.*t18.*t26.*(1.0./2.0))+k_r.*log_sqrt_w_over_sig1_r.*t17.*t27.*t28),-sig_r.*(log_sqrt_w_over_sig1_r.*t3.*(d_occ.*t9.*(-t5.*t11.*v+t2.*t12.*t13.*terr_dis.*v+t4.*t12.*t14.*terr_dis.*v)-t9.*t18.*t26.*t32.*(1.0./2.0))+k_r.*log_sqrt_w_over_sig1_r.*t27.*t28.*t32),-sig_r.*(log_sqrt_w_over_sig1_r.*t3.*(d_occ.*t9.*(t2.*t11.*t14.*terr_dis.*v-t4.*t11.*t13.*terr_dis.*v)+t9.*t18.*t26.*t34.*(1.0./2.0))-k_r.*log_sqrt_w_over_sig1_r.*t27.*t28.*t34)];
