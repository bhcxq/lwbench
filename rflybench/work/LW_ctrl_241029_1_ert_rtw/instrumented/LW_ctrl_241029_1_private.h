/*
 * File: LW_ctrl_241029_1_private.h
 *
 * Code generated for Simulink model 'LW_ctrl_241029_1'.
 *
 * Model version                  : 10.97
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Dec 23 22:14:43 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef LW_ctrl_241029_1_private_h_
#define LW_ctrl_241029_1_private_h_
#include "rtwtypes.h"
#include "LW_ctrl_241029_1.h"
#include "LW_ctrl_241029_1_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern void LW_ctrl_241029_1_Lowpass_Init(DW_Lowpass_LW_ctrl_241029_1_T *localDW);
extern void LW_ctrl_241029_1_Lowpass(B_Lowpass_LW_ctrl_241029_1_T *localB,
  DW_Lowpass_LW_ctrl_241029_1_T *localDW);
extern void LW_ctrl_241029_1_nan_inf0(real32_T rtu_u,
  B_nan_inf0_LW_ctrl_241029_1_T *localB);
extern void LW_ctrl_241_pitchrate_deadzone1(real32_T rtu_u,
  B_pitchrate_deadzone1_LW_ctrl_T *localB);
extern void LW_ctrl_2410_hrt_timestamp_Init(DW_hrt_timestamp_LW_ctrl_2410_T
  *localDW);
extern void LW_ctrl_241029_1_hrt_timestamp(B_hrt_timestamp_LW_ctrl_24102_T
  *localB, DW_hrt_timestamp_LW_ctrl_2410_T *localDW);
extern void LW_ctrl_241029_1_nan_inf(real32_T rtu_u, real32_T rtu_u_i, real32_T
  rtu_u_j, B_nan_inf_LW_ctrl_241029_1_T *localB);

#endif                                 /* LW_ctrl_241029_1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
