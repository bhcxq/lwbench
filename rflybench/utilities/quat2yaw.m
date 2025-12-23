function psi = quat2yaw(q)
 %Function description;
%  Quaternion to Euler
%phi = atan2(2*(q(1)*q(2) + q(3)*q(4)), (1 - 2*(q(2)*q(2) + q(3)*q(3))));
%theta = asin(max(min(2*(q(1)*q(3) - q(2)*q(4)),1),-1));
psi = single(atan2(2*(q(1)*q(4) + q(2)*q(3)), (1 - 2*(q(3)*q(3) + q(4)*q(4)))));
%euler = [phi theta psi];

