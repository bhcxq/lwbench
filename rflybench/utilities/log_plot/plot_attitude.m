function plot_attitude(attctrl, navigator, statemachine, params, plot_interval)

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
% save('log_ac_att_wl','log_ac_att_wl');
% save('log_ac_rates_ref','log_ac_rates_ref')


figure('Name', 'attitude');

tiledlayout(3, 2, 'TileSpacing', 'Compact')
ax1=nexttile;
p1 = plot(timestamp, euler(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(timestamp, euler_ref(:, 1), 'g--', 'LineWidth', 1);
p3 = plot(n_timestamp, ob_euler(:, 1), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('roll(deg)'); legend([p1 p2 p3], 'feedback', 'ref','offboard')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_ROLL_P')
    title(ax1,['Kp=',num2str(params.LW_ROLL_P)])
end
hold off
ax2 = nexttile;
p1 = plot(timestamp, log_ac_att_wb(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(timestamp, log_ac_wb_ref(:, 1), 'g--', 'LineWidth', 1);
p3 = plot(n_timestamp, ob_wbref(:, 1), 'b--', 'LineWidth', 1);

plot_statemachine(statemachine, plot_interval)
box on
ylabel('p(deg/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_WX_P')
    if isfield(params,'LW_TAUSP_FZ')
        title(ax2,['Kp=',num2str(params.LW_WX_P),',Ki=',num2str(params.LW_WX_I),',Kd=',num2str(params.LW_WX_D),...
              ' ,TAUSP\_FZ=',num2str(params.LW_TAUSP_FZ), ' ,TAUSP\_TM=',num2str(params.LW_TAUSP_TM)])
    else
        title(ax2,['Kp=',num2str(params.LW_WX_P),',Ki=',num2str(params.LW_WX_I),',Kd=',num2str(params.LW_WX_D),...
              ' ,TAUXYSP\_FZ=',num2str(params.LW_TAUXYSP_FZ), ' ,TAUSP\_TM=',num2str(0),...
              ' ,TAUZSP\_FZ=',num2str(params.LW_TAUZSP_FZ), ' ,TAUZSP\_TM=',num2str(params.LW_TAUZSP_TM)])
    end
end
hold off
ax3 = nexttile;
plot(timestamp, euler(:, 2), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, euler_ref(:, 2), 'g--', 'LineWidth', 1)
plot(n_timestamp, ob_euler(:, 2), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('pitch(deg)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_PITCH_P')
    title(ax3,['Kp=',num2str(params.LW_PITCH_P)])
end
hold off
ax4 = nexttile;
plot(timestamp, log_ac_att_wb(:, 2), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, log_ac_wb_ref(:, 2), 'g--', 'LineWidth', 1)
plot(n_timestamp, ob_wbref(:, 2), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('q(deg/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_WY_P')
    title(ax4,['Kp=',num2str(params.LW_WY_P),',Ki=',num2str(params.LW_WY_I),',Kd=',num2str(params.LW_WY_D)])
end
hold off
ax5 = nexttile;
plot(timestamp, euler(:, 3), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, euler_ref(:, 3), 'g--', 'LineWidth', 1)
plot(n_timestamp, ob_euler(:, 3), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
xlabel('t(s)'); ylabel('yaw(deg)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_YAW_P')
    title(ax5,['Kp=',num2str(params.LW_YAW_P),', RelaxedYaw = ',num2str(params.LW_REX_YAW)])
end
hold off
ax6 = nexttile;
plot(timestamp, log_ac_att_wb(:, 3), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, log_ac_wb_ref(:, 3), 'g--', 'LineWidth', 1)
plot(n_timestamp, ob_wbref(:, 3), 'b--', 'LineWidth', 1);
plot(n_timestamp, manual_rates_ref(:, 3), 'k--', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
box on
xlabel('t(s)'); ylabel('r(deg/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_WZ_P')
    title(ax6,['Kp=',num2str(params.LW_WZ_P),',Ki=',num2str(params.LW_WZ_I),',Kd=',num2str(params.LW_WZ_D)])
end
hold off
end