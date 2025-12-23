Map_xoffset = 0;
Map_yoffset = 0;
Map_zoffset = 0;
MapName = 'OldFactory';%MountainTerrain,Grasslands,OldFactory
LoadPngData(MapName)
%RflySendUE4CMD(['RflyChangeMapbyName ',MapName]);
pause(0.5)
switch MapName
    case 'MountainTerrain'
        Map_xoffset = 400;
        Map_yoffset = 50;
        Map_zoffset = getTerrainAltData(Map_xoffset,Map_yoffset);
    case 'Grasslands'
        Map_xoffset = 0;
        Map_yoffset = 0;
        Map_zoffset = getTerrainAltData(Map_xoffset,Map_yoffset);
    case 'OldFactory'
        Map_xoffset = 0;
        Map_yoffset = 0;
        Map_zoffset = getTerrainAltData(Map_xoffset,Map_yoffset);
    otherwise
        Map_xoffset = 0;
        Map_yoffset = 0;
        Map_zoffset = getTerrainAltData(Map_xoffset,Map_yoffset);
end
% RflySendUE4CMD('RflyChangeViewKeyCmd T');
% pause(0.5)
% RflySendUE4CMD('RflyChangeViewKeyCmd P');
% pause(0.5)
% RflySendUE4CMD('RflyChangeViewKeyCmd B 1');
% pause(0.5)
% RflySendUE4CMD('RflyChangeViewKeyCmd N 0');
% pause(0.5)
% RflySendUE4CMD('RflyChangeViewKeyCmd S');
% 
% 
% GPSOrigin=[40.1540302,116.2593683,0];