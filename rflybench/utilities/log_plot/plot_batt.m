function plot_batt(battery, statemachine, plot_interval)

[timestamp, index] = getIndex(battery.timestamp * 1e-6, plot_interval);

voltage = battery.voltage_v(index);
voltage_filter = battery.voltage_filtered_v(index);
current = battery.current_a(index);
current_filter = battery.current_filtered_a(index);
discharged_mah = battery.discharged_mah(index);
figure('Name', 'battery')
tiledlayout(3, 1, 'TileSpacing', 'Compact')
nexttile(1)
yyaxis left;

%plot(timestamp, voltage,'g--','LineWidth',0.5)
hold on
plot(timestamp, voltage_filter, 'b', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
ylabel('Voltage(V)')
yyaxis right;
%plot(timestamp, current,'b--','LineWidth',0.5)
plot(timestamp, current_filter, 'r', 'LineWidth', 1)
ylabel('Current(I)')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(2)
plot(timestamp, voltage .* current, 'g--', 'LineWidth', 1)
hold on
plot(timestamp, voltage_filter .* current_filter, 'r', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('P')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
nexttile(3)
plot(timestamp, discharged_mah, 'LineWidth', 1)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('E')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
end