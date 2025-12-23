function plot_vel(posctrl, attctrl, imu, navigator, statemachine, plot_interval)


[timestamp_raw, i_index] = getIndex(imu.timestamp * 1e-6, plot_interval);
acc_raw = [imu.accelerometer_m_s20(i_index) imu.accelerometer_m_s21(i_index) imu.accelerometer_m_s22(i_index)];

[p_timestamp, p_index] = getIndex(posctrl.timestamp * 1e-6, plot_interval);
posctrl_vel = [posctrl.log_pc_local_pos3(p_index) posctrl.log_pc_local_pos4(p_index) posctrl.log_pc_local_pos5(p_index)];
for i = 1 : length(posctrl_vel)
    posctrl_vel_xy(i) = norm(posctrl_vel(i, 1 : 2));
end

[n_timestamp, n_index] = getIndex(navigator.timestamp * 1e-6, plot_interval);
manual_vel = [navigator.manual_ref10(n_index) navigator.manual_ref11(n_index) navigator.manual_ref12(n_index)];
ob_vel_ref = [navigator.offboard_ref3(n_index) navigator.offboard_ref4(n_index) navigator.offboard_ref5(n_index)];
fd = navigator.offboard_ref13(n_index);
ob_alpha_ref = navigator.offboard_ref14(n_index)*180/pi;
ob_beta_ref = navigator.offboard_ref15(n_index)*180/pi;
posctrl_vel_ref = [posctrl.log_pc_local_pos_ref3(p_index) posctrl.log_pc_local_pos_ref4(p_index) posctrl.log_pc_local_pos_ref5(p_index)];
posctrl_q_ref = [posctrl.log_pc_att_ref0(p_index) posctrl.log_pc_att_ref1(p_index) posctrl.log_pc_att_ref2(p_index) posctrl.log_pc_att_ref3(p_index)];
posctrl_acc_ref = [posctrl.log_pc_accel_ref0(p_index) posctrl.log_pc_accel_ref1(p_index) posctrl.log_pc_accel_ref2(p_index)];

log_ac_att_q = [attctrl.log_ac_att_q0 attctrl.log_ac_att_q1 attctrl.log_ac_att_q2 attctrl.log_ac_att_q3];
k = (34 * pi / 180);
R_lb = [cos(k), (0.0), -sin(k);
         (0.0), (1.0), (0);
        sin(k), (0.0), cos(k)];

