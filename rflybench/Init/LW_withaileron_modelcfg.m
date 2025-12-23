%% startVars.m - Initialize variables
% This script initializes variables and buses required for the model to
% work.
% Author: wsh.
% Date: 2023/05/05
% Email: wsh_buaa@buaa.edu.cn
lwVariantDefinition;
load(fullfile(codertarget.pixhawk.internal.getSpPkgRootDir, '+codertarget', '+pixhawk', '+CMAKE_Utils', 'CmakeInfo.mat'));

%% 将自定义的msg文件添加到源码中
msg_name = {'costom_lw_attctrl.msg', ...
            'costom_lw_manual_ctrl_in.msg', ...
            'costom_lw_mixer.msg', ...
            'costom_lw_navigator.msg', ...
            'costom_lw_posctrl.msg', ...
            'costom_lw_statemachine.msg'};
insert_mark = 'set(msg_files'; %在这个字符串的后一行插入
msg_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '.\msg\', msg_name);
msg_cmakelist_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '.\msg\', 'CMakeLists.txt');
fclose('all');
for i = 1 : length(msg_path)
    my_msg_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion], char(msg_name(i)));
    if ~exist(string(msg_path(i)), 'file')
        [status,message,messageId] = copyfile(my_msg_path, char(msg_path(i)));
        if status && isempty(message) && isempty(messageId)
                disp(['Copy ',char(msg_name(i)),' to ', char(msg_path(i))])
        end
        editCmakeLists(msg_cmakelist_path, msg_name(i), insert_mark);
    else
        msg_info = dir(string(msg_path(i)));
        msg_date = msg_info.datenum;
        my_msg_info = dir(my_msg_path);
        my_msg_date = my_msg_info.datenum;
        if msg_date < my_msg_date
            copyfile(my_msg_path, string(msg_path(i)));
            editCmakeLists(msg_cmakelist_path, msg_name(i), insert_mark);
        end
    end
end
%% 设置模型参数
if ~bdIsLoaded(ModelConfigure_Name)
    open_system(ModelConfigure_Name);
else
    disp([ModelConfigure_Name ' is already open.']);
end

activeConfigObj = getActiveConfigSet(ModelConfigure_Name);
set_param(activeConfigObj, 'SolverType', 'Fixed-step');
set_param(activeConfigObj, 'Solver', 'ode4');

SampleTime = 0.001;
if strcmp(ModelConfigure_Type, 'SIM')
    set_param(activeConfigObj, 'FixedStep', num2str(SampleTime));
    if SEND_TO_UNREAL
        set_param(activeConfigObj, 'StopTime', 'SIM_TIME');
        system(['tasklist|find /i "RflySim3D.exe" || start ',Px4PSP_CmakeInfo.Px4_Base_Dir, '\RflySim3D\RflySim3D.exe']);
        
    else
        set_param(activeConfigObj, 'StopTime', 'SIM_TIME');
    end
    Output_cycle = 1;
    StatesUpdate_cycle = StatesUpdate / SampleTime;
    AttCtrl_cycle = ATTCTRL / SampleTime;
    Mixer_cycle = MIXER / SampleTime;
    PosCtrl_cycle = POSCTRL / SampleTime;
    Navigator_cycle = NAVIGATOR / SampleTime;
    StateMachine_cycle = STATEMACHINE / SampleTime;
    RCReceive_cycle = RCRECEIVE / SampleTime;
    if ~SEND_TO_UNREAL
        set_param([ModelConfigure_Name, '/Output/OutputSelect/Sim/Lifting Body Airframe/To Unreal'], 'commented', 'on');
    else
        set_param([ModelConfigure_Name, '/Output/OutputSelect/Sim/Lifting Body Airframe/To Unreal'], 'commented', 'off');
    end
    if ENABLE_PACING
        set_param(ModelConfigure_Name, 'EnablePacing', 'on')
        %set_param(ModelConfigure_Name, 'PacingRate', value)
    else
        set_param(ModelConfigure_Name, 'EnablePacing', 'off')
    end
else
    set_param(activeConfigObj, 'FixedStep', num2str(MAX_T));
    set_param(activeConfigObj, 'StopTime', 'inf');
    Output_cycle = 1;
    StatesUpdate_cycle = 1;
    AttCtrl_cycle = 1;
    Mixer_cycle = 1;
    PosCtrl_cycle = 1;
    Navigator_cycle = 1;
    StateMachine_cycle = 1;
    RCReceive_cycle = 4;
