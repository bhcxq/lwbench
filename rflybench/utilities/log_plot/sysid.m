function sysid(posctrl, attctrl, mixer, imu, battery,params,plot_interval)
    %[att_timestamp, index] = getIndex(attctrl.timestamp * 1e-6, plot_interval);
    log_ac_att_q = [attctrl.log_ac_att_q0 attctrl.log_ac_att_q1 attctrl.log_ac_att_q2 attctrl.log_ac_att_q3];
    
    [itimestamp, i_index] = getIndex(imu.timestamp * 1e-6, plot_interval);
    acc_raw = [imu.accelerometer_m_s20(i_index) imu.accelerometer_m_s21(i_index) imu.accelerometer_m_s22(i_index)];
    [acc_raw, acc_timestamp] = resample(acc_raw, itimestamp, 250, 'spline');
    firf = designfilt('lowpassfir','FilterOrder',150, 'CutoffFrequency',5,'SampleRate',250);
    acc_filted = filtfilt(firf,acc_raw);
    gyro_raw = [imu.gyro_rad0(i_index) imu.gyro_rad1(i_index) imu.gyro_rad2(i_index)];
    [gyro_raw, gtimestamp] = resample(gyro_raw, itimestamp, 250, 'spline');
    gyro_filted = filtfilt(firf,gyro_raw);

    [ptimestamp, index] = getIndex(posctrl.timestamp * 1e-6, plot_interval);
    posctrl_vel = [posctrl.log_pc_local_pos3(index) posctrl.log_pc_local_pos4(index) posctrl.log_pc_local_pos5(index)];
    for i = 1 : length(posctrl_vel)
        q = log_ac_att_q(find(attctrl.timestamp >= ptimestamp(i), 1), :);
        if norm(q) < 0.5
            posctrl_velb(i, 1 : 3) = posctrl_vel(i, :);
        else
            Reb = quat2R(q);
            posctrl_velb(i, 1 : 3) = Reb' * posctrl_vel(i, :)';
            gb(i,1:3) = Reb'*[0; 0; 9.8];
        end
    end
    [posctrl_velb, vtimestamp] = resample(posctrl_velb, ptimestamp, 250, 'spline');
    posctrl_velb_filted = filtfilt(firf,posctrl_velb);
    [gb, vtimestamp] = resample(gb, ptimestamp, 250, 'spline');
    gb_filted = filtfilt(firf,gb);
    mass = params.LW_MASS;
    for i = 1 : length(acc_filted)
        %f(i,1:3) = (acc_filted(i,:) + cross(gyro_filted(i,:),posctrl_velb_filted(i,:)))*mass;
        f(i,1:3) = (acc_filted(i,:))*mass;
    end
    wdotdot = diff(gyro_filted)./diff(gtimestamp);

    [btimestamp, bindex] = getIndex(battery.timestamp * 1e-6, plot_interval);

    voltage = battery.voltage_v(bindex);
    voltage_filter = battery.voltage_filtered_v;
    current = battery.current_a(bindex);
    current_filter = battery.current_filtered_a(bindex);
    discharged_mah = battery.discharged_mah(bindex);

    

    USE_ELEVATOR = 0;
    uavJ = [0.0133, 0, 0; ...
            0, 0.0045, 0; ...
            0, 0, 0.0162];
    torque = uavJ * wdotdot';
    torque = torque';
    [mixer_timestamp, index] = getIndex(mixer.timestamp * 1e-6, plot_interval);
    T1 = mixer.log_m_t_limit0(index);
    T2 = mixer.log_m_t_limit1(index);
    T3 = mixer.log_m_t_limit2(index);
    T4 = mixer.log_m_t_limit3(index);
    T5 = mixer.log_m_t_limit4(index);
    T6 = mixer.log_m_t_limit5(index);
    PWM1 = (mixer.log_m_outpwm0(index) -1000)/1000;
    PWM2 = (mixer.log_m_outpwm1(index) - 1000)/1000;
    PWM3 = (mixer.log_m_outpwm2(index) - 1000)/1000;
    PWM4 = (mixer.log_m_outpwm3(index) - 1000)/1000;
    PWM5 = mixer.log_m_outpwm4(index);
    PWM6 = mixer.log_m_outpwm5(index);
    p1 = -5.47; p2 = 214.1; p3 = 465.6;
    for i = 1:length(PWM1)
        Vf = voltage_filter(find(battery.timestamp >= mixer.timestamp(i), 1));
        thro1(i) = PWM1(i)*Vf;
        thro2(i) = PWM2(i)*Vf;
        thro3(i) = PWM3(i)*Vf;
        thro4(i) = PWM4(i)*Vf;
    end
    Tu1 = p1*thro1.^2 + p2*thro1 + p3;
    Tu2 = p1*thro2.^2 + p2*thro2 + p3;
    Tu3 = p1*thro3.^2 + p2*thro3 + p3;
    Tu4 = p1*thro4.^2 + p2*thro4 + p3;
    Tu5 = T5;
    Tu6 = T6;
    ModelParam_rotorCt = 1.2681e-06; % RS2205 KV2600
    Tu1 = ModelParam_rotorCt.*Tu1.^2;
    Tu2 = ModelParam_rotorCt.*Tu2.^2;
    Tu3 = ModelParam_rotorCt.*Tu3.^2;
    Tu4 = ModelParam_rotorCt.*Tu4.^2;
    
    Va = mixer.log_m_va(index);
    
    %torque_ref = uavJ * wdotdot;

    kappa = 34 * pi / 180;
    eta = 0;
    coseta = cos(eta);
    dx = 0.12;
    dy = 0.12;
    LBS = 0.09;
    LBb = 0.662;
    LBc = 0.15;
    Cl_d = 0.12;
    Cm_d = -0.206;
    Cn_d = 0;
    K1 = 2.237e-08 / 1.345e-06 + dx * sin(eta);
    K2 = dy * coseta * cos(kappa) + K1 * sin(kappa);
    K3 = dy * coseta * cos(kappa) - K1 * sin(kappa);
    K4 = dy * coseta * sin(kappa) + K1 * cos(kappa);
    K5 = dy * coseta * sin(kappa) - K1 * cos(kappa);
    for ii = 1 : length(Va)
        if USE_ELEVATOR < 0.5
            Q = 0;
        else
            Q = 0.5 * double(1.22) * Va(ii) ^ 2 * LBS;
        end
        q = log_ac_att_q(find(attctrl.timestamp * 1e-6 <= mixer_timestamp(ii), 1,'last'), :);
        if norm(q) < 0.1
            euler = [0, 0, 0];
        else
            euler = my_quat2eul(q');
        end
        theta = euler(2);
        alpha = theta + kappa;
        beta = 0;
        
        C_l = 0 + -0.0849 * beta;
        ssCm = [2.341, 0.2294, -3.081, 0.1121, 8.391, -0.2862];
        Cm_linear = [3.587, 0.7512];
        if alpha > -0.237232
            a1 = ssCm(1); b1 = ssCm(2); c1 = ssCm(3);
            a2 = ssCm(4); b2 = ssCm(5); c2 = ssCm(6);
            C_m = a1 * sin(b1 * alpha + c1) + a2 * sin(b2 * alpha + c2);
        else
            p1 = Cm_linear(1); p2 = Cm_linear(2);
            C_m = p1 * alpha + p2;
        end
        
        C_n = 0 + 0 * beta;
        
        dxcoseta = dx * coseta;
        B = [-coseta   -coseta   -coseta  -coseta   0   0;
            -K2       -K3        K2       K3      -Q * LBb * Cl_d Q * LBb * Cl_d;
            dxcoseta  -dxcoseta dxcoseta -dxcoseta Q * LBc * Cm_d Q * LBc * Cm_d;
            -K5        -K4        K5      K4      -Q * LBb * Cn_d Q * LBb * Cn_d];
        b = [0; Q * LBb * C_l; Q * LBc * C_m; Q * LBb * C_n];
        f_tao(ii, :) = B * [T1(ii); T2(ii); T3(ii); T4(ii); T5(ii); T6(ii)] + b;
        f_tao_u(ii, :) = B * [Tu1(ii); Tu2(ii); Tu3(ii); Tu4(ii); Tu5(ii); Tu6(ii)] + b;
    end
    [f_tao, mtimestamp] = resample(f_tao, mixer_timestamp, 250, 'spline');
    f_tao_filted = filtfilt(firf,f_tao);
    [f_tao_u, mtimestamp] = resample(f_tao_u, mixer_timestamp, 250, 'spline');
    f_tao_u_filted = filtfilt(firf,f_tao_u);

figure
tiledlayout(3, 1, 'TileSpacing', 'Compact')

nexttile(1)
plot(acc_timestamp,f(:,1),'r-')
legend('Real')
ylabel('f_x')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])

