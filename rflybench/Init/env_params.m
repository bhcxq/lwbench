%% env_params.m - environment parameters
% Define the required parameters for environment and sensor models 

% Author: wsh.
% Date: 2021/10/18
% Email: wsh_buaa@buaa.edu.cn

ModelFailEnable = boolean(0);
ModelParam_uavType = int8(3); %这里是四旋翼X型，具体定义见文档"机型定义文档.docx"

%% 环境模型中的参数

ModelParam_envGravityAcc = 9.8;  % Gravity acceleration(m/s^2)
ModelParam_envRadius = 6378.137; % Earth radius (m)
ModelParam_envLongitude = 116.259368300000;
ModelParam_envLatitude = 40.1540302;
ModelParam_GPSLatLong = [ModelParam_envLatitude ModelParam_envLongitude];  %Latitude and longitude
ModelParam_envAltitude = -41.5260009765625;  %Reference height, down is positive
ModelParam_use_CoesaAtmosphereModel_temperature = true;
ModelParam_temperature = 25;% celsius
ModelParam_use_CoesaAtmosphereModel_density = false;
ModelParam_LBRho = 1.22; %空气密度

%% 风干扰模型参数
ModelFailWind_isEnable = boolean(1);
ModelFailWind_isConstWind = boolean(0);
ModelFailWind_isGustWind = boolean(0);
ModelFailWind_isTurbWind = boolean(0);
ModelFailWind_isSheerWind = boolean(0);
ModelFailWind_GustWindAmplitude = [-0 -5 0];
ModelFailWind_GustStartTime = 15;
ModelFailWind_TurbWindFreq = 0;

ModelFailWind_ConstWindX = 0;
ModelFailWind_ConstWindY = 0;
ModelFailWind_ConstWindZ = 0;
if ModelFailWind_isEnable
    disp('%%%%%%%  Wind disturbance is added. %%%%%')
    if ModelFailWind_isConstWind
       fprintf('Const wind is added, [windX, windY, windZ]=[%.2f, %.2f, %.2f]\n',ModelFailWind_ConstWindX,ModelFailWind_ConstWindY, ModelFailWind_ConstWindZ); 
    end
    if ModelFailWind_isGustWind
        fprintf('Gust wind is added. Gust Wind Amplitude :[%.2f,%.2f,%.2f],start at:%.2f\n',...
            ModelFailWind_GustWindAmplitude(1),ModelFailWind_GustWindAmplitude(2),ModelFailWind_GustWindAmplitude(3),ModelFailWind_GustStartTime)
    end
    if ModelFailWind_isTurbWind
        fprintf('Turb wind is added.\n')
    end
    if ModelFailWind_isSheerWind
        fprintf('Sheer wind is added.\n')
    end
end

%% 5.Sensor Model
%状态重置
ModelReset_time = [40 ]; %s
ModelReset_Euler = [0 0 00;
                    0 0 -20]*pi/180; %rad
ModelReset_Pos = [0.0 0.0 0.0;
                  0.8 0 -0.4]*0; %m

NoiseGain = 0.5;
% F and M
if strcmp(ModelConfigure_Type, 'SIM')
    FMScale = 0.0;
else
    FMScale = 0.0;
end
ModelParam_noiseFNaX = 0.05;
ModelParam_noiseFNaY = 0.05;
ModelParam_noiseFNaZ = 0.1;
ModelParam_noiseFNa = [ModelParam_noiseFNaX, ModelParam_noiseFNaY, ModelParam_noiseFNaZ]'*FMScale;
ModelParam_noiseFNaSeed = [1516,1617,1718];
ModelParam_noiseFBaX = 0.0001;
ModelParam_noiseFBaY = 0.0001;
ModelParam_noiseFBaZ = 0.0001;
ModelParam_noiseFBa = [ModelParam_noiseFBaX, ModelParam_noiseFBaY, ModelParam_noiseFBaZ]'*FMScale;
ModelParam_noiseFBaSeed = [1819,1920,2021];
ModelParam_noiseMNaX = 0.01;
ModelParam_noiseMNaY = 0.01;
ModelParam_noiseMNaZ = 0.02;
ModelParam_noiseMNa = [ModelParam_noiseMNaX, ModelParam_noiseMNaY, ModelParam_noiseMNaZ]'*FMScale;
ModelParam_noiseMNaSeed = [2122,2223,2324];
ModelParam_noiseMBaX = 0.00001;
ModelParam_noiseMBaY = 0.00001;
ModelParam_noiseMBaZ = 0.00001;
ModelParam_noiseMBa = [ModelParam_noiseMBaX, ModelParam_noiseMBaY, ModelParam_noiseMBaZ]'*FMScale;
ModelParam_noiseMBaSeed = [2425,2526,2627];