end

if strcmp(ModelConfigure_Type, 'SIM')
    
    set_param(activeConfigObj, 'HardwareBoard', 'None');
    set_param(activeConfigObj, 'DefaultParameterBehavior', 'Tunable');
    %增加共享内存区，保存仿真模型的输出状态
    if getSimulinkBlockHandle([ModelConfigure_Name, '/vehicle_local_position']) < 0
        %get_param([ModelConfigure_Name,'/vehicle_local_position'],'Position')
        add_block('simulink/Signal Routing/Data Store Memory', [ModelConfigure_Name, '/vehicle_local_position']);
        set_param([ModelConfigure_Name, '/vehicle_local_position'], 'Position', [-290 1370 -88 1420]) %[left top right bottom]
        set_param([ModelConfigure_Name, '/vehicle_local_position'], ...
            'DataStoreName', 'vehicle_local_position', ...
            'OutDataTypeStr', 'single', ...
            'Dimensions', '19', ...
            'SignalType', 'real', ...
            'ShareAcrossModelInstances', 'on')
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/vehicle_global_position']) < 0
        add_block('simulink/Signal Routing/Data Store Memory', [ModelConfigure_Name, '/vehicle_global_position']);
        set_param([ModelConfigure_Name, '/vehicle_global_position'], 'Position', [-290 1470 -88 1520]) %[left top right bottom]
        set_param([ModelConfigure_Name, '/vehicle_global_position'], ...
            'DataStoreName', 'vehicle_global_position', ...
            'OutDataTypeStr', 'single', ...
            'Dimensions', '15', ...
            'SignalType', 'real', ...
            'ShareAcrossModelInstances', 'on')
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/vehicle_attitude']) < 0
        add_block('simulink/Signal Routing/Data Store Memory', [ModelConfigure_Name, '/vehicle_attitude']);
        set_param([ModelConfigure_Name, '/vehicle_attitude'], 'Position', [-75 1370 127 1420]) %[left top right bottom]
        set_param([ModelConfigure_Name, '/vehicle_attitude'], ...
            'DataStoreName', 'vehicle_attitude', ...
            'OutDataTypeStr', 'single', ...
            'Dimensions', '24', ...
            'SignalType', 'real', ...
            'ShareAcrossModelInstances', 'on')
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/vehicle_airspeed']) < 0
        add_block('simulink/Signal Routing/Data Store Memory', [ModelConfigure_Name, '/vehicle_airspeed']);
        set_param([ModelConfigure_Name, '/vehicle_airspeed'], 'Position', [140 1370 342 1420]) %[left top right bottom]
        set_param([ModelConfigure_Name, '/vehicle_airspeed'], ...
            'DataStoreName', 'vehicle_airspeed', ...
            'OutDataTypeStr', 'single', ...
            'Dimensions', '8', ...
            'SignalType', 'real', ...
            'ShareAcrossModelInstances', 'on')
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/sensor_imu']) < 0
        add_block('simulink/Signal Routing/Data Store Memory', [ModelConfigure_Name, '/sensor_imu']);
        set_param([ModelConfigure_Name, '/sensor_imu'], 'Position', [-75 1470 127 1520]) %[left top right bottom]
        set_param([ModelConfigure_Name, '/sensor_imu'], ...
            'DataStoreName', 'sensor_imu', ...
            'OutDataTypeStr', 'single', ...
            'Dimensions', '6', ...
            'SignalType', 'real', ...
            'ShareAcrossModelInstances', 'on')
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/mixer_output']) < 0
        add_block('simulink/Signal Routing/Data Store Memory', [ModelConfigure_Name, '/mixer_output']);
        set_param([ModelConfigure_Name, '/mixer_output'], 'Position', [140 1470 342 1520]) %[left top right bottom]
        set_param([ModelConfigure_Name, '/mixer_output'], ...
            'DataStoreName', 'mixer_output', ...
            'OutDataTypeStr', 'single', ...
            'Dimensions', '7', ...
            'SignalType', 'real', ...
            'ShareAcrossModelInstances', 'on')
    end
    
