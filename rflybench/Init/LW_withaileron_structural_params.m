%% LW_noaileron_structural_params.m - Model parameters
% Define the required parameters for model

% Author: wsh.
% Date: 2023/04/09
% Email: wsh_buaa@buaa.edu.cn

%% Initial condition
ModelInit_PosE = [0, 0, 0]'; %Initial position
ModelInit_VelB = [0, 0, 0]'; %Initial velocity
ModelInit_AngEuler = [0, 0, 0.0]'; %Initial Euler angle
ModelInit_RateB = [0, 0, 0]'; %Initial angular velocity
ModelInit_Rads = 0; %Initial motor speed(rad/s)
ModelInit_servoRads = 0; %Init servo angle(rad)

ModelParam_lDeltamax = 20 * pi / 180; % 副翼偏角极限，左侧向下为正
ModelParam_lDeltamin = -20 * pi / 180; % 副翼偏角极限
ModelParam_rDeltamin = -20 * pi / 180; % 副翼偏角极限
ModelParam_rDeltamax = 20 * pi / 180; % 副翼偏角极限，右侧向上为正
ModelParam_DeltaRatemax = 8.7266; % 副翼最大偏转速度 0.12s/60°= 8.7266 rad/s
ModelParam_rotorEta = 0; % 电机安装角
ModelParam_rotordx = 0.20; % 旋翼力臂
ModelParam_rotordy = 0.20; % 旋翼力臂
ModelParam_LBb = 0.9; % 展长
ModelParam_LBc = 0.2; % 平均气动弦
ModelParam_LBS = 0.16; % 机翼面积

ModelParam_uavJxx = 0.05;
ModelParam_uavJyy = 0.05;
ModelParam_uavJzz = 0.07;
ModelParam_uavJ = [ModelParam_uavJxx, 0, 0; ...
    0, ModelParam_uavJyy, 0; ...
    0, 0, ModelParam_uavJzz];

LW_MASS = 2;
ModelParam_uavMass = LW_MASS;


%% propulsion system parameter
ModelParam_servoT = 0.02; %1/(Ts+1)
ModelParam_servoCr = pi / 6; %(-1,1)->(-pi/2,pi/2)
ModelParam_efficiency = 1.0;

% T-motor MN3510 KV700 4s APC12*8
ModelParam_motorp1 = -387.3;
ModelParam_motorp2 = 1269;
ModelParam_motorp3 = -32.5;

% T-motor MN3510 KV700 4s
ModelParam_motorUp1 = -1.035;
ModelParam_motorUp2 = 67;
ModelParam_motorUp3 = -12.22;

ModelParam_motorT = 0.002; %Motor inertia time constant(s)
ModelParam_motorJm = 8.8493e-06; %Moment of inertia of motor rotor + propeller(kg.m^2)
ModelParam_motorMinThr = 0.0; %Motor throttle dead zone(kg.m^2)
USE_PROPELLER_MODEL1 = true; % true

%仿真模型参数
%T=kT0 + kTvarpi**w + kTV*v + kTvarpi2*w^2 + kTvarpiV*w*V + kTV2*V^2
ModelParam_propellerkT0 = 0;
ModelParam_propellerkTvarpi = 0;
ModelParam_propellerkTV = 0;
ModelParam_propellerkTvarpi2 = 0.008977;
ModelParam_propellerkTvarpiV = 0.007314;
ModelParam_propellerkTV2 = -0.01619;
ModelParam_rotorCt = 2.2e-05; % T-motor MN3510 KV700 4s APC12*6
%M=kM0 + kMvarpi**w + kMV*v + kMvarpi2*w^2 + kMvarpiV*w*V + kMV2*V^2
ModelParam_propellerkM0 = 0;
ModelParam_propellerkMvarpi = 0;
ModelParam_propellerkMV = 0;
ModelParam_propellerkMvarpi2 = 0.0003188;
ModelParam_propellerkMvarpiV = 0.0003198;
ModelParam_propellerkMV2 = -0.0005944;
ModelParam_rotorCm = 5.2e-07;
ModelParam_rotorkm_f = ModelParam_rotorCm / ModelParam_rotorCt;

%% Aerodynamic parameters
USE_AeroCoefficient = true; %设置为false之后，"Environment Models"中的qbar被置为0,气动力失效
USE_ConstCoefficient = false; %设置为true之后，使用常值气动系数