nexttile(2)
plot(acc_timestamp,f(:,2),'r-')
legend('Real')  
ylabel('f_y')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])

nexttile(3)
plot(mtimestamp,f_tao(:,1),'g--')
hold on
plot(mtimestamp,f_tao_u(:,1),'k--')
plot(acc_timestamp,f(:,3),'r-')
legend('Est','EstU','Real')
xlabel('t(s)');ylabel('f_z')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

figure
tiledlayout(3, 1, 'TileSpacing', 'Compact')

nexttile(1)
plot(mtimestamp,f_tao_filted(:,2),'g--')
hold on
plot(mtimestamp,f_tao_u_filted(:,2),'k--')
plot(gtimestamp(1:end-1),torque(:,1),'r-')
legend('Est','EstU','Real')
ylabel('m_x')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])

nexttile(2)
plot(mtimestamp,f_tao_filted(:,3),'g--')
hold on
plot(mtimestamp,f_tao_u_filted(:,3),'k--')
plot(gtimestamp(1:end-1),torque(:,2),'r-')
ylabel('m_y')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])

nexttile(3)
plot(mtimestamp,f_tao_filted(:,4),'g--')
hold on
plot(mtimestamp,f_tao_u_filted(:,4),'k--')
plot(gtimestamp(1:end-1),torque(:,3),'r-')
xlabel('t(s)');ylabel('m_z')
axis([plot_interval.startTime, plot_interval.endTime, -inf, inf])
hold off

end