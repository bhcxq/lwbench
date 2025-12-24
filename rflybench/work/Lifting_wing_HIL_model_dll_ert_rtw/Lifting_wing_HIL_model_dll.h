//
// File: Lifting_wing_HIL_model_dll.h
//
// Code generated for Simulink model 'Lifting_wing_HIL_model_dll'.
//
// Model version                  : 10.19
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Dec 24 11:26:19 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef Lifting_wing_HIL_model_dll_h_
#define Lifting_wing_HIL_model_dll_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "coder_bounded_array.h"
#include <cstring>
#ifndef DEFINED_TYPEDEF_FOR_MavLinkGPS_
#define DEFINED_TYPEDEF_FOR_MavLinkGPS_

struct MavLinkGPS
{
  uint32_T time_usec;
  int32_T lat;
  int32_T lon;
  int32_T alt;
  uint16_T eph;
  uint16_T epv;
  uint16_T vel;
  int16_T vn;
  int16_T ve;
  int16_T vd;
  uint16_T cog;
  uint8_T fix_type;
  uint8_T satellites_visible;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_HILGPS_
#define DEFINED_TYPEDEF_FOR_HILGPS_

struct HILGPS
{
  uint8_T fix_type;
  uint8_T satellites_visible;
  int32_T lat;
  int32_T lon;
  int32_T alt;
  uint32_T hAcc;
  uint32_T vAcc;
  int32_T velN;
  int32_T velE;
  int32_T velD;
  int32_T gSpeed;
  int32_T headMot;
  int32_T headVeh;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MavLinkStateQuat_
#define DEFINED_TYPEDEF_FOR_MavLinkStateQuat_

struct MavLinkStateQuat
{
  uint32_T time_usec;
  real32_T attitude_quaternion[4];
  real32_T rollspeed;
  real32_T pitchspeed;
  real32_T yawspeed;
  int32_T lat;
  int32_T lon;
  int32_T alt;
  int16_T vx;
  int16_T vy;
  int16_T vz;
  uint16_T ind_airspeed;
  uint16_T true_airspeed;
  int16_T xacc;
  int16_T yacc;
  int16_T zacc;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MavLinkSensor_
#define DEFINED_TYPEDEF_FOR_MavLinkSensor_

struct MavLinkSensor
{
  uint32_T time_usec;
  real32_T xacc;
  real32_T yacc;
  real32_T zacc;
  real32_T xgyro;
  real32_T ygyro;
  real32_T zgyro;
  real32_T xmag;
  real32_T ymag;
  real32_T zmag;
  real32_T abs_pressure;
  real32_T diff_pressure;
  real32_T pressure_alt;
  real32_T temperature;
  uint32_T fields_updated;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_MavVehileInfo_
#define DEFINED_TYPEDEF_FOR_MavVehileInfo_

struct MavVehileInfo
{
  int32_T copterID;
  int32_T vehicleType;
  real_T runnedTime;
  real32_T VelE[3];
  real32_T PosE[3];
  real32_T AngEuler[3];
  real32_T AngQuatern[4];
  real32_T MotorRPMS[8];
  real32_T AccB[3];
  real32_T RateB[3];
  real_T PosGPS[3];
};

#endif

#ifndef ODE4_INTG
#define ODE4_INTG

// ODE4 Integration Data
struct ODE4_IntgData {
  real_T *y;                           // output
  real_T *f[4];                        // derivatives
};

#endif

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
}                                      // extern "C"

// Class declaration for model Lifting_wing_HIL_model_dll
class MulticopterModelClass final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<S47>/Negative Trace'
  struct DW_NegativeTrace_Lifting_wing_T {
    int8_T FindMaximumDiagonalValue_Active;// '<S48>/Find Maximum Diagonal Value' 
  };

  // Block signals for system '<S215>/Distance into gust (y)'
  struct B_Distanceintogusty_Lifting_w_T {
    real_T DistanceintoGustxLimitedtogustl;
                 // '<S219>/Distance into Gust (x) (Limited to gust length d) '
  };

  // Block states (default storage) for system '<S215>/Distance into gust (y)'
  struct DW_Distanceintogusty_Lifting__T {
    boolean_T Distanceintogusty_MODE;  // '<S215>/Distance into gust (y)'
  };

  // Continuous states for system '<S215>/Distance into gust (y)'
  struct X_Distanceintogusty_Lifting_w_T {
    real_T DistanceintoGustxLimitedtogustl;
                 // '<S219>/Distance into Gust (x) (Limited to gust length d) '
  };

  // State derivatives for system '<S215>/Distance into gust (y)'
  struct XDot_Distanceintogusty_Liftin_T {
    real_T DistanceintoGustxLimitedtogustl;
                 // '<S219>/Distance into Gust (x) (Limited to gust length d) '
  };

  // State Disabled for system '<S215>/Distance into gust (y)'
  struct XDis_Distanceintogusty_Liftin_T {
    boolean_T DistanceintoGustxLimitedtogustl;
                 // '<S219>/Distance into Gust (x) (Limited to gust length d) '
  };

  // Block signals for system '<S284>/MATLAB Function'
  struct B_MATLABFunction_Lifting_wing_T {
    real_T Aa;                         // '<S284>/MATLAB Function'
  };

  // Block states (default storage) for system '<S284>/MATLAB Function'
  struct DW_MATLABFunction_Lifting_win_T {
    real_T Ad_last;                    // '<S284>/MATLAB Function'
  };

  // Block signals for system '<S174>/throttle2rads2'
  struct B_throttle2rads2_Lifting_wing_T {
    real_T y;                          // '<S174>/throttle2rads2'
  };

  // Block signals (default storage)
  struct B_Lifting_wing_HIL_model_dll_T {
    real_T DiscreteTimeIntegrator;     // '<S277>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_m;   // '<S278>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_k;   // '<S279>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_o;   // '<S280>/Discrete-Time Integrator'
    real_T q0;                         // '<S307>/q0'
    real_T q1;                         // '<S307>/q1'
    real_T q2;                         // '<S307>/q2'
    real_T q3;                         // '<S307>/q3'
    real_T Product[3];                 // '<S304>/Product'
    real_T mag_e[3];                   // '<S172>/nT2Gauss'
    real_T SinCos_o1;                  // '<S184>/SinCos'
    real_T SinCos_o2;                  // '<S184>/SinCos'
    real_T sqrt_l;                     // '<S209>/sqrt'
    real_T Switch;                     // '<S195>/Switch'
    real_T Sum1;                       // '<S204>/Sum1'
    real_T Switch_p;                   // '<S196>/Switch'
    real_T Merge_m;                    // '<S189>/Merge'
    real_T Saturation;                 // '<S172>/Saturation'
    real_T SFunction_o1;               // '<S263>/S-Function'
    real_T SFunction_o2;               // '<S263>/S-Function'
    real_T SFunction_o3;               // '<S263>/S-Function'
    real_T SFunction_o4;               // '<S263>/S-Function'
    real_T Merge_p[4];                 // '<S296>/Merge'
    real_T DiscreteTimeIntegrator_kn;  // '<S282>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_c;   // '<S283>/Discrete-Time Integrator'
    real_T delta_e;                    // '<S174>/Sum'
    real_T delta_a;                    // '<S174>/Sum1'
    real_T Gain[3];                    // '<S94>/Gain'
    real_T Selector1[9];               // '<S298>/Selector1'
    real_T Selector[9];                // '<S298>/Selector'
    real_T Selector2[9];               // '<S298>/Selector2'
    real_T Product2[3];                // '<S298>/Product2'
    real_T RandomNumber[3];            // '<S89>/Random Number'
    real_T Sum[3];                     // '<S89>/Sum'
    real_T Delay[3];                   // '<S89>/Delay'
    real_T Saturation_n[3];            // '<S160>/Saturation'
    real_T Delay1[3];                  // '<S92>/Delay1'
    real_T RandomNumber2[3];           // '<S93>/Random Number2'
    real_T Product1[3];                // '<S93>/Product1'
    real_T Delay1_h[3];                // '<S93>/Delay1'
    real_T RandomNumber1;              // '<S90>/Random Number1'
    real_T SinCos_o1_e;                // '<S21>/SinCos'
    real_T SinCos_o2_l;                // '<S21>/SinCos'
    real_T sqrt_b;                     // '<S46>/sqrt'
    real_T Switch_c;                   // '<S32>/Switch'
    real_T Sum1_p;                     // '<S41>/Sum1'
    real_T Switch_b;                   // '<S33>/Switch'
    real_T Merge_c;                    // '<S26>/Merge'
    real_T Sum_p[3];                   // '<S295>/Sum'
    real_T Gain1[3];                   // '<S91>/Gain1'
    real_T SinCos_o1_g;                // '<S130>/SinCos'
    real_T SinCos_o2_j;                // '<S130>/SinCos'
    real_T sqrt_j;                     // '<S155>/sqrt'
    real_T Switch_l;                   // '<S141>/Switch'
    real_T Sum1_m;                     // '<S150>/Sum1'
    real_T Switch_d;                   // '<S142>/Switch'
    real_T Merge_pz;                   // '<S135>/Merge'
    real_T Merge_k[4];                 // '<S47>/Merge'
    real_T RandomNumber1_e[3];         // '<S89>/Random Number1'
    real_T Sum2[3];                    // '<S100>/Sum2'
    real_T Gain_l[3];                  // '<S95>/Gain'
    real_T Sum2_b[3];                  // '<S113>/Sum2'
    real_T RandomNumber3[3];           // '<S89>/Random Number3'
    real_T RandomNumber2_o;            // '<S90>/Random Number2'
    real_T BiasGain1[3];               // '<S91>/BiasGain1'
    real_T RandomNumber_b[3];          // '<S92>/Random Number'
    real_T RandomNumber1_e1[3];        // '<S92>/Random Number1'
    real_T Product4[3];                // '<S92>/Product4'
    real_T Sum2_k[3];                  // '<S163>/Sum2'
    real_T Sum2_h[3];                  // '<S166>/Sum2'
    real_T RandomNumber3_a[3];         // '<S92>/Random Number3'
    real_T RandomNumber1_m[3];         // '<S93>/Random Number1'
    real_T Product3_p[3];              // '<S93>/Product3'
    real_T RandomNumber3_f[3];         // '<S93>/Random Number3'
    real_T RandomNumber_h[3];          // '<S272>/Random Number'
    real_T Add_d[3];                   // '<S272>/Add'
    real_T RandomNumber1_n[3];         // '<S272>/Random Number1'
    real_T RandomNumber2_a[3];         // '<S273>/Random Number2'
    real_T Add2[3];                    // '<S273>/Add2'
    real_T RandomNumber3_a0[3];        // '<S273>/Random Number3'
    real_T Divide;                     // '<S277>/Divide'
    real_T Divide_l;                   // '<S278>/Divide'
    real_T Divide_c;                   // '<S279>/Divide'
    real_T Divide_n;                   // '<S280>/Divide'
    real_T Divide_b;                   // '<S282>/Divide'
    real_T Divide_h;                   // '<S283>/Divide'
    real_T TmpSignalConversionAtq0q1q2q3_c[4];// '<S297>/qdot'
    real_T mag_nbm_var[3];             // '<S382>/failture_mag_nbm_var'
    real_T gyro_ng_var[3];             // '<S381>/failture_gyro_ng_var'
    real_T gyro_nbg_var[3];            // '<S381>/failture_gyro_nbg_var'
    real_T F_env[3];                   // '<S173>/MATLAB Function'
    real_T M_env[3];                   // '<S173>/MATLAB Function'
    real_T UnitConversion;             // '<S222>/Unit Conversion'
    real_T UnitConversion_h;           // '<S260>/Unit Conversion'
    real_T sigma_wg;                   // '<S241>/sigma_wg '
    real_T PreLookUpIndexSearchprobofexcee;
                          // '<S240>/PreLook-Up Index Search  (prob of exceed)'
    real_T Product_k[4];               // '<S233>/Product'
    real_T UnitConversion_c;           // '<S231>/Unit Conversion'
    real_T UnitConversion_e;           // '<S226>/Unit Conversion'
    real_T lnref_heightz0;             // '<S217>/ln(ref_height//z0)'
    real_T Windspeedatreferenceheight[3];
                                     // '<S217>/Wind speed at reference height'
    real_T wind[3];                    // '<S180>/Product3'
    real_T w[2];                       // '<S239>/w'
    real_T sqrt_e;                     // '<S239>/sqrt'
    real_T LwgV1[2];                   // '<S239>/Lwg//V 1'
    real_T w_e[2];                     // '<S239>/w '
    real_T w_d[2];                     // '<S238>/w'
    real_T w_b[2];                     // '<S238>/w '
    real_T w1[2];                      // '<S238>/w 1'
    real_T w_b2[2];                    // '<S237>/w'
    real_T w1_h[2];                    // '<S237>/w1'
    real_T pi3;                        // '<S236>/pi//3'
    real_T w_a[2];                     // '<S236>/w'
    real_T pi4;                        // '<S235>/pi//4'
    real_T w_b5[2];                    // '<S235>/w'
    real_T u16;                        // '<S234>/u^1//6'
    real_T sqrt08V;                    // '<S234>/sqrt(0.8//V)'
    real_T w3;                         // '<S234>/w3'
    real_T w_h[2];                     // '<S234>/w'
    real_T DistanceintoGustxLimitedtogustl;
                  // '<S218>/Distance into Gust (x) (Limited to gust length d)'
    real_T alpha;                      // '<S172>/MATLAB Function1'
    real_T beta;                       // '<S172>/MATLAB Function1'
    real_T airspeed;                   // '<S172>/MATLAB Function1'
    real_T qbar;                       // '<S172>/MATLAB Function1'
    real_T va_l[3];                    // '<S172>/MATLAB Function1'
    real_T Merge_k0;                   // '<S324>/Merge'
    uint32_T fields_updated;           // '<S6>/Data Type Conversion6'
    uint32_T hAcc;                     // '<S13>/Data Type Conversion13'
    uint32_T vAcc;                     // '<S13>/Data Type Conversion14'
    uint32_T PreLookUpIndexSearchprobofexc_o;
                          // '<S240>/PreLook-Up Index Search  (prob of exceed)'
    real32_T xacc;                     // '<S15>/Data Type Conversion2'
    real32_T yacc;                     // '<S15>/Data Type Conversion1'
    real32_T zacc;                     // '<S15>/Data Type Conversion3'
    real32_T xgyro;                    // '<S15>/Data Type Conversion4'
    real32_T ygyro;                    // '<S15>/Data Type Conversion5'
    real32_T zgyro;                    // '<S15>/Data Type Conversion6'
    real32_T xmag;                     // '<S15>/Data Type Conversion7'
    real32_T ymag;                     // '<S15>/Data Type Conversion8'
    real32_T zmag;                     // '<S15>/Data Type Conversion9'
    real32_T MotorRPMS[8];             // '<S16>/Data Type Conversion7'
    int32_T copterID;                  // '<S16>/Data Type Conversion'
    int32_T vehicleType;               // '<S16>/Data Type Conversion1'
    uint16_T eph;                      // '<S13>/Data Type Conversion2'
    uint16_T epv;                      // '<S13>/Data Type Conversion3'
    uint8_T fix_type;                  // '<S13>/Data Type Conversion9'
    uint8_T satellites_visible;        // '<S13>/Data Type Conversion12'
    uint8_T Compare;                   // '<S210>/Compare'
    uint8_T Compare_g;                 // '<S211>/Compare'
    uint8_T Compare_e;                 // '<S213>/Compare'
    uint8_T Compare_a;                 // '<S214>/Compare'
    int8_T landed;                     // '<S172>/Ground Model'
    boolean_T HiddenBuf_InsertedFor_Distanc_n;// '<S215>/Logical Operator1'
    boolean_T HiddenBuf_InsertedFor_Distanc_l;// '<S215>/Logical Operator3'
    B_throttle2rads2_Lifting_wing_T sf_throttle2rads3;// '<S174>/throttle2rads3' 
    B_throttle2rads2_Lifting_wing_T sf_throttle2rads2;// '<S174>/throttle2rads2' 
    B_MATLABFunction_Lifting_wing_T sf_MATLABFunction_i;// '<S285>/MATLAB Function' 
    B_MATLABFunction_Lifting_wing_T sf_MATLABFunction_g;// '<S284>/MATLAB Function' 
    B_Distanceintogusty_Lifting_w_T Distanceintogustz;// '<S215>/Distance into gust (z)' 
    B_Distanceintogusty_Lifting_w_T Distanceintogusty;// '<S215>/Distance into gust (y)' 
  };