for i = 1 : length(posctrl_vel_ref)
    posctrl_vel_ref_xy(i) = norm(posctrl_vel_ref(i, 1 : 2));
    q = log_ac_att_q(find(attctrl.timestamp * 1e-6 >= p_timestamp(i), 1), :);
    q_ref = posctrl_q_ref(i,:)';
    flight_mode = statemachine.flight_mode(find(statemachine.timestamp* 1e-6 >= p_timestamp(i),1));
    if flight_mode > 0 
        if norm(q_ref) < 0.5 || isempty(q_ref)
            posctrl_acc_ref(i,1:3) = posctrl_acc_ref(i,1:3);
        else
            posctrl_acc_ref(i,1:3) = (quat2yaw(q_ref) * posctrl_acc_ref(i,1:3)');
        end
    end

    if norm(q_ref) < 0.5
        posctrl_vel_refyaw(i, 1 : 3) = posctrl_vel_ref(i, :)';
        posctrl_vel_refb(i, 1 : 3) = posctrl_vel_ref(i, :)';
        posctrl_vel_refl(i, 1 : 3) = R_lb*posctrl_vel_ref(i, :)';
        posctrl_velyaw(i, 1 : 3) = posctrl_vel(i, :)';
        posctrl_velb(i, 1 : 3) = posctrl_vel(i, :)';
        posctrl_vell(i, 1 : 3) = R_lb*posctrl_vel(i, :)';
        posctrl_va(i, 1 : 3) = posctrl_vel(i, :)';
    else
        yaw_ref = quat2yaw(q_ref);
        Ryawe = [cos(yaw_ref) sin(yaw_ref)  0;
           -sin(yaw_ref) cos(yaw_ref) 0;
            0 0 1];
        Rbe = quat2dcm(q);
        posctrl_vel_refyaw(i, 1 : 3) = Ryawe * posctrl_vel_ref(i, :)';
        posctrl_vel_refb(i, 1 : 3) = Rbe * posctrl_vel_ref(i, :)';
        posctrl_vel_refl(i, 1 : 3) = R_lb*Rbe * posctrl_vel_ref(i, :)';
        posctrl_velyaw(i, 1 : 3) = Ryawe * posctrl_vel(i, :)';
        posctrl_velb(i, 1 : 3) = Rbe * posctrl_vel(i, :)';
        posctrl_vell(i, 1 : 3) = R_lb*Rbe * posctrl_vel(i, :)';
        posctrl_va(i, 1 : 3) = Ryawe * posctrl_vel(i, :)';
    end
    posctrl_Va(i) = norm(posctrl_vel(i, :));
    beta(i) = asin(posctrl_vell(i, 2)/posctrl_Va(i))*tanh(pi*posctrl_Va(i)/3)*180/pi;
    alpha(i) = atan2(posctrl_vell(i, 3), posctrl_vell(i, 1))*tanh(pi*posctrl_Va(i)/3)*180/pi;
end
%save('posctrl_velb','posctrl_velyaw')
%save('posctrl_vel_refb','posctrl_vel_refyaw')

for i = 1 : length(ob_vel_ref)
    q = log_ac_att_q(find(attctrl.timestamp * 1e-6 >= n_timestamp(i), 1), :);
    posctrl_q_ref = [posctrl.log_pc_att_ref0 posctrl.log_pc_att_ref1 posctrl.log_pc_att_ref2 posctrl.log_pc_att_ref3];
    q_ref = posctrl_q_ref(find(posctrl.timestamp * 1e-6 >= n_timestamp(i), 1), :)';
    if norm(q_ref) < 0.5
        ob_velyaw_ref(i, 1 : 3) = ob_vel_ref(i, :)';
        ob_velb_ref(i, 1 : 3) = ob_vel_ref(i, :)';
        ob_vell_ref(i, 1 : 3) = R_lb * ob_vel_ref(i, :)';
    else
        yaw_ref = quat2yaw(q_ref);
        Ryawe = [cos(yaw_ref) sin(yaw_ref)  0;
           -sin(yaw_ref) cos(yaw_ref) 0;
            0 0 1];
        Rbe = quat2dcm(q);
        ob_velb_ref(i, 1 : 3) = Rbe * ob_vel_ref(i, :)';
        ob_vell_ref(i, 1 : 3) = R_lb * Rbe * ob_vel_ref(i, :)';
        ob_velyaw_ref(i, 1 : 3) = Ryawe * ob_vel_ref(i, :)';

    end
end

[acc_raw, timestamp_raw] = resample(acc_raw, timestamp_raw, 250, 'spline');
firf = designfilt('lowpassfir','FilterOrder',150, 'CutoffFrequency',5,'SampleRate',250);
if length(acc_raw) < 450
    acc_filted = acc_raw;
else
    acc_filted = filtfilt(firf,acc_raw);
end


for i = 1 : length(acc_filted)
    q = log_ac_att_q(find(attctrl.timestamp * 1e-6 >= timestamp_raw(i), 1), :);
        if norm(q) < 0.5 || isempty(q)
            acc_b(i,1:3) = acc_filted(i,1:3);
        else
            acc_b(i,1:3) = quat2yaw(q')*(quat2R(q) * acc_filted(i,1:3)' + [0 0 9.8]');
        end
    %end
end
for i = 1 : size(log_ac_att_q, 1)
    euler(i, 1 : 3) = my_quat2eul(log_ac_att_q(i, :)') * 180 / pi;
end
[att_timestamp, att_index] = getIndex(attctrl.timestamp * 1e-6, plot_interval);


figure('Name', 'vel in heading coordinate')
tiledlayout(3, 2, 'TileSpacing', 'Compact')
nexttile(2)
p1 = plot(timestamp_raw, acc_b(:,1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(p_timestamp, posctrl_acc_ref(:,1), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
ylabel('a_x^\psi')
box on; legend([p1, p2],'feedback', 'ref')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(4)
plot(timestamp_raw, acc_b(:,2), 'r-', 'LineWidth', 1)
hold on
plot(p_timestamp, posctrl_acc_ref(:,2), 'g--', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
ylabel('a_y^\psi')
box on;
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(6)
plot(timestamp_raw, acc_b(:,3), 'r-', 'LineWidth', 1)
hold on
plot(p_timestamp, posctrl_acc_ref(:,3), 'g--', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
xlabel('t(s)'); ylabel('a_z^\psi')
box on; 
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

nexttile(1)
p1 = plot(p_timestamp, posctrl_velyaw(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(p_timestamp, posctrl_vel_refyaw(:, 1), 'g--', 'LineWidth', 1);
p3 = plot(n_timestamp, manual_vel(:, 1), 'k--', 'LineWidth', 1);
p4 = plot(n_timestamp, ob_velyaw_ref(:, 1), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_x^\psi');
legend([p1 p2 p3 p4], 'feedback', 'ref','man','offboard')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(3)
plot(p_timestamp, posctrl_velyaw(:, 2), 'r-', 'LineWidth', 1)
hold on
plot(p_timestamp, posctrl_vel_refyaw(:, 2), 'g--', 'LineWidth', 1)
plot(n_timestamp, manual_vel(:, 2), 'k--', 'LineWidth', 1);
plot(n_timestamp, ob_velyaw_ref(:, 2), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_y^\psi');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(5)
plot(p_timestamp, posctrl_velyaw(:, 3), 'r-', 'LineWidth', 1)
hold on
plot(p_timestamp, posctrl_vel_refyaw(:, 3), 'g--', 'LineWidth', 1)
plot(n_timestamp, manual_vel(:, 3), 'k--', 'LineWidth', 1);
plot(n_timestamp, ob_velyaw_ref(:, 3), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_z^\psi'); 
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

figure('Name', 'vel in body coordinate')
tiledlayout(3, 1, 'TileSpacing', 'Compact')
nexttile(1)
p1 = plot(p_timestamp, posctrl_velb(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(p_timestamp, posctrl_vel_refb(:, 1), 'g--', 'LineWidth', 1);
p4 = plot(n_timestamp, ob_velb_ref(:, 1), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_x^b');
legend([p1 p2 p4], 'feedback', 'ref','offboard')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(2)
plot(p_timestamp, posctrl_velb(:, 2), 'r-', 'LineWidth', 1)
hold on
plot(p_timestamp, posctrl_vel_refb(:, 2), 'g--', 'LineWidth', 1)
plot(n_timestamp, ob_velb_ref(:, 2), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_y^b');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(3)
plot(p_timestamp, posctrl_velb(:, 3), 'r-', 'LineWidth', 1)
hold on
plot(p_timestamp, posctrl_vel_refb(:, 3), 'g--', 'LineWidth', 1)
plot(n_timestamp, ob_velb_ref(:, 3), 'b--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_z^b'); 
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

figure('Name', 'aerodynamic angle')
tiledlayout(2, 1, 'TileSpacing', 'Compact')
nexttile(1)
p1 = plot(p_timestamp, alpha, 'r-', 'LineWidth', 1);
hold on
p2 = plot(n_timestamp, ob_alpha_ref, 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('alpha(deg)');
legend([p1 p2], 'feedback', 'offboard')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
nexttile(2)
p1 = plot(p_timestamp, beta, 'r-', 'LineWidth', 1);
hold on
p2 = plot(n_timestamp, ob_beta_ref, 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('beta(deg)');
legend([p1 p2], 'feedback', 'offboard')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

% figure('Name', 'vel in the lifting-wing coordinate')
% tiledlayout(3, 1, 'TileSpacing', 'Compact')
% nexttile(1)
% p1 = plot(p_timestamp, posctrl_vell(:, 1), 'r-', 'LineWidth', 1);
% hold on
% p2 = plot(p_timestamp, posctrl_vel_refl(:, 1), 'g--', 'LineWidth', 1);
% p4 = plot(n_timestamp, ob_vell_ref(:, 1), 'b--', 'LineWidth', 1);
% plot_statemachine(statemachine, plot_interval)
% box on; ylabel('v_x^l');
% legend([p1 p2 p4], 'feedback', 'ref','offboard')
% axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
% hold off
% nexttile(2)
% plot(p_timestamp, posctrl_vell(:, 2), 'r-', 'LineWidth', 1)
% hold on
% plot(p_timestamp, posctrl_vel_refl(:, 2), 'g--', 'LineWidth', 1)
% plot(n_timestamp, ob_vell_ref(:, 2), 'b--', 'LineWidth', 1);
% plot_statemachine(statemachine, plot_interval)
% box on; ylabel('v_y^l');
% axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
% hold off
% nexttile(3)
% plot(p_timestamp, posctrl_vell(:, 3), 'r-', 'LineWidth', 1)
% hold on
% plot(p_timestamp, posctrl_vel_refl(:, 3), 'g--', 'LineWidth', 1)
% plot(n_timestamp, ob_vell_ref(:, 3), 'b--', 'LineWidth', 1);
% plot_statemachine(statemachine, plot_interval)
% box on; ylabel('v_z^l'); 
% axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
% hold off

% figure('Name', 'Transition')
% p1 = plot(p_timestamp, posctrl.log_pc_local_pos2(p_index), 'r--', 'LineWidth', 1);
% hold on
% p2 = plot(att_timestamp, -euler(att_index, 2), 'g-', 'LineWidth', 1);
% p3 = plot(p_timestamp, posctrl_Va(:), 'b--', 'LineWidth', 1);
% plot_statemachine(statemachine, plot_interval)
% title('altitude & pitch')
% legend([p1 p2 p3], 'altitude(m)', '-pitch(deg)', 'Va(m/s)')
% axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
% hold off
end