else
    set_param(activeConfigObj, 'HardwareBoard', 'Pixhawk PX4');
    set_param(activeConfigObj, 'DefaultParameterBehavior', 'Inlined');
    set_param(activeConfigObj, 'MaxStackSize', '128');
    %删除共享内存模块
    if getSimulinkBlockHandle([ModelConfigure_Name, '/vehicle_local_position']) > 0
        delete_block([ModelConfigure_Name, '/vehicle_local_position']);
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/vehicle_global_position']) > 0
        delete_block([ModelConfigure_Name, '/vehicle_global_position']);
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/vehicle_attitude']) > 0
        delete_block([ModelConfigure_Name, '/vehicle_attitude']);
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/vehicle_airspeed']) > 0
        delete_block([ModelConfigure_Name, '/vehicle_airspeed']);
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/sensor_imu']) > 0
        delete_block([ModelConfigure_Name, '/sensor_imu']);
    end
    if getSimulinkBlockHandle([ModelConfigure_Name, '/mixer_output']) > 0
        delete_block([ModelConfigure_Name, '/mixer_output']);
    end
    %参数检查
    if strcmp(ModelConfigure_Type, 'HIL') || strcmp(ModelConfigure_Type, 'HIL-FPGA')
        unusedVars = Simulink.findVars(ModelConfigure_Name,'FindUsedVars','off','SourceType','base workspace','Regexp','on','Name','LW_');
        if ~isempty(unusedVars)
            warning('The following variables are not used!')
            for i = 1:length(unusedVars)
                disp(unusedVars(i).Name);
            end
        end
    end
    %升力翼专用角度校正