  // Block states (default storage) for system '<Root>'
  struct DW_Lifting_wing_HIL_model_dll_T {
    coder::bounded_array<real_T,60,2> x_init;// '<S382>/failture_mag_nm_var'
    coder::bounded_array<real_T,60,2> x_init_k;// '<S382>/failture_mag_nbm_var'
    coder::bounded_array<real_T,60,2> x_init_i;// '<S381>/failture_gyro_ng_var'
    coder::bounded_array<real_T,60,2> x_init_e;// '<S381>/failture_gyro_nbg_var' 
    coder::bounded_array<real_T,60,2> x_init_n;// '<S381>/failture_gyro_kgp'
    coder::bounded_array<real_T,20,1> mag_nm_var_T;// '<S382>/failture_mag_nm_var' 
    coder::bounded_array<real_T,20,1> mag_nm_var_dt;// '<S382>/failture_mag_nm_var' 
    coder::bounded_array<real_T,20,1> v;// '<S382>/failture_mag_nm_var'
    coder::bounded_array<real_T,20,1> mag_nbm_var_T;// '<S382>/failture_mag_nbm_var' 
    coder::bounded_array<real_T,20,1> mag_nbm_var_dt;// '<S382>/failture_mag_nbm_var' 
    coder::bounded_array<real_T,20,1> v_b;// '<S382>/failture_mag_nbm_var'
    coder::bounded_array<real_T,20,1> mag_dm_T;// '<S382>/failture_mag_dm'
    coder::bounded_array<real_T,20,1> gyro_ng_var_T;// '<S381>/failture_gyro_ng_var' 
    coder::bounded_array<real_T,20,1> gyro_ng_var_dt;// '<S381>/failture_gyro_ng_var' 
    coder::bounded_array<real_T,20,1> v_n;// '<S381>/failture_gyro_ng_var'
    coder::bounded_array<real_T,20,1> gyro_nbg_var_T;// '<S381>/failture_gyro_nbg_var' 
    coder::bounded_array<real_T,20,1> gyro_nbg_var_dt;// '<S381>/failture_gyro_nbg_var' 
    coder::bounded_array<real_T,20,1> v_j;// '<S381>/failture_gyro_nbg_var'
    coder::bounded_array<real_T,20,1> gyro_kgp_T;// '<S381>/failture_gyro_kgp'
    coder::bounded_array<real_T,20,1> gyro_kgp_dt;// '<S381>/failture_gyro_kgp'
    coder::bounded_array<real_T,20,1> v_bm;// '<S381>/failture_gyro_kgp'
    coder::bounded_array<real_T,20,1> accel_nbg_var_T;// '<S380>/failture_accel_nba_var' 
    coder::bounded_array<real_T,20,1> accel_na_var_T;// '<S380>/failture_accel_na_var' 
    coder::bounded_array<real_T,20,1> accel_kgp_T;// '<S380>/failture_accel_kap' 
    coder::bounded_array<real_T,20,1> baro_nbb_var_T;// '<S379>/failture_baro_nbb_var' 
    coder::bounded_array<real_T,20,1> x_init_hs;// '<S379>/failture_baro_nbb_var' 
    coder::bounded_array<real_T,20,1> baro_nb_var_T;// '<S379>/failture_baro_nb_var' 
    coder::bounded_array<real_T,2,1> propeller_kct_am;// '<S384>/failture_propeller8' 
    coder::bounded_array<real_T,2,1> propeller_kct_am_a;// '<S384>/failture_propeller7' 
    coder::bounded_array<real_T,2,1> propeller_kct_am_e;// '<S384>/failture_propeller6' 
    coder::bounded_array<real_T,2,1> propeller_kct_am_i;// '<S384>/failture_propeller5' 
    coder::bounded_array<real_T,2,1> propeller_kct_am_j;// '<S384>/failture_propeller4' 
    coder::bounded_array<real_T,2,1> propeller_kct_am_k;// '<S384>/failture_propeller3' 
    coder::bounded_array<real_T,2,1> propeller_kct_am_m;// '<S384>/failture_propeller2' 
    coder::bounded_array<real_T,2,1> propeller_kct_am_c;// '<S384>/failture_propeller1' 
    coder::bounded_array<real_T,2,1> motor_ktc_limit;// '<S383>/failture_motor_ktc8' 
    coder::bounded_array<real_T,2,1> motor_ktc_limit_m;// '<S383>/failture_motor_ktc7' 
    coder::bounded_array<real_T,2,1> motor_ktc_limit_o;// '<S383>/failture_motor_ktc6' 
    coder::bounded_array<real_T,2,1> motor_ktc_limit_i;// '<S383>/failture_motor_ktc5' 
    coder::bounded_array<real_T,2,1> motor_ktc_limit_a;// '<S383>/failture_motor_ktc4' 
    coder::bounded_array<real_T,2,1> motor_ktc_limit_p;// '<S383>/failture_motor_ktc3' 
    coder::bounded_array<real_T,2,1> motor_ktc_limit_mf;// '<S383>/failture_motor_ktc2' 
    coder::bounded_array<real_T,2,1> motor_ktc_limit_iq;// '<S383>/failture_motor_ktc1' 
    coder::bounded_array<real_T,2,1> motor_speed_am;// '<S383>/failture_motor8'
    coder::bounded_array<real_T,2,1> motor_speed_am_i;// '<S383>/failture_motor7' 
    coder::bounded_array<real_T,2,1> motor_speed_am_m;// '<S383>/failture_motor6' 
    coder::bounded_array<real_T,2,1> motor_speed_am_h;// '<S383>/failture_motor5' 
    coder::bounded_array<real_T,2,1> motor_speed_am_e;// '<S383>/failture_motor4' 
    coder::bounded_array<real_T,2,1> motor_speed_am_a;// '<S383>/failture_motor3' 
    coder::bounded_array<real_T,2,1> motor_speed_am_id;// '<S383>/failture_motor2' 
    coder::bounded_array<real_T,2,1> motor_speed_am_f;// '<S383>/failture_motor1' 
    coder::bounded_array<real_T,2,1> mag_km_limit;// '<S382>/failture_magl_km_cm' 
    coder::bounded_array<real_T,2,1> mag_cm_limit;// '<S382>/failture_magl_km_cm' 
    coder::bounded_array<real_T,2,1> mag_nm_var_am;// '<S382>/failture_mag_nm_var' 
    coder::bounded_array<real_T,2,1> mag_nbm_var_am;// '<S382>/failture_mag_nbm_var' 
    coder::bounded_array<real_T,2,1> mag_dm_am;// '<S382>/failture_mag_dm'
    coder::bounded_array<real_T,2,1> gyro_ng_var_am;// '<S381>/failture_gyro_ng_var' 
    coder::bounded_array<real_T,2,1> gyro_nbg_var_am;// '<S381>/failture_gyro_nbg_var' 
    coder::bounded_array<real_T,2,1> gyro_kgp_am;// '<S381>/failture_gyro_kgp'
    coder::bounded_array<real_T,2,1> gyro_kg_limit;// '<S381>/failture_gyro_kg_cg' 
    coder::bounded_array<real_T,2,1> gyro_cg_limit;// '<S381>/failture_gyro_kg_cg' 
    coder::bounded_array<real_T,2,1> accel_nbg_var_am;// '<S380>/failture_accel_nba_var' 
    coder::bounded_array<real_T,2,1> accel_na_var_am;// '<S380>/failture_accel_na_var' 
    coder::bounded_array<real_T,2,1> accel_kgp_am;// '<S380>/failture_accel_kap' 
    coder::bounded_array<real_T,2,1> accel_kg_limit;// '<S380>/failture_accel_ka_ca' 
    coder::bounded_array<real_T,2,1> accel_cg_limit;// '<S380>/failture_accel_ka_ca' 
    coder::bounded_array<real_T,2,1> baro_nbb_var_am;// '<S379>/failture_baro_nbb_var' 
    coder::bounded_array<real_T,2,1> baro_nb_var_am;// '<S379>/failture_baro_nb_var' 
    real_T DiscreteTimeIntegrator_DSTATE;// '<S277>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_DSTATE_e;// '<S278>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_DSTATE_o;// '<S279>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_DSTATE_c;// '<S280>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator_DSTATE_f;// '<S282>/Discrete-Time Integrator'
    real_T UnitDelay_DSTATE;           // '<S284>/Unit Delay'
    real_T DiscreteTimeIntegrator_DSTATE_j;// '<S283>/Discrete-Time Integrator'
    real_T UnitDelay_DSTATE_h;         // '<S285>/Unit Delay'
    real_T Delay_DSTATE[300];          // '<S89>/Delay'
    real_T Delay1_DSTATE[300];         // '<S92>/Delay1'
    real_T Delay1_DSTATE_l[300];       // '<S93>/Delay1'
    real_T SFunction_temp_table[8];    // '<S263>/S-Function'
    real_T SFunction_pres_table[8];    // '<S263>/S-Function'
    real_T Product2_DWORK4[9];         // '<S298>/Product2'
    real_T NextOutput[3];              // '<S89>/Random Number'
    real_T NextOutput_j[3];            // '<S93>/Random Number2'
    real_T NextOutput_h;               // '<S90>/Random Number1'
    real_T UniformRandomNumber1_NextOutput[3];// '<S91>/Uniform Random Number1'
    real_T NextOutput_g[3];            // '<S89>/Random Number1'
    real_T NextOutput_b[3];            // '<S89>/Random Number3'
    real_T NextOutput_l;               // '<S90>/Random Number2'
    real_T UniformRandomNumber4_NextOutput[3];// '<S91>/Uniform Random Number4'
    real_T NextOutput_i[3];            // '<S92>/Random Number'
    real_T NextOutput_gk[3];           // '<S92>/Random Number1'
    real_T NextOutput_le[3];           // '<S92>/Random Number3'
    real_T NextOutput_k[3];            // '<S93>/Random Number'
    real_T NextOutput_ko[3];           // '<S93>/Random Number1'
    real_T NextOutput_ld[3];           // '<S93>/Random Number3'
    real_T NextOutput_c[3];            // '<S272>/Random Number'
    real_T NextOutput_cd[3];           // '<S272>/Random Number1'
    real_T NextOutput_im[3];           // '<S273>/Random Number2'
    real_T NextOutput_o[3];            // '<S273>/Random Number3'
    real_T propeller_init;             // '<S384>/failture_propeller8'
    real_T propeller_kct_dt;           // '<S384>/failture_propeller8'
    real_T propeller_kct_en;           // '<S384>/failture_propeller8'
    real_T x_init_c;                   // '<S384>/failture_propeller8'
    real_T propeller_init_i;           // '<S384>/failture_propeller7'
    real_T propeller_kct_dt_k;         // '<S384>/failture_propeller7'
    real_T propeller_kct_en_p;         // '<S384>/failture_propeller7'
    real_T x_init_o;                   // '<S384>/failture_propeller7'
    real_T propeller_init_p;           // '<S384>/failture_propeller6'
    real_T propeller_kct_dt_a;         // '<S384>/failture_propeller6'
    real_T propeller_kct_en_k;         // '<S384>/failture_propeller6'
    real_T x_init_i1;                  // '<S384>/failture_propeller6'
    real_T propeller_init_m;           // '<S384>/failture_propeller5'
    real_T propeller_kct_dt_m;         // '<S384>/failture_propeller5'
    real_T propeller_kct_en_a;         // '<S384>/failture_propeller5'
    real_T x_init_oi;                  // '<S384>/failture_propeller5'
    real_T propeller_init_b;           // '<S384>/failture_propeller4'
    real_T propeller_kct_dt_j;         // '<S384>/failture_propeller4'
    real_T propeller_kct_en_d;         // '<S384>/failture_propeller4'
    real_T x_init_cr;                  // '<S384>/failture_propeller4'
    real_T propeller_init_d;           // '<S384>/failture_propeller3'
    real_T propeller_kct_dt_jm;        // '<S384>/failture_propeller3'
    real_T propeller_kct_en_i;         // '<S384>/failture_propeller3'
    real_T x_init_ee;                  // '<S384>/failture_propeller3'
    real_T propeller_init_dn;          // '<S384>/failture_propeller2'
    real_T propeller_kct_dt_c;         // '<S384>/failture_propeller2'
    real_T propeller_kct_en_h;         // '<S384>/failture_propeller2'
    real_T x_init_b;                   // '<S384>/failture_propeller2'
    real_T propeller_init_a;           // '<S384>/failture_propeller1'
    real_T propeller_kct_dt_n;         // '<S384>/failture_propeller1'
    real_T propeller_kct_en_o;         // '<S384>/failture_propeller1'
    real_T x_init_a;                   // '<S384>/failture_propeller1'
    real_T motor_init;                 // '<S383>/failture_motor_ktc8'
    real_T motor_ktc_en;               // '<S383>/failture_motor_ktc8'
    real_T motor_init_o;               // '<S383>/failture_motor_ktc7'
    real_T motor_ktc_en_h;             // '<S383>/failture_motor_ktc7'
    real_T motor_init_l;               // '<S383>/failture_motor_ktc6'
    real_T motor_ktc_en_j;             // '<S383>/failture_motor_ktc6'
    real_T motor_init_e;               // '<S383>/failture_motor_ktc5'
    real_T motor_ktc_en_f;             // '<S383>/failture_motor_ktc5'
    real_T motor_init_a;               // '<S383>/failture_motor_ktc4'
    real_T motor_ktc_en_c;             // '<S383>/failture_motor_ktc4'
    real_T motor_init_c;               // '<S383>/failture_motor_ktc3'
    real_T motor_ktc_en_i;             // '<S383>/failture_motor_ktc3'
    real_T motor_init_aq;              // '<S383>/failture_motor_ktc2'
    real_T motor_ktc_en_k;             // '<S383>/failture_motor_ktc2'
    real_T motor_init_ao;              // '<S383>/failture_motor_ktc1'
    real_T motor_ktc_en_l;             // '<S383>/failture_motor_ktc1'
    real_T motor_init_h;               // '<S383>/failture_motor8'
    real_T motor_speed_dt;             // '<S383>/failture_motor8'
    real_T motor_speed_en;             // '<S383>/failture_motor8'
    real_T x_init_bp;                  // '<S383>/failture_motor8'
    real_T motor_init_d;               // '<S383>/failture_motor7'
    real_T motor_speed_dt_a;           // '<S383>/failture_motor7'
    real_T motor_speed_en_l;           // '<S383>/failture_motor7'
    real_T x_init_l;                   // '<S383>/failture_motor7'
    real_T motor_init_n;               // '<S383>/failture_motor6'
    real_T motor_speed_dt_b;           // '<S383>/failture_motor6'
    real_T motor_speed_en_m;           // '<S383>/failture_motor6'
    real_T x_init_m;                   // '<S383>/failture_motor6'
    real_T motor_init_ci;              // '<S383>/failture_motor5'
    real_T motor_speed_dt_ah;          // '<S383>/failture_motor5'
    real_T motor_speed_en_h;           // '<S383>/failture_motor5'
    real_T x_init_pa;                  // '<S383>/failture_motor5'
    real_T motor_init_g;               // '<S383>/failture_motor4'
    real_T motor_speed_dt_be;          // '<S383>/failture_motor4'
    real_T motor_speed_en_p;           // '<S383>/failture_motor4'
    real_T x_init_bz;                  // '<S383>/failture_motor4'
    real_T motor_init_m;               // '<S383>/failture_motor3'
    real_T motor_speed_dt_c;           // '<S383>/failture_motor3'
    real_T motor_speed_en_o;           // '<S383>/failture_motor3'
    real_T x_init_pt;                  // '<S383>/failture_motor3'
    real_T motor_init_c4;              // '<S383>/failture_motor2'
    real_T motor_speed_dt_c1;          // '<S383>/failture_motor2'
    real_T motor_speed_en_d;           // '<S383>/failture_motor2'
    real_T x_init_lu;                  // '<S383>/failture_motor2'
    real_T motor_init_a2;              // '<S383>/failture_motor1'
    real_T motor_speed_dt_o;           // '<S383>/failture_motor1'
    real_T motor_speed_en_i;           // '<S383>/failture_motor1'
    real_T x_init_pc;                  // '<S383>/failture_motor1'
    real_T mag_init;                   // '<S382>/failture_magl_km_cm'
    real_T mag_km_cm_en;               // '<S382>/failture_magl_km_cm'
    real_T mag_km[3];                  // '<S382>/failture_magl_km_cm'
    real_T mag_nm_var_init;            // '<S382>/failture_mag_nm_var'
    real_T mag_nm_var_en;              // '<S382>/failture_mag_nm_var'
    real_T timestart_d;                // '<S382>/failture_mag_nm_var'
    real_T mag_nbm_var_init;           // '<S382>/failture_mag_nbm_var'
    real_T mag_nbm_var_en;             // '<S382>/failture_mag_nbm_var'
    real_T timestart_mr;               // '<S382>/failture_mag_nbm_var'
    real_T mag_dm_init;                // '<S382>/failture_mag_dm'
    real_T mag_dm_en;                  // '<S382>/failture_mag_dm'
    real_T gyro_ng_var_init;           // '<S381>/failture_gyro_ng_var'
    real_T gyro_ng_var_en;             // '<S381>/failture_gyro_ng_var'
    real_T timestart_ml;               // '<S381>/failture_gyro_ng_var'
    real_T gyro_nbg_var_init;          // '<S381>/failture_gyro_nbg_var'
    real_T gyro_nbg_var_en;            // '<S381>/failture_gyro_nbg_var'
    real_T timestart_n;                // '<S381>/failture_gyro_nbg_var'
    real_T gyro_kgp_init;              // '<S381>/failture_gyro_kgp'
    real_T gyro_kgp_en;                // '<S381>/failture_gyro_kgp'
    real_T timestart_jj;               // '<S381>/failture_gyro_kgp'
    real_T gyro_init;                  // '<S381>/failture_gyro_kg_cg'
    real_T gyro_kg_cg_en;              // '<S381>/failture_gyro_kg_cg'
    real_T gyro_kg[3];                 // '<S381>/failture_gyro_kg_cg'
    real_T gyro_cg[3];                 // '<S381>/failture_gyro_kg_cg'
    real_T accel_nbg_var_init;         // '<S380>/failture_accel_nba_var'
    real_T accel_nbg_var_en;           // '<S380>/failture_accel_nba_var'
    real_T accel_na_var_init;          // '<S380>/failture_accel_na_var'
    real_T accel_na_var_en;            // '<S380>/failture_accel_na_var'
    real_T accel_kgp_init;             // '<S380>/failture_accel_kap'
    real_T accel_kgp_en;               // '<S380>/failture_accel_kap'
    real_T accel_init;                 // '<S380>/failture_accel_ka_ca'
    real_T accel_kg_cg_en;             // '<S380>/failture_accel_ka_ca'
    real_T baro_nbb_var_init;          // '<S379>/failture_baro_nbb_var'
    real_T baro_nbb_var_en;            // '<S379>/failture_baro_nbb_var'
    real_T baro_nb_var_init;           // '<S379>/failture_baro_nb_var'
    real_T baro_nb_var_en;             // '<S379>/failture_baro_nb_var'
    real_T NextOutput_ia[4];           // '<S233>/White Noise'
    real_T xTemp[8];                   // '<S12>/Model Fail Assessment'
    real_T kk;                         // '<S12>/Model Fail Assessment'
    real_T ss[6];                      // '<S12>/Model Fail Assessment'
    real_T lastZ;                      // '<Root>/MATLAB Function'
    real_T mv0[3];                     // '<Root>/CollisionDetection'
    real_T tColi;                      // '<Root>/CollisionDetection'
    uint32_T RandSeed[3];              // '<S89>/Random Number'
    uint32_T RandSeed_d[3];            // '<S93>/Random Number2'
    uint32_T RandSeed_p;               // '<S90>/Random Number1'
    uint32_T RandSeed_h[3];            // '<S91>/Uniform Random Number1'
    uint32_T RandSeed_a[3];            // '<S89>/Random Number1'
    uint32_T RandSeed_n[3];            // '<S89>/Random Number3'
    uint32_T RandSeed_g;               // '<S90>/Random Number2'
    uint32_T RandSeed_l[3];            // '<S91>/Uniform Random Number4'
    uint32_T RandSeed_nm[3];           // '<S92>/Random Number'
    uint32_T RandSeed_p5[3];           // '<S92>/Random Number1'
    uint32_T RandSeed_c[3];            // '<S92>/Random Number3'
    uint32_T RandSeed_i[3];            // '<S93>/Random Number'
    uint32_T RandSeed_g1[3];           // '<S93>/Random Number1'
    uint32_T RandSeed_go[3];           // '<S93>/Random Number3'
    uint32_T RandSeed_m[3];            // '<S272>/Random Number'
    uint32_T RandSeed_k[3];            // '<S272>/Random Number1'
    uint32_T RandSeed_ld[3];           // '<S273>/Random Number2'
    uint32_T RandSeed_o[3];            // '<S273>/Random Number3'
    uint32_T state[625];               // '<S384>/failture_propeller8'
    uint32_T state_d[625];             // '<S384>/failture_propeller7'
    uint32_T state_j[625];             // '<S384>/failture_propeller6'
    uint32_T state_k[625];             // '<S384>/failture_propeller5'
    uint32_T state_l[625];             // '<S384>/failture_propeller4'
    uint32_T state_kf[625];            // '<S384>/failture_propeller3'
    uint32_T state_dm[625];            // '<S384>/failture_propeller2'
    uint32_T state_n[625];             // '<S384>/failture_propeller1'
    uint32_T state_e[625];             // '<S383>/failture_motor_ktc8'
    uint32_T state_ns[625];            // '<S383>/failture_motor_ktc7'
    uint32_T state_f[625];             // '<S383>/failture_motor_ktc6'
    uint32_T state_el[625];            // '<S383>/failture_motor_ktc5'
    uint32_T state_i[625];             // '<S383>/failture_motor_ktc4'
    uint32_T state_m[625];             // '<S383>/failture_motor_ktc3'
    uint32_T state_g[625];             // '<S383>/failture_motor_ktc2'
    uint32_T state_n5[625];            // '<S383>/failture_motor_ktc1'
    uint32_T state_dmq[625];           // '<S383>/failture_motor8'
    uint32_T state_gz[625];            // '<S383>/failture_motor7'
    uint32_T state_dy[625];            // '<S383>/failture_motor6'
    uint32_T state_p[625];             // '<S383>/failture_motor5'
    uint32_T state_b[625];             // '<S383>/failture_motor4'
    uint32_T state_o[625];             // '<S383>/failture_motor3'
    uint32_T state_lo[625];            // '<S383>/failture_motor2'
    uint32_T state_no[625];            // '<S383>/failture_motor1'
    uint32_T state_kv[625];            // '<S382>/failture_magl_km_cm'
    uint32_T state_m2[625];            // '<S382>/failture_mag_nm_var'
    uint32_T state_c[625];             // '<S382>/failture_mag_nbm_var'
    uint32_T state_e5[625];            // '<S382>/failture_mag_dm'
    uint32_T state_nk[625];            // '<S381>/failture_gyro_ng_var'
    uint32_T state_ke[625];            // '<S381>/failture_gyro_nbg_var'
    uint32_T state_bu[625];            // '<S381>/failture_gyro_kgp'
    uint32_T state_c0[625];            // '<S381>/failture_gyro_kg_cg'
    uint32_T state_oa[625];            // '<S380>/failture_accel_nba_var'
    uint32_T state_i5[625];            // '<S380>/failture_accel_na_var'
    uint32_T state_a[625];             // '<S380>/failture_accel_kap'
    uint32_T state_nk2[625];           // '<S380>/failture_accel_ka_ca'
    uint32_T state_k4[625];            // '<S379>/failture_baro_nbb_var'
    uint32_T state_e3[625];            // '<S379>/failture_baro_nb_var'
    uint32_T PreLookUpIndexSearchaltitude_DW;
                                // '<S240>/PreLook-Up Index Search  (altitude)'
    uint32_T PreLookUpIndexSearchprobofexcee;
                          // '<S240>/PreLook-Up Index Search  (prob of exceed)'
    uint32_T RandSeed_kb[4];           // '<S233>/White Noise'
    uint32_T method;                   // '<Root>/CollisionDetection'
    uint32_T state_gk;                 // '<Root>/CollisionDetection'
    uint32_T state_as[2];              // '<Root>/CollisionDetection'
    uint32_T state_bm[625];            // '<Root>/CollisionDetection'
    int_T IntegratorSecondOrderLimited_MO[3];
                                   // '<S100>/Integrator, Second-Order Limited'
    int_T IntegratorSecondOrderLimited__n[3];
                                   // '<S166>/Integrator, Second-Order Limited'
    int_T IntegratorSecondOrderLimited__h[3];
                                   // '<S113>/Integrator, Second-Order Limited'
    int_T IntegratorSecondOrderLimited__c[3];
                                   // '<S163>/Integrator, Second-Order Limited'
    int8_T If_ActiveSubsystem;         // '<S198>/If'
    int8_T If_ActiveSubsystem_f;       // '<S189>/If'
    int8_T If_ActiveSubsystem_p;       // '<S296>/If'
    int8_T If_ActiveSubsystem_l;       // '<S324>/If'
    int8_T If_ActiveSubsystem_m;       // '<S35>/If'
    int8_T If_ActiveSubsystem_f4;      // '<S26>/If'
    int8_T If_ActiveSubsystem_j;       // '<S144>/If'
    int8_T If_ActiveSubsystem_g;       // '<S135>/If'
    int8_T If_ActiveSubsystem_a;       // '<S47>/If'
    int8_T If1_ActiveSubsystem;        // '<S50>/If1'
    int8_T If1_ActiveSubsystem_l;      // '<S339>/If1'
    int8_T ifHeightMaxlowaltitudeelseifHei;
    // '<S228>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
    int8_T ifHeightMaxlowaltitudeelseifH_f;
    // '<S229>/if Height < Max low altitude  elseif Height > Min isotropic altitude ' 
    int8_T takeoffFlag;                // '<S172>/Ground Model'
    int8_T landFlag;                   // '<S172>/Ground Model'
    int8_T isCol;                      // '<Root>/CollisionDetection'
    boolean_T IntegratorSecondOrderLimited_DW;
                                   // '<S100>/Integrator, Second-Order Limited'
    boolean_T q0q1q2q3_DWORK1;         // '<S297>/q0 q1 q2 q3'
    boolean_T IntegratorSecondOrderLimited__d;
                                   // '<S166>/Integrator, Second-Order Limited'
    boolean_T IntegratorSecondOrderLimited__j;
                                   // '<S113>/Integrator, Second-Order Limited'
    boolean_T IntegratorSecondOrderLimited_ht;
                                   // '<S163>/Integrator, Second-Order Limited'
    boolean_T timestart_not_empty;     // '<S384>/failture_propeller8'
    boolean_T timestart_not_empty_o;   // '<S384>/failture_propeller7'
    boolean_T timestart_not_empty_f;   // '<S384>/failture_propeller6'
    boolean_T timestart_not_empty_h;   // '<S384>/failture_propeller5'
    boolean_T timestart_not_empty_fy;  // '<S384>/failture_propeller4'
    boolean_T timestart_not_empty_l;   // '<S384>/failture_propeller3'
    boolean_T timestart_not_empty_g;   // '<S384>/failture_propeller2'
    boolean_T timestart_not_empty_fc;  // '<S384>/failture_propeller1'
    boolean_T timestart_not_empty_d;   // '<S383>/failture_motor8'
    boolean_T timestart_not_empty_k;   // '<S383>/failture_motor7'
    boolean_T timestart_not_empty_fv;  // '<S383>/failture_motor6'
    boolean_T timestart_not_empty_a;   // '<S383>/failture_motor5'
    boolean_T timestart_not_empty_ax;  // '<S383>/failture_motor4'
    boolean_T timestart_not_empty_n;   // '<S383>/failture_motor3'
    boolean_T timestart_not_empty_e;   // '<S383>/failture_motor2'
    boolean_T timestart_not_empty_m;   // '<S383>/failture_motor1'
    boolean_T timestart_not_empty_d0;  // '<S382>/failture_mag_nm_var'
    boolean_T timestart_not_empty_o4;  // '<S382>/failture_mag_nbm_var'
    boolean_T timestart_not_empty_b;   // '<S382>/failture_mag_dm'
    boolean_T timestart_not_empty_j;   // '<S381>/failture_gyro_ng_var'
    boolean_T timestart_not_empty_h5;  // '<S381>/failture_gyro_nbg_var'
    boolean_T timestart_not_empty_c;   // '<S381>/failture_gyro_kgp'
    boolean_T timestart_not_empty_d4;  // '<S380>/failture_accel_nba_var'
    boolean_T timestart_not_empty_ca;  // '<S380>/failture_accel_na_var'
    boolean_T timestart_not_empty_mc;  // '<S380>/failture_accel_kap'
    boolean_T timestart_not_empty_nr;  // '<S379>/failture_baro_nbb_var'
    boolean_T timestart_not_empty_gj;  // '<S379>/failture_baro_nb_var'
    boolean_T hold_yaw_flag;           // '<S173>/MATLAB Function'
    boolean_T hold_yaw_flag_not_empty; // '<S173>/MATLAB Function'
    boolean_T land_yaw_not_empty;      // '<S173>/MATLAB Function'
    boolean_T gyro_not_empty;          // '<S92>/MATLAB Function'
    boolean_T Hwgws_MODE;              // '<S224>/Hwgw(s)'
    boolean_T Hvgws_MODE;              // '<S224>/Hvgw(s)'
    boolean_T Hugws_MODE;              // '<S224>/Hugw(s)'
    boolean_T Hrgw_MODE;               // '<S223>/Hrgw'
    boolean_T Hqgw_MODE;               // '<S223>/Hqgw'
    boolean_T Hpgw_MODE;               // '<S223>/Hpgw'
    boolean_T Distanceintogustx_MODE;  // '<S215>/Distance into gust (x)'
    DW_NegativeTrace_Lifting_wing_T NegativeTrace_h;// '<S296>/Negative Trace'
    DW_MATLABFunction_Lifting_win_T sf_MATLABFunction_i;// '<S285>/MATLAB Function' 
    DW_MATLABFunction_Lifting_win_T sf_MATLABFunction_g;// '<S284>/MATLAB Function' 
    DW_Distanceintogusty_Lifting__T Distanceintogustz;// '<S215>/Distance into gust (z)' 
    DW_Distanceintogusty_Lifting__T Distanceintogusty;// '<S215>/Distance into gust (y)' 
    DW_NegativeTrace_Lifting_wing_T NegativeTrace;// '<S47>/Negative Trace'
  };

