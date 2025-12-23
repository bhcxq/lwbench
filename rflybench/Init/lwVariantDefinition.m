%% lwVariantDefinition.m - Variants definiton
% This script initializes the variant objects for the lifting-wing quadcopter model.

% Author: wsh.
% Email: wsh_buaa@buaa.edu.cn

if strcmp(ModelConfigure_Type, 'SIM')
    VSS_PROCEDURE = 0;       % 0: sim, 1: HIL, 2: FLY, 3: HIL-FPGA
elseif strcmp(ModelConfigure_Type, 'HIL')
    VSS_PROCEDURE = 1;
elseif strcmp(ModelConfigure_Type, 'FLY')
    VSS_PROCEDURE = 2;
else
    VSS_PROCEDURE = 3;
end
if strcmp(ModelConfigure_FirmwareVersion, 'V1.8.2')
    VSS_FIRMWARE_VERSION = 0;
elseif strcmp(ModelConfigure_FirmwareVersion, 'V1.12.3')
    VSS_FIRMWARE_VERSION = 1;
elseif strcmp(ModelConfigure_FirmwareVersion, 'V1.13.3')
    VSS_FIRMWARE_VERSION = 2;
else
    error('Firmware version error! It is not V1.8.2 V1.12.3 or V1.13.3'); 
end

%procedure type
VSS_PROCEDURE_SIM = Simulink.Variant('VSS_PROCEDURE==0');
VSS_PROCEDURE_HIL = Simulink.Variant('VSS_PROCEDURE==1');
VSS_PROCEDURE_HIL_V1_8 = Simulink.Variant('VSS_PROCEDURE==1 && VSS_FIRMWARE_VERSION ==0');
VSS_PROCEDURE_HIL_V1_12 = Simulink.Variant('VSS_PROCEDURE==1 && VSS_FIRMWARE_VERSION ==1');
VSS_PROCEDURE_HIL_V1_13 = Simulink.Variant('VSS_PROCEDURE==1 && VSS_FIRMWARE_VERSION ==2');
VSS_PROCEDURE_FLY = Simulink.Variant('VSS_PROCEDURE==2 || VSS_PROCEDURE==3');
%VSS_PROCEDURE_FLY_HIL_FPGA = Simulink.Variant('VSS_PROCEDURE==2 || VSS_PROCEDURE==3');
VSS_PROCEDURE_FLY_V1_8 = Simulink.Variant('(VSS_PROCEDURE==2 || VSS_PROCEDURE==3) && VSS_FIRMWARE_VERSION ==0');
VSS_PROCEDURE_FLY_V1_12 = Simulink.Variant('(VSS_PROCEDURE==2 || VSS_PROCEDURE==3) && VSS_FIRMWARE_VERSION ==1');
VSS_PROCEDURE_FLY_V1_13 = Simulink.Variant('(VSS_PROCEDURE==2 || VSS_PROCEDURE==3) && VSS_FIRMWARE_VERSION ==2');
VSS_PROCEDURE_HIL_FLY = Simulink.Variant('VSS_PROCEDURE==3||VSS_PROCEDURE==2||VSS_PROCEDURE==1');
VSS_PROCEDURE_HIL_FLY_V1_8 = Simulink.Variant('(VSS_PROCEDURE==3||VSS_PROCEDURE==2||VSS_PROCEDURE==1) &&VSS_FIRMWARE_VERSION ==0');
VSS_PROCEDURE_HIL_FLY_V1_12 = Simulink.Variant('(VSS_PROCEDURE==3||VSS_PROCEDURE==2||VSS_PROCEDURE==1) && VSS_FIRMWARE_VERSION ==1');
VSS_PROCEDURE_HIL_FLY_V1_13 = Simulink.Variant('(VSS_PROCEDURE==3||VSS_PROCEDURE==2||VSS_PROCEDURE==1) && VSS_FIRMWARE_VERSION ==2');

%6dof model
VSS_6DOF_WSH = Simulink.Variant('VSS_6DOF==0');
VSS_6DOF_MATHWORKS = Simulink.Variant('VSS_6DOF==1');

%attitude control law
VSS_ATT_CTRL_EULERPID = Simulink.Variant('VSS_ATT_CTRL==0');
VSS_ATT_CTRL_EULERADRC = Simulink.Variant('VSS_ATT_CTRL==1');
VSS_ATT_CTRL_DCMPID = Simulink.Variant('VSS_ATT_CTRL==2');
VSS_ATT_CTRL_DCMADRC = Simulink.Variant('VSS_ATT_CTRL==3');

%position control
VSS_POS_LON_CTRL_PID = Simulink.Variant('VSS_POS_LON_CTRL==0');
VSS_POS_LON_CTRL_TECS = Simulink.Variant('VSS_POS_LON_CTRL==1');
VSS_POS_LAT_CTRL_PID = Simulink.Variant('VSS_POS_LAT_CTRL==0');
VSS_POS_LAT_CTRL_PATHFOLLOWING = Simulink.Variant('VSS_POS_LAT_CTRL==1');
%force allocation
VSS_FORCE_ALLOCATION_PROPOTION = Simulink.Variant('VSS_FORCE_ALLOCATION==0');
VSS_FORCE_ALLOCATION_NONLINEAR = Simulink.Variant('VSS_FORCE_ALLOCATION==1');
VSS_FORCE_ALLOCATION_OPTIMIZATION = Simulink.Variant('VSS_FORCE_ALLOCATION==2');



