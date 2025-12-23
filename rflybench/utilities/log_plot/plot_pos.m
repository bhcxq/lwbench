function plot_pos(posctrl, attctrl, navigator,statemachine, params, plot_interval)

[timestamp, index] = getIndex(posctrl.timestamp * 1e-6, plot_interval);

posctrl_pos = [posctrl.log_pc_local_pos0(index) posctrl.log_pc_local_pos1(index) posctrl.log_pc_local_pos2(index)];
posctrl_pos_ref = [posctrl.log_pc_local_pos_ref0(index) posctrl.log_pc_local_pos_ref1(index) posctrl.log_pc_local_pos_ref2(index)];
for i = 2 : length(posctrl_pos_ref)
    if posctrl_pos_ref(i, 1) == 0 && posctrl_pos_ref(i, 2) == 0
        posctrl_pos_ref(i, 1 : 2) = posctrl_pos_ref(i - 1, 1 : 2);
    end
end
for i = 2 : length(posctrl_pos)
    if posctrl_pos(i, 1) == 0 && posctrl_pos(i, 2) == 0
        posctrl_pos(i, 1 : 2) = posctrl_pos(i - 1, 1 : 2);
    end
end


posctrl_vel = [posctrl.log_pc_local_pos3(index) posctrl.log_pc_local_pos4(index) posctrl.log_pc_local_pos5(index)];
for i = 1 : length(posctrl_vel)
    posctrl_vel_xy(i) = norm(posctrl_vel(i, 1 : 2));
end

posctrl_vel_ref = [posctrl.log_pc_local_pos_ref3(index) posctrl.log_pc_local_pos_ref4(index) posctrl.log_pc_local_pos_ref5(index)];
log_ac_att_q = [attctrl.log_ac_att_q0 attctrl.log_ac_att_q1 attctrl.log_ac_att_q2 attctrl.log_ac_att_q3];
for i = 1 : length(posctrl_vel_ref)
    posctrl_vel_ref_xy(i) = norm(posctrl_vel_ref(i, 1 : 2));
%     q = log_ac_att_q(find(attctrl.timestamp >= timestamp(i), 1), :);
%     if norm(q) < 0.5
%         posctrl_velb(i, 1 : 3) = posctrl_vel(i, :);
%     else
%         Rbe = quat2yaw(q);
%         posctrl_velb(i, 1 : 3) = Rbe * posctrl_vel(i, :)';
%     end
end
[n_timestamp, n_index] = getIndex(navigator.timestamp * 1e-6, plot_interval);
ob_vel_ref = [navigator.offboard_ref3(n_index) navigator.offboard_ref4(n_index) navigator.offboard_ref5(n_index)];

% dpos = diff(posctrl_pos)./diff(timestamp);
% firf = designfilt('lowpassfir','FilterOrder',150, 'CutoffFrequency',5,'SampleRate',250);
% dpos_filted = filtfilt(firf,dpos);
% figure
% tiledlayout(3,1)
% nexttile
% plot(timestamp(1:end-1),dpos(:,1))
% hold on
% plot(timestamp(1:end-1),dpos_filted(:,1))
% plot(timestamp,posctrl_vel(:,1))
% nexttile
% plot(timestamp(1:end-1),dpos(:,2))
% hold on
% plot(timestamp(1:end-1),dpos_filted(:,2))
% plot(timestamp,posctrl_vel(:,2))
% nexttile
% plot(timestamp(1:end-1),dpos(:,3))
% hold on
% plot(timestamp(1:end-1),dpos_filted(:,3))
% plot(timestamp,posctrl_vel(:,3))

% figure('Name', 'pos')
% plot3(posctrl_pos(:, 1), posctrl_pos(:, 2), -posctrl_pos(:,3), 'r-', 'LineWidth', 2)
% hold on
% plot3(posctrl_pos_ref(:, 1), posctrl_pos_ref(:, 2), -posctrl_pos_ref(:,3), 'g--', 'LineWidth', 1)
% legend('feedback', 'ref', 'Location', 'northeast')
% hold off
% axis equal
% xlabel('x(m)'); ylabel('y(m)'); zlabel('altitude(m)');

% figure('Name','Velocity feedback')
% tiledlayout(3,1)
% nexttile
% plot(timestamp,(posctrl_pos_ref(:,1) - posctrl_pos(:,1))*params.LW_X_P)
% nexttile
% plot(timestamp,(posctrl_pos_ref(:,2) - posctrl_pos(:,2))*params.LW_Y_P)
% nexttile
% plot(timestamp,(posctrl_pos_ref(:,3) - posctrl_pos(:,3))*params.LW_Z_P)

% figure('Name','Pos')
% tiledlayout(3,1)
% nexttile
% plot(timestamp,posctrl_pos(:,1))
% nexttile
% plot(timestamp,posctrl_pos(:,2))
% nexttile
% plot(timestamp,posctrl_pos(:,3))

% figure('Name','Pos ref')
% tiledlayout(3,1)
% nexttile
% plot(timestamp,posctrl_pos_ref(:,1))
% nexttile
% plot(timestamp,posctrl_pos_ref(:,2))
% nexttile
% plot(timestamp,posctrl_pos_ref(:,3))


figure('Name', 'pos')
tiledlayout(5, 2, 'TileSpacing', 'None')
nexttile(1, [2, 1])
plot3(posctrl_pos(:, 1), posctrl_pos(:, 2), -posctrl_pos(:,3), 'r-', 'LineWidth', 1)
hold on
plot3(posctrl_pos_ref(:, 1), posctrl_pos_ref(:, 2), -posctrl_pos_ref(:,3), 'g--', 'LineWidth', 1)
legend('feedback', 'ref', 'Location', 'northeast')
hold off
xlabel('x(m)'); ylabel('y(m)'); zlabel('altitude(m)');