  // Continuous states (default storage)
  struct X_Lifting_wing_HIL_model_dll_T {
    real_T IntegratorSecondOrderLimited_CS[6];
                                   // '<S100>/Integrator, Second-Order Limited'
    real_T q0q1q2q3_CSTATE[4];         // '<S297>/q0 q1 q2 q3'
    real_T ubvbwb_CSTATE[3];           // '<S295>/ub,vb,wb'
    real_T xeyeze_CSTATE[3];           // '<S295>/xe,ye,ze'
    real_T pqr_CSTATE[3];              // '<S295>/p,q,r '
    real_T TransferFcn_CSTATE;         // '<S272>/Transfer Fcn'
    real_T TransferFcn1_CSTATE;        // '<S272>/Transfer Fcn1'
    real_T TransferFcn2_CSTATE;        // '<S272>/Transfer Fcn2'
    real_T TransferFcn3_CSTATE;        // '<S273>/Transfer Fcn3'
    real_T TransferFcn4_CSTATE;        // '<S273>/Transfer Fcn4'
    real_T TransferFcn5_CSTATE;        // '<S273>/Transfer Fcn5'
    real_T Integrator_CSTATE[3];       // '<S89>/Integrator'
    real_T IntegratorSecondOrderLimited__f[6];
                                   // '<S166>/Integrator, Second-Order Limited'
    real_T Integrator1_CSTATE[3];      // '<S93>/Integrator1'
    real_T Integrator1_CSTATE_m;       // '<S90>/Integrator1'
    real_T TransferFcn4_CSTATE_l;      // '<S127>/Transfer Fcn4'
    real_T TransferFcn1_CSTATE_o;      // '<S127>/Transfer Fcn1'
    real_T TransferFcn2_CSTATE_j;      // '<S127>/Transfer Fcn2'
    real_T IntegratorSecondOrderLimited_fi[6];
                                   // '<S113>/Integrator, Second-Order Limited'
    real_T Integrator1_CSTATE_f[3];    // '<S89>/Integrator1'
    real_T Integrator_CSTATE_l[3];     // '<S92>/Integrator'
    real_T IntegratorSecondOrderLimited__j[6];
                                   // '<S163>/Integrator, Second-Order Limited'
    real_T Integrator1_CSTATE_d[3];    // '<S92>/Integrator1'
    real_T Integrator_CSTATE_n[3];     // '<S93>/Integrator'
    real_T Integrator_CSTATE_o[3];     // '<S272>/Integrator'
    real_T Integrator1_CSTATE_e[3];    // '<S273>/Integrator1'
    real_T wg_p1_CSTATE[2];            // '<S239>/wg_p1'
    real_T wg_p2_CSTATE[2];            // '<S239>/wg_p2'
    real_T vg_p1_CSTATE[2];            // '<S238>/vg_p1'
    real_T vgw_p2_CSTATE[2];           // '<S238>/vgw_p2'
    real_T ug_p_CSTATE[2];             // '<S237>/ug_p'
    real_T rgw_p_CSTATE[2];            // '<S236>/rgw_p'
    real_T qgw_p_CSTATE[2];            // '<S235>/qgw_p'
    real_T pgw_p_CSTATE[2];            // '<S234>/pgw_p'
    X_Distanceintogusty_Lifting_w_T Distanceintogustz;// '<S215>/Distance into gust (y)' 
    X_Distanceintogusty_Lifting_w_T Distanceintogusty;// '<S215>/Distance into gust (y)' 
    real_T DistanceintoGustxLimitedtogus_n;
                  // '<S218>/Distance into Gust (x) (Limited to gust length d)'
  };

  // State derivatives (default storage)
  struct XDot_Lifting_wing_HIL_model_d_T {
    real_T IntegratorSecondOrderLimited_CS[6];
                                   // '<S100>/Integrator, Second-Order Limited'
    real_T q0q1q2q3_CSTATE[4];         // '<S297>/q0 q1 q2 q3'
    real_T ubvbwb_CSTATE[3];           // '<S295>/ub,vb,wb'
    real_T xeyeze_CSTATE[3];           // '<S295>/xe,ye,ze'
    real_T pqr_CSTATE[3];              // '<S295>/p,q,r '
    real_T TransferFcn_CSTATE;         // '<S272>/Transfer Fcn'
    real_T TransferFcn1_CSTATE;        // '<S272>/Transfer Fcn1'
    real_T TransferFcn2_CSTATE;        // '<S272>/Transfer Fcn2'
    real_T TransferFcn3_CSTATE;        // '<S273>/Transfer Fcn3'
    real_T TransferFcn4_CSTATE;        // '<S273>/Transfer Fcn4'
    real_T TransferFcn5_CSTATE;        // '<S273>/Transfer Fcn5'
    real_T Integrator_CSTATE[3];       // '<S89>/Integrator'
    real_T IntegratorSecondOrderLimited__f[6];
                                   // '<S166>/Integrator, Second-Order Limited'
    real_T Integrator1_CSTATE[3];      // '<S93>/Integrator1'
    real_T Integrator1_CSTATE_m;       // '<S90>/Integrator1'
    real_T TransferFcn4_CSTATE_l;      // '<S127>/Transfer Fcn4'
    real_T TransferFcn1_CSTATE_o;      // '<S127>/Transfer Fcn1'
    real_T TransferFcn2_CSTATE_j;      // '<S127>/Transfer Fcn2'
    real_T IntegratorSecondOrderLimited_fi[6];
                                   // '<S113>/Integrator, Second-Order Limited'
    real_T Integrator1_CSTATE_f[3];    // '<S89>/Integrator1'
    real_T Integrator_CSTATE_l[3];     // '<S92>/Integrator'
    real_T IntegratorSecondOrderLimited__j[6];
                                   // '<S163>/Integrator, Second-Order Limited'
    real_T Integrator1_CSTATE_d[3];    // '<S92>/Integrator1'
    real_T Integrator_CSTATE_n[3];     // '<S93>/Integrator'
    real_T Integrator_CSTATE_o[3];     // '<S272>/Integrator'
    real_T Integrator1_CSTATE_e[3];    // '<S273>/Integrator1'
    real_T wg_p1_CSTATE[2];            // '<S239>/wg_p1'
    real_T wg_p2_CSTATE[2];            // '<S239>/wg_p2'
    real_T vg_p1_CSTATE[2];            // '<S238>/vg_p1'
    real_T vgw_p2_CSTATE[2];           // '<S238>/vgw_p2'
    real_T ug_p_CSTATE[2];             // '<S237>/ug_p'
    real_T rgw_p_CSTATE[2];            // '<S236>/rgw_p'
    real_T qgw_p_CSTATE[2];            // '<S235>/qgw_p'
    real_T pgw_p_CSTATE[2];            // '<S234>/pgw_p'
    XDot_Distanceintogusty_Liftin_T Distanceintogustz;// '<S215>/Distance into gust (y)' 
    XDot_Distanceintogusty_Liftin_T Distanceintogusty;// '<S215>/Distance into gust (y)' 
    real_T DistanceintoGustxLimitedtogus_n;
                  // '<S218>/Distance into Gust (x) (Limited to gust length d)'
  };

  // State disabled
  struct XDis_Lifting_wing_HIL_model_d_T {
    boolean_T IntegratorSecondOrderLimited_CS[6];
                                   // '<S100>/Integrator, Second-Order Limited'
    boolean_T q0q1q2q3_CSTATE[4];      // '<S297>/q0 q1 q2 q3'
    boolean_T ubvbwb_CSTATE[3];        // '<S295>/ub,vb,wb'
    boolean_T xeyeze_CSTATE[3];        // '<S295>/xe,ye,ze'
    boolean_T pqr_CSTATE[3];           // '<S295>/p,q,r '
    boolean_T TransferFcn_CSTATE;      // '<S272>/Transfer Fcn'
    boolean_T TransferFcn1_CSTATE;     // '<S272>/Transfer Fcn1'
    boolean_T TransferFcn2_CSTATE;     // '<S272>/Transfer Fcn2'
    boolean_T TransferFcn3_CSTATE;     // '<S273>/Transfer Fcn3'
    boolean_T TransferFcn4_CSTATE;     // '<S273>/Transfer Fcn4'
    boolean_T TransferFcn5_CSTATE;     // '<S273>/Transfer Fcn5'
    boolean_T Integrator_CSTATE[3];    // '<S89>/Integrator'
    boolean_T IntegratorSecondOrderLimited__f[6];
                                   // '<S166>/Integrator, Second-Order Limited'
    boolean_T Integrator1_CSTATE[3];   // '<S93>/Integrator1'
    boolean_T Integrator1_CSTATE_m;    // '<S90>/Integrator1'
    boolean_T TransferFcn4_CSTATE_l;   // '<S127>/Transfer Fcn4'
    boolean_T TransferFcn1_CSTATE_o;   // '<S127>/Transfer Fcn1'
    boolean_T TransferFcn2_CSTATE_j;   // '<S127>/Transfer Fcn2'
    boolean_T IntegratorSecondOrderLimited_fi[6];
                                   // '<S113>/Integrator, Second-Order Limited'
    boolean_T Integrator1_CSTATE_f[3]; // '<S89>/Integrator1'
    boolean_T Integrator_CSTATE_l[3];  // '<S92>/Integrator'
    boolean_T IntegratorSecondOrderLimited__j[6];
                                   // '<S163>/Integrator, Second-Order Limited'
    boolean_T Integrator1_CSTATE_d[3]; // '<S92>/Integrator1'
    boolean_T Integrator_CSTATE_n[3];  // '<S93>/Integrator'
    boolean_T Integrator_CSTATE_o[3];  // '<S272>/Integrator'
    boolean_T Integrator1_CSTATE_e[3]; // '<S273>/Integrator1'
    boolean_T wg_p1_CSTATE[2];         // '<S239>/wg_p1'
    boolean_T wg_p2_CSTATE[2];         // '<S239>/wg_p2'
    boolean_T vg_p1_CSTATE[2];         // '<S238>/vg_p1'
    boolean_T vgw_p2_CSTATE[2];        // '<S238>/vgw_p2'
    boolean_T ug_p_CSTATE[2];          // '<S237>/ug_p'
    boolean_T rgw_p_CSTATE[2];         // '<S236>/rgw_p'
    boolean_T qgw_p_CSTATE[2];         // '<S235>/qgw_p'
    boolean_T pgw_p_CSTATE[2];         // '<S234>/pgw_p'
    XDis_Distanceintogusty_Liftin_T Distanceintogustz;// '<S215>/Distance into gust (y)' 
    XDis_Distanceintogusty_Liftin_T Distanceintogusty;// '<S215>/Distance into gust (y)' 
    boolean_T DistanceintoGustxLimitedtogus_n;
                  // '<S218>/Distance into Gust (x) (Limited to gust length d)'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_Lifting_wing_HIL_model_d_T {
    real_T inPWMs[16];                 // '<Root>/inPWMs'
    real_T TerrainZ;                   // '<Root>/TerrainZ'
    real32_T inFloatsCollision[20];    // '<Root>/inFloatsCollision'
    real32_T inSILInts[8];             // '<Root>/inSILInts'
    real32_T inSILFloats[20];          // '<Root>/inSILFloats'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_Lifting_wing_HIL_model_d_T {
    MavLinkSensor MavHILSensor;        // '<Root>/MavHILSensor'
    MavLinkStateQuat MavHILStateQuat;  // '<Root>/MavHILStateQuat'
    MavLinkGPS MavHILGPS;              // '<Root>/MavHILGPS'
    HILGPS PXIHILGPSData;              // '<Root>/PXIHILGPSData'
    MavVehileInfo MavVehile3DInfo;     // '<Root>/MavVehile3DInfo'
  };

  // Parameters for system: '<S26>/If Action Subsystem1'
  struct P_IfActionSubsystem1_Lifting__T {
    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S29>/Constant'

  };

  // Parameters for system: '<S35>/If Action Subsystem1'
  struct P_IfActionSubsystem1_Liftin_b_T {
    real_T Constant_Value;             // Expression: 0
                                          //  Referenced by: '<S38>/Constant'

  };

  // Parameters for system: '<S47>/Positive Trace'
  struct P_PositiveTrace_Lifting_wing__T {
    real_T Constant_Value;             // Expression: 1
                                          //  Referenced by: '<S49>/Constant'

    real_T Gain_Gain;                  // Expression: 0.5
                                          //  Referenced by: '<S49>/Gain'

    real_T Gain1_Gain;                 // Expression: 2
                                          //  Referenced by: '<S49>/Gain1'

  };

  // Parameters for system: '<S47>/Negative Trace'
  struct P_NegativeTrace_Lifting_wing__T {
    real_T Constant1_Value;            // Expression: 0.5
                                          //  Referenced by: '<S64>/Constant1'

    real_T Constant_Value;             // Expression: 1
                                          //  Referenced by: '<S65>/Constant'

    real_T Constant2_Value[2];         // Expression: [0 1]
                                          //  Referenced by: '<S64>/Constant2'

    real_T Switch_Threshold;           // Expression: 0
                                          //  Referenced by: '<S64>/Switch'

    real_T Gain_Gain;                  // Expression: 0.5
                                          //  Referenced by: '<S53>/Gain'

    real_T Constant1_Value_e;          // Expression: 0.5
                                          //  Referenced by: '<S69>/Constant1'

    real_T Constant_Value_n;           // Expression: 1
                                          //  Referenced by: '<S70>/Constant'

    real_T Constant2_Value_o[2];       // Expression: [0 1]
                                          //  Referenced by: '<S69>/Constant2'

    real_T Switch_Threshold_a;         // Expression: 0
                                          //  Referenced by: '<S69>/Switch'

    real_T Gain_Gain_i;                // Expression: 0.5
                                          //  Referenced by: '<S54>/Gain'

    real_T Constant1_Value_f;          // Expression: 0.5
                                          //  Referenced by: '<S59>/Constant1'

    real_T Constant_Value_i;           // Expression: 1
                                          //  Referenced by: '<S60>/Constant'

    real_T Constant2_Value_j[2];       // Expression: [0 1]
                                          //  Referenced by: '<S59>/Constant2'

    real_T Switch_Threshold_k;         // Expression: 0
                                          //  Referenced by: '<S59>/Switch'

    real_T Gain_Gain_a;                // Expression: 0.5
                                          //  Referenced by: '<S52>/Gain'

  };

  // Parameters for system: '<S50>/If Warning//Error'
  struct P_IfWarningError_Lifting_wing_T {
    real_T Constant1_Value;            // Expression: 0
                                          //  Referenced by: '<S77>/Constant1'

    real_T Constant1_Value_i;          // Expression: 0
                                          //  Referenced by: '<S75>/Constant1'

    real_T Bias_Bias;                  // Expression: -1
                                          //  Referenced by: '<S79>/Bias'

    real_T Bias1_Bias[9];              // Expression: -eye(3)
                                          //  Referenced by: '<S78>/Bias1'

    boolean_T Assertion_Enabled;       // Computed Parameter: Assertion_Enabled
                                          //  Referenced by: '<S85>/Assertion'

    boolean_T Assertion_Enabled_e;    // Computed Parameter: Assertion_Enabled_e
                                         //  Referenced by: '<S83>/Assertion'

    boolean_T Assertion_Enabled_a;    // Computed Parameter: Assertion_Enabled_a
                                         //  Referenced by: '<S82>/Assertion'

    boolean_T Assertion_Enabled_ak;  // Computed Parameter: Assertion_Enabled_ak
                                        //  Referenced by: '<S80>/Assertion'

  };

  // Parameters for system: '<S215>/Distance into gust (y)'
  struct P_Distanceintogusty_Lifting_w_T {
    real_T x_Y0;                       // Expression: [0]
                                          //  Referenced by: '<S219>/x'

    real_T DistanceintoGustxLimitedtogustl;// Expression: 0
                                              //  Referenced by: '<S219>/Distance into Gust (x) (Limited to gust length d) '

    real_T DistanceintoGustxLimitedtogus_g;// Expression: 0
                                              //  Referenced by: '<S219>/Distance into Gust (x) (Limited to gust length d) '

  };

  // Parameters (default storage)
  struct P_Lifting_wing_HIL_model_dll_T {
    real_T LW_ANGLE;                   // Variable: LW_ANGLE
                                          //  Referenced by:
                                          //    '<S170>/aerodynamic coefficients'
                                          //    '<S172>/kappa'
                                          //    '<S173>/Aerodynamics and torque'
                                          //    '<S173>/b2l'
                                          //    '<S173>/b2l1'

    real_T ModelFailWind_ConstWindX;   // Variable: ModelFailWind_ConstWindX
                                          //  Referenced by: '<S180>/ModelFailWind_ConstWindX'

    real_T ModelFailWind_ConstWindY;   // Variable: ModelFailWind_ConstWindY
                                          //  Referenced by: '<S180>/ModelFailWind_ConstWindY'

    real_T ModelFailWind_ConstWindZ;   // Variable: ModelFailWind_ConstWindZ
                                          //  Referenced by: '<S180>/ModelFailWind_ConstWindZ'

    real_T ModelFailWind_GustStartTime;// Variable: ModelFailWind_GustStartTime
                                          //  Referenced by: '<S215>/Gust start time'

    real_T ModelFailWind_GustWindAmplitude[3];
                                    // Variable: ModelFailWind_GustWindAmplitude
                                       //  Referenced by: '<S215>/Gust magnitude//2.0'

    real_T ModelInit_AngEuler[3];      // Variable: ModelInit_AngEuler
                                          //  Referenced by:
                                          //    '<S173>/MATLAB Function'
                                          //    '<S297>/Initial Euler Angles'

    real_T ModelInit_PosE[3];          // Variable: ModelInit_PosE
                                          //  Referenced by: '<S295>/xe,ye,ze'

    real_T ModelInit_Rads;             // Variable: ModelInit_Rads
                                          //  Referenced by:
                                          //    '<S277>/Init_Rads'
                                          //    '<S278>/Init_Rads'
                                          //    '<S279>/Init_Rads'
                                          //    '<S280>/Init_Rads'

    real_T ModelInit_RateB[3];         // Variable: ModelInit_RateB
                                          //  Referenced by: '<S295>/p,q,r '

    real_T ModelInit_VelB[3];          // Variable: ModelInit_VelB
                                          //  Referenced by: '<S295>/ub,vb,wb'

