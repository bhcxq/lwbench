/*
 * File: LW_ctrl_241029_1.h
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

#ifndef LW_ctrl_241029_1_h_
#define LW_ctrl_241029_1_h_
#ifndef LW_ctrl_241029_1_COMMON_INCLUDES_
#define LW_ctrl_241029_1_COMMON_INCLUDES_
#include <uORB/uORB.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <nuttx/config.h>
#include <nuttx/sched.h>
#include <systemlib/err.h>
#include <uORB/topics/costom_lw_navigator.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/costom_lw_statemachine.h>
#include <uORB/topics/input_rc.h>
#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/tasks.h>
#include <px4_platform_common/posix.h>
#include <uORB/topics/costom_lw_manual_ctrl_in.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/costom_lw_mixer.h>
#include <uORB/topics/battery_status.h>
#include <uORB/topics/parameter_update.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_command.h>
#include <uORB/topics/vehicle_status.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* LW_ctrl_241029_1_COMMON_INCLUDES_ */

#include "LW_ctrl_241029_1_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rtGetInf.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct costom_lw_navigator_s costom_lw_navigator_s_t;
typedef struct pollfd pollfd_t;
typedef struct actuator_armed_s actuator_armed_SL;
typedef struct costom_lw_statemachine_s costom_lw_statemachine_s_t;
typedef struct costom_lw_manual_ctrl_in_s costom_lw_manual_ctrl_in_s_t;
typedef struct pollfd pollfd_t;
typedef struct vehicle_local_position_s vehicle_local_position_SL;
typedef struct pollfd pollfd_t;
typedef struct vehicle_attitude_s vehicle_attitude_SL;
typedef struct pollfd pollfd_t;
typedef struct vehicle_angular_velocity_s vehicle_angular_velocity_SL;
typedef struct pollfd pollfd_t;
typedef struct costom_lw_mixer_s costom_lw_mixer_SL;
typedef struct pollfd pollfd_t;
typedef struct battery_status_s battery_status_SL;
typedef struct actuator_armed_s actuator_armed_s_t;
typedef struct actuator_outputs_s actuator_outputs_s_t;
typedef struct vehicle_command_s vehicle_command_s_t;
typedef struct pollfd pollfd_t;
typedef struct vehicle_status_s vehicle_status_SL;

/* Block signals for system '<S370>/Lowpass' */
typedef struct {
  real32_T data_in;                    /* '<S370>/Lowpass' */
} B_Lowpass_LW_ctrl_241029_1_T;

/* Block states (default storage) for system '<S370>/Lowpass' */
typedef struct {
  real32_T data_last;                  /* '<S370>/Lowpass' */
  boolean_T data_last_not_empty;       /* '<S370>/Lowpass' */
} DW_Lowpass_LW_ctrl_241029_1_T;

/* Block signals for system '<S370>/nan_inf0' */
typedef struct {
  real32_T y;                          /* '<S370>/nan_inf0' */
} B_nan_inf0_LW_ctrl_241029_1_T;

/* Block signals for system '<S370>/pitchrate_deadzone1' */
typedef struct {
  real32_T y;                          /* '<S370>/pitchrate_deadzone1' */
} B_pitchrate_deadzone1_LW_ctrl_T;

/* Block signals for system '<S372>/hrt_timestamp' */
typedef struct {
  real_T ts;                           /* '<S372>/hrt_timestamp' */
} B_hrt_timestamp_LW_ctrl_24102_T;

/* Block states (default storage) for system '<S372>/hrt_timestamp' */
typedef struct {
  real_T count;                        /* '<S372>/hrt_timestamp' */
} DW_hrt_timestamp_LW_ctrl_2410_T;

/* Block signals for system '<S419>/nan_inf' */
typedef struct {
  real32_T y[3];                       /* '<S419>/nan_inf' */
} B_nan_inf_LW_ctrl_241029_1_T;

