function plot_mixer_t(mixer, statemachine, plot_interval)

[timestamp, index] = getIndex(mixer.timestamp * 1e-6, plot_interval);

telapsed = mixer.log_m_telapsed(index);
iter = mixer.log_m_iter(index);

figure('Name', 'mixer')
subplot(2, 1, 1)
plot(timestamp, telapsed)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('telapsed')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(2, 1, 2)
plot(timestamp, iter)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('iter')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
end