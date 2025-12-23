function y = wrap_pi(x)
%将 x 限定在[-pi,pi]
i = 0;
y = x;
while x > pi
    y =  x - 2*pi;
    i = i + 1;
    if i > 100
        break
    end
end
i = 0;
while x < -pi
    y =  x + 2*pi;
    i = i + 1;
    if i > 100
        break
    end
end
end

