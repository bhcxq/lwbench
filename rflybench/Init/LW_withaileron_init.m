%% lifting_wing_noaileron_init.m - Model parameters
% Config and define the required parameters for model

% Author: wsh.
% Date: 2023/09/26
% Email: wsh_buaa@buaa.edu.cn

clear all
% Open a project
[init_path, init_name] = fileparts(mfilename('fullpath'));
cd(init_path);
proj_loaded = ~isempty(matlab.project.rootProject);
if proj_loaded
    proj = currentProject;
else
    proj = openProject("..\");
end
cd(proj.RootFolder)

lwEnumDefinition;
ModelConfigure_VehicleType = VehicleType.LIFTING_WING;
ModelConfigure_FirmwareVersion = 'V1.13.3';

%% run simulink model
Controller_Switch = 0;
ModelConfigure_Type = 'HIL'; % SIM, HIL
SIM_TIME = 1000; % 仿真时间
SEND_TO_UNREAL = true; % 启用之后，可以在UNREAL中观察飞行器的状态，
ENABLE_PACING = false; % 启用之后，Simulink会按照实际时间运行，仿真时间设置为 SIM_TIME
USE_MOTOR = int8(2); % 1:t-motor MN3510 kv360; 2: t-motor MN3510 kv700
                     % 3: RS2205-2300KV；4：RS2205-2600KV
AERO_COEFFICIENT = int8(1); % 1: post-stall; 2: pre-stall; 3: mix
                            %只影响仿真模型中气动参数，不影响位置控制中的
LW_ANGLE = 34; %翼面安装角,deg
DELETE_PARAMS_XML = true; % 删除build文件夹下的参数文件，新增自定义参数时设置为true
env_params;
LW_withaileron_structural_params;%LW_structural_params_1;
LW_withaileron_control_params;
ModelConfigure_Name = 'LW_ctrl_241029_1';
%getUAVMission
loadBusObject
VSS_6DOF = 0; %0: use 6dof model built by wsh; 1: use 6dof model built by MathWorks
VSS_ATT_CTRL = 2; % 0:euler PID; 1: euler ADRC; 2: DCM PID; 3: DCM ADRC
VSS_FORCE_ALLOCATION = 1; %0: propotion;1: nonlinear; 2: optimization
VSS_POS_LON_CTRL = 0; % 0: PID;1:TECS
VSS_POS_LAT_CTRL = 1; %0: PID;1:path following
LW_withaileron_modelcfg;

