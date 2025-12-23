% # Fused local position in NED.
% # The coordinate system origin is the vehicle position at the time when the EKF2-module was started.
% 
% uint64 timestamp			# time since system start (microseconds)
% uint64 timestamp_sample                 # the timestamp of the raw data (microseconds)
% 
% bool xy_valid				# true if x and y are valid
% bool z_valid				# true if z is valid
% bool v_xy_valid				# true if vx and vy are valid
% bool v_z_valid				# true if vz is valid
% 
% # Position in local NED frame
% float32 x				# North position in NED earth-fixed frame, (metres)
% float32 y				# East position in NED earth-fixed frame, (metres)
% float32 z				# Down position (negative altitude) in NED earth-fixed frame, (metres)
% 
% # Position reset delta
% float32[2] delta_xy
% uint8 xy_reset_counter
% 
% float32 delta_z
% uint8 z_reset_counter
% 
% # Velocity in NED frame
% float32 vx 				# North velocity in NED earth-fixed frame, (metres/sec)
% float32 vy				# East velocity in NED earth-fixed frame, (metres/sec)
% float32 vz				# Down velocity in NED earth-fixed frame, (metres/sec)
% float32 z_deriv				# Down position time derivative in NED earth-fixed frame, (metres/sec)
% 
% # Velocity reset delta
% float32[2] delta_vxy
% uint8 vxy_reset_counter
% 
% float32 delta_vz
% uint8 vz_reset_counter
% # Acceleration in NED frame
% float32 ax        # North velocity derivative in NED earth-fixed frame, (metres/sec^2)
% float32 ay        # East velocity derivative in NED earth-fixed frame, (metres/sec^2)
% float32 az        # Down velocity derivative in NED earth-fixed frame, (metres/sec^2)
% 
% float32 heading				# Euler yaw angle transforming the tangent plane relative to NED earth-fixed frame, -PI..+PI,  (radians)
% float32 delta_heading
% uint8 heading_reset_counter
% bool heading_good_for_control
% 
% # Position of reference point (local NED frame origin) in global (GPS / WGS84) frame
% bool xy_global				# true if position (x, y) has a valid global reference (ref_lat, ref_lon)
% bool z_global				# true if z has a valid global reference (ref_alt)
% uint64 ref_timestamp			# Time when reference position was set since system start, (microseconds)
% float64 ref_lat				# Reference point latitude, (degrees)
% float64 ref_lon				# Reference point longitude, (degrees)
% float32 ref_alt				# Reference altitude AMSL, (metres)
% 
% # Distance to surface
% float32 dist_bottom			# Distance from from bottom surface to ground, (metres)
% bool dist_bottom_valid			# true if distance to bottom surface is valid
% uint8 dist_bottom_sensor_bitfield	# bitfield indicating what type of sensor is used to estimate dist_bottom
% uint8 DIST_BOTTOM_SENSOR_NONE = 0
% uint8 DIST_BOTTOM_SENSOR_RANGE = 1	# (1 << 0) a range sensor is used to estimate dist_bottom field
% uint8 DIST_BOTTOM_SENSOR_FLOW = 2	# (1 << 1) a flow sensor is used to estimate dist_bottom field (mostly fixed-wing use case)
% 
% float32 eph				# Standard deviation of horizontal position error, (metres)
% float32 epv				# Standard deviation of vertical position error, (metres)
% float32 evh				# Standard deviation of horizontal velocity error, (metres/sec)
% float32 evv				# Standard deviation of horizontal velocity error, (metres/sec)
% 
% # estimator specified vehicle limits
% float32 vxy_max				# maximum horizontal speed - set to 0 when limiting not required (meters/sec)
% float32 vz_max				# maximum vertical speed - set to 0 when limiting not required (meters/sec)
% float32 hagl_min			# minimum height above ground level - set to 0 when limiting not required (meters)
% float32 hagl_max			# maximum height above ground level - set to 0 when limiting not required (meters)
% 
% # TOPICS vehicle_local_position vehicle_local_position_groundtruth
% # TOPICS estimator_local_position


local_position_bus = Simulink.Bus;

timestamp = Simulink.BusElement;
timestamp.Name = 'timestamp';
timestamp.Dimensions = 1;
timestamp.DimensionsMode = 'Fixed';
timestamp.DataType = 'double';

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

delta_xy = Simulink.BusElement;
delta_xy.Name = 'delta_xy';
delta_xy.Dimensions = 2;
delta_xy.DimensionsMode = 'Fixed';
delta_xy.DataType = 'single';

xy_reset_counter = Simulink.BusElement;
xy_reset_counter.Name = 'xy_reset_counter';
xy_reset_counter.Dimensions = 1;
xy_reset_counter.DimensionsMode = 'Fixed';
xy_reset_counter.DataType = 'uint8';


delta_z = Simulink.BusElement;
delta_z.Name = 'delta_z';
delta_z.Dimensions = 1;
delta_z.DimensionsMode = 'Fixed';
delta_z.DataType = 'single';

z_reset_counter = Simulink.BusElement;
z_reset_counter.Name = 'z_reset_counter';
z_reset_counter.Dimensions = 1;
z_reset_counter.DimensionsMode = 'Fixed';
z_reset_counter.DataType = 'uint8';

delta_vxy = Simulink.BusElement;
delta_vxy.Name = 'delta_vxy';
delta_vxy.Dimensions = 2;
delta_vxy.DimensionsMode = 'Fixed';
delta_vxy.DataType = 'single';

vxy_reset_counter = Simulink.BusElement;
vxy_reset_counter.Name = 'vxy_reset_counter';
vxy_reset_counter.Dimensions = 1;
vxy_reset_counter.DimensionsMode = 'Fixed';
vxy_reset_counter.DataType = 'uint8';


delta_vz = Simulink.BusElement;
delta_vz.Name = 'delta_vz';
delta_vz.Dimensions = 1;
delta_vz.DimensionsMode = 'Fixed';
delta_vz.DataType = 'single';

vz_reset_counter = Simulink.BusElement;
vz_reset_counter.Name = 'vz_reset_counter';
vz_reset_counter.Dimensions = 1;
vz_reset_counter.DimensionsMode = 'Fixed';
vz_reset_counter.DataType = 'uint8';

heading = Simulink.BusElement;
heading.Name = 'heading';
heading.Dimensions = 1;
heading.DimensionsMode = 'Fixed';
heading.DataType = 'single';

delta_heading = Simulink.BusElement;
delta_heading.Name = 'delta_heading';
delta_heading.Dimensions = 1;
delta_heading.DimensionsMode = 'Fixed';
delta_heading.DataType = 'single';

heading_reset_counter = Simulink.BusElement;
heading_reset_counter.Name = 'heading_reset_counter';
heading_reset_counter.Dimensions = 1;
heading_reset_counter.DimensionsMode = 'Fixed';
heading_reset_counter.DataType = 'uint8';

heading_good_for_control = Simulink.BusElement;
heading_good_for_control.Name = 'heading_good_for_control';
heading_good_for_control.Dimensions = 1;
heading_good_for_control.DimensionsMode = 'Fixed';
heading_good_for_control.DataType = 'boolean';


local_position_bus.Elements = [timestamp pos vel delta_xy xy_reset_counter delta_z z_reset_counter...
    delta_vxy vxy_reset_counter delta_vz vz_reset_counter heading delta_heading heading_reset_counter heading_good_for_control];


