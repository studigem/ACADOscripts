  t2 = cos(in04);
  t3 = in01-p_e;
  t4 = in00-p_n;
  t5 = 1.0/in44;
  t6 = 1.0/norm_rp_ne;
  t7 = -in02+p_d;
  t8 = sat_e_ne-1.0;
  t9 = t8*t8;
  t10 = 3.141592653589793*t9*(1.0/2.0);
  t11 = cos(t10);
  t12 = sin(t10);
  t13 = sat_e_d-1.0;
  t14 = t13*t13;
  t15 = 3.141592653589793*t14*(1.0/2.0);
  t16 = sin(t15);
  t17 = e_dot*e_dot;
  t18 = n_dot*n_dot;
  t19 = t17+t18;
  t20 = alpha-in39+in41;
  t21 = 1.0/(in41*in41);
  t22 = -alpha+in40+in41;
  A0[0][0] = -in04+in07;
  A0[1][0] = in03;
  A0[2][0] = in36+Vsafe*t2*cos(in05);
  A0[3][0] = in37+Vsafe*t2*sin(in05);
  A0[4][0] = in38-Vsafe*sin(in04);
  A0[5][0] = sqrt(t3*t3+t4*t4);
  A0[6][0] = t4*tP_e-t3*tP_n;
  A0[7][0] = t7;
  A0[8][0] = in42*in44*(1.0/2.0)+in42*t5*t19*(1.0/2.0);
  A0[9][0] = in43*in44*(1.0/2.0)+in43*t5*fabs(d_dot)*(1.0/2.0);
  A0[10][0] = e_ne/e_b_ne;
  A0[11][0] = e_d/e_b_d;
  A0[12][0] = -t4*t6;
  A0[13][0] = -t3*t6;
  A0[14][0] = t7;
  A0[15][0] = rp_e_unit*t11+t12*tP_e;
  A0[16][0] = rp_n_unit*t11+t12*tP_n;
  A0[17][0] = e_dot;
  A0[18][0] = n_dot;
  A0[19][0] = atan2_01-atan2_02;
  A0[20][0] = -t16*tP_d-sgn_rp*cos(t15);
  A0[21][0] = t16*sqrt(tP_e*tP_e+tP_n*tP_n);
  A0[22][0] = -d_dot;
  A0[23][0] = sqrt(t19);
  A0[24][0] = atan2_03-atan2_04;
  A0[25][0] = (t20*t20)*t21;
  A0[26][0] = t21*(t22*t22);
  A0[27][0] = eta_lat;
  A0[28][0] = eta_lon;
  A0[29][0] = Vsafe;
  A0[30][0] = in08;
  A0[31][0] = in09;
  A0[32][0] = in10;
  A0[33][0] = a_soft;
  A0[34][0] = in11*(-4.143016944939305)+in13*4.143016944939305;
  A0[35][0] = in13;
  A0[36][0] = in14;
  A0[37][0] = in15;
  A0[38][0] = in13;
  A0[39][0] = in14;
  A0[40][0] = in15;
