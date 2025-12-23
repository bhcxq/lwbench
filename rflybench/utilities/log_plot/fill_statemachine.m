function fill_statemachine(timestamp, control_mode, mode)
%timestamp:s
%
if strcmp(mode, 'Arm')
    index_change = getControlModeIndexChange(control_mode == 1);
    fill_rgb = [0.82745 0.82745 0.82745]; %light grey
elseif strcmp(mode, 'Manual')
    index_change = getControlModeIndexChange(control_mode == 2);
    fill_rgb = [0.12549 0.69804 0.66667]; %LightSeaGreen
elseif strcmp(mode, 'Acro')
    index_change = getControlModeIndexChange(control_mode == 3);
    fill_rgb = [0.48627 0.98824 0]; %LawnGreen
elseif strcmp(mode, 'Stabilize')
    index_change = getControlModeIndexChange(control_mode == 4);
    fill_rgb = [0.52941 0.80784 0.98039]; %LightSkyBlue
elseif strcmp(mode, 'Altitude')
    %index = ischange(double(control_mode == 5));
    index_change = getControlModeIndexChange(control_mode == 5);
    fill_rgb = [0.99216 0.96078 0.90196]; %OldLace
elseif strcmp(mode, 'Position')
    index_change = getControlModeIndexChange(control_mode == 6);
    fill_rgb = [1 0.71373 0.75686]; % LightPink
elseif strcmp(mode, 'Mission')
    index_change = getControlModeIndexChange(control_mode == 7);
    fill_rgb = [0.72941 0.33333 0.82745]; %MediumOrchid
elseif strcmp(mode, 'Offboard')
    index_change = getControlModeIndexChange(control_mode == 8);
    fill_rgb = [0.94118, 1, 0.94118]; %Honeydew
else
    error(['No ', mode, ' mode, the mode must be Arm, Stabilize, Altitude, Position, Mission.'])
end
ax = gca;
X = []; Y = [];
if ~isempty(index_change)
    for ii = 1 : fix(length(index_change) / 2)
        if ii ~= 0
            X = [timestamp(index_change(ii * 2 - 1)) timestamp(index_change(ii * 2 - 1)) timestamp(index_change(ii * 2)) timestamp(index_change(ii * 2))];
            Y = [ax.YLim(1), ax.YLim(2), ax.YLim(2), ax.YLim(1)];
            p1 = fill(X, Y, fill_rgb, 'EdgeColor', 'none');
            p1.FaceVertexAlphaData = 0.1; % Set constant transparency
            p1.FaceAlpha = 'flat'; % Interpolate to find face transparency
            if timestamp(index_change(ii * 2)) - timestamp(index_change(ii * 2 - 1)) > 0.1
                text(timestamp(index_change(ii * 2 - 1)) + 3, ax.YLim(2), mode, 'HorizontalAlignment', 'right', 'ROtation', 90);
            end
            uistack(p1, 'bottom')
        end
    end
    %     if rem(length(index_change),2) ~= 0
    %         X = [timestamp(index_change(end)) timestamp(index_change(end))
    %         timestamp(end) timestamp(end)]; Y = [ax.YLim(1), ax.YLim(2),
    %         ax.YLim(2), ax.YLim(1)]; p1 =
    %         fill(X,Y,fill_rgb,'EdgeColor','none'); p1.FaceVertexAlphaData =
    %         0.1;    % Set constant transparency p1.FaceAlpha = 'flat' ;
    %         % Interpolate to find face transparency if timestamp(end) -
    %         timestamp(index_change(end)) > 10
    %             text(timestamp(index_change(end)),ax.YLim(2),mode,'HorizontalAlignment','right','ROtation',90);
    %         end uistack(p1,'bottom')
    %     end
end
    function index_change = getControlModeIndexChange(control_mode_)

            index_ = ischange(double(control_mode_));%
            index_change = find(index_);
            if find(control_mode_, 1) == 1
                index_change = [1; index_change];
            end
            if find(control_mode_, 1, 'last') == length(control_mode_)
                index_change = [index_change; length(control_mode_)];
            end
    end
end