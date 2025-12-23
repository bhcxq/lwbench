function plot_statemachine(statemachine, plot_interval)

[timestamp, index] = getIndex(statemachine.timestamp * 1e-6, plot_interval);
statemachine.control_mode(find(statemachine.arm == 1)) = 1;
control_mode = statemachine.control_mode(index) + statemachine.flight_mode(index);
fill_statemachine(timestamp, statemachine.arm(index)+statemachine.flight_mode(index), 'Arm');
fill_statemachine(timestamp, control_mode, 'Manual');
fill_statemachine(timestamp, control_mode, 'Acro');
fill_statemachine(timestamp, control_mode, 'Stabilize');
fill_statemachine(timestamp, control_mode, 'Altitude');
fill_statemachine(timestamp, control_mode, 'Position');
fill_statemachine(timestamp, control_mode, 'Mission');
fill_statemachine(timestamp, control_mode, 'Offboard');

end