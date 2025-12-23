function [B, b] = control_allocation_matrix(Va, aero_com, use_ser, ...
    eta, LBb, LBc, LBS, kappa, Rho, dx, dy, Cl, Cm, Cn, Cl_d, Cm_d, ...
    rotorCm, rotorCt)
%control_allocation_matrix
%
% 公式推导和定义见文档《控制器设计231030》
%   u = Bx+b
% motor configuration
% 3 ↓   1 ↑
% 4 ↑   2 ↓
% 5 right aileron
% 6 left aileron

km_f = rotorCm/rotorCt;
K1 = km_f+dx*sin(eta);
coseta = cos(eta);
K2 = dy*coseta;
dxcoseta = dx*coseta;

Va_ = max(Va, 1);

if aero_com > 0.5
    QQ = 0.5*Rho*Va^2*LBS;
else
    QQ = double(0);
end
if use_ser > 0.5
    Q = 0.5*Rho*Va_^2*LBS;
    QQ = 0.5*Rho*Va^2*LBS;
else
    Q = double(0);
end

B = [-coseta,   -coseta,   -coseta,  -coseta,   double(0),   double(0);
     -K2,       -K2,        K2,       K2,      -Q*LBb*Cl_d*cos(kappa), Q*LBb*Cl_d*cos(kappa);
     dxcoseta,  -dxcoseta, dxcoseta, -dxcoseta, Q*LBc*Cm_d, Q*LBc*Cm_d;
     K1,        -K1,       -K1,      K1,      Q*LBb*Cl_d*sin(kappa), -Q*LBb*Cl_d*sin(kappa)];
b = [double(0); QQ*LBb*Cl*cos(kappa)+QQ*LBb*Cn*sin(kappa); QQ*LBc*Cm; -QQ*LBb*Cl*sin(kappa)+QQ*LBb*Cn*cos(kappa)];

end