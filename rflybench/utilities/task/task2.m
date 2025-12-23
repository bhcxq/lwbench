function [pos_ref, vel_ref, acc_ref, euler_ref, dot3x, yaw_ref, dotpsi, reverse_flag] = task2(timestamp, flight_mode,pos, vel, q, LW_OB_CIRCLE_R, LW_OB_CIRCLE_V, LW_OB_CIRCLE_W, LW_OB_TYPE)
LW_OB_TYPE = single(1);%
LW_OB_CIRCLE_R = single(50);%10m/s,30m;15m/s,50m
LW_OB_CIRCLE_V = single(10);
LW_OB_CIRCLE_W = single(0.03);%0.03
persistent time_start
if isempty(time_start)
    time_start = timestamp;
end
persistent pos_last acc_last yaw_last pos_start pos_takeoff
if isempty(acc_last)
    acc_last = zeros(3,1,'single');
    pos_last = zeros(3,1,'single');
    pos_start = pos(:);
    pos_takeoff = pos(:);
end
persistent circleMode Acct Unit
if isempty(circleMode)
    circleMode = int8(0);
    Acct = single(0);
    Unit = single(0);
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

Takeoff_holdtime = 20;
% a = -6*tf/tf^3*t^2 + 6*vf/tf^2*t
% Takeoff_tf = 30;
% takeoff_vf = 2;
% takeoff_c1 = -6*takeoff_vf/Takeoff_tf^3;
% takeoff_c2 = 6*takeoff_vf/Takeoff_tf^2;

task1_time = 200;
task1_R = LW_OB_CIRCLE_R;
task1_omega = LW_OB_CIRCLE_W;
CircleVmax = LW_OB_CIRCLE_V;
nCircle = 1.6;

if flight_mode ~= FlightMode.OFFBOARD
    time_start = timestamp;

    circleMode = int8(0);
    Acct = single(0);
    Unit = single(0);
    pos_start = pos(:);
    pos_takeoff = pos(:);

    pos_last = pos;
    yaw_last = yaw;
end



dotpsi = single(0);

