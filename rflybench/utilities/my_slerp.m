function qr_ = my_slerp(qs, qe, t)

qs = robotics.internal.validation.validateQuaternion(qs', 'quat2eul', 'q');
qe = robotics.internal.validation.validateQuaternion(qe', 'quat2eul', 'q');
qs = robotics.internal.normalizeRows(qs);
qe = robotics.internal.normalizeRows(qe);

cosa = qs*qe';
if cosa < single(0.0)
    qe = -qe;
    cosa = -cosa;
end
if cosa > 0.9995
   k0 = 1 - t;
   k1 = t;
else
    sina = sqrt( 1.0 - cosa*cosa );
    a = atan2( sina, cosa );
    k0 = sin((1.0 - t)*a)  / sina;
    k1 = sin(t*a) / sina;
end

qr = qs*k0 + qe*k1;
qr = robotics.internal.normalizeRows(qr);
qr_ = qr(:);

