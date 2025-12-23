function euler = R2euler(dcm)
%R2EULER 此处显示有关此函数的摘要
%   此处显示详细说明
phi_val = single(atan2(dcm(3, 2), dcm(3, 3)));
theta_val = single(asin(-dcm(3, 1)));
psi_val = single(atan2(dcm(2, 1), dcm(1, 1)));

if (single(abs(theta_val - pi / single(2))) < single(1.0e-3))
    phi_val = single(0.0);
    psi_val = single(atan2(dcm(2, 3), dcm(1, 3)));
    
elseif (single(abs(theta_val + pi / single(2))) < single(1.0e-3))
    phi_val = single(0.0);
    psi_val = single(atan2(-dcm(2, 3), -dcm(1, 3)));
end

euler = single([phi_val;theta_val;psi_val]);
end

