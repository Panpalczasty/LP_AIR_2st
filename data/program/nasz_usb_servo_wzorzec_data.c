/*
 * nasz_usb_servo_wzorzec_data.c
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

#include "nasz_usb_servo_wzorzec.h"
#include "nasz_usb_servo_wzorzec_private.h"

/* Block parameters (auto storage) */
P_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_P = {
  170.0,                               /* Mask Parameter: ChirpSignal_T
                                        * Referenced by: '<S1>/targetTime'
                                        */
  -1.0,                                /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  0.01,                                /* Mask Parameter: ChirpSignal_f1
                                        * Referenced by:
                                        *   '<S1>/deltaFreq'
                                        *   '<S1>/initialFreq'
                                        */
  50.0,                                /* Mask Parameter: ChirpSignal_f2
                                        * Referenced by: '<S1>/deltaFreq'
                                        */
  0.02,                                /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S2>/Step'
                                        */
  5.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S2>/Step'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S10>/Constant3'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [1 1 1 1]
   * Referenced by: '<S10>/Constant10'
   */
  { 1.0, 1.0, 1.0, 1.0 },
  4.294967296E+9,                      /* Expression: 2^32
                                        * Referenced by: '<S13>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Theta SP'
                                        */

  /*  Computed Parameter: RTDAC_USB2DeviceDriverTerminate
   * Referenced by: '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Encoder 1024 PPR'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S10>/Convert to rad'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S6>/Gain'
                                        */
  -50.0,                               /* Computed Parameter: filtervelocityencoder_A
                                        * Referenced by: '<S5>/filter velocity (encoder)'
                                        */
  50.0,                                /* Computed Parameter: filtervelocityencoder_C
                                        * Referenced by: '<S5>/filter velocity (encoder)'
                                        */
  -25.5,                               /* Expression: -25.5
                                        * Referenced by: '<S7>/Scale'
                                        */
  1.0,                                 /* Computed Parameter: Simplefilter_D
                                        * Referenced by: '<S7>/Simple filter'
                                        */
  -5.0,                                /* Computed Parameter: filtervelocitytacho_A
                                        * Referenced by: '<S5>/filter velocity (tacho)'
                                        */
  5.0,                                 /* Computed Parameter: filtervelocitytacho_C
                                        * Referenced by: '<S5>/filter velocity (tacho)'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S5>/scale filtered velocity'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/ConvertToAmper'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/ConvertToAmper1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.9999,                              /* Expression: 0.9999
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -0.9999,                             /* Expression: -0.9999
                                        * Referenced by: '<Root>/Saturation'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  4096.0,                              /* Expression: 4096
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit0-Bit12'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit13'
                                        */
  8192.0,                              /* Expression: 2^13
                                        * Referenced by: '<S3>/Gain13'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit14'
                                        */
  16384.0,                             /* Expression: 2^14
                                        * Referenced by: '<S3>/Gain14'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit15'
                                        */
  32768.0,                             /* Expression: 2^15
                                        * Referenced by: '<S3>/Gain18'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit16'
                                        */
  65536.0,                             /* Expression: 2^16
                                        * Referenced by: '<S3>/Gain19'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit17'
                                        */
  131072.0,                            /* Expression: 2^17
                                        * Referenced by: '<S3>/Gain20'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit18-Therm0'
                                        */
  262144.0,                            /* Expression: 2^18
                                        * Referenced by: '<S3>/Gain21'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit19-PWM0'
                                        */
  524288.0,                            /* Expression: 2^19
                                        * Referenced by: '<S3>/Gain22'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit20-Brake0'
                                        */
  1.048576E+6,                         /* Expression: 2^20
                                        * Referenced by: '<S3>/Gain23'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Constant10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant3'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S3>/Switch'
                                        */
  2.097152E+6,                         /* Expression: 2^21
                                        * Referenced by: '<S3>/Gain24'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit22-Therm1'
                                        */
  4.194304E+6,                         /* Expression: 2^22
                                        * Referenced by: '<S3>/Gain25'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit23-PWM1'
                                        */
  8.388608E+6,                         /* Expression: 2^23
                                        * Referenced by: '<S3>/Gain15'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Bit24-Brake1'
                                        */
  1.6777216E+7,                        /* Expression: 2^24
                                        * Referenced by: '<S3>/Gain16'
                                        */
  3.3554432E+7,                        /* Expression: 2^25
                                        * Referenced by: '<S3>/Gain17'
                                        */
  4.718591E+6,                         /* Expression: hex2dec('047FFFF')
                                        * Referenced by: '<S9>/Direction (Input)'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S10>/Switch'
                                        */

  /*  Expression: 0*[1 1 1 1]
   * Referenced by: '<S10>/Constant5'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S10>/Constant6'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: ones(1,16)
   * Referenced by: '<S7>/Constant8'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0 },

  /*  Expression: [0 0 0 0] + 1
   * Referenced by: '<S12>/Constant1'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /*  Expression: 1*[1 1 1 1]
   * Referenced by: '<S12>/Constant2'
   */
  { 1.0, 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant13'
                                        */

  /*  Expression: [ 0 0 0 0 ]
   * Referenced by: '<S6>/Constant14'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S6>/Constant15'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: 8192*[ 1 1 1 1]
   * Referenced by: '<S8>/Constant12'
   */
  { 8192.0, 8192.0, 8192.0, 8192.0 },
  0.0,                                 /* Expression: hex2dec('00')
                                        * Referenced by: '<S11>/Pin Mode (Input)'
                                        */
  2.0E+7,                              /* Expression: 20e6
                                        * Referenced by: '<S13>/Clock Frequency'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */

  /*  Expression: [ 0 0 ]
   * Referenced by: '<S13>/Constant4'
   */
  { 0.0, 0.0 },

  /*  Expression: [ 1 1]
   * Referenced by: '<S13>/Constant7'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  1U,                                  /* Computed Parameter: SigmodeRealtimeonly2_CurrentSet
                                        * Referenced by: '<Root>/Sig mode Real-time only2'
                                        */
  0U,                                  /* Computed Parameter: SigmodeRealtimeonly1_CurrentSet
                                        * Referenced by: '<Root>/Sig mode Real-time only1'
                                        */
  0U                                   /* Computed Parameter: ResetEncodersRealtimeonly_Curre
                                        * Referenced by: '<Root>/Reset Encoders Real-time only'
                                        */
};