ax5 = nexttile(5);
plot(timestamp, posctrl_pos(:, 1), 'r--', 'LineWidth', 1);
hold on
plot(timestamp, posctrl_pos_ref(:, 1), 'g-', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('x(m)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_X_P')
    title(ax5,['K_p = ',num2str(params.LW_X_P)])
end
hold off
ax7 = nexttile(7);
plot(timestamp, posctrl_pos(:, 2), 'r--', 'LineWidth', 1)
hold on
plot(timestamp, posctrl_pos_ref(:, 2), 'g-', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
box on; ylabel('y(m)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_Y_P')
    title(ax7,['K_p = ',num2str(params.LW_Y_P)])
end
hold off
ax9 = nexttile(9);
plot(timestamp, posctrl_pos(:, 3), 'r--', 'LineWidth', 1)
hold on
plot(timestamp, posctrl_pos_ref(:, 3), 'g-', 'LineWidth', 1)
plot_statemachine(statemachine, plot_interval)
box on; xlabel('t(s)'); ylabel('z(m)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_Z_P')
    title(ax9,['K_p = ',num2str(params.LW_Z_P)])
end
hold off

nexttile(2, [2, 1])
p1 = plot(timestamp, posctrl_vel_xy(:), 'r--', 'LineWidth', 1);
hold on
p2 = plot(timestamp, posctrl_vel_ref_xy(:), 'g-', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_x_y'); legend([p1 p2], 'feedback', 'ref')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ax6=nexttile(6);
plot(timestamp, posctrl_vel(:, 1), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, posctrl_vel_ref(:,1),'g--','LineWidth',1)
plot(n_timestamp, ob_vel_ref(:,1),'b--','LineWidth',1)

plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_x(m/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_X_VEL_P')
    title(ax6,['K_p = ',num2str(params.LW_X_VEL_P),',K_i = ',num2str(params.LW_X_VEL_I),',K_d = ',num2str(params.LW_X_VEL_D)])
end
hold off
ax8=nexttile(8);
plot(timestamp, posctrl_vel(:, 2), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, posctrl_vel_ref(:,2),'g--','LineWidth',1)
plot(n_timestamp, ob_vel_ref(:,2),'b--','LineWidth',1)
plot_statemachine(statemachine, plot_interval)
box on; ylabel('v_y(m/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_Y_VEL_P')
    title(ax8,['K_p = ',num2str(params.LW_Y_VEL_P),',K_i = ',num2str(params.LW_Y_VEL_I),',K_d = ',num2str(params.LW_Y_VEL_D)])
end
hold off
ax10=nexttile(10);
plot(timestamp, posctrl_vel(:, 3), 'r-', 'LineWidth', 1)
hold on
plot(timestamp, posctrl_vel_ref(:,3),'g--','LineWidth',1)
plot(n_timestamp, ob_vel_ref(:,3),'b--','LineWidth',1)
plot_statemachine(statemachine, plot_interval)
box on; xlabel('t(s)'); ylabel('v_z(m/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_Z_VEL_P')
    title(ax10,['K_p = ',num2str(params.LW_Z_VEL_P),',K_i = ',num2str(params.LW_Z_VEL_I),',K_d = ',num2str(params.LW_Z_VEL_D)])
end
hold off

offboard_interval.start = statemachine.timestamp(find(statemachine.flight_mode > 1,1));
offboard_interval.end = statemachine.timestamp(find(statemachine.flight_mode > 1,1,'last'));
offboard_interval.start = max([statemachine.timestamp(find(statemachine.flight_mode > 1,1))*1e-6,plot_interval.startTime]);
offboard_interval.end = min([statemachine.timestamp(find(statemachine.flight_mode > 1,1,'last'))*1e-6,plot_interval.endTime]);

%offboard_interval.end = 240*1e6;
if ~(isempty(offboard_interval.start) || isempty(offboard_interval.end))
    figure('Name','Pos Error')
    ob_index = find(timestamp>=offboard_interval.start,1):find(timestamp<=offboard_interval.end,1,'last');
    posctrl_pos_ob = posctrl_pos(ob_index,:);
    posctrl_pos_ref_ob = posctrl_pos_ref(ob_index,:);
    tiledlayout(3, 1)
    nexttile
    plot(timestamp(ob_index),vecnorm(posctrl_pos_ob(:, 1:2) - posctrl_pos_ref_ob(:,1:2),2,2),'LineWidth',1);
    if isfield(params,'LW_Z_VEL_P')
        title(['Cd0=',num2str(params.LW_AERO_C0),',Cla=',num2str(params.LW_AERO_C1),',Cy0=',num2str(params.LW_AERO_Y0)]);
    end
 
    subtitle(['Mean Error:',num2str(mean(vecnorm(posctrl_pos_ob(:, 1:2) - posctrl_pos_ref_ob(:,1:2),2,2)))])
    ylabel('Hor Error')
    nexttile
    plot(timestamp(ob_index),vecnorm(posctrl_pos_ob(:, 3) - posctrl_pos_ref_ob(:,3),2,2),'LineWidth',1);
    subtitle(['Mean Error:',num2str(mean(vecnorm(posctrl_pos_ob(:, 3) - posctrl_pos_ref_ob(:,3),2,2)))])
    ylabel('Ver Error')
    nexttile
    plot(timestamp(ob_index),vecnorm(posctrl_pos_ob(:, 1:3) - posctrl_pos_ref_ob(:,1:3),2,2),'LineWidth',1);
    subtitle(['Mean Error:',num2str(mean(vecnorm(posctrl_pos_ob(:, 1:3) - posctrl_pos_ref_ob(:,1:3),2,2)))])
    ylabel('Pos Error')
end
end