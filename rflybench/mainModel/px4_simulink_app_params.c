/****************************************************************************
 *
 *   Copyright (c) 2013-2016 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file px4_simulink_app_params.c
 * Lifting-wing multicopter controller parameters.
 *
 * @author wsh
 */


//******************************************************************************************************************//
//************************************************Model Configuration***********************************************//
//******************************************************************************************************************//
/**
 * Parameter test
 *
 * Displayed in debug vector
 * 
 * @decimal 2
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_LED, 0.0f);
/**
 * Mass of aircraft
 *
 * @unit kg
 * @min 0.1
 * @max 10.0
 * @decimal 2
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_MASS, 2.14f);

/**
 * Installation angle between lifting wing and rotor plane
 *
 * @unit deg
 * @min 0.0
 * @max 90.0
 * @decimal 1
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_ANGLE, 34.0f);

/**
 * Right aileron deflection direction calibration
 *
 * @min -1.0
 * @max 1.0
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_SERVOR_REV, 1.0f);

/**
 * Left aileron deflection direction calibration
 *
 * @min -1.0
 * @max 1.0
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_SERVOL_REV, -1.0f);

/**
 * Maximum deflection angle of right aileron
 *
 * @unit deg
 * @min 0.0
 * @max 50.0
 * @decimal 1
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_SERVOR_MAX, 20.0f);

/**
 * Minimun deflection angle of right aileron
 *
 * @unit deg
 * @min -50.0
 * @max 0.0
 * @decimal 1
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_SERVOR_MIN, -20.0f);

/**
 * Maximum deflection angle of left aileron
 *
 * @unit deg
 * @min 0.0
 * @max 50.0
 * @decimal 1
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_SERVOL_MAX, 20.0f);

/**
 * Minimun deflection angle of left aileron
 *
 * @unit deg
 * @min -50.0
 * @max 0.0
 * @decimal 1
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_SERVOL_MIN, -20.0f);

/**
 * aileron identification.>0 pitch; <0 roll
 *
 * @unit deg
 * @min -30.0
 * @max 30.0
 * @decimal 1
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_SERVOR_CON, 0.0f);


/**
 * Using aerodynamic models to compensate for aerodynamic forces
 *
 * @min 0.0
 * @max 1.0
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_AERO_COM, 1.0f);

/**
 * Drag coefficient in aerodynamic models
 *
 * @min 0.01
 * @max 2.0
 * @decimal 2
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_AERO_C0, 0.26f);

/**
 * Lift coefficient in aerodynamic models
 *
 * @min 0.01
 * @max 3.0
 * @decimal 2
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_AERO_C1, 1.88f);

/**
 * Side drag coefficient in aerodynamic models
 *
 * @min 0.01
 * @max 2.0
 * @decimal 2
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_AERO_Y0, 0.3f);

/**
 * Roll torque coefficient of rudder surface
 *
 * @min -2.0
 * @max 2.0
 * @decimal 2
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_LBCL_D, 0.07f);

/**
 * Pitch torque coefficient of rudder surface
 *
 * @min -2.0
 * @max 2.0
 * @decimal 2
 * @group LW Model Configuration
 */
PARAM_DEFINE_FLOAT(LW_LBCM_D, -0.2f);

//******************************************************************************************************************//
//**********************************************Disturdance Estimation**********************************************//
//******************************************************************************************************************//
/**
 * Enable disturdance torque estimation
 *
 * @min 0
 * @max 1.0
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_EN, 1.0f);

/**
 * Enable disturdance force estimation
 *
 * @min 0
 * @max 1.0
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_EN, 1.0f);

/**
 * Filter bandwidth for xy disturdance torque estimation
 *
 * 2*wn*sigma for angular error, wn^2 for attitude error
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_WNXY, 50.0f);

/**
 * Filter bandwidth for z disturdance torque estimation
 *
 * 2*wn*sigma for angular error, wn^2 for attitude error
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_WNZ, 10.0f);

/**
 * Filter damping for xy disturdance torque estimation
 *
 * 2*wn*sigma for angular error, wn^2 for attitude error
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_SIGXY, 1.5f);

/**
 * Filter damping for z disturdance torque estimation
 *
 * 2*wn*sigma for angular error, wn^2 for attitude error
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_SIGZ, 10.0f);

/**
 * Integral coefficient for xy disturdance torque estimation
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_LAMXY, 1.0f);

/**
 * Integral coefficient for z disturdance torque estimation
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_LAMZ, 1.0f);

/**
 * Omega filtering coefficient
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_WBDT, 0.05f);

/**
 * XY Disturbance torque filtering coefficient
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_DTXY, 0.03f);

/**
 * Z Disturbance torque filtering coefficient
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_DTZ, 0.03f);

/**
 * Filtering coefficient of thrust in disturbance torque estimation
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_TDT, 0.02f);

/**
 * Observer type, 0：GOB-Q,1:GOB-I,2:GOB-II,3:CFO,4:ESO,5:NDOB,6:GOB_Reduced.
 *
 * @min 0.0
 * @max 10.0
 * @decimal 1
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_TEST_NUM, 0.0f);

/**
 * Filter bandwidth for xy disturdance force estimation
 *
 * 2*wn*sigma for velocity error, wn^2 for position error
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_WNXY, 2.0f);

/**
 * Filter bandwidth for z disturdance force estimation
 *
 * 2*wn*sigma for velocity error, wn^2 for position error
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_WNZ, 1.0f);

/**
 * Filter damping for xy disturdance force estimation
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_SIGXY, 20.0f);

/**
 * Filter damping for z disturdance force estimation
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_SIGZ, 20.0f);

/**
 * Integral coefficient for xy disturdance force estimation
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_LAMXY, 1.0f);

/**
 * Integral coefficient for z disturdance force estimation
 *
 * @min 0.1
 * @max 100.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_LAMZ, 1.0f);

/**
 * Disturbance compensation coefficient
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_P, 0.9f);

/**
 * Disturbance force filtering coefficient
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_DT, 0.03f);

/**
 * Filtering coefficient of thrust in disturbance force estimation
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Disturdance Estimation
 */
PARAM_DEFINE_FLOAT(LW_FEST_TDT, 0.02f);

//******************************************************************************************************************//
//******************************************************Mixer*******************************************************//
//******************************************************************************************************************//

/**
 * Enable aileron for control
 *
 * @min 0.0
 * @max 1.0
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_USE_SER, 1.0f);

/**
 * The proportion of torque error to the energy consumption of the actuator
 *
 * The larger the value, the more you want to reduce torque error and pay less attention to energy consumption
 *
 * @min 0.0
 * @max 1000000.0
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_MIXER_GAM, 500.0f);

/**
 * Weight for desired thrust
 *
 * @min 1.0
 * @max 100.0
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_W_FZ, 20.0f);

/**
 * Weight for desired x-axis torque
 *
 * @min 1.0
 * @max 100.0
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_W_TAOX, 50.0f);

/**
 * Weight for desired y-axis torque
 *
 * @min 1.0
 * @max 100.0
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_W_TAOY, 50.0f);

/**
 * Weight for desired z-axis torque
 *
 * @min 1.0
 * @max 100.0
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_W_TAOZ, 15.0f);

/**
 * Weight for aileron at low speeds
 *
 * @min 0.0
 * @max 1000000.0
 * @decimal 2
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_W_SER, 1000.0f);

/**
 * Weight for aileron at high speeds
 *
 * @min 0.0
 * @max 100.0
 * @decimal 2
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_W_SERH, 5.0f);

/**
 * Output low-pass filtering cut-off frequency of servo
 *
 * @unit Hz
 * @min 0.0
 * @max 100.0
 * @decimal 2
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_SER_LP, 1.0f);

/**
 * Minimum thrust limit for one motor (percentage of minimum thrust to hovering thrust)
 *
 * @min 0.0
 * @max 0.3
 * @decimal 1
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_THR_LOW, 0.0f);

/**
 * Motor thrust change rate limit (percentage of thrust change to hovering thrust in a control cycle)
 *
 * @min 0.0
 * @max 0.5
 * @decimal 1
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_DTHR, 0.3f);

/**
 * Servo change rate limit (percentage of servo change to maximum servo rate in a control cycle)
 *
 * @min 0.0
 * @max 0.5
 * @decimal 1
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_DSER, 0.2f);

/**
 * Minimum airspeed when starting to use the control surface (if enable surface control)
 *
 * @min 0.0
 * @max 10.0
 * @decimal 1
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_VA_TMIN, 6.0f);

/**
 * Exceeding this airspeed will not limit the use of the control surface (if enable surface control)
 *
 * @min 3.0
 * @max 20.0
 * @decimal 1
 * @group LW Mixer
 */
PARAM_DEFINE_FLOAT(LW_VA_TMAX, 10.0f);

//******************************************************************************************************************//
//*************************************************Attitude Control*************************************************//
//******************************************************************************************************************//
/**
 * Enable coordinate turn control
 *
 * @min 0.0
 * @max 1.0
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_COOR_TURN, 0.0f);

/**
 * Throttle for hovering, only used in attitude control mode
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_THR_HOVER, 0.41f);

/**
 * Maximum roll angle, only used in attitude control mode
 *
 * @unit deg
 * @min 10.0
 * @max 45.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_MAN_ROLL_MAX, 35.0f);

/**
 * Maximum pitch angle, only used in attitude control mode
 *
 * @unit deg
 * @min 10.0
 * @max 45.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_MAN_PITCH_MAX, 35.0f);

/**
 * Maximum y-axis angular rate
 *
 * @unit deg/s
 * @min 10.0
 * @max 1000.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WY_MAX, 80.0f);

/**
 * Maximum y-axis angular rate in decelerating phase
 *
 * @unit deg/s
 * @min 10.0
 * @max 1000.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WY_DE_MAX, 50.0f);

/**
 * Maximum x-axis angular rate
 *
 * @unit deg/s
 * @min 10.0
 * @max 1000.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WX_MAX, 80.0f);

/**
 * Maximum z-axis angular rate
 *
 * @unit deg/s
 * @min 10.0
 * @max 1000.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WZ_MAX, 80.0f);

/**
 * Maximum x-axis angular rate setpoint, only used in acro mode
 *
 * @unit deg/s
 * @min 10.0
 * @max 1000.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_ACRO_P_MAX, 360.0f);

/**
 * Maximum y-axis angular rate setpoint, only used in acro mode
 *
 * @unit deg/s
 * @min 10.0
 * @max 1000.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_ACRO_R_MAX, 360.0f);

/**
 * Maximum z-axis angular rate setpoint, only used in acro mode
 *
 * @unit deg/s
 * @min 10.0
 * @max 1000.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_ACRO_Y_MAX, 100.0f);

/**
 * Pitch P gain
 *
 * Pitch proportional gain, i.e. desired angular speed in rad/s for error 1 rad.
 *
 * @min 0.0
 * @max 12
 * @decimal 2
 * @increment 0.1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_PITCH_P, 4.0f);

/**
 * Pitch rate P gain
 *
 * Pitch rate proportional gain, i.e. control output for angular speed error 1 rad/s.
 *
 * @min 0.1
 * @max 100.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WY_P, 20.0f);

/**
 * Pitch rate I gain
 *
 * Pitch rate integral gain. Can be set to compensate static thrust difference or gravity center offset.
 *
 * @min 0.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WY_I, 0.0f);

/**
 * Pitch rate D gain
 *
 * Pitch rate differential gain. Small values help reduce fast oscillations. If value is too big oscillations will appear again.
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WY_D, 0.00f);

/**
 * Filter coefficients for roll rate error differentiation
 *
 *
 * @min 1.0
 * @max 10.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WY_N, 1.0f);

/**
 * Roll P gain
 *
 * Roll proportional gain, i.e. desired angular speed in rad/s for error 1 rad.
 *
 * @min 0.0
 * @max 12
 * @decimal 2
 * @increment 0.1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_ROLL_P, 4.0f);

/**
 * Roll rate P gain
 *
 * Roll rate proportional gain, i.e. control output for angular speed error 1 rad/s.
 *
 * @min 0.1
 * @max 100.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WX_P, 17.0f);

/**
 * Roll rate I gain
 *
 * Roll rate integral gain. Can be set to compensate static thrust difference or gravity center offset.
 *
 * @min 0.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WX_I, 0.0f);

/**
 * Roll rate D gain
 *
 * Roll rate differential gain. Small values help reduce fast oscillations. If value is too big oscillations will appear again.
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WX_D, 0.00f);

/**
 * Filter coefficients for roll rate error differentiation
 *
 *
 * @min 1.0
 * @max 10.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WX_N, 1.0f);

/**
 * Yaw P gain
 *
 * Yaw proportional gain, i.e. desired angular speed in rad/s for error 1 rad.
 *
 * @min 0.0
 * @max 12
 * @decimal 2
 * @increment 0.1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_YAW_P, 2.0f);

/**
 * Yaw rate P gain
 *
 * Yaw rate proportional gain, i.e. control output for angular speed error 1 rad/s.
 *
 * @min 0.1
 * @max 100.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WZ_P, 18.0f);

/**
 * Yaw rate I gain
 *
 * Yaw rate integral gain. Can be set to compensate static thrust difference or gravity center offset.
 *
 * @min 0.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WZ_I, 0.0f);

/**
 * Yaw rate D gain
 *
 * Yaw rate differential gain. Small values help reduce fast oscillations. If value is too big oscillations will appear again.
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WZ_D, 0.0f);

/**
 * Filter coefficients for yaw rate error differentiation
 *
 *
 * @min 1.0
 * @max 10.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WZ_N, 1.0f);

/**
 * Roll rate feedforward
 *
 * Improves tracking performance.
 *
 * @min 0.0
 * @max 1.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WX_FF, 1.0f);

/**
 * Pitch rate feedforward
 *
 * Improves tracking performance.
 *
 * @min 0.0
 * @max 1.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WY_FF, 1.0f);

/**
 * Yaw rate feedforward
 *
 * Improves tracking performance.
 *
 * @min 0.0
 * @max 1.0
 * @decimal 1
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_WZ_FF, 1.0f);

/**
 * The cut-off frequency of low-pass filtering for ideal differentiators for xy axis Smith predictor in Offboard mode
 *
 * The low-pass filtering cutoff frequency of the ideal differentiator. When fz=0, x_ Out=x_ In.
 *
 * @min 0.0
 * @max 200.0
 * @unit Hz
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_TAUXYSP_FZ, 0.0f);

/**
 * The cut-off frequency of low-pass filtering for ideal differentiators for z axis Smith predictor in Offboard mode
 *
 * The low-pass filtering cutoff frequency of the ideal differentiator. When fz=0, x_ Out=x_ In.
 *
 * @min 0.0
 * @max 200.0
 * @unit Hz
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_TAUZSP_FZ, 10.0f);

/**
 * Prediction time of torque control command for xy axis Smith predictor
 *
 * Prediction time of torque control command for Smith predictor. When Tm=0, the low-pass filtering with a cutoff frequency of fz is performed on x_in.
 *
 * @min 0.0
 * @max 1.0
 * @unit s
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_TAUXYSP_TM, 0.00f);

/**
 * Prediction time of torque control command for z axis Smith predictor
 *
 * Prediction time of torque control command for Smith predictor. When Tm=0, the low-pass filtering with a cutoff frequency of fz is performed on x_in.
 *
 * @min 0.0
 * @max 1.0
 * @unit s
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_TAUZSP_TM, 0.00f);

/**
 * Rocker center dead zone for roll setpoint
 *
 * @min 0.0
 * @max 0.5
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_MAN_ROLL_DZ, 0.05f);

/**
 * Rocker center dead zone for pitch setpoint
 *
 * @min 0.0
 * @max 0.5
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_MAN_PITCH_DZ, 0.05f);

/**
 * Rocker center dead zone for roll rate setpoint
 *
 * @min 0.0
 * @max 0.5
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_MAN_WX_DZ, 0.01f);

/**
 * Rocker center dead zone for pitch rate setpoint
 *
 * @min 0.0
 * @max 0.5
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_MAN_WY_DZ, 0.01f);

/**
 * Rocker center dead zone for yaw rate setpoint
 *
 * @min 0.0
 * @max 0.5
 * @decimal 2
 * @group LW Attitude Control
 */
PARAM_DEFINE_FLOAT(LW_MAN_WZ_DZ, 0.1f);

//******************************************************************************************************************//
//*************************************************Position Control*************************************************//
//******************************************************************************************************************//
/**
 * The mapping method from expected force to attitude
 *
 * 1: Known aerodynamic model, direct compensation;
 * 2: Known the aerodynamic model, use differential flatness to solve;
 * 3: Unknown aerodynamic model
 *
 * @min 1
 * @max 3
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_F_MAP, 1.0f);

/**
 * Active abandonment of yaw angle control
 *
 * When the mixer cannot meet the expected yaw torque, the position control actively abandons the control of yaw angle
 *
 * @min 0
 * @max 1
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_REX_YAW, 0.0f);

/**
 * Yaw admittance control
 *
 * Static error compensation for yaw moment during hovering.
 *
 * @min -2
 * @max 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_DMZ0, 0.0f);

/**
 * Yaw admittance control
 * 
 * Only when abs(dmz) > LW_DMZ_MIN will the desired yaw angle be provided; otherwise, maintain the yaw angle from the previous moment.
 *
 * @min 0
 * @max 1
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_DMZ_MIN, 0.01f);

/**
 * Yaw admittance control
 *
 * stiffness coefficient
 *
 * @min 0
 * @max 5
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_YAW_KAP, 1.0f);

/**
 * Yaw admittance control
 *
 * damping coefficient, must bigger than 0
 *
 * @min 0.1
 * @max 5.0
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_YAW_KAD, 1.0f);

/**
 * Maximum tilt angle in air
 *
 * Limits maximum tilt in POSCTRL modes during flight.
 *
 * @unit deg
 * @min 10.0
 * @max 90.0
 * @decimal 1
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_TILTMAX_AIR, 30.0f);

/**
 * Maximum horizontal velocity
 *
 * Maximum horizontal velocity and maximum velocity setpoint on x-axies in POSCTRL mode. If higher speeds
 * are commanded they will be capped to this velocity.
 *
 * @unit m/s
 * @min 0.0
 * @max 30.0
 * @increment 1
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_VEL_MAX, 20.0f);

/**
 * Maximum velocity setpoint on y-axies for manual control mode
 *
 * If velocity setpoint larger than LW_Y_VEL_MAX is set, then
 * the setpoint will be capped to LW_Y_VEL_MAX
 *
 * @unit m/s
 * @min 1.0
 * @max 20.0
 * @increment 1
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_VEL_MAX, 20.0f);

/**
 * Filtering coefficient of velocity command in position control mode
 *
 * filted_vel = man_vel_last + LW_VEL_DT*(man_vel - man_vel_last). When set to 1, the command will not be filted.
 *
 * @min 0.0
 * @max 1.0
 * @increment 0.01
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_VEL_DT, 0.01f);

/**
 * Maximum ascent velocity
 *
 * Ascent velocity in manual modes
 *
 * @unit m/s
 * @min 0.5
 * @max 8.0
 * @increment 0.1
 * @decimal 1
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_VEL_MAX_UP, 3.0f);

/**
 * Maximum x-axis acceleration in position control modes
 *
 * @unit m/s^2
 * @min 2.0
 * @max 10.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_ACCEL_MAX, 4.0f);

/**
 * Minimum x-axis acceleration in position control modes
 *
 * @unit m/s^2
 * @min -10.0
 * @max -2.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_ACCEL_MIN, -4.0f);

/**
 * Maximum jerk limit on x-axis
 *
 * Limit the maximum jerk of the vehicle (how fast the acceleration can change).
 * A lower value leads to smoother vehicle motions, but it also limits its
 * agility (how fast it can change directions or break).
 *
 * Setting this to the maximum value essentially disables the limit.
 *
 * Note: This is only used in Pilot mode.
 *
 * @unit m/s^3
 * @min 0.5
 * @max 500.0
 * @increment 1
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_JERK_MAX, 100.0f);

/**
 * Maximum y-axis acceleration in velocity controlled modes
 *
 * @unit m/s^2
 * @min 2.0
 * @max 10.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_ACCEL_MAX, 4.0f);

/**
 * Minimum y-axis acceleration in velocity controlled modes
 *
 * @unit m/s^2
 * @min -10.0
 * @max -2.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_ACCEL_MIN, -4.0f);

/**
 * Maximum jerk limit on y-axis
 *
 * Limit the maximum jerk of the vehicle (how fast the acceleration can change).
 * A lower value leads to smoother vehicle motions, but it also limits its
 * agility (how fast it can change directions or break).
 *
 * Setting this to the maximum value essentially disables the limit.
 *
 * Note: This is only used in Pilot mode.
 *
 * @unit m/s^3
 * @min 0.5
 * @max 500.0
 * @increment 1
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_JERK_MAX, 100.0f);

/**
 * Minimum z-axis acceleration (The norm is the maximum upward acceleration) in velocity controlled modes
 *
 * @unit m/s^2
 * @min -20.0
 * @max -2.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_ACCEL_LOW, -13.1f);

/**
 * Maximum z-axis acceleration (The norm is the maximum downward acceleration) in velocity controlled modes
 *
 * @unit m/s^2
 * @min 2.0
 * @max 10.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_ACCEL_UP, 6.8f);

/**
 * Maximum jerk limit on z-axis
 *
 * Limit the maximum jerk of the vehicle (how fast the acceleration can change).
 * A lower value leads to smoother vehicle motions, but it also limits its
 * agility (how fast it can change directions or break).
 *
 * Setting this to the maximum value essentially disables the limit.
 *
 * Note: This is only used in Pilot mode.
 *
 * @unit m/s^3
 * @min 0.5
 * @max 500.0
 * @increment 1
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_JERK_MAX, 100.0f);

/**
 * Feedforward gain for x-axis velocity in Offboard mode
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_FF, 1.0f);

/**
 * Feedforward gain for y-axis velocity in Offboard mode
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_FF, 1.0f);

/**
 * Feedforward gain for z-axis velocity in Offboard mode
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_FF, 1.0f);

/**
 * Proportional gain for x-axis position error
 *
 * @min 0.0
 * @max 2.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_P, 0.2f);

/**
 * Proportional gain for x-axis velocity error in heading coordinate in Pilot mode, in NED coordinate in Pilot mode.
 *
 * defined as correction acceleration in m/s^2 per m/s velocity error
 *
 * @min 1.0
 * @max 5.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_VEL_P, 1.0f);

/**
 * Integral gain for x-axis velocity error
 *
 * defined as correction acceleration in m/s^2 per m velocity integral
 * Non-zero value allows to eliminate steady state errors in the presence of disturbances like wind.
 *
 * @min 0.0
 * @max 60.0
 * @decimal 3
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_VEL_I, 0.3f);

/**
 * Differential gain for x-axis velocity error.
 *
 * defined as correction acceleration in m/s^2 per m/s^2 velocity derivative
 *
 * @min 0.0
 * @max 2.0
 * @decimal 3
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_VEL_D, 0.0f);

/**
 * Filter coefficients for x-axis velocity error differentiation
 *
 * @min 0.0
 * @max 100.0
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_VEL_N, 1.0f);

/**
 * Proportional gain for y-axis position error
 *
 * @min 0.0
 * @max 2.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_P, 0.2f);

/**
 * Proportional gain for y-axis velocity error in heading coordinate in Pilot mode, in NED coordinate in Pilot mode.
 *
 * defined as correction acceleration in m/s^2 per m/s velocity error
 *
 * @min 1.0
 * @max 5.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_VEL_P, 1.0f);

/**
 * Integral gain for y-axis velocity error
 *
 * defined as correction acceleration in m/s^2 per m velocity integral
 * Non-zero value allows to eliminate steady state errors in the presence of disturbances like wind.
 *
 * @min 0.0
 * @max 60.0
 * @decimal 3
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_VEL_I, 0.3f);

/**
 * Differential gain for y-axis velocity error.
 *
 * defined as correction acceleration in m/s^2 per m/s^2 velocity derivative
 *
 * @min 0.0
 * @max 2.0
 * @decimal 3
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_VEL_D, 0.0f);

/**
 * Filter coefficients for y-axis velocity error differentiation
 *
 * @min 0.0
 * @max 100.0
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_VEL_N, 10.0f);

/**
 * Proportional gain for vertical position error
 *
 * @min 0.0
 * @max 3.5
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_P, 0.8f);
/**
 * Proportional gain for vertical velocity error
 *
 * defined as correction acceleration in m/s^2 per m/s velocity error
 *
 * @min 1.0
 * @max 15.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_VEL_P, 3.0f);

/**
 * Integral gain for vertical velocity error
 *
 * defined as correction acceleration in m/s^2 per m velocity integral
 *
 *
 * @min 0.0
 * @max 3.0
 * @decimal 3
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_VEL_I, 0.3f);

/**
 * Differential gain for vertical velocity error
 *
 * defined as correction acceleration in m/s^2 per m/s^2 velocity derivative
 *
 * @min 0.0
 * @max 2.0
 * @decimal 3
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_VEL_D, 0.0f);

/**
 * Filter coefficients for vertical velocity error differentiation
 *
 *
 * @min 1.0
 * @max 100.0
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_VEL_N, 1.0f);

/**
 * Feedforward gain for x-axis acceleration in Offboard mode
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_ACCX_FF, 1.0f);

/**
 * Feedforward gain for y-axis acceleration in Offboard mode
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_ACCY_FF, 1.0f);

/**
 * Feedforward gain for z-axis acceleration in Offboard mode
 *
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_ACCZ_FF, 1.0f);

/**
 * The cut-off frequency of low-pass filtering for ideal differentiators for Smith predictor in Offboard mode
 *
 * The low-pass filtering cutoff frequency of the ideal differentiator. When fz=0, x_ Out=x_ In.
 *
 * @min 0.0
 * @max 200.0
 * @unit Hz
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_ACCSP_FZ, 0.0f);

/**
 * Prediction time of acceleration control command for Smith predictor in Offboard mode
 *
 * Prediction time of acceleration control command for Smith predictor. When Tm=0, the low-pass filtering with a cutoff frequency of fz is performed on x_in.
 *
 * @min 0.0
 * @max 1.0
 * @unit s
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_ACCSP_TM, 0.0f);



/**
 * Rocker center dead zone for x-axis velocity
 *
 * @min 0.0
 * @max 0.5
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_X_VEL_DZ, 0.1f);

/**
 * Rocker center dead zone for y-axis velocity
 *
 * @min 0.0
 * @max 0.5
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Y_VEL_DZ, 0.1f);

/**
 * Rocker center dead zone for x-axis velocity
 *
 * @min 0.0
 * @max 0.5
 * @decimal 2
 * @group LW Position Control
 */
