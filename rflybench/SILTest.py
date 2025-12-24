import time
import math
import sys

import PX4MavCtrlV4 as PX4MavCtrl


#Create a new MAVLink communication instance, UDP sending port (CopterSim’s receving port) is 20100
mav = PX4MavCtrl.PX4MavCtrler(1)


#Turn on MAVLink to monitor CopterSim data and update it in real time. 
mav.InitMavLoop()

mav.initOffboard()
time.sleep(1)

# init RC pwm values
pwms=[1499,1499,1499,1499,1899,1899,1100,1510]

#Turn on RCOverride mode, and start to send RC pwms
mav.initRCSendLoop()

# reset pwms value to send
mav.SendRCPwms(pwms)

time.sleep(1000)

#Exit Offboard control mode
print("Send offboard stop")
mav.endRCSendLoop()
time.sleep(1)

#Exit MAVLink data receiving mode
print("Send Mavlink stop")
mav.stopRun()
time.sleep(1)
#while True:
#    print(mav.uavPosNED)
#    time.sleep(2)

