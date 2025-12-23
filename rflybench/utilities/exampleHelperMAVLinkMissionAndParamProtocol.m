% exampleHelperMAVLinkMissionAndParamProtocol 
% Copyright 2020 The MathWorks, Inc.

paramCreator = exampleHelperMAVLinkParamProtocol;
apParams = paramCreator.AutopilotParamsArray;
pmTotal = double(exampleHelperMAVLinkParamProtocol.PARAM_COUNT) - 1;
% Define Global Data Stores

% Mission Microservice
newCount =  Simulink.Signal;
newCount.DataType = 'boolean';
newCount.InitialValue = 'boolean(0)';
newCount.Complexity = 'real';

newItem =  Simulink.Signal;
newItem.DataType = 'boolean';
newItem.InitialValue = 'boolean(0)';
newItem.Complexity = 'real';

% Parameter Microservice
newParamList =  Simulink.Signal;
newParamList.DataType = 'boolean';
newParamList.InitialValue = 'boolean(0)';
newParamList.Complexity = 'real';

newParamRead =  Simulink.Signal;
newParamRead.DataType = 'boolean';
newParamRead.InitialValue = 'boolean(0)';
newParamRead.Complexity = 'real';

newParamSet =  Simulink.Signal;
newParamSet.DataType = 'boolean';
newParamSet.InitialValue = 'boolean(0)';
newParamSet.Complexity = 'real';

flightParams = Simulink.Signal;
flightParams.DataType = 'Bus: SL_Bus_MAVLink_PARAM_VALUE_Payload';
flightParams.Complexity = 'real';
flightParams.Dimensions = double(exampleHelperMAVLinkParamProtocol.PARAM_COUNT);