/* Block signals (default storage) */
typedef struct {
  vehicle_local_position_SL uORBReadFunctionCallTrigger2;
                                 /* '<S419>/uORB Read Function-Call Trigger2' */
  battery_status_SL uORBReadFunctionCallTrigger6;
                                 /* '<S419>/uORB Read Function-Call Trigger6' */
  real_T d_tmp[16];
  vehicle_status_SL uORBReadFunctionCallTrigger;
                                  /* '<S362>/uORB Read Function-Call Trigger' */
  costom_lw_mixer_SL uORBReadFunctionCallTrigger7;
                                 /* '<S419>/uORB Read Function-Call Trigger7' */
  real32_T eta[18];
  real_T inv_uavJ[9];
  real_T dv[8];
  real32_T d_tmp_m[16];
  real_T d_i_data[7];
  vehicle_attitude_SL uORBReadFunctionCallTrigger_d;
                                  /* '<S419>/uORB Read Function-Call Trigger' */
  real32_T Rbe_psi[9];
  real32_T vd_lim_tmp[9];
  real32_T km_f[9];
  vehicle_angular_velocity_SL uORBReadFunctionCallTrigger1;
                                 /* '<S419>/uORB Read Function-Call Trigger1' */
  real32_T u[8];
  real32_T T[6];
  actuator_armed_SL uORBReadFunctionCallTrigger_c;
                                    /* '<S6>/uORB Read Function-Call Trigger' */
  real32_T qm[4];
  real32_T q_err[4];
  real32_T T_c[4];
  real32_T qk_[4];
  real32_T Xi_e[3];
  real32_T z3_[3];
  real32_T vel_ref_kk[3];
  real32_T vd_psi[3];
  real32_T y_c[3];
  real32_T TmpSignalConversionAtDotPro[3];
  real32_T d_est[3];
  real32_T vel_ref_c[3];
  real32_T fv[3];
  real32_T fv1[3];
  int32_T d_i_size[2];
  real_T DataTypeConversion;           /* '<S362>/Data Type Conversion' */
  real_T isSend;                       /* '<S367>/ModeSwitch' */
  real_T isSendCmd;                    /* '<S362>/ArmTrig1' */
  real_T DeadZone;                     /* '<S51>/DeadZone' */
  real_T FilterCoefficient;            /* '<S62>/Filter Coefficient' */
  real_T Saturation_d;                 /* '<S425>/Saturation' */
  real_T sigma_idx_3;
  real_T u0;
  real_T tmp;
  real_T px;
  real_T py;
  real_T ax;
  real_T ay;
  real_T jx;
  real_T jy;
  real_T jx_tmp;
  real32_T DataTypeConversion_h;       /* '<S410>/Data Type Conversion' */
  real32_T x;                          /* '<S407>/MATLAB Function' */
  real32_T y_b;                        /* '<S407>/MATLAB Function' */
  real32_T z;                          /* '<S407>/MATLAB Function' */
  real32_T r;                          /* '<S407>/MATLAB Function' */
  real32_T AU5;                        /* '<S407>/MATLAB Function' */
  real32_T AU6;                        /* '<S407>/MATLAB Function' */
  real32_T AU7;                        /* '<S407>/MATLAB Function' */
  real32_T AU8;                        /* '<S407>/MATLAB Function' */
  real32_T DataTypeConversion_p;       /* '<S416>/Data Type Conversion' */
  real32_T rates_ref[3];
  real32_T vel_ref[3];
  real32_T pos[3];
  real32_T vel[3];
  real32_T q[4];
  real32_T DataTypeConversion5_h;      /* '<S372>/Data Type Conversion5' */
  real32_T DataTypeConversion_g;       /* '<S373>/Data Type Conversion' */
  real32_T pos_ref_l[3];               /* '<S403>/df,coor,wind' */
  real32_T vel_ref_k[3];               /* '<S403>/df,coor,wind' */
  real32_T acc_ref_b[3];               /* '<S403>/df,coor,wind' */
  real32_T q_ref[4];                   /* '<S403>/df,coor,wind' */
  real32_T f_d_l;                      /* '<S403>/df,coor,wind' */
  real32_T alpha_d;                    /* '<S403>/df,coor,wind' */
  real32_T beta_a;                     /* '<S403>/df,coor,wind' */
  real32_T wb_ref[3];                  /* '<S403>/df,coor,wind' */
  real32_T dotwb_ref[3];               /* '<S403>/df,coor,wind' */
  real32_T thrust;                     /* '<S370>/Gain4' */
  real32_T yaw_ref_n;                  /* '<S370>/Constant' */
  real32_T roll_ref;                   /* '<S370>/deg2rad' */
  real32_T delta_r;                    /* '<S370>/deg2rad1' */
  real32_T pitch_ref;                  /* '<S370>/deg2rad2' */
  real32_T yawrate_ref;                /* '<S370>/deg2rad3' */
  real32_T rollrate_ref;               /* '<S370>/deg2rad4' */
  real32_T pitchRate_d;                /* '<S370>/deg2rad5' */
  real32_T delta_a;                    /* '<S370>/deg2rad6' */
  real32_T delta_e;                    /* '<S370>/deg2rad7' */
  real32_T max_vx;                     /* '<S370>/max_vx' */
  real32_T max_vy;                     /* '<S370>/max_vy' */
  real32_T max_vz;                     /* '<S370>/max_vz' */
  real32_T pwm[8];                     /* '<S9>/Saturation' */
  real32_T pos_ref_lq[3];              /* '<S12>/position control' */
  real32_T param1;                     /* '<S362>/ArmTrig1' */
  real32_T param2;                     /* '<S362>/ArmTrig1' */
  real32_T param3;                     /* '<S362>/ArmTrig1' */
  real32_T kappa;
  real32_T km_f_b;
  real32_T Va_;
  real32_T eta_p;
  real32_T theta;
  real32_T aSinInput;
  real32_T time_to_stop;
  real32_T delta_t;
  real32_T c_b;
  real32_T b_c;
  real32_T varargin_1_data;
  real32_T IntegralGain;               /* '<S337>/Integral Gain' */
  real32_T FilterCoefficient_jy;       /* '<S235>/Filter Coefficient' */
  real32_T DeadZone_e;                 /* '<S224>/DeadZone' */
  real32_T IntegralGain_gt;            /* '<S283>/Integral Gain' */
  real32_T FilterCoefficient_l;        /* '<S289>/Filter Coefficient' */
  real32_T DeadZone_el;                /* '<S278>/DeadZone' */
  real32_T FilterCoefficient_i;        /* '<S116>/Filter Coefficient' */
  real32_T DeadZone_p;                 /* '<S105>/DeadZone' */
  real32_T IntegralGain_n;             /* '<S164>/Integral Gain' */
  real32_T FilterCoefficient_k;        /* '<S170>/Filter Coefficient' */
  real32_T DeadZone_ph;                /* '<S159>/DeadZone' */
  real32_T T1;                         /* '<S11>/MATLAB Function' */
  real32_T T2;                         /* '<S11>/MATLAB Function' */
  real32_T T3;                         /* '<S11>/MATLAB Function' */
  real32_T T4;                         /* '<S11>/MATLAB Function' */
  real32_T Integrator_a;
  real32_T Filter_l;
  real32_T Filter_o;
  real32_T Integrator_f;
  uint32_T DataTypeConversion5;        /* '<S409>/Data Type Conversion5' */
  uint32_T DataTypeConversion6;        /* '<S409>/Data Type Conversion6' */
  uint32_T DataTypeConversion7;        /* '<S409>/Data Type Conversion7' */
  uint32_T DataTypeConversion9;        /* '<S409>/Data Type Conversion9' */
  uint32_T cmd;                        /* '<S362>/ArmTrig1' */
  real32_T Switch[16];                 /* '<S362>/Switch' */
  real32_T v_wind[3];                  /* '<S419>/Constant' */
  real32_T y[4];                       /* '<S419>/nan_inf_q' */
  real32_T y_e[3];                     /* '<S419>/nan_inf0' */
  real32_T d_est_j[3];                 /* '<S419>/Lowpass' */
  uint32_T PID_Controller_ELAPS_T;
  FlightMode flight_mode;              /* '<S6>/MATLAB Function4' */
  ControlMode ctrl_mode;               /* '<S6>/MATLAB Function4' */
  ControlMode arm;                     /* '<S6>/MATLAB Function3' */
  uint16_T input_rc;                   /* '<S361>/input_rc' */
  uint16_T input_rc_o1;                /* '<S407>/input_rc' */
  uint16_T input_rc_o2;                /* '<S407>/input_rc' */
  uint16_T input_rc_o3;                /* '<S407>/input_rc' */
  uint16_T input_rc_o4;                /* '<S407>/input_rc' */
  uint16_T input_rc_o5;                /* '<S407>/input_rc' */
  uint16_T input_rc_o6;                /* '<S407>/input_rc' */
  uint16_T input_rc_o7;                /* '<S407>/input_rc' */
  uint16_T input_rc_o8;                /* '<S407>/input_rc' */
  uint8_T DataTypeConversion1;         /* '<S415>/Data Type Conversion1' */
  uint8_T DataTypeConversion2;         /* '<S415>/Data Type Conversion2' */
  uint8_T DataTypeConversion3;         /* '<S415>/Data Type Conversion3' */
  boolean_T input_rc_o9;               /* '<S407>/input_rc' */
  boolean_T input_rc_o10;              /* '<S407>/input_rc' */
  boolean_T DataTypeConversion8;       /* '<S409>/Data Type Conversion8' */
  boolean_T isSim;                     /* '<S367>/ModeSwitch' */
  boolean_T isTor;                     /* '<S367>/ModeSwitch' */
  boolean_T isIO;                      /* '<S367>/ModeSwitch' */
  boolean_T isRC;                      /* '<S367>/ModeSwitch' */
  B_nan_inf_LW_ctrl_241029_1_T sf_nan_inf1_f;/* '<S419>/nan_inf1' */
  B_nan_inf_LW_ctrl_241029_1_T sf_nan_inf;/* '<S419>/nan_inf' */
  B_hrt_timestamp_LW_ctrl_24102_T sf_hrt_timestamp_k;/* '<S409>/hrt_timestamp' */
  B_hrt_timestamp_LW_ctrl_24102_T sf_hrt_timestamp_p;/* '<S415>/hrt_timestamp' */
  B_hrt_timestamp_LW_ctrl_24102_T sf_hrt_timestamp;/* '<S372>/hrt_timestamp' */
  B_pitchrate_deadzone1_LW_ctrl_T sf_yawrate_deadzone1;/* '<S370>/yawrate_deadzone1' */
  B_pitchrate_deadzone1_LW_ctrl_T sf_rollrate_deadzone1;/* '<S370>/rollrate_deadzone1' */
  B_pitchrate_deadzone1_LW_ctrl_T sf_pitchrate_deadzone1;/* '<S370>/pitchrate_deadzone1' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf9;/* '<S370>/nan_inf9' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf8;/* '<S370>/nan_inf8' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf7;/* '<S370>/nan_inf7' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf6;/* '<S370>/nan_inf6' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf5;/* '<S370>/nan_inf5' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf4;/* '<S370>/nan_inf4' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf3;/* '<S370>/nan_inf3' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf2;/* '<S370>/nan_inf2' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf11;/* '<S370>/nan_inf11' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf10;/* '<S370>/nan_inf10' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf1;/* '<S370>/nan_inf1' */
  B_nan_inf0_LW_ctrl_241029_1_T sf_nan_inf0;/* '<S370>/nan_inf0' */
  B_Lowpass_LW_ctrl_241029_1_T sf_Lowpass2;/* '<S370>/Lowpass2' */
  B_Lowpass_LW_ctrl_241029_1_T sf_Lowpass1;/* '<S370>/Lowpass1' */
  B_Lowpass_LW_ctrl_241029_1_T sf_Lowpass;/* '<S370>/Lowpass' */
} B_LW_ctrl_241029_1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  costom_lw_navigator_s_t uORBWriteAdvanced_uorb_msg;/* '<S372>/uORB Write Advanced' */
  actuator_outputs_s_t uORBWriteAdvanced_dai_uorb_msg;/* '<S362>/uORB Write Advanced_dai' */
  vehicle_command_s_t uORBWriteAdvanced_dai2_uorb_msg;/* '<S362>/uORB Write Advanced_dai2' */
  costom_lw_manual_ctrl_in_s_t uORBWriteAdvanced_uorb_msg_d;/* '<S409>/uORB Write Advanced' */
  actuator_armed_s_t actuator_armed_rfly_uorb_msg;/* '<S367>/actuator_armed_rfly' */
  costom_lw_statemachine_s_t uORBWriteAdvanced1_uorb_msg;/* '<S415>/uORB Write Advanced1' */
  pollfd_t input_rc_input_rc_fd;       /* '<S361>/input_rc' */
  pollfd_t uORBReadFunctionCallTrigger_uOR;
                                  /* '<S362>/uORB Read Function-Call Trigger' */
  pollfd_t uORBReadFunctionCallTrigger2_uO;
                                 /* '<S419>/uORB Read Function-Call Trigger2' */
  pollfd_t uORBReadFunctionCallTrigger_u_a;
                                  /* '<S419>/uORB Read Function-Call Trigger' */
  pollfd_t uORBReadFunctionCallTrigger1_uO;
                                 /* '<S419>/uORB Read Function-Call Trigger1' */
  pollfd_t uORBReadFunctionCallTrigger7_uO;
                                 /* '<S419>/uORB Read Function-Call Trigger7' */
  pollfd_t uORBReadFunctionCallTrigger6_uO;
                                 /* '<S419>/uORB Read Function-Call Trigger6' */
  pollfd_t ParamUpdate_uORB_fd;        /* '<S419>/ParamUpdate' */
  pollfd_t input_rc_input_rc_fd_b;     /* '<S407>/input_rc' */
  pollfd_t uORBReadFunctionCallTrigger_u_d;
                                    /* '<S6>/uORB Read Function-Call Trigger' */
  real_T Filter_DSTATE;                /* '<S54>/Filter' */
  real_T Memory_PreviousInput;         /* '<S425>/Memory' */
  real_T Memory_PreviousInput_f;       /* '<S410>/Memory' */
  real_T Memory_PreviousInput_fs;      /* '<S416>/Memory' */
  real_T Memory_PreviousInput_i;       /* '<S373>/Memory' */
  real_T Filter_PREV_U;                /* '<S54>/Filter' */
  real_T timestamp_last;               /* '<S12>/position control' */
  real_T hold_xy_timestamp;            /* '<S12>/position control' */
  real_T hold_z_timestamp;             /* '<S12>/position control' */
  real32_T Integrator_DSTATE;          /* '<S340>/Integrator' */
  real32_T Filter_DSTATE_f;            /* '<S335>/Filter' */
  real32_T Integrator_DSTATE_h;        /* '<S232>/Integrator' */
  real32_T Filter_DSTATE_e;            /* '<S227>/Filter' */
  real32_T Integrator_DSTATE_n;        /* '<S286>/Integrator' */
  real32_T Filter_DSTATE_p;            /* '<S281>/Filter' */
  real32_T Integrator_DSTATE_j;        /* '<S59>/Integrator' */
  real32_T Integrator_DSTATE_m;        /* '<S113>/Integrator' */
  real32_T Filter_DSTATE_fv;           /* '<S108>/Filter' */
  real32_T Integrator_DSTATE_a;        /* '<S167>/Integrator' */
  real32_T Filter_DSTATE_i;            /* '<S162>/Filter' */
  orb_advert_t actuator_armed_rfly_uorb_advert;/* '<S367>/actuator_armed_rfly' */
  orb_advert_t uORBWriteAdvanced_dai_uorb_adve;/* '<S362>/uORB Write Advanced_dai' */
  orb_advert_t uORBWriteAdvanced_dai2_uorb_adv;/* '<S362>/uORB Write Advanced_dai2' */
  orb_advert_t uORBWriteAdvanced_uorb_advert;/* '<S409>/uORB Write Advanced' */
  orb_advert_t uORBWriteAdvanced1_uorb_advert;/* '<S415>/uORB Write Advanced1' */
  orb_advert_t uORBWriteAdvanced_uorb_advert_p;/* '<S372>/uORB Write Advanced' */
  real32_T d_est_last[3];              /* '<S419>/Lowpass1' */
  real32_T d_est_last_f[3];            /* '<S419>/Lowpass' */
  real32_T tau_qk[4];                  /* '<S419>/DisturbanceEstimator' */
  real32_T tau_omegak[3];              /* '<S419>/DisturbanceEstimator' */
  real32_T tau_z3[3];                  /* '<S419>/DisturbanceEstimator' */
  real32_T d_est_last_p[6];            /* '<S419>/DisturbanceEstimator' */
  real32_T rc_lost_count;              /* '<S407>/MATLAB Function' */
  real32_T time_start;                 /* '<S403>/task' */
  real32_T pos_last[3];                /* '<S403>/task' */
  real32_T yaw_last;                   /* '<S403>/task' */
  real32_T pos_start[3];               /* '<S403>/task' */
  real32_T pos_deacc_start[3];         /* '<S403>/task' */
  real32_T pos_takeoff[3];             /* '<S403>/task' */
  real32_T Acct;                       /* '<S403>/task' */
  real32_T Unit;                       /* '<S403>/task' */
  real32_T time_start_a;               /* '<S403>/task' */
  real32_T pos_last_e[3];              /* '<S403>/task' */
  real32_T yaw_last_n;                 /* '<S403>/task' */
  real32_T pos_start_k[3];             /* '<S403>/task' */
  real32_T pos_deacc_start_j[3];       /* '<S403>/task' */
  real32_T Acct_l;                     /* '<S403>/task' */
  real32_T Unit_e;                     /* '<S403>/task' */
  real32_T xw_[3];                     /* '<S403>/df,coor,wind' */
  real32_T yb_[3];                     /* '<S403>/df,coor,wind' */
  real32_T wz_;                        /* '<S403>/df,coor,wind' */
  real32_T Integrator_PREV_U;          /* '<S340>/Integrator' */
  real32_T Filter_PREV_U_e;            /* '<S335>/Filter' */
  real32_T Integrator_PREV_U_f;        /* '<S232>/Integrator' */
  real32_T Filter_PREV_U_b;            /* '<S227>/Filter' */
  real32_T Integrator_PREV_U_l;        /* '<S286>/Integrator' */
  real32_T Filter_PREV_U_h;            /* '<S281>/Filter' */
  real32_T Integrator_PREV_U_m;        /* '<S59>/Integrator' */
  real32_T Integrator_PREV_U_a;        /* '<S113>/Integrator' */
  real32_T Filter_PREV_U_j;            /* '<S108>/Filter' */
  real32_T Integrator_PREV_U_d;        /* '<S167>/Integrator' */
  real32_T Filter_PREV_U_n;            /* '<S162>/Filter' */
  real32_T pos_x1;                     /* '<S12>/position control' */
  real32_T pos_y1;                     /* '<S12>/position control' */
  real32_T pos_z1;                     /* '<S12>/position control' */
  real32_T yaw_d_;                     /* '<S12>/position control' */
  real32_T hold_vxy[2];                /* '<S12>/position control' */
  real32_T hold_pxy[2];                /* '<S12>/position control' */
  real32_T hold_vz;                    /* '<S12>/position control' */
  real32_T hold_pz;                    /* '<S12>/position control' */
  real32_T yawerror_last;              /* '<S12>/position control' */
  real32_T yaw_ref_last;               /* '<S12>/position control' */
  real32_T v1[3];                      /* '<S12>/position control' */
  real32_T v2[3];                      /* '<S12>/position control' */
  uint32_T temporalCounter_i1;         /* '<Root>/Scheduler' */
  uint32_T temporalCounter_i2;         /* '<Root>/Scheduler' */
  uint32_T temporalCounter_i3;         /* '<Root>/Scheduler' */
  uint32_T temporalCounter_i4;         /* '<Root>/Scheduler' */
  uint32_T temporalCounter_i5;         /* '<Root>/Scheduler' */
  uint32_T temporalCounter_i6;         /* '<Root>/Scheduler' */
  uint32_T temporalCounter_i7;         /* '<Root>/Scheduler' */
  uint32_T PID_Controller_PREV_T;      /* '<S1>/PID_Controller' */
  int8_T lineMode;                     /* '<S403>/task' */
  int8_T lineMode_o;                   /* '<S403>/task' */
  int8_T Integrator_PrevResetState;    /* '<S340>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S335>/Filter' */
  int8_T Integrator_PrevResetState_m;  /* '<S232>/Integrator' */
  int8_T Filter_PrevResetState_f;      /* '<S227>/Filter' */
  int8_T Integrator_PrevResetState_f;  /* '<S286>/Integrator' */
  int8_T Filter_PrevResetState_b;      /* '<S281>/Filter' */
  int8_T Integrator_PrevResetState_o;  /* '<S59>/Integrator' */
  int8_T Filter_PrevResetState_m;      /* '<S54>/Filter' */
  int8_T Integrator_PrevResetState_mv; /* '<S113>/Integrator' */
  int8_T Filter_PrevResetState_p;      /* '<S108>/Filter' */
  int8_T Integrator_PrevResetState_fl; /* '<S167>/Integrator' */
  int8_T Filter_PrevResetState_i;      /* '<S162>/Filter' */
  uint8_T is_active_c3_LW_ctrl_241029_1;/* '<Root>/Scheduler' */
  uint8_T quat_reset_counter_;         /* '<S419>/DisturbanceEstimator' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S340>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE;        /* '<S335>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_l;  /* '<S232>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_k;      /* '<S227>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_d;  /* '<S286>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_j;      /* '<S281>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_ls; /* '<S59>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_m;      /* '<S54>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_n;  /* '<S113>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_n;      /* '<S108>/Filter' */
  uint8_T Integrator_SYSTEM_ENABLE_j;  /* '<S167>/Integrator' */
  uint8_T Filter_SYSTEM_ENABLE_b;      /* '<S162>/Filter' */
  uint8_T xy_reset_counter_;           /* '<S12>/position control' */
  uint8_T z_reset_counter_;            /* '<S12>/position control' */
  uint8_T vxy_reset_counter_;          /* '<S12>/position control' */
  uint8_T vz_reset_counter_;           /* '<S12>/position control' */
  uint8_T heading_reset_counter_;      /* '<S12>/position control' */
  uint8_T lastState;                   /* '<S367>/ModeSwitch' */
  boolean_T d_est_last_not_empty;      /* '<S419>/Lowpass1' */
  boolean_T d_est_last_not_empty_j;    /* '<S419>/Lowpass' */
  boolean_T tau_qk_not_empty;          /* '<S419>/DisturbanceEstimator' */
  boolean_T tau_omegak_not_empty;      /* '<S419>/DisturbanceEstimator' */
  boolean_T quat_reset_counter__not_empty;/* '<S419>/DisturbanceEstimator' */
  boolean_T d_est_last_not_empty_h;    /* '<S419>/DisturbanceEstimator' */
  boolean_T time_start_not_empty;      /* '<S403>/task' */
  boolean_T acc_last_not_empty;        /* '<S403>/task' */
  boolean_T takeoff_yaw_not_empty;     /* '<S403>/task' */
  boolean_T time_start_not_empty_b;    /* '<S403>/task' */
  boolean_T acc_last_not_empty_b;      /* '<S403>/task' */
  boolean_T takeoff_yaw_not_empty_e;   /* '<S403>/task' */
  boolean_T xw__not_empty;             /* '<S403>/df,coor,wind' */
  boolean_T PID_Controller_RESET_ELAPS_T;/* '<S1>/PID_Controller' */
  boolean_T timestamp_last_not_empty;  /* '<S12>/position control' */
  boolean_T pos_x1_not_empty;          /* '<S12>/position control' */
  boolean_T pos_y1_not_empty;          /* '<S12>/position control' */
  boolean_T pos_z1_not_empty;          /* '<S12>/position control' */
  boolean_T hold_xy_flag;              /* '<S12>/position control' */
  boolean_T hold_xy_flag_not_empty;    /* '<S12>/position control' */
  boolean_T hold_z_flag;               /* '<S12>/position control' */
  boolean_T hold_z_flag_not_empty;     /* '<S12>/position control' */
  boolean_T yaw_d__not_empty;          /* '<S12>/position control' */
  boolean_T hold_xy_timestamp_not_empty;/* '<S12>/position control' */
  boolean_T hold_z_timestamp_not_empty;/* '<S12>/position control' */
  boolean_T hold_vxy_not_empty;        /* '<S12>/position control' */
  boolean_T hold_pxy_not_empty;        /* '<S12>/position control' */
  boolean_T hold_vz_not_empty;         /* '<S12>/position control' */
  boolean_T hold_pz_not_empty;         /* '<S12>/position control' */
  boolean_T xy_reset_counter__not_empty;/* '<S12>/position control' */
  boolean_T z_reset_counter__not_empty;/* '<S12>/position control' */
  boolean_T vxy_reset_counter__not_empty;/* '<S12>/position control' */
  boolean_T vz_reset_counter__not_empty;/* '<S12>/position control' */
  boolean_T heading_reset_counter__not_empt;/* '<S12>/position control' */
  boolean_T yawerror_last_not_empty;   /* '<S12>/position control' */
  boolean_T yaw_ref_last_not_empty;    /* '<S12>/position control' */
  boolean_T v1_not_empty;              /* '<S12>/position control' */
  boolean_T v2_not_empty;              /* '<S12>/position control' */
  boolean_T lastState_not_empty;       /* '<S367>/ModeSwitch' */
  boolean_T lastEn;                    /* '<S367>/ModeSwitch' */
  boolean_T lastEnState;               /* '<S362>/ArmTrig1' */
  DW_hrt_timestamp_LW_ctrl_2410_T sf_hrt_timestamp_k;/* '<S409>/hrt_timestamp' */
  DW_hrt_timestamp_LW_ctrl_2410_T sf_hrt_timestamp_p;/* '<S415>/hrt_timestamp' */
  DW_hrt_timestamp_LW_ctrl_2410_T sf_hrt_timestamp;/* '<S372>/hrt_timestamp' */
  DW_Lowpass_LW_ctrl_241029_1_T sf_Lowpass2;/* '<S370>/Lowpass2' */
  DW_Lowpass_LW_ctrl_241029_1_T sf_Lowpass1;/* '<S370>/Lowpass1' */
  DW_Lowpass_LW_ctrl_241029_1_T sf_Lowpass;/* '<S370>/Lowpass' */
} DW_LW_ctrl_241029_1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T DataTypeConversion[8];/* '<S361>/Data Type Conversion' */
} ConstB_LW_ctrl_241029_1_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: ModelParam_uavJ)
   * Referenced by:
   *   '<S419>/DisturbanceEstimator'
   *   '<S11>/MATLAB Function'
   */
  real_T pooled1[9];
} ConstP_LW_ctrl_241029_1_T;

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct tag_RTM_LW_ctrl_241029_1_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_LW_ctrl_241029_1_T LW_ctrl_241029_1_B;

