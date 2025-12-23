function plot_Torque_estimator(attctrl, vehicle_attitude, vehicle_angular_velocity, params, navigator,statemachine, plot_interval)
[timestamp, index] = getIndex(attctrl.timestamp * 1e-6, plot_interval);
[vehicle_attitude_timestamp, vehicle_attitude_index] = getIndex(vehicle_attitude.timestamp * 1e-6, plot_interval);
[vehicle_angular_velocity_timestamp, vehicle_angular_velocity_index] = getIndex(vehicle_angular_velocity.timestamp * 1e-6, plot_interval);
log_ac_att_wb = [vehicle_angular_velocity.xyz0(vehicle_angular_velocity_index), vehicle_angular_velocity.xyz1(vehicle_angular_velocity_index), vehicle_angular_velocity.xyz2(vehicle_angular_velocity_index)]*180/pi;
log_ac_att_q = [vehicle_attitude.q0(vehicle_attitude_index) vehicle_attitude.q1(vehicle_attitude_index) vehicle_attitude.q2(vehicle_attitude_index) vehicle_attitude.q3(vehicle_attitude_index)];
log_ac_rates_ref = [attctrl.log_ac_rates_ref0(index), attctrl.log_ac_rates_ref1(index), attctrl.log_ac_rates_ref2(index)]*180/pi;
kappa = (params.LW_ANGLE * pi / 180);
    R_lb = [cos(kappa), single(0.0), -sin(kappa);
        single(0.0), single(1.0), single(0);
        sin(kappa), single(0.0), cos(kappa)];
    log_ac_att_wl = log_ac_att_wb*R_lb';

log_ac_d_hat = [attctrl.log_ac_d_hat0(index),attctrl.log_ac_d_hat1(index),attctrl.log_ac_d_hat2(index)];
log_ac_d_hat_l = log_ac_d_hat*R_lb';%升力翼坐标系中的扰动力矩
log_ac_rates_est = [attctrl.log_ac_rates_est0(index),attctrl.log_ac_rates_est1(index),attctrl.log_ac_rates_est2(index)]*180/pi;
log_ac_q_est = [attctrl.log_ac_q_est0(index),attctrl.log_ac_q_est1(index),attctrl.log_ac_q_est2(index),attctrl.log_ac_q_est3(index)];
for i = 1 : size(log_ac_att_q, 1)
    euler(i, 1 : 3) = my_quat2eul(log_ac_att_q(i, :)','ZYX') * 180 / pi;
end
for i = 1 : size(log_ac_q_est, 1)
    est_euler(i, 1 : 3) = my_quat2eul(log_ac_q_est(i, :)','ZYX') * 180 / pi;
end

figure('Name','Torque disturbance In Fb')
tiledlayout(3, 1, 'TileSpacing', 'Compact')
nexttile
plot(timestamp, log_ac_d_hat(:, 1), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('dx(rad/s^2)');
nexttile
plot(timestamp, log_ac_d_hat(:, 2), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('dy(rad/s^2)');
nexttile
plot(timestamp, log_ac_d_hat(:, 3), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('dz(rad/s^2)');xlabel('t(s)');

figure('Name','Torque disturbance in Fl')
tiledlayout(3, 1, 'TileSpacing', 'Compact')
nexttile
plot(timestamp, log_ac_d_hat_l(:, 1), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('dxl(rad/s^2)');
nexttile
plot(timestamp, log_ac_d_hat_l(:, 2), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('dyl(rad/s^2)');
nexttile
plot(timestamp, log_ac_d_hat_l(:, 3), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('dzl(rad/s^2)');xlabel('t(s)');

figure('Name','Estimated attitude')
tiledlayout(3, 2, 'TileSpacing', 'Compact')
ax1 = nexttile;
p1 = plot(timestamp, est_euler(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(vehicle_attitude_timestamp, euler(:, 1), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('roll(deg)'); legend([p1 p2], 'CFO', 'EKF2')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_TEST_WNXY')
    title(ax1,['EN=',num2str(params.LW_TEST_EN),...
        ',Wn=[',num2str(params.LW_TEST_WNXY),',',num2str(params.LW_TEST_WNXY),',',num2str(params.LW_TEST_WNZ),...
        '],Sigma=[',num2str(params.LW_TEST_SIGXY),',',num2str(params.LW_TEST_SIGXY),',',num2str(params.LW_TEST_SIGZ),...
        '],Lamda=[',num2str(params.LW_TEST_LAMXY),',',num2str(params.LW_TEST_LAMXY),',',num2str(params.LW_TEST_LAMZ),']'])
end
hold off
ax2 = nexttile;
p1 = plot(timestamp, log_ac_rates_est(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(vehicle_angular_velocity_timestamp, log_ac_att_wb(:, 1), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('w_x(deg/s)'); 
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ax3 = nexttile;
p1 = plot(timestamp, est_euler(:, 2), 'r-', 'LineWidth', 1);
hold on
p2 = plot(vehicle_attitude_timestamp, euler(:, 2), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('pitch(deg)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ax4 = nexttile;
plot(timestamp, log_ac_rates_est(:, 2), 'r-', 'LineWidth', 1);
hold on
plot(vehicle_angular_velocity_timestamp, log_ac_att_wb(:, 2), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('w_y(deg/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ax5 = nexttile;
p1 = plot(timestamp, est_euler(:, 3), 'r-', 'LineWidth', 1);
hold on
p2 = plot(vehicle_attitude_timestamp, euler(:, 3), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('yaw(deg)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ax6 = nexttile;
plot(timestamp, log_ac_rates_est(:, 3), 'r-', 'LineWidth', 1);
hold on
plot(vehicle_angular_velocity_timestamp, log_ac_att_wb(:, 3), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('w_z(deg/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off


end