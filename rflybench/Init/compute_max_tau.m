eta = double(ModelParam_rotorEta);
dx = double(ModelParam_rotordx);
dy = double(ModelParam_rotordy);
rotorCm = double(ModelParam_rotorCm);
rotorCt = double(ModelParam_rotorCt);
km_f = rotorCm/rotorCt;
K1 = km_f+dx*sin(eta);
coseta = cos(eta);
K2 = dy*coseta;

dxcoseta = dx*coseta;
T_hover = LW_MASS*9.8/4;


B = [-coseta,   -coseta,   -coseta,  -coseta;
     -K2,       -K2,        K2,       K2;
     dxcoseta,  -dxcoseta, dxcoseta, -dxcoseta;
     K1,        -K1,       -K1,      K1];

options = optimoptions('fmincon','Algorithm','sqp','MaxIterations',1000,'StepTolerance',0.00001);
%z
A = [];b = []; Aeq = B(2:3,:); beq = [0;0];
lb  = zeros(4,1);
ub  = ones(4,1)*ModelParam_Tmax;
fun = @(x)(B(4,:)*x);
x0 = ones(4,1)*T_hover;
[xx,fval,exitflag,output] = fmincon(fun,x0,A,b,Aeq,beq,lb,ub,[],options);
tz_min = (B(4,:)*xx)
%y
A = [];b = []; Aeq = B(2,:); beq = [0];
lb  = zeros(4,1);
ub  = ones(4,1)*ModelParam_Tmax;
fun = @(x)(B(3,:)*x);
x0 = ones(4,1)*T_hover;
[xx,fval,exitflag,output] = fmincon(fun,x0,A,b,Aeq,beq,lb,ub,[],options);
ty_min = (B(3,:)*xx)
%x
A = [];b = []; Aeq = B(3,:); beq = [0];
lb  = zeros(4,1);
ub  = ones(4,1)*ModelParam_Tmax;
fun = @(x)(B(2,:)*x);
x0 = ones(4,1)*T_hover;
[xx,fval,exitflag,output] = fmincon(fun,x0,A,b,Aeq,beq,lb,ub,[],options);
tx_min = (B(2,:)*xx)
