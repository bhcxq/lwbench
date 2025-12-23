function plot_interval = get_plot_interval(statemachine,task)
% task=1, 从解锁到上锁
% task=2, offboard任务
if task < 1.5
    disarm_s = find(statemachine.arm == 0, 1);
    disarm_e = find(statemachine.arm == 0, 1, 'last');
    if isempty(disarm_s)
        plot_interval.endTime = 0;
        plot_interval.startTime = 0;
        error('Start time is empty!')
    else
        plot_interval.startTime = statemachine.timestamp(disarm_s) * 1e-6;
        plot_interval.endTime = statemachine.timestamp(disarm_e) * 1e-6;
    end
else
    ob_s = find(statemachine.flight_mode == 2, 1);
    ob_e = find(statemachine.flight_mode == 2, 1, 'last');
    if isempty(ob_s)
        plot_interval.endTime = 0;
        plot_interval.startTime = 0;
        error('Start time is empty!')
    else
        plot_interval.startTime = statemachine.timestamp(ob_s) * 1e-6;
        plot_interval.endTime = statemachine.timestamp(ob_e) * 1e-6;
    end
end
end