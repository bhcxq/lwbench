function y = notInfNan(data)
%ISINFNAN 此处显示有关此函数的摘要
%   Data is a vector.
y = false;
for ii = 1:length(data)
   if isinf(data(ii)) || isnan(data(ii))
       y = false;
       return;
   else
       y = true;
   end
end
end

