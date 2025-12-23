function y = constrain(x,min,max)
%CONSTRAIN 此处显示有关此函数的摘要
%   此处显示详细说明
% min  = single(min);
% max = single(max);
if x > max 
    y = max;
elseif x < min
    y = min;
else
    y = x;
end
end

