/*
 * File: LW_ctrl_241029_1_types.h
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

#ifndef LW_ctrl_241029_1_types_h_
#define LW_ctrl_241029_1_types_h_
#include "rtwtypes.h"
#include <uORB/topics/vehicle_status.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/vehicle_global_position.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/battery_status.h>
#include <uORB/topics/costom_lw_mixer.h>
#include <uORB/topics/sensor_combined.h>
#ifndef DEFINED_TYPEDEF_FOR_ControlMode_
#define DEFINED_TYPEDEF_FOR_ControlMode_

typedef enum {
  ARM = 0,                             /* Default value */
  DISARM,
  MANUAL,
  ACRO,
  STABILIZED,
  ALTITUDE,
  POSITION,
  RTL,
  LANDING,
  LOITER,
  MISSION
} ControlMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_offboard_bus_
#define DEFINED_TYPEDEF_FOR_offboard_bus_

typedef struct {
  real32_T pos[3];
  real32_T vel[3];
  real32_T acc[3];
  real32_T q[4];
  real32_T f_d;
  real32_T alpha;
  real32_T beta;
  real32_T rates[3];
  real32_T dotrates[3];
  int8_T OB_TASK;
} offboard_bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FlightMode_
#define DEFINED_TYPEDEF_FOR_FlightMode_

typedef enum {
  PILOT = 0,                           /* Default value */
  AUTO,
  OFFBOARD
} FlightMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_battery_status_bus_
#define DEFINED_TYPEDEF_FOR_battery_status_bus_

typedef struct {
  real32_T voltage_filtered_v;
  real32_T current_filtered_a;
  boolean_T connected;
} battery_status_bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_n8db7rBuopXQNVEyALzLlE_
#define DEFINED_TYPEDEF_FOR_struct_n8db7rBuopXQNVEyALzLlE_

typedef struct {
  ControlMode arm;
  real32_T pwm[8];
} struct_n8db7rBuopXQNVEyALzLlE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_djeyQTWEB67UJOmttv5sgG_
#define DEFINED_TYPEDEF_FOR_struct_djeyQTWEB67UJOmttv5sgG_

typedef struct {
  real32_T euler_ref[3];
  real32_T rates_ref[3];
  real32_T thrust;
  real32_T delta[3];
  real32_T vel_ref[3];
} struct_djeyQTWEB67UJOmttv5sgG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_vGK5WqaMUbAPLyXr23lkqC_
#define DEFINED_TYPEDEF_FOR_struct_vGK5WqaMUbAPLyXr23lkqC_

typedef struct {
  struct_djeyQTWEB67UJOmttv5sgG manual;
  offboard_bus offboard;
} struct_vGK5WqaMUbAPLyXr23lkqC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_90J8evq9mFBj2XWmamCV5B_
#define DEFINED_TYPEDEF_FOR_struct_90J8evq9mFBj2XWmamCV5B_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T r;
  real32_T AU5;
  real32_T AU6;
  real32_T AU7;
  real32_T AU8;
  real32_T RC_Lost;
} struct_90J8evq9mFBj2XWmamCV5B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_JnHo0Y3AJ82sYxZ3FhVDTD_
#define DEFINED_TYPEDEF_FOR_struct_JnHo0Y3AJ82sYxZ3FhVDTD_

typedef struct {
  FlightMode flight_mode;
  ControlMode ctrl_mode;
  ControlMode arm;
} struct_JnHo0Y3AJ82sYxZ3FhVDTD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_6m5jAWj8dasyo8DYIXsH_
#define DEFINED_TYPEDEF_FOR_struct_6m5jAWj8dasyo8DYIXsH_

typedef struct {
  real_T timestamp;
  real32_T vehicle_local_pos[3];
  real32_T vehicle_local_vel[3];
  real32_T delta_xy[2];
  uint8_T xy_reset_counter;
  real32_T delta_z;
  uint8_T z_reset_counter;
  real32_T delta_vxy[2];
  uint8_T vxy_reset_counter;
  real32_T delta_vz;
  uint8_T vz_reset_counter;
  real32_T heading;
  real32_T delta_heading;
  uint8_T heading_reset_counter;
  boolean_T heading_good_for_control;
} struct_6m5jAWj8dasyo8DYIXsH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4WDulvwJrZlpiQtmxc0pQC_
#define DEFINED_TYPEDEF_FOR_struct_4WDulvwJrZlpiQtmxc0pQC_

typedef struct {
  real32_T indicated_airspeed_m_s;
  real32_T true_airspeed_m_s;
  real32_T air_temperature_celsius;
  real32_T confidence;
  real32_T incid[2];
  real32_T v_wind[3];
} struct_4WDulvwJrZlpiQtmxc0pQC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SlLNwqwfxg1Dz8uCn0Xzp_
#define DEFINED_TYPEDEF_FOR_struct_SlLNwqwfxg1Dz8uCn0Xzp_

typedef struct {
  real32_T quat[4];
  real32_T omega[3];
  real_T timestamp;
  real32_T delta_q_reset[4];
  uint8_T quat_reset_counter;
  real32_T q_est[4];
  real32_T omega_est[3];
  real32_T dm_est[3];
} struct_SlLNwqwfxg1Dz8uCn0Xzp;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_mEIg3OMBptiV8K0odN0KFH_
#define DEFINED_TYPEDEF_FOR_struct_mEIg3OMBptiV8K0odN0KFH_

typedef struct {
  real_T lat;
  real_T lon;
  real32_T alt;
  real32_T delta_alt;
  real32_T vel_n_m_s;
  real32_T vel_e_m_s;
  real32_T vel_d_m_s;
  real32_T cog_rad;
} struct_mEIg3OMBptiV8K0odN0KFH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_hkCsNHTiCE8HoNZA2rGFPB_
#define DEFINED_TYPEDEF_FOR_struct_hkCsNHTiCE8HoNZA2rGFPB_

typedef struct {
  real_T timestamp;
  real32_T gyro_rad[3];
  real32_T accelerometer_m_s2[3];
} struct_hkCsNHTiCE8HoNZA2rGFPB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_itV4hYrx0nCCNFlK4RrFKG_
#define DEFINED_TYPEDEF_FOR_struct_itV4hYrx0nCCNFlK4RrFKG_

typedef struct {
  struct_6m5jAWj8dasyo8DYIXsH vehicle_local_position;
  struct_4WDulvwJrZlpiQtmxc0pQC airspeed;
  struct_SlLNwqwfxg1Dz8uCn0Xzp vehicle_attitude;
  struct_mEIg3OMBptiV8K0odN0KFH vehicle_global_position;
  battery_status_bus battery_status;
  real32_T T_limit[6];
  struct_hkCsNHTiCE8HoNZA2rGFPB sensor_imu;
  real32_T states_flag;
} struct_itV4hYrx0nCCNFlK4RrFKG;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_LW_ctrl_241029_1_T RT_MODEL_LW_ctrl_241029_1_T;

#endif                                 /* LW_ctrl_241029_1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
