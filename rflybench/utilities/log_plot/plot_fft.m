function plot_fft(imu, vehicle_angular_velocity, vehicle_acceleration, statemachine, params,plot_interval)

[timestamp_raw, index] = getIndex(imu.timestamp * 1e-6, plot_interval);

acc_raw = [imu.accelerometer_m_s20(index) imu.accelerometer_m_s21(index) imu.accelerometer_m_s22(index)];
[acc, timestamp] = resample(acc_raw, timestamp_raw, 250, 'spline');
gyro_raw = [imu.gyro_rad0(index) imu.gyro_rad1(index) imu.gyro_rad2(index)] * 180 / pi;
[gyro, timestamp] = resample(gyro_raw, timestamp_raw, 250, 'spline');
[timestamp_wb_raw, index] = getIndex(vehicle_angular_velocity.timestamp * 1e-6, plot_interval);
gyro_filted_raw = [vehicle_angular_velocity.xyz0(index) vehicle_angular_velocity.xyz1(index) vehicle_angular_velocity.xyz2(index)] * 180 / pi;
[gyro_filted, gyro_timestamp] = resample(gyro_filted_raw, timestamp_wb_raw, 250, 'spline');
[timestamp_acc_raw, index] = getIndex(vehicle_acceleration.timestamp * 1e-6, plot_interval);
acc_filted_raw = [vehicle_acceleration.xyz0(index) vehicle_acceleration.xyz1(index) vehicle_acceleration.xyz2(index)];
[acc_filted, acc_timestamp] = resample(acc_filted_raw, timestamp_acc_raw, 250, 'spline');
% figure
% subplot(3,1,1)
% plot(timestamp_raw,acc_raw(:,1))
% hold on
% plot(timestamp,acc(:,1))
% hold off
% subplot(3,1,2)
% plot(timestamp_raw,acc_raw(:,2))
% hold on
% plot(timestamp,acc(:,2))
% hold off
% subplot(3,1,3)
% plot(timestamp_raw,acc_raw(:,3))
% hold on
% plot(timestamp,acc(:,3))
% hold off

[acc1_f, acc1_P1] = my_fft(acc(:, 1));
[acc2_f, acc2_P1] = my_fft(acc(:, 2));
[acc3_f, acc3_P1] = my_fft(acc(:, 3));
[acc_filted1_f, acc_filted1_P1] = my_fft(acc_filted(:, 1));
[acc_filted2_f, acc_filted2_P1] = my_fft(acc_filted(:, 2));
[acc_filted3_f, acc_filted3_P1] = my_fft(acc_filted(:, 3));
[gyro1_f, gyro1_P1] = my_fft(gyro(:, 1));
[gyro2_f, gyro2_P1] = my_fft(gyro(:, 2));
[gyro3_f, gyro3_P1] = my_fft(gyro(:, 3));
[gyro_filted1_f, gyro_filted1_P1] = my_fft(gyro_filted(:, 1));
[gyro_filted2_f, gyro_filted2_P1] = my_fft(gyro_filted(:, 2));
[gyro_filted3_f, gyro_filted3_P1] = my_fft(gyro_filted(:, 3));

figure('Name','IMU-filted')
tiledlayout(1, 2, 'TileSpacing', 'Compact')
nexttile(1)
plot(acc_timestamp, acc_filted(:, 1),'g');
hold on
plot(acc_timestamp, acc_filted(:, 2),'r');
plot(acc_timestamp, acc_filted(:, 3),'k');
xlabel('t(s)'); ylabel('acc(m/s)');
legend('x', 'y', 'z')
hold off
nexttile(2)
plot(gyro_timestamp, gyro_filted(:, 1),'g');
hold on
plot(gyro_timestamp, gyro_filted(:, 2),'r');
plot(gyro_timestamp, gyro_filted(:, 3),'k');
xlabel('t(s)'); ylabel('gyro(deg/s)');
legend('x', 'y', 'z')
hold off

figure('Name', 'imu-fft')
tiledlayout(3, 2, 'TileSpacing', 'Compact')
nexttile(1)
axis([0, 125, 0, 1])
plot(acc1_f, acc1_P1,'g')
hold on
plot(acc_filted1_f, acc_filted1_P1,'r')
ylabel('accx(m/s)');
legend('raw','filted')
if isfield(params,'IMU_ACCEL_CUTOFF')
    title(['Acc cutoff: ', num2str(params.IMU_ACCEL_CUTOFF)])
end
hold off

nexttile(3)
axis([0, 125, 0, 1])
plot(acc2_f, acc2_P1,'g')
hold on
plot(acc_filted2_f, acc_filted2_P1,'r')
ylabel('accy(m/s)');
hold off

nexttile(5)
axis([0, 125, 0, 1])
plot(acc3_f, acc3_P1,'g')
hold on
plot(acc_filted3_f, acc_filted3_P1,'r')
ylabel('accz(m/s)');
xlabel('频率(Hz)');
hold off

% p1 = plot(timestamp, acc_filted(:, 1));
% hold on
% p2 = plot(timestamp, acc_filted(:, 2));
% p3 = plot(timestamp, acc_filted(:, 3));
% axis([-inf inf -25 25])
% plot_statemachine(statemachine, plot_interval)
% xlabel('t(s)'); ylabel('acc(m/s)');
% legend([p1 p2 p3], 'x', 'y', 'z')
% hold off
% nexttile(2)
% plot(acc1_f, acc1_P1)
% hold on
% plot(acc2_f, acc2_P1)
% plot(acc3_f, acc3_P1)
% if isfield(params,'IMU_ACCEL_CUTOFF')
%     title(['Acc cutoff: ', num2str(params.IMU_ACCEL_CUTOFF)])
% end
% xlabel('频率(Hz)'); ylabel('acc fft')
% axis([0, 125, 0, 1])
% hold off
nexttile(2)

% p1 = plot(timestamp, gyro(:, 1));
% hold on
% p2 = plot(timestamp, gyro(:, 2));
% p3 = plot(timestamp, gyro(:, 3));
% axis([-inf inf -200 200])
% plot_statemachine(statemachine, plot_interval)
% xlabel('t(s)'); ylabel('gyro(deg/s)');
% legend([p1 p2 p3], 'x', 'y', 'z')
% hold off
% nexttile(4)
plot(gyro1_f, gyro1_P1,'g')
hold on
plot(gyro_filted1_f, gyro_filted1_P1,'r')
ylabel('gyrox(rad/s)')
if isfield(params,'IMU_GYRO_CUTOFF')
    title(['Gyro cutoff: ', num2str(params.IMU_GYRO_CUTOFF)])
end
hold off
nexttile(4)
plot(gyro2_f, gyro2_P1,'g')
hold on
plot(gyro_filted2_f, gyro_filted2_P1,'r')
ylabel('gyroy(rad/s)')
hold off
nexttile(6)
plot(gyro3_f, gyro3_P1,'g')
hold on
plot(gyro_filted3_f, gyro_filted3_P1,'r')
ylabel('gyroz(rad/s)')
hold off
xlabel('频率(Hz)');
hold off

end