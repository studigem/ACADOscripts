
cmap = lines(7);
color_ref = [0.5 0.5 0.5];
color_hor = [min(ones(1,3), cmap(2,:)*1.6) 0.2];%[0.2 0.2 1 0.6];


%% ////////////////////////////////////////////////////////////////////////
% POSITION

figure('color','w','name','Position')
hold on; grid on; %axis equal;

% terrain
surf(ee_plot,nn_plot,terrain_data_plot,'edgecolor','none');
% surf(eek,nnk,terrain_data_matrix+50,'edgecolor','none');

% path
len_path = 2000;
plot3([b_e, b_e+len_path*sin(chi_p)*cos(Gamma_p)], ...
    [b_n, b_n+len_path*cos(chi_p)*cos(Gamma_p)], ...
    -[b_d, b_d-len_path*sin(Gamma_p)],'color',color_ref,'linewidth',1.5);

% position horizons
hor_int = round(10/Ts);
horO = plot3(rec.x_hor(1,1:hor_int:end,2), rec.x_hor(1,1:hor_int:end,1), ...
    -rec.x_hor(1,1:hor_int:end,3), 'o', 'MarkerSize', 4, 'Color', color_hor(1:3));
% horO.Color = color_hor;
hor1 = plot3(rec.x_hor(:,1:hor_int:end,2), rec.x_hor(:,1:hor_int:end,1), ...
    -rec.x_hor(:,1:hor_int:end,3), 'Color', color_hor(1:3));
% hor1.Color = color_hor;

% position
plot3(rec.x(:,2),rec.x(:,1),-rec.x(:,3), 'linewidth', 1.5, 'color', cmap(2,:));

xlabel('East [m]')
ylabel('North [m]')
zlabel('Height [m]');

%% ////////////////////////////////////////////////////////////////////////
% ATTITUDE

figure('color','w','name','Attitude');

% flight path angle
hand_att(1) = subplot(3,1,1); hold on; grid on; box on;
plot(time,rad2deg(rec.u(:,1)),'color',color_ref);
plot(time,rad2deg(rec.x(:,4)));
legend('ref','state')
ylabel('\gamma [deg]')

% heading angle
hand_att(2) = subplot(3,1,2); hold on; grid on; box on;
plot(time,rad2deg(rec.x(:,5)));
ylabel('\xi [deg]')

% bank angle
hand_att(3) = subplot(3,1,3); hold on; grid on; box on;
plot(time,rad2deg(rec.u(:,2)),'color',color_ref);
plot(time,rad2deg(rec.x(:,6)));
legend('ref','state')
ylabel('\mu [deg]')

xlabel('Time [s]')

linkaxes(hand_att,'x')

%% ////////////////////////////////////////////////////////////////////////
% POSITION ERRORS

figure('color','w','name','Position Errors')

hand_pos_err(1)=subplot(2,1,1); hold on; grid on; box on;

plot(time,rec.yz(:,1));
plot(time,rec.yz(:,2));

legend('e_{lat}','e_{lon}')
ylabel('e [m]')

hand_pos_err(2)=subplot(2,1,2); hold on; grid on; box on;

plot(time,rec.aux(:,1));
plot(time,-rec.x(:,3));

legend('h_terr','h')
ylabel('Height [m]')

xlabel('time [s]')

linkaxes(hand_pos_err,'x');

%% ////////////////////////////////////////////////////////////////////////
% OBJECTIVE COSTS

obj_cost(:,1) = (yref(1)*ones(length(time),1)-rec.yz(:,1)).^2*Q_output(1);
obj_cost(:,2) = (yref(2)*ones(length(time),1)-rec.yz(:,2)).^2*Q_output(2);
obj_cost(:,3) = (yref(3)*ones(length(time),1)-rec.yz(:,3)).^2*Q_output(3);
obj_cost(:,4) = (yref(4)*ones(length(time),1)-rec.yz(:,4)).^2*Q_output(4);

obj_cost(:,5) = (zref(1)*ones(length(time),1)-rec.yz(:,5)).^2*R_controls(1);
obj_cost(:,6) = (zref(2)*ones(length(time),1)-rec.yz(:,6)).^2*R_controls(2);
obj_cost(:,7) = (zref(3)*ones(length(time),1)-rec.yz(:,7)).^2*R_controls(3);
obj_cost(:,8) = (zref(4)*ones(length(time),1)-rec.yz(:,8)).^2*R_controls(4);

figure('color','w','name','Objective Costs')

hand_obj(1)=subplot(2,1,1); hold on; grid on; box on;

plot(time,obj_cost(:,1)); % e_lat
plot(time,obj_cost(:,2)); % e_lon
plot(time,obj_cost(:,3)); % e_dir
plot(time,obj_cost(:,4)); % terr

legend('e_{lat}','e_{lon}','\chi','h_{terr}');
ylabel('J(x)');
ylim([0 max(obj_cost(:))]);

hand_obj(2)=subplot(2,1,2); hold on; grid on; box on;

plot(time,obj_cost(:,5)); % gamma_ref
plot(time,obj_cost(:,6)); % mu_ref
plot(time,obj_cost(:,7)); % gamma dot
plot(time,obj_cost(:,8)); % mu dot

legend('\gamma_{ref}','\mu_{ref}','\gamma{dot}','\mu{dot}');
ylabel('J(x,u)');
ylim([0 max(obj_cost(:))]);

xlabel('time [s]');

linkaxes(hand_obj,'x');
