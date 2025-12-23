function plot_dataflow(manual_ctrl, navigator, attctrl, posctrl, mixer, plot_interval)
[man_timestamp, index] = getIndex(manual_ctrl.timestamp * 1e-6, plot_interval);
manual_xyz = [manual_ctrl.x(index) manual_ctrl.y(index) manual_ctrl.z(index)];
manual_r = manual_ctrl.r(index);
%attitude
[n_timestamp, index] = getIndex(navigator.timestamp * 1e-6, plot_interval);
manual_euler_ref = [navigator.manual_ref0(index) navigator.manual_ref1(index) navigator.manual_ref2(index)];
manual_rates_ref = [navigator.manual_ref3(index) navigator.manual_ref4(index) navigator.manual_ref5(index)];
%thrust
manual_thrust = navigator.manual_ref6(index);
%delta
manual_delta = [navigator.manual_ref7(index) navigator.manual_ref8(index) navigator.manual_ref9(index)];
%vel
manual_vel = [navigator.manual_ref10(index) navigator.manual_ref11(index) navigator.manual_ref12(index)];

[pc_timestamp, index] = getIndex(posctrl.timestamp * 1e-6, plot_interval);
pc_vel_ref = [posctrl.log_pc_local_pos_ref3(index) posctrl.log_pc_local_pos_ref4(index) posctrl.log_pc_local_pos_ref5(index)];
pc_q_ref = [posctrl.log_pc_att_ref0(index) posctrl.log_pc_att_ref1(index) posctrl.log_pc_att_ref2(index) posctrl.log_pc_att_ref3(index)];
pc_acc_ref = [posctrl.log_pc_accel_ref0(index) posctrl.log_pc_accel_ref1(index) posctrl.log_pc_accel_ref2(index)];
for ii = 1:length(pc_q_ref)
    pc_euler_ref(ii,:) = my_quat2eul(pc_q_ref(ii,:));
end

[ac_timestamp, index] = getIndex(attctrl.timestamp * 1e-6, plot_interval);
ac_q_ref = [attctrl.log_ac_q_ref0(index) attctrl.log_ac_q_ref1(index) attctrl.log_ac_q_ref2(index) attctrl.log_ac_q_ref3(index)];
for ii = 1:length(ac_q_ref)
    ac_euler_ref(ii,:) = my_quat2eul(ac_q_ref(ii,:));
end
ac_rates_ref = [attctrl.log_ac_rates_ref0(index) attctrl.log_ac_rates_ref1(index) attctrl.log_ac_rates_ref2(index)];

[m_timestamp, index] = getIndex(mixer.timestamp * 1e-6, plot_interval);
T5 = mixer.log_m_t_limit4(index);
T6 = mixer.log_m_t_limit5(index);
PWM5 = mixer.log_m_outpwm4(index);
PWM6 = mixer.log_m_outpwm5(index);

% figure('Name', 'data flow--yaw rate')
% plot(n_timestamp, manual_rates_ref(:, 3))
% hold on
% plot(ac_timestamp, ac_rates_ref(:, 3))
% hold off
% figure('Name', 'data flow--delta_e')
% plot(n_timestamp, manual_delta(:, 2) * 1000)
% hold on
% plot(m_timestamp, PWM5)
% plot(m_timestamp, PWM6)
% hold off

% figure('Name', 'data yaw')
% plot(pc_timestamp, pc_euler_ref(:, 3))
% hold on
% plot(ac_timestamp, ac_euler_ref(:, 3))
% plot(n_timestamp, manual_rates_ref(:, 3))
% hold off
figure('Name', 'position control')
plot(n_timestamp, manual_vel(:, 1))
hold on
plot(pc_timestamp, pc_vel_ref(:, 1))
plot(man_timestamp,manual_xyz(:,1))
plot(pc_timestamp, pc_acc_ref(:, 1))
hold off
legend('Navigator','pos ctrl','man z')

figure('Name', 'position control')
plot(n_timestamp, manual_vel(:, 3))
hold on
plot(pc_timestamp, pc_vel_ref(:, 3))
plot(man_timestamp,manual_xyz(:,3))
plot(pc_timestamp, pc_acc_ref(:, 3))
hold off
legend('Navigator','pos ctrl','man z')

figure('Name', 'position control')
plot(n_timestamp, manual_rates_ref(:, 3))
hold on
plot(man_timestamp, manual_r)
hold off
legend('Navigator','man r')


end