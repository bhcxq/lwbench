function y = wrap_pi_n(x)
%将 x 限定在（-pi,pi）
i = 0;
y = x;
for j = 1:length(x)
    while y(j) >= pi
        y(j) =  y(j) - 2*pi;
        i = i + 1;
        if i > 100
            break
        end
    end
    i = 0;
    while y(j) < -pi
        y(j) =  y(j) + 2*pi;
        i = i + 1;
        if i > 100
            break
        end
    end
end
end

