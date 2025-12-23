offboard_bus = Simulink.Bus;
pos = Simulink.BusElement;
pos.Name = 'pos';
pos.Dimensions = 3;
pos.DimensionsMode = 'Fixed';
pos.DataType = 'single';

vel = Simulink.BusElement;
vel.Name = 'vel';
vel.Dimensions = 3;
vel.DimensionsMode = 'Fixed';
vel.DataType = 'single';

acc = Simulink.BusElement;
acc.Name = 'acc';
acc.Dimensions = 3;
acc.DimensionsMode = 'Fixed';
acc.DataType = 'single';

q = Simulink.BusElement;
q.Name = 'q';
q.Dimensions = 4;
q.DimensionsMode = 'Fixed';
q.DataType = 'single';

f_d = Simulink.BusElement;
f_d.Name = 'f_d';
f_d.Dimensions = 1;
f_d.DimensionsMode = 'Fixed';
f_d.DataType = 'single';

alpha = Simulink.BusElement;
alpha.Name = 'alpha';
alpha.Dimensions = 1;
alpha.DimensionsMode = 'Fixed';
alpha.DataType = 'single';

beta = Simulink.BusElement;
beta.Name = 'beta';
beta.Dimensions = 1;
beta.DimensionsMode = 'Fixed';
beta.DataType = 'single';

rates = Simulink.BusElement;
rates.Name = 'rates';
rates.Dimensions = 3;
rates.DimensionsMode = 'Fixed';
rates.DataType = 'single';

dotrates = Simulink.BusElement;
dotrates.Name = 'dotrates';
dotrates.Dimensions = 3;
dotrates.DimensionsMode = 'Fixed';
dotrates.DataType = 'single';

OB_TASK = Simulink.BusElement;
OB_TASK.Name = 'OB_TASK';
OB_TASK.Dimensions = 1;
OB_TASK.DimensionsMode = 'Fixed';
OB_TASK.DataType = 'int8';

offboard_bus.Elements = [pos vel acc q f_d alpha beta rates dotrates OB_TASK];