/* Block states (default storage) */
extern DW_LW_ctrl_241029_1_T LW_ctrl_241029_1_DW;
extern const ConstB_LW_ctrl_241029_1_T LW_ctrl_241029_1_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_LW_ctrl_241029_1_T LW_ctrl_241029_1_ConstP;

/* Model entry point functions */
extern void LW_ctrl_241029_1_initialize(void);
extern void LW_ctrl_241029_1_step(void);
extern void LW_ctrl_241029_1_terminate(void);

/* Exported data declaration */

/* Declaration of data with custom storage class MTD */
extern real32_T LW_ACCSP_FZ;      /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_ACCSP_TM;      /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_ACCX_FF;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_ACCY_FF;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_ACCZ_FF;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_ACRO_P_MAX;         /* Referenced by:
                                        * '<S370>/Gain7'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_ACRO_R_MAX;         /* Referenced by:
                                        * '<S370>/Gain6'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_ACRO_Y_MAX;         /* Referenced by:
                                        * '<S370>/Gain2'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_AERO_C0;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S403>/df,coor,wind'
                                        */
extern real32_T LW_AERO_C1;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S403>/df,coor,wind'
                                        */
extern real32_T LW_AERO_COM;      /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_AERO_Y0;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S403>/df,coor,wind'
                                        */
