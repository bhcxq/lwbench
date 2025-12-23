function [xyzMission, llaMission, missionLen] = getUAVMissionStructFromQGCPlan(maxMissionItem, missionPlan, homeLocation, plotFig)
%Input:
% xyzMission: local position of the mission with the longtitude and latitude of first mission item,and altitude is 0. 
% llaMission: longtitude,latitude and altitude of the mission decoded from
%             mission plan.
% missionLen: the valid length of mission.
%Output:
% missionPlan:the name of mission plan.
% homeLocation: the reference longtitude,latitude and altitude, in this
%               case, only altitude is used.
% plotFig: if is true, plot the mission's local position.

qgcMission = jsondecode(fileread(missionPlan));

baseStruct = struct('mode', uint8(2), 'position', single([0; 0; 0]), 'params', single([0; 0; 0; 0]));
nwps = size(qgcMission.mission.items,1);
missionLen = nwps;
xyzMission = repmat(baseStruct,maxMissionItem,1);
baseStruct = struct('mode', uint8(2), 'position', single([0; 0; 0]), 'params', single([0; 0; 0; 0]));
llaMission = repmat(baseStruct,maxMissionItem,1);
if (plotFig)
    figure('Name','local position of the mission');
    xlabel('y');ylabel('x')
    hold on
end
for ii = 1:nwps
    gPos = qgcMission.mission.items(ii).params(5:7)';
    lPos = lla2flat (gPos, homeLocation(1:2), 0, homeLocation(3));
    %lPos = lla2flat (gPos, qgcMission.mission.items(1).params(5:6), 0, homeLocation(3));
    lPos(3) = lPos(3) * single(-1);
     %判断是否为有效mission
    %isMissionValid = missionValid(lPos, xyzMission);
    if ii == 1
        if abs(lPos(3)) < 0.01
            isMissionValid = false;
        else
            isMissionValid = true;
        end
    elseif norm(lPos(:) - xyzMission(ii - 1).position) < 1e-3 || abs(lPos(3)) < 0.01
        isMissionValid = false;
    end
    if isMissionValid
        missionLen = ii;
    end
    if (plotFig && isMissionValid)
        plot(lPos(2), lPos(1),'-o');
        text(double(lPos(2)), double(lPos(1)),num2str(ii))
    end
    xyzMission(ii).position = single(lPos');
    xyzMission(ii).mode = uint8(mavlinkToPlannerType(qgcMission.mission.items(ii).command));
    y = isnan(qgcMission.mission.items(ii).params);
    xyzMission(ii).params = single(qgcMission.mission.items(ii).params(1:4));
    if sum(y)>0
        xyzMission(ii).params(y) = single(0);
    end
    llaMission(ii).position = single(gPos');
    llaMission(ii).mode = uint8(mavlinkToPlannerType(qgcMission.mission.items(ii).command));
    y = isnan(qgcMission.mission.items(ii).params);
    llaMission(ii).params = single(qgcMission.mission.items(ii).params(1:4));
    if sum(y)>0
        llaMission(ii).params(y) = single(0);
    end
    
end
if (plotFig)
    hold off
end
end

function plannerType =  mavlinkToPlannerType (mavlinkType)
% see enum name="MAV_CMD" in common.xml for values.
switch mavlinkType
    case 16 %MAV_CMD_NAV_WAYPOINT
        plannerType = uint8(2);
    case 18 %MAV_CMD_NAV_LOITER_TURNS
        plannerType = uint8(3);
    case 21 %MAV_CMD_NAV_LAND
        plannerType = uint8(4);
    case 22 %MAV_CMD_NAV_TAKEOFF
        plannerType = uint8(1);
    otherwise %this will likely error out to signal something unexpected
        plannerType = uint8(0);
end
end
