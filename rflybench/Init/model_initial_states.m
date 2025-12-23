%% model_initial_states.m - Model initial states definitions
% Define the initial outputs of some blocks. Different modules have different run cycles. 

% Author: wsh.
% Email: wsh_buaa@buaa.edu.cn


manual_ref_init = struct('euler_ref',single([0 0 0]'),'rates_ref',single([0 0 0]'),'thrust',single(0),'vel_ref',single([0 0 0]'));
auto_ref_init = struct('pos_ref',single([0 0 0]'),'vel_ref',single([0 0 0]'));
offboard_ref_init = struct('pos_ref',single([0 0 0]'),'vel_ref',single([0 0 0]'),'accel_ref',single([0 0 0]'),'att_ref',single([0 0 0]'),'rates_ref',single([0 0 0]'));
pwm_out_init = struct('arm',ControlMode.DISARM, 'pwm',single([ones(4,1)*1000;1500;1500;1000;1000])); % /mixer/pwm_out

%UnderspecifiedInitializationDetection