extern real32_T LW_ANGLE;              /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        * '<S419>/getIncid'
                                        * '<S403>/df,coor,wind'
                                        */
extern real32_T LW_COOR_TURN;     /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_DMZ0;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_DMZ_MIN;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_DSER;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_DTHR;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_DT;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_EN;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_LAMXY;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_LAMZ;     /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_P;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_SIGXY;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_SIGZ;     /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_TDT;      /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_WNXY;     /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_FEST_WNZ;      /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_F_MAP;         /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_LAT_CIRCLE;         /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_LBCL_D;             /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_LBCM_D;             /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_LED;                /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/LW_LED'
                                        */
extern real32_T LW_MAN_PITCH_DZ;       /* Referenced by:
                                        * '<S370>/pitch_deadzone'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_MAN_PITCH_MAX;      /* Referenced by:
                                        * '<S370>/man_pitch_max'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_MAN_ROLL_DZ;        /* Referenced by:
                                        * '<S370>/roll_deadzone'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_MAN_ROLL_MAX;       /* Referenced by:
                                        * '<S370>/man_roll_max'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_MAN_WX_DZ;          /* Referenced by:
                                        * '<S370>/rollrate_deadzone'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_MAN_WY_DZ;          /* Referenced by:
                                        * '<S370>/pitchrate_deadzone'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_MAN_WZ_DZ;          /* Referenced by:
                                        * '<S370>/yawrate_deadzone'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_MASS;               /* Referenced by:
                                        * '<S370>/Gain4'
                                        * '<S361>/MATLAB Function2'
                                        * '<S14>/Constant'
                                        * '<S403>/df,coor,wind'
                                        */
