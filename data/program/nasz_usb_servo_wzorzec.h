/*
 * nasz_usb_servo_wzorzec.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "nasz_usb_servo_wzorzec".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Mar 15 13:17:13 2022
 *
 * Target selection: rtcon_servo_usb2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Real-Time Windows Target
 * Emulation hardware selection:
 *    Differs from embedded hardware (32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_nasz_usb_servo_wzorzec_h_
#define RTW_HEADER_nasz_usb_servo_wzorzec_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef nasz_usb_servo_wzorzec_COMMON_INCLUDES_
# define nasz_usb_servo_wzorzec_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* nasz_usb_servo_wzorzec_COMMON_INCLUDES_ */

#include "nasz_usb_servo_wzorzec_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T ThetaSP;                      /* '<Root>/Theta SP' */
  real_T RTDAC_USB2DeviceDriverTerminate;/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_h;/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_e;/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_p;/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_m;/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_n[4];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_b[4];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_k[4];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermin_nd[4];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_a[4];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermin_p1[4];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermin_af[4];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermin_hh[2];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_o[2];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermin_em[2];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermina_d[16];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermin_pn[16];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T RTDAC_USB2DeviceDriverTermin_e2[4];/* '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' */
  real_T Angleencoder;                 /* '<S6>/Gain' */
  real_T filteredvelocityencoder;      /* '<S5>/filter velocity (encoder)' */
  real_T Scale;                        /* '<S7>/Scale' */
  real_T Simplefilter;                 /* '<S7>/Simple filter' */
  real_T scaledfilteredvelocitytacho;  /* '<S5>/scale filtered velocity' */
  real_T ConvertToAmper;               /* '<S7>/ConvertToAmper' */
  real_T ConvertToAmper1;              /* '<S7>/ConvertToAmper1' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Abs;                          /* '<S3>/Abs' */
  real_T Gain13;                       /* '<S3>/Gain13' */
  real_T Gain14;                       /* '<S3>/Gain14' */
  real_T Gain18;                       /* '<S3>/Gain18' */
  real_T Gain19;                       /* '<S3>/Gain19' */
  real_T Gain20;                       /* '<S3>/Gain20' */
  real_T Gain21;                       /* '<S3>/Gain21' */
  real_T Gain22;                       /* '<S3>/Gain22' */
  real_T Gain23;                       /* '<S3>/Gain23' */
  real_T Gain25;                       /* '<S3>/Gain25' */
  real_T Gain15;                       /* '<S3>/Gain15' */
  real_T Gain16;                       /* '<S3>/Gain16' */
  real_T DirectionInput;               /* '<S9>/Direction (Input)' */
  real_T Switch[4];                    /* '<S10>/Switch' */
  real_T Constant5[4];                 /* '<S10>/Constant5' */
  real_T Constant6[4];                 /* '<S10>/Constant6' */
  real_T Constant8[16];                /* '<S7>/Constant8' */
  real_T Constant1[4];                 /* '<S12>/Constant1' */
  real_T Constant2[4];                 /* '<S12>/Constant2' */
  real_T Constant13;                   /* '<S6>/Constant13' */
  real_T Constant14[4];                /* '<S6>/Constant14' */
  real_T Constant15[4];                /* '<S6>/Constant15' */
  real_T Constant12[4];                /* '<S8>/Constant12' */
  real_T PinModeInput;                 /* '<S11>/Pin Mode (Input)' */
  real_T Constant4[2];                 /* '<S13>/Constant4' */
  real_T Constant7[2];                 /* '<S13>/Constant7' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Product;                      /* '<S14>/Product' */
  real_T Switch_n;                     /* '<S14>/Switch' */
} B_nasz_usb_servo_wzorzec_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Memory2_PreviousInput;        /* '<S13>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S14>/Memory1' */
  struct {
    void *LoggedData;
  } AngleReferencevelocity_PWORK;      /* '<Root>/Angle & Reference & velocity' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_nasz_usb_servo_wzorzec_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T filtervelocityencoder_CSTATE; /* '<S5>/filter velocity (encoder)' */
  real_T filtervelocitytacho_CSTATE;   /* '<S5>/filter velocity (tacho)' */
} X_nasz_usb_servo_wzorzec_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T filtervelocityencoder_CSTATE; /* '<S5>/filter velocity (encoder)' */
  real_T filtervelocitytacho_CSTATE;   /* '<S5>/filter velocity (tacho)' */
} XDot_nasz_usb_servo_wzorzec_T;

