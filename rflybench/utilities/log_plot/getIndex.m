function [timestamp1, index] = getIndex(timestamp1, plot_interval)

index_start = find(timestamp1 >= plot_interval.startTime, 1);
index_end = find(timestamp1 <= plot_interval.endTime, 1,'last');
if isempty(index_start)
    error('Start time exceeds the max time!')
end
if isempty(index_end)
    index_end = length(timestamp1);
    if index_end < 1
        warning('End time exceeds the max time!')
    end
end
if index_start > index_end
    error('Start time is greater than end time!')
end
index = index_start : index_end;
timestamp1 = timestamp1(index);
end

