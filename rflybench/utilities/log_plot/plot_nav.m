function plot_nav(navigator, statemachine, plot_interval)
%attitude
[n_timestamp, index] = getIndex(navigator.timestamp * 1e-6, plot_interval);
%manual_euler_ref = [navigator.manual_ref0(index) navigator.manual_ref1(index) navigator.manual_ref2(index)];
%manual_rates_ref = [navigator.manual_ref3(index) navigator.manual_ref4(index) navigator.manual_ref5(index)];
%thrust
%manual_thrust = navigator.manual_ref6(index);
%delta
%manual_delta = [navigator.manual_ref7(index) navigator.manual_ref8(index) navigator.manual_ref9(index)];
%vel
manual_vel = [navigator.manual_ref10(index) navigator.manual_ref11(index) navigator.manual_ref12(index)];

figure('Name', 'manual vel')
tiledlayout(3, 1, 'TileSpacing', 'Compact')
nexttile(1)
plot(n_timestamp, manual_vel(:, 1), 'r--', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
ylabel('vx');
legend('vx')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(2)
plot(n_timestamp, manual_vel(:, 2), 'r--', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
ylabel('vy');
legend('vy')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(3)
plot(n_timestamp, manual_vel(:, 3), 'r--', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
xlabel('x'); ylabel('z');
legend('vz')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
end