    real_T ModelInit_servoRads;        // Variable: ModelInit_servoRads
                                          //  Referenced by:
                                          //    '<S282>/Init_Rads'
                                          //    '<S283>/Init_Rads'

    real_T ModelParam_DeltaRatemax;    // Variable: ModelParam_DeltaRatemax
                                          //  Referenced by:
                                          //    '<S284>/Constant'
                                          //    '<S285>/Constant'

    real_T ModelParam_GPSEphFinal;     // Variable: ModelParam_GPSEphFinal
                                          //  Referenced by: '<S91>/ModelParam.GPSEphFinal'

    real_T ModelParam_GPSEpvFinal;     // Variable: ModelParam_GPSEpvFinal
                                          //  Referenced by: '<S91>/ModelParam.GPSEpvFinal'

    real_T ModelParam_GPSFix3DFix;     // Variable: ModelParam_GPSFix3DFix
                                          //  Referenced by: '<S91>/ModelParam_GPSFix3DFix'

    real_T ModelParam_GPSLatLong[2];   // Variable: ModelParam_GPSLatLong
                                          //  Referenced by:
                                          //    '<S18>/ref_position'
                                          //    '<S125>/ref_position'
                                          //    '<S177>/ref_position'

    real_T ModelParam_GPSSatsVisible;  // Variable: ModelParam_GPSSatsVisible
                                          //  Referenced by: '<S91>/ModelParam.GPSSatsVisible'

    real_T ModelParam_LBCY0;           // Variable: ModelParam_LBCY0
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBCYB;           // Variable: ModelParam_LBCYB
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBCl0;           // Variable: ModelParam_LBCl0
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBClB;           // Variable: ModelParam_LBClB
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBCl_d;          // Variable: ModelParam_LBCl_d
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBClp;           // Variable: ModelParam_LBClp
                                          //  Referenced by:
                                          //    '<S170>/aerodynamic coefficients'
                                          //    '<S173>/Aerodynamics and torque'

    real_T ModelParam_LBCm_d;          // Variable: ModelParam_LBCm_d
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBCmq;           // Variable: ModelParam_LBCmq
                                          //  Referenced by:
                                          //    '<S170>/aerodynamic coefficients'
                                          //    '<S173>/Aerodynamics and torque'

    real_T ModelParam_LBCn0;           // Variable: ModelParam_LBCn0
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBCnB;           // Variable: ModelParam_LBCnB
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBCn_d;          // Variable: ModelParam_LBCn_d
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_LBCnr;           // Variable: ModelParam_LBCnr
                                          //  Referenced by:
                                          //    '<S170>/aerodynamic coefficients'
                                          //    '<S173>/Aerodynamics and torque'

    real_T ModelParam_LBRho;           // Variable: ModelParam_LBRho
                                          //  Referenced by:
                                          //    '<S173>/Aerodynamics and torque'
                                          //    '<S181>/airDensity'

    real_T ModelParam_LBS;             // Variable: ModelParam_LBS
                                          //  Referenced by: '<S173>/Aerodynamics and torque'

    real_T ModelParam_LBb;             // Variable: ModelParam_LBb
                                          //  Referenced by:
                                          //    '<S170>/aerodynamic coefficients'
                                          //    '<S173>/Aerodynamics and torque'

    real_T ModelParam_LBc;             // Variable: ModelParam_LBc
                                          //  Referenced by:
                                          //    '<S170>/aerodynamic coefficients'
                                          //    '<S173>/Aerodynamics and torque'

    real_T ModelParam_efficiency;      // Variable: ModelParam_efficiency
                                          //  Referenced by:
                                          //    '<S174>/throttle2rads'
                                          //    '<S174>/throttle2rads1'
                                          //    '<S174>/throttle2rads2'
                                          //    '<S174>/throttle2rads3'

    real_T ModelParam_envAltitude;     // Variable: ModelParam_envAltitude
                                          //  Referenced by:
                                          //    '<S14>/ModelParam_envAltitude'
                                          //    '<S91>/ModelParam_envAltitude'
                                          //    '<S172>/envAltitude'

    real_T ModelParam_lDeltamax;       // Variable: ModelParam_lDeltamax
                                          //  Referenced by: '<S287>/Constant'

    real_T ModelParam_lDeltamin;       // Variable: ModelParam_lDeltamin
                                          //  Referenced by: '<S287>/Constant1'

    real_T ModelParam_motorJm;         // Variable: ModelParam_motorJm
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_motorT;          // Variable: ModelParam_motorT
                                          //  Referenced by:
                                          //    '<S277>/motorT'
                                          //    '<S278>/motorT'
                                          //    '<S279>/motorT'
                                          //    '<S280>/motorT'

    real_T ModelParam_motorUp1;        // Variable: ModelParam_motorUp1
                                          //  Referenced by: '<S174>/throttle2rads'

    real_T ModelParam_motorUp2;        // Variable: ModelParam_motorUp2
                                          //  Referenced by: '<S174>/throttle2rads'

    real_T ModelParam_motorUp3;        // Variable: ModelParam_motorUp3
                                          //  Referenced by: '<S174>/throttle2rads'

    real_T ModelParam_motorp1;         // Variable: ModelParam_motorp1
                                          //  Referenced by:
                                          //    '<S174>/throttle2rads1'
                                          //    '<S174>/throttle2rads2'
                                          //    '<S174>/throttle2rads3'

    real_T ModelParam_motorp2;         // Variable: ModelParam_motorp2
                                          //  Referenced by:
                                          //    '<S174>/throttle2rads1'
                                          //    '<S174>/throttle2rads2'
                                          //    '<S174>/throttle2rads3'

    real_T ModelParam_motorp3;         // Variable: ModelParam_motorp3
                                          //  Referenced by:
                                          //    '<S174>/throttle2rads1'
                                          //    '<S174>/throttle2rads2'
                                          //    '<S174>/throttle2rads3'

    real_T ModelParam_noiseAccelBa[3]; // Variable: ModelParam_noiseAccelBa
                                          //  Referenced by: '<S89>/Random Number1'

    real_T ModelParam_noiseAccelBaSeed[3];// Variable: ModelParam_noiseAccelBaSeed
                                             //  Referenced by: '<S89>/Random Number1'

    real_T ModelParam_noiseAccelNa[3]; // Variable: ModelParam_noiseAccelNa
                                          //  Referenced by: '<S89>/Random Number'

    real_T ModelParam_noiseAccelNaSeed[3];// Variable: ModelParam_noiseAccelNaSeed
                                             //  Referenced by: '<S89>/Random Number'

    real_T ModelParam_noiseBaroNbm;    // Variable: ModelParam_noiseBaroNbm
                                          //  Referenced by: '<S90>/Random Number2'

    real_T ModelParam_noiseBaroNbmSeed;// Variable: ModelParam_noiseBaroNbmSeed
                                          //  Referenced by: '<S90>/Random Number2'

    real_T ModelParam_noiseBaroNm;     // Variable: ModelParam_noiseBaroNm
                                          //  Referenced by: '<S90>/Random Number1'

    real_T ModelParam_noiseBaroNmSeed; // Variable: ModelParam_noiseBaroNmSeed
                                          //  Referenced by: '<S90>/Random Number1'

    real_T ModelParam_noiseFBa[3];     // Variable: ModelParam_noiseFBa
                                          //  Referenced by:
                                          //    '<S272>/Random Number1'
                                          //    '<S273>/Random Number3'

    real_T ModelParam_noiseFBaSeed[3]; // Variable: ModelParam_noiseFBaSeed
                                          //  Referenced by:
                                          //    '<S272>/Random Number1'
                                          //    '<S273>/Random Number3'

    real_T ModelParam_noiseFNa[3];     // Variable: ModelParam_noiseFNa
                                          //  Referenced by: '<S272>/Random Number'

    real_T ModelParam_noiseFNaSeed[3]; // Variable: ModelParam_noiseFNaSeed
                                          //  Referenced by: '<S272>/Random Number'

    real_T ModelParam_noiseGyroNbg[3]; // Variable: ModelParam_noiseGyroNbg
                                          //  Referenced by: '<S92>/Random Number1'

    real_T ModelParam_noiseGyroNbgSeed[3];// Variable: ModelParam_noiseGyroNbgSeed
                                             //  Referenced by: '<S92>/Random Number1'

    real_T ModelParam_noiseGyroNg[3];  // Variable: ModelParam_noiseGyroNg
                                          //  Referenced by: '<S92>/Random Number'

    real_T ModelParam_noiseGyroNgSeed[3];// Variable: ModelParam_noiseGyroNgSeed
                                            //  Referenced by: '<S92>/Random Number'

    real_T ModelParam_noiseMNa[3];     // Variable: ModelParam_noiseMNa
                                          //  Referenced by: '<S273>/Random Number2'

    real_T ModelParam_noiseMNaSeed[3]; // Variable: ModelParam_noiseMNaSeed
                                          //  Referenced by: '<S273>/Random Number2'

    real_T ModelParam_noiseMagNm[3];   // Variable: ModelParam_noiseMagNm
                                          //  Referenced by:
                                          //    '<S93>/Random Number'
                                          //    '<S93>/Random Number1'

    real_T ModelParam_noiseMagNmSeed[3];// Variable: ModelParam_noiseMagNmSeed
                                           //  Referenced by: '<S93>/Random Number'

    real_T ModelParam_propellerkM0;    // Variable: ModelParam_propellerkM0
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkMV;    // Variable: ModelParam_propellerkMV
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkMV2;   // Variable: ModelParam_propellerkMV2
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkMvarpi;// Variable: ModelParam_propellerkMvarpi
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkMvarpi2;// Variable: ModelParam_propellerkMvarpi2
                                           //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkMvarpiV;// Variable: ModelParam_propellerkMvarpiV
                                           //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkT0;    // Variable: ModelParam_propellerkT0
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkTV;    // Variable: ModelParam_propellerkTV
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkTV2;   // Variable: ModelParam_propellerkTV2
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkTvarpi;// Variable: ModelParam_propellerkTvarpi
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkTvarpi2;// Variable: ModelParam_propellerkTvarpi2
                                           //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_propellerkTvarpiV;// Variable: ModelParam_propellerkTvarpiV
                                           //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_pu_alpha0;       // Variable: ModelParam_pu_alpha0
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_breaks[1000]; // Variable: ModelParam_pu_breaks
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_c0;           // Variable: ModelParam_pu_c0
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_c1;           // Variable: ModelParam_pu_c1
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_c2;           // Variable: ModelParam_pu_c2
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_c3;           // Variable: ModelParam_pu_c3
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_cl0;          // Variable: ModelParam_pu_cl0
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_coefs[3996];  // Variable: ModelParam_pu_coefs
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_kD;           // Variable: ModelParam_pu_kD
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_pu_kL;           // Variable: ModelParam_pu_kL
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    real_T ModelParam_rDeltamax;       // Variable: ModelParam_rDeltamax
                                          //  Referenced by: '<S286>/Constant'

    real_T ModelParam_rDeltamin;       // Variable: ModelParam_rDeltamin
                                          //  Referenced by: '<S286>/Constant1'

    real_T ModelParam_rotorCm;         // Variable: ModelParam_rotorCm
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_rotorCt;         // Variable: ModelParam_rotorCt
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_rotorEta;        // Variable: ModelParam_rotorEta
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_rotordx;         // Variable: ModelParam_rotordx
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_rotordy;         // Variable: ModelParam_rotordy
                                          //  Referenced by: '<S173>/Propeller Model'

    real_T ModelParam_servoT;          // Variable: ModelParam_servoT
                                          //  Referenced by:
                                          //    '<S282>/motorT'
                                          //    '<S283>/motorT'

    real_T ModelParam_temperature;     // Variable: ModelParam_temperature
                                          //  Referenced by: '<S181>/Constant2'

    real_T ModelParam_uavCCm[3];       // Variable: ModelParam_uavCCm
                                          //  Referenced by: '<S173>/Aerodynamics and torque'

    real_T ModelParam_uavCd[3];        // Variable: ModelParam_uavCd
                                          //  Referenced by: '<S173>/Aerodynamics and torque'

    real_T ModelParam_uavJ[9];         // Variable: ModelParam_uavJ
                                          //  Referenced by: '<S299>/Constant1'

    real_T ModelParam_uavMass;         // Variable: ModelParam_uavMass
                                          //  Referenced by:
                                          //    '<Root>/uavMass'
                                          //    '<S173>/Mass'
                                          //    '<S299>/Constant'

    boolean_T ModelFailEnable;         // Variable: ModelFailEnable
                                          //  Referenced by: '<S12>/ModelFailEnable'

    boolean_T ModelFailWind_isConstWind;// Variable: ModelFailWind_isConstWind
                                           //  Referenced by: '<S180>/Constant4'

    boolean_T ModelFailWind_isEnable;  // Variable: ModelFailWind_isEnable
                                          //  Referenced by: '<S180>/Constant2'

    boolean_T ModelFailWind_isGustWind;// Variable: ModelFailWind_isGustWind
                                          //  Referenced by: '<S180>/Constant5'

    boolean_T ModelFailWind_isSheerWind;// Variable: ModelFailWind_isSheerWind
                                           //  Referenced by: '<S180>/Constant1'

    boolean_T ModelFailWind_isTurbWind;// Variable: ModelFailWind_isTurbWind
                                          //  Referenced by: '<S180>/Constant3'

    boolean_T ModelParam_use_CoesaAtmosphereModel_density;
                        // Variable: ModelParam_use_CoesaAtmosphereModel_density
                           //  Referenced by: '<S181>/airDensity1'

    boolean_T ModelParam_use_CoesaAtmosphereModel_temperature;
                    // Variable: ModelParam_use_CoesaAtmosphereModel_temperature
                       //  Referenced by: '<S181>/Constant1'

    boolean_T USE_AeroCoefficient;     // Variable: USE_AeroCoefficient
                                          //  Referenced by: '<S173>/Aerodynamics and torque'

    boolean_T USE_PROPELLER_MODEL1;    // Variable: USE_PROPELLER_MODEL1
                                          //  Referenced by: '<S173>/Propeller Model'

    int8_T AERO_COEFFICIENT;           // Variable: AERO_COEFFICIENT
                                          //  Referenced by: '<S170>/aerodynamic coefficients'

    int8_T ModelParam_uavType;         // Variable: ModelParam_uavType
                                          //  Referenced by: '<S16>/UAVType'

    real_T DrydenWindTurbulenceModelContin;
                              // Mask Parameter: DrydenWindTurbulenceModelContin
                                 //  Referenced by: '<S259>/Medium//High Altitude'

    real_T DrydenWindTurbulenceModelCont_a[4];
                              // Mask Parameter: DrydenWindTurbulenceModelCont_a
                                 //  Referenced by: '<S233>/White Noise'

    real_T DrydenWindTurbulenceModelCont_b;
                              // Mask Parameter: DrydenWindTurbulenceModelCont_b
                                 //  Referenced by:
                                 //    '<S223>/Constant1'
                                 //    '<S223>/Constant2'
                                 //    '<S223>/Constant3'
                                 //    '<S224>/Constant'

    real_T WhiteNoise_Ts;              // Mask Parameter: WhiteNoise_Ts
                                          //  Referenced by: '<S233>/Constant1'

    real_T DrydenWindTurbulenceModelCont_p;
                              // Mask Parameter: DrydenWindTurbulenceModelCont_p
                                 //  Referenced by: '<S240>/Probability of  Exceedance'

    real_T DrydenWindTurbulenceModelCont_c;
                              // Mask Parameter: DrydenWindTurbulenceModelCont_c
                                 //  Referenced by: '<S216>/Windspeed at 20ft (6m)'

    real_T WindShearModel_W_20;        // Mask Parameter: WindShearModel_W_20
                                          //  Referenced by: '<S217>/Wind speed at reference height'

    real_T DrydenWindTurbulenceModelCont_l;
                              // Mask Parameter: DrydenWindTurbulenceModelCont_l
                                 //  Referenced by: '<S216>/Wind direction'

    real_T WindShearModel_Wdeg;        // Mask Parameter: WindShearModel_Wdeg
                                          //  Referenced by: '<S217>/Wind Direction'

    real_T DrydenWindTurbulenceModelCont_g;
                              // Mask Parameter: DrydenWindTurbulenceModelCont_g
                                 //  Referenced by: '<S216>/Wingspan'

    real_T ThreeaxisAccelerometer0_a_bias[3];
                               // Mask Parameter: ThreeaxisAccelerometer0_a_bias
                                  //  Referenced by: '<S94>/Measurement bias'

    real_T ThreeaxisAccelerometer1_a_bias[3];
                               // Mask Parameter: ThreeaxisAccelerometer1_a_bias
                                  //  Referenced by: '<S95>/Measurement bias'

    real_T ThreeaxisAccelerometer0_a_sf_cc[9];
                              // Mask Parameter: ThreeaxisAccelerometer0_a_sf_cc
                                 //  Referenced by: '<S94>/Scale factors & Cross-coupling  errors'

    real_T ThreeaxisAccelerometer1_a_sf_cc[9];
                              // Mask Parameter: ThreeaxisAccelerometer1_a_sf_cc
                                 //  Referenced by: '<S95>/Scale factors & Cross-coupling  errors'

    real_T ThreeaxisAccelerometer0_acc[3];
                                  // Mask Parameter: ThreeaxisAccelerometer0_acc
                                     //  Referenced by: '<S94>/wl_ins'

    real_T ThreeaxisAccelerometer1_acc[3];
                                  // Mask Parameter: ThreeaxisAccelerometer1_acc
                                     //  Referenced by: '<S95>/wl_ins'

    real_T COESAAtmosphereModel_action;
                                  // Mask Parameter: COESAAtmosphereModel_action
                                     //  Referenced by: '<S263>/S-Function'

    real_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S202>/Constant'

    real_T CompareToConstant_const_l;
                                    // Mask Parameter: CompareToConstant_const_l
                                       //  Referenced by: '<S197>/Constant'

    real_T CompareToConstant_const_f;
                                    // Mask Parameter: CompareToConstant_const_f
                                       //  Referenced by: '<S203>/Constant'

    real_T CompareToConstant_const_h;
                                    // Mask Parameter: CompareToConstant_const_h
                                       //  Referenced by: '<S193>/Constant'

    real_T CompareToConstant_const_j;
                                    // Mask Parameter: CompareToConstant_const_j
                                       //  Referenced by: '<S188>/Constant'

    real_T CompareToConstant_const_d;
                                    // Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S194>/Constant'

    real_T CompareToConstant_const_b;
                                    // Mask Parameter: CompareToConstant_const_b
                                       //  Referenced by: '<S39>/Constant'

    real_T CompareToConstant_const_c;
                                    // Mask Parameter: CompareToConstant_const_c
                                       //  Referenced by: '<S34>/Constant'

    real_T CompareToConstant_const_e;
                                    // Mask Parameter: CompareToConstant_const_e
                                       //  Referenced by: '<S40>/Constant'

    real_T CompareToConstant_const_p;
                                    // Mask Parameter: CompareToConstant_const_p
                                       //  Referenced by: '<S30>/Constant'

    real_T CompareToConstant_const_o;
                                    // Mask Parameter: CompareToConstant_const_o
                                       //  Referenced by: '<S25>/Constant'

    real_T CompareToConstant_const_h3;
                                   // Mask Parameter: CompareToConstant_const_h3
                                      //  Referenced by: '<S31>/Constant'

    real_T CompareToConstant_const_i;
                                    // Mask Parameter: CompareToConstant_const_i
                                       //  Referenced by: '<S148>/Constant'

    real_T CompareToConstant_const_lb;
                                   // Mask Parameter: CompareToConstant_const_lb
                                      //  Referenced by: '<S143>/Constant'

    real_T CompareToConstant_const_jt;
                                   // Mask Parameter: CompareToConstant_const_jt
                                      //  Referenced by: '<S149>/Constant'

    real_T CompareToConstant_const_hj;
                                   // Mask Parameter: CompareToConstant_const_hj
                                      //  Referenced by: '<S139>/Constant'

    real_T CompareToConstant_const_fd;
                                   // Mask Parameter: CompareToConstant_const_fd
                                      //  Referenced by: '<S134>/Constant'

    real_T CompareToConstant_const_hi;
                                   // Mask Parameter: CompareToConstant_const_hi
                                      //  Referenced by: '<S140>/Constant'

    real_T Distanceintogustx_d_m;      // Mask Parameter: Distanceintogustx_d_m
                                          //  Referenced by: '<S218>/Distance into Gust (x) (Limited to gust length d)'

    real_T Distanceintogusty_d_m;      // Mask Parameter: Distanceintogusty_d_m
                                          //  Referenced by: '<S215>/Distance into gust (y)'

    real_T Distanceintogustz_d_m;      // Mask Parameter: Distanceintogustz_d_m
                                          //  Referenced by: '<S215>/Distance into gust (z)'

    real_T DiscreteWindGustModel_d_m[3];
                                    // Mask Parameter: DiscreteWindGustModel_d_m
                                       //  Referenced by: '<S215>/pi//Gust length'

    real_T ThreeaxisGyroscope1_g_bias[3];
                                   // Mask Parameter: ThreeaxisGyroscope1_g_bias
                                      //  Referenced by: '<S160>/Measurement bias'

    real_T ThreeaxisGyroscope0_g_bias[3];
                                   // Mask Parameter: ThreeaxisGyroscope0_g_bias
                                      //  Referenced by: '<S159>/Measurement bias'

    real_T ThreeaxisGyroscope1_g_sen[3];
                                    // Mask Parameter: ThreeaxisGyroscope1_g_sen
                                       //  Referenced by: '<S160>/g-sensitive bias'

    real_T ThreeaxisGyroscope0_g_sen[3];
                                    // Mask Parameter: ThreeaxisGyroscope0_g_sen
                                       //  Referenced by: '<S159>/g-sensitive bias'

    real_T ThreeaxisGyroscope1_g_sf_cc[9];
                                  // Mask Parameter: ThreeaxisGyroscope1_g_sf_cc
                                     //  Referenced by: '<S160>/Scale factors & Cross-coupling  errors '

    real_T ThreeaxisGyroscope0_g_sf_cc[9];
                                  // Mask Parameter: ThreeaxisGyroscope0_g_sf_cc
                                     //  Referenced by: '<S159>/Scale factors & Cross-coupling  errors '

    real_T uDOFQuaternion_k_quat;      // Mask Parameter: uDOFQuaternion_k_quat
                                          //  Referenced by: '<S308>/High Gain Quaternion Normalization'

    real_T FlatEarthtoLLA_psi;         // Mask Parameter: FlatEarthtoLLA_psi
                                          //  Referenced by: '<S177>/ref_rotation'

    real_T FlatEarthtoLLA_psi_a;       // Mask Parameter: FlatEarthtoLLA_psi_a
                                          //  Referenced by: '<S18>/ref_rotation'

    real_T FlatEarthtoLLA_psi_m;       // Mask Parameter: FlatEarthtoLLA_psi_m
                                          //  Referenced by: '<S125>/ref_rotation'

    real_T WhiteNoise_pwr[4];          // Mask Parameter: WhiteNoise_pwr
                                          //  Referenced by: '<S233>/Constant'

    real_T DirectionCosineMatrixtoQuaterni;
                              // Mask Parameter: DirectionCosineMatrixtoQuaterni
                                 //  Referenced by: '<S50>/If Warning//Error'

    real_T DirectionCosineMatrixtoQuater_f;
                              // Mask Parameter: DirectionCosineMatrixtoQuater_f
                                 //  Referenced by: '<S339>/If Warning//Error'

    real_T ThreeaxisAccelerometer0_w_a;
                                  // Mask Parameter: ThreeaxisAccelerometer0_w_a
                                     //  Referenced by:
                                     //    '<S100>/2*zeta * wn'
                                     //    '<S100>/wn^2'

    real_T ThreeaxisAccelerometer1_w_a;
                                  // Mask Parameter: ThreeaxisAccelerometer1_w_a
                                     //  Referenced by:
                                     //    '<S113>/2*zeta * wn'
                                     //    '<S113>/wn^2'

    real_T ThreeaxisGyroscope0_w_g;   // Mask Parameter: ThreeaxisGyroscope0_w_g
                                         //  Referenced by:
                                         //    '<S163>/2*zeta * wn'
                                         //    '<S163>/wn^2'

    real_T ThreeaxisGyroscope1_w_g;   // Mask Parameter: ThreeaxisGyroscope1_w_g
                                         //  Referenced by:
                                         //    '<S166>/2*zeta * wn'
                                         //    '<S166>/wn^2'

    real_T ThreeaxisAccelerometer0_z_a;
                                  // Mask Parameter: ThreeaxisAccelerometer0_z_a
                                     //  Referenced by: '<S100>/2*zeta * wn'

    real_T ThreeaxisAccelerometer1_z_a;
                                  // Mask Parameter: ThreeaxisAccelerometer1_z_a
                                     //  Referenced by: '<S113>/2*zeta * wn'

    real_T ThreeaxisGyroscope0_z_g;   // Mask Parameter: ThreeaxisGyroscope0_z_g
                                         //  Referenced by: '<S163>/2*zeta * wn'

    real_T ThreeaxisGyroscope1_z_g;   // Mask Parameter: ThreeaxisGyroscope1_z_g
                                         //  Referenced by: '<S166>/2*zeta * wn'

    boolean_T DiscreteWindGustModel_Gx;
                                     // Mask Parameter: DiscreteWindGustModel_Gx
                                        //  Referenced by: '<S215>/Constant'

    boolean_T DiscreteWindGustModel_Gy;
                                     // Mask Parameter: DiscreteWindGustModel_Gy
                                        //  Referenced by: '<S215>/Constant1'

    boolean_T DiscreteWindGustModel_Gz;
                                     // Mask Parameter: DiscreteWindGustModel_Gz
                                        //  Referenced by: '<S215>/Constant2'

    boolean_T CompareToConstant_const_a;
                                    // Mask Parameter: CompareToConstant_const_a
                                       //  Referenced by: '<S210>/Constant'

    boolean_T CompareToConstant1_const;
                                     // Mask Parameter: CompareToConstant1_const
                                        //  Referenced by: '<S211>/Constant'

    boolean_T CompareToConstant2_const;
                                     // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S212>/Constant'

    boolean_T CompareToConstant3_const;
                                     // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S213>/Constant'

    boolean_T CompareToConstant4_const;
                                     // Mask Parameter: CompareToConstant4_const
                                        //  Referenced by: '<S214>/Constant'

    uint8_T DirectionCosineMatrixtoQuater_a;
                              // Mask Parameter: DirectionCosineMatrixtoQuater_a
                                 //  Referenced by:
                                 //    '<S50>/If Warning//Error'
                                 //    '<S50>/Constant'

    uint8_T DirectionCosineMatrixtoQuater_n;
                              // Mask Parameter: DirectionCosineMatrixtoQuater_n
                                 //  Referenced by:
                                 //    '<S339>/If Warning//Error'
                                 //    '<S339>/Constant'

    real_T Bias_Bias;                  // Expression: -90
                                          //  Referenced by: '<S23>/Bias'

    real_T Gain_Gain;                  // Expression: -1
                                          //  Referenced by: '<S23>/Gain'

    real_T Bias1_Bias;                 // Expression: +90
                                          //  Referenced by: '<S23>/Bias1'

    real_T Bias_Bias_d;                // Expression: 180
                                          //  Referenced by: '<S27>/Bias'

    real_T Bias1_Bias_l;               // Expression: -180
                                          //  Referenced by: '<S27>/Bias1'

    real_T Bias_Bias_g;                // Expression: 180
                                          //  Referenced by: '<S24>/Bias'

    real_T Bias1_Bias_c;               // Expression: -180
                                          //  Referenced by: '<S24>/Bias1'

    real_T Bias_Bias_e;                // Expression: -90
                                          //  Referenced by: '<S32>/Bias'

    real_T Gain_Gain_k;                // Expression: -1
                                          //  Referenced by: '<S32>/Gain'

    real_T Bias1_Bias_n;               // Expression: +90
                                          //  Referenced by: '<S32>/Bias1'

    real_T Constant2_Value;            // Expression: 360
                                          //  Referenced by: '<S36>/Constant2'

    real_T Bias_Bias_j;                // Expression: 180
                                          //  Referenced by: '<S36>/Bias'

    real_T Bias1_Bias_o;               // Expression: -180
                                          //  Referenced by: '<S36>/Bias1'

    real_T Constant_Value;             // Expression: 180
                                          //  Referenced by: '<S20>/Constant'

    real_T Constant1_Value;            // Expression: 0
                                          //  Referenced by: '<S20>/Constant1'

    real_T Constant2_Value_b;          // Expression: 360
                                          //  Referenced by: '<S33>/Constant2'

    real_T Bias_Bias_n;                // Expression: 180
                                          //  Referenced by: '<S33>/Bias'

    real_T Bias1_Bias_nx;              // Expression: -180
                                          //  Referenced by: '<S33>/Bias1'

    real_T Bias_Bias_c;                // Expression: -90
                                          //  Referenced by: '<S132>/Bias'

    real_T Gain_Gain_m;                // Expression: -1
                                          //  Referenced by: '<S132>/Gain'

    real_T Bias1_Bias_f;               // Expression: +90
                                          //  Referenced by: '<S132>/Bias1'

    real_T Bias_Bias_h;                // Expression: 180
                                          //  Referenced by: '<S136>/Bias'

    real_T Bias1_Bias_h;               // Expression: -180
                                          //  Referenced by: '<S136>/Bias1'

    real_T Bias_Bias_c1;               // Expression: 180
                                          //  Referenced by: '<S133>/Bias'

    real_T Bias1_Bias_nn;              // Expression: -180
                                          //  Referenced by: '<S133>/Bias1'

    real_T Bias_Bias_f;                // Expression: -90
                                          //  Referenced by: '<S141>/Bias'

    real_T Gain_Gain_l;                // Expression: -1
                                          //  Referenced by: '<S141>/Gain'

    real_T Bias1_Bias_o3;              // Expression: +90
                                          //  Referenced by: '<S141>/Bias1'

    real_T Constant2_Value_bi;         // Expression: 360
                                          //  Referenced by: '<S145>/Constant2'

    real_T Bias_Bias_j1;               // Expression: 180
                                          //  Referenced by: '<S145>/Bias'

    real_T Bias1_Bias_k;               // Expression: -180
                                          //  Referenced by: '<S145>/Bias1'

    real_T Constant_Value_a;           // Expression: 180
                                          //  Referenced by: '<S129>/Constant'

    real_T Constant1_Value_b;          // Expression: 0
                                          //  Referenced by: '<S129>/Constant1'

    real_T Constant2_Value_m;          // Expression: 360
                                          //  Referenced by: '<S142>/Constant2'

    real_T Bias_Bias_hi;               // Expression: 180
                                          //  Referenced by: '<S142>/Bias'

    real_T Bias1_Bias_j;               // Expression: -180
                                          //  Referenced by: '<S142>/Bias1'

    real_T Bias_Bias_c0;               // Expression: -90
                                          //  Referenced by: '<S186>/Bias'

    real_T Gain_Gain_m0;               // Expression: -1
                                          //  Referenced by: '<S186>/Gain'

    real_T Bias1_Bias_i;               // Expression: +90
                                          //  Referenced by: '<S186>/Bias1'

    real_T Bias_Bias_b;                // Expression: 180
                                          //  Referenced by: '<S190>/Bias'

    real_T Bias1_Bias_kx;              // Expression: -180
                                          //  Referenced by: '<S190>/Bias1'

    real_T Bias_Bias_jv;               // Expression: 180
                                          //  Referenced by: '<S187>/Bias'

    real_T Bias1_Bias_b;               // Expression: -180
                                          //  Referenced by: '<S187>/Bias1'

    real_T Bias_Bias_gl;               // Expression: -90
                                          //  Referenced by: '<S195>/Bias'

    real_T Gain_Gain_p;                // Expression: -1
                                          //  Referenced by: '<S195>/Gain'

    real_T Bias1_Bias_bq;              // Expression: +90
                                          //  Referenced by: '<S195>/Bias1'

    real_T Constant2_Value_a;          // Expression: 360
                                          //  Referenced by: '<S199>/Constant2'

    real_T Bias_Bias_bb;               // Expression: 180
                                          //  Referenced by: '<S199>/Bias'

    real_T Bias1_Bias_e;               // Expression: -180
                                          //  Referenced by: '<S199>/Bias1'

    real_T Constant_Value_j;           // Expression: 180
                                          //  Referenced by: '<S183>/Constant'

    real_T Constant1_Value_l;          // Expression: 0
                                          //  Referenced by: '<S183>/Constant1'

    real_T Constant2_Value_o;          // Expression: 360
                                          //  Referenced by: '<S196>/Constant2'

    real_T Bias_Bias_a;                // Expression: 180
                                          //  Referenced by: '<S196>/Bias'

    real_T Bias1_Bias_kz;              // Expression: -180
                                          //  Referenced by: '<S196>/Bias1'

    real_T x_Y0;                       // Expression: [0]
                                          //  Referenced by: '<S218>/x'

    real_T DistanceintoGustxLimitedtogustl;// Expression: 0
                                              //  Referenced by: '<S218>/Distance into Gust (x) (Limited to gust length d)'

    real_T DistanceintoGustxLimitedtogus_g;// Expression: 0
                                              //  Referenced by: '<S218>/Distance into Gust (x) (Limited to gust length d)'

    real_T pgw_Y0;                     // Expression: 0
                                          //  Referenced by: '<S234>/pgw'

    real_T Constant1_Value_c;          // Expression: 1/3
                                          //  Referenced by: '<S234>/Constant1'

    real_T Constant2_Value_c;          // Expression: 1/6
                                          //  Referenced by: '<S234>/Constant2'

    real_T Constant3_Value;            // Expression: pi/4
                                          //  Referenced by: '<S234>/Constant3'

    real_T pgw_p_IC;                   // Expression: 0
                                          //  Referenced by: '<S234>/pgw_p'

    real_T qgw_Y0;                     // Expression: 0
                                          //  Referenced by: '<S235>/qgw'

    real_T qgw_p_IC;                   // Expression: 0
                                          //  Referenced by: '<S235>/qgw_p'

    real_T pi4_Gain;                   // Expression: pi/4
                                          //  Referenced by: '<S235>/pi//4'

    real_T rgw_Y0;                     // Expression: 0
                                          //  Referenced by: '<S236>/rgw'

    real_T rgw_p_IC;                   // Expression: 0
                                          //  Referenced by: '<S236>/rgw_p'

    real_T pi3_Gain;                   // Expression: pi/3
                                          //  Referenced by: '<S236>/pi//3'

    real_T ugw_Y0;                     // Expression: 0
                                          //  Referenced by: '<S237>/ugw'

    real_T upi_Gain;                   // Expression: 2/pi
                                          //  Referenced by: '<S237>/(2//pi)'

    real_T ug_p_IC;                    // Expression: 0
                                          //  Referenced by: '<S237>/ug_p'

    real_T vgw_Y0;                     // Expression: 0
                                          //  Referenced by: '<S238>/vgw'

    real_T upi_Gain_l;                 // Expression: 1/pi
                                          //  Referenced by: '<S238>/(1//pi)'

    real_T vg_p1_IC;                   // Expression: 0
                                          //  Referenced by: '<S238>/vg_p1'

    real_T vgw_p2_IC;                  // Expression: 0
                                          //  Referenced by: '<S238>/vgw_p2'

    real_T sqrt3_Gain;                 // Expression: sqrt(3)
                                          //  Referenced by: '<S238>/sqrt(3)'

    real_T wgw_Y0;                     // Expression: 0
                                          //  Referenced by: '<S239>/wgw'

    real_T upi_Gain_g;                 // Expression: 1/pi
                                          //  Referenced by: '<S239>/1//pi'

    real_T Constant_Value_l;           // Expression: 3
                                          //  Referenced by: '<S239>/Constant'

    real_T wg_p1_IC;                   // Expression: 0
                                          //  Referenced by: '<S239>/wg_p1'

    real_T wg_p2_IC;                   // Expression: 0
                                          //  Referenced by: '<S239>/wg_p2'

    real_T Gain_Gain_kz;               // Expression: 1
                                          //  Referenced by: '<S244>/Gain'

    real_T max_height_low_Value;       // Expression: max_height_low
                                          //  Referenced by: '<S242>/max_height_low'

    real_T min_height_high_Value;      // Expression: min_height_high
                                          //  Referenced by: '<S242>/min_height_high'

    real_T Gain_Gain_l1;               // Expression: 1
                                          //  Referenced by: '<S252>/Gain'

    real_T max_height_low_Value_g;     // Expression: max_height_low
                                          //  Referenced by: '<S250>/max_height_low'

    real_T min_height_high_Value_h;    // Expression: min_height_high
                                          //  Referenced by: '<S250>/min_height_high'

    real_T Constant_Value_d;           // Expression: 10
                                          //  Referenced by: '<S180>/Constant'

    real_T Constant_DCM_Value[9];      // Expression: eye(3)
                                          //  Referenced by: '<S180>/Constant_DCM'

    real_T u_Value;                    // Expression: 1.0
                                          //  Referenced by: '<S215>/2'

    real_T LimitFunction10ftto1000ft_Upper;// Expression: max_height_low
                                              //  Referenced by: '<S258>/Limit Function 10ft to 1000ft'

    real_T LimitFunction10ftto1000ft_Lower;// Expression: 10
                                              //  Referenced by: '<S258>/Limit Function 10ft to 1000ft'

    real_T Lw_Gain;                    // Expression: 1
                                          //  Referenced by: '<S230>/Lw'

    real_T sigma_wg_Gain;              // Expression: 0.1
                                          //  Referenced by: '<S241>/sigma_wg '

    real_T PreLookUpIndexSearchaltitude_Br[12];// Expression: h_vec
                                                  //  Referenced by: '<S240>/PreLook-Up Index Search  (altitude)'

    real_T PreLookUpIndexSearchprobofexcee[7];// Expression: [1:7]
                                                 //  Referenced by: '<S240>/PreLook-Up Index Search  (prob of exceed)'

    real_T MediumHighAltitudeIntensity_Tab[84];// Expression: sigma_vec'
                                                  //  Referenced by: '<S240>/Medium//High Altitude Intensity'

    real_T WhiteNoise_Mean;            // Expression: 0
                                          //  Referenced by: '<S233>/White Noise'

    real_T WhiteNoise_StdDev;          // Computed Parameter: WhiteNoise_StdDev
                                          //  Referenced by: '<S233>/White Noise'

    real_T LimitHeighth1000ft_UpperSat;// Expression: max_height_low
                                          //  Referenced by: '<S241>/Limit Height h<1000ft'

    real_T LimitHeighth1000ft_LowerSat;// Expression: 0
                                          //  Referenced by: '<S241>/Limit Height h<1000ft'

    real_T Lv_Gain;                    // Expression: 1
                                          //  Referenced by: '<S230>/Lv'

    real_T uftinf_UpperSat;            // Expression: inf
                                          //  Referenced by: '<S217>/3ft-->inf'

    real_T uftinf_LowerSat;            // Expression: 3
                                          //  Referenced by: '<S217>/3ft-->inf'

    real_T hz0_Gain;                   // Expression: 1/z0
                                          //  Referenced by: '<S217>/h//z0'

    real_T ref_heightz0_Value;         // Expression: 20/z0
                                          //  Referenced by: '<S217>/ref_height//z0'

    real_T Wdeg1_Value;                // Expression: 0
                                          //  Referenced by: '<S217>/Wdeg1'

    real_T Constant_Value_f;           // Expression: 1
                                          //  Referenced by: '<S325>/Constant'

    real_T Constant_Value_l1;          // Expression: 1
                                          //  Referenced by: '<S326>/Constant'

    real_T Gain_clock_Gain;            // Expression: 1E6
                                          //  Referenced by: '<S5>/Gain_clock'

    real_T IntegratorSecondOrderLimited_IC;// Expression: 0
                                              //  Referenced by: '<S100>/Integrator, Second-Order Limited'

    real_T IntegratorSecondOrderLimited__h;// Expression: 0
                                              //  Referenced by: '<S100>/Integrator, Second-Order Limited'

    real_T Constant_Value_am;          // Expression: dtype_a
                                          //  Referenced by: '<S96>/Constant'

    real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S277>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_gainva_i;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_i
                             //  Referenced by: '<S278>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_gainva_g;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_g
                             //  Referenced by: '<S279>/Discrete-Time Integrator'

    real_T DiscreteTimeIntegrator_gainva_o;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_o
                             //  Referenced by: '<S280>/Discrete-Time Integrator'

    real_T u2_Gain;                    // Expression: 0.5
                                          //  Referenced by: '<S307>/1//2'

    real_T Gain_Gain_h;                // Expression: 2
                                          //  Referenced by: '<S312>/Gain'

    real_T Gain_Gain_ka;               // Expression: 2
                                          //  Referenced by: '<S315>/Gain'

    real_T Gain_Gain_b;                // Expression: 2
                                          //  Referenced by: '<S310>/Gain'

    real_T Gain_Gain_n;                // Expression: 2
                                          //  Referenced by: '<S316>/Gain'

    real_T Gain_Gain_b3;               // Expression: 2
                                          //  Referenced by: '<S311>/Gain'

    real_T Gain_Gain_lg;               // Expression: 2
                                          //  Referenced by: '<S314>/Gain'

    real_T Constant3_Value_f[3];     // Expression: [27666.94 -3533.48 47325.16]
                                        //  Referenced by: '<S181>/Constant3'

    real_T nT2Gauss_Gain;              // Expression: 1e-5
                                          //  Referenced by: '<S172>/nT2Gauss'

    real_T Constant4_Value;            // Expression: -7.28
                                          //  Referenced by: '<S181>/Constant4'

    real_T Constant1_Value_g;          // Expression: R
                                          //  Referenced by: '<S204>/Constant1'

    real_T Constant_Value_d3;          // Expression: 1
                                          //  Referenced by: '<S207>/Constant'

    real_T Constant_Value_fq;          // Expression: 1
                                          //  Referenced by: '<S209>/Constant'

    real_T Constant_Value_jl;          // Expression: F
                                          //  Referenced by: '<S208>/Constant'

    real_T f_Value;                    // Expression: 1
                                          //  Referenced by: '<S208>/f'

    real_T Merge_InitialOutput;        // Expression: 1
                                          //  Referenced by: '<S198>/Merge'

    real_T Constant_Value_p;           // Expression: 1
                                          //  Referenced by: '<S204>/Constant'

    real_T Constant2_Value_i;          // Expression: 360
                                          //  Referenced by: '<S190>/Constant2'

    real_T Merge_InitialOutput_h;      // Expression: 1
                                          //  Referenced by: '<S189>/Merge'

    real_T Constant_Value_k;           // Expression: 180
                                          //  Referenced by: '<S182>/Constant'

    real_T Constant1_Value_bq;         // Expression: 0
                                          //  Referenced by: '<S182>/Constant1'

    real_T Constant2_Value_k;          // Expression: 360
                                          //  Referenced by: '<S187>/Constant2'

    real_T Saturation_UpperSat;        // Expression: 10000
                                          //  Referenced by: '<S172>/Saturation'

    real_T Saturation_LowerSat;        // Expression: 0
                                          //  Referenced by: '<S172>/Saturation'

    real_T Merge_InitialOutput_i[4];   // Expression: [1 0 0 0]
                                          //  Referenced by: '<S296>/Merge'

