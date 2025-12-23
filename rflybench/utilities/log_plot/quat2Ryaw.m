function Ryaw = quat2Ryaw(q)
euler = my_quat2eul(q,'ZYX');
euler(1) = 0;
euler(2) = 0;
Reb = my_eul2rotm(euler,'ZYX');
Ryaw = Reb';
end