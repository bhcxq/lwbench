function [pos_ref, vel_ref, acc_ref, euler_ref,dot3x, yaw_ref, dotpsi,reverse_flag] = task1(timestamp, flight_mode,pos, vel, q, LW_OB_CIRCLE_R, LW_OB_CIRCLE_V, LW_OB_CIRCLE_W, LW_OB_TYPE)
LW_OB_TYPE = single(0);%
LW_OB_CIRCLE_R = single(225/180*pi);
LW_OB_CIRCLE_V = single(10);
LW_OB_CIRCLE_W = single(20);
persistent time_start  
if isempty(time_start)
    time_start = timestamp;
end
persistent pos_last  acc_last yaw_last pos_start pos_deacc_start pos_takeoff
if isempty(acc_last)
    acc_last = zeros(3,1,'single');
    pos_last = zeros(3,1,'single');
    pos_start = pos(:);
    pos_deacc_start = pos(:);
    pos_takeoff = pos(:);
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
Takeoff_holdtime = 20;
task1_time = 500;
task1_R = LW_OB_CIRCLE_R;
task1_omega = LW_OB_CIRCLE_W;%复用为匀速时间
LineVmax = LW_OB_CIRCLE_V;
Trj_acc_ppx = [0.000000e+00 0.000000e+00 0.000000e+00 0.000000e+00 6.000000e-02 -1.140000e-02 8.000000e-04 -2.000000e-05 ];
Trj_acc_ppy = [0.0,0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0];
Trj_acc_t = 8.0;
Trj_deacc_ppx = [0.000000e+00 1.000000e+01 0.000000e+00 0.000000e+00 1.000000e-02 -5.400000e-03 6.000000e-04 -2.000000e-05];
Trj_deacc_ppy = [0.0,0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0];
Trj_deacc_t = 10.0;

if flight_mode ~= FlightMode.OFFBOARD
    time_start = timestamp;

    lineMode = int8(0);
    Acct = single(0);
    Unit = single(0);
    pos_start = pos(:);
    pos_takeoff = pos(:);
 
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
    elseif timestamp <= time_start + Takeoff_holdtime + Takeoff_time
        %起飞之后保持,调整偏航角
        t = timestamp - time_start -Takeoff_time;
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
        %    pos_start = single([0; 0; -3]);
    elseif timestamp <= time_start + Takeoff_holdtime +task1_time + Takeoff_time
        %task1
        t = timestamp - time_start - Takeoff_holdtime - Takeoff_time;
  
         if lineMode <= int8(1) %加速
            tmp = double(t);
            px = poly_val(Trj_acc_ppx,tmp,0);
            py = poly_val(Trj_acc_ppy,tmp,0);
            vx = poly_val(Trj_acc_ppx,tmp,1);
            vy = poly_val(Trj_acc_ppy,tmp,1);
            ax = poly_val(Trj_acc_ppx,tmp,2);
            ay = poly_val(Trj_acc_ppy,tmp,2);
            jx = poly_val(Trj_acc_ppx,tmp,3);
            jy = poly_val(Trj_acc_ppy,tmp,3);

            pos_ref = pos_start + single(Rbe_psi'*[px; py; 0]);
            vel_ref = single(Rbe_psi'*[vx; vy; 0]);
            acc_ref = single(Rbe_psi'*[ax; ay; 0]);
            dot3x = single(Rbe_psi'*[jx; jy; 0]);
         
            yaw_ref = single(NaN);
            pos_last = pos_ref;
            pos_deacc_start = pos_ref;
            yaw_last = yaw;
        elseif lineMode <= int8(2) %匀速,保持加速结束时刻的速度
            tmp = double(Acct);
            px = poly_val(Trj_acc_ppx,tmp,0);
            py = poly_val(Trj_acc_ppy,tmp,0);
            vx = poly_val(Trj_acc_ppx,tmp,1);
            vy = poly_val(Trj_acc_ppy,tmp,1);
            tmp = double((t - Acct));
            px = px + vx*tmp;
            py = py+ vy*tmp;
            ax = 0;
            ay = 0;
            jx = 0;
            jy = 0;

            pos_ref = pos_start + single(Rbe_psi'*[px; py; 0]);
            vel_ref = single(Rbe_psi'*[vx; vy; 0]);
            acc_ref = single(Rbe_psi'*[ax; ay; 0]);
            dot3x = single(Rbe_psi'*[jx; jy; 0]);
         
            yaw_ref = single(NaN);
            pos_last = pos_ref;
            pos_deacc_start = pos_ref;
            yaw_last = yaw;
         elseif lineMode <= int8(3) %减速
             tmp = double((t -Unit - Acct));

             px = poly_val(Trj_deacc_ppx,tmp,0);
             py = poly_val(Trj_deacc_ppy,tmp,0);
             vx = poly_val(Trj_deacc_ppx,tmp,1);
             vy = poly_val(Trj_deacc_ppy,tmp,1);
             ax = poly_val(Trj_deacc_ppx,tmp,2);
             ay = poly_val(Trj_deacc_ppy,tmp,2);
             jx = poly_val(Trj_deacc_ppx,tmp,3);
             jy = poly_val(Trj_deacc_ppy,tmp,3);

             pos_ref = pos_deacc_start + single(Rbe_psi'*[px; py; 0]);
             vel_ref = single(Rbe_psi'*[vx; vy; 0]);
             acc_ref = single(Rbe_psi'*[ax; ay; 0]);
             dot3x = single(Rbe_psi'*[jx; jy; 0]);

             yaw_ref = single(NaN);
             pos_last = pos_ref;
             yaw_last = yaw;
        elseif lineMode <= int8(4) %匀速,保持加速结束时刻的速度
            pos_ref = pos_last;
            vel_ref = single(Rbe_psi'*[0; 0; 0]);
            acc_ref = single(Rbe_psi'*[0; 0; 0]);
            dot3x = single(Rbe_psi'*[0; 0; 0]);

            yaw_ref = single(NaN);
            pos_last = [pos(1:2);pos_ref(3)];
            pos_deacc_start = pos_ref;
            yaw_last = yaw;
        else
            acc_ref = zeros(3,1,'single');
            vel_ref = zeros(3,1,'single');
            pos_ref = pos_last;
            dot3x = zeros(3,1,'single');
            yaw_ref = yaw_last;
        end

        if t <= Trj_acc_t && lineMode <= int8(1) %加速
            lineMode = int8(1); 
            Acct = t;
        elseif lineMode <= int8(2) && t <= task1_omega + Acct %匀速
            lineMode = int8(2);
            Unit = t - Acct;
        elseif lineMode <= int8(3) && Trj_deacc_t - (t - Acct - Unit) >= 0 %减速
            lineMode = int8(3);
        else
            lineMode = int8(4);
        end
    else
        acc_ref = zeros(3,1,'single');
        vel_ref = zeros(3,1,'single');
        pos_ref = pos_last;
        dot3x = zeros(3,1,'single');
        yaw_ref = yaw_last;
        dotpsi = single(0);
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
euler_ref = zeros(3,1,'single');
reverse_flag = int8(0);
end