%constant parameters
ModelParam_LBCd = 0.1347; %阻力系数
ModelParam_LBCY = -4.152e-04; %
ModelParam_LBCL = 4.4851; %升力系数
ModelParam_LBCl = 0; %-3.364e-05; %滚转力矩系数
ModelParam_LBCm = -0.1195; %俯仰力矩系数
ModelParam_LBCn_d = -0; %偏航舵操纵导数
ModelParam_uavCd = [0.055 0.055 0.055]'; %Damping coefficient(N/(m/s)^2)
ModelParam_uavCCm = [0.0035 0.0039 0.0034]'; %Damping moment coefficient vector(N/(m/s)^2)

% Aerodynamic modeling of the Skywalker X8 Fixed-Wing Unmanned Aerial Vehicle
ModelParam_LBCYB = -0.224;
ModelParam_LBClB = -0.05; %有风的情况下，加入容易导致控制不稳定
ModelParam_LBClp = -0.4;
ModelParam_LBCnr = -0.01;
ModelParam_LBCmq = -1;
ModelParam_LBCl_d = 0.1; %副翼操纵导数
ModelParam_LBCm_d = -0.2; %升降舵操纵导数

ModelParam_LBCn = 0;
ModelParam_LBCY0 = 0;
ModelParam_LBCl0 = 0;
ModelParam_LBCn0 = 0;
ModelParam_LBCnB = 0.03;

ModelParam_pu_alpha0 = 12 * pi / 180; %失速角度
ModelParam_pu_c0 = 0.267; % 最小阻力
ModelParam_pu_c1 = 1.88; %失速后最高升力，阻力
AR = ModelParam_LBb ^ 2 / ModelParam_LBS;
ModelParam_pu_cl0 = 0.3041*0.6; % 0迎角升力
ModelParam_pu_c2 = 5.736*0.7; %小迎角升力变化率
ModelParam_pu_c3 = 0.8; % 小迎角阻力变化率
ModelParam_pu_kL = 7.8;
ModelParam_pu_kD = 20; %升力、阻力切换
%Cm参数
load F18_Cm.mat
tm = Cm_y(108 : 111);
Cm_y(108 : 111) = Cm_y(94 : 97);
Cm_y(94 : 97) = tm;
Cm_y([92 : 93 96 98 112 113]) = [];
Cm_alpha([92 : 93 96 98 112 113]) = [];
alpha = linspace(-pi, pi, 1000);
ppCm = csape(Cm_alpha * pi / 180, Cm_y);
Cm = ppval(ppCm, alpha);
Cm(1 : 35) = smoothdata(Cm(1 : 35), 'loess', 'SmoothingFactor', 0.8);
Cm(35 : 454) = smoothdata(Cm(35 : 454), 'loess', 'SmoothingFactor', 0.5);
Cm(444 : 555) = smoothdata(Cm(444 : 555), 'loess', 'SmoothingFactor', 0.5);
Cm(545 : 980) = smoothdata(Cm(545 : 980), 'loess', 'SmoothingFactor', 0.5);
Cm(970 : 1000) = smoothdata(Cm(970 : 1000), 'loess', 'SmoothingFactor', 0.8);
Cm(35 : 974) = smoothdata(Cm(35 : 974), 'loess', 'SmoothingFactor', 0.01);
ppCm = csape(alpha, Cm);
[ModelParam_pu_breaks, ModelParam_pu_coefs, ModelParam_pu_L, ModelParam_pu_order, ModelParam_pu_dim] = unmkpp(ppCm);
%Cm = ppval(ppCm, alpha);
Cm_line = Cm(454 : 545);
Cm_noline = Cm(545 : end);
ft = fittype( 'poly1');
opts.Display = 'Off'; opts.Robust = 'On';
opts.TolFun = 1e-10; opt.TolX = 1e-10;
[fitresult_Cm_line, gof_Cm_line] = fit( alpha(454 : 545)', Cm_line', ft);
ModelParam_pu_Cm_line = [fitresult_Cm_line.p1 fitresult_Cm_line.p2];
ft = fittype( 'poly2');
[fitresult_Cm_noline, gof_Cm_noline] = fit( alpha(545 : end)', Cm_noline', ft );
ModelParam_pu_Cm_noline = [fitresult_Cm_noline.p1 fitresult_Cm_noline.p2 fitresult_Cm_noline.p3];
syms x
func1 = @(x)fitresult_Cm_noline.p1 * x ^ 2 + fitresult_Cm_noline.p2 * x + fitresult_Cm_noline.p3 - (fitresult_Cm_line.p1 * x + fitresult_Cm_line.p2);
x1 = solve(func1, x);
ModelParam_pu_Cm_x = double(x1(1)); % 0.2905