if flight_mode == FlightMode.OFFBOARD
    if timestamp <= time_start + Takeoff_holdtime
        %起飞之后保持,调整偏航角
        t = timestamp - time_start;
        if t <= 15
            acc_ref = zeros(3,1,'single');
            vel_ref = single([0;0;-1]);
            pos_ref = pos_takeoff + single([0;0;-t]);
            dot3x = zeros(3,1,'single');
            yaw_ref = yaw_last;
            dotpsi = single(0);
            pos_start = pos(:);
        else
            t = t-15;
            acc_ref = zeros(3,1,'single');
            vel_ref = zeros(3,1,'single');
            pos_ref = pos_start;
            dot3x = zeros(3,1,'single');
            yaw_ref = single(pi/2*sin(pi/(Takeoff_holdtime*2)*t));
            dotpsi = single(pi*pi/(4*Takeoff_holdtime)*cos(pi/(Takeoff_holdtime*2)*t));
            yaw_last = yaw_ref;
            circleMode = int8(0);
            %    pos_start = single([0; 0; -3]);
        end
    elseif timestamp <= time_start + Takeoff_holdtime +task1_time
        %task1
        t = timestamp - time_start - Takeoff_holdtime;
  
        if circleMode <= int8(1) %加速
            if LW_OB_TYPE < 0.5
                pos_ref = pos_start + [task1_R*(1 - cos(0.5*task1_omega*t*t)); task1_R*sin(0.5*task1_omega*t*t); 0];
                vel_ref = [task1_omega*t*task1_R*sin(0.5*task1_omega*t*t); task1_omega*t*task1_R*cos(0.5*task1_omega*t*t); 0];
                acc_ref = [task1_omega*task1_R*sin(0.5*task1_omega*t*t)+task1_omega^2*t^2*task1_R*cos(0.5*task1_omega*t*t);
                           task1_omega*task1_R*cos(0.5*task1_omega*t^2)-task1_omega^2*t^2*task1_R*sin(0.5*task1_omega*t*t); 0];
                dot3x = [3*task1_omega^2*t*task1_R*cos(0.5*task1_omega*t^2)-task1_omega^3*t^3*task1_R*sin(0.5*task1_omega*t^2);
                        -3*task1_omega^2*t*task1_R*sin(0.5*task1_omega*t^2)-task1_omega^3*t^3*task1_R*cos(0.5*task1_omega*t^2); 0];
            else
                pos_ref = pos_start + [task1_R*(1 - cos(0.5*task1_omega/2*t*t)); task1_R/2*sin(0.5*task1_omega*t*t); 0];
                vel_ref = [task1_omega/2*t*task1_R*sin(0.5*task1_omega/2*t*t); task1_omega*t*task1_R/2*cos(0.5*task1_omega*t*t); 0];
                acc_ref = [task1_omega/2*task1_R*sin(0.5*task1_omega/2*t*t) + (task1_omega/2)^2*t^2*task1_R*cos(0.5*task1_omega/2*t*t);
                           task1_omega*task1_R/2*cos(0.5*task1_omega*t^2) - task1_omega^2*t^2*task1_R/2*sin(0.5*task1_omega*t*t); 0];
                dot3x = [3*(task1_omega/2)^2*t*task1_R*cos(0.5*task1_omega/2*t^2)-(task1_omega/2)^3*t^3*task1_R*sin(0.5*task1_omega/2*t^2);
                        -3*task1_omega^2*t*task1_R/2*sin(0.5*task1_omega*t^2)-task1_omega^3*t^3*task1_R/2*cos(0.5*task1_omega*t^2); 0];
            end
         
            yaw_ref = single(NaN);
            pos_last = pos_ref;
            yaw_last = yaw;
        elseif circleMode <= int8(2) %匀速
            omega = 0.5*task1_omega*Acct^2 +task1_omega*Acct*(t - Acct);
           if LW_OB_TYPE < 0.5
                pos_ref = pos_start + [task1_R*(1 - cos(omega)); task1_R*sin(omega); 0];
                vel_ref = [Acct*task1_R*task1_omega*sin(omega); 
                           Acct*task1_R*task1_omega*cos(omega); 0];
                acc_ref = [Acct^2*task1_R*task1_omega^2*cos(omega);
                          -Acct^2*task1_R*task1_omega^2*sin(omega); 0];
                dot3x = [-Acct^3*task1_R*task1_omega^3*sin(omega);
                         -Acct^3*task1_R*task1_omega^3*cos(omega); 0];
            else
                pos_ref = pos_start + [task1_R*(1 - cos(omega/2)); task1_R/2*sin(omega); 0];
                vel_ref = [Acct*task1_R*task1_omega/2*sin(omega/2); 
                           Acct*task1_R/2*task1_omega*cos(omega); 0];
                acc_ref = [Acct^2*task1_R*(task1_omega/2)^2*cos(omega/2);
                          -Acct^2*task1_R/2*task1_omega^2*sin(omega); 0];
                dot3x = [-Acct^3*task1_R*(task1_omega/2)^3*sin(omega/2);
                         -Acct^3*task1_R/2*task1_omega^3*cos(omega); 0];
            end
            yaw_ref = single(NaN);
            pos_last = pos_ref;
            yaw_last = yaw;
        elseif circleMode <= int8(3) %减速
            tem = (t - Acct - Unit);
            omega = 0.5*task1_omega*Acct^2 +task1_omega*Acct*Unit + 0.5*task1_omega*(2*Acct - tem)*tem;
            %deAcct = Acct + Unit - t;
            if LW_OB_TYPE < 0.5
                pos_ref = pos_start + [task1_R*(1 - cos(omega)); task1_R*sin(omega); 0];
            vel_ref = [task1_R*(Acct - tem)*task1_omega*sin(omega);
                       task1_R*(Acct - tem)*task1_omega*cos(omega); 0];
            acc_ref = [(task1_R*task1_omega^2*cos(omega)*(Acct - tem)*(2*Acct - 2*tem))/2 - task1_R*task1_omega*sin(omega);
                       - task1_R*task1_omega*cos(omega) - (task1_R*task1_omega^2*sin(omega)*(Acct - tem)*(2*Acct - 2*tem))/2; 0];
            dot3x = [- task1_R*task1_omega^3*sin(omega)*(Acct - tem)^3 - task1_R*task1_omega^2*cos(omega)*(Acct - tem) - task1_R*task1_omega^2*cos(omega)*(2*Acct - 2*tem);
                     task1_R*task1_omega^2*sin(omega)*(2*Acct - 2*tem) + task1_R*task1_omega^2*sin(omega)*(Acct - tem) - task1_R*task1_omega^3*cos(omega)*(Acct - tem)^3; 0];
            else
                pos_ref = pos_start + [task1_R*(1 - cos(omega/2)); task1_R/2*sin(omega); 0];
                vel_ref = [task1_R*(Acct - tem)*task1_omega/2*sin(omega/2);
                           task1_R/2*(Acct - tem)*task1_omega*cos(omega); 0];
                acc_ref = [(task1_R*(task1_omega/2)^2*cos(omega/2)*(Acct - tem)*(2*Acct - 2*tem))/2 - task1_R*task1_omega/2*sin(omega/2);
                           - task1_R/2*task1_omega*cos(omega) - (task1_R/2*task1_omega^2*sin(omega)*(Acct - tem)*(2*Acct - 2*tem))/2; 0];
                dot3x = [- task1_R*(task1_omega/2)^3*sin(omega/2)*(Acct - tem)^3 - task1_R*(task1_omega/2)^2*cos(omega/2)*(Acct - tem) - task1_R*(task1_omega/2)^2*cos(omega/2)*(2*Acct - 2*tem);
                         task1_R/2*task1_omega^2*sin(omega)*(2*Acct - 2*tem) + task1_R/2*task1_omega^2*sin(omega)*(Acct - tem) - task1_R/2*task1_omega^3*cos(omega)*(Acct - tem)^3; 0];
            
            end
         
                yaw_ref = single(NaN);
                pos_last = pos_ref;
                yaw_last = yaw;
        else
            acc_ref = zeros(3,1,'single');
            vel_ref = zeros(3,1,'single');
            pos_ref = pos_last;
            dot3x = zeros(3,1,'single');
            yaw_ref = yaw_last;
        end

       if norm(vel_ref) < CircleVmax && circleMode <= int8(1)
            circleMode = int8(1); 
            Acct = t;
        elseif circleMode <= int8(2) && t < 20*pi*task1_R/CircleVmax*nCircle + Acct
            circleMode = int8(2);
            Unit = t - Acct;
        elseif circleMode <= int8(3) && Acct - (t - Acct - Unit) >= 0
            circleMode = int8(3);
        else
            circleMode = int8(4);
        end
    else
        %悬停
    
        acc_ref = zeros(3,1,'single');
        vel_ref = zeros(3,1,'single');
        pos_ref = pos_last;
        dot3x = zeros(3,1,'single');
        yaw_ref = yaw_last;
        dotpsi = single(0);
    end
%     circleMode_ = circleMode;
%     Acct_ = Acct;
%     Unit_ = Unit;
else
    %悬停
    acc_ref = zeros(3,1,'single');
    vel_ref = zeros(3,1,'single');
    pos_ref = pos_last;
    dot3x = zeros(3,1,'single');
    yaw_ref = yaw_last;
    dotpsi = single(0);

end
euler_ref = zeros(3,1,'single');
reverse_flag = int8(0);
end

