  t3 = cos(in08);
  t9 = cos(in03);
  t10 = in09*t3*t9;
  t2 = in28+t10;
  t7 = sin(in03);
  t8 = in09*t3*t7;
  t4 = in29+t8;
  t5 = sin(in08);
  t11 = in09*t5;
  t6 = in30-t11;
  t13 = d_d-in02;
  t15 = d_e-in01;
  t12 = Td_e*t13-Td_d*t15;
  t16 = d_n-in00;
  t14 = -Td_d*t16+Td_n*t13;
  t17 = Td_e*t16-Td_n*t15;
  A0[0][0] = t6*1.0/sqrt(t2*t2+t4*t4+t6*t6);
  A0[1][0] = Td_e;
  A0[2][0] = Td_n;
  A0[3][0] = t4;
  A0[4][0] = t2;
  A0[5][0] = atan2_01-atan2_02;
  A0[6][0] = t2;
  A0[7][0] = t4;
  A0[8][0] = t6;
  A0[9][0] = (tan(in07)*(9.81E2/1.0E2))/in09;
  A0[10][0] = sqrt(t12*t12+t14*t14+t17*t17);
  A0[11][0] = Gamma_d+asin(sin_d_dot_V_g);
  A0[12][0] = e_chi;
