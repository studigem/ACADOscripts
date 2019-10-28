const double t2 = cos(gamma); 
const double t3 = cos(xi); 
const double t4 = one_over_vG_norm*one_over_vG_norm; 
const double t5 = sin(gamma); 
const double t6 = sin(xi); 
const double t7 = t2*t3*vG_n*2.0; 
const double t8 = t2*t6*vG_e*2.0; 
const double t16 = t5*vG_d*2.0; 
const double t9 = t7+t8-t16; 
const double t10 = t2*v*vG_d*2.0; 
const double t11 = t3*t5*v*vG_n*2.0; 
const double t12 = t5*t6*v*vG_e*2.0; 
const double t13 = t10+t11+t12; 
const double t14 = vG_n*v_e*2.0; 
const double t15 = t14-vG_e*v_n*2.0; 
jac[0] = one_over_vG_norm*t2*t3-t4*t9*vG_n_unit*(1.0/2.0); 
jac[1] = one_over_vG_norm*t3*v_d+t4*t13*vG_n_unit*(1.0/2.0); 
jac[2] = -one_over_vG_norm*v_e+t4*t15*vG_n_unit*(1.0/2.0); 
jac[3] = one_over_vG_norm*t2*t6-t4*t9*vG_e_unit*(1.0/2.0); 
jac[4] = one_over_vG_norm*t6*v_d+t4*t13*vG_e_unit*(1.0/2.0); 
jac[5] = one_over_vG_norm*v_n+t4*t15*vG_e_unit*(1.0/2.0); 
jac[6] = -one_over_vG_norm*t5-t4*t9*vG_d_unit*(1.0/2.0); 
jac[7] = -one_over_vG_norm*t2*v+t4*t13*vG_d_unit*(1.0/2.0); 
jac[8] = t4*vG_d_unit*(vG_n*v_e-vG_e*v_n); 
