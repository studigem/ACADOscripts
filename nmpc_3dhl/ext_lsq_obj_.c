  t2 = cos(in04);
  t3 = alpha-in44+in46;
  t4 = 1.0/(in46*in46);
  t5 = -alpha+in45+in46;
  t6 = e_t_ne+in42;
  t7 = in41*t6;
  t8 = exp(t7);
  t9 = t8+1.0;
  t10 = 1.0/t9;
  t11 = e_t_ne-in42;
  t15 = in41*t11;
  t12 = exp(-t15);
  t13 = t12+1.0;
  t14 = 1.0/t13;
  t16 = t10+t14-1.0;
  t17 = t10+t14;
  t18 = e_t_d+in40;
  t19 = in39*t18;
  t20 = exp(t19);
  t21 = t20+1.0;
  t22 = 1.0/t21;
  t23 = e_t_d-in40;
  t24 = exp(-in39*t23);
  t25 = t24+1.0;
  t26 = 1.0/t25;
  A0[0][0] = -in04+in07;
  A0[1][0] = in03;
  A0[2][0] = in36+Vsafe*t2*cos(in05);
  A0[3][0] = in37+Vsafe*t2*sin(in05);
  A0[4][0] = in38-Vsafe*sin(in04);
  A0[5][0] = sqrt(d_dot*d_dot+e_dot*e_dot+n_dot*n_dot);
  A0[6][0] = in43;
  A0[7][0] = d_n-in00;
  A0[8][0] = d_e-in01;
  A0[9][0] = d_d-in02;
  A0[10][0] = -Td_e*pd_n+Td_n*pd_e;
  A0[11][0] = pd_d;
  A0[12][0] = sin((3.141592653589793*e_t_ne*(1.0/2.0))/in42);
  A0[13][0] = sin((3.141592653589793*e_t_d*(1.0/2.0))/in40);
  A0[14][0] = (t3*t3)*t4;
  A0[15][0] = t4*(t5*t5);
  A0[16][0] = e_t_1_ne;
  A0[17][0] = e_t_1_d;
  A0[18][0] = -vbar_n-Td_n*t16+Tpd_n*t17;
  A0[19][0] = -vbar_e-Td_e*t16+Tpd_e*t17;
  A0[20][0] = -vbar_d-Td_d*(t22+t26-1.0)+Tpd_d*(t22+t26);
  A0[21][0] = Vsafe;
  A0[22][0] = in08;
  A0[23][0] = in09;
  A0[24][0] = in10;
  A0[25][0] = a_soft;
  A0[26][0] = in11;
  A0[27][0] = in14;
  A0[28][0] = in15;
  A0[29][0] = in11;
  A0[30][0] = in14;
  A0[31][0] = in15;
