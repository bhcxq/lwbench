function plot_PWM(mixer, statemachine, plot_interval)

[timestamp, index] = getIndex(mixer.timestamp * 1e-6, plot_interval);

PWM1 = mixer.log_m_outpwm0(index);
PWM2 = mixer.log_m_outpwm1(index);
PWM3 = mixer.log_m_outpwm2(index);
PWM4 = mixer.log_m_outpwm3(index);
PWM5 = mixer.log_m_outpwm4(index);
PWM6 = mixer.log_m_outpwm5(index);
figure('Name', 'PWM')
subplot(4, 2, [1, 2])
plot(timestamp, PWM1, timestamp, PWM2, timestamp, PWM3, timestamp, PWM4)
ylabel('PWM1~4')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
legend('PWM1','PWM2','PWM3','PWM4')
subplot(4, 2, 3)
plot(timestamp, PWM1)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('PWM1')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 4)
plot(timestamp, PWM2)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('PWM2')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 5)
plot(timestamp, PWM3)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('PWM3')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 6)
plot(timestamp, PWM4)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('PWM4')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 7)
plot(timestamp, PWM5)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('right elevon')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
subplot(4, 2, 8)
plot(timestamp, PWM6)
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('left elevon')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
end