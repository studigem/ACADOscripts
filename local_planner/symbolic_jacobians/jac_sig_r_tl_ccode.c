  t2 = p1_h-p2_h;
  t3 = cos(gamma);
  t4 = cos(xi);
  t5 = t3*t4*v;
  t6 = t5+w_n;
  t7 = sin(xi);
  t8 = t3*t7*v;
  t9 = t8+w_e;
  t10 = sin(gamma);
  t16 = t10*v;
  t11 = -t16+w_d;
  t12 = terr_dis*terr_dis;
  t13 = p2_h-p3_h;
  t14 = t6*t6;
  t15 = t9*t9;
  t17 = t11*t11;
  t18 = t14+t15+t17;
  t20 = t11*t12;
  t21 = t2*t6*terr_dis;
  t22 = t9*t13*terr_dis;
  t23 = -t20+t21+t22;
  t24 = 1.0/t23;
  t25 = sqrt(t18);
  t26 = p1_h+r_d;
  t27 = t12*t26;
  t28 = p1_h*t12;
  t29 = p1_e-r_e;
  t30 = t13*t29*terr_dis;
  t31 = p1_n-r_n;
  t32 = t2*t31*terr_dis;
  t33 = t27+t28+t30+t32;
  t34 = t24*t25*t33;
  t35 = 1.0/g;
  t36 = tan(phi_max);
  t37 = 1.0/t36;
  t38 = k_r*t18*t35*t37;
  t19 = delta_r0-t34+t38;
  t39 = t19*t19;
  t40 = t3*t4*t6*2.0;
  t41 = t3*t7*t9*2.0;
  t42 = t40+t41-t10*t11*2.0;
  t43 = 1.0/(t23*t23);
  t44 = t3*t11*v*2.0;
  t45 = t4*t6*t10*v*2.0;
  t46 = t7*t9*t10*v*2.0;
  t47 = t44+t45+t46;
  t48 = 1.0/sqrt(t18);
  t49 = t3*t4*t9*v*2.0;
  t50 = t49-t3*t6*t7*v*2.0;
  A0[0][0] = t2*t24*t25*t39*terr_dis*3.0;
  A0[0][1] = t13*t24*t25*t39*terr_dis*3.0;
  A0[0][2] = t12*t24*t25*t39*-3.0;
  A0[0][3] = t39*(k_r*t35*t37*t42-t24*t33*t42*t48*(1.0/2.0)+t25*t33*t43*(t10*t12+t2*t3*t4*terr_dis+t3*t7*t13*terr_dis))*3.0;
  A0[0][4] = t39*(t25*t33*t43*(-t3*t12*v+t2*t4*t10*terr_dis*v+t7*t10*t13*terr_dis*v)+k_r*t35*t37*t47-t24*t33*t47*t48*(1.0/2.0))*-3.0;
  A0[0][5] = t39*(-k_r*t35*t37*t50+t24*t33*t48*t50*(1.0/2.0)+t25*t33*t43*(t2*t3*t7*terr_dis*v-t3*t4*t13*terr_dis*v))*-3.0;
