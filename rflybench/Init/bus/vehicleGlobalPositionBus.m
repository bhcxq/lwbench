% # Fused global position in WGS84.
% # This struct contains global position estimation. It is not the raw GPS
% # measurement (@see vehicle_gps_position). This topic is usually published by the position
% # estimator, which will take more sources of information into account than just GPS,
% # e.g. control inputs of the vehicle in a Kalman-filter implementation.
% #
% 
% float64 lat			# Latitude, (degrees)
% float64 lon			# Longitude, (degrees)
% float32 alt			# Altitude AMSL, (meters)
% 
% float32 delta_alt 	# Reset delta for altitude
% uint8 lat_lon_reset_counter	# Counter for reset events on horizontal position coordinates
% uint8 alt_reset_counter 	# Counter for reset events on altitude
% 
% float32 vel_n			# North velocity in NED earth-fixed frame, (metres/sec)
% float32 vel_e			# East velocity in NED earth-fixed frame, (metres/sec)
% float32 vel_d			# Down velocity in NED earth-fixed frame, (metres/sec)
% 
% float32 yaw 			# Euler yaw angle relative to NED earth-fixed frame, -PI..+PI, (radians)
% 
% float32 eph			# Standard deviation of horizontal position error, (metres)
% float32 epv			# Standard deviation of vertical position error, (metres)
% 
% float32 terrain_alt		# Terrain altitude WGS84, (metres)
% bool terrain_alt_valid		# Terrain altitude estimate is valid
% 
% bool dead_reckoning		# True if this position is estimated through dead-reckoning
% 
% # TOPICS vehicle_global_position vehicle_global_position_groundtruth

vehicle_global_position_bus = Simulink.Bus;
lat = Simulink.BusElement;
lat.Name = 'lat';
lat.Dimensions = 1;
lat.DimensionsMode = 'Fixed';
lat.DataType = 'double';

lon = Simulink.BusElement;
lon.Name = 'lon';
lon.Dimensions = 1;
lon.DimensionsMode = 'Fixed';
lon.DataType = 'double';

alt = Simulink.BusElement;
alt.Name = 'alt';
alt.Dimensions = 1;
alt.DimensionsMode = 'Fixed';
alt.DataType = 'single';

delta_alt = Simulink.BusElement;
delta_alt.Name = 'delta_alt';
delta_alt.Dimensions = 1;
delta_alt.DimensionsMode = 'Fixed';
delta_alt.DataType = 'single';

vel_n = Simulink.BusElement;
vel_n.Name = 'vel_n_m_s';
vel_n.Dimensions = 1;
vel_n.DimensionsMode = 'Fixed';
vel_n.DataType = 'single';

vel_e = Simulink.BusElement;
vel_e.Name = 'vel_e_m_s';
vel_e.Dimensions = 1;
vel_e.DimensionsMode = 'Fixed';
vel_e.DataType = 'single';

vel_d = Simulink.BusElement;
vel_d.Name = 'vel_d_m_s';
vel_d.Dimensions = 1;
vel_d.DimensionsMode = 'Fixed';
vel_d.DataType = 'single';

yaw = Simulink.BusElement;
yaw.Name = 'yaw';
yaw.Dimensions = 1;
yaw.DimensionsMode = 'Fixed';
yaw.DataType = 'single';

vehicle_global_position_bus.Elements = [lat lon alt delta_alt vel_n vel_e vel_d yaw];

