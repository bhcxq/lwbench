classdef exampleHelperMAVLinkParamProtocol < handle
    % exampleHelperMAVLinkParamProtocol Create and initialize the
    % Autopilot parameters for Fixed-Wing
    
    % Copyright 2020 The MathWorks, Inc.
    
    % Parameter array
    properties
        % Array of params for Fixed-Wing
        AutopilotParamsArray = struct
    end
    
    properties(Constant)
        % MAV_PARAM_TYPE: MAV_PARAM_TYPE_REAL32
        PARAM_TYPE = uint8(9);
        
        % Number of parameters
        PARAM_COUNT = uint8(28);
    end
    
    properties(Constant)
        PARAM_ID_LIST = {'SYS_ID', 'GDNC_TSTAR', 'GDNC_TURN_LEAD', 'CTRL_UHOLD_P', ...
            'CTRL_UHOLD_I', 'CTRL_UHOLD_D', 'CTRL_DE_FFWD', 'CTRL_HE2THE_P', ...
            'CTRL_HE2THE_I', 'CTRL_HE2THE_D', 'CTRL_TH2DT_P', 'CTRL_TH2DT_I', ...
            'CTRL_TH2DT_D', 'CTRL_DT_FFWD', 'CTRL_ROLL_P', 'CTRL_ROLL_I', ...
            'CTRL_ROLL_D', 'CTRL_YAW_P', 'CTRL_YAW_I', 'CTRL_YAW_D', ...
            'CMDS_U_C', 'CMDS_H_C_MIDL', 'CMDS_PSID_C_M', 'CMDS_RTB', ...
            'CMDS_FOLLOW', 'CMDS_IS_MAN', 'CMDS_GDNC_MD', 'CMDS_VIEW_IDX'}
        
        PARAM_VALUE_LIST = {12, 2.5, 6.5, 1.3, 0.15, 0, 0, ...
            0.07, 0.0, 0.0, -1.1, -0.2, 0, 0, ...
            10, 2, 0.3, 0.03, 0.05, 0.0, 18, ...
            50, 0, 0, 0, 0, 2, 2};
    end
    
    properties(Access = private)
        % dialect parser
        dialectInfo
    end
    
    methods
        function obj = exampleHelperMAVLinkParamProtocol(varargin)
            %exampleHelperMAVLinkParamProtocol creates an array
            %of PARAM_VALUE message
            
            % create a parser for common.xml with MAVLink version 2
            dialectInfo = mavlinkdialect('common.xml', 2);
            paramArray = dialectInfo.createmsg('PARAM_VALUE');
            
            for i = 1:obj.PARAM_COUNT
                newParam = obj.createParam(dialectInfo, obj.PARAM_ID_LIST{i}, obj.PARAM_TYPE, ...
                    uint16(i-1), single(obj.PARAM_VALUE_LIST{i}), obj.PARAM_COUNT);
                
               paramArray(i) = newParam;
            end
            
            obj.AutopilotParamsArray = [paramArray(:).Payload];
        end
        
    end
    methods(Static)
        function msg = createParam(parser, id, type, index, value, count)
            %createParam create a new PARAM_VALUE message
            msg = parser.createmsg('PARAM_VALUE');
            
            % Modify message payload to create a parameter entry
            msg.Payload.param_count(:) = count;
            msg.Payload.param_id(1:strlength(id)) = id;
            msg.Payload.param_type(:) = type;
            msg.Payload.param_index(:) = index;
            msg.Payload.param_value(:) = value;
            msg.Payload.param_id = uint8(msg.Payload.param_id);
        end
        
    end
end

