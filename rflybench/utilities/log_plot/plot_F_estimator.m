function plot_F_estimator(posctrl,statemachine, params, plot_interval)

[timestamp, index] = getIndex(posctrl.timestamp * 1e-6, plot_interval);

posctrl_pos = [posctrl.log_pc_local_pos0(index) posctrl.log_pc_local_pos1(index) posctrl.log_pc_local_pos2(index)];
for i = 2 : length(posctrl_pos)
    if posctrl_pos(i, 1) == 0 && posctrl_pos(i, 2) == 0
        posctrl_pos(i, 1 : 2) = posctrl_pos(i - 1, 1 : 2);
    end
end
posctrl_vel = [posctrl.log_pc_local_pos3(index) posctrl.log_pc_local_pos4(index) posctrl.log_pc_local_pos5(index)];
log_pc_ae_hat = [posctrl.log_pc_ae_hat0(index),posctrl.log_pc_ae_hat1(index),posctrl.log_pc_ae_hat2(index)];
log_pc_pos_est = [posctrl.log_pc_pos_est0(index),posctrl.log_pc_pos_est1(index),posctrl.log_pc_pos_est2(index)];
log_pc_vel_est = [posctrl.log_pc_vel_est0(index),posctrl.log_pc_vel_est1(index),posctrl.log_pc_vel_est2(index)];


figure('Name','Force disturbance')
tiledlayout(3, 1, 'TileSpacing', 'Compact')
ax1=nexttile;
plot(timestamp, log_pc_ae_hat(:, 1), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('ae_x(m/s^2)');
nexttile
plot(timestamp, log_pc_ae_hat(:, 2), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('ae_y(m/s^2)');
nexttile
plot(timestamp, log_pc_ae_hat(:, 3), 'k-', 'LineWidth', 1);
hold on
plot_statemachine(statemachine, plot_interval)
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ylabel('ae_z(m/s^2)');xlabel('t(s)');
if isfield(params,'LW_FEST_DT')
    title(ax1,['DT=',num2str(params.LW_FEST_DT)])
end

figure('Name','Estimated pos')
tiledlayout(3, 2, 'TileSpacing', 'Compact')
ax1 = nexttile;
p1 = plot(timestamp, log_pc_pos_est(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(timestamp, posctrl_pos(:, 1), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('p_x(m)'); legend([p1 p2], 'CFO', 'EKF2')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_FEST_WNXY')
    title(ax1,['EN=',num2str(params.LW_FEST_EN),...
        ',Wn=[',num2str(params.LW_FEST_WNXY),',',num2str(params.LW_FEST_WNXY),',',num2str(params.LW_FEST_WNZ),...
        '],Sigma=[',num2str(params.LW_FEST_SIGXY),',',num2str(params.LW_FEST_SIGXY),',',num2str(params.LW_FEST_SIGZ),...
        '],Lamda=[',num2str(params.LW_FEST_LAMXY),',',num2str(params.LW_FEST_LAMXY),',',num2str(params.LW_FEST_LAMZ),']'])
end
hold off
ax2 = nexttile;
p1 = plot(timestamp, log_pc_vel_est(:, 1), 'r-', 'LineWidth', 1);
hold on
p2 = plot(timestamp, posctrl_vel(:, 1), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('v_x(m/s)'); 
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_F_MAP')
    title(ax2,['F_{MAP}=',num2str(params.LW_F_MAP),',P=',num2str(params.LW_FEST_P)])
end
hold off
ax3 = nexttile;
p1 = plot(timestamp, log_pc_pos_est(:, 2), 'r-', 'LineWidth', 1);
hold on
p2 = plot(timestamp, posctrl_pos(:, 2), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('p_y(m)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ax4 = nexttile;
plot(timestamp, log_pc_vel_est(:, 2), 'r-', 'LineWidth', 1);
hold on
plot(timestamp, posctrl_vel(:, 2), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('v_y(m/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ax5 = nexttile;
p1 = plot(timestamp, log_pc_pos_est(:, 3), 'r-', 'LineWidth', 1);
hold on
p2 = plot(timestamp, posctrl_pos(:, 3), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('p_z(m)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off
ax6 = nexttile;
plot(timestamp, log_pc_vel_est(:, 3), 'r-', 'LineWidth', 1);
hold on
plot(timestamp, posctrl_vel(:, 3), 'g--', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
box on
ylabel('v_z(m/s)');
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

end