    real_T DiscreteTimeIntegrator_gainva_j;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_j
                             //  Referenced by: '<S282>/Discrete-Time Integrator'

    real_T UnitDelay_InitialCondition; // Expression: 0
                                          //  Referenced by: '<S284>/Unit Delay'

    real_T DiscreteTimeIntegrator_gainva_p;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_p
                             //  Referenced by: '<S283>/Discrete-Time Integrator'

    real_T UnitDelay_InitialCondition_n;// Expression: 0
                                           //  Referenced by: '<S285>/Unit Delay'

    real_T TransferFcn_A;              // Computed Parameter: TransferFcn_A
                                          //  Referenced by: '<S272>/Transfer Fcn'

    real_T TransferFcn_C;              // Computed Parameter: TransferFcn_C
                                          //  Referenced by: '<S272>/Transfer Fcn'

    real_T TransferFcn1_A;             // Computed Parameter: TransferFcn1_A
                                          //  Referenced by: '<S272>/Transfer Fcn1'

    real_T TransferFcn1_C;             // Computed Parameter: TransferFcn1_C
                                          //  Referenced by: '<S272>/Transfer Fcn1'

    real_T TransferFcn2_A;             // Computed Parameter: TransferFcn2_A
                                          //  Referenced by: '<S272>/Transfer Fcn2'

    real_T TransferFcn2_C;             // Computed Parameter: TransferFcn2_C
                                          //  Referenced by: '<S272>/Transfer Fcn2'

    real_T ZeroOrderHold1_Gain;        // Expression: 1
                                          //  Referenced by: '<S94>/Zero-Order Hold1'

    real_T ZeroOrderHold2_Gain;        // Expression: 1
                                          //  Referenced by: '<S94>/Zero-Order Hold2'

    real_T ZeroOrderHold_Gain;         // Expression: 1
                                          //  Referenced by: '<S94>/Zero-Order Hold'

    real_T CG_Acc0_Value[3];           // Expression: [0 0 0]
                                          //  Referenced by: '<S89>/CG_Acc0'

    real_T ZeroOrderHold4_Gain;        // Expression: 1
                                          //  Referenced by: '<S94>/Zero-Order Hold4'

    real_T Gain_Gain_be[3];            // Expression: [1 -1 1]
                                          //  Referenced by: '<S94>/Gain'

    real_T TransferFcn3_A;             // Computed Parameter: TransferFcn3_A
                                          //  Referenced by: '<S273>/Transfer Fcn3'

    real_T TransferFcn3_C;             // Computed Parameter: TransferFcn3_C
                                          //  Referenced by: '<S273>/Transfer Fcn3'

    real_T TransferFcn4_A;             // Computed Parameter: TransferFcn4_A
                                          //  Referenced by: '<S273>/Transfer Fcn4'

    real_T TransferFcn4_C;             // Computed Parameter: TransferFcn4_C
                                          //  Referenced by: '<S273>/Transfer Fcn4'

    real_T TransferFcn5_A;             // Computed Parameter: TransferFcn5_A
                                          //  Referenced by: '<S273>/Transfer Fcn5'

    real_T TransferFcn5_C;             // Computed Parameter: TransferFcn5_C
                                          //  Referenced by: '<S273>/Transfer Fcn5'

    real_T Constant2_Value_mh[9];      // Expression: zeros(3)
                                          //  Referenced by: '<S299>/Constant2'

    real_T ZeroOrderHold3_Gain;        // Expression: 1
                                          //  Referenced by: '<S94>/Zero-Order Hold3'

    real_T Switch_Threshold;           // Expression: 0.5
                                          //  Referenced by: '<S96>/Switch'

    real_T Saturation_UpperSat_l[3];   // Expression: a_sath
                                          //  Referenced by: '<S94>/Saturation'

    real_T Saturation_LowerSat_e[3];   // Expression: a_satl
                                          //  Referenced by: '<S94>/Saturation'

    real_T RandomNumber_Mean;          // Expression: 0
                                          //  Referenced by: '<S89>/Random Number'

    real_T Integrator_IC;              // Expression: 0
                                          //  Referenced by: '<S89>/Integrator'

    real_T DelayLength0_Value;         // Expression: 0
                                          //  Referenced by: '<S89>/DelayLength0'

    real_T Enable0_Value;              // Expression: 1
                                          //  Referenced by: '<S89>/Enable0'

    real_T Delay_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S89>/Delay'

    real_T IntegratorSecondOrderLimited__m;// Expression: 0
                                              //  Referenced by: '<S166>/Integrator, Second-Order Limited'

    real_T IntegratorSecondOrderLimited__b;// Expression: 0
                                              //  Referenced by: '<S166>/Integrator, Second-Order Limited'

    real_T Constant_Value_l3;          // Expression: dtype_g
                                          //  Referenced by: '<S164>/Constant'

    real_T ZeroOrderHold_Gain_p;       // Expression: 1
                                          //  Referenced by: '<S160>/Zero-Order Hold'

    real_T ZeroOrderHold1_Gain_n;      // Expression: 1
                                          //  Referenced by: '<S160>/Zero-Order Hold1'

    real_T Switch_Threshold_o;         // Expression: 0.5
                                          //  Referenced by: '<S164>/Switch'

    real_T Saturation_UpperSat_g[3];   // Expression: g_sath
                                          //  Referenced by: '<S160>/Saturation'

    real_T Saturation_LowerSat_m[3];   // Expression: g_satl
                                          //  Referenced by: '<S160>/Saturation'

    real_T DelayLength1_Value;         // Expression: 0
                                          //  Referenced by: '<S92>/DelayLength1'

    real_T Enable1_Value;              // Expression: 1
                                          //  Referenced by: '<S92>/Enable1'

    real_T Delay1_InitialCondition;    // Expression: 0.0
                                          //  Referenced by: '<S92>/Delay1'

    real_T K_pulse1_Value[9];          // Expression: [1 0 0;0 1 0;0 0 1]
                                          //  Referenced by: '<S93>/K_pulse1'

    real_T Integrator1_IC;             // Expression: 0
                                          //  Referenced by: '<S93>/Integrator1'

    real_T Measurementbias1_Value[3];  // Expression: [0 0 0]
                                          //  Referenced by: '<S93>/Measurement bias1'

    real_T RandomNumber2_Mean[3];      // Expression: [0 0 0]
                                          //  Referenced by: '<S93>/Random Number2'

    real_T RandomNumber2_StdDev[3];  // Computed Parameter: RandomNumber2_StdDev
                                        //  Referenced by: '<S93>/Random Number2'

    real_T RandomNumber2_Seed[3];      // Expression: [666 588 477]
                                          //  Referenced by: '<S93>/Random Number2'

    real_T K_m1_Value[9];              // Expression: [1 0 0; 0 1 0; 0 0 1]
                                          //  Referenced by: '<S93>/K_m1'

    real_T DelayLength1_Value_g;       // Expression: 0
                                          //  Referenced by: '<S93>/DelayLength1'

    real_T Enable1_Value_a;            // Expression: 1
                                          //  Referenced by: '<S93>/Enable1'

    real_T Delay1_InitialCondition_l;  // Expression: 0.0
                                          //  Referenced by: '<S93>/Delay1'

    real_T SeaLevelTemperature_Value;  // Expression: T0
                                          //  Referenced by: '<S123>/Sea Level  Temperature'

    real_T K_pulse0_Value;             // Expression: 1
                                          //  Referenced by: '<S90>/K_pulse0'

    real_T RandomNumber1_Mean;         // Expression: 0
                                          //  Referenced by: '<S90>/Random Number1'

    real_T Integrator1_IC_i;           // Expression: 0
                                          //  Referenced by: '<S90>/Integrator1'

    real_T Limitaltitudetotroposhere_Upper;// Expression: h_trop
                                              //  Referenced by: '<S123>/Limit  altitude  to troposhere'

    real_T Limitaltitudetotroposhere_Lower;// Expression: h0
                                              //  Referenced by: '<S123>/Limit  altitude  to troposhere'

    real_T LapseRate_Gain;             // Expression: L
                                          //  Referenced by: '<S123>/Lapse Rate'

    real_T uT0_Gain;                   // Expression: 1/T0
                                          //  Referenced by: '<S123>/1//T0'

    real_T Constant_Value_o;           // Expression: g/(L*R)
                                          //  Referenced by: '<S123>/Constant'

    real_T P0_Gain;                    // Expression: P0
                                          //  Referenced by: '<S123>/P0'

    real_T AltitudeofTroposphere_Value;// Expression: h_trop
                                          //  Referenced by: '<S123>/Altitude of Troposphere'

    real_T LimitaltitudetoStratosphere_Upp;// Expression: 0
                                              //  Referenced by: '<S123>/Limit  altitude  to Stratosphere'

    real_T LimitaltitudetoStratosphere_Low;// Expression: h_trop-h_strat
                                              //  Referenced by: '<S123>/Limit  altitude  to Stratosphere'

    real_T gR_Gain;                    // Expression: g/R
                                          //  Referenced by: '<S123>/g//R'

    real_T Gain3_Gain;                 // Expression: 0.01
                                          //  Referenced by: '<S90>/Gain3'

    real_T Gain_Gain_c;                // Expression: 0.01
                                          //  Referenced by: '<S90>/Gain'

    real_T Constant_Value_kl;          // Expression: 8191
                                          //  Referenced by: '<S6>/Constant'

    real_T Constant1_Value_lv;         // Expression: R
                                          //  Referenced by: '<S41>/Constant1'

    real_T Constant_Value_fz;          // Expression: 1
                                          //  Referenced by: '<S44>/Constant'

    real_T Constant_Value_p4;          // Expression: 1
                                          //  Referenced by: '<S46>/Constant'

    real_T Constant_Value_n;           // Expression: F
                                          //  Referenced by: '<S45>/Constant'

    real_T f_Value_p;                  // Expression: 1
                                          //  Referenced by: '<S45>/f'

    real_T Merge_InitialOutput_g;      // Expression: 1
                                          //  Referenced by: '<S35>/Merge'

    real_T Constant_Value_fp;          // Expression: 1
                                          //  Referenced by: '<S41>/Constant'

    real_T Constant2_Value_mf;         // Expression: 360
                                          //  Referenced by: '<S27>/Constant2'

    real_T Merge_InitialOutput_p;      // Expression: 1
                                          //  Referenced by: '<S26>/Merge'

    real_T Gain_Gain_o;                // Expression: 1E7
                                          //  Referenced by: '<S14>/Gain'

    real_T Constant_Value_ar;          // Expression: 180
                                          //  Referenced by: '<S19>/Constant'

    real_T Constant1_Value_k;          // Expression: 0
                                          //  Referenced by: '<S19>/Constant1'

    real_T Constant2_Value_m1;         // Expression: 360
                                          //  Referenced by: '<S24>/Constant2'

    real_T Gain1_Gain;                 // Expression: 1E7
                                          //  Referenced by: '<S14>/Gain1'

    real_T Saturation_UpperSat_a;      // Expression: 100000
                                          //  Referenced by: '<S14>/Saturation'

    real_T Saturation_LowerSat_i;      // Expression: 0
                                          //  Referenced by: '<S14>/Saturation'

    real_T Gain3_Gain_i;               // Expression: 1E3
                                          //  Referenced by: '<S14>/Gain3'

    real_T Gain4_Gain;                 // Expression: 100
                                          //  Referenced by: '<S14>/Gain4'

    real_T Gain2_Gain;                 // Expression: 2/1.225*100
                                          //  Referenced by: '<S14>/Gain2'

    real_T Gain7_Gain;                 // Expression: 100
                                          //  Referenced by: '<S14>/Gain7'

    real_T Gain5_Gain;                 // Expression: 1000.0/9.80665
                                          //  Referenced by: '<S14>/Gain5'

    real_T UniformRandomNumber1_Minimum[3];// Expression: [-1,-1,-2]*1e-5
                                              //  Referenced by: '<S91>/Uniform Random Number1'

    real_T UniformRandomNumber1_Maximum[3];// Expression: [1,1,2]*1e-5
                                              //  Referenced by: '<S91>/Uniform Random Number1'

    real_T UniformRandomNumber1_Seed[3];// Expression: [1452,787,69]
                                           //  Referenced by: '<S91>/Uniform Random Number1'

    real_T Gain1_Gain_b;               // Expression: 0.2*0.58
                                          //  Referenced by: '<S91>/Gain1'

    real_T Constant1_Value_e;          // Expression: R
                                          //  Referenced by: '<S150>/Constant1'

    real_T Constant_Value_j3;          // Expression: 1
                                          //  Referenced by: '<S153>/Constant'

    real_T Constant_Value_lj;          // Expression: 1
                                          //  Referenced by: '<S155>/Constant'

    real_T Constant_Value_oe;          // Expression: F
                                          //  Referenced by: '<S154>/Constant'

    real_T f_Value_g;                  // Expression: 1
                                          //  Referenced by: '<S154>/f'

    real_T Merge_InitialOutput_e;      // Expression: 1
                                          //  Referenced by: '<S144>/Merge'

    real_T Constant_Value_lk;          // Expression: 1
                                          //  Referenced by: '<S150>/Constant'

    real_T Constant2_Value_bb;         // Expression: 360
                                          //  Referenced by: '<S136>/Constant2'

    real_T Merge_InitialOutput_ee;     // Expression: 1
                                          //  Referenced by: '<S135>/Merge'

    real_T Gain_Gain_pm;               // Expression: 1E7
                                          //  Referenced by: '<S13>/Gain'

    real_T Constant_Value_b;           // Expression: 180
                                          //  Referenced by: '<S128>/Constant'

    real_T Constant1_Value_bf;         // Expression: 0
                                          //  Referenced by: '<S128>/Constant1'

    real_T Constant2_Value_mz;         // Expression: 360
                                          //  Referenced by: '<S133>/Constant2'

    real_T Gain1_Gain_h;               // Expression: 1E7
                                          //  Referenced by: '<S13>/Gain1'

    real_T Saturation_UpperSat_i;      // Expression: 100000
                                          //  Referenced by: '<S91>/Saturation'

    real_T Saturation_LowerSat_i4;     // Expression: 0
                                          //  Referenced by: '<S91>/Saturation'

    real_T Gain3_Gain_g;               // Expression: 1E3
                                          //  Referenced by: '<S13>/Gain3'

    real_T Gain6_Gain;                 // Expression: 100
                                          //  Referenced by: '<S13>/Gain6'

    real_T Gain8_Gain;                 // Expression: 100
                                          //  Referenced by: '<S13>/Gain8'

    real_T TransferFcn4_A_j;           // Computed Parameter: TransferFcn4_A_j
                                          //  Referenced by: '<S127>/Transfer Fcn4'

    real_T TransferFcn4_C_b;           // Computed Parameter: TransferFcn4_C_b
                                          //  Referenced by: '<S127>/Transfer Fcn4'

    real_T TransferFcn1_A_k;           // Computed Parameter: TransferFcn1_A_k
                                          //  Referenced by: '<S127>/Transfer Fcn1'

    real_T TransferFcn1_C_j;           // Computed Parameter: TransferFcn1_C_j
                                          //  Referenced by: '<S127>/Transfer Fcn1'

    real_T TransferFcn2_A_b;           // Computed Parameter: TransferFcn2_A_b
                                          //  Referenced by: '<S127>/Transfer Fcn2'

    real_T TransferFcn2_C_o;           // Computed Parameter: TransferFcn2_C_o
                                          //  Referenced by: '<S127>/Transfer Fcn2'

    real_T Gain9_Gain;                 // Expression: 100
                                          //  Referenced by: '<S13>/Gain9'

    real_T Gain4_Gain_n;               // Expression: 100
                                          //  Referenced by: '<S13>/Gain4'

    real_T Gain10_Gain;                // Expression: 100
                                          //  Referenced by: '<S13>/Gain10'

    real_T Gain11_Gain;                // Expression: 100
                                          //  Referenced by: '<S13>/Gain11'

    real_T Gain2_Gain_p;               // Expression: 100
                                          //  Referenced by: '<S13>/Gain2'

    real_T Gain5_Gain_e;               // Expression: 1E3
                                          //  Referenced by: '<S13>/Gain5'

    real_T Gain7_Gain_g;               // Expression: 1E3
                                          //  Referenced by: '<S13>/Gain7'

    real_T Gain12_Gain;                // Expression: 1000
                                          //  Referenced by: '<S13>/Gain12'

    real_T Gain13_Gain;                // Expression: 1000
                                          //  Referenced by: '<S13>/Gain13'

    real_T Gain14_Gain;                // Expression: 1000
                                          //  Referenced by: '<S13>/Gain14'

    real_T Gain15_Gain;                // Expression: 1000
                                          //  Referenced by: '<S13>/Gain15'

    real_T Gain16_Gain;                // Expression: 1e5
                                          //  Referenced by: '<S13>/Gain16'

    real_T Gain17_Gain;                // Expression: 1e5
                                          //  Referenced by: '<S13>/Gain17'

    real_T CopterID_Value;             // Expression: 1
                                          //  Referenced by: '<S16>/CopterID'

    real_T Merge_InitialOutput_d[4];   // Expression: [1 0 0 0]
                                          //  Referenced by: '<S47>/Merge'

    real_T Gain_Gain_g;                // Expression: 60/2/pi
                                          //  Referenced by: '<S16>/Gain'

    real_T Constant_Value_c[2];        // Expression: [0 0]
                                          //  Referenced by: '<S7>/Constant'

    real_T Gain1_Gain_m;               // Expression: 180/pi
                                          //  Referenced by: '<S16>/Gain1'

    real_T Saturation_UpperSat_n;      // Expression: 1
                                          //  Referenced by: '<Root>/Saturation'

    real_T Saturation_LowerSat_h;      // Expression: 0
                                          //  Referenced by: '<Root>/Saturation'

    real_T CG_Acc1_Value[3];           // Expression: [0 0 0]
                                          //  Referenced by: '<S89>/CG_Acc1'

    real_T RandomNumber1_Mean_b;       // Expression: 0
                                          //  Referenced by: '<S89>/Random Number1'

    real_T IntegratorSecondOrderLimited__j;// Expression: 0
                                              //  Referenced by: '<S113>/Integrator, Second-Order Limited'

    real_T IntegratorSecondOrderLimited__l;// Expression: 0
                                              //  Referenced by: '<S113>/Integrator, Second-Order Limited'

    real_T ZeroOrderHold1_Gain_g;      // Expression: 1
                                          //  Referenced by: '<S95>/Zero-Order Hold1'

    real_T ZeroOrderHold2_Gain_k;      // Expression: 1
                                          //  Referenced by: '<S95>/Zero-Order Hold2'

    real_T ZeroOrderHold_Gain_i;       // Expression: 1
                                          //  Referenced by: '<S95>/Zero-Order Hold'

    real_T ZeroOrderHold4_Gain_g;      // Expression: 1
                                          //  Referenced by: '<S95>/Zero-Order Hold4'

    real_T Gain_Gain_bv[3];            // Expression: [1 -1 1]
                                          //  Referenced by: '<S95>/Gain'

    real_T ZeroOrderHold3_Gain_g;      // Expression: 1
                                          //  Referenced by: '<S95>/Zero-Order Hold3'

    real_T Integrator1_IC_g;           // Expression: 0
                                          //  Referenced by: '<S89>/Integrator1'

    real_T RandomNumber3_Mean[3];      // Expression: [0 0 0]
                                          //  Referenced by: '<S89>/Random Number3'

    real_T RandomNumber3_StdDev[3];  // Computed Parameter: RandomNumber3_StdDev
                                        //  Referenced by: '<S89>/Random Number3'

    real_T RandomNumber3_Seed[3];      // Expression: [3341 365 597]
                                          //  Referenced by: '<S89>/Random Number3'

    real_T RandomNumber2_Mean_a;       // Expression: 0
                                          //  Referenced by: '<S90>/Random Number2'

    real_T UniformRandomNumber4_Minimum[3];// Expression: [-1,-1,-2]*1e-5
                                              //  Referenced by: '<S91>/Uniform Random Number4'

    real_T UniformRandomNumber4_Maximum[3];// Expression: [1,1,2]*1e-5
                                              //  Referenced by: '<S91>/Uniform Random Number4'

    real_T UniformRandomNumber4_Seed[3];// Expression: [5445,45433,33433]
                                           //  Referenced by: '<S91>/Uniform Random Number4'

    real_T BiasGain1_Gain;             // Expression: 0.1
                                          //  Referenced by: '<S91>/BiasGain1'

    real_T RandomNumber_Mean_g;        // Expression: 0
                                          //  Referenced by: '<S92>/Random Number'

    real_T Integrator_IC_h;            // Expression: 0
                                          //  Referenced by: '<S92>/Integrator'

    real_T Constant_Value_i[3];        // Expression: ones(3,1)
                                          //  Referenced by: '<S92>/Constant'

    real_T IntegratorSecondOrderLimited__c;// Expression: 0
                                              //  Referenced by: '<S163>/Integrator, Second-Order Limited'

    real_T IntegratorSecondOrderLimited__f;// Expression: 0
                                              //  Referenced by: '<S163>/Integrator, Second-Order Limited'

    real_T Constant_Value_p0;          // Expression: dtype_g
                                          //  Referenced by: '<S161>/Constant'

    real_T ZeroOrderHold_Gain_i4;      // Expression: 1
                                          //  Referenced by: '<S159>/Zero-Order Hold'

    real_T ZeroOrderHold1_Gain_j;      // Expression: 1
                                          //  Referenced by: '<S159>/Zero-Order Hold1'

    real_T Switch_Threshold_g;         // Expression: 0.5
                                          //  Referenced by: '<S161>/Switch'

    real_T Saturation_UpperSat_at[3];  // Expression: g_sath
                                          //  Referenced by: '<S159>/Saturation'

    real_T Saturation_LowerSat_c[3];   // Expression: g_satl
                                          //  Referenced by: '<S159>/Saturation'

