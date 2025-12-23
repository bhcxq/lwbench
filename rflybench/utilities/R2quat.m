function q = R2quat(R)
%R2QUAT 此处显示有关此函数的摘要
%   此处显示详细说明

q = single([1;0;0;0]);
        t = trace(R);
        if (t > (0)) 
            t = sqrt( single(1) + t);
            q(1) =  single(0.5) * t;
            t =  single(0.5) / t;
            q(2) = (R(3,2) - R(2,3)) * t;
            q(3) = (R(1,3) - R(3,1)) * t;
            q(4) = (R(2,1) - R(1,2)) * t;
        elseif (R(1,1) > R(2,2) && R(1,1) > R(3,3)) 
            t = sqrt( single(1) + R(1,1) - R(2,2) - R(3,3));
            q(2) =  single(0.5) * t;
            t =  single(0.5) / t;
            q(1) = (R(3,2) - R(2,3)) * t;
            q(3) = (R(2,1) + R(1,2)) * t;
            q(4) = (R(1,3) + R(3,1)) * t;
        elseif (R(2,2) > R(3,3)) 
            t = sqrt( single(1) - R(1,1) + R(2,2) - R(3,3));
            q(3) =  single(0.5) * t;
            t =  single(0.5) / t;
            q(1) = (R(1,3) - R(3,1)) * t;
            q(2) = (R(2,1) + R(1,2)) * t;
            q(4) = (R(3,2) + R(2,3)) * t;
         else 
            t = sqrt( single(1) - R(1,1) - R(2,2) + R(3,3));
            q(4) =  single(0.5) * t;
            t =  single(0.5) / t;
            q(1) = (R(2,1) - R(1,2)) * t;
            q(2) = (R(1,3) + R(3,1)) * t;
            q(3) = (R(3,2) + R(2,3)) * t;
        end
end