%     if USE_MOTOR == int8(2) || USE_MOTOR == int8(1)
%         rotation_h_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\src\lib\conversion\rotation.h');
%         rotation_cpp_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\src\lib\conversion\rotation.cpp');
%         if strcmp(ModelConfigure_Type, 'FLY')
%             my_rotation_h_path = fullfile(proj.RootFolder, '\Init\rotation\',ModelConfigure_FirmwareVersion,'\rotation_34.h');
%             my_rotation_cpp_path = fullfile(proj.RootFolder, '\Init\rotation\',ModelConfigure_FirmwareVersion,'\rotation_34.cpp');
%             copyfile(my_rotation_h_path, rotation_h_path);
%             copyfile(my_rotation_cpp_path, rotation_cpp_path);
%             disp('rotation.cpp with 34 degree ratation is replaced!');
%         else
%             my_rotation_h_path = fullfile(proj.RootFolder, ['\Init\rotation\',ModelConfigure_FirmwareVersion,'\rotation.h']);
%             my_rotation_cpp_path = fullfile(proj.RootFolder, ['\Init\rotation\',ModelConfigure_FirmwareVersion,'\rotation.cpp']);
%             copyfile(my_rotation_h_path, rotation_h_path);
%             copyfile(my_rotation_cpp_path, rotation_cpp_path);
%         end
%     end
    %HIL-FPGA 选择外置传感器
%     sensor_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\boards\px4\fmu-v5\init\rc.board_sensors');
%     if strcmp(ModelConfigure_Type, 'HIL-FPGA')
%         my_sensor_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc_ex.board_sensors']);
%         copyfile(my_sensor_path, sensor_path);
%         disp('The sensors are set to exteral sources from FPGA.');
%     else
%         my_sensor_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc_in.board_sensors']);
%         copyfile(my_sensor_path, sensor_path);
%         disp('The sensors are set to internal sources on pixhawk.');
%     end
    %数据记录
    if strcmp(ModelConfigure_FirmwareVersion, 'V1.8.2')
        logger_cpp_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\src\modules\logger\logger.cpp');
        my_logger_cpp_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\logger.cpp']);
        copyfile(my_logger_cpp_path, logger_cpp_path);
        disp('logger file is replaced!');
    elseif strcmp(ModelConfigure_FirmwareVersion, 'V1.12.3')
        logger_cpp_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\src\modules\logger\logged_topics.cpp');
        my_logger_cpp_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\logged_topics.cpp']);
        copyfile(my_logger_cpp_path, logger_cpp_path);
        disp('logger file is replaced!');
    elseif strcmp(ModelConfigure_FirmwareVersion, 'V1.13.3')
        logger_cpp_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\src\modules\logger\logged_topics.cpp');
        my_logger_cpp_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\logged_topics.cpp']);
        copyfile(my_logger_cpp_path, logger_cpp_path);
        disp('logger file is replaced!');
    end
    
    %启动文件
    if strcmp(ModelConfigure_FirmwareVersion, 'V1.12.3')
        rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rcS');
        my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rcS']);
        copyfile(my_rc_path, rc_path);
        %小升力翼
        rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rc.mc_apps');
        my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc.mc_apps']);
        copyfile(my_rc_path, rc_path);
        rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rc.mc_defaults');
        my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc.mc_defaults']);
        copyfile(my_rc_path, rc_path);
        %大升力翼
        rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rc.vtol_apps');
        my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc.vtol_apps']);
        copyfile(my_rc_path, rc_path);
        rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rc.vtol_defaults');
        my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc.vtol_defaults']);
        copyfile(my_rc_path, rc_path);
        disp('rcS, rc.mc_apps, rc.mc_defaults, rc.vtol_apps, rc.vtol_defaults are replaced!');
     % elseif strcmp(ModelConfigure_FirmwareVersion, 'V1.13.3')
     %    rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rcS');
     %    my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rcS']);
     %    copyfile(my_rc_path, rc_path);
     %    %小升力翼
     %    rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rc.mc_apps');
     %    my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc.mc_apps']);
     %    copyfile(my_rc_path, rc_path);
     %    rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rc.mc_defaults');
     %    my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc.mc_defaults']);
     %    copyfile(my_rc_path, rc_path);
     %    %大升力翼
     %    rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rc.vtol_apps');
     %    my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc.vtol_apps']);
     %    copyfile(my_rc_path, rc_path);
     %    rc_path = fullfile(Px4PSP_CmakeInfo.Px4_Firmware_Dir, '\ROMFS\px4fmu_common\init.d\rc.vtol_defaults');
     %    my_rc_path = fullfile(proj.RootFolder, ['\Init\msg\',ModelConfigure_FirmwareVersion,'\rc.vtol_defaults']);
     %    copyfile(my_rc_path, rc_path);
     %    disp('rcS, rc.mc_apps, rc.mc_defaults, rc.vtol_apps, rc.vtol_defaults are replaced!');
    end
    
    %删除xml文件
    if DELETE_PARAMS_XML
        xml_path = fullfile(Px4PSP_CmakeInfo.Px4_Build_Dir, 'parameters.xml');
        if exist(xml_path, 'file')
            delete(xml_path);
        end
        disp('parameters.xml has been deleted!');
    end
end

function editCmakeLists(msg_cmakelist_path, msg_name, insert_mark)
%插入字符串：将原来的文件内容复制一份，将插入行之前和插入行之后原样写入文件
msg_context = importdata(msg_cmakelist_path);
msg_context_len = length(msg_context);
editFile = true;
% 
for i = 1 : msg_context_len
    if  contains(char(msg_context(i)), char(msg_name))
        editFile = false;
        break;
    end
end
if editFile
    fileID = fopen(msg_cmakelist_path);
    empty_line = [];
    lineNum = 0;
    %读取空行
    while 1
        lineNum = lineNum + 1;
        tline = fgetl(fileID);
        if isempty(tline)
            empty_line = [empty_line, lineNum];
        end
        if ~ischar(tline)
            break;
        end
    end
    fclose(fileID);
    %寻找插入位置
    for i = 1 : msg_context_len
        if  strncmpi(msg_context(i), insert_mark, length(insert_mark)) 
            lineNum = i;
            break;
        end
    end
    %new_msg_cmakelist_path = 'CMakeLists1.txt';
    if exist(msg_cmakelist_path, 'file')
        delete(msg_cmakelist_path);
    end
    fileID = fopen(msg_cmakelist_path, 'w');
    formatSpec = '%s\n';
    writeLine = 1;
    for i = 1 : lineNum
        if find(empty_line == writeLine)
            fprintf(fileID, '\n');
            writeLine = writeLine + 1;
        end
        fprintf(fileID, formatSpec, char(msg_context(i)));
        writeLine = writeLine + 1;
    end
    fprintf(fileID, formatSpec, ("    " + char(msg_name)));
    writeLine = writeLine + 1;
    for i = lineNum + 1 : msg_context_len
        if find(empty_line == writeLine - 1)
            fprintf(fileID, '\n');
            writeLine = writeLine + 1;
        end
        fprintf(fileID, formatSpec, char(msg_context(i)));
        writeLine = writeLine + 1;
    end
    fclose(fileID);
end
end
