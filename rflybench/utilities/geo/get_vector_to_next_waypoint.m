function v_ne = get_vector_to_next_waypoint(lat_now,lon_now,lat_next,lon_next)
%GET_VECTOR_TO_NEXT_WAYPOINT 此处显示有关此函数的摘要
%   此处显示详细说明
CONSTANTS_RADIUS_OF_EARTH = 6371000; % meters (m)
DEG2RAD = 0.0174533;
lat_now_rad = lat_now*DEG2RAD;
lat_next_rad = lat_next*DEG2RAD;
d_lon = (lon_next - lon_now)*DEG2RAD;

% conscious mix of double and float trig function to maximize speed and efficiency */
v_ne = zeros(2,1);
v_ne(1) = (CONSTANTS_RADIUS_OF_EARTH * (cos(lat_now_rad) * sin(lat_next_rad) - sin(lat_now_rad) * cos(lat_next_rad) * cos(d_lon)));
v_ne(2) = (CONSTANTS_RADIUS_OF_EARTH * sin(d_lon) * cos(lat_next_rad));

end

