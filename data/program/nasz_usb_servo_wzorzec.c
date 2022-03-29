/*
 * nasz_usb_servo_wzorzec.c
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
#include "nasz_usb_servo_wzorzec_dt.h"

/* Block signals (auto storage) */
B_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_B;

/* Continuous states */
X_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_X;

/* Block states (auto storage) */
DW_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_DW;

/* Real-time model */
RT_MODEL_nasz_usb_servo_wzorzec_T nasz_usb_servo_wzorzec_M_;
RT_MODEL_nasz_usb_servo_wzorzec_T *const nasz_usb_servo_wzorzec_M =
  &nasz_usb_servo_wzorzec_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  nasz_usb_servo_wzorzec_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  nasz_usb_servo_wzorzec_step();
  nasz_usb_servo_wzorzec_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  nasz_usb_servo_wzorzec_step();
  nasz_usb_servo_wzorzec_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  nasz_usb_servo_wzorzec_step();
  nasz_usb_servo_wzorzec_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void nasz_usb_servo_wzorzec_step(void)
{
  /* local block i/o variables */
  real_T rtb_Clock1;
  real_T rtb_Clock1_h;
  real_T rtb_Step;
  real_T rtb_Product_g;
  real_T rtb_Sum2;
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* set solver stop time */
    if (!(nasz_usb_servo_wzorzec_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&nasz_usb_servo_wzorzec_M->solverInfo,
                            ((nasz_usb_servo_wzorzec_M->Timing.clockTickH0 + 1) *
        nasz_usb_servo_wzorzec_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&nasz_usb_servo_wzorzec_M->solverInfo,
                            ((nasz_usb_servo_wzorzec_M->Timing.clockTick0 + 1) *
        nasz_usb_servo_wzorzec_M->Timing.stepSize0 +
        nasz_usb_servo_wzorzec_M->Timing.clockTickH0 *
        nasz_usb_servo_wzorzec_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(nasz_usb_servo_wzorzec_M)) {
    nasz_usb_servo_wzorzec_M->Timing.t[0] = rtsiGetT
      (&nasz_usb_servo_wzorzec_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Constant: '<Root>/Theta SP' */
    nasz_usb_servo_wzorzec_B.ThetaSP = nasz_usb_servo_wzorzec_P.ThetaSP_Value;

    /* Level2 S-Function Block: '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' (rtdacusb2_servo_dd) */
    {
      SimStruct *rts = nasz_usb_servo_wzorzec_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S6>/Gain' incorporates:
     *  Gain: '<S10>/Convert to rad'
     *  Gain: '<S10>/Encoder 1024 PPR'
     */
    nasz_usb_servo_wzorzec_B.Angleencoder =
      nasz_usb_servo_wzorzec_P.Encoder1024PPR_Gain *
      nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_nd[0] *
      nasz_usb_servo_wzorzec_P.Converttorad_Gain *
      nasz_usb_servo_wzorzec_P.Gain_Gain_h;
  }

  /* TransferFcn: '<S5>/filter velocity (encoder)' */
  nasz_usb_servo_wzorzec_B.filteredvelocityencoder = 0.0;
  nasz_usb_servo_wzorzec_B.filteredvelocityencoder +=
    nasz_usb_servo_wzorzec_P.filtervelocityencoder_C *
    nasz_usb_servo_wzorzec_X.filtervelocityencoder_CSTATE;
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Gain: '<S7>/Scale' */
    nasz_usb_servo_wzorzec_B.Scale = nasz_usb_servo_wzorzec_P.Scale_Gain *
      nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_pn[0];
  }

  /* TransferFcn: '<S7>/Simple filter' */
  nasz_usb_servo_wzorzec_B.Simplefilter = 0.0;
  nasz_usb_servo_wzorzec_B.Simplefilter +=
    nasz_usb_servo_wzorzec_P.Simplefilter_D * nasz_usb_servo_wzorzec_B.Scale;

  /* Gain: '<S5>/scale filtered velocity' incorporates:
   *  TransferFcn: '<S5>/filter velocity (tacho)'
   */
  nasz_usb_servo_wzorzec_B.scaledfilteredvelocitytacho =
    nasz_usb_servo_wzorzec_P.filtervelocitytacho_C *
    nasz_usb_servo_wzorzec_X.filtervelocitytacho_CSTATE *
    nasz_usb_servo_wzorzec_P.scalefilteredvelocity_Gain;
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Gain: '<S7>/ConvertToAmper' */
    nasz_usb_servo_wzorzec_B.ConvertToAmper =
      nasz_usb_servo_wzorzec_P.ConvertToAmper_Gain *
      nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_pn[4];

    /* Gain: '<S7>/ConvertToAmper1' */
    nasz_usb_servo_wzorzec_B.ConvertToAmper1 =
      nasz_usb_servo_wzorzec_P.ConvertToAmper1_Gain *
      nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_pn[5];
  }

  /* Clock: '<S2>/Clock' */
  rtb_Clock1_h = nasz_usb_servo_wzorzec_M->Timing.t[0];

  /* Step: '<S2>/Step' */
  if (nasz_usb_servo_wzorzec_M->Timing.t[0] <
      nasz_usb_servo_wzorzec_P.Ramp_start) {
    rtb_Step = nasz_usb_servo_wzorzec_P.Step_Y0;
  } else {
    rtb_Step = nasz_usb_servo_wzorzec_P.Ramp_slope;
  }

  /* End of Step: '<S2>/Step' */

  /* Sum: '<S2>/Output' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Sum'
   */
  rtb_Step = (rtb_Clock1_h - nasz_usb_servo_wzorzec_P.Ramp_start) * rtb_Step +
    nasz_usb_servo_wzorzec_P.Ramp_X0;

  /* Clock: '<S1>/Clock1' */
  rtb_Clock1 = nasz_usb_servo_wzorzec_M->Timing.t[0];
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Gain: '<S1>/Gain' incorporates:
     *  Constant: '<S1>/deltaFreq'
     *  Constant: '<S1>/targetTime'
     *  Product: '<S1>/Product'
     */
    nasz_usb_servo_wzorzec_B.Gain = (nasz_usb_servo_wzorzec_P.ChirpSignal_f2 -
      nasz_usb_servo_wzorzec_P.ChirpSignal_f1) * 6.2831853071795862 /
      nasz_usb_servo_wzorzec_P.ChirpSignal_T
      * nasz_usb_servo_wzorzec_P.Gain_Gain_d;
  }

  /* ManualSwitch: '<Root>/Sig mode Real-time only1' */
  if (nasz_usb_servo_wzorzec_P.SigmodeRealtimeonly1_CurrentSet == 1) {
    /* ManualSwitch: '<Root>/Sig mode Real-time only2' incorporates:
     *  Gain: '<Root>/Gain'
     */
    if (nasz_usb_servo_wzorzec_P.SigmodeRealtimeonly2_CurrentSet == 1) {
      rtb_Clock1_h = nasz_usb_servo_wzorzec_P.Gain_Gain * rtb_Step;
    } else {
      rtb_Clock1_h = rtb_Step;
    }
  } else {
    /* ManualSwitch: '<Root>/Sig mode Real-time only2' incorporates:
     *  Constant: '<S1>/initialFreq'
     *  Product: '<S1>/Product1'
     *  Product: '<S1>/Product2'
     *  Sum: '<S1>/Sum'
     *  Trigonometry: '<S1>/Output'
     */
    rtb_Clock1_h = sin((rtb_Clock1 * nasz_usb_servo_wzorzec_B.Gain +
                        6.2831853071795862 *
                        nasz_usb_servo_wzorzec_P.ChirpSignal_f1) * rtb_Clock1);
  }

  /* End of ManualSwitch: '<Root>/Sig mode Real-time only1' */

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Clock1_h > nasz_usb_servo_wzorzec_P.Saturation_UpperSat) {
    nasz_usb_servo_wzorzec_B.Saturation =
      nasz_usb_servo_wzorzec_P.Saturation_UpperSat;
  } else if (rtb_Clock1_h < nasz_usb_servo_wzorzec_P.Saturation_LowerSat) {
    nasz_usb_servo_wzorzec_B.Saturation =
      nasz_usb_servo_wzorzec_P.Saturation_LowerSat;
  } else {
    nasz_usb_servo_wzorzec_B.Saturation = rtb_Clock1_h;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Scope: '<Root>/Angle & Reference & velocity' */
    if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
      StructLogVar *svar = (StructLogVar *)
        nasz_usb_servo_wzorzec_DW.AngleReferencevelocity_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = nasz_usb_servo_wzorzec_M->Timing.t[1];
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[2];
        up0[0] = nasz_usb_servo_wzorzec_B.ThetaSP;
        up0[1] = nasz_usb_servo_wzorzec_B.Angleencoder;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[3];
        up1[0] = nasz_usb_servo_wzorzec_B.filteredvelocityencoder;
        up1[1] = nasz_usb_servo_wzorzec_B.Simplefilter;
        up1[2] = nasz_usb_servo_wzorzec_B.scaledfilteredvelocitytacho;
        rt_UpdateLogVar((LogVar *)var, up1, 0);
        var = var->next;
      }

      {
        real_T up2[2];
        up2[0] = nasz_usb_servo_wzorzec_B.ConvertToAmper;
        up2[1] = nasz_usb_servo_wzorzec_B.ConvertToAmper1;
        rt_UpdateLogVar((LogVar *)var, up2, 0);
        var = var->next;
      }

      {
        real_T up3[1];
        up3[0] = nasz_usb_servo_wzorzec_B.Saturation;
        rt_UpdateLogVar((LogVar *)var, up3, 0);
      }
    }

    /* ManualSwitch: '<Root>/Reset Encoders Real-time only' incorporates:
     *  Constant: '<Root>/Normal'
     *  Constant: '<Root>/Reset'
     */
    if (nasz_usb_servo_wzorzec_P.ResetEncodersRealtimeonly_Curre == 1) {
      rtb_Sum2 = nasz_usb_servo_wzorzec_P.Reset_Value;
    } else {
      rtb_Sum2 = nasz_usb_servo_wzorzec_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders Real-time only' */
  }

  /* Saturate: '<S3>/Saturation' */
  if (nasz_usb_servo_wzorzec_B.Saturation >
      nasz_usb_servo_wzorzec_P.Saturation_UpperSat_h) {
    rtb_Step = nasz_usb_servo_wzorzec_P.Saturation_UpperSat_h;
  } else if (nasz_usb_servo_wzorzec_B.Saturation <
             nasz_usb_servo_wzorzec_P.Saturation_LowerSat_g) {
    rtb_Step = nasz_usb_servo_wzorzec_P.Saturation_LowerSat_g;
  } else {
    rtb_Step = nasz_usb_servo_wzorzec_B.Saturation;
  }

  /* Gain: '<S3>/Gain1' incorporates:
   *  Saturate: '<S3>/Saturation'
   */
  rtb_Clock1_h = nasz_usb_servo_wzorzec_P.Gain1_Gain * rtb_Step;

  /* Abs: '<S3>/Abs' */
  nasz_usb_servo_wzorzec_B.Abs = fabs(rtb_Clock1_h);
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Gain: '<S3>/Gain13' incorporates:
     *  Constant: '<S3>/Bit13'
     */
    nasz_usb_servo_wzorzec_B.Gain13 = nasz_usb_servo_wzorzec_P.Gain13_Gain *
      nasz_usb_servo_wzorzec_P.Bit13_Value;

    /* Gain: '<S3>/Gain14' incorporates:
     *  Constant: '<S3>/Bit14'
     */
    nasz_usb_servo_wzorzec_B.Gain14 = nasz_usb_servo_wzorzec_P.Gain14_Gain *
      nasz_usb_servo_wzorzec_P.Bit14_Value;

    /* Gain: '<S3>/Gain18' incorporates:
     *  Constant: '<S3>/Bit15'
     */
    nasz_usb_servo_wzorzec_B.Gain18 = nasz_usb_servo_wzorzec_P.Gain18_Gain *
      nasz_usb_servo_wzorzec_P.Bit15_Value;

    /* Gain: '<S3>/Gain19' incorporates:
     *  Constant: '<S3>/Bit16'
     */
    nasz_usb_servo_wzorzec_B.Gain19 = nasz_usb_servo_wzorzec_P.Gain19_Gain *
      nasz_usb_servo_wzorzec_P.Bit16_Value;

    /* Gain: '<S3>/Gain20' incorporates:
     *  Constant: '<S3>/Bit17'
     */
    nasz_usb_servo_wzorzec_B.Gain20 = nasz_usb_servo_wzorzec_P.Gain20_Gain *
      nasz_usb_servo_wzorzec_P.Bit17_Value;

    /* Gain: '<S3>/Gain21' incorporates:
     *  Constant: '<S3>/Bit18-Therm0'
     */
    nasz_usb_servo_wzorzec_B.Gain21 = nasz_usb_servo_wzorzec_P.Gain21_Gain *
      nasz_usb_servo_wzorzec_P.Bit18Therm0_Value;

    /* Gain: '<S3>/Gain22' incorporates:
     *  Constant: '<S3>/Bit19-PWM0'
     */
    nasz_usb_servo_wzorzec_B.Gain22 = nasz_usb_servo_wzorzec_P.Gain22_Gain *
      nasz_usb_servo_wzorzec_P.Bit19PWM0_Value;

    /* Gain: '<S3>/Gain23' incorporates:
     *  Constant: '<S3>/Bit20-Brake0'
     */
    nasz_usb_servo_wzorzec_B.Gain23 = nasz_usb_servo_wzorzec_P.Gain23_Gain *
      nasz_usb_servo_wzorzec_P.Bit20Brake0_Value;
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant3'
   */
  if (rtb_Clock1_h >= nasz_usb_servo_wzorzec_P.Switch_Threshold) {
    rtb_Clock1_h = nasz_usb_servo_wzorzec_P.Constant10_Value_o;
  } else {
    rtb_Clock1_h = nasz_usb_servo_wzorzec_P.Constant3_Value_d;
  }

  /* End of Switch: '<S3>/Switch' */
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Gain: '<S3>/Gain25' incorporates:
     *  Constant: '<S3>/Bit22-Therm1'
     */
    nasz_usb_servo_wzorzec_B.Gain25 = nasz_usb_servo_wzorzec_P.Gain25_Gain *
      nasz_usb_servo_wzorzec_P.Bit22Therm1_Value;

    /* Gain: '<S3>/Gain15' incorporates:
     *  Constant: '<S3>/Bit23-PWM1'
     */
    nasz_usb_servo_wzorzec_B.Gain15 = nasz_usb_servo_wzorzec_P.Gain15_Gain *
      nasz_usb_servo_wzorzec_P.Bit23PWM1_Value;

    /* Gain: '<S3>/Gain16' incorporates:
     *  Constant: '<S3>/Bit24-Brake1'
     */
    nasz_usb_servo_wzorzec_B.Gain16 = nasz_usb_servo_wzorzec_P.Gain16_Gain *
      nasz_usb_servo_wzorzec_P.Bit24Brake1_Value;
  }

  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Constant: '<S9>/Direction (Input)' */
    nasz_usb_servo_wzorzec_B.DirectionInput =
      nasz_usb_servo_wzorzec_P.DirectionInput_Value;

    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/Constant10'
     *  Constant: '<S10>/Constant3'
     */
    if (rtb_Sum2 >= nasz_usb_servo_wzorzec_P.Switch_Threshold_p) {
      nasz_usb_servo_wzorzec_B.Switch[0] =
        nasz_usb_servo_wzorzec_P.Constant10_Value[0];
      nasz_usb_servo_wzorzec_B.Switch[1] =
        nasz_usb_servo_wzorzec_P.Constant10_Value[1];
      nasz_usb_servo_wzorzec_B.Switch[2] =
        nasz_usb_servo_wzorzec_P.Constant10_Value[2];
      nasz_usb_servo_wzorzec_B.Switch[3] =
        nasz_usb_servo_wzorzec_P.Constant10_Value[3];
    } else {
      nasz_usb_servo_wzorzec_B.Switch[0] =
        nasz_usb_servo_wzorzec_P.Constant3_Value[0];
      nasz_usb_servo_wzorzec_B.Switch[1] =
        nasz_usb_servo_wzorzec_P.Constant3_Value[1];
      nasz_usb_servo_wzorzec_B.Switch[2] =
        nasz_usb_servo_wzorzec_P.Constant3_Value[2];
      nasz_usb_servo_wzorzec_B.Switch[3] =
        nasz_usb_servo_wzorzec_P.Constant3_Value[3];
    }

    /* End of Switch: '<S10>/Switch' */

    /* Constant: '<S10>/Constant5' */
    nasz_usb_servo_wzorzec_B.Constant5[0] =
      nasz_usb_servo_wzorzec_P.Constant5_Value[0];
    nasz_usb_servo_wzorzec_B.Constant5[1] =
      nasz_usb_servo_wzorzec_P.Constant5_Value[1];
    nasz_usb_servo_wzorzec_B.Constant5[2] =
      nasz_usb_servo_wzorzec_P.Constant5_Value[2];
    nasz_usb_servo_wzorzec_B.Constant5[3] =
      nasz_usb_servo_wzorzec_P.Constant5_Value[3];

    /* Constant: '<S10>/Constant6' */
    nasz_usb_servo_wzorzec_B.Constant6[0] =
      nasz_usb_servo_wzorzec_P.Constant6_Value[0];
    nasz_usb_servo_wzorzec_B.Constant6[1] =
      nasz_usb_servo_wzorzec_P.Constant6_Value[1];
    nasz_usb_servo_wzorzec_B.Constant6[2] =
      nasz_usb_servo_wzorzec_P.Constant6_Value[2];
    nasz_usb_servo_wzorzec_B.Constant6[3] =
      nasz_usb_servo_wzorzec_P.Constant6_Value[3];

    /* Constant: '<S7>/Constant8' */
    memcpy(&nasz_usb_servo_wzorzec_B.Constant8[0],
           &nasz_usb_servo_wzorzec_P.Constant8_Value[0], sizeof(real_T) << 4U);

    /* Constant: '<S12>/Constant1' */
    nasz_usb_servo_wzorzec_B.Constant1[0] =
      nasz_usb_servo_wzorzec_P.Constant1_Value_e[0];
    nasz_usb_servo_wzorzec_B.Constant1[1] =
      nasz_usb_servo_wzorzec_P.Constant1_Value_e[1];
    nasz_usb_servo_wzorzec_B.Constant1[2] =
      nasz_usb_servo_wzorzec_P.Constant1_Value_e[2];
    nasz_usb_servo_wzorzec_B.Constant1[3] =
      nasz_usb_servo_wzorzec_P.Constant1_Value_e[3];

    /* Constant: '<S12>/Constant2' */
    nasz_usb_servo_wzorzec_B.Constant2[0] =
      nasz_usb_servo_wzorzec_P.Constant2_Value[0];
    nasz_usb_servo_wzorzec_B.Constant2[1] =
      nasz_usb_servo_wzorzec_P.Constant2_Value[1];
    nasz_usb_servo_wzorzec_B.Constant2[2] =
      nasz_usb_servo_wzorzec_P.Constant2_Value[2];
    nasz_usb_servo_wzorzec_B.Constant2[3] =
      nasz_usb_servo_wzorzec_P.Constant2_Value[3];

    /* Constant: '<S6>/Constant13' */
    nasz_usb_servo_wzorzec_B.Constant13 =
      nasz_usb_servo_wzorzec_P.Constant13_Value;

    /* Constant: '<S6>/Constant14' */
    nasz_usb_servo_wzorzec_B.Constant14[0] =
      nasz_usb_servo_wzorzec_P.Constant14_Value[0];
    nasz_usb_servo_wzorzec_B.Constant14[1] =
      nasz_usb_servo_wzorzec_P.Constant14_Value[1];
    nasz_usb_servo_wzorzec_B.Constant14[2] =
      nasz_usb_servo_wzorzec_P.Constant14_Value[2];
    nasz_usb_servo_wzorzec_B.Constant14[3] =
      nasz_usb_servo_wzorzec_P.Constant14_Value[3];

    /* Constant: '<S6>/Constant15' */
    nasz_usb_servo_wzorzec_B.Constant15[0] =
      nasz_usb_servo_wzorzec_P.Constant15_Value[0];
    nasz_usb_servo_wzorzec_B.Constant15[1] =
      nasz_usb_servo_wzorzec_P.Constant15_Value[1];
    nasz_usb_servo_wzorzec_B.Constant15[2] =
      nasz_usb_servo_wzorzec_P.Constant15_Value[2];
    nasz_usb_servo_wzorzec_B.Constant15[3] =
      nasz_usb_servo_wzorzec_P.Constant15_Value[3];

    /* Constant: '<S8>/Constant12' */
    nasz_usb_servo_wzorzec_B.Constant12[0] =
      nasz_usb_servo_wzorzec_P.Constant12_Value[0];
    nasz_usb_servo_wzorzec_B.Constant12[1] =
      nasz_usb_servo_wzorzec_P.Constant12_Value[1];
    nasz_usb_servo_wzorzec_B.Constant12[2] =
      nasz_usb_servo_wzorzec_P.Constant12_Value[2];
    nasz_usb_servo_wzorzec_B.Constant12[3] =
      nasz_usb_servo_wzorzec_P.Constant12_Value[3];

    /* Constant: '<S11>/Pin Mode (Input)' */
    nasz_usb_servo_wzorzec_B.PinModeInput =
      nasz_usb_servo_wzorzec_P.PinModeInput_Value;

    /* Sum: '<S13>/Sum2' incorporates:
     *  Memory: '<S13>/Memory2'
     */
    rtb_Sum2 = nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_em[0] -
      nasz_usb_servo_wzorzec_DW.Memory2_PreviousInput;

    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Sum: '<S13>/Sum1'
     */
    if (!(rtb_Sum2 > nasz_usb_servo_wzorzec_P.Switch_Threshold_a)) {
      rtb_Sum2 += nasz_usb_servo_wzorzec_P.Constant1_Value;
    }

    /* End of Switch: '<S13>/Switch' */

    /* MinMax: '<S13>/MinMax' incorporates:
     *  Constant: '<S13>/Constant'
     */
    if (!((rtb_Sum2 >= nasz_usb_servo_wzorzec_P.Constant_Value) || rtIsNaN
          (nasz_usb_servo_wzorzec_P.Constant_Value))) {
      rtb_Sum2 = nasz_usb_servo_wzorzec_P.Constant_Value;
    }

    /* Product: '<S13>/Product' incorporates:
     *  Constant: '<S13>/Clock Frequency'
     *  MinMax: '<S13>/MinMax'
     */
    rtb_Product_g = rtb_Sum2 / nasz_usb_servo_wzorzec_P.ClockFrequency_Value;

    /* Constant: '<S13>/Constant4' */
    nasz_usb_servo_wzorzec_B.Constant4[0] =
      nasz_usb_servo_wzorzec_P.Constant4_Value[0];
    nasz_usb_servo_wzorzec_B.Constant4[1] =
      nasz_usb_servo_wzorzec_P.Constant4_Value[1];

    /* Constant: '<S13>/Constant7' */
    nasz_usb_servo_wzorzec_B.Constant7[0] =
      nasz_usb_servo_wzorzec_P.Constant7_Value[0];
    nasz_usb_servo_wzorzec_B.Constant7[1] =
      nasz_usb_servo_wzorzec_P.Constant7_Value[1];
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/Bit0-Bit12'
   *  Gain: '<S3>/Gain17'
   *  Gain: '<S3>/Gain24'
   *  Sum: '<S3>/Bit13-Bit25'
   */
  nasz_usb_servo_wzorzec_B.Sum = ((((((((((((nasz_usb_servo_wzorzec_B.Gain13 +
    nasz_usb_servo_wzorzec_B.Gain14) + nasz_usb_servo_wzorzec_B.Gain18) +
    nasz_usb_servo_wzorzec_B.Gain19) + nasz_usb_servo_wzorzec_B.Gain20) +
    nasz_usb_servo_wzorzec_B.Gain21) + nasz_usb_servo_wzorzec_B.Gain22) +
    nasz_usb_servo_wzorzec_B.Gain23) + nasz_usb_servo_wzorzec_P.Gain24_Gain *
    rtb_Clock1_h) + nasz_usb_servo_wzorzec_B.Gain25) +
    nasz_usb_servo_wzorzec_B.Gain15) + nasz_usb_servo_wzorzec_B.Gain16) +
    nasz_usb_servo_wzorzec_P.Gain17_Gain * rtb_Clock1_h) +
    nasz_usb_servo_wzorzec_P.Bit0Bit12_Value;

  /* Clock: '<S14>/Clock1' */
  rtb_Clock1_h = nasz_usb_servo_wzorzec_M->Timing.t[0];
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Product: '<S14>/Product' incorporates:
     *  Memory: '<S14>/Memory1'
     *  Sum: '<S14>/Sum1'
     */
    nasz_usb_servo_wzorzec_B.Product = (nasz_usb_servo_wzorzec_B.Angleencoder -
      nasz_usb_servo_wzorzec_DW.Memory1_PreviousInput) / rtb_Product_g;
  }

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  if (rtb_Clock1_h > nasz_usb_servo_wzorzec_P.Switch_Threshold_a5) {
    nasz_usb_servo_wzorzec_B.Switch_n = nasz_usb_servo_wzorzec_B.Product;
  } else {
    nasz_usb_servo_wzorzec_B.Switch_n =
      nasz_usb_servo_wzorzec_P.Constant1_Value_e5;
  }

  /* End of Switch: '<S14>/Switch' */
  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
  }

  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(nasz_usb_servo_wzorzec_M->rtwLogInfo,
                        (nasz_usb_servo_wzorzec_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
      /* Update for Memory: '<S13>/Memory2' */
      nasz_usb_servo_wzorzec_DW.Memory2_PreviousInput =
        nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_em[0];

      /* Update for Memory: '<S14>/Memory1' */
      nasz_usb_servo_wzorzec_DW.Memory1_PreviousInput =
        nasz_usb_servo_wzorzec_B.Angleencoder;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, nasz_usb_servo_wzorzec_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {/* Sample time: [0.01s, 0.0s] */
      rtExtModeUpload(1, nasz_usb_servo_wzorzec_M->Timing.t[1]);
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(nasz_usb_servo_wzorzec_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(nasz_usb_servo_wzorzec_M)!=-1) &&
          !((rtmGetTFinal(nasz_usb_servo_wzorzec_M)-
             nasz_usb_servo_wzorzec_M->Timing.t[1]) >
            nasz_usb_servo_wzorzec_M->Timing.t[1] * (DBL_EPSILON))) {
        rtmSetErrorStatus(nasz_usb_servo_wzorzec_M, "Simulation finished");
      }

      if (rtmGetStopRequested(nasz_usb_servo_wzorzec_M)) {
        rtmSetErrorStatus(nasz_usb_servo_wzorzec_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&nasz_usb_servo_wzorzec_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++nasz_usb_servo_wzorzec_M->Timing.clockTick0)) {
      ++nasz_usb_servo_wzorzec_M->Timing.clockTickH0;
    }

    nasz_usb_servo_wzorzec_M->Timing.t[0] = rtsiGetSolverStopTime
      (&nasz_usb_servo_wzorzec_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The absolute time is the multiplication of "clockTick1"
       * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
       * overflow during the application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      if (!(++nasz_usb_servo_wzorzec_M->Timing.clockTick1)) {
        ++nasz_usb_servo_wzorzec_M->Timing.clockTickH1;
      }

      nasz_usb_servo_wzorzec_M->Timing.t[1] =
        nasz_usb_servo_wzorzec_M->Timing.clockTick1 *
        nasz_usb_servo_wzorzec_M->Timing.stepSize1 +
        nasz_usb_servo_wzorzec_M->Timing.clockTickH1 *
        nasz_usb_servo_wzorzec_M->Timing.stepSize1 * 4294967296.0;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void nasz_usb_servo_wzorzec_derivatives(void)
{
  XDot_nasz_usb_servo_wzorzec_T *_rtXdot;
  _rtXdot = ((XDot_nasz_usb_servo_wzorzec_T *)
             nasz_usb_servo_wzorzec_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S5>/filter velocity (encoder)' */
  _rtXdot->filtervelocityencoder_CSTATE = 0.0;
  _rtXdot->filtervelocityencoder_CSTATE +=
    nasz_usb_servo_wzorzec_P.filtervelocityencoder_A *
    nasz_usb_servo_wzorzec_X.filtervelocityencoder_CSTATE;
  _rtXdot->filtervelocityencoder_CSTATE += nasz_usb_servo_wzorzec_B.Switch_n;

  /* Derivatives for TransferFcn: '<S5>/filter velocity (tacho)' */
  _rtXdot->filtervelocitytacho_CSTATE = 0.0;
  _rtXdot->filtervelocitytacho_CSTATE +=
    nasz_usb_servo_wzorzec_P.filtervelocitytacho_A *
    nasz_usb_servo_wzorzec_X.filtervelocitytacho_CSTATE;
  _rtXdot->filtervelocitytacho_CSTATE += nasz_usb_servo_wzorzec_B.Simplefilter;
}

/* Model initialize function */
void nasz_usb_servo_wzorzec_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)nasz_usb_servo_wzorzec_M, 0,
                sizeof(RT_MODEL_nasz_usb_servo_wzorzec_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&nasz_usb_servo_wzorzec_M->solverInfo,
                          &nasz_usb_servo_wzorzec_M->Timing.simTimeStep);
    rtsiSetTPtr(&nasz_usb_servo_wzorzec_M->solverInfo, &rtmGetTPtr
                (nasz_usb_servo_wzorzec_M));
    rtsiSetStepSizePtr(&nasz_usb_servo_wzorzec_M->solverInfo,
                       &nasz_usb_servo_wzorzec_M->Timing.stepSize0);
    rtsiSetdXPtr(&nasz_usb_servo_wzorzec_M->solverInfo,
                 &nasz_usb_servo_wzorzec_M->ModelData.derivs);
    rtsiSetContStatesPtr(&nasz_usb_servo_wzorzec_M->solverInfo, (real_T **)
                         &nasz_usb_servo_wzorzec_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&nasz_usb_servo_wzorzec_M->solverInfo,
      &nasz_usb_servo_wzorzec_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&nasz_usb_servo_wzorzec_M->solverInfo,
                          (&rtmGetErrorStatus(nasz_usb_servo_wzorzec_M)));
    rtsiSetRTModelPtr(&nasz_usb_servo_wzorzec_M->solverInfo,
                      nasz_usb_servo_wzorzec_M);
  }

  rtsiSetSimTimeStep(&nasz_usb_servo_wzorzec_M->solverInfo, MAJOR_TIME_STEP);
  nasz_usb_servo_wzorzec_M->ModelData.intgData.y =
    nasz_usb_servo_wzorzec_M->ModelData.odeY;
  nasz_usb_servo_wzorzec_M->ModelData.intgData.f[0] =
    nasz_usb_servo_wzorzec_M->ModelData.odeF[0];
  nasz_usb_servo_wzorzec_M->ModelData.intgData.f[1] =
    nasz_usb_servo_wzorzec_M->ModelData.odeF[1];
  nasz_usb_servo_wzorzec_M->ModelData.intgData.f[2] =
    nasz_usb_servo_wzorzec_M->ModelData.odeF[2];
  nasz_usb_servo_wzorzec_M->ModelData.intgData.f[3] =
    nasz_usb_servo_wzorzec_M->ModelData.odeF[3];
  nasz_usb_servo_wzorzec_M->ModelData.contStates = ((X_nasz_usb_servo_wzorzec_T *)
    &nasz_usb_servo_wzorzec_X);
  rtsiSetSolverData(&nasz_usb_servo_wzorzec_M->solverInfo, (void *)
                    &nasz_usb_servo_wzorzec_M->ModelData.intgData);
  rtsiSetSolverName(&nasz_usb_servo_wzorzec_M->solverInfo,"ode4");
  nasz_usb_servo_wzorzec_M->solverInfoPtr =
    (&nasz_usb_servo_wzorzec_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = nasz_usb_servo_wzorzec_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    nasz_usb_servo_wzorzec_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    nasz_usb_servo_wzorzec_M->Timing.sampleTimes =
      (&nasz_usb_servo_wzorzec_M->Timing.sampleTimesArray[0]);
    nasz_usb_servo_wzorzec_M->Timing.offsetTimes =
      (&nasz_usb_servo_wzorzec_M->Timing.offsetTimesArray[0]);

    /* task periods */
    nasz_usb_servo_wzorzec_M->Timing.sampleTimes[0] = (0.0);
    nasz_usb_servo_wzorzec_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    nasz_usb_servo_wzorzec_M->Timing.offsetTimes[0] = (0.0);
    nasz_usb_servo_wzorzec_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(nasz_usb_servo_wzorzec_M, &nasz_usb_servo_wzorzec_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = nasz_usb_servo_wzorzec_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    nasz_usb_servo_wzorzec_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(nasz_usb_servo_wzorzec_M, 300.0);
  nasz_usb_servo_wzorzec_M->Timing.stepSize0 = 0.01;
  nasz_usb_servo_wzorzec_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    nasz_usb_servo_wzorzec_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(nasz_usb_servo_wzorzec_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(nasz_usb_servo_wzorzec_M->rtwLogInfo, (NULL));
    rtliSetLogT(nasz_usb_servo_wzorzec_M->rtwLogInfo, "");
    rtliSetLogX(nasz_usb_servo_wzorzec_M->rtwLogInfo, "");
    rtliSetLogXFinal(nasz_usb_servo_wzorzec_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(nasz_usb_servo_wzorzec_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(nasz_usb_servo_wzorzec_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(nasz_usb_servo_wzorzec_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(nasz_usb_servo_wzorzec_M->rtwLogInfo, 1);
    rtliSetLogY(nasz_usb_servo_wzorzec_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(nasz_usb_servo_wzorzec_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(nasz_usb_servo_wzorzec_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  nasz_usb_servo_wzorzec_M->Sizes.checksums[0] = (2190976335U);
  nasz_usb_servo_wzorzec_M->Sizes.checksums[1] = (1250969628U);
  nasz_usb_servo_wzorzec_M->Sizes.checksums[2] = (1231406533U);
  nasz_usb_servo_wzorzec_M->Sizes.checksums[3] = (2226924262U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    nasz_usb_servo_wzorzec_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(nasz_usb_servo_wzorzec_M->extModeInfo,
      &nasz_usb_servo_wzorzec_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(nasz_usb_servo_wzorzec_M->extModeInfo,
                        nasz_usb_servo_wzorzec_M->Sizes.checksums);
    rteiSetTPtr(nasz_usb_servo_wzorzec_M->extModeInfo, rtmGetTPtr
                (nasz_usb_servo_wzorzec_M));
  }

  nasz_usb_servo_wzorzec_M->solverInfoPtr =
    (&nasz_usb_servo_wzorzec_M->solverInfo);
  nasz_usb_servo_wzorzec_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&nasz_usb_servo_wzorzec_M->solverInfo, 0.01);
  rtsiSetSolverMode(&nasz_usb_servo_wzorzec_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  {
    int32_T i;
    for (i = 0; i < 16; i++) {
      nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_d[i] = 0.0;
    }

    for (i = 0; i < 16; i++) {
      nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_pn[i] = 0.0;
    }

    for (i = 0; i < 16; i++) {
      nasz_usb_servo_wzorzec_B.Constant8[i] = 0.0;
    }

    nasz_usb_servo_wzorzec_B.ThetaSP = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTerminate = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_h = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_e = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_p = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_m = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_n[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_n[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_n[2] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_n[3] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_b[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_b[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_b[2] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_b[3] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_k[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_k[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_k[2] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_k[3] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_nd[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_nd[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_nd[2] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_nd[3] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_a[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_a[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_a[2] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_a[3] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_p1[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_p1[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_p1[2] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_p1[3] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_af[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_af[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_af[2] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_af[3] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_hh[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_hh[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_o[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_o[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_em[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_em[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_e2[0] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_e2[1] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_e2[2] = 0.0;
    nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_e2[3] = 0.0;
    nasz_usb_servo_wzorzec_B.Angleencoder = 0.0;
    nasz_usb_servo_wzorzec_B.filteredvelocityencoder = 0.0;
    nasz_usb_servo_wzorzec_B.Scale = 0.0;
    nasz_usb_servo_wzorzec_B.Simplefilter = 0.0;
    nasz_usb_servo_wzorzec_B.scaledfilteredvelocitytacho = 0.0;
    nasz_usb_servo_wzorzec_B.ConvertToAmper = 0.0;
    nasz_usb_servo_wzorzec_B.ConvertToAmper1 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain = 0.0;
    nasz_usb_servo_wzorzec_B.Saturation = 0.0;
    nasz_usb_servo_wzorzec_B.Abs = 0.0;
    nasz_usb_servo_wzorzec_B.Gain13 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain14 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain18 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain19 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain20 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain21 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain22 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain23 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain25 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain15 = 0.0;
    nasz_usb_servo_wzorzec_B.Gain16 = 0.0;
    nasz_usb_servo_wzorzec_B.DirectionInput = 0.0;
    nasz_usb_servo_wzorzec_B.Switch[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Switch[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Switch[2] = 0.0;
    nasz_usb_servo_wzorzec_B.Switch[3] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant5[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant5[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant5[2] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant5[3] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant6[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant6[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant6[2] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant6[3] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant1[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant1[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant1[2] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant1[3] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant2[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant2[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant2[2] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant2[3] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant13 = 0.0;
    nasz_usb_servo_wzorzec_B.Constant14[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant14[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant14[2] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant14[3] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant15[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant15[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant15[2] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant15[3] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant12[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant12[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant12[2] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant12[3] = 0.0;
    nasz_usb_servo_wzorzec_B.PinModeInput = 0.0;
    nasz_usb_servo_wzorzec_B.Constant4[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant4[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant7[0] = 0.0;
    nasz_usb_servo_wzorzec_B.Constant7[1] = 0.0;
    nasz_usb_servo_wzorzec_B.Sum = 0.0;
    nasz_usb_servo_wzorzec_B.Product = 0.0;
    nasz_usb_servo_wzorzec_B.Switch_n = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&nasz_usb_servo_wzorzec_X, 0,
                  sizeof(X_nasz_usb_servo_wzorzec_T));
  }

  /* states (dwork) */
  (void) memset((void *)&nasz_usb_servo_wzorzec_DW, 0,
                sizeof(DW_nasz_usb_servo_wzorzec_T));
  nasz_usb_servo_wzorzec_DW.Memory2_PreviousInput = 0.0;
  nasz_usb_servo_wzorzec_DW.Memory1_PreviousInput = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    nasz_usb_servo_wzorzec_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.sfcnInfo;
    nasz_usb_servo_wzorzec_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(nasz_usb_servo_wzorzec_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &nasz_usb_servo_wzorzec_M->Sizes.numSampTimes);
    nasz_usb_servo_wzorzec_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (nasz_usb_servo_wzorzec_M)[0]);
    nasz_usb_servo_wzorzec_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (nasz_usb_servo_wzorzec_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   nasz_usb_servo_wzorzec_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(nasz_usb_servo_wzorzec_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(nasz_usb_servo_wzorzec_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (nasz_usb_servo_wzorzec_M));
    rtssSetStepSizePtr(sfcnInfo, &nasz_usb_servo_wzorzec_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (nasz_usb_servo_wzorzec_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &nasz_usb_servo_wzorzec_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &nasz_usb_servo_wzorzec_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &nasz_usb_servo_wzorzec_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &nasz_usb_servo_wzorzec_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &nasz_usb_servo_wzorzec_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &nasz_usb_servo_wzorzec_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &nasz_usb_servo_wzorzec_M->solverInfoPtr);
  }

  nasz_usb_servo_wzorzec_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)
                  &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    nasz_usb_servo_wzorzec_M->childSfunctions =
      (&nasz_usb_servo_wzorzec_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    nasz_usb_servo_wzorzec_M->childSfunctions[0] =
      (&nasz_usb_servo_wzorzec_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: nasz_usb_servo_wzorzec/<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11 (rtdacusb2_servo_dd) */
    {
      SimStruct *rts = nasz_usb_servo_wzorzec_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, nasz_usb_servo_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.statesInfo2
                         [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 16);
        ssSetPortInfoForInputs(rts,
          &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &nasz_usb_servo_wzorzec_B.PinModeInput;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &nasz_usb_servo_wzorzec_B.DirectionInput;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs2;
          sfcnUPtrs[0] = &nasz_usb_servo_wzorzec_B.Sum;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant1;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant1[1];
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Constant1[2];
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Constant1[3];
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 4);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs4;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant2;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant2[1];
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Constant2[2];
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Constant2[3];
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 4);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs5;
          sfcnUPtrs[0] = &nasz_usb_servo_wzorzec_B.Abs;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Abs;
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Abs;
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Abs;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 4);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs6;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Switch;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Switch[1];
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Switch[2];
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Switch[3];
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 4);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs7;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant5;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant5[1];
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Constant5[2];
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Constant5[3];
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 4);
        }

        /* port 8 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs8;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant6;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant6[1];
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Constant6[2];
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Constant6[3];
          ssSetInputPortSignalPtrs(rts, 8, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 8, 1);
          ssSetInputPortWidth(rts, 8, 4);
        }

        /* port 9 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs9;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant4;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant4[1];
          ssSetInputPortSignalPtrs(rts, 9, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 9, 1);
          ssSetInputPortWidth(rts, 9, 2);
        }

        /* port 10 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs10;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant7;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant7[1];
          ssSetInputPortSignalPtrs(rts, 10, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 10, 1);
          ssSetInputPortWidth(rts, 10, 2);
        }

        /* port 11 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs11;

          {
            int_T i1;
            const real_T *u11 = nasz_usb_servo_wzorzec_B.Constant8;
            for (i1=0; i1 < 16; i1++) {
              sfcnUPtrs[i1] = &u11[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 11, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 11, 1);
          ssSetInputPortWidth(rts, 11, 16);
        }

        /* port 12 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs12;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant12;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant12[1];
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Constant12[2];
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Constant12[3];
          ssSetInputPortSignalPtrs(rts, 12, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 12, 1);
          ssSetInputPortWidth(rts, 12, 4);
        }

        /* port 13 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs13;
          sfcnUPtrs[0] = &nasz_usb_servo_wzorzec_B.Constant13;
          ssSetInputPortSignalPtrs(rts, 13, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 13, 1);
          ssSetInputPortWidth(rts, 13, 1);
        }

        /* port 14 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs14;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant14;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant14[1];
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Constant14[2];
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Constant14[3];
          ssSetInputPortSignalPtrs(rts, 14, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 14, 1);
          ssSetInputPortWidth(rts, 14, 4);
        }

        /* port 15 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.UPtrs15;
          sfcnUPtrs[0] = nasz_usb_servo_wzorzec_B.Constant15;
          sfcnUPtrs[1] = &nasz_usb_servo_wzorzec_B.Constant15[1];
          sfcnUPtrs[2] = &nasz_usb_servo_wzorzec_B.Constant15[2];
          sfcnUPtrs[3] = &nasz_usb_servo_wzorzec_B.Constant15[3];
          ssSetInputPortSignalPtrs(rts, 15, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 15, 1);
          ssSetInputPortWidth(rts, 15, 4);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 18);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTerminate));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_h));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_e));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_p));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_m));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 4);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_n));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 4);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_b));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 4);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_k));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 4);
          ssSetOutputPortSignal(rts, 8, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_nd));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 4);
          ssSetOutputPortSignal(rts, 9, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_a));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 4);
          ssSetOutputPortSignal(rts, 10, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_p1));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 4);
          ssSetOutputPortSignal(rts, 11, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_af));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 2);
          ssSetOutputPortSignal(rts, 12, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_hh));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 2);
          ssSetOutputPortSignal(rts, 13, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_o));
        }

        /* port 14 */
        {
          _ssSetOutputPortNumDimensions(rts, 14, 1);
          ssSetOutputPortWidth(rts, 14, 2);
          ssSetOutputPortSignal(rts, 14, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_em));
        }

        /* port 15 */
        {
          _ssSetOutputPortNumDimensions(rts, 15, 1);
          ssSetOutputPortWidth(rts, 15, 16);
          ssSetOutputPortSignal(rts, 15, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_d));
        }

        /* port 16 */
        {
          _ssSetOutputPortNumDimensions(rts, 16, 1);
          ssSetOutputPortWidth(rts, 16, 16);
          ssSetOutputPortSignal(rts, 16, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_pn));
        }

        /* port 17 */
        {
          _ssSetOutputPortNumDimensions(rts, 17, 1);
          ssSetOutputPortWidth(rts, 17, 4);
          ssSetOutputPortSignal(rts, 17, ((real_T *)
            nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_e2));
        }
      }

      /* path info */
      ssSetModelName(rts, "RTDAC_USB2 Device Driver\nTerminated Version 2.11");
      ssSetPath(rts,
                "nasz_usb_servo_wzorzec/Servo/RT-DAC//USB2 Generic Driver Customised for Servo/RTDAC_USB2 Device Driver Terminated Version 2.11");
      ssSetRTModel(rts,nasz_usb_servo_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &nasz_usb_servo_wzorzec_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       nasz_usb_servo_wzorzec_P.RTDAC_USB2DeviceDriverTerminate);
      }

      /* registration */
      rtdacusb2_servo_dd(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetInputPortConnected(rts, 6, 1);
      _ssSetInputPortConnected(rts, 7, 1);
      _ssSetInputPortConnected(rts, 8, 1);
      _ssSetInputPortConnected(rts, 9, 1);
      _ssSetInputPortConnected(rts, 10, 1);
      _ssSetInputPortConnected(rts, 11, 1);
      _ssSetInputPortConnected(rts, 12, 1);
      _ssSetInputPortConnected(rts, 13, 1);
      _ssSetInputPortConnected(rts, 14, 1);
      _ssSetInputPortConnected(rts, 15, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 1);
      _ssSetOutputPortConnected(rts, 12, 1);
      _ssSetOutputPortConnected(rts, 13, 1);
      _ssSetOutputPortConnected(rts, 14, 1);
      _ssSetOutputPortConnected(rts, 15, 1);
      _ssSetOutputPortConnected(rts, 16, 1);
      _ssSetOutputPortConnected(rts, 17, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);
      _ssSetOutputPortBeingMerged(rts, 12, 0);
      _ssSetOutputPortBeingMerged(rts, 13, 0);
      _ssSetOutputPortBeingMerged(rts, 14, 0);
      _ssSetOutputPortBeingMerged(rts, 15, 0);
      _ssSetOutputPortBeingMerged(rts, 16, 0);
      _ssSetOutputPortBeingMerged(rts, 17, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
      ssSetInputPortBufferDstPort(rts, 7, -1);
      ssSetInputPortBufferDstPort(rts, 8, -1);
      ssSetInputPortBufferDstPort(rts, 9, -1);
      ssSetInputPortBufferDstPort(rts, 10, -1);
      ssSetInputPortBufferDstPort(rts, 11, -1);
      ssSetInputPortBufferDstPort(rts, 12, -1);
      ssSetInputPortBufferDstPort(rts, 13, -1);
      ssSetInputPortBufferDstPort(rts, 14, -1);
      ssSetInputPortBufferDstPort(rts, 15, -1);
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(nasz_usb_servo_wzorzec_M->rtwLogInfo, 0.0,
    rtmGetTFinal(nasz_usb_servo_wzorzec_M),
    nasz_usb_servo_wzorzec_M->Timing.stepSize0, (&rtmGetErrorStatus
    (nasz_usb_servo_wzorzec_M)));

  /* Level2 S-Function Block: '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' (rtdacusb2_servo_dd) */
  {
    SimStruct *rts = nasz_usb_servo_wzorzec_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Angle & Reference & velocity' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 2, 3, 2, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 2, 3, 2, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "Angle & ref",
      "",
      "",
      "" };

    static char_T rt_ScopeSignalTitles[] = "Angle & ref";
    static int_T rt_ScopeSignalTitleLengths[] = { 11, 0, 0, 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 0, 0, 0, 1, 1, 0 };

    BuiltInDTypeId dTypes[4] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] =
      "nasz_usb_servo_wzorzec/Angle & Reference\n& velocity";
    rt_ScopeSignalInfo.numSignals = 4;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    nasz_usb_servo_wzorzec_DW.AngleReferencevelocity_PWORK.LoggedData =
      rt_CreateStructLogVar(
      nasz_usb_servo_wzorzec_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(nasz_usb_servo_wzorzec_M),
      nasz_usb_servo_wzorzec_M->Timing.stepSize0,
      (&rtmGetErrorStatus(nasz_usb_servo_wzorzec_M)),
      "PD_C",
      1,
      0,
      2,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (nasz_usb_servo_wzorzec_DW.AngleReferencevelocity_PWORK.LoggedData ==
        (NULL))
      return;
  }

  /* Start for Constant: '<S9>/Direction (Input)' */
  nasz_usb_servo_wzorzec_B.DirectionInput =
    nasz_usb_servo_wzorzec_P.DirectionInput_Value;

  /* Start for Constant: '<S10>/Constant5' */
  nasz_usb_servo_wzorzec_B.Constant5[0] =
    nasz_usb_servo_wzorzec_P.Constant5_Value[0];
  nasz_usb_servo_wzorzec_B.Constant5[1] =
    nasz_usb_servo_wzorzec_P.Constant5_Value[1];
  nasz_usb_servo_wzorzec_B.Constant5[2] =
    nasz_usb_servo_wzorzec_P.Constant5_Value[2];
  nasz_usb_servo_wzorzec_B.Constant5[3] =
    nasz_usb_servo_wzorzec_P.Constant5_Value[3];

  /* Start for Constant: '<S10>/Constant6' */
  nasz_usb_servo_wzorzec_B.Constant6[0] =
    nasz_usb_servo_wzorzec_P.Constant6_Value[0];
  nasz_usb_servo_wzorzec_B.Constant6[1] =
    nasz_usb_servo_wzorzec_P.Constant6_Value[1];
  nasz_usb_servo_wzorzec_B.Constant6[2] =
    nasz_usb_servo_wzorzec_P.Constant6_Value[2];
  nasz_usb_servo_wzorzec_B.Constant6[3] =
    nasz_usb_servo_wzorzec_P.Constant6_Value[3];

  /* Start for Constant: '<S7>/Constant8' */
  memcpy(&nasz_usb_servo_wzorzec_B.Constant8[0],
         &nasz_usb_servo_wzorzec_P.Constant8_Value[0], sizeof(real_T) << 4U);

  /* Start for Constant: '<S12>/Constant1' */
  nasz_usb_servo_wzorzec_B.Constant1[0] =
    nasz_usb_servo_wzorzec_P.Constant1_Value_e[0];
  nasz_usb_servo_wzorzec_B.Constant1[1] =
    nasz_usb_servo_wzorzec_P.Constant1_Value_e[1];
  nasz_usb_servo_wzorzec_B.Constant1[2] =
    nasz_usb_servo_wzorzec_P.Constant1_Value_e[2];
  nasz_usb_servo_wzorzec_B.Constant1[3] =
    nasz_usb_servo_wzorzec_P.Constant1_Value_e[3];

  /* Start for Constant: '<S12>/Constant2' */
  nasz_usb_servo_wzorzec_B.Constant2[0] =
    nasz_usb_servo_wzorzec_P.Constant2_Value[0];
  nasz_usb_servo_wzorzec_B.Constant2[1] =
    nasz_usb_servo_wzorzec_P.Constant2_Value[1];
  nasz_usb_servo_wzorzec_B.Constant2[2] =
    nasz_usb_servo_wzorzec_P.Constant2_Value[2];
  nasz_usb_servo_wzorzec_B.Constant2[3] =
    nasz_usb_servo_wzorzec_P.Constant2_Value[3];

  /* Start for Constant: '<S6>/Constant13' */
  nasz_usb_servo_wzorzec_B.Constant13 =
    nasz_usb_servo_wzorzec_P.Constant13_Value;

  /* Start for Constant: '<S6>/Constant14' */
  nasz_usb_servo_wzorzec_B.Constant14[0] =
    nasz_usb_servo_wzorzec_P.Constant14_Value[0];
  nasz_usb_servo_wzorzec_B.Constant14[1] =
    nasz_usb_servo_wzorzec_P.Constant14_Value[1];
  nasz_usb_servo_wzorzec_B.Constant14[2] =
    nasz_usb_servo_wzorzec_P.Constant14_Value[2];
  nasz_usb_servo_wzorzec_B.Constant14[3] =
    nasz_usb_servo_wzorzec_P.Constant14_Value[3];

  /* Start for Constant: '<S6>/Constant15' */
  nasz_usb_servo_wzorzec_B.Constant15[0] =
    nasz_usb_servo_wzorzec_P.Constant15_Value[0];
  nasz_usb_servo_wzorzec_B.Constant15[1] =
    nasz_usb_servo_wzorzec_P.Constant15_Value[1];
  nasz_usb_servo_wzorzec_B.Constant15[2] =
    nasz_usb_servo_wzorzec_P.Constant15_Value[2];
  nasz_usb_servo_wzorzec_B.Constant15[3] =
    nasz_usb_servo_wzorzec_P.Constant15_Value[3];

  /* Start for Constant: '<S8>/Constant12' */
  nasz_usb_servo_wzorzec_B.Constant12[0] =
    nasz_usb_servo_wzorzec_P.Constant12_Value[0];
  nasz_usb_servo_wzorzec_B.Constant12[1] =
    nasz_usb_servo_wzorzec_P.Constant12_Value[1];
  nasz_usb_servo_wzorzec_B.Constant12[2] =
    nasz_usb_servo_wzorzec_P.Constant12_Value[2];
  nasz_usb_servo_wzorzec_B.Constant12[3] =
    nasz_usb_servo_wzorzec_P.Constant12_Value[3];

  /* Start for Constant: '<S11>/Pin Mode (Input)' */
  nasz_usb_servo_wzorzec_B.PinModeInput =
    nasz_usb_servo_wzorzec_P.PinModeInput_Value;

  /* Start for Constant: '<S13>/Constant4' */
  nasz_usb_servo_wzorzec_B.Constant4[0] =
    nasz_usb_servo_wzorzec_P.Constant4_Value[0];
  nasz_usb_servo_wzorzec_B.Constant4[1] =
    nasz_usb_servo_wzorzec_P.Constant4_Value[1];

  /* Start for Constant: '<S13>/Constant7' */
  nasz_usb_servo_wzorzec_B.Constant7[0] =
    nasz_usb_servo_wzorzec_P.Constant7_Value[0];
  nasz_usb_servo_wzorzec_B.Constant7[1] =
    nasz_usb_servo_wzorzec_P.Constant7_Value[1];

  /* InitializeConditions for TransferFcn: '<S5>/filter velocity (encoder)' */
  nasz_usb_servo_wzorzec_X.filtervelocityencoder_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/filter velocity (tacho)' */
  nasz_usb_servo_wzorzec_X.filtervelocitytacho_CSTATE = 0.0;

  /* InitializeConditions for Memory: '<S13>/Memory2' */
  nasz_usb_servo_wzorzec_DW.Memory2_PreviousInput =
    nasz_usb_servo_wzorzec_P.Memory2_X0;

  /* InitializeConditions for Memory: '<S14>/Memory1' */
  nasz_usb_servo_wzorzec_DW.Memory1_PreviousInput =
    nasz_usb_servo_wzorzec_P.Memory1_X0;
}

/* Model terminate function */
void nasz_usb_servo_wzorzec_terminate(void)
{
  /* Level2 S-Function Block: '<S6>/RTDAC_USB2 Device Driver Terminated Version 2.11' (rtdacusb2_servo_dd) */
  {
    SimStruct *rts = nasz_usb_servo_wzorzec_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

#include <stdio.h>

/* Final time from "Simulation Parameters"   */
real_T finaltime = 300.0;
real_T StepSize = 0.01;

////////////////////////////////////////////////

////////////////////////////////////////////////
//
//  Return compilation date and time
//
char *GetDateAndTime( void )
{
  static char AuxStr[ 128 ];
  sprintf( AuxStr, "%s %s", __DATE__, __TIME__ );
  return( AuxStr );
}
