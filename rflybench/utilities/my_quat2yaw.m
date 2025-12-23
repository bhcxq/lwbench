function yaw = my_quat2yaw(q, varargin)
if isempty(varargin)
    % Use default rotation sequence
    euler = my_quat2eul(q);
else
    euler = my_quat2eul(q, convertStringsToChars(varargin{1}));
end

    yaw = euler(3);
end