PARAM_DEFINE_FLOAT(LW_Z_VEL_DZ, 0.1f);

//******************************************************************************************************************//
//*****************************************************offboard*****************************************************//
//******************************************************************************************************************//
/**
 * Turnoff yaw control when Va>6m/s.
 *
 * @min 0.0
 * @max 1.0
 * @group LW Offboard
 */
PARAM_DEFINE_FLOAT(LW_OFFYAW, 0.0f);

/**
 * Choose between different trajectories
 *
 * @min 0.0
 * @max 2.0
 * @group LW Offboard
 */
PARAM_DEFINE_FLOAT(LW_OB_TYPE, 0.0f);

/**
 * Radius for circular trajectory; desired heading(rad) for linear trajectory
 *
 * @min 0.0
 * @decimal 2
 * @group LW Offboard
 */
PARAM_DEFINE_FLOAT(LW_OB_CIRCLE_R, 2.8f);

/**
 * Desired maximum velocity for trajectory
 *
 * @min 0.0
 * @max 30.0
 * @decimal 2
 * @group LW Offboard
 */
PARAM_DEFINE_FLOAT(LW_OB_CIRCLE_V, 10.0f);

/**
 * Angular velocity(rad/s) for circular trajectory and time to maintain(s) the maximum velocity for linear trajectory
 *
 * @min 0.0
 * @decimal 2
 * @group LW Offboard
 */
PARAM_DEFINE_FLOAT(LW_OB_CIRCLE_W, 3.0f);

/**
 * Not used
 *
 * @min 0.0
 * @decimal 2
 * @group LW Offboard
 */
PARAM_DEFINE_FLOAT(LW_LAT_CIRCLE, 1.0f);








