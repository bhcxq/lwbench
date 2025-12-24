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
ModelConfigure_Type = 'SIM'; % SIM, HIL
SIM_TIME = 1000;
SEND_TO_UNREAL = true; 
ENABLE_PACING = false; 
USE_MOTOR = int8(2); 
AERO_COEFFICIENT = int8(1); 
LW_ANGLE = 34; 
DELETE_PARAMS_XML = true; 
env_params;
LW_withaileron_structural_params;%LW_structural_params_1;
LW_withaileron_control_params;
ModelConfigure_Name = 'LW_ctrl_241029_1';
loadBusObject
VSS_6DOF = 1;
LW_withaileron_modelcfg;

