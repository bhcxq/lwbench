function bearing = get_bearing_to_next_waypoint(lat_now,lon_now,lat_next,lon_next)
%UNTITLED 此处显示有关此函数的摘要
%   此处显示详细说明
    lat_now_rad = deg2rad(lat_now);
	lon_now_rad = deg2rad(lon_now);
    lat_next_rad = deg2rad(lat_next);
    lon_next_rad = deg2rad(lon_next);

    d_lon = lon_next_rad - lon_now_rad;

	% conscious mix of double and float trig function to maximize speed and efficiency 

	y = single(sin(d_lon) * cos(lat_next_rad));
	x = single(cos(lat_now_rad) * sin(lat_next_rad) - sin(lat_now_rad) * cos(lat_next_rad) * cos(d_lon));

	bearing = wrap_pi(atan2(y, x));
end