%GPS Parameter
ModelParam_GPSEphFinal=0.3;
ModelParam_GPSEpvFinal=0.4;
ModelParam_GPSFix3DFix=3;
ModelParam_GPSSatsVisible=10;
ModelParam_noiseGPSSampTime=0.02;%GPS Sample time (5Hz)
%barometer
ModelParam_timeSampBaro = 0.01;  % Barometer data sample time
ModelParam_noisePowerOffGainBaro = 0.006;
ModelParam_noiseBaroNm = 0.01;
ModelParam_noiseBaroNmSeed = 19192020;
ModelParam_noiseBaroNbm = 0.0001;
ModelParam_noiseBaroNbmSeed = 20202121;
%acc
ModelParam_noiseAccelNaX = 0.05;
ModelParam_noiseAccelNaY = 0.05;
ModelParam_noiseAccelNaZ = 0.1;
ModelParam_noiseAccelNa = [ModelParam_noiseAccelNaX, ModelParam_noiseAccelNaY, ModelParam_noiseAccelNaZ]';
ModelParam_noiseAccelNaSeed = [1122,2233,3344];
ModelParam_noiseAccelBaX = 0.0001;
ModelParam_noiseAccelBaY = 0.0001;
ModelParam_noiseAccelBaZ = 0.0001;
ModelParam_noiseAccelBa = [ModelParam_noiseAccelBaX, ModelParam_noiseAccelBaY, ModelParam_noiseAccelBaZ]';
ModelParam_noiseAccelBaSeed = [4455,5566,6677];

ModelParam_noiseGyroNgX = 0.0005;
ModelParam_noiseGyroNgY = 0.0005;
ModelParam_noiseGyroNgZ = 0.0005;
ModelParam_noiseGyroNg= [ModelParam_noiseGyroNgX, ModelParam_noiseGyroNgY, ModelParam_noiseGyroNgZ]';
ModelParam_noiseGyroNgSeed = [7788,8899,991010];
ModelParam_noiseGyroNbgX = 0.00001;
ModelParam_noiseGyroNbgY = 0.00001;
ModelParam_noiseGyroNbgZ = 0.00001;
ModelParam_noiseGyroNbg= [ModelParam_noiseGyroNbgX, ModelParam_noiseGyroNbgY, ModelParam_noiseGyroNbgZ]';
ModelParam_noiseGyroNbgSeed = [10101111,11111212,12121313];
ModelParam_noiseMagNmX = 0.00005;
ModelParam_noiseMagNmY = 0.00005;
ModelParam_noiseMagNmZ = 0.00005;
ModelParam_noiseMagNm= [ModelParam_noiseMagNmX, ModelParam_noiseMagNmY, ModelParam_noiseMagNmZ]';
ModelParam_noiseMagNmSeed = [13131414,14141515,15151616];
ModelParam_noiseMagNbmX = 0.000001;
ModelParam_noiseMagNbmY = 0.000001;
ModelParam_noiseMagNbmZ = 0.000001;
ModelParam_noiseMagNbm= [ModelParam_noiseMagNbmX, ModelParam_noiseMagNbmY, ModelParam_noiseMagNbmZ]';
ModelParam_noiseMagNbmSeed = [16161717,17171818,18181919];
% sensor delay
ModelParam_DelayPos = 0;
ModelParam_DelayAtt = 0;
ModelParam_DelayOmega = 0;
if ModelParam_DelayPos > 0
    disp('%%%%%%%  Sensor delay is added. %%%%%')
    fprintf('Position and velocity delay is %.2f\n',ModelParam_DelayPos); 
    fprintf('Attitude delay is %.2f\n',ModelParam_DelayAtt); 
    fprintf('Omega delay is %.2f\n',ModelParam_DelayOmega); 
end