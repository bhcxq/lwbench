%% LW_noaileron_control_params.m - Controller parameters
% Define the required parameters for controller designer

% Author: wsh.
% Date: 2022/08/24
% Email: wsh_buaa@buaa.edu.cn

%% 模块运行周期
MAX_T = 1/200;
LOG_T = 1/40;
StatesUpdate = MAX_T;
ATTCTRL = MAX_T;
MIXER = MAX_T;
POSCTRL = MAX_T;
NAVIGATOR = MAX_T;
STATEMACHINE = MAX_T;
RCRECEIVE = MAX_T;
MPCRATE = MAX_T;

%% congrol model initial states
% Define the initial outputs of some blocks. Different modules have different run cycles. 
manual_ref_init = struct('euler_ref',single([0 0 0]'),'rates_ref',single([0 0 0]'),'thrust',single(0),'vel_ref',single([0 0 0]'));
auto_ref_init = struct('pos_ref',single([0 0 0]'),'vel_ref',single([0 0 0]'));
offboard_ref_init = struct('pos_ref',single([0 0 0]'),'vel_ref',single([0 0 0]'),'accel_ref',single([0 0 0]'),'att_ref',single([0 0 0]'),'rates_ref',single([0 0 0]'));
pwm_out_init = struct('arm',ControlMode.DISARM, 'pwm',single([ones(4,1)*1000;1500;1500;1000;1000])); % /mixer/pwm_out

%% Model paramters
ModelParam_motorMaxSpeed = ModelParam_motorp1 + ModelParam_motorp2 + ModelParam_motorp3;
ModelParam_Tmax = ModelParam_rotorCt * ModelParam_motorMaxSpeed ^ 2; %单个电机最大拉力
ModelParam_AccelMax = ModelParam_Tmax * 4 / ModelParam_uavMass * 0.95; %螺旋桨所能提供的最大加速度
ModelParam_Tmid = ModelParam_Tmax / 2;
ModelParam_Mmax = ModelParam_rotorCm * ModelParam_motorMaxSpeed ^ 2; %单个螺旋桨产生的最大扭转力矩

%与compute_max_tau结果大体一致
MAX_Mx = ModelParam_Tmax * ModelParam_rotordy * 2; %螺旋桨产生的最大滚转力矩
MAX_My = ModelParam_Tmax * ModelParam_rotordx * 2; %螺旋桨产生的最大俯仰力矩
MAX_Mz = ModelParam_Mmax*2; %螺旋桨产生的最大偏航力矩
MAX_wdotx = MAX_Mx / ModelParam_uavJxx * 0.7; %最大横滚角加速度。x轴两侧螺旋桨满速，另两侧停转，达到最大值。
MAX_wdoty = MAX_My / ModelParam_uavJyy * 0.7; %最大俯仰角加速度。y轴两侧螺旋桨满速，另两侧停转，达到最大值。
MAX_wdotz = MAX_Mz / ModelParam_uavJzz * 0.8; %最大偏航角加速度。两个对角螺旋桨满速，另外两个停转，达到最大值。
MAX_Mxl = abs(cos(LW_ANGLE*pi/180)*MAX_Mx - sin(LW_ANGLE*pi/180)*MAX_Mz);
MAX_Myl = MAX_My;
MAX_Mzl = sin(LW_ANGLE*pi/180)*MAX_Mx + cos(LW_ANGLE*pi/180)*MAX_Mz;
MAX_wdotxl = MAX_Mxl / ModelParam_uavJxx; 
MAX_wdotyl = MAX_Myl / ModelParam_uavJyy; 
MAX_wdotzl = MAX_Mzl  / ModelParam_uavJzz;


%% Sim
if strcmp(ModelConfigure_Type, 'SIM')
    LW_USE_SER = true; %是否使用舵面
    LW_COOR_TURN = false;
    LW_SERVOR_CON = 0;%deg
    LW_AERO_COM = true;
    LW_TEST_EN = 1; %力矩估计补偿
    LW_FEST_EN = 1; %力估计补偿，0：关闭气动补偿；
    LW_FEST_TYPE = single(1);
    LW_F_MAP = 1; % 1：已知气动模型,直接补偿；2：已知气动模型，使用微分平坦求解；3：未知气动模型
    

    LW_AERO_C0 = 0.26;
    LW_AERO_C1 = 1.88;
    LW_AERO_Y0 = 0.3;
    LW_LBCL_D = 0.066;%0.053;%辨识0.066 -0.197
    LW_LBCM_D = -0.197;%-0.24;
    LW_OB_TYPE = single(0);%
    %offboard
    %直线轨迹
    LW_OB_CIRCLE_R = single(10*pi/180);
    LW_OB_CIRCLE_V = single(15);
    LW_OB_CIRCLE_W = single(10);%v=20,w=3;
    %圆形轨迹
    % LW_OB_CIRCLE_R = single(30);%10m/s,30m;15m/s,50m
    % LW_OB_CIRCLE_V = single(10);
    % LW_OB_CIRCLE_W = single(0.03);

    % yaw admittance
    %与PX4中的方法复用参数
    LW_REX_YAW = 0.0;
    LW_DMZ0 = single(-0.023);%零偏补偿配合最小阈值保证悬停时不自转
    LW_DMZ_MIN = single(0.00);
    LW_YAW_KAP = single(2.0);
    LW_YAW_KAD = single(2.0);
    % PX4:
    LW_YAW_KAD = 1; %设置为启用PX4中方法
    LW_YAW_KAP = single(10.0); %roll->yaw rate 比例系数
    LW_DMZ_MIN = single(0.00); %roll死区
    %扰动力矩估计器参数
    LW_TEST_WNXY = single(80.0);
    LW_TEST_WNZ = single(80.0);
    LW_TEST_SIGXY = single(2);
    LW_TEST_SIGZ = single(2);
    LW_TEST_LAMXY = single(1);
    LW_TEST_LAMZ = single(1);
    LW_TEST_WBDT = single(0.05); %扰动力矩估计中角速度滤波系数
    LW_TEST_DTXY = single(0.1); %扰动滤波系数
    LW_TEST_DTZ = single(0.01); %扰动滤波系数
    LW_TEST_TDT = single(0.02); %扰动力矩估计中推力的滤波系数
    %扰动力估计器参数
    LW_FEST_WNXY = single(2.0);
    LW_FEST_WNZ = single(1.0);
    LW_FEST_SIGXY = single(20.0);
    LW_FEST_SIGZ = single(20.0);
    LW_FEST_LAMXY = single(1.0);
    LW_FEST_LAMZ = single(1.0);
    LW_FEST_P = single(1.0);%LW_FEST_EN=1,0.65;LW_FEST_EN=2,0.9
    LW_FEST_DT = single(0.01);%扰动滤波系数
    LW_FEST_TDT = single(0.02);%%扰动力估计中推力的滤波系数
    %Smith Predictor
    LW_TAUXYSP_FZ = single(0);%Hz
    LW_TAUXYSP_TM = single(0.02);%s
    LW_TAUZSP_FZ = single(0);%Hz
    LW_TAUZSP_TM = single(0.02);%s
    LW_ACCSP_FZ = single(0);
    LW_ACCSP_TM = single(0.04);%HIL中这个参数偏大会引起速度控制振荡

    %throttle when UAV hover
    %ModelParam_envGravityAcc/ModelParam_AccelMax
    LW_THR_HOVER = single(ModelParam_envGravityAcc/ModelParam_AccelMax); % hover throttle for stabilized and acro mode
    LW_THR_LOW = single(0.0); %最小推力占悬停时单个螺旋桨推力的百分比
    LW_DTHR = single(0.3); % 油门变化限制
    LW_DSER = single(0.2);% 舵机变化限制
    %mixer
    LW_VA_TMIN = single(6);
    LW_VA_TMAX = single(13);
    LW_MIXER_GAM = single(500.0);
    LW_W_FZ = single(20.0);
    LW_W_TAOX = single(50.0);
    LW_W_TAOY = single(50.0);
    LW_W_TAOZ = single(15);
    LW_W_SER = single(1000.0);%低速时舵面权重系数
    LW_W_SERH = single(10);%高速时舵面权重系数
    LW_SER_LP = single(1);%舵机输出低通滤波截止频率，Hz
    %Attitude limitation
    if LW_ANGLE > 80
        LW_MAN_ROLL_MAX = single(90.0);
        LW_MAN_PITCH_MAX = single(90.0);
    else
        LW_MAN_ROLL_MAX = single(30.0);
        LW_MAN_PITCH_MAX = single(35.0);
    end
    LW_WY_MAX = single(70.0);
    LW_WY_DE_MAX = single(70.0); %# 减速时的最大角速度
    LW_WX_MAX = single(70.0);
    LW_WZ_MAX = single(40.0);

    LW_ACRO_P_MAX = single(720.0);
    LW_ACRO_R_MAX = single(720.0);
    LW_ACRO_Y_MAX = single(200.0);
    %PID parameters
    LW_PITCH_P = single(5.5); 
    LW_WY_P = single(25.0); %硬件在环下需要设置小一点，如20，不然机身会振荡
    LW_WY_I = single(5);
    LW_WY_D = single(0.0);
    LW_WY_N = single(10);
    LW_ROLL_P = single(5.5);
    LW_WX_P = single(25.0);
    LW_WX_I = single(5);
    LW_WX_D = single(0.0);
    LW_WX_N = single(10); %滤波系数，越小，滤波效果越好
    LW_YAW_P = single(3.0);
    LW_WZ_P = single(30.0);
    LW_WZ_I = single(5);
    LW_WZ_D = single(0.000);
    LW_WZ_N = single(10);
    LW_WX_FF = single(1.0);
    LW_WY_FF = single(1.0);
    LW_WZ_FF = single(0.0);

    %Position limitation
    if LW_ANGLE > 80
        LW_TILTMAX_AIR = single(80.0);
    else
        LW_TILTMAX_AIR = single(20.0);%增大会导致高速下俯仰角控制发散
    end
    LW_AUTO_ALTITUDE = single(70.0);
    LW_AUTO_VA = single(10.0);
    LW_AUTO_CIRCLE_R = single(200);
    LW_L1_PERIOD = single(25);
    LW_L1_DAMP = single(0.75);
    LW_L1_KCIRCLE = single(5.0);
    LW_X_VEL_MAX = single(25.0);
    LW_Y_VEL_MAX = single(25.0);
    LW_X_ACCEL_MAX = single(4.0);
    LW_X_ACCEL_MIN = single(-4.0);
    %LW_X_DEACCEL_MAX = single(2.0);
    LW_X_JERK_MAX = single(3.2);
    LW_LAT_CIRCLE = single(1); 
    LW_CIRCLE_YAW = single(10.0); 
    LW_Y_ACCEL_MAX = single(4.0);
    LW_Y_ACCEL_MIN = single(-4.0);
    LW_Y_JERK_MAX = single(3.2);
    LW_Z_VEL_MAX_UP = single(3.0);
    LW_Z_ACCEL_LOW = single(-ModelParam_AccelMax*0.7 + ModelParam_envGravityAcc);
    LW_Z_ACCEL_UP = single(ModelParam_envGravityAcc - 3);
    LW_Z_JERK_MAX = single(3.2);
    LW_VEL_DT = single(0.01); %手动模式下，速度滤波系数
    %PID parameters
    LW_X_FF = single(1.0);
    LW_Y_FF = single(1.0);
    LW_Z_FF = single(1.0);
    LW_X_P = single(1.0);
    LW_X_VEL_P = single(3.0);
    LW_X_VEL_I = single(0.00);
    LW_X_VEL_D = single(0.0000);
    LW_X_VEL_N = single(5.0);
    LW_Y_P = single(1.0);
    LW_Y_VEL_P = single(3.0); %增大，会引起抖动
    LW_Y_VEL_I = single(0.0); %增大，引起超调
    LW_Y_VEL_D = single(0.000);
    LW_Y_VEL_N = single(5.0);
    LW_Z_P = single(1.5); %增大，会引起定点时位置振荡
    LW_Z_VEL_P = single(5.5); %增大会使速度跟踪性能更好，而不会引入不良影响
    LW_Z_VEL_I = single(0.3); %增大，引起超调
    LW_Z_VEL_D = single(0.00); 
    LW_Z_VEL_N = single(5.0);
    LW_ACCX_FF = single(1.0);
    LW_ACCY_FF = single(1.0);
    LW_ACCZ_FF = single(1.0);
    


    % joystick calibration
    RC1_MIN = single(-0.67);
    RC1_MAX = single(0.67);
    RC1_REV = single(1);
    RC2_MIN = single(-0.68);
    RC2_MAX = single(0.67);
    RC2_REV = single(-1);
    RC3_MIN = single(0.16);
    RC3_MAX = single(0.84);
    RC3_REV = single(1);
    RC4_MIN = single(-0.68);
    RC4_MAX = single(0.67);
    RC4_REV = single(1);
    
    %摇杆死区
    LW_MAN_ROLL_DZ = single(0.05);
    LW_MAN_PITCH_DZ = single(0.05);
    LW_MAN_WX_DZ = single(0.01);
    LW_MAN_WY_DZ = single(0.01);
    LW_MAN_WZ_DZ = single(0.01);
    LW_X_VEL_DZ = single(0.01);
    LW_Y_VEL_DZ = single(0.01);
    LW_Z_VEL_DZ = single(0.01);

    %舵面偏转极限
    LW_SERVOR_MAX = single(20);%与LW_noaileron_structural_params中的ModelParam_lDeltamax同表示舵面偏转极限，
                               % 但是ModelParam_lDeltamax只在动力学模型中使用
    LW_SERVOR_MIN= single(-20);
    LW_SERVOL_MAX = single(20);
    LW_SERVOL_MIN = single(-20);
    LW_SERVOR_REV = single(1.0);%舵机方向校准
    LW_SERVOL_REV = single(1.0);%舵机方向校准
    
else
    %% HIL&FLY
    %变量长度不能超过14个字符
    LW_LED = Pixhawk_CSC.Parameter({single(0.0), 'LW_LED'});
    LW_USE_SER = Pixhawk_CSC.Parameter({single(1.0), 'LW_USE_SER'});
    LW_COOR_TURN = Pixhawk_CSC.Parameter({single(0.0), 'LW_COOR_TURN'});
    LW_AERO_COM = Pixhawk_CSC.Parameter({single(1.0), 'LW_AERO_COM'});
    LW_TEST_EN = Pixhawk_CSC.Parameter({single(0.0), 'LW_TEST_EN'});
    LW_FEST_EN = Pixhawk_CSC.Parameter({single(0.0), 'LW_FEST_EN'});
    LW_F_MAP = Pixhawk_CSC.Parameter({single(1.0), 'LW_F_MAP'});
    LW_REX_YAW = Pixhawk_CSC.Parameter({single(0.0), 'LW_REX_YAW'});
    LW_DMZ0 = Pixhawk_CSC.Parameter({single(0.0), 'LW_DMZ0'});
    LW_DMZ_MIN = Pixhawk_CSC.Parameter({single(0.01), 'LW_DMZ_MIN'});
    LW_YAW_KAP = Pixhawk_CSC.Parameter({single(1.0), 'LW_YAW_KAP'});
    LW_YAW_KAD = Pixhawk_CSC.Parameter({single(1.0), 'LW_YAW_KAD'});
    LW_ANGLE = Pixhawk_CSC.Parameter({single(34.0), 'LW_ANGLE'});

    %Throttle amplitude
    %throttle when UAV hover
    LW_MASS = Pixhawk_CSC.Parameter({single(2.10), 'LW_MASS'});
    LW_THR_HOVER = Pixhawk_CSC.Parameter({single(0.3), 'LW_THR_HOVER'});
    LW_THR_LOW = Pixhawk_CSC.Parameter({single(0.0), 'LW_THR_LOW'});
    LW_DTHR = Pixhawk_CSC.Parameter({single(0.3), 'LW_DTHR'});
    LW_DSER = Pixhawk_CSC.Parameter({single(0.2), 'LW_DSER'});
    LW_AERO_C0 = Pixhawk_CSC.Parameter({single(0.1), 'LW_AERO_C0'});
    LW_AERO_C1 = Pixhawk_CSC.Parameter({single(2.4), 'LW_AERO_C1'});
    LW_AERO_Y0 = Pixhawk_CSC.Parameter({single(1.3), 'LW_AERO_Y0'});
    LW_LBCL_D = Pixhawk_CSC.Parameter({single(0.12), 'LW_LBCL_D'});
    LW_LBCM_D = Pixhawk_CSC.Parameter({single(-0.2), 'LW_LBCM_D'});
    LW_OB_TYPE = Pixhawk_CSC.Parameter({single(0.0), 'LW_OB_TYPE'});

    %扰动力估计器参数
    LW_FEST_WNXY = Pixhawk_CSC.Parameter({single(2.0), 'LW_FEST_WNXY'});
    LW_FEST_WNZ = Pixhawk_CSC.Parameter({single(1.0), 'LW_FEST_WNZ'});
    LW_FEST_SIGXY = Pixhawk_CSC.Parameter({single(20.0), 'LW_FEST_SIGXY'});
    LW_FEST_SIGZ = Pixhawk_CSC.Parameter({single(10.0), 'LW_FEST_SIGZ'});
    LW_FEST_LAMXY = Pixhawk_CSC.Parameter({single(1.0), 'LW_FEST_LAMXY'});
    LW_FEST_LAMZ = Pixhawk_CSC.Parameter({single(1.0), 'LW_FEST_LAMZ'});
    LW_FEST_P = Pixhawk_CSC.Parameter({single(0.9), 'LW_FEST_P'});
    LW_FEST_DT = Pixhawk_CSC.Parameter({single(0.01), 'LW_FEST_DT'});
    LW_FEST_TDT = Pixhawk_CSC.Parameter({single(0.02), 'LW_FEST_TDT'});
    %扰动力矩估计器参数
    LW_TEST_WNXY = Pixhawk_CSC.Parameter({single(80.0), 'LW_TEST_WNXY'});
    LW_TEST_WNZ = Pixhawk_CSC.Parameter({single(10.0), 'LW_TEST_WNZ'});
    LW_TEST_SIGXY = Pixhawk_CSC.Parameter({single(10.0), 'LW_TEST_SIGXY'});
    LW_TEST_SIGZ = Pixhawk_CSC.Parameter({single(10.0), 'LW_TEST_SIGZ'});
    LW_TEST_LAMXY = Pixhawk_CSC.Parameter({single(1.0), 'LW_TEST_LAMXY'});
    LW_TEST_LAMZ = Pixhawk_CSC.Parameter({single(1.0), 'LW_TEST_LAMZ'});
    LW_TEST_DTXY = Pixhawk_CSC.Parameter({single(0.01), 'LW_TEST_DTXY'});
    LW_TEST_DTZ = Pixhawk_CSC.Parameter({single(0.01), 'LW_TEST_DTZ'});
    LW_TEST_WBDT = Pixhawk_CSC.Parameter({single(0.05), 'LW_TEST_WBDT'});
    LW_TEST_TDT = Pixhawk_CSC.Parameter({single(0.02), 'LW_TEST_TDT'});



    %mixer
    LW_VA_TMIN = Pixhawk_CSC.Parameter({single(6.0), 'LW_VA_TMIN'});
    LW_VA_TMAX = Pixhawk_CSC.Parameter({single(10.0), 'LW_VA_TMAX'});
    LW_MIXER_GAM = Pixhawk_CSC.Parameter({single(1000.0), 'LW_MIXER_GAM'});
    LW_W_FZ = Pixhawk_CSC.Parameter({single(200.0), 'LW_W_FZ'});
    LW_W_TAOX = Pixhawk_CSC.Parameter({single(10.0), 'LW_W_TAOX'});
    LW_W_TAOY = Pixhawk_CSC.Parameter({single(10.0), 'LW_W_TAOY'});
    LW_W_TAOZ = Pixhawk_CSC.Parameter({single(5.0), 'LW_W_TAOZ'});
    LW_W_SER = Pixhawk_CSC.Parameter({single(500.0), 'LW_W_SER'});
    LW_W_SERH = Pixhawk_CSC.Parameter({single(5.0), 'LW_W_SERH'});
    LW_SER_LP = Pixhawk_CSC.Parameter({single(5.0), 'LW_SER_LP'});

    %Attitude limitation
    LW_MAN_ROLL_MAX = Pixhawk_CSC.Parameter({single(35.0), 'LW_MAN_ROLL_MAX'});
    LW_MAN_PITCH_MAX = Pixhawk_CSC.Parameter({single(35.0), 'LW_MAN_PITCH_MAX'});
    LW_WY_MAX = Pixhawk_CSC.Parameter({single(80.0), 'LW_WY_MAX'});
    LW_WY_DE_MAX = Pixhawk_CSC.Parameter({single(20.0), 'LW_WY_DE_MAX'});
    LW_WX_MAX = Pixhawk_CSC.Parameter({single(80.0), 'LW_WX_MAX'});
    LW_WZ_MAX = Pixhawk_CSC.Parameter({single(80.0), 'LW_WZ_MAX'});
    LW_ACRO_P_MAX = Pixhawk_CSC.Parameter({single(360.0), 'LW_ACRO_P_MAX'});
    LW_ACRO_R_MAX = Pixhawk_CSC.Parameter({single(360.0), 'LW_ACRO_R_MAX'});
    LW_ACRO_Y_MAX = Pixhawk_CSC.Parameter({single(200.0), 'LW_ACRO_Y_MAX'});
    %PID parameters
    LW_PITCH_P = Pixhawk_CSC.Parameter({single(4.5), 'LW_PITCH_P'});
    LW_WY_P = Pixhawk_CSC.Parameter({single(35), 'LW_WY_P'});
    LW_WY_I = Pixhawk_CSC.Parameter({single(5), 'LW_WY_I'});
    LW_WY_D = Pixhawk_CSC.Parameter({single(0.000), 'LW_WY_D'});
    LW_WY_N = Pixhawk_CSC.Parameter({single(10.0), 'LW_WY_N'});
    LW_ROLL_P = Pixhawk_CSC.Parameter({single(5.5), 'LW_ROLL_P'});
    LW_WX_P = Pixhawk_CSC.Parameter({single(20.0), 'LW_WX_P'});
    LW_WX_I = Pixhawk_CSC.Parameter({single(1.0), 'LW_WX_I'});
    LW_WX_D = Pixhawk_CSC.Parameter({single(0.001), 'LW_WX_D'});
    LW_WX_N = Pixhawk_CSC.Parameter({single(100.0), 'LW_WX_N'});
    LW_YAW_P = Pixhawk_CSC.Parameter({single(4.0), 'LW_YAW_P'});
    LW_WZ_P = Pixhawk_CSC.Parameter({single(30.0), 'LW_WZ_P'});
    LW_WZ_I = Pixhawk_CSC.Parameter({single(10), 'LW_WZ_I'});
    LW_WZ_D = Pixhawk_CSC.Parameter({single(0.000), 'LW_WZ_D'});
    LW_WZ_N = Pixhawk_CSC.Parameter({single(100.0), 'LW_WZ_N'});
    LW_WX_FF = Pixhawk_CSC.Parameter({single(1.0), 'LW_WX_FF'});
    LW_WY_FF = Pixhawk_CSC.Parameter({single(1.0), 'LW_WY_FF'});
    LW_WZ_FF = Pixhawk_CSC.Parameter({single(0.7), 'LW_WZ_FF'});
    LW_TAUXYSP_FZ = Pixhawk_CSC.Parameter({single(30), 'LW_TAUXYSP_FZ'});
    LW_TAUXYSP_TM = Pixhawk_CSC.Parameter({single(0.01), 'LW_TAUXYSP_TM'});
    LW_TAUZSP_FZ = Pixhawk_CSC.Parameter({single(5), 'LW_TAUZSP_FZ'});
    LW_TAUZSP_TM = Pixhawk_CSC.Parameter({single(0.01), 'LW_TAUZSP_TM'});
    LW_ACCSP_FZ = Pixhawk_CSC.Parameter({single(5), 'LW_ACCSP_FZ'});
    LW_ACCSP_TM = Pixhawk_CSC.Parameter({single(0.1), 'LW_ACCSP_TM'});
    %Position limitation
    %LW_AUTO_ALTITUDE = Pixhawk_CSC.Parameter({single(10.0), 'LW_AUTO_ALTITUDE'});
    %LW_AUTO_VA = Pixhawk_CSC.Parameter({single(5.0), 'LW_AUTO_VA'});
    %LW_AUTO_CIRCLE_R = Pixhawk_CSC.Parameter({single(15.0), 'LW_AUTO_CIRCLE_R'});%g*tan(phi)=v^2/R
    %LW_L1_PERIOD = Pixhawk_CSC.Parameter({single(25.0), 'LW_L1_PERIOD'});
    %LW_L1_DAMP = Pixhawk_CSC.Parameter({single(0.75), 'LW_L1_DAMP'});
    %LW_L1_KCIRCLE = Pixhawk_CSC.Parameter({single(5.0), 'LW_L1_KCIRCLE'});
    LW_TILTMAX_AIR = Pixhawk_CSC.Parameter({single(30.0), 'LW_TILTMAX_AIR'});
    LW_LAT_CIRCLE = Pixhawk_CSC.Parameter({single(1.0), 'LW_LAT_CIRCLE'});
    %LW_CIRCLE_YAW = Pixhawk_CSC.Parameter({single(10.0), 'LW_CIRCLE_YAW'});
    LW_X_VEL_MAX = Pixhawk_CSC.Parameter({single(20.0), 'LW_X_VEL_MAX'});
    LW_X_ACCEL_MAX = Pixhawk_CSC.Parameter({single(4.0), 'LW_X_ACCEL_MAX'});
    LW_X_ACCEL_MIN = Pixhawk_CSC.Parameter({single(-4.0), 'LW_X_ACCEL_MIN'});
    %LW_X_DEACCEL_MAX = Pixhawk_CSC.Parameter({single(2.0), 'LW_X_DEACCEL_MAX'});
    LW_X_JERK_MAX = Pixhawk_CSC.Parameter({single(10.0), 'LW_X_JERK_MAX'});
    LW_Y_VEL_MAX = Pixhawk_CSC.Parameter({single(20.0), 'LW_Y_VEL_MAX'});
    LW_Y_ACCEL_MAX = Pixhawk_CSC.Parameter({single(4.0), 'LW_Y_ACCEL_MAX'});
    LW_Y_ACCEL_MIN = Pixhawk_CSC.Parameter({single(-4.0), 'LW_Y_ACCEL_MIN'});
    LW_Y_JERK_MAX = Pixhawk_CSC.Parameter({single(10.0), 'LW_Y_JERK_MAX'});
    LW_Z_VEL_MAX_UP = Pixhawk_CSC.Parameter({single(3.0), 'LW_Z_VEL_MAX_UP'});
    LW_Z_ACCEL_LOW = Pixhawk_CSC.Parameter({single(-ModelParam_AccelMax*0.7 + ModelParam_envGravityAcc), 'LW_Z_ACCEL_LOW'});
    LW_Z_ACCEL_UP = Pixhawk_CSC.Parameter({single(ModelParam_envGravityAcc - 3), 'LW_Z_ACCEL_UP'});
    LW_Z_JERK_MAX = Pixhawk_CSC.Parameter({single(10.0), 'LW_Z_JERK_MAX'});
    LW_VEL_DT = Pixhawk_CSC.Parameter({single(0.01), 'LW_VEL_DT'});

    %PID parameters
    LW_X_FF = Pixhawk_CSC.Parameter({single(1.0), 'LW_X_FF'});
    LW_Y_FF = Pixhawk_CSC.Parameter({single(1.0), 'LW_Y_FF'});
    LW_Z_FF = Pixhawk_CSC.Parameter({single(1.0), 'LW_Z_FF'});
    LW_X_P = Pixhawk_CSC.Parameter({single(0.5), 'LW_X_P'});
    LW_X_VEL_P = Pixhawk_CSC.Parameter({single(2.0), 'LW_X_VEL_P'});
    LW_X_VEL_I = Pixhawk_CSC.Parameter({single(0.2), 'LW_X_VEL_I'});
    LW_X_VEL_D = Pixhawk_CSC.Parameter({single(0.1), 'LW_X_VEL_D'});
    LW_X_VEL_N = Pixhawk_CSC.Parameter({single(100.0), 'LW_X_VEL_N'});
    LW_Y_P = Pixhawk_CSC.Parameter({single(0.5), 'LW_Y_P'});
    LW_Y_VEL_P = Pixhawk_CSC.Parameter({single(2.0), 'LW_Y_VEL_P'});
    LW_Y_VEL_I = Pixhawk_CSC.Parameter({single(0.2), 'LW_Y_VEL_I'});
    LW_Y_VEL_D = Pixhawk_CSC.Parameter({single(0.01), 'LW_Y_VEL_D'});
    LW_Y_VEL_N = Pixhawk_CSC.Parameter({single(100.0), 'LW_Y_VEL_N'});
    LW_Z_P = Pixhawk_CSC.Parameter({single(1.5), 'LW_Z_P'});
    LW_Z_VEL_P = Pixhawk_CSC.Parameter({single(5.5), 'LW_Z_VEL_P'});
    LW_Z_VEL_I = Pixhawk_CSC.Parameter({single(0.3), 'LW_Z_VEL_I'});
    LW_Z_VEL_D = Pixhawk_CSC.Parameter({single(0.1), 'LW_Z_VEL_D'});
    LW_Z_VEL_N = Pixhawk_CSC.Parameter({single(100.0), 'LW_Z_VEL_N'});
    LW_ACCX_FF = Pixhawk_CSC.Parameter({single(1.0), 'LW_ACCX_FF'});
    LW_ACCY_FF = Pixhawk_CSC.Parameter({single(1.0), 'LW_ACCY_FF'});
    LW_ACCZ_FF = Pixhawk_CSC.Parameter({single(1.0), 'LW_ACCZ_FF'});
    %offboard
    LW_OB_CIRCLE_R = Pixhawk_CSC.Parameter({single(5.0), 'LW_OB_CIRCLE_R'});
    LW_OB_CIRCLE_V = Pixhawk_CSC.Parameter({single(3.0), 'LW_OB_CIRCLE_V'});
    LW_OB_CIRCLE_W = Pixhawk_CSC.Parameter({single(0.01), 'LW_OB_CIRCLE_W'});

    %RC calibration parameters from QGC
    RC1_MIN = Pixhawk_CSC.Parameter({single(1050), 'RC1_MIN'});
    RC1_MAX = Pixhawk_CSC.Parameter({single(1950), 'RC1_MAX'});
    RC1_REV = Pixhawk_CSC.Parameter({single(1), 'RC1_REV'}); % -1:reverse channel
    RC2_MIN = Pixhawk_CSC.Parameter({single(1050), 'RC2_MIN'});
    RC2_MAX = Pixhawk_CSC.Parameter({single(1950), 'RC2_MAX'});
    RC2_REV = Pixhawk_CSC.Parameter({single(1), 'RC2_REV'}); % -1:reverse channel
    RC3_MIN = Pixhawk_CSC.Parameter({single(1050), 'RC3_MIN'});
    RC3_MAX = Pixhawk_CSC.Parameter({single(1950), 'RC3_MAX'});
    RC3_REV = Pixhawk_CSC.Parameter({single(1), 'RC3_REV'}); % -1:reverse channel
    RC4_MIN = Pixhawk_CSC.Parameter({single(1050), 'RC4_MIN'});
    RC4_MAX = Pixhawk_CSC.Parameter({single(1950), 'RC4_MAX'});
    RC4_REV = Pixhawk_CSC.Parameter({single(1), 'RC4_REV'}); % -1:reverse channel
%     RC5_MIN = Pixhawk_CSC.Parameter({single(1050), 'RC5_MIN'});
%     RC5_MAX = Pixhawk_CSC.Parameter({single(1950), 'RC5_MAX'});
%     RC5_REV = Pixhawk_CSC.Parameter({single(1), 'RC5_REV'}); % -1:reverse channel
%     RC6_MIN = Pixhawk_CSC.Parameter({single(1050), 'RC6_MIN'});
%     RC6_MAX = Pixhawk_CSC.Parameter({single(1950), 'RC6_MAX'});
%     RC6_REV = Pixhawk_CSC.Parameter({single(1), 'RC6_REV'}); % -1:reverse channel
%     RC7_MIN = Pixhawk_CSC.Parameter({single(1050), 'RC7_MIN'});
%     RC7_MAX = Pixhawk_CSC.Parameter({single(1950), 'RC7_MAX'});
%     RC7_REV = Pixhawk_CSC.Parameter({single(1), 'RC7_REV'}); % -1:reverse channel
%     RC8_MIN = Pixhawk_CSC.Parameter({single(1050), 'RC8_MIN'});
%     RC8_MAX = Pixhawk_CSC.Parameter({single(1950), 'RC8_MAX'});
%     RC8_REV = Pixhawk_CSC.Parameter({single(1), 'RC8_REV'}); % -1:reverse channel
    %摇杆死区
    LW_MAN_ROLL_DZ = Pixhawk_CSC.Parameter({single(0.05), 'LW_MAN_ROLL_DZ'});
    LW_MAN_PITCH_DZ = Pixhawk_CSC.Parameter({single(0.05), 'LW_MAN_PITCH_DZ'});
    LW_MAN_WX_DZ = Pixhawk_CSC.Parameter({single(0.01), 'LW_MAN_WX_DZ'});
    LW_MAN_WY_DZ = Pixhawk_CSC.Parameter({single(0.01), 'LW_MAN_WY_DZ'});
    LW_MAN_WZ_DZ = Pixhawk_CSC.Parameter({single(0.01), 'LW_MAN_WZ_DZ'});
    LW_X_VEL_DZ = Pixhawk_CSC.Parameter({single(0.1), 'LW_X_VEL_DZ'});
    LW_Y_VEL_DZ = Pixhawk_CSC.Parameter({single(0.1), 'LW_Y_VEL_DZ'});
    LW_Z_VEL_DZ = Pixhawk_CSC.Parameter({single(0.1), 'LW_Z_VEL_DZ'});


    LW_SERVOR_REV = Pixhawk_CSC.Parameter({single(1.0), 'LW_SERVOR_REV'});
    LW_SERVOL_REV = Pixhawk_CSC.Parameter({single(1.0), 'LW_SERVOL_REV'});
    LW_SERVOR_MAX = Pixhawk_CSC.Parameter({single(20.0), 'LW_SERVOR_MAX'});
    LW_SERVOR_MIN = Pixhawk_CSC.Parameter({single(-20.0), 'LW_SERVOR_MIN'});
    LW_SERVOL_MAX = Pixhawk_CSC.Parameter({single(20.0), 'LW_SERVOL_MAX'});
    LW_SERVOL_MIN = Pixhawk_CSC.Parameter({single(-20.0), 'LW_SERVOL_MIN'});
    LW_SERVOR_CON = Pixhawk_CSC.Parameter({single(0), 'LW_SERVOR_CON'});
end
%%

%角速率积分限幅
Saturation_I_Wx_Up = (MAX_wdotx * 0.4);
Saturation_I_Wx_Low = (-MAX_wdotx * 0.4);
Saturation_I_Wy_Up = (MAX_wdoty * 0.4);
Saturation_I_Wy_Low = (-MAX_wdoty * 0.4);
Saturation_I_Wz_Up = (MAX_wdotz); %自旋时，空气阻力矩较大，需要靠积分补偿
Saturation_I_Wz_Low = (-MAX_wdotz);
%速度控制积分限幅。
%不能超过倾斜最大角度时的加速度
%水平方向没有考虑阻力的影响，因为需要考虑姿态，需要在程序中调整
lw_tiltmax_air= 30;
Saturation_I_ah = single(9.8 * tan(lw_tiltmax_air * pi / 180));
%如果没有气动补偿，需要设置得大一点；反之，可以设置得小一点。
Saturation_I_az = single(3.0);
%不使用气动补偿，假设气动力的范围为[-g,0]
Saturation_I_AZ_LOW = double(-ModelParam_envGravityAcc - Saturation_I_az);
Saturation_I_AZ_UP = double(Saturation_I_az);
%速度低通滤波器参数。
% 位置控制模式下，使用速度计算期望偏航角，这里对滤波器得到的速度进一步做低通滤波，得到更加平滑的期望偏航角。
% 偏航响应本来比较慢，这样应该不会造成偏航响应的延迟问题。
params_posctrl_calculate_yawd_weight = 0.7; % 高通部分参数
