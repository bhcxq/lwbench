load MavLinkStruct.mat
load environmentStates.mat
load SL_Bus_MAVLink.mat
load uavStateBus.mat
load gps_raw_init.mat
load attitudeBus.mat
load local_position_ned.mat
load uavPathManagerBus.mat
positionSetpointBus;
vehicleGlobalPositionBus;
OffboardBus;

%load position_setpoint.mat
%1.8.2

if strcmp(ModelConfigure_FirmwareVersion, 'V1.8.2')
    load .\Init\bus\V1.8.2\input_rc_SL.mat
    load .\Init\bus\V1.8.2\vehicle_attitude_SL.mat
    load .\Init\bus\V1.8.2\vehicle_local_position.mat
    load .\Init\bus\V1.8.2\vehicle_local_position_SL.mat
elseif strcmp(ModelConfigure_FirmwareVersion, 'V1.12.3')
    load .\Init\bus\V1.12.3\input_rc_SL.mat
    load .\Init\bus\V1.12.3\manual_control_setpoint_SL.mat
    load .\Init\bus\V1.12.3\vehicle_attitude_SL.mat
    load .\Init\bus\V1.12.3\vehicle_angular_velocity_SL.mat
    load .\Init\bus\V1.12.3\vehicle_local_position_SL.mat
    load .\Init\bus\V1.12.3\vehicle_global_position_SL.mat
    load .\Init\bus\V1.12.3\vehicle_gps_position_SL.mat
    load .\Init\bus\V1.12.3\battery_status_SL.mat
    load .\Init\bus\V1.12.3\airspeed_SL.mat
    load .\Init\bus\V1.12.3\costom_lw_mixer_SL.mat
    load .\Init\bus\V1.12.3\sensor_combined_SL.mat
elseif strcmp(ModelConfigure_FirmwareVersion, 'V1.13.3')
    load .\Init\bus\V1.13.3\airspeed_SL.mat
    load .\Init\bus\V1.13.3\battery_status_SL.mat
    load .\Init\bus\V1.13.3\vehicle_angular_velocity_SL.mat
    load .\Init\bus\V1.13.3\vehicle_attitude_SL.mat
    load .\Init\bus\V1.13.3\vehicle_global_position_SL.mat
    load .\Init\bus\V1.13.3\vehicle_gps_position_SL.mat
    load .\Init\bus\V1.13.3\vehicle_local_position_SL.mat
    load .\Init\bus\V1.13.3\sensor_combined_SL.mat
    load .\Init\bus\V1.12.3\costom_lw_mixer_SL.mat
else
    error('Firmware version error! It is not V1.8.2 V1.12.3 or V1.13.3'); 
end

vehicle_attitude_bus = Simulink.Bus;
q = Simulink.BusElement;
q.Name = 'q';
q.Dimensions = [4 1];
q.DimensionsMode = 'Fixed';
q.DataType = 'single';
wb = Simulink.BusElement;
wb.Name = 'wb';
wb.Dimensions = [3 1];
wb.DimensionsMode = 'Fixed';
wb.DataType = 'single';
timestamp = Simulink.BusElement;
timestamp.Name = 'timestamp';
timestamp.Dimensions = 1;
timestamp.DimensionsMode = 'Fixed';
timestamp.DataType = 'double';
vehicle_attitude_bus.Elements = [q wb timestamp];

vehicle_mode_bus = Simulink.Bus;
flight_mode = Simulink.BusElement;
flight_mode.Name = 'flight_mode';
flight_mode.Dimensions = 1;
flight_mode.DimensionsMode = 'Fixed';
flight_mode.DataType = 'uint8';
ctrl_mode = Simulink.BusElement;
ctrl_mode.Name = 'ctrl_mode';
ctrl_mode.DataType = 'uint8';
arm = Simulink.BusElement;
arm.Name = 'arm';
arm.DataType = 'uint8';
vehicle_mode_bus.Elements = [flight_mode ctrl_mode arm];

battery_status_bus = Simulink.Bus;
voltage_filtered_v = Simulink.BusElement;
voltage_filtered_v.Name = 'voltage_filtered_v';
voltage_filtered_v.Dimensions = 1;
voltage_filtered_v.DimensionsMode = 'Fixed';
voltage_filtered_v.DataType = 'single';
current_filtered_a = Simulink.BusElement;
current_filtered_a.Name = 'current_filtered_a';
current_filtered_a.Dimensions = 1;
current_filtered_a.DimensionsMode = 'Fixed';
current_filtered_a.DataType = 'single';
connected = Simulink.BusElement;
connected.Name = 'connected';
connected.Dimensions = 1;
connected.DimensionsMode = 'Fixed';
connected.DataType = 'boolean';
battery_status_bus.Elements = [voltage_filtered_v current_filtered_a connected];
%auto flight
for i = 1:MAX_MISSION_ITEM
    basline_mission(i) = struct('mode',uint8(1),'position',single([0,0,0]'),'params',single([0;0;0;0]));
end
auto_ref_bus = Simulink.Bus;
dubins = Simulink.BusElement;
dubins.Name = 'dubins';
dubins.Dimensions = 7;
dubins.DimensionsMode = 'Fixed';
dubins.DataType = 'single';
pos_z_ref = Simulink.BusElement;
pos_z_ref.Name = 'pos_z_ref';
pos_z_ref.DataType = 'single';
yaw_ref = Simulink.BusElement;
yaw_ref.Name = 'yaw_ref';
yaw_ref.DataType = 'single';
v_ref = Simulink.BusElement;
v_ref.Name = 'v_ref';
v_ref.Dimensions = 3;
v_ref.DataType = 'single';
auto_ref_bus.Elements = [dubins pos_z_ref yaw_ref v_ref];

UDPMessageLength = 10;
paramCreator = exampleHelperMAVLinkParamProtocol;
apParams = paramCreator.AutopilotParamsArray;
pmTotal = double(exampleHelperMAVLinkParamProtocol.PARAM_COUNT) - 1;
% Mission Microservice
newCount =  Simulink.Signal;
newCount.DataType = 'boolean';
newCount.InitialValue = 'boolean(0)';
newCount.Complexity = 'real';

newItem =  Simulink.Signal;
newItem.DataType = 'boolean';
newItem.InitialValue = 'boolean(0)';
newItem.Complexity = 'real';

% Parameter Microservice
newParamList =  Simulink.Signal;
newParamList.DataType = 'boolean';
newParamList.InitialValue = 'boolean(0)';
newParamList.Complexity = 'real';

newParamRead =  Simulink.Signal;
newParamRead.DataType = 'boolean';
newParamRead.InitialValue = 'boolean(0)';
newParamRead.Complexity = 'real';

newParamSet =  Simulink.Signal;
newParamSet.DataType = 'boolean';
newParamSet.InitialValue = 'boolean(0)';
newParamSet.Complexity = 'real';

flightParams = Simulink.Signal;
flightParams.DataType = 'Bus: SL_Bus_MAVLink_PARAM_VALUE_Payload';
flightParams.Complexity = 'real';
flightParams.Dimensions = double(exampleHelperMAVLinkParamProtocol.PARAM_COUNT);


