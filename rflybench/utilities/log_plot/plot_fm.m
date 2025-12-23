function plot_fm(attctrl, mixer, statemachine, params,plot_interval)

%% control parameters
if isfield(params,'LW_USE_SER')
    LW_USE_SER = params.LW_USE_SER;
else
    LW_USE_SER = false;
end

if isfield(params,'LW_AERO_COM')
    LW_AERO_COM = params.LW_AERO_COM;
else
    LW_AERO_COM = false;
end

if isfield(params,'LW_LBCL_D')
    LW_LBCL_D = params.LW_LBCL_D;
else
    LW_LBCL_D = false;
end

if isfield(params,'LW_LBCM_D')
    LW_LBCM_D = params.LW_LBCM_D;
else
    LW_LBCM_D = false;
end
kappa = params.LW_ANGLE* pi / 180;

%% get model parameters from workspace
eta = evalin('base', 'ModelParam_rotorEta');
dx = evalin('base', 'ModelParam_rotordx');
dy = evalin('base', 'ModelParam_rotordy');
LBS = evalin('base', 'ModelParam_LBS');
LBb = evalin('base', 'ModelParam_LBb');
LBc = evalin('base', 'ModelParam_LBc');
Rho = evalin('base', 'ModelParam_LBRho');
rotorCm = evalin('base', 'ModelParam_rotorCm');
rotorCt = evalin('base', 'ModelParam_rotorCt');

%% 
[mixer_timestamp, index] = getIndex(mixer.timestamp * 1e-6, plot_interval);
T1 = mixer.log_m_t_limit0(index);
T2 = mixer.log_m_t_limit1(index);
T3 = mixer.log_m_t_limit2(index);
T4 = mixer.log_m_t_limit3(index);
T5 = mixer.log_m_t_limit4(index);
T6 = mixer.log_m_t_limit5(index);
Va = mixer.log_m_va(index);
[attctrl_timestamp, index] = getIndex(attctrl.timestamp * 1e-6, plot_interval);
thrust_ref = attctrl.log_ac_thrust_ref(index);
torque_ref = [attctrl.log_ac_torque_ref0(index)'; attctrl.log_ac_torque_ref1(index)'; attctrl.log_ac_torque_ref2(index)'];
log_ac_att_q = [attctrl.log_ac_att_q0 attctrl.log_ac_att_q1 attctrl.log_ac_att_q2 attctrl.log_ac_att_q3];

%% 
for ii = 1 : length(Va)
    %计算气动参数
    q = log_ac_att_q(find(attctrl.timestamp * 1e-6 <= mixer_timestamp(ii), 1,'last'), :);
    if norm(q) < 0.1
        euler = [0, 0, 0];
    else
        euler = my_quat2eul(q');
    end
    theta = euler(2);
    alpha = theta + kappa;
    beta = 0;
    C_l = 0 + -0.0849 * beta;
    ssCm = [2.341, 0.2294, -3.081, 0.1121, 8.391, -0.2862];
    Cm_linear = [3.587, 0.7512];
    if alpha > -0.237232
        a1 = ssCm(1); b1 = ssCm(2); c1 = ssCm(3);
        a2 = ssCm(4); b2 = ssCm(5); c2 = ssCm(6);
        C_m = a1 * sin(b1 * alpha + c1) + a2 * sin(b2 * alpha + c2);
    else
        p1 = Cm_linear(1); p2 = Cm_linear(2);
        C_m = p1 * alpha + p2;
    end
    C_n = 0 + 0 * beta;
    
    [B, b] = control_allocation_matrix(Va(ii), LW_AERO_COM, LW_USE_SER, ...
    eta, LBb, LBc, LBS, kappa, Rho, dx, dy, C_l, C_m, C_n, LW_LBCL_D, LW_LBCM_D, ...
    rotorCm, rotorCt);
    f_tao(ii, :) = B * [T1(ii); T2(ii); T3(ii); T4(ii); T5(ii); T6(ii)] + b*0;
end

%% plot
figure('Name', 'thrust&torque')
ax1 = subplot(2, 2, 1);
p1 = plot(attctrl_timestamp, -thrust_ref, 'g--', 'LineWidth', 1);
hold on
p2 = plot(mixer_timestamp, -f_tao(:,1), 'r-', 'LineWidth', 1);
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('thrust')
legend([p1, p2], 'thrust_r_e_f', 'thrust')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_W_FZ')
    title(ax1,['W_f=',num2str(params.LW_W_FZ)])
end
ax2=subplot(2, 2, 2);
p1 = plot(attctrl_timestamp, torque_ref(1, :), mixer_timestamp, f_tao(:, 2));
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('torquex')
legend(p1, 'ref', 'actual')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_W_TAOX')
    title(ax2,['\tau_x = ',num2str(params.LW_W_TAOX)])
end
ax3=subplot(2, 2, 3);
p1 = plot(attctrl_timestamp, torque_ref(2, :), mixer_timestamp, f_tao(:, 3));
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('torquey')
legend(p1, 'ref', 'actual')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_W_TAOY')
    title(ax3,['\tau_y = ',num2str(params.LW_W_TAOY)])
end
ax4 = subplot(2, 2, 4);
p1 = plot(attctrl_timestamp, torque_ref(3, :), mixer_timestamp, f_tao(:, 4));
hold on
plot_statemachine(statemachine, plot_interval)
hold off
ylabel('torquez')
legend(p1, 'ref', 'actual')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
if isfield(params,'LW_W_TAOZ')
    title(ax4,['\tau_z = ',num2str(params.LW_W_TAOZ)])
end

end

