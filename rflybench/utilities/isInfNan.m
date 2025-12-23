function y = isInfNan(data)
%ISINFNAN 此处显示有关此函数的摘要
%   Data is a vector.
for ii = 1:length(data)
   if isinf(data(ii)) || isnan(data(ii))
       y = true;
       return;
   else
       y = false;
   end
end
end