    real_T RandomNumber1_Mean_d;       // Expression: 0
                                          //  Referenced by: '<S92>/Random Number1'

    real_T Integrator1_IC_o;           // Expression: 0
                                          //  Referenced by: '<S92>/Integrator1'

    real_T RandomNumber3_Mean_e[3];    // Expression: [0 0 0]
                                          //  Referenced by: '<S92>/Random Number3'

    real_T RandomNumber3_StdDev_e[3];
                                   // Computed Parameter: RandomNumber3_StdDev_e
                                      //  Referenced by: '<S92>/Random Number3'

    real_T RandomNumber3_Seed_b[3];    // Expression: [691 147 369]
                                          //  Referenced by: '<S92>/Random Number3'

    real_T Integrator_IC_b;            // Expression: 0
                                          //  Referenced by: '<S93>/Integrator'

    real_T RandomNumber_Mean_l;        // Expression: 0
                                          //  Referenced by: '<S93>/Random Number'

    real_T RandomNumber1_Mean_p;       // Expression: 0
                                          //  Referenced by: '<S93>/Random Number1'

    real_T RandomNumber1_Seed[3];      // Expression: [45465,454534,1234232]
                                          //  Referenced by: '<S93>/Random Number1'

    real_T RandomNumber3_Mean_p[3];    // Expression: [0 0 0]
                                          //  Referenced by: '<S93>/Random Number3'

    real_T RandomNumber3_StdDev_d[3];
                                   // Computed Parameter: RandomNumber3_StdDev_d
                                      //  Referenced by: '<S93>/Random Number3'

    real_T RandomNumber3_Seed_a[3];    // Expression: [111 222 333]
                                          //  Referenced by: '<S93>/Random Number3'

    real_T BatteryVol_Value;           // Expression: 16
                                          //  Referenced by: '<S171>/BatteryVol'

    real_T RandomNumber_Mean_h;        // Expression: 0
                                          //  Referenced by: '<S272>/Random Number'

    real_T Integrator_IC_o;            // Expression: 0
                                          //  Referenced by: '<S272>/Integrator'

    real_T RandomNumber1_Mean_pz;      // Expression: 0
                                          //  Referenced by: '<S272>/Random Number1'

    real_T RandomNumber2_Mean_g;       // Expression: 0
                                          //  Referenced by: '<S273>/Random Number2'

    real_T Integrator1_IC_o2;          // Expression: 0
                                          //  Referenced by: '<S273>/Integrator1'

    real_T RandomNumber3_Mean_h;       // Expression: 0
                                          //  Referenced by: '<S273>/Random Number3'

    real_T Gain3_Gain_f;               // Expression: 1000
                                          //  Referenced by: '<S9>/Gain3'

    real_T Constant2_Value_om[4];      // Expression: [1000,1000,1000,1000]
                                          //  Referenced by: '<S9>/Constant2'

    real_T Gain1_Gain_l;               // Expression: 1000
                                          //  Referenced by: '<S9>/Gain1'

    real_T Constant1_Value_i[2];       // Expression: [1000 1000]
                                          //  Referenced by: '<S9>/Constant1'

    real_T Signal_Saturation_7_UpperSat;// Expression: 2000
                                           //  Referenced by: '<S174>/Signal_Saturation_7'

    real_T Signal_Saturation_7_LowerSat;// Expression: 1000
                                           //  Referenced by: '<S174>/Signal_Saturation_7'

    real_T Constant2_Value_g[4];       // Expression: [1000,1000,1000,1000]
                                          //  Referenced by: '<S281>/Constant2'

    real_T Gain1_Gain_lu;              // Expression: 1/1000
                                          //  Referenced by: '<S281>/Gain1'

    real_T Signal_Saturation_1_UpperSat;// Expression: 1
                                           //  Referenced by: '<S174>/Signal_Saturation_1'

    real_T Signal_Saturation_1_LowerSat;// Expression: 0
                                           //  Referenced by: '<S174>/Signal_Saturation_1'

    real_T motorSpeed_UpperSat;        // Expression: 9000
                                          //  Referenced by: '<S174>/motorSpeed'

    real_T motorSpeed_LowerSat;        // Expression: 0
                                          //  Referenced by: '<S174>/motorSpeed'

    real_T Signal_Saturation_2_UpperSat;// Expression: 1
                                           //  Referenced by: '<S174>/Signal_Saturation_2'

    real_T Signal_Saturation_2_LowerSat;// Expression: 0
                                           //  Referenced by: '<S174>/Signal_Saturation_2'

    real_T motorSpeed1_UpperSat;       // Expression: 9000
                                          //  Referenced by: '<S174>/motorSpeed1'

    real_T motorSpeed1_LowerSat;       // Expression: 0
                                          //  Referenced by: '<S174>/motorSpeed1'

    real_T Signal_Saturation_3_UpperSat;// Expression: 1
                                           //  Referenced by: '<S174>/Signal_Saturation_3'

    real_T Signal_Saturation_3_LowerSat;// Expression: 0
                                           //  Referenced by: '<S174>/Signal_Saturation_3'

    real_T motorSpeed2_UpperSat;       // Expression: 9000
                                          //  Referenced by: '<S174>/motorSpeed2'

    real_T motorSpeed2_LowerSat;       // Expression: 0
                                          //  Referenced by: '<S174>/motorSpeed2'

    real_T Signal_Saturation_4_UpperSat;// Expression: 1
                                           //  Referenced by: '<S174>/Signal_Saturation_4'

    real_T Signal_Saturation_4_LowerSat;// Expression: 0
                                           //  Referenced by: '<S174>/Signal_Saturation_4'

    real_T motorSpeed3_UpperSat;       // Expression: 9000
                                          //  Referenced by: '<S174>/motorSpeed3'

    real_T motorSpeed3_LowerSat;       // Expression: 0
                                          //  Referenced by: '<S174>/motorSpeed3'

    real_T Constant1_Value_d[2];       // Expression: [1000 1000]
                                          //  Referenced by: '<S281>/Constant1'

    real_T Gain2_Gain_b;               // Expression: 1/1000*2
                                          //  Referenced by: '<S281>/Gain2'

    real_T Constant_Value_pq[2];       // Expression: [1 1]
                                          //  Referenced by: '<S281>/Constant'

    real_T Signal_Saturation_5_UpperSat;// Expression: 1
                                           //  Referenced by: '<S174>/Signal_Saturation_5'

    real_T Signal_Saturation_5_LowerSat;// Expression: -1
                                           //  Referenced by: '<S174>/Signal_Saturation_5'

    real_T Switch_Threshold_d;         // Expression: 0
                                          //  Referenced by: '<S286>/Switch'

    real_T Signal_Saturation_6_UpperSat;// Expression: 1
                                           //  Referenced by: '<S174>/Signal_Saturation_6'

    real_T Signal_Saturation_6_LowerSat;// Expression: -1
                                           //  Referenced by: '<S174>/Signal_Saturation_6'

    real_T Switch_Threshold_b;         // Expression: 0
                                          //  Referenced by: '<S287>/Switch'

    real_T Constant_Value_f4;          // Expression: 1
                                          //  Referenced by: '<S308>/Constant'

    real32_T Gain_Gain_j;              // Computed Parameter: Gain_Gain_j
                                          //  Referenced by: '<S173>/Gain'

    uint32_T MediumHighAltitudeIntensity_max[2];
                          // Computed Parameter: MediumHighAltitudeIntensity_max
                             //  Referenced by: '<S240>/Medium//High Altitude Intensity'

    uint8_T Constant_Value_nn[4];      // Computed Parameter: Constant_Value_nn
                                          //  Referenced by: '<S385>/Constant'

    P_IfWarningError_Lifting_wing_T IfWarningError_i;// '<S339>/If Warning//Error' 
    P_NegativeTrace_Lifting_wing__T NegativeTrace_h;// '<S296>/Negative Trace'
    P_PositiveTrace_Lifting_wing__T PositiveTrace_k;// '<S296>/Positive Trace'
    P_Distanceintogusty_Lifting_w_T Distanceintogustz;// '<S215>/Distance into gust (z)' 
    P_Distanceintogusty_Lifting_w_T Distanceintogusty;// '<S215>/Distance into gust (y)' 
    P_IfActionSubsystem1_Liftin_b_T IfActionSubsystem1_f;// '<S198>/If Action Subsystem1' 
    P_IfActionSubsystem1_Lifting__T IfActionSubsystem1_j1;// '<S189>/If Action Subsystem1' 
    P_IfActionSubsystem1_Liftin_b_T IfActionSubsystem1_j;// '<S144>/If Action Subsystem1' 
    P_IfActionSubsystem1_Lifting__T IfActionSubsystem1_n;// '<S135>/If Action Subsystem1' 
    P_IfWarningError_Lifting_wing_T IfWarningError;// '<S50>/If Warning//Error'
    P_NegativeTrace_Lifting_wing__T NegativeTrace;// '<S47>/Negative Trace'
    P_PositiveTrace_Lifting_wing__T PositiveTrace;// '<S47>/Positive Trace'
    P_IfActionSubsystem1_Liftin_b_T IfActionSubsystem1_g;// '<S35>/If Action Subsystem1' 
    P_IfActionSubsystem1_Lifting__T IfActionSubsystem1;// '<S26>/If Action Subsystem1' 
  };

  // Real-time Model Data Structure
  using odeFSubArray = real_T[90];
  struct RT_MODEL_Lifting_wing_HIL_mod_T {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;
    X_Lifting_wing_HIL_model_dll_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    XDis_Lifting_wing_HIL_model_d_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T CTOutputIncnstWithState;
    real_T odeY[90];
    real_T odeF[4][90];
    ODE4_IntgData intgData;

    //
    //  Sizes:
    //  The following substructure contains sizes information
    //  for many of the model attributes such as inputs, outputs,
    //  dwork, sample times, etc.

    struct {
      int_T numContStates;
      int_T numPeriodicContStates;
      int_T numSampTimes;
    } Sizes;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
      boolean_T firstInitCondFlag;
      struct {
        uint8_T TID[4];
      } TaskCounters;

      time_T tStart;
      SimTimeStep simTimeStep;
      boolean_T stopRequestedFlag;
      time_T *t;
      time_T tArray[4];
    } Timing;

    boolean_T getStopRequested() const;
    void setStopRequested(boolean_T aStopRequested);
    void setFirstInitCond(boolean_T aFirstInitCond);
    boolean_T isFirstInitCond() const;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus);
    time_T* getTPtr() const;
    void setTPtr(time_T* aTPtr);
    boolean_T* getStopRequestedPtr();
    const char_T** getErrorStatusPtr();
    boolean_T isMajorTimeStep() const;
    boolean_T isMinorTimeStep() const;
    time_T** getTPtrPtr();
    time_T getTStart() const;
  };

  // Copy Constructor
  MulticopterModelClass(MulticopterModelClass const&) = delete;

  // Assignment Operator
  MulticopterModelClass& operator= (MulticopterModelClass const&) & = delete;

  // Move Constructor
  MulticopterModelClass(MulticopterModelClass &&) = delete;

  // Move Assignment Operator
  MulticopterModelClass& operator= (MulticopterModelClass &&) = delete;

  // Real-Time Model get method
  MulticopterModelClass::RT_MODEL_Lifting_wing_HIL_mod_T * getRTM();

  // External inputs
  ExtU_Lifting_wing_HIL_model_d_T Lifting_wing_HIL_model_dll_U;

  // External outputs
  ExtY_Lifting_wing_HIL_model_d_T Lifting_wing_HIL_model_dll_Y;

  // Tunable parameters
  static P_Lifting_wing_HIL_model_dll_T Lifting_wing_HIL_model_dll_P;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  MulticopterModelClass();

  // Destructor
  ~MulticopterModelClass();

  // private data and function members
 private:
  // Block signals
  B_Lifting_wing_HIL_model_dll_T Lifting_wing_HIL_model_dll_B;

  // Block states
  DW_Lifting_wing_HIL_model_dll_T Lifting_wing_HIL_model_dll_DW;

  // Block continuous states
  X_Lifting_wing_HIL_model_dll_T Lifting_wing_HIL_model_dll_X;

  // Block Continuous state disabled vector
  XDis_Lifting_wing_HIL_model_d_T Lifting_wing_HIL_model_dll_XDis;

  // private member function(s) for subsystem '<S26>/If Action Subsystem'
  static void Lifting_wing__IfActionSubsystem(real_T rtu_u, real_T rtu_absu,
    real_T *rty_signu);

  // private member function(s) for subsystem '<S26>/If Action Subsystem1'
  void Lifting_wing_IfActionSubsystem1(real_T *rty_zero,
    P_IfActionSubsystem1_Lifting__T *localP);

  // private member function(s) for subsystem '<S35>/If Action Subsystem1'
  static void Lifting_wi_IfActionSubsystem1_g(real_T *rty_zero,
    P_IfActionSubsystem1_Liftin_b_T *localP);

  // private member function(s) for subsystem '<S47>/Positive Trace'
  static void Lifting_wing_HIL__PositiveTrace(real_T rtu_traceDCM, const real_T
    rtu_DCM[9], real_T rty_qwqxqyqz[4], P_PositiveTrace_Lifting_wing__T *localP);

  // private member function(s) for subsystem '<S47>/Negative Trace'
  static void Lifting_wing_NegativeTrace_Init(DW_NegativeTrace_Lifting_wing_T
    *localDW);
  void Lifting_wing_HIL__NegativeTrace(const real_T rtu_DCM[9], real_T
    rty_qwqxqyqz[4], DW_NegativeTrace_Lifting_wing_T *localDW,
    P_NegativeTrace_Lifting_wing__T *localP);

  // private member function(s) for subsystem '<S50>/If Warning//Error'
  static void Lifting_wing_HIL_IfWarningError(const real_T rtu_dcm[9], uint8_T
    rtp_action, real_T rtp_tolerance, P_IfWarningError_Lifting_wing_T *localP);

  // private member function(s) for subsystem '<S215>/Distance into gust (y)'
  static void Lifting__Distanceintogusty_Init(B_Distanceintogusty_Lifting_w_T
    *localB, P_Distanceintogusty_Lifting_w_T *localP,
    X_Distanceintogusty_Lifting_w_T *localX);
  static void Lifting_Distanceintogusty_Reset(P_Distanceintogusty_Lifting_w_T
    *localP, X_Distanceintogusty_Lifting_w_T *localX);
  void Lifting_Distanceintogusty_Deriv(real_T rtu_V, real_T rtp_d_m,
    DW_Distanceintogusty_Lifting__T *localDW, P_Distanceintogusty_Lifting_w_T
    *localP, X_Distanceintogusty_Lifting_w_T *localX,
    XDot_Distanceintogusty_Liftin_T *localXdot);
  static void Lifti_Distanceintogusty_Disable(DW_Distanceintogusty_Lifting__T
    *localDW);
  void Lifting_wing__Distanceintogusty(boolean_T rtu_Enable, real_T rtp_d_m,
    B_Distanceintogusty_Lifting_w_T *localB, DW_Distanceintogusty_Lifting__T
    *localDW, P_Distanceintogusty_Lifting_w_T *localP,
    X_Distanceintogusty_Lifting_w_T *localX, XDis_Distanceintogusty_Liftin_T
    *localXdis);

  // private member function(s) for subsystem '<S284>/MATLAB Function'
  static void Lifting_wing_HIL_MATLABFunction(real_T rtu_Ad, real_T rtu_dt,
    real_T rtu_rate_max, B_MATLABFunction_Lifting_wing_T *localB,
    DW_MATLABFunction_Lifting_win_T *localDW);

  // private member function(s) for subsystem '<S174>/throttle2rads2'
  void Lifting_wing_HIL_throttle2rads2(real_T rtu_throttle,
    B_throttle2rads2_Lifting_wing_T *localB) const;

  // private member function(s) for subsystem '<Root>'
  real_T Lifting_wing_HIL_model_dl_ppval(const real_T pp_breaks[1000], const
    real_T pp_coefs[3996], real_T x);
  real_T Lifting_wing_eml_rand_mt19937ar(uint32_T state[625]);
  real_T Lifting_wing__eml_rand_mcg16807(uint32_T *state);
  real_T Lifting_wing_HIL_model_dll_rand(void);
  void Lifting_wing_HIL_model_d_rand_o(real_T r[3]);
  real_T Lifting_wing_HIL_model_dll_norm(const real_T x[3]);
  real_T Lifting_wing_HIL_model_d_rand_a(void);
  void Lifting_wing_HIL_mo_param_gen_a(real_T runtime, const real_T x_init_data[],
    const int32_T x_init_size[1], const real_T Ti_data[], const int32_T Ti_size
    [1], const real_T dt_data[], real_T y_data[], int32_T y_size[1]);
  real_T Lifting_wing_HIL_model_d_rand_c(void);
  real_T Lifting_wing_HIL_model_d_rand_p(void);
  real_T Lifting_wing_HIL_model_d_rand_i(void);
  real_T Lifting_wing_HIL_model__rand_iv(void);
  real_T Lifting_wing_HIL_model__rand_az(void);
  real_T Lifting_wing_HIL_model__rand_d3(void);
  real_T Lifting_wing_HIL_model_d_rand_d(void);
  real_T Lifting_wing_HIL_model__rand_dm(void);
  real_T Lifting_wing_HIL_model_d_rand_b(void);
  real_T Lifting_wing_HIL_model_d_rand_k(void);
  real_T Lifting_wing_HIL_model_d_rand_h(void);
  real_T Lifting_wing_HIL_model_d_rand_g(void);
  real_T Lifting_wing_HIL_model_d_rand_j(void);
  real_T Lifting_wing_HIL_model_d_rand_l(void);
  real_T Lifting_wing_HIL_model__rand_lh(void);
  real_T Lifting_wing_HIL_model__rand_kb(void);
  real_T Lifting_wing_HIL_model__rand_p0(void);
  real_T Lifting_wing_HIL_model_d_rand_n(void);
  real_T Lifting_wing_HIL_model__rand_ig(void);
  real_T Lifting_wing_HIL_model_d_rand_f(void);
  real_T Lifting_wing_HIL_model__rand_bt(void);
  real_T Lifting_wing_HIL_model__rand_fv(void);
  real_T Lifting_wing_HIL_model_d_rand_m(void);
  real_T Lifting_wing_HIL_model__rand_ir(void);
  real_T Lifting_wing_HIL_model__rand_gk(void);
  real_T Lifting_wing_HIL_model__rand_os(void);
  real_T Lifting_wing_HIL_model__rand_fi(void);
  real_T Lifting_wing_HIL_model__rand_o0(void);
  real_T Lifting_wing_HIL_model__rand_ly(void);
  real_T Lifting_wing_HIL_model__rand_p4(void);
  real_T Lifting_wing_HIL_model__rand_jc(void);
  real_T Lifting_wing_HIL_model__rand_fl(void);
  real_T Lifting_wing_HIL_model__rand_oi(void);
  real_T Lifting_wing_HIL_model__rand_jg(void);
  real_T Lifting_wing_HIL_model__rand_c5(void);
  real_T Lifting_wing_HIL_model__rand_nm(void);
  real_T Lifting_wing_HIL_model__rand_nb(void);

  // Global mass matrix

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void Lifting_wing_HIL_model_dll_derivatives();

