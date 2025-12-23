/*
 * File: LW_ctrl_241029_1.c
 *
 * Code generated for Simulink model 'LW_ctrl_241029_1'.
 *
 * Model version                  : 10.91
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Dec 23 11:47:06 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LW_ctrl_241029_1.h"
#include "rtwtypes.h"
#include "LW_ctrl_241029_1_types.h"
#include "LW_ctrl_241029_1_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>
#include "rt_defines.h"

/* Exported data definition */

/* Definition of data with custom storage class MTD */
real32_T LW_ACCSP_FZ = 5.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_ACCSP_TM = 0.1F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_ACCX_FF = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_ACCY_FF = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_ACCZ_FF = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_ACRO_P_MAX = 360.0F;

/* Referenced by:
 * '<S370>/Gain7'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_ACRO_R_MAX = 360.0F;

/* Referenced by:
 * '<S370>/Gain6'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_ACRO_Y_MAX = 200.0F;

/* Referenced by:
 * '<S370>/Gain2'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_AERO_C0 = 0.1F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S403>/df,coor,wind'
 */
real32_T LW_AERO_C1 = 2.4F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S403>/df,coor,wind'
 */
real32_T LW_AERO_COM = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_AERO_Y0 = 1.3F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S403>/df,coor,wind'
 */
real32_T LW_ANGLE = 34.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 * '<S419>/getIncid'
 * '<S403>/df,coor,wind'
 */
real32_T LW_COOR_TURN = 0.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_DMZ0 = 0.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_DMZ_MIN = 0.01F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_DSER = 0.2F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_DTHR = 0.3F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_DT = 0.01F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_EN = 0.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_LAMXY = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_LAMZ = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_P = 0.9F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_SIGXY = 20.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_SIGZ = 10.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_TDT = 0.02F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_WNXY = 2.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_FEST_WNZ = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_F_MAP = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_LAT_CIRCLE = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_LBCL_D = 0.12F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_LBCM_D = -0.2F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_LED = 0.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/LW_LED'
 */
real32_T LW_MAN_PITCH_DZ = 0.05F;

/* Referenced by:
 * '<S370>/pitch_deadzone'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_MAN_PITCH_MAX = 35.0F;

/* Referenced by:
 * '<S370>/man_pitch_max'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_MAN_ROLL_DZ = 0.05F;

/* Referenced by:
 * '<S370>/roll_deadzone'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_MAN_ROLL_MAX = 35.0F;

/* Referenced by:
 * '<S370>/man_roll_max'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_MAN_WX_DZ = 0.01F;

/* Referenced by:
 * '<S370>/rollrate_deadzone'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_MAN_WY_DZ = 0.01F;

/* Referenced by:
 * '<S370>/pitchrate_deadzone'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_MAN_WZ_DZ = 0.01F;

/* Referenced by:
 * '<S370>/yawrate_deadzone'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_MASS = 2.1F;

/* Referenced by:
 * '<S370>/Gain4'
 * '<S361>/MATLAB Function2'
 * '<S14>/Constant'
 * '<S403>/df,coor,wind'
 */
real32_T LW_MIXER_GAM = 1000.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_OB_CIRCLE_R = 5.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S403>/task'
 */
real32_T LW_OB_CIRCLE_V = 3.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S403>/task'
 */
real32_T LW_OB_CIRCLE_W = 0.01F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S403>/task'
 */
real32_T LW_OB_TYPE = 0.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S403>/task'
 */
real32_T LW_PITCH_P = 4.5F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_REX_YAW = 0.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_ROLL_P = 5.5F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_SERVOL_MAX = 20.0F;

/* Referenced by:
 * '<S370>/Gain3'
 * '<S370>/Gain8'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_SERVOL_MIN = -20.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_SERVOL_REV = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_SERVOR_CON = 0.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_SERVOR_MAX = 20.0F;

/* Referenced by:
 * '<S370>/Gain3'
 * '<S370>/Gain8'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_SERVOR_MIN = -20.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_SERVOR_REV = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_SER_LP = 5.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_TAUXYSP_FZ = 30.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_TAUXYSP_TM = 0.01F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_TAUZSP_FZ = 5.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_TAUZSP_TM = 0.01F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_TEST_DTXY = 0.01F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/Lowpass'
 */
real32_T LW_TEST_DTZ = 0.01F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/Lowpass'
 */
real32_T LW_TEST_EN = 0.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_TEST_LAMXY = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_TEST_LAMZ = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_TEST_SIGXY = 10.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_TEST_SIGZ = 10.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_TEST_TDT = 0.02F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_TEST_WBDT = 0.05F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/Lowpass1'
 */
real32_T LW_TEST_WNXY = 80.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_TEST_WNZ = 10.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_THR_HOVER = 0.3F;

/* Referenced by:
 * '<S370>/Constant2'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_THR_LOW = 0.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_TILTMAX_AIR = 30.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_USE_SER = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S419>/DisturbanceEstimator'
 */
real32_T LW_VA_TMAX = 10.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_VA_TMIN = 6.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_VEL_DT = 0.01F;

/* Referenced by:
 * '<S370>/Lowpass'
 * '<S370>/Lowpass1'
 * '<S370>/Lowpass2'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_WX_D = 0.001F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WX_FF = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WX_I = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WX_MAX = 80.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WX_N = 100.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WX_P = 20.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WY_D = 0.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WY_DE_MAX = 20.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WY_FF = 1.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WY_I = 5.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WY_MAX = 80.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WY_N = 10.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WY_P = 35.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WZ_D = 0.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WZ_FF = 0.7F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WZ_I = 10.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WZ_MAX = 80.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_WZ_N = 100.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_WZ_P = 30.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_W_FZ = 200.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_W_SER = 500.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_W_SERH = 5.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_W_TAOX = 10.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_W_TAOY = 10.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_W_TAOZ = 5.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_X_ACCEL_MAX = 4.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S239>/Saturation'
 * '<S224>/DeadZone'
 */
real32_T LW_X_ACCEL_MIN = -4.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S239>/Saturation'
 * '<S224>/DeadZone'
 */
real32_T LW_X_FF = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_X_JERK_MAX = 10.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_X_P = 0.5F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_X_VEL_D = 0.1F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_X_VEL_DZ = 0.1F;

/* Referenced by:
 * '<S370>/vx_deadzone'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_X_VEL_I = 0.2F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_X_VEL_MAX = 20.0F;

/* Referenced by:
 * '<S370>/max_vx'
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_X_VEL_N = 100.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_X_VEL_P = 2.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_YAW_KAD = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_YAW_KAP = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_YAW_P = 4.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_Y_ACCEL_MAX = 4.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 * '<S293>/Saturation'
 * '<S278>/DeadZone'
 */
real32_T LW_Y_ACCEL_MIN = -4.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S293>/Saturation'
 * '<S278>/DeadZone'
 */
real32_T LW_Y_FF = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_Y_JERK_MAX = 10.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_Y_P = 0.5F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_Y_VEL_D = 0.01F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_Y_VEL_DZ = 0.1F;

/* Referenced by:
 * '<S370>/vy_deadzone'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_Y_VEL_I = 0.2F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_Y_VEL_MAX = 20.0F;

/* Referenced by:
 * '<S370>/max_vy'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_Y_VEL_N = 100.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_Y_VEL_P = 2.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_Z_ACCEL_LOW = -11.8689404F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S347>/Saturation'
 * '<S332>/DeadZone'
 */
real32_T LW_Z_ACCEL_UP = 6.8F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S347>/Saturation'
 * '<S332>/DeadZone'
 */
real32_T LW_Z_FF = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_Z_JERK_MAX = 10.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_Z_P = 1.5F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_Z_VEL_D = 0.1F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_Z_VEL_DZ = 0.1F;

/* Referenced by:
 * '<S370>/vz_deadzone'
 * '<S361>/MATLAB Function2'
 */
real32_T LW_Z_VEL_I = 0.3F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_Z_VEL_MAX_UP = 3.0F;

/* Referenced by:
 * '<S370>/max_vz'
 * '<S361>/MATLAB Function2'
 * '<S12>/position control'
 */
real32_T LW_Z_VEL_N = 100.0F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T LW_Z_VEL_P = 5.5F;

/* Referenced by: '<S361>/MATLAB Function2' */
real32_T RC1_MAX = 1950.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC1_MIN = 1050.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC1_REV = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC2_MAX = 1950.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC2_MIN = 1050.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC2_REV = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC3_MAX = 1950.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC3_MIN = 1050.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC3_REV = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC4_MAX = 1950.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC4_MIN = 1050.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */
real32_T RC4_REV = 1.0F;

/* Referenced by:
 * '<S361>/MATLAB Function2'
 * '<S407>/MATLAB Function'
 */

/* Block signals (default storage) */
B_LW_ctrl_241029_1_T LW_ctrl_241029_1_B;

/* Block states (default storage) */
DW_LW_ctrl_241029_1_T LW_ctrl_241029_1_DW;

/* Real-time model */
static RT_MODEL_LW_ctrl_241029_1_T LW_ctrl_241029_1_M_;
RT_MODEL_LW_ctrl_241029_1_T *const LW_ctrl_241029_1_M = &LW_ctrl_241029_1_M_;

/* Forward declaration for local functions */
static void LW_ctrl_241029_1_quatmultiply(const real32_T q[4], const real32_T r
  [4], real32_T qout[4]);
static void LW_ctrl_241029_1_quatnormalize(real32_T q[4]);
static void LW_ctrl_241029_1_eye(real_T b_I[9]);
static void LW_ctrl_241029_1_LowPass(real32_T d_est[6], real32_T DT);
static void LW_ctrl_241029_1_cross(const real32_T a[3], const real32_T b[3],
  real32_T c[3]);
static void LW_ctrl_241029_1_eye_b(real_T b_I[16]);
static boolean_T LW_ctrl_241029_1_notInfNan(const real32_T data[4]);
static void LW_ctrl_241029_1_my_quat2eul(const real32_T q[4], real32_T eul[3]);
static boolean_T LW_ctrl_241029_1_notInfNan_p(const real32_T data[3]);
static void LW_ctrl_241029_1_AdmittanceYaw(real32_T dmz, real32_T yaw, real32_T
  dot_yaw, real32_T dt, real32_T dmz0, real32_T dmz_min, real32_T k_ap, real32_T
  k_ad, real_T reset, real32_T *yaw_ref, real32_T *dot_yaw_ref);
static void LW_ctrl_241029_1_TD_3DVector(const real32_T v[3], const real32_T r[3],
  real32_T h, real32_T v1_[3], real32_T v2_[3]);
static void LW_ctrl_241029_1_my_quat2eul_k(const real32_T q[4], real32_T eul[3]);
static real_T LW_ctrl_241029_1_prod(const real_T x_data[], const int32_T x_size
  [2]);
static real_T LW_ctrl_241029_1_poly_val(const real_T poly[8], real_T t);
static void LW_ctrl_241029_1_task1(real32_T timestamp, FlightMode flight_mode,
  const real32_T pos[3], const real32_T q[4], real32_T pos_ref[3], real32_T
  vel_ref[3], real32_T acc_ref[3], real32_T dot3x[3], real32_T *yaw_ref,
  real32_T *dotpsi);
static real32_T LW_ctrl_241029_1_norm(const real32_T x[3]);
static void LW_ctrl_241029_1_task5(real32_T timestamp, FlightMode flight_mode,
  const real32_T pos[3], const real32_T q[4], real32_T pos_ref[3], real32_T
  vel_ref[3], real32_T acc_ref[3], real32_T dot3x[3], real32_T *yaw_ref,
  real32_T *dotpsi);
static real32_T LW_ctrl_241029_1_rcNormalize(real32_T ch, real32_T RC_MIN,
  real32_T RC_MAX, real32_T RC_REV, real32_T DEADZONE_RATE);

/*
 * System initialize for atomic system:
 *    '<S370>/Lowpass'
 *    '<S370>/Lowpass1'
 *    '<S370>/Lowpass2'
 */
void LW_ctrl_241029_1_Lowpass_Init(DW_Lowpass_LW_ctrl_241029_1_T *localDW)
{
  localDW->data_last_not_empty = false;
}

/*
 * Output and update for atomic system:
 *    '<S370>/Lowpass'
 *    '<S370>/Lowpass1'
 *    '<S370>/Lowpass2'
 */
void LW_ctrl_241029_1_Lowpass(B_Lowpass_LW_ctrl_241029_1_T *localB,
  DW_Lowpass_LW_ctrl_241029_1_T *localDW)
{
  /* MATLAB Function 'navigator/navigator_manual/Lowpass': '<S375>:1' */
  /* '<S375>:1:3' if isempty(data_last) */
  if (!localDW->data_last_not_empty) {
    /* '<S375>:1:4' data_last = data_in; */
    localDW->data_last = localB->data_in;
    localDW->data_last_not_empty = true;
  }

  /* '<S375>:1:6' if isInfNan(data_last) */
  /* ISINFNAN 此处显示有关此函数的摘要 */
  /*    Data is a vector. */
  /* 'isInfNan:4' for ii = 1:length(data) */
  /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
  if (rtIsInfF(localDW->data_last) || rtIsNaNF(localDW->data_last)) {
    /* 'isInfNan:6' y = true; */
    /* '<S375>:1:7' data_last = single(0); */
    localDW->data_last = 0.0F;
  } else {
    /* 'isInfNan:8' else */
    /* 'isInfNan:9' y = false; */
  }

  /* '<S375>:1:10' data_in = data_last + LW_VEL_DT*(data_in - data_last); */
  localB->data_in = (localB->data_in - localDW->data_last) * LW_VEL_DT +
    localDW->data_last;

  /* '<S375>:1:11' data_last = data_in; */
  localDW->data_last = localB->data_in;
}

/*
 * Output and update for atomic system:
 *    '<S370>/nan_inf0'
 *    '<S370>/nan_inf1'
 *    '<S370>/nan_inf10'
 *    '<S370>/nan_inf11'
 *    '<S370>/nan_inf2'
 *    '<S370>/nan_inf3'
 *    '<S370>/nan_inf4'
 *    '<S370>/nan_inf5'
 *    '<S370>/nan_inf6'
 *    '<S370>/nan_inf7'
 *    ...
 */
void LW_ctrl_241029_1_nan_inf0(real32_T rtu_u, B_nan_inf0_LW_ctrl_241029_1_T
  *localB)
{
  localB->y = rtu_u;

  /* MATLAB Function 'navigator/navigator_manual/nan_inf0': '<S379>:1' */
  /* '<S379>:1:3' for i = 1:length(u) */
  /* '<S379>:1:4' if isnan(u(i)) || isinf(u(i)) */
  if (rtIsNaNF(rtu_u) || rtIsInfF(rtu_u)) {
    /* '<S379>:1:5' u(i) = single(0); */
    localB->y = 0.0F;
  }

  /* '<S379>:1:8' y = u; */
}

/*
 * Output and update for atomic system:
 *    '<S370>/pitchrate_deadzone1'
 *    '<S370>/rollrate_deadzone1'
 *    '<S370>/yawrate_deadzone1'
 */
void LW_ctrl_241_pitchrate_deadzone1(real32_T rtu_u,
  B_pitchrate_deadzone1_LW_ctrl_T *localB)
{
  /* Function description: */
  /*   set a dead zone with a dead zone size of ±deadZone. */
  /* MATLAB Function 'navigator/navigator_manual/pitchrate_deadzone1': '<S393>:1' */
  /* '<S393>:1:4' RCMin = single(-1); */
  /* '<S393>:1:5' RCMax = single(1); */
  /* '<S393>:1:6' RCMid = ((RCMin + RCMax)/2); */
  /* '<S393>:1:7' deadZone = 0; */
  /* '<S393>:1:8' k = 1/(RCMax - RCMid - deadZone); */
  /* dead zone */
  /* '<S393>:1:11' if(u > RCMid + deadZone) */
  if (rtu_u > 0.0F) {
    /* '<S393>:1:12' y = single((u-RCMid - deadZone)*k); */
    localB->y = rtu_u;
  } else if (rtu_u < 0.0F) {
    /* '<S393>:1:13' elseif(u < RCMid - deadZone) */
    /* '<S393>:1:14' y = single((u - RCMid + deadZone)*k); */
    localB->y = rtu_u;
  } else {
    /* '<S393>:1:15' else */
    /* '<S393>:1:16' y = single(0); */
    localB->y = 0.0F;
  }
}

/*
 * System initialize for atomic system:
 *    '<S372>/hrt_timestamp'
 *    '<S415>/hrt_timestamp'
 *    '<S409>/hrt_timestamp'
 */
void LW_ctrl_2410_hrt_timestamp_Init(DW_hrt_timestamp_LW_ctrl_2410_T *localDW)
{
  /* '<S374>:1:5' count = 0; */
  localDW->count = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S372>/hrt_timestamp'
 *    '<S415>/hrt_timestamp'
 *    '<S409>/hrt_timestamp'
 */
void LW_ctrl_241029_1_hrt_timestamp(B_hrt_timestamp_LW_ctrl_24102_T *localB,
  DW_hrt_timestamp_LW_ctrl_2410_T *localDW)
{
  /*  coder.cinclude('drivers/drv_hrt.h'); */
  /* MATLAB Function 'navigator/logger/HIL&FLY/hrt_timestamp': '<S374>:1' */
  /* '<S374>:1:4' if isempty(count) */
  /* '<S374>:1:8' hrt = 0; */
  /* '<S374>:1:9' if coder.target('Rtw') */
  /* '<S374>:1:10' hrt = coder.ceval('hrt_absolute_time'); */
  profileStart_LW_ctrl_241029_1(1U); /* original_line:916 */localB->ts = hrt_absolute_time();profileEnd_LW_ctrl_241029_1(1U); /* original_line:916 */

  /* '<S374>:1:14' ts = hrt; */
  /*  us */
  /* '<S374>:1:16' count = count + 1; */
  localDW->count++;
}

/*
 * Output and update for atomic system:
 *    '<S419>/nan_inf'
 *    '<S419>/nan_inf1'
 */
void LW_ctrl_241029_1_nan_inf(real32_T rtu_u, real32_T rtu_u_i, real32_T rtu_u_j,
  B_nan_inf_LW_ctrl_241029_1_T *localB)
{
  int32_T i;

  /* SignalConversion generated from: '<S426>/ SFunction ' */
  localB->y[0] = rtu_u;
  localB->y[1] = rtu_u_i;
  localB->y[2] = rtu_u_j;

  /* MATLAB Function 'states_update/vehicle_local_position/HIL&FLY V1.13.3/nan_inf': '<S426>:1' */
  /* '<S426>:1:3' for i = 1:length(u) */
  for (i = 0; i < 3; i++) {
    /* '<S426>:1:4' if isnan(u(i)) || isinf(u(i)) */
    if (rtIsNaNF(localB->y[i]) || rtIsInfF(localB->y[i])) {
      /* '<S426>:1:5' u(i) = single(0); */
      localB->y[i] = 0.0F;
    }
  }

  /* '<S426>:1:8' y = u; */
}

/* Function for MATLAB Function: '<S419>/DisturbanceEstimator' */
static void LW_ctrl_241029_1_quatmultiply(const real32_T q[4], const real32_T r
  [4], real32_T qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - r[2] * q[3]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (r[1] * q[3] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - r[1] * q[2]);
}

/* Function for MATLAB Function: '<S419>/DisturbanceEstimator' */
static void LW_ctrl_241029_1_quatnormalize(real32_T q[4])
{
  real32_T qm;
  profileStart_LW_ctrl_241029_1(234U); /* original_line:966 */qm = (real32_T)sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) + q[3] * q[3]);profileEnd_LW_ctrl_241029_1(234U); /* original_line:966 */
  q[0] /= qm;
  q[1] /= qm;
  q[2] /= qm;
  q[3] /= qm;
}

/*
 * Function for MATLAB Function: '<S419>/DisturbanceEstimator'
 * function y = wrap_pi(x)
 * 将 x 限定在[-pi,pi]
 */
real32_T LW_ctrl_241029_1_wrap_pi(real32_T x)
{
  int32_T i;
  real32_T y;
  boolean_T exitg1;

  /* 'wrap_pi:3' i = 0; */
  i = 0;

  /* 'wrap_pi:4' y = x; */
  y = x;

  /* 'wrap_pi:5' while x > pi */
  exitg1 = false;
  while ((!exitg1) && (x > 3.1415926535897931)) {
    /* 'wrap_pi:6' y =  x - 2*pi; */
    y = x - 6.28318548F;

    /* 'wrap_pi:7' i = i + 1; */
    i++;

    /* 'wrap_pi:8' if i > 100 */
    if (i > 100) {
      exitg1 = true;
    }
  }

  /* 'wrap_pi:12' i = 0; */
  i = 0;

  /* 'wrap_pi:13' while x < -pi */
  exitg1 = false;
  while ((!exitg1) && (x < -3.1415926535897931)) {
    /* 'wrap_pi:14' y =  x + 2*pi; */
    y = x + 6.28318548F;

    /* 'wrap_pi:15' i = i + 1; */
    i++;

    /* 'wrap_pi:16' if i > 100 */
    if (i > 100) {
      exitg1 = true;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S419>/DisturbanceEstimator' */
static void LW_ctrl_241029_1_eye(real_T b_I[9])
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    b_I[i] = 0.0;
  }

  b_I[0] = 1.0;
  b_I[4] = 1.0;
  b_I[8] = 1.0;
}

/*
 * Function for MATLAB Function: '<S419>/DisturbanceEstimator'
 * function d_est = LowPass(d_est,DT)
 *  DT = dt/(dt + Ts)
 *  其中dt是采样周期，Ts是低通滤波器的时间常数
 *  截止频率f = 1/Ts/2pi Hz
 *  如 dt=0.004, f=30Hz , LW_TEST_DT=0.43
 */
static void LW_ctrl_241029_1_LowPass(real32_T d_est[6], real32_T DT)
{
  int32_T i;
  real32_T d_est_last_p;
  boolean_T exitg1;
  boolean_T y;

  /* '<S420>:1:173' if isempty(d_est_last) */
  if (!LW_ctrl_241029_1_DW.d_est_last_not_empty_h) {
    /* '<S420>:1:174' d_est_last = d_est; */
    for (i = 0; i < 6; i++) {
      LW_ctrl_241029_1_DW.d_est_last_p[i] = d_est[i];
    }

    LW_ctrl_241029_1_DW.d_est_last_not_empty_h = true;
  }

  /* '<S420>:1:176' if isInfNan(d_est_last) */
  /* ISINFNAN 此处显示有关此函数的摘要 */
  /*    Data is a vector. */
  /* 'isInfNan:4' for ii = 1:length(data) */
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 6)) {
    /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
    if (rtIsInfF(LW_ctrl_241029_1_DW.d_est_last_p[i]) || rtIsNaNF
        (LW_ctrl_241029_1_DW.d_est_last_p[i])) {
      /* 'isInfNan:6' y = true; */
      y = true;
      exitg1 = true;
    } else {
      /* 'isInfNan:8' else */
      /* 'isInfNan:9' y = false; */
      y = false;
      i++;
    }
  }

  if (y) {
    /* '<S420>:1:177' d_est_last = zeros(size(d_est),'single'); */
    for (i = 0; i < 6; i++) {
      LW_ctrl_241029_1_DW.d_est_last_p[i] = 0.0F;
    }
  }

  /* '<S420>:1:179' d_est = d_est_last + DT*(d_est - d_est_last); */
  /* '<S420>:1:180' d_est_last = d_est; */
  for (i = 0; i < 6; i++) {
    d_est_last_p = LW_ctrl_241029_1_DW.d_est_last_p[i];
    d_est_last_p += (d_est[i] - d_est_last_p) * DT;
    d_est[i] = d_est_last_p;
    LW_ctrl_241029_1_DW.d_est_last_p[i] = d_est_last_p;
  }
}

/* Function for MATLAB Function: '<S419>/DisturbanceEstimator' */
static void LW_ctrl_241029_1_cross(const real32_T a[3], const real32_T b[3],
  real32_T c[3])
{
  c[0] = a[1] * b[2] - b[1] * a[2];
  c[1] = b[0] * a[2] - a[0] * b[2];
  c[2] = a[0] * b[1] - b[0] * a[1];
}

/* Function for MATLAB Function: '<S419>/DisturbanceEstimator' */
static void LW_ctrl_241029_1_eye_b(real_T b_I[16])
{
  profileStart_LW_ctrl_241029_1(233U); /* original_line:1114 */memset(&b_I[0], 0, sizeof(real_T) << 4U);profileEnd_LW_ctrl_241029_1(233U); /* original_line:1114 */
  b_I[0] = 1.0;
  b_I[5] = 1.0;
  b_I[10] = 1.0;
  b_I[15] = 1.0;
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  int32_T tmp;
  int32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = (real32_T)atan2((real32_T)tmp, (real32_T)tmp_0);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2(u0, u1);
  }

  return y;
}

/*
 * Function for MATLAB Function: '<S12>/position control'
 * function y = notInfNan(data)
 * ISINFNAN 此处显示有关此函数的摘要
 *    Data is a vector.
 */
static boolean_T LW_ctrl_241029_1_notInfNan(const real32_T data[4])
{
  int32_T ii;
  boolean_T exitg1;
  boolean_T y;

  /* 'notInfNan:4' y = false; */
  y = false;

  /* 'notInfNan:5' for ii = 1:length(data) */
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 4)) {
    /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
    if (rtIsInfF(data[ii]) || rtIsNaNF(data[ii])) {
      /* 'notInfNan:7' y = false; */
      y = false;
      exitg1 = true;
    } else {
      /* 'notInfNan:9' else */
      /* 'notInfNan:10' y = true; */
      y = true;
      ii++;
    }
  }

  return y;
}

/*
 * Function for MATLAB Function: '<S12>/position control'
 * function eul = my_quat2eul(q, varargin)
 * MY_QUAT2EUL Convert quaternion to Euler angles, modified from quat2eul.m
 *    EUL = QUAT2EUL(QOBJ) converts a quaternion object, QOBJ, into the
 *    corresponding Euler angles, EUL.QOBJ is an 4-element vector of quaternion objects.
 *    The output, EUL, is an 3-element vector of Euler rotation angles,that is [roll;pitch;yaw]. Rotation angles are in radians.
 */
static void LW_ctrl_241029_1_my_quat2eul(const real32_T q[4], real32_T eul[3])
{
  real32_T aSinInput;
  real32_T b_q_idx_0;
  real32_T b_q_idx_1;
  real32_T b_q_idx_2;
  real32_T b_q_idx_3;
  real32_T eul_tmp;
  real32_T eul_tmp_0;
  real32_T eul_tmp_1;
  real32_T eul_tmp_2;

  /* 'my_quat2eul:6' q = q(:); */
  /* 'my_quat2eul:7' if isempty(varargin) */
  /* 'my_quat2eul:10' else */
  /* 'my_quat2eul:11' seq = convertStringsToChars(varargin{1}); */
  /* 'my_quat2eul:13' q = robotics.internal.validation.validateQuaternion(q', 'quat2eul', 'q'); */
  /* norm_q = sqrt(q' * q); */
  /*  if norm_q < 0.5 */
  /*      q = [1;0;0;0]; */
  /*      norm_q = 1; */
  /*  end */
  /* q = q ./ norm_q; */
  /* 'my_quat2eul:20' q = robotics.internal.normalizeRows(q); */
  profileStart_LW_ctrl_241029_1(165U); /* original_line:1224 */aSinInput = 1.0F / (real32_T)sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2])
    + q[3] * q[3]);profileEnd_LW_ctrl_241029_1(165U); /* original_line:1225 */
  b_q_idx_0 = q[0] * aSinInput;
  b_q_idx_1 = q[1] * aSinInput;
  b_q_idx_2 = q[2] * aSinInput;
  b_q_idx_3 = q[3] * aSinInput;

  /* 'my_quat2eul:22' qw = q(1); */
  /* 'my_quat2eul:23' qx = q(2); */
  /* 'my_quat2eul:24' qy = q(3); */
  /* 'my_quat2eul:25' qz = q(4); */
  /*  Pre-allocate output */
  /* 'my_quat2eul:28' eul = single(zeros(3, 1,'like',q)); */
  /* 'my_quat2eul:29' upperSeq = upper(seq); */
  /* 'my_quat2eul:30' switch upperSeq */
  /* 'my_quat2eul:31' case 'ZYX' */
  /*  Cap all inputs to asin to 1, since values >1 produce complex */
  /*  results */
  /*  Since the quaternion is of unit length, this should never happen, */
  /*  but some code generation configuration seem to hit this edge case */
  /*  under some circumstances. */
  /* 'my_quat2eul:37' aSinInput = -2 * (qx .* qz - qw .* qy); */
  aSinInput = (b_q_idx_1 * b_q_idx_3 - b_q_idx_0 * b_q_idx_2) * -2.0F;

  /* 'my_quat2eul:38' if aSinInput > 1 */
  if (aSinInput > 1.0F) {
    /* 'my_quat2eul:39' aSinInput = single(1); */
    aSinInput = 1.0F;
  } else if (aSinInput < -1.0F) {
    /* 'my_quat2eul:40' elseif (aSinInput < -1) */
    /* 'my_quat2eul:41' aSinInput = -single(1); */
    aSinInput = -1.0F;
  }

  /* 'my_quat2eul:44' eul = [atan2( 2 * (qy .* qz + qw .* qx), qw .^ 2 - qx .^ 2 - qy .^ 2 + qz .^ 2 ); ... */
  /* 'my_quat2eul:45'             asin( aSinInput ); ... */
  /* 'my_quat2eul:46'             atan2( 2 * (qx .* qy + qw .* qz), qw .^ 2 + qx .^ 2 - qy .^ 2 - qz .^ 2 )]; */
  eul_tmp = b_q_idx_0 * b_q_idx_0;
  eul_tmp_0 = b_q_idx_1 * b_q_idx_1;
  eul_tmp_1 = b_q_idx_2 * b_q_idx_2;
  eul_tmp_2 = b_q_idx_3 * b_q_idx_3;
  profileStart_LW_ctrl_241029_1(166U); /* original_line:1265 */eul[0] = rt_atan2f_snf((b_q_idx_2 * b_q_idx_3 + b_q_idx_0 * b_q_idx_1) * 2.0F,
    ((eul_tmp - eul_tmp_0) - eul_tmp_1) + eul_tmp_2);profileEnd_LW_ctrl_241029_1(166U); /* original_line:1266 */
  profileStart_LW_ctrl_241029_1(167U); /* original_line:1267 */eul[1] = (real32_T)asin(aSinInput);profileEnd_LW_ctrl_241029_1(167U); /* original_line:1267 */
  profileStart_LW_ctrl_241029_1(168U); /* original_line:1268 */eul[2] = rt_atan2f_snf((b_q_idx_1 * b_q_idx_2 + b_q_idx_0 * b_q_idx_3) * 2.0F,
    ((eul_tmp + eul_tmp_0) - eul_tmp_1) - eul_tmp_2);profileEnd_LW_ctrl_241029_1(168U); /* original_line:1269 */

  /*  Check for complex numbers */
  /* 'my_quat2eul:93' if ~isreal(eul) */
}

/*
 * Function for MATLAB Function: '<S12>/position control'
 * function y = notInfNan(data)
 * ISINFNAN 此处显示有关此函数的摘要
 *    Data is a vector.
 */
static boolean_T LW_ctrl_241029_1_notInfNan_p(const real32_T data[3])
{
  int32_T ii;
  boolean_T exitg1;
  boolean_T y;

  /* 'notInfNan:4' y = false; */
  y = false;

  /* 'notInfNan:5' for ii = 1:length(data) */
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 3)) {
    /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
    if (rtIsInfF(data[ii]) || rtIsNaNF(data[ii])) {
      /* 'notInfNan:7' y = false; */
      y = false;
      exitg1 = true;
    } else {
      /* 'notInfNan:9' else */
      /* 'notInfNan:10' y = true; */
      y = true;
      ii++;
    }
  }

  return y;
}

/*
 * Function for MATLAB Function: '<S12>/position control'
 * function [yaw_ref, dot_yaw_ref] = AdmittanceYaw(dmz, yaw, dot_yaw, dt, dmz0, dmz_min, k_ap, k_ad, reset)
 *  偏航导纳控制
 *  误差形式：
 *  e = yaw_ref - yaw
 *  k_ap*e + k_ad*dote = dmz
 *  输入：
 *  dmz         - 估计偏航力矩扰动 d_m_est_z
 *  yaw         - 偏航角 \psi
 *  dot_yaw     - 偏航导数 \dot{\psi}
 *  dt          - 采样时间间隔
 *  输出：
 *  yaw_ref     - 期望偏航角
 *  dot_yaw_ref - 期望偏航角速率
 *  参数：
 *  k_ad        - 调节参数 k_{\text{ad}}
 *  k_ap        - 调节参数 k_{\text{ap}}
 */
static void LW_ctrl_241029_1_AdmittanceYaw(real32_T dmz, real32_T yaw, real32_T
  dot_yaw, real32_T dt, real32_T dmz0, real32_T dmz_min, real32_T k_ap, real32_T
  k_ad, real_T reset, real32_T *yaw_ref, real32_T *dot_yaw_ref)
{
  /* '<S187>:1:409' if isempty(yawerror_last) || isempty(yaw_ref_last) */
  if ((!LW_ctrl_241029_1_DW.yawerror_last_not_empty) ||
      (!LW_ctrl_241029_1_DW.yaw_ref_last_not_empty)) {
    /* '<S187>:1:410' yawerror_last = single(0); */
    LW_ctrl_241029_1_DW.yawerror_last = 0.0F;
    LW_ctrl_241029_1_DW.yawerror_last_not_empty = true;

    /* '<S187>:1:411' yaw_ref_last =  yaw; */
    LW_ctrl_241029_1_DW.yaw_ref_last = yaw;
    LW_ctrl_241029_1_DW.yaw_ref_last_not_empty = true;
  }

  /*  k_ap = 1; k_ad = 1.0; */
  /*  dmz0 = -0.023; */
  /* '<S187>:1:416' if reset > 0.5 */
  if (reset > 0.5) {
    /* '<S187>:1:417' yawerror_last = single(0); */
    LW_ctrl_241029_1_DW.yawerror_last = 0.0F;

    /* '<S187>:1:418' yaw_ref_last =  yaw; */
    LW_ctrl_241029_1_DW.yaw_ref_last = yaw;

    /* '<S187>:1:419' yaw_ref = yaw; */
    *yaw_ref = yaw;

    /* '<S187>:1:420' dot_yaw_ref = single(0); */
    *dot_yaw_ref = 0.0F;
  } else {
    /* '<S187>:1:421' else */
    /* '<S187>:1:422' dmz = dmz - dmz0; */
    dmz -= dmz0;

    /* '<S187>:1:423' if abs(dmz) <= dmz_min */
    if ((real32_T)fabs(dmz) <= dmz_min) {
      /* '<S187>:1:424' dmz = single(0); */
      dmz = 0.0F;
    }

    /* '<S187>:1:426' dot_yaw_ref = dot_yaw + 1/k_ad*(-k_ap*yawerror_last + dmz); */
    *dot_yaw_ref = (-k_ap * LW_ctrl_241029_1_DW.yawerror_last + dmz) * (1.0F /
      k_ad) + dot_yaw;

    /* '<S187>:1:427' yawerror_last = yawerror_last + (dot_yaw_ref - dot_yaw)*dt; */
    LW_ctrl_241029_1_DW.yawerror_last += (*dot_yaw_ref - dot_yaw) * dt;

    /* '<S187>:1:428' yaw_ref = yaw + yawerror_last; */
    *yaw_ref = yaw + LW_ctrl_241029_1_DW.yawerror_last;

    /* '<S187>:1:430' if abs(dmz) <= dmz_min */
    if ((real32_T)fabs(dmz) <= dmz_min) {
      /* '<S187>:1:431' yaw_ref = yaw_ref_last; */
      *yaw_ref = LW_ctrl_241029_1_DW.yaw_ref_last;
    } else {
      /* '<S187>:1:432' else */
      /* '<S187>:1:433' yaw_ref_last = yaw_ref; */
      LW_ctrl_241029_1_DW.yaw_ref_last = *yaw_ref;
    }
  }
}

/*
 * Function for MATLAB Function: '<S12>/position control'
 * function [v1_, v2_] = TD_3DVector(v, r, h)
 * v:[3,1]
 * r:[3,1]
 * h:1
 */
static void LW_ctrl_241029_1_TD_3DVector(const real32_T v[3], const real32_T r[3],
  real32_T h, real32_T v1_[3], real32_T v2_[3])
{
  int32_T i;
  real32_T a0_tmp;
  real32_T a2;
  real32_T d;
  real32_T d_tmp;
  real32_T fv;
  real32_T u;
  real32_T u_0;
  boolean_T exitg1;
  boolean_T y;

  /* '<S187>:1:466' if isempty(v1) || isempty(v2) */
  if ((!LW_ctrl_241029_1_DW.v1_not_empty) || (!LW_ctrl_241029_1_DW.v2_not_empty))
  {
    /* '<S187>:1:467' v1 = single([0;0;0]); */
    LW_ctrl_241029_1_DW.v1_not_empty = true;

    /* '<S187>:1:468' v2 = single([0;0;0]); */
    LW_ctrl_241029_1_DW.v1[0] = 0.0F;
    LW_ctrl_241029_1_DW.v2[0] = 0.0F;
    LW_ctrl_241029_1_DW.v1[1] = 0.0F;
    LW_ctrl_241029_1_DW.v2[1] = 0.0F;
    LW_ctrl_241029_1_DW.v1[2] = 0.0F;
    LW_ctrl_241029_1_DW.v2[2] = 0.0F;
    LW_ctrl_241029_1_DW.v2_not_empty = true;
  }

  /* '<S187>:1:470' v = single(v); */
  /* '<S187>:1:471' r = single(r); */
  /* '<S187>:1:472' h = single(h); */
  /* '<S187>:1:474' v1_ = v1; */
  /* '<S187>:1:475' v2_ = v2; */
  /* '<S187>:1:476' for i = 1:3 */
  /* '<S187>:1:477' fv = fhan(v1(i) - v(i), v2(i), r(i),  h); */
  /* '<S187>:1:490' d = r0*h0^2; */
  d_tmp = h * h;
  d = d_tmp * r[0];

  /* '<S187>:1:491' a0 = h0*x2; */
  a0_tmp = h * LW_ctrl_241029_1_DW.v2[0];

  /* '<S187>:1:492' y = x1 + a0; */
  fv = (LW_ctrl_241029_1_DW.v1[0] - v[0]) + a0_tmp;

  /* '<S187>:1:493' a1 = sqrt(d*(d + 8*abs(y))); */
  /* '<S187>:1:494' a2 = a0 + sign(y)*(a1 - d)/2; */
  if (rtIsNaNF(fv)) {
    u = (rtNaNF);
  } else if (fv < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(fv > 0.0F);
  }

  profileStart_LW_ctrl_241029_1(169U); /* original_line:1457 */a2 = ((real32_T)sqrt((8.0F * (real32_T)fabs(fv) + d) * d) - d) * u / 2.0F +
    a0_tmp;profileEnd_LW_ctrl_241029_1(169U); /* original_line:1458 */

  /* '<S187>:1:495' sy = (sign(y + d) - sign(y - d))/2; */
  /* fsg */
  /* '<S187>:1:496' a = (a0 + y -a2)*sy + a2; */
  u = fv + d;
  u_0 = fv - d;
  if (rtIsNaNF(u)) {
    u = (rtNaNF);
  } else if (u < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(u > 0.0F);
  }

  if (rtIsNaNF(u_0)) {
    u_0 = (rtNaNF);
  } else if (u_0 < 0.0F) {
    u_0 = -1.0F;
  } else {
    u_0 = (real32_T)(u_0 > 0.0F);
  }

  a2 += ((a0_tmp + fv) - a2) * ((u - u_0) / 2.0F);

  /* '<S187>:1:497' sa = (sign(a + d) - sign(a - d))/2; */
  /* '<S187>:1:498' y = -r0*(a/d - sign(a))*sa - r0*sign(a); */
  /* '<S187>:1:478' v1_(i) = v1(i) + h*v2(i); */
  v1_[0] = a0_tmp + LW_ctrl_241029_1_DW.v1[0];

  /* '<S187>:1:479' v2_(i) = v2(i) + h*fv; */
  if (rtIsNaNF(a2)) {
    fv = (rtNaNF);
  } else if (a2 < 0.0F) {
    fv = -1.0F;
  } else {
    fv = (real32_T)(a2 > 0.0F);
  }

  u = a2 + d;
  u_0 = a2 - d;
  if (rtIsNaNF(u)) {
    u = (rtNaNF);
  } else if (u < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(u > 0.0F);
  }

  if (rtIsNaNF(u_0)) {
    u_0 = (rtNaNF);
  } else if (u_0 < 0.0F) {
    u_0 = -1.0F;
  } else {
    u_0 = (real32_T)(u_0 > 0.0F);
  }

  v2_[0] = ((a2 / d - fv) * -r[0] * ((u - u_0) / 2.0F) - r[0] * fv) * h +
    LW_ctrl_241029_1_DW.v2[0];

  /* '<S187>:1:477' fv = fhan(v1(i) - v(i), v2(i), r(i),  h); */
  /* '<S187>:1:490' d = r0*h0^2; */
  d = d_tmp * r[1];

  /* '<S187>:1:491' a0 = h0*x2; */
  a0_tmp = h * LW_ctrl_241029_1_DW.v2[1];

  /* '<S187>:1:492' y = x1 + a0; */
  fv = (LW_ctrl_241029_1_DW.v1[1] - v[1]) + a0_tmp;

  /* '<S187>:1:493' a1 = sqrt(d*(d + 8*abs(y))); */
  /* '<S187>:1:494' a2 = a0 + sign(y)*(a1 - d)/2; */
  if (rtIsNaNF(fv)) {
    u = (rtNaNF);
  } else if (fv < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(fv > 0.0F);
  }

  profileStart_LW_ctrl_241029_1(170U); /* original_line:1538 */a2 = ((real32_T)sqrt((8.0F * (real32_T)fabs(fv) + d) * d) - d) * u / 2.0F +
    a0_tmp;profileEnd_LW_ctrl_241029_1(170U); /* original_line:1539 */

  /* '<S187>:1:495' sy = (sign(y + d) - sign(y - d))/2; */
  /* fsg */
  /* '<S187>:1:496' a = (a0 + y -a2)*sy + a2; */
  u = fv + d;
  u_0 = fv - d;
  if (rtIsNaNF(u)) {
    u = (rtNaNF);
  } else if (u < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(u > 0.0F);
  }

  if (rtIsNaNF(u_0)) {
    u_0 = (rtNaNF);
  } else if (u_0 < 0.0F) {
    u_0 = -1.0F;
  } else {
    u_0 = (real32_T)(u_0 > 0.0F);
  }

  a2 += ((a0_tmp + fv) - a2) * ((u - u_0) / 2.0F);

  /* '<S187>:1:497' sa = (sign(a + d) - sign(a - d))/2; */
  /* '<S187>:1:498' y = -r0*(a/d - sign(a))*sa - r0*sign(a); */
  /* '<S187>:1:478' v1_(i) = v1(i) + h*v2(i); */
  v1_[1] = a0_tmp + LW_ctrl_241029_1_DW.v1[1];

  /* '<S187>:1:479' v2_(i) = v2(i) + h*fv; */
  if (rtIsNaNF(a2)) {
    fv = (rtNaNF);
  } else if (a2 < 0.0F) {
    fv = -1.0F;
  } else {
    fv = (real32_T)(a2 > 0.0F);
  }

  u = a2 + d;
  u_0 = a2 - d;
  if (rtIsNaNF(u)) {
    u = (rtNaNF);
  } else if (u < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(u > 0.0F);
  }

  if (rtIsNaNF(u_0)) {
    u_0 = (rtNaNF);
  } else if (u_0 < 0.0F) {
    u_0 = -1.0F;
  } else {
    u_0 = (real32_T)(u_0 > 0.0F);
  }

  v2_[1] = ((a2 / d - fv) * -r[1] * ((u - u_0) / 2.0F) - r[1] * fv) * h +
    LW_ctrl_241029_1_DW.v2[1];

  /* '<S187>:1:477' fv = fhan(v1(i) - v(i), v2(i), r(i),  h); */
  /* '<S187>:1:490' d = r0*h0^2; */
  d = d_tmp * r[2];

  /* '<S187>:1:491' a0 = h0*x2; */
  a0_tmp = h * LW_ctrl_241029_1_DW.v2[2];

  /* '<S187>:1:492' y = x1 + a0; */
  fv = (LW_ctrl_241029_1_DW.v1[2] - v[2]) + a0_tmp;

  /* '<S187>:1:493' a1 = sqrt(d*(d + 8*abs(y))); */
  /* '<S187>:1:494' a2 = a0 + sign(y)*(a1 - d)/2; */
  if (rtIsNaNF(fv)) {
    u = (rtNaNF);
  } else if (fv < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(fv > 0.0F);
  }

  profileStart_LW_ctrl_241029_1(171U); /* original_line:1619 */a2 = ((real32_T)sqrt((8.0F * (real32_T)fabs(fv) + d) * d) - d) * u / 2.0F +
    a0_tmp;profileEnd_LW_ctrl_241029_1(171U); /* original_line:1620 */

  /* '<S187>:1:495' sy = (sign(y + d) - sign(y - d))/2; */
  /* fsg */
  /* '<S187>:1:496' a = (a0 + y -a2)*sy + a2; */
  u = fv + d;
  u_0 = fv - d;
  if (rtIsNaNF(u)) {
    u = (rtNaNF);
  } else if (u < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(u > 0.0F);
  }

  if (rtIsNaNF(u_0)) {
    u_0 = (rtNaNF);
  } else if (u_0 < 0.0F) {
    u_0 = -1.0F;
  } else {
    u_0 = (real32_T)(u_0 > 0.0F);
  }

  a2 += ((a0_tmp + fv) - a2) * ((u - u_0) / 2.0F);

  /* '<S187>:1:497' sa = (sign(a + d) - sign(a - d))/2; */
  /* '<S187>:1:498' y = -r0*(a/d - sign(a))*sa - r0*sign(a); */
  /* '<S187>:1:478' v1_(i) = v1(i) + h*v2(i); */
  v1_[2] = a0_tmp + LW_ctrl_241029_1_DW.v1[2];

  /* '<S187>:1:479' v2_(i) = v2(i) + h*fv; */
  if (rtIsNaNF(a2)) {
    fv = (rtNaNF);
  } else if (a2 < 0.0F) {
    fv = -1.0F;
  } else {
    fv = (real32_T)(a2 > 0.0F);
  }

  u = a2 + d;
  u_0 = a2 - d;
  if (rtIsNaNF(u)) {
    u = (rtNaNF);
  } else if (u < 0.0F) {
    u = -1.0F;
  } else {
    u = (real32_T)(u > 0.0F);
  }

  if (rtIsNaNF(u_0)) {
    u_0 = (rtNaNF);
  } else if (u_0 < 0.0F) {
    u_0 = -1.0F;
  } else {
    u_0 = (real32_T)(u_0 > 0.0F);
  }

  v2_[2] = ((a2 / d - fv) * -r[2] * ((u - u_0) / 2.0F) - r[2] * fv) * h +
    LW_ctrl_241029_1_DW.v2[2];

  /* '<S187>:1:482' if notInfNan(v1_) && notInfNan(v2_) */
  /* ISINFNAN 此处显示有关此函数的摘要 */
  /*    Data is a vector. */
  /* 'notInfNan:4' y = false; */
  y = false;

  /* 'notInfNan:5' for ii = 1:length(data) */
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 3)) {
    /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
    if (rtIsInfF(v1_[i]) || rtIsNaNF(v1_[i])) {
      /* 'notInfNan:7' y = false; */
      y = false;
      exitg1 = true;
    } else {
      /* 'notInfNan:9' else */
      /* 'notInfNan:10' y = true; */
      y = true;
      i++;
    }
  }

  if (y) {
    /* ISINFNAN 此处显示有关此函数的摘要 */
    /*    Data is a vector. */
    /* 'notInfNan:4' y = false; */
    y = false;

    /* 'notInfNan:5' for ii = 1:length(data) */
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
      if (rtIsInfF(v2_[i]) || rtIsNaNF(v2_[i])) {
        /* 'notInfNan:7' y = false; */
        y = false;
        exitg1 = true;
      } else {
        /* 'notInfNan:9' else */
        /* 'notInfNan:10' y = true; */
        y = true;
        i++;
      }
    }

    if (y) {
      /* '<S187>:1:483' v1 = v1_; */
      /* '<S187>:1:484' v2 = v2_; */
      LW_ctrl_241029_1_DW.v1[0] = v1_[0];
      LW_ctrl_241029_1_DW.v2[0] = v2_[0];
      LW_ctrl_241029_1_DW.v1[1] = v1_[1];
      LW_ctrl_241029_1_DW.v2[1] = v2_[1];
      LW_ctrl_241029_1_DW.v1[2] = v1_[2];
      LW_ctrl_241029_1_DW.v2[2] = v2_[2];
    }
  }
}

/*
 * Function for MATLAB Function: '<S403>/task'
 * function eul = my_quat2eul(q, varargin)
 * MY_QUAT2EUL Convert quaternion to Euler angles, modified from quat2eul.m
 *    EUL = QUAT2EUL(QOBJ) converts a quaternion object, QOBJ, into the
 *    corresponding Euler angles, EUL.QOBJ is an 4-element vector of quaternion objects.
 *    The output, EUL, is an 3-element vector of Euler rotation angles,that is [roll;pitch;yaw]. Rotation angles are in radians.
 */
static void LW_ctrl_241029_1_my_quat2eul_k(const real32_T q[4], real32_T eul[3])
{
  real32_T aSinInput;
  real32_T b_q_idx_0;
  real32_T b_q_idx_1;
  real32_T b_q_idx_2;
  real32_T b_q_idx_3;
  real32_T eul_tmp;
  real32_T eul_tmp_0;

  /* 'my_quat2eul:6' q = q(:); */
  /* 'my_quat2eul:7' if isempty(varargin) */
  /*  Use default rotation sequence */
  /* 'my_quat2eul:9' seq = 'ZXY'; */
  /* 'my_quat2eul:13' q = robotics.internal.validation.validateQuaternion(q', 'quat2eul', 'q'); */
  /* norm_q = sqrt(q' * q); */
  /*  if norm_q < 0.5 */
  /*      q = [1;0;0;0]; */
  /*      norm_q = 1; */
  /*  end */
  /* q = q ./ norm_q; */
  /* 'my_quat2eul:20' q = robotics.internal.normalizeRows(q); */
  profileStart_LW_ctrl_241029_1(204U); /* original_line:1769 */aSinInput = 1.0F / (real32_T)sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2])
    + q[3] * q[3]);profileEnd_LW_ctrl_241029_1(204U); /* original_line:1770 */
  b_q_idx_0 = q[0] * aSinInput;
  b_q_idx_1 = q[1] * aSinInput;
  b_q_idx_2 = q[2] * aSinInput;
  b_q_idx_3 = q[3] * aSinInput;

  /* 'my_quat2eul:22' qw = q(1); */
  /* 'my_quat2eul:23' qx = q(2); */
  /* 'my_quat2eul:24' qy = q(3); */
  /* 'my_quat2eul:25' qz = q(4); */
  /*  Pre-allocate output */
  /* 'my_quat2eul:28' eul = single(zeros(3, 1,'like',q)); */
  /* 'my_quat2eul:29' upperSeq = upper(seq); */
  /* 'my_quat2eul:30' switch upperSeq */
  /* 'my_quat2eul:72' case 'ZXY' */
  /* 'my_quat2eul:73' aSinInput = 2 * (qy .* qz + qw .* qx); */
  aSinInput = (b_q_idx_2 * b_q_idx_3 + b_q_idx_0 * b_q_idx_1) * 2.0F;

  /* 'my_quat2eul:74' if aSinInput > 1 */
  if (aSinInput > 1.0F) {
    /* 'my_quat2eul:75' aSinInput = single(1); */
    aSinInput = 1.0F;
  } else if (aSinInput < -1.0F) {
    /* 'my_quat2eul:76' elseif (aSinInput < -1) */
    /* 'my_quat2eul:77' aSinInput = -single(1); */
    aSinInput = -1.0F;
  }

  /* 'my_quat2eul:80' eul = [ asin( aSinInput ); ... */
  /* 'my_quat2eul:81'             atan2( -2 * (qx .* qz - qw .* qy), qw .^ 2 - qx .^ 2 - qy .^ 2 + qz .^ 2 ); ... */
  /* 'my_quat2eul:82'             atan2( -2 * (qx .* qy - qw .* qz), qw .^ 2 - qx .^ 2 + qy .^ 2 - qz .^ 2 )]; */
  profileStart_LW_ctrl_241029_1(205U); /* original_line:1801 */eul[0] = (real32_T)asin(aSinInput);profileEnd_LW_ctrl_241029_1(205U); /* original_line:1801 */
  aSinInput = b_q_idx_0 * b_q_idx_0 - b_q_idx_1 * b_q_idx_1;
  eul_tmp = b_q_idx_2 * b_q_idx_2;
  eul_tmp_0 = b_q_idx_3 * b_q_idx_3;
  profileStart_LW_ctrl_241029_1(206U); /* original_line:1805 */eul[1] = rt_atan2f_snf((b_q_idx_1 * b_q_idx_3 - b_q_idx_0 * b_q_idx_2) * -2.0F,
    (aSinInput - eul_tmp) + eul_tmp_0);profileEnd_LW_ctrl_241029_1(206U); /* original_line:1806 */
  profileStart_LW_ctrl_241029_1(207U); /* original_line:1807 */eul[2] = rt_atan2f_snf((b_q_idx_1 * b_q_idx_2 - b_q_idx_0 * b_q_idx_3) * -2.0F,
    (aSinInput + eul_tmp) - eul_tmp_0);profileEnd_LW_ctrl_241029_1(207U); /* original_line:1808 */

  /*  Check for complex numbers */
  /* 'my_quat2eul:93' if ~isreal(eul) */
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S403>/task' */
static real_T LW_ctrl_241029_1_prod(const real_T x_data[], const int32_T x_size
  [2])
{
  real_T y;
  int32_T k;
  int32_T vlen;
  vlen = x_size[1];
  if (x_size[1] == 0) {
    y = 1.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= vlen; k++) {
      y *= x_data[k - 1];
    }
  }

  return y;
}

/*
 * Function for MATLAB Function: '<S403>/task'
 * function val = poly_val(poly,t,r)
 */
static real_T LW_ctrl_241029_1_poly_val(const real_T poly[8], real_T t)
{
  real_T val;
  int32_T i;

  /* 'poly_val:2' val = 0; */
  val = 0.0;

  /* 'poly_val:3' n = length(poly)-1; */
  /* 'poly_val:4' if r<=0 */
  /* 'poly_val:8' else */
  /* 'poly_val:9' for i=r:n */
  for (i = 0; i < 7; i++) {
    /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
    /* 'poly_val:11' val = val + a; */
    profileStart_LW_ctrl_241029_1(232U); /* original_line:1899 */val += poly[i + 1] * ((real_T)i + 1.0) * rt_powd_snf(t, ((real_T)i + 1.0) -
      1.0);profileEnd_LW_ctrl_241029_1(232U); /* original_line:1900 */
  }

  return val;
}

/*
 * Function for MATLAB Function: '<S403>/task'
 * function [pos_ref, vel_ref, acc_ref, euler_ref,dot3x, yaw_ref, dotpsi,reverse_flag] = task1(timestamp, flight_mode,pos, vel, q, LW_OB_CIRCLE_R, LW_OB_CIRCLE_V, LW_OB_CIRCLE_W, LW_OB_TYPE)
 */
static void LW_ctrl_241029_1_task1(real32_T timestamp, FlightMode flight_mode,
  const real32_T pos[3], const real32_T q[4], real32_T pos_ref[3], real32_T
  vel_ref[3], real32_T acc_ref[3], real32_T dot3x[3], real32_T *yaw_ref,
  real32_T *dotpsi)
{
  int32_T d_i;
  int32_T i;
  real32_T acc_ref_0;
  real32_T dot3x_0;
  real32_T error_yaw;
  real32_T t;
  real32_T tmp;
  real32_T vel_ref_0;
  real32_T yaw;
  boolean_T y;
  static const real_T poly[8] = { 0.0, 0.0, 0.0, 0.0, 0.06, -0.0114, 0.0008,
    -2.0E-5 };

  static const real_T c[8] = { 0.0, 10.0, 0.0, 0.0, 0.01, -0.0054, 0.0006,
    -2.0E-5 };

  static const real32_T d[9] = { -0.707106829F, -0.707106769F, 0.0F,
    0.707106769F, -0.707106829F, 0.0F, 0.0F, 0.0F, 1.0F };

  boolean_T exitg1;

  /* 'task1:2' LW_OB_TYPE = single(0); */
  /*  */
  /* 'task1:3' LW_OB_CIRCLE_R = single(225/180*pi); */
  /* 'task1:4' LW_OB_CIRCLE_V = single(10); */
  /* 'task1:5' LW_OB_CIRCLE_W = single(20); */
  /* 'task1:7' if isempty(time_start) */
  if (!LW_ctrl_241029_1_DW.time_start_not_empty_b) {
    /* 'task1:8' time_start = timestamp; */
    LW_ctrl_241029_1_DW.time_start_a = timestamp;
    LW_ctrl_241029_1_DW.time_start_not_empty_b = true;
  }

  /* 'task1:11' if isempty(acc_last) */
  if (!LW_ctrl_241029_1_DW.acc_last_not_empty_b) {
    /* 'task1:12' acc_last = zeros(3,1,'single'); */
    LW_ctrl_241029_1_DW.acc_last_not_empty_b = true;

    /* 'task1:13' pos_last = zeros(3,1,'single'); */
    /* 'task1:14' pos_start = pos(:); */
    /* 'task1:15' pos_deacc_start = pos(:); */
    LW_ctrl_241029_1_DW.pos_start_k[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_deacc_start_j[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_start_k[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_deacc_start_j[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_start_k[2] = pos[2];
    LW_ctrl_241029_1_DW.pos_deacc_start_j[2] = pos[2];

    /* 'task1:16' pos_takeoff = pos(:); */
  }

  /* 'task1:19' if isempty(lineMode) */
  /* 'task1:25' if notInfNan(q) */
  /* ISINFNAN 此处显示有关此函数的摘要 */
  /*    Data is a vector. */
  /* 'notInfNan:4' y = false; */
  y = false;

  /* 'notInfNan:5' for ii = 1:length(data) */
  d_i = 0;
  exitg1 = false;
  while ((!exitg1) && (d_i < 4)) {
    /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
    if (rtIsInfF(q[d_i]) || rtIsNaNF(q[d_i])) {
      /* 'notInfNan:7' y = false; */
      y = false;
      exitg1 = true;
    } else {
      /* 'notInfNan:9' else */
      /* 'notInfNan:10' y = true; */
      y = true;
      d_i++;
    }
  }

  if (y) {
    /* 'task1:26' euler = my_quat2eul(q); */
    /* 'task1:27' yaw = euler(3); */
    profileStart_LW_ctrl_241029_1(208U); /* original_line:1993 */LW_ctrl_241029_1_my_quat2eul_k(q, LW_ctrl_241029_1_B.fv);profileEnd_LW_ctrl_241029_1(208U); /* original_line:1993 */
    yaw = LW_ctrl_241029_1_B.fv[2];
  } else {
    /* 'task1:28' else */
    /* 'task1:29' yaw = single(0); */
    yaw = 0.0F;
  }

  /* 'task1:32' if isempty(takeoff_yaw) */
  if (!LW_ctrl_241029_1_DW.takeoff_yaw_not_empty_e) {
    /* 'task1:33' takeoff_yaw = yaw; */
    LW_ctrl_241029_1_DW.takeoff_yaw_not_empty_e = true;

    /* 'task1:34' yaw_last = yaw; */
    LW_ctrl_241029_1_DW.yaw_last_n = yaw;
  }

  /* 'task1:37' Takeoff_time = 0; */
  /* 'task1:38' Takeoff_holdtime = 20; */
  /* 'task1:39' task1_time = 500; */
  /* 'task1:40' task1_R = LW_OB_CIRCLE_R; */
  /* 'task1:41' task1_omega = LW_OB_CIRCLE_W; */
  /* 复用为匀速时间 */
  /* 'task1:42' LineVmax = LW_OB_CIRCLE_V; */
  /* 'task1:43' Trj_acc_ppx = [0.000000e+00 0.000000e+00 0.000000e+00 0.000000e+00 6.000000e-02 -1.140000e-02 8.000000e-04 -2.000000e-05 ]; */
  /* 'task1:44' Trj_acc_ppy = [0.0,0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0]; */
  /* 'task1:45' Trj_acc_t = 8.0; */
  /* 'task1:46' Trj_deacc_ppx = [0.000000e+00 1.000000e+01 0.000000e+00 0.000000e+00 1.000000e-02 -5.400000e-03 6.000000e-04 -2.000000e-05]; */
  /* 'task1:47' Trj_deacc_ppy = [0.0,0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0]; */
  /* 'task1:48' Trj_deacc_t = 10.0; */
  /* 'task1:50' if flight_mode ~= FlightMode.OFFBOARD */
  if (flight_mode != OFFBOARD) {
    /* 'task1:51' time_start = timestamp; */
    LW_ctrl_241029_1_DW.time_start_a = timestamp;

    /* 'task1:53' lineMode = int8(0); */
    LW_ctrl_241029_1_DW.lineMode_o = 0;

    /* 'task1:54' Acct = single(0); */
    LW_ctrl_241029_1_DW.Acct_l = 0.0F;

    /* 'task1:55' Unit = single(0); */
    LW_ctrl_241029_1_DW.Unit_e = 0.0F;

    /* 'task1:56' pos_start = pos(:); */
    /* 'task1:57' pos_takeoff = pos(:); */
    /* 'task1:59' pos_last = pos; */
    LW_ctrl_241029_1_DW.pos_start_k[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_last_e[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_start_k[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_last_e[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_start_k[2] = pos[2];
    LW_ctrl_241029_1_DW.pos_last_e[2] = pos[2];

    /* 'task1:60' yaw_last = yaw; */
    LW_ctrl_241029_1_DW.yaw_last_n = yaw;
  }

  /* 'task1:64' dotpsi = single(0); */
  *dotpsi = 0.0F;

  /* 'task1:65' Rbe_psi = [cos(task1_R) sin(task1_R)  0; */
  /* 'task1:66'            -sin(task1_R) cos(task1_R) 0; */
  /* 'task1:67'             0 0 1]; */
  /* task1_R在这里被复用为期望偏航角 */
  /* 'task1:68' if flight_mode == FlightMode.OFFBOARD */
  if (flight_mode == OFFBOARD) {
    /* 'task1:69' if timestamp <= time_start  + Takeoff_time */
    if (timestamp <= LW_ctrl_241029_1_DW.time_start_a) {
      /* 'task1:70' pos_start = pos; */
      /* 'task1:71' pos_takeoff = pos; */
      /* 'task1:72' acc_ref = zeros(3,1,'single'); */
      /* 'task1:73' vel_ref = zeros(3,1,'single'); */
      /* 'task1:74' pos_ref = pos_takeoff; */
      /* 'task1:75' dot3x = zeros(3,1,'single'); */
      LW_ctrl_241029_1_DW.pos_start_k[0] = pos[0];
      acc_ref[0] = 0.0F;
      vel_ref[0] = 0.0F;
      pos_ref[0] = pos[0];
      dot3x[0] = 0.0F;
      LW_ctrl_241029_1_DW.pos_start_k[1] = pos[1];
      acc_ref[1] = 0.0F;
      vel_ref[1] = 0.0F;
      pos_ref[1] = pos[1];
      dot3x[1] = 0.0F;
      LW_ctrl_241029_1_DW.pos_start_k[2] = pos[2];
      acc_ref[2] = 0.0F;
      vel_ref[2] = 0.0F;
      pos_ref[2] = pos[2];
      dot3x[2] = 0.0F;

      /* 'task1:76' yaw_ref = yaw_last; */
      *yaw_ref = LW_ctrl_241029_1_DW.yaw_last_n;

      /* 'task1:77' dotpsi = single(0); */
    } else if (timestamp <= LW_ctrl_241029_1_DW.time_start_a + 20.0F) {
      /* 'task1:78' elseif timestamp <= time_start + Takeoff_holdtime + Takeoff_time */
      /* 起飞之后保持,调整偏航角 */
      /* 'task1:80' t = timestamp - time_start -Takeoff_time; */
      t = timestamp - LW_ctrl_241029_1_DW.time_start_a;

      /* 'task1:81' acc_ref = zeros(3,1,'single'); */
      /* 'task1:82' vel_ref = zeros(3,1,'single'); */
      /* 'task1:83' pos_ref = pos_start; */
      /* 'task1:84' dot3x = zeros(3,1,'single'); */
      acc_ref[0] = 0.0F;
      vel_ref[0] = 0.0F;
      pos_ref[0] = LW_ctrl_241029_1_DW.pos_start_k[0];
      dot3x[0] = 0.0F;
      acc_ref[1] = 0.0F;
      vel_ref[1] = 0.0F;
      pos_ref[1] = LW_ctrl_241029_1_DW.pos_start_k[1];
      dot3x[1] = 0.0F;
      acc_ref[2] = 0.0F;
      vel_ref[2] = 0.0F;
      pos_ref[2] = LW_ctrl_241029_1_DW.pos_start_k[2];
      dot3x[2] = 0.0F;

      /* 'task1:85' error_yaw = wrap_pi(task1_R - yaw); */
      /* 将 x 限定在[-pi,pi] */
      /* 'wrap_pi:3' i = 0; */
      d_i = 0;

      /* 'wrap_pi:4' y = x; */
      error_yaw = 3.92699075F - yaw;

      /* 'wrap_pi:5' while x > pi */
      exitg1 = false;
      while ((!exitg1) && (3.92699075F - yaw > 3.1415926535897931)) {
        /* 'wrap_pi:6' y =  x - 2*pi; */
        error_yaw = (3.92699075F - yaw) - 6.28318548F;

        /* 'wrap_pi:7' i = i + 1; */
        d_i++;

        /* 'wrap_pi:8' if i > 100 */
        if (d_i > 100) {
          exitg1 = true;
        }
      }

      /* 'wrap_pi:12' i = 0; */
      d_i = 0;

      /* 'wrap_pi:13' while x < -pi */
      exitg1 = false;
      while ((!exitg1) && (3.92699075F - yaw < -3.1415926535897931)) {
        /* 'wrap_pi:14' y =  x + 2*pi; */
        error_yaw = (3.92699075F - yaw) + 6.28318548F;

        /* 'wrap_pi:15' i = i + 1; */
        d_i++;

        /* 'wrap_pi:16' if i > 100 */
        if (d_i > 100) {
          exitg1 = true;
        }
      }

      /* 'task1:86' yaw_ref = single(yaw + error_yaw*sin(pi/(Takeoff_holdtime*2)*t)); */
      profileStart_LW_ctrl_241029_1(230U); /* original_line:2153 */yaw += (real32_T)sin(0.0785398185F * t) * error_yaw;profileEnd_LW_ctrl_241029_1(230U); /* original_line:2153 */

      /* 'task1:87' yaw_ref = wrap_pi(yaw_ref); */
      /* 将 x 限定在[-pi,pi] */
      /* 'wrap_pi:3' i = 0; */
      d_i = 0;

      /* 'wrap_pi:4' y = x; */
      *yaw_ref = yaw;

      /* 'wrap_pi:5' while x > pi */
      exitg1 = false;
      while ((!exitg1) && (yaw > 3.1415926535897931)) {
        /* 'wrap_pi:6' y =  x - 2*pi; */
        *yaw_ref = yaw - 6.28318548F;

        /* 'wrap_pi:7' i = i + 1; */
        d_i++;

        /* 'wrap_pi:8' if i > 100 */
        if (d_i > 100) {
          exitg1 = true;
        }
      }

      /* 'wrap_pi:12' i = 0; */
      d_i = 0;

      /* 'wrap_pi:13' while x < -pi */
      exitg1 = false;
      while ((!exitg1) && (yaw < -3.1415926535897931)) {
        /* 'wrap_pi:14' y =  x + 2*pi; */
        *yaw_ref = yaw + 6.28318548F;

        /* 'wrap_pi:15' i = i + 1; */
        d_i++;

        /* 'wrap_pi:16' if i > 100 */
        if (d_i > 100) {
          exitg1 = true;
        }
      }

      /* 'task1:88' dotpsi = single(error_yaw*pi/(2*Takeoff_holdtime)*cos(pi/(Takeoff_holdtime*2)*t)); */
      profileStart_LW_ctrl_241029_1(231U); /* original_line:2197 */*dotpsi = error_yaw * 3.14159274F / 40.0F * (real32_T)cos(0.0785398185F *
        t);profileEnd_LW_ctrl_241029_1(231U); /* original_line:2198 */

      /* 'task1:89' yaw_last = yaw_ref; */
      LW_ctrl_241029_1_DW.yaw_last_n = *yaw_ref;

      /* 'task1:90' lineMode = int8(0); */
      LW_ctrl_241029_1_DW.lineMode_o = 0;

      /*     pos_start = single([0; 0; -3]); */
    } else if (timestamp <= (LW_ctrl_241029_1_DW.time_start_a + 20.0F) + 500.0F)
    {
      /* 'task1:92' elseif timestamp <= time_start + Takeoff_holdtime +task1_time + Takeoff_time */
      /* task1 */
      /* 'task1:94' t = timestamp - time_start - Takeoff_holdtime - Takeoff_time; */
      t = (timestamp - LW_ctrl_241029_1_DW.time_start_a) - 20.0F;

      /* 'task1:96' if lineMode <= int8(1) */
      if (LW_ctrl_241029_1_DW.lineMode_o <= 1) {
        /* 加速 */
        /* 'task1:97' tmp = double(t); */
        /* 'task1:98' px = poly_val(Trj_acc_ppx,tmp,0); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.px = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:5' for i=0:n */
        /* 'task1:99' py = poly_val(Trj_acc_ppy,tmp,0); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.py = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:5' for i=0:n */
        for (d_i = 0; d_i < 8; d_i++) {
          /* 'poly_val:6' val = val+poly(i+1)*t^i; */
          profileStart_LW_ctrl_241029_1(221U); /* original_line:2234 */LW_ctrl_241029_1_B.ay = rt_powd_snf((real_T)t, (real_T)d_i);profileEnd_LW_ctrl_241029_1(221U); /* original_line:2234 */
          LW_ctrl_241029_1_B.px += poly[d_i] * LW_ctrl_241029_1_B.ay;

          /* 'poly_val:6' val = val+poly(i+1)*t^i; */
          LW_ctrl_241029_1_B.py += 0.0 * LW_ctrl_241029_1_B.ay;
        }

        /* 'task1:100' vx = poly_val(Trj_acc_ppx,tmp,1); */
        /* 'task1:101' vy = poly_val(Trj_acc_ppy,tmp,1); */
        /* 'task1:102' ax = poly_val(Trj_acc_ppx,tmp,2); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.ax = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:8' else */
        /* 'poly_val:9' for i=r:n */
        /* 'task1:103' ay = poly_val(Trj_acc_ppy,tmp,2); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.ay = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:8' else */
        /* 'poly_val:9' for i=r:n */
        for (d_i = 0; d_i < 6; d_i++) {
          /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
          /* 'poly_val:11' val = val + a; */
          LW_ctrl_241029_1_B.d_i_size[0] = 1;
          LW_ctrl_241029_1_B.d_i_size[1] = 2;
          for (i = 0; i < 2; i++) {
            LW_ctrl_241029_1_B.d_i_data[i] = (d_i + i) + 1;
          }

          profileStart_LW_ctrl_241029_1(222U); /* original_line:2268 */LW_ctrl_241029_1_B.jx = rt_powd_snf((real_T)t, ((real_T)d_i + 2.0) -
            2.0);profileEnd_LW_ctrl_241029_1(222U); /* original_line:2269 */
          profileStart_LW_ctrl_241029_1(223U); /* original_line:2270 */LW_ctrl_241029_1_B.ax += poly[d_i + 2] * LW_ctrl_241029_1_prod
            (LW_ctrl_241029_1_B.d_i_data, LW_ctrl_241029_1_B.d_i_size) *
            LW_ctrl_241029_1_B.jx;profileEnd_LW_ctrl_241029_1(223U); /* original_line:2272 */

          /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
          /* 'poly_val:11' val = val + a; */
          LW_ctrl_241029_1_B.d_i_size[0] = 1;
          LW_ctrl_241029_1_B.d_i_size[1] = 2;
          for (i = 0; i < 2; i++) {
            LW_ctrl_241029_1_B.d_i_data[i] = (d_i + i) + 1;
          }

          profileStart_LW_ctrl_241029_1(224U); /* original_line:2282 */LW_ctrl_241029_1_B.ay += 0.0 * LW_ctrl_241029_1_prod
            (LW_ctrl_241029_1_B.d_i_data, LW_ctrl_241029_1_B.d_i_size) *
            LW_ctrl_241029_1_B.jx;profileEnd_LW_ctrl_241029_1(224U); /* original_line:2284 */
        }

        /* 'task1:104' jx = poly_val(Trj_acc_ppx,tmp,3); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.jx = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:8' else */
        /* 'poly_val:9' for i=r:n */
        /* 'task1:105' jy = poly_val(Trj_acc_ppy,tmp,3); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.jy = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:8' else */
        /* 'poly_val:9' for i=r:n */
        for (d_i = 0; d_i < 5; d_i++) {
          /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
          /* 'poly_val:11' val = val + a; */
          LW_ctrl_241029_1_B.d_i_size[0] = 1;
          LW_ctrl_241029_1_B.d_i_size[1] = 3;
          for (i = 0; i < 3; i++) {
            LW_ctrl_241029_1_B.d_i_data[i] = (d_i + i) + 1;
          }

          profileStart_LW_ctrl_241029_1(225U); /* original_line:2312 */LW_ctrl_241029_1_B.jx_tmp = rt_powd_snf((real_T)t, ((real_T)d_i + 3.0)
            - 3.0);profileEnd_LW_ctrl_241029_1(225U); /* original_line:2313 */
          profileStart_LW_ctrl_241029_1(226U); /* original_line:2314 */LW_ctrl_241029_1_B.jx += poly[d_i + 3] * LW_ctrl_241029_1_prod
            (LW_ctrl_241029_1_B.d_i_data, LW_ctrl_241029_1_B.d_i_size) *
            LW_ctrl_241029_1_B.jx_tmp;profileEnd_LW_ctrl_241029_1(226U); /* original_line:2316 */

          /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
          /* 'poly_val:11' val = val + a; */
          LW_ctrl_241029_1_B.d_i_size[0] = 1;
          LW_ctrl_241029_1_B.d_i_size[1] = 3;
          for (i = 0; i < 3; i++) {
            LW_ctrl_241029_1_B.d_i_data[i] = (d_i + i) + 1;
          }

          profileStart_LW_ctrl_241029_1(227U); /* original_line:2326 */LW_ctrl_241029_1_B.jy += 0.0 * LW_ctrl_241029_1_prod
            (LW_ctrl_241029_1_B.d_i_data, LW_ctrl_241029_1_B.d_i_size) *
            LW_ctrl_241029_1_B.jx_tmp;profileEnd_LW_ctrl_241029_1(227U); /* original_line:2328 */
        }

        /* 'task1:107' pos_ref = pos_start + single(Rbe_psi'*[px; py; 0]); */
        for (i = 0; i < 3; i++) {
          pos_ref[i] = (d[i + 3] * (real32_T)LW_ctrl_241029_1_B.py + d[i] *
                        (real32_T)LW_ctrl_241029_1_B.px) +
            LW_ctrl_241029_1_DW.pos_start_k[i];
        }

        /* 'task1:108' vel_ref = single(Rbe_psi'*[vx; vy; 0]); */
        for (i = 0; i < 8; i++) {
          LW_ctrl_241029_1_B.dv[i] = 0.0;
        }

        profileStart_LW_ctrl_241029_1(228U); /* original_line:2343 */LW_ctrl_241029_1_B.px = LW_ctrl_241029_1_poly_val(poly, (real_T)t);profileEnd_LW_ctrl_241029_1(228U); /* original_line:2343 */
        profileStart_LW_ctrl_241029_1(229U); /* original_line:2344 */LW_ctrl_241029_1_B.tmp = LW_ctrl_241029_1_poly_val(LW_ctrl_241029_1_B.dv,
          (real_T)t);profileEnd_LW_ctrl_241029_1(229U); /* original_line:2345 */

        /* 'task1:109' acc_ref = single(Rbe_psi'*[ax; ay; 0]); */
        /* 'task1:110' dot3x = single(Rbe_psi'*[jx; jy; 0]); */
        /* 'task1:112' yaw_ref = single(NaN); */
        *yaw_ref = (rtNaNF);

        /* 'task1:113' pos_last = pos_ref; */
        /* 'task1:114' pos_deacc_start = pos_ref; */
        for (d_i = 0; d_i < 3; d_i++) {
          error_yaw = d[d_i];
          vel_ref_0 = error_yaw * (real32_T)LW_ctrl_241029_1_B.px;
          acc_ref_0 = error_yaw * (real32_T)LW_ctrl_241029_1_B.ax;
          dot3x_0 = error_yaw * (real32_T)LW_ctrl_241029_1_B.jx;
          error_yaw = d[d_i + 3];
          dot3x[d_i] = error_yaw * (real32_T)LW_ctrl_241029_1_B.jy + dot3x_0;
          acc_ref[d_i] = error_yaw * (real32_T)LW_ctrl_241029_1_B.ay + acc_ref_0;
          vel_ref[d_i] = error_yaw * (real32_T)LW_ctrl_241029_1_B.tmp +
            vel_ref_0;
          error_yaw = pos_ref[d_i];
          LW_ctrl_241029_1_DW.pos_last_e[d_i] = error_yaw;
          LW_ctrl_241029_1_DW.pos_deacc_start_j[d_i] = error_yaw;
        }

        /* 'task1:115' yaw_last = yaw; */
        LW_ctrl_241029_1_DW.yaw_last_n = yaw;
      } else if (LW_ctrl_241029_1_DW.lineMode_o <= 2) {
        /* 'task1:116' elseif lineMode <= int8(2) */
        /* 匀速,保持加速结束时刻的速度 */
        /* 'task1:117' tmp = double(Acct); */
        /* 'task1:118' px = poly_val(Trj_acc_ppx,tmp,0); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.px = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:5' for i=0:n */
        /* 'task1:119' py = poly_val(Trj_acc_ppy,tmp,0); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.py = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:5' for i=0:n */
        /* 'task1:120' vx = poly_val(Trj_acc_ppx,tmp,1); */
        profileStart_LW_ctrl_241029_1(218U); /* original_line:2390 */LW_ctrl_241029_1_B.ax = LW_ctrl_241029_1_poly_val(poly, (real_T)
          LW_ctrl_241029_1_DW.Acct_l);profileEnd_LW_ctrl_241029_1(218U); /* original_line:2391 */

        /* 'task1:121' vy = poly_val(Trj_acc_ppy,tmp,1); */
        for (d_i = 0; d_i < 8; d_i++) {
          /* 'poly_val:6' val = val+poly(i+1)*t^i; */
          profileStart_LW_ctrl_241029_1(219U); /* original_line:2396 */LW_ctrl_241029_1_B.ay = rt_powd_snf((real_T)LW_ctrl_241029_1_DW.Acct_l,
            (real_T)d_i);profileEnd_LW_ctrl_241029_1(219U); /* original_line:2397 */
          LW_ctrl_241029_1_B.px += poly[d_i] * LW_ctrl_241029_1_B.ay;

          /* 'poly_val:6' val = val+poly(i+1)*t^i; */
          LW_ctrl_241029_1_B.py += 0.0 * LW_ctrl_241029_1_B.ay;
          LW_ctrl_241029_1_B.dv[d_i] = 0.0;
        }

        profileStart_LW_ctrl_241029_1(220U); /* original_line:2405 */LW_ctrl_241029_1_B.ay = LW_ctrl_241029_1_poly_val(LW_ctrl_241029_1_B.dv,
          (real_T)LW_ctrl_241029_1_DW.Acct_l);profileEnd_LW_ctrl_241029_1(220U); /* original_line:2406 */

        /* 'task1:122' tmp = double((t - Acct)); */
        LW_ctrl_241029_1_B.tmp = t - LW_ctrl_241029_1_DW.Acct_l;

        /* 'task1:123' px = px + vx*tmp; */
        /* 'task1:124' py = py+ vy*tmp; */
        /* 'task1:125' ax = 0; */
        /* 'task1:126' ay = 0; */
        /* 'task1:127' jx = 0; */
        /* 'task1:128' jy = 0; */
        /* 'task1:130' pos_ref = pos_start + single(Rbe_psi'*[px; py; 0]); */
        acc_ref_0 = (real32_T)(LW_ctrl_241029_1_B.ax * LW_ctrl_241029_1_B.tmp +
          LW_ctrl_241029_1_B.px);
        dot3x_0 = (real32_T)(LW_ctrl_241029_1_B.ay * LW_ctrl_241029_1_B.tmp +
                             LW_ctrl_241029_1_B.py);

        /* 'task1:131' vel_ref = single(Rbe_psi'*[vx; vy; 0]); */
        /* 'task1:132' acc_ref = single(Rbe_psi'*[ax; ay; 0]); */
        /* 'task1:133' dot3x = single(Rbe_psi'*[jx; jy; 0]); */
        /* 'task1:135' yaw_ref = single(NaN); */
        *yaw_ref = (rtNaNF);

        /* 'task1:136' pos_last = pos_ref; */
        /* 'task1:137' pos_deacc_start = pos_ref; */
        for (d_i = 0; d_i < 3; d_i++) {
          error_yaw = d[d_i];
          tmp = error_yaw * acc_ref_0;
          vel_ref_0 = error_yaw * (real32_T)LW_ctrl_241029_1_B.ax;
          error_yaw = d[d_i + 3];
          vel_ref[d_i] = error_yaw * (real32_T)LW_ctrl_241029_1_B.ay + vel_ref_0;
          error_yaw = (error_yaw * dot3x_0 + tmp) +
            LW_ctrl_241029_1_DW.pos_start_k[d_i];
          pos_ref[d_i] = error_yaw;
          acc_ref[d_i] = 0.0F;
          dot3x[d_i] = 0.0F;
          LW_ctrl_241029_1_DW.pos_last_e[d_i] = error_yaw;
          LW_ctrl_241029_1_DW.pos_deacc_start_j[d_i] = error_yaw;
        }

        /* 'task1:138' yaw_last = yaw; */
        LW_ctrl_241029_1_DW.yaw_last_n = yaw;
      } else if (LW_ctrl_241029_1_DW.lineMode_o <= 3) {
        /* 'task1:139' elseif lineMode <= int8(3) */
        /* 减速 */
        /* 'task1:140' tmp = double((t -Unit - Acct)); */
        LW_ctrl_241029_1_B.tmp = (t - LW_ctrl_241029_1_DW.Unit_e) -
          LW_ctrl_241029_1_DW.Acct_l;

        /* 'task1:142' px = poly_val(Trj_deacc_ppx,tmp,0); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.px = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:5' for i=0:n */
        /* 'task1:143' py = poly_val(Trj_deacc_ppy,tmp,0); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.py = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:5' for i=0:n */
        for (d_i = 0; d_i < 8; d_i++) {
          /* 'poly_val:6' val = val+poly(i+1)*t^i; */
          profileStart_LW_ctrl_241029_1(209U); /* original_line:2471 */LW_ctrl_241029_1_B.ay = rt_powd_snf(LW_ctrl_241029_1_B.tmp, (real_T)
            d_i);profileEnd_LW_ctrl_241029_1(209U); /* original_line:2472 */
          LW_ctrl_241029_1_B.px += c[d_i] * LW_ctrl_241029_1_B.ay;

          /* 'poly_val:6' val = val+poly(i+1)*t^i; */
          LW_ctrl_241029_1_B.py += 0.0 * LW_ctrl_241029_1_B.ay;
        }

        /* 'task1:144' vx = poly_val(Trj_deacc_ppx,tmp,1); */
        /* 'task1:145' vy = poly_val(Trj_deacc_ppy,tmp,1); */
        /* 'task1:146' ax = poly_val(Trj_deacc_ppx,tmp,2); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.ax = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:8' else */
        /* 'poly_val:9' for i=r:n */
        /* 'task1:147' ay = poly_val(Trj_deacc_ppy,tmp,2); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.ay = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:8' else */
        /* 'poly_val:9' for i=r:n */
        for (d_i = 0; d_i < 6; d_i++) {
          /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
          /* 'poly_val:11' val = val + a; */
          LW_ctrl_241029_1_B.d_i_size[0] = 1;
          LW_ctrl_241029_1_B.d_i_size[1] = 2;
          for (i = 0; i < 2; i++) {
            LW_ctrl_241029_1_B.d_i_data[i] = (d_i + i) + 1;
          }

          profileStart_LW_ctrl_241029_1(210U); /* original_line:2506 */LW_ctrl_241029_1_B.jx = rt_powd_snf(LW_ctrl_241029_1_B.tmp, ((real_T)
            d_i + 2.0) - 2.0);profileEnd_LW_ctrl_241029_1(210U); /* original_line:2507 */
          profileStart_LW_ctrl_241029_1(211U); /* original_line:2508 */LW_ctrl_241029_1_B.ax += c[d_i + 2] * LW_ctrl_241029_1_prod
            (LW_ctrl_241029_1_B.d_i_data, LW_ctrl_241029_1_B.d_i_size) *
            LW_ctrl_241029_1_B.jx;profileEnd_LW_ctrl_241029_1(211U); /* original_line:2510 */

          /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
          /* 'poly_val:11' val = val + a; */
          LW_ctrl_241029_1_B.d_i_size[0] = 1;
          LW_ctrl_241029_1_B.d_i_size[1] = 2;
          for (i = 0; i < 2; i++) {
            LW_ctrl_241029_1_B.d_i_data[i] = (d_i + i) + 1;
          }

          profileStart_LW_ctrl_241029_1(212U); /* original_line:2520 */LW_ctrl_241029_1_B.ay += 0.0 * LW_ctrl_241029_1_prod
            (LW_ctrl_241029_1_B.d_i_data, LW_ctrl_241029_1_B.d_i_size) *
            LW_ctrl_241029_1_B.jx;profileEnd_LW_ctrl_241029_1(212U); /* original_line:2522 */
        }

        /* 'task1:148' jx = poly_val(Trj_deacc_ppx,tmp,3); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.jx = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:8' else */
        /* 'poly_val:9' for i=r:n */
        /* 'task1:149' jy = poly_val(Trj_deacc_ppy,tmp,3); */
        /* 'poly_val:2' val = 0; */
        LW_ctrl_241029_1_B.jy = 0.0;

        /* 'poly_val:3' n = length(poly)-1; */
        /* 'poly_val:4' if r<=0 */
        /* 'poly_val:8' else */
        /* 'poly_val:9' for i=r:n */
        for (d_i = 0; d_i < 5; d_i++) {
          /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
          /* 'poly_val:11' val = val + a; */
          LW_ctrl_241029_1_B.d_i_size[0] = 1;
          LW_ctrl_241029_1_B.d_i_size[1] = 3;
          for (i = 0; i < 3; i++) {
            LW_ctrl_241029_1_B.d_i_data[i] = (d_i + i) + 1;
          }

          profileStart_LW_ctrl_241029_1(213U); /* original_line:2550 */LW_ctrl_241029_1_B.jx_tmp = rt_powd_snf(LW_ctrl_241029_1_B.tmp,
            ((real_T)d_i + 3.0) - 3.0);profileEnd_LW_ctrl_241029_1(213U); /* original_line:2551 */
          profileStart_LW_ctrl_241029_1(214U); /* original_line:2552 */LW_ctrl_241029_1_B.jx += c[d_i + 3] * LW_ctrl_241029_1_prod
            (LW_ctrl_241029_1_B.d_i_data, LW_ctrl_241029_1_B.d_i_size) *
            LW_ctrl_241029_1_B.jx_tmp;profileEnd_LW_ctrl_241029_1(214U); /* original_line:2554 */

          /* 'poly_val:10' a = poly(i+1)*prod(i-r+1:i)*t^(i-r); */
          /* 'poly_val:11' val = val + a; */
          LW_ctrl_241029_1_B.d_i_size[0] = 1;
          LW_ctrl_241029_1_B.d_i_size[1] = 3;
          for (i = 0; i < 3; i++) {
            LW_ctrl_241029_1_B.d_i_data[i] = (d_i + i) + 1;
          }

          profileStart_LW_ctrl_241029_1(215U); /* original_line:2564 */LW_ctrl_241029_1_B.jy += 0.0 * LW_ctrl_241029_1_prod
            (LW_ctrl_241029_1_B.d_i_data, LW_ctrl_241029_1_B.d_i_size) *
            LW_ctrl_241029_1_B.jx_tmp;profileEnd_LW_ctrl_241029_1(215U); /* original_line:2566 */
        }

        /* 'task1:151' pos_ref = pos_deacc_start + single(Rbe_psi'*[px; py; 0]); */
        for (i = 0; i < 3; i++) {
          pos_ref[i] = (d[i + 3] * (real32_T)LW_ctrl_241029_1_B.py + d[i] *
                        (real32_T)LW_ctrl_241029_1_B.px) +
            LW_ctrl_241029_1_DW.pos_deacc_start_j[i];
        }

        /* 'task1:152' vel_ref = single(Rbe_psi'*[vx; vy; 0]); */
        for (i = 0; i < 8; i++) {
          LW_ctrl_241029_1_B.dv[i] = 0.0;
        }

        profileStart_LW_ctrl_241029_1(216U); /* original_line:2581 */LW_ctrl_241029_1_B.px = LW_ctrl_241029_1_poly_val(c,
          LW_ctrl_241029_1_B.tmp);profileEnd_LW_ctrl_241029_1(216U); /* original_line:2582 */
        profileStart_LW_ctrl_241029_1(217U); /* original_line:2583 */LW_ctrl_241029_1_B.tmp = LW_ctrl_241029_1_poly_val(LW_ctrl_241029_1_B.dv,
          LW_ctrl_241029_1_B.tmp);profileEnd_LW_ctrl_241029_1(217U); /* original_line:2584 */

        /* 'task1:153' acc_ref = single(Rbe_psi'*[ax; ay; 0]); */
        /* 'task1:154' dot3x = single(Rbe_psi'*[jx; jy; 0]); */
        /* 'task1:156' yaw_ref = single(NaN); */
        *yaw_ref = (rtNaNF);

        /* 'task1:157' pos_last = pos_ref; */
        for (d_i = 0; d_i < 3; d_i++) {
          error_yaw = d[d_i];
          vel_ref_0 = error_yaw * (real32_T)LW_ctrl_241029_1_B.px;
          acc_ref_0 = error_yaw * (real32_T)LW_ctrl_241029_1_B.ax;
          dot3x_0 = error_yaw * (real32_T)LW_ctrl_241029_1_B.jx;
          error_yaw = d[d_i + 3];
          dot3x[d_i] = error_yaw * (real32_T)LW_ctrl_241029_1_B.jy + dot3x_0;
          acc_ref[d_i] = error_yaw * (real32_T)LW_ctrl_241029_1_B.ay + acc_ref_0;
          vel_ref[d_i] = error_yaw * (real32_T)LW_ctrl_241029_1_B.tmp +
            vel_ref_0;
          LW_ctrl_241029_1_DW.pos_last_e[d_i] = pos_ref[d_i];
        }

        /* 'task1:158' yaw_last = yaw; */
        LW_ctrl_241029_1_DW.yaw_last_n = yaw;
      } else {
        /* 'task1:159' elseif lineMode <= int8(4) */
        /* 匀速,保持加速结束时刻的速度 */
        /* 'task1:160' pos_ref = pos_last; */
        /* 'task1:161' vel_ref = single(Rbe_psi'*[0; 0; 0]); */
        /* 'task1:162' acc_ref = single(Rbe_psi'*[0; 0; 0]); */
        /* 'task1:163' dot3x = single(Rbe_psi'*[0; 0; 0]); */
        pos_ref[0] = LW_ctrl_241029_1_DW.pos_last_e[0];
        vel_ref[0] = 0.0F;
        acc_ref[0] = 0.0F;
        dot3x[0] = 0.0F;
        pos_ref[1] = LW_ctrl_241029_1_DW.pos_last_e[1];
        vel_ref[1] = 0.0F;
        acc_ref[1] = 0.0F;
        dot3x[1] = 0.0F;
        pos_ref[2] = LW_ctrl_241029_1_DW.pos_last_e[2];
        vel_ref[2] = 0.0F;
        acc_ref[2] = 0.0F;
        dot3x[2] = 0.0F;

        /* 'task1:165' yaw_ref = single(NaN); */
        *yaw_ref = (rtNaNF);

        /* 'task1:166' pos_last = [pos(1:2);pos_ref(3)]; */
        LW_ctrl_241029_1_DW.pos_last_e[0] = pos[0];
        LW_ctrl_241029_1_DW.pos_last_e[1] = pos[1];

        /* 'task1:167' pos_deacc_start = pos_ref; */
        LW_ctrl_241029_1_DW.pos_deacc_start_j[0] = pos_ref[0];
        LW_ctrl_241029_1_DW.pos_deacc_start_j[1] = pos_ref[1];
        LW_ctrl_241029_1_DW.pos_deacc_start_j[2] =
          LW_ctrl_241029_1_DW.pos_last_e[2];

        /* 'task1:168' yaw_last = yaw; */
        LW_ctrl_241029_1_DW.yaw_last_n = yaw;
      }

      /* 'task1:177' if t <= Trj_acc_t && lineMode <= int8(1) */
      if ((t <= 8.0F) && (LW_ctrl_241029_1_DW.lineMode_o <= 1)) {
        /* 加速 */
        /* 'task1:178' lineMode = int8(1); */
        LW_ctrl_241029_1_DW.lineMode_o = 1;

        /* 'task1:179' Acct = t; */
        LW_ctrl_241029_1_DW.Acct_l = t;
      } else if ((LW_ctrl_241029_1_DW.lineMode_o <= 2) && (t <=
                  LW_ctrl_241029_1_DW.Acct_l + 20.0F)) {
        /* 'task1:180' elseif lineMode <= int8(2) && t <= task1_omega + Acct */
        /* 匀速 */
        /* 'task1:181' lineMode = int8(2); */
        LW_ctrl_241029_1_DW.lineMode_o = 2;

        /* 'task1:182' Unit = t - Acct; */
        LW_ctrl_241029_1_DW.Unit_e = t - LW_ctrl_241029_1_DW.Acct_l;
      } else if ((LW_ctrl_241029_1_DW.lineMode_o <= 3) && (10.0F - ((t -
                    LW_ctrl_241029_1_DW.Acct_l) - LW_ctrl_241029_1_DW.Unit_e) >=
                  0.0F)) {
        /* 'task1:183' elseif lineMode <= int8(3) && Trj_deacc_t - (t - Acct - Unit) >= 0 */
        /* 减速 */
        /* 'task1:184' lineMode = int8(3); */
        LW_ctrl_241029_1_DW.lineMode_o = 3;
      } else {
        /* 'task1:185' else */
        /* 'task1:186' lineMode = int8(4); */
        LW_ctrl_241029_1_DW.lineMode_o = 4;
      }
    } else {
      /* 'task1:188' else */
      /* 'task1:189' acc_ref = zeros(3,1,'single'); */
      /* 'task1:190' vel_ref = zeros(3,1,'single'); */
      /* 'task1:191' pos_ref = pos_last; */
      /* 'task1:192' dot3x = zeros(3,1,'single'); */
      acc_ref[0] = 0.0F;
      vel_ref[0] = 0.0F;
      pos_ref[0] = LW_ctrl_241029_1_DW.pos_last_e[0];
      dot3x[0] = 0.0F;
      acc_ref[1] = 0.0F;
      vel_ref[1] = 0.0F;
      pos_ref[1] = LW_ctrl_241029_1_DW.pos_last_e[1];
      dot3x[1] = 0.0F;
      acc_ref[2] = 0.0F;
      vel_ref[2] = 0.0F;
      pos_ref[2] = LW_ctrl_241029_1_DW.pos_last_e[2];
      dot3x[2] = 0.0F;

      /* 'task1:193' yaw_ref = yaw_last; */
      *yaw_ref = LW_ctrl_241029_1_DW.yaw_last_n;

      /* 'task1:194' dotpsi = single(0); */
    }
  } else {
    /* 'task1:196' else */
    /* 悬停 */
    /* 'task1:198' acc_ref = zeros(3,1,'single'); */
    /* 'task1:199' vel_ref = zeros(3,1,'single'); */
    /* 'task1:200' pos_ref = pos_last; */
    /* 'task1:201' dot3x = zeros(3,1,'single'); */
    acc_ref[0] = 0.0F;
    vel_ref[0] = 0.0F;
    pos_ref[0] = LW_ctrl_241029_1_DW.pos_last_e[0];
    dot3x[0] = 0.0F;
    acc_ref[1] = 0.0F;
    vel_ref[1] = 0.0F;
    pos_ref[1] = LW_ctrl_241029_1_DW.pos_last_e[1];
    dot3x[1] = 0.0F;
    acc_ref[2] = 0.0F;
    vel_ref[2] = 0.0F;
    pos_ref[2] = LW_ctrl_241029_1_DW.pos_last_e[2];
    dot3x[2] = 0.0F;

    /* 'task1:202' yaw_ref = yaw_last; */
    *yaw_ref = LW_ctrl_241029_1_DW.yaw_last_n;

    /* 'task1:203' dotpsi = single(0); */
  }

  /* 'task1:206' euler_ref = zeros(3,1,'single'); */
  /* 'task1:207' reverse_flag = int8(0); */
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S403>/df,coor,wind' */
static real32_T LW_ctrl_241029_1_norm(const real32_T x[3])
{
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  scale = 1.29246971E-26F;
  profileStart_LW_ctrl_241029_1(172U); /* original_line:2781 */absxk = (real32_T)fabs(x[0]);profileEnd_LW_ctrl_241029_1(172U); /* original_line:2781 */
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  profileStart_LW_ctrl_241029_1(173U); /* original_line:2790 */absxk = (real32_T)fabs(x[1]);profileEnd_LW_ctrl_241029_1(173U); /* original_line:2790 */
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  profileStart_LW_ctrl_241029_1(174U); /* original_line:2800 */absxk = (real32_T)fabs(x[2]);profileEnd_LW_ctrl_241029_1(174U); /* original_line:2800 */
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  profileStart_LW_ctrl_241029_1(175U); /* original_line:2810 */y = scale * (real32_T)sqrt(y);profileEnd_LW_ctrl_241029_1(175U); /* original_line:2810 */
  return y;
}

/*
 * Function for MATLAB Function: '<S403>/task'
 * function [pos_ref, vel_ref, acc_ref, euler_ref,dot3x, yaw_ref, dotpsi,reverse_flag] = task5(timestamp, flight_mode,pos, vel, q, LW_OB_CIRCLE_R, LW_OB_CIRCLE_V, LW_OB_CIRCLE_W, LW_OB_TYPE)
 */
static void LW_ctrl_241029_1_task5(real32_T timestamp, FlightMode flight_mode,
  const real32_T pos[3], const real32_T q[4], real32_T pos_ref[3], real32_T
  vel_ref[3], real32_T acc_ref[3], real32_T dot3x[3], real32_T *yaw_ref,
  real32_T *dotpsi)
{
  int32_T CircleVmax;
  int32_T ii;
  real32_T acc_ref_tmp;
  real32_T acc_ref_tmp_0;
  real32_T omega;
  real32_T pos_ref_tmp;
  real32_T pos_ref_tmp_0;
  real32_T t;
  real32_T task1_R;
  real32_T tem;
  real32_T vel_ref_tmp;
  real32_T vel_ref_tmp_0;
  real32_T yaw;
  boolean_T y;
  static const real32_T c[9] = { 0.707106769F, 0.707106769F, 0.0F, -0.707106769F,
    0.707106769F, 0.0F, 0.0F, 0.0F, 1.0F };

  static const int8_T b[3] = { 0, 0, -1 };

  static const real32_T d[3] = { 4.2426405F, 4.2426405F, 0.0F };

  static const real32_T e[3] = { 0.707106769F, 0.707106769F, 0.0F };

  static const real32_T f[3] = { -0.707106769F, -0.707106769F, 0.0F };

  boolean_T exitg1;

  /* 'task5:2' LW_OB_TYPE = single(0); */
  /* 'task5:3' LW_OB_CIRCLE_R = single(45/180*pi); */
  /* 'task5:4' LW_OB_CIRCLE_V = single(15); */
  /* 'task5:5' LW_OB_CIRCLE_W = single(60); */
  /* 'task5:6' task1_omega = LW_OB_CIRCLE_W; */
  /* 'task5:7' CircleVmax = LW_OB_CIRCLE_V; */
  CircleVmax = 15;

  /* 'task5:8' nCircle = 12; */
  /* 'task5:10' if isempty(time_start) */
  if (!LW_ctrl_241029_1_DW.time_start_not_empty) {
    /* 'task5:11' time_start = timestamp; */
    LW_ctrl_241029_1_DW.time_start = timestamp;
    LW_ctrl_241029_1_DW.time_start_not_empty = true;
  }

  /* 'task5:14' if isempty(acc_last) */
  if (!LW_ctrl_241029_1_DW.acc_last_not_empty) {
    /* 'task5:15' acc_last = zeros(3,1,'single'); */
    LW_ctrl_241029_1_DW.acc_last_not_empty = true;

    /* 'task5:16' pos_last = zeros(3,1,'single'); */
    /* 'task5:17' pos_start = pos(:); */
    /* 'task5:18' pos_deacc_start = pos(:); */
    /* 'task5:19' pos_takeoff = pos(:); */
    LW_ctrl_241029_1_DW.pos_start[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_deacc_start[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_takeoff[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_start[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_deacc_start[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_takeoff[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_start[2] = pos[2];
    LW_ctrl_241029_1_DW.pos_deacc_start[2] = pos[2];
    LW_ctrl_241029_1_DW.pos_takeoff[2] = pos[2];

    /* 'task5:20' pos_return = pos(:); */
  }

  /* 'task5:23' if isempty(lineMode) */
  /* 'task5:29' if notInfNan(q) */
  /* ISINFNAN 此处显示有关此函数的摘要 */
  /*    Data is a vector. */
  /* 'notInfNan:4' y = false; */
  y = false;

  /* 'notInfNan:5' for ii = 1:length(data) */
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 4)) {
    /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
    if (rtIsInfF(q[ii]) || rtIsNaNF(q[ii])) {
      /* 'notInfNan:7' y = false; */
      y = false;
      exitg1 = true;
    } else {
      /* 'notInfNan:9' else */
      /* 'notInfNan:10' y = true; */
      y = true;
      ii++;
    }
  }

  if (y) {
    /* 'task5:30' euler = my_quat2eul(q); */
    /* 'task5:31' yaw = euler(3); */
    profileStart_LW_ctrl_241029_1(176U); /* original_line:2915 */LW_ctrl_241029_1_my_quat2eul_k(q, LW_ctrl_241029_1_B.fv1);profileEnd_LW_ctrl_241029_1(176U); /* original_line:2915 */
    yaw = LW_ctrl_241029_1_B.fv1[2];
  } else {
    /* 'task5:32' else */
    /* 'task5:33' yaw = single(0); */
    yaw = 0.0F;
  }

  /* 'task5:36' if isempty(takeoff_yaw) */
  if (!LW_ctrl_241029_1_DW.takeoff_yaw_not_empty) {
    /* 'task5:37' takeoff_yaw = yaw; */
    LW_ctrl_241029_1_DW.takeoff_yaw_not_empty = true;

    /* 'task5:38' yaw_last = yaw; */
    LW_ctrl_241029_1_DW.yaw_last = yaw;
  }

  /* 'task5:41' Takeoff_time = 0; */
  /* 'task5:42' Takeoff_holdtime = 100; */
  /* 100 */
  /* 'task5:43' task1_time = 100000; */
  /* 'task5:44' task1_R = LW_OB_CIRCLE_R; */
  task1_R = 0.785398185F;

  /* 'task5:45' task_R = LW_OB_CIRCLE_W; */
  /* 复用为匀速时间 */
  /* 'task5:46' LineVmax = LW_OB_CIRCLE_V; */
  /* 'task5:48' if flight_mode ~= FlightMode.OFFBOARD */
  if (flight_mode != OFFBOARD) {
    /* 'task5:49' time_start = timestamp; */
    LW_ctrl_241029_1_DW.time_start = timestamp;

    /* 'task5:51' lineMode = int8(0); */
    LW_ctrl_241029_1_DW.lineMode = 0;

    /* 'task5:52' Acct = single(0); */
    LW_ctrl_241029_1_DW.Acct = 0.0F;

    /* 'task5:53' Unit = single(0); */
    LW_ctrl_241029_1_DW.Unit = 0.0F;

    /* 'task5:54' pos_start = pos(:); */
    /* 'task5:55' pos_takeoff = pos(:); */
    /* 'task5:56' pos_return = pos(:); */
    /* 'task5:58' pos_last = pos; */
    LW_ctrl_241029_1_DW.pos_start[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_takeoff[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_last[0] = pos[0];
    LW_ctrl_241029_1_DW.pos_start[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_takeoff[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_last[1] = pos[1];
    LW_ctrl_241029_1_DW.pos_start[2] = pos[2];
    LW_ctrl_241029_1_DW.pos_takeoff[2] = pos[2];
    LW_ctrl_241029_1_DW.pos_last[2] = pos[2];

    /* 'task5:59' yaw_last = yaw; */
    LW_ctrl_241029_1_DW.yaw_last = yaw;
  }

  /* 'task5:63' dotpsi = single(0); */
  *dotpsi = 0.0F;

  /* 'task5:64' Rbe_psi = [cos(task1_R) sin(task1_R)  0; */
  /* 'task5:65'            -sin(task1_R) cos(task1_R) 0; */
  /* 'task5:66'             0 0 1]; */
  /* task1_R在这里被复用为期望偏航角 */
  /* 'task5:67' if flight_mode == FlightMode.OFFBOARD */
  if (flight_mode == OFFBOARD) {
    /* 'task5:68' if timestamp <= time_start  + Takeoff_time */
    if (timestamp <= LW_ctrl_241029_1_DW.time_start) {
      /* 'task5:69' pos_start = pos; */
      /* 'task5:70' pos_takeoff = pos; */
      /* 'task5:71' acc_ref = zeros(3,1,'single'); */
      /* 'task5:72' vel_ref = zeros(3,1,'single'); */
      /* 'task5:73' pos_ref = pos_takeoff; */
      /* 'task5:74' dot3x = zeros(3,1,'single'); */
      LW_ctrl_241029_1_DW.pos_start[0] = pos[0];
      LW_ctrl_241029_1_DW.pos_takeoff[0] = pos[0];
      acc_ref[0] = 0.0F;
      vel_ref[0] = 0.0F;
      pos_ref[0] = pos[0];
      dot3x[0] = 0.0F;
      LW_ctrl_241029_1_DW.pos_start[1] = pos[1];
      LW_ctrl_241029_1_DW.pos_takeoff[1] = pos[1];
      acc_ref[1] = 0.0F;
      vel_ref[1] = 0.0F;
      pos_ref[1] = pos[1];
      dot3x[1] = 0.0F;
      LW_ctrl_241029_1_DW.pos_start[2] = pos[2];
      LW_ctrl_241029_1_DW.pos_takeoff[2] = pos[2];
      acc_ref[2] = 0.0F;
      vel_ref[2] = 0.0F;
      pos_ref[2] = pos[2];
      dot3x[2] = 0.0F;

      /* 'task5:75' yaw_ref = yaw_last; */
      *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

      /* 'task5:76' dotpsi = single(0); */
      /* 'task5:77' reverse_flag = int8(0); */
    } else if (timestamp <= LW_ctrl_241029_1_DW.time_start + 100.0F) {
      /* 'task5:78' elseif timestamp <= time_start + Takeoff_holdtime + Takeoff_time */
      /* 起飞之后保持,调整偏航角 */
      /* 'task5:80' t = timestamp - time_start -Takeoff_time; */
      t = timestamp - LW_ctrl_241029_1_DW.time_start;

      /* 'task5:81' if t <= 10 */
      if (t <= 10.0F) {
        /* 'task5:82' acc_ref = zeros(3,1,'single'); */
        /* 'task5:83' vel_ref = single([0;0;-1]); */
        /* 'task5:84' pos_ref = pos_takeoff + single([0;0;-t]); */
        pos_ref[0] = LW_ctrl_241029_1_DW.pos_takeoff[0];
        pos_ref[1] = LW_ctrl_241029_1_DW.pos_takeoff[1];
        pos_ref[2] = LW_ctrl_241029_1_DW.pos_takeoff[2] - t;

        /* 'task5:85' dot3x = zeros(3,1,'single'); */
        /* 'task5:86' yaw_ref = yaw_last; */
        *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

        /* 'task5:87' dotpsi = single(0); */
        /* 'task5:88' pos_start = pos_ref; */
        acc_ref[0] = 0.0F;
        vel_ref[0] = 0.0F;
        dot3x[0] = 0.0F;
        LW_ctrl_241029_1_DW.pos_start[0] = LW_ctrl_241029_1_DW.pos_takeoff[0];
        acc_ref[1] = 0.0F;
        vel_ref[1] = 0.0F;
        dot3x[1] = 0.0F;
        LW_ctrl_241029_1_DW.pos_start[1] = LW_ctrl_241029_1_DW.pos_takeoff[1];
        acc_ref[2] = 0.0F;
        vel_ref[2] = -1.0F;
        dot3x[2] = 0.0F;
        LW_ctrl_241029_1_DW.pos_start[2] = pos_ref[2];
      } else {
        /* 'task5:89' else */
        /* 'task5:90' pos_return = pos_start; */
        /* 'task5:91' t = t-10; */
        t -= 10.0F;

        /* 'task5:92' acc_ref = zeros(3,1,'single'); */
        /* 'task5:93' vel_ref = zeros(3,1,'single'); */
        /* 'task5:94' pos_ref = pos_start; */
        /* 'task5:95' dot3x = zeros(3,1,'single'); */
        acc_ref[0] = 0.0F;
        vel_ref[0] = 0.0F;
        pos_ref[0] = LW_ctrl_241029_1_DW.pos_start[0];
        dot3x[0] = 0.0F;
        acc_ref[1] = 0.0F;
        vel_ref[1] = 0.0F;
        pos_ref[1] = LW_ctrl_241029_1_DW.pos_start[1];
        dot3x[1] = 0.0F;
        acc_ref[2] = 0.0F;
        vel_ref[2] = 0.0F;
        pos_ref[2] = LW_ctrl_241029_1_DW.pos_start[2];
        dot3x[2] = 0.0F;

        /* 'task5:96' error_yaw = wrap_pi(task1_R - yaw); */
        /* 将 x 限定在[-pi,pi] */
        /* 'wrap_pi:3' i = 0; */
        CircleVmax = 0;

        /* 'wrap_pi:4' y = x; */
        task1_R = 0.785398185F - yaw;

        /* 'wrap_pi:5' while x > pi */
        exitg1 = false;
        while ((!exitg1) && (0.785398185F - yaw > 3.1415926535897931)) {
          /* 'wrap_pi:6' y =  x - 2*pi; */
          task1_R = (0.785398185F - yaw) - 6.28318548F;

          /* 'wrap_pi:7' i = i + 1; */
          CircleVmax++;

          /* 'wrap_pi:8' if i > 100 */
          if (CircleVmax > 100) {
            exitg1 = true;
          }
        }

        /* 'wrap_pi:12' i = 0; */
        CircleVmax = 0;

        /* 'wrap_pi:13' while x < -pi */
        exitg1 = false;
        while ((!exitg1) && (0.785398185F - yaw < -3.1415926535897931)) {
          /* 'wrap_pi:14' y =  x + 2*pi; */
          task1_R = (0.785398185F - yaw) + 6.28318548F;

          /* 'wrap_pi:15' i = i + 1; */
          CircleVmax++;

          /* 'wrap_pi:16' if i > 100 */
          if (CircleVmax > 100) {
            exitg1 = true;
          }
        }

        /* 'task5:97' yaw_ref = single(yaw + error_yaw*sin(pi/(Takeoff_holdtime*2)*t)); */
        profileStart_LW_ctrl_241029_1(202U); /* original_line:3113 */yaw += (real32_T)sin(0.0157079641F * t) * task1_R;profileEnd_LW_ctrl_241029_1(202U); /* original_line:3113 */

        /* 'task5:98' yaw_ref = wrap_pi(yaw_ref); */
        /* 将 x 限定在[-pi,pi] */
        /* 'wrap_pi:3' i = 0; */
        CircleVmax = 0;

        /* 'wrap_pi:4' y = x; */
        *yaw_ref = yaw;

        /* 'wrap_pi:5' while x > pi */
        exitg1 = false;
        while ((!exitg1) && (yaw > 3.1415926535897931)) {
          /* 'wrap_pi:6' y =  x - 2*pi; */
          *yaw_ref = yaw - 6.28318548F;

          /* 'wrap_pi:7' i = i + 1; */
          CircleVmax++;

          /* 'wrap_pi:8' if i > 100 */
          if (CircleVmax > 100) {
            exitg1 = true;
          }
        }

        /* 'wrap_pi:12' i = 0; */
        CircleVmax = 0;

        /* 'wrap_pi:13' while x < -pi */
        exitg1 = false;
        while ((!exitg1) && (yaw < -3.1415926535897931)) {
          /* 'wrap_pi:14' y =  x + 2*pi; */
          *yaw_ref = yaw + 6.28318548F;

          /* 'wrap_pi:15' i = i + 1; */
          CircleVmax++;

          /* 'wrap_pi:16' if i > 100 */
          if (CircleVmax > 100) {
            exitg1 = true;
          }
        }

        /* 'task5:99' dotpsi = single(error_yaw*pi/(2*Takeoff_holdtime)*cos(pi/(Takeoff_holdtime*2)*t)); */
        profileStart_LW_ctrl_241029_1(203U); /* original_line:3157 */*dotpsi = task1_R * 3.14159274F / 200.0F * (real32_T)cos(0.0157079641F *
          t);profileEnd_LW_ctrl_241029_1(203U); /* original_line:3158 */

        /* 'task5:100' yaw_last = yaw_ref; */
        LW_ctrl_241029_1_DW.yaw_last = *yaw_ref;

        /* 'task5:101' lineMode = int8(0); */
        LW_ctrl_241029_1_DW.lineMode = 0;
      }

      /* 'task5:103' reverse_flag = int8(0); */
    } else if (timestamp <= (LW_ctrl_241029_1_DW.time_start + 100.0F) +
               100000.0F) {
      /* 'task5:104' elseif timestamp <= time_start + Takeoff_holdtime +task1_time + Takeoff_time */
      /* task1 */
      /* 'task5:106' t = timestamp - time_start - Takeoff_holdtime - Takeoff_time; */
      t = (timestamp - LW_ctrl_241029_1_DW.time_start) - 100.0F;

      /* 'task5:108' if lineMode <= int8(1) */
      if (LW_ctrl_241029_1_DW.lineMode <= 1) {
        /* 小幅度高频率姿态响应 */
        /* 'task5:109' if t < 30 */
        if (t < 30.0F) {
          /* 'task5:110' pos_ref = pos_start + single(Rbe_psi'*[0.5*sin(3*t); 0; 0]); */
          profileStart_LW_ctrl_241029_1(200U); /* original_line:3181 */pos_ref_tmp = (real32_T)sin(3.0F * t) * 0.5F;profileEnd_LW_ctrl_241029_1(200U); /* original_line:3181 */

          /* 'task5:111' vel_ref = single(Rbe_psi'*[1.5*cos(3*t); 0; 0]); */
          profileStart_LW_ctrl_241029_1(201U); /* original_line:3184 */omega = (real32_T)cos(3.0F * t) * 1.5F;profileEnd_LW_ctrl_241029_1(201U); /* original_line:3184 */

          /* 'task5:112' acc_ref = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:113' dot3x = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:115' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:116' pos_last = pos_ref; */
          /* 'task5:117' pos_deacc_start = pos_ref; */
          for (ii = 0; ii < 3; ii++) {
            yaw = c[ii];
            pos_ref_tmp_0 = yaw * pos_ref_tmp;
            vel_ref_tmp = yaw * omega;
            yaw = c[ii + 3];
            vel_ref[ii] = yaw * 0.0F + vel_ref_tmp;
            yaw = (yaw * 0.0F + pos_ref_tmp_0) +
              LW_ctrl_241029_1_DW.pos_start[ii];
            pos_ref[ii] = yaw;
            acc_ref[ii] = 0.0F;
            dot3x[ii] = 0.0F;
            LW_ctrl_241029_1_DW.pos_last[ii] = yaw;
            LW_ctrl_241029_1_DW.pos_deacc_start[ii] = yaw;
          }

          /* 'task5:118' reverse_flag = int8(0); */
        } else {
          /* 'task5:119' else */
          /* 'task5:120' acc_ref = zeros(3,1,'single'); */
          /* 'task5:121' vel_ref = zeros(3,1,'single'); */
          /* 'task5:122' pos_ref = pos_last; */
          /* 'task5:123' pos_start = pos_last; */
          /* 'task5:124' dot3x = zeros(3,1,'single'); */
          acc_ref[0] = 0.0F;
          vel_ref[0] = 0.0F;
          pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
          LW_ctrl_241029_1_DW.pos_start[0] = LW_ctrl_241029_1_DW.pos_last[0];
          dot3x[0] = 0.0F;
          acc_ref[1] = 0.0F;
          vel_ref[1] = 0.0F;
          pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
          LW_ctrl_241029_1_DW.pos_start[1] = LW_ctrl_241029_1_DW.pos_last[1];
          dot3x[1] = 0.0F;
          acc_ref[2] = 0.0F;
          vel_ref[2] = 0.0F;
          pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
          LW_ctrl_241029_1_DW.pos_start[2] = LW_ctrl_241029_1_DW.pos_last[2];
          dot3x[2] = 0.0F;

          /* 'task5:125' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:126' reverse_flag = int8(0); */
        }
      } else if (LW_ctrl_241029_1_DW.lineMode <= 2) {
        /* 'task5:128' elseif lineMode <= int8(2) */
        /* 小幅度高频率姿态响应 */
        /* 'task5:129' if t-Acct < 30 */
        pos_ref_tmp_0 = t - LW_ctrl_241029_1_DW.Acct;
        if (pos_ref_tmp_0 < 30.0F) {
          /* 'task5:130' pos_ref = pos_deacc_start + single(Rbe_psi'*[0; 0.5*cos(3*(t-Acct)); 0]); */
          yaw = pos_ref_tmp_0 * 3.0F;
          profileStart_LW_ctrl_241029_1(198U); /* original_line:3245 */pos_ref_tmp = (real32_T)cos(yaw) * 0.5F;profileEnd_LW_ctrl_241029_1(198U); /* original_line:3245 */

          /* 'task5:131' vel_ref = single(Rbe_psi'*[0; -1.5*sin(3*(t-Acct)); 0]); */
          profileStart_LW_ctrl_241029_1(199U); /* original_line:3248 */pos_ref_tmp_0 = (real32_T)sin(yaw) * -1.5F;profileEnd_LW_ctrl_241029_1(199U); /* original_line:3248 */

          /* 'task5:132' acc_ref = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:133' dot3x = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:135' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:136' pos_last = pos_ref; */
          /* 'task5:137' pos_start = pos_ref; */
          for (ii = 0; ii < 3; ii++) {
            yaw = c[ii + 3];
            vel_ref[ii] = yaw * pos_ref_tmp_0;
            yaw = yaw * pos_ref_tmp + LW_ctrl_241029_1_DW.pos_deacc_start[ii];
            pos_ref[ii] = yaw;
            acc_ref[ii] = 0.0F;
            dot3x[ii] = 0.0F;
            LW_ctrl_241029_1_DW.pos_last[ii] = yaw;
            LW_ctrl_241029_1_DW.pos_start[ii] = yaw;
          }

          /* 'task5:138' reverse_flag = int8(0); */
        } else {
          /* 'task5:139' else */
          /* 'task5:140' acc_ref = zeros(3,1,'single'); */
          /* 'task5:141' vel_ref = zeros(3,1,'single'); */
          /* 'task5:142' pos_ref = pos_last; */
          /* 'task5:143' pos_start = pos_last; */
          /* 'task5:144' dot3x = zeros(3,1,'single'); */
          acc_ref[0] = 0.0F;
          vel_ref[0] = 0.0F;
          pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
          LW_ctrl_241029_1_DW.pos_start[0] = LW_ctrl_241029_1_DW.pos_last[0];
          dot3x[0] = 0.0F;
          acc_ref[1] = 0.0F;
          vel_ref[1] = 0.0F;
          pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
          LW_ctrl_241029_1_DW.pos_start[1] = LW_ctrl_241029_1_DW.pos_last[1];
          dot3x[1] = 0.0F;
          acc_ref[2] = 0.0F;
          vel_ref[2] = 0.0F;
          pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
          LW_ctrl_241029_1_DW.pos_start[2] = LW_ctrl_241029_1_DW.pos_last[2];
          dot3x[2] = 0.0F;

          /* 'task5:145' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:146' reverse_flag = int8(0); */
        }
      } else if (LW_ctrl_241029_1_DW.lineMode <= 3) {
        /* 'task5:148' elseif lineMode <= int8(3) */
        /* 小幅度高频率高度响应 */
        /* 'task5:149' if t-Unit < 10 */
        pos_ref_tmp_0 = t - LW_ctrl_241029_1_DW.Unit;
        if (pos_ref_tmp_0 < 10.0F) {
          /* 'task5:150' pos_ref = pos_start + single(Rbe_psi'*[0; 0; -(t-Unit)]); */
          /* 'task5:151' vel_ref = single(Rbe_psi'*[0; 0; -1]); */
          /* 'task5:152' acc_ref = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:153' dot3x = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:155' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:156' pos_last = pos_ref; */
          /* 'task5:157' pos_deacc_start = pos_ref; */
          for (ii = 0; ii < 3; ii++) {
            yaw = c[ii + 6] * -pos_ref_tmp_0 + LW_ctrl_241029_1_DW.pos_start[ii];
            pos_ref[ii] = yaw;
            vel_ref[ii] = b[ii];
            acc_ref[ii] = 0.0F;
            dot3x[ii] = 0.0F;
            LW_ctrl_241029_1_DW.pos_last[ii] = yaw;
            LW_ctrl_241029_1_DW.pos_deacc_start[ii] = yaw;
          }

          /* 'task5:158' reverse_flag = int8(0); */
        } else {
          /* 'task5:159' else */
          /* 'task5:160' acc_ref = zeros(3,1,'single'); */
          /* 'task5:161' vel_ref = zeros(3,1,'single'); */
          /* 'task5:162' pos_ref = pos_last; */
          /* 'task5:163' pos_start = pos_last; */
          /* 'task5:164' dot3x = zeros(3,1,'single'); */
          acc_ref[0] = 0.0F;
          vel_ref[0] = 0.0F;
          pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
          LW_ctrl_241029_1_DW.pos_start[0] = LW_ctrl_241029_1_DW.pos_last[0];
          dot3x[0] = 0.0F;
          acc_ref[1] = 0.0F;
          vel_ref[1] = 0.0F;
          pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
          LW_ctrl_241029_1_DW.pos_start[1] = LW_ctrl_241029_1_DW.pos_last[1];
          dot3x[1] = 0.0F;
          acc_ref[2] = 0.0F;
          vel_ref[2] = 0.0F;
          pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
          LW_ctrl_241029_1_DW.pos_start[2] = LW_ctrl_241029_1_DW.pos_last[2];
          dot3x[2] = 0.0F;

          /* 'task5:165' yaw_ref = yaw_last + single(wrap_pi(5/180*pi)*sin(3*(t-Unit))); */
          profileStart_LW_ctrl_241029_1(197U); /* original_line:3347 */*yaw_ref = (real32_T)sin(pos_ref_tmp_0 * 3.0F) * 0.0872664601F +
            LW_ctrl_241029_1_DW.yaw_last;profileEnd_LW_ctrl_241029_1(197U); /* original_line:3348 */

          /* 'task5:166' reverse_flag = int8(0); */
        }
      } else if (LW_ctrl_241029_1_DW.lineMode <= 4) {
        /* 'task5:168' elseif lineMode <= int8(4) */
        /* 中幅度姿态变化 */
        /* 'task5:169' if t-Acct < 30 */
        pos_ref_tmp_0 = t - LW_ctrl_241029_1_DW.Acct;
        if (pos_ref_tmp_0 < 30.0F) {
          /* 'task5:170' pos_ref = pos_start + single(Rbe_psi'*[6*(t-Acct); 0; 0]); */
          pos_ref_tmp = pos_ref_tmp_0 * 6.0F;

          /* 'task5:171' vel_ref = single(Rbe_psi'*[6; 0; 0]); */
          /* 'task5:172' acc_ref = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:173' dot3x = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:175' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:176' pos_last = pos_ref; */
          /* 'task5:177' pos_deacc_start = pos_ref; */
          for (ii = 0; ii < 3; ii++) {
            yaw = (c[ii + 3] * 0.0F + c[ii] * pos_ref_tmp) +
              LW_ctrl_241029_1_DW.pos_start[ii];
            pos_ref[ii] = yaw;
            vel_ref[ii] = d[ii];
            acc_ref[ii] = 0.0F;
            dot3x[ii] = 0.0F;
            LW_ctrl_241029_1_DW.pos_last[ii] = yaw;
            LW_ctrl_241029_1_DW.pos_deacc_start[ii] = yaw;
          }

          /* 'task5:178' reverse_flag = int8(0); */
        } else {
          /* 'task5:179' else */
          /* 'task5:180' acc_ref = zeros(3,1,'single'); */
          /* 'task5:181' vel_ref = zeros(3,1,'single'); */
          /* 'task5:182' pos_ref = pos_last; */
          /* 'task5:183' pos_start = pos_last; */
          /* 'task5:184' dot3x = zeros(3,1,'single'); */
          acc_ref[0] = 0.0F;
          vel_ref[0] = 0.0F;
          pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
          LW_ctrl_241029_1_DW.pos_start[0] = LW_ctrl_241029_1_DW.pos_last[0];
          dot3x[0] = 0.0F;
          acc_ref[1] = 0.0F;
          vel_ref[1] = 0.0F;
          pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
          LW_ctrl_241029_1_DW.pos_start[1] = LW_ctrl_241029_1_DW.pos_last[1];
          dot3x[1] = 0.0F;
          acc_ref[2] = 0.0F;
          vel_ref[2] = 0.0F;
          pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
          LW_ctrl_241029_1_DW.pos_start[2] = LW_ctrl_241029_1_DW.pos_last[2];
          dot3x[2] = 0.0F;

          /* 'task5:185' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:186' reverse_flag = int8(0); */
        }
      } else if (LW_ctrl_241029_1_DW.lineMode <= 5) {
        /* 'task5:188' elseif lineMode <= int8(5) */
        /* 小幅度高频率姿态响应 */
        /* 'task5:189' if t-Unit < 30 */
        pos_ref_tmp_0 = t - LW_ctrl_241029_1_DW.Unit;
        if (pos_ref_tmp_0 < 30.0F) {
          /* 'task5:190' pos_ref = pos_start + single(Rbe_psi'*[10*(t-Unit) + 0.2*sin(3*t); 0; 0]); */
          profileStart_LW_ctrl_241029_1(195U); /* original_line:3416 */pos_ref_tmp = (real32_T)sin(3.0F * t) * 0.2F + pos_ref_tmp_0 * 10.0F;profileEnd_LW_ctrl_241029_1(195U); /* original_line:3416 */

          /* 'task5:191' vel_ref = single(Rbe_psi'*[10 + 0.6*cos(3*(t-Unit)); 0 ; 0]); */
          profileStart_LW_ctrl_241029_1(196U); /* original_line:3419 */omega = (real32_T)cos(pos_ref_tmp_0 * 3.0F) * 0.6F + 10.0F;profileEnd_LW_ctrl_241029_1(196U); /* original_line:3419 */

          /* 'task5:192' acc_ref = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:193' dot3x = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:195' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:196' pos_last = pos_ref; */
          /* 'task5:197' pos_deacc_start = pos_ref; */
          for (ii = 0; ii < 3; ii++) {
            yaw = c[ii];
            pos_ref_tmp_0 = yaw * pos_ref_tmp;
            vel_ref_tmp = yaw * omega;
            yaw = c[ii + 3];
            vel_ref[ii] = yaw * 0.0F + vel_ref_tmp;
            yaw = (yaw * 0.0F + pos_ref_tmp_0) +
              LW_ctrl_241029_1_DW.pos_start[ii];
            pos_ref[ii] = yaw;
            acc_ref[ii] = 0.0F;
            dot3x[ii] = 0.0F;
            LW_ctrl_241029_1_DW.pos_last[ii] = yaw;
            LW_ctrl_241029_1_DW.pos_deacc_start[ii] = yaw;
          }

          /* 'task5:198' reverse_flag = int8(0); */
        } else {
          /* 'task5:199' else */
          /* 'task5:200' acc_ref = zeros(3,1,'single'); */
          /* 'task5:201' vel_ref = zeros(3,1,'single'); */
          /* 'task5:202' pos_ref = pos_last; */
          /* 'task5:203' pos_start = pos_last; */
          /* 'task5:204' dot3x = zeros(3,1,'single'); */
          acc_ref[0] = 0.0F;
          vel_ref[0] = 0.0F;
          pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
          LW_ctrl_241029_1_DW.pos_start[0] = LW_ctrl_241029_1_DW.pos_last[0];
          dot3x[0] = 0.0F;
          acc_ref[1] = 0.0F;
          vel_ref[1] = 0.0F;
          pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
          LW_ctrl_241029_1_DW.pos_start[1] = LW_ctrl_241029_1_DW.pos_last[1];
          dot3x[1] = 0.0F;
          acc_ref[2] = 0.0F;
          vel_ref[2] = 0.0F;
          pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
          LW_ctrl_241029_1_DW.pos_start[2] = LW_ctrl_241029_1_DW.pos_last[2];
          dot3x[2] = 0.0F;

          /* 'task5:205' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:206' reverse_flag = int8(0); */
        }
      } else if (LW_ctrl_241029_1_DW.lineMode <= 6) {
        /* 'task5:208' elseif lineMode <= int8(6) */
        /* 直线加速 */
        /* 'task5:209' if t-Acct < 12 */
        omega = t - LW_ctrl_241029_1_DW.Acct;
        if (omega < 12.0F) {
          /* 'task5:210' pos_ref = pos_start + single(Rbe_psi'*[0.5*(t-Acct)^2; 0; 0]); */
          pos_ref_tmp = omega * omega * 0.5F;

          /* 'task5:211' vel_ref = single(Rbe_psi'*[1*(t-Acct); 0 ; 0]); */
          /* 'task5:212' acc_ref = single(Rbe_psi'*[1; 0; 0]); */
          /* 'task5:213' dot3x = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:215' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:216' pos_last = pos_ref; */
          /* 'task5:217' pos_deacc_start = pos_ref; */
          for (ii = 0; ii < 3; ii++) {
            yaw = c[ii];
            pos_ref_tmp_0 = yaw * pos_ref_tmp;
            vel_ref_tmp = yaw * omega;
            yaw = c[ii + 3];
            vel_ref[ii] = yaw * 0.0F + vel_ref_tmp;
            yaw = (yaw * 0.0F + pos_ref_tmp_0) +
              LW_ctrl_241029_1_DW.pos_start[ii];
            pos_ref[ii] = yaw;
            acc_ref[ii] = e[ii];
            dot3x[ii] = 0.0F;
            LW_ctrl_241029_1_DW.pos_last[ii] = yaw;
            LW_ctrl_241029_1_DW.pos_deacc_start[ii] = yaw;
          }

          /* 'task5:218' reverse_flag = int8(0); */
        } else if (omega < 24.0F) {
          /* 'task5:219' elseif t-Acct < 24 */
          /* 'task5:220' t = t - 12; */
          t -= 12.0F;

          /* 'task5:221' pos_ref = pos_deacc_start + single(Rbe_psi'*[12*(t-Acct)-0.5*(t-Acct)^2; 0; 0]); */
          omega = t - LW_ctrl_241029_1_DW.Acct;
          pos_ref_tmp = omega * 12.0F - omega * omega * 0.5F;

          /* 'task5:222' vel_ref = single(Rbe_psi'*[12-1*(t-Acct); 0 ; 0]); */
          /* 'task5:223' acc_ref = single(Rbe_psi'*[-1; 0; 0]); */
          /* 'task5:224' dot3x = single(Rbe_psi'*[0; 0; 0]); */
          /* 'task5:226' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:227' pos_last = pos_ref; */
          /* 'task5:228' pos_start = pos_ref; */
          for (ii = 0; ii < 3; ii++) {
            yaw = c[ii];
            pos_ref_tmp_0 = yaw * pos_ref_tmp;
            vel_ref_tmp = (12.0F - omega) * yaw;
            yaw = c[ii + 3];
            vel_ref[ii] = yaw * 0.0F + vel_ref_tmp;
            yaw = (yaw * 0.0F + pos_ref_tmp_0) +
              LW_ctrl_241029_1_DW.pos_deacc_start[ii];
            pos_ref[ii] = yaw;
            acc_ref[ii] = f[ii];
            dot3x[ii] = 0.0F;
            LW_ctrl_241029_1_DW.pos_last[ii] = yaw;
            LW_ctrl_241029_1_DW.pos_start[ii] = yaw;
          }

          /* 'task5:229' reverse_flag = int8(0); */
        } else {
          /* 'task5:230' else */
          /* 'task5:231' acc_ref = zeros(3,1,'single'); */
          /* 'task5:232' vel_ref = zeros(3,1,'single'); */
          /* 'task5:233' pos_ref = pos_last; */
          /* 'task5:234' pos_start = pos_last; */
          /* 'task5:235' dot3x = zeros(3,1,'single'); */
          acc_ref[0] = 0.0F;
          vel_ref[0] = 0.0F;
          pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
          LW_ctrl_241029_1_DW.pos_start[0] = LW_ctrl_241029_1_DW.pos_last[0];
          dot3x[0] = 0.0F;
          acc_ref[1] = 0.0F;
          vel_ref[1] = 0.0F;
          pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
          LW_ctrl_241029_1_DW.pos_start[1] = LW_ctrl_241029_1_DW.pos_last[1];
          dot3x[1] = 0.0F;
          acc_ref[2] = 0.0F;
          vel_ref[2] = 0.0F;
          pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
          LW_ctrl_241029_1_DW.pos_start[2] = LW_ctrl_241029_1_DW.pos_last[2];
          dot3x[2] = 0.0F;

          /* 'task5:236' yaw_ref = yaw_last; */
          *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

          /* 'task5:237' reverse_flag = int8(0); */
        }
      } else if (LW_ctrl_241029_1_DW.lineMode <= 7) {
        /* 'task5:239' elseif lineMode <= int8(7) */
        /* 加速 */
        /* 'task5:240' LW_OB_TYPE = single(1); */
        /*  */
        /* 'task5:241' LW_OB_CIRCLE_R = single(50); */
        /* 10m/s,30m;15m/s,50m */
        /* 'task5:242' LW_OB_CIRCLE_V = single(10); */
        /* 'task5:243' LW_OB_CIRCLE_W = single(0.03); */
        /* 0.03 */
        /* 'task5:244' task1_R = LW_OB_CIRCLE_R; */
        task1_R = 50.0F;

        /* 'task5:245' task1_omega = LW_OB_CIRCLE_W; */
        /* 'task5:246' CircleVmax = LW_OB_CIRCLE_V; */
        CircleVmax = 10;

        /* 'task5:247' t = t - Unit; */
        t -= LW_ctrl_241029_1_DW.Unit;

        /* 'task5:248' if LW_OB_TYPE < 0.5 */
        /* 'task5:255' else */
        /* 'task5:256' pos_ref = pos_start + [task1_R*(1 - cos(0.5*task1_omega/2*t*t)); task1_R/2*sin(0.5*task1_omega*t*t); 0]; */
        vel_ref_tmp = 0.0075F * t * t;
        profileStart_LW_ctrl_241029_1(187U); /* original_line:3590 */pos_ref_tmp = (real32_T)cos(vel_ref_tmp);profileEnd_LW_ctrl_241029_1(187U); /* original_line:3590 */
        omega = 0.015F * t * t;
        profileStart_LW_ctrl_241029_1(188U); /* original_line:3592 */pos_ref_tmp_0 = (real32_T)sin(omega);profileEnd_LW_ctrl_241029_1(188U); /* original_line:3592 */
        pos_ref[0] = (1.0F - pos_ref_tmp) * 50.0F +
          LW_ctrl_241029_1_DW.pos_start[0];
        pos_ref[1] = 25.0F * pos_ref_tmp_0 + LW_ctrl_241029_1_DW.pos_start[1];
        pos_ref[2] = LW_ctrl_241029_1_DW.pos_start[2];

        /* 'task5:257' vel_ref = [task1_omega/2*t*task1_R*sin(0.5*task1_omega/2*t*t); task1_omega*t*task1_R/2*cos(0.5*task1_omega*t*t); 0]; */
        profileStart_LW_ctrl_241029_1(189U); /* original_line:3599 */vel_ref_tmp = (real32_T)sin(vel_ref_tmp);profileEnd_LW_ctrl_241029_1(189U); /* original_line:3599 */
        vel_ref[0] = 0.015F * t * 50.0F * vel_ref_tmp;
        profileStart_LW_ctrl_241029_1(190U); /* original_line:3601 */vel_ref[1] = 0.03F * t * 50.0F / 2.0F * (real32_T)cos(omega);profileEnd_LW_ctrl_241029_1(190U); /* original_line:3601 */
        vel_ref[2] = 0.0F;

        /* 'task5:258' acc_ref = [task1_omega/2*task1_R*sin(0.5*task1_omega/2*t*t) + (task1_omega/2)^2*t^2*task1_R*cos(0.5*task1_omega/2*t*t); */
        /* 'task5:259'                            task1_omega*task1_R/2*cos(0.5*task1_omega*t^2) - task1_omega^2*t^2*task1_R/2*sin(0.5*task1_omega*t*t); 0]; */
        acc_ref_tmp = t * t;
        vel_ref_tmp_0 = acc_ref_tmp * 0.015F;
        profileStart_LW_ctrl_241029_1(191U); /* original_line:3608 */tem = (real32_T)cos(vel_ref_tmp_0);profileEnd_LW_ctrl_241029_1(191U); /* original_line:3608 */
        acc_ref[0] = acc_ref_tmp * 0.000225F * 50.0F * pos_ref_tmp + 0.75F *
          vel_ref_tmp;
        acc_ref[1] = 0.75F * tem - acc_ref_tmp * 0.0009F * 50.0F / 2.0F *
          pos_ref_tmp_0;
        acc_ref[2] = 0.0F;

        /* 'task5:260' dot3x = [3*(task1_omega/2)^2*t*task1_R*cos(0.5*task1_omega/2*t^2)-(task1_omega/2)^3*t^3*task1_R*sin(0.5*task1_omega/2*t^2); */
        /* 'task5:261'                         -3*task1_omega^2*t*task1_R/2*sin(0.5*task1_omega*t^2)-task1_omega^3*t^3*task1_R/2*cos(0.5*task1_omega*t^2); 0]; */
        profileStart_LW_ctrl_241029_1(192U); /* original_line:3617 */omega = rt_powf_snf(t, 3.0F);profileEnd_LW_ctrl_241029_1(192U); /* original_line:3617 */
        pos_ref_tmp = acc_ref_tmp * 0.0075F;
        profileStart_LW_ctrl_241029_1(193U); /* original_line:3619 */dot3x[0] = 0.000675F * t * 50.0F * (real32_T)cos(pos_ref_tmp) -
          3.37499978E-6F * omega * 50.0F * (real32_T)sin(pos_ref_tmp);profileEnd_LW_ctrl_241029_1(193U); /* original_line:3620 */
        profileStart_LW_ctrl_241029_1(194U); /* original_line:3621 */dot3x[1] = -0.0027F * t * 50.0F / 2.0F * (real32_T)sin(vel_ref_tmp_0) -
          2.69999982E-5F * omega * 50.0F / 2.0F * tem;profileEnd_LW_ctrl_241029_1(194U); /* original_line:3622 */
        dot3x[2] = 0.0F;

        /* 'task5:264' yaw_ref = single(NaN); */
        *yaw_ref = (rtNaNF);

        /* 'task5:265' pos_last = pos_ref; */
        LW_ctrl_241029_1_DW.pos_last[0] = pos_ref[0];
        LW_ctrl_241029_1_DW.pos_last[1] = pos_ref[1];
        LW_ctrl_241029_1_DW.pos_last[2] = LW_ctrl_241029_1_DW.pos_start[2];

        /* 'task5:266' yaw_last = yaw; */
        LW_ctrl_241029_1_DW.yaw_last = yaw;
      } else if (LW_ctrl_241029_1_DW.lineMode <= 8) {
        /* 'task5:267' elseif lineMode <= int8(8) */
        /* 匀速 */
        /* 'task5:268' LW_OB_TYPE = single(1); */
        /*  */
        /* 'task5:269' LW_OB_CIRCLE_R = single(50); */
        /* 10m/s,30m;15m/s,50m */
        /* 'task5:270' LW_OB_CIRCLE_V = single(10); */
        /* 'task5:271' LW_OB_CIRCLE_W = single(0.03); */
        /* 0.03 */
        /* 'task5:272' task1_R = LW_OB_CIRCLE_R; */
        task1_R = 50.0F;

        /* 'task5:273' task1_omega = LW_OB_CIRCLE_W; */
        /* 'task5:274' CircleVmax = LW_OB_CIRCLE_V; */
        CircleVmax = 10;

        /* 'task5:275' omega = 0.5*task1_omega*Acct^2 +task1_omega*Acct*(t - Acct); */
        tem = LW_ctrl_241029_1_DW.Acct * LW_ctrl_241029_1_DW.Acct;
        omega = 0.03F * LW_ctrl_241029_1_DW.Acct * (t - LW_ctrl_241029_1_DW.Acct)
          + tem * 0.015F;

        /* 'task5:276' if LW_OB_TYPE < 0.5 */
        /* 'task5:284' else */
        /* 'task5:285' pos_ref = pos_start + [task1_R*(1 - cos(omega/2)); task1_R/2*sin(omega); 0]; */
        profileStart_LW_ctrl_241029_1(182U); /* original_line:3660 */pos_ref_tmp = (real32_T)cos(omega / 2.0F);profileEnd_LW_ctrl_241029_1(182U); /* original_line:3660 */
        profileStart_LW_ctrl_241029_1(183U); /* original_line:3661 */pos_ref_tmp_0 = (real32_T)sin(omega);profileEnd_LW_ctrl_241029_1(183U); /* original_line:3661 */
        pos_ref[0] = (1.0F - pos_ref_tmp) * 50.0F +
          LW_ctrl_241029_1_DW.pos_start[0];
        pos_ref[1] = 25.0F * pos_ref_tmp_0 + LW_ctrl_241029_1_DW.pos_start[1];
        pos_ref[2] = LW_ctrl_241029_1_DW.pos_start[2];

        /* 'task5:286' vel_ref = [Acct*task1_R*task1_omega/2*sin(omega/2);  */
        /* 'task5:287'                            Acct*task1_R/2*task1_omega*cos(omega); 0]; */
        profileStart_LW_ctrl_241029_1(184U); /* original_line:3669 */vel_ref_tmp = (real32_T)sin(omega / 2.0F);profileEnd_LW_ctrl_241029_1(184U); /* original_line:3669 */
        profileStart_LW_ctrl_241029_1(185U); /* original_line:3670 */vel_ref_tmp_0 = (real32_T)cos(omega);profileEnd_LW_ctrl_241029_1(185U); /* original_line:3670 */
        vel_ref[0] = LW_ctrl_241029_1_DW.Acct * 50.0F * 0.03F / 2.0F *
          vel_ref_tmp;
        vel_ref[1] = LW_ctrl_241029_1_DW.Acct * 50.0F / 2.0F * 0.03F *
          vel_ref_tmp_0;
        vel_ref[2] = 0.0F;

        /* 'task5:288' acc_ref = [Acct^2*task1_R*(task1_omega/2)^2*cos(omega/2); */
        /* 'task5:289'                           -Acct^2*task1_R/2*task1_omega^2*sin(omega); 0]; */
        acc_ref[0] = tem * 50.0F * 0.000225F * pos_ref_tmp;
        acc_ref[1] = -tem * 50.0F / 2.0F * 0.0009F * pos_ref_tmp_0;
        acc_ref[2] = 0.0F;

        /* 'task5:290' dot3x = [-Acct^3*task1_R*(task1_omega/2)^3*sin(omega/2); */
        /* 'task5:291'                          -Acct^3*task1_R/2*task1_omega^3*cos(omega); 0]; */
        profileStart_LW_ctrl_241029_1(186U); /* original_line:3685 */pos_ref_tmp = -rt_powf_snf(LW_ctrl_241029_1_DW.Acct, 3.0F) * 50.0F;profileEnd_LW_ctrl_241029_1(186U); /* original_line:3685 */
        dot3x[0] = pos_ref_tmp * 3.37499978E-6F * vel_ref_tmp;
        dot3x[1] = pos_ref_tmp / 2.0F * 2.69999982E-5F * vel_ref_tmp_0;
        dot3x[2] = 0.0F;

        /* 'task5:293' yaw_ref = single(NaN); */
        *yaw_ref = (rtNaNF);

        /* 'task5:294' pos_last = pos_ref; */
        LW_ctrl_241029_1_DW.pos_last[0] = pos_ref[0];
        LW_ctrl_241029_1_DW.pos_last[1] = pos_ref[1];
        LW_ctrl_241029_1_DW.pos_last[2] = LW_ctrl_241029_1_DW.pos_start[2];

        /* 'task5:295' yaw_last = yaw; */
        LW_ctrl_241029_1_DW.yaw_last = yaw;
      } else if (LW_ctrl_241029_1_DW.lineMode <= 9) {
        /* 'task5:296' elseif lineMode <= int8(9) */
        /* 减速 */
        /* 'task5:297' LW_OB_TYPE = single(1); */
        /*  */
        /* 'task5:298' LW_OB_CIRCLE_R = single(50); */
        /* 10m/s,30m;15m/s,50m */
        /* 'task5:299' LW_OB_CIRCLE_V = single(10); */
        /* 'task5:300' LW_OB_CIRCLE_W = single(0.03); */
        /* 0.03 */
        /* 'task5:301' task1_R = LW_OB_CIRCLE_R; */
        task1_R = 50.0F;

        /* 'task5:302' task1_omega = LW_OB_CIRCLE_W; */
        /* 'task5:303' CircleVmax = LW_OB_CIRCLE_V; */
        CircleVmax = 10;

        /* 'task5:304' tem = (t - Acct - Unit); */
        tem = (t - LW_ctrl_241029_1_DW.Acct) - LW_ctrl_241029_1_DW.Unit;

        /* 'task5:305' omega = 0.5*task1_omega*Acct^2 +task1_omega*Acct*Unit + 0.5*task1_omega*(2*Acct - tem)*tem; */
        omega = (2.0F * LW_ctrl_241029_1_DW.Acct - tem) * 0.015F * tem +
          (LW_ctrl_241029_1_DW.Acct * LW_ctrl_241029_1_DW.Acct * 0.015F + 0.03F *
           LW_ctrl_241029_1_DW.Acct * LW_ctrl_241029_1_DW.Unit);

        /* deAcct = Acct + Unit - t; */
        /* 'task5:307' if LW_OB_TYPE < 0.5 */
        /* 'task5:315' else */
        /* 'task5:316' pos_ref = pos_start + [task1_R*(1 - cos(omega/2)); task1_R/2*sin(omega); 0]; */
        profileStart_LW_ctrl_241029_1(177U); /* original_line:3729 */pos_ref_tmp = (real32_T)cos(omega / 2.0F);profileEnd_LW_ctrl_241029_1(177U); /* original_line:3729 */
        profileStart_LW_ctrl_241029_1(178U); /* original_line:3730 */pos_ref_tmp_0 = (real32_T)sin(omega);profileEnd_LW_ctrl_241029_1(178U); /* original_line:3730 */
        pos_ref[0] = (1.0F - pos_ref_tmp) * 50.0F +
          LW_ctrl_241029_1_DW.pos_start[0];
        pos_ref[1] = 25.0F * pos_ref_tmp_0 + LW_ctrl_241029_1_DW.pos_start[1];
        pos_ref[2] = LW_ctrl_241029_1_DW.pos_start[2];

        /* 'task5:317' vel_ref = [task1_R*(Acct - tem)*task1_omega/2*sin(omega/2); */
        /* 'task5:318'                            task1_R/2*(Acct - tem)*task1_omega*cos(omega); 0]; */
        profileStart_LW_ctrl_241029_1(179U); /* original_line:3738 */vel_ref_tmp = (real32_T)sin(omega / 2.0F);profileEnd_LW_ctrl_241029_1(179U); /* original_line:3738 */
        profileStart_LW_ctrl_241029_1(180U); /* original_line:3739 */vel_ref_tmp_0 = (real32_T)cos(omega);profileEnd_LW_ctrl_241029_1(180U); /* original_line:3739 */
        omega = LW_ctrl_241029_1_DW.Acct - tem;
        vel_ref[0] = omega * 50.0F * 0.03F / 2.0F * vel_ref_tmp;
        vel_ref[1] = omega * 25.0F * 0.03F * vel_ref_tmp_0;
        vel_ref[2] = 0.0F;

        /* 'task5:319' acc_ref = [(task1_R*(task1_omega/2)^2*cos(omega/2)*(Acct - tem)*(2*Acct - 2*tem))/2 - task1_R*task1_omega/2*sin(omega/2); */
        /* 'task5:320'                            - task1_R/2*task1_omega*cos(omega) - (task1_R/2*task1_omega^2*sin(omega)*(Acct - tem)*(2*Acct - 2*tem))/2; 0]; */
        tem = 2.0F * LW_ctrl_241029_1_DW.Acct - 2.0F * tem;
        acc_ref_tmp = 0.0112499995F * pos_ref_tmp * omega;
        acc_ref[0] = acc_ref_tmp * tem / 2.0F - 0.75F * vel_ref_tmp;
        acc_ref_tmp_0 = 0.022499999F * pos_ref_tmp_0 * omega;
        acc_ref[1] = -0.75F * vel_ref_tmp_0 - acc_ref_tmp_0 * tem / 2.0F;
        acc_ref[2] = 0.0F;

        /* 'task5:321' dot3x = [- task1_R*(task1_omega/2)^3*sin(omega/2)*(Acct - tem)^3 - task1_R*(task1_omega/2)^2*cos(omega/2)*(Acct - tem) - task1_R*(task1_omega/2)^2*cos(omega/2)*(2*Acct - 2*tem); */
        /* 'task5:322'                          task1_R/2*task1_omega^2*sin(omega)*(2*Acct - 2*tem) + task1_R/2*task1_omega^2*sin(omega)*(Acct - tem) - task1_R/2*task1_omega^3*cos(omega)*(Acct - tem)^3; 0]; */
        profileStart_LW_ctrl_241029_1(181U); /* original_line:3756 */omega = rt_powf_snf(omega, 3.0F);profileEnd_LW_ctrl_241029_1(181U); /* original_line:3756 */
        dot3x[0] = (-0.00016874999F * vel_ref_tmp * omega - acc_ref_tmp) -
          0.0112499995F * pos_ref_tmp * tem;
        dot3x[1] = (0.022499999F * pos_ref_tmp_0 * tem + acc_ref_tmp_0) -
          0.000674999959F * vel_ref_tmp_0 * omega;
        dot3x[2] = 0.0F;

        /* 'task5:325' yaw_ref = single(NaN); */
        *yaw_ref = (rtNaNF);

        /* 'task5:326' pos_last = pos_ref; */
        LW_ctrl_241029_1_DW.pos_last[0] = pos_ref[0];
        LW_ctrl_241029_1_DW.pos_last[1] = pos_ref[1];
        LW_ctrl_241029_1_DW.pos_last[2] = LW_ctrl_241029_1_DW.pos_start[2];

        /* 'task5:327' yaw_last = yaw; */
        LW_ctrl_241029_1_DW.yaw_last = yaw;
      } else {
        /* 'task5:328' else */
        /* 'task5:329' acc_ref = zeros(3,1,'single'); */
        /* 'task5:330' vel_ref = zeros(3,1,'single'); */
        /* 'task5:331' pos_ref = pos_last; */
        /* 'task5:332' dot3x = zeros(3,1,'single'); */
        acc_ref[0] = 0.0F;
        vel_ref[0] = 0.0F;
        pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
        dot3x[0] = 0.0F;
        acc_ref[1] = 0.0F;
        vel_ref[1] = 0.0F;
        pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
        dot3x[1] = 0.0F;
        acc_ref[2] = 0.0F;
        vel_ref[2] = 0.0F;
        pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
        dot3x[2] = 0.0F;

        /* 'task5:333' yaw_ref = yaw_last; */
        *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

        /* 'task5:334' reverse_flag = int8(0); */
      }

      /* 'task5:337' time1 = 40; */
      /* 'task5:338' if t <= time1 && lineMode <= int8(1) */
      if ((t <= 40.0F) && (LW_ctrl_241029_1_DW.lineMode <= 1)) {
        /* 俯仰高频 */
        /* 'task5:339' lineMode = int8(1); */
        LW_ctrl_241029_1_DW.lineMode = 1;

        /* 'task5:340' Acct = t; */
        LW_ctrl_241029_1_DW.Acct = t;
      } else if ((t <= 80.0F) && (LW_ctrl_241029_1_DW.lineMode <= 2)) {
        /* 'task5:341' elseif t <= 2*time1 && lineMode <= int8(2) */
        /* 滚转高频 */
        /* 'task5:342' lineMode = int8(2); */
        LW_ctrl_241029_1_DW.lineMode = 2;

        /* 'task5:343' Unit = t; */
        LW_ctrl_241029_1_DW.Unit = t;
      } else if ((t <= 120.0F) && (LW_ctrl_241029_1_DW.lineMode <= 3)) {
        /* 'task5:344' elseif t <= 3*time1 && lineMode <= int8(3) */
        /* 高度阶跃 */
        /* 'task5:345' lineMode = int8(3); */
        LW_ctrl_241029_1_DW.lineMode = 3;

        /* 'task5:346' Acct = t; */
        LW_ctrl_241029_1_DW.Acct = t;
      } else if ((t <= 160.0F) && (LW_ctrl_241029_1_DW.lineMode <= 4)) {
        /* 'task5:347' elseif t <= 4*time1 && lineMode <= int8(4) */
        /* 俯仰阶跃 */
        /* 'task5:348' lineMode = int8(4); */
        LW_ctrl_241029_1_DW.lineMode = 4;

        /* 'task5:349' Unit = t; */
        LW_ctrl_241029_1_DW.Unit = t;
      } else if ((t <= 200.0F) && (LW_ctrl_241029_1_DW.lineMode <= 5)) {
        /* 'task5:350' elseif t <= 5*time1 && lineMode <= int8(5) */
        /* 巡航俯仰高频 */
        /* 'task5:351' lineMode = int8(5); */
        LW_ctrl_241029_1_DW.lineMode = 5;

        /* 'task5:352' Acct = t; */
        LW_ctrl_241029_1_DW.Acct = t;
      } else if ((t <= 240.0F) && (LW_ctrl_241029_1_DW.lineMode <= 6)) {
        /* 'task5:353' elseif t <= 6*time1  && lineMode <= int8(6) */
        /* 直线加减速 */
        /* 'task5:354' lineMode = int8(6); */
        LW_ctrl_241029_1_DW.lineMode = 6;

        /* 'task5:355' Unit = t; */
        LW_ctrl_241029_1_DW.Unit = t;
      } else if ((LW_ctrl_241029_1_norm(vel_ref) < CircleVmax) &&
                 (LW_ctrl_241029_1_DW.lineMode <= 7)) {
        /* 'task5:356' elseif norm(vel_ref) < CircleVmax && lineMode <= int8(7) */
        /* 'task5:357' lineMode = int8(7); */
        LW_ctrl_241029_1_DW.lineMode = 7;

        /* 'task5:358' Acct = t; */
        LW_ctrl_241029_1_DW.Acct = t;
      } else if ((LW_ctrl_241029_1_DW.lineMode <= 8) && (t < 6.28318548F *
                  task1_R / (real32_T)CircleVmax * 12.0F +
                  LW_ctrl_241029_1_DW.Acct)) {
        /* 'task5:359' elseif lineMode <= int8(8) && t < 2*pi*task1_R/CircleVmax*nCircle + Acct */
        /* 'task5:360' lineMode = int8(8); */
        LW_ctrl_241029_1_DW.lineMode = 8;

        /* 'task5:361' Unit = t - Acct; */
        LW_ctrl_241029_1_DW.Unit = t - LW_ctrl_241029_1_DW.Acct;
      } else if ((LW_ctrl_241029_1_DW.lineMode <= 9) &&
                 (LW_ctrl_241029_1_DW.Acct - ((t - LW_ctrl_241029_1_DW.Acct) -
                   LW_ctrl_241029_1_DW.Unit) >= 0.0F)) {
        /* 'task5:362' elseif lineMode <= int8(9) && Acct - (t - Acct - Unit) >= 0 */
        /* 'task5:363' lineMode = int8(9); */
        LW_ctrl_241029_1_DW.lineMode = 9;
      } else {
        /* 'task5:364' else */
        /* 'task5:365' lineMode = int8(10); */
        LW_ctrl_241029_1_DW.lineMode = 10;
      }
    } else {
      /* 'task5:367' else */
      /* 'task5:368' acc_ref = zeros(3,1,'single'); */
      /* 'task5:369' vel_ref = zeros(3,1,'single'); */
      /* 'task5:370' pos_ref = pos_last; */
      /* 'task5:371' dot3x = zeros(3,1,'single'); */
      acc_ref[0] = 0.0F;
      vel_ref[0] = 0.0F;
      pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
      dot3x[0] = 0.0F;
      acc_ref[1] = 0.0F;
      vel_ref[1] = 0.0F;
      pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
      dot3x[1] = 0.0F;
      acc_ref[2] = 0.0F;
      vel_ref[2] = 0.0F;
      pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
      dot3x[2] = 0.0F;

      /* 'task5:372' yaw_ref = yaw_last; */
      *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

      /* 'task5:373' dotpsi = single(0); */
      /* 'task5:374' reverse_flag = int8(0); */
    }
  } else {
    /* 'task5:376' else */
    /* 悬停 */
    /* 'task5:378' acc_ref = zeros(3,1,'single'); */
    /* 'task5:379' vel_ref = zeros(3,1,'single'); */
    /* 'task5:380' pos_ref = pos_last; */
    /* 'task5:381' dot3x = zeros(3,1,'single'); */
    acc_ref[0] = 0.0F;
    vel_ref[0] = 0.0F;
    pos_ref[0] = LW_ctrl_241029_1_DW.pos_last[0];
    dot3x[0] = 0.0F;
    acc_ref[1] = 0.0F;
    vel_ref[1] = 0.0F;
    pos_ref[1] = LW_ctrl_241029_1_DW.pos_last[1];
    dot3x[1] = 0.0F;
    acc_ref[2] = 0.0F;
    vel_ref[2] = 0.0F;
    pos_ref[2] = LW_ctrl_241029_1_DW.pos_last[2];
    dot3x[2] = 0.0F;

    /* 'task5:382' yaw_ref = yaw_last; */
    *yaw_ref = LW_ctrl_241029_1_DW.yaw_last;

    /* 'task5:383' dotpsi = single(0); */
    /* 'task5:384' reverse_flag = int8(0); */
  }

  /* 'task5:386' euler_ref = single([0;0;0]); */
  /* 'task5:387' reverse_flag = int8(0); */
}

/*
 * Function for MATLAB Function: '<S407>/MATLAB Function'
 * function y = rcNormalize(ch, RC_MIN, RC_MAX, RC_REV, DEADZONE_RATE)
 * Function description:
 *   Control the range of the remote control input from RCMin to RCMax, and set
 *   a dead zone with a dead zone size of ±deadZone,the output y is
 *   normalized to 0~1.You can get the RC calibration parameters in QGC.
 */
static real32_T LW_ctrl_241029_1_rcNormalize(real32_T ch, real32_T RC_MIN,
  real32_T RC_MAX, real32_T RC_REV, real32_T DEADZONE_RATE)
{
  real32_T deadzone;
  real32_T k;
  real32_T rc_mid;
  real32_T y;

  /* 'rcNormalize:6' rc_min = RC_MIN; */
  /* 'rcNormalize:7' rc_max = RC_MAX; */
  /* 'rcNormalize:8' rc_mid = ((rc_min + rc_max)/single(2.0)); */
  rc_mid = (RC_MIN + RC_MAX) / 2.0F;

  /* 'rcNormalize:9' deadzone_rate = DEADZONE_RATE; */
  /* 'rcNormalize:10' deadzone = deadzone_rate*(rc_max - rc_min); */
  deadzone = (RC_MAX - RC_MIN) * DEADZONE_RATE;

  /* 'rcNormalize:11' k = single(1)/(rc_max - rc_mid - deadzone); */
  k = 1.0F / ((RC_MAX - rc_mid) - deadzone);

  /* 'rcNormalize:12' ch = constrain(ch, rc_min, rc_max); */
  /* CONSTRAIN 此处显示有关此函数的摘要 */
  /*    此处显示详细说明 */
  /*  min  = single(min); */
  /*  max = single(max); */
  /* 'constrain:6' if x > max */
  if (ch > RC_MAX) {
    /* 'constrain:7' y = max; */
    ch = RC_MAX;
  } else if (ch < RC_MIN) {
    /* 'constrain:8' elseif x < min */
    /* 'constrain:9' y = min; */
    ch = RC_MIN;
  } else {
    /* 'constrain:10' else */
    /* 'constrain:11' y = x; */
  }

  /* dead zone and normalize */
  /* 'rcNormalize:15' if(ch > rc_mid + deadzone) */
  if (ch > rc_mid + deadzone) {
    /* 'rcNormalize:16' y = (ch - rc_mid - deadzone)*k; */
    y = ((ch - rc_mid) - deadzone) * k;
  } else if (ch < rc_mid - deadzone) {
    /* 'rcNormalize:17' elseif(ch < rc_mid - deadzone) */
    /* 'rcNormalize:18' y = (ch - rc_mid + deadzone)*k; */
    y = ((ch - rc_mid) + deadzone) * k;
  } else {
    /* 'rcNormalize:19' else */
    /* 'rcNormalize:20' y = single(0.0); */
    y = 0.0F;
  }

  /* 'rcNormalize:22' y = single(RC_REV*y); */
  y *= RC_REV;
  return y;
}

/* Model step function */
void LW_ctrl_241029_1_step(void)
{
  int32_T i;
  int32_T trueCount;
  real32_T Filter_o5;
  real32_T q;
  real32_T rtb_FilterCoefficient_jy_tmp;
  int8_T tmp;
  int8_T tmp_0;
  uint8_T rtb_blockMode;
  boolean_T f_y;
  boolean_T rEQ0;
  boolean_T rtb_RelationalOperator_om;
  boolean_T rtb_integral_reset_idx_0;
  boolean_T rtb_integral_reset_idx_1;
  boolean_T rtb_rate_ctrl_integral_reset_id;
  boolean_T want_hold_xy;
  boolean_T want_hold_z;
  static const int8_T e[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real32_T b[16] = { 0.25F, 0.25F, 0.25F, 0.25F, -1.1765F, -1.1765F,
    1.1765F, 1.1765F, 1.0F, -1.0F, 1.0F, -1.0F, 15.0602F, -15.0602F, -15.0602F,
    15.0602F };

  boolean_T exitg1;
  boolean_T guard1;

  /* Chart: '<Root>/Scheduler' incorporates:
   *  MATLAB Function: '<S11>/MATLAB Function1'
   */
  /* Gateway: Scheduler */
  if (LW_ctrl_241029_1_DW.temporalCounter_i1 < 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i1 = 1U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i2 < 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i2 = 1U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i3 < 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i3 = 1U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i4 < 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i4 = 1U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i5 < 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i5 = 1U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i6 < 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i6 = 1U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i7 < 4U) {
    LW_ctrl_241029_1_DW.temporalCounter_i7++;
  }

  /* During: Scheduler */
  if (LW_ctrl_241029_1_DW.is_active_c3_LW_ctrl_241029_1 == 0) {
    /* Entry: Scheduler */
    LW_ctrl_241029_1_DW.is_active_c3_LW_ctrl_241029_1 = 1U;

    /* Entry Internal: Scheduler */
    /* Transition: '<S3>:2' */
    LW_ctrl_241029_1_DW.temporalCounter_i1 = 0U;
    LW_ctrl_241029_1_DW.temporalCounter_i2 = 0U;
    LW_ctrl_241029_1_DW.temporalCounter_i3 = 0U;
    LW_ctrl_241029_1_DW.temporalCounter_i4 = 0U;
    LW_ctrl_241029_1_DW.temporalCounter_i5 = 0U;
    LW_ctrl_241029_1_DW.temporalCounter_i6 = 0U;
    LW_ctrl_241029_1_DW.temporalCounter_i7 = 0U;

    /* Entry 'Scheduler': '<S3>:1' */
  } else {
    /* During 'Scheduler': '<S3>:1' */
    /* '<S3>:1:2' sf_internal_predicateOutput = every(StatesUpdate_cycle,tick); */
    if (LW_ctrl_241029_1_DW.temporalCounter_i1 == 1U) {
      /* Outputs for Function Call SubSystem: '<Root>/states_update' */
      /* S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger2' */
      /* '<S3>:1:2' send(StatesUpdate); */
      /* Event: '<S3>:23' */
      profileStart_LW_ctrl_241029_1(2U); /* original_line:4081 */{
        //interval val: 0
        bool updated;
        orb_check(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger2_uO.fd,
                  &updated);
        if (updated) {
          /* obtained uorb data */
          /* copy sensors raw data into local buffer */
          orb_copy(ORB_ID(vehicle_local_position),
                   LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger2_uO.fd,
                   &LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2);
        }
      }profileEnd_LW_ctrl_241029_1(2U); /* original_line:4093 */

      /* S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger' */
      profileStart_LW_ctrl_241029_1(3U); /* original_line:4096 */{
        //interval val: 0
        bool updated;
        orb_check(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_a.fd,
                  &updated);
        if (updated) {
          /* obtained uorb data */
          /* copy sensors raw data into local buffer */
          orb_copy(ORB_ID(vehicle_attitude),
                   LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_a.fd,
                   &LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger_d);
        }
      }profileEnd_LW_ctrl_241029_1(3U); /* original_line:4108 */

      /* MATLAB Function: '<S419>/nan_inf_q' incorporates:
       *  Math: '<S419>/Math Function'
       */
      /* MATLAB Function 'states_update/vehicle_local_position/HIL&FLY V1.13.3/nan_inf_q': '<S429>:1' */
      /* '<S429>:1:3' for i = 1:length(u) */
      for (i = 0; i < 4; i++) {
        LW_ctrl_241029_1_B.y[i] =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger_d.q[i];

        /* '<S429>:1:4' if isnan(u(i)) || isinf(u(i)) */
        if (rtIsNaNF(LW_ctrl_241029_1_B.y[i]) || rtIsInfF(LW_ctrl_241029_1_B.y[i]))
        {
          /* '<S429>:1:5' if i == 1 */
          if (i + 1 == 1) {
            /* '<S429>:1:6' u(i) = single(1); */
            LW_ctrl_241029_1_B.y[i] = 1.0F;
          } else {
            /* '<S429>:1:7' else */
            /* '<S429>:1:8' u(i) = single(0); */
            LW_ctrl_241029_1_B.y[i] = 0.0F;
          }
        }
      }

      /* End of MATLAB Function: '<S419>/nan_inf_q' */

      /* S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger1' */
      /* '<S429>:1:12' y = u; */
      profileStart_LW_ctrl_241029_1(4U); /* original_line:4138 */{
        //interval val: 0
        bool updated;
        orb_check(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger1_uO.fd,
                  &updated);
        if (updated) {
          /* obtained uorb data */
          /* copy sensors raw data into local buffer */
          orb_copy(ORB_ID(vehicle_angular_velocity),
                   LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger1_uO.fd,
                   &LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger1);
        }
      }profileEnd_LW_ctrl_241029_1(4U); /* original_line:4150 */

      /* MATLAB Function: '<S419>/nan_inf0' */
      /* MATLAB Function 'states_update/vehicle_local_position/HIL&FLY V1.13.3/nan_inf0': '<S427>:1' */
      /* '<S427>:1:3' for i = 1:length(u) */
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.y_e[i] =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger1.xyz[i];

        /* '<S427>:1:4' if isnan(u(i)) || isinf(u(i)) */
        if (rtIsNaNF(LW_ctrl_241029_1_B.y_e[i]) || rtIsInfF
            (LW_ctrl_241029_1_B.y_e[i])) {
          /* '<S427>:1:5' u(i) = single(0); */
          LW_ctrl_241029_1_B.y_e[i] = 0.0F;
        }
      }

      /* End of MATLAB Function: '<S419>/nan_inf0' */

      /* MATLAB Function: '<S419>/Lowpass1' */
      /* '<S427>:1:8' y = u(:); */
      /*  LW_TEST_DT = dt/(dt + Ts) */
      /*  其中dt是采样周期，Ts是低通滤波器的时间常数 */
      /*  截止频率f = 1/Ts/2pi Hz */
      /*  如 dt=0.004, f=30Hz , LW_TEST_DT=0.43 */
      /* MATLAB Function 'states_update/vehicle_local_position/HIL&FLY V1.13.3/Lowpass1': '<S423>:1' */
      /* '<S423>:1:7' if isempty(d_est_last) */
      if (!LW_ctrl_241029_1_DW.d_est_last_not_empty) {
        /* '<S423>:1:8' d_est_last = d_est; */
        LW_ctrl_241029_1_DW.d_est_last[0] = LW_ctrl_241029_1_B.y_e[0];
        LW_ctrl_241029_1_DW.d_est_last[1] = LW_ctrl_241029_1_B.y_e[1];
        LW_ctrl_241029_1_DW.d_est_last[2] = LW_ctrl_241029_1_B.y_e[2];
        LW_ctrl_241029_1_DW.d_est_last_not_empty = true;
      }

      /* '<S423>:1:10' if isInfNan(d_est_last) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'isInfNan:4' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_DW.d_est_last[i]) || rtIsNaNF
            (LW_ctrl_241029_1_DW.d_est_last[i])) {
          /* 'isInfNan:6' y = true; */
          rtb_integral_reset_idx_0 = true;
          exitg1 = true;
        } else {
          /* 'isInfNan:8' else */
          /* 'isInfNan:9' y = false; */
          rtb_integral_reset_idx_0 = false;
          i++;
        }
      }

      if (rtb_integral_reset_idx_0) {
        /* '<S423>:1:11' d_est_last = single([0;0;0]); */
        LW_ctrl_241029_1_DW.d_est_last[0] = 0.0F;
        LW_ctrl_241029_1_DW.d_est_last[1] = 0.0F;
        LW_ctrl_241029_1_DW.d_est_last[2] = 0.0F;
      }

      /* '<S423>:1:13' d_est = d_est_last + LW_TEST_WBDT*(d_est - d_est_last); */
      /* '<S423>:1:14' d_est_last = d_est; */
      LW_ctrl_241029_1_B.Va_ = (LW_ctrl_241029_1_B.y_e[0] -
        LW_ctrl_241029_1_DW.d_est_last[0]) * LW_TEST_WBDT +
        LW_ctrl_241029_1_DW.d_est_last[0];

      /* End of Outputs for SubSystem: '<Root>/states_update' */
      LW_ctrl_241029_1_B.d_est[0] = LW_ctrl_241029_1_B.Va_;

      /* Outputs for Function Call SubSystem: '<Root>/states_update' */
      /* MATLAB Function: '<S419>/Lowpass1' */
      LW_ctrl_241029_1_DW.d_est_last[0] = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.Va_ = (LW_ctrl_241029_1_B.y_e[1] -
        LW_ctrl_241029_1_DW.d_est_last[1]) * LW_TEST_WBDT +
        LW_ctrl_241029_1_DW.d_est_last[1];

      /* End of Outputs for SubSystem: '<Root>/states_update' */
      LW_ctrl_241029_1_B.d_est[1] = LW_ctrl_241029_1_B.Va_;

      /* Outputs for Function Call SubSystem: '<Root>/states_update' */
      /* MATLAB Function: '<S419>/Lowpass1' */
      LW_ctrl_241029_1_DW.d_est_last[1] = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.Va_ = (LW_ctrl_241029_1_B.y_e[2] -
        LW_ctrl_241029_1_DW.d_est_last[2]) * LW_TEST_WBDT +
        LW_ctrl_241029_1_DW.d_est_last[2];

      /* End of Outputs for SubSystem: '<Root>/states_update' */
      LW_ctrl_241029_1_B.d_est[2] = LW_ctrl_241029_1_B.Va_;

      /* Outputs for Function Call SubSystem: '<Root>/states_update' */
      /* MATLAB Function: '<S419>/Lowpass1' */
      LW_ctrl_241029_1_DW.d_est_last[2] = LW_ctrl_241029_1_B.Va_;

      /* S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger7' */
      profileStart_LW_ctrl_241029_1(5U); /* original_line:4247 */{
        //interval val: 0
        bool updated;
        orb_check(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger7_uO.fd,
                  &updated);
        if (updated) {
          /* obtained uorb data */
          /* copy sensors raw data into local buffer */
          orb_copy(ORB_ID(costom_lw_mixer),
                   LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger7_uO.fd,
                   &LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger7);
        }
      }profileEnd_LW_ctrl_241029_1(5U); /* original_line:4259 */

      /* Gain: '<S425>/Gain' incorporates:
       *  Memory: '<S425>/Memory'
       *  Sum: '<S425>/Sum'
       */
      LW_ctrl_241029_1_B.Saturation_d =
        (LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger1.timestamp -
         LW_ctrl_241029_1_DW.Memory_PreviousInput) * 1.0E-6;

      /* Saturate: '<S425>/Saturation' */
      if (LW_ctrl_241029_1_B.Saturation_d > 0.2) {
        LW_ctrl_241029_1_B.Saturation_d = 0.2;
      } else if (LW_ctrl_241029_1_B.Saturation_d < 0.001) {
        LW_ctrl_241029_1_B.Saturation_d = 0.001;
      }

      /* End of Saturate: '<S425>/Saturation' */

      /* MATLAB Function: '<S419>/DisturbanceEstimator' incorporates:
       *  DataTypeConversion: '<S425>/Data Type Conversion'
       */
      LW_ctrl_241029_1_B.IntegralGain = (real32_T)
        LW_ctrl_241029_1_B.Saturation_d;

      /* MATLAB Function 'states_update/vehicle_local_position/HIL&FLY V1.13.3/DisturbanceEstimator': '<S420>:1' */
      /* '<S420>:1:8' if isempty(quat_reset_counter_) */
      if (!LW_ctrl_241029_1_DW.quat_reset_counter__not_empty) {
        /* '<S420>:1:9' quat_reset_counter_ = quat_reset_counter; */
        LW_ctrl_241029_1_DW.quat_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger_d.quat_reset_counter;
        LW_ctrl_241029_1_DW.quat_reset_counter__not_empty = true;
      }

      /* '<S420>:1:12' if isInfNan(qm) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'isInfNan:4' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 4)) {
        /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_B.y[i]) || rtIsNaNF(LW_ctrl_241029_1_B.y[i]))
        {
          /* 'isInfNan:6' y = true; */
          rtb_integral_reset_idx_1 = true;
          exitg1 = true;
        } else {
          /* 'isInfNan:8' else */
          /* 'isInfNan:9' y = false; */
          rtb_integral_reset_idx_1 = false;
          i++;
        }
      }

      if (rtb_integral_reset_idx_1) {
        /* '<S420>:1:13' qm = single([1;0;0;0]); */
        LW_ctrl_241029_1_B.qm[0] = 1.0F;
        LW_ctrl_241029_1_B.qm[1] = 0.0F;
        LW_ctrl_241029_1_B.qm[2] = 0.0F;
        LW_ctrl_241029_1_B.qm[3] = 0.0F;
      } else {
        /* '<S420>:1:14' else */
        /* qm = qm/(sqrt(qm'*qm)); */
        /* qm = quatnormalize(qm'); */
        /* '<S420>:1:17' qm = qm(:); */
        LW_ctrl_241029_1_B.qm[0] = LW_ctrl_241029_1_B.y[0];
        LW_ctrl_241029_1_B.qm[1] = LW_ctrl_241029_1_B.y[1];
        LW_ctrl_241029_1_B.qm[2] = LW_ctrl_241029_1_B.y[2];
        LW_ctrl_241029_1_B.qm[3] = LW_ctrl_241029_1_B.y[3];
      }

      /* '<S420>:1:19' if isInfNan(omegam) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'isInfNan:4' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_B.d_est[i]) || rtIsNaNF
            (LW_ctrl_241029_1_B.d_est[i])) {
          /* 'isInfNan:6' y = true; */
          rEQ0 = true;
          exitg1 = true;
        } else {
          /* 'isInfNan:8' else */
          /* 'isInfNan:9' y = false; */
          rEQ0 = false;
          i++;
        }
      }

      if (rEQ0) {
        /* '<S420>:1:20' omegam = single([0;0;0]); */
        LW_ctrl_241029_1_B.d_est[0] = 0.0F;
        LW_ctrl_241029_1_B.d_est[1] = 0.0F;
        LW_ctrl_241029_1_B.d_est[2] = 0.0F;
      } else {
        /* '<S420>:1:21' else */
        /* '<S420>:1:22' omegam = omegam(:); */
      }

      /* '<S420>:1:24' if isInfNan(T) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'isInfNan:4' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 6)) {
        /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF
            (LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger7.log_m_t_limit[i]) ||
            rtIsNaNF
            (LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger7.log_m_t_limit[i]))
        {
          /* 'isInfNan:6' y = true; */
          rtb_rate_ctrl_integral_reset_id = true;
          exitg1 = true;
        } else {
          /* 'isInfNan:8' else */
          /* 'isInfNan:9' y = false; */
          rtb_rate_ctrl_integral_reset_id = false;
          i++;
        }
      }

      if (rtb_rate_ctrl_integral_reset_id) {
        /* '<S420>:1:25' T = single([0;0;0;0;0;0]); */
        for (i = 0; i < 6; i++) {
          LW_ctrl_241029_1_B.T[i] = 0.0F;
        }
      } else {
        /* '<S420>:1:26' else */
        /* '<S420>:1:27' T = T(:); */
        for (i = 0; i < 6; i++) {
          LW_ctrl_241029_1_B.T[i] =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger7.log_m_t_limit[i];
        }
      }

      /* '<S420>:1:29' if dt < 0.001 */
      if ((real32_T)LW_ctrl_241029_1_B.Saturation_d < 0.001) {
        /* '<S420>:1:30' dt = single(0.001); */
        LW_ctrl_241029_1_B.IntegralGain = 0.001F;
      } else if ((real32_T)LW_ctrl_241029_1_B.Saturation_d > 0.02) {
        /* '<S420>:1:31' elseif dt > 0.02 */
        /* '<S420>:1:32' dt = single(0.02); */
        LW_ctrl_241029_1_B.IntegralGain = 0.02F;
      }

      /* '<S420>:1:35' if isempty(tau_qk) */
      if (!LW_ctrl_241029_1_DW.tau_qk_not_empty) {
        /* '<S420>:1:36' if notInfNan(qm) */
        /* ISINFNAN 此处显示有关此函数的摘要 */
        /*    Data is a vector. */
        /* 'notInfNan:4' y = false; */
        rtb_integral_reset_idx_1 = false;

        /* 'notInfNan:5' for ii = 1:length(data) */
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i < 4)) {
          /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
          if (rtIsInfF(LW_ctrl_241029_1_B.qm[i]) || rtIsNaNF
              (LW_ctrl_241029_1_B.qm[i])) {
            /* 'notInfNan:7' y = false; */
            rtb_integral_reset_idx_1 = false;
            exitg1 = true;
          } else {
            /* 'notInfNan:9' else */
            /* 'notInfNan:10' y = true; */
            rtb_integral_reset_idx_1 = true;
            i++;
          }
        }

        if (rtb_integral_reset_idx_1) {
          /* '<S420>:1:37' tau_qk = qm; */
          LW_ctrl_241029_1_DW.tau_qk[0] = LW_ctrl_241029_1_B.qm[0];
          LW_ctrl_241029_1_DW.tau_qk[1] = LW_ctrl_241029_1_B.qm[1];
          LW_ctrl_241029_1_DW.tau_qk[2] = LW_ctrl_241029_1_B.qm[2];
          LW_ctrl_241029_1_DW.tau_qk[3] = LW_ctrl_241029_1_B.qm[3];
          LW_ctrl_241029_1_DW.tau_qk_not_empty = true;
        } else {
          /* '<S420>:1:38' else */
          /* '<S420>:1:39' tau_qk = single([1;0;0;0]); */
          LW_ctrl_241029_1_DW.tau_qk[0] = 1.0F;
          LW_ctrl_241029_1_DW.tau_qk[1] = 0.0F;
          LW_ctrl_241029_1_DW.tau_qk[2] = 0.0F;
          LW_ctrl_241029_1_DW.tau_qk[3] = 0.0F;
          LW_ctrl_241029_1_DW.tau_qk_not_empty = true;
        }
      }

      /* '<S420>:1:42' if isInfNan(tau_qk) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'isInfNan:4' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 4)) {
        /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_DW.tau_qk[i]) || rtIsNaNF
            (LW_ctrl_241029_1_DW.tau_qk[i])) {
          /* 'isInfNan:6' y = true; */
          f_y = true;
          exitg1 = true;
        } else {
          /* 'isInfNan:8' else */
          /* 'isInfNan:9' y = false; */
          f_y = false;
          i++;
        }
      }

      if (f_y) {
        /* '<S420>:1:43' if notInfNan(qm) */
        /* ISINFNAN 此处显示有关此函数的摘要 */
        /*    Data is a vector. */
        /* 'notInfNan:4' y = false; */
        rtb_integral_reset_idx_1 = false;

        /* 'notInfNan:5' for ii = 1:length(data) */
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i < 4)) {
          /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
          if (rtIsInfF(LW_ctrl_241029_1_B.qm[i]) || rtIsNaNF
              (LW_ctrl_241029_1_B.qm[i])) {
            /* 'notInfNan:7' y = false; */
            rtb_integral_reset_idx_1 = false;
            exitg1 = true;
          } else {
            /* 'notInfNan:9' else */
            /* 'notInfNan:10' y = true; */
            rtb_integral_reset_idx_1 = true;
            i++;
          }
        }

        if (rtb_integral_reset_idx_1) {
          /* '<S420>:1:44' tau_qk = qm; */
          LW_ctrl_241029_1_DW.tau_qk[0] = LW_ctrl_241029_1_B.qm[0];
          LW_ctrl_241029_1_DW.tau_qk[1] = LW_ctrl_241029_1_B.qm[1];
          LW_ctrl_241029_1_DW.tau_qk[2] = LW_ctrl_241029_1_B.qm[2];
          LW_ctrl_241029_1_DW.tau_qk[3] = LW_ctrl_241029_1_B.qm[3];
        } else {
          /* '<S420>:1:45' else */
          /* '<S420>:1:46' tau_qk = single([1;0;0;0]); */
          LW_ctrl_241029_1_DW.tau_qk[0] = 1.0F;
          LW_ctrl_241029_1_DW.tau_qk[1] = 0.0F;
          LW_ctrl_241029_1_DW.tau_qk[2] = 0.0F;
          LW_ctrl_241029_1_DW.tau_qk[3] = 0.0F;
        }
      }

      /* '<S420>:1:49' if isempty(tau_omegak) */
      if (!LW_ctrl_241029_1_DW.tau_omegak_not_empty) {
        /* '<S420>:1:50' if notInfNan(omegam) */
        /* ISINFNAN 此处显示有关此函数的摘要 */
        /*    Data is a vector. */
        /* 'notInfNan:4' y = false; */
        rtb_integral_reset_idx_1 = false;

        /* 'notInfNan:5' for ii = 1:length(data) */
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i < 3)) {
          /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
          if (rtIsInfF(LW_ctrl_241029_1_B.d_est[i]) || rtIsNaNF
              (LW_ctrl_241029_1_B.d_est[i])) {
            /* 'notInfNan:7' y = false; */
            rtb_integral_reset_idx_1 = false;
            exitg1 = true;
          } else {
            /* 'notInfNan:9' else */
            /* 'notInfNan:10' y = true; */
            rtb_integral_reset_idx_1 = true;
            i++;
          }
        }

        if (rtb_integral_reset_idx_1) {
          /* '<S420>:1:51' tau_omegak = omegam; */
          LW_ctrl_241029_1_DW.tau_omegak[0] = LW_ctrl_241029_1_B.d_est[0];
          LW_ctrl_241029_1_DW.tau_omegak[1] = LW_ctrl_241029_1_B.d_est[1];
          LW_ctrl_241029_1_DW.tau_omegak[2] = LW_ctrl_241029_1_B.d_est[2];
          LW_ctrl_241029_1_DW.tau_omegak_not_empty = true;
        } else {
          /* '<S420>:1:52' else */
          /* '<S420>:1:53' tau_omegak = single([0;0;0]); */
          LW_ctrl_241029_1_DW.tau_omegak[0] = 0.0F;
          LW_ctrl_241029_1_DW.tau_omegak[1] = 0.0F;
          LW_ctrl_241029_1_DW.tau_omegak[2] = 0.0F;
          LW_ctrl_241029_1_DW.tau_omegak_not_empty = true;
        }
      }

      /* '<S420>:1:56' if isInfNan(tau_omegak) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'isInfNan:4' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_DW.tau_omegak[i]) || rtIsNaNF
            (LW_ctrl_241029_1_DW.tau_omegak[i])) {
          /* 'isInfNan:6' y = true; */
          want_hold_z = true;
          exitg1 = true;
        } else {
          /* 'isInfNan:8' else */
          /* 'isInfNan:9' y = false; */
          want_hold_z = false;
          i++;
        }
      }

      if (want_hold_z) {
        /* '<S420>:1:57' if notInfNan(omegam) */
        /* ISINFNAN 此处显示有关此函数的摘要 */
        /*    Data is a vector. */
        /* 'notInfNan:4' y = false; */
        want_hold_z = false;

        /* 'notInfNan:5' for ii = 1:length(data) */
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i < 3)) {
          /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
          if (rtIsInfF(LW_ctrl_241029_1_B.d_est[i]) || rtIsNaNF
              (LW_ctrl_241029_1_B.d_est[i])) {
            /* 'notInfNan:7' y = false; */
            want_hold_z = false;
            exitg1 = true;
          } else {
            /* 'notInfNan:9' else */
            /* 'notInfNan:10' y = true; */
            want_hold_z = true;
            i++;
          }
        }

        if (want_hold_z) {
          /* '<S420>:1:58' tau_omegak = omegam; */
          LW_ctrl_241029_1_DW.tau_omegak[0] = LW_ctrl_241029_1_B.d_est[0];
          LW_ctrl_241029_1_DW.tau_omegak[1] = LW_ctrl_241029_1_B.d_est[1];
          LW_ctrl_241029_1_DW.tau_omegak[2] = LW_ctrl_241029_1_B.d_est[2];
        } else {
          /* '<S420>:1:59' else */
          /* '<S420>:1:60' tau_omegak = single([0;0;0]); */
          LW_ctrl_241029_1_DW.tau_omegak[0] = 0.0F;
          LW_ctrl_241029_1_DW.tau_omegak[1] = 0.0F;
          LW_ctrl_241029_1_DW.tau_omegak[2] = 0.0F;
        }
      }

      /* '<S420>:1:63' if isempty(tau_z3) */
      /* '<S420>:1:66' if isInfNan(tau_z3) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'isInfNan:4' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_DW.tau_z3[i]) || rtIsNaNF
            (LW_ctrl_241029_1_DW.tau_z3[i])) {
          /* 'isInfNan:6' y = true; */
          want_hold_xy = true;
          exitg1 = true;
        } else {
          /* 'isInfNan:8' else */
          /* 'isInfNan:9' y = false; */
          want_hold_xy = false;
          i++;
        }
      }

      if (want_hold_xy) {
        /* '<S420>:1:67' tau_z3 = single([0;0;0]); */
        LW_ctrl_241029_1_DW.tau_z3[0] = 0.0F;
        LW_ctrl_241029_1_DW.tau_z3[1] = 0.0F;
        LW_ctrl_241029_1_DW.tau_z3[2] = 0.0F;
      }

      /* 结构参数 */
      /* '<S420>:1:73' rotorEta = single(ModelParam_rotorEta); */
      /* '<S420>:1:74' rotordx = single(ModelParam_rotordx); */
      /* '<S420>:1:75' rotordy = single(ModelParam_rotordy); */
      /* '<S420>:1:76' LBb = single(ModelParam_LBb); */
      /* '<S420>:1:77' LBc = single(ModelParam_LBc); */
      /* '<S420>:1:78' LBS = single(ModelParam_LBS); */
      /* '<S420>:1:79' kappa = single(LW_ANGLE*pi/180); */
      LW_ctrl_241029_1_B.kappa = LW_ANGLE * 3.14159274F / 180.0F;

      /* Sqrt: '<S419>/Sqrt' incorporates:
       *  DotProduct: '<S419>/Dot Product'
       *  SignalConversion generated from: '<S419>/Dot Product'
       */
      /* '<S420>:1:80' Rho = single(ModelParam_LBRho); */
      /* 动力系统参数 */
      /* '<S420>:1:82' rotorCm = single(ModelParam_rotorCm); */
      /* '<S420>:1:83' rotorCt = single(ModelParam_rotorCt); */
      /* '<S420>:1:84' km_f = rotorCm/rotorCt; */
      /* '<S420>:1:85' Cl_d = single(LW_LBCL_D); */
      /* '<S420>:1:86' Cm_d = single(LW_LBCM_D); */
      /* '<S420>:1:87' Cn_d = single(ModelParam_LBCn_d); */
      /*  */
      /* '<S420>:1:89' Va_ = max(Va,0.1); */
      profileStart_LW_ctrl_241029_1(6U); /* original_line:4671 */LW_ctrl_241029_1_B.Va_ = (real32_T)sqrt
        ((LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vx *
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vx +
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vy *
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vy) +
         LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vz *
         LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vz);profileEnd_LW_ctrl_241029_1(6U); /* original_line:4677 */

      /* MATLAB Function: '<S419>/DisturbanceEstimator' */
      if (!(LW_ctrl_241029_1_B.Va_ >= 0.1F)) {
        LW_ctrl_241029_1_B.Va_ = 0.1F;
      }

      /* '<S420>:1:90' if LW_USE_SER > 0.5 */
      if (LW_USE_SER > 0.5F) {
        /* '<S420>:1:91' Q = 0.5*Rho*Va_^2*LBS; */
        LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.Va_ * LW_ctrl_241029_1_B.Va_
          * 0.61F * 0.155F;
      } else {
        /* '<S420>:1:92' else */
        /* '<S420>:1:93' Q = single(0); */
        LW_ctrl_241029_1_B.Va_ = 0.0F;
      }

      /* 滤波器参数 */
      /* '<S420>:1:96' L = eye(3,2,"single"); */
      /* '<S420>:1:97' wn = [LW_TEST_WNXY;LW_TEST_WNXY;LW_TEST_WNZ]; */
      /* rad/s */
      /* '<S420>:1:98' sigma = [LW_TEST_SIGXY;LW_TEST_SIGXY;LW_TEST_SIGZ]; */
      /* '<S420>:1:99' L(:,1) = wn.^2; */
      /* '<S420>:1:100' L(:,2) = 2*sigma.*wn; */
      /* '<S420>:1:101' lamda = single([LW_TEST_LAMXY;LW_TEST_LAMXY;LW_TEST_LAMZ]); */
      /* 滤波器结构 */
      /* reset处理 */
      /* '<S420>:1:104' if quat_reset_counter_ ~= quat_reset_counter */
      if (LW_ctrl_241029_1_DW.quat_reset_counter_ !=
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger_d.quat_reset_counter) {
        /* '<S420>:1:105' tau_q = quatmultiply(delta_q_reset(:)',tau_qk'); */
        /* '<S420>:1:106' tau_qk = tau_q'; */
        for (i = 0; i < 4; i++) {
          LW_ctrl_241029_1_B.q_err[i] = LW_ctrl_241029_1_DW.tau_qk[i];
        }

        profileStart_LW_ctrl_241029_1(7U); /* original_line:4714 */LW_ctrl_241029_1_quatmultiply
          (LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger_d.delta_q_reset,
           LW_ctrl_241029_1_B.q_err, LW_ctrl_241029_1_DW.tau_qk);profileEnd_LW_ctrl_241029_1(7U); /* original_line:4716 */

        /* '<S420>:1:107' quat_reset_counter_ = quat_reset_counter; */
        LW_ctrl_241029_1_DW.quat_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger_d.quat_reset_counter;
      }

      /* '<S420>:1:109' q_err = quatmultiply(quatconj(tau_qk'), qm'); */
      LW_ctrl_241029_1_B.qk_[0] = LW_ctrl_241029_1_DW.tau_qk[0];
      LW_ctrl_241029_1_B.qk_[1] = -LW_ctrl_241029_1_DW.tau_qk[1];
      LW_ctrl_241029_1_B.qk_[2] = -LW_ctrl_241029_1_DW.tau_qk[2];
      LW_ctrl_241029_1_B.qk_[3] = -LW_ctrl_241029_1_DW.tau_qk[3];

      /* '<S420>:1:110' q_err = quatnormalize(q_err); */
      profileStart_LW_ctrl_241029_1(8U); /* original_line:4730 */LW_ctrl_241029_1_quatmultiply(LW_ctrl_241029_1_B.qk_,
        LW_ctrl_241029_1_B.qm, LW_ctrl_241029_1_B.q_err);profileEnd_LW_ctrl_241029_1(8U); /* original_line:4731 */
      profileStart_LW_ctrl_241029_1(9U); /* original_line:4732 */LW_ctrl_241029_1_quatnormalize(LW_ctrl_241029_1_B.q_err);profileEnd_LW_ctrl_241029_1(9U); /* original_line:4732 */

      /* '<S420>:1:111' eta = constrain(q_err(1), single(-1), single(1)); */
      /* CONSTRAIN 此处显示有关此函数的摘要 */
      /*    此处显示详细说明 */
      /*  min  = single(min); */
      /*  max = single(max); */
      /* 'constrain:6' if x > max */
      if (LW_ctrl_241029_1_B.q_err[0] > 1.0F) {
        /* 'constrain:7' y = max; */
        LW_ctrl_241029_1_B.eta_p = 1.0F;
      } else if (LW_ctrl_241029_1_B.q_err[0] < -1.0F) {
        /* 'constrain:8' elseif x < min */
        /* 'constrain:9' y = min; */
        LW_ctrl_241029_1_B.eta_p = -1.0F;
      } else {
        /* 'constrain:10' else */
        /* 'constrain:11' y = x; */
        LW_ctrl_241029_1_B.eta_p = LW_ctrl_241029_1_B.q_err[0];
      }

      /* '<S420>:1:112' epsilon = q_err(2 : 4); */
      /* '<S420>:1:113' theta = 2 * acos(eta); */
      /* '<S420>:1:114' theta = wrap_pi(theta); */
      profileStart_LW_ctrl_241029_1(10U); /* original_line:4756 */LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_wrap_pi(2.0F * (real32_T)acos
        (LW_ctrl_241029_1_B.eta_p));profileEnd_LW_ctrl_241029_1(10U); /* original_line:4757 */

      /* '<S420>:1:115' if abs(theta) < 0.0873 */
      if ((real32_T)fabs(LW_ctrl_241029_1_B.theta) < 0.0873) {
        /*  5*pi/180 */
        /* '<S420>:1:116' Xi_e = sign(eta) * 2 * epsilon; */
        if (rtIsNaNF(LW_ctrl_241029_1_B.eta_p)) {
          rtb_FilterCoefficient_jy_tmp = (rtNaNF);
        } else if (LW_ctrl_241029_1_B.eta_p < 0.0F) {
          rtb_FilterCoefficient_jy_tmp = -1.0F;
        } else {
          rtb_FilterCoefficient_jy_tmp = (real32_T)(LW_ctrl_241029_1_B.eta_p >
            0.0F);
        }

        LW_ctrl_241029_1_B.eta_p = rtb_FilterCoefficient_jy_tmp * 2.0F;
        LW_ctrl_241029_1_B.Xi_e[0] = LW_ctrl_241029_1_B.eta_p *
          LW_ctrl_241029_1_B.q_err[1];
        LW_ctrl_241029_1_B.Xi_e[1] = LW_ctrl_241029_1_B.eta_p *
          LW_ctrl_241029_1_B.q_err[2];
        LW_ctrl_241029_1_B.Xi_e[2] = LW_ctrl_241029_1_B.eta_p *
          LW_ctrl_241029_1_B.q_err[3];
      } else {
        /* '<S420>:1:117' else */
        /* '<S420>:1:118' Xi_e = sign(eta) / sin(theta / 2) * theta * epsilon; */
        if (rtIsNaNF(LW_ctrl_241029_1_B.eta_p)) {
          rtb_FilterCoefficient_jy_tmp = (rtNaNF);
        } else if (LW_ctrl_241029_1_B.eta_p < 0.0F) {
          rtb_FilterCoefficient_jy_tmp = -1.0F;
        } else {
          rtb_FilterCoefficient_jy_tmp = (real32_T)(LW_ctrl_241029_1_B.eta_p >
            0.0F);
        }

        profileStart_LW_ctrl_241029_1(11U); /* original_line:4791 */LW_ctrl_241029_1_B.aSinInput = rtb_FilterCoefficient_jy_tmp / (real32_T)
          sin(LW_ctrl_241029_1_B.theta / 2.0F) * LW_ctrl_241029_1_B.theta;profileEnd_LW_ctrl_241029_1(11U); /* original_line:4792 */
        LW_ctrl_241029_1_B.Xi_e[0] = LW_ctrl_241029_1_B.aSinInput *
          LW_ctrl_241029_1_B.q_err[1];
        LW_ctrl_241029_1_B.Xi_e[1] = LW_ctrl_241029_1_B.aSinInput *
          LW_ctrl_241029_1_B.q_err[2];
        LW_ctrl_241029_1_B.Xi_e[2] = LW_ctrl_241029_1_B.aSinInput *
          LW_ctrl_241029_1_B.q_err[3];
      }

      /* '<S420>:1:120' e_q = Xi_e(:); */
      /* '<S420>:1:121' e_omega = omegam - tau_omegak; */
      /* inv_uavJ = eye(3,3)/ModelParam_uavJ; */
      /* '<S420>:1:124' inv_uavJ = eye(3); */
      profileStart_LW_ctrl_241029_1(12U); /* original_line:4805 */LW_ctrl_241029_1_eye(LW_ctrl_241029_1_B.inv_uavJ);profileEnd_LW_ctrl_241029_1(12U); /* original_line:4805 */

      /* '<S420>:1:125' for ii = 1:3 */
      /* le = l1*eq+l2*ew */
      /* '<S420>:1:129' Le = L(:,1).*e_q + L(:,2).*e_omega; */
      /* '<S420>:1:126' inv_uavJ(ii,ii) = 1/(ModelParam_uavJ(ii,ii)); */
      LW_ctrl_241029_1_B.inv_uavJ[0] = 19.53125;
      LW_ctrl_241029_1_B.km_f_b = 2.0F * LW_TEST_SIGXY * LW_TEST_WNXY;
      LW_ctrl_241029_1_B.time_to_stop = LW_TEST_WNXY * LW_TEST_WNXY;
      LW_ctrl_241029_1_B.Xi_e[0] = (LW_ctrl_241029_1_B.d_est[0] -
        LW_ctrl_241029_1_DW.tau_omegak[0]) * LW_ctrl_241029_1_B.km_f_b +
        LW_ctrl_241029_1_B.time_to_stop * LW_ctrl_241029_1_B.Xi_e[0];

      /* '<S420>:1:126' inv_uavJ(ii,ii) = 1/(ModelParam_uavJ(ii,ii)); */
      LW_ctrl_241029_1_B.inv_uavJ[4] = 18.050541516245488;
      LW_ctrl_241029_1_B.Xi_e[1] = (LW_ctrl_241029_1_B.d_est[1] -
        LW_ctrl_241029_1_DW.tau_omegak[1]) * LW_ctrl_241029_1_B.km_f_b +
        LW_ctrl_241029_1_B.time_to_stop * LW_ctrl_241029_1_B.Xi_e[1];

      /* '<S420>:1:126' inv_uavJ(ii,ii) = 1/(ModelParam_uavJ(ii,ii)); */
      LW_ctrl_241029_1_B.inv_uavJ[8] = 13.157894736842106;
      LW_ctrl_241029_1_B.Xi_e[2] = 2.0F * LW_TEST_SIGZ * LW_TEST_WNZ *
        (LW_ctrl_241029_1_B.d_est[2] - LW_ctrl_241029_1_DW.tau_omegak[2]) +
        LW_TEST_WNZ * LW_TEST_WNZ * LW_ctrl_241029_1_B.Xi_e[2];

      /* '<S420>:1:130' K1 = km_f; */
      /* '<S420>:1:131' coseta = cos(rotorEta); */
      /* '<S420>:1:132' K2 = rotordy*coseta; */
      /* '<S420>:1:133' dxcoseta = rotordx*coseta; */
      /* 估计螺旋桨推力，根据混控器输出滤波得到 */
      /* '<S420>:1:135' T = LowPass(T, LW_TEST_TDT); */
      profileStart_LW_ctrl_241029_1(13U); /* original_line:4836 */LW_ctrl_241029_1_LowPass(LW_ctrl_241029_1_B.T, LW_TEST_TDT);profileEnd_LW_ctrl_241029_1(13U); /* original_line:4836 */

      /* '<S420>:1:136' B = [-K2       -K2        K2       K2      -Q*LBb*Cl_d*cos(kappa) Q*LBb*Cl_d*cos(kappa); */
      /* '<S420>:1:137'      dxcoseta  -dxcoseta dxcoseta -dxcoseta Q*LBc*Cm_d Q*LBc*Cm_d; */
      /* '<S420>:1:138'      K1        -K1       -K1      K1      Q*LBb*Cl_d*sin(kappa) -Q*LBb*Cl_d*sin(kappa)]; */
      /* '<S420>:1:139' z3_ = tau_z3 + lamda.*Le*dt; */
      LW_ctrl_241029_1_B.z3_[0] = LW_TEST_LAMXY * LW_ctrl_241029_1_B.Xi_e[0] *
        LW_ctrl_241029_1_B.IntegralGain + LW_ctrl_241029_1_DW.tau_z3[0];
      LW_ctrl_241029_1_B.z3_[1] = LW_TEST_LAMXY * LW_ctrl_241029_1_B.Xi_e[1] *
        LW_ctrl_241029_1_B.IntegralGain + LW_ctrl_241029_1_DW.tau_z3[1];
      LW_ctrl_241029_1_B.z3_[2] = LW_TEST_LAMZ * LW_ctrl_241029_1_B.Xi_e[2] *
        LW_ctrl_241029_1_B.IntegralGain + LW_ctrl_241029_1_DW.tau_z3[2];

      /* '<S420>:1:140' if LW_USE_SER > 0.5 */
      if (LW_USE_SER > 0.5F) {
        /* '<S420>:1:141' Fr = B*T; */
        profileStart_LW_ctrl_241029_1(16U); /* original_line:4852 */LW_ctrl_241029_1_B.time_to_stop = (real32_T)cos(LW_ctrl_241029_1_B.kappa);profileEnd_LW_ctrl_241029_1(16U); /* original_line:4852 */
        profileStart_LW_ctrl_241029_1(17U); /* original_line:4853 */LW_ctrl_241029_1_B.kappa = (real32_T)sin(LW_ctrl_241029_1_B.kappa);profileEnd_LW_ctrl_241029_1(17U); /* original_line:4853 */
        LW_ctrl_241029_1_B.eta[0] = -0.2125F;
        LW_ctrl_241029_1_B.eta[3] = -0.2125F;
        LW_ctrl_241029_1_B.eta[6] = 0.2125F;
        LW_ctrl_241029_1_B.eta[9] = 0.2125F;
        LW_ctrl_241029_1_B.km_f_b = -LW_ctrl_241029_1_B.Va_ * 0.94F;
        LW_ctrl_241029_1_B.eta[12] = LW_ctrl_241029_1_B.km_f_b * LW_LBCL_D *
          LW_ctrl_241029_1_B.time_to_stop;
        LW_ctrl_241029_1_B.eta_p = LW_ctrl_241029_1_B.Va_ * 0.94F * LW_LBCL_D;
        LW_ctrl_241029_1_B.eta[15] = LW_ctrl_241029_1_B.eta_p *
          LW_ctrl_241029_1_B.time_to_stop;
        LW_ctrl_241029_1_B.eta[1] = 0.25F;
        LW_ctrl_241029_1_B.eta[4] = -0.25F;
        LW_ctrl_241029_1_B.eta[7] = 0.25F;
        LW_ctrl_241029_1_B.eta[10] = -0.25F;
        LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.Va_ * 0.17F * LW_LBCM_D;
        LW_ctrl_241029_1_B.eta[13] = LW_ctrl_241029_1_B.Va_;
        LW_ctrl_241029_1_B.eta[16] = LW_ctrl_241029_1_B.Va_;
        LW_ctrl_241029_1_B.eta[2] = 0.0234918036F;
        LW_ctrl_241029_1_B.eta[5] = -0.0234918036F;
        LW_ctrl_241029_1_B.eta[8] = -0.0234918036F;
        LW_ctrl_241029_1_B.eta[11] = 0.0234918036F;
        LW_ctrl_241029_1_B.eta[14] = LW_ctrl_241029_1_B.eta_p *
          LW_ctrl_241029_1_B.kappa;
        LW_ctrl_241029_1_B.eta[17] = LW_ctrl_241029_1_B.km_f_b * LW_LBCL_D *
          LW_ctrl_241029_1_B.kappa;
        for (i = 0; i < 3; i++) {
          LW_ctrl_241029_1_B.Integrator_a = 0.0F;
          for (trueCount = 0; trueCount < 6; trueCount++) {
            LW_ctrl_241029_1_B.Integrator_a += LW_ctrl_241029_1_B.eta[3 *
              trueCount + i] * LW_ctrl_241029_1_B.T[trueCount];
          }

          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[i] =
            LW_ctrl_241029_1_B.Integrator_a;
        }
      } else {
        /* '<S420>:1:142' else */
        /* '<S420>:1:143' Fr = B(:,1:4)*T(1:4); */
        profileStart_LW_ctrl_241029_1(14U); /* original_line:4892 */LW_ctrl_241029_1_B.time_to_stop = (real32_T)cos(LW_ctrl_241029_1_B.kappa);profileEnd_LW_ctrl_241029_1(14U); /* original_line:4892 */
        profileStart_LW_ctrl_241029_1(15U); /* original_line:4893 */LW_ctrl_241029_1_B.kappa = (real32_T)sin(LW_ctrl_241029_1_B.kappa);profileEnd_LW_ctrl_241029_1(15U); /* original_line:4893 */
        LW_ctrl_241029_1_B.eta[0] = -0.2125F;
        LW_ctrl_241029_1_B.eta[3] = -0.2125F;
        LW_ctrl_241029_1_B.eta[6] = 0.2125F;
        LW_ctrl_241029_1_B.eta[9] = 0.2125F;
        LW_ctrl_241029_1_B.km_f_b = -LW_ctrl_241029_1_B.Va_ * 0.94F;
        LW_ctrl_241029_1_B.eta[12] = LW_ctrl_241029_1_B.km_f_b * LW_LBCL_D *
          LW_ctrl_241029_1_B.time_to_stop;
        LW_ctrl_241029_1_B.eta[15] = LW_ctrl_241029_1_B.Va_ * 0.94F * LW_LBCL_D *
          LW_ctrl_241029_1_B.time_to_stop;
        LW_ctrl_241029_1_B.eta[1] = 0.25F;
        LW_ctrl_241029_1_B.eta[4] = -0.25F;
        LW_ctrl_241029_1_B.eta[7] = 0.25F;
        LW_ctrl_241029_1_B.eta[10] = -0.25F;
        LW_ctrl_241029_1_B.eta_p = LW_ctrl_241029_1_B.Va_ * 0.17F * LW_LBCM_D;
        LW_ctrl_241029_1_B.eta[13] = LW_ctrl_241029_1_B.eta_p;
        LW_ctrl_241029_1_B.eta[16] = LW_ctrl_241029_1_B.eta_p;
        LW_ctrl_241029_1_B.eta[2] = 0.0234918036F;
        LW_ctrl_241029_1_B.eta[5] = -0.0234918036F;
        LW_ctrl_241029_1_B.eta[8] = -0.0234918036F;
        LW_ctrl_241029_1_B.eta[11] = 0.0234918036F;
        LW_ctrl_241029_1_B.eta[14] = LW_ctrl_241029_1_B.Va_ * 0.94F * LW_LBCL_D *
          LW_ctrl_241029_1_B.kappa;
        LW_ctrl_241029_1_B.eta[17] = LW_ctrl_241029_1_B.km_f_b * LW_LBCL_D *
          LW_ctrl_241029_1_B.kappa;
        LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.T[1];
        LW_ctrl_241029_1_B.km_f_b = LW_ctrl_241029_1_B.T[0];
        LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.T[2];
        LW_ctrl_241029_1_B.kappa = LW_ctrl_241029_1_B.T[3];
        for (i = 0; i < 3; i++) {
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[i] =
            ((LW_ctrl_241029_1_B.eta[i + 3] * LW_ctrl_241029_1_B.Va_ +
              LW_ctrl_241029_1_B.eta[i] * LW_ctrl_241029_1_B.km_f_b) +
             LW_ctrl_241029_1_B.eta[i + 6] * LW_ctrl_241029_1_B.aSinInput) +
            LW_ctrl_241029_1_B.eta[i + 9] * LW_ctrl_241029_1_B.kappa;
        }
      }

      /* '<S420>:1:146' omegak_ = tau_omegak +(Le + z3_ + inv_uavJ*Fr- inv_uavJ*(cross(omegam,ModelParam_uavJ*omegam)))*dt; */
      LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.d_est[1];
      LW_ctrl_241029_1_B.km_f_b = LW_ctrl_241029_1_B.d_est[0];
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.d_est[2];
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.Xi_e[i] += LW_ctrl_241029_1_B.z3_[i];
        LW_ctrl_241029_1_B.vel_ref_c[i] = ((real32_T)
          LW_ctrl_241029_1_ConstP.pooled1[i + 3] * LW_ctrl_241029_1_B.Va_ +
          (real32_T)LW_ctrl_241029_1_ConstP.pooled1[i] *
          LW_ctrl_241029_1_B.km_f_b) + (real32_T)
          LW_ctrl_241029_1_ConstP.pooled1[i + 6] * LW_ctrl_241029_1_B.aSinInput;
      }

      profileStart_LW_ctrl_241029_1(18U); /* original_line:4944 */LW_ctrl_241029_1_cross(LW_ctrl_241029_1_B.d_est,
        LW_ctrl_241029_1_B.vel_ref_c, LW_ctrl_241029_1_B.vd_psi);profileEnd_LW_ctrl_241029_1(18U); /* original_line:4945 */
      LW_ctrl_241029_1_B.Integrator_a =
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];
      LW_ctrl_241029_1_B.aSinInput =
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];
      LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2];
      rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.vd_psi[0];
      LW_ctrl_241029_1_B.T1 = LW_ctrl_241029_1_B.vd_psi[1];
      LW_ctrl_241029_1_B.T2 = LW_ctrl_241029_1_B.vd_psi[2];
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.Saturation_d = LW_ctrl_241029_1_B.inv_uavJ[i];
        LW_ctrl_241029_1_B.T3 = (real32_T)LW_ctrl_241029_1_B.Saturation_d *
          LW_ctrl_241029_1_B.Integrator_a;
        LW_ctrl_241029_1_B.km_f_b = (real32_T)LW_ctrl_241029_1_B.Saturation_d *
          rtb_FilterCoefficient_jy_tmp;
        LW_ctrl_241029_1_B.Saturation_d = LW_ctrl_241029_1_B.inv_uavJ[i + 3];
        LW_ctrl_241029_1_B.T3 += (real32_T)LW_ctrl_241029_1_B.Saturation_d *
          LW_ctrl_241029_1_B.aSinInput;
        LW_ctrl_241029_1_B.km_f_b += (real32_T)LW_ctrl_241029_1_B.Saturation_d *
          LW_ctrl_241029_1_B.T1;
        LW_ctrl_241029_1_B.Saturation_d = LW_ctrl_241029_1_B.inv_uavJ[i + 6];
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[i] = ((((real32_T)
          LW_ctrl_241029_1_B.Saturation_d * LW_ctrl_241029_1_B.Va_ +
          LW_ctrl_241029_1_B.T3) + LW_ctrl_241029_1_B.Xi_e[i]) - ((real32_T)
          LW_ctrl_241029_1_B.Saturation_d * LW_ctrl_241029_1_B.T2 +
          LW_ctrl_241029_1_B.km_f_b)) * LW_ctrl_241029_1_B.IntegralGain +
          LW_ctrl_241029_1_DW.tau_omegak[i];
      }

      /* '<S420>:1:147' delta_theta = [0 -omegak_(1) -omegak_(2) -omegak_(3); */
      /* '<S420>:1:148'                omegak_(1) 0 omegak_(3) -omegak_(2); */
      /* '<S420>:1:149'                omegak_(2) -omegak_(3) 0 omegak_(1); */
      /* '<S420>:1:150'                omegak_(3) omegak_(2) -omegak_(1) 0]*dt; */
      /* '<S420>:1:151' qk_ = (eye(4) + delta_theta/2)*tau_qk; */
      profileStart_LW_ctrl_241029_1(19U); /* original_line:4979 */LW_ctrl_241029_1_eye_b(LW_ctrl_241029_1_B.d_tmp);profileEnd_LW_ctrl_241029_1(19U); /* original_line:4979 */
      LW_ctrl_241029_1_B.Va_ = 0.0F * LW_ctrl_241029_1_B.IntegralGain / 2.0F;
      LW_ctrl_241029_1_B.d_tmp_m[0] = LW_ctrl_241029_1_B.Va_ + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[0];
      LW_ctrl_241029_1_B.km_f_b =
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] *
        LW_ctrl_241029_1_B.IntegralGain / 2.0F;
      LW_ctrl_241029_1_B.d_tmp_m[1] = LW_ctrl_241029_1_B.km_f_b + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[1];
      LW_ctrl_241029_1_B.aSinInput =
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] *
        LW_ctrl_241029_1_B.IntegralGain / 2.0F;
      LW_ctrl_241029_1_B.d_tmp_m[2] = LW_ctrl_241029_1_B.aSinInput + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[2];
      LW_ctrl_241029_1_B.kappa = LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro
        [2] * LW_ctrl_241029_1_B.IntegralGain / 2.0F;
      LW_ctrl_241029_1_B.d_tmp_m[3] = LW_ctrl_241029_1_B.kappa + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[3];
      LW_ctrl_241029_1_B.theta =
        -LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] *
        LW_ctrl_241029_1_B.IntegralGain / 2.0F;
      LW_ctrl_241029_1_B.d_tmp_m[4] = LW_ctrl_241029_1_B.theta + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[4];
      LW_ctrl_241029_1_B.d_tmp_m[5] = LW_ctrl_241029_1_B.Va_ + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[5];
      LW_ctrl_241029_1_B.time_to_stop =
        -LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2] *
        LW_ctrl_241029_1_B.IntegralGain / 2.0F;
      LW_ctrl_241029_1_B.d_tmp_m[6] = LW_ctrl_241029_1_B.time_to_stop +
        (real32_T)LW_ctrl_241029_1_B.d_tmp[6];
      LW_ctrl_241029_1_B.d_tmp_m[7] = LW_ctrl_241029_1_B.aSinInput + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[7];
      LW_ctrl_241029_1_B.aSinInput =
        -LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] *
        LW_ctrl_241029_1_B.IntegralGain / 2.0F;
      LW_ctrl_241029_1_B.d_tmp_m[8] = LW_ctrl_241029_1_B.aSinInput + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[8];
      LW_ctrl_241029_1_B.d_tmp_m[9] = LW_ctrl_241029_1_B.kappa + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[9];
      LW_ctrl_241029_1_B.d_tmp_m[10] = LW_ctrl_241029_1_B.Va_ + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[10];
      LW_ctrl_241029_1_B.d_tmp_m[11] = LW_ctrl_241029_1_B.theta + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[11];
      LW_ctrl_241029_1_B.d_tmp_m[12] = LW_ctrl_241029_1_B.time_to_stop +
        (real32_T)LW_ctrl_241029_1_B.d_tmp[12];
      LW_ctrl_241029_1_B.d_tmp_m[13] = LW_ctrl_241029_1_B.aSinInput + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[13];
      LW_ctrl_241029_1_B.d_tmp_m[14] = LW_ctrl_241029_1_B.km_f_b + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[14];
      LW_ctrl_241029_1_B.d_tmp_m[15] = LW_ctrl_241029_1_B.Va_ + (real32_T)
        LW_ctrl_241029_1_B.d_tmp[15];
      LW_ctrl_241029_1_B.IntegralGain = LW_ctrl_241029_1_DW.tau_qk[1];
      LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_DW.tau_qk[0];
      LW_ctrl_241029_1_B.km_f_b = LW_ctrl_241029_1_DW.tau_qk[2];
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_DW.tau_qk[3];
      for (i = 0; i < 4; i++) {
        LW_ctrl_241029_1_B.qk_[i] = ((LW_ctrl_241029_1_B.d_tmp_m[i + 4] *
          LW_ctrl_241029_1_B.IntegralGain + LW_ctrl_241029_1_B.d_tmp_m[i] *
          LW_ctrl_241029_1_B.Va_) + LW_ctrl_241029_1_B.d_tmp_m[i + 8] *
          LW_ctrl_241029_1_B.km_f_b) + LW_ctrl_241029_1_B.d_tmp_m[i + 12] *
          LW_ctrl_241029_1_B.aSinInput;
      }

      /* '<S420>:1:152' qk_ = qk_/(sqrt(qk_'*qk_)); */
      profileStart_LW_ctrl_241029_1(20U); /* original_line:5043 */LW_ctrl_241029_1_B.aSinInput = (real32_T)sqrt(((LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[0] + LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qk_[1]) + LW_ctrl_241029_1_B.qk_[2] *
        LW_ctrl_241029_1_B.qk_[2]) + LW_ctrl_241029_1_B.qk_[3] *
        LW_ctrl_241029_1_B.qk_[3]);profileEnd_LW_ctrl_241029_1(20U); /* original_line:5047 */
      LW_ctrl_241029_1_B.IntegralGain = LW_ctrl_241029_1_B.qk_[0] /
        LW_ctrl_241029_1_B.aSinInput;
      LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.qk_[1] /
        LW_ctrl_241029_1_B.aSinInput;
      LW_ctrl_241029_1_B.km_f_b = LW_ctrl_241029_1_B.qk_[2] /
        LW_ctrl_241029_1_B.aSinInput;
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.qk_[3] /
        LW_ctrl_241029_1_B.aSinInput;
      LW_ctrl_241029_1_B.qk_[0] = LW_ctrl_241029_1_B.IntegralGain;
      LW_ctrl_241029_1_B.qk_[1] = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.qk_[2] = LW_ctrl_241029_1_B.km_f_b;
      LW_ctrl_241029_1_B.qk_[3] = LW_ctrl_241029_1_B.aSinInput;

      /* '<S420>:1:153' d_hat = ModelParam_uavJ*(Le + z3_); */
      /* '<S420>:1:155' if notInfNan(z3_) && notInfNan(omegak_) && notInfNan(qk_) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'notInfNan:4' y = false; */
      want_hold_xy = false;

      /* 'notInfNan:5' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_B.z3_[i]) || rtIsNaNF
            (LW_ctrl_241029_1_B.z3_[i])) {
          /* 'notInfNan:7' y = false; */
          want_hold_xy = false;
          exitg1 = true;
        } else {
          /* 'notInfNan:9' else */
          /* 'notInfNan:10' y = true; */
          want_hold_xy = true;
          i++;
        }
      }

      guard1 = false;
      if (want_hold_xy) {
        /* ISINFNAN 此处显示有关此函数的摘要 */
        /*    Data is a vector. */
        /* 'notInfNan:4' y = false; */
        want_hold_xy = false;

        /* 'notInfNan:5' for ii = 1:length(data) */
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i < 3)) {
          /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
          if (rtIsInfF(LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[i]) ||
              rtIsNaNF(LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[i])) {
            /* 'notInfNan:7' y = false; */
            want_hold_xy = false;
            exitg1 = true;
          } else {
            /* 'notInfNan:9' else */
            /* 'notInfNan:10' y = true; */
            want_hold_xy = true;
            i++;
          }
        }

        if (want_hold_xy) {
          /* ISINFNAN 此处显示有关此函数的摘要 */
          /*    Data is a vector. */
          /* 'notInfNan:4' y = false; */
          want_hold_xy = false;

          /* 'notInfNan:5' for ii = 1:length(data) */
          i = 0;
          exitg1 = false;
          while ((!exitg1) && (i < 4)) {
            /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
            if (rtIsInfF(LW_ctrl_241029_1_B.qk_[i]) || rtIsNaNF
                (LW_ctrl_241029_1_B.qk_[i])) {
              /* 'notInfNan:7' y = false; */
              want_hold_xy = false;
              exitg1 = true;
            } else {
              /* 'notInfNan:9' else */
              /* 'notInfNan:10' y = true; */
              want_hold_xy = true;
              i++;
            }
          }

          if (want_hold_xy) {
            /* '<S420>:1:156' tau_z3 = z3_; */
            /* '<S420>:1:157' tau_omegak = omegak_; */
            LW_ctrl_241029_1_DW.tau_z3[0] = LW_ctrl_241029_1_B.z3_[0];
            LW_ctrl_241029_1_DW.tau_omegak[0] =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];
            LW_ctrl_241029_1_DW.tau_z3[1] = LW_ctrl_241029_1_B.z3_[1];
            LW_ctrl_241029_1_DW.tau_omegak[1] =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];
            LW_ctrl_241029_1_DW.tau_z3[2] = LW_ctrl_241029_1_B.z3_[2];
            LW_ctrl_241029_1_DW.tau_omegak[2] =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2];

            /* '<S420>:1:158' tau_qk = qk_; */
            LW_ctrl_241029_1_DW.tau_qk[0] = LW_ctrl_241029_1_B.IntegralGain;
            LW_ctrl_241029_1_DW.tau_qk[1] = LW_ctrl_241029_1_B.Va_;
            LW_ctrl_241029_1_DW.tau_qk[2] = LW_ctrl_241029_1_B.km_f_b;
            LW_ctrl_241029_1_DW.tau_qk[3] = LW_ctrl_241029_1_B.aSinInput;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        /* '<S420>:1:159' else */
        /* '<S420>:1:160' tau_z3 = single([0;0;0]); */
        /* '<S420>:1:161' tau_omegak = omegam; */
        LW_ctrl_241029_1_DW.tau_z3[0] = 0.0F;
        LW_ctrl_241029_1_DW.tau_omegak[0] = LW_ctrl_241029_1_B.d_est[0];
        LW_ctrl_241029_1_DW.tau_z3[1] = 0.0F;
        LW_ctrl_241029_1_DW.tau_omegak[1] = LW_ctrl_241029_1_B.d_est[1];
        LW_ctrl_241029_1_DW.tau_z3[2] = 0.0F;
        LW_ctrl_241029_1_DW.tau_omegak[2] = LW_ctrl_241029_1_B.d_est[2];

        /* '<S420>:1:162' tau_qk = qm; */
        LW_ctrl_241029_1_DW.tau_qk[0] = LW_ctrl_241029_1_B.qm[0];
        LW_ctrl_241029_1_DW.tau_qk[1] = LW_ctrl_241029_1_B.qm[1];
        LW_ctrl_241029_1_DW.tau_qk[2] = LW_ctrl_241029_1_B.qm[2];
        LW_ctrl_241029_1_DW.tau_qk[3] = LW_ctrl_241029_1_B.qm[3];
      }

      LW_ctrl_241029_1_B.DeadZone_p = LW_ctrl_241029_1_B.Xi_e[1];
      q = LW_ctrl_241029_1_B.Xi_e[0];
      LW_ctrl_241029_1_B.b_c = LW_ctrl_241029_1_B.Xi_e[2];
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.IntegralGain = ((real32_T)
          LW_ctrl_241029_1_ConstP.pooled1[i + 3] * LW_ctrl_241029_1_B.DeadZone_p
          + (real32_T)LW_ctrl_241029_1_ConstP.pooled1[i] * q) + (real32_T)
          LW_ctrl_241029_1_ConstP.pooled1[i + 6] * LW_ctrl_241029_1_B.b_c;
        LW_ctrl_241029_1_B.d_est_j[i] = LW_ctrl_241029_1_B.IntegralGain;

        /* MATLAB Function: '<S419>/Lowpass' */
        LW_ctrl_241029_1_B.d_est[i] = LW_ctrl_241029_1_B.IntegralGain;
      }

      /* MATLAB Function: '<S419>/Lowpass' */
      /*  LW_TEST_DT = dt/(dt + Ts) */
      /*  其中dt是采样周期，Ts是低通滤波器的时间常数 */
      /*  截止频率f = 1/Ts/2pi Hz */
      /*  如 dt=0.004, f=30Hz , LW_TEST_DT=0.43 */
      /* MATLAB Function 'states_update/vehicle_local_position/HIL&FLY V1.13.3/Lowpass': '<S422>:1' */
      /* '<S422>:1:7' if isempty(d_est_last) */
      if (!LW_ctrl_241029_1_DW.d_est_last_not_empty_j) {
        /* '<S422>:1:8' d_est_last = d_est; */
        LW_ctrl_241029_1_DW.d_est_last_f[0] = LW_ctrl_241029_1_B.d_est[0];
        LW_ctrl_241029_1_DW.d_est_last_f[1] = LW_ctrl_241029_1_B.d_est[1];
        LW_ctrl_241029_1_DW.d_est_last_f[2] = LW_ctrl_241029_1_B.d_est[2];
        LW_ctrl_241029_1_DW.d_est_last_not_empty_j = true;
      }

      /* '<S422>:1:10' if isInfNan(d_est_last) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'isInfNan:4' for ii = 1:length(data) */
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        /* 'isInfNan:5' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_DW.d_est_last_f[i]) || rtIsNaNF
            (LW_ctrl_241029_1_DW.d_est_last_f[i])) {
          /* 'isInfNan:6' y = true; */
          rtb_RelationalOperator_om = true;
          exitg1 = true;
        } else {
          /* 'isInfNan:8' else */
          /* 'isInfNan:9' y = false; */
          rtb_RelationalOperator_om = false;
          i++;
        }
      }

      if (rtb_RelationalOperator_om) {
        /* '<S422>:1:11' d_est_last = single([0;0;0]); */
        LW_ctrl_241029_1_DW.d_est_last_f[0] = 0.0F;
        LW_ctrl_241029_1_DW.d_est_last_f[1] = 0.0F;
        LW_ctrl_241029_1_DW.d_est_last_f[2] = 0.0F;
      }

      /* '<S422>:1:13' d_est(1:2) = d_est_last(1:2) + LW_TEST_DTXY*(d_est(1:2) - d_est_last(1:2)); */
      LW_ctrl_241029_1_B.d_est_j[0] = (LW_ctrl_241029_1_B.d_est_j[0] -
        LW_ctrl_241029_1_DW.d_est_last_f[0]) * LW_TEST_DTXY +
        LW_ctrl_241029_1_DW.d_est_last_f[0];
      LW_ctrl_241029_1_B.d_est_j[1] = (LW_ctrl_241029_1_B.d_est_j[1] -
        LW_ctrl_241029_1_DW.d_est_last_f[1]) * LW_TEST_DTXY +
        LW_ctrl_241029_1_DW.d_est_last_f[1];

      /* '<S422>:1:14' d_est(3) = d_est_last(3) + LW_TEST_DTZ*(d_est(3) - d_est_last(3)); */
      LW_ctrl_241029_1_B.d_est_j[2] = (LW_ctrl_241029_1_B.d_est_j[2] -
        LW_ctrl_241029_1_DW.d_est_last_f[2]) * LW_TEST_DTZ +
        LW_ctrl_241029_1_DW.d_est_last_f[2];

      /* '<S422>:1:16' d_est_last = d_est; */
      LW_ctrl_241029_1_DW.d_est_last_f[0] = LW_ctrl_241029_1_B.d_est_j[0];

      /* SignalConversion generated from: '<S419>/Constant' incorporates:
       *  Constant: '<S419>/Constant'
       */
      LW_ctrl_241029_1_B.v_wind[0] = 0.0F;

      /* MATLAB Function: '<S419>/Lowpass' */
      LW_ctrl_241029_1_DW.d_est_last_f[1] = LW_ctrl_241029_1_B.d_est_j[1];

      /* SignalConversion generated from: '<S419>/Constant' incorporates:
       *  Constant: '<S419>/Constant'
       */
      LW_ctrl_241029_1_B.v_wind[1] = 0.0F;

      /* MATLAB Function: '<S419>/Lowpass' */
      LW_ctrl_241029_1_DW.d_est_last_f[2] = LW_ctrl_241029_1_B.d_est_j[2];

      /* SignalConversion generated from: '<S419>/Constant' incorporates:
       *  Constant: '<S419>/Constant'
       */
      LW_ctrl_241029_1_B.v_wind[2] = 0.0F;

      /* MATLAB Function: '<S419>/nan_inf' */
      /* MATLAB Function 'states_update/vehicle_local_position/HIL&FLY V1.13.3/getIncid': '<S424>:1' */
      /* '<S424>:1:3' if notInfNan(q) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'notInfNan:4' y = false; */
      /* 'notInfNan:5' for ii = 1:length(data) */
      /* '<S424>:1:8' theta = euler(2); */
      /* '<S424>:1:9' alpha = theta + LW_ANGLE*pi/180; */
      /* '<S424>:1:10' beta = single(0); */
      /* '<S424>:1:11' incid = [alpha; beta]; */
      profileStart_LW_ctrl_241029_1(21U); /* original_line:5286 */LW_ctrl_241029_1_nan_inf(LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.x,
        LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.y,
        LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.z,
        &LW_ctrl_241029_1_B.sf_nan_inf);profileEnd_LW_ctrl_241029_1(21U); /* original_line:5289 */

      /* MATLAB Function: '<S419>/nan_inf1' */
      profileStart_LW_ctrl_241029_1(22U); /* original_line:5292 */LW_ctrl_241029_1_nan_inf
        (LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vx,
         LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vy,
         LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vz,
         &LW_ctrl_241029_1_B.sf_nan_inf1_f);profileEnd_LW_ctrl_241029_1(22U); /* original_line:5296 */

      /* S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger6' */
      profileStart_LW_ctrl_241029_1(23U); /* original_line:5299 */{
        //interval val: 0
        bool updated;
        orb_check(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger6_uO.fd,
                  &updated);
        if (updated) {
          /* obtained uorb data */
          /* copy sensors raw data into local buffer */
          orb_copy(ORB_ID(battery_status),
                   LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger6_uO.fd,
                   &LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger6);
        }
      }profileEnd_LW_ctrl_241029_1(23U); /* original_line:5311 */

      /* S-Function (sfun_px4_update_mtd_params): '<S419>/ParamUpdate'
       *
       * Block description for '<S419>/ParamUpdate':
       *  ParamUpdate Block
       *
       *  Use this block at your top-level of your model to insert a "parameter update" function in the generated code.
       */
      /* MATLAB Function 'states_update/vehicle_local_position/HIL&FLY V1.13.3/LW_LED': '<S421>:1' */
      /* '<S421>:1:3' y = [LW_LED 0 0]; */
      profileStart_LW_ctrl_241029_1(24U); /* original_line:5322 */{
        bool updated_params = false;
        orb_check(LW_ctrl_241029_1_DW.ParamUpdate_uORB_fd.fd,&updated_params);
        if (updated_params) {
          struct parameter_update_s param_update;
          orb_copy(ORB_ID(parameter_update),
                   LW_ctrl_241029_1_DW.ParamUpdate_uORB_fd.fd,&param_update);
          PX4_INFO("Got parameter update! \n");
          InitParamFunction("LW_ACCSP_FZ",&LW_ACCSP_FZ);/* Assign LW_ACCSP_FZ */
          InitParamFunction("LW_ACCSP_TM",&LW_ACCSP_TM);/* Assign LW_ACCSP_TM */
          InitParamFunction("LW_ACCX_FF",&LW_ACCX_FF);/* Assign LW_ACCX_FF */
          InitParamFunction("LW_ACCY_FF",&LW_ACCY_FF);/* Assign LW_ACCY_FF */
          InitParamFunction("LW_ACCZ_FF",&LW_ACCZ_FF);/* Assign LW_ACCZ_FF */
          InitParamFunction("LW_ACRO_P_MAX",&LW_ACRO_P_MAX);/* Assign LW_ACRO_P_MAX */
          InitParamFunction("LW_ACRO_R_MAX",&LW_ACRO_R_MAX);/* Assign LW_ACRO_R_MAX */
          InitParamFunction("LW_ACRO_Y_MAX",&LW_ACRO_Y_MAX);/* Assign LW_ACRO_Y_MAX */
          InitParamFunction("LW_AERO_C0",&LW_AERO_C0);/* Assign LW_AERO_C0 */
          InitParamFunction("LW_AERO_C1",&LW_AERO_C1);/* Assign LW_AERO_C1 */
          InitParamFunction("LW_AERO_COM",&LW_AERO_COM);/* Assign LW_AERO_COM */
          InitParamFunction("LW_AERO_Y0",&LW_AERO_Y0);/* Assign LW_AERO_Y0 */
          InitParamFunction("LW_ANGLE",&LW_ANGLE);/* Assign LW_ANGLE */
          InitParamFunction("LW_COOR_TURN",&LW_COOR_TURN);/* Assign LW_COOR_TURN */
          InitParamFunction("LW_DMZ0",&LW_DMZ0);/* Assign LW_DMZ0 */
          InitParamFunction("LW_DMZ_MIN",&LW_DMZ_MIN);/* Assign LW_DMZ_MIN */
          InitParamFunction("LW_DSER",&LW_DSER);/* Assign LW_DSER */
          InitParamFunction("LW_DTHR",&LW_DTHR);/* Assign LW_DTHR */
          InitParamFunction("LW_FEST_DT",&LW_FEST_DT);/* Assign LW_FEST_DT */
          InitParamFunction("LW_FEST_EN",&LW_FEST_EN);/* Assign LW_FEST_EN */
          InitParamFunction("LW_FEST_LAMXY",&LW_FEST_LAMXY);/* Assign LW_FEST_LAMXY */
          InitParamFunction("LW_FEST_LAMZ",&LW_FEST_LAMZ);/* Assign LW_FEST_LAMZ */
          InitParamFunction("LW_FEST_P",&LW_FEST_P);/* Assign LW_FEST_P */
          InitParamFunction("LW_FEST_SIGXY",&LW_FEST_SIGXY);/* Assign LW_FEST_SIGXY */
          InitParamFunction("LW_FEST_SIGZ",&LW_FEST_SIGZ);/* Assign LW_FEST_SIGZ */
          InitParamFunction("LW_FEST_TDT",&LW_FEST_TDT);/* Assign LW_FEST_TDT */
          InitParamFunction("LW_FEST_WNXY",&LW_FEST_WNXY);/* Assign LW_FEST_WNXY */
          InitParamFunction("LW_FEST_WNZ",&LW_FEST_WNZ);/* Assign LW_FEST_WNZ */
          InitParamFunction("LW_F_MAP",&LW_F_MAP);/* Assign LW_F_MAP */
          InitParamFunction("LW_LAT_CIRCLE",&LW_LAT_CIRCLE);/* Assign LW_LAT_CIRCLE */
          InitParamFunction("LW_LBCL_D",&LW_LBCL_D);/* Assign LW_LBCL_D */
          InitParamFunction("LW_LBCM_D",&LW_LBCM_D);/* Assign LW_LBCM_D */
          InitParamFunction("LW_LED",&LW_LED);/* Assign LW_LED */
          InitParamFunction("LW_MAN_PITCH_DZ",&LW_MAN_PITCH_DZ);/* Assign LW_MAN_PITCH_DZ */
          InitParamFunction("LW_MAN_PITCH_MAX",&LW_MAN_PITCH_MAX);/* Assign LW_MAN_PITCH_MAX */
          InitParamFunction("LW_MAN_ROLL_DZ",&LW_MAN_ROLL_DZ);/* Assign LW_MAN_ROLL_DZ */
          InitParamFunction("LW_MAN_ROLL_MAX",&LW_MAN_ROLL_MAX);/* Assign LW_MAN_ROLL_MAX */
          InitParamFunction("LW_MAN_WX_DZ",&LW_MAN_WX_DZ);/* Assign LW_MAN_WX_DZ */
          InitParamFunction("LW_MAN_WY_DZ",&LW_MAN_WY_DZ);/* Assign LW_MAN_WY_DZ */
          InitParamFunction("LW_MAN_WZ_DZ",&LW_MAN_WZ_DZ);/* Assign LW_MAN_WZ_DZ */
          InitParamFunction("LW_MASS",&LW_MASS);/* Assign LW_MASS */
          InitParamFunction("LW_MIXER_GAM",&LW_MIXER_GAM);/* Assign LW_MIXER_GAM */
          InitParamFunction("LW_OB_CIRCLE_R",&LW_OB_CIRCLE_R);/* Assign LW_OB_CIRCLE_R */
          InitParamFunction("LW_OB_CIRCLE_V",&LW_OB_CIRCLE_V);/* Assign LW_OB_CIRCLE_V */
          InitParamFunction("LW_OB_CIRCLE_W",&LW_OB_CIRCLE_W);/* Assign LW_OB_CIRCLE_W */
          InitParamFunction("LW_OB_TYPE",&LW_OB_TYPE);/* Assign LW_OB_TYPE */
          InitParamFunction("LW_PITCH_P",&LW_PITCH_P);/* Assign LW_PITCH_P */
          InitParamFunction("LW_REX_YAW",&LW_REX_YAW);/* Assign LW_REX_YAW */
          InitParamFunction("LW_ROLL_P",&LW_ROLL_P);/* Assign LW_ROLL_P */
          InitParamFunction("LW_SERVOL_MAX",&LW_SERVOL_MAX);/* Assign LW_SERVOL_MAX */
          InitParamFunction("LW_SERVOL_MIN",&LW_SERVOL_MIN);/* Assign LW_SERVOL_MIN */
          InitParamFunction("LW_SERVOL_REV",&LW_SERVOL_REV);/* Assign LW_SERVOL_REV */
          InitParamFunction("LW_SERVOR_CON",&LW_SERVOR_CON);/* Assign LW_SERVOR_CON */
          InitParamFunction("LW_SERVOR_MAX",&LW_SERVOR_MAX);/* Assign LW_SERVOR_MAX */
          InitParamFunction("LW_SERVOR_MIN",&LW_SERVOR_MIN);/* Assign LW_SERVOR_MIN */
          InitParamFunction("LW_SERVOR_REV",&LW_SERVOR_REV);/* Assign LW_SERVOR_REV */
          InitParamFunction("LW_SER_LP",&LW_SER_LP);/* Assign LW_SER_LP */
          InitParamFunction("LW_TAUXYSP_FZ",&LW_TAUXYSP_FZ);/* Assign LW_TAUXYSP_FZ */
          InitParamFunction("LW_TAUXYSP_TM",&LW_TAUXYSP_TM);/* Assign LW_TAUXYSP_TM */
          InitParamFunction("LW_TAUZSP_FZ",&LW_TAUZSP_FZ);/* Assign LW_TAUZSP_FZ */
          InitParamFunction("LW_TAUZSP_TM",&LW_TAUZSP_TM);/* Assign LW_TAUZSP_TM */
          InitParamFunction("LW_TEST_DTXY",&LW_TEST_DTXY);/* Assign LW_TEST_DTXY */
          InitParamFunction("LW_TEST_DTZ",&LW_TEST_DTZ);/* Assign LW_TEST_DTZ */
          InitParamFunction("LW_TEST_EN",&LW_TEST_EN);/* Assign LW_TEST_EN */
          InitParamFunction("LW_TEST_LAMXY",&LW_TEST_LAMXY);/* Assign LW_TEST_LAMXY */
          InitParamFunction("LW_TEST_LAMZ",&LW_TEST_LAMZ);/* Assign LW_TEST_LAMZ */
          InitParamFunction("LW_TEST_SIGXY",&LW_TEST_SIGXY);/* Assign LW_TEST_SIGXY */
          InitParamFunction("LW_TEST_SIGZ",&LW_TEST_SIGZ);/* Assign LW_TEST_SIGZ */
          InitParamFunction("LW_TEST_TDT",&LW_TEST_TDT);/* Assign LW_TEST_TDT */
          InitParamFunction("LW_TEST_WBDT",&LW_TEST_WBDT);/* Assign LW_TEST_WBDT */
          InitParamFunction("LW_TEST_WNXY",&LW_TEST_WNXY);/* Assign LW_TEST_WNXY */
          InitParamFunction("LW_TEST_WNZ",&LW_TEST_WNZ);/* Assign LW_TEST_WNZ */
          InitParamFunction("LW_THR_HOVER",&LW_THR_HOVER);/* Assign LW_THR_HOVER */
          InitParamFunction("LW_THR_LOW",&LW_THR_LOW);/* Assign LW_THR_LOW */
          InitParamFunction("LW_TILTMAX_AIR",&LW_TILTMAX_AIR);/* Assign LW_TILTMAX_AIR */
          InitParamFunction("LW_USE_SER",&LW_USE_SER);/* Assign LW_USE_SER */
          InitParamFunction("LW_VA_TMAX",&LW_VA_TMAX);/* Assign LW_VA_TMAX */
          InitParamFunction("LW_VA_TMIN",&LW_VA_TMIN);/* Assign LW_VA_TMIN */
          InitParamFunction("LW_VEL_DT",&LW_VEL_DT);/* Assign LW_VEL_DT */
          InitParamFunction("LW_WX_D",&LW_WX_D);/* Assign LW_WX_D */
          InitParamFunction("LW_WX_FF",&LW_WX_FF);/* Assign LW_WX_FF */
          InitParamFunction("LW_WX_I",&LW_WX_I);/* Assign LW_WX_I */
          InitParamFunction("LW_WX_MAX",&LW_WX_MAX);/* Assign LW_WX_MAX */
          InitParamFunction("LW_WX_N",&LW_WX_N);/* Assign LW_WX_N */
          InitParamFunction("LW_WX_P",&LW_WX_P);/* Assign LW_WX_P */
          InitParamFunction("LW_WY_D",&LW_WY_D);/* Assign LW_WY_D */
          InitParamFunction("LW_WY_DE_MAX",&LW_WY_DE_MAX);/* Assign LW_WY_DE_MAX */
          InitParamFunction("LW_WY_FF",&LW_WY_FF);/* Assign LW_WY_FF */
          InitParamFunction("LW_WY_I",&LW_WY_I);/* Assign LW_WY_I */
          InitParamFunction("LW_WY_MAX",&LW_WY_MAX);/* Assign LW_WY_MAX */
          InitParamFunction("LW_WY_N",&LW_WY_N);/* Assign LW_WY_N */
          InitParamFunction("LW_WY_P",&LW_WY_P);/* Assign LW_WY_P */
          InitParamFunction("LW_WZ_D",&LW_WZ_D);/* Assign LW_WZ_D */
          InitParamFunction("LW_WZ_FF",&LW_WZ_FF);/* Assign LW_WZ_FF */
          InitParamFunction("LW_WZ_I",&LW_WZ_I);/* Assign LW_WZ_I */
          InitParamFunction("LW_WZ_MAX",&LW_WZ_MAX);/* Assign LW_WZ_MAX */
          InitParamFunction("LW_WZ_N",&LW_WZ_N);/* Assign LW_WZ_N */
          InitParamFunction("LW_WZ_P",&LW_WZ_P);/* Assign LW_WZ_P */
          InitParamFunction("LW_W_FZ",&LW_W_FZ);/* Assign LW_W_FZ */
          InitParamFunction("LW_W_SER",&LW_W_SER);/* Assign LW_W_SER */
          InitParamFunction("LW_W_SERH",&LW_W_SERH);/* Assign LW_W_SERH */
          InitParamFunction("LW_W_TAOX",&LW_W_TAOX);/* Assign LW_W_TAOX */
          InitParamFunction("LW_W_TAOY",&LW_W_TAOY);/* Assign LW_W_TAOY */
          InitParamFunction("LW_W_TAOZ",&LW_W_TAOZ);/* Assign LW_W_TAOZ */
          InitParamFunction("LW_X_ACCEL_MAX",&LW_X_ACCEL_MAX);/* Assign LW_X_ACCEL_MAX */
          InitParamFunction("LW_X_ACCEL_MIN",&LW_X_ACCEL_MIN);/* Assign LW_X_ACCEL_MIN */
          InitParamFunction("LW_X_FF",&LW_X_FF);/* Assign LW_X_FF */
          InitParamFunction("LW_X_JERK_MAX",&LW_X_JERK_MAX);/* Assign LW_X_JERK_MAX */
          InitParamFunction("LW_X_P",&LW_X_P);/* Assign LW_X_P */
          InitParamFunction("LW_X_VEL_D",&LW_X_VEL_D);/* Assign LW_X_VEL_D */
          InitParamFunction("LW_X_VEL_DZ",&LW_X_VEL_DZ);/* Assign LW_X_VEL_DZ */
          InitParamFunction("LW_X_VEL_I",&LW_X_VEL_I);/* Assign LW_X_VEL_I */
          InitParamFunction("LW_X_VEL_MAX",&LW_X_VEL_MAX);/* Assign LW_X_VEL_MAX */
          InitParamFunction("LW_X_VEL_N",&LW_X_VEL_N);/* Assign LW_X_VEL_N */
          InitParamFunction("LW_X_VEL_P",&LW_X_VEL_P);/* Assign LW_X_VEL_P */
          InitParamFunction("LW_YAW_KAD",&LW_YAW_KAD);/* Assign LW_YAW_KAD */
          InitParamFunction("LW_YAW_KAP",&LW_YAW_KAP);/* Assign LW_YAW_KAP */
          InitParamFunction("LW_YAW_P",&LW_YAW_P);/* Assign LW_YAW_P */
          InitParamFunction("LW_Y_ACCEL_MAX",&LW_Y_ACCEL_MAX);/* Assign LW_Y_ACCEL_MAX */
          InitParamFunction("LW_Y_ACCEL_MIN",&LW_Y_ACCEL_MIN);/* Assign LW_Y_ACCEL_MIN */
          InitParamFunction("LW_Y_FF",&LW_Y_FF);/* Assign LW_Y_FF */
          InitParamFunction("LW_Y_JERK_MAX",&LW_Y_JERK_MAX);/* Assign LW_Y_JERK_MAX */
          InitParamFunction("LW_Y_P",&LW_Y_P);/* Assign LW_Y_P */
          InitParamFunction("LW_Y_VEL_D",&LW_Y_VEL_D);/* Assign LW_Y_VEL_D */
          InitParamFunction("LW_Y_VEL_DZ",&LW_Y_VEL_DZ);/* Assign LW_Y_VEL_DZ */
          InitParamFunction("LW_Y_VEL_I",&LW_Y_VEL_I);/* Assign LW_Y_VEL_I */
          InitParamFunction("LW_Y_VEL_MAX",&LW_Y_VEL_MAX);/* Assign LW_Y_VEL_MAX */
          InitParamFunction("LW_Y_VEL_N",&LW_Y_VEL_N);/* Assign LW_Y_VEL_N */
          InitParamFunction("LW_Y_VEL_P",&LW_Y_VEL_P);/* Assign LW_Y_VEL_P */
          InitParamFunction("LW_Z_ACCEL_LOW",&LW_Z_ACCEL_LOW);/* Assign LW_Z_ACCEL_LOW */
          InitParamFunction("LW_Z_ACCEL_UP",&LW_Z_ACCEL_UP);/* Assign LW_Z_ACCEL_UP */
          InitParamFunction("LW_Z_FF",&LW_Z_FF);/* Assign LW_Z_FF */
          InitParamFunction("LW_Z_JERK_MAX",&LW_Z_JERK_MAX);/* Assign LW_Z_JERK_MAX */
          InitParamFunction("LW_Z_P",&LW_Z_P);/* Assign LW_Z_P */
          InitParamFunction("LW_Z_VEL_D",&LW_Z_VEL_D);/* Assign LW_Z_VEL_D */
          InitParamFunction("LW_Z_VEL_DZ",&LW_Z_VEL_DZ);/* Assign LW_Z_VEL_DZ */
          InitParamFunction("LW_Z_VEL_I",&LW_Z_VEL_I);/* Assign LW_Z_VEL_I */
          InitParamFunction("LW_Z_VEL_MAX_UP",&LW_Z_VEL_MAX_UP);/* Assign LW_Z_VEL_MAX_UP */
          InitParamFunction("LW_Z_VEL_N",&LW_Z_VEL_N);/* Assign LW_Z_VEL_N */
          InitParamFunction("LW_Z_VEL_P",&LW_Z_VEL_P);/* Assign LW_Z_VEL_P */
          InitParamFunction("RC1_MAX",&RC1_MAX);/* Assign RC1_MAX */
          InitParamFunction("RC1_MIN",&RC1_MIN);/* Assign RC1_MIN */
          InitParamFunction("RC1_REV",&RC1_REV);/* Assign RC1_REV */
          InitParamFunction("RC2_MAX",&RC2_MAX);/* Assign RC2_MAX */
          InitParamFunction("RC2_MIN",&RC2_MIN);/* Assign RC2_MIN */
          InitParamFunction("RC2_REV",&RC2_REV);/* Assign RC2_REV */
          InitParamFunction("RC3_MAX",&RC3_MAX);/* Assign RC3_MAX */
          InitParamFunction("RC3_MIN",&RC3_MIN);/* Assign RC3_MIN */
          InitParamFunction("RC3_REV",&RC3_REV);/* Assign RC3_REV */
          InitParamFunction("RC4_MAX",&RC4_MAX);/* Assign RC4_MAX */
          InitParamFunction("RC4_MIN",&RC4_MIN);/* Assign RC4_MIN */
          InitParamFunction("RC4_REV",&RC4_REV);/* Assign RC4_REV */
        }
      }profileEnd_LW_ctrl_241029_1(24U); /* original_line:5483 */

      /* Update for Memory: '<S425>/Memory' */
      LW_ctrl_241029_1_DW.Memory_PreviousInput =
        LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger1.timestamp;

      /* End of Outputs for SubSystem: '<Root>/states_update' */
    }

    /* '<S3>:1:3' sf_internal_predicateOutput = every(AttCtrl_cycle,tick); */
    if (LW_ctrl_241029_1_DW.temporalCounter_i2 == 1U) {
      /* Outputs for Function Call SubSystem: '<S1>/PID_Controller' */
      /* '<S3>:1:3' send(AttCtrl); */
      /* Event: '<S3>:4' */
      if (LW_ctrl_241029_1_DW.PID_Controller_RESET_ELAPS_T) {
        LW_ctrl_241029_1_B.PID_Controller_ELAPS_T = 0U;
      } else {
        LW_ctrl_241029_1_B.PID_Controller_ELAPS_T =
          LW_ctrl_241029_1_M->Timing.clockTick0 -
          LW_ctrl_241029_1_DW.PID_Controller_PREV_T;
      }

      LW_ctrl_241029_1_DW.PID_Controller_PREV_T =
        LW_ctrl_241029_1_M->Timing.clockTick0;
      LW_ctrl_241029_1_DW.PID_Controller_RESET_ELAPS_T = false;

      /* RelationalOperator: '<S10>/Compare' incorporates:
       *  Constant: '<S10>/Constant'
       *  MATLAB Function: '<S9>/nan_inf_mode'
       */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/nan_inf_mode': '<S13>:1' */
      /* '<S13>:1:2' for i = 1:length(u) */
      /* '<S13>:1:3' if isnan(u(i)) || isinf(u(i)) */
      /* '<S13>:1:7' y = u; */
      rtb_RelationalOperator_om = (LW_ctrl_241029_1_B.arm == ARM);

      /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
       *  MATLAB Function: '<S11>/MATLAB Function1'
       */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/select parameter/MATLAB Function': '<S358>:1' */
      /* '<S358>:1:3' y = my_quat2eul(u); */
      /* MY_QUAT2EUL Convert quaternion to Euler angles, modified from quat2eul.m */
      /*    EUL = QUAT2EUL(QOBJ) converts a quaternion object, QOBJ, into the */
      /*    corresponding Euler angles, EUL.QOBJ is an 4-element vector of quaternion objects. */
      /*    The output, EUL, is an 3-element vector of Euler rotation angles,that is [roll;pitch;yaw]. Rotation angles are in radians. */
      /* 'my_quat2eul:6' q = q(:); */
      /* 'my_quat2eul:7' if isempty(varargin) */
      /*  Use default rotation sequence */
      /* 'my_quat2eul:9' seq = 'ZXY'; */
      /* 'my_quat2eul:13' q = robotics.internal.validation.validateQuaternion(q', 'quat2eul', 'q'); */
      /* norm_q = sqrt(q' * q); */
      /*  if norm_q < 0.5 */
      /*      q = [1;0;0;0]; */
      /*      norm_q = 1; */
      /*  end */
      /* q = q ./ norm_q; */
      /* 'my_quat2eul:20' q = robotics.internal.normalizeRows(q); */
      LW_ctrl_241029_1_B.FilterCoefficient_k = ((LW_ctrl_241029_1_B.y[0] *
        LW_ctrl_241029_1_B.y[0] + LW_ctrl_241029_1_B.y[1] *
        LW_ctrl_241029_1_B.y[1]) + LW_ctrl_241029_1_B.y[2] *
        LW_ctrl_241029_1_B.y[2]) + LW_ctrl_241029_1_B.y[3] *
        LW_ctrl_241029_1_B.y[3];
      profileStart_LW_ctrl_241029_1(25U); /* original_line:5545 */Filter_o5 = 1.0F / (real32_T)sqrt(LW_ctrl_241029_1_B.FilterCoefficient_k);profileEnd_LW_ctrl_241029_1(25U); /* original_line:5545 */
      LW_ctrl_241029_1_B.qk_[0] = LW_ctrl_241029_1_B.y[0] * Filter_o5;
      LW_ctrl_241029_1_B.qk_[1] = LW_ctrl_241029_1_B.y[1] * Filter_o5;
      LW_ctrl_241029_1_B.qk_[2] = LW_ctrl_241029_1_B.y[2] * Filter_o5;
      LW_ctrl_241029_1_B.qk_[3] = LW_ctrl_241029_1_B.y[3] * Filter_o5;

      /* 'my_quat2eul:22' qw = q(1); */
      /* 'my_quat2eul:23' qx = q(2); */
      /* 'my_quat2eul:24' qy = q(3); */
      /* 'my_quat2eul:25' qz = q(4); */
      /*  Pre-allocate output */
      /* 'my_quat2eul:28' eul = single(zeros(3, 1,'like',q)); */
      /* 'my_quat2eul:29' upperSeq = upper(seq); */
      /* 'my_quat2eul:30' switch upperSeq */
      /* 'my_quat2eul:72' case 'ZXY' */
      /* 'my_quat2eul:73' aSinInput = 2 * (qy .* qz + qw .* qx); */
      LW_ctrl_241029_1_B.aSinInput = (LW_ctrl_241029_1_B.qk_[2] *
        LW_ctrl_241029_1_B.qk_[3] + LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[1]) * 2.0F;

      /* 'my_quat2eul:74' if aSinInput > 1 */
      if (LW_ctrl_241029_1_B.aSinInput > 1.0F) {
        /* 'my_quat2eul:75' aSinInput = single(1); */
        LW_ctrl_241029_1_B.aSinInput = 1.0F;
      } else if (LW_ctrl_241029_1_B.aSinInput < -1.0F) {
        /* 'my_quat2eul:76' elseif (aSinInput < -1) */
        /* 'my_quat2eul:77' aSinInput = -single(1); */
        LW_ctrl_241029_1_B.aSinInput = -1.0F;
      }

      /* 'my_quat2eul:80' eul = [ asin( aSinInput ); ... */
      /* 'my_quat2eul:81'             atan2( -2 * (qx .* qz - qw .* qy), qw .^ 2 - qx .^ 2 - qy .^ 2 + qz .^ 2 ); ... */
      /* 'my_quat2eul:82'             atan2( -2 * (qx .* qy - qw .* qz), qw .^ 2 - qx .^ 2 + qy .^ 2 - qz .^ 2 )]; */
      /*  Check for complex numbers */
      /* 'my_quat2eul:93' if ~isreal(eul) */
      rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[0] - LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qk_[1];
      LW_ctrl_241029_1_B.T1 = LW_ctrl_241029_1_B.qk_[2] *
        LW_ctrl_241029_1_B.qk_[2];
      LW_ctrl_241029_1_B.T2 = LW_ctrl_241029_1_B.qk_[3] *
        LW_ctrl_241029_1_B.qk_[3];
      profileStart_LW_ctrl_241029_1(26U); /* original_line:5587 */LW_ctrl_241029_1_B.T3 = rt_atan2f_snf((LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qk_[2] - LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[3]) * -2.0F, (rtb_FilterCoefficient_jy_tmp +
        LW_ctrl_241029_1_B.T1) - LW_ctrl_241029_1_B.T2);profileEnd_LW_ctrl_241029_1(26U); /* original_line:5590 */
      profileStart_LW_ctrl_241029_1(27U); /* original_line:5591 */LW_ctrl_241029_1_B.d_est[0] = (real32_T)asin(LW_ctrl_241029_1_B.aSinInput);profileEnd_LW_ctrl_241029_1(27U); /* original_line:5591 */
      profileStart_LW_ctrl_241029_1(28U); /* original_line:5592 */LW_ctrl_241029_1_B.d_est[1] = rt_atan2f_snf((LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qk_[3] - LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[2]) * -2.0F, (rtb_FilterCoefficient_jy_tmp -
        LW_ctrl_241029_1_B.T1) + LW_ctrl_241029_1_B.T2);profileEnd_LW_ctrl_241029_1(28U); /* original_line:5595 */

      /* MATLAB Function: '<S14>/pos_ctrl_integral_reset1' incorporates:
       *  MATLAB Function: '<S14>/pos_ctrl_integral_reset2'
       *  MATLAB Function: '<S15>/MATLAB Function'
       */
      /*  构造旋转矩阵 */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/postion control/pos_ctrl_integral_reset1': '<S190>:1' */
      /* '<S190>:1:3' R = [cos(psi), sin(psi), 0; */
      /* '<S190>:1:4'          -sin(psi), cos(psi), 0; */
      /* '<S190>:1:5'          0, 0, 1]; */
      /*  转换速度 */
      /* '<S190>:1:8' v_body = R * [v_ned(1);v_ned(2);v_ned(3)]; */
      profileStart_LW_ctrl_241029_1(29U); /* original_line:5608 */LW_ctrl_241029_1_B.km_f_b = (real32_T)sin(LW_ctrl_241029_1_B.T3);profileEnd_LW_ctrl_241029_1(29U); /* original_line:5608 */
      profileStart_LW_ctrl_241029_1(30U); /* original_line:5609 */LW_ctrl_241029_1_B.Va_ = (real32_T)cos(LW_ctrl_241029_1_B.T3);profileEnd_LW_ctrl_241029_1(30U); /* original_line:5609 */
      LW_ctrl_241029_1_B.Rbe_psi[0] = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.Rbe_psi[3] = LW_ctrl_241029_1_B.km_f_b;
      LW_ctrl_241029_1_B.Rbe_psi[6] = 0.0F;
      LW_ctrl_241029_1_B.Rbe_psi[1] = -LW_ctrl_241029_1_B.km_f_b;
      LW_ctrl_241029_1_B.Rbe_psi[4] = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.Rbe_psi[7] = 0.0F;
      LW_ctrl_241029_1_B.Rbe_psi[2] = 0.0F;
      LW_ctrl_241029_1_B.Rbe_psi[5] = 0.0F;
      LW_ctrl_241029_1_B.Rbe_psi[8] = 1.0F;
      LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
      LW_ctrl_241029_1_B.T1 = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];
      LW_ctrl_241029_1_B.T2 = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2];
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.Xi_e[i] = (LW_ctrl_241029_1_B.Rbe_psi[i + 3] *
          LW_ctrl_241029_1_B.T1 + LW_ctrl_241029_1_B.Rbe_psi[i] *
          LW_ctrl_241029_1_B.time_to_stop) + LW_ctrl_241029_1_B.Rbe_psi[i + 6] *
          LW_ctrl_241029_1_B.T2;
      }

      /* End of MATLAB Function: '<S14>/pos_ctrl_integral_reset1' */

      /* MATLAB Function: '<S12>/position control' incorporates:
       *  BusCreator generated from: '<S12>/position control'
       *  MATLAB Function: '<S12>/nan_inf_mode'
       *  MATLAB Function: '<S12>/nan_inf_mode1'
       */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/local_pos_ref_selector/nan_inf_mode': '<S185>:1' */
      /* '<S185>:1:3' for i = 1:length(u) */
      /* '<S185>:1:4' if isnan(u(i)) || isinf(u(i)) */
      /* '<S185>:1:8' y = u; */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/local_pos_ref_selector/nan_inf_mode1': '<S186>:1' */
      /* '<S186>:1:3' for i = 1:length(u) */
      /* '<S186>:1:4' if isnan(u(i)) || isinf(u(i)) */
      /* '<S186>:1:8' y = u; */
      /* Function description: */
      /*   Mode switch implementation. */
      /* Input: */
      /*   mode */
      /*   manual_vel_ref：航向坐标系下的期望速度 */
      /*   vel_ref: The desired velocity specified by the remote control */
      /*   x, y, z: current position */
      /*   vx, vy,vz: current velocity */
      /* Output: */
      /*   pos_ref, vd_lim: desired velocity and position in NED */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/local_pos_ref_selector/position control': '<S187>:1' */
      /* '<S187>:1:16' lw_acc_xy_max = LW_Y_ACCEL_MAX; */
      /* 水平方向最大减速加速度 */
      /* '<S187>:1:17' lw_acc_z_max = single(3.0); */
      /* '<S187>:1:18' if notInfNan(q) */
      if (LW_ctrl_241029_1_notInfNan(LW_ctrl_241029_1_B.y)) {
        /* '<S187>:1:19' yaw = my_quat2yaw(q,'ZYX'); */
        /* 'my_quat2yaw:2' if isempty(varargin) */
        /* 'my_quat2yaw:5' else */
        /* 'my_quat2yaw:6' euler = my_quat2eul(q, convertStringsToChars(varargin{1})); */
        /* 'my_quat2yaw:9' yaw = euler(3); */
        profileStart_LW_ctrl_241029_1(31U); /* original_line:5665 */LW_ctrl_241029_1_my_quat2eul(LW_ctrl_241029_1_B.y,
          LW_ctrl_241029_1_B.vel_ref_c);profileEnd_LW_ctrl_241029_1(31U); /* original_line:5666 */
        LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.vel_ref_c[2];

        /* 强制旋转次序，很有必要 */
      } else {
        /* '<S187>:1:20' else */
        /* '<S187>:1:21' yaw = single(0); */
        LW_ctrl_241029_1_B.aSinInput = 0.0F;
      }

      /*  persistent data define */
      /* '<S187>:1:26' if isempty(timestamp_last) */
      if (!LW_ctrl_241029_1_DW.timestamp_last_not_empty) {
        /* '<S187>:1:27' timestamp_last = timestamp; */
        LW_ctrl_241029_1_DW.timestamp_last_not_empty = true;

        /* '<S187>:1:28' dt = single(0.02); */
        LW_ctrl_241029_1_B.IntegralGain = 0.02F;
      } else {
        /* '<S187>:1:29' else */
        /* '<S187>:1:30' dt = single((timestamp - timestamp_last)*1e-6); */
        LW_ctrl_241029_1_B.IntegralGain = (real32_T)
          ((LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp -
            LW_ctrl_241029_1_DW.timestamp_last) * 1.0E-6);
      }

      /* '<S187>:1:32' if dt > 0.2 */
      if (LW_ctrl_241029_1_B.IntegralGain > 0.2) {
        /* '<S187>:1:33' dt = single(0.2); */
        LW_ctrl_241029_1_B.IntegralGain = 0.2F;
      } else if (LW_ctrl_241029_1_B.IntegralGain < 0.001) {
        /* '<S187>:1:34' elseif dt < 0.001 */
        /* '<S187>:1:35' dt = single(0.001); */
        LW_ctrl_241029_1_B.IntegralGain = 0.001F;
      }

      /* '<S187>:1:37' timestamp_last = timestamp; */
      LW_ctrl_241029_1_DW.timestamp_last =
        LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

      /* '<S187>:1:40' if isempty(pos_x1) || isempty(pos_y1) || isempty(pos_z1) */
      if ((!LW_ctrl_241029_1_DW.pos_x1_not_empty) ||
          (!LW_ctrl_241029_1_DW.pos_y1_not_empty) ||
          (!LW_ctrl_241029_1_DW.pos_z1_not_empty)) {
        /* '<S187>:1:41' if notInfNan(vehicle_pos) */
        if (LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.sf_nan_inf.y)) {
          /* '<S187>:1:42' pos_x1 = vehicle_pos(1); */
          LW_ctrl_241029_1_DW.pos_x1 = LW_ctrl_241029_1_B.sf_nan_inf.y[0];
          LW_ctrl_241029_1_DW.pos_x1_not_empty = true;

          /* '<S187>:1:43' pos_y1 = vehicle_pos(2); */
          LW_ctrl_241029_1_DW.pos_y1 = LW_ctrl_241029_1_B.sf_nan_inf.y[1];
          LW_ctrl_241029_1_DW.pos_y1_not_empty = true;

          /* '<S187>:1:44' pos_z1 = vehicle_pos(3); */
          LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_B.sf_nan_inf.y[2];
          LW_ctrl_241029_1_DW.pos_z1_not_empty = true;
        } else {
          /* '<S187>:1:45' else */
          /* '<S187>:1:46' pos_x1 = single(0); */
          LW_ctrl_241029_1_DW.pos_x1 = 0.0F;
          LW_ctrl_241029_1_DW.pos_x1_not_empty = true;

          /* '<S187>:1:47' pos_y1 = single(0); */
          LW_ctrl_241029_1_DW.pos_y1 = 0.0F;
          LW_ctrl_241029_1_DW.pos_y1_not_empty = true;

          /* '<S187>:1:48' pos_z1 = single(0); */
          LW_ctrl_241029_1_DW.pos_z1 = 0.0F;
          LW_ctrl_241029_1_DW.pos_z1_not_empty = true;
        }
      }

      /* '<S187>:1:52' if isempty(hold_xy_flag) || isempty(hold_z_flag) */
      if ((!LW_ctrl_241029_1_DW.hold_xy_flag_not_empty) ||
          (!LW_ctrl_241029_1_DW.hold_z_flag_not_empty)) {
        /* '<S187>:1:53' hold_xy_flag = false; */
        LW_ctrl_241029_1_DW.hold_xy_flag = false;
        LW_ctrl_241029_1_DW.hold_xy_flag_not_empty = true;

        /* '<S187>:1:54' hold_z_flag = false; */
        LW_ctrl_241029_1_DW.hold_z_flag = false;
        LW_ctrl_241029_1_DW.hold_z_flag_not_empty = true;
      }

      /* '<S187>:1:57' if isempty(yaw_d_) */
      if (!LW_ctrl_241029_1_DW.yaw_d__not_empty) {
        /* '<S187>:1:58' if notInfNan(yaw) */
        /* ISINFNAN 此处显示有关此函数的摘要 */
        /*    Data is a vector. */
        /* 'notInfNan:4' y = false; */
        /* 'notInfNan:5' for ii = 1:length(data) */
        /* 'notInfNan:6' if isinf(data(ii)) || isnan(data(ii)) */
        if (rtIsInfF(LW_ctrl_241029_1_B.aSinInput) || rtIsNaNF
            (LW_ctrl_241029_1_B.aSinInput)) {
          /* 'notInfNan:7' y = false; */
          /* '<S187>:1:60' else */
          /* '<S187>:1:61' yaw_d_ = single(0); */
          LW_ctrl_241029_1_DW.yaw_d_ = 0.0F;
          LW_ctrl_241029_1_DW.yaw_d__not_empty = true;
        } else {
          /* 'notInfNan:9' else */
          /* 'notInfNan:10' y = true; */
          /* '<S187>:1:59' yaw_d_ = yaw; */
          LW_ctrl_241029_1_DW.yaw_d_ = LW_ctrl_241029_1_B.aSinInput;
          LW_ctrl_241029_1_DW.yaw_d__not_empty = true;
        }
      }

      /* '<S187>:1:65' if isempty(hold_xy_timestamp) || isempty(hold_z_timestamp) */
      if ((!LW_ctrl_241029_1_DW.hold_xy_timestamp_not_empty) ||
          (!LW_ctrl_241029_1_DW.hold_z_timestamp_not_empty)) {
        /* '<S187>:1:66' hold_xy_timestamp = timestamp; */
        LW_ctrl_241029_1_DW.hold_xy_timestamp =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;
        LW_ctrl_241029_1_DW.hold_xy_timestamp_not_empty = true;

        /* '<S187>:1:67' hold_z_timestamp = timestamp; */
        LW_ctrl_241029_1_DW.hold_z_timestamp =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;
        LW_ctrl_241029_1_DW.hold_z_timestamp_not_empty = true;
      }

      /* '<S187>:1:69' if isempty(hold_vxy) */
      if (!LW_ctrl_241029_1_DW.hold_vxy_not_empty) {
        /* '<S187>:1:70' hold_vxy = vehicle_vel(1:2); */
        LW_ctrl_241029_1_DW.hold_vxy[0] = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
        LW_ctrl_241029_1_DW.hold_vxy[1] = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];
        LW_ctrl_241029_1_DW.hold_vxy_not_empty = true;
      }

      /* '<S187>:1:72' if isempty(hold_pxy) */
      if (!LW_ctrl_241029_1_DW.hold_pxy_not_empty) {
        /* '<S187>:1:73' hold_pxy = vehicle_pos(1:2); */
        LW_ctrl_241029_1_DW.hold_pxy[0] = LW_ctrl_241029_1_B.sf_nan_inf.y[0];
        LW_ctrl_241029_1_DW.hold_pxy[1] = LW_ctrl_241029_1_B.sf_nan_inf.y[1];
        LW_ctrl_241029_1_DW.hold_pxy_not_empty = true;
      }

      /* '<S187>:1:75' if isempty(hold_pz) */
      if (!LW_ctrl_241029_1_DW.hold_pz_not_empty) {
        /* '<S187>:1:76' hold_pz = vehicle_pos(3); */
        LW_ctrl_241029_1_DW.hold_pz = LW_ctrl_241029_1_B.sf_nan_inf.y[2];
        LW_ctrl_241029_1_DW.hold_pz_not_empty = true;
      }

      /* '<S187>:1:78' if isempty(hold_vz) */
      if (!LW_ctrl_241029_1_DW.hold_vz_not_empty) {
        /* '<S187>:1:79' hold_vz = vehicle_vel(3); */
        LW_ctrl_241029_1_DW.hold_vz = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2];
        LW_ctrl_241029_1_DW.hold_vz_not_empty = true;
      }

      /* '<S187>:1:83' if isempty(heading_reset_counter_) || isempty(xy_reset_counter_) || isempty(z_reset_counter_) ... */
      /* '<S187>:1:84'         || isempty(vxy_reset_counter_) || isempty(vz_reset_counter_) */
      if ((!LW_ctrl_241029_1_DW.heading_reset_counter__not_empt) ||
          (!LW_ctrl_241029_1_DW.xy_reset_counter__not_empty) ||
          (!LW_ctrl_241029_1_DW.z_reset_counter__not_empty) ||
          (!LW_ctrl_241029_1_DW.vxy_reset_counter__not_empty) ||
          (!LW_ctrl_241029_1_DW.vz_reset_counter__not_empty)) {
        /* '<S187>:1:85' xy_reset_counter_ = xy_reset_counter; */
        LW_ctrl_241029_1_DW.xy_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.xy_reset_counter;
        LW_ctrl_241029_1_DW.xy_reset_counter__not_empty = true;

        /* '<S187>:1:86' z_reset_counter_ = z_reset_counter; */
        LW_ctrl_241029_1_DW.z_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.z_reset_counter;
        LW_ctrl_241029_1_DW.z_reset_counter__not_empty = true;

        /* '<S187>:1:87' vxy_reset_counter_ = vxy_reset_counter; */
        LW_ctrl_241029_1_DW.vxy_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vxy_reset_counter;
        LW_ctrl_241029_1_DW.vxy_reset_counter__not_empty = true;

        /* '<S187>:1:88' vz_reset_counter_ = vz_reset_counter; */
        LW_ctrl_241029_1_DW.vz_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vz_reset_counter;
        LW_ctrl_241029_1_DW.vz_reset_counter__not_empty = true;

        /* '<S187>:1:89' heading_reset_counter_ = heading_reset_counter; */
        LW_ctrl_241029_1_DW.heading_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.heading_reset_counter;
        LW_ctrl_241029_1_DW.heading_reset_counter__not_empt = true;
      }

      /* '<S187>:1:92' man_acc_ff = zeros(3,1,'single'); */
      /* '<S187>:1:93' if notInfNan(flight_mode) && notInfNan(ctrl_mode) && arm == ControlMode.ARM */
      if (LW_ctrl_241029_1_B.arm == ARM) {
        /*     %% yaw control */
        /* '<S187>:1:95' relaxed_yaw = states_flag(1); */
        /* '<S187>:1:96' wbz_ref = single(0); */
        /* '<S187>:1:97' if flight_mode == FlightMode.PILOT && notInfNan(manual_rates_ref)... */
        /* '<S187>:1:98'             && ctrl_mode == ControlMode.POSITION */
        if ((LW_ctrl_241029_1_B.flight_mode == PILOT) &&
            LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.rates_ref) &&
            (LW_ctrl_241029_1_B.ctrl_mode == POSITION)) {
          /* '<S187>:1:99' if hold_xy_flag && LW_REX_YAW > 0.5 && abs(manual_rates_ref(3)) < 0.01 */
          if (LW_ctrl_241029_1_DW.hold_xy_flag && (LW_REX_YAW > 0.5F) &&
              ((real32_T)fabs(LW_ctrl_241029_1_B.rates_ref[2]) < 0.01)) {
            /* '<S187>:1:100' Euler = my_quat2eul(q,'ZYX'); */
            profileStart_LW_ctrl_241029_1(35U); /* original_line:5867 */LW_ctrl_241029_1_my_quat2eul(LW_ctrl_241029_1_B.y,
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro);profileEnd_LW_ctrl_241029_1(35U); /* original_line:5868 */

            /* '<S187>:1:101' dot_yaw = sin(Euler(1))/cos(Euler(2))*wb(2) + cos(Euler(1))/cos(Euler(2))*wb(3); */
            /* '<S187>:1:102' if LW_YAW_KAD > 0.001 */
            if (LW_YAW_KAD > 0.001) {
              /* '<S187>:1:103' [yaw_d_, dot_yaw_ref] = AdmittanceYaw(dm_est(3), yaw, dot_yaw, dt, LW_DMZ0, LW_DMZ_MIN, LW_YAW_KAP, LW_YAW_KAD, 0); */
              profileStart_LW_ctrl_241029_1(36U); /* original_line:5874 */LW_ctrl_241029_1_B.kappa = (real32_T)cos
                (LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]);profileEnd_LW_ctrl_241029_1(36U); /* original_line:5875 */
              profileStart_LW_ctrl_241029_1(37U); /* original_line:5876 */LW_ctrl_241029_1_AdmittanceYaw(LW_ctrl_241029_1_B.d_est_j[2],
                LW_ctrl_241029_1_B.aSinInput, (real32_T)sin
                (LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0]) /
                LW_ctrl_241029_1_B.kappa * LW_ctrl_241029_1_B.y_e[1] + (real32_T)
                cos(LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0]) /
                LW_ctrl_241029_1_B.kappa * LW_ctrl_241029_1_B.y_e[2],
                LW_ctrl_241029_1_B.IntegralGain, LW_DMZ0, LW_DMZ_MIN, LW_YAW_KAP,
                LW_YAW_KAD, 0.0, &LW_ctrl_241029_1_DW.yaw_d_,
                &LW_ctrl_241029_1_B.eta_p);profileEnd_LW_ctrl_241029_1(37U); /* original_line:5884 */

              /* '<S187>:1:104' wbz_ref = dot_yaw_ref*cos(Euler(1))*cos(Euler(2)); */
              /* '<S187>:1:105' wbz_ref = single(0); */
            } else {
              /* '<S187>:1:106' else */
              /* '<S187>:1:107' roll_min = LW_DMZ_MIN; */
              /* '<S187>:1:108' wv_gain = LW_YAW_KAP; */
              /* '<S187>:1:109' roll_exceeding_treshold = single(0); */
              /* '<S187>:1:110' if Euler(1) > roll_min */
              /* '<S187>:1:115' yaw_d_ = yaw; */
              LW_ctrl_241029_1_DW.yaw_d_ = LW_ctrl_241029_1_B.aSinInput;

              /* '<S187>:1:116' wbz_ref = wv_gain*roll_exceeding_treshold; */
            }

            /*              if relaxed_yaw > 0.5 */
            /*                  yaw_d_ = yaw;%悬停状态放宽偏航控制 */
            /*              end */
          } else {
            /* '<S187>:1:121' else */
            /* '<S187>:1:122' [~, ~] = AdmittanceYaw(dm_est(3), yaw, single(0), dt, LW_DMZ0, LW_DMZ_MIN, LW_YAW_KAP, LW_YAW_KAD, 1); */
            profileStart_LW_ctrl_241029_1(34U); /* original_line:5906 */LW_ctrl_241029_1_AdmittanceYaw(LW_ctrl_241029_1_B.d_est_j[2],
              LW_ctrl_241029_1_B.aSinInput, 0.0F,
              LW_ctrl_241029_1_B.IntegralGain, LW_DMZ0, LW_DMZ_MIN, LW_YAW_KAP,
              LW_YAW_KAD, 1.0, &LW_ctrl_241029_1_B.kappa,
              &LW_ctrl_241029_1_B.eta_p);profileEnd_LW_ctrl_241029_1(34U); /* original_line:5910 */

            /* reset */
            /* '<S187>:1:123' yaw_d_ = yaw_d_ + manual_rates_ref(3) * dt; */
            LW_ctrl_241029_1_DW.yaw_d_ += LW_ctrl_241029_1_B.rates_ref[2] *
              LW_ctrl_241029_1_B.IntegralGain;

            /* 前飞状态允许手控偏航 */
          }

          /* '<S187>:1:125' if my_norm(vehicle_vel(1:2)) > 3 && abs(manual_vel_ref(2)) > 0.1 */
          /* 'my_norm:2' x = x(:); */
          /* 'my_norm:3' x_norm = sqrt(x'*x); */
          if (((real32_T)sqrt(LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0] *
                              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0] +
                              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1] *
                              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1]) > 3.0F) &&
              ((real32_T)fabs(LW_ctrl_241029_1_B.vel_ref[1]) > 0.1)) {
            /* '<S187>:1:126' yaw_d_ = yaw; */
            LW_ctrl_241029_1_DW.yaw_d_ = LW_ctrl_241029_1_B.aSinInput;
          }
        } else {
          /* '<S187>:1:128' else */
          /* '<S187>:1:129' yaw_d_ = yaw; */
          LW_ctrl_241029_1_DW.yaw_d_ = LW_ctrl_241029_1_B.aSinInput;

          /* '<S187>:1:130' [~, ~] = AdmittanceYaw(dm_est(3), yaw, single(0), dt, LW_DMZ0, LW_DMZ_MIN, LW_YAW_KAP, LW_YAW_KAD, 1); */
          profileStart_LW_ctrl_241029_1(33U); /* original_line:5937 */LW_ctrl_241029_1_AdmittanceYaw(LW_ctrl_241029_1_B.d_est_j[2],
            LW_ctrl_241029_1_B.aSinInput, 0.0F, LW_ctrl_241029_1_B.IntegralGain,
            LW_DMZ0, LW_DMZ_MIN, LW_YAW_KAP, LW_YAW_KAD, 1.0,
            &LW_ctrl_241029_1_B.kappa, &LW_ctrl_241029_1_B.eta_p);profileEnd_LW_ctrl_241029_1(33U); /* original_line:5940 */

          /* reset */
        }

        /* '<S187>:1:133' if flight_mode == FlightMode.PILOT */
        if (LW_ctrl_241029_1_B.flight_mode == PILOT) {
          /* handle reset */
          /* '<S187>:1:135' if heading_reset_counter_ ~= heading_reset_counter && abs(wrap_pi(yaw_d_ - yaw)) > 0.001 */
          if ((LW_ctrl_241029_1_DW.heading_reset_counter_ !=
               LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.heading_reset_counter)
              && ((real32_T)fabs(LW_ctrl_241029_1_wrap_pi
                                 (LW_ctrl_241029_1_DW.yaw_d_ -
                                  LW_ctrl_241029_1_B.aSinInput)) > 0.001)) {
            /* '<S187>:1:136' yaw_d_ = yaw_d_ + delta_heading; */
            LW_ctrl_241029_1_DW.yaw_d_ +=
              LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.delta_heading;
          }

          /* '<S187>:1:138' yaw_ref = yaw_d_; */
          LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_DW.yaw_d_;
        } else if (LW_ctrl_241029_1_B.flight_mode == OFFBOARD) {
          /* '<S187>:1:139' elseif flight_mode == FlightMode.OFFBOARD */
          /* '<S187>:1:140' yaw_ref = my_quat2yaw(offboard_ref.q,'ZYX'); */
          /* 'my_quat2yaw:2' if isempty(varargin) */
          /* 'my_quat2yaw:5' else */
          /* 'my_quat2yaw:6' euler = my_quat2eul(q, convertStringsToChars(varargin{1})); */
          /* 'my_quat2yaw:9' yaw = euler(3); */
          profileStart_LW_ctrl_241029_1(38U); /* original_line:5968 */LW_ctrl_241029_1_my_quat2eul(LW_ctrl_241029_1_B.q,
            LW_ctrl_241029_1_B.vel_ref_c);profileEnd_LW_ctrl_241029_1(38U); /* original_line:5969 */
          LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.vel_ref_c[2];

          /* 已经经过了reset补偿 */
        } else {
          /* '<S187>:1:141' else */
          /* '<S187>:1:142' yaw_ref = yaw_d_; */
          LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_DW.yaw_d_;
        }

        /* 限定偏航角的最大角度率 */
        /* '<S187>:1:146' LW_WZ_MAX_RAD = LW_WZ_MAX * pi / 180; */
        /* yaw_ref = limit_yaw(yaw_ref, dt, LW_WZ_MAX_RAD, arm); */
        /* '<S187>:1:149' Rbe_psi = [ cos(yaw_d_) sin(yaw_d_) 0; */
        /* '<S187>:1:150'         -sin(yaw_d_) cos(yaw_d_) 0; */
        /* '<S187>:1:151'         0        0        1]; */
        profileStart_LW_ctrl_241029_1(39U); /* original_line:5985 */LW_ctrl_241029_1_B.kappa = (real32_T)sin(LW_ctrl_241029_1_DW.yaw_d_);profileEnd_LW_ctrl_241029_1(39U); /* original_line:5985 */
        profileStart_LW_ctrl_241029_1(40U); /* original_line:5986 */LW_ctrl_241029_1_B.eta_p = (real32_T)cos(LW_ctrl_241029_1_DW.yaw_d_);profileEnd_LW_ctrl_241029_1(40U); /* original_line:5986 */
        LW_ctrl_241029_1_B.Rbe_psi[0] = LW_ctrl_241029_1_B.eta_p;
        LW_ctrl_241029_1_B.Rbe_psi[3] = LW_ctrl_241029_1_B.kappa;
        LW_ctrl_241029_1_B.Rbe_psi[6] = 0.0F;
        LW_ctrl_241029_1_B.Rbe_psi[1] = -LW_ctrl_241029_1_B.kappa;
        LW_ctrl_241029_1_B.Rbe_psi[4] = LW_ctrl_241029_1_B.eta_p;
        LW_ctrl_241029_1_B.Rbe_psi[7] = 0.0F;
        LW_ctrl_241029_1_B.Rbe_psi[2] = 0.0F;
        LW_ctrl_241029_1_B.Rbe_psi[5] = 0.0F;
        LW_ctrl_241029_1_B.Rbe_psi[8] = 1.0F;

        /*     %% select reference data */
        /* '<S187>:1:154' if flight_mode == FlightMode.PILOT && (notInfNan(vehicle_pos) && notInfNan(vehicle_vel) && notInfNan(manual_vel_ref)) */
        if ((LW_ctrl_241029_1_B.flight_mode == PILOT) &&
            LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.sf_nan_inf.y) &&
            LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.sf_nan_inf1_f.y) &&
            LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.vel_ref)) {
          /* '<S187>:1:155' vehicle_vel_psi = Rbe_psi*vehicle_vel; */
          LW_ctrl_241029_1_B.kappa = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];
          LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
          LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2];
          for (i = 0; i < 3; i++) {
            LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[i] =
              (LW_ctrl_241029_1_B.Rbe_psi[i + 3] * LW_ctrl_241029_1_B.kappa +
               LW_ctrl_241029_1_B.Rbe_psi[i] * LW_ctrl_241029_1_B.theta) +
              LW_ctrl_241029_1_B.Rbe_psi[i + 6] *
              LW_ctrl_241029_1_B.time_to_stop;
          }

          /* '<S187>:1:156' if ctrl_mode == ControlMode.STABILIZED || ctrl_mode == ControlMode.ACRO || ctrl_mode == ControlMode.MANUAL */
          if ((LW_ctrl_241029_1_B.ctrl_mode == STABILIZED) ||
              (LW_ctrl_241029_1_B.ctrl_mode == ACRO) ||
              (LW_ctrl_241029_1_B.ctrl_mode == MANUAL)) {
            /* '<S187>:1:157' pos_x1 = vehicle_pos(1); */
            LW_ctrl_241029_1_DW.pos_x1 = LW_ctrl_241029_1_B.sf_nan_inf.y[0];

            /* '<S187>:1:157' pos_y1 = vehicle_pos(2); */
            LW_ctrl_241029_1_DW.pos_y1 = LW_ctrl_241029_1_B.sf_nan_inf.y[1];

            /* '<S187>:1:157' pos_z1 = vehicle_pos(3); */
            LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_B.sf_nan_inf.y[2];

            /* '<S187>:1:158' hold_pxy = vehicle_pos(1:2); */
            /* '<S187>:1:158' hold_pz = vehicle_pos(3); */
            LW_ctrl_241029_1_DW.hold_pz = LW_ctrl_241029_1_B.sf_nan_inf.y[2];

            /* '<S187>:1:159' hold_vxy = vehicle_vel(1:2); */
            LW_ctrl_241029_1_DW.hold_pxy[0] = LW_ctrl_241029_1_B.sf_nan_inf.y[0];
            LW_ctrl_241029_1_DW.hold_vxy[0] =
              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
            LW_ctrl_241029_1_DW.hold_pxy[1] = LW_ctrl_241029_1_B.sf_nan_inf.y[1];
            LW_ctrl_241029_1_DW.hold_vxy[1] =
              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];

            /* '<S187>:1:159' hold_vz = vehicle_vel(3); */
            LW_ctrl_241029_1_DW.hold_vz = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2];

            /* '<S187>:1:160' hold_z_flag = false; */
            LW_ctrl_241029_1_DW.hold_z_flag = false;

            /* '<S187>:1:160' hold_xy_flag = false; */
            LW_ctrl_241029_1_DW.hold_xy_flag = false;

            /* '<S187>:1:161' hold_xy_timestamp = timestamp; */
            LW_ctrl_241029_1_DW.hold_xy_timestamp =
              LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

            /* '<S187>:1:161' hold_z_timestamp = timestamp; */
            LW_ctrl_241029_1_DW.hold_z_timestamp =
              LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

            /* '<S187>:1:162' vx_d = vehicle_vel_psi(1); */
            LW_ctrl_241029_1_B.kappa =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];

            /* '<S187>:1:162' vy_d = vehicle_vel_psi(2); */
            LW_ctrl_241029_1_B.eta_p =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];

            /* '<S187>:1:162' vz_d = vehicle_vel_psi(3); */
            LW_ctrl_241029_1_B.theta =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2];
          } else if (LW_ctrl_241029_1_B.ctrl_mode == ALTITUDE) {
            /* '<S187>:1:163' elseif ctrl_mode == ControlMode.ALTITUDE */
            /* '<S187>:1:164' pos_x1 = vehicle_pos(1); */
            LW_ctrl_241029_1_DW.pos_x1 = LW_ctrl_241029_1_B.sf_nan_inf.y[0];

            /* '<S187>:1:164' pos_y1 = vehicle_pos(2); */
            LW_ctrl_241029_1_DW.pos_y1 = LW_ctrl_241029_1_B.sf_nan_inf.y[1];

            /* '<S187>:1:165' hold_pxy = vehicle_pos(1:2); */
            /* '<S187>:1:166' hold_vxy = vehicle_vel(1:2); */
            LW_ctrl_241029_1_DW.hold_pxy[0] = LW_ctrl_241029_1_B.sf_nan_inf.y[0];
            LW_ctrl_241029_1_DW.hold_vxy[0] =
              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
            LW_ctrl_241029_1_DW.hold_pxy[1] = LW_ctrl_241029_1_B.sf_nan_inf.y[1];
            LW_ctrl_241029_1_DW.hold_vxy[1] =
              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];

            /* '<S187>:1:167' hold_xy_flag = false; */
            LW_ctrl_241029_1_DW.hold_xy_flag = false;

            /* '<S187>:1:168' hold_xy_timestamp = timestamp; */
            LW_ctrl_241029_1_DW.hold_xy_timestamp =
              LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

            /* '<S187>:1:169' vx_d = vehicle_vel_psi(1); */
            LW_ctrl_241029_1_B.kappa =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];

            /* '<S187>:1:169' vy_d = vehicle_vel_psi(2); */
            LW_ctrl_241029_1_B.eta_p =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];

            /* 判断是否需要定高 */
            /* '<S187>:1:171' if abs(manual_vel_ref(3)) < 0.001 && abs(vehicle_vel(3)) <= 0.8 */
            if (((real32_T)fabs(LW_ctrl_241029_1_B.vel_ref[2]) < 0.001) &&
                ((real32_T)fabs(LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2]) <= 0.8))
            {
              /* '<S187>:1:172' want_hold_z = true; */
              want_hold_z = true;
            } else {
              /* '<S187>:1:173' else */
              /* '<S187>:1:174' want_hold_z = false; */
              want_hold_z = false;

              /* '<S187>:1:175' hold_z_flag = false; */
              LW_ctrl_241029_1_DW.hold_z_flag = false;

              /* '<S187>:1:176' hold_z_timestamp = timestamp; */
              LW_ctrl_241029_1_DW.hold_z_timestamp =
                LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

              /* '<S187>:1:177' hold_vz = vehicle_vel(3); */
              LW_ctrl_241029_1_DW.hold_vz = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2];

              /* '<S187>:1:178' hold_pz = vehicle_pos(3); */
              LW_ctrl_241029_1_DW.hold_pz = LW_ctrl_241029_1_B.sf_nan_inf.y[2];
            }

            /* '<S187>:1:181' if (want_hold_z) && (~hold_z_flag) */
            if (want_hold_z && (!LW_ctrl_241029_1_DW.hold_z_flag)) {
              /* 加入最大加速度限制 */
              /* '<S187>:1:183' time_to_stop = my_norm(hold_vz)/lw_acc_z_max; */
              /* 'my_norm:2' x = x(:); */
              /* 'my_norm:3' x_norm = sqrt(x'*x); */
              profileStart_LW_ctrl_241029_1(43U); /* original_line:6132 */LW_ctrl_241029_1_B.time_to_stop = (real32_T)sqrt
                (LW_ctrl_241029_1_DW.hold_vz * LW_ctrl_241029_1_DW.hold_vz) /
                3.0F;profileEnd_LW_ctrl_241029_1(43U); /* original_line:6134 */

              /* '<S187>:1:184' delta_t = single((timestamp - hold_z_timestamp)*1e-6); */
              LW_ctrl_241029_1_B.delta_t = (real32_T)
                ((LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp -
                  LW_ctrl_241029_1_DW.hold_z_timestamp) * 1.0E-6);

              /* '<S187>:1:185' if delta_t > time_to_stop */
              if (LW_ctrl_241029_1_B.delta_t > LW_ctrl_241029_1_B.time_to_stop)
              {
                /* '<S187>:1:186' delta_t = time_to_stop; */
                LW_ctrl_241029_1_B.delta_t = LW_ctrl_241029_1_B.time_to_stop;

                /* '<S187>:1:187' hold_z_flag = true; */
                LW_ctrl_241029_1_DW.hold_z_flag = true;
              }

              /* '<S187>:1:189' pos_z1 = hold_pz + hold_vz*delta_t; */
              LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_DW.hold_vz *
                LW_ctrl_241029_1_B.delta_t + LW_ctrl_241029_1_DW.hold_pz;
            }

            /* '<S187>:1:192' if ~want_hold_z */
            if (!want_hold_z) {
              /* '<S187>:1:193' pos_z1 = vehicle_pos(3); */
              LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_B.sf_nan_inf.y[2];

              /* '<S187>:1:194' hold_z_flag = false; */
              LW_ctrl_241029_1_DW.hold_z_flag = false;
            }

            /* '<S187>:1:196' vz_d = manual_vel_ref(3); */
            LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_B.vel_ref[2];
          } else {
            /* '<S187>:1:197' else */
            /* position mode */
            /* '<S187>:1:198' if abs(manual_vel_ref(1)) < 0.001 && abs(vehicle_vel_psi(1)) <= 0.8 && ... */
            /* '<S187>:1:199'                     abs(manual_vel_ref(2)) < 0.001 && abs(vehicle_vel_psi(2)) <= 0.8 */
            if (((real32_T)fabs(LW_ctrl_241029_1_B.vel_ref[0]) < 0.001) &&
                ((real32_T)fabs(LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0])
                 <= 0.8) && ((real32_T)fabs(LW_ctrl_241029_1_B.vel_ref[1]) <
                             0.001) && ((real32_T)fabs
                 (LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) <= 0.8)) {
              /* '<S187>:1:200' want_hold_xy = true; */
              want_hold_xy = true;
            } else {
              /* '<S187>:1:201' else */
              /* '<S187>:1:202' want_hold_xy = false; */
              want_hold_xy = false;

              /* '<S187>:1:202' hold_xy_flag = false; */
              LW_ctrl_241029_1_DW.hold_xy_flag = false;

              /* '<S187>:1:203' hold_xy_timestamp = timestamp; */
              LW_ctrl_241029_1_DW.hold_xy_timestamp =
                LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

              /* '<S187>:1:204' hold_vxy = vehicle_vel(1:2); */
              /* '<S187>:1:205' hold_pxy = vehicle_pos(1:2); */
              LW_ctrl_241029_1_DW.hold_vxy[0] =
                LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
              LW_ctrl_241029_1_DW.hold_pxy[0] = LW_ctrl_241029_1_B.sf_nan_inf.y
                [0];
              LW_ctrl_241029_1_DW.hold_vxy[1] =
                LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];
              LW_ctrl_241029_1_DW.hold_pxy[1] = LW_ctrl_241029_1_B.sf_nan_inf.y
                [1];
            }

            /* '<S187>:1:207' if abs(manual_vel_ref(3)) < 0.001 && abs(vehicle_vel(3)) <= 0.8 */
            if (((real32_T)fabs(LW_ctrl_241029_1_B.vel_ref[2]) < 0.001) &&
                ((real32_T)fabs(LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2]) <= 0.8))
            {
              /* '<S187>:1:208' want_hold_z = true; */
              want_hold_z = true;
            } else {
              /* '<S187>:1:209' else */
              /* '<S187>:1:210' want_hold_z = false; */
              want_hold_z = false;

              /* '<S187>:1:211' hold_z_flag = false; */
              LW_ctrl_241029_1_DW.hold_z_flag = false;

              /* '<S187>:1:212' hold_z_timestamp = timestamp; */
              LW_ctrl_241029_1_DW.hold_z_timestamp =
                LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

              /* '<S187>:1:213' hold_vz = vehicle_vel(3); */
              LW_ctrl_241029_1_DW.hold_vz = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2];

              /* '<S187>:1:214' hold_pz = vehicle_pos(3); */
              LW_ctrl_241029_1_DW.hold_pz = LW_ctrl_241029_1_B.sf_nan_inf.y[2];
            }

            /* '<S187>:1:217' vx_d = manual_vel_ref(1); */
            LW_ctrl_241029_1_B.kappa = LW_ctrl_241029_1_B.vel_ref[0];

            /* '<S187>:1:217' vy_d = manual_vel_ref(2); */
            LW_ctrl_241029_1_B.eta_p = LW_ctrl_241029_1_B.vel_ref[1];

            /* '<S187>:1:218' vz_d = manual_vel_ref(3); */
            LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_B.vel_ref[2];

            /* 对手动期望速度进行平滑 */
            /*              [vd_smoothed, ~] = TD_3DVector([vx_d;vy_d;vz_d], [lw_acc_xy_max;lw_acc_xy_max;lw_acc_z_max]*1.2, dt); */
            /*              vx_d = vd_smoothed(1); */
            /*              vy_d = vd_smoothed(2); */
            /*              vz_d = vd_smoothed(3); */
            /* 让期望位置保持进入定点那刻的位置 */
            /* '<S187>:1:225' if (want_hold_xy) && (~hold_xy_flag) */
            if (want_hold_xy && (!LW_ctrl_241029_1_DW.hold_xy_flag)) {
              /* 加入最大加速度限制 */
              /* '<S187>:1:227' v0_xy = my_norm(hold_vxy(1:2)); */
              /* 'my_norm:2' x = x(:); */
              /* 'my_norm:3' x_norm = sqrt(x'*x); */
              /* '<S187>:1:228' time_to_stop = v0_xy/lw_acc_xy_max; */
              profileStart_LW_ctrl_241029_1(41U); /* original_line:6250 */LW_ctrl_241029_1_B.time_to_stop = (real32_T)sqrt
                (LW_ctrl_241029_1_DW.hold_vxy[0] * LW_ctrl_241029_1_DW.hold_vxy
                 [0] + LW_ctrl_241029_1_DW.hold_vxy[1] *
                 LW_ctrl_241029_1_DW.hold_vxy[1]) / LW_Y_ACCEL_MAX;profileEnd_LW_ctrl_241029_1(41U); /* original_line:6253 */

              /* '<S187>:1:229' delta_t = single((timestamp - hold_xy_timestamp)*1e-6); */
              LW_ctrl_241029_1_B.delta_t = (real32_T)
                ((LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp -
                  LW_ctrl_241029_1_DW.hold_xy_timestamp) * 1.0E-6);

              /* '<S187>:1:230' if delta_t > time_to_stop */
              if (LW_ctrl_241029_1_B.delta_t > LW_ctrl_241029_1_B.time_to_stop)
              {
                /* '<S187>:1:231' delta_t = time_to_stop; */
                LW_ctrl_241029_1_B.delta_t = LW_ctrl_241029_1_B.time_to_stop;

                /* '<S187>:1:232' hold_xy_flag = true; */
                LW_ctrl_241029_1_DW.hold_xy_flag = true;
              }

              /* '<S187>:1:235' pos_x1 = hold_pxy(1) + hold_vxy(1)*delta_t; */
              LW_ctrl_241029_1_DW.pos_x1 = LW_ctrl_241029_1_DW.hold_vxy[0] *
                LW_ctrl_241029_1_B.delta_t + LW_ctrl_241029_1_DW.hold_pxy[0];

              /* '<S187>:1:236' pos_y1 = hold_pxy(2) + hold_vxy(2)*delta_t; */
              LW_ctrl_241029_1_DW.pos_y1 = LW_ctrl_241029_1_DW.hold_vxy[1] *
                LW_ctrl_241029_1_B.delta_t + LW_ctrl_241029_1_DW.hold_pxy[1];

              /*                  delta_vxy = v0_xy - lw_acc_xy_max*delta_t; */
              /*                  delta_pxy = v0_xy*delta_t - 0.5*lw_acc_xy_max*delta_t^2; */
              /*                  pos_x1 = hold_pxy(1) + delta_pxy*cos(yaw_d_); */
              /*                  pos_y1 = hold_pxy(2) + delta_pxy*sin(yaw_d_); */
              /* 直接停住 */
              /*                      x1 = vehicle_pos(1); y1 = vehicle_pos(2); */
              /*                      hold_xy_flag = true; */
            }

            /*  throttle in the middle position, hold the height */
            /* '<S187>:1:249' if (want_hold_z) && (~hold_z_flag) */
            if (want_hold_z && (!LW_ctrl_241029_1_DW.hold_z_flag)) {
              /* 加入最大加速度限制 */
              /* '<S187>:1:251' time_to_stop = my_norm(hold_vz)/lw_acc_z_max; */
              /* 'my_norm:2' x = x(:); */
              /* 'my_norm:3' x_norm = sqrt(x'*x); */
              profileStart_LW_ctrl_241029_1(42U); /* original_line:6294 */LW_ctrl_241029_1_B.time_to_stop = (real32_T)sqrt
                (LW_ctrl_241029_1_DW.hold_vz * LW_ctrl_241029_1_DW.hold_vz) /
                3.0F;profileEnd_LW_ctrl_241029_1(42U); /* original_line:6296 */

              /* '<S187>:1:252' delta_t = single((timestamp - hold_xy_timestamp)*1e-6); */
              LW_ctrl_241029_1_B.delta_t = (real32_T)
                ((LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp -
                  LW_ctrl_241029_1_DW.hold_xy_timestamp) * 1.0E-6);

              /* '<S187>:1:253' if delta_t > time_to_stop */
              if (LW_ctrl_241029_1_B.delta_t > LW_ctrl_241029_1_B.time_to_stop)
              {
                /* '<S187>:1:254' delta_t = time_to_stop; */
                LW_ctrl_241029_1_B.delta_t = LW_ctrl_241029_1_B.time_to_stop;

                /* '<S187>:1:255' hold_z_flag = true; */
                LW_ctrl_241029_1_DW.hold_z_flag = true;
              }

              /* '<S187>:1:257' pos_z1 = hold_pz + hold_vz*delta_t; */
              LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_DW.hold_vz *
                LW_ctrl_241029_1_B.delta_t + LW_ctrl_241029_1_DW.hold_pz;
            }

            /* When the RC sticks(CH1, CH2, CH3, CH4) deviate from the middle dead zone range, the position is the current position. */
            /* The position controller only works with the velocity loop */
            /* '<S187>:1:261' if ~want_hold_xy */
            if (!want_hold_xy) {
              /* '<S187>:1:262' pos_x1 = vehicle_pos(1); */
              LW_ctrl_241029_1_DW.pos_x1 = LW_ctrl_241029_1_B.sf_nan_inf.y[0];

              /* '<S187>:1:262' pos_y1 = vehicle_pos(2); */
              LW_ctrl_241029_1_DW.pos_y1 = LW_ctrl_241029_1_B.sf_nan_inf.y[1];

              /* '<S187>:1:263' hold_xy_flag = false; */
              LW_ctrl_241029_1_DW.hold_xy_flag = false;
            }

            /* '<S187>:1:265' if ~want_hold_z */
            if (!want_hold_z) {
              /* '<S187>:1:266' pos_z1 = vehicle_pos(3); */
              LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_B.sf_nan_inf.y[2];

              /* '<S187>:1:266' hold_z_flag = false; */
              LW_ctrl_241029_1_DW.hold_z_flag = false;
            }
          }

          /* '<S187>:1:270' vel_ref = [vx_d; vy_d; vz_d]; */
          LW_ctrl_241029_1_B.vel_ref_kk[0] = LW_ctrl_241029_1_B.kappa;
          LW_ctrl_241029_1_B.vel_ref_kk[1] = LW_ctrl_241029_1_B.eta_p;
          LW_ctrl_241029_1_B.vel_ref_kk[2] = LW_ctrl_241029_1_B.theta;

          /* 航向坐标系下的期望速度 */
          /* '<S187>:1:271' pos_ref = [pos_x1; pos_y1; pos_z1]; */
          LW_ctrl_241029_1_B.pos_ref_lq[0] = LW_ctrl_241029_1_DW.pos_x1;
          LW_ctrl_241029_1_B.pos_ref_lq[1] = LW_ctrl_241029_1_DW.pos_y1;
          LW_ctrl_241029_1_B.pos_ref_lq[2] = LW_ctrl_241029_1_DW.pos_z1;

          /*  状态reset处理 */
          /* '<S187>:1:274' delta_v = Rbe_psi *[delta_vxy;delta_vz]; */
          LW_ctrl_241029_1_B.time_to_stop =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.delta_vxy[0];
          LW_ctrl_241029_1_B.T1 =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.delta_vxy[1];
          for (i = 0; i < 3; i++) {
            LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[i] =
              (LW_ctrl_241029_1_B.Rbe_psi[i + 3] * LW_ctrl_241029_1_B.T1 +
               LW_ctrl_241029_1_B.Rbe_psi[i] * LW_ctrl_241029_1_B.time_to_stop)
              + LW_ctrl_241029_1_B.Rbe_psi[i + 6] *
              LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.delta_vz;
          }

          /* '<S187>:1:275' if vxy_reset_counter_ ~= vxy_reset_counter && my_norm(vel_ref(1:2) - vehicle_vel(1:2)) > 0.001 */
          if (LW_ctrl_241029_1_DW.vxy_reset_counter_ !=
              LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vxy_reset_counter)
          {
            /* 'my_norm:2' x = x(:); */
            /* 'my_norm:3' x_norm = sqrt(x'*x); */
            LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.kappa -
              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
            LW_ctrl_241029_1_B.delta_t = LW_ctrl_241029_1_B.time_to_stop *
              LW_ctrl_241029_1_B.time_to_stop;
            LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.eta_p -
              LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];
            if ((real32_T)sqrt(LW_ctrl_241029_1_B.time_to_stop *
                               LW_ctrl_241029_1_B.time_to_stop +
                               LW_ctrl_241029_1_B.delta_t) > 0.001) {
              /* '<S187>:1:276' vel_ref(1:2) = vel_ref(1:2) + delta_v(1:2); */
              LW_ctrl_241029_1_B.vel_ref_kk[0] = LW_ctrl_241029_1_B.kappa +
                LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];
              LW_ctrl_241029_1_B.vel_ref_kk[1] = LW_ctrl_241029_1_B.eta_p +
                LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];
            }
          }

          /* '<S187>:1:278' if vz_reset_counter_ ~= vz_reset_counter && abs(vel_ref(3) - vehicle_vel(3)) > 0.001 */
          if ((LW_ctrl_241029_1_DW.vz_reset_counter_ !=
               LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vz_reset_counter)
              && ((real32_T)fabs(LW_ctrl_241029_1_B.theta -
                                 LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2]) > 0.001))
          {
            /* '<S187>:1:279' vel_ref(3) = vel_ref(3) +  delta_v(3); */
            LW_ctrl_241029_1_B.vel_ref_kk[2] = LW_ctrl_241029_1_B.theta +
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2];
          }

          /* '<S187>:1:281' if xy_reset_counter_ ~= xy_reset_counter && my_norm(pos_ref(1:2) - vehicle_pos(1:2)) > 0.001 */
          if (LW_ctrl_241029_1_DW.xy_reset_counter_ !=
              LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.xy_reset_counter)
          {
            /* 'my_norm:2' x = x(:); */
            /* 'my_norm:3' x_norm = sqrt(x'*x); */
            LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.pos_ref_lq[0] -
              LW_ctrl_241029_1_B.sf_nan_inf.y[0];
            LW_ctrl_241029_1_B.delta_t = LW_ctrl_241029_1_B.time_to_stop *
              LW_ctrl_241029_1_B.time_to_stop;
            LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.pos_ref_lq[1] -
              LW_ctrl_241029_1_B.sf_nan_inf.y[1];
            if ((real32_T)sqrt(LW_ctrl_241029_1_B.time_to_stop *
                               LW_ctrl_241029_1_B.time_to_stop +
                               LW_ctrl_241029_1_B.delta_t) > 0.001) {
              /* '<S187>:1:282' pos_ref(1:2) = pos_ref(1:2) + delta_xy; */
              LW_ctrl_241029_1_B.pos_ref_lq[0] +=
                LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.delta_xy[0];
              LW_ctrl_241029_1_B.pos_ref_lq[1] +=
                LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.delta_xy[1];

              /* '<S187>:1:283' pos_x1 = pos_ref(1); */
              LW_ctrl_241029_1_DW.pos_x1 = LW_ctrl_241029_1_B.pos_ref_lq[0];

              /* '<S187>:1:284' pos_y1 = pos_ref(2); */
              LW_ctrl_241029_1_DW.pos_y1 = LW_ctrl_241029_1_B.pos_ref_lq[1];
            }
          }

          /* '<S187>:1:286' if z_reset_counter_ ~= z_reset_counter && abs(pos_ref(3) - vehicle_pos(3)) > 0.001 */
          if ((LW_ctrl_241029_1_DW.z_reset_counter_ !=
               LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.z_reset_counter) &&
              ((real32_T)fabs(LW_ctrl_241029_1_B.pos_ref_lq[2] -
                              LW_ctrl_241029_1_B.sf_nan_inf.y[2]) > 0.001)) {
            /* '<S187>:1:287' pos_ref(3) = pos_ref(3) + delta_z; */
            LW_ctrl_241029_1_B.pos_ref_lq[2] +=
              LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.delta_z;

            /* '<S187>:1:288' pos_z1 = pos_ref(3); */
            LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_B.pos_ref_lq[2];
          }

          /* '<S187>:1:290' xy_reset_counter_ = xy_reset_counter; */
          LW_ctrl_241029_1_DW.xy_reset_counter_ =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.xy_reset_counter;

          /* '<S187>:1:291' z_reset_counter_ = z_reset_counter; */
          LW_ctrl_241029_1_DW.z_reset_counter_ =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.z_reset_counter;

          /* '<S187>:1:292' vxy_reset_counter_ = vxy_reset_counter; */
          LW_ctrl_241029_1_DW.vxy_reset_counter_ =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vxy_reset_counter;

          /* '<S187>:1:293' vz_reset_counter_ = vz_reset_counter; */
          LW_ctrl_241029_1_DW.vz_reset_counter_ =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vz_reset_counter;

          /* '<S187>:1:294' heading_reset_counter_ = heading_reset_counter; */
          LW_ctrl_241029_1_DW.heading_reset_counter_ =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.heading_reset_counter;

          /*  */
          /*      elseif flight_mode == FlightMode.AUTO && notInfNan(vehicle_pos) % auto */
          /*          dubins = auto_ref.dubins; */
          /*          pos_ref = [vehicle_pos(1 : 2); -non_manual_ref.current.alt]; */
          /*          vel_ref = [non_manual_ref.current.cruising_speed; 0; 0]; */
          /*          x1 = vehicle_pos(1); y1 = vehicle_pos(2); z1 = vehicle_pos(3); */
          /*          if ctrl_mode == ControlMode.LOITER && (notInfNan(non_manual_ref.current.pos) && notInfNan(non_manual_ref.current.vel)) */
          /*              pos_ref = non_manual_ref.current.pos; */
          /*              vel_ref = non_manual_ref.current.vel; */
          /*          end */
        } else if ((LW_ctrl_241029_1_B.flight_mode == OFFBOARD) &&
                   LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.sf_nan_inf.y))
        {
          /* '<S187>:1:305' elseif flight_mode == FlightMode.OFFBOARD && (notInfNan(vehicle_pos)) */
          /*  offboard */
          /* '<S187>:1:306' if notInfNan(offboard_ref.pos) */
          if (LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.pos)) {
            /* '<S187>:1:307' pos_ref = offboard_ref.pos; */
            LW_ctrl_241029_1_B.pos_ref_lq[0] = LW_ctrl_241029_1_B.pos[0];
            LW_ctrl_241029_1_B.pos_ref_lq[1] = LW_ctrl_241029_1_B.pos[1];
            LW_ctrl_241029_1_B.pos_ref_lq[2] = LW_ctrl_241029_1_B.pos[2];
          } else {
            /* '<S187>:1:308' else */
            /* '<S187>:1:309' pos_ref = vehicle_pos; */
            LW_ctrl_241029_1_B.pos_ref_lq[0] = LW_ctrl_241029_1_B.sf_nan_inf.y[0];
            LW_ctrl_241029_1_B.pos_ref_lq[1] = LW_ctrl_241029_1_B.sf_nan_inf.y[1];
            LW_ctrl_241029_1_B.pos_ref_lq[2] = LW_ctrl_241029_1_B.sf_nan_inf.y[2];
          }

          /* '<S187>:1:311' if notInfNan(offboard_ref.vel) */
          if (LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.vel)) {
            /* '<S187>:1:312' vel_ref = offboard_ref.vel; */
            LW_ctrl_241029_1_B.vel_ref_kk[0] = LW_ctrl_241029_1_B.vel[0];
            LW_ctrl_241029_1_B.vel_ref_kk[1] = LW_ctrl_241029_1_B.vel[1];
            LW_ctrl_241029_1_B.vel_ref_kk[2] = LW_ctrl_241029_1_B.vel[2];
          } else {
            /* '<S187>:1:313' else */
            /* '<S187>:1:314' vel_ref = zeros(3,1,'single'); */
            LW_ctrl_241029_1_B.vel_ref_kk[0] = 0.0F;
            LW_ctrl_241029_1_B.vel_ref_kk[1] = 0.0F;
            LW_ctrl_241029_1_B.vel_ref_kk[2] = 0.0F;
          }

          /* '<S187>:1:317' pos_x1 = vehicle_pos(1); */
          LW_ctrl_241029_1_DW.pos_x1 = LW_ctrl_241029_1_B.sf_nan_inf.y[0];

          /* '<S187>:1:317' pos_y1 = vehicle_pos(2); */
          LW_ctrl_241029_1_DW.pos_y1 = LW_ctrl_241029_1_B.sf_nan_inf.y[1];

          /* '<S187>:1:317' pos_z1 = vehicle_pos(3); */
          LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_B.sf_nan_inf.y[2];

          /* '<S187>:1:318' hold_pxy = vehicle_pos(1:2); */
          /* '<S187>:1:318' hold_pz = vehicle_pos(3); */
          LW_ctrl_241029_1_DW.hold_pz = LW_ctrl_241029_1_B.sf_nan_inf.y[2];

          /* '<S187>:1:319' hold_vxy = vehicle_vel(1:2); */
          LW_ctrl_241029_1_DW.hold_pxy[0] = LW_ctrl_241029_1_B.sf_nan_inf.y[0];
          LW_ctrl_241029_1_DW.hold_vxy[0] = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
          LW_ctrl_241029_1_DW.hold_pxy[1] = LW_ctrl_241029_1_B.sf_nan_inf.y[1];
          LW_ctrl_241029_1_DW.hold_vxy[1] = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];

          /* '<S187>:1:319' hold_vz = vehicle_vel(3); */
          LW_ctrl_241029_1_DW.hold_vz = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2];

          /* '<S187>:1:320' hold_z_flag = false; */
          LW_ctrl_241029_1_DW.hold_z_flag = false;

          /* '<S187>:1:320' hold_xy_flag = false; */
          LW_ctrl_241029_1_DW.hold_xy_flag = false;

          /* '<S187>:1:321' hold_xy_timestamp = timestamp; */
          LW_ctrl_241029_1_DW.hold_xy_timestamp =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

          /* '<S187>:1:321' hold_z_timestamp = timestamp; */
          LW_ctrl_241029_1_DW.hold_z_timestamp =
            LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;
        } else {
          /* '<S187>:1:322' else */
          /* '<S187>:1:323' vel_ref = single([0; 0; 0]); */
          LW_ctrl_241029_1_B.vel_ref_kk[0] = 0.0F;
          LW_ctrl_241029_1_B.vel_ref_kk[1] = 0.0F;
          LW_ctrl_241029_1_B.vel_ref_kk[2] = 0.0F;

          /* '<S187>:1:324' pos_ref = [pos_x1; pos_y1; pos_z1]; */
          LW_ctrl_241029_1_B.pos_ref_lq[0] = LW_ctrl_241029_1_DW.pos_x1;
          LW_ctrl_241029_1_B.pos_ref_lq[1] = LW_ctrl_241029_1_DW.pos_y1;
          LW_ctrl_241029_1_B.pos_ref_lq[2] = LW_ctrl_241029_1_DW.pos_z1;
        }

        /*     %% position control */
        /* '<S187>:1:329' vel_fb = (pos_ref - vehicle_pos).* [LW_X_P; LW_Y_P; LW_Z_P]; */
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] =
          (LW_ctrl_241029_1_B.pos_ref_lq[0] - LW_ctrl_241029_1_B.sf_nan_inf.y[0])
          * LW_X_P;
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] =
          (LW_ctrl_241029_1_B.pos_ref_lq[1] - LW_ctrl_241029_1_B.sf_nan_inf.y[1])
          * LW_Y_P;
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2] =
          (LW_ctrl_241029_1_B.pos_ref_lq[2] - LW_ctrl_241029_1_B.sf_nan_inf.y[2])
          * LW_Z_P;

        /* '<S187>:1:330' vd_psi = Rbe_psi *vel_fb + vel_ref; */
        LW_ctrl_241029_1_B.kappa =
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];
        LW_ctrl_241029_1_B.theta =
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];
        LW_ctrl_241029_1_B.time_to_stop =
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2];
        for (i = 0; i < 3; i++) {
          LW_ctrl_241029_1_B.vd_psi[i] = ((LW_ctrl_241029_1_B.Rbe_psi[i + 3] *
            LW_ctrl_241029_1_B.kappa + LW_ctrl_241029_1_B.Rbe_psi[i] *
            LW_ctrl_241029_1_B.theta) + LW_ctrl_241029_1_B.Rbe_psi[i + 6] *
            LW_ctrl_241029_1_B.time_to_stop) + LW_ctrl_241029_1_B.vel_ref_kk[i];
        }

        /* 手控模式下参考速度vel_ref是航向坐标系下的 */
        /* '<S187>:1:331' if flight_mode == FlightMode.AUTO */
        if (LW_ctrl_241029_1_B.flight_mode == AUTO) {
          /* not used, replaced by the L1 in PX4 */
          /* '<S187>:1:332' if vel_ref(2) < 1e-3 */
          if (LW_ctrl_241029_1_B.vel_ref_kk[1] < 0.001) {
            /* '<S187>:1:333' vd_psi(2) = vel_fb(2); */
            LW_ctrl_241029_1_B.vd_psi[1] =
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];
          } else {
            /* '<S187>:1:334' else */
            /* 对圆轨迹跟踪，d为半径误差 */
            /* '<S187>:1:336' vd_psi(2) = single(LW_LAT_CIRCLE * vel_ref(2)); */
            LW_ctrl_241029_1_B.vd_psi[1] = LW_LAT_CIRCLE *
              LW_ctrl_241029_1_B.vel_ref_kk[1];
          }
        }

        /* '<S187>:1:340' vd_lim = Rbe_psi'*vd_psi; */
        for (i = 0; i < 3; i++) {
          LW_ctrl_241029_1_B.vd_lim_tmp[3 * i] = LW_ctrl_241029_1_B.Rbe_psi[i];
          LW_ctrl_241029_1_B.vd_lim_tmp[3 * i + 1] =
            LW_ctrl_241029_1_B.Rbe_psi[i + 3];
          LW_ctrl_241029_1_B.vd_lim_tmp[3 * i + 2] =
            LW_ctrl_241029_1_B.Rbe_psi[i + 6];
        }

        LW_ctrl_241029_1_B.kappa = LW_ctrl_241029_1_B.vd_psi[1];
        LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_B.vd_psi[0];
        LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.vd_psi[2];
        for (i = 0; i < 3; i++) {
          LW_ctrl_241029_1_B.z3_[i] = (LW_ctrl_241029_1_B.vd_lim_tmp[i + 3] *
            LW_ctrl_241029_1_B.kappa + LW_ctrl_241029_1_B.vd_lim_tmp[i] *
            LW_ctrl_241029_1_B.theta) + LW_ctrl_241029_1_B.vd_lim_tmp[i + 6] *
            LW_ctrl_241029_1_B.time_to_stop;
        }

        /* 将期望速度转换到NED下 */
        /* '<S187>:1:341' if (flight_mode == FlightMode.PILOT && (ctrl_mode == ControlMode.ALTITUDE || ctrl_mode == ControlMode.POSITION )) ... */
        /* '<S187>:1:342'             || flight_mode == FlightMode.AUTO */
        if (((LW_ctrl_241029_1_B.flight_mode == PILOT) &&
             ((LW_ctrl_241029_1_B.ctrl_mode == ALTITUDE) ||
              (LW_ctrl_241029_1_B.ctrl_mode == POSITION))) ||
            (LW_ctrl_241029_1_B.flight_mode == AUTO)) {
          /* z-axis保大小 */
          /* '<S187>:1:344' vd_psi(3) = constrain(vd_psi(3), -LW_Z_VEL_MAX_UP, LW_Z_VEL_MAX_UP); */
          /* CONSTRAIN 此处显示有关此函数的摘要 */
          /*    此处显示详细说明 */
          /*  min  = single(min); */
          /*  max = single(max); */
          /* 'constrain:6' if x > max */
          if (LW_ctrl_241029_1_B.vd_psi[2] > LW_Z_VEL_MAX_UP) {
            /* 'constrain:7' y = max; */
            LW_ctrl_241029_1_B.vd_psi[2] = LW_Z_VEL_MAX_UP;
          } else if (LW_ctrl_241029_1_B.vd_psi[2] < -LW_Z_VEL_MAX_UP) {
            /* 'constrain:8' elseif x < min */
            /* 'constrain:9' y = min; */
            LW_ctrl_241029_1_B.vd_psi[2] = -LW_Z_VEL_MAX_UP;
          } else {
            /* 'constrain:10' else */
            /* 'constrain:11' y = x; */
          }

          /* '<S187>:1:346' if (flight_mode == FlightMode.PILOT && (ctrl_mode == ControlMode.POSITION )) || flight_mode == FlightMode.AUTO */
          if (((LW_ctrl_241029_1_B.flight_mode == PILOT) &&
               (LW_ctrl_241029_1_B.ctrl_mode == POSITION)) ||
              (LW_ctrl_241029_1_B.flight_mode == AUTO)) {
            /* xy-axis保方向 */
            /* '<S187>:1:348' vd_xy_norm = sqrt(vd_psi(1) * vd_psi(1) + vd_psi(2) * vd_psi(2)); */
            profileStart_LW_ctrl_241029_1(44U); /* original_line:6649 */LW_ctrl_241029_1_B.kappa = (real32_T)sqrt(LW_ctrl_241029_1_B.vd_psi
              [0] * LW_ctrl_241029_1_B.vd_psi[0] + LW_ctrl_241029_1_B.vd_psi[1] *
              LW_ctrl_241029_1_B.vd_psi[1]);profileEnd_LW_ctrl_241029_1(44U); /* original_line:6651 */

            /* '<S187>:1:349' VEL_MAX_XY = LW_X_VEL_MAX; */
            /* '<S187>:1:350' if vd_xy_norm > VEL_MAX_XY */
            if (LW_ctrl_241029_1_B.kappa > LW_X_VEL_MAX) {
              /* '<S187>:1:351' vd_psi(1 : 2) = vd_psi(1 : 2) * VEL_MAX_XY / vd_xy_norm; */
              LW_ctrl_241029_1_B.vd_psi[0] = LW_ctrl_241029_1_B.vd_psi[0] *
                LW_X_VEL_MAX / LW_ctrl_241029_1_B.kappa;
              LW_ctrl_241029_1_B.vd_psi[1] = LW_ctrl_241029_1_B.vd_psi[1] *
                LW_X_VEL_MAX / LW_ctrl_241029_1_B.kappa;
            }
          }

          /* '<S187>:1:354' [vd_psi, man_acc_ff] = TD_3DVector(vd_psi, ([LW_X_JERK_MAX; LW_Y_JERK_MAX; LW_Z_JERK_MAX]), dt); */
          LW_ctrl_241029_1_B.vel_ref_c[0] = LW_X_JERK_MAX;
          LW_ctrl_241029_1_B.vel_ref_c[1] = LW_Y_JERK_MAX;
          LW_ctrl_241029_1_B.vel_ref_c[2] = LW_Z_JERK_MAX;
          profileStart_LW_ctrl_241029_1(45U); /* original_line:6668 */LW_ctrl_241029_1_TD_3DVector(LW_ctrl_241029_1_B.vd_psi,
            LW_ctrl_241029_1_B.vel_ref_c, LW_ctrl_241029_1_B.IntegralGain,
            LW_ctrl_241029_1_B.y_c, LW_ctrl_241029_1_B.z3_);profileEnd_LW_ctrl_241029_1(45U); /* original_line:6670 */

          /* '<S187>:1:355' man_acc_ff = zeros(3,1,'single'); */
          /* 手动控制加速度前馈 */
          /* '<S187>:1:356' vd_lim = Rbe_psi'*vd_psi; */
          LW_ctrl_241029_1_B.kappa = LW_ctrl_241029_1_B.y_c[1];
          LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_B.y_c[0];
          LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.y_c[2];
          for (i = 0; i < 3; i++) {
            LW_ctrl_241029_1_B.z3_[i] = (LW_ctrl_241029_1_B.vd_lim_tmp[i + 3] *
              LW_ctrl_241029_1_B.kappa + LW_ctrl_241029_1_B.vd_lim_tmp[i] *
              LW_ctrl_241029_1_B.theta) + LW_ctrl_241029_1_B.vd_lim_tmp[i + 6] *
              LW_ctrl_241029_1_B.time_to_stop;
          }
        }

        /* '<S187>:1:358' if flight_mode == FlightMode.OFFBOARD */
        if (LW_ctrl_241029_1_B.flight_mode == OFFBOARD) {
          /* '<S187>:1:359' vel_fb = ((pos_ref - vehicle_pos)).* [LW_X_P; LW_Y_P; LW_Z_P]; */
          /* '<S187>:1:360' vd_lim = vel_fb + vel_ref.* [LW_X_FF; LW_Y_FF; LW_Z_FF]; */
          LW_ctrl_241029_1_B.z3_[0] = LW_ctrl_241029_1_B.vel_ref_kk[0] * LW_X_FF
            + LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];
          LW_ctrl_241029_1_B.z3_[1] = LW_ctrl_241029_1_B.vel_ref_kk[1] * LW_Y_FF
            + LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];
          LW_ctrl_241029_1_B.z3_[2] = LW_ctrl_241029_1_B.vel_ref_kk[2] * LW_Z_FF
            + LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2];
        }
      } else {
        /* '<S187>:1:362' else */
        /* '<S187>:1:363' if notInfNan(vehicle_pos) */
        if (LW_ctrl_241029_1_notInfNan_p(LW_ctrl_241029_1_B.sf_nan_inf.y)) {
          /* '<S187>:1:364' pos_ref = vehicle_pos; */
          LW_ctrl_241029_1_B.pos_ref_lq[0] = LW_ctrl_241029_1_B.sf_nan_inf.y[0];
          LW_ctrl_241029_1_B.pos_ref_lq[1] = LW_ctrl_241029_1_B.sf_nan_inf.y[1];
          LW_ctrl_241029_1_B.pos_ref_lq[2] = LW_ctrl_241029_1_B.sf_nan_inf.y[2];
        } else {
          /* '<S187>:1:365' else */
          /* '<S187>:1:366' pos_ref = single([0; 0; 0]); */
          LW_ctrl_241029_1_B.pos_ref_lq[0] = 0.0F;
          LW_ctrl_241029_1_B.pos_ref_lq[1] = 0.0F;
          LW_ctrl_241029_1_B.pos_ref_lq[2] = 0.0F;
        }

        /* '<S187>:1:368' vd_lim = single([0; 0; 0]); */
        LW_ctrl_241029_1_B.z3_[0] = 0.0F;
        LW_ctrl_241029_1_B.z3_[1] = 0.0F;
        LW_ctrl_241029_1_B.z3_[2] = 0.0F;

        /* '<S187>:1:369' yaw_ref = yaw; */
        /* '<S187>:1:370' wbz_ref = single(0); */
        /* '<S187>:1:371' [~, ~] = AdmittanceYaw(dm_est(3), yaw, single(0), dt, LW_DMZ0, LW_DMZ_MIN, LW_YAW_KAP, LW_YAW_KAD, 1); */
        profileStart_LW_ctrl_241029_1(32U); /* original_line:6721 */LW_ctrl_241029_1_AdmittanceYaw(LW_ctrl_241029_1_B.d_est_j[2],
          LW_ctrl_241029_1_B.aSinInput, 0.0F, LW_ctrl_241029_1_B.IntegralGain,
          LW_DMZ0, LW_DMZ_MIN, LW_YAW_KAP, LW_YAW_KAD, 1.0,
          &LW_ctrl_241029_1_B.kappa, &LW_ctrl_241029_1_B.eta_p);profileEnd_LW_ctrl_241029_1(32U); /* original_line:6724 */

        /* reset */
        /* '<S187>:1:373' pos_x1 = vehicle_pos(1); */
        LW_ctrl_241029_1_DW.pos_x1 = LW_ctrl_241029_1_B.sf_nan_inf.y[0];

        /* '<S187>:1:373' pos_y1 = vehicle_pos(2); */
        LW_ctrl_241029_1_DW.pos_y1 = LW_ctrl_241029_1_B.sf_nan_inf.y[1];

        /* '<S187>:1:373' pos_z1 = vehicle_pos(3); */
        LW_ctrl_241029_1_DW.pos_z1 = LW_ctrl_241029_1_B.sf_nan_inf.y[2];

        /* '<S187>:1:374' hold_pxy = vehicle_pos(1:2); */
        /* '<S187>:1:374' hold_pz = vehicle_pos(3); */
        LW_ctrl_241029_1_DW.hold_pz = LW_ctrl_241029_1_B.sf_nan_inf.y[2];

        /* '<S187>:1:375' hold_vxy = vehicle_vel(1:2); */
        LW_ctrl_241029_1_DW.hold_pxy[0] = LW_ctrl_241029_1_B.sf_nan_inf.y[0];
        LW_ctrl_241029_1_DW.hold_vxy[0] = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[0];
        LW_ctrl_241029_1_DW.hold_pxy[1] = LW_ctrl_241029_1_B.sf_nan_inf.y[1];
        LW_ctrl_241029_1_DW.hold_vxy[1] = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[1];

        /* '<S187>:1:375' hold_vz = vehicle_vel(3); */
        LW_ctrl_241029_1_DW.hold_vz = LW_ctrl_241029_1_B.sf_nan_inf1_f.y[2];

        /* '<S187>:1:376' hold_z_flag = false; */
        LW_ctrl_241029_1_DW.hold_z_flag = false;

        /* '<S187>:1:376' hold_xy_flag = false; */
        LW_ctrl_241029_1_DW.hold_xy_flag = false;

        /* '<S187>:1:377' hold_xy_timestamp = timestamp; */
        LW_ctrl_241029_1_DW.hold_xy_timestamp =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

        /* '<S187>:1:377' hold_z_timestamp = timestamp; */
        LW_ctrl_241029_1_DW.hold_z_timestamp =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp;

        /* '<S187>:1:378' yaw_d_ = yaw; */
        LW_ctrl_241029_1_DW.yaw_d_ = LW_ctrl_241029_1_B.aSinInput;

        /* '<S187>:1:380' xy_reset_counter_ = xy_reset_counter; */
        LW_ctrl_241029_1_DW.xy_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.xy_reset_counter;

        /* '<S187>:1:381' z_reset_counter_ = z_reset_counter; */
        LW_ctrl_241029_1_DW.z_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.z_reset_counter;

        /* '<S187>:1:382' vxy_reset_counter_ = vxy_reset_counter; */
        LW_ctrl_241029_1_DW.vxy_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vxy_reset_counter;

        /* '<S187>:1:383' vz_reset_counter_ = vz_reset_counter; */
        LW_ctrl_241029_1_DW.vz_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.vz_reset_counter;

        /* '<S187>:1:384' heading_reset_counter_ = heading_reset_counter; */
        LW_ctrl_241029_1_DW.heading_reset_counter_ =
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.heading_reset_counter;
      }

      /* End of MATLAB Function: '<S12>/position control' */

      /* MATLAB Function: '<S14>/pos_ctrl_integral_reset2' */
      /* yaw_ref = my_quat2yaw(offboard_ref.q,'ZYX'); */
      /* yaw_ref = single(45/180*pi); */
      /*  构造旋转矩阵 */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/postion control/pos_ctrl_integral_reset2': '<S191>:1' */
      /* '<S191>:1:3' R = [cos(psi), sin(psi), 0; */
      /* '<S191>:1:4'          -sin(psi), cos(psi), 0; */
      /* '<S191>:1:5'          0, 0, 1]; */
      /*  转换速度 */
      /* '<S191>:1:8' v_body = R * [v_ned(1);v_ned(2);v_ned(3)]; */
      LW_ctrl_241029_1_B.Rbe_psi[0] = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.Rbe_psi[3] = LW_ctrl_241029_1_B.km_f_b;
      LW_ctrl_241029_1_B.Rbe_psi[6] = 0.0F;
      LW_ctrl_241029_1_B.Rbe_psi[1] = -LW_ctrl_241029_1_B.km_f_b;
      LW_ctrl_241029_1_B.Rbe_psi[4] = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.Rbe_psi[7] = 0.0F;
      LW_ctrl_241029_1_B.Rbe_psi[2] = 0.0F;
      LW_ctrl_241029_1_B.Rbe_psi[5] = 0.0F;
      LW_ctrl_241029_1_B.Rbe_psi[8] = 1.0F;
      LW_ctrl_241029_1_B.IntegralGain = LW_ctrl_241029_1_B.z3_[0];
      LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.z3_[1];
      LW_ctrl_241029_1_B.km_f_b = LW_ctrl_241029_1_B.z3_[2];
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[i] =
          (LW_ctrl_241029_1_B.Rbe_psi[i + 3] * LW_ctrl_241029_1_B.Va_ +
           LW_ctrl_241029_1_B.Rbe_psi[i] * LW_ctrl_241029_1_B.IntegralGain) +
          LW_ctrl_241029_1_B.Rbe_psi[i + 6] * LW_ctrl_241029_1_B.km_f_b;
      }

      /* Sum: '<S14>/Sum2' */
      LW_ctrl_241029_1_B.IntegralGain = LW_ctrl_241029_1_B.Xi_e[2] -
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[2];

      /* MATLAB Function: '<S14>/pos_ctrl_integral_reset' incorporates:
       *  MATLAB Function: '<S14>/nan_inf_mode'
       *  SignalConversion generated from: '<S188>/ SFunction '
       */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/postion control/nan_inf_mode': '<S188>:1' */
      /* '<S188>:1:3' for i = 1:length(u) */
      /* '<S188>:1:8' y = u; */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/postion control/pos_ctrl_integral_reset': '<S189>:1' */
      /* '<S189>:1:2' mode = ctrl_mode(1); */
      /* '<S189>:1:3' arm = ctrl_mode(2); */
      /* '<S189>:1:4' if mode == ControlMode.ACRO || mode == ControlMode.STABILIZED || mode == ControlMode.MANUAL || arm == ControlMode.DISARM */
      if ((LW_ctrl_241029_1_B.ctrl_mode == ACRO) ||
          (LW_ctrl_241029_1_B.ctrl_mode == STABILIZED) ||
          (LW_ctrl_241029_1_B.ctrl_mode == MANUAL) || (LW_ctrl_241029_1_B.arm ==
           DISARM)) {
        /* '<S189>:1:5' integral_reset = [true true]; */
        rtb_integral_reset_idx_0 = true;
        rtb_integral_reset_idx_1 = true;
      } else if (LW_ctrl_241029_1_B.ctrl_mode == ALTITUDE) {
        /* '<S189>:1:6' elseif mode == ControlMode.ALTITUDE */
        /* '<S189>:1:7' integral_reset = [true false]; */
        rtb_integral_reset_idx_0 = true;
        rtb_integral_reset_idx_1 = false;
      } else if (LW_ctrl_241029_1_B.ctrl_mode == POSITION) {
        /* '<S189>:1:8' elseif mode == ControlMode.POSITION */
        /* '<S189>:1:9' integral_reset = [false false]; */
        rtb_integral_reset_idx_0 = false;
        rtb_integral_reset_idx_1 = false;
      } else {
        /* '<S189>:1:10' else */
        /* '<S189>:1:11' integral_reset = [false false]; */
        rtb_integral_reset_idx_0 = false;
        rtb_integral_reset_idx_1 = false;
      }

      /* End of MATLAB Function: '<S14>/pos_ctrl_integral_reset' */

      /* DiscreteIntegrator: '<S340>/Integrator' */
      if (LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE != 0) {
        /* DiscreteIntegrator: '<S340>/Integrator' */
        LW_ctrl_241029_1_B.km_f_b = LW_ctrl_241029_1_DW.Integrator_DSTATE;
      } else if (rtb_integral_reset_idx_1 ||
                 (LW_ctrl_241029_1_DW.Integrator_PrevResetState != 0)) {
        /* DiscreteIntegrator: '<S340>/Integrator' */
        LW_ctrl_241029_1_B.km_f_b = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S340>/Integrator' */
        LW_ctrl_241029_1_B.km_f_b = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Integrator_PREV_U +
          LW_ctrl_241029_1_DW.Integrator_DSTATE;
      }

      /* End of DiscreteIntegrator: '<S340>/Integrator' */

      /* DiscreteIntegrator: '<S335>/Filter' */
      if (LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE != 0) {
        /* DiscreteIntegrator: '<S335>/Filter' */
        LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_DW.Filter_DSTATE_f;
      } else if (rtb_integral_reset_idx_1 ||
                 (LW_ctrl_241029_1_DW.Filter_PrevResetState != 0)) {
        /* DiscreteIntegrator: '<S335>/Filter' */
        LW_ctrl_241029_1_B.Va_ = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S335>/Filter' */
        LW_ctrl_241029_1_B.Va_ = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Filter_PREV_U_e +
          LW_ctrl_241029_1_DW.Filter_DSTATE_f;
      }

      /* End of DiscreteIntegrator: '<S335>/Filter' */

      /* Gain: '<S343>/Filter Coefficient' incorporates:
       *  Gain: '<S333>/Derivative Gain'
       *  Sum: '<S335>/SumD'
       */
      LW_ctrl_241029_1_B.kappa = (0.0F * LW_ctrl_241029_1_B.IntegralGain -
        LW_ctrl_241029_1_B.Va_) * 100.0F;

      /* Sum: '<S349>/Sum' incorporates:
       *  Gain: '<S345>/Proportional Gain'
       */
      LW_ctrl_241029_1_B.eta_p = (5.5F * LW_ctrl_241029_1_B.IntegralGain +
        LW_ctrl_241029_1_B.km_f_b) + LW_ctrl_241029_1_B.kappa;

      /* Sum: '<S14>/Sum3' */
      LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_B.Xi_e[0] -
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];

      /* DiscreteIntegrator: '<S232>/Integrator' */
      if (LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_l != 0) {
        /* DiscreteIntegrator: '<S232>/Integrator' */
        LW_ctrl_241029_1_B.time_to_stop =
          LW_ctrl_241029_1_DW.Integrator_DSTATE_h;
      } else if (rtb_integral_reset_idx_0 ||
                 (LW_ctrl_241029_1_DW.Integrator_PrevResetState_m != 0)) {
        /* DiscreteIntegrator: '<S232>/Integrator' */
        LW_ctrl_241029_1_B.time_to_stop = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S232>/Integrator' */
        LW_ctrl_241029_1_B.time_to_stop = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Integrator_PREV_U_f +
          LW_ctrl_241029_1_DW.Integrator_DSTATE_h;
      }

      /* End of DiscreteIntegrator: '<S232>/Integrator' */

      /* DiscreteIntegrator: '<S227>/Filter' */
      if (LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_k != 0) {
        /* DiscreteIntegrator: '<S227>/Filter' */
        LW_ctrl_241029_1_B.delta_t = LW_ctrl_241029_1_DW.Filter_DSTATE_e;
      } else if (rtb_integral_reset_idx_0 ||
                 (LW_ctrl_241029_1_DW.Filter_PrevResetState_f != 0)) {
        /* DiscreteIntegrator: '<S227>/Filter' */
        LW_ctrl_241029_1_B.delta_t = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S227>/Filter' */
        LW_ctrl_241029_1_B.delta_t = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Filter_PREV_U_b +
          LW_ctrl_241029_1_DW.Filter_DSTATE_e;
      }

      /* End of DiscreteIntegrator: '<S227>/Filter' */

      /* Gain: '<S235>/Filter Coefficient' incorporates:
       *  Gain: '<S225>/Derivative Gain'
       *  Sum: '<S227>/SumD'
       */
      LW_ctrl_241029_1_B.FilterCoefficient_jy = (0.0F * LW_ctrl_241029_1_B.theta
        - LW_ctrl_241029_1_B.delta_t) * 100.0F;

      /* Sum: '<S241>/Sum' incorporates:
       *  Gain: '<S237>/Proportional Gain'
       */
      LW_ctrl_241029_1_B.DeadZone_e = (3.0F * LW_ctrl_241029_1_B.theta +
        LW_ctrl_241029_1_B.time_to_stop) +
        LW_ctrl_241029_1_B.FilterCoefficient_jy;

      /* Sum: '<S14>/Sum1' */
      LW_ctrl_241029_1_B.IntegralGain_gt = LW_ctrl_241029_1_B.Xi_e[1] -
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];

      /* DiscreteIntegrator: '<S286>/Integrator' */
      if (LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_d != 0) {
        /* DiscreteIntegrator: '<S286>/Integrator' */
        LW_ctrl_241029_1_B.Integrator_a =
          LW_ctrl_241029_1_DW.Integrator_DSTATE_n;
      } else if (rtb_integral_reset_idx_0 ||
                 (LW_ctrl_241029_1_DW.Integrator_PrevResetState_f != 0)) {
        /* DiscreteIntegrator: '<S286>/Integrator' */
        LW_ctrl_241029_1_B.Integrator_a = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S286>/Integrator' */
        LW_ctrl_241029_1_B.Integrator_a = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Integrator_PREV_U_l +
          LW_ctrl_241029_1_DW.Integrator_DSTATE_n;
      }

      /* End of DiscreteIntegrator: '<S286>/Integrator' */

      /* DiscreteIntegrator: '<S281>/Filter' */
      if (LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_j != 0) {
        /* DiscreteIntegrator: '<S281>/Filter' */
        LW_ctrl_241029_1_B.Filter_l = LW_ctrl_241029_1_DW.Filter_DSTATE_p;
      } else if (rtb_integral_reset_idx_0 ||
                 (LW_ctrl_241029_1_DW.Filter_PrevResetState_b != 0)) {
        /* DiscreteIntegrator: '<S281>/Filter' */
        LW_ctrl_241029_1_B.Filter_l = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S281>/Filter' */
        LW_ctrl_241029_1_B.Filter_l = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Filter_PREV_U_h +
          LW_ctrl_241029_1_DW.Filter_DSTATE_p;
      }

      /* End of DiscreteIntegrator: '<S281>/Filter' */

      /* Gain: '<S289>/Filter Coefficient' incorporates:
       *  Gain: '<S279>/Derivative Gain'
       *  Sum: '<S281>/SumD'
       */
      LW_ctrl_241029_1_B.FilterCoefficient_l = (0.0F *
        LW_ctrl_241029_1_B.IntegralGain_gt - LW_ctrl_241029_1_B.Filter_l) *
        100.0F;

      /* Sum: '<S295>/Sum' incorporates:
       *  Gain: '<S291>/Proportional Gain'
       */
      LW_ctrl_241029_1_B.DeadZone_el = (3.0F *
        LW_ctrl_241029_1_B.IntegralGain_gt + LW_ctrl_241029_1_B.Integrator_a) +
        LW_ctrl_241029_1_B.FilterCoefficient_l;

      /* Saturate: '<S293>/Saturation' */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/postion control/pos_ctrl_integral_reset3': '<S192>:1' */
      /* '<S192>:1:3' g = 9.8; */
      /* '<S192>:1:4' phi_d = atan(eay/g); */
      /* '<S192>:1:5' theta_d = -atan(eax/g); */
      if (LW_ctrl_241029_1_B.DeadZone_el > LW_Y_ACCEL_MAX) {
        rtb_FilterCoefficient_jy_tmp = LW_Y_ACCEL_MAX;
      } else if (LW_ctrl_241029_1_B.DeadZone_el < LW_Y_ACCEL_MIN) {
        rtb_FilterCoefficient_jy_tmp = LW_Y_ACCEL_MIN;
      } else {
        rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.DeadZone_el;
      }

      /* MATLAB Function: '<S14>/pos_ctrl_integral_reset3' incorporates:
       *  Gain: '<S14>/Gain3'
       *  Saturate: '<S293>/Saturation'
       */
      profileStart_LW_ctrl_241029_1(46U); /* original_line:7036 */LW_ctrl_241029_1_B.Filter_o = (real32_T)atan(-rtb_FilterCoefficient_jy_tmp
        / 9.8F);profileEnd_LW_ctrl_241029_1(46U); /* original_line:7037 */

      /* Saturate: '<S14>/Output_Limits3' */
      if (LW_ctrl_241029_1_B.Filter_o > 0.34906584F) {
        LW_ctrl_241029_1_B.Filter_o = 0.34906584F;
      } else if (LW_ctrl_241029_1_B.Filter_o < -0.34906584F) {
        LW_ctrl_241029_1_B.Filter_o = -0.34906584F;
      }

      /* End of Saturate: '<S14>/Output_Limits3' */

      /* Saturate: '<S239>/Saturation' */
      if (LW_ctrl_241029_1_B.DeadZone_e > LW_X_ACCEL_MAX) {
        rtb_FilterCoefficient_jy_tmp = LW_X_ACCEL_MAX;
      } else if (LW_ctrl_241029_1_B.DeadZone_e < LW_X_ACCEL_MIN) {
        rtb_FilterCoefficient_jy_tmp = LW_X_ACCEL_MIN;
      } else {
        rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.DeadZone_e;
      }

      /* MATLAB Function: '<S14>/pos_ctrl_integral_reset3' incorporates:
       *  Gain: '<S14>/Gain2'
       *  Saturate: '<S239>/Saturation'
       */
      profileStart_LW_ctrl_241029_1(47U); /* original_line:7061 */LW_ctrl_241029_1_B.c_b = -(real32_T)atan(-rtb_FilterCoefficient_jy_tmp /
        9.8F);profileEnd_LW_ctrl_241029_1(47U); /* original_line:7062 */

      /* Saturate: '<S14>/Output_Limits1' */
      if (LW_ctrl_241029_1_B.c_b > 0.34906584F) {
        LW_ctrl_241029_1_B.c_b = 0.34906584F;
      } else if (LW_ctrl_241029_1_B.c_b < -0.34906584F) {
        LW_ctrl_241029_1_B.c_b = -0.34906584F;
      }

      /* End of Saturate: '<S14>/Output_Limits1' */

      /* MATLAB Function: '<S11>/MATLAB Function1' incorporates:
       *  SignalConversion generated from: '<S18>/ SFunction '
       */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/altitude control/MATLAB Function1': '<S18>:1' */
      /* '<S18>:1:3' quat_d = my_eul2quat(euler_d); */
      /* MY_EUL2QUAT Convert Euler angle to quaternion, modified from eul2quat.m */
      /*    Q = EUL2QUAT(EUL) converts a given Euler angle, EUL, into */
      /*    the corresponding unit quaternion, Q. EUL is a 3-by-1 vector of Euler */
      /*    rotation angles. */
      /*    The output, Q, is a 4-by-1 vector. The quaternion is of the form q = [w x y z]T, with w as the scalar number. */
      /* 'my_eul2quat:8' if isempty(varargin) */
      /*  Use default rotation sequence */
      /* 'my_eul2quat:10' seq = 'ZXY'; */
      /*  Pre-allocate output */
      /* 'my_eul2quat:16' q = zeros(4, 1, 'like', eul); */
      /* 'my_eul2quat:17' q(1) = 1; */
      /* 'my_eul2quat:18' c = cos(eul / 2); */
      /* 'my_eul2quat:19' s = sin(eul / 2); */
      LW_ctrl_241029_1_B.DeadZone_p = LW_ctrl_241029_1_B.Filter_o / 2.0F;
      profileStart_LW_ctrl_241029_1(48U); /* original_line:7092 */LW_ctrl_241029_1_B.Integrator_f = (real32_T)cos
        (LW_ctrl_241029_1_B.DeadZone_p);profileEnd_LW_ctrl_241029_1(48U); /* original_line:7093 */
      profileStart_LW_ctrl_241029_1(49U); /* original_line:7094 */q = (real32_T)sin(LW_ctrl_241029_1_B.DeadZone_p);profileEnd_LW_ctrl_241029_1(49U); /* original_line:7094 */
      LW_ctrl_241029_1_B.DeadZone_p = LW_ctrl_241029_1_B.c_b / 2.0F;
      profileStart_LW_ctrl_241029_1(50U); /* original_line:7096 */LW_ctrl_241029_1_B.FilterCoefficient_i = (real32_T)cos
        (LW_ctrl_241029_1_B.DeadZone_p);profileEnd_LW_ctrl_241029_1(50U); /* original_line:7097 */
      profileStart_LW_ctrl_241029_1(51U); /* original_line:7098 */LW_ctrl_241029_1_B.b_c = (real32_T)sin(LW_ctrl_241029_1_B.DeadZone_p);profileEnd_LW_ctrl_241029_1(51U); /* original_line:7098 */
      LW_ctrl_241029_1_B.DeadZone_p = LW_ctrl_241029_1_B.aSinInput / 2.0F;
      profileStart_LW_ctrl_241029_1(52U); /* original_line:7100 */LW_ctrl_241029_1_B.IntegralGain_n = (real32_T)cos
        (LW_ctrl_241029_1_B.DeadZone_p);profileEnd_LW_ctrl_241029_1(52U); /* original_line:7101 */
      profileStart_LW_ctrl_241029_1(53U); /* original_line:7102 */LW_ctrl_241029_1_B.DeadZone_p = (real32_T)sin
        (LW_ctrl_241029_1_B.DeadZone_p);profileEnd_LW_ctrl_241029_1(53U); /* original_line:7103 */

      /* 'my_eul2quat:21' upperSeq = upper(seq); */
      /* 'my_eul2quat:22' switch upperSeq */
      /* 'my_eul2quat:37' case 'ZXY' */
      /* 'my_eul2quat:38' q = [c(3) * c(1) * c(2) - s(3) * s(1) * s(2); */
      /* 'my_eul2quat:39'             c(3) * s(1) * c(2) - s(3) * c(1) * s(2); */
      /* 'my_eul2quat:40'             c(3) * c(1) * s(2) + s(3) * s(1) * c(2); */
      /* 'my_eul2quat:41'             s(3) * c(1) * c(2) + c(3) * s(1) * s(2)]; */
      /* '<S18>:1:4' euler = my_quat2eul(quat); */
      /* MY_QUAT2EUL Convert quaternion to Euler angles, modified from quat2eul.m */
      /*    EUL = QUAT2EUL(QOBJ) converts a quaternion object, QOBJ, into the */
      /*    corresponding Euler angles, EUL.QOBJ is an 4-element vector of quaternion objects. */
      /*    The output, EUL, is an 3-element vector of Euler rotation angles,that is [roll;pitch;yaw]. Rotation angles are in radians. */
      /* 'my_quat2eul:6' q = q(:); */
      /* 'my_quat2eul:7' if isempty(varargin) */
      /*  Use default rotation sequence */
      /* 'my_quat2eul:9' seq = 'ZXY'; */
      /* 'my_quat2eul:13' q = robotics.internal.validation.validateQuaternion(q', 'quat2eul', 'q'); */
      /* norm_q = sqrt(q' * q); */
      /*  if norm_q < 0.5 */
      /*      q = [1;0;0;0]; */
      /*      norm_q = 1; */
      /*  end */
      /* q = q ./ norm_q; */
      /* 'my_quat2eul:20' q = robotics.internal.normalizeRows(q); */
      LW_ctrl_241029_1_B.qk_[0] = LW_ctrl_241029_1_B.y[0] * Filter_o5;
      LW_ctrl_241029_1_B.qk_[1] = LW_ctrl_241029_1_B.y[1] * Filter_o5;
      LW_ctrl_241029_1_B.qk_[2] = LW_ctrl_241029_1_B.y[2] * Filter_o5;
      LW_ctrl_241029_1_B.qk_[3] = LW_ctrl_241029_1_B.y[3] * Filter_o5;

      /* 'my_quat2eul:22' qw = q(1); */
      /* 'my_quat2eul:23' qx = q(2); */
      /* 'my_quat2eul:24' qy = q(3); */
      /* 'my_quat2eul:25' qz = q(4); */
      /*  Pre-allocate output */
      /* 'my_quat2eul:28' eul = single(zeros(3, 1,'like',q)); */
      /* 'my_quat2eul:29' upperSeq = upper(seq); */
      /* 'my_quat2eul:30' switch upperSeq */
      /* 'my_quat2eul:72' case 'ZXY' */
      /* 'my_quat2eul:73' aSinInput = 2 * (qy .* qz + qw .* qx); */
      LW_ctrl_241029_1_B.aSinInput = (LW_ctrl_241029_1_B.qk_[2] *
        LW_ctrl_241029_1_B.qk_[3] + LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[1]) * 2.0F;

      /* 'my_quat2eul:74' if aSinInput > 1 */
      if (LW_ctrl_241029_1_B.aSinInput > 1.0F) {
        /* 'my_quat2eul:75' aSinInput = single(1); */
        LW_ctrl_241029_1_B.aSinInput = 1.0F;
      } else if (LW_ctrl_241029_1_B.aSinInput < -1.0F) {
        /* 'my_quat2eul:76' elseif (aSinInput < -1) */
        /* 'my_quat2eul:77' aSinInput = -single(1); */
        LW_ctrl_241029_1_B.aSinInput = -1.0F;
      }

      /* 'my_quat2eul:80' eul = [ asin( aSinInput ); ... */
      /* 'my_quat2eul:81'             atan2( -2 * (qx .* qz - qw .* qy), qw .^ 2 - qx .^ 2 - qy .^ 2 + qz .^ 2 ); ... */
      /* 'my_quat2eul:82'             atan2( -2 * (qx .* qy - qw .* qz), qw .^ 2 - qx .^ 2 + qy .^ 2 - qz .^ 2 )]; */
      profileStart_LW_ctrl_241029_1(54U); /* original_line:7161 */rtb_FilterCoefficient_jy_tmp = (real32_T)asin(LW_ctrl_241029_1_B.aSinInput);profileEnd_LW_ctrl_241029_1(54U); /* original_line:7161 */
      profileStart_LW_ctrl_241029_1(55U); /* original_line:7162 */LW_ctrl_241029_1_B.T1 = rt_atan2f_snf((LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qk_[3] - LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[2]) * -2.0F, ((LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[0] - LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qk_[1]) - LW_ctrl_241029_1_B.qk_[2] *
        LW_ctrl_241029_1_B.qk_[2]) + LW_ctrl_241029_1_B.qk_[3] *
        LW_ctrl_241029_1_B.qk_[3]);profileEnd_LW_ctrl_241029_1(55U); /* original_line:7168 */

      /*  Check for complex numbers */
      /* 'my_quat2eul:93' if ~isreal(eul) */
      /*  quat_d, quat: 1x4, [w x y z] */
      /* '<S18>:1:7' q_err = quatmultiply(quat_d', quatinv(quat')); */
      LW_ctrl_241029_1_B.qk_[0] = LW_ctrl_241029_1_B.y[0] /
        LW_ctrl_241029_1_B.FilterCoefficient_k;
      LW_ctrl_241029_1_B.qk_[1] = -LW_ctrl_241029_1_B.y[1] /
        LW_ctrl_241029_1_B.FilterCoefficient_k;
      LW_ctrl_241029_1_B.qk_[2] = -LW_ctrl_241029_1_B.y[2] /
        LW_ctrl_241029_1_B.FilterCoefficient_k;
      LW_ctrl_241029_1_B.qk_[3] = -LW_ctrl_241029_1_B.y[3] /
        LW_ctrl_241029_1_B.FilterCoefficient_k;
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.Integrator_f *
        LW_ctrl_241029_1_B.IntegralGain_n;
      Filter_o5 = q * LW_ctrl_241029_1_B.DeadZone_p;
      LW_ctrl_241029_1_B.qm[0] = LW_ctrl_241029_1_B.aSinInput *
        LW_ctrl_241029_1_B.FilterCoefficient_i - Filter_o5 *
        LW_ctrl_241029_1_B.b_c;
      LW_ctrl_241029_1_B.DeadZone_p *= LW_ctrl_241029_1_B.Integrator_f;
      q *= LW_ctrl_241029_1_B.IntegralGain_n;
      LW_ctrl_241029_1_B.qm[1] = q * LW_ctrl_241029_1_B.FilterCoefficient_i -
        LW_ctrl_241029_1_B.DeadZone_p * LW_ctrl_241029_1_B.b_c;
      LW_ctrl_241029_1_B.qm[2] = LW_ctrl_241029_1_B.aSinInput *
        LW_ctrl_241029_1_B.b_c + Filter_o5 *
        LW_ctrl_241029_1_B.FilterCoefficient_i;
      LW_ctrl_241029_1_B.qm[3] = LW_ctrl_241029_1_B.DeadZone_p *
        LW_ctrl_241029_1_B.FilterCoefficient_i + q * LW_ctrl_241029_1_B.b_c;
      LW_ctrl_241029_1_B.T_c[0] = ((LW_ctrl_241029_1_B.qm[0] *
        LW_ctrl_241029_1_B.qk_[0] - LW_ctrl_241029_1_B.qm[1] *
        LW_ctrl_241029_1_B.qk_[1]) - LW_ctrl_241029_1_B.qm[2] *
        LW_ctrl_241029_1_B.qk_[2]) - LW_ctrl_241029_1_B.qm[3] *
        LW_ctrl_241029_1_B.qk_[3];
      LW_ctrl_241029_1_B.T_c[1] = (LW_ctrl_241029_1_B.qm[0] *
        LW_ctrl_241029_1_B.qk_[1] + LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qm[1]) + (LW_ctrl_241029_1_B.qm[2] *
        LW_ctrl_241029_1_B.qk_[3] - LW_ctrl_241029_1_B.qk_[2] *
        LW_ctrl_241029_1_B.qm[3]);
      LW_ctrl_241029_1_B.T_c[2] = (LW_ctrl_241029_1_B.qm[0] *
        LW_ctrl_241029_1_B.qk_[2] + LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qm[2]) + (LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qm[3] - LW_ctrl_241029_1_B.qm[1] *
        LW_ctrl_241029_1_B.qk_[3]);
      LW_ctrl_241029_1_B.T_c[3] = (LW_ctrl_241029_1_B.qm[0] *
        LW_ctrl_241029_1_B.qk_[3] + LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qm[3]) + (LW_ctrl_241029_1_B.qm[1] *
        LW_ctrl_241029_1_B.qk_[2] - LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qm[2]);

      /* '<S18>:1:9' eul_err = quat2eul(q_err, "ZYX"); */
      profileStart_LW_ctrl_241029_1(56U); /* original_line:7219 */LW_ctrl_241029_1_B.aSinInput = 1.0F / (real32_T)sqrt
        (((LW_ctrl_241029_1_B.T_c[0] * LW_ctrl_241029_1_B.T_c[0] +
           LW_ctrl_241029_1_B.T_c[1] * LW_ctrl_241029_1_B.T_c[1]) +
          LW_ctrl_241029_1_B.T_c[2] * LW_ctrl_241029_1_B.T_c[2]) +
         LW_ctrl_241029_1_B.T_c[3] * LW_ctrl_241029_1_B.T_c[3]);profileEnd_LW_ctrl_241029_1(56U); /* original_line:7223 */
      LW_ctrl_241029_1_B.qk_[0] = LW_ctrl_241029_1_B.T_c[0] *
        LW_ctrl_241029_1_B.aSinInput;
      LW_ctrl_241029_1_B.qk_[1] = LW_ctrl_241029_1_B.T_c[1] *
        LW_ctrl_241029_1_B.aSinInput;
      LW_ctrl_241029_1_B.qk_[2] = LW_ctrl_241029_1_B.T_c[2] *
        LW_ctrl_241029_1_B.aSinInput;
      LW_ctrl_241029_1_B.qk_[3] = LW_ctrl_241029_1_B.T_c[3] *
        LW_ctrl_241029_1_B.aSinInput;
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.qk_[1] *
        LW_ctrl_241029_1_B.qk_[3] * 2.0F - LW_ctrl_241029_1_B.qk_[0] *
        LW_ctrl_241029_1_B.qk_[2] * 2.0F;
      if (LW_ctrl_241029_1_B.aSinInput > 1.0F) {
        LW_ctrl_241029_1_B.aSinInput = 1.0F;
      }

      if (LW_ctrl_241029_1_B.aSinInput < -1.0F) {
        LW_ctrl_241029_1_B.aSinInput = -1.0F;
      }

      /* MATLAB Function: '<S11>/MATLAB Function1' */
      if ((LW_ctrl_241029_1_B.aSinInput < 0.0F) && ((real32_T)fabs
           (LW_ctrl_241029_1_B.aSinInput + 1.0F) < 1.1920929E-6F)) {
        profileStart_LW_ctrl_241029_1(59U); /* original_line:7246 */LW_ctrl_241029_1_B.aSinInput = -2.0F * rt_atan2f_snf
          (LW_ctrl_241029_1_B.qk_[1], LW_ctrl_241029_1_B.qk_[0]);profileEnd_LW_ctrl_241029_1(59U); /* original_line:7247 */
      } else if ((LW_ctrl_241029_1_B.aSinInput > 0.0F) && ((real32_T)fabs
                  (LW_ctrl_241029_1_B.aSinInput - 1.0F) < 1.1920929E-6F)) {
        profileStart_LW_ctrl_241029_1(58U); /* original_line:7250 */LW_ctrl_241029_1_B.aSinInput = 2.0F * rt_atan2f_snf
          (LW_ctrl_241029_1_B.qk_[1], LW_ctrl_241029_1_B.qk_[0]);profileEnd_LW_ctrl_241029_1(58U); /* original_line:7251 */
      } else {
        profileStart_LW_ctrl_241029_1(57U); /* original_line:7253 */LW_ctrl_241029_1_B.aSinInput = rt_atan2f_snf(LW_ctrl_241029_1_B.qk_[0] *
          LW_ctrl_241029_1_B.qk_[3] * 2.0F + LW_ctrl_241029_1_B.qk_[1] *
          LW_ctrl_241029_1_B.qk_[2] * 2.0F, (LW_ctrl_241029_1_B.qk_[0] *
          LW_ctrl_241029_1_B.qk_[0] * 2.0F - 1.0F) + LW_ctrl_241029_1_B.qk_[1] *
          LW_ctrl_241029_1_B.qk_[1] * 2.0F);profileEnd_LW_ctrl_241029_1(57U); /* original_line:7257 */
      }

      /* '<S18>:1:10' yaw_err = 3*wrapToPi(eul_err(1)); */
      want_hold_xy = ((LW_ctrl_241029_1_B.aSinInput < -3.1415926535897931) ||
                      (LW_ctrl_241029_1_B.aSinInput > 3.1415926535897931));

      /* End of Outputs for SubSystem: '<S1>/PID_Controller' */
      trueCount = 0;

      /* Outputs for Function Call SubSystem: '<S1>/PID_Controller' */
      if (want_hold_xy) {
        for (i = 0; i < 1; i++) {
          trueCount++;
        }
      }

      /* MATLAB Function: '<S11>/MATLAB Function1' */
      if (trueCount - 1 >= 0) {
        if (rtIsNaNF(LW_ctrl_241029_1_B.aSinInput + 3.14159274F) || rtIsInfF
            (LW_ctrl_241029_1_B.aSinInput + 3.14159274F)) {
          LW_ctrl_241029_1_B.b_c = (rtNaNF);
        } else if (LW_ctrl_241029_1_B.aSinInput + 3.14159274F == 0.0F) {
          LW_ctrl_241029_1_B.b_c = 0.0F;
        } else {
          profileStart_LW_ctrl_241029_1(60U); /* original_line:7282 */LW_ctrl_241029_1_B.b_c = (real32_T)fmod(LW_ctrl_241029_1_B.aSinInput +
            3.14159274F, 6.2831854820251465);profileEnd_LW_ctrl_241029_1(60U); /* original_line:7283 */
          rEQ0 = (LW_ctrl_241029_1_B.b_c == 0.0F);
          if (!rEQ0) {
            profileStart_LW_ctrl_241029_1(61U); /* original_line:7286 */q = (real32_T)fabs((LW_ctrl_241029_1_B.aSinInput + 3.14159274F) /
                               6.28318548F);profileEnd_LW_ctrl_241029_1(61U); /* original_line:7287 */
            profileStart_LW_ctrl_241029_1(62U); /* original_line:7288 */rEQ0 = !((real32_T)fabs(q - (real32_T)floor(q + 0.5F)) >
                     1.1920929E-7F * q);profileEnd_LW_ctrl_241029_1(62U); /* original_line:7289 */
          }

          if (rEQ0) {
            LW_ctrl_241029_1_B.b_c = 0.0F;
          } else if (LW_ctrl_241029_1_B.b_c < 0.0F) {
            LW_ctrl_241029_1_B.b_c += 6.28318548F;
          }
        }

        LW_ctrl_241029_1_B.varargin_1_data = LW_ctrl_241029_1_B.b_c;
      }

      /* End of Outputs for SubSystem: '<S1>/PID_Controller' */
      for (i = 0; i < trueCount; i++) {
        /* Outputs for Function Call SubSystem: '<S1>/PID_Controller' */
        if ((LW_ctrl_241029_1_B.varargin_1_data == 0.0F) &&
            (LW_ctrl_241029_1_B.aSinInput + 3.14159274F > 0.0F)) {
          LW_ctrl_241029_1_B.varargin_1_data = 6.28318548F;
        }

        /* End of Outputs for SubSystem: '<S1>/PID_Controller' */
      }

      /* Outputs for Function Call SubSystem: '<S1>/PID_Controller' */
      /* MATLAB Function: '<S11>/MATLAB Function1' */
      LW_ctrl_241029_1_B.T2 = LW_ctrl_241029_1_B.aSinInput;
      if (want_hold_xy) {
        LW_ctrl_241029_1_B.T2 = LW_ctrl_241029_1_B.varargin_1_data - 3.14159274F;
      }

      /* Sum: '<S11>/Sum3' incorporates:
       *  MATLAB Function: '<S11>/MATLAB Function1'
       *  SignalConversion generated from: '<S18>/ SFunction '
       */
      /* '<S18>:1:11' phi_err = 10*(euler_d(1) - euler(1)); */
      /* '<S18>:1:12' theta_err = 10*(euler_d(2) - euler(2)); */
      LW_ctrl_241029_1_B.aSinInput = (LW_ctrl_241029_1_B.Filter_o -
        rtb_FilterCoefficient_jy_tmp) * 10.0F - LW_ctrl_241029_1_B.y_e[0];

      /* MATLAB Function: '<S11>/attrates_ref_selector' */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/altitude control/attrates_ref_selector': '<S19>:1' */
      /* '<S19>:1:3' rate_ctrl_integral_reset = [true; true; true]; */
      /* '<S19>:1:4' if notInfNan(flight_mode) && notInfNan([ctrl_mode, arm]) */
      /* ISINFNAN 此处显示有关此函数的摘要 */
      /*    Data is a vector. */
      /* 'notInfNan:4' y = false; */
      /* 'notInfNan:5' for ii = 1:length(data) */
      /* '<S19>:1:5' if  arm == ControlMode.DISARM || ctrl_mode == ControlMode.MANUAL */
      if ((LW_ctrl_241029_1_B.arm == DISARM) || (LW_ctrl_241029_1_B.ctrl_mode ==
           MANUAL)) {
        /* '<S19>:1:6' rate_ctrl_integral_reset = [true; true; true]; */
        want_hold_xy = true;
        rEQ0 = true;
        rtb_rate_ctrl_integral_reset_id = true;
      } else {
        /* '<S19>:1:7' else */
        /* '<S19>:1:8' rate_ctrl_integral_reset = [false; false; false]; */
        want_hold_xy = false;
        rEQ0 = false;
        rtb_rate_ctrl_integral_reset_id = false;
      }

      /* End of MATLAB Function: '<S11>/attrates_ref_selector' */

      /* DiscreteIntegrator: '<S59>/Integrator' */
      if (LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_ls != 0) {
        /* DiscreteIntegrator: '<S59>/Integrator' */
        LW_ctrl_241029_1_B.b_c = LW_ctrl_241029_1_DW.Integrator_DSTATE_j;
      } else if (want_hold_xy ||
                 (LW_ctrl_241029_1_DW.Integrator_PrevResetState_o != 0)) {
        /* DiscreteIntegrator: '<S59>/Integrator' */
        LW_ctrl_241029_1_B.b_c = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S59>/Integrator' */
        LW_ctrl_241029_1_B.b_c = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Integrator_PREV_U_m +
          LW_ctrl_241029_1_DW.Integrator_DSTATE_j;
      }

      /* End of DiscreteIntegrator: '<S59>/Integrator' */

      /* DiscreteIntegrator: '<S54>/Filter' */
      if (LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_m != 0) {
        /* DiscreteIntegrator: '<S54>/Filter' */
        LW_ctrl_241029_1_B.Saturation_d = LW_ctrl_241029_1_DW.Filter_DSTATE;
      } else if (want_hold_xy || (LW_ctrl_241029_1_DW.Filter_PrevResetState_m !=
                  0)) {
        /* DiscreteIntegrator: '<S54>/Filter' */
        LW_ctrl_241029_1_B.Saturation_d = 0.0;
      } else {
        /* DiscreteIntegrator: '<S54>/Filter' */
        LW_ctrl_241029_1_B.Saturation_d = 0.005 * (real_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Filter_PREV_U +
          LW_ctrl_241029_1_DW.Filter_DSTATE;
      }

      /* End of DiscreteIntegrator: '<S54>/Filter' */

      /* Gain: '<S62>/Filter Coefficient' incorporates:
       *  Gain: '<S52>/Derivative Gain'
       *  Sum: '<S54>/SumD'
       */
      LW_ctrl_241029_1_B.FilterCoefficient = (0.0F *
        LW_ctrl_241029_1_B.aSinInput - LW_ctrl_241029_1_B.Saturation_d) * 100.0;

      /* Sum: '<S68>/Sum' incorporates:
       *  Gain: '<S64>/Proportional Gain'
       */
      LW_ctrl_241029_1_B.DeadZone = ((real_T)(20.0F *
        LW_ctrl_241029_1_B.aSinInput) + LW_ctrl_241029_1_B.b_c) +
        LW_ctrl_241029_1_B.FilterCoefficient;

      /* Sum: '<S11>/Sum' incorporates:
       *  MATLAB Function: '<S11>/MATLAB Function1'
       *  SignalConversion generated from: '<S18>/ SFunction '
       */
      LW_ctrl_241029_1_B.c_b = (LW_ctrl_241029_1_B.c_b - LW_ctrl_241029_1_B.T1) *
        10.0F - LW_ctrl_241029_1_B.y_e[1];

      /* DiscreteIntegrator: '<S113>/Integrator' */
      if (LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_n != 0) {
        /* DiscreteIntegrator: '<S113>/Integrator' */
        q = LW_ctrl_241029_1_DW.Integrator_DSTATE_m;
      } else if (rEQ0 || (LW_ctrl_241029_1_DW.Integrator_PrevResetState_mv != 0))
      {
        /* DiscreteIntegrator: '<S113>/Integrator' */
        q = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S113>/Integrator' */
        q = 0.005F * (real32_T)LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Integrator_PREV_U_a +
          LW_ctrl_241029_1_DW.Integrator_DSTATE_m;
      }

      /* End of DiscreteIntegrator: '<S113>/Integrator' */

      /* DiscreteIntegrator: '<S108>/Filter' */
      if (LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_n != 0) {
        /* DiscreteIntegrator: '<S108>/Filter' */
        LW_ctrl_241029_1_B.Filter_o = LW_ctrl_241029_1_DW.Filter_DSTATE_fv;
      } else if (rEQ0 || (LW_ctrl_241029_1_DW.Filter_PrevResetState_p != 0)) {
        /* DiscreteIntegrator: '<S108>/Filter' */
        LW_ctrl_241029_1_B.Filter_o = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S108>/Filter' */
        LW_ctrl_241029_1_B.Filter_o = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Filter_PREV_U_j +
          LW_ctrl_241029_1_DW.Filter_DSTATE_fv;
      }

      /* End of DiscreteIntegrator: '<S108>/Filter' */

      /* Gain: '<S116>/Filter Coefficient' incorporates:
       *  Gain: '<S106>/Derivative Gain'
       *  Sum: '<S108>/SumD'
       */
      LW_ctrl_241029_1_B.FilterCoefficient_i = (0.0F * LW_ctrl_241029_1_B.c_b -
        LW_ctrl_241029_1_B.Filter_o) * 100.0F;

      /* Sum: '<S122>/Sum' incorporates:
       *  Gain: '<S118>/Proportional Gain'
       */
      LW_ctrl_241029_1_B.DeadZone_p = (20.0F * LW_ctrl_241029_1_B.c_b + q) +
        LW_ctrl_241029_1_B.FilterCoefficient_i;

      /* Sum: '<S11>/Sum2' incorporates:
       *  MATLAB Function: '<S11>/MATLAB Function1'
       */
      LW_ctrl_241029_1_B.IntegralGain_n = 3.0F * LW_ctrl_241029_1_B.T2 -
        LW_ctrl_241029_1_B.y_e[2];

      /* DiscreteIntegrator: '<S167>/Integrator' */
      if (LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_j != 0) {
        /* DiscreteIntegrator: '<S167>/Integrator' */
        LW_ctrl_241029_1_B.Integrator_f =
          LW_ctrl_241029_1_DW.Integrator_DSTATE_a;
      } else if (rtb_rate_ctrl_integral_reset_id ||
                 (LW_ctrl_241029_1_DW.Integrator_PrevResetState_fl != 0)) {
        /* DiscreteIntegrator: '<S167>/Integrator' */
        LW_ctrl_241029_1_B.Integrator_f = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S167>/Integrator' */
        LW_ctrl_241029_1_B.Integrator_f = 0.005F * (real32_T)
          LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Integrator_PREV_U_d +
          LW_ctrl_241029_1_DW.Integrator_DSTATE_a;
      }

      /* End of DiscreteIntegrator: '<S167>/Integrator' */

      /* DiscreteIntegrator: '<S162>/Filter' */
      if (LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_b != 0) {
        /* DiscreteIntegrator: '<S162>/Filter' */
        Filter_o5 = LW_ctrl_241029_1_DW.Filter_DSTATE_i;
      } else if (rtb_rate_ctrl_integral_reset_id ||
                 (LW_ctrl_241029_1_DW.Filter_PrevResetState_i != 0)) {
        /* DiscreteIntegrator: '<S162>/Filter' */
        Filter_o5 = 0.0F;
      } else {
        /* DiscreteIntegrator: '<S162>/Filter' */
        Filter_o5 = 0.005F * (real32_T)LW_ctrl_241029_1_B.PID_Controller_ELAPS_T
          * LW_ctrl_241029_1_DW.Filter_PREV_U_n +
          LW_ctrl_241029_1_DW.Filter_DSTATE_i;
      }

      /* End of DiscreteIntegrator: '<S162>/Filter' */

      /* Gain: '<S170>/Filter Coefficient' incorporates:
       *  Gain: '<S160>/Derivative Gain'
       *  Sum: '<S162>/SumD'
       */
      LW_ctrl_241029_1_B.FilterCoefficient_k = (0.0F *
        LW_ctrl_241029_1_B.IntegralGain_n - Filter_o5) * 100.0F;

      /* Sum: '<S176>/Sum' incorporates:
       *  Gain: '<S172>/Proportional Gain'
       */
      LW_ctrl_241029_1_B.DeadZone_ph = (20.0F *
        LW_ctrl_241029_1_B.IntegralGain_n + LW_ctrl_241029_1_B.Integrator_f) +
        LW_ctrl_241029_1_B.FilterCoefficient_k;

      /* Saturate: '<S66>/Saturation' */
      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/altitude control/MATLAB Function': '<S17>:1' */
      /* '<S17>:1:4' u = ModelParam_uavJ*[Mx_d;My_d;Mz_d]; */
      /* '<S17>:1:5' fM_d = [f_d;u]; */
      /* '<S17>:1:6' Allocation = [0.2500   -1.1765    1.0000   15.0602 */
      /* '<S17>:1:7'     0.2500   -1.1765   -1.0000  -15.0602 */
      /* '<S17>:1:8'     0.2500    1.1765    1.0000  -15.0602 */
      /* '<S17>:1:9'     0.2500    1.1765   -1.0000   15.0602]; */
      /* '<S17>:1:11' T = Allocation*fM_d; */
      if (LW_ctrl_241029_1_B.DeadZone > 102.24140440937498) {
        LW_ctrl_241029_1_B.sigma_idx_3 = 102.24140440937498;
      } else if (LW_ctrl_241029_1_B.DeadZone < -102.24140440937498) {
        LW_ctrl_241029_1_B.sigma_idx_3 = -102.24140440937498;
      } else {
        LW_ctrl_241029_1_B.sigma_idx_3 = LW_ctrl_241029_1_B.DeadZone;
      }

      /* Saturate: '<S120>/Saturation' */
      if (LW_ctrl_241029_1_B.DeadZone_p > 111.165F) {
        LW_ctrl_241029_1_B.T1 = 111.165F;
      } else if (LW_ctrl_241029_1_B.DeadZone_p < -111.165F) {
        LW_ctrl_241029_1_B.T1 = -111.165F;
      } else {
        LW_ctrl_241029_1_B.T1 = LW_ctrl_241029_1_B.DeadZone_p;
      }

      /* Saturate: '<S174>/Saturation' */
      if (LW_ctrl_241029_1_B.DeadZone_ph > 8.70227F) {
        LW_ctrl_241029_1_B.T2 = 8.70227F;
      } else if (LW_ctrl_241029_1_B.DeadZone_ph < -8.70227F) {
        LW_ctrl_241029_1_B.T2 = -8.70227F;
      } else {
        LW_ctrl_241029_1_B.T2 = LW_ctrl_241029_1_B.DeadZone_ph;
      }

      /* Saturate: '<S347>/Saturation' */
      if (LW_ctrl_241029_1_B.eta_p > LW_Z_ACCEL_UP) {
        rtb_FilterCoefficient_jy_tmp = LW_Z_ACCEL_UP;
      } else if (LW_ctrl_241029_1_B.eta_p < LW_Z_ACCEL_LOW) {
        rtb_FilterCoefficient_jy_tmp = LW_Z_ACCEL_LOW;
      } else {
        rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.eta_p;
      }

      /* Product: '<S14>/Divide1' incorporates:
       *  Constant: '<S14>/Constant'
       *  Constant: '<S14>/Constant1'
       *  Product: '<S14>/Divide2'
       *  Product: '<S14>/Divide3'
       *  Saturate: '<S347>/Saturation'
       *  Sum: '<S14>/Sum4'
       *  Trigonometry: '<S14>/Cos'
       *  Trigonometry: '<S14>/Cos1'
       */
      profileStart_LW_ctrl_241029_1(63U); /* original_line:7568 */LW_ctrl_241029_1_B.u0 = (rtb_FilterCoefficient_jy_tmp + 9.81) * LW_MASS /
        (real32_T)cos(LW_ctrl_241029_1_B.d_est[0]) / (real32_T)cos
        (LW_ctrl_241029_1_B.d_est[1]);profileEnd_LW_ctrl_241029_1(63U); /* original_line:7570 */

      /* Saturate: '<S14>/Output_Limits2' */
      if (LW_ctrl_241029_1_B.u0 > 40.0) {
        /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
         *  DataTypeConversion: '<S11>/Cast To Single'
         */
        LW_ctrl_241029_1_B.qm[0] = 40.0F;
      } else if (LW_ctrl_241029_1_B.u0 < 0.0) {
        /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
         *  DataTypeConversion: '<S11>/Cast To Single'
         */
        LW_ctrl_241029_1_B.qm[0] = 0.0F;
      } else {
        /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
         *  DataTypeConversion: '<S11>/Cast To Single'
         */
        LW_ctrl_241029_1_B.qm[0] = (real32_T)LW_ctrl_241029_1_B.u0;
      }

      /* End of Saturate: '<S14>/Output_Limits2' */

      /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
       *  Saturate: '<S120>/Saturation'
       *  Saturate: '<S174>/Saturation'
       *  Saturate: '<S66>/Saturation'
       */
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.qm[i + 1] = ((real32_T)
          LW_ctrl_241029_1_ConstP.pooled1[i + 3] * LW_ctrl_241029_1_B.T1 +
          (real32_T)LW_ctrl_241029_1_ConstP.pooled1[i] * (real32_T)
          LW_ctrl_241029_1_B.sigma_idx_3) + (real32_T)
          LW_ctrl_241029_1_ConstP.pooled1[i + 6] * LW_ctrl_241029_1_B.T2;
      }

      rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.qm[1];
      LW_ctrl_241029_1_B.T1 = LW_ctrl_241029_1_B.qm[0];
      LW_ctrl_241029_1_B.T2 = LW_ctrl_241029_1_B.qm[2];
      LW_ctrl_241029_1_B.T3 = LW_ctrl_241029_1_B.qm[3];
      for (i = 0; i < 4; i++) {
        LW_ctrl_241029_1_B.T_c[i] = ((b[i + 4] * rtb_FilterCoefficient_jy_tmp +
          b[i] * LW_ctrl_241029_1_B.T1) + b[i + 8] * LW_ctrl_241029_1_B.T2) +
          b[i + 12] * LW_ctrl_241029_1_B.T3;
      }

      /* '<S17>:1:12' if T(1)<0 */
      if (LW_ctrl_241029_1_B.T_c[0] < 0.0F) {
        /* '<S17>:1:13' T1 = single(0); */
        LW_ctrl_241029_1_B.T1 = 0.0F;
      } else {
        /* '<S17>:1:14' else */
        /* '<S17>:1:15' T1 = T(1); */
        LW_ctrl_241029_1_B.T1 = LW_ctrl_241029_1_B.T_c[0];
      }

      /* '<S17>:1:17' if T(2)<0 */
      if (LW_ctrl_241029_1_B.T_c[1] < 0.0F) {
        /* '<S17>:1:18' T2 = single(0); */
        LW_ctrl_241029_1_B.T2 = 0.0F;
      } else {
        /* '<S17>:1:19' else */
        /* '<S17>:1:20' T2 = T(2); */
        LW_ctrl_241029_1_B.T2 = LW_ctrl_241029_1_B.T_c[1];
      }

      /* '<S17>:1:22' if T(3)<0 */
      if (LW_ctrl_241029_1_B.T_c[2] < 0.0F) {
        /* '<S17>:1:23' T3 = single(0); */
        LW_ctrl_241029_1_B.T3 = 0.0F;
      } else {
        /* '<S17>:1:24' else */
        /* '<S17>:1:25' T3 = T(3); */
        LW_ctrl_241029_1_B.T3 = LW_ctrl_241029_1_B.T_c[2];
      }

      /* '<S17>:1:27' if T(4)<0 */
      if (LW_ctrl_241029_1_B.T_c[3] < 0.0F) {
        /* '<S17>:1:28' T4 = single(0); */
        LW_ctrl_241029_1_B.T4 = 0.0F;
      } else {
        /* '<S17>:1:29' else */
        /* '<S17>:1:30' T4 = T(4); */
        LW_ctrl_241029_1_B.T4 = LW_ctrl_241029_1_B.T_c[3];
      }

      /* Saturate: '<S11>/Output_Limits1' */
      if (LW_ctrl_241029_1_B.T1 > 15.0F) {
        rtb_FilterCoefficient_jy_tmp = 15.0F;
      } else {
        rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.T1;
      }

      /* MATLAB Function: '<S16>/toPWM' */
      LW_ctrl_241029_1_B.T1 =
        LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger6.voltage_filtered_v;

      /* MATLAB Function 'Controller/PID_Controller/PID_Controller/toPWM/toPWM': '<S359>:1' */
      /* '<S359>:1:2' a = ModelParam_motorUp1; */
      /* '<S359>:1:3' b = ModelParam_motorUp2; */
      /* '<S359>:1:4' sigma = zeros(4,1); */
      /* '<S359>:1:5' if batt_connected */
      if (LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger6.connected) {
        /*  4S */
        /* '<S359>:1:7' if voltage < 12.0 */
        if (LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger6.voltage_filtered_v <
            12.0F) {
          /* '<S359>:1:8' voltage = single(12.0); */
          LW_ctrl_241029_1_B.T1 = 12.0F;
        } else if
            (LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger6.voltage_filtered_v >
             17.0F) {
          /* '<S359>:1:9' elseif voltage > 17 */
          /* '<S359>:1:10' voltage = single(17.0); */
          LW_ctrl_241029_1_B.T1 = 17.0F;
        }
      } else {
        /* '<S359>:1:12' else */
        /* '<S359>:1:13' voltage = single(16.0); */
        LW_ctrl_241029_1_B.T1 = 16.0F;
      }

      /* Saturate: '<S11>/Output_Limits1' */
      /* '<S359>:1:16' for i = 1:4 */
      /* '<S359>:1:17' c = ModelParam_motorUp3 - w(i); */
      /* '<S359>:1:18' if a ~= 0 */
      /* '<S359>:1:19' sigma(i) = (-b+sqrt(abs(b^2-4*a*c)))/(2*a)/voltage; */
      /* '<S359>:1:17' c = ModelParam_motorUp3 - w(i); */
      /* '<S359>:1:18' if a ~= 0 */
      /* '<S359>:1:19' sigma(i) = (-b+sqrt(abs(b^2-4*a*c)))/(2*a)/voltage; */
      /* '<S359>:1:17' c = ModelParam_motorUp3 - w(i); */
      /* '<S359>:1:18' if a ~= 0 */
      /* '<S359>:1:19' sigma(i) = (-b+sqrt(abs(b^2-4*a*c)))/(2*a)/voltage; */
      /* '<S359>:1:17' c = ModelParam_motorUp3 - w(i); */
      /* '<S359>:1:18' if a ~= 0 */
      /* '<S359>:1:19' sigma(i) = (-b+sqrt(abs(b^2-4*a*c)))/(2*a)/voltage; */
      if (LW_ctrl_241029_1_B.T4 > 15.0F) {
        LW_ctrl_241029_1_B.T4 = 15.0F;
      }

      /* MATLAB Function: '<S16>/toPWM' incorporates:
       *  Constant: '<S16>/Constant'
       *  Product: '<S16>/Product'
       *  Saturate: '<S11>/Output_Limits1'
       *  Sqrt: '<S16>/Sqrt'
       */
      profileStart_LW_ctrl_241029_1(64U); /* original_line:7715 */LW_ctrl_241029_1_B.sigma_idx_3 = ((real32_T)sqrt(4489.0F - (-12.22F -
        (real32_T)sqrt(LW_ctrl_241029_1_B.T4 * 40983.6055F)) * -4.14F) - 67.0F) /
        -2.07F / LW_ctrl_241029_1_B.T1;profileEnd_LW_ctrl_241029_1(64U); /* original_line:7717 */

      /* '<S359>:1:25' if sigma(i) < -0.2 */
      if (LW_ctrl_241029_1_B.sigma_idx_3 < -0.2) {
        /* '<S359>:1:26' sigma(i) = -0.2; */
        LW_ctrl_241029_1_B.sigma_idx_3 = -0.2;
      } else if (LW_ctrl_241029_1_B.sigma_idx_3 > 1.0) {
        /* '<S359>:1:27' elseif sigma(i) > 1 */
        /* '<S359>:1:28' sigma(i) = 1; */
        LW_ctrl_241029_1_B.sigma_idx_3 = 1.0;
      }

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S16>/Constant'
       *  Constant: '<S9>/Constant1'
       *  MATLAB Function: '<S16>/toPWM'
       *  Product: '<S16>/Product'
       *  Saturate: '<S11>/Output_Limits1'
       *  Sqrt: '<S16>/Sqrt'
       */
      /* '<S359>:1:30' pwm = single(sigma*1000 + 1000); */
      if (rtb_RelationalOperator_om) {
        profileStart_LW_ctrl_241029_1(65U); /* original_line:7739 */rtb_FilterCoefficient_jy_tmp = (real32_T)(((real32_T)sqrt(4489.0F -
          (-12.22F - (real32_T)sqrt(rtb_FilterCoefficient_jy_tmp * 40983.6055F))
          * -4.14F) - 67.0F) / -2.07F / LW_ctrl_241029_1_B.T1 * 1000.0 + 1000.0);profileEnd_LW_ctrl_241029_1(65U); /* original_line:7741 */
      } else {
        rtb_FilterCoefficient_jy_tmp = 900.0F;
      }

      /* Saturate: '<S9>/Saturation' */
      if (rtb_FilterCoefficient_jy_tmp > 2000.0F) {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[0] = 2000.0F;
      } else if (rtb_FilterCoefficient_jy_tmp < 1000.0F) {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[0] = 1000.0F;
      } else {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[0] = rtb_FilterCoefficient_jy_tmp;
      }

      /* Saturate: '<S9>/Saturation' */
      LW_ctrl_241029_1_B.pwm[4] = 1500.0F;

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S16>/Constant'
       *  Constant: '<S9>/Constant1'
       *  MATLAB Function: '<S16>/toPWM'
       *  Product: '<S16>/Product'
       *  Saturate: '<S11>/Output_Limits1'
       *  Sqrt: '<S16>/Sqrt'
       */
      if (rtb_RelationalOperator_om) {
        /* Saturate: '<S11>/Output_Limits1' */
        if (LW_ctrl_241029_1_B.T2 > 15.0F) {
          LW_ctrl_241029_1_B.T2 = 15.0F;
        }

        profileStart_LW_ctrl_241029_1(66U); /* original_line:7775 */rtb_FilterCoefficient_jy_tmp = (real32_T)(((real32_T)sqrt(4489.0F -
          (-12.22F - (real32_T)sqrt(LW_ctrl_241029_1_B.T2 * 40983.6055F)) *
          -4.14F) - 67.0F) / -2.07F / LW_ctrl_241029_1_B.T1 * 1000.0 + 1000.0);profileEnd_LW_ctrl_241029_1(66U); /* original_line:7777 */
      } else {
        rtb_FilterCoefficient_jy_tmp = 900.0F;
      }

      /* Saturate: '<S9>/Saturation' */
      if (rtb_FilterCoefficient_jy_tmp > 2000.0F) {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[1] = 2000.0F;
      } else if (rtb_FilterCoefficient_jy_tmp < 1000.0F) {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[1] = 1000.0F;
      } else {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[1] = rtb_FilterCoefficient_jy_tmp;
      }

      /* Saturate: '<S9>/Saturation' */
      LW_ctrl_241029_1_B.pwm[5] = 1500.0F;

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S16>/Constant'
       *  Constant: '<S9>/Constant1'
       *  MATLAB Function: '<S16>/toPWM'
       *  Product: '<S16>/Product'
       *  Saturate: '<S11>/Output_Limits1'
       *  Sqrt: '<S16>/Sqrt'
       */
      if (rtb_RelationalOperator_om) {
        /* Saturate: '<S11>/Output_Limits1' */
        if (LW_ctrl_241029_1_B.T3 > 15.0F) {
          LW_ctrl_241029_1_B.T3 = 15.0F;
        }

        profileStart_LW_ctrl_241029_1(67U); /* original_line:7811 */rtb_FilterCoefficient_jy_tmp = (real32_T)(((real32_T)sqrt(4489.0F -
          (-12.22F - (real32_T)sqrt(LW_ctrl_241029_1_B.T3 * 40983.6055F)) *
          -4.14F) - 67.0F) / -2.07F / LW_ctrl_241029_1_B.T1 * 1000.0 + 1000.0);profileEnd_LW_ctrl_241029_1(67U); /* original_line:7813 */
      } else {
        rtb_FilterCoefficient_jy_tmp = 900.0F;
      }

      /* Saturate: '<S9>/Saturation' */
      if (rtb_FilterCoefficient_jy_tmp > 2000.0F) {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[2] = 2000.0F;
      } else if (rtb_FilterCoefficient_jy_tmp < 1000.0F) {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[2] = 1000.0F;
      } else {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[2] = rtb_FilterCoefficient_jy_tmp;
      }

      /* Saturate: '<S9>/Saturation' */
      LW_ctrl_241029_1_B.pwm[6] = 1500.0F;

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/Constant1'
       *  MATLAB Function: '<S16>/toPWM'
       */
      if (rtb_RelationalOperator_om) {
        rtb_FilterCoefficient_jy_tmp = (real32_T)(LW_ctrl_241029_1_B.sigma_idx_3
          * 1000.0 + 1000.0);
      } else {
        rtb_FilterCoefficient_jy_tmp = 900.0F;
      }

      /* Saturate: '<S9>/Saturation' */
      if (rtb_FilterCoefficient_jy_tmp < 1000.0F) {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[3] = 1000.0F;
      } else {
        /* Saturate: '<S9>/Saturation' */
        LW_ctrl_241029_1_B.pwm[3] = rtb_FilterCoefficient_jy_tmp;
      }

      /* Saturate: '<S9>/Saturation' */
      LW_ctrl_241029_1_B.pwm[7] = 1500.0F;

      /* DeadZone: '<S51>/DeadZone' */
      if (LW_ctrl_241029_1_B.DeadZone > 102.24140440937498) {
        LW_ctrl_241029_1_B.DeadZone -= 102.24140440937498;
      } else if (LW_ctrl_241029_1_B.DeadZone >= -102.24140440937498) {
        LW_ctrl_241029_1_B.DeadZone = 0.0;
      } else {
        LW_ctrl_241029_1_B.DeadZone -= -102.24140440937498;
      }

      /* End of DeadZone: '<S51>/DeadZone' */

      /* DeadZone: '<S105>/DeadZone' */
      if (LW_ctrl_241029_1_B.DeadZone_p > 111.165F) {
        LW_ctrl_241029_1_B.DeadZone_p -= 111.165F;
      } else if (LW_ctrl_241029_1_B.DeadZone_p >= -111.165F) {
        LW_ctrl_241029_1_B.DeadZone_p = 0.0F;
      } else {
        LW_ctrl_241029_1_B.DeadZone_p -= -111.165F;
      }

      /* End of DeadZone: '<S105>/DeadZone' */

      /* DeadZone: '<S159>/DeadZone' */
      if (LW_ctrl_241029_1_B.DeadZone_ph > 8.70227F) {
        LW_ctrl_241029_1_B.DeadZone_ph -= 8.70227F;
      } else if (LW_ctrl_241029_1_B.DeadZone_ph >= -8.70227F) {
        LW_ctrl_241029_1_B.DeadZone_ph = 0.0F;
      } else {
        LW_ctrl_241029_1_B.DeadZone_ph -= -8.70227F;
      }

      /* End of DeadZone: '<S159>/DeadZone' */

      /* DeadZone: '<S224>/DeadZone' */
      if (LW_ctrl_241029_1_B.DeadZone_e > LW_X_ACCEL_MAX) {
        LW_ctrl_241029_1_B.DeadZone_e -= LW_X_ACCEL_MAX;
      } else if (LW_ctrl_241029_1_B.DeadZone_e >= LW_X_ACCEL_MIN) {
        LW_ctrl_241029_1_B.DeadZone_e = 0.0F;
      } else {
        LW_ctrl_241029_1_B.DeadZone_e -= LW_X_ACCEL_MIN;
      }

      /* End of DeadZone: '<S224>/DeadZone' */

      /* DeadZone: '<S278>/DeadZone' */
      if (LW_ctrl_241029_1_B.DeadZone_el > LW_Y_ACCEL_MAX) {
        LW_ctrl_241029_1_B.DeadZone_el -= LW_Y_ACCEL_MAX;
      } else if (LW_ctrl_241029_1_B.DeadZone_el >= LW_Y_ACCEL_MIN) {
        LW_ctrl_241029_1_B.DeadZone_el = 0.0F;
      } else {
        LW_ctrl_241029_1_B.DeadZone_el -= LW_Y_ACCEL_MIN;
      }

      /* End of DeadZone: '<S278>/DeadZone' */

      /* DeadZone: '<S332>/DeadZone' */
      if (LW_ctrl_241029_1_B.eta_p > LW_Z_ACCEL_UP) {
        LW_ctrl_241029_1_B.eta_p -= LW_Z_ACCEL_UP;
      } else if (LW_ctrl_241029_1_B.eta_p >= LW_Z_ACCEL_LOW) {
        LW_ctrl_241029_1_B.eta_p = 0.0F;
      } else {
        LW_ctrl_241029_1_B.eta_p -= LW_Z_ACCEL_LOW;
      }

      /* End of DeadZone: '<S332>/DeadZone' */

      /* Gain: '<S337>/Integral Gain' */
      LW_ctrl_241029_1_B.IntegralGain *= 0.3F;

      /* Update for DiscreteIntegrator: '<S340>/Integrator' */
      LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE = 0U;
      LW_ctrl_241029_1_DW.Integrator_DSTATE = LW_ctrl_241029_1_B.km_f_b;
      LW_ctrl_241029_1_DW.Integrator_PrevResetState = (int8_T)
        rtb_integral_reset_idx_1;

      /* Switch: '<S330>/Switch1' incorporates:
       *  Constant: '<S330>/Clamping_zero'
       *  Constant: '<S330>/Constant'
       *  Constant: '<S330>/Constant2'
       *  RelationalOperator: '<S330>/fix for DT propagation issue'
       */
      if (LW_ctrl_241029_1_B.eta_p > 0.0F) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      /* Switch: '<S330>/Switch2' incorporates:
       *  Constant: '<S330>/Clamping_zero'
       *  Constant: '<S330>/Constant3'
       *  Constant: '<S330>/Constant4'
       *  RelationalOperator: '<S330>/fix for DT propagation issue1'
       */
      if (LW_ctrl_241029_1_B.IntegralGain > 0.0F) {
        tmp_0 = 1;
      } else {
        tmp_0 = -1;
      }

      /* Switch: '<S330>/Switch' incorporates:
       *  Constant: '<S330>/Clamping_zero'
       *  Logic: '<S330>/AND3'
       *  RelationalOperator: '<S330>/Equal1'
       *  RelationalOperator: '<S330>/Relational Operator'
       *  Switch: '<S330>/Switch1'
       *  Switch: '<S330>/Switch2'
       */
      if ((LW_ctrl_241029_1_B.eta_p != 0.0F) && (tmp == tmp_0)) {
        /* Update for DiscreteIntegrator: '<S340>/Integrator' incorporates:
         *  Constant: '<S330>/Constant1'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U = 0.0F;
      } else {
        /* Update for DiscreteIntegrator: '<S340>/Integrator' */
        LW_ctrl_241029_1_DW.Integrator_PREV_U = LW_ctrl_241029_1_B.IntegralGain;
      }

      /* End of Switch: '<S330>/Switch' */

      /* Update for DiscreteIntegrator: '<S335>/Filter' incorporates:
       *  DiscreteIntegrator: '<S340>/Integrator'
       */
      LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE = 0U;
      LW_ctrl_241029_1_DW.Filter_DSTATE_f = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_DW.Filter_PrevResetState = (int8_T)
        rtb_integral_reset_idx_1;
      LW_ctrl_241029_1_DW.Filter_PREV_U_e = LW_ctrl_241029_1_B.kappa;

      /* Update for DiscreteIntegrator: '<S232>/Integrator' */
      LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_l = 0U;
      LW_ctrl_241029_1_DW.Integrator_DSTATE_h = LW_ctrl_241029_1_B.time_to_stop;
      LW_ctrl_241029_1_DW.Integrator_PrevResetState_m = (int8_T)
        rtb_integral_reset_idx_0;

      /* Switch: '<S222>/Switch1' incorporates:
       *  Constant: '<S222>/Clamping_zero'
       *  Constant: '<S222>/Constant'
       *  Constant: '<S222>/Constant2'
       *  RelationalOperator: '<S222>/fix for DT propagation issue'
       */
      if (LW_ctrl_241029_1_B.DeadZone_e > 0.0F) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      /* Switch: '<S222>/Switch' incorporates:
       *  Constant: '<S222>/Clamping_zero'
       *  Logic: '<S222>/AND3'
       *  RelationalOperator: '<S222>/Equal1'
       *  RelationalOperator: '<S222>/Relational Operator'
       *  Switch: '<S222>/Switch1'
       *  Switch: '<S222>/Switch2'
       */
      if ((LW_ctrl_241029_1_B.DeadZone_e != 0.0F) && (tmp == -1)) {
        /* Update for DiscreteIntegrator: '<S232>/Integrator' incorporates:
         *  Constant: '<S222>/Constant1'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_f = 0.0F;
      } else {
        /* Update for DiscreteIntegrator: '<S232>/Integrator' incorporates:
         *  Gain: '<S229>/Integral Gain'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_f = 0.0F *
          LW_ctrl_241029_1_B.theta;
      }

      /* End of Switch: '<S222>/Switch' */

      /* Update for DiscreteIntegrator: '<S227>/Filter' incorporates:
       *  DiscreteIntegrator: '<S232>/Integrator'
       */
      LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_k = 0U;
      LW_ctrl_241029_1_DW.Filter_DSTATE_e = LW_ctrl_241029_1_B.delta_t;
      LW_ctrl_241029_1_DW.Filter_PrevResetState_f = (int8_T)
        rtb_integral_reset_idx_0;
      LW_ctrl_241029_1_DW.Filter_PREV_U_b =
        LW_ctrl_241029_1_B.FilterCoefficient_jy;

      /* Update for DiscreteIntegrator: '<S286>/Integrator' incorporates:
       *  DiscreteIntegrator: '<S232>/Integrator'
       */
      LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_d = 0U;
      LW_ctrl_241029_1_DW.Integrator_DSTATE_n = LW_ctrl_241029_1_B.Integrator_a;
      LW_ctrl_241029_1_DW.Integrator_PrevResetState_f = (int8_T)
        rtb_integral_reset_idx_0;

      /* Switch: '<S276>/Switch1' incorporates:
       *  Constant: '<S276>/Clamping_zero'
       *  Constant: '<S276>/Constant'
       *  Constant: '<S276>/Constant2'
       *  RelationalOperator: '<S276>/fix for DT propagation issue'
       */
      if (LW_ctrl_241029_1_B.DeadZone_el > 0.0F) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      /* Switch: '<S276>/Switch' incorporates:
       *  Constant: '<S276>/Clamping_zero'
       *  Logic: '<S276>/AND3'
       *  RelationalOperator: '<S276>/Equal1'
       *  RelationalOperator: '<S276>/Relational Operator'
       *  Switch: '<S276>/Switch1'
       *  Switch: '<S276>/Switch2'
       */
      if ((LW_ctrl_241029_1_B.DeadZone_el != 0.0F) && (tmp == -1)) {
        /* Update for DiscreteIntegrator: '<S286>/Integrator' incorporates:
         *  Constant: '<S276>/Constant1'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_l = 0.0F;
      } else {
        /* Update for DiscreteIntegrator: '<S286>/Integrator' incorporates:
         *  Gain: '<S283>/Integral Gain'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_l = 0.0F *
          LW_ctrl_241029_1_B.IntegralGain_gt;
      }

      /* End of Switch: '<S276>/Switch' */

      /* Update for DiscreteIntegrator: '<S281>/Filter' incorporates:
       *  DiscreteIntegrator: '<S232>/Integrator'
       */
      LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_j = 0U;
      LW_ctrl_241029_1_DW.Filter_DSTATE_p = LW_ctrl_241029_1_B.Filter_l;
      LW_ctrl_241029_1_DW.Filter_PrevResetState_b = (int8_T)
        rtb_integral_reset_idx_0;
      LW_ctrl_241029_1_DW.Filter_PREV_U_h =
        LW_ctrl_241029_1_B.FilterCoefficient_l;

      /* Update for DiscreteIntegrator: '<S59>/Integrator' */
      LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_ls = 0U;
      LW_ctrl_241029_1_DW.Integrator_DSTATE_j = LW_ctrl_241029_1_B.b_c;
      LW_ctrl_241029_1_DW.Integrator_PrevResetState_o = (int8_T)want_hold_xy;

      /* Switch: '<S49>/Switch1' incorporates:
       *  Constant: '<S49>/Constant'
       *  Constant: '<S49>/Constant2'
       *  RelationalOperator: '<S49>/fix for DT propagation issue'
       */
      if (LW_ctrl_241029_1_B.DeadZone > 0.0) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      /* Switch: '<S49>/Switch' incorporates:
       *  Logic: '<S49>/AND3'
       *  RelationalOperator: '<S49>/Equal1'
       *  RelationalOperator: '<S49>/Relational Operator'
       *  Switch: '<S49>/Switch1'
       *  Switch: '<S49>/Switch2'
       */
      if ((LW_ctrl_241029_1_B.DeadZone != 0.0) && (tmp == -1)) {
        /* Update for DiscreteIntegrator: '<S59>/Integrator' incorporates:
         *  Constant: '<S49>/Constant1'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_m = 0.0F;
      } else {
        /* Update for DiscreteIntegrator: '<S59>/Integrator' incorporates:
         *  Gain: '<S56>/Integral Gain'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_m = 0.0F *
          LW_ctrl_241029_1_B.aSinInput;
      }

      /* End of Switch: '<S49>/Switch' */

      /* Update for DiscreteIntegrator: '<S54>/Filter' incorporates:
       *  DiscreteIntegrator: '<S59>/Integrator'
       */
      LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_m = 0U;
      LW_ctrl_241029_1_DW.Filter_DSTATE = LW_ctrl_241029_1_B.Saturation_d;
      LW_ctrl_241029_1_DW.Filter_PrevResetState_m = (int8_T)want_hold_xy;
      LW_ctrl_241029_1_DW.Filter_PREV_U = LW_ctrl_241029_1_B.FilterCoefficient;

      /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
       *  DiscreteIntegrator: '<S59>/Integrator'
       */
      LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_n = 0U;
      LW_ctrl_241029_1_DW.Integrator_DSTATE_m = q;
      LW_ctrl_241029_1_DW.Integrator_PrevResetState_mv = (int8_T)want_hold_xy;

      /* Switch: '<S103>/Switch1' incorporates:
       *  Constant: '<S103>/Clamping_zero'
       *  Constant: '<S103>/Constant'
       *  Constant: '<S103>/Constant2'
       *  RelationalOperator: '<S103>/fix for DT propagation issue'
       */
      if (LW_ctrl_241029_1_B.DeadZone_p > 0.0F) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      /* Switch: '<S103>/Switch' incorporates:
       *  Constant: '<S103>/Clamping_zero'
       *  Logic: '<S103>/AND3'
       *  RelationalOperator: '<S103>/Equal1'
       *  RelationalOperator: '<S103>/Relational Operator'
       *  Switch: '<S103>/Switch1'
       *  Switch: '<S103>/Switch2'
       */
      if ((LW_ctrl_241029_1_B.DeadZone_p != 0.0F) && (tmp == -1)) {
        /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
         *  Constant: '<S103>/Constant1'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_a = 0.0F;
      } else {
        /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
         *  Gain: '<S110>/Integral Gain'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_a = 0.0F * LW_ctrl_241029_1_B.c_b;
      }

      /* End of Switch: '<S103>/Switch' */

      /* Update for DiscreteIntegrator: '<S108>/Filter' incorporates:
       *  DiscreteIntegrator: '<S59>/Integrator'
       */
      LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_n = 0U;
      LW_ctrl_241029_1_DW.Filter_DSTATE_fv = LW_ctrl_241029_1_B.Filter_o;
      LW_ctrl_241029_1_DW.Filter_PrevResetState_p = (int8_T)want_hold_xy;
      LW_ctrl_241029_1_DW.Filter_PREV_U_j =
        LW_ctrl_241029_1_B.FilterCoefficient_i;

      /* Update for DiscreteIntegrator: '<S167>/Integrator' incorporates:
       *  DiscreteIntegrator: '<S59>/Integrator'
       */
      LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_j = 0U;
      LW_ctrl_241029_1_DW.Integrator_DSTATE_a = LW_ctrl_241029_1_B.Integrator_f;
      LW_ctrl_241029_1_DW.Integrator_PrevResetState_fl = (int8_T)want_hold_xy;

      /* Switch: '<S157>/Switch1' incorporates:
       *  Constant: '<S157>/Clamping_zero'
       *  Constant: '<S157>/Constant'
       *  Constant: '<S157>/Constant2'
       *  RelationalOperator: '<S157>/fix for DT propagation issue'
       */
      if (LW_ctrl_241029_1_B.DeadZone_ph > 0.0F) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      /* Switch: '<S157>/Switch' incorporates:
       *  Constant: '<S157>/Clamping_zero'
       *  Logic: '<S157>/AND3'
       *  RelationalOperator: '<S157>/Equal1'
       *  RelationalOperator: '<S157>/Relational Operator'
       *  Switch: '<S157>/Switch1'
       *  Switch: '<S157>/Switch2'
       */
      if ((LW_ctrl_241029_1_B.DeadZone_ph != 0.0F) && (tmp == -1)) {
        /* Update for DiscreteIntegrator: '<S167>/Integrator' incorporates:
         *  Constant: '<S157>/Constant1'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_d = 0.0F;
      } else {
        /* Update for DiscreteIntegrator: '<S167>/Integrator' incorporates:
         *  Gain: '<S164>/Integral Gain'
         */
        LW_ctrl_241029_1_DW.Integrator_PREV_U_d = 0.0F *
          LW_ctrl_241029_1_B.IntegralGain_n;
      }

      /* End of Switch: '<S157>/Switch' */

      /* Update for DiscreteIntegrator: '<S162>/Filter' incorporates:
       *  DiscreteIntegrator: '<S59>/Integrator'
       */
      LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_b = 0U;
      LW_ctrl_241029_1_DW.Filter_DSTATE_i = Filter_o5;
      LW_ctrl_241029_1_DW.Filter_PrevResetState_i = (int8_T)want_hold_xy;
      LW_ctrl_241029_1_DW.Filter_PREV_U_n =
        LW_ctrl_241029_1_B.FilterCoefficient_k;

      /* End of Outputs for SubSystem: '<S1>/PID_Controller' */
    }

    /* '<S3>:1:4' sf_internal_predicateOutput = every(Mixer_cycle,tick); */
    /* '<S3>:1:5' sf_internal_predicateOutput = every(PosCtrl_cycle,tick); */
    /* '<S3>:1:6' sf_internal_predicateOutput = every(Navigator_cycle,tick); */
    if (LW_ctrl_241029_1_DW.temporalCounter_i5 == 1U) {
      /* Outputs for Function Call SubSystem: '<Root>/navigator' */
      /* SwitchCase: '<S4>/Switch Case' */
      /* '<S3>:1:6' send(Navigator); */
      /* Event: '<S3>:9' */
      if (LW_ctrl_241029_1_B.flight_mode == PILOT) {
        /* Outputs for IfAction SubSystem: '<S4>/navigator_manual' incorporates:
         *  ActionPort: '<S370>/Action Port'
         */
        /* MATLAB Function: '<S370>/nan_inf11' */
        profileStart_LW_ctrl_241029_1(68U); /* original_line:8251 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.r,
          &LW_ctrl_241029_1_B.sf_nan_inf11);profileEnd_LW_ctrl_241029_1(68U); /* original_line:8252 */

        /* MATLAB Function: '<S370>/yawrate_deadzone1' */
        profileStart_LW_ctrl_241029_1(69U); /* original_line:8255 */LW_ctrl_241_pitchrate_deadzone1(LW_ctrl_241029_1_B.sf_nan_inf11.y,
          &LW_ctrl_241029_1_B.sf_yawrate_deadzone1);profileEnd_LW_ctrl_241029_1(69U); /* original_line:8256 */

        /* MATLAB Function: '<S370>/nan_inf4' */
        profileStart_LW_ctrl_241029_1(70U); /* original_line:8259 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.r,
          &LW_ctrl_241029_1_B.sf_nan_inf4);profileEnd_LW_ctrl_241029_1(70U); /* original_line:8260 */

        /* MATLAB Function: '<S370>/yawrate_deadzone' */
        /* Function description: */
        /*   set a dead zone with a dead zone size of ±deadZone. */
        /* MATLAB Function 'navigator/navigator_manual/yawrate_deadzone': '<S400>:1' */
        /* '<S400>:1:4' RCMin = single(-1); */
        /* '<S400>:1:5' RCMax = single(1); */
        /* '<S400>:1:6' RCMid = ((RCMin + RCMax)/2); */
        /* '<S400>:1:7' deadZone = LW_MAN_WZ_DZ; */
        /* '<S400>:1:8' k = 1/(RCMax - RCMid - deadZone); */
        LW_ctrl_241029_1_B.kappa = 1.0F / (1.0F - LW_MAN_WZ_DZ);

        /* dead zone */
        /* '<S400>:1:11' if(u > RCMid + deadZone) */
        if (LW_ctrl_241029_1_B.sf_nan_inf4.y > LW_MAN_WZ_DZ) {
          /* '<S400>:1:12' y = single((u-RCMid - deadZone)*k); */
          LW_ctrl_241029_1_B.IntegralGain = (LW_ctrl_241029_1_B.sf_nan_inf4.y -
            LW_MAN_WZ_DZ) * LW_ctrl_241029_1_B.kappa;
        } else if (LW_ctrl_241029_1_B.sf_nan_inf4.y < 0.0F - LW_MAN_WZ_DZ) {
          /* '<S400>:1:13' elseif(u < RCMid - deadZone) */
          /* '<S400>:1:14' y = single((u - RCMid + deadZone)*k); */
          LW_ctrl_241029_1_B.IntegralGain = (LW_ctrl_241029_1_B.sf_nan_inf4.y +
            LW_MAN_WZ_DZ) * LW_ctrl_241029_1_B.kappa;
        } else {
          /* '<S400>:1:15' else */
          /* '<S400>:1:16' y = single(0); */
          LW_ctrl_241029_1_B.IntegralGain = 0.0F;
        }

        /* End of MATLAB Function: '<S370>/yawrate_deadzone' */

        /* MATLAB Function: '<S370>/nan_inf9' */
        profileStart_LW_ctrl_241029_1(71U); /* original_line:8293 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.y_b,
          &LW_ctrl_241029_1_B.sf_nan_inf9);profileEnd_LW_ctrl_241029_1(71U); /* original_line:8294 */

        /* MATLAB Function: '<S370>/rollrate_deadzone1' */
        profileStart_LW_ctrl_241029_1(72U); /* original_line:8297 */LW_ctrl_241_pitchrate_deadzone1(LW_ctrl_241029_1_B.sf_nan_inf9.y,
          &LW_ctrl_241029_1_B.sf_rollrate_deadzone1);profileEnd_LW_ctrl_241029_1(72U); /* original_line:8298 */

        /* MATLAB Function: '<S370>/nan_inf5' */
        profileStart_LW_ctrl_241029_1(73U); /* original_line:8301 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.z,
          &LW_ctrl_241029_1_B.sf_nan_inf5);profileEnd_LW_ctrl_241029_1(73U); /* original_line:8302 */

        /* MATLAB Function: '<S370>/f1' incorporates:
         *  Constant: '<S370>/Constant2'
         */
        /* Function description: */
        /*   throttle curve. When the throttle is in the middle position, the output */
        /*   is hovering throttle value. */
        /* Input: */
        /*   in: normalized throttle, range from 0 to 1 */
        /*   hover: hovering throttle value */
        /* Output: */
        /*   y: processed throttle value */
        /* MATLAB Function 'navigator/navigator_manual/f1': '<S378>:1' */
        /* '<S378>:1:10' if in < 0.5 */
        if (LW_ctrl_241029_1_B.sf_nan_inf5.y < 0.5F) {
          /* '<S378>:1:11' y=2 * in * hover; */
          LW_ctrl_241029_1_B.km_f_b = 2.0F * LW_ctrl_241029_1_B.sf_nan_inf5.y *
            LW_THR_HOVER;
        } else {
          /* '<S378>:1:12' else */
          /* '<S378>:1:13' y=hover + 2 * (in - 0.5) * (1.0 - hover); */
          LW_ctrl_241029_1_B.km_f_b = (LW_ctrl_241029_1_B.sf_nan_inf5.y - 0.5F) *
            2.0F * (1.0F - LW_THR_HOVER) + LW_THR_HOVER;
        }

        /* End of MATLAB Function: '<S370>/f1' */

        /* Gain: '<S370>/Gain5' */
        LW_ctrl_241029_1_B.Filter_o = 30.9556293F * LW_ctrl_241029_1_B.km_f_b;

        /* Saturate: '<S370>/Saturation10' */
        if (LW_ctrl_241029_1_B.Filter_o > 14.8F) {
          LW_ctrl_241029_1_B.Filter_o = 14.8F;
        } else if (LW_ctrl_241029_1_B.Filter_o < 0.0F) {
          LW_ctrl_241029_1_B.Filter_o = 0.0F;
        }

        /* Gain: '<S370>/Gain4' incorporates:
         *  Saturate: '<S370>/Saturation10'
         */
        LW_ctrl_241029_1_B.thrust = -LW_MASS * LW_ctrl_241029_1_B.Filter_o;

        /* MATLAB Function: '<S370>/nan_inf2' */
        profileStart_LW_ctrl_241029_1(74U); /* original_line:8346 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.y_b,
          &LW_ctrl_241029_1_B.sf_nan_inf2);profileEnd_LW_ctrl_241029_1(74U); /* original_line:8347 */

        /* MATLAB Function: '<S370>/rollrate_deadzone' */
        /* Function description: */
        /*   set a dead zone with a dead zone size of ±deadZone. */
        /* MATLAB Function 'navigator/navigator_manual/rollrate_deadzone': '<S395>:1' */
        /* '<S395>:1:4' RCMin = single(-1); */
        /* '<S395>:1:5' RCMax = single(1); */
        /* '<S395>:1:6' RCMid = ((RCMin + RCMax)/2); */
        /* '<S395>:1:7' deadZone = LW_MAN_WX_DZ; */
        /* '<S395>:1:8' k = 1/(RCMax - RCMid - deadZone); */
        LW_ctrl_241029_1_B.kappa = 1.0F / (1.0F - LW_MAN_WX_DZ);

        /* dead zone */
        /* '<S395>:1:11' if(u > RCMid + deadZone) */
        if (LW_ctrl_241029_1_B.sf_nan_inf2.y > LW_MAN_WX_DZ) {
          /* '<S395>:1:12' y = single((u-RCMid - deadZone)*k); */
          LW_ctrl_241029_1_B.km_f_b = (LW_ctrl_241029_1_B.sf_nan_inf2.y -
            LW_MAN_WX_DZ) * LW_ctrl_241029_1_B.kappa;
        } else if (LW_ctrl_241029_1_B.sf_nan_inf2.y < 0.0F - LW_MAN_WX_DZ) {
          /* '<S395>:1:13' elseif(u < RCMid - deadZone) */
          /* '<S395>:1:14' y = single((u - RCMid + deadZone)*k); */
          LW_ctrl_241029_1_B.km_f_b = (LW_ctrl_241029_1_B.sf_nan_inf2.y +
            LW_MAN_WX_DZ) * LW_ctrl_241029_1_B.kappa;
        } else {
          /* '<S395>:1:15' else */
          /* '<S395>:1:16' y = single(0); */
          LW_ctrl_241029_1_B.km_f_b = 0.0F;
        }

        /* End of MATLAB Function: '<S370>/rollrate_deadzone' */

        /* MATLAB Function: '<S370>/nan_inf3' */
        profileStart_LW_ctrl_241029_1(75U); /* original_line:8380 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.x,
          &LW_ctrl_241029_1_B.sf_nan_inf3);profileEnd_LW_ctrl_241029_1(75U); /* original_line:8381 */

        /* MATLAB Function: '<S370>/pitchrate_deadzone' */
        /* Function description: */
        /*   set a dead zone with a dead zone size of ±deadZone. */
        /* MATLAB Function 'navigator/navigator_manual/pitchrate_deadzone': '<S392>:1' */
        /* '<S392>:1:4' RCMin = single(-1); */
        /* '<S392>:1:5' RCMax = single(1); */
        /* '<S392>:1:6' RCMid = ((RCMin + RCMax)/2); */
        /* '<S392>:1:7' deadZone = LW_MAN_WY_DZ; */
        /* '<S392>:1:8' k = 1/(RCMax - RCMid - deadZone); */
        LW_ctrl_241029_1_B.kappa = 1.0F / (1.0F - LW_MAN_WY_DZ);

        /* dead zone */
        /* '<S392>:1:11' if(u > RCMid + deadZone) */
        if (LW_ctrl_241029_1_B.sf_nan_inf3.y > LW_MAN_WY_DZ) {
          /* '<S392>:1:12' y = single((u-RCMid - deadZone)*k); */
          LW_ctrl_241029_1_B.Va_ = (LW_ctrl_241029_1_B.sf_nan_inf3.y -
            LW_MAN_WY_DZ) * LW_ctrl_241029_1_B.kappa;
        } else if (LW_ctrl_241029_1_B.sf_nan_inf3.y < 0.0F - LW_MAN_WY_DZ) {
          /* '<S392>:1:13' elseif(u < RCMid - deadZone) */
          /* '<S392>:1:14' y = single((u - RCMid + deadZone)*k); */
          LW_ctrl_241029_1_B.Va_ = (LW_ctrl_241029_1_B.sf_nan_inf3.y +
            LW_MAN_WY_DZ) * LW_ctrl_241029_1_B.kappa;
        } else {
          /* '<S392>:1:15' else */
          /* '<S392>:1:16' y = single(0); */
          LW_ctrl_241029_1_B.Va_ = 0.0F;
        }

        /* End of MATLAB Function: '<S370>/pitchrate_deadzone' */

        /* MATLAB Function: '<S370>/nan_inf10' */
        profileStart_LW_ctrl_241029_1(76U); /* original_line:8414 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.x,
          &LW_ctrl_241029_1_B.sf_nan_inf10);profileEnd_LW_ctrl_241029_1(76U); /* original_line:8415 */

        /* MATLAB Function: '<S370>/pitchrate_deadzone1' */
        profileStart_LW_ctrl_241029_1(77U); /* original_line:8418 */LW_ctrl_241_pitchrate_deadzone1(LW_ctrl_241029_1_B.sf_nan_inf10.y,
          &LW_ctrl_241029_1_B.sf_pitchrate_deadzone1);profileEnd_LW_ctrl_241029_1(77U); /* original_line:8419 */

        /* MATLAB Function: '<S370>/nan_inf6' */
        profileStart_LW_ctrl_241029_1(78U); /* original_line:8422 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.x,
          &LW_ctrl_241029_1_B.sf_nan_inf6);profileEnd_LW_ctrl_241029_1(78U); /* original_line:8423 */

        /* MATLAB Function: '<S370>/vx_deadzone' */
        /* Function description: */
        /*   set a dead zone with a dead zone size of ±deadZone. */
        /* MATLAB Function 'navigator/navigator_manual/vx_deadzone': '<S397>:1' */
        /* '<S397>:1:4' RCMin = single(-1); */
        /* '<S397>:1:5' RCMax = single(1); */
        /* '<S397>:1:6' RCMid = ((RCMin + RCMax)/2); */
        /* '<S397>:1:7' deadZone = LW_X_VEL_DZ; */
        /* '<S397>:1:8' k = 1/(RCMax - RCMid - deadZone); */
        LW_ctrl_241029_1_B.kappa = 1.0F / (1.0F - LW_X_VEL_DZ);

        /* dead zone */
        /* '<S397>:1:11' if(u > RCMid + deadZone) */
        if (LW_ctrl_241029_1_B.sf_nan_inf6.y > LW_X_VEL_DZ) {
          /* MATLAB Function: '<S370>/Lowpass' */
          /* '<S397>:1:12' y = single((u-RCMid - deadZone)*k); */
          LW_ctrl_241029_1_B.sf_Lowpass.data_in =
            (LW_ctrl_241029_1_B.sf_nan_inf6.y - LW_X_VEL_DZ) *
            LW_ctrl_241029_1_B.kappa;
        } else if (LW_ctrl_241029_1_B.sf_nan_inf6.y < 0.0F - LW_X_VEL_DZ) {
          /* MATLAB Function: '<S370>/Lowpass' */
          /* '<S397>:1:13' elseif(u < RCMid - deadZone) */
          /* '<S397>:1:14' y = single((u - RCMid + deadZone)*k); */
          LW_ctrl_241029_1_B.sf_Lowpass.data_in =
            (LW_ctrl_241029_1_B.sf_nan_inf6.y + LW_X_VEL_DZ) *
            LW_ctrl_241029_1_B.kappa;
        } else {
          /* MATLAB Function: '<S370>/Lowpass' */
          /* '<S397>:1:15' else */
          /* '<S397>:1:16' y = single(0); */
          LW_ctrl_241029_1_B.sf_Lowpass.data_in = 0.0F;
        }

        /* End of MATLAB Function: '<S370>/vx_deadzone' */

        /* MATLAB Function: '<S370>/Lowpass' */
        profileStart_LW_ctrl_241029_1(79U); /* original_line:8461 */LW_ctrl_241029_1_Lowpass(&LW_ctrl_241029_1_B.sf_Lowpass,
          &LW_ctrl_241029_1_DW.sf_Lowpass);profileEnd_LW_ctrl_241029_1(79U); /* original_line:8462 */

        /* MATLAB Function: '<S370>/nan_inf7' */
        profileStart_LW_ctrl_241029_1(80U); /* original_line:8465 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.y_b,
          &LW_ctrl_241029_1_B.sf_nan_inf7);profileEnd_LW_ctrl_241029_1(80U); /* original_line:8466 */

        /* MATLAB Function: '<S370>/vy_deadzone' */
        /* Function description: */
        /*   set a dead zone with a dead zone size of ±deadZone. */
        /* MATLAB Function 'navigator/navigator_manual/vy_deadzone': '<S398>:1' */
        /* '<S398>:1:4' RCMin = single(-1); */
        /* '<S398>:1:5' RCMax = single(1); */
        /* '<S398>:1:6' RCMid = ((RCMin + RCMax)/2); */
        /* '<S398>:1:7' deadZone = LW_Y_VEL_DZ; */
        /* '<S398>:1:8' k = 1/(RCMax - RCMid - deadZone); */
        LW_ctrl_241029_1_B.kappa = 1.0F / (1.0F - LW_Y_VEL_DZ);

        /* dead zone */
        /* '<S398>:1:11' if(u > RCMid + deadZone) */
        if (LW_ctrl_241029_1_B.sf_nan_inf7.y > LW_Y_VEL_DZ) {
          /* '<S398>:1:12' y = single((u-RCMid - deadZone)*k); */
          LW_ctrl_241029_1_B.sf_Lowpass1.data_in =
            (LW_ctrl_241029_1_B.sf_nan_inf7.y - LW_Y_VEL_DZ) *
            LW_ctrl_241029_1_B.kappa;
        } else if (LW_ctrl_241029_1_B.sf_nan_inf7.y < 0.0F - LW_Y_VEL_DZ) {
          /* '<S398>:1:13' elseif(u < RCMid - deadZone) */
          /* '<S398>:1:14' y = single((u - RCMid + deadZone)*k); */
          LW_ctrl_241029_1_B.sf_Lowpass1.data_in =
            (LW_ctrl_241029_1_B.sf_nan_inf7.y + LW_Y_VEL_DZ) *
            LW_ctrl_241029_1_B.kappa;
        } else {
          /* '<S398>:1:15' else */
          /* '<S398>:1:16' y = single(0); */
          LW_ctrl_241029_1_B.sf_Lowpass1.data_in = 0.0F;
        }

        /* End of MATLAB Function: '<S370>/vy_deadzone' */

        /* MATLAB Function: '<S370>/Lowpass1' */
        profileStart_LW_ctrl_241029_1(81U); /* original_line:8501 */LW_ctrl_241029_1_Lowpass(&LW_ctrl_241029_1_B.sf_Lowpass1,
          &LW_ctrl_241029_1_DW.sf_Lowpass1);profileEnd_LW_ctrl_241029_1(81U); /* original_line:8502 */

        /* MATLAB Function: '<S370>/nan_inf8' */
        profileStart_LW_ctrl_241029_1(82U); /* original_line:8505 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.z,
          &LW_ctrl_241029_1_B.sf_nan_inf8);profileEnd_LW_ctrl_241029_1(82U); /* original_line:8506 */

        /* MATLAB Function: '<S370>/vz_deadzone' */
        /* Function description: */
        /*   set a dead zone with a dead zone size of ±deadZone. */
        /*  u:0-1 */
        /* MATLAB Function 'navigator/navigator_manual/vz_deadzone': '<S399>:1' */
        /* '<S399>:1:5' u = u*2 - 1; */
        LW_ctrl_241029_1_B.eta_p = LW_ctrl_241029_1_B.sf_nan_inf8.y * 2.0F -
          1.0F;

        /*  -1~1 */
        /* '<S399>:1:6' RCMin = single(-1); */
        /* '<S399>:1:7' RCMax = single(1); */
        /* '<S399>:1:8' RCMid = ((RCMin + RCMax)/2); */
        /* '<S399>:1:9' deadZone = LW_Z_VEL_DZ; */
        /* '<S399>:1:10' k = 1/(RCMax - RCMid - deadZone); */
        LW_ctrl_241029_1_B.kappa = 1.0F / (1.0F - LW_Z_VEL_DZ);

        /* dead zone */
        /* '<S399>:1:13' if(u > RCMid + deadZone) */
        if (LW_ctrl_241029_1_B.eta_p > LW_Z_VEL_DZ) {
          /* '<S399>:1:14' y = single((u-RCMid - deadZone)*k); */
          LW_ctrl_241029_1_B.sf_Lowpass2.data_in = (LW_ctrl_241029_1_B.eta_p -
            LW_Z_VEL_DZ) * LW_ctrl_241029_1_B.kappa;
        } else if (LW_ctrl_241029_1_B.eta_p < 0.0F - LW_Z_VEL_DZ) {
          /* '<S399>:1:15' elseif(u < RCMid - deadZone) */
          /* '<S399>:1:16' y = single((u - RCMid + deadZone)*k); */
          LW_ctrl_241029_1_B.sf_Lowpass2.data_in = (LW_ctrl_241029_1_B.eta_p +
            LW_Z_VEL_DZ) * LW_ctrl_241029_1_B.kappa;
        } else {
          /* '<S399>:1:17' else */
          /* '<S399>:1:18' y = single(0); */
          LW_ctrl_241029_1_B.sf_Lowpass2.data_in = 0.0F;
        }

        /* End of MATLAB Function: '<S370>/vz_deadzone' */

        /* MATLAB Function: '<S370>/Lowpass2' */
        profileStart_LW_ctrl_241029_1(83U); /* original_line:8545 */LW_ctrl_241029_1_Lowpass(&LW_ctrl_241029_1_B.sf_Lowpass2,
          &LW_ctrl_241029_1_DW.sf_Lowpass2);profileEnd_LW_ctrl_241029_1(83U); /* original_line:8546 */

        /* SignalConversion generated from: '<S370>/Constant' incorporates:
         *  Constant: '<S370>/Constant'
         */
        LW_ctrl_241029_1_B.yaw_ref_n = 0.0F;

        /* MATLAB Function: '<S370>/nan_inf0' */
        profileStart_LW_ctrl_241029_1(84U); /* original_line:8554 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.y_b,
          &LW_ctrl_241029_1_B.sf_nan_inf0);profileEnd_LW_ctrl_241029_1(84U); /* original_line:8555 */

        /* MATLAB Function: '<S370>/roll_deadzone' */
        /* Function description: */
        /*   set a dead zone with a dead zone size of ±deadZone. */
        /* MATLAB Function 'navigator/navigator_manual/roll_deadzone': '<S394>:1' */
        /* '<S394>:1:4' RCMin = single(-1); */
        /* '<S394>:1:5' RCMax = single(1); */
        /* '<S394>:1:6' RCMid = ((RCMin + RCMax)/2); */
        /* '<S394>:1:7' deadZone = LW_MAN_ROLL_DZ; */
        /* '<S394>:1:8' k = 1/(RCMax - RCMid - deadZone); */
        LW_ctrl_241029_1_B.kappa = 1.0F / (1.0F - LW_MAN_ROLL_DZ);

        /* dead zone */
        /* '<S394>:1:11' if(u > RCMid + deadZone) */
        if (LW_ctrl_241029_1_B.sf_nan_inf0.y > LW_MAN_ROLL_DZ) {
          /* '<S394>:1:12' y = single((u-RCMid - deadZone)*k); */
          LW_ctrl_241029_1_B.kappa *= LW_ctrl_241029_1_B.sf_nan_inf0.y -
            LW_MAN_ROLL_DZ;
        } else if (LW_ctrl_241029_1_B.sf_nan_inf0.y < 0.0F - LW_MAN_ROLL_DZ) {
          /* '<S394>:1:13' elseif(u < RCMid - deadZone) */
          /* '<S394>:1:14' y = single((u - RCMid + deadZone)*k); */
          LW_ctrl_241029_1_B.kappa *= LW_ctrl_241029_1_B.sf_nan_inf0.y +
            LW_MAN_ROLL_DZ;
        } else {
          /* '<S394>:1:15' else */
          /* '<S394>:1:16' y = single(0); */
          LW_ctrl_241029_1_B.kappa = 0.0F;
        }

        /* End of MATLAB Function: '<S370>/roll_deadzone' */

        /* Gain: '<S370>/deg2rad' incorporates:
         *  Gain: '<S370>/man_roll_max'
         */
        LW_ctrl_241029_1_B.roll_ref = LW_MAN_ROLL_MAX * LW_ctrl_241029_1_B.kappa
          * 0.0174533F;

        /* Gain: '<S370>/deg2rad1' incorporates:
         *  Gain: '<S370>/Gain1'
         */
        LW_ctrl_241029_1_B.delta_r = 0.0F *
          LW_ctrl_241029_1_B.sf_yawrate_deadzone1.y * 0.0174533F;

        /* MATLAB Function: '<S370>/nan_inf1' */
        profileStart_LW_ctrl_241029_1(85U); /* original_line:8600 */LW_ctrl_241029_1_nan_inf0(LW_ctrl_241029_1_B.x,
          &LW_ctrl_241029_1_B.sf_nan_inf1);profileEnd_LW_ctrl_241029_1(85U); /* original_line:8601 */

        /* MATLAB Function: '<S370>/pitch_deadzone' */
        /* Function description: */
        /*   set a dead zone with a dead zone size of ±deadZone. */
        /* MATLAB Function 'navigator/navigator_manual/pitch_deadzone': '<S391>:1' */
        /* '<S391>:1:4' RCMin = single(-1); */
        /* '<S391>:1:5' RCMax = single(1); */
        /* '<S391>:1:6' RCMid = ((RCMin + RCMax)/2); */
        /* '<S391>:1:7' deadZone = LW_MAN_PITCH_DZ; */
        /* '<S391>:1:8' k = 1/(RCMax - RCMid - deadZone); */
        LW_ctrl_241029_1_B.kappa = 1.0F / (1.0F - LW_MAN_PITCH_DZ);

        /* dead zone */
        /* '<S391>:1:11' if(u > RCMid + deadZone) */
        if (LW_ctrl_241029_1_B.sf_nan_inf1.y > LW_MAN_PITCH_DZ) {
          /* '<S391>:1:12' y = single((u-RCMid - deadZone)*k); */
          LW_ctrl_241029_1_B.kappa *= LW_ctrl_241029_1_B.sf_nan_inf1.y -
            LW_MAN_PITCH_DZ;
        } else if (LW_ctrl_241029_1_B.sf_nan_inf1.y < 0.0F - LW_MAN_PITCH_DZ) {
          /* '<S391>:1:13' elseif(u < RCMid - deadZone) */
          /* '<S391>:1:14' y = single((u - RCMid + deadZone)*k); */
          LW_ctrl_241029_1_B.kappa *= LW_ctrl_241029_1_B.sf_nan_inf1.y +
            LW_MAN_PITCH_DZ;
        } else {
          /* '<S391>:1:15' else */
          /* '<S391>:1:16' y = single(0); */
          LW_ctrl_241029_1_B.kappa = 0.0F;
        }

        /* End of MATLAB Function: '<S370>/pitch_deadzone' */

        /* Gain: '<S370>/deg2rad2' incorporates:
         *  Gain: '<S370>/man_pitch_max'
         */
        LW_ctrl_241029_1_B.pitch_ref = -LW_MAN_PITCH_MAX *
          LW_ctrl_241029_1_B.kappa * 0.0174533F;

        /* Gain: '<S370>/deg2rad3' incorporates:
         *  Gain: '<S370>/Gain2'
         */
        LW_ctrl_241029_1_B.yawrate_ref = LW_ACRO_Y_MAX *
          LW_ctrl_241029_1_B.IntegralGain * 0.0174533F;

        /* Gain: '<S370>/deg2rad4' incorporates:
         *  Gain: '<S370>/Gain6'
         */
        LW_ctrl_241029_1_B.rollrate_ref = LW_ACRO_R_MAX *
          LW_ctrl_241029_1_B.km_f_b * 0.0174533F;

        /* Gain: '<S370>/deg2rad5' incorporates:
         *  Gain: '<S370>/Gain7'
         */
        LW_ctrl_241029_1_B.pitchRate_d = -LW_ACRO_P_MAX * LW_ctrl_241029_1_B.Va_
          * 0.0174533F;

        /* Gain: '<S370>/Gain3' incorporates:
         *  Gain: '<S370>/Gain8'
         */
        LW_ctrl_241029_1_B.IntegralGain = LW_SERVOR_MAX + LW_SERVOL_MAX;

        /* Gain: '<S370>/deg2rad6' incorporates:
         *  Gain: '<S370>/Gain3'
         */
        LW_ctrl_241029_1_B.delta_a = LW_ctrl_241029_1_B.IntegralGain *
          LW_ctrl_241029_1_B.sf_rollrate_deadzone1.y * 0.0174533F;

        /* Gain: '<S370>/deg2rad7' incorporates:
         *  Gain: '<S370>/Gain8'
         */
        LW_ctrl_241029_1_B.delta_e = LW_ctrl_241029_1_B.IntegralGain *
          LW_ctrl_241029_1_B.sf_pitchrate_deadzone1.y * 0.0174533F;

        /* Gain: '<S370>/max_vx' */
        LW_ctrl_241029_1_B.max_vx = LW_X_VEL_MAX *
          LW_ctrl_241029_1_B.sf_Lowpass.data_in;

        /* Gain: '<S370>/max_vy' */
        LW_ctrl_241029_1_B.max_vy = LW_Y_VEL_MAX *
          LW_ctrl_241029_1_B.sf_Lowpass1.data_in;

        /* Gain: '<S370>/max_vz' */
        LW_ctrl_241029_1_B.max_vz = -LW_Z_VEL_MAX_UP *
          LW_ctrl_241029_1_B.sf_Lowpass2.data_in;

        /* End of Outputs for SubSystem: '<S4>/navigator_manual' */
      }

      /* End of SwitchCase: '<S4>/Switch Case' */

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.rates_ref[0] = LW_ctrl_241029_1_B.rollrate_ref;
      LW_ctrl_241029_1_B.rates_ref[1] = LW_ctrl_241029_1_B.pitchRate_d;
      LW_ctrl_241029_1_B.rates_ref[2] = LW_ctrl_241029_1_B.yawrate_ref;

      /* Outputs for Atomic SubSystem: '<S4>/navigator_offboard' */
      /* MATLAB Function: '<S403>/task' incorporates:
       *  DataTypeConversion: '<S371>/Data Type Conversion'
       *  Gain: '<S371>/Gain'
       */
      /* 纵向正弦轨迹 八字轨迹 S弯轨迹 直线加减速 侧向复位 */
      /* MATLAB Function 'navigator/navigator_offboard/task select/task select/task': '<S405>:1' */
      /* '<S405>:1:3' d = 20; */
      /*  if timestamp <= 400 */
      /*      CH8 = 1550; */
      /*  end */
      /* '<S405>:1:8' if CH8 < 1600 */
      if (LW_ctrl_241029_1_B.AU8 < 1600.0F) {
        /* '<S405>:1:9' [pos_ref, vel_ref, acc_ref, euler_ref,dot3x, yaw_ref, dotpsi,reverse_flag] = task5(timestamp, flight_mode,pos, vel, q, LW_OB_CIRCLE_R, LW_OB_CIRCLE_V, LW_OB_CIRCLE_W, LW_OB_TYPE); */
        profileStart_LW_ctrl_241029_1(87U); /* original_line:8710 */LW_ctrl_241029_1_task5((real32_T)(1.0E-6 *
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp),
          LW_ctrl_241029_1_B.flight_mode, LW_ctrl_241029_1_B.sf_nan_inf.y,
          LW_ctrl_241029_1_B.y, LW_ctrl_241029_1_B.Xi_e,
          LW_ctrl_241029_1_B.vel_ref_c, LW_ctrl_241029_1_B.z3_,
          LW_ctrl_241029_1_B.d_est, &LW_ctrl_241029_1_B.Va_,
          &LW_ctrl_241029_1_B.IntegralGain);profileEnd_LW_ctrl_241029_1(87U); /* original_line:8716 */
      } else {
        /* '<S405>:1:10' else */
        /* '<S405>:1:11' [pos_ref, vel_ref, acc_ref, euler_ref,dot3x, yaw_ref, dotpsi,reverse_flag] = task1(timestamp, flight_mode,pos, vel, q, LW_OB_CIRCLE_R, LW_OB_CIRCLE_V, LW_OB_CIRCLE_W, LW_OB_TYPE); */
        profileStart_LW_ctrl_241029_1(86U); /* original_line:8720 */LW_ctrl_241029_1_task1((real32_T)(1.0E-6 *
          LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger2.timestamp),
          LW_ctrl_241029_1_B.flight_mode, LW_ctrl_241029_1_B.sf_nan_inf.y,
          LW_ctrl_241029_1_B.y, LW_ctrl_241029_1_B.Xi_e,
          LW_ctrl_241029_1_B.vel_ref_c, LW_ctrl_241029_1_B.z3_,
          LW_ctrl_241029_1_B.d_est, &LW_ctrl_241029_1_B.Va_,
          &LW_ctrl_241029_1_B.IntegralGain);profileEnd_LW_ctrl_241029_1(86U); /* original_line:8726 */
      }

      /* End of MATLAB Function: '<S403>/task' */

      /* MATLAB Function: '<S403>/df,coor,wind' */
      LW_ctrl_241029_1_B.pos_ref_l[0] = LW_ctrl_241029_1_B.Xi_e[0];
      LW_ctrl_241029_1_B.vel_ref_k[0] = LW_ctrl_241029_1_B.vel_ref_c[0];
      LW_ctrl_241029_1_B.acc_ref_b[0] = LW_ctrl_241029_1_B.z3_[0];
      LW_ctrl_241029_1_B.pos_ref_l[1] = LW_ctrl_241029_1_B.Xi_e[1];
      LW_ctrl_241029_1_B.vel_ref_k[1] = LW_ctrl_241029_1_B.vel_ref_c[1];
      LW_ctrl_241029_1_B.acc_ref_b[1] = LW_ctrl_241029_1_B.z3_[1];
      LW_ctrl_241029_1_B.pos_ref_l[2] = LW_ctrl_241029_1_B.Xi_e[2];
      LW_ctrl_241029_1_B.vel_ref_k[2] = LW_ctrl_241029_1_B.vel_ref_c[2];
      LW_ctrl_241029_1_B.acc_ref_b[2] = LW_ctrl_241029_1_B.z3_[2];

      /*  Note */
      /*  adopt the results from differential Flatness derived from data 2022-6-16 */
      /*  加入风 */
      /* MATLAB Function 'navigator/navigator_offboard/task select/task select/df,coor,wind': '<S404>:1' */
      /* '<S404>:1:9' if isempty(xw_) */
      if (!LW_ctrl_241029_1_DW.xw__not_empty) {
        /* '<S404>:1:10' if ~isnan(yaw_ref) */
        if (!rtIsNaNF(LW_ctrl_241029_1_B.Va_)) {
          /* '<S404>:1:11' xw_ = [cos(yaw_ref) sin(yaw_ref) 0]'; */
          profileStart_LW_ctrl_241029_1(88U); /* original_line:8751 */LW_ctrl_241029_1_B.kappa = (real32_T)sin(LW_ctrl_241029_1_B.Va_);profileEnd_LW_ctrl_241029_1(88U); /* original_line:8751 */
          profileStart_LW_ctrl_241029_1(89U); /* original_line:8752 */LW_ctrl_241029_1_B.eta_p = (real32_T)cos(LW_ctrl_241029_1_B.Va_);profileEnd_LW_ctrl_241029_1(89U); /* original_line:8752 */
          LW_ctrl_241029_1_DW.xw_[0] = LW_ctrl_241029_1_B.eta_p;
          LW_ctrl_241029_1_DW.xw_[1] = LW_ctrl_241029_1_B.kappa;
          LW_ctrl_241029_1_DW.xw_[2] = 0.0F;
          LW_ctrl_241029_1_DW.xw__not_empty = true;

          /* '<S404>:1:12' yb_ = [-sin(yaw_ref) cos(yaw_ref) 0]'; */
          LW_ctrl_241029_1_DW.yb_[0] = -LW_ctrl_241029_1_B.kappa;
          LW_ctrl_241029_1_DW.yb_[1] = LW_ctrl_241029_1_B.eta_p;
          LW_ctrl_241029_1_DW.yb_[2] = 0.0F;
        } else {
          /* '<S404>:1:13' else */
          /* '<S404>:1:14' xw_ = single([1 0 0]'); */
          LW_ctrl_241029_1_DW.xw__not_empty = true;

          /* '<S404>:1:15' yb_ = single([0 1 0]'); */
          LW_ctrl_241029_1_DW.xw_[0] = 1.0F;
          LW_ctrl_241029_1_DW.yb_[0] = 0.0F;
          LW_ctrl_241029_1_DW.xw_[1] = 0.0F;
          LW_ctrl_241029_1_DW.yb_[1] = 1.0F;
          LW_ctrl_241029_1_DW.xw_[2] = 0.0F;
          LW_ctrl_241029_1_DW.yb_[2] = 0.0F;
        }
      }

      /*   */
      /* '<S404>:1:19' airspeed_T = single(0.01); */
      /* '<S404>:1:20' g = single([0; 0; ModelParam_envGravityAcc]); */
      /* '<S404>:1:21' Cd0 = single(ModelParam_pu_c0); */
      /*  最小阻力 */
      /* '<S404>:1:22' Cla = single(ModelParam_pu_c1); */
      /*  post stall */
      /* '<S404>:1:23' Cd0 = single(LW_AERO_C0); */
      /*  最小阻力 */
      /* '<S404>:1:24' Cla = single(LW_AERO_C1); */
      /*  post stall */
      /*  Cd0 = single(ModelParam_pu_c3); % 最小阻力 */
      /*  Cla = single(ModelParam_pu_c2); % pre stall */
      /* '<S404>:1:28' Cy0 = single(LW_AERO_Y0); */
      /* '<S404>:1:29' kk = single(LW_ANGLE*pi/180); */
      LW_ctrl_241029_1_B.km_f_b = LW_ANGLE * 3.14159274F / 180.0F;

      /* '<S404>:1:30' Rho = single(ModelParam_LBRho); */
      /* '<S404>:1:31' Mass = single(LW_MASS); */
      /* '<S404>:1:34' dotdotx = single(acc_ref(:)); */
      /* '<S404>:1:35' va = single(vel_ref(:) - v_wind); */
      /* '<S404>:1:36' Va = sqrt(va'*va); */
      LW_ctrl_241029_1_B.Integrator_a = LW_ctrl_241029_1_B.vel_ref_k[0] -
        LW_ctrl_241029_1_B.v_wind[0];
      LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] =
        LW_ctrl_241029_1_B.Integrator_a;
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.Integrator_a *
        LW_ctrl_241029_1_B.Integrator_a;
      LW_ctrl_241029_1_B.Integrator_a = LW_ctrl_241029_1_B.vel_ref_k[1] -
        LW_ctrl_241029_1_B.v_wind[1];
      LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] =
        LW_ctrl_241029_1_B.Integrator_a;
      LW_ctrl_241029_1_B.aSinInput += LW_ctrl_241029_1_B.Integrator_a *
        LW_ctrl_241029_1_B.Integrator_a;
      LW_ctrl_241029_1_B.Integrator_a = LW_ctrl_241029_1_B.vel_ref_k[2] -
        LW_ctrl_241029_1_B.v_wind[2];
      profileStart_LW_ctrl_241029_1(90U); /* original_line:8813 */LW_ctrl_241029_1_B.IntegralGain = (real32_T)sqrt
        (LW_ctrl_241029_1_B.Integrator_a * LW_ctrl_241029_1_B.Integrator_a +
         LW_ctrl_241029_1_B.aSinInput);profileEnd_LW_ctrl_241029_1(90U); /* original_line:8815 */

      /* '<S404>:1:37' Qa = 0.5/Mass * Rho * ModelParam_LBS * Va; */
      /* '<S404>:1:39' if ~isnan(yaw_ref) */
      profileStart_LW_ctrl_241029_1(91U); /* original_line:8819 */rtb_RelationalOperator_om = rtIsNaNF(LW_ctrl_241029_1_B.Va_);profileEnd_LW_ctrl_241029_1(91U); /* original_line:8819 */
      if (!rtb_RelationalOperator_om) {
        /* '<S404>:1:40' xw_ = [cos(yaw_ref) sin(yaw_ref) 0]'; */
        profileStart_LW_ctrl_241029_1(92U); /* original_line:8822 */LW_ctrl_241029_1_B.kappa = (real32_T)sin(LW_ctrl_241029_1_B.Va_);profileEnd_LW_ctrl_241029_1(92U); /* original_line:8822 */
        profileStart_LW_ctrl_241029_1(93U); /* original_line:8823 */LW_ctrl_241029_1_B.eta_p = (real32_T)cos(LW_ctrl_241029_1_B.Va_);profileEnd_LW_ctrl_241029_1(93U); /* original_line:8823 */
        LW_ctrl_241029_1_DW.xw_[0] = LW_ctrl_241029_1_B.eta_p;
        LW_ctrl_241029_1_DW.xw_[1] = LW_ctrl_241029_1_B.kappa;
        LW_ctrl_241029_1_DW.xw_[2] = 0.0F;

        /* '<S404>:1:41' yb_ = [-sin(yaw_ref) cos(yaw_ref) 0]'; */
        LW_ctrl_241029_1_DW.yb_[0] = -LW_ctrl_241029_1_B.kappa;
        LW_ctrl_241029_1_DW.yb_[1] = LW_ctrl_241029_1_B.eta_p;
        LW_ctrl_241029_1_DW.yb_[2] = 0.0F;
      }

      /* '<S404>:1:44' if Va > airspeed_T && isnan(yaw_ref) */
      if ((LW_ctrl_241029_1_B.IntegralGain > 0.01F) && rtb_RelationalOperator_om)
      {
        /* '<S404>:1:45' xw = va / Va; */
        LW_ctrl_241029_1_DW.xw_[0] =
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] /
          LW_ctrl_241029_1_B.IntegralGain;
        LW_ctrl_241029_1_DW.xw_[1] =
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] /
          LW_ctrl_241029_1_B.IntegralGain;
        LW_ctrl_241029_1_DW.xw_[2] = LW_ctrl_241029_1_B.Integrator_a /
          LW_ctrl_241029_1_B.IntegralGain;

        /* '<S404>:1:46' xw_ = xw; */
      } else {
        /* '<S404>:1:47' else */
        /* '<S404>:1:48' xw = xw_; */
      }

      /* '<S404>:1:51' a_xw = xw' * (dotdotx - g); */
      rtb_FilterCoefficient_jy_tmp = (LW_ctrl_241029_1_DW.xw_[0] *
        LW_ctrl_241029_1_B.acc_ref_b[0] + LW_ctrl_241029_1_DW.xw_[1] *
        LW_ctrl_241029_1_B.acc_ref_b[1]) + (LW_ctrl_241029_1_B.acc_ref_b[2] -
        9.8F) * LW_ctrl_241029_1_DW.xw_[2];

      /* '<S404>:1:52' an = dotdotx - g - a_xw * xw; */
      /* '<S404>:1:53' a_zw = -norm(an); */
      /* '<S404>:1:54' [f_d, alpha] = SolveFza(a_xw, a_zw, Va, Cd0, Cla, Rho,  ModelParam_LBS, LW_MASS, kk); */
      /* '<S404>:1:80' Q = 0.5 * Rho * Va ^ 2; */
      LW_ctrl_241029_1_B.Filter_l = LW_ctrl_241029_1_B.IntegralGain *
        LW_ctrl_241029_1_B.IntegralGain;
      LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.Filter_l * 0.61F;

      /* '<S404>:1:81' QSCla = Q * S * Cla; */
      LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_B.Va_ * 0.155F * LW_AERO_C1;

      /* '<S404>:1:83' av1 = av1_*m + Q * S * Cd0; */
      LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_B.Va_ * 0.155F *
        LW_AERO_C0 + rtb_FilterCoefficient_jy_tmp * LW_MASS;

      /* '<S404>:1:84' av3 = min(av3_*m, 0); */
      /* '<S404>:1:85' k1 = sqrt(av1 ^ 2 * cos(kk) ^ 2 + (av1 + QSCla) ^ 2 * sin(kk) ^ 2 + av3 ^ 2 - QSCla * av3 * sin(2 * kk)); */
      LW_ctrl_241029_1_B.Va_ = LW_ctrl_241029_1_B.time_to_stop +
        LW_ctrl_241029_1_B.theta;
      profileStart_LW_ctrl_241029_1(94U); /* original_line:8878 */LW_ctrl_241029_1_B.eta_p = (real32_T)sin(LW_ctrl_241029_1_B.km_f_b);profileEnd_LW_ctrl_241029_1(94U); /* original_line:8878 */

      /* '<S404>:1:86' fz = -(av1^2 + QSCla*av1 + av3^2) / k1; */
      /* '<S404>:1:88' alpha = 2 * atan((QSCla * sin(kk) - av3 * cos(kk) + av1 * sin(kk) - k1) / (av1 * cos(kk) + av3 * sin(kk))); */
      /* '<S404>:1:56' ay = Qa * Cy0 * va - g + dotdotx; */
      Filter_o5 = 0.5F / LW_MASS * 1.22F * 0.155F;
      LW_ctrl_241029_1_B.aSinInput = Filter_o5 * LW_ctrl_241029_1_B.IntegralGain
        * LW_AERO_Y0;
      LW_ctrl_241029_1_B.vel_ref_c[0] = LW_ctrl_241029_1_B.acc_ref_b[0] -
        rtb_FilterCoefficient_jy_tmp * LW_ctrl_241029_1_DW.xw_[0];
      LW_ctrl_241029_1_B.Xi_e[0] = LW_ctrl_241029_1_B.aSinInput *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
        LW_ctrl_241029_1_B.acc_ref_b[0];
      LW_ctrl_241029_1_B.vel_ref_c[1] = LW_ctrl_241029_1_B.acc_ref_b[1] -
        rtb_FilterCoefficient_jy_tmp * LW_ctrl_241029_1_DW.xw_[1];
      LW_ctrl_241029_1_B.Xi_e[1] = LW_ctrl_241029_1_B.aSinInput *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] +
        LW_ctrl_241029_1_B.acc_ref_b[1];
      LW_ctrl_241029_1_B.vel_ref_c[2] = (LW_ctrl_241029_1_B.acc_ref_b[2] - 9.8F)
        - rtb_FilterCoefficient_jy_tmp * LW_ctrl_241029_1_DW.xw_[2];
      LW_ctrl_241029_1_B.Xi_e[2] = (LW_ctrl_241029_1_B.aSinInput *
        LW_ctrl_241029_1_B.Integrator_a - 9.8F) + LW_ctrl_241029_1_B.acc_ref_b[2];
      profileStart_LW_ctrl_241029_1(95U); /* original_line:8900 */LW_ctrl_241029_1_B.delta_t = -LW_ctrl_241029_1_norm
        (LW_ctrl_241029_1_B.vel_ref_c) * LW_MASS;profileEnd_LW_ctrl_241029_1(95U); /* original_line:8901 */
      if (!(LW_ctrl_241029_1_B.delta_t <= 0.0F)) {
        LW_ctrl_241029_1_B.delta_t = 0.0F;
      }

      profileStart_LW_ctrl_241029_1(96U); /* original_line:8906 */LW_ctrl_241029_1_B.kappa = (real32_T)cos(LW_ctrl_241029_1_B.km_f_b);profileEnd_LW_ctrl_241029_1(96U); /* original_line:8906 */
      LW_ctrl_241029_1_B.DeadZone_e = LW_ctrl_241029_1_B.time_to_stop *
        LW_ctrl_241029_1_B.time_to_stop;
      LW_ctrl_241029_1_B.IntegralGain_gt = LW_ctrl_241029_1_B.delta_t *
        LW_ctrl_241029_1_B.delta_t;
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.eta_p *
        LW_ctrl_241029_1_B.eta_p;
      rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.kappa *
        LW_ctrl_241029_1_B.kappa;
      profileStart_LW_ctrl_241029_1(97U); /* original_line:8915 */LW_ctrl_241029_1_B.FilterCoefficient_jy = (real32_T)sqrt
        (((LW_ctrl_241029_1_B.Va_ * LW_ctrl_241029_1_B.Va_ *
           LW_ctrl_241029_1_B.aSinInput + LW_ctrl_241029_1_B.DeadZone_e *
           rtb_FilterCoefficient_jy_tmp) + LW_ctrl_241029_1_B.IntegralGain_gt) -
         LW_ctrl_241029_1_B.theta * LW_ctrl_241029_1_B.delta_t * (real32_T)sin
         (2.0F * LW_ctrl_241029_1_B.km_f_b));profileEnd_LW_ctrl_241029_1(97U); /* original_line:8920 */
      LW_ctrl_241029_1_B.Va_ = -((LW_ctrl_241029_1_B.theta *
        LW_ctrl_241029_1_B.time_to_stop + LW_ctrl_241029_1_B.DeadZone_e) +
        LW_ctrl_241029_1_B.IntegralGain_gt) /
        LW_ctrl_241029_1_B.FilterCoefficient_jy;
      profileStart_LW_ctrl_241029_1(98U); /* original_line:8925 */LW_ctrl_241029_1_B.theta = (real32_T)atan((((LW_ctrl_241029_1_B.theta *
        LW_ctrl_241029_1_B.eta_p - LW_ctrl_241029_1_B.delta_t *
        LW_ctrl_241029_1_B.kappa) + LW_ctrl_241029_1_B.time_to_stop *
        LW_ctrl_241029_1_B.eta_p) - LW_ctrl_241029_1_B.FilterCoefficient_jy) /
        (LW_ctrl_241029_1_B.time_to_stop * LW_ctrl_241029_1_B.kappa +
         LW_ctrl_241029_1_B.delta_t * LW_ctrl_241029_1_B.eta_p)) * 2.0F;profileEnd_LW_ctrl_241029_1(98U); /* original_line:8930 */
      LW_ctrl_241029_1_B.f_d_l = LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.alpha_d = LW_ctrl_241029_1_B.theta;

      /* '<S404>:1:57' xw_ay_norm = norm(cross(xw, ay)); */
      LW_ctrl_241029_1_B.delta_t = LW_ctrl_241029_1_DW.xw_[1] *
        LW_ctrl_241029_1_B.Xi_e[2] - LW_ctrl_241029_1_B.Xi_e[1] *
        LW_ctrl_241029_1_DW.xw_[2];
      LW_ctrl_241029_1_B.vel_ref_c[0] = LW_ctrl_241029_1_B.delta_t;
      LW_ctrl_241029_1_B.FilterCoefficient_jy = LW_ctrl_241029_1_B.Xi_e[0] *
        LW_ctrl_241029_1_DW.xw_[2] - LW_ctrl_241029_1_DW.xw_[0] *
        LW_ctrl_241029_1_B.Xi_e[2];
      LW_ctrl_241029_1_B.vel_ref_c[1] = LW_ctrl_241029_1_B.FilterCoefficient_jy;
      LW_ctrl_241029_1_B.DeadZone_e = LW_ctrl_241029_1_DW.xw_[0] *
        LW_ctrl_241029_1_B.Xi_e[1] - LW_ctrl_241029_1_B.Xi_e[0] *
        LW_ctrl_241029_1_DW.xw_[1];
      LW_ctrl_241029_1_B.vel_ref_c[2] = LW_ctrl_241029_1_B.DeadZone_e;
      profileStart_LW_ctrl_241029_1(99U); /* original_line:8947 */LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_norm
        (LW_ctrl_241029_1_B.vel_ref_c);profileEnd_LW_ctrl_241029_1(99U); /* original_line:8948 */

      /* '<S404>:1:58' if xw_ay_norm > 0.01 */
      if (LW_ctrl_241029_1_B.time_to_stop > 0.01) {
        /* '<S404>:1:59' yb = cross(xw, ay) / xw_ay_norm; */
        LW_ctrl_241029_1_DW.yb_[0] = LW_ctrl_241029_1_B.delta_t /
          LW_ctrl_241029_1_B.time_to_stop;
        LW_ctrl_241029_1_DW.yb_[1] = LW_ctrl_241029_1_B.FilterCoefficient_jy /
          LW_ctrl_241029_1_B.time_to_stop;
        LW_ctrl_241029_1_DW.yb_[2] = LW_ctrl_241029_1_B.DeadZone_e /
          LW_ctrl_241029_1_B.time_to_stop;

        /* '<S404>:1:60' yb_ = yb; */
      } else {
        /* '<S404>:1:61' else */
        /* '<S404>:1:62' yb = yb_; */
      }

      /* '<S404>:1:64' yb_hat = [0 -yb(3) yb(2); yb(3) 0 -yb(1); -yb(2) yb(1) 0]; */
      /* '<S404>:1:65' lamda = alpha - kk; */
      LW_ctrl_241029_1_B.theta -= LW_ctrl_241029_1_B.km_f_b;

      /* '<S404>:1:66' xb = (cos(lamda)*eye(3) + (1 - cos(lamda))*yb*yb'+sin(lamda)*yb_hat)*xw; */
      profileStart_LW_ctrl_241029_1(100U); /* original_line:8971 */LW_ctrl_241029_1_B.km_f_b = (real32_T)cos(LW_ctrl_241029_1_B.theta);profileEnd_LW_ctrl_241029_1(100U); /* original_line:8971 */
      profileStart_LW_ctrl_241029_1(101U); /* original_line:8972 */LW_ctrl_241029_1_B.theta = (real32_T)sin(LW_ctrl_241029_1_B.theta);profileEnd_LW_ctrl_241029_1(101U); /* original_line:8972 */
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.Rbe_psi[3 * i] = (1.0F - LW_ctrl_241029_1_B.km_f_b) *
          LW_ctrl_241029_1_DW.yb_[0] * LW_ctrl_241029_1_DW.yb_[i] + (real32_T)e
          [3 * i] * LW_ctrl_241029_1_B.km_f_b;
        trueCount = 3 * i + 1;
        LW_ctrl_241029_1_B.Rbe_psi[trueCount] = (1.0F -
          LW_ctrl_241029_1_B.km_f_b) * LW_ctrl_241029_1_DW.yb_[1] *
          LW_ctrl_241029_1_DW.yb_[i] + (real32_T)e[trueCount] *
          LW_ctrl_241029_1_B.km_f_b;
        trueCount = 3 * i + 2;
        LW_ctrl_241029_1_B.Rbe_psi[trueCount] = (1.0F -
          LW_ctrl_241029_1_B.km_f_b) * LW_ctrl_241029_1_DW.yb_[2] *
          LW_ctrl_241029_1_DW.yb_[i] + (real32_T)e[trueCount] *
          LW_ctrl_241029_1_B.km_f_b;
      }

      LW_ctrl_241029_1_B.vd_lim_tmp[0] = LW_ctrl_241029_1_B.theta * 0.0F;
      LW_ctrl_241029_1_B.vd_lim_tmp[3] = LW_ctrl_241029_1_B.theta *
        -LW_ctrl_241029_1_DW.yb_[2];
      LW_ctrl_241029_1_B.vd_lim_tmp[6] = LW_ctrl_241029_1_B.theta *
        LW_ctrl_241029_1_DW.yb_[1];
      LW_ctrl_241029_1_B.vd_lim_tmp[1] = LW_ctrl_241029_1_B.theta *
        LW_ctrl_241029_1_DW.yb_[2];
      LW_ctrl_241029_1_B.vd_lim_tmp[4] = LW_ctrl_241029_1_B.theta * 0.0F;
      LW_ctrl_241029_1_B.vd_lim_tmp[7] = LW_ctrl_241029_1_B.theta *
        -LW_ctrl_241029_1_DW.yb_[0];
      LW_ctrl_241029_1_B.vd_lim_tmp[2] = LW_ctrl_241029_1_B.theta *
        -LW_ctrl_241029_1_DW.yb_[1];
      LW_ctrl_241029_1_B.vd_lim_tmp[5] = LW_ctrl_241029_1_B.theta *
        LW_ctrl_241029_1_DW.yb_[0];
      LW_ctrl_241029_1_B.vd_lim_tmp[8] = LW_ctrl_241029_1_B.theta * 0.0F;
      for (i = 0; i < 9; i++) {
        LW_ctrl_241029_1_B.km_f[i] = LW_ctrl_241029_1_B.Rbe_psi[i] +
          LW_ctrl_241029_1_B.vd_lim_tmp[i];
      }

      LW_ctrl_241029_1_B.km_f_b = LW_ctrl_241029_1_DW.xw_[1];
      LW_ctrl_241029_1_B.theta = LW_ctrl_241029_1_DW.xw_[0];
      LW_ctrl_241029_1_B.time_to_stop = LW_ctrl_241029_1_DW.xw_[2];
      for (i = 0; i < 3; i++) {
        LW_ctrl_241029_1_B.Xi_e[i] = (LW_ctrl_241029_1_B.km_f[i + 3] *
          LW_ctrl_241029_1_B.km_f_b + LW_ctrl_241029_1_B.km_f[i] *
          LW_ctrl_241029_1_B.theta) + LW_ctrl_241029_1_B.km_f[i + 6] *
          LW_ctrl_241029_1_B.time_to_stop;
      }

      /* '<S404>:1:67' zb = cross(xb, yb); */
      /* '<S404>:1:68' R_d = [xb yb zb]; */
      LW_ctrl_241029_1_B.Rbe_psi[0] = LW_ctrl_241029_1_B.Xi_e[0];
      LW_ctrl_241029_1_B.Rbe_psi[1] = LW_ctrl_241029_1_B.Xi_e[1];
      LW_ctrl_241029_1_B.Rbe_psi[2] = LW_ctrl_241029_1_B.Xi_e[2];
      LW_ctrl_241029_1_B.Rbe_psi[6] = LW_ctrl_241029_1_B.Xi_e[1] *
        LW_ctrl_241029_1_DW.yb_[2] - LW_ctrl_241029_1_DW.yb_[1] *
        LW_ctrl_241029_1_B.Xi_e[2];
      LW_ctrl_241029_1_B.Rbe_psi[7] = LW_ctrl_241029_1_DW.yb_[0] *
        LW_ctrl_241029_1_B.Xi_e[2] - LW_ctrl_241029_1_B.Xi_e[0] *
        LW_ctrl_241029_1_DW.yb_[2];
      LW_ctrl_241029_1_B.Rbe_psi[8] = LW_ctrl_241029_1_B.Xi_e[0] *
        LW_ctrl_241029_1_DW.yb_[1] - LW_ctrl_241029_1_DW.yb_[0] *
        LW_ctrl_241029_1_B.Xi_e[1];

      /* 协调假设求解角速度 */
      /* '<S404>:1:70' wb_ref = calculateWb(f_d, R_d, Va, va, dotdotx, dot3x, Cd0, Cla, Cy0, Rho, ModelParam_LBS, LW_MASS, g, kk); */
      /* '<S404>:1:93' if isempty(wz_) */
      /* '<S404>:1:97' Qa = 0.5/m * Rho * S * Vg; */
      LW_ctrl_241029_1_B.km_f_b = Filter_o5 * LW_ctrl_241029_1_B.IntegralGain;

      /* '<S404>:1:98' cz = fz/m; */
      LW_ctrl_241029_1_B.Va_ /= LW_MASS;

      /* '<S404>:1:99' dxz = Cla * sin(kk) * cos(kk); */
      LW_ctrl_241029_1_B.delta_t = LW_AERO_C1 * LW_ctrl_241029_1_B.eta_p *
        LW_ctrl_241029_1_B.kappa;

      /* '<S404>:1:100' dx = Cd0 + Cla * sin(kk) ^ 2; */
      LW_ctrl_241029_1_B.FilterCoefficient_jy = LW_ctrl_241029_1_B.aSinInput *
        LW_AERO_C1 + LW_AERO_C0;

      /* '<S404>:1:101' dz = Cd0 + Cla * cos(kk) ^ 2; */
      LW_ctrl_241029_1_B.DeadZone_e = rtb_FilterCoefficient_jy_tmp * LW_AERO_C1
        + LW_AERO_C0;

      /* '<S404>:1:103' if Vg < 0.01 */
      if (LW_ctrl_241029_1_B.IntegralGain < 0.01) {
        /* '<S404>:1:104' C1 = Rbb(:, 1)' * dot3x + Qa * (dx * Rbb(:, 1)' * dotdotx + dxz * Rbb(:, 3)' * dotdotx); */
        LW_ctrl_241029_1_B.kappa = (((LW_ctrl_241029_1_B.FilterCoefficient_jy *
          LW_ctrl_241029_1_B.Xi_e[0] * LW_ctrl_241029_1_B.acc_ref_b[0] +
          LW_ctrl_241029_1_B.FilterCoefficient_jy * LW_ctrl_241029_1_B.Xi_e[1] *
          LW_ctrl_241029_1_B.acc_ref_b[1]) +
          LW_ctrl_241029_1_B.FilterCoefficient_jy * LW_ctrl_241029_1_B.Xi_e[2] *
          LW_ctrl_241029_1_B.acc_ref_b[2]) + ((LW_ctrl_241029_1_B.delta_t *
          LW_ctrl_241029_1_B.Rbe_psi[6] * LW_ctrl_241029_1_B.acc_ref_b[0] +
          LW_ctrl_241029_1_B.delta_t * LW_ctrl_241029_1_B.Rbe_psi[7] *
          LW_ctrl_241029_1_B.acc_ref_b[1]) + LW_ctrl_241029_1_B.delta_t *
          LW_ctrl_241029_1_B.Rbe_psi[8] * LW_ctrl_241029_1_B.acc_ref_b[2])) *
          LW_ctrl_241029_1_B.km_f_b + ((LW_ctrl_241029_1_B.Xi_e[0] *
          LW_ctrl_241029_1_B.d_est[0] + LW_ctrl_241029_1_B.Xi_e[1] *
          LW_ctrl_241029_1_B.d_est[1]) + LW_ctrl_241029_1_B.Xi_e[2] *
          LW_ctrl_241029_1_B.d_est[2]);
      } else {
        /* '<S404>:1:105' else */
        /* '<S404>:1:106' C1 = Rbb(:, 1)' * dot3x + Qa*dotx'*dotdotx/(Vg^2)*(dx * Rbb(:, 1)' * dotx + dxz * Rbb(:, 3)' * dotx)+ Qa * (dx * Rbb(:, 1)' * dotdotx + dxz * Rbb(:, 3)' * dotdotx); */
        LW_ctrl_241029_1_B.DeadZone_p = LW_ctrl_241029_1_B.FilterCoefficient_jy *
          LW_ctrl_241029_1_B.Rbe_psi[0];
        LW_ctrl_241029_1_B.Integrator_f = LW_ctrl_241029_1_B.delta_t *
          LW_ctrl_241029_1_B.Rbe_psi[6];
        q = LW_ctrl_241029_1_B.DeadZone_p *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];
        LW_ctrl_241029_1_B.FilterCoefficient_i = LW_ctrl_241029_1_B.Integrator_f
          * LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0];
        LW_ctrl_241029_1_B.b_c = LW_ctrl_241029_1_B.DeadZone_p *
          LW_ctrl_241029_1_B.acc_ref_b[0];
        LW_ctrl_241029_1_B.IntegralGain_n = LW_ctrl_241029_1_B.Integrator_f *
          LW_ctrl_241029_1_B.acc_ref_b[0];
        LW_ctrl_241029_1_B.DeadZone_p = LW_ctrl_241029_1_B.FilterCoefficient_jy *
          LW_ctrl_241029_1_B.Rbe_psi[1];
        LW_ctrl_241029_1_B.Integrator_f = LW_ctrl_241029_1_B.delta_t *
          LW_ctrl_241029_1_B.Rbe_psi[7];
        q += LW_ctrl_241029_1_B.DeadZone_p *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];
        LW_ctrl_241029_1_B.FilterCoefficient_i +=
          LW_ctrl_241029_1_B.Integrator_f *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1];
        LW_ctrl_241029_1_B.b_c += LW_ctrl_241029_1_B.DeadZone_p *
          LW_ctrl_241029_1_B.acc_ref_b[1];
        LW_ctrl_241029_1_B.IntegralGain_n += LW_ctrl_241029_1_B.Integrator_f *
          LW_ctrl_241029_1_B.acc_ref_b[1];
        LW_ctrl_241029_1_B.DeadZone_p = LW_ctrl_241029_1_B.FilterCoefficient_jy *
          LW_ctrl_241029_1_B.Rbe_psi[2];
        LW_ctrl_241029_1_B.Integrator_f = LW_ctrl_241029_1_B.delta_t *
          LW_ctrl_241029_1_B.Rbe_psi[8];
        LW_ctrl_241029_1_B.kappa = (((LW_ctrl_241029_1_B.km_f_b *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] *
          LW_ctrl_241029_1_B.acc_ref_b[0] + LW_ctrl_241029_1_B.km_f_b *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] *
          LW_ctrl_241029_1_B.acc_ref_b[1]) + LW_ctrl_241029_1_B.km_f_b *
          LW_ctrl_241029_1_B.Integrator_a * LW_ctrl_241029_1_B.acc_ref_b[2]) /
          LW_ctrl_241029_1_B.Filter_l * ((LW_ctrl_241029_1_B.DeadZone_p *
          LW_ctrl_241029_1_B.Integrator_a + q) +
          (LW_ctrl_241029_1_B.Integrator_f * LW_ctrl_241029_1_B.Integrator_a +
           LW_ctrl_241029_1_B.FilterCoefficient_i)) +
          ((LW_ctrl_241029_1_B.Rbe_psi[0] * LW_ctrl_241029_1_B.d_est[0] +
            LW_ctrl_241029_1_B.Rbe_psi[1] * LW_ctrl_241029_1_B.d_est[1]) +
           LW_ctrl_241029_1_B.Rbe_psi[2] * LW_ctrl_241029_1_B.d_est[2])) +
          ((LW_ctrl_241029_1_B.DeadZone_p * LW_ctrl_241029_1_B.acc_ref_b[2] +
            LW_ctrl_241029_1_B.b_c) + (LW_ctrl_241029_1_B.Integrator_f *
            LW_ctrl_241029_1_B.acc_ref_b[2] + LW_ctrl_241029_1_B.IntegralGain_n))
          * LW_ctrl_241029_1_B.km_f_b;
      }

      /* '<S404>:1:109' A1 = Qa * dxz * Rbb(:, 2)' * dotx; */
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.km_f_b *
        LW_ctrl_241029_1_B.delta_t;

      /* '<S404>:1:110' B1 = cz - Qa * ((dz - dx) * Rbb(:, 3)' * dotx + 2*dxz * Rbb(:, 1)' * dotx); */
      LW_ctrl_241029_1_B.theta = 2.0F * LW_ctrl_241029_1_B.delta_t;

      /* '<S404>:1:111' D1 = -Qa * ((dx - Cy0) * Rbb(:, 2)' * dotx); */
      rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.FilterCoefficient_jy -
        LW_AERO_Y0;
      LW_ctrl_241029_1_B.eta_p = (LW_ctrl_241029_1_B.aSinInput *
        LW_ctrl_241029_1_DW.yb_[0] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
        LW_ctrl_241029_1_B.aSinInput * LW_ctrl_241029_1_DW.yb_[1] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
        LW_ctrl_241029_1_B.aSinInput * LW_ctrl_241029_1_DW.yb_[2] *
        LW_ctrl_241029_1_B.Integrator_a;
      LW_ctrl_241029_1_B.aSinInput = LW_ctrl_241029_1_B.DeadZone_e -
        LW_ctrl_241029_1_B.FilterCoefficient_jy;
      LW_ctrl_241029_1_B.time_to_stop = ((rtb_FilterCoefficient_jy_tmp *
        LW_ctrl_241029_1_DW.yb_[0] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
        rtb_FilterCoefficient_jy_tmp * LW_ctrl_241029_1_DW.yb_[1] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
        rtb_FilterCoefficient_jy_tmp * LW_ctrl_241029_1_DW.yb_[2] *
        LW_ctrl_241029_1_B.Integrator_a) * -LW_ctrl_241029_1_B.km_f_b;

      /* '<S404>:1:112' if Vg < 0.01 */
      if (LW_ctrl_241029_1_B.IntegralGain < 0.01) {
        /* '<S404>:1:113' C2 = Rbb(:, 2)' * dot3x + Qa * Cy0 * Rbb(:, 2)' * dotdotx; */
        LW_ctrl_241029_1_B.IntegralGain = LW_ctrl_241029_1_B.km_f_b * LW_AERO_Y0;
        LW_ctrl_241029_1_B.IntegralGain = ((LW_ctrl_241029_1_B.IntegralGain *
          LW_ctrl_241029_1_DW.yb_[0] * LW_ctrl_241029_1_B.acc_ref_b[0] +
          LW_ctrl_241029_1_B.IntegralGain * LW_ctrl_241029_1_DW.yb_[1] *
          LW_ctrl_241029_1_B.acc_ref_b[1]) + LW_ctrl_241029_1_B.IntegralGain *
          LW_ctrl_241029_1_DW.yb_[2] * LW_ctrl_241029_1_B.acc_ref_b[2]) +
          ((LW_ctrl_241029_1_DW.yb_[0] * LW_ctrl_241029_1_B.d_est[0] +
            LW_ctrl_241029_1_DW.yb_[1] * LW_ctrl_241029_1_B.d_est[1]) +
           LW_ctrl_241029_1_DW.yb_[2] * LW_ctrl_241029_1_B.d_est[2]);
      } else {
        /* '<S404>:1:114' else */
        /* '<S404>:1:115' C2 = Rbb(:, 2)' * dot3x + Qa*dotx'*dotdotx/(Vg^2)*(Cy0 * Rbb(:, 2)' * dotx)+ Qa * Cy0 * Rbb(:, 2)' * dotdotx; */
        LW_ctrl_241029_1_B.IntegralGain_gt = LW_ctrl_241029_1_B.km_f_b *
          LW_AERO_Y0;
        LW_ctrl_241029_1_B.IntegralGain = (((LW_ctrl_241029_1_B.km_f_b *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] *
          LW_ctrl_241029_1_B.acc_ref_b[0] + LW_ctrl_241029_1_B.km_f_b *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] *
          LW_ctrl_241029_1_B.acc_ref_b[1]) + LW_ctrl_241029_1_B.km_f_b *
          LW_ctrl_241029_1_B.Integrator_a * LW_ctrl_241029_1_B.acc_ref_b[2]) /
          LW_ctrl_241029_1_B.Filter_l * ((LW_AERO_Y0 * LW_ctrl_241029_1_DW.yb_[0]
          * LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] + LW_AERO_Y0 *
          LW_ctrl_241029_1_DW.yb_[1] *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) + LW_AERO_Y0 *
          LW_ctrl_241029_1_DW.yb_[2] * LW_ctrl_241029_1_B.Integrator_a) +
          ((LW_ctrl_241029_1_DW.yb_[0] * LW_ctrl_241029_1_B.d_est[0] +
            LW_ctrl_241029_1_DW.yb_[1] * LW_ctrl_241029_1_B.d_est[1]) +
           LW_ctrl_241029_1_DW.yb_[2] * LW_ctrl_241029_1_B.d_est[2])) +
          ((LW_ctrl_241029_1_B.IntegralGain_gt * LW_ctrl_241029_1_DW.yb_[0] *
            LW_ctrl_241029_1_B.acc_ref_b[0] + LW_ctrl_241029_1_B.IntegralGain_gt
            * LW_ctrl_241029_1_DW.yb_[1] * LW_ctrl_241029_1_B.acc_ref_b[1]) +
           LW_ctrl_241029_1_B.IntegralGain_gt * LW_ctrl_241029_1_DW.yb_[2] *
           LW_ctrl_241029_1_B.acc_ref_b[2]);
      }

      /* '<S404>:1:117' A2 = -cz + Qa * (dxz * Rbb(:, 1)' * dotx + (dz - Cy0) * Rbb(:, 3)' * dotx); */
      LW_ctrl_241029_1_B.DeadZone_e -= LW_AERO_Y0;

      /* '<S404>:1:118' D2 = -Qa * ((dx - Cy0) * Rbb(:, 1)' * dotx + dxz * Rbb(:, 3)' * dotx); */
      /* '<S404>:1:119' A3 = Rbb(:, 3)' * dotx; */
      /* '<S404>:1:120' D3 = -Rbb(:, 1)' * dotx; */
      /* '<S404>:1:121' C3 = -Rbb(:, 2)' * g; */
      LW_ctrl_241029_1_B.IntegralGain_gt =
        (LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] *
         LW_ctrl_241029_1_B.Rbe_psi[6] +
         LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1] *
         LW_ctrl_241029_1_B.Rbe_psi[7]) + LW_ctrl_241029_1_B.Rbe_psi[8] *
        LW_ctrl_241029_1_B.Integrator_a;
      LW_ctrl_241029_1_B.Filter_l = (-LW_ctrl_241029_1_B.Rbe_psi[0] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
        -LW_ctrl_241029_1_B.Rbe_psi[1] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
        -LW_ctrl_241029_1_B.Rbe_psi[2] * LW_ctrl_241029_1_B.Integrator_a;
      LW_ctrl_241029_1_B.FilterCoefficient_l = (-LW_ctrl_241029_1_DW.yb_[0] *
        0.0F + -LW_ctrl_241029_1_DW.yb_[1] * 0.0F) + -LW_ctrl_241029_1_DW.yb_[2]
        * 9.8F;
      LW_ctrl_241029_1_B.DeadZone_e = (((LW_ctrl_241029_1_B.delta_t *
        LW_ctrl_241029_1_B.Rbe_psi[0] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
        LW_ctrl_241029_1_B.delta_t * LW_ctrl_241029_1_B.Rbe_psi[1] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
        LW_ctrl_241029_1_B.delta_t * LW_ctrl_241029_1_B.Rbe_psi[2] *
        LW_ctrl_241029_1_B.Integrator_a) + ((LW_ctrl_241029_1_B.DeadZone_e *
        LW_ctrl_241029_1_B.Rbe_psi[6] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
        LW_ctrl_241029_1_B.DeadZone_e * LW_ctrl_241029_1_B.Rbe_psi[7] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
        LW_ctrl_241029_1_B.DeadZone_e * LW_ctrl_241029_1_B.Rbe_psi[8] *
        LW_ctrl_241029_1_B.Integrator_a)) * LW_ctrl_241029_1_B.km_f_b -
        LW_ctrl_241029_1_B.Va_;
      LW_ctrl_241029_1_B.delta_t = (((rtb_FilterCoefficient_jy_tmp *
        LW_ctrl_241029_1_B.Rbe_psi[0] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
        rtb_FilterCoefficient_jy_tmp * LW_ctrl_241029_1_B.Rbe_psi[1] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
        rtb_FilterCoefficient_jy_tmp * LW_ctrl_241029_1_B.Rbe_psi[2] *
        LW_ctrl_241029_1_B.Integrator_a) + ((LW_ctrl_241029_1_B.delta_t *
        LW_ctrl_241029_1_B.Rbe_psi[6] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
        LW_ctrl_241029_1_B.delta_t * LW_ctrl_241029_1_B.Rbe_psi[7] *
        LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
        LW_ctrl_241029_1_B.delta_t * LW_ctrl_241029_1_B.Rbe_psi[8] *
        LW_ctrl_241029_1_B.Integrator_a)) * -LW_ctrl_241029_1_B.km_f_b;

      /* '<S404>:1:122' if abs(A2*D3 - A3*D2) < 0.001 */
      rtb_FilterCoefficient_jy_tmp = LW_ctrl_241029_1_B.DeadZone_e *
        LW_ctrl_241029_1_B.Filter_l - LW_ctrl_241029_1_B.IntegralGain_gt *
        LW_ctrl_241029_1_B.delta_t;
      if ((real32_T)fabs(rtb_FilterCoefficient_jy_tmp) < 0.001) {
        /* '<S404>:1:123' wz = wz_; */
        LW_ctrl_241029_1_B.IntegralGain_gt = LW_ctrl_241029_1_DW.wz_;

        /* '<S404>:1:124' wx = (C2 - D2*wz)/A2; */
        LW_ctrl_241029_1_B.FilterCoefficient_jy =
          (LW_ctrl_241029_1_B.IntegralGain - LW_ctrl_241029_1_B.delta_t *
           LW_ctrl_241029_1_DW.wz_) / LW_ctrl_241029_1_B.DeadZone_e;

        /* wx = wx_; */
        /* '<S404>:1:126' wy = (C1 - A1*wx - D1*wz)/B1; */
        LW_ctrl_241029_1_B.wb_ref[1] = ((LW_ctrl_241029_1_B.kappa -
          LW_ctrl_241029_1_B.eta_p * LW_ctrl_241029_1_B.FilterCoefficient_jy) -
          LW_ctrl_241029_1_B.time_to_stop * LW_ctrl_241029_1_DW.wz_) /
          (LW_ctrl_241029_1_B.Va_ - (((LW_ctrl_241029_1_B.aSinInput *
              LW_ctrl_241029_1_B.Rbe_psi[6] *
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
              LW_ctrl_241029_1_B.aSinInput * LW_ctrl_241029_1_B.Rbe_psi[7] *
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
             LW_ctrl_241029_1_B.aSinInput * LW_ctrl_241029_1_B.Rbe_psi[8] *
             LW_ctrl_241029_1_B.Integrator_a) + ((LW_ctrl_241029_1_B.theta *
              LW_ctrl_241029_1_B.Rbe_psi[0] *
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
              LW_ctrl_241029_1_B.theta * LW_ctrl_241029_1_B.Rbe_psi[1] *
              LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
             LW_ctrl_241029_1_B.theta * LW_ctrl_241029_1_B.Rbe_psi[2] *
             LW_ctrl_241029_1_B.Integrator_a)) * LW_ctrl_241029_1_B.km_f_b);

        /* disp('Omega Signarity') */
      } else {
        /* '<S404>:1:128' else */
        /* '<S404>:1:129' wx = (C2*D3 - C3*D2)/(A2*D3 - A3*D2); */
        LW_ctrl_241029_1_B.FilterCoefficient_jy =
          (LW_ctrl_241029_1_B.IntegralGain * LW_ctrl_241029_1_B.Filter_l -
           LW_ctrl_241029_1_B.FilterCoefficient_l * LW_ctrl_241029_1_B.delta_t) /
          rtb_FilterCoefficient_jy_tmp;

        /* '<S404>:1:130' wy = -(A1*C2*D3 - A1*C3*D2 - A2*C1*D3 + A2*C3*D1 + A3*C1*D2 - A3*C2*D1)/(B1*(A2*D3 - A3*D2)); */
        LW_ctrl_241029_1_B.DeadZone_el = LW_ctrl_241029_1_B.DeadZone_e *
          LW_ctrl_241029_1_B.FilterCoefficient_l;
        LW_ctrl_241029_1_B.T1 = LW_ctrl_241029_1_B.IntegralGain_gt *
          LW_ctrl_241029_1_B.IntegralGain;
        LW_ctrl_241029_1_B.wb_ref[1] = -(((((LW_ctrl_241029_1_B.eta_p *
          LW_ctrl_241029_1_B.IntegralGain * LW_ctrl_241029_1_B.Filter_l -
          LW_ctrl_241029_1_B.eta_p * LW_ctrl_241029_1_B.FilterCoefficient_l *
          LW_ctrl_241029_1_B.delta_t) - LW_ctrl_241029_1_B.DeadZone_e *
          LW_ctrl_241029_1_B.kappa * LW_ctrl_241029_1_B.Filter_l) +
          LW_ctrl_241029_1_B.DeadZone_el * LW_ctrl_241029_1_B.time_to_stop) +
          LW_ctrl_241029_1_B.IntegralGain_gt * LW_ctrl_241029_1_B.kappa *
          LW_ctrl_241029_1_B.delta_t) - LW_ctrl_241029_1_B.T1 *
          LW_ctrl_241029_1_B.time_to_stop) / ((LW_ctrl_241029_1_B.Va_ -
          (((LW_ctrl_241029_1_B.aSinInput * LW_ctrl_241029_1_B.Rbe_psi[6] *
             LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
             LW_ctrl_241029_1_B.aSinInput * LW_ctrl_241029_1_B.Rbe_psi[7] *
             LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
            LW_ctrl_241029_1_B.aSinInput * LW_ctrl_241029_1_B.Rbe_psi[8] *
            LW_ctrl_241029_1_B.Integrator_a) + ((LW_ctrl_241029_1_B.theta *
          LW_ctrl_241029_1_B.Rbe_psi[0] *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[0] +
          LW_ctrl_241029_1_B.theta * LW_ctrl_241029_1_B.Rbe_psi[1] *
          LW_ctrl_241029_1_B.TmpSignalConversionAtDotPro[1]) +
          LW_ctrl_241029_1_B.theta * LW_ctrl_241029_1_B.Rbe_psi[2] *
          LW_ctrl_241029_1_B.Integrator_a)) * LW_ctrl_241029_1_B.km_f_b) *
          rtb_FilterCoefficient_jy_tmp);

        /* '<S404>:1:131' wz = (A2*C3 - A3*C2)/(A2*D3 - A3*D2); */
        LW_ctrl_241029_1_B.IntegralGain_gt = (LW_ctrl_241029_1_B.DeadZone_el -
          LW_ctrl_241029_1_B.T1) / rtb_FilterCoefficient_jy_tmp;

        /* '<S404>:1:132' wz_ = wz; */
        LW_ctrl_241029_1_DW.wz_ = LW_ctrl_241029_1_B.IntegralGain_gt;

        /* '<S404>:1:133' wx_ = wx; */
      }

      /*      wx = -(D2*wsz - C2*cos(kk-alpha))/(A2*cos(kk-alpha) + D2*sin(kk-alpha)); */
      /*      wy = (A1*D2*wsz - A2*D1*wsz - A1*C2*cos(kk-alpha) + A2*C1*cos(kk-alpha) + C1*D2*sin(kk-alpha) - C2*D1*sin(kk-alpha))/(B1*(A2*cos(kk-alpha) + D2*sin(kk-alpha))); */
      /*      wz = (A2*wsz + C2*sin(kk-alpha))/(A2*cos(kk-alpha) + D2*sin(kk-alpha)); */
      /* '<S404>:1:138' wbb = [wx; wy; wz]; */
      /* wbb(2) = constrain(wbb(2), -3, 3); wbb(1) = constrain(wbb(1), -3, 3); wbb(3) = constrain(wbb(3), -3, 3); */
      LW_ctrl_241029_1_B.wb_ref[0] = LW_ctrl_241029_1_B.FilterCoefficient_jy;
      LW_ctrl_241029_1_B.wb_ref[2] = LW_ctrl_241029_1_B.IntegralGain_gt;

      /* '<S404>:1:71' q_ref = R2quat(R_d); */
      /* R2QUAT 此处显示有关此函数的摘要 */
      /*    此处显示详细说明 */
      /* 'R2quat:5' q = single([1;0;0;0]); */
      /* 'R2quat:6' t = trace(R); */
      LW_ctrl_241029_1_B.IntegralGain = (LW_ctrl_241029_1_B.Rbe_psi[0] +
        LW_ctrl_241029_1_DW.yb_[1]) + LW_ctrl_241029_1_B.Rbe_psi[8];

      /* 'R2quat:7' if (t > (0)) */
      if (LW_ctrl_241029_1_B.IntegralGain > 0.0F) {
        /* 'R2quat:8' t = sqrt( single(1) + t); */
        profileStart_LW_ctrl_241029_1(105U); /* original_line:9335 */LW_ctrl_241029_1_B.IntegralGain = (real32_T)sqrt
          (LW_ctrl_241029_1_B.IntegralGain + 1.0F);profileEnd_LW_ctrl_241029_1(105U); /* original_line:9336 */

        /* 'R2quat:9' q(1) =  single(0.5) * t; */
        LW_ctrl_241029_1_B.qk_[0] = 0.5F * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:10' t =  single(0.5) / t; */
        LW_ctrl_241029_1_B.IntegralGain = 0.5F / LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:11' q(2) = (R(3,2) - R(2,3)) * t; */
        LW_ctrl_241029_1_B.qk_[1] = (LW_ctrl_241029_1_DW.yb_[2] -
          LW_ctrl_241029_1_B.Rbe_psi[7]) * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:12' q(3) = (R(1,3) - R(3,1)) * t; */
        LW_ctrl_241029_1_B.qk_[2] = (LW_ctrl_241029_1_B.Rbe_psi[6] -
          LW_ctrl_241029_1_B.Rbe_psi[2]) * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:13' q(4) = (R(2,1) - R(1,2)) * t; */
        LW_ctrl_241029_1_B.qk_[3] = (LW_ctrl_241029_1_B.Rbe_psi[1] -
          LW_ctrl_241029_1_DW.yb_[0]) * LW_ctrl_241029_1_B.IntegralGain;
      } else if ((LW_ctrl_241029_1_B.Rbe_psi[0] > LW_ctrl_241029_1_DW.yb_[1]) &&
                 (LW_ctrl_241029_1_B.Rbe_psi[0] > LW_ctrl_241029_1_B.Rbe_psi[8]))
      {
        /* 'R2quat:14' elseif (R(1,1) > R(2,2) && R(1,1) > R(3,3)) */
        /* 'R2quat:15' t = sqrt( single(1) + R(1,1) - R(2,2) - R(3,3)); */
        profileStart_LW_ctrl_241029_1(104U); /* original_line:9360 */LW_ctrl_241029_1_B.IntegralGain = (real32_T)sqrt
          (((LW_ctrl_241029_1_B.Rbe_psi[0] + 1.0F) - LW_ctrl_241029_1_DW.yb_[1])
           - LW_ctrl_241029_1_B.Rbe_psi[8]);profileEnd_LW_ctrl_241029_1(104U); /* original_line:9362 */

        /* 'R2quat:16' q(2) =  single(0.5) * t; */
        LW_ctrl_241029_1_B.qk_[1] = 0.5F * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:17' t =  single(0.5) / t; */
        LW_ctrl_241029_1_B.IntegralGain = 0.5F / LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:18' q(1) = (R(3,2) - R(2,3)) * t; */
        LW_ctrl_241029_1_B.qk_[0] = (LW_ctrl_241029_1_DW.yb_[2] -
          LW_ctrl_241029_1_B.Rbe_psi[7]) * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:19' q(3) = (R(2,1) + R(1,2)) * t; */
        LW_ctrl_241029_1_B.qk_[2] = (LW_ctrl_241029_1_DW.yb_[0] +
          LW_ctrl_241029_1_B.Rbe_psi[1]) * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:20' q(4) = (R(1,3) + R(3,1)) * t; */
        LW_ctrl_241029_1_B.qk_[3] = (LW_ctrl_241029_1_B.Rbe_psi[2] +
          LW_ctrl_241029_1_B.Rbe_psi[6]) * LW_ctrl_241029_1_B.IntegralGain;
      } else if (LW_ctrl_241029_1_DW.yb_[1] > LW_ctrl_241029_1_B.Rbe_psi[8]) {
        /* 'R2quat:21' elseif (R(2,2) > R(3,3)) */
        /* 'R2quat:22' t = sqrt( single(1) - R(1,1) + R(2,2) - R(3,3)); */
        profileStart_LW_ctrl_241029_1(103U); /* original_line:9384 */LW_ctrl_241029_1_B.IntegralGain = (real32_T)sqrt(((1.0F -
          LW_ctrl_241029_1_B.Rbe_psi[0]) + LW_ctrl_241029_1_DW.yb_[1]) -
          LW_ctrl_241029_1_B.Rbe_psi[8]);profileEnd_LW_ctrl_241029_1(103U); /* original_line:9386 */

        /* 'R2quat:23' q(3) =  single(0.5) * t; */
        LW_ctrl_241029_1_B.qk_[2] = 0.5F * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:24' t =  single(0.5) / t; */
        LW_ctrl_241029_1_B.IntegralGain = 0.5F / LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:25' q(1) = (R(1,3) - R(3,1)) * t; */
        LW_ctrl_241029_1_B.qk_[0] = (LW_ctrl_241029_1_B.Rbe_psi[6] -
          LW_ctrl_241029_1_B.Rbe_psi[2]) * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:26' q(2) = (R(2,1) + R(1,2)) * t; */
        LW_ctrl_241029_1_B.qk_[1] = (LW_ctrl_241029_1_DW.yb_[0] +
          LW_ctrl_241029_1_B.Rbe_psi[1]) * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:27' q(4) = (R(3,2) + R(2,3)) * t; */
        LW_ctrl_241029_1_B.qk_[3] = (LW_ctrl_241029_1_DW.yb_[2] +
          LW_ctrl_241029_1_B.Rbe_psi[7]) * LW_ctrl_241029_1_B.IntegralGain;
      } else {
        /* 'R2quat:28' else */
        /* 'R2quat:29' t = sqrt( single(1) - R(1,1) - R(2,2) + R(3,3)); */
        profileStart_LW_ctrl_241029_1(102U); /* original_line:9408 */LW_ctrl_241029_1_B.IntegralGain = (real32_T)sqrt(((1.0F -
          LW_ctrl_241029_1_B.Rbe_psi[0]) - LW_ctrl_241029_1_DW.yb_[1]) +
          LW_ctrl_241029_1_B.Rbe_psi[8]);profileEnd_LW_ctrl_241029_1(102U); /* original_line:9410 */

        /* 'R2quat:30' q(4) =  single(0.5) * t; */
        LW_ctrl_241029_1_B.qk_[3] = 0.5F * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:31' t =  single(0.5) / t; */
        LW_ctrl_241029_1_B.IntegralGain = 0.5F / LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:32' q(1) = (R(2,1) - R(1,2)) * t; */
        LW_ctrl_241029_1_B.qk_[0] = (LW_ctrl_241029_1_B.Rbe_psi[1] -
          LW_ctrl_241029_1_DW.yb_[0]) * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:33' q(2) = (R(1,3) + R(3,1)) * t; */
        LW_ctrl_241029_1_B.qk_[1] = (LW_ctrl_241029_1_B.Rbe_psi[2] +
          LW_ctrl_241029_1_B.Rbe_psi[6]) * LW_ctrl_241029_1_B.IntegralGain;

        /* 'R2quat:34' q(3) = (R(3,2) + R(2,3)) * t; */
        LW_ctrl_241029_1_B.qk_[2] = (LW_ctrl_241029_1_DW.yb_[2] +
          LW_ctrl_241029_1_B.Rbe_psi[7]) * LW_ctrl_241029_1_B.IntegralGain;
      }

      /* '<S404>:1:72' dotwb_ref = zeros(3,1,'single'); */
      LW_ctrl_241029_1_B.dotwb_ref[0] = 0.0F;
      LW_ctrl_241029_1_B.dotwb_ref[1] = 0.0F;
      LW_ctrl_241029_1_B.dotwb_ref[2] = 0.0F;

      /* '<S404>:1:73' beta = single(0); */
      LW_ctrl_241029_1_B.beta_a = 0.0F;

      /* '<S404>:1:74' OB_TASK = int8(2); */
      /* '<S404>:1:75' eee = my_quat2eul(q_ref); */
      /* MY_QUAT2EUL Convert quaternion to Euler angles, modified from quat2eul.m */
      /*    EUL = QUAT2EUL(QOBJ) converts a quaternion object, QOBJ, into the */
      /*    corresponding Euler angles, EUL.QOBJ is an 4-element vector of quaternion objects. */
      /*    The output, EUL, is an 3-element vector of Euler rotation angles,that is [roll;pitch;yaw]. Rotation angles are in radians. */
      /* 'my_quat2eul:6' q = q(:); */
      /* 'my_quat2eul:7' if isempty(varargin) */
      /*  Use default rotation sequence */
      /* 'my_quat2eul:9' seq = 'ZXY'; */
      /* 'my_quat2eul:13' q = robotics.internal.validation.validateQuaternion(q', 'quat2eul', 'q'); */
      /* norm_q = sqrt(q' * q); */
      /*  if norm_q < 0.5 */
      /*      q = [1;0;0;0]; */
      /*      norm_q = 1; */
      /*  end */
      /* q = q ./ norm_q; */
      /* 'my_quat2eul:20' q = robotics.internal.normalizeRows(q); */
      /* 'my_quat2eul:22' qw = q(1); */
      /* 'my_quat2eul:23' qx = q(2); */
      /* 'my_quat2eul:24' qy = q(3); */
      /* 'my_quat2eul:25' qz = q(4); */
      /*  Pre-allocate output */
      /* 'my_quat2eul:28' eul = single(zeros(3, 1,'like',q)); */
      /* 'my_quat2eul:29' upperSeq = upper(seq); */
      /* 'my_quat2eul:30' switch upperSeq */
      /* 'my_quat2eul:72' case 'ZXY' */
      /* 'my_quat2eul:73' aSinInput = 2 * (qy .* qz + qw .* qx); */
      /* 'my_quat2eul:74' if aSinInput > 1 */
      /* 'my_quat2eul:80' eul = [ asin( aSinInput ); ... */
      /* 'my_quat2eul:81'             atan2( -2 * (qx .* qz - qw .* qy), qw .^ 2 - qx .^ 2 - qy .^ 2 + qz .^ 2 ); ... */
      /* 'my_quat2eul:82'             atan2( -2 * (qx .* qy - qw .* qz), qw .^ 2 - qx .^ 2 + qy .^ 2 - qz .^ 2 )]; */
      /*  Check for complex numbers */
      /* 'my_quat2eul:93' if ~isreal(eul) */
      LW_ctrl_241029_1_B.q_ref[0] = LW_ctrl_241029_1_B.qk_[0];
      LW_ctrl_241029_1_B.q_ref[1] = LW_ctrl_241029_1_B.qk_[1];
      LW_ctrl_241029_1_B.q_ref[2] = LW_ctrl_241029_1_B.qk_[2];
      LW_ctrl_241029_1_B.q_ref[3] = LW_ctrl_241029_1_B.qk_[3];

      /* End of Outputs for SubSystem: '<S4>/navigator_offboard' */

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.vel_ref[0] = LW_ctrl_241029_1_B.max_vx;
      LW_ctrl_241029_1_B.vel_ref[1] = LW_ctrl_241029_1_B.max_vy;
      LW_ctrl_241029_1_B.vel_ref[2] = LW_ctrl_241029_1_B.max_vz;

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.pos[0] = LW_ctrl_241029_1_B.pos_ref_l[0];

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.vel[0] = LW_ctrl_241029_1_B.vel_ref_k[0];

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.pos[1] = LW_ctrl_241029_1_B.pos_ref_l[1];

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.vel[1] = LW_ctrl_241029_1_B.vel_ref_k[1];

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.pos[2] = LW_ctrl_241029_1_B.pos_ref_l[2];

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.vel[2] = LW_ctrl_241029_1_B.vel_ref_k[2];

      /* SignalConversion generated from: '<S4>/StatesRef' */
      LW_ctrl_241029_1_B.q[0] = LW_ctrl_241029_1_B.q_ref[0];
      LW_ctrl_241029_1_B.q[1] = LW_ctrl_241029_1_B.q_ref[1];
      LW_ctrl_241029_1_B.q[2] = LW_ctrl_241029_1_B.q_ref[2];
      LW_ctrl_241029_1_B.q[3] = LW_ctrl_241029_1_B.q_ref[3];

      /* S-Function (sfun_px4_uorb_write): '<S372>/uORB Write Advanced' */
      profileStart_LW_ctrl_241029_1(106U); /* original_line:9510 */{
        //struct costom_lw_navigator_s InputStruct;
        //memset( &InputStruct, 0, sizeof(InputStruct));

        /* assign input parameters to struct */
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.timestamp = (double)
          LW_ctrl_241029_1_B.sf_hrt_timestamp.ts;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.delta_t =
          LW_ctrl_241029_1_B.DataTypeConversion_g;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[0] =
          LW_ctrl_241029_1_B.roll_ref;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[1] =
          LW_ctrl_241029_1_B.pitch_ref;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[2] =
          LW_ctrl_241029_1_B.yaw_ref_n;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[3] =
          LW_ctrl_241029_1_B.rollrate_ref;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[4] =
          LW_ctrl_241029_1_B.pitchRate_d;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[5] =
          LW_ctrl_241029_1_B.yawrate_ref;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[6] =
          LW_ctrl_241029_1_B.thrust;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[7] =
          LW_ctrl_241029_1_B.delta_a;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[8] =
          LW_ctrl_241029_1_B.delta_e;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[9] =
          LW_ctrl_241029_1_B.delta_r;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[10] =
          LW_ctrl_241029_1_B.max_vx;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[11] =
          LW_ctrl_241029_1_B.max_vy;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.manual_ref[12] =
          LW_ctrl_241029_1_B.max_vz;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[0] =
          LW_ctrl_241029_1_B.pos_ref_l[0];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[1] =
          LW_ctrl_241029_1_B.pos_ref_l[1];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[2] =
          LW_ctrl_241029_1_B.pos_ref_l[2];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[3] =
          LW_ctrl_241029_1_B.vel_ref_k[0];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[4] =
          LW_ctrl_241029_1_B.vel_ref_k[1];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[5] =
          LW_ctrl_241029_1_B.vel_ref_k[2];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[6] =
          LW_ctrl_241029_1_B.acc_ref_b[0];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[7] =
          LW_ctrl_241029_1_B.acc_ref_b[1];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[8] =
          LW_ctrl_241029_1_B.acc_ref_b[2];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[9] =
          LW_ctrl_241029_1_B.q_ref[0];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[10] =
          LW_ctrl_241029_1_B.q_ref[1];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[11] =
          LW_ctrl_241029_1_B.q_ref[2];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[12] =
          LW_ctrl_241029_1_B.q_ref[3];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[13] =
          LW_ctrl_241029_1_B.f_d_l;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[14] =
          LW_ctrl_241029_1_B.alpha_d;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[15] =
          LW_ctrl_241029_1_B.beta_a;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[16] =
          LW_ctrl_241029_1_B.wb_ref[0];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[17] =
          LW_ctrl_241029_1_B.wb_ref[1];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[18] =
          LW_ctrl_241029_1_B.wb_ref[2];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[19] =
          LW_ctrl_241029_1_B.dotwb_ref[0];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[20] =
          LW_ctrl_241029_1_B.dotwb_ref[1];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[21] =
          LW_ctrl_241029_1_B.dotwb_ref[2];
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg.offboard_ref[22] =
          LW_ctrl_241029_1_B.DataTypeConversion5_h;

        /* Publish data for subscribers */
        orb_publish(ORB_ID(costom_lw_navigator),
                    LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_advert_p,
                    &LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg);
      }profileEnd_LW_ctrl_241029_1(106U); /* original_line:9596 */

      /* Outputs for Atomic SubSystem: '<S4>/navigator_offboard' */
      /* DataTypeConversion: '<S372>/Data Type Conversion5' incorporates:
       *  MATLAB Function: '<S403>/df,coor,wind'
       */
      LW_ctrl_241029_1_B.DataTypeConversion5_h = 2.0F;

      /* End of Outputs for SubSystem: '<S4>/navigator_offboard' */

      /* MATLAB Function: '<S372>/hrt_timestamp' */
      profileStart_LW_ctrl_241029_1(107U); /* original_line:9607 */LW_ctrl_241029_1_hrt_timestamp(&LW_ctrl_241029_1_B.sf_hrt_timestamp,
        &LW_ctrl_241029_1_DW.sf_hrt_timestamp);profileEnd_LW_ctrl_241029_1(107U); /* original_line:9608 */

      /* Gain: '<S373>/Gain' incorporates:
       *  Memory: '<S373>/Memory'
       *  Sum: '<S373>/Sum'
       */
      LW_ctrl_241029_1_B.u0 = (LW_ctrl_241029_1_B.sf_hrt_timestamp.ts -
        LW_ctrl_241029_1_DW.Memory_PreviousInput_i) * 1.0E-6;

      /* Saturate: '<S373>/Saturation' */
      if (LW_ctrl_241029_1_B.u0 > 0.2) {
        /* DataTypeConversion: '<S373>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_g = 0.2F;
      } else if (LW_ctrl_241029_1_B.u0 < 0.001) {
        /* DataTypeConversion: '<S373>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_g = 0.001F;
      } else {
        /* DataTypeConversion: '<S373>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_g = (real32_T)
          LW_ctrl_241029_1_B.u0;
      }

      /* End of Saturate: '<S373>/Saturation' */

      /* Update for Memory: '<S373>/Memory' */
      LW_ctrl_241029_1_DW.Memory_PreviousInput_i =
        LW_ctrl_241029_1_B.sf_hrt_timestamp.ts;

      /* End of Outputs for SubSystem: '<Root>/navigator' */
    }

    /* '<S3>:1:7' sf_internal_predicateOutput = every(StateMachine_cycle,tick); */
    if (LW_ctrl_241029_1_DW.temporalCounter_i6 == 1U) {
      /* Outputs for Function Call SubSystem: '<Root>/state_machine' */
      /* S-Function (sfun_px4_uorb_read_topic): '<S6>/uORB Read Function-Call Trigger' */
      /* '<S3>:1:7' send(StateMachine); */
      /* Event: '<S3>:10' */
      profileStart_LW_ctrl_241029_1(108U); /* original_line:9645 */{
        //interval val: 4
        bool updated;
        orb_check(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_d.fd,
                  &updated);
        if (updated) {
          /* obtained uorb data */
          /* copy sensors raw data into local buffer */
          orb_copy(ORB_ID(actuator_armed),
                   LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_d.fd,
                   &LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger_c);
        }
      }profileEnd_LW_ctrl_241029_1(108U); /* original_line:9657 */

      /* MATLAB Function: '<S6>/MATLAB Function3' */
      /* Function description: */
      /*   the remote control CH6 channel arm or disarm the vehicle */
      /* input: */
      /*   ch6: Remote control CH6 channel input */
      /* MATLAB Function 'state_machine/MATLAB Function3': '<S412>:1' */
      /*  if ch6 > 1700 || armed == 1 */
      /*      arm = ControlMode.ARM; */
      /*  else */
      /*      arm = ControlMode.DISARM; */
      /*  end */
      /* '<S412>:1:13' if ch6 < 1700 && armed == 0 */
      if ((LW_ctrl_241029_1_B.AU6 < 1700.0F) &&
          (!LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger_c.armed)) {
        /* '<S412>:1:14' arm = ControlMode.DISARM; */
        LW_ctrl_241029_1_B.arm = DISARM;
      } else {
        /* '<S412>:1:15' else */
        /* '<S412>:1:16' arm = ControlMode.ARM; */
        LW_ctrl_241029_1_B.arm = ARM;
      }

      /* End of MATLAB Function: '<S6>/MATLAB Function3' */

      /* MATLAB Function: '<S6>/MATLAB Function4' */
      /* Function description: */
      /*   Map the remote control CH5 channel to control mode */
      /* input: */
      /*   ch5: Remote control CH5 channel input */
      /*   control_mode: Custom control mode */
      /*   0: stablelize mode；1: height control mode; 2: position control mode */
      /*   4: attitude rate mode */
      /*   the remote control CH8 channel change the flight mode */
      /* input: */
      /*   ch8: Remote control CH8 channel input */
      /* MATLAB Function 'state_machine/MATLAB Function4': '<S413>:1' */
      /* '<S413>:1:13' if ch5 < 1400 */
      if (LW_ctrl_241029_1_B.AU5 < 1400.0F) {
        /* '<S413>:1:14' ctrl_mode = ControlMode.STABILIZED; */
        LW_ctrl_241029_1_B.ctrl_mode = STABILIZED;

        /* '<S413>:1:15' if ch7 >1300 && ch7 < 1600 */
        if (((!(LW_ctrl_241029_1_B.AU7 > 1300.0F)) || (!(LW_ctrl_241029_1_B.AU7 <
               1600.0F))) && (LW_ctrl_241029_1_B.AU7 >= 1600.0F)) {
          /* '<S413>:1:17' elseif ch7 >= 1600 */
          /* '<S413>:1:18' ctrl_mode = ControlMode.MANUAL; */
          LW_ctrl_241029_1_B.ctrl_mode = MANUAL;
        } else {
          /* ctrl_mode = ControlMode.ACRO; */
        }
      } else if (LW_ctrl_241029_1_B.AU5 < 1600.0F) {
        /* '<S413>:1:20' elseif ch5 < 1600 */
        /* '<S413>:1:21' ctrl_mode = ControlMode.ALTITUDE; */
        LW_ctrl_241029_1_B.ctrl_mode = ALTITUDE;
      } else {
        /* '<S413>:1:22' else */
        /* '<S413>:1:23' ctrl_mode = ControlMode.POSITION; */
        LW_ctrl_241029_1_B.ctrl_mode = POSITION;
      }

      /* '<S413>:1:25' if ch8 < 1400 */
      if (LW_ctrl_241029_1_B.AU8 < 1400.0F) {
        /* '<S413>:1:26' flight_mode = FlightMode.PILOT; */
        LW_ctrl_241029_1_B.flight_mode = PILOT;

        /*  elseif ch8 < 1600 */
        /*      flight_mode = FlightMode.AUTO; */
        /*      ctrl_mode = ControlMode.MISSION; */
      } else {
        /* '<S413>:1:30' else */
        /* '<S413>:1:31' flight_mode = FlightMode.OFFBOARD; */
        LW_ctrl_241029_1_B.flight_mode = OFFBOARD;
      }

      /* End of MATLAB Function: '<S6>/MATLAB Function4' */

      /* S-Function (sfun_px4_uorb_write): '<S415>/uORB Write Advanced1' */
      /* '<S413>:1:34' if RC_Lost > 0.5 */
      /*  if armed > 0.5 && ch8 > 1500 */
      /*      flight_mode = FlightMode.OFFBOARD; */
      /*  end */
      profileStart_LW_ctrl_241029_1(109U); /* original_line:9740 */{
        //struct costom_lw_statemachine_s InputStruct;
        //memset( &InputStruct, 0, sizeof(InputStruct));

        /* assign input parameters to struct */
        LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_msg.timestamp = (double)
          LW_ctrl_241029_1_B.sf_hrt_timestamp_p.ts;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_msg.delta_t =
          LW_ctrl_241029_1_B.DataTypeConversion_p;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_msg.flight_mode =
          LW_ctrl_241029_1_B.DataTypeConversion1;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_msg.control_mode =
          LW_ctrl_241029_1_B.DataTypeConversion2;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_msg.arm =
          LW_ctrl_241029_1_B.DataTypeConversion3;

        /* Publish data for subscribers */
        orb_publish(ORB_ID(costom_lw_statemachine),
                    LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_advert,
                    &LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_msg);
      }profileEnd_LW_ctrl_241029_1(109U); /* original_line:9760 */

      /* DataTypeConversion: '<S415>/Data Type Conversion1' */
      LW_ctrl_241029_1_B.DataTypeConversion1 = (uint8_T)
        LW_ctrl_241029_1_B.flight_mode;

      /* DataTypeConversion: '<S415>/Data Type Conversion2' */
      LW_ctrl_241029_1_B.DataTypeConversion2 = (uint8_T)
        LW_ctrl_241029_1_B.ctrl_mode;

      /* DataTypeConversion: '<S415>/Data Type Conversion3' */
      LW_ctrl_241029_1_B.DataTypeConversion3 = (uint8_T)LW_ctrl_241029_1_B.arm;

      /* MATLAB Function: '<S415>/hrt_timestamp' */
      profileStart_LW_ctrl_241029_1(110U); /* original_line:9774 */LW_ctrl_241029_1_hrt_timestamp(&LW_ctrl_241029_1_B.sf_hrt_timestamp_p,
        &LW_ctrl_241029_1_DW.sf_hrt_timestamp_p);profileEnd_LW_ctrl_241029_1(110U); /* original_line:9775 */

      /* Gain: '<S416>/Gain' incorporates:
       *  Memory: '<S416>/Memory'
       *  Sum: '<S416>/Sum'
       */
      LW_ctrl_241029_1_B.u0 = (LW_ctrl_241029_1_B.sf_hrt_timestamp_p.ts -
        LW_ctrl_241029_1_DW.Memory_PreviousInput_fs) * 1.0E-6;

      /* Saturate: '<S416>/Saturation' */
      if (LW_ctrl_241029_1_B.u0 > 0.2) {
        /* DataTypeConversion: '<S416>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_p = 0.2F;
      } else if (LW_ctrl_241029_1_B.u0 < 0.001) {
        /* DataTypeConversion: '<S416>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_p = 0.001F;
      } else {
        /* DataTypeConversion: '<S416>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_p = (real32_T)
          LW_ctrl_241029_1_B.u0;
      }

      /* End of Saturate: '<S416>/Saturation' */

      /* Update for Memory: '<S416>/Memory' */
      LW_ctrl_241029_1_DW.Memory_PreviousInput_fs =
        LW_ctrl_241029_1_B.sf_hrt_timestamp_p.ts;

      /* End of Outputs for SubSystem: '<Root>/state_machine' */
    }

    /* '<S3>:1:8' sf_internal_predicateOutput = every(RCReceive_cycle,tick); */
    if (LW_ctrl_241029_1_DW.temporalCounter_i7 == 4U) {
      /* Outputs for Function Call SubSystem: '<Root>/rc_receive' */
      /* S-Function (sfun_px4_input_rc): '<S407>/input_rc'
       *
       * Block description for '<S407>/input_rc':
       *  RC Input Block
       *
       *  This block provides user input control to the model.
       *  It uses the input_rc uORB topic.
       *
       *  The user has the ability to choose which channels are available as outputs from this block and also some optional outputs. These include
       *  Channels 1 through 18
       *  double data type indicating the PWM value from the controller
       *  measured pulse widths for each of the supported channels
       *  Channel Count
       *  uint32 data type of the number of channels which are detector by the PX4
       *  RC Failsafe
       *  boolean data types indicating that the RC Tx is sending the FailSafe signal (if equipped and properly setup)
       *  explicit failsafe flag: true on TX failure or TX out of range , false otherwise.
       *  Only the true state is reliable, as there are some (PPM) receivers on the market going into failsafe without telling us explicitly.
       *  RC Input Source
       *  Enumeration data type indicating which source the RC input is from.
       *  Valid values are found in the ENUM file: RC_INPUT_SOURCE_ENUM.m
       *            Enumeration members for class 'RC_INPUT_SOURCE_ENUM':
       *            RCINPUT_SOURCE_UNKNOWN         (0)
       *            RCINPUT_SOURCE_PX4FMU_PPM      (1)
       *            RCINPUT_SOURCE_PX4IO_PPM       (2)
       *            RCINPUT_SOURCE_PX4IO_SPEKTRUM  (3)
       *            RCINPUT_SOURCE_PX4IO_SBUS      (4)
       *            RCINPUT_SOURCE_PX4IO_ST24      (5)
       *            RCINPUT_SOURCE_MAVLINK         (6)
       *            RCINPUT_SOURCE_QURT            (7)
       *            RCINPUT_SOURCE_PX4FMU_SPEKTRUM (8)
       *            RCINPUT_SOURCE_PX4FMU_SBUS     (9)
       *            RCINPUT_SOURCE_PX4FMU_ST24     (10)
       *            RCINPUT_SOURCE_PX4FMU_SUMD     (11)
       *            RCINPUT_SOURCE_PX4FMU_DSM      (12)
       *            RCINPUT_SOURCE_PX4IO_SUMD      (13)
       *
       *  RSSI - Receive signal strength index
       *  receive signal strength indicator (RSSI): < 0: Undefined, 0: no signal, 255: full reception
       *  RC Lost Connection
       *  boolean data type indicating RC receiver connection status
       *  True, if no frame has arrived in the expected time, false otherwise.
       *  True usally means that the receiver has been disconnected, but can also indicate a radio link loss on "stupid" systems.
       *  Will remain false, if a RX with failsafe option continues to transmit frames after a link loss.
       *
       *  Sample Model: px4demo_input_rc.slx
       */
      /* '<S3>:1:8' send(RCReceive); */
      /* Event: '<S3>:20' */
      profileStart_LW_ctrl_241029_1(111U); /* original_line:9858 */{
        bool updated;
        orb_check(LW_ctrl_241029_1_DW.input_rc_input_rc_fd_b.fd, &updated);
        if (updated) {
          struct input_rc_s pwm_inputs;

          /* copy input_rc raw data into local buffer (uint16)*/
          orb_copy(ORB_ID(input_rc),
                   LW_ctrl_241029_1_DW.input_rc_input_rc_fd_b.fd, &pwm_inputs);
          LW_ctrl_241029_1_B.input_rc_o1 = pwm_inputs.values[0];
          LW_ctrl_241029_1_B.input_rc_o2 = pwm_inputs.values[1];
          LW_ctrl_241029_1_B.input_rc_o3 = pwm_inputs.values[2];
          LW_ctrl_241029_1_B.input_rc_o4 = pwm_inputs.values[3];
          LW_ctrl_241029_1_B.input_rc_o5 = pwm_inputs.values[4];
          LW_ctrl_241029_1_B.input_rc_o6 = pwm_inputs.values[5];
          LW_ctrl_241029_1_B.input_rc_o7 = pwm_inputs.values[6];
          LW_ctrl_241029_1_B.input_rc_o8 = pwm_inputs.values[7];
          LW_ctrl_241029_1_B.input_rc_o9 = pwm_inputs.rc_failsafe;
          LW_ctrl_241029_1_B.input_rc_o10 = pwm_inputs.rc_lost;
        }
      }profileEnd_LW_ctrl_241029_1(111U); /* original_line:9878 */

      /* MATLAB Function: '<S407>/MATLAB Function' */
      /* MATLAB Function 'rc_receive/manual_ctrl_in/HIL&FLY V1.13.3/MATLAB Function': '<S408>:1' */
      /* '<S408>:1:5' if isempty(rc_lost_count) */
      /* '<S408>:1:8' x = rcNormalize(single(ch2), RC2_MIN, RC2_MAX, RC2_REV,single(0.0)); */
      profileStart_LW_ctrl_241029_1(112U); /* original_line:9884 */LW_ctrl_241029_1_B.IntegralGain = LW_ctrl_241029_1_rcNormalize((real32_T)
        LW_ctrl_241029_1_B.input_rc_o2, RC2_MIN, RC2_MAX, RC2_REV, 0.0F);profileEnd_LW_ctrl_241029_1(112U); /* original_line:9885 */

      /* '<S408>:1:9' x = constrain(x, single(-1), single(1)); */
      /* CONSTRAIN 此处显示有关此函数的摘要 */
      /*    此处显示详细说明 */
      /*  min  = single(min); */
      /*  max = single(max); */
      /* 'constrain:6' if x > max */
      if (LW_ctrl_241029_1_B.IntegralGain > 1.0F) {
        /* 'constrain:7' y = max; */
        LW_ctrl_241029_1_B.x = 1.0F;
      } else if (LW_ctrl_241029_1_B.IntegralGain < -1.0F) {
        /* 'constrain:8' elseif x < min */
        /* 'constrain:9' y = min; */
        LW_ctrl_241029_1_B.x = -1.0F;
      } else {
        /* 'constrain:10' else */
        /* 'constrain:11' y = x; */
        LW_ctrl_241029_1_B.x = LW_ctrl_241029_1_B.IntegralGain;
      }

      /* '<S408>:1:10' y = rcNormalize(single(ch1), RC1_MIN, RC1_MAX, RC1_REV,single(0.0)); */
      profileStart_LW_ctrl_241029_1(113U); /* original_line:9907 */LW_ctrl_241029_1_B.IntegralGain = LW_ctrl_241029_1_rcNormalize((real32_T)
        LW_ctrl_241029_1_B.input_rc_o1, RC1_MIN, RC1_MAX, RC1_REV, 0.0F);profileEnd_LW_ctrl_241029_1(113U); /* original_line:9908 */

      /* '<S408>:1:11' y = constrain(y, single(-1), single(1)); */
      /* CONSTRAIN 此处显示有关此函数的摘要 */
      /*    此处显示详细说明 */
      /*  min  = single(min); */
      /*  max = single(max); */
      /* 'constrain:6' if x > max */
      if (LW_ctrl_241029_1_B.IntegralGain > 1.0F) {
        /* 'constrain:7' y = max; */
        LW_ctrl_241029_1_B.y_b = 1.0F;
      } else if (LW_ctrl_241029_1_B.IntegralGain < -1.0F) {
        /* 'constrain:8' elseif x < min */
        /* 'constrain:9' y = min; */
        LW_ctrl_241029_1_B.y_b = -1.0F;
      } else {
        /* 'constrain:10' else */
        /* 'constrain:11' y = x; */
        LW_ctrl_241029_1_B.y_b = LW_ctrl_241029_1_B.IntegralGain;
      }

      /* '<S408>:1:12' z = rcNormalize(single(ch3), RC3_MIN, RC3_MAX, RC3_REV,single(0.0)); */
      /* '<S408>:1:13' z = (z + 1)*0.5; */
      profileStart_LW_ctrl_241029_1(114U); /* original_line:9931 */LW_ctrl_241029_1_B.IntegralGain = (LW_ctrl_241029_1_rcNormalize((real32_T)
        LW_ctrl_241029_1_B.input_rc_o3, RC3_MIN, RC3_MAX, RC3_REV, 0.0F) + 1.0F)
        * 0.5F;profileEnd_LW_ctrl_241029_1(114U); /* original_line:9933 */

      /* '<S408>:1:14' z = constrain(z, single(0), single(1)); */
      /* CONSTRAIN 此处显示有关此函数的摘要 */
      /*    此处显示详细说明 */
      /*  min  = single(min); */
      /*  max = single(max); */
      /* 'constrain:6' if x > max */
      if (LW_ctrl_241029_1_B.IntegralGain > 1.0F) {
        /* 'constrain:7' y = max; */
        LW_ctrl_241029_1_B.z = 1.0F;
      } else if (LW_ctrl_241029_1_B.IntegralGain < 0.0F) {
        /* 'constrain:8' elseif x < min */
        /* 'constrain:9' y = min; */
        LW_ctrl_241029_1_B.z = 0.0F;
      } else {
        /* 'constrain:10' else */
        /* 'constrain:11' y = x; */
        LW_ctrl_241029_1_B.z = LW_ctrl_241029_1_B.IntegralGain;
      }

      /* '<S408>:1:15' r = rcNormalize(single(ch4), RC4_MIN, RC4_MAX, RC4_REV,single(0.0)); */
      profileStart_LW_ctrl_241029_1(115U); /* original_line:9955 */LW_ctrl_241029_1_B.IntegralGain = LW_ctrl_241029_1_rcNormalize((real32_T)
        LW_ctrl_241029_1_B.input_rc_o4, RC4_MIN, RC4_MAX, RC4_REV, 0.0F);profileEnd_LW_ctrl_241029_1(115U); /* original_line:9956 */

      /* '<S408>:1:16' r = constrain(r, single(-1), single(1)); */
      /* CONSTRAIN 此处显示有关此函数的摘要 */
      /*    此处显示详细说明 */
      /*  min  = single(min); */
      /*  max = single(max); */
      /* 'constrain:6' if x > max */
      if (LW_ctrl_241029_1_B.IntegralGain > 1.0F) {
        /* 'constrain:7' y = max; */
        LW_ctrl_241029_1_B.r = 1.0F;
      } else if (LW_ctrl_241029_1_B.IntegralGain < -1.0F) {
        /* 'constrain:8' elseif x < min */
        /* 'constrain:9' y = min; */
        LW_ctrl_241029_1_B.r = -1.0F;
      } else {
        /* 'constrain:10' else */
        /* 'constrain:11' y = x; */
        LW_ctrl_241029_1_B.r = LW_ctrl_241029_1_B.IntegralGain;
      }

      /* '<S408>:1:17' AU5 = single(ch5); */
      LW_ctrl_241029_1_B.AU5 = LW_ctrl_241029_1_B.input_rc_o5;

      /* '<S408>:1:18' AU6 = single(ch6); */
      LW_ctrl_241029_1_B.AU6 = LW_ctrl_241029_1_B.input_rc_o6;

      /* '<S408>:1:19' AU7 = single(ch7); */
      LW_ctrl_241029_1_B.AU7 = LW_ctrl_241029_1_B.input_rc_o7;

      /* '<S408>:1:20' AU8 = single(ch8); */
      LW_ctrl_241029_1_B.AU8 = LW_ctrl_241029_1_B.input_rc_o8;

      /* '<S408>:1:21' RC_LOST = single(0.0); */
      LW_ctrl_241029_1_B.IntegralGain = 0.0F;

      /* '<S408>:1:22' if rc_lost > single(0.5) || failsafe > single(0.5) */
      if (((real32_T)LW_ctrl_241029_1_B.input_rc_o10 > 0.5F) || ((real32_T)
           LW_ctrl_241029_1_B.input_rc_o9 > 0.5F)) {
        /* '<S408>:1:23' rc_lost_count = rc_lost_count + single(1); */
        LW_ctrl_241029_1_DW.rc_lost_count++;

        /* '<S408>:1:24' if rc_lost_count > single(5) */
        if (LW_ctrl_241029_1_DW.rc_lost_count > 5.0F) {
          /* '<S408>:1:25' RC_LOST = single(1.0); */
          LW_ctrl_241029_1_B.IntegralGain = 1.0F;

          /* '<S408>:1:26' rc_lost_count = single(5); */
          LW_ctrl_241029_1_DW.rc_lost_count = 5.0F;
        }
      } else {
        /* '<S408>:1:28' else */
        /* '<S408>:1:29' rc_lost_count = single(0.0); */
        LW_ctrl_241029_1_DW.rc_lost_count = 0.0F;
      }

      /* End of MATLAB Function: '<S407>/MATLAB Function' */

      /* S-Function (sfun_px4_uorb_write): '<S409>/uORB Write Advanced' */
      profileStart_LW_ctrl_241029_1(116U); /* original_line:10015 */{
        //struct costom_lw_manual_ctrl_in_s InputStruct;
        //memset( &InputStruct, 0, sizeof(InputStruct));

        /* assign input parameters to struct */
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.timestamp = (double)
          LW_ctrl_241029_1_B.sf_hrt_timestamp_k.ts;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.delta_t =
          LW_ctrl_241029_1_B.DataTypeConversion_h;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.x =
          LW_ctrl_241029_1_B.x;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.y =
          LW_ctrl_241029_1_B.y_b;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.r =
          LW_ctrl_241029_1_B.r;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.z =
          LW_ctrl_241029_1_B.z;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.au5 =
          LW_ctrl_241029_1_B.DataTypeConversion5;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.au6 =
          LW_ctrl_241029_1_B.DataTypeConversion6;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.au7 =
          LW_ctrl_241029_1_B.DataTypeConversion7;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.au8 =
          LW_ctrl_241029_1_B.DataTypeConversion9;
        LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d.rc_lost =
          LW_ctrl_241029_1_B.DataTypeConversion8;

        /* Publish data for subscribers */
        orb_publish(ORB_ID(costom_lw_manual_ctrl_in),
                    LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_advert,
                    &LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_msg_d);
      }profileEnd_LW_ctrl_241029_1(116U); /* original_line:10047 */

      /* DataTypeConversion: '<S409>/Data Type Conversion5' */
      profileStart_LW_ctrl_241029_1(117U); /* original_line:10050 */LW_ctrl_241029_1_B.DataTypeConversion5 = (uint32_T)(real32_T)fmod
        (LW_ctrl_241029_1_B.AU5, 4.294967296E+9);profileEnd_LW_ctrl_241029_1(117U); /* original_line:10051 */

      /* DataTypeConversion: '<S409>/Data Type Conversion6' */
      profileStart_LW_ctrl_241029_1(118U); /* original_line:10054 */LW_ctrl_241029_1_B.DataTypeConversion6 = (uint32_T)(real32_T)fmod
        (LW_ctrl_241029_1_B.AU6, 4.294967296E+9);profileEnd_LW_ctrl_241029_1(118U); /* original_line:10055 */

      /* DataTypeConversion: '<S409>/Data Type Conversion7' */
      profileStart_LW_ctrl_241029_1(119U); /* original_line:10058 */LW_ctrl_241029_1_B.DataTypeConversion7 = (uint32_T)(real32_T)fmod
        (LW_ctrl_241029_1_B.AU7, 4.294967296E+9);profileEnd_LW_ctrl_241029_1(119U); /* original_line:10059 */

      /* DataTypeConversion: '<S409>/Data Type Conversion8' */
      LW_ctrl_241029_1_B.DataTypeConversion8 = (LW_ctrl_241029_1_B.IntegralGain
        != 0.0F);

      /* DataTypeConversion: '<S409>/Data Type Conversion9' */
      profileStart_LW_ctrl_241029_1(120U); /* original_line:10066 */LW_ctrl_241029_1_B.DataTypeConversion9 = (uint32_T)(real32_T)fmod
        (LW_ctrl_241029_1_B.AU8, 4.294967296E+9);profileEnd_LW_ctrl_241029_1(120U); /* original_line:10067 */

      /* MATLAB Function: '<S409>/hrt_timestamp' */
      profileStart_LW_ctrl_241029_1(121U); /* original_line:10070 */LW_ctrl_241029_1_hrt_timestamp(&LW_ctrl_241029_1_B.sf_hrt_timestamp_k,
        &LW_ctrl_241029_1_DW.sf_hrt_timestamp_k);profileEnd_LW_ctrl_241029_1(121U); /* original_line:10071 */

      /* Gain: '<S410>/Gain' incorporates:
       *  Memory: '<S410>/Memory'
       *  Sum: '<S410>/Sum'
       */
      LW_ctrl_241029_1_B.u0 = (LW_ctrl_241029_1_B.sf_hrt_timestamp_k.ts -
        LW_ctrl_241029_1_DW.Memory_PreviousInput_f) * 1.0E-6;

      /* Saturate: '<S410>/Saturation' */
      if (LW_ctrl_241029_1_B.u0 > 0.2) {
        /* DataTypeConversion: '<S410>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_h = 0.2F;
      } else if (LW_ctrl_241029_1_B.u0 < 0.001) {
        /* DataTypeConversion: '<S410>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_h = 0.001F;
      } else {
        /* DataTypeConversion: '<S410>/Data Type Conversion' */
        LW_ctrl_241029_1_B.DataTypeConversion_h = (real32_T)
          LW_ctrl_241029_1_B.u0;
      }

      /* End of Saturate: '<S410>/Saturation' */

      /* Update for Memory: '<S410>/Memory' */
      LW_ctrl_241029_1_DW.Memory_PreviousInput_f =
        LW_ctrl_241029_1_B.sf_hrt_timestamp_k.ts;

      /* End of Outputs for SubSystem: '<Root>/rc_receive' */
    }
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i1 == 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i1 = 0U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i2 == 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i2 = 0U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i3 == 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i3 = 0U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i4 == 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i4 = 0U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i5 == 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i5 = 0U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i6 == 1U) {
    LW_ctrl_241029_1_DW.temporalCounter_i6 = 0U;
  }

  if (LW_ctrl_241029_1_DW.temporalCounter_i7 == 4U) {
    LW_ctrl_241029_1_DW.temporalCounter_i7 = 0U;
  }

  /* End of Chart: '<Root>/Scheduler' */

  /* S-Function (sfun_px4_uorb_write_dai): '<S367>/actuator_armed_rfly' */
  profileStart_LW_ctrl_241029_1(122U); /* original_line:10134 */{
    //struct actuator_armed_s InputStruct;
    //memset( &InputStruct, 0, sizeof(InputStruct));
    int isSend= 1;

    /* assign input parameters to struct */
    LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_msg.armed =
      LW_ctrl_241029_1_B.isSim;
    LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_msg.prearmed =
      LW_ctrl_241029_1_B.isTor;
    LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_msg.ready_to_arm =
      LW_ctrl_241029_1_B.isIO;
    LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_msg.lockdown =
      LW_ctrl_241029_1_B.isRC;
    isSend= LW_ctrl_241029_1_B.isSend;
    LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_msg.timestamp =
      hrt_absolute_time();
    if (isSend>0.5) {
      /* Publish data for subscribers */
      orb_publish(ORB_ID(actuator_armed_rfly),
                  LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_advert,
                  &LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_msg);
    }
  }profileEnd_LW_ctrl_241029_1(122U); /* original_line:10157 */

  /* S-Function (sfun_px4_input_rc): '<S361>/input_rc'
   *
   * Block description for '<S361>/input_rc':
   *  RC Input Block
   *
   *  This block provides user input control to the model.
   *  It uses the input_rc uORB topic.
   *
   *  The user has the ability to choose which channels are available as outputs from this block and also some optional outputs. These include
   *  Channels 1 through 18
   *  double data type indicating the PWM value from the controller
   *  measured pulse widths for each of the supported channels
   *  Channel Count
   *  uint32 data type of the number of channels which are detector by the PX4
   *  RC Failsafe
   *  boolean data types indicating that the RC Tx is sending the FailSafe signal (if equipped and properly setup)
   *  explicit failsafe flag: true on TX failure or TX out of range , false otherwise.
   *  Only the true state is reliable, as there are some (PPM) receivers on the market going into failsafe without telling us explicitly.
   *  RC Input Source
   *  Enumeration data type indicating which source the RC input is from.
   *  Valid values are found in the ENUM file: RC_INPUT_SOURCE_ENUM.m
   *            Enumeration members for class 'RC_INPUT_SOURCE_ENUM':
   *            RCINPUT_SOURCE_UNKNOWN         (0)
   *            RCINPUT_SOURCE_PX4FMU_PPM      (1)
   *            RCINPUT_SOURCE_PX4IO_PPM       (2)
   *            RCINPUT_SOURCE_PX4IO_SPEKTRUM  (3)
   *            RCINPUT_SOURCE_PX4IO_SBUS      (4)
   *            RCINPUT_SOURCE_PX4IO_ST24      (5)
   *            RCINPUT_SOURCE_MAVLINK         (6)
   *            RCINPUT_SOURCE_QURT            (7)
   *            RCINPUT_SOURCE_PX4FMU_SPEKTRUM (8)
   *            RCINPUT_SOURCE_PX4FMU_SBUS     (9)
   *            RCINPUT_SOURCE_PX4FMU_ST24     (10)
   *            RCINPUT_SOURCE_PX4FMU_SUMD     (11)
   *            RCINPUT_SOURCE_PX4FMU_DSM      (12)
   *            RCINPUT_SOURCE_PX4IO_SUMD      (13)
   *
   *  RSSI - Receive signal strength index
   *  receive signal strength indicator (RSSI): < 0: Undefined, 0: no signal, 255: full reception
   *  RC Lost Connection
   *  boolean data type indicating RC receiver connection status
   *  True, if no frame has arrived in the expected time, false otherwise.
   *  True usally means that the receiver has been disconnected, but can also indicate a radio link loss on "stupid" systems.
   *  Will remain false, if a RX with failsafe option continues to transmit frames after a link loss.
   *
   *  Sample Model: px4demo_input_rc.slx
   */
  profileStart_LW_ctrl_241029_1(123U); /* original_line:10206 */{
    bool updated;
    orb_check(LW_ctrl_241029_1_DW.input_rc_input_rc_fd.fd, &updated);
    if (updated) {
      struct input_rc_s pwm_inputs;

      /* copy input_rc raw data into local buffer (uint16)*/
      orb_copy(ORB_ID(input_rc), LW_ctrl_241029_1_DW.input_rc_input_rc_fd.fd,
               &pwm_inputs);
      LW_ctrl_241029_1_B.input_rc = pwm_inputs.values[4];
    }
  }profileEnd_LW_ctrl_241029_1(123U); /* original_line:10217 */

  /* MATLAB Function: '<S361>/MATLAB Function' */
  /* MATLAB Function 'Output/OutputSelect/HIL/MATLAB Function': '<S363>:1' */
  /* '<S363>:1:3' if u > 1700 */
  if (LW_ctrl_241029_1_B.input_rc > 1700) {
    /* '<S363>:1:4' y = boolean(1); */
    rtb_RelationalOperator_om = true;
  } else {
    /* '<S363>:1:5' else */
    /* '<S363>:1:6' y = boolean(0); */
    rtb_RelationalOperator_om = false;
  }

  /* End of MATLAB Function: '<S361>/MATLAB Function' */

  /* MATLAB Function: '<S362>/ArmTrig1' */
  /* MATLAB Function 'HIL16CtrlsPWM/ArmTrig1': '<S366>:1' */
  /* '<S366>:1:4' if isempty(lastEnState) */
  /* '<S366>:1:9' cmd=uint32(0); */
  LW_ctrl_241029_1_B.cmd = 0U;

  /*  默认空指令 */
  /* '<S366>:1:10' param1=single(0); */
  LW_ctrl_241029_1_B.param1 = 0.0F;

  /* '<S366>:1:11' param2=single(0); */
  LW_ctrl_241029_1_B.param2 = 0.0F;

  /* '<S366>:1:12' param3=single(0); */
  LW_ctrl_241029_1_B.param3 = 0.0F;

  /* '<S366>:1:13' isSendCmd=0; */
  LW_ctrl_241029_1_B.isSendCmd = 0.0;

  /*  不发送 */
  /* '<S366>:1:15' if isEn */
  if (rtb_RelationalOperator_om) {
    /*  使能的话，就要屏蔽输出 */
    /* '<S366>:1:16' blockMode=uint8(1); */
    rtb_blockMode = 1U;

    /*  如果置于1，则屏蔽输出 */
  } else {
    /* '<S366>:1:17' else */
    /* '<S366>:1:18' blockMode=uint8(0); */
    rtb_blockMode = 0U;

    /*  默认不屏蔽输出 */
  }

  /* '<S366>:1:21' if isEn~=lastEnState */
  if (rtb_RelationalOperator_om != LW_ctrl_241029_1_DW.lastEnState) {
    /*  不相等，就会触发本循环 */
    /* '<S366>:1:22' lastEnState=isEn; */
    LW_ctrl_241029_1_DW.lastEnState = rtb_RelationalOperator_om;

    /* '<S366>:1:24' if isEn && isAutoArm */
    /* '<S366>:1:31' if ~isEn && isAutoLoiter */
  }

  /* End of MATLAB Function: '<S362>/ArmTrig1' */

  /* MATLAB Function: '<S367>/ModeSwitch' incorporates:
   *  Constant: '<S362>/Constant5'
   */
  /* MATLAB Function 'RePX4Block/ModeSwitch': '<S368>:1' */
  /* '<S368>:1:3' isSend=0; */
  LW_ctrl_241029_1_B.isSend = 0.0;

  /* '<S368>:1:6' if isempty(lastState) */
  if (!LW_ctrl_241029_1_DW.lastState_not_empty) {
    /* '<S368>:1:7' lastState=uint8(0); */
    LW_ctrl_241029_1_DW.lastState = 0U;
    LW_ctrl_241029_1_DW.lastState_not_empty = true;

    /* '<S368>:1:8' if isEn */
    /* '<S368>:1:9' isSend=1; */
    LW_ctrl_241029_1_B.isSend = 1.0;
  }

  /* '<S368>:1:13' if isempty(lastEn) */
  /*  默认不屏蔽输出 */
  /* '<S368>:1:18' isSim=false; */
  LW_ctrl_241029_1_B.isSim = false;

  /* '<S368>:1:19' isTor=false; */
  LW_ctrl_241029_1_B.isTor = false;

  /* '<S368>:1:20' isIO=false; */
  LW_ctrl_241029_1_B.isIO = false;

  /* '<S368>:1:21' isRC=false; */
  LW_ctrl_241029_1_B.isRC = false;

  /* '<S368>:1:23' if dState~=lastState || isEn~=lastEn */
  if ((rtb_blockMode != LW_ctrl_241029_1_DW.lastState) ||
      (!LW_ctrl_241029_1_DW.lastEn)) {
    /*  两种情况都会触发消息发送 */
    /* '<S368>:1:24' lastState=dState; */
    LW_ctrl_241029_1_DW.lastState = rtb_blockMode;

    /* '<S368>:1:25' lastEn=isEn; */
    LW_ctrl_241029_1_DW.lastEn = true;

    /* '<S368>:1:26' if dState>2.5 */
    if (rtb_blockMode > 0.5) {
      /* '<S368>:1:36' elseif dState>0.5 */
      /*  屏蔽PX4的所有输出 */
      /* '<S368>:1:37' isSim=true; */
      LW_ctrl_241029_1_B.isSim = true;

      /* '<S368>:1:38' isTor=false; */
      LW_ctrl_241029_1_B.isTor = false;

      /* '<S368>:1:39' isIO=true; */
      LW_ctrl_241029_1_B.isIO = true;
    }

    /* '<S368>:1:42' if isEn */
    /* '<S368>:1:43' isSend=1; */
    LW_ctrl_241029_1_B.isSend = 1.0;
  }

  /* End of MATLAB Function: '<S367>/ModeSwitch' */

  /* S-Function (sfun_px4_uorb_write_dai): '<S362>/uORB Write Advanced_dai' */
  profileStart_LW_ctrl_241029_1(124U); /* original_line:10344 */{
    //struct actuator_outputs_s InputStruct;
    //memset( &InputStruct, 0, sizeof(InputStruct));
    int isSend= 1;

    /* assign input parameters to struct */
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[0] =
      LW_ctrl_241029_1_B.Switch[0];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[1] =
      LW_ctrl_241029_1_B.Switch[1];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[2] =
      LW_ctrl_241029_1_B.Switch[2];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[3] =
      LW_ctrl_241029_1_B.Switch[3];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[4] =
      LW_ctrl_241029_1_B.Switch[4];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[5] =
      LW_ctrl_241029_1_B.Switch[5];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[6] =
      LW_ctrl_241029_1_B.Switch[6];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[7] =
      LW_ctrl_241029_1_B.Switch[7];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[8] =
      LW_ctrl_241029_1_B.Switch[8];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[9] =
      LW_ctrl_241029_1_B.Switch[9];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[10] =
      LW_ctrl_241029_1_B.Switch[10];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[11] =
      LW_ctrl_241029_1_B.Switch[11];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[12] =
      LW_ctrl_241029_1_B.Switch[12];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[13] =
      LW_ctrl_241029_1_B.Switch[13];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[14] =
      LW_ctrl_241029_1_B.Switch[14];
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.output[15] =
      LW_ctrl_241029_1_B.Switch[15];
    isSend= LW_ctrl_241029_1_B.DataTypeConversion;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg.timestamp =
      hrt_absolute_time();
    if (isSend>0.5) {
      /* Publish data for subscribers */
      orb_publish(ORB_ID(actuator_outputs_rfly),
                  LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_adve,
                  &LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_msg);
    }
  }profileEnd_LW_ctrl_241029_1(124U); /* original_line:10391 */

  /* S-Function (sfun_px4_uorb_write_dai): '<S362>/uORB Write Advanced_dai2' */
  profileStart_LW_ctrl_241029_1(125U); /* original_line:10394 */{
    //struct vehicle_command_s InputStruct;
    //memset( &InputStruct, 0, sizeof(InputStruct));
    int isSend= 1;

    /* assign input parameters to struct */
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.param1 =
      LW_ctrl_241029_1_B.param1;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.param2 =
      LW_ctrl_241029_1_B.param2;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.param3 =
      LW_ctrl_241029_1_B.param3;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.command =
      LW_ctrl_241029_1_B.cmd;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.target_system =
      LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger.system_id;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.target_component =
      LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger.component_id;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.source_system =
      LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger.system_id;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.source_component =
      LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger.component_id;
    isSend= LW_ctrl_241029_1_B.isSendCmd;
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg.timestamp =
      hrt_absolute_time();
    if (isSend>0.5) {
      /* Publish data for subscribers */
      orb_publish(ORB_ID(vehicle_command),
                  LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_adv,
                  &LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_msg);
    }
  }profileEnd_LW_ctrl_241029_1(125U); /* original_line:10425 */

  /* DataTypeConversion: '<S362>/Data Type Conversion' */
  LW_ctrl_241029_1_B.DataTypeConversion = rtb_RelationalOperator_om;

  /* MATLAB Function: '<S361>/MATLAB Function1' */
  for (i = 0; i < 8; i++) {
    LW_ctrl_241029_1_B.u[i] = LW_ctrl_241029_1_B.pwm[i];
  }

  /* MATLAB Function 'Output/OutputSelect/HIL/MATLAB Function1': '<S364>:1' */
  /* '<S364>:1:3' t = u(4); */
  /* '<S364>:1:4' u(4) = u(2); */
  LW_ctrl_241029_1_B.u[3] = LW_ctrl_241029_1_B.pwm[1];

  /* '<S364>:1:5' u(2) = t; */
  LW_ctrl_241029_1_B.u[1] = LW_ctrl_241029_1_B.pwm[3];

  /* Switch: '<S362>/Switch' */
  /* '<S364>:1:6' y = u; */
  if (rtb_RelationalOperator_om) {
    /* Saturate: '<S362>/Saturation' incorporates:
     *  MATLAB Function: '<S361>/MATLAB Function1'
     */
    for (i = 0; i < 8; i++) {
      LW_ctrl_241029_1_B.d_tmp_m[i] = LW_ctrl_241029_1_B.u[i];
      LW_ctrl_241029_1_B.d_tmp_m[i + 8] =
        LW_ctrl_241029_1_ConstB.DataTypeConversion[i];
    }

    /* Switch: '<S362>/Switch' */
    for (i = 0; i < 16; i++) {
      /* Saturate: '<S362>/Saturation' */
      LW_ctrl_241029_1_B.Filter_o = LW_ctrl_241029_1_B.d_tmp_m[i];
      if (LW_ctrl_241029_1_B.Filter_o > 2000.0F) {
        LW_ctrl_241029_1_B.Switch[i] = 2000.0F;
      } else if (LW_ctrl_241029_1_B.Filter_o < 1000.0F) {
        LW_ctrl_241029_1_B.Switch[i] = 1000.0F;
      } else {
        LW_ctrl_241029_1_B.Switch[i] = LW_ctrl_241029_1_B.Filter_o;
      }
    }
  } else {
    /* Switch: '<S362>/Switch' */
    for (i = 0; i < 16; i++) {
      LW_ctrl_241029_1_B.Switch[i] = 1000.0F;
    }
  }

  /* End of Switch: '<S362>/Switch' */

  /* S-Function (sfun_px4_uorb_read_topic): '<S362>/uORB Read Function-Call Trigger' */
  profileStart_LW_ctrl_241029_1(126U); /* original_line:10477 */{
    //interval val: 4
    bool updated;
    orb_check(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_uOR.fd, &updated);
    if (updated) {
      /* obtained uorb data */
      /* copy sensors raw data into local buffer */
      orb_copy(ORB_ID(vehicle_status),
               LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_uOR.fd,
               &LW_ctrl_241029_1_B.uORBReadFunctionCallTrigger);
    }
  }profileEnd_LW_ctrl_241029_1(126U); /* original_line:10488 */

  /* MATLAB Function 'Output/OutputSelect/HIL/MATLAB Function2': '<S365>:1' */
  /* '<S365>:1:21' out = LW_SERVOR_REV; */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  LW_ctrl_241029_1_M->Timing.clockTick0++;
}

/* Model initialize function */
void LW_ctrl_241029_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)LW_ctrl_241029_1_M, 0,
                sizeof(RT_MODEL_LW_ctrl_241029_1_T));

  /* block I/O */
  (void) memset(((void *) &LW_ctrl_241029_1_B), 0,
                sizeof(B_LW_ctrl_241029_1_T));

  {
    LW_ctrl_241029_1_B.flight_mode = PILOT;
    LW_ctrl_241029_1_B.ctrl_mode = ARM;
    LW_ctrl_241029_1_B.arm = ARM;
  }

  /* states (dwork) */
  (void) memset((void *)&LW_ctrl_241029_1_DW, 0,
                sizeof(DW_LW_ctrl_241029_1_T));

  /* Start for S-Function (sfun_px4_uorb_write_dai): '<S367>/actuator_armed_rfly' */
  profileStart_LW_ctrl_241029_1(143U); /* original_line:10529 */{
    /* S-Function Block: <S367>/actuator_armed_rfly */
    /* Initializing topic: actuator_armed */
    struct actuator_armed_s initialize_topic;
    memset( &initialize_topic, 0, sizeof(initialize_topic));
    LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_advert = orb_advertise(ORB_ID
      (actuator_armed_rfly), &initialize_topic);
    if (LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_advert != 0) {
      PX4_INFO("Started advertising actuator_armed");
    }
  }profileEnd_LW_ctrl_241029_1(143U); /* original_line:10539 */

  /* Start for S-Function (sfun_px4_input_rc): '<S361>/input_rc'
   *
   * Block description for '<S361>/input_rc':
   *  RC Input Block
   *
   *  This block provides user input control to the model.
   *  It uses the input_rc uORB topic.
   *
   *  The user has the ability to choose which channels are available as outputs from this block and also some optional outputs. These include
   *  Channels 1 through 18
   *  double data type indicating the PWM value from the controller
   *  measured pulse widths for each of the supported channels
   *  Channel Count
   *  uint32 data type of the number of channels which are detector by the PX4
   *  RC Failsafe
   *  boolean data types indicating that the RC Tx is sending the FailSafe signal (if equipped and properly setup)
   *  explicit failsafe flag: true on TX failure or TX out of range , false otherwise.
   *  Only the true state is reliable, as there are some (PPM) receivers on the market going into failsafe without telling us explicitly.
   *  RC Input Source
   *  Enumeration data type indicating which source the RC input is from.
   *  Valid values are found in the ENUM file: RC_INPUT_SOURCE_ENUM.m
   *            Enumeration members for class 'RC_INPUT_SOURCE_ENUM':
   *            RCINPUT_SOURCE_UNKNOWN         (0)
   *            RCINPUT_SOURCE_PX4FMU_PPM      (1)
   *            RCINPUT_SOURCE_PX4IO_PPM       (2)
   *            RCINPUT_SOURCE_PX4IO_SPEKTRUM  (3)
   *            RCINPUT_SOURCE_PX4IO_SBUS      (4)
   *            RCINPUT_SOURCE_PX4IO_ST24      (5)
   *            RCINPUT_SOURCE_MAVLINK         (6)
   *            RCINPUT_SOURCE_QURT            (7)
   *            RCINPUT_SOURCE_PX4FMU_SPEKTRUM (8)
   *            RCINPUT_SOURCE_PX4FMU_SBUS     (9)
   *            RCINPUT_SOURCE_PX4FMU_ST24     (10)
   *            RCINPUT_SOURCE_PX4FMU_SUMD     (11)
   *            RCINPUT_SOURCE_PX4FMU_DSM      (12)
   *            RCINPUT_SOURCE_PX4IO_SUMD      (13)
   *
   *  RSSI - Receive signal strength index
   *  receive signal strength indicator (RSSI): < 0: Undefined, 0: no signal, 255: full reception
   *  RC Lost Connection
   *  boolean data type indicating RC receiver connection status
   *  True, if no frame has arrived in the expected time, false otherwise.
   *  True usally means that the receiver has been disconnected, but can also indicate a radio link loss on "stupid" systems.
   *  Will remain false, if a RX with failsafe option continues to transmit frames after a link loss.
   *
   *  Sample Model: px4demo_input_rc.slx
   */
  profileStart_LW_ctrl_241029_1(144U); /* original_line:10588 */{
    /* S-Function Block: <S361>/input_rc */
    /* subscribe to PWM RC input topic */
    int fd = orb_subscribe(ORB_ID(input_rc));
    LW_ctrl_241029_1_DW.input_rc_input_rc_fd.fd = fd;
    LW_ctrl_241029_1_DW.input_rc_input_rc_fd.events = POLLIN;
    orb_set_interval(fd, 1);
    PX4_INFO("* Subscribed to input_rc topic (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(144U); /* original_line:10596 */

  /* Start for S-Function (sfun_px4_uorb_write_dai): '<S362>/uORB Write Advanced_dai' */
  profileStart_LW_ctrl_241029_1(145U); /* original_line:10599 */{
    /* S-Function Block: <S362>/uORB Write Advanced_dai */
    /* Initializing topic: actuator_outputs */
    struct actuator_outputs_s initialize_topic;
    memset( &initialize_topic, 0, sizeof(initialize_topic));
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_adve = orb_advertise(ORB_ID
      (actuator_outputs_rfly), &initialize_topic);
    if (LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_adve != 0) {
      PX4_INFO("Started advertising actuator_outputs");
    }
  }profileEnd_LW_ctrl_241029_1(145U); /* original_line:10609 */

  /* Start for S-Function (sfun_px4_uorb_write_dai): '<S362>/uORB Write Advanced_dai2' */
  profileStart_LW_ctrl_241029_1(146U); /* original_line:10612 */{
    /* S-Function Block: <S362>/uORB Write Advanced_dai2 */
    /* Initializing topic: vehicle_command */
    struct vehicle_command_s initialize_topic;
    memset( &initialize_topic, 0, sizeof(initialize_topic));
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_adv = orb_advertise(ORB_ID
      (vehicle_command), &initialize_topic);
    if (LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_adv != 0) {
      PX4_INFO("Started advertising vehicle_command");
    }
  }profileEnd_LW_ctrl_241029_1(146U); /* original_line:10622 */

  /* Start for S-Function (sfun_px4_uorb_read_topic): '<S362>/uORB Read Function-Call Trigger' */
  profileStart_LW_ctrl_241029_1(147U); /* original_line:10625 */{
    /* S-Function Block: <S362>/uORB Read Function-Call Trigger */
    /* subscribe to vehicle_status topic */
    int fd = orb_subscribe(ORB_ID(vehicle_status));
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_uOR.fd = fd;
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_uOR.events = POLLIN;
    orb_set_interval(fd, 4);
    PX4_INFO("* Subscribed to topic: vehicle_status (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(147U); /* original_line:10633 */

  /* user code (Start function Trailer) */
  InitParamFunction("LW_ACCSP_FZ",&LW_ACCSP_FZ);/*  Assign LW_ACCSP_FZ */
  InitParamFunction("LW_ACCSP_TM",&LW_ACCSP_TM);/*  Assign LW_ACCSP_TM */
  InitParamFunction("LW_ACCX_FF",&LW_ACCX_FF);/*  Assign LW_ACCX_FF */
  InitParamFunction("LW_ACCY_FF",&LW_ACCY_FF);/*  Assign LW_ACCY_FF */
  InitParamFunction("LW_ACCZ_FF",&LW_ACCZ_FF);/*  Assign LW_ACCZ_FF */
  InitParamFunction("LW_ACRO_P_MAX",&LW_ACRO_P_MAX);/*  Assign LW_ACRO_P_MAX */
  InitParamFunction("LW_ACRO_R_MAX",&LW_ACRO_R_MAX);/*  Assign LW_ACRO_R_MAX */
  InitParamFunction("LW_ACRO_Y_MAX",&LW_ACRO_Y_MAX);/*  Assign LW_ACRO_Y_MAX */
  InitParamFunction("LW_AERO_C0",&LW_AERO_C0);/*  Assign LW_AERO_C0 */
  InitParamFunction("LW_AERO_C1",&LW_AERO_C1);/*  Assign LW_AERO_C1 */
  InitParamFunction("LW_AERO_COM",&LW_AERO_COM);/*  Assign LW_AERO_COM */
  InitParamFunction("LW_AERO_Y0",&LW_AERO_Y0);/*  Assign LW_AERO_Y0 */
  InitParamFunction("LW_ANGLE",&LW_ANGLE);/*  Assign LW_ANGLE */
  InitParamFunction("LW_COOR_TURN",&LW_COOR_TURN);/*  Assign LW_COOR_TURN */
  InitParamFunction("LW_DMZ0",&LW_DMZ0);/*  Assign LW_DMZ0 */
  InitParamFunction("LW_DMZ_MIN",&LW_DMZ_MIN);/*  Assign LW_DMZ_MIN */
  InitParamFunction("LW_DSER",&LW_DSER);/*  Assign LW_DSER */
  InitParamFunction("LW_DTHR",&LW_DTHR);/*  Assign LW_DTHR */
  InitParamFunction("LW_FEST_DT",&LW_FEST_DT);/*  Assign LW_FEST_DT */
  InitParamFunction("LW_FEST_EN",&LW_FEST_EN);/*  Assign LW_FEST_EN */
  InitParamFunction("LW_FEST_LAMXY",&LW_FEST_LAMXY);/*  Assign LW_FEST_LAMXY */
  InitParamFunction("LW_FEST_LAMZ",&LW_FEST_LAMZ);/*  Assign LW_FEST_LAMZ */
  InitParamFunction("LW_FEST_P",&LW_FEST_P);/*  Assign LW_FEST_P */
  InitParamFunction("LW_FEST_SIGXY",&LW_FEST_SIGXY);/*  Assign LW_FEST_SIGXY */
  InitParamFunction("LW_FEST_SIGZ",&LW_FEST_SIGZ);/*  Assign LW_FEST_SIGZ */
  InitParamFunction("LW_FEST_TDT",&LW_FEST_TDT);/*  Assign LW_FEST_TDT */
  InitParamFunction("LW_FEST_WNXY",&LW_FEST_WNXY);/*  Assign LW_FEST_WNXY */
  InitParamFunction("LW_FEST_WNZ",&LW_FEST_WNZ);/*  Assign LW_FEST_WNZ */
  InitParamFunction("LW_F_MAP",&LW_F_MAP);/*  Assign LW_F_MAP */
  InitParamFunction("LW_LAT_CIRCLE",&LW_LAT_CIRCLE);/*  Assign LW_LAT_CIRCLE */
  InitParamFunction("LW_LBCL_D",&LW_LBCL_D);/*  Assign LW_LBCL_D */
  InitParamFunction("LW_LBCM_D",&LW_LBCM_D);/*  Assign LW_LBCM_D */
  InitParamFunction("LW_LED",&LW_LED); /*  Assign LW_LED */
  InitParamFunction("LW_MAN_PITCH_DZ",&LW_MAN_PITCH_DZ);/*  Assign LW_MAN_PITCH_DZ */
  InitParamFunction("LW_MAN_PITCH_MAX",&LW_MAN_PITCH_MAX);/*  Assign LW_MAN_PITCH_MAX */
  InitParamFunction("LW_MAN_ROLL_DZ",&LW_MAN_ROLL_DZ);/*  Assign LW_MAN_ROLL_DZ */
  InitParamFunction("LW_MAN_ROLL_MAX",&LW_MAN_ROLL_MAX);/*  Assign LW_MAN_ROLL_MAX */
  InitParamFunction("LW_MAN_WX_DZ",&LW_MAN_WX_DZ);/*  Assign LW_MAN_WX_DZ */
  InitParamFunction("LW_MAN_WY_DZ",&LW_MAN_WY_DZ);/*  Assign LW_MAN_WY_DZ */
  InitParamFunction("LW_MAN_WZ_DZ",&LW_MAN_WZ_DZ);/*  Assign LW_MAN_WZ_DZ */
  InitParamFunction("LW_MASS",&LW_MASS);/*  Assign LW_MASS */
  InitParamFunction("LW_MIXER_GAM",&LW_MIXER_GAM);/*  Assign LW_MIXER_GAM */
  InitParamFunction("LW_OB_CIRCLE_R",&LW_OB_CIRCLE_R);/*  Assign LW_OB_CIRCLE_R */
  InitParamFunction("LW_OB_CIRCLE_V",&LW_OB_CIRCLE_V);/*  Assign LW_OB_CIRCLE_V */
  InitParamFunction("LW_OB_CIRCLE_W",&LW_OB_CIRCLE_W);/*  Assign LW_OB_CIRCLE_W */
  InitParamFunction("LW_OB_TYPE",&LW_OB_TYPE);/*  Assign LW_OB_TYPE */
  InitParamFunction("LW_PITCH_P",&LW_PITCH_P);/*  Assign LW_PITCH_P */
  InitParamFunction("LW_REX_YAW",&LW_REX_YAW);/*  Assign LW_REX_YAW */
  InitParamFunction("LW_ROLL_P",&LW_ROLL_P);/*  Assign LW_ROLL_P */
  InitParamFunction("LW_SERVOL_MAX",&LW_SERVOL_MAX);/*  Assign LW_SERVOL_MAX */
  InitParamFunction("LW_SERVOL_MIN",&LW_SERVOL_MIN);/*  Assign LW_SERVOL_MIN */
  InitParamFunction("LW_SERVOL_REV",&LW_SERVOL_REV);/*  Assign LW_SERVOL_REV */
  InitParamFunction("LW_SERVOR_CON",&LW_SERVOR_CON);/*  Assign LW_SERVOR_CON */
  InitParamFunction("LW_SERVOR_MAX",&LW_SERVOR_MAX);/*  Assign LW_SERVOR_MAX */
  InitParamFunction("LW_SERVOR_MIN",&LW_SERVOR_MIN);/*  Assign LW_SERVOR_MIN */
  InitParamFunction("LW_SERVOR_REV",&LW_SERVOR_REV);/*  Assign LW_SERVOR_REV */
  InitParamFunction("LW_SER_LP",&LW_SER_LP);/*  Assign LW_SER_LP */
  InitParamFunction("LW_TAUXYSP_FZ",&LW_TAUXYSP_FZ);/*  Assign LW_TAUXYSP_FZ */
  InitParamFunction("LW_TAUXYSP_TM",&LW_TAUXYSP_TM);/*  Assign LW_TAUXYSP_TM */
  InitParamFunction("LW_TAUZSP_FZ",&LW_TAUZSP_FZ);/*  Assign LW_TAUZSP_FZ */
  InitParamFunction("LW_TAUZSP_TM",&LW_TAUZSP_TM);/*  Assign LW_TAUZSP_TM */
  InitParamFunction("LW_TEST_DTXY",&LW_TEST_DTXY);/*  Assign LW_TEST_DTXY */
  InitParamFunction("LW_TEST_DTZ",&LW_TEST_DTZ);/*  Assign LW_TEST_DTZ */
  InitParamFunction("LW_TEST_EN",&LW_TEST_EN);/*  Assign LW_TEST_EN */
  InitParamFunction("LW_TEST_LAMXY",&LW_TEST_LAMXY);/*  Assign LW_TEST_LAMXY */
  InitParamFunction("LW_TEST_LAMZ",&LW_TEST_LAMZ);/*  Assign LW_TEST_LAMZ */
  InitParamFunction("LW_TEST_SIGXY",&LW_TEST_SIGXY);/*  Assign LW_TEST_SIGXY */
  InitParamFunction("LW_TEST_SIGZ",&LW_TEST_SIGZ);/*  Assign LW_TEST_SIGZ */
  InitParamFunction("LW_TEST_TDT",&LW_TEST_TDT);/*  Assign LW_TEST_TDT */
  InitParamFunction("LW_TEST_WBDT",&LW_TEST_WBDT);/*  Assign LW_TEST_WBDT */
  InitParamFunction("LW_TEST_WNXY",&LW_TEST_WNXY);/*  Assign LW_TEST_WNXY */
  InitParamFunction("LW_TEST_WNZ",&LW_TEST_WNZ);/*  Assign LW_TEST_WNZ */
  InitParamFunction("LW_THR_HOVER",&LW_THR_HOVER);/*  Assign LW_THR_HOVER */
  InitParamFunction("LW_THR_LOW",&LW_THR_LOW);/*  Assign LW_THR_LOW */
  InitParamFunction("LW_TILTMAX_AIR",&LW_TILTMAX_AIR);/*  Assign LW_TILTMAX_AIR */
  InitParamFunction("LW_USE_SER",&LW_USE_SER);/*  Assign LW_USE_SER */
  InitParamFunction("LW_VA_TMAX",&LW_VA_TMAX);/*  Assign LW_VA_TMAX */
  InitParamFunction("LW_VA_TMIN",&LW_VA_TMIN);/*  Assign LW_VA_TMIN */
  InitParamFunction("LW_VEL_DT",&LW_VEL_DT);/*  Assign LW_VEL_DT */
  InitParamFunction("LW_WX_D",&LW_WX_D);/*  Assign LW_WX_D */
  InitParamFunction("LW_WX_FF",&LW_WX_FF);/*  Assign LW_WX_FF */
  InitParamFunction("LW_WX_I",&LW_WX_I);/*  Assign LW_WX_I */
  InitParamFunction("LW_WX_MAX",&LW_WX_MAX);/*  Assign LW_WX_MAX */
  InitParamFunction("LW_WX_N",&LW_WX_N);/*  Assign LW_WX_N */
  InitParamFunction("LW_WX_P",&LW_WX_P);/*  Assign LW_WX_P */
  InitParamFunction("LW_WY_D",&LW_WY_D);/*  Assign LW_WY_D */
  InitParamFunction("LW_WY_DE_MAX",&LW_WY_DE_MAX);/*  Assign LW_WY_DE_MAX */
  InitParamFunction("LW_WY_FF",&LW_WY_FF);/*  Assign LW_WY_FF */
  InitParamFunction("LW_WY_I",&LW_WY_I);/*  Assign LW_WY_I */
  InitParamFunction("LW_WY_MAX",&LW_WY_MAX);/*  Assign LW_WY_MAX */
  InitParamFunction("LW_WY_N",&LW_WY_N);/*  Assign LW_WY_N */
  InitParamFunction("LW_WY_P",&LW_WY_P);/*  Assign LW_WY_P */
  InitParamFunction("LW_WZ_D",&LW_WZ_D);/*  Assign LW_WZ_D */
  InitParamFunction("LW_WZ_FF",&LW_WZ_FF);/*  Assign LW_WZ_FF */
  InitParamFunction("LW_WZ_I",&LW_WZ_I);/*  Assign LW_WZ_I */
  InitParamFunction("LW_WZ_MAX",&LW_WZ_MAX);/*  Assign LW_WZ_MAX */
  InitParamFunction("LW_WZ_N",&LW_WZ_N);/*  Assign LW_WZ_N */
  InitParamFunction("LW_WZ_P",&LW_WZ_P);/*  Assign LW_WZ_P */
  InitParamFunction("LW_W_FZ",&LW_W_FZ);/*  Assign LW_W_FZ */
  InitParamFunction("LW_W_SER",&LW_W_SER);/*  Assign LW_W_SER */
  InitParamFunction("LW_W_SERH",&LW_W_SERH);/*  Assign LW_W_SERH */
  InitParamFunction("LW_W_TAOX",&LW_W_TAOX);/*  Assign LW_W_TAOX */
  InitParamFunction("LW_W_TAOY",&LW_W_TAOY);/*  Assign LW_W_TAOY */
  InitParamFunction("LW_W_TAOZ",&LW_W_TAOZ);/*  Assign LW_W_TAOZ */
  InitParamFunction("LW_X_ACCEL_MAX",&LW_X_ACCEL_MAX);/*  Assign LW_X_ACCEL_MAX */
  InitParamFunction("LW_X_ACCEL_MIN",&LW_X_ACCEL_MIN);/*  Assign LW_X_ACCEL_MIN */
  InitParamFunction("LW_X_FF",&LW_X_FF);/*  Assign LW_X_FF */
  InitParamFunction("LW_X_JERK_MAX",&LW_X_JERK_MAX);/*  Assign LW_X_JERK_MAX */
  InitParamFunction("LW_X_P",&LW_X_P); /*  Assign LW_X_P */
  InitParamFunction("LW_X_VEL_D",&LW_X_VEL_D);/*  Assign LW_X_VEL_D */
  InitParamFunction("LW_X_VEL_DZ",&LW_X_VEL_DZ);/*  Assign LW_X_VEL_DZ */
  InitParamFunction("LW_X_VEL_I",&LW_X_VEL_I);/*  Assign LW_X_VEL_I */
  InitParamFunction("LW_X_VEL_MAX",&LW_X_VEL_MAX);/*  Assign LW_X_VEL_MAX */
  InitParamFunction("LW_X_VEL_N",&LW_X_VEL_N);/*  Assign LW_X_VEL_N */
  InitParamFunction("LW_X_VEL_P",&LW_X_VEL_P);/*  Assign LW_X_VEL_P */
  InitParamFunction("LW_YAW_KAD",&LW_YAW_KAD);/*  Assign LW_YAW_KAD */
  InitParamFunction("LW_YAW_KAP",&LW_YAW_KAP);/*  Assign LW_YAW_KAP */
  InitParamFunction("LW_YAW_P",&LW_YAW_P);/*  Assign LW_YAW_P */
  InitParamFunction("LW_Y_ACCEL_MAX",&LW_Y_ACCEL_MAX);/*  Assign LW_Y_ACCEL_MAX */
  InitParamFunction("LW_Y_ACCEL_MIN",&LW_Y_ACCEL_MIN);/*  Assign LW_Y_ACCEL_MIN */
  InitParamFunction("LW_Y_FF",&LW_Y_FF);/*  Assign LW_Y_FF */
  InitParamFunction("LW_Y_JERK_MAX",&LW_Y_JERK_MAX);/*  Assign LW_Y_JERK_MAX */
  InitParamFunction("LW_Y_P",&LW_Y_P); /*  Assign LW_Y_P */
  InitParamFunction("LW_Y_VEL_D",&LW_Y_VEL_D);/*  Assign LW_Y_VEL_D */
  InitParamFunction("LW_Y_VEL_DZ",&LW_Y_VEL_DZ);/*  Assign LW_Y_VEL_DZ */
  InitParamFunction("LW_Y_VEL_I",&LW_Y_VEL_I);/*  Assign LW_Y_VEL_I */
  InitParamFunction("LW_Y_VEL_MAX",&LW_Y_VEL_MAX);/*  Assign LW_Y_VEL_MAX */
  InitParamFunction("LW_Y_VEL_N",&LW_Y_VEL_N);/*  Assign LW_Y_VEL_N */
  InitParamFunction("LW_Y_VEL_P",&LW_Y_VEL_P);/*  Assign LW_Y_VEL_P */
  InitParamFunction("LW_Z_ACCEL_LOW",&LW_Z_ACCEL_LOW);/*  Assign LW_Z_ACCEL_LOW */
  InitParamFunction("LW_Z_ACCEL_UP",&LW_Z_ACCEL_UP);/*  Assign LW_Z_ACCEL_UP */
  InitParamFunction("LW_Z_FF",&LW_Z_FF);/*  Assign LW_Z_FF */
  InitParamFunction("LW_Z_JERK_MAX",&LW_Z_JERK_MAX);/*  Assign LW_Z_JERK_MAX */
  InitParamFunction("LW_Z_P",&LW_Z_P); /*  Assign LW_Z_P */
  InitParamFunction("LW_Z_VEL_D",&LW_Z_VEL_D);/*  Assign LW_Z_VEL_D */
  InitParamFunction("LW_Z_VEL_DZ",&LW_Z_VEL_DZ);/*  Assign LW_Z_VEL_DZ */
  InitParamFunction("LW_Z_VEL_I",&LW_Z_VEL_I);/*  Assign LW_Z_VEL_I */
  InitParamFunction("LW_Z_VEL_MAX_UP",&LW_Z_VEL_MAX_UP);/*  Assign LW_Z_VEL_MAX_UP */
  InitParamFunction("LW_Z_VEL_N",&LW_Z_VEL_N);/*  Assign LW_Z_VEL_N */
  InitParamFunction("LW_Z_VEL_P",&LW_Z_VEL_P);/*  Assign LW_Z_VEL_P */
  InitParamFunction("RC1_MAX",&RC1_MAX);/*  Assign RC1_MAX */
  InitParamFunction("RC1_MIN",&RC1_MIN);/*  Assign RC1_MIN */
  InitParamFunction("RC1_REV",&RC1_REV);/*  Assign RC1_REV */
  InitParamFunction("RC2_MAX",&RC2_MAX);/*  Assign RC2_MAX */
  InitParamFunction("RC2_MIN",&RC2_MIN);/*  Assign RC2_MIN */
  InitParamFunction("RC2_REV",&RC2_REV);/*  Assign RC2_REV */
  InitParamFunction("RC3_MAX",&RC3_MAX);/*  Assign RC3_MAX */
  InitParamFunction("RC3_MIN",&RC3_MIN);/*  Assign RC3_MIN */
  InitParamFunction("RC3_REV",&RC3_REV);/*  Assign RC3_REV */
  InitParamFunction("RC4_MAX",&RC4_MAX);/*  Assign RC4_MAX */
  InitParamFunction("RC4_MIN",&RC4_MIN);/*  Assign RC4_MIN */
  InitParamFunction("RC4_REV",&RC4_REV);/*  Assign RC4_REV */
  LW_ctrl_241029_1_DW.temporalCounter_i1 = 0U;
  LW_ctrl_241029_1_DW.temporalCounter_i2 = 0U;
  LW_ctrl_241029_1_DW.temporalCounter_i3 = 0U;
  LW_ctrl_241029_1_DW.temporalCounter_i4 = 0U;
  LW_ctrl_241029_1_DW.temporalCounter_i5 = 0U;
  LW_ctrl_241029_1_DW.temporalCounter_i6 = 0U;
  LW_ctrl_241029_1_DW.temporalCounter_i7 = 0U;
  LW_ctrl_241029_1_DW.is_active_c3_LW_ctrl_241029_1 = 0U;

  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/PID_Controller'
   */
  /* InitializeConditions for DiscreteIntegrator: '<S340>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_PrevResetState = 0;
  LW_ctrl_241029_1_DW.Integrator_PREV_U = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S335>/Filter' */
  LW_ctrl_241029_1_DW.Filter_PrevResetState = 0;
  LW_ctrl_241029_1_DW.Filter_PREV_U_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S232>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_PrevResetState_m = 0;
  LW_ctrl_241029_1_DW.Integrator_PREV_U_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S227>/Filter' */
  LW_ctrl_241029_1_DW.Filter_PrevResetState_f = 0;
  LW_ctrl_241029_1_DW.Filter_PREV_U_b = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S286>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_PrevResetState_f = 0;
  LW_ctrl_241029_1_DW.Integrator_PREV_U_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S281>/Filter' */
  LW_ctrl_241029_1_DW.Filter_PrevResetState_b = 0;
  LW_ctrl_241029_1_DW.Filter_PREV_U_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_PrevResetState_o = 0;
  LW_ctrl_241029_1_DW.Integrator_PREV_U_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Filter' */
  LW_ctrl_241029_1_DW.Filter_PrevResetState_m = 0;
  LW_ctrl_241029_1_DW.Filter_PREV_U = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_PrevResetState_mv = 0;
  LW_ctrl_241029_1_DW.Integrator_PREV_U_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S108>/Filter' */
  LW_ctrl_241029_1_DW.Filter_PrevResetState_p = 0;
  LW_ctrl_241029_1_DW.Filter_PREV_U_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_PrevResetState_fl = 0;
  LW_ctrl_241029_1_DW.Integrator_PREV_U_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Filter' */
  LW_ctrl_241029_1_DW.Filter_PrevResetState_i = 0;
  LW_ctrl_241029_1_DW.Filter_PREV_U_n = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S12>/position control' */
  LW_ctrl_241029_1_DW.timestamp_last_not_empty = false;
  LW_ctrl_241029_1_DW.pos_x1_not_empty = false;
  LW_ctrl_241029_1_DW.pos_y1_not_empty = false;
  LW_ctrl_241029_1_DW.pos_z1_not_empty = false;
  LW_ctrl_241029_1_DW.hold_xy_flag_not_empty = false;
  LW_ctrl_241029_1_DW.hold_z_flag_not_empty = false;
  LW_ctrl_241029_1_DW.yaw_d__not_empty = false;
  LW_ctrl_241029_1_DW.hold_xy_timestamp_not_empty = false;
  LW_ctrl_241029_1_DW.hold_z_timestamp_not_empty = false;
  LW_ctrl_241029_1_DW.hold_vxy_not_empty = false;
  LW_ctrl_241029_1_DW.hold_pxy_not_empty = false;
  LW_ctrl_241029_1_DW.hold_vz_not_empty = false;
  LW_ctrl_241029_1_DW.hold_pz_not_empty = false;
  LW_ctrl_241029_1_DW.xy_reset_counter__not_empty = false;
  LW_ctrl_241029_1_DW.z_reset_counter__not_empty = false;
  LW_ctrl_241029_1_DW.vxy_reset_counter__not_empty = false;
  LW_ctrl_241029_1_DW.vz_reset_counter__not_empty = false;
  LW_ctrl_241029_1_DW.heading_reset_counter__not_empt = false;
  LW_ctrl_241029_1_DW.yawerror_last_not_empty = false;
  LW_ctrl_241029_1_DW.yaw_ref_last_not_empty = false;
  LW_ctrl_241029_1_DW.v1_not_empty = false;
  LW_ctrl_241029_1_DW.v2_not_empty = false;

  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<Root>/navigator'
   */
  /* Start for S-Function (sfun_px4_uorb_write): '<S372>/uORB Write Advanced' */
  profileStart_LW_ctrl_241029_1(148U); /* original_line:10876 */{
    /* S-Function Block: <S372>/uORB Write Advanced */
    /* Initializing topic: costom_lw_navigator */
    struct costom_lw_navigator_s initialize_topic;
    memset( &initialize_topic, 0, sizeof(initialize_topic));
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_advert_p = orb_advertise(ORB_ID
      (costom_lw_navigator), &initialize_topic);
    if (LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_advert_p != 0) {
      PX4_INFO("Started advertising costom_lw_navigator");
    }
  }profileEnd_LW_ctrl_241029_1(148U); /* original_line:10886 */

  /* SystemInitialize for IfAction SubSystem: '<S4>/navigator_manual' */

  /* SystemInitialize for MATLAB Function: '<S370>/Lowpass' */
  profileStart_LW_ctrl_241029_1(149U); /* original_line:10891 */LW_ctrl_241029_1_Lowpass_Init(&LW_ctrl_241029_1_DW.sf_Lowpass);profileEnd_LW_ctrl_241029_1(149U); /* original_line:10891 */

  /* SystemInitialize for MATLAB Function: '<S370>/Lowpass1' */
  profileStart_LW_ctrl_241029_1(150U); /* original_line:10894 */LW_ctrl_241029_1_Lowpass_Init(&LW_ctrl_241029_1_DW.sf_Lowpass1);profileEnd_LW_ctrl_241029_1(150U); /* original_line:10894 */

  /* SystemInitialize for MATLAB Function: '<S370>/Lowpass2' */
  profileStart_LW_ctrl_241029_1(151U); /* original_line:10897 */LW_ctrl_241029_1_Lowpass_Init(&LW_ctrl_241029_1_DW.sf_Lowpass2);profileEnd_LW_ctrl_241029_1(151U); /* original_line:10897 */

  /* End of SystemInitialize for SubSystem: '<S4>/navigator_manual' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/navigator_offboard' */
  /* SystemInitialize for MATLAB Function: '<S403>/task' */
  LW_ctrl_241029_1_DW.time_start_not_empty = false;
  LW_ctrl_241029_1_DW.acc_last_not_empty = false;
  LW_ctrl_241029_1_DW.takeoff_yaw_not_empty = false;
  LW_ctrl_241029_1_DW.time_start_not_empty_b = false;
  LW_ctrl_241029_1_DW.acc_last_not_empty_b = false;
  LW_ctrl_241029_1_DW.takeoff_yaw_not_empty_e = false;

  /* 'task5:24' lineMode = int8(0); */
  LW_ctrl_241029_1_DW.lineMode = 0;

  /* 'task5:25' Acct = single(0); */
  LW_ctrl_241029_1_DW.Acct = 0.0F;

  /* 'task5:26' Unit = single(0); */
  LW_ctrl_241029_1_DW.Unit = 0.0F;

  /* 'task1:20' lineMode = int8(0); */
  LW_ctrl_241029_1_DW.lineMode_o = 0;

  /* 'task1:21' Acct = single(0); */
  LW_ctrl_241029_1_DW.Acct_l = 0.0F;

  /* 'task1:22' Unit = single(0); */
  LW_ctrl_241029_1_DW.Unit_e = 0.0F;
  LW_ctrl_241029_1_DW.pos_last[0] = 0.0F;
  LW_ctrl_241029_1_DW.pos_last_e[0] = 0.0F;
  LW_ctrl_241029_1_DW.pos_last[1] = 0.0F;
  LW_ctrl_241029_1_DW.pos_last_e[1] = 0.0F;
  LW_ctrl_241029_1_DW.pos_last[2] = 0.0F;
  LW_ctrl_241029_1_DW.pos_last_e[2] = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S403>/df,coor,wind' */
  LW_ctrl_241029_1_DW.xw__not_empty = false;

  /* '<S404>:1:94' wz_ = single(0); */
  LW_ctrl_241029_1_DW.wz_ = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S4>/navigator_offboard' */

  /* SystemInitialize for MATLAB Function: '<S372>/hrt_timestamp' */
  /* '<S404>:1:95' wx_ = single(0); */
  profileStart_LW_ctrl_241029_1(152U); /* original_line:10944 */LW_ctrl_2410_hrt_timestamp_Init(&LW_ctrl_241029_1_DW.sf_hrt_timestamp);profileEnd_LW_ctrl_241029_1(152U); /* original_line:10944 */

  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<Root>/state_machine'
   */
  /* Start for S-Function (sfun_px4_uorb_read_topic): '<S6>/uORB Read Function-Call Trigger' */
  profileStart_LW_ctrl_241029_1(153U); /* original_line:10950 */{
    /* S-Function Block: <S6>/uORB Read Function-Call Trigger */
    /* subscribe to actuator_armed topic */
    int fd = orb_subscribe(ORB_ID(actuator_armed));
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_d.fd = fd;
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_d.events = POLLIN;
    orb_set_interval(fd, 4);
    PX4_INFO("* Subscribed to topic: actuator_armed (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(153U); /* original_line:10958 */

  /* Start for S-Function (sfun_px4_uorb_write): '<S415>/uORB Write Advanced1' */
  profileStart_LW_ctrl_241029_1(154U); /* original_line:10961 */{
    /* S-Function Block: <S415>/uORB Write Advanced1 */
    /* Initializing topic: costom_lw_statemachine */
    struct costom_lw_statemachine_s initialize_topic;
    memset( &initialize_topic, 0, sizeof(initialize_topic));
    LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_advert = orb_advertise(ORB_ID
      (costom_lw_statemachine), &initialize_topic);
    if (LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_advert != 0) {
      PX4_INFO("Started advertising costom_lw_statemachine");
    }
  }profileEnd_LW_ctrl_241029_1(154U); /* original_line:10971 */

  /* SystemInitialize for MATLAB Function: '<S415>/hrt_timestamp' */
  profileStart_LW_ctrl_241029_1(155U); /* original_line:10974 */LW_ctrl_2410_hrt_timestamp_Init(&LW_ctrl_241029_1_DW.sf_hrt_timestamp_p);profileEnd_LW_ctrl_241029_1(155U); /* original_line:10974 */

  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<Root>/rc_receive'
   */
  /* Start for S-Function (sfun_px4_input_rc): '<S407>/input_rc'
   *
   * Block description for '<S407>/input_rc':
   *  RC Input Block
   *
   *  This block provides user input control to the model.
   *  It uses the input_rc uORB topic.
   *
   *  The user has the ability to choose which channels are available as outputs from this block and also some optional outputs. These include
   *  Channels 1 through 18
   *  double data type indicating the PWM value from the controller
   *  measured pulse widths for each of the supported channels
   *  Channel Count
   *  uint32 data type of the number of channels which are detector by the PX4
   *  RC Failsafe
   *  boolean data types indicating that the RC Tx is sending the FailSafe signal (if equipped and properly setup)
   *  explicit failsafe flag: true on TX failure or TX out of range , false otherwise.
   *  Only the true state is reliable, as there are some (PPM) receivers on the market going into failsafe without telling us explicitly.
   *  RC Input Source
   *  Enumeration data type indicating which source the RC input is from.
   *  Valid values are found in the ENUM file: RC_INPUT_SOURCE_ENUM.m
   *            Enumeration members for class 'RC_INPUT_SOURCE_ENUM':
   *            RCINPUT_SOURCE_UNKNOWN         (0)
   *            RCINPUT_SOURCE_PX4FMU_PPM      (1)
   *            RCINPUT_SOURCE_PX4IO_PPM       (2)
   *            RCINPUT_SOURCE_PX4IO_SPEKTRUM  (3)
   *            RCINPUT_SOURCE_PX4IO_SBUS      (4)
   *            RCINPUT_SOURCE_PX4IO_ST24      (5)
   *            RCINPUT_SOURCE_MAVLINK         (6)
   *            RCINPUT_SOURCE_QURT            (7)
   *            RCINPUT_SOURCE_PX4FMU_SPEKTRUM (8)
   *            RCINPUT_SOURCE_PX4FMU_SBUS     (9)
   *            RCINPUT_SOURCE_PX4FMU_ST24     (10)
   *            RCINPUT_SOURCE_PX4FMU_SUMD     (11)
   *            RCINPUT_SOURCE_PX4FMU_DSM      (12)
   *            RCINPUT_SOURCE_PX4IO_SUMD      (13)
   *
   *  RSSI - Receive signal strength index
   *  receive signal strength indicator (RSSI): < 0: Undefined, 0: no signal, 255: full reception
   *  RC Lost Connection
   *  boolean data type indicating RC receiver connection status
   *  True, if no frame has arrived in the expected time, false otherwise.
   *  True usally means that the receiver has been disconnected, but can also indicate a radio link loss on "stupid" systems.
   *  Will remain false, if a RX with failsafe option continues to transmit frames after a link loss.
   *
   *  Sample Model: px4demo_input_rc.slx
   */
  profileStart_LW_ctrl_241029_1(156U); /* original_line:11026 */{
    /* S-Function Block: <S407>/input_rc */
    /* subscribe to PWM RC input topic */
    int fd = orb_subscribe(ORB_ID(input_rc));
    LW_ctrl_241029_1_DW.input_rc_input_rc_fd_b.fd = fd;
    LW_ctrl_241029_1_DW.input_rc_input_rc_fd_b.events = POLLIN;
    orb_set_interval(fd, 1);
    PX4_INFO("* Subscribed to input_rc topic (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(156U); /* original_line:11034 */

  /* Start for S-Function (sfun_px4_uorb_write): '<S409>/uORB Write Advanced' */
  profileStart_LW_ctrl_241029_1(157U); /* original_line:11037 */{
    /* S-Function Block: <S409>/uORB Write Advanced */
    /* Initializing topic: costom_lw_manual_ctrl_in */
    struct costom_lw_manual_ctrl_in_s initialize_topic;
    memset( &initialize_topic, 0, sizeof(initialize_topic));
    LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_advert = orb_advertise(ORB_ID
      (costom_lw_manual_ctrl_in), &initialize_topic);
    if (LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_advert != 0) {
      PX4_INFO("Started advertising costom_lw_manual_ctrl_in");
    }
  }profileEnd_LW_ctrl_241029_1(157U); /* original_line:11047 */

  /* SystemInitialize for MATLAB Function: '<S407>/MATLAB Function' */
  /* '<S408>:1:6' rc_lost_count = single(0.0); */
  LW_ctrl_241029_1_DW.rc_lost_count = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S409>/hrt_timestamp' */
  profileStart_LW_ctrl_241029_1(158U); /* original_line:11054 */LW_ctrl_2410_hrt_timestamp_Init(&LW_ctrl_241029_1_DW.sf_hrt_timestamp_k);profileEnd_LW_ctrl_241029_1(158U); /* original_line:11054 */

  /* SystemInitialize for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<Root>/states_update'
   */
  /* Start for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger2' */
  profileStart_LW_ctrl_241029_1(159U); /* original_line:11060 */{
    /* S-Function Block: <S419>/uORB Read Function-Call Trigger2 */
    /* subscribe to vehicle_local_position topic */
    int fd = orb_subscribe(ORB_ID(vehicle_local_position));
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger2_uO.fd = fd;
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger2_uO.events = POLLIN;
    orb_set_interval(fd, 0);
    PX4_INFO("* Subscribed to topic: vehicle_local_position (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(159U); /* original_line:11068 */

  /* Start for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger' */
  profileStart_LW_ctrl_241029_1(160U); /* original_line:11071 */{
    /* S-Function Block: <S419>/uORB Read Function-Call Trigger */
    /* subscribe to vehicle_attitude topic */
    int fd = orb_subscribe(ORB_ID(vehicle_attitude));
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_a.fd = fd;
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_a.events = POLLIN;
    orb_set_interval(fd, 0);
    PX4_INFO("* Subscribed to topic: vehicle_attitude (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(160U); /* original_line:11079 */

  /* Start for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger1' */
  profileStart_LW_ctrl_241029_1(161U); /* original_line:11082 */{
    /* S-Function Block: <S419>/uORB Read Function-Call Trigger1 */
    /* subscribe to vehicle_angular_velocity topic */
    int fd = orb_subscribe(ORB_ID(vehicle_angular_velocity));
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger1_uO.fd = fd;
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger1_uO.events = POLLIN;
    orb_set_interval(fd, 0);
    PX4_INFO("* Subscribed to topic: vehicle_angular_velocity (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(161U); /* original_line:11090 */

  /* Start for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger7' */
  profileStart_LW_ctrl_241029_1(162U); /* original_line:11093 */{
    /* S-Function Block: <S419>/uORB Read Function-Call Trigger7 */
    /* subscribe to costom_lw_mixer topic */
    int fd = orb_subscribe(ORB_ID(costom_lw_mixer));
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger7_uO.fd = fd;
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger7_uO.events = POLLIN;
    orb_set_interval(fd, 0);
    PX4_INFO("* Subscribed to topic: costom_lw_mixer (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(162U); /* original_line:11101 */

  /* Start for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger6' */
  profileStart_LW_ctrl_241029_1(163U); /* original_line:11104 */{
    /* S-Function Block: <S419>/uORB Read Function-Call Trigger6 */
    /* subscribe to battery_status topic */
    int fd = orb_subscribe(ORB_ID(battery_status));
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger6_uO.fd = fd;
    LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger6_uO.events = POLLIN;
    orb_set_interval(fd, 0);
    PX4_INFO("* Subscribed to topic: battery_status (fd = %d)*\n", fd);
  }profileEnd_LW_ctrl_241029_1(163U); /* original_line:11112 */

  /* Start for S-Function (sfun_px4_update_mtd_params): '<S419>/ParamUpdate'
   *
   * Block description for '<S419>/ParamUpdate':
   *  ParamUpdate Block
   *
   *  Use this block at your top-level of your model to insert a "parameter update" function in the generated code.
   */
  profileStart_LW_ctrl_241029_1(164U); /* original_line:11121 */{
    /* S-Function Block: <S419>/ParamUpdate */
    /* subscribe to parameter_update topic */
    LW_ctrl_241029_1_DW.ParamUpdate_uORB_fd.fd = orb_subscribe(ORB_ID
      (parameter_update));
    PX4_INFO("* Subscribed to topic: parameter_update (fd = %d)*\n",
             LW_ctrl_241029_1_DW.ParamUpdate_uORB_fd.fd);
  }profileEnd_LW_ctrl_241029_1(164U); /* original_line:11128 */

  /* SystemInitialize for MATLAB Function: '<S419>/Lowpass1' */
  LW_ctrl_241029_1_DW.d_est_last_not_empty = false;

  /* SystemInitialize for MATLAB Function: '<S419>/DisturbanceEstimator' */
  LW_ctrl_241029_1_DW.tau_qk_not_empty = false;
  LW_ctrl_241029_1_DW.tau_omegak_not_empty = false;
  LW_ctrl_241029_1_DW.quat_reset_counter__not_empty = false;
  LW_ctrl_241029_1_DW.d_est_last_not_empty_h = false;

  /* '<S420>:1:64' tau_z3 = single([0;0;0]); */
  LW_ctrl_241029_1_DW.tau_z3[0] = 0.0F;
  LW_ctrl_241029_1_DW.tau_z3[1] = 0.0F;
  LW_ctrl_241029_1_DW.tau_z3[2] = 0.0F;

  /* SystemInitialize for MATLAB Function: '<S419>/Lowpass' */
  LW_ctrl_241029_1_DW.d_est_last_not_empty_j = false;

  /* SystemInitialize for MATLAB Function: '<S362>/ArmTrig1' */
  /* '<S366>:1:5' lastEnState=false; */
  LW_ctrl_241029_1_DW.lastEnState = false;

  /* SystemInitialize for MATLAB Function: '<S367>/ModeSwitch' */
  LW_ctrl_241029_1_DW.lastState_not_empty = false;

  /* '<S368>:1:14' lastEn=false; */
  LW_ctrl_241029_1_DW.lastEn = false;

  /* Enable for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<S1>/PID_Controller'
   */
  LW_ctrl_241029_1_DW.PID_Controller_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S340>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S335>/Filter' */
  LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S232>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_l = 1U;

  /* Enable for DiscreteIntegrator: '<S227>/Filter' */
  LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_k = 1U;

  /* Enable for DiscreteIntegrator: '<S286>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_d = 1U;

  /* Enable for DiscreteIntegrator: '<S281>/Filter' */
  LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_j = 1U;

  /* Enable for DiscreteIntegrator: '<S59>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_ls = 1U;

  /* Enable for DiscreteIntegrator: '<S54>/Filter' */
  LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_m = 1U;

  /* Enable for DiscreteIntegrator: '<S113>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_n = 1U;

  /* Enable for DiscreteIntegrator: '<S108>/Filter' */
  LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_n = 1U;

  /* Enable for DiscreteIntegrator: '<S167>/Integrator' */
  LW_ctrl_241029_1_DW.Integrator_SYSTEM_ENABLE_j = 1U;

  /* Enable for DiscreteIntegrator: '<S162>/Filter' */
  LW_ctrl_241029_1_DW.Filter_SYSTEM_ENABLE_b = 1U;
}

/* Model terminate function */
void LW_ctrl_241029_1_terminate(void)
{
  /* Terminate for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<Root>/navigator'
   */
  /* Terminate for S-Function (sfun_px4_uorb_write): '<S372>/uORB Write Advanced' */

  /* Close uORB service used in the S-Function Block: <S372>/uORB Write Advanced */
  profileStart_LW_ctrl_241029_1(127U); /* original_line:11208 */orb_unadvertise(LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_advert_p);profileEnd_LW_ctrl_241029_1(127U); /* original_line:11208 */

  /* Terminate for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<Root>/state_machine'
   */
  /* Terminate for S-Function (sfun_px4_uorb_read_topic): '<S6>/uORB Read Function-Call Trigger' */

  /* Close uORB service used in the S-Function Block: <S6>/uORB Read Function-Call Trigger */
  profileStart_LW_ctrl_241029_1(128U); /* original_line:11216 */close(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_d.fd);profileEnd_LW_ctrl_241029_1(128U); /* original_line:11216 */

  /* Terminate for S-Function (sfun_px4_uorb_write): '<S415>/uORB Write Advanced1' */

  /* Close uORB service used in the S-Function Block: <S415>/uORB Write Advanced1 */
  profileStart_LW_ctrl_241029_1(129U); /* original_line:11221 */orb_unadvertise(LW_ctrl_241029_1_DW.uORBWriteAdvanced1_uorb_advert);profileEnd_LW_ctrl_241029_1(129U); /* original_line:11221 */

  /* Terminate for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<Root>/rc_receive'
   */
  /* Terminate for S-Function (sfun_px4_input_rc): '<S407>/input_rc'
   *
   * Block description for '<S407>/input_rc':
   *  RC Input Block
   *
   *  This block provides user input control to the model.
   *  It uses the input_rc uORB topic.
   *
   *  The user has the ability to choose which channels are available as outputs from this block and also some optional outputs. These include
   *  Channels 1 through 18
   *  double data type indicating the PWM value from the controller
   *  measured pulse widths for each of the supported channels
   *  Channel Count
   *  uint32 data type of the number of channels which are detector by the PX4
   *  RC Failsafe
   *  boolean data types indicating that the RC Tx is sending the FailSafe signal (if equipped and properly setup)
   *  explicit failsafe flag: true on TX failure or TX out of range , false otherwise.
   *  Only the true state is reliable, as there are some (PPM) receivers on the market going into failsafe without telling us explicitly.
   *  RC Input Source
   *  Enumeration data type indicating which source the RC input is from.
   *  Valid values are found in the ENUM file: RC_INPUT_SOURCE_ENUM.m
   *            Enumeration members for class 'RC_INPUT_SOURCE_ENUM':
   *            RCINPUT_SOURCE_UNKNOWN         (0)
   *            RCINPUT_SOURCE_PX4FMU_PPM      (1)
   *            RCINPUT_SOURCE_PX4IO_PPM       (2)
   *            RCINPUT_SOURCE_PX4IO_SPEKTRUM  (3)
   *            RCINPUT_SOURCE_PX4IO_SBUS      (4)
   *            RCINPUT_SOURCE_PX4IO_ST24      (5)
   *            RCINPUT_SOURCE_MAVLINK         (6)
   *            RCINPUT_SOURCE_QURT            (7)
   *            RCINPUT_SOURCE_PX4FMU_SPEKTRUM (8)
   *            RCINPUT_SOURCE_PX4FMU_SBUS     (9)
   *            RCINPUT_SOURCE_PX4FMU_ST24     (10)
   *            RCINPUT_SOURCE_PX4FMU_SUMD     (11)
   *            RCINPUT_SOURCE_PX4FMU_DSM      (12)
   *            RCINPUT_SOURCE_PX4IO_SUMD      (13)
   *
   *  RSSI - Receive signal strength index
   *  receive signal strength indicator (RSSI): < 0: Undefined, 0: no signal, 255: full reception
   *  RC Lost Connection
   *  boolean data type indicating RC receiver connection status
   *  True, if no frame has arrived in the expected time, false otherwise.
   *  True usally means that the receiver has been disconnected, but can also indicate a radio link loss on "stupid" systems.
   *  Will remain false, if a RX with failsafe option continues to transmit frames after a link loss.
   *
   *  Sample Model: px4demo_input_rc.slx
   */

  /* Close uORB service used in the S-Function Block: <S407>/input_rc */
  profileStart_LW_ctrl_241029_1(130U); /* original_line:11275 */close(LW_ctrl_241029_1_DW.input_rc_input_rc_fd_b.fd);profileEnd_LW_ctrl_241029_1(130U); /* original_line:11275 */

  /* Terminate for S-Function (sfun_px4_uorb_write): '<S409>/uORB Write Advanced' */

  /* Close uORB service used in the S-Function Block: <S409>/uORB Write Advanced */
  profileStart_LW_ctrl_241029_1(131U); /* original_line:11280 */orb_unadvertise(LW_ctrl_241029_1_DW.uORBWriteAdvanced_uorb_advert);profileEnd_LW_ctrl_241029_1(131U); /* original_line:11280 */

  /* Terminate for Chart: '<Root>/Scheduler' incorporates:
   *  SubSystem: '<Root>/states_update'
   */
  /* Terminate for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger2' */

  /* Close uORB service used in the S-Function Block: <S419>/uORB Read Function-Call Trigger2 */
  profileStart_LW_ctrl_241029_1(132U); /* original_line:11288 */close(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger2_uO.fd);profileEnd_LW_ctrl_241029_1(132U); /* original_line:11288 */

  /* Terminate for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger' */

  /* Close uORB service used in the S-Function Block: <S419>/uORB Read Function-Call Trigger */
  profileStart_LW_ctrl_241029_1(133U); /* original_line:11293 */close(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_u_a.fd);profileEnd_LW_ctrl_241029_1(133U); /* original_line:11293 */

  /* Terminate for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger1' */

  /* Close uORB service used in the S-Function Block: <S419>/uORB Read Function-Call Trigger1 */
  profileStart_LW_ctrl_241029_1(134U); /* original_line:11298 */close(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger1_uO.fd);profileEnd_LW_ctrl_241029_1(134U); /* original_line:11298 */

  /* Terminate for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger7' */

  /* Close uORB service used in the S-Function Block: <S419>/uORB Read Function-Call Trigger7 */
  profileStart_LW_ctrl_241029_1(135U); /* original_line:11303 */close(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger7_uO.fd);profileEnd_LW_ctrl_241029_1(135U); /* original_line:11303 */

  /* Terminate for S-Function (sfun_px4_uorb_read_topic): '<S419>/uORB Read Function-Call Trigger6' */

  /* Close uORB service used in the S-Function Block: <S419>/uORB Read Function-Call Trigger6 */
  profileStart_LW_ctrl_241029_1(136U); /* original_line:11308 */close(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger6_uO.fd);profileEnd_LW_ctrl_241029_1(136U); /* original_line:11308 */

  /* Terminate for S-Function (sfun_px4_update_mtd_params): '<S419>/ParamUpdate'
   *
   * Block description for '<S419>/ParamUpdate':
   *  ParamUpdate Block
   *
   *  Use this block at your top-level of your model to insert a "parameter update" function in the generated code.
   */
  profileStart_LW_ctrl_241029_1(137U); /* original_line:11317 */{
    /* S-Function Block: <S419>/ParamUpdate */
    /* closing parameter_update topic */
    close(LW_ctrl_241029_1_DW.ParamUpdate_uORB_fd.fd);
  }profileEnd_LW_ctrl_241029_1(137U); /* original_line:11321 */

  /* Terminate for S-Function (sfun_px4_uorb_write_dai): '<S367>/actuator_armed_rfly' */

  /* Close uORB service used in the S-Function Block: <S367>/actuator_armed_rfly */
  profileStart_LW_ctrl_241029_1(138U); /* original_line:11326 */orb_unadvertise(LW_ctrl_241029_1_DW.actuator_armed_rfly_uorb_advert);profileEnd_LW_ctrl_241029_1(138U); /* original_line:11326 */

  /* Terminate for S-Function (sfun_px4_input_rc): '<S361>/input_rc'
   *
   * Block description for '<S361>/input_rc':
   *  RC Input Block
   *
   *  This block provides user input control to the model.
   *  It uses the input_rc uORB topic.
   *
   *  The user has the ability to choose which channels are available as outputs from this block and also some optional outputs. These include
   *  Channels 1 through 18
   *  double data type indicating the PWM value from the controller
   *  measured pulse widths for each of the supported channels
   *  Channel Count
   *  uint32 data type of the number of channels which are detector by the PX4
   *  RC Failsafe
   *  boolean data types indicating that the RC Tx is sending the FailSafe signal (if equipped and properly setup)
   *  explicit failsafe flag: true on TX failure or TX out of range , false otherwise.
   *  Only the true state is reliable, as there are some (PPM) receivers on the market going into failsafe without telling us explicitly.
   *  RC Input Source
   *  Enumeration data type indicating which source the RC input is from.
   *  Valid values are found in the ENUM file: RC_INPUT_SOURCE_ENUM.m
   *            Enumeration members for class 'RC_INPUT_SOURCE_ENUM':
   *            RCINPUT_SOURCE_UNKNOWN         (0)
   *            RCINPUT_SOURCE_PX4FMU_PPM      (1)
   *            RCINPUT_SOURCE_PX4IO_PPM       (2)
   *            RCINPUT_SOURCE_PX4IO_SPEKTRUM  (3)
   *            RCINPUT_SOURCE_PX4IO_SBUS      (4)
   *            RCINPUT_SOURCE_PX4IO_ST24      (5)
   *            RCINPUT_SOURCE_MAVLINK         (6)
   *            RCINPUT_SOURCE_QURT            (7)
   *            RCINPUT_SOURCE_PX4FMU_SPEKTRUM (8)
   *            RCINPUT_SOURCE_PX4FMU_SBUS     (9)
   *            RCINPUT_SOURCE_PX4FMU_ST24     (10)
   *            RCINPUT_SOURCE_PX4FMU_SUMD     (11)
   *            RCINPUT_SOURCE_PX4FMU_DSM      (12)
   *            RCINPUT_SOURCE_PX4IO_SUMD      (13)
   *
   *  RSSI - Receive signal strength index
   *  receive signal strength indicator (RSSI): < 0: Undefined, 0: no signal, 255: full reception
   *  RC Lost Connection
   *  boolean data type indicating RC receiver connection status
   *  True, if no frame has arrived in the expected time, false otherwise.
   *  True usally means that the receiver has been disconnected, but can also indicate a radio link loss on "stupid" systems.
   *  Will remain false, if a RX with failsafe option continues to transmit frames after a link loss.
   *
   *  Sample Model: px4demo_input_rc.slx
   */

  /* Close uORB service used in the S-Function Block: <S361>/input_rc */
  profileStart_LW_ctrl_241029_1(139U); /* original_line:11377 */close(LW_ctrl_241029_1_DW.input_rc_input_rc_fd.fd);profileEnd_LW_ctrl_241029_1(139U); /* original_line:11377 */

  /* Terminate for S-Function (sfun_px4_uorb_write_dai): '<S362>/uORB Write Advanced_dai' */

  /* Close uORB service used in the S-Function Block: <S362>/uORB Write Advanced_dai */
  profileStart_LW_ctrl_241029_1(140U); /* original_line:11382 */orb_unadvertise(LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai_uorb_adve);profileEnd_LW_ctrl_241029_1(140U); /* original_line:11382 */

  /* Terminate for S-Function (sfun_px4_uorb_write_dai): '<S362>/uORB Write Advanced_dai2' */

  /* Close uORB service used in the S-Function Block: <S362>/uORB Write Advanced_dai2 */
  profileStart_LW_ctrl_241029_1(141U); /* original_line:11387 */orb_unadvertise(LW_ctrl_241029_1_DW.uORBWriteAdvanced_dai2_uorb_adv);profileEnd_LW_ctrl_241029_1(141U); /* original_line:11387 */

  /* Terminate for S-Function (sfun_px4_uorb_read_topic): '<S362>/uORB Read Function-Call Trigger' */

  /* Close uORB service used in the S-Function Block: <S362>/uORB Read Function-Call Trigger */
  profileStart_LW_ctrl_241029_1(142U); /* original_line:11392 */close(LW_ctrl_241029_1_DW.uORBReadFunctionCallTrigger_uOR.fd);profileEnd_LW_ctrl_241029_1(142U); /* original_line:11392 */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
