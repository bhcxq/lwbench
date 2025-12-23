function S_serial = saveData(filename, dataname, plot_interval)
%SAVEDATA 此处显示有关此函数的摘要
%   此处显示详细说明
csvname = ['./', filename, '/', filename, '_', dataname, '_0.csv'];
S_serial = struct;
data = importdata(csvname);
data.data(find(data.data(:, 1) == 0), :) = [];
time_ = data.data(:, 1)*1e-6;
index = find(time_>plot_interval.startTime,1):find(time_>plot_interval.endTime,1);
S_serial.time = data.data(index, 1)*1e-6;
S_serial.signals.values = data.data(index, 2:end);
S_serial.signals.dimensions =length(data.textdata)-1;
end

