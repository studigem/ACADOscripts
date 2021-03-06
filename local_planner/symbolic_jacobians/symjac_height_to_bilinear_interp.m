% / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
% symbolic jacobian for height over bilinearly interpolated terrain grid
% / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /

clear; clc;

r_n = sym('r_n','real');
r_e = sym('r_e','real');
r_d = sym('r_d','real');
xi = sym('xi','real');
h_offset = sym('h_offset','real');
delta_h = sym('delta_h','real');
delta_y = sym('delta_y','real');
log_sqrt_w_over_sig1_h = sym('log_sqrt_w_over_sig1_h','real');
terr_dis = sym('terr_dis','real');
sgn_n = sym('sgn_n','real');
sgn_e = sym('sgn_e','real');
n_floor = sym('n_floor','real');
e_floor = sym('e_floor','real');
h1 = sym('h1','real');
h2 = sym('h2','real');
h3 = sym('h3','real');
h4 = sym('h4','real');

% bilinear interpolation
dn_expr = (r_n + sgn_n * sin(xi) * delta_y) / terr_dis - n_floor;
de_expr = (r_e + sgn_e * cos(xi) * delta_y) / terr_dis - e_floor;
h12_expr = [h1 h2] * [(1-dn_expr); dn_expr];
h34_expr = [h3 h4] * [(1-dn_expr); dn_expr];
h_terr_expr = [(1-de_expr) de_expr] * [h12_expr; h34_expr];
h_above_terr_expr = -r_d - h_terr_expr;

% jacobian
jac_h = jacobian(h_above_terr_expr, [r_n; r_e; r_d; xi]);

%% substitute calculations we'll have already done
h_terr = sym('h_terr','real');
jac_h = subs(jac_h , h_terr_expr, h_terr);
h12 = sym('h12','real');
jac_h = subs(jac_h , h12_expr, h12);
h34 = sym('h34','real');
jac_h = subs(jac_h , h34_expr, h34);
dn = sym('dn','real');
jac_h = subs(jac_h , dn_expr, dn);
de = sym('de','real');
jac_h = subs(jac_h , de_expr, de);

jac_h = simplify(jac_h);

%% get input arguments (used variables)
input_arg = sym2cell(symvar(jac_h));
doit = true;

if doit
%% export to m code
matlabFunction(jac_h,'File','jac_h.m','Vars',input_arg,'Outputs',{'out'});
end

if doit
%% export to c code
ccode(jac_h,'file','jac_h_ccode.c');
end

strs = {'h'};
ss = 1;

if doit
%% prep c code for mpc model functions
fid = fopen(['jac_',strs{ss},'_ccode.c']);
txt = textscan(fid,'%s','delimiter','\n'); 
fclose(fid);
txt = txt{1};
for i = 1:length(txt)
    
    str1 = txt{i};
    
    if strcmp(str1(1),'t')
        str1 = ['const double ',str1];
        txt{i} = str1;
        % t's 
    elseif length(str1) > 5
        % A0's
        if strcmp(str1(1:6),'A0[0][')
            str1 = ['jac[',str1(7:end)];
            txt{i} = str1;
        end
    end
end
txt_top = cell(2,1);
txt_top{1} = ['void jacobian_',strs{ss},'(double *jac,'];
txt_top{2} = ['const double ', char(input_arg{1})];
for k = 2:length(input_arg)
    txt_top{2} = [txt_top{2}, ', const double ', char(input_arg{k})];
end
txt_top{2} = [txt_top{2}, ') {\n'];
txt_top{3} = '/* w.r.t.:';
txt_top{4} = '    r_n';
txt_top{5} = '    r_e';
txt_top{6} = '    r_d';
txt_top{7} = '    xi';
txt_top{8} = '*/\n';
fid = fopen(['jac_',strs{ss},'_ccode.c'],'w');
for k = 1:length(txt_top)
    fprintf(fid,[char(txt_top{k}),'\n']);
end
for k = 1:length(txt)
    fprintf(fid,[char(txt{k}),'\n']);
end
fprintf(fid,[char('}'),'\n']);
fclose(fid);
end



