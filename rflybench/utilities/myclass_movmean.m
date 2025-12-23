classdef myclass_movmean < handle
    properties
        
    end
    methods
        function outdata = my_movmean(obj, indata, win)
            persistent win_data
            if isempty(win_data)
                win_data = zeros(win, 1, 'like', indata);
            end
            if ~isInfNan(indata)
                indata = 0;
            end
            win_data(1 : win - 1) = win_data(2 : win);
            win_data(win) = indata;
            outdata = mean(win_data);
        end
    end
end
