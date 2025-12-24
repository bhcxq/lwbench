function [pos_ref, vel_ref, acc_ref, euler_ref,dot3x, yaw_ref, dotpsi,reverse_flag] = task5(timestamp, flight_mode,pos, vel, q, LW_OB_CIRCLE_R, LW_OB_CIRCLE_V, LW_OB_CIRCLE_W, LW_OB_TYPE)
LW_OB_TYPE = single(0);
LW_OB_CIRCLE_R = single(45/180*pi);
LW_OB_CIRCLE_V = single(15);
LW_OB_CIRCLE_W = single(60);
task1_omega = LW_OB_CIRCLE_W;
CircleVmax = LW_OB_CIRCLE_V;
nCircle = 12;
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
persistent lineMode Acct Unit
if isempty(lineMode)
    lineMode = int8(0);
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

Takeoff_time = 0;
Takeoff_holdtime = 100; %100
task1_time = 100000;
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
        if t <= 10
            acc_ref = zeros(3,1,'single');
            vel_ref = single([0;0;-1]);
            pos_ref = pos_takeoff + single([0;0;-t]);
            dot3x = zeros(3,1,'single');
            yaw_ref = yaw_last;
            dotpsi = single(0);
            pos_start = pos_ref;
        else
            pos_return = pos_start;
            t = t-10;
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
  
         if lineMode <= int8(1) %小幅度高频率姿态响应
             if t < 30
                 pos_ref = pos_start + single(Rbe_psi'*[0.5*sin(3*t); 0; 0]);
                 vel_ref = single(Rbe_psi'*[1.5*cos(3*t); 0; 0]);
                 acc_ref = single(Rbe_psi'*[0; 0; 0]);
                 dot3x = single(Rbe_psi'*[0; 0; 0]);

                 yaw_ref = yaw_last;
                 pos_last = pos_ref;
                 pos_deacc_start = pos_ref;
                 reverse_flag = int8(0);
             else
                 acc_ref = zeros(3,1,'single');
                 vel_ref = zeros(3,1,'single');
                 pos_ref = pos_last;
                 pos_start = pos_last;
                 dot3x = zeros(3,1,'single');
                 yaw_ref = yaw_last;
                 reverse_flag = int8(0);
             end
        elseif lineMode <= int8(2) %小幅度高频率姿态响应
            if t-Acct < 30
                pos_ref = pos_deacc_start + single(Rbe_psi'*[0; 0.5*cos(3*(t-Acct)); 0]);
                vel_ref = single(Rbe_psi'*[0; -1.5*sin(3*(t-Acct)); 0]);
                acc_ref = single(Rbe_psi'*[0; 0; 0]);
                dot3x = single(Rbe_psi'*[0; 0; 0]);

                yaw_ref = yaw_last;
                pos_last = pos_ref;
                pos_start = pos_ref;
                reverse_flag = int8(0);
            else
                acc_ref = zeros(3,1,'single');
                vel_ref = zeros(3,1,'single');
                pos_ref = pos_last;
                pos_start = pos_last;
                dot3x = zeros(3,1,'single');
                yaw_ref = yaw_last;
                reverse_flag = int8(0);
            end
        elseif lineMode <= int8(3) %小幅度高频率高度响应
            if t-Unit < 10
                pos_ref = pos_start + single(Rbe_psi'*[0; 0; -(t-Unit)]);
                vel_ref = single(Rbe_psi'*[0; 0; -1]);
                acc_ref = single(Rbe_psi'*[0; 0; 0]);
                dot3x = single(Rbe_psi'*[0; 0; 0]);

                yaw_ref = yaw_last;
                pos_last = pos_ref;
                pos_deacc_start = pos_ref;
                reverse_flag = int8(0);
            else
                acc_ref = zeros(3,1,'single');
                vel_ref = zeros(3,1,'single');
                pos_ref = pos_last;
                pos_start = pos_last;
                dot3x = zeros(3,1,'single');
                yaw_ref = yaw_last + single(wrap_pi(5/180*pi)*sin(3*(t-Unit)));
                reverse_flag = int8(0);
            end
        elseif lineMode <= int8(4) %中幅度姿态变化
            if t-Acct < 30
                pos_ref = pos_start + single(Rbe_psi'*[6*(t-Acct); 0; 0]);
                vel_ref = single(Rbe_psi'*[6; 0; 0]);
                acc_ref = single(Rbe_psi'*[0; 0; 0]);
                dot3x = single(Rbe_psi'*[0; 0; 0]);

                yaw_ref = yaw_last;
                pos_last = pos_ref;
                pos_deacc_start = pos_ref;
                reverse_flag = int8(0);
            else
                acc_ref = zeros(3,1,'single');
                vel_ref = zeros(3,1,'single');
                pos_ref = pos_last;
                pos_start = pos_last;
                dot3x = zeros(3,1,'single');
                yaw_ref = yaw_last;
                reverse_flag = int8(0);
            end
         elseif lineMode <= int8(5) %小幅度高频率姿态响应
             if t-Unit < 30
                 pos_ref = pos_start + single(Rbe_psi'*[10*(t-Unit) + 0.2*sin(3*t); 0; 0]);
                 vel_ref = single(Rbe_psi'*[10 + 0.6*cos(3*(t-Unit)); 0 ; 0]);
                 acc_ref = single(Rbe_psi'*[0; 0; 0]);
                 dot3x = single(Rbe_psi'*[0; 0; 0]);

                 yaw_ref = yaw_last;
                 pos_last = pos_ref;
                 pos_deacc_start = pos_ref;
                 reverse_flag = int8(0);
             else
                 acc_ref = zeros(3,1,'single');
                 vel_ref = zeros(3,1,'single');
                 pos_ref = pos_last;
                 pos_start = pos_last;
                 dot3x = zeros(3,1,'single');
                 yaw_ref = yaw_last;
                 reverse_flag = int8(0);
             end
        elseif lineMode <= int8(6) %直线加速
             if t-Acct < 12
                 pos_ref = pos_start + single(Rbe_psi'*[0.5*(t-Acct)^2; 0; 0]);
                 vel_ref = single(Rbe_psi'*[1*(t-Acct); 0 ; 0]);
                 acc_ref = single(Rbe_psi'*[1; 0; 0]);
                 dot3x = single(Rbe_psi'*[0; 0; 0]);

                 yaw_ref = yaw_last;
                 pos_last = pos_ref;
                 pos_deacc_start = pos_ref;
                 reverse_flag = int8(0);
             elseif t-Acct < 24
                 t = t - 12;
                 pos_ref = pos_deacc_start + single(Rbe_psi'*[12*(t-Acct)-0.5*(t-Acct)^2; 0; 0]);
                 vel_ref = single(Rbe_psi'*[12-1*(t-Acct); 0 ; 0]);
                 acc_ref = single(Rbe_psi'*[-1; 0; 0]);
                 dot3x = single(Rbe_psi'*[0; 0; 0]);

                 yaw_ref = yaw_last;
                 pos_last = pos_ref;
                 pos_start = pos_ref;
                 reverse_flag = int8(0);
             else
                 acc_ref = zeros(3,1,'single');
                 vel_ref = zeros(3,1,'single');
                 pos_ref = pos_last;
                 pos_start = pos_last;
                 dot3x = zeros(3,1,'single');
                 yaw_ref = yaw_last;
                 reverse_flag = int8(0);
             end
         elseif lineMode <= int8(7) %加速
             LW_OB_TYPE = single(1);%
             LW_OB_CIRCLE_R = single(50);%10m/s,30m;15m/s,50m
             LW_OB_CIRCLE_V = single(10);
             LW_OB_CIRCLE_W = single(0.03);%0.03
             task1_R = LW_OB_CIRCLE_R;
             task1_omega = LW_OB_CIRCLE_W;
             CircleVmax = LW_OB_CIRCLE_V;
             t = t - Unit;
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
         elseif lineMode <= int8(8) %匀速
             LW_OB_TYPE = single(1);%
             LW_OB_CIRCLE_R = single(50);%10m/s,30m;15m/s,50m
             LW_OB_CIRCLE_V = single(10);
             LW_OB_CIRCLE_W = single(0.03);%0.03
             task1_R = LW_OB_CIRCLE_R;
             task1_omega = LW_OB_CIRCLE_W;
             CircleVmax = LW_OB_CIRCLE_V;
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
        elseif lineMode <= int8(9) %减速
            LW_OB_TYPE = single(1);%
            LW_OB_CIRCLE_R = single(50);%10m/s,30m;15m/s,50m
            LW_OB_CIRCLE_V = single(10);
            LW_OB_CIRCLE_W = single(0.03);%0.03
            task1_R = LW_OB_CIRCLE_R;
            task1_omega = LW_OB_CIRCLE_W;
            CircleVmax = LW_OB_CIRCLE_V;
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
            reverse_flag = int8(0);
        end

        time1 = 40;
        if t <= time1 && lineMode <= int8(1) %俯仰高频
            lineMode = int8(1);
            Acct = t;
        elseif t <= 2*time1 && lineMode <= int8(2) %滚转高频
            lineMode = int8(2);
            Unit = t;
        elseif t <= 3*time1 && lineMode <= int8(3) %高度阶跃
            lineMode = int8(3);
            Acct = t;
        elseif t <= 4*time1 && lineMode <= int8(4) %俯仰阶跃
            lineMode = int8(4);
            Unit = t;
        elseif t <= 5*time1 && lineMode <= int8(5) %巡航俯仰高频
            lineMode = int8(5);
            Acct = t;
        elseif t <= 6*time1  && lineMode <= int8(6) %直线加减速
            lineMode = int8(6);
            Unit = t;
        elseif norm(vel_ref) < CircleVmax && lineMode <= int8(7)
            lineMode = int8(7); 
            Acct = t;
        elseif lineMode <= int8(8) && t < 2*pi*task1_R/CircleVmax*nCircle + Acct
            lineMode = int8(8);
            Unit = t - Acct;
        elseif lineMode <= int8(9) && Acct - (t - Acct - Unit) >= 0
            lineMode = int8(9);
        else
            lineMode = int8(10);
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
reverse_flag = int8(0);
end




