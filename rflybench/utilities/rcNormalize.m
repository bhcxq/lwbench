function y = rcNormalize(ch, RC_MIN, RC_MAX, RC_REV, DEADZONE_RATE)
%Function description:
%  Control the range of the remote control input from RCMin to RCMax, and set
%  a dead zone with a dead zone size of ±deadZone,the output y is
%  normalized to 0~1.You can get the RC calibration parameters in QGC.
rc_min = RC_MIN;
rc_max = RC_MAX;
rc_mid = ((rc_min + rc_max)/single(2.0));
deadzone_rate = DEADZONE_RATE;
deadzone = deadzone_rate*(rc_max - rc_min);
k = single(1)/(rc_max - rc_mid - deadzone);
ch = constrain(ch, rc_min, rc_max);

%dead zone and normalize
 if(ch > rc_mid + deadzone)
    y = (ch - rc_mid - deadzone)*k;
 elseif(ch < rc_mid - deadzone)
     y = (ch - rc_mid + deadzone)*k;
 else
     y = single(0.0);
 end
 y = single(RC_REV*y);
end

