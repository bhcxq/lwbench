if strcmp(ModelConfigure_Type, 'SIM')
    maxMissionItem = 15;
else
    maxMissionItem = 5;
end
%maxMissionItem = 15;
%homeLocation = [39.9792567, 116.3393730, 0];%[longtitude, latitude,
%altitude]，真实环境中的起点
homeLocation = [40.1540302, 116.259368300000, 0]; %HIL 模型中起点

%% 自定义轨迹
%生成跑道轨迹
% generatedMissionPath = '.\utilities\runwayLargeHILMission.plan';
% missionPlan = 'runwayLargeHILMission.plan';
% plotFig = true;
% generateXyzMission = runwayMission(11);

%偏航测试轨迹
% generatedMissionPath = '.\utilities\yaw90TestMission.plan';
% missionPlan = 'yaw90TestMission.plan';
% plotFig = true;
% generateXyzMission = yawTestMission(11,90);

%跑道
generatedMissionPath = '.\utilities\lineCircleMission.plan';
missionPlan = 'lineCircleMission.plan';
plotFig = false;
generateXyzMission = lineCircleMission(11,500,250);
%直线
% generatedMissionPath = '.\utilities\lineMission.plan';
% missionPlan = 'lineMission.plan';
% plotFig = true;
% generateXyzMission = lineMission(11,500,250);
%% 
% 根据local position mission 生成 mission plan 文件
getQGCPlanFromUAVMissionStruct(generateXyzMission, homeLocation, plotFig, generatedMissionPath);
pause(1)
% 根据 mission plan 文件生成 local position mission 和 lla mission 
[xyzMission, llaMission,missionLen] = getUAVMissionStructFromQGCPlan(maxMissionItem,missionPlan, homeLocation, plotFig);
% 保存变量供模型使用
save('.\Init\missionPlan.mat','xyzMission','llaMission','missionLen')
%% function
function generateXyzMission = lineMission(maxMissionItem,line,radius)

baseStruct = struct('mode', uint8(2), 'position', single([0; 0; 0]), 'params', single([0; 0; 0; 0]));
    generateXyzMission = repmat(baseStruct,5,1);
    generateXyzMission(1).position(2) = 0;
    generateXyzMission(1).position(1) = radius;
    generateXyzMission(1).position(3) = 50;
    generateXyzMission(2).position(2) = 0;
    generateXyzMission(2).position(1) = radius+line;
    generateXyzMission(2).position(3) = 50;
    generateXyzMission(2).params(2) = 0;
     generateXyzMission(3).position(2) = radius*2;
    generateXyzMission(3).position(1) = radius+line;
    generateXyzMission(3).position(3) = 50;
    generateXyzMission(3).params(2) = 0;
    generateXyzMission(4).position(2) = radius*2;
    generateXyzMission(4).position(1) = radius;
    generateXyzMission(4).position(3) = 50;
    generateXyzMission(4).params(2) = 0;
    generateXyzMission(5).position(2) = 0;
    generateXyzMission(5).position(1) = radius;
    generateXyzMission(5).position(3) = 50;
    generateXyzMission(5).params(2) = 0;
end
function generateXyzMission = lineCircleMission(maxMissionItem,line,radius)

baseStruct = struct('mode', uint8(2), 'position', single([0; 0; 0]), 'params', single([0; 0; 0; 0]));
    generateXyzMission = repmat(baseStruct,5,1);
    generateXyzMission(1).position(2) = 0;
    generateXyzMission(1).position(1) = radius;
    generateXyzMission(1).position(3) = 50;
    generateXyzMission(2).position(2) = 0;
    generateXyzMission(2).position(1) = radius+line;
    generateXyzMission(2).position(3) = 50;
    generateXyzMission(2).params(2) = 1;
     generateXyzMission(3).position(2) = radius*2;
    generateXyzMission(3).position(1) = radius+line;
    generateXyzMission(3).position(3) = 50;
    generateXyzMission(3).params(2) = 2;
    generateXyzMission(4).position(2) = radius*2;
    generateXyzMission(4).position(1) = radius;
    generateXyzMission(4).position(3) = 50;
    generateXyzMission(4).params(2) = 1;
    generateXyzMission(5).position(2) = 0;
    generateXyzMission(5).position(1) = radius;
    generateXyzMission(5).position(3) = 50;
    generateXyzMission(5).params(2) = 2;
end
function generateXyzMission = yawTestMission(maxMissionItem,yaw)
pathYaw = yaw*pi/180;
baseStruct = struct('mode', uint8(2), 'position', single([0; 0; 0]), 'params', single([0; 0; 0; 0]));
generateXyzMission = repmat(baseStruct,3,1);
    generateXyzMission(1).position(2) = -100;
    generateXyzMission(1).position(1) = -100;
    generateXyzMission(1).position(3) = 50;
    generateXyzMission(2).position(2) = 0;
    generateXyzMission(2).position(1) = 500;
    generateXyzMission(2).position(3) = 50;
     generateXyzMission(3).position(2) = 500*sin(pathYaw);
    generateXyzMission(3).position(1) = 500+500*cos(pathYaw);
    generateXyzMission(3).position(3) = 50;
end
function generateXyzMission = runwayMission(maxMissionItem)
baseStruct = struct('mode', uint8(2), 'position', single([0; 0; 0]), 'params', single([0; 0; 0; 0]));
generateXyzMission = repmat(baseStruct,maxMissionItem,1);
%生成跑道轨迹
%   
%   /~~~~~~~~~~~~~~\
%  /                \
%  \                /
%   \______________/
R = 185*5;
line = 85;
n = floor((maxMissionItem -4)/2)+1;
nrad = pi/n;
for i = 0:n
    generateXyzMission(i+1).position(2) = R - R*cos(nrad*i);
    generateXyzMission(i+1).position(1) = R*sin(nrad*i);
    generateXyzMission(i+1).position(3) = 50;
end

 for i = 0:n
    generateXyzMission(i+n+2).position(2) = R + R*cos(nrad*i);
    generateXyzMission(i+n+2).position(1) = -line - R*sin(nrad*i);
    generateXyzMission(i+n+2).position(3) = 50;
 end
generateXyzMission(2*n+3).position = generateXyzMission(1).position;
end

