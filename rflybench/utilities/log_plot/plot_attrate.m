function plot_attrate(attctrl, params, navigator,statemachine, plot_interval)
[timestamp, index] = getIndex(attctrl.timestamp * 1e-6, plot_interval);
log_ac_att_wb = [attctrl.log_ac_att_wb0(index), attctrl.log_ac_att_wb1(index), attctrl.log_ac_att_wb2(index)]*180/pi;
log_ac_rates_ref = [attctrl.log_ac_rates_ref0(index), attctrl.log_ac_rates_ref1(index), attctrl.log_ac_rates_ref2(index)]*180/pi;
kappa = (params.LW_ANGLE * pi / 180);
    R_lb = [cos(kappa), single(0.0), -sin(kappa);
        single(0.0), single(1.0), single(0);
        sin(kappa), single(0.0), cos(kappa)];
    log_ac_att_wl = log_ac_att_wb*R_lb';
log_ac_att_wl_ref = log_ac_rates_ref*R_lb';
[n_timestamp, n_index] = getIndex(navigator.timestamp * 1e-6, plot_interval);
ob_wbref = [navigator.offboard_ref16(n_index) navigator.offboard_ref17(n_index) navigator.offboard_ref18(n_index)];
ob_wlref = R_lb * ob_wbref';
ob_wlref = ob_wlref'*180/pi;

figure('Name', 'angle rate in lifting-wing frame')
tiledlayout(3, 1, 'TileSpacing', 'Compact')
ax_wx = nexttile;
p1 = plot(timestamp, log_ac_att_wl(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(timestamp, log_ac_att_wl_ref(:, 1), 'g--', 'LineWidth', 1);
p3 = plot(n_timestamp, ob_wlref(:, 1), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('p(deg/s)'); legend([p1 p2 p3], 'feedback', 'ref','offboard')
axis([plot_interval.startTime, plot_interval.endTime, -100, 100])
hold off
nexttile
plot(timestamp, log_ac_att_wl(:, 2), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, log_ac_att_wl_ref(:, 2), 'g--', 'LineWidth', 1)
plot(n_timestamp, ob_wlref(:, 2), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('q(deg/s)');
axis([plot_interval.startTime, plot_interval.endTime, -100, 100])
hold off
nexttile
plot(timestamp, log_ac_att_wl(:, 3), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, log_ac_att_wl_ref(:, 3), 'g--', 'LineWidth', 1)
plot(n_timestamp, ob_wlref(:, 3), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
xlabel('t(s)'); ylabel('r(deg/s)');
axis([plot_interval.startTime, plot_interval.endTime, -100, 100])
hold off
end