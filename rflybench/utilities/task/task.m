function [pos_ref, vel_ref, acc_ref, euler_ref,dot3x, yaw_ref, dotpsi,reverse_flag] = task(timestamp, flight_mode,pos, vel, q, LW_OB_CIRCLE_R, LW_OB_CIRCLE_V, LW_OB_CIRCLE_W, LW_OB_TYPE)
LW_OB_TYPE = single(0);
LW_OB_CIRCLE_R = single(0);
LW_OB_CIRCLE_V = single(15);
LW_OB_CIRCLE_W = single(60);

persistent time_start  
if isempty(time_start)
    time_start = timestamp;
end
persistent pos_last  acc_last yaw_last pos_start pos_deacc_start pos_takeoff pos_return
if isempty(acc_last)
    acc_last = zeros(3,1,'single');
    pos_last = zeros(3,1,'single');
    pos_start = pos(:);
    pos_deacc_start = pos(:);
    pos_takeoff = pos(:);
    pos_return = pos(:);
end
persistent lineMode Acct Unit Unit1
if isempty(lineMode)
    lineMode = int8(0);
    Acct = single(0);
    Unit = single(0);
    Unit1 = single(0);
end

if notInfNan(q)
    euler = my_quat2eul(q);
    yaw = euler(3);
else
    yaw = single(0);
end
persistent takeoff_yaw
if isempty(takeoff_yaw)
    takeoff_yaw = yaw;
    yaw_last = yaw;
end

Takeoff_time = 0;
Takeoff_holdtime = 20;
task1_time = 500;
task1_R = LW_OB_CIRCLE_R;
task_R = LW_OB_CIRCLE_W;%复用为匀速时间
LineVmax = LW_OB_CIRCLE_V;

if flight_mode ~= FlightMode.OFFBOARD
    time_start = timestamp;

    lineMode = int8(0);
    Acct = single(0);
    Unit = single(0);
    pos_start = pos(:);
    pos_takeoff = pos(:);
    pos_return = pos(:);
 
    pos_last = pos;
    yaw_last = yaw;
end


dotpsi = single(0);
Rbe_psi = [cos(task1_R) sin(task1_R)  0;
           -sin(task1_R) cos(task1_R) 0;
            0 0 1];%task1_R在这里被复用为期望偏航角
if flight_mode == FlightMode.OFFBOARD
    if timestamp <= time_start  + Takeoff_time
        pos_start = pos;
        pos_takeoff = pos;
        acc_ref = zeros(3,1,'single');
        vel_ref = zeros(3,1,'single');
        pos_ref = pos_takeoff;
        dot3x = zeros(3,1,'single');
        yaw_ref = yaw_last;
        dotpsi = single(0);
        reverse_flag = int8(0);
    elseif timestamp <= time_start + Takeoff_holdtime + Takeoff_time
        %起飞之后保持,调整偏航角
        t = timestamp - time_start -Takeoff_time;
        if t <= 15
            acc_ref = zeros(3,1,'single');
            vel_ref = single([0;0;0]);
            pos_ref = pos_takeoff + single([0;0;-t]);
            dot3x = zeros(3,1,'single');
            yaw_ref = yaw_last;
            dotpsi = single(0);
            pos_start = pos_ref;
        else
            pos_return = pos_start;
            t = t-15;
            acc_ref = zeros(3,1,'single');
            vel_ref = zeros(3,1,'single');
            pos_ref = pos_start;
            dot3x = zeros(3,1,'single');
            error_yaw = wrap_pi(task1_R - yaw);
            yaw_ref = single(yaw + error_yaw*sin(pi/(Takeoff_holdtime*2)*t));
            yaw_ref = wrap_pi(yaw_ref);
            dotpsi = single(error_yaw*pi/(2*Takeoff_holdtime)*cos(pi/(Takeoff_holdtime*2)*t));
            yaw_last = yaw_ref;
            lineMode = int8(0);
        end
        reverse_flag = int8(0);
    elseif timestamp <= time_start + Takeoff_holdtime +task1_time + Takeoff_time
        %task1
        t = timestamp - time_start - Takeoff_holdtime - Takeoff_time;
  
         if lineMode <= int8(1) %加速
            pos_ref = pos_start + single(Rbe_psi'*[0; 12; 0]);
            vel_ref = single(Rbe_psi'*[0; 0; 0]);
            acc_ref = single(Rbe_psi'*[0; 0; 0]);
            dot3x = single(Rbe_psi'*[0; 0; 0]);
         
            yaw_ref = single(task1_R);
            pos_last = pos_ref;
            pos_deacc_start = pos_ref;
            yaw_last = yaw;
            reverse_flag = int8(0);
        else
            acc_ref = zeros(3,1,'single');
            vel_ref = zeros(3,1,'single');
            pos_ref = pos_last;
            dot3x = zeros(3,1,'single');
            yaw_ref = yaw_last;
            reverse_flag = int8(0);
        end

        time = 10;
        if t <= time && lineMode <= int8(1) %加速
            lineMode = int8(1); 
            Acct = t;
        else
            lineMode = int8(2);
        end
    else
        acc_ref = zeros(3,1,'single');
        vel_ref = zeros(3,1,'single');
        pos_ref = pos_last;
        dot3x = zeros(3,1,'single');
        yaw_ref = yaw_last;
        dotpsi = single(0);
        reverse_flag = int8(0);
    end
else
    %悬停
    acc_ref = zeros(3,1,'single');
    vel_ref = zeros(3,1,'single');
    pos_ref = pos_last;
    dot3x = zeros(3,1,'single');
    yaw_ref = yaw_last;
    dotpsi = single(0);
    reverse_flag = int8(0);
end
euler_ref = single([0;0;0]);
end