  // Real-Time Model
  RT_MODEL_Lifting_wing_HIL_mod_T Lifting_wing_HIL_model_dll_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Gain1' : Unused code path elimination
//  Block '<S11>/Gain' : Unused code path elimination
//  Block '<S18>/Data Type Duplicate' : Unused code path elimination
//  Block '<S89>/Add1' : Unused code path elimination
//  Block '<S89>/Delay1' : Unused code path elimination
//  Block '<S89>/DelayLength1' : Unused code path elimination
//  Block '<S89>/Enable1' : Unused code path elimination
//  Block '<S89>/K_pulse1' : Unused code path elimination
//  Block '<S89>/Product1' : Unused code path elimination
//  Block '<S89>/Random Number2' : Unused code path elimination
//  Block '<S89>/Rate Transition1' : Unused code path elimination
//  Block '<S89>/Sum1' : Unused code path elimination
//  Block '<S109>/Constant' : Unused code path elimination
//  Block '<S109>/Switch' : Unused code path elimination
//  Block '<S95>/Saturation' : Unused code path elimination
//  Block '<S95>/Sum1' : Unused code path elimination
//  Block '<S122>/Add' : Unused code path elimination
//  Block '<S122>/Constant' : Unused code path elimination
//  Block '<S122>/Constant1' : Unused code path elimination
//  Block '<S122>/Data Type Conversion' : Unused code path elimination
//  Block '<S122>/Data Type Conversion1' : Unused code path elimination
//  Block '<S122>/Data Type Conversion3' : Unused code path elimination
//  Block '<S122>/Divide' : Unused code path elimination
//  Block '<S122>/Divide1' : Unused code path elimination
//  Block '<S122>/Gain' : Unused code path elimination
//  Block '<S123>/Product' : Unused code path elimination
//  Block '<S123>/Product3' : Unused code path elimination
//  Block '<S123>/a' : Unused code path elimination
//  Block '<S123>/gamma*R' : Unused code path elimination
//  Block '<S123>/rho0' : Unused code path elimination
//  Block '<S122>/Power' : Unused code path elimination
//  Block '<S122>/dynVisc Conversion' : Unused code path elimination
//  Block '<S122>/kineVisc Conversion' : Unused code path elimination
//  Block '<S125>/Data Type Duplicate' : Unused code path elimination
//  Block '<S92>/Add1' : Unused code path elimination
//  Block '<S92>/Delay' : Unused code path elimination
//  Block '<S92>/DelayLength0' : Unused code path elimination
//  Block '<S92>/Enable0' : Unused code path elimination
//  Block '<S92>/Product1' : Unused code path elimination
//  Block '<S92>/Random Number2' : Unused code path elimination
//  Block '<S92>/Rate Transition' : Unused code path elimination
//  Block '<S92>/Sum1' : Unused code path elimination
//  Block '<S93>/Delay' : Unused code path elimination
//  Block '<S93>/DelayLength0' : Unused code path elimination
//  Block '<S93>/Enable0' : Unused code path elimination
//  Block '<S93>/K_pulse0' : Unused code path elimination
//  Block '<S93>/Product' : Unused code path elimination
//  Block '<S93>/Rate Transition' : Unused code path elimination
//  Block '<S171>/Constant' : Unused code path elimination
//  Block '<S177>/Data Type Duplicate' : Unused code path elimination
//  Block '<S216>/Cast' : Unused code path elimination
//  Block '<S269>/Unit Conversion' : Unused code path elimination
//  Block '<S181>/Constant' : Unused code path elimination
//  Block '<S303>/Unit Conversion' : Unused code path elimination
//  Block '<S15>/Data Type Conversion14' : Eliminate redundant data type conversion
//  Block '<S16>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S16>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S47>/Reshape 3x3 -> 9' : Reshape block reduction
//  Block '<S78>/Reshape' : Reshape block reduction
//  Block '<S89>/Rate Transition' : Eliminated since input and output rates are identical
//  Block '<S94>/Reshape1' : Reshape block reduction
//  Block '<S95>/Reshape1' : Reshape block reduction
//  Block '<S122>/Cast To Double' : Eliminate redundant data type conversion
//  Block '<S122>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S92>/Rate Transition1' : Eliminated since input and output rates are identical
//  Block '<S93>/Rate Transition1' : Eliminated since input and output rates are identical
//  Block '<S172>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S215>/Cast' : Eliminate redundant data type conversion
//  Block '<S215>/Cast To Double' : Eliminate redundant data type conversion
//  Block '<S221>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S216>/Cast To Double' : Eliminate redundant data type conversion
//  Block '<S216>/Cast To Double1' : Eliminate redundant data type conversion
//  Block '<S216>/Cast To Double2' : Eliminate redundant data type conversion
//  Block '<S216>/Cast To Double3' : Eliminate redundant data type conversion
//  Block '<S216>/Cast To Double4' : Eliminate redundant data type conversion
//  Block '<S246>/Reshape' : Reshape block reduction
//  Block '<S246>/Reshape1' : Reshape block reduction
//  Block '<S248>/Reshape' : Reshape block reduction
//  Block '<S254>/Reshape' : Reshape block reduction
//  Block '<S254>/Reshape1' : Reshape block reduction
//  Block '<S256>/Reshape' : Reshape block reduction
//  Block '<S217>/Cast To Double' : Eliminate redundant data type conversion
//  Block '<S217>/Reshape' : Reshape block reduction
//  Block '<S217>/Reshape1' : Reshape block reduction
//  Block '<S265>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S266>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S267>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S268>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S318>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S331>/Reshape1' : Reshape block reduction
//  Block '<S331>/Reshape2' : Reshape block reduction
//  Block '<S332>/Reshape1' : Reshape block reduction
//  Block '<S332>/Reshape2' : Reshape block reduction
//  Block '<S298>/Reshape' : Reshape block reduction
//  Block '<S298>/Reshape1' : Reshape block reduction
//  Block '<S301>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S302>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S304>/Reshape1' : Reshape block reduction
//  Block '<S304>/Reshape2' : Reshape block reduction
//  Block '<S296>/Reshape 3x3 -> 9' : Reshape block reduction
//  Block '<S367>/Reshape' : Reshape block reduction
//  Block '<S294>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Lifting_wing_HIL_model_dll'
//  '<S1>'   : 'Lifting_wing_HIL_model_dll/CollisionDetection'
//  '<S2>'   : 'Lifting_wing_HIL_model_dll/MATLAB Function'
//  '<S3>'   : 'Lifting_wing_HIL_model_dll/MATLAB Function1'
//  '<S4>'   : 'Lifting_wing_HIL_model_dll/MATLAB Function2'
//  '<S5>'   : 'Lifting_wing_HIL_model_dll/Mav HIL'
//  '<S6>'   : 'Lifting_wing_HIL_model_dll/Sensor Model'
//  '<S7>'   : 'Lifting_wing_HIL_model_dll/Subsystem'
//  '<S8>'   : 'Lifting_wing_HIL_model_dll/Subsystem Reference'
//  '<S9>'   : 'Lifting_wing_HIL_model_dll/throttle2pwm'
//  '<S10>'  : 'Lifting_wing_HIL_model_dll/udp_receiver'
//  '<S11>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/DynamicSystemModel'
//  '<S12>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/EnvironmentModel'
//  '<S13>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILGPSModel'
//  '<S14>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel'
//  '<S15>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Subsystem'
//  '<S16>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States'
//  '<S17>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/EnvironmentModel/Model Fail Assessment'
//  '<S18>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA'
//  '<S19>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap'
//  '<S20>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1'
//  '<S21>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LongLat_offset'
//  '<S22>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/pos_deg'
//  '<S23>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S24>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S25>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S26>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero'
//  '<S27>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S28>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem'
//  '<S29>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem1'
//  '<S30>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S31>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S32>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S33>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S34>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S35>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero'
//  '<S36>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S37>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem'
//  '<S38>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem1'
//  '<S39>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S40>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S41>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LongLat_offset/Find Rn and Rm'
//  '<S42>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S43>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/Angle Conversion2'
//  '<S44>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/denom'
//  '<S45>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/e'
//  '<S46>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/HILStateMavModel/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/e^4'
//  '<S47>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions'
//  '<S48>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace'
//  '<S49>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Positive Trace'
//  '<S50>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM'
//  '<S51>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/trace(DCM)'
//  '<S52>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
//  '<S53>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
//  '<S54>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
//  '<S55>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
//  '<S56>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S57>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S58>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S59>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
//  '<S60>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
//  '<S61>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S62>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S63>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S64>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
//  '<S65>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
//  '<S66>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S67>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S68>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S69>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
//  '<S70>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
//  '<S71>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S72>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S73>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S74>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
//  '<S75>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
//  '<S76>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else No Action'
//  '<S77>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
//  '<S78>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
//  '<S79>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
//  '<S80>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
//  '<S81>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/None'
//  '<S82>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
//  '<S83>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
//  '<S84>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/None'
//  '<S85>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
//  '<S86>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
//  '<S87>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
//  '<S88>'  : 'Lifting_wing_HIL_model_dll/Mav HIL/Vehicle States/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
//  '<S89>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub'
//  '<S90>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Barometer'
//  '<S91>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS'
//  '<S92>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub'
//  '<S93>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Magnetometer Hub'
//  '<S94>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0'
//  '<S95>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1'
//  '<S96>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/Dynamics'
//  '<S97>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/w x (w x d)'
//  '<S98>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/wdot x d'
//  '<S99>'  : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/Dynamics/No Dynamics'
//  '<S100>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/Dynamics/Second-order Dynamics'
//  '<S101>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/w x (w x d)/w x (w x d)'
//  '<S102>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/w x (w x d)/w x d'
//  '<S103>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/w x (w x d)/w x (w x d)/Subsystem'
//  '<S104>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/w x (w x d)/w x (w x d)/Subsystem1'
//  '<S105>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/w x (w x d)/w x d/Subsystem'
//  '<S106>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/w x (w x d)/w x d/Subsystem1'
//  '<S107>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/wdot x d/Subsystem'
//  '<S108>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer0/wdot x d/Subsystem1'
//  '<S109>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/Dynamics'
//  '<S110>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/w x (w x d)'
//  '<S111>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/wdot x d'
//  '<S112>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/Dynamics/No Dynamics'
//  '<S113>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/Dynamics/Second-order Dynamics'
//  '<S114>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/w x (w x d)/w x (w x d)'
//  '<S115>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/w x (w x d)/w x d'
//  '<S116>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/w x (w x d)/w x (w x d)/Subsystem'
//  '<S117>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/w x (w x d)/w x (w x d)/Subsystem1'
//  '<S118>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/w x (w x d)/w x d/Subsystem'
//  '<S119>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/w x (w x d)/w x d/Subsystem1'
//  '<S120>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/wdot x d/Subsystem'
//  '<S121>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Accelerometer Hub/Three-axis Accelerometer1/wdot x d/Subsystem1'
//  '<S122>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Barometer/ISA Atmosphere Model'
//  '<S123>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Barometer/ISA Atmosphere Model/Modelling'
//  '<S124>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/-pi-pi---->0-2pi'
//  '<S125>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA'
//  '<S126>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/GenCogVel'
//  '<S127>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/NoiseFilter1'
//  '<S128>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap'
//  '<S129>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1'
//  '<S130>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LongLat_offset'
//  '<S131>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/pos_deg'
//  '<S132>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S133>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S134>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S135>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero'
//  '<S136>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S137>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem'
//  '<S138>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem1'
//  '<S139>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S140>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S141>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S142>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S143>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S144>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero'
//  '<S145>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S146>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem'
//  '<S147>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem1'
//  '<S148>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S149>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S150>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LongLat_offset/Find Rn and Rm'
//  '<S151>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S152>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/Angle Conversion2'
//  '<S153>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/denom'
//  '<S154>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/e'
//  '<S155>' : 'Lifting_wing_HIL_model_dll/Sensor Model/GPS/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/e^4'
//  '<S156>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Acceleration Conversion'
//  '<S157>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/MATLAB Function'
//  '<S158>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/MATLAB Function1'
//  '<S159>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Three-axis Gyroscope0'
//  '<S160>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Three-axis Gyroscope1'
//  '<S161>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Three-axis Gyroscope0/Dynamics'
//  '<S162>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Three-axis Gyroscope0/Dynamics/No Dynamics'
//  '<S163>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Three-axis Gyroscope0/Dynamics/Second-order Dynamics'
//  '<S164>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Three-axis Gyroscope1/Dynamics'
//  '<S165>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Three-axis Gyroscope1/Dynamics/No Dynamics'
//  '<S166>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Gyroscope Hub/Three-axis Gyroscope1/Dynamics/Second-order Dynamics'
//  '<S167>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Magnetometer Hub/MATLAB Function'
//  '<S168>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Magnetometer Hub/MATLAB Function1'
//  '<S169>' : 'Lifting_wing_HIL_model_dll/Sensor Model/Magnetometer Hub/MATLAB Function2'
//  '<S170>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Aerodynamic Coefficients'
//  '<S171>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Battery Model'
//  '<S172>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models'
//  '<S173>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Forces and Moments'
//  '<S174>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model'
//  '<S175>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model'
//  '<S176>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Aerodynamic Coefficients/aerodynamic coefficients'
//  '<S177>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA'
//  '<S178>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Ground Model'
//  '<S179>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/MATLAB Function1'
//  '<S180>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models'
//  '<S181>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/geographical environment'
//  '<S182>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap'
//  '<S183>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1'
//  '<S184>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LongLat_offset'
//  '<S185>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/pos_deg'
//  '<S186>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
//  '<S187>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
//  '<S188>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
//  '<S189>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero'
//  '<S190>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
//  '<S191>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem'
//  '<S192>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem1'
//  '<S193>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S194>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
//  '<S195>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
//  '<S196>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
//  '<S197>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
//  '<S198>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero'
//  '<S199>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
//  '<S200>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem'
//  '<S201>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Sign1 Or Zero/If Action Subsystem1'
//  '<S202>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
//  '<S203>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
//  '<S204>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LongLat_offset/Find Rn and Rm'
//  '<S205>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LongLat_offset/rotation_rad'
//  '<S206>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/Angle Conversion2'
//  '<S207>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/denom'
//  '<S208>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/e'
//  '<S209>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Flat Earth to LLA/LongLat_offset/Find Rn and Rm/e^4'
//  '<S210>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Compare To Constant'
//  '<S211>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Compare To Constant1'
//  '<S212>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Compare To Constant2'
//  '<S213>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Compare To Constant3'
//  '<S214>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Compare To Constant4'
//  '<S215>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Discrete Wind Gust Model'
//  '<S216>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))'
//  '<S217>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Wind Shear Model'
//  '<S218>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Discrete Wind Gust Model/Distance into gust (x)'
//  '<S219>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Discrete Wind Gust Model/Distance into gust (y)'
//  '<S220>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Discrete Wind Gust Model/Distance into gust (z)'
//  '<S221>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Discrete Wind Gust Model/Velocity Conversion'
//  '<S222>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Angle Conversion'
//  '<S223>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Filters on angular rates'
//  '<S224>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Filters on velocities'
//  '<S225>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Length Conversion'
//  '<S226>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Length Conversion1'
//  '<S227>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/RMS turbulence  intensities'
//  '<S228>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates'
//  '<S229>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities'
//  '<S230>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Turbulence scale lengths'
//  '<S231>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Velocity Conversion'
//  '<S232>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Velocity Conversion2'
//  '<S233>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/White Noise'
//  '<S234>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Filters on angular rates/Hpgw'
//  '<S235>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Filters on angular rates/Hqgw'
//  '<S236>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Filters on angular rates/Hrgw'
//  '<S237>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Filters on velocities/Hugw(s)'
//  '<S238>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Filters on velocities/Hvgw(s)'
//  '<S239>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Filters on velocities/Hwgw(s)'
//  '<S240>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/RMS turbulence  intensities/High Altitude Intensity'
//  '<S241>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/RMS turbulence  intensities/Low Altitude Intensity'
//  '<S242>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates/Interpolate  rates'
//  '<S243>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates/Low altitude  rates'
//  '<S244>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates/Medium//High  altitude rates'
//  '<S245>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates/Merge Subsystems'
//  '<S246>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates/Interpolate  rates/wind to body transformation'
//  '<S247>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates/Interpolate  rates/wind to body transformation/convert to earth coords'
//  '<S248>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates/Low altitude  rates/wind to body transformation'
//  '<S249>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select angular rates/Low altitude  rates/wind to body transformation/convert to earth coords'
//  '<S250>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities/Interpolate  velocities'
//  '<S251>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities/Low altitude  velocities'
//  '<S252>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities/Medium//High  altitude velocities'
//  '<S253>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities/Merge Subsystems'
//  '<S254>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities/Interpolate  velocities/wind to body transformation'
//  '<S255>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities/Interpolate  velocities/wind to body transformation/convert to earth coords'
//  '<S256>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities/Low altitude  velocities/wind to body transformation'
//  '<S257>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Select velocities/Low altitude  velocities/wind to body transformation/convert to earth coords'
//  '<S258>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Turbulence scale lengths/Low altitude scale length'
//  '<S259>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Turbulence scale lengths/Medium//High altitude scale length'
//  '<S260>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Dryden Wind Turbulence Model  (Continuous (+q -r))/Turbulence scale lengths/Medium//High altitude scale length/Length Conversion'
//  '<S261>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Wind Shear Model/Angle Conversion'
//  '<S262>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/Wind Models/Wind Shear Model/Length Conversion'
//  '<S263>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/geographical environment/COESA Atmosphere Model'
//  '<S264>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/geographical environment/Temperature Conversion'
//  '<S265>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/geographical environment/COESA Atmosphere Model/Density Conversion'
//  '<S266>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/geographical environment/COESA Atmosphere Model/Length Conversion'
//  '<S267>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/geographical environment/COESA Atmosphere Model/Pressure Conversion'
//  '<S268>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/geographical environment/COESA Atmosphere Model/Temperature Conversion'
//  '<S269>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Environment Models/geographical environment/COESA Atmosphere Model/Velocity Conversion'
//  '<S270>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Forces and Moments/Aerodynamics and torque'
//  '<S271>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Forces and Moments/MATLAB Function'
//  '<S272>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Forces and Moments/Noise F'
//  '<S273>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Forces and Moments/Noise M'
//  '<S274>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Forces and Moments/Propeller Model'
//  '<S275>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Forces and Moments/b2l'
//  '<S276>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Forces and Moments/b2l1'
//  '<S277>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/MotorDynamic'
//  '<S278>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/MotorDynamic1'
//  '<S279>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/MotorDynamic2'
//  '<S280>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/MotorDynamic3'
//  '<S281>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Normalize'
//  '<S282>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Servo_Dynamics'
//  '<S283>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Servo_Dynamics1'
//  '<S284>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Subsystem'
//  '<S285>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Subsystem1'
//  '<S286>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Throttle To rads Gain _5'
//  '<S287>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Throttle To rads Gain _6'
//  '<S288>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/throttle2rads'
//  '<S289>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/throttle2rads1'
//  '<S290>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/throttle2rads2'
//  '<S291>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/throttle2rads3'
//  '<S292>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Subsystem/MATLAB Function'
//  '<S293>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Motor and Servo Model/Subsystem1/MATLAB Function'
//  '<S294>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS'
//  '<S295>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)'
//  '<S296>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions'
//  '<S297>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles'
//  '<S298>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate omega_dot'
//  '<S299>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Determine Force,  Mass & Inertia'
//  '<S300>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Vbxw'
//  '<S301>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Velocity Conversion'
//  '<S302>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Velocity Conversion1'
//  '<S303>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Velocity Conversion2'
//  '<S304>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/transform to Inertial axes '
//  '<S305>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix'
//  '<S306>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles'
//  '<S307>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Rotation Angles to Quaternions'
//  '<S308>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/qdot'
//  '<S309>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A11'
//  '<S310>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A12'
//  '<S311>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A13'
//  '<S312>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A21'
//  '<S313>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A22'
//  '<S314>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A23'
//  '<S315>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A31'
//  '<S316>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A32'
//  '<S317>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A33'
//  '<S318>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Create 3x3 Matrix'
//  '<S319>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
//  '<S320>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
//  '<S321>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S322>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation'
//  '<S323>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S324>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S325>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S326>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S327>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S328>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S329>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S330>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product'
//  '<S331>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate omega_dot/I x w'
//  '<S332>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate omega_dot/I x w1'
//  '<S333>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product/Subsystem'
//  '<S334>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
//  '<S335>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Vbxw/Subsystem'
//  '<S336>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/6DOF (Quaternion)/Vbxw/Subsystem1'
//  '<S337>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace'
//  '<S338>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Positive Trace'
//  '<S339>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM'
//  '<S340>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/trace(DCM)'
//  '<S341>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
//  '<S342>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
//  '<S343>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
//  '<S344>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
//  '<S345>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S346>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S347>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S348>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
//  '<S349>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
//  '<S350>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S351>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S352>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S353>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
//  '<S354>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
//  '<S355>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S356>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S357>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S358>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
//  '<S359>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
//  '<S360>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S361>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S362>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S363>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error'
//  '<S364>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal'
//  '<S365>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else No Action'
//  '<S366>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper'
//  '<S367>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal'
//  '<S368>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper'
//  '<S369>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
//  '<S370>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/None'
//  '<S371>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
//  '<S372>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Error'
//  '<S373>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/None'
//  '<S374>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/If Not Proper/Warning'
//  '<S375>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
//  '<S376>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
//  '<S377>' : 'Lifting_wing_HIL_model_dll/Subsystem Reference/Rigid Model/MATHWORKS/Direction Cosine Matrix  to Quaternions/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
//  '<S378>' : 'Lifting_wing_HIL_model_dll/udp_receiver/MATLAB Function'
//  '<S379>' : 'Lifting_wing_HIL_model_dll/udp_receiver/Subsystem'
//  '<S380>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_accel1'
//  '<S381>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_gyro1'
//  '<S382>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_mag1'
//  '<S383>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor'
//  '<S384>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller'
//  '<S385>' : 'Lifting_wing_HIL_model_dll/udp_receiver/udp_receiver'
//  '<S386>' : 'Lifting_wing_HIL_model_dll/udp_receiver/Subsystem/failture_baro_nb_var'
//  '<S387>' : 'Lifting_wing_HIL_model_dll/udp_receiver/Subsystem/failture_baro_nbb_var'
//  '<S388>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_accel1/failture_accel_ka_ca'
//  '<S389>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_accel1/failture_accel_kap'
//  '<S390>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_accel1/failture_accel_na_var'
//  '<S391>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_accel1/failture_accel_nba_var'
//  '<S392>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_gyro1/failture_gyro_kg_cg'
//  '<S393>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_gyro1/failture_gyro_kgp'
//  '<S394>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_gyro1/failture_gyro_nbg_var'
//  '<S395>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_gyro1/failture_gyro_ng_var'
//  '<S396>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_mag1/failture_mag_dm'
//  '<S397>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_mag1/failture_mag_nbm_var'
//  '<S398>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_mag1/failture_mag_nm_var'
//  '<S399>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_mag1/failture_magl_km_cm'
//  '<S400>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor1'
//  '<S401>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor2'
//  '<S402>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor3'
//  '<S403>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor4'
//  '<S404>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor5'
//  '<S405>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor6'
//  '<S406>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor7'
//  '<S407>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor8'
//  '<S408>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor_ktc1'
//  '<S409>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor_ktc2'
//  '<S410>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor_ktc3'
//  '<S411>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor_ktc4'
//  '<S412>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor_ktc5'
//  '<S413>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor_ktc6'
//  '<S414>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor_ktc7'
//  '<S415>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_motor/failture_motor_ktc8'
//  '<S416>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller/failture_propeller1'
//  '<S417>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller/failture_propeller2'
//  '<S418>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller/failture_propeller3'
//  '<S419>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller/failture_propeller4'
//  '<S420>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller/failture_propeller5'
//  '<S421>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller/failture_propeller6'
//  '<S422>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller/failture_propeller7'
//  '<S423>' : 'Lifting_wing_HIL_model_dll/udp_receiver/failture_propeller/failture_propeller8'

#endif                                 // Lifting_wing_HIL_model_dll_h_

//
// File trailer for generated code.
//
// [EOF]
//
