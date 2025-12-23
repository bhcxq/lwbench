function plot_resist_wind(posctrl, attctrl, airspeed, navigator, statemachine, params, plot_interval)

[timestamp, index] = getIndex(attctrl.timestamp * 1e-6, plot_interval);
log_ac_att_q = [attctrl.log_ac_att_q0(index) attctrl.log_ac_att_q1(index) attctrl.log_ac_att_q2(index) attctrl.log_ac_att_q3(index)];
for i = 1 : size(log_ac_att_q, 1)
    euler(i, 1 : 3) = my_quat2eul(log_ac_att_q(i, :)','ZYX') * 180 / pi;
end

log_ac_att_q_ref = [attctrl.log_ac_q_ref0(index) attctrl.log_ac_q_ref1(index) attctrl.log_ac_q_ref2(index) attctrl.log_ac_q_ref3(index)];
for i = 1 : size(log_ac_att_q_ref, 1)
    euler_ref(i, 1 : 3) = my_quat2eul(log_ac_att_q_ref(i, :)','ZYX') * 180 / pi;
end

roll_iddata = iddata(euler(:, 1), [], 0.004);
% sys = ar(roll_iddata, 4);
% iosys = noise2meas(sys);
%   step(iosys);

log_ac_att_wb = [attctrl.log_ac_att_wb0(index), attctrl.log_ac_att_wb1(index), attctrl.log_ac_att_wb2(index)] * 180 / pi;
kappa = (params.LW_ANGLE * pi / 180);
R_lb = [cos(kappa), (0.0), -sin(kappa);
    (0.0), (1.0), (0);
    sin(kappa), (0.0), cos(kappa)];
log_ac_att_wl = R_lb * log_ac_att_wb';
log_ac_att_wl = log_ac_att_wl';
log_ac_rates_ref = [attctrl.log_ac_rates_ref0(index), attctrl.log_ac_rates_ref1(index), attctrl.log_ac_rates_ref2(index)] * 180 / pi;
log_ac_wb_ref = log_ac_rates_ref;

[n_timestamp, n_index] = getIndex(navigator.timestamp * 1e-6, plot_interval);
manual_rates_ref = [navigator.manual_ref3(n_index) navigator.manual_ref4(n_index) navigator.manual_ref5(n_index)]* 180 / pi;
ob_wbref = [navigator.offboard_ref16(n_index) navigator.offboard_ref17(n_index) navigator.offboard_ref18(n_index)]*180/pi;
ob_wlref = R_lb * ob_wbref';
ob_wlref = ob_wlref';
ob_qref = [navigator.offboard_ref9(n_index) navigator.offboard_ref10(n_index) navigator.offboard_ref11(n_index) navigator.offboard_ref12(n_index)];
for i = 1 : size(ob_qref, 1)
    ob_euler(i, 1 : 3) = my_quat2eul(ob_qref(i, :)','ZYX') * 180 / pi;
end

[airspeed_timestamp, airspeed_index] = getIndex(airspeed.timestamp * 1e-6, plot_interval);
[calibrated_airspeed_m_s_resample, airspeed_timestamp_resample] = resample(airspeed.calibrated_airspeed_m_s(airspeed_index), airspeed_timestamp, 250, 'spline');
firf = designfilt('lowpassfir','FilterOrder',50, 'CutoffFrequency',1,'SampleRate',250);
calibrated_airspeed_m_s_filted = filtfilt(firf,calibrated_airspeed_m_s_resample);
figure('Name', 'attitude-airspeed');

tiledlayout(3, 1, 'TileSpacing', 'Compact')
ax1=nexttile;
yyaxis left
p1 = plot(timestamp, euler(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(timestamp, euler_ref(:, 1), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('roll(deg)'); legend([p1 p2], 'feedback', 'ref')
yyaxis right 
grid on
plot(airspeed_timestamp_resample, calibrated_airspeed_m_s_filted, 'b-.', 'LineWidth', 1);

axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

ax3 = nexttile;
yyaxis left
plot(timestamp, euler(:, 2), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, euler_ref(:, 2), 'g--', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
box on
ylabel('pitch(deg)');

yyaxis right 
grid on
plot(airspeed_timestamp_resample, calibrated_airspeed_m_s_filted, 'b-.', 'LineWidth', 1);
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

ax5 = nexttile;
plot(timestamp, euler(:, 3), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, euler_ref(:, 3), 'g--', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
box on
xlabel('t(s)'); ylabel('yaw(deg)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

[pos_timestamp, index] = getIndex(posctrl.timestamp * 1e-6, plot_interval);
posctrl_pos = [posctrl.log_pc_local_pos0(index) posctrl.log_pc_local_pos1(index) posctrl.log_pc_local_pos2(index)];
posctrl_pos_ref = [posctrl.log_pc_local_pos_ref0(index) posctrl.log_pc_local_pos_ref1(index) posctrl.log_pc_local_pos_ref2(index)];
for i = 2 : length(posctrl_pos_ref)
    if posctrl_pos_ref(i, 1) == 0 && posctrl_pos_ref(i, 2) == 0
        posctrl_pos_ref(i, 1 : 2) = posctrl_pos_ref(i - 1, 1 : 2);
    end
end
for i = 2 : length(posctrl_pos)
    if posctrl_pos(i, 1) == 0 && posctrl_pos(i, 2) == 0
        posctrl_pos(i, 1 : 2) = posctrl_pos(i - 1, 1 : 2);
    end
end


posctrl_vel = [posctrl.log_pc_local_pos3(index) posctrl.log_pc_local_pos4(index) posctrl.log_pc_local_pos5(index)];
for i = 1 : length(posctrl_vel)
    posctrl_vel_xy(i) = norm(posctrl_vel(i, 1 : 2));
end

posctrl_vel_ref = [posctrl.log_pc_local_pos_ref3(index) posctrl.log_pc_local_pos_ref4(index) posctrl.log_pc_local_pos_ref5(index)];
log_ac_att_q = [attctrl.log_ac_att_q0 attctrl.log_ac_att_q1 attctrl.log_ac_att_q2 attctrl.log_ac_att_q3];
for i = 1 : length(posctrl_vel_ref)
    posctrl_vel_ref_xy(i) = norm(posctrl_vel_ref(i, 1 : 2));
end
[n_timestamp, n_index] = getIndex(navigator.timestamp * 1e-6, plot_interval);
ob_vel_ref = [navigator.offboard_ref3(n_index) navigator.offboard_ref4(n_index) navigator.offboard_ref5(n_index)];

figure('Name', 'pos')
tiledlayout(2, 1, 'TileSpacing', 'Compact')


nexttile(1);
plot(posctrl_pos(:, 1)-posctrl_pos(1, 1), posctrl_pos(:, 2)-posctrl_pos(1, 2), 'r--', 'LineWidth', 1);
hold on
%plot(timestamp, posctrl_pos_ref(:, 1), 'g-', 'LineWidth', 1);
%plot_statemachine(statemachine, plot_interval)
box on
xlabel('x(m)')
ylabel('y(m)');
axis equal
hold off


nexttile(2);
plot(pos_timestamp, vecnorm(posctrl_pos_ref(:, 1:3) - posctrl_pos(:,1:3),2,2),'LineWidth',1);
hold on
plot_statemachine(statemachine, plot_interval)
box on
xlabel('time(s)')
ylabel('pos error (m)');
hold off
end