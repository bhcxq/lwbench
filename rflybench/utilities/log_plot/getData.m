function S = getData(filename, dataname)
csvname = ['./', filename, '/', filename, '_', dataname, '_0.csv'];

S = struct;
data = importdata(csvname);
data.data(find(data.data(:, 1) == 0), :) = [];
for i = 1 : length(data.textdata)
    field = string(data.textdata(i));
    field = erase(field, ["[", "]"]);
    S = setfield(S, field, data.data(:, i));
end

end