extern real32_T LW_MIXER_GAM;     /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_OB_CIRCLE_R;        /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S403>/task'
                                        */
extern real32_T LW_OB_CIRCLE_V;        /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S403>/task'
                                        */
extern real32_T LW_OB_CIRCLE_W;        /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S403>/task'
                                        */
extern real32_T LW_OB_TYPE;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S403>/task'
                                        */
extern real32_T LW_PITCH_P;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_REX_YAW;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_ROLL_P;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_SERVOL_MAX;         /* Referenced by:
                                        * '<S370>/Gain3'
                                        * '<S370>/Gain8'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_SERVOL_MIN;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_SERVOL_REV;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_SERVOR_CON;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_SERVOR_MAX;         /* Referenced by:
                                        * '<S370>/Gain3'
                                        * '<S370>/Gain8'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_SERVOR_MIN;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_SERVOR_REV;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_SER_LP;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_TAUXYSP_FZ;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_TAUXYSP_TM;    /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_TAUZSP_FZ;     /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_TAUZSP_TM;     /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_TEST_DTXY;          /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/Lowpass'
                                        */
extern real32_T LW_TEST_DTZ;           /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/Lowpass'
                                        */
extern real32_T LW_TEST_EN;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_TEST_LAMXY;         /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_TEST_LAMZ;          /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_TEST_SIGXY;         /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_TEST_SIGZ;          /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_TEST_TDT;           /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_TEST_WBDT;          /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/Lowpass1'
                                        */
extern real32_T LW_TEST_WNXY;          /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_TEST_WNZ;           /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_THR_HOVER;          /* Referenced by:
                                        * '<S370>/Constant2'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_THR_LOW;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_TILTMAX_AIR;   /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_USE_SER;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S419>/DisturbanceEstimator'
                                        */
extern real32_T LW_VA_TMAX;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_VA_TMIN;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_VEL_DT;             /* Referenced by:
                                        * '<S370>/Lowpass'
                                        * '<S370>/Lowpass1'
                                        * '<S370>/Lowpass2'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_WX_D;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WX_FF;         /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WX_I;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WX_MAX;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WX_N;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WX_P;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WY_D;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WY_DE_MAX;     /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WY_FF;         /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WY_I;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WY_MAX;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WY_N;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WY_P;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WZ_D;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WZ_FF;         /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WZ_I;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WZ_MAX;             /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_WZ_N;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_WZ_P;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_W_FZ;          /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_W_SER;         /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_W_SERH;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_W_TAOX;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_W_TAOY;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_W_TAOZ;        /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_X_ACCEL_MAX;        /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S239>/Saturation'
                                        * '<S224>/DeadZone'
                                        */
extern real32_T LW_X_ACCEL_MIN;        /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S239>/Saturation'
                                        * '<S224>/DeadZone'
                                        */
extern real32_T LW_X_FF;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_X_JERK_MAX;         /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_X_P;                /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_X_VEL_D;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_X_VEL_DZ;           /* Referenced by:
                                        * '<S370>/vx_deadzone'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_X_VEL_I;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_X_VEL_MAX;          /* Referenced by:
                                        * '<S370>/max_vx'
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_X_VEL_N;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_X_VEL_P;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_YAW_KAD;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_YAW_KAP;            /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_YAW_P;         /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_Y_ACCEL_MAX;        /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        * '<S293>/Saturation'
                                        * '<S278>/DeadZone'
                                        */
extern real32_T LW_Y_ACCEL_MIN;        /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S293>/Saturation'
                                        * '<S278>/DeadZone'
                                        */
extern real32_T LW_Y_FF;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_Y_JERK_MAX;         /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_Y_P;                /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_Y_VEL_D;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_Y_VEL_DZ;           /* Referenced by:
                                        * '<S370>/vy_deadzone'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_Y_VEL_I;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_Y_VEL_MAX;          /* Referenced by:
                                        * '<S370>/max_vy'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_Y_VEL_N;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_Y_VEL_P;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_Z_ACCEL_LOW;        /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S347>/Saturation'
                                        * '<S332>/DeadZone'
                                        */
extern real32_T LW_Z_ACCEL_UP;         /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S347>/Saturation'
                                        * '<S332>/DeadZone'
                                        */
extern real32_T LW_Z_FF;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_Z_JERK_MAX;         /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_Z_P;                /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_Z_VEL_D;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_Z_VEL_DZ;           /* Referenced by:
                                        * '<S370>/vz_deadzone'
                                        * '<S361>/MATLAB Function2'
                                        */
extern real32_T LW_Z_VEL_I;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_Z_VEL_MAX_UP;       /* Referenced by:
                                        * '<S370>/max_vz'
                                        * '<S361>/MATLAB Function2'
                                        * '<S12>/position control'
                                        */
extern real32_T LW_Z_VEL_N;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T LW_Z_VEL_P;       /* Referenced by: '<S361>/MATLAB Function2' */
extern real32_T RC1_MAX;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC1_MIN;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC1_REV;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC2_MAX;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC2_MIN;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC2_REV;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC3_MAX;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC3_MIN;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC3_REV;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC4_MAX;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC4_MIN;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */
extern real32_T RC4_REV;               /* Referenced by:
                                        * '<S361>/MATLAB Function2'
                                        * '<S407>/MATLAB Function'
                                        */