/* State disabled  */
typedef struct {
  boolean_T filtervelocityencoder_CSTATE;/* '<S5>/filter velocity (encoder)' */
  boolean_T filtervelocitytacho_CSTATE;/* '<S5>/filter velocity (tacho)' */
} XDis_nasz_usb_servo_wzorzec_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (auto storage) */
struct P_nasz_usb_servo_wzorzec_T_ {
  real_T ChirpSignal_T;                /* Mask Parameter: ChirpSignal_T
                                        * Referenced by: '<S1>/targetTime'
                                        */
  real_T Ramp_X0;                      /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T ChirpSignal_f1;               /* Mask Parameter: ChirpSignal_f1
                                        * Referenced by:
                                        *   '<S1>/deltaFreq'
                                        *   '<S1>/initialFreq'
                                        */
  real_T ChirpSignal_f2;               /* Mask Parameter: ChirpSignal_f2
                                        * Referenced by: '<S1>/deltaFreq'
                                        */
  real_T Ramp_slope;                   /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Ramp_start;                   /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S2>/Step'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Normal_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T Constant3_Value[4];           /* Expression: [0 0 0 0]
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant10_Value[4];          /* Expression: [1 1 1 1]
                                        * Referenced by: '<S10>/Constant10'
                                        */
  real_T Constant1_Value;              /* Expression: 2^32
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T ThetaSP_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/Theta SP'
                                        */
  real_T RTDAC_USB2DeviceDriverTerminate[2];/* Computed Parameter: RTDAC_USB2DeviceDriverTerminate
                                             * Referenced by: '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11'
                                             */
  real_T RTDAC_USB2DeviceDriverTermina_o;/* Expression: 0.01
                                          * Referenced by: '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11'
                                          */
  real_T Encoder1024PPR_Gain;          /* Expression: 1
                                        * Referenced by: '<S10>/Encoder 1024 PPR'
                                        */
  real_T Converttorad_Gain;            /* Expression: 2*pi/4096
                                        * Referenced by: '<S10>/Convert to rad'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T filtervelocityencoder_A;      /* Computed Parameter: filtervelocityencoder_A
                                        * Referenced by: '<S5>/filter velocity (encoder)'
                                        */
  real_T filtervelocityencoder_C;      /* Computed Parameter: filtervelocityencoder_C
                                        * Referenced by: '<S5>/filter velocity (encoder)'
                                        */
  real_T Scale_Gain;                   /* Expression: -25.5
                                        * Referenced by: '<S7>/Scale'
                                        */
  real_T Simplefilter_D;               /* Computed Parameter: Simplefilter_D
                                        * Referenced by: '<S7>/Simple filter'
                                        */
  real_T filtervelocitytacho_A;        /* Computed Parameter: filtervelocitytacho_A
                                        * Referenced by: '<S5>/filter velocity (tacho)'
                                        */
  real_T filtervelocitytacho_C;        /* Computed Parameter: filtervelocitytacho_C
                                        * Referenced by: '<S5>/filter velocity (tacho)'
                                        */
  real_T scalefilteredvelocity_Gain;   /* Expression: 2
                                        * Referenced by: '<S5>/scale filtered velocity'
                                        */
  real_T ConvertToAmper_Gain;          /* Expression: 1
                                        * Referenced by: '<S7>/ConvertToAmper'
                                        */
  real_T ConvertToAmper1_Gain;         /* Expression: 1
                                        * Referenced by: '<S7>/ConvertToAmper1'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 0.5
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.9999
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.9999
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: -1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: 4096
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Bit0Bit12_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Bit0-Bit12'
                                        */
  real_T Bit13_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/Bit13'
                                        */
  real_T Gain13_Gain;                  /* Expression: 2^13
                                        * Referenced by: '<S3>/Gain13'
                                        */
  real_T Bit14_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/Bit14'
                                        */
  real_T Gain14_Gain;                  /* Expression: 2^14
                                        * Referenced by: '<S3>/Gain14'
                                        */
  real_T Bit15_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/Bit15'
                                        */
  real_T Gain18_Gain;                  /* Expression: 2^15
                                        * Referenced by: '<S3>/Gain18'
                                        */
  real_T Bit16_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/Bit16'
                                        */
  real_T Gain19_Gain;                  /* Expression: 2^16
                                        * Referenced by: '<S3>/Gain19'
                                        */
  real_T Bit17_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/Bit17'
                                        */
  real_T Gain20_Gain;                  /* Expression: 2^17
                                        * Referenced by: '<S3>/Gain20'
                                        */
  real_T Bit18Therm0_Value;            /* Expression: 0
                                        * Referenced by: '<S3>/Bit18-Therm0'
                                        */
  real_T Gain21_Gain;                  /* Expression: 2^18
                                        * Referenced by: '<S3>/Gain21'
                                        */
  real_T Bit19PWM0_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Bit19-PWM0'
                                        */
  real_T Gain22_Gain;                  /* Expression: 2^19
                                        * Referenced by: '<S3>/Gain22'
                                        */
  real_T Bit20Brake0_Value;            /* Expression: 0
                                        * Referenced by: '<S3>/Bit20-Brake0'
                                        */
  real_T Gain23_Gain;                  /* Expression: 2^20
                                        * Referenced by: '<S3>/Gain23'
                                        */
  real_T Constant10_Value_o;           /* Expression: 1
                                        * Referenced by: '<S3>/Constant10'
                                        */
  real_T Constant3_Value_d;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Gain24_Gain;                  /* Expression: 2^21
                                        * Referenced by: '<S3>/Gain24'
                                        */
  real_T Bit22Therm1_Value;            /* Expression: 0
                                        * Referenced by: '<S3>/Bit22-Therm1'
                                        */
  real_T Gain25_Gain;                  /* Expression: 2^22
                                        * Referenced by: '<S3>/Gain25'
                                        */
  real_T Bit23PWM1_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Bit23-PWM1'
                                        */
  real_T Gain15_Gain;                  /* Expression: 2^23
                                        * Referenced by: '<S3>/Gain15'
                                        */
  real_T Bit24Brake1_Value;            /* Expression: 0
                                        * Referenced by: '<S3>/Bit24-Brake1'
                                        */
  real_T Gain16_Gain;                  /* Expression: 2^24
                                        * Referenced by: '<S3>/Gain16'
                                        */
  real_T Gain17_Gain;                  /* Expression: 2^25
                                        * Referenced by: '<S3>/Gain17'
                                        */
  real_T DirectionInput_Value;         /* Expression: hex2dec('047FFFF')
                                        * Referenced by: '<S9>/Direction (Input)'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0.5
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T Constant5_Value[4];           /* Expression: 0*[1 1 1 1]
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant6_Value[4];           /* Expression: [0 0 0 0]
                                        * Referenced by: '<S10>/Constant6'
                                        */
  real_T Constant8_Value[16];          /* Expression: ones(1,16)
                                        * Referenced by: '<S7>/Constant8'
                                        */
  real_T Constant1_Value_e[4];         /* Expression: [0 0 0 0] + 1
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant2_Value[4];           /* Expression: 1*[1 1 1 1]
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant13'
                                        */
  real_T Constant14_Value[4];          /* Expression: [ 0 0 0 0 ]
                                        * Referenced by: '<S6>/Constant14'
                                        */
  real_T Constant15_Value[4];          /* Expression: [0 0 0 0]
                                        * Referenced by: '<S6>/Constant15'
                                        */
  real_T Constant12_Value[4];          /* Expression: 8192*[ 1 1 1 1]
                                        * Referenced by: '<S8>/Constant12'
                                        */
  real_T PinModeInput_Value;           /* Expression: hex2dec('00')
                                        * Referenced by: '<S11>/Pin Mode (Input)'
                                        */
  real_T ClockFrequency_Value;         /* Expression: 20e6
                                        * Referenced by: '<S13>/Clock Frequency'
                                        */
  real_T Constant_Value;               /* Expression: 1e-6
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S13>/Memory2'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T Constant4_Value[2];           /* Expression: [ 0 0 ]
                                        * Referenced by: '<S13>/Constant4'
                                        */
  real_T Constant7_Value[2];           /* Expression: [ 1 1]
                                        * Referenced by: '<S13>/Constant7'
                                        */
  real_T Constant1_Value_e5;           /* Expression: 0
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S14>/Memory1'
                                        */
  real_T Switch_Threshold_a5;          /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  uint8_T SigmodeRealtimeonly2_CurrentSet;/* Computed Parameter: SigmodeRealtimeonly2_CurrentSet
                                           * Referenced by: '<Root>/Sig mode Real-time only2'
                                           */
  uint8_T SigmodeRealtimeonly1_CurrentSet;/* Computed Parameter: SigmodeRealtimeonly1_CurrentSet
                                           * Referenced by: '<Root>/Sig mode Real-time only1'
                                           */
  uint8_T ResetEncodersRealtimeonly_Curre;/* Computed Parameter: ResetEncodersRealtimeonly_Curre
                                           * Referenced by: '<Root>/Reset Encoders Real-time only'
                                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_nasz_usb_servo_wzorzec_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssStatesInfo2 statesInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[16];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[4];
      real_T const *UPtrs4[4];
      real_T const *UPtrs5[4];
      real_T const *UPtrs6[4];
      real_T const *UPtrs7[4];
      real_T const *UPtrs8[4];
      real_T const *UPtrs9[2];
      real_T const *UPtrs10[2];
      real_T const *UPtrs11[16];
      real_T const *UPtrs12[4];
      real_T const *UPtrs13[1];
      real_T const *UPtrs14[4];
      real_T const *UPtrs15[4];
      struct _ssPortOutputs outputPortInfo[18];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn0;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_nasz_usb_servo_wzorzec_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[2];
    real_T odeF[4][2];
    ODE4_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_P;

/* Block signals (auto storage) */
extern B_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_B;

/* Continuous states (auto storage) */
extern X_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_X;

/* Block states (auto storage) */
extern DW_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_DW;

/* Model entry point functions */
extern void nasz_usb_servo_wzorzec_initialize(void);
extern void nasz_usb_servo_wzorzec_step(void);
extern void nasz_usb_servo_wzorzec_terminate(void);

/* Real-time Model object */
extern RT_MODEL_nasz_usb_servo_wzorzec_T *const nasz_usb_servo_wzorzec_M;

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
 * '<Root>' : 'nasz_usb_servo_wzorzec'
 * '<S1>'   : 'nasz_usb_servo_wzorzec/Chirp Signal'
 * '<S2>'   : 'nasz_usb_servo_wzorzec/Ramp'
 * '<S3>'   : 'nasz_usb_servo_wzorzec/Servo'
 * '<S4>'   : 'nasz_usb_servo_wzorzec/Slider Gain'
 * '<S5>'   : 'nasz_usb_servo_wzorzec/velocity data'
 * '<S6>'   : 'nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo'
 * '<S7>'   : 'nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo/A//D'
 * '<S8>'   : 'nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo/D//A'
 * '<S9>'   : 'nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo/Digital I//O'
 * '<S10>'  : 'nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo/Encoder1'
 * '<S11>'  : 'nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo/Mode'
 * '<S12>'  : 'nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo/PWM DD'
 * '<S13>'  : 'nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo/Timer'
 * '<S14>'  : 'nasz_usb_servo_wzorzec/velocity data/Calculate Velocity'
 */
#endif                                 /* RTW_HEADER_nasz_usb_servo_wzorzec_h_ */
