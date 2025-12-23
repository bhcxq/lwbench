% uint8 SETPOINT_TYPE_POSITION=0	# position setpoint
% uint8 SETPOINT_TYPE_VELOCITY=1	# velocity setpoint
% uint8 SETPOINT_TYPE_LOITER=2	# loiter setpoint
% uint8 SETPOINT_TYPE_TAKEOFF=3	# takeoff setpoint
% uint8 SETPOINT_TYPE_LAND=4	# land setpoint, altitude must be ignored, descend until landing
% uint8 SETPOINT_TYPE_IDLE=5	# do nothing, switch off motors or keep at idle speed (MC)
% uint8 SETPOINT_TYPE_OFFBOARD=6 	# setpoint in NED frame (x, y, z, vx, vy, vz) set by offboard
% uint8 SETPOINT_TYPE_FOLLOW_TARGET=7  # setpoint in NED frame (x, y, z, vx, vy, vz) set by follow target
% 
% uint8 VELOCITY_FRAME_LOCAL_NED = 1 # MAV_FRAME_LOCAL_NED
% uint8 VELOCITY_FRAME_BODY_NED = 8 # MAV_FRAME_BODY_NED
% 
% bool valid			# true if setpoint is valid
% uint8 type			# setpoint type to adjust behavior of position controller
% 
% float32 x			# local position setpoint in m in NED
% float32 y			# local position setpoint in m in NED
% float32 z			# local position setpoint in m in NED
% bool position_valid		# true if local position setpoint valid
% 
% float32 vx			# local velocity setpoint in m/s in NED
% float32 vy			# local velocity setpoint in m/s in NED
% float32 vz			# local velocity setpoint in m/s in NED
% bool velocity_valid		# true if local velocity setpoint valid
% uint8 velocity_frame		# to set velocity setpoints in NED or body
% bool alt_valid		# do not set for 3D position control. Set to true if you want z-position control while doing vx,vy velocity control.
% 
% float64 lat			# latitude, in deg
% float64 lon			# longitude, in deg
% float32 alt			# altitude AMSL, in m
% 
% float32 yaw			# yaw (only for multirotors), in rad [-PI..PI), NaN = hold current yaw
% bool yaw_valid			# true if yaw setpoint valid
% 
% float32 yawspeed		# yawspeed (only for multirotors, in rad/s)
% bool yawspeed_valid		# true if yawspeed setpoint valid
% 
% float32 loiter_radius		# loiter radius (only for fixed wing), in m
% int8 loiter_direction		# loiter direction: 1 = CW, -1 = CCW
% float32 pitch_min		# minimal pitch angle for fixed wing takeoff waypoints
% 
% float32 a_x			# acceleration x setpoint
% float32 a_y			# acceleration y setpoint
% float32 a_z			# acceleration z setpoint
% bool acceleration_valid		# true if acceleration setpoint is valid/should be used
% bool acceleration_is_force	# interprete acceleration as force
% 
% float32 acceptance_radius   # navigation acceptance_radius if we're doing waypoint navigation
% 
% float32 cruising_speed		# the generally desired cruising speed (not a hard constraint)
% float32 cruising_throttle	# the generally desired cruising throttle (not a hard constraint)

Simulink.defineIntEnumType('SETPOINT_TYPE',{...
    'SETPOINT_TYPE_POSITION',...
    'SETPOINT_TYPE_VELOCITY',...
    'SETPOINT_TYPE_LOITER',...
    'SETPOINT_TYPE_TAKEOFF',...
    'SETPOINT_TYPE_LAND',...
    'SETPOINT_TYPE_IDLE',...
    'SETPOINT_TYPE_OFFBOARD',...
    'SETPOINT_TYPE_FOLLOW_TARGET'},...
    [0;1;2;3;4;5;6;7]);
Simulink.defineIntEnumType('VELOCITY_FRAME',{...
    'VELOCITY_FRAME_LOCAL_NED',...
    'VELOCITY_FRAME_BODY_NED'},...
    [1;8]);
position_setpoint_bus = Simulink.Bus;
type = Simulink.BusElement;
type.Name = 'type';
type.Dimensions = 1;
type.DimensionsMode = 'Fixed';
type.DataType = 'uint8';

pos = Simulink.BusElement;
pos.Name = 'pos';
pos.Dimensions = 3;
pos.DimensionsMode = 'Fixed';
pos.DataType = 'single';

vel = Simulink.BusElement;
vel.Name = 'vel';
vel.Dimensions = 3;
vel.DimensionsMode = 'Fixed';
vel.DataType = 'single';
velocity_frame = Simulink.BusElement;
velocity_frame.Name = 'velocity_frame';
velocity_frame.Dimensions = 1;
velocity_frame.DimensionsMode = 'Fixed';
velocity_frame.DataType = 'uint8';

lat_long = Simulink.BusElement;
lat_long.Name = 'lat_long';
lat_long.Dimensions = 2;
lat_long.DimensionsMode = 'Fixed';
lat_long.DataType = 'double';
alt = Simulink.BusElement;
alt.Name = 'alt';
alt.Dimensions = 1;
alt.DimensionsMode = 'Fixed';
alt.DataType = 'single';

yaw = Simulink.BusElement;
yaw.Name = 'yaw';
yaw.Dimensions = 1;
yaw.DimensionsMode = 'Fixed';
yaw.DataType = 'single';

loiter_radius = Simulink.BusElement;
loiter_radius.Name = 'loiter_radius';
loiter_radius.Dimensions = 1;
loiter_radius.DimensionsMode = 'Fixed';
loiter_radius.DataType = 'single';

loiter_direction = Simulink.BusElement;
loiter_direction.Name = 'loiter_direction';
loiter_direction.Dimensions = 1;
loiter_direction.DimensionsMode = 'Fixed';
loiter_direction.DataType = 'single';

cruising_speed = Simulink.BusElement;
cruising_speed.Name = 'cruising_speed';
cruising_speed.Dimensions = 1;
cruising_speed.DimensionsMode = 'Fixed';
cruising_speed.DataType = 'single';

position_setpoint_bus.Elements = [type velocity_frame pos vel lat_long alt yaw loiter_radius loiter_direction cruising_speed];

position_setpoint_triplet_bus = Simulink.Bus;
previous = Simulink.BusElement;
previous.Name = 'previous';
previous.Dimensions = 1;
previous.DimensionsMode = 'Fixed';
previous.DataType = 'Bus: position_setpoint_bus';

current = Simulink.BusElement;
current.Name = 'current';
current.Dimensions = 1;
current.DimensionsMode = 'Fixed';
current.DataType = 'Bus: position_setpoint_bus';

next = Simulink.BusElement;
next.Name = 'next';
next.Dimensions = 1;
next.DimensionsMode = 'Fixed';
next.DataType = 'Bus: position_setpoint_bus';
position_setpoint_triplet_bus.Elements = [previous current next];

