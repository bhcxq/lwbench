function euler = quat2euler(q)
%Function description;
%  Quaternion to Euler

q = q/(norm(q,2));
phi = atan2(2*(q(1)*q(2) + q(3)*q(4)), (1 - 2*(q(2)*q(2) + q(3)*q(3))));
if isnan(phi) || isinf(phi)
    phi = single(0);
end
theta = asin(max(min(2*(q(1)*q(3) - q(2)*q(4)),1),-1));
if isnan(theta) || isinf(theta)
    theta = single(0);
end
psi = atan2(2*(q(1)*q(4) + q(2)*q(3)), (1 - 2*(q(3)*q(3) + q(4)*q(4))));
if isnan(psi) || isinf(psi)
    psi = single(0);
end
euler = [phi theta psi]';
end