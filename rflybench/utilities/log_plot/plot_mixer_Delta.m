function plot_mixer_Delta(mixer, statemachine, plot_interval)

[timestamp_raw, index] = getIndex(mixer.timestamp * 1e-6, plot_interval);
T1 = resample(mixer.log_m_t_limit0(index), timestamp_raw, 250, 5, 1, 'spline');
T2 = resample(mixer.log_m_t_limit1(index), timestamp_raw, 250, 5, 1, 'spline');
T3 = resample(mixer.log_m_t_limit2(index), timestamp_raw, 250, 5, 1, 'spline');
T4 = resample(mixer.log_m_t_limit3(index), timestamp_raw, 250, 5, 1, 'spline');
T5 = resample(mixer.log_m_t_limit4(index), timestamp_raw, 250, 5, 1, 'spline');
[T6, timestamp] = resample(mixer.log_m_t_limit5(index), timestamp_raw, 250, 5, 1, 'spline');

figure('Name', 'mixer T')
subplot(4, 2, [1, 2])
plot(timestamp, T1, timestamp, T2, timestamp, T3, timestamp, T4)
ylabel('T1~4')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 3)
plot(timestamp, T1)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('T1')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 4)
plot(timestamp, T2)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('T2')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 5)
plot(timestamp, T3)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('T3')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 6)
plot(timestamp, T4)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('T4')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 7)
plot(timestamp, T5)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('right elevon')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 8)
plot(timestamp, T6)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('left elevon')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
end