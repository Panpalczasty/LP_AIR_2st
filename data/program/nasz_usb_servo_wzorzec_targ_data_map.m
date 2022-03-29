  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nasz_usb_servo_wzorzec_P)
    ;%
      section.nData     = 83;
      section.data(83)  = dumData; %prealloc
      
	  ;% nasz_usb_servo_wzorzec_P.ChirpSignal_T
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nasz_usb_servo_wzorzec_P.Ramp_X0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nasz_usb_servo_wzorzec_P.ChirpSignal_f1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% nasz_usb_servo_wzorzec_P.ChirpSignal_f2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% nasz_usb_servo_wzorzec_P.Ramp_slope
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% nasz_usb_servo_wzorzec_P.Ramp_start
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain_Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% nasz_usb_servo_wzorzec_P.Normal_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% nasz_usb_servo_wzorzec_P.Reset_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant3_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant10_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant1_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% nasz_usb_servo_wzorzec_P.ThetaSP_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% nasz_usb_servo_wzorzec_P.RTDAC_USB2DeviceDriverTerminate
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% nasz_usb_servo_wzorzec_P.RTDAC_USB2DeviceDriverTermina_o
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% nasz_usb_servo_wzorzec_P.Encoder1024PPR_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% nasz_usb_servo_wzorzec_P.Converttorad_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 23;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain_Gain_h
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 24;
	
	  ;% nasz_usb_servo_wzorzec_P.filtervelocityencoder_A
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 25;
	
	  ;% nasz_usb_servo_wzorzec_P.filtervelocityencoder_C
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 26;
	
	  ;% nasz_usb_servo_wzorzec_P.Scale_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 27;
	
	  ;% nasz_usb_servo_wzorzec_P.Simplefilter_D
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 28;
	
	  ;% nasz_usb_servo_wzorzec_P.filtervelocitytacho_A
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 29;
	
	  ;% nasz_usb_servo_wzorzec_P.filtervelocitytacho_C
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 30;
	
	  ;% nasz_usb_servo_wzorzec_P.scalefilteredvelocity_Gain
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 31;
	
	  ;% nasz_usb_servo_wzorzec_P.ConvertToAmper_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 32;
	
	  ;% nasz_usb_servo_wzorzec_P.ConvertToAmper1_Gain
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 33;
	
	  ;% nasz_usb_servo_wzorzec_P.Step_Y0
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 34;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain_Gain_d
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 35;
	
	  ;% nasz_usb_servo_wzorzec_P.Saturation_UpperSat
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 36;
	
	  ;% nasz_usb_servo_wzorzec_P.Saturation_LowerSat
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 37;
	
	  ;% nasz_usb_servo_wzorzec_P.Saturation_UpperSat_h
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 38;
	
	  ;% nasz_usb_servo_wzorzec_P.Saturation_LowerSat_g
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 39;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain1_Gain
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 40;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit0Bit12_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 41;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit13_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 42;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain13_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 43;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit14_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 44;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain14_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 45;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit15_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 46;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain18_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 47;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit16_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 48;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain19_Gain
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 49;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit17_Value
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 50;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain20_Gain
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 51;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit18Therm0_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 52;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain21_Gain
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 53;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit19PWM0_Value
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 54;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain22_Gain
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 55;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit20Brake0_Value
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 56;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain23_Gain
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 57;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant10_Value_o
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 58;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant3_Value_d
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 59;
	
	  ;% nasz_usb_servo_wzorzec_P.Switch_Threshold
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 60;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain24_Gain
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 61;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit22Therm1_Value
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 62;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain25_Gain
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 63;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit23PWM1_Value
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 64;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain15_Gain
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 65;
	
	  ;% nasz_usb_servo_wzorzec_P.Bit24Brake1_Value
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 66;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain16_Gain
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 67;
	
	  ;% nasz_usb_servo_wzorzec_P.Gain17_Gain
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 68;
	
	  ;% nasz_usb_servo_wzorzec_P.DirectionInput_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 69;
	
	  ;% nasz_usb_servo_wzorzec_P.Switch_Threshold_p
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 70;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant5_Value
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 71;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant6_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 75;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant8_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 79;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant1_Value_e
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 95;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant2_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 99;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant13_Value
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 103;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant14_Value
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 104;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant15_Value
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 108;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant12_Value
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 112;
	
	  ;% nasz_usb_servo_wzorzec_P.PinModeInput_Value
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 116;
	
	  ;% nasz_usb_servo_wzorzec_P.ClockFrequency_Value
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 117;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant_Value
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 118;
	
	  ;% nasz_usb_servo_wzorzec_P.Memory2_X0
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 119;
	
	  ;% nasz_usb_servo_wzorzec_P.Switch_Threshold_a
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 120;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant4_Value
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 121;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant7_Value
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 123;
	
	  ;% nasz_usb_servo_wzorzec_P.Constant1_Value_e5
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 125;
	
	  ;% nasz_usb_servo_wzorzec_P.Memory1_X0
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 126;
	
	  ;% nasz_usb_servo_wzorzec_P.Switch_Threshold_a5
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 127;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% nasz_usb_servo_wzorzec_P.SigmodeRealtimeonly2_CurrentSet
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nasz_usb_servo_wzorzec_P.SigmodeRealtimeonly1_CurrentSet
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nasz_usb_servo_wzorzec_P.ResetEncodersRealtimeonly_Curre
	  section.data(3).logicalSrcIdx = 85;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nasz_usb_servo_wzorzec_B)
    ;%
      section.nData     = 57;
      section.data(57)  = dumData; %prealloc
      
	  ;% nasz_usb_servo_wzorzec_B.ThetaSP
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTerminate
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_h
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_e
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_p
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_m
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_n
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_b
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_k
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_nd
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 18;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_a
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 22;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_p1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 26;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_af
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 30;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_hh
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 34;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_o
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 36;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_em
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 38;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermina_d
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 40;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_pn
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 56;
	
	  ;% nasz_usb_servo_wzorzec_B.RTDAC_USB2DeviceDriverTermin_e2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 72;
	
	  ;% nasz_usb_servo_wzorzec_B.Angleencoder
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 76;
	
	  ;% nasz_usb_servo_wzorzec_B.filteredvelocityencoder
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 77;
	
	  ;% nasz_usb_servo_wzorzec_B.Scale
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 78;
	
	  ;% nasz_usb_servo_wzorzec_B.Simplefilter
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 79;
	
	  ;% nasz_usb_servo_wzorzec_B.scaledfilteredvelocitytacho
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 80;
	
	  ;% nasz_usb_servo_wzorzec_B.ConvertToAmper
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 81;
	
	  ;% nasz_usb_servo_wzorzec_B.ConvertToAmper1
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 82;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 83;
	
	  ;% nasz_usb_servo_wzorzec_B.Saturation
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 84;
	
	  ;% nasz_usb_servo_wzorzec_B.Abs
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 85;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain13
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 86;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain14
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 87;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain18
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 88;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain19
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 89;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain20
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 90;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain21
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 91;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain22
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 92;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain23
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 93;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain25
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 94;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain15
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 95;
	
	  ;% nasz_usb_servo_wzorzec_B.Gain16
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 96;
	
	  ;% nasz_usb_servo_wzorzec_B.DirectionInput
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 97;
	
	  ;% nasz_usb_servo_wzorzec_B.Switch
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 98;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant5
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 102;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant6
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 106;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant8
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 110;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 126;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant2
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 130;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant13
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 134;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant14
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 135;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant15
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 139;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant12
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 143;
	
	  ;% nasz_usb_servo_wzorzec_B.PinModeInput
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 147;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant4
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 148;
	
	  ;% nasz_usb_servo_wzorzec_B.Constant7
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 150;
	
	  ;% nasz_usb_servo_wzorzec_B.Sum
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 152;
	
	  ;% nasz_usb_servo_wzorzec_B.Product
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 153;
	
	  ;% nasz_usb_servo_wzorzec_B.Switch_n
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 154;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (nasz_usb_servo_wzorzec_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% nasz_usb_servo_wzorzec_DW.Memory2_PreviousInput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nasz_usb_servo_wzorzec_DW.Memory1_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% nasz_usb_servo_wzorzec_DW.AngleReferencevelocity_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% nasz_usb_servo_wzorzec_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2190976335;
  targMap.checksum1 = 1250969628;
  targMap.checksum2 = 1231406533;
  targMap.checksum3 = 2226924262;