/* Real-time Model object */
extern RT_MODEL_LW_ctrl_241029_1_T *const LW_ctrl_241029_1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S419>/uORB Read Function-Call Trigger3' : Unused code path elimination
 * Block '<S419>/uORB Read Function-Call Trigger4' : Unused code path elimination
 * Block '<S419>/uORB Read Function-Call Trigger5' : Unused code path elimination
 * Block '<S419>/uORB Read Function-Call Trigger8' : Unused code path elimination
 * Block '<S14>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S361>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S372>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S372>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S372>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S370>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S370>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S370>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S409>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S409>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S409>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S409>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S409>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S415>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LW_ctrl_241029_1'
 * '<S1>'   : 'LW_ctrl_241029_1/Controller'
 * '<S2>'   : 'LW_ctrl_241029_1/Output'
 * '<S3>'   : 'LW_ctrl_241029_1/Scheduler'
 * '<S4>'   : 'LW_ctrl_241029_1/navigator'
 * '<S5>'   : 'LW_ctrl_241029_1/rc_receive'
 * '<S6>'   : 'LW_ctrl_241029_1/state_machine'
 * '<S7>'   : 'LW_ctrl_241029_1/states_update'
 * '<S8>'   : 'LW_ctrl_241029_1/Controller/PID_Controller'
 * '<S9>'   : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller'
 * '<S10>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/Compare To Constant'
 * '<S11>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control'
 * '<S12>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/local_pos_ref_selector'
 * '<S13>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/nan_inf_mode'
 * '<S14>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control'
 * '<S15>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/select parameter'
 * '<S16>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/toPWM'
 * '<S17>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/MATLAB Function'
 * '<S18>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/MATLAB Function1'
 * '<S19>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/attrates_ref_selector'
 * '<S20>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control'
 * '<S21>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control'
 * '<S22>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control'
 * '<S23>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Anti-windup'
 * '<S24>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/D Gain'
 * '<S25>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/External Derivative'
 * '<S26>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Filter'
 * '<S27>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Filter ICs'
 * '<S28>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/I Gain'
 * '<S29>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Ideal P Gain'
 * '<S30>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Ideal P Gain Fdbk'
 * '<S31>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Integrator'
 * '<S32>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Integrator ICs'
 * '<S33>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/N Copy'
 * '<S34>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/N Gain'
 * '<S35>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/P Copy'
 * '<S36>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Parallel P Gain'
 * '<S37>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Reset Signal'
 * '<S38>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Saturation'
 * '<S39>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Saturation Fdbk'
 * '<S40>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Sum'
 * '<S41>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Sum Fdbk'
 * '<S42>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Tracking Mode'
 * '<S43>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Tracking Mode Sum'
 * '<S44>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Tsamp - Integral'
 * '<S45>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Tsamp - Ngain'
 * '<S46>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/postSat Signal'
 * '<S47>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/preInt Signal'
 * '<S48>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/preSat Signal'
 * '<S49>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Anti-windup/Disc. Clamping Parallel'
 * '<S50>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S51>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S52>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/D Gain/Internal Parameters'
 * '<S53>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/External Derivative/Error'
 * '<S54>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Filter/Disc. Forward Euler Filter'
 * '<S55>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Filter ICs/Internal IC - Filter'
 * '<S56>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/I Gain/Internal Parameters'
 * '<S57>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Ideal P Gain/Passthrough'
 * '<S58>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Ideal P Gain Fdbk/Disabled'
 * '<S59>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Integrator/Discrete'
 * '<S60>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Integrator ICs/Internal IC'
 * '<S61>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/N Copy/Disabled'
 * '<S62>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/N Gain/Internal Parameters'
 * '<S63>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/P Copy/Disabled'
 * '<S64>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Parallel P Gain/Internal Parameters'
 * '<S65>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Reset Signal/External Reset'
 * '<S66>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Saturation/Enabled'
 * '<S67>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Saturation Fdbk/Disabled'
 * '<S68>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Sum/Sum_PID'
 * '<S69>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Sum Fdbk/Disabled'
 * '<S70>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Tracking Mode/Disabled'
 * '<S71>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Tracking Mode Sum/Passthrough'
 * '<S72>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Tsamp - Integral/TsSignalSpecification'
 * '<S73>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/Tsamp - Ngain/Passthrough'
 * '<S74>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/postSat Signal/Forward_Path'
 * '<S75>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/preInt Signal/Internal PreInt'
 * '<S76>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wx_control/preSat Signal/Forward_Path'
 * '<S77>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Anti-windup'
 * '<S78>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/D Gain'
 * '<S79>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/External Derivative'
 * '<S80>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Filter'
 * '<S81>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Filter ICs'
 * '<S82>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/I Gain'
 * '<S83>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Ideal P Gain'
 * '<S84>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Ideal P Gain Fdbk'
 * '<S85>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Integrator'
 * '<S86>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Integrator ICs'
 * '<S87>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/N Copy'
 * '<S88>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/N Gain'
 * '<S89>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/P Copy'
 * '<S90>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Parallel P Gain'
 * '<S91>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Reset Signal'
 * '<S92>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Saturation'
 * '<S93>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Saturation Fdbk'
 * '<S94>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Sum'
 * '<S95>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Sum Fdbk'
 * '<S96>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Tracking Mode'
 * '<S97>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Tracking Mode Sum'
 * '<S98>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Tsamp - Integral'
 * '<S99>'  : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Tsamp - Ngain'
 * '<S100>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/postSat Signal'
 * '<S101>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/preInt Signal'
 * '<S102>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/preSat Signal'
 * '<S103>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Anti-windup/Disc. Clamping Parallel'
 * '<S104>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S105>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S106>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/D Gain/Internal Parameters'
 * '<S107>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/External Derivative/Error'
 * '<S108>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Filter/Disc. Forward Euler Filter'
 * '<S109>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Filter ICs/Internal IC - Filter'
 * '<S110>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/I Gain/Internal Parameters'
 * '<S111>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Ideal P Gain/Passthrough'
 * '<S112>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Ideal P Gain Fdbk/Disabled'
 * '<S113>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Integrator/Discrete'
 * '<S114>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Integrator ICs/Internal IC'
 * '<S115>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/N Copy/Disabled'
 * '<S116>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/N Gain/Internal Parameters'
 * '<S117>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/P Copy/Disabled'
 * '<S118>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Parallel P Gain/Internal Parameters'
 * '<S119>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Reset Signal/External Reset'
 * '<S120>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Saturation/Enabled'
 * '<S121>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Saturation Fdbk/Disabled'
 * '<S122>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Sum/Sum_PID'
 * '<S123>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Sum Fdbk/Disabled'
 * '<S124>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Tracking Mode/Disabled'
 * '<S125>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Tracking Mode Sum/Passthrough'
 * '<S126>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Tsamp - Integral/TsSignalSpecification'
 * '<S127>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/Tsamp - Ngain/Passthrough'
 * '<S128>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/postSat Signal/Forward_Path'
 * '<S129>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/preInt Signal/Internal PreInt'
 * '<S130>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wy_control/preSat Signal/Forward_Path'
 * '<S131>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Anti-windup'
 * '<S132>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/D Gain'
 * '<S133>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/External Derivative'
 * '<S134>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Filter'
 * '<S135>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Filter ICs'
 * '<S136>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/I Gain'
 * '<S137>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Ideal P Gain'
 * '<S138>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Ideal P Gain Fdbk'
 * '<S139>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Integrator'
 * '<S140>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Integrator ICs'
 * '<S141>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/N Copy'
 * '<S142>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/N Gain'
 * '<S143>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/P Copy'
 * '<S144>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Parallel P Gain'
 * '<S145>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Reset Signal'
 * '<S146>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Saturation'
 * '<S147>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Saturation Fdbk'
 * '<S148>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Sum'
 * '<S149>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Sum Fdbk'
 * '<S150>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Tracking Mode'
 * '<S151>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Tracking Mode Sum'
 * '<S152>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Tsamp - Integral'
 * '<S153>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Tsamp - Ngain'
 * '<S154>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/postSat Signal'
 * '<S155>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/preInt Signal'
 * '<S156>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/preSat Signal'
 * '<S157>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Anti-windup/Disc. Clamping Parallel'
 * '<S158>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S159>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S160>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/D Gain/Internal Parameters'
 * '<S161>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/External Derivative/Error'
 * '<S162>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Filter/Disc. Forward Euler Filter'
 * '<S163>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Filter ICs/Internal IC - Filter'
 * '<S164>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/I Gain/Internal Parameters'
 * '<S165>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Ideal P Gain/Passthrough'
 * '<S166>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Ideal P Gain Fdbk/Disabled'
 * '<S167>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Integrator/Discrete'
 * '<S168>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Integrator ICs/Internal IC'
 * '<S169>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/N Copy/Disabled'
 * '<S170>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/N Gain/Internal Parameters'
 * '<S171>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/P Copy/Disabled'
 * '<S172>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Parallel P Gain/Internal Parameters'
 * '<S173>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Reset Signal/External Reset'
 * '<S174>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Saturation/Enabled'
 * '<S175>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Saturation Fdbk/Disabled'
 * '<S176>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Sum/Sum_PID'
 * '<S177>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Sum Fdbk/Disabled'
 * '<S178>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Tracking Mode/Disabled'
 * '<S179>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Tracking Mode Sum/Passthrough'
 * '<S180>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Tsamp - Integral/TsSignalSpecification'
 * '<S181>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/Tsamp - Ngain/Passthrough'
 * '<S182>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/postSat Signal/Forward_Path'
 * '<S183>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/preInt Signal/Internal PreInt'
 * '<S184>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/altitude control/wz_control/preSat Signal/Forward_Path'
 * '<S185>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/local_pos_ref_selector/nan_inf_mode'
 * '<S186>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/local_pos_ref_selector/nan_inf_mode1'
 * '<S187>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/local_pos_ref_selector/position control'
 * '<S188>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/nan_inf_mode'
 * '<S189>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/pos_ctrl_integral_reset'
 * '<S190>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/pos_ctrl_integral_reset1'
 * '<S191>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/pos_ctrl_integral_reset2'
 * '<S192>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/pos_ctrl_integral_reset3'
 * '<S193>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control'
 * '<S194>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control'
 * '<S195>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control'
 * '<S196>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Anti-windup'
 * '<S197>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/D Gain'
 * '<S198>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/External Derivative'
 * '<S199>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Filter'
 * '<S200>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Filter ICs'
 * '<S201>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/I Gain'
 * '<S202>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Ideal P Gain'
 * '<S203>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Ideal P Gain Fdbk'
 * '<S204>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Integrator'
 * '<S205>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Integrator ICs'
 * '<S206>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/N Copy'
 * '<S207>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/N Gain'
 * '<S208>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/P Copy'
 * '<S209>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Parallel P Gain'
 * '<S210>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Reset Signal'
 * '<S211>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Saturation'
 * '<S212>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Saturation Fdbk'
 * '<S213>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Sum'
 * '<S214>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Sum Fdbk'
 * '<S215>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Tracking Mode'
 * '<S216>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Tracking Mode Sum'
 * '<S217>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Tsamp - Integral'
 * '<S218>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Tsamp - Ngain'
 * '<S219>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/postSat Signal'
 * '<S220>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/preInt Signal'
 * '<S221>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/preSat Signal'
 * '<S222>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Anti-windup/Disc. Clamping Parallel'
 * '<S223>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S224>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S225>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/D Gain/Internal Parameters'
 * '<S226>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/External Derivative/Error'
 * '<S227>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Filter/Disc. Forward Euler Filter'
 * '<S228>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Filter ICs/Internal IC - Filter'
 * '<S229>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/I Gain/Internal Parameters'
 * '<S230>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Ideal P Gain/Passthrough'
 * '<S231>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Ideal P Gain Fdbk/Disabled'
 * '<S232>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Integrator/Discrete'
 * '<S233>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Integrator ICs/Internal IC'
 * '<S234>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/N Copy/Disabled'
 * '<S235>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/N Gain/Internal Parameters'
 * '<S236>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/P Copy/Disabled'
 * '<S237>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Parallel P Gain/Internal Parameters'
 * '<S238>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Reset Signal/External Reset'
 * '<S239>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Saturation/Enabled'
 * '<S240>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Saturation Fdbk/Disabled'
 * '<S241>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Sum/Sum_PID'
 * '<S242>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Sum Fdbk/Disabled'
 * '<S243>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Tracking Mode/Disabled'
 * '<S244>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Tracking Mode Sum/Passthrough'
 * '<S245>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Tsamp - Integral/TsSignalSpecification'
 * '<S246>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/Tsamp - Ngain/Passthrough'
 * '<S247>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/postSat Signal/Forward_Path'
 * '<S248>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/preInt Signal/Internal PreInt'
 * '<S249>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vx_control/preSat Signal/Forward_Path'
 * '<S250>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Anti-windup'
 * '<S251>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/D Gain'
 * '<S252>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/External Derivative'
 * '<S253>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Filter'
 * '<S254>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Filter ICs'
 * '<S255>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/I Gain'
 * '<S256>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Ideal P Gain'
 * '<S257>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Ideal P Gain Fdbk'
 * '<S258>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Integrator'
 * '<S259>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Integrator ICs'
 * '<S260>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/N Copy'
 * '<S261>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/N Gain'
 * '<S262>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/P Copy'
 * '<S263>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Parallel P Gain'
 * '<S264>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Reset Signal'
 * '<S265>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Saturation'
 * '<S266>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Saturation Fdbk'
 * '<S267>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Sum'
 * '<S268>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Sum Fdbk'
 * '<S269>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Tracking Mode'
 * '<S270>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Tracking Mode Sum'
 * '<S271>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Tsamp - Integral'
 * '<S272>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Tsamp - Ngain'
 * '<S273>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/postSat Signal'
 * '<S274>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/preInt Signal'
 * '<S275>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/preSat Signal'
 * '<S276>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Anti-windup/Disc. Clamping Parallel'
 * '<S277>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S278>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S279>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/D Gain/Internal Parameters'
 * '<S280>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/External Derivative/Error'
 * '<S281>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Filter/Disc. Forward Euler Filter'
 * '<S282>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Filter ICs/Internal IC - Filter'
 * '<S283>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/I Gain/Internal Parameters'
 * '<S284>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Ideal P Gain/Passthrough'
 * '<S285>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Ideal P Gain Fdbk/Disabled'
 * '<S286>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Integrator/Discrete'
 * '<S287>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Integrator ICs/Internal IC'
 * '<S288>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/N Copy/Disabled'
 * '<S289>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/N Gain/Internal Parameters'
 * '<S290>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/P Copy/Disabled'
 * '<S291>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Parallel P Gain/Internal Parameters'
 * '<S292>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Reset Signal/External Reset'
 * '<S293>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Saturation/Enabled'
 * '<S294>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Saturation Fdbk/Disabled'
 * '<S295>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Sum/Sum_PID'
 * '<S296>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Sum Fdbk/Disabled'
 * '<S297>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Tracking Mode/Disabled'
 * '<S298>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Tracking Mode Sum/Passthrough'
 * '<S299>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Tsamp - Integral/TsSignalSpecification'
 * '<S300>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/Tsamp - Ngain/Passthrough'
 * '<S301>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/postSat Signal/Forward_Path'
 * '<S302>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/preInt Signal/Internal PreInt'
 * '<S303>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vy_control/preSat Signal/Forward_Path'
 * '<S304>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Anti-windup'
 * '<S305>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/D Gain'
 * '<S306>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/External Derivative'
 * '<S307>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Filter'
 * '<S308>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Filter ICs'
 * '<S309>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/I Gain'
 * '<S310>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Ideal P Gain'
 * '<S311>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Ideal P Gain Fdbk'
 * '<S312>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Integrator'
 * '<S313>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Integrator ICs'
 * '<S314>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/N Copy'
 * '<S315>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/N Gain'
 * '<S316>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/P Copy'
 * '<S317>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Parallel P Gain'
 * '<S318>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Reset Signal'
 * '<S319>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Saturation'
 * '<S320>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Saturation Fdbk'
 * '<S321>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Sum'
 * '<S322>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Sum Fdbk'
 * '<S323>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Tracking Mode'
 * '<S324>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Tracking Mode Sum'
 * '<S325>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Tsamp - Integral'
 * '<S326>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Tsamp - Ngain'
 * '<S327>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/postSat Signal'
 * '<S328>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/preInt Signal'
 * '<S329>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/preSat Signal'
 * '<S330>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Anti-windup/Disc. Clamping Parallel'
 * '<S331>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S332>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S333>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/D Gain/Internal Parameters'
 * '<S334>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/External Derivative/Error'
 * '<S335>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Filter/Disc. Forward Euler Filter'
 * '<S336>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Filter ICs/Internal IC - Filter'
 * '<S337>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/I Gain/Internal Parameters'
 * '<S338>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Ideal P Gain/Passthrough'
 * '<S339>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Ideal P Gain Fdbk/Disabled'
 * '<S340>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Integrator/Discrete'
 * '<S341>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Integrator ICs/Internal IC'
 * '<S342>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/N Copy/Disabled'
 * '<S343>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/N Gain/Internal Parameters'
 * '<S344>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/P Copy/Disabled'
 * '<S345>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Parallel P Gain/Internal Parameters'
 * '<S346>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Reset Signal/External Reset'
 * '<S347>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Saturation/Enabled'
 * '<S348>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Saturation Fdbk/Disabled'
 * '<S349>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Sum/Sum_PID'
 * '<S350>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Sum Fdbk/Disabled'
 * '<S351>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Tracking Mode/Disabled'
 * '<S352>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Tracking Mode Sum/Passthrough'
 * '<S353>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Tsamp - Integral/TsSignalSpecification'
 * '<S354>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/Tsamp - Ngain/Passthrough'
 * '<S355>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/postSat Signal/Forward_Path'
 * '<S356>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/preInt Signal/Internal PreInt'
 * '<S357>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/postion control/vz_control/preSat Signal/Forward_Path'
 * '<S358>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/select parameter/MATLAB Function'
 * '<S359>' : 'LW_ctrl_241029_1/Controller/PID_Controller/PID_Controller/toPWM/toPWM'
 * '<S360>' : 'LW_ctrl_241029_1/Output/OutputSelect'
 * '<S361>' : 'LW_ctrl_241029_1/Output/OutputSelect/HIL'
 * '<S362>' : 'LW_ctrl_241029_1/Output/OutputSelect/HIL/HIL16CtrlsPWM'
 * '<S363>' : 'LW_ctrl_241029_1/Output/OutputSelect/HIL/MATLAB Function'
 * '<S364>' : 'LW_ctrl_241029_1/Output/OutputSelect/HIL/MATLAB Function1'
 * '<S365>' : 'LW_ctrl_241029_1/Output/OutputSelect/HIL/MATLAB Function2'
 * '<S366>' : 'LW_ctrl_241029_1/Output/OutputSelect/HIL/HIL16CtrlsPWM/ArmTrig1'
 * '<S367>' : 'LW_ctrl_241029_1/Output/OutputSelect/HIL/HIL16CtrlsPWM/RePX4Block'
 * '<S368>' : 'LW_ctrl_241029_1/Output/OutputSelect/HIL/HIL16CtrlsPWM/RePX4Block/ModeSwitch'
 * '<S369>' : 'LW_ctrl_241029_1/navigator/logger'
 * '<S370>' : 'LW_ctrl_241029_1/navigator/navigator_manual'
 * '<S371>' : 'LW_ctrl_241029_1/navigator/navigator_offboard'
 * '<S372>' : 'LW_ctrl_241029_1/navigator/logger/HIL&FLY'
 * '<S373>' : 'LW_ctrl_241029_1/navigator/logger/HIL&FLY/get_delta_t'
 * '<S374>' : 'LW_ctrl_241029_1/navigator/logger/HIL&FLY/hrt_timestamp'
 * '<S375>' : 'LW_ctrl_241029_1/navigator/navigator_manual/Lowpass'
 * '<S376>' : 'LW_ctrl_241029_1/navigator/navigator_manual/Lowpass1'
 * '<S377>' : 'LW_ctrl_241029_1/navigator/navigator_manual/Lowpass2'
 * '<S378>' : 'LW_ctrl_241029_1/navigator/navigator_manual/f1'
 * '<S379>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf0'
 * '<S380>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf1'
 * '<S381>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf10'
 * '<S382>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf11'
 * '<S383>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf2'
 * '<S384>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf3'
 * '<S385>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf4'
 * '<S386>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf5'
 * '<S387>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf6'
 * '<S388>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf7'
 * '<S389>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf8'
 * '<S390>' : 'LW_ctrl_241029_1/navigator/navigator_manual/nan_inf9'
 * '<S391>' : 'LW_ctrl_241029_1/navigator/navigator_manual/pitch_deadzone'
 * '<S392>' : 'LW_ctrl_241029_1/navigator/navigator_manual/pitchrate_deadzone'
 * '<S393>' : 'LW_ctrl_241029_1/navigator/navigator_manual/pitchrate_deadzone1'
 * '<S394>' : 'LW_ctrl_241029_1/navigator/navigator_manual/roll_deadzone'
 * '<S395>' : 'LW_ctrl_241029_1/navigator/navigator_manual/rollrate_deadzone'
 * '<S396>' : 'LW_ctrl_241029_1/navigator/navigator_manual/rollrate_deadzone1'
 * '<S397>' : 'LW_ctrl_241029_1/navigator/navigator_manual/vx_deadzone'
 * '<S398>' : 'LW_ctrl_241029_1/navigator/navigator_manual/vy_deadzone'
 * '<S399>' : 'LW_ctrl_241029_1/navigator/navigator_manual/vz_deadzone'
 * '<S400>' : 'LW_ctrl_241029_1/navigator/navigator_manual/yawrate_deadzone'
 * '<S401>' : 'LW_ctrl_241029_1/navigator/navigator_manual/yawrate_deadzone1'
 * '<S402>' : 'LW_ctrl_241029_1/navigator/navigator_offboard/task select'
 * '<S403>' : 'LW_ctrl_241029_1/navigator/navigator_offboard/task select/task select'
 * '<S404>' : 'LW_ctrl_241029_1/navigator/navigator_offboard/task select/task select/df,coor,wind'
 * '<S405>' : 'LW_ctrl_241029_1/navigator/navigator_offboard/task select/task select/task'
 * '<S406>' : 'LW_ctrl_241029_1/rc_receive/manual_ctrl_in'
 * '<S407>' : 'LW_ctrl_241029_1/rc_receive/manual_ctrl_in/HIL&FLY V1.13.3'
 * '<S408>' : 'LW_ctrl_241029_1/rc_receive/manual_ctrl_in/HIL&FLY V1.13.3/MATLAB Function'
 * '<S409>' : 'LW_ctrl_241029_1/rc_receive/manual_ctrl_in/HIL&FLY V1.13.3/logger'
 * '<S410>' : 'LW_ctrl_241029_1/rc_receive/manual_ctrl_in/HIL&FLY V1.13.3/logger/get_delta_t'
 * '<S411>' : 'LW_ctrl_241029_1/rc_receive/manual_ctrl_in/HIL&FLY V1.13.3/logger/hrt_timestamp'
 * '<S412>' : 'LW_ctrl_241029_1/state_machine/MATLAB Function3'
 * '<S413>' : 'LW_ctrl_241029_1/state_machine/MATLAB Function4'
 * '<S414>' : 'LW_ctrl_241029_1/state_machine/logger'
 * '<S415>' : 'LW_ctrl_241029_1/state_machine/logger/HIL&FLY'
 * '<S416>' : 'LW_ctrl_241029_1/state_machine/logger/HIL&FLY/get_delta_t'
 * '<S417>' : 'LW_ctrl_241029_1/state_machine/logger/HIL&FLY/hrt_timestamp'
 * '<S418>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position'
 * '<S419>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3'
 * '<S420>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/DisturbanceEstimator'
 * '<S421>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/LW_LED'
 * '<S422>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/Lowpass'
 * '<S423>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/Lowpass1'
 * '<S424>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/getIncid'
 * '<S425>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/get_delta_t'
 * '<S426>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/nan_inf'
 * '<S427>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/nan_inf0'
 * '<S428>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/nan_inf1'
 * '<S429>' : 'LW_ctrl_241029_1/states_update/vehicle_local_position/HIL&FLY V1.13.3/nan_inf_q'
 */
#endif                                 /* LW_ctrl_241029_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
