  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 227;
      section.data(227)  = dumData; %prealloc
      
	  ;% rtP.Idc
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.LoadA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.LoadB
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.LoadC
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.ModulationIndex
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.ffund
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Fourier1_Freq
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.Fourier1_Freq_kyl1z2hreh
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.Fourier1_Freq_ckkrxwnziq
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.RMS3_TrueRMS
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.RMS4_TrueRMS
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.RMS5_TrueRMS
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.Gain_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.Gain1_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.Gain_Gain_nfdcqsmx05
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.Gain1_Gain_mpdvg40lot
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.RMS_Y0
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.sinwt_Amp
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.sinwt_Bias
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.sinwt_Hsin
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.sinwt_HCos
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtP.sinwt_PSin
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtP.sinwt_PCos
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtP.Integ4_gainval
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtP.Integ4_IC
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtP.K1_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtP.SFunction_P1_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtP.SFunction_P1
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 28;
	
	  ;% rtP.SFunction_P2_Size
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 29;
	
	  ;% rtP.SFunction_P2
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 31;
	
	  ;% rtP.SFunction_P3_Size
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 32;
	
	  ;% rtP.SFunction_P3
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% rtP.SFunction_P4_Size
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% rtP.SFunction_P4
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 37;
	
	  ;% rtP.K2_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 38;
	
	  ;% rtP.UnitDelay_InitialCondition
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 39;
	
	  ;% rtP.UnitDelay1_InitialCondition
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 40;
	
	  ;% rtP.coswt_Amp
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 41;
	
	  ;% rtP.coswt_Bias
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 42;
	
	  ;% rtP.coswt_Hsin
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 43;
	
	  ;% rtP.coswt_HCos
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 44;
	
	  ;% rtP.coswt_PSin
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 45;
	
	  ;% rtP.coswt_PCos
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 46;
	
	  ;% rtP.Integ4_gainval_p0pakyry2d
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 47;
	
	  ;% rtP.Integ4_IC_pm40rzklkj
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 48;
	
	  ;% rtP.K1_Value_gmfkjcymcu
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 49;
	
	  ;% rtP.SFunction_P1_Size_h24o5xofg5
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 50;
	
	  ;% rtP.SFunction_P1_mve5jzjn2t
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 52;
	
	  ;% rtP.SFunction_P2_Size_ptok2c4vkm
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 53;
	
	  ;% rtP.SFunction_P2_dnazov5g1j
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 55;
	
	  ;% rtP.SFunction_P3_Size_ojs5p0ceq0
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 56;
	
	  ;% rtP.SFunction_P3_ivpagtbovw
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 58;
	
	  ;% rtP.SFunction_P4_Size_kvdkozvfrz
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 59;
	
	  ;% rtP.SFunction_P4_gtch0vha02
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 61;
	
	  ;% rtP.K2_Value_ehlwinmotq
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 62;
	
	  ;% rtP.UnitDelay_InitialCondition_aoguy1temn
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 63;
	
	  ;% rtP.UnitDelay1_InitialCondition_a5jgapepa0
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 64;
	
	  ;% rtP.Gain_Gain_mzuc0gr3rr
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 65;
	
	  ;% rtP.Gain1_Gain_jvz4pavaqm
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 66;
	
	  ;% rtP.Gain_Gain_gpon2qmr4o
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 67;
	
	  ;% rtP.RMS_Y0_bgjt2cqyc0
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 68;
	
	  ;% rtP.Integ4_gainval_cmbswlryt5
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 69;
	
	  ;% rtP.Integ4_IC_hyg1orgnjy
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 70;
	
	  ;% rtP.K1_Value_eper5cnwey
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 71;
	
	  ;% rtP.SFunction_P1_Size_cfue4013uz
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 72;
	
	  ;% rtP.SFunction_P1_ces20fopyh
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 74;
	
	  ;% rtP.SFunction_P2_Size_ay0oozdq4l
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 75;
	
	  ;% rtP.SFunction_P2_czfhe53zlo
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 77;
	
	  ;% rtP.SFunction_P3_Size_eavq2jcrxn
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 78;
	
	  ;% rtP.SFunction_P3_dso1nd4g1i
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 80;
	
	  ;% rtP.SFunction_P4_Size_iuauhtkk0r
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 81;
	
	  ;% rtP.SFunction_P4_o1nsl2odxy
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 83;
	
	  ;% rtP.UnitDelay_InitialCondition_msrh1hb3tx
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 84;
	
	  ;% rtP.K2_Value_poc3ahh3o0
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 85;
	
	  ;% rtP.UnitDelay1_InitialCondition_mjkrfyvx2n
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 86;
	
	  ;% rtP.Saturationtoavoidnegativesqrt_UpperSat
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 87;
	
	  ;% rtP.Saturationtoavoidnegativesqrt_LowerSat
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 88;
	
	  ;% rtP.Gain_Gain_cikg2wd54t
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 89;
	
	  ;% rtP.Gain1_Gain_og1ztmrikp
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 90;
	
	  ;% rtP.Gain_Gain_evmlakd0vp
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 91;
	
	  ;% rtP.Gain1_Gain_ju55l2bdzy
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 92;
	
	  ;% rtP.RMS_Y0_dzq0lqiuxk
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 93;
	
	  ;% rtP.sinwt_Amp_oijvtutv4k
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 94;
	
	  ;% rtP.sinwt_Bias_hpiubgslry
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 95;
	
	  ;% rtP.sinwt_Hsin_embht0yjxr
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 96;
	
	  ;% rtP.sinwt_HCos_phnvp0v0je
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 97;
	
	  ;% rtP.sinwt_PSin_mqldsacd5r
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 98;
	
	  ;% rtP.sinwt_PCos_l0uzrah2yr
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 99;
	
	  ;% rtP.Integ4_gainval_b2hr2aosow
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 100;
	
	  ;% rtP.Integ4_IC_eia2ftyj1x
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 101;
	
	  ;% rtP.K1_Value_d02xdalxac
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 102;
	
	  ;% rtP.SFunction_P1_Size_drqbfawq2t
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 103;
	
	  ;% rtP.SFunction_P1_meab1fmohc
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 105;
	
	  ;% rtP.SFunction_P2_Size_mtui52flb0
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 106;
	
	  ;% rtP.SFunction_P2_mtpqswmwzj
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 108;
	
	  ;% rtP.SFunction_P3_Size_koxhnafs0c
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 109;
	
	  ;% rtP.SFunction_P3_dvfpjfg0ac
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 111;
	
	  ;% rtP.SFunction_P4_Size_jmx5nhnvsc
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 112;
	
	  ;% rtP.SFunction_P4_odxtskcuwt
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 114;
	
	  ;% rtP.K2_Value_gwlqxdyahb
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 115;
	
	  ;% rtP.UnitDelay_InitialCondition_h222ofuws1
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 116;
	
	  ;% rtP.UnitDelay1_InitialCondition_mgl10icrr2
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 117;
	
	  ;% rtP.coswt_Amp_ckwsy1d5vd
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 118;
	
	  ;% rtP.coswt_Bias_hhsezuq143
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 119;
	
	  ;% rtP.coswt_Hsin_i0o0fsqk53
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 120;
	
	  ;% rtP.coswt_HCos_bibg2rjnu5
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 121;
	
	  ;% rtP.coswt_PSin_bcb2sivwyr
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 122;
	
	  ;% rtP.coswt_PCos_b2mnttqblm
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 123;
	
	  ;% rtP.Integ4_gainval_nfkwaoa5zw
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 124;
	
	  ;% rtP.Integ4_IC_id0g55h212
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 125;
	
	  ;% rtP.K1_Value_fri1a0ongp
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 126;
	
	  ;% rtP.SFunction_P1_Size_mdfnofpkyb
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 127;
	
	  ;% rtP.SFunction_P1_cc5kyrw4xh
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 129;
	
	  ;% rtP.SFunction_P2_Size_kn3dc1rpjw
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 130;
	
	  ;% rtP.SFunction_P2_jxgkcddozl
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 132;
	
	  ;% rtP.SFunction_P3_Size_iffghakq0a
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 133;
	
	  ;% rtP.SFunction_P3_demgfrwqa1
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 135;
	
	  ;% rtP.SFunction_P4_Size_ngg0llxaro
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 136;
	
	  ;% rtP.SFunction_P4_lg3wpmfbov
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 138;
	
	  ;% rtP.K2_Value_jtrzvmmebu
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 139;
	
	  ;% rtP.UnitDelay_InitialCondition_pgrk2rptpk
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 140;
	
	  ;% rtP.UnitDelay1_InitialCondition_ecwqqjll5r
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 141;
	
	  ;% rtP.Gain_Gain_k2vac0i5eo
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 142;
	
	  ;% rtP.Gain1_Gain_fdymcqm5hn
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 143;
	
	  ;% rtP.Gain_Gain_lrl440wsi1
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 144;
	
	  ;% rtP.RMS_Y0_jasmhly5vt
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 145;
	
	  ;% rtP.Integ4_gainval_cyxcyfj2ix
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 146;
	
	  ;% rtP.Integ4_IC_cmkobyzxoi
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 147;
	
	  ;% rtP.K1_Value_fiqnvvlbtv
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 148;
	
	  ;% rtP.SFunction_P1_Size_adklgix35t
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 149;
	
	  ;% rtP.SFunction_P1_hkfef4lit1
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 151;
	
	  ;% rtP.SFunction_P2_Size_fn0kh1ozqy
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 152;
	
	  ;% rtP.SFunction_P2_de1rgculkk
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 154;
	
	  ;% rtP.SFunction_P3_Size_a4xnsyreel
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 155;
	
	  ;% rtP.SFunction_P3_epvfavtoo2
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 157;
	
	  ;% rtP.SFunction_P4_Size_h30xo1wbyk
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 158;
	
	  ;% rtP.SFunction_P4_nl142gpj5w
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 160;
	
	  ;% rtP.UnitDelay_InitialCondition_fwom33d0us
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 161;
	
	  ;% rtP.K2_Value_kmw4g0e5by
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 162;
	
	  ;% rtP.UnitDelay1_InitialCondition_pav0c4wl2x
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 163;
	
	  ;% rtP.Saturationtoavoidnegativesqrt_UpperSat_pkr45gxbax
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 164;
	
	  ;% rtP.Saturationtoavoidnegativesqrt_LowerSat_faduiv0b3h
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 165;
	
	  ;% rtP.Gain_Gain_irzzlkvume
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 166;
	
	  ;% rtP.Gain1_Gain_h3dgnhtza4
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 167;
	
	  ;% rtP.Gain_Gain_cvnqvfbfob
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 168;
	
	  ;% rtP.Gain1_Gain_pp3awytfhp
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 169;
	
	  ;% rtP.RMS_Y0_ka1uowgurp
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 170;
	
	  ;% rtP.sinwt_Amp_l2gdj0uf33
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 171;
	
	  ;% rtP.sinwt_Bias_of4cf15cx1
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 172;
	
	  ;% rtP.sinwt_Hsin_fwqz1kodyw
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 173;
	
	  ;% rtP.sinwt_HCos_iatcouh3bm
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 174;
	
	  ;% rtP.sinwt_PSin_ezmzcturha
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 175;
	
	  ;% rtP.sinwt_PCos_bqkynrur55
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 176;
	
	  ;% rtP.Integ4_gainval_ad3r4knrp3
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 177;
	
	  ;% rtP.Integ4_IC_hlm5pnpjyb
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 178;
	
	  ;% rtP.K1_Value_bvxfbao2pd
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 179;
	
	  ;% rtP.SFunction_P1_Size_hdzfqts4px
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 180;
	
	  ;% rtP.SFunction_P1_gejrt01jyf
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 182;
	
	  ;% rtP.SFunction_P2_Size_kygust4i13
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 183;
	
	  ;% rtP.SFunction_P2_ek1xdjc2tb
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 185;
	
	  ;% rtP.SFunction_P3_Size_gxecz1stla
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 186;
	
	  ;% rtP.SFunction_P3_ckfk1oml4o
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 188;
	
	  ;% rtP.SFunction_P4_Size_ehy32gbq1m
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 189;
	
	  ;% rtP.SFunction_P4_ljqgukgmbn
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 191;
	
	  ;% rtP.K2_Value_lfot5huboi
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 192;
	
	  ;% rtP.UnitDelay_InitialCondition_mhq5umibzr
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 193;
	
	  ;% rtP.UnitDelay1_InitialCondition_csl0lzavbh
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 194;
	
	  ;% rtP.coswt_Amp_mrrwl5kftw
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 195;
	
	  ;% rtP.coswt_Bias_eabnppk3dd
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 196;
	
	  ;% rtP.coswt_Hsin_ipmmvop0j2
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 197;
	
	  ;% rtP.coswt_HCos_hrlrqukbrc
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 198;
	
	  ;% rtP.coswt_PSin_ien3v5if2m
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 199;
	
	  ;% rtP.coswt_PCos_jfqix0kyk3
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 200;
	
	  ;% rtP.Integ4_gainval_k5i2tkby2r
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 201;
	
	  ;% rtP.Integ4_IC_e3ezkszlmy
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 202;
	
	  ;% rtP.K1_Value_fpmnopebgd
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 203;
	
	  ;% rtP.SFunction_P1_Size_nurtgxf3pr
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 204;
	
	  ;% rtP.SFunction_P1_fsncrxesv5
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 206;
	
	  ;% rtP.SFunction_P2_Size_abuhz0s45k
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 207;
	
	  ;% rtP.SFunction_P2_mbvxvar4qa
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 209;
	
	  ;% rtP.SFunction_P3_Size_iribng3jzq
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 210;
	
	  ;% rtP.SFunction_P3_eixmpunjta
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 212;
	
	  ;% rtP.SFunction_P4_Size_d34e4l0tlz
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 213;
	
	  ;% rtP.SFunction_P4_f2joxh0nvg
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 215;
	
	  ;% rtP.K2_Value_fdk4k2gepc
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 216;
	
	  ;% rtP.UnitDelay_InitialCondition_liy42xpsvk
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 217;
	
	  ;% rtP.UnitDelay1_InitialCondition_kp4i0cv52p
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 218;
	
	  ;% rtP.Gain_Gain_mjhuuub0oq
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 219;
	
	  ;% rtP.Gain1_Gain_iohcin0rw2
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 220;
	
	  ;% rtP.Gain_Gain_ozgidwvo0b
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 221;
	
	  ;% rtP.RMS_Y0_jys4w42uyu
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 222;
	
	  ;% rtP.Integ4_gainval_aic2uxvjtz
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 223;
	
	  ;% rtP.Integ4_IC_n3vsv1fujy
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 224;
	
	  ;% rtP.K1_Value_chvilvz2jj
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 225;
	
	  ;% rtP.SFunction_P1_Size_nq3uzrogtq
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 226;
	
	  ;% rtP.SFunction_P1_msdslcv5o3
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 228;
	
	  ;% rtP.SFunction_P2_Size_brp5zn1b4c
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 229;
	
	  ;% rtP.SFunction_P2_hxiv5xbvlo
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 231;
	
	  ;% rtP.SFunction_P3_Size_dz2f5ik0lq
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 232;
	
	  ;% rtP.SFunction_P3_fugjw14aid
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 234;
	
	  ;% rtP.SFunction_P4_Size_go4cr2gil4
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 235;
	
	  ;% rtP.SFunction_P4_keejlnirow
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 237;
	
	  ;% rtP.UnitDelay_InitialCondition_bqwauueqoj
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 238;
	
	  ;% rtP.K2_Value_e5ticna4dr
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 239;
	
	  ;% rtP.UnitDelay1_InitialCondition_o2zq5zqj25
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 240;
	
	  ;% rtP.Saturationtoavoidnegativesqrt_UpperSat_jebmupogt4
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 241;
	
	  ;% rtP.Saturationtoavoidnegativesqrt_LowerSat_hhpj4y3w4k
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 242;
	
	  ;% rtP.Constant_Value
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 243;
	
	  ;% rtP.SineWaveFunction1_Bias
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 244;
	
	  ;% rtP.SineWaveFunction1_Phase
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 245;
	
	  ;% rtP.Constant3_Value
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 246;
	
	  ;% rtP.Constant4_Value
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 247;
	
	  ;% rtP.uib1_Gain
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 248;
	
	  ;% rtP.uDLookupTable_tableData
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 249;
	
	  ;% rtP.uDLookupTable_bp01Data
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 252;
	
	  ;% rtP.Constant2_Value
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 255;
	
	  ;% rtP.Constant_Value_dlflefihkr
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 256;
	
	  ;% rtP.Constant1_Value
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 257;
	
	  ;% rtP.SineWaveFunction_Bias
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 258;
	
	  ;% rtP.SineWaveFunction_Phase
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 259;
	
	  ;% rtP.Constant_Value_l3unqqh2kq
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 260;
	
	  ;% rtP.Constant_Value_dxzjx5wwcr
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 261;
	
	  ;% rtP.Constant_Value_a4nouejct5
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 262;
	
	  ;% rtP.SineWaveFunction2_Bias
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 263;
	
	  ;% rtP.SineWaveFunction2_Phase
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 264;
	
	  ;% rtP.Constant_Value_cpsdmvnz4x
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 265;
	
	  ;% rtP.Constant_Value_ln0n1kk0z4
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 266;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 79;
      section.data(79)  = dumData; %prealloc
      
	  ;% rtB.lcge5t1gjo
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.b1sdosls3i
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.dvb12qxvf2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.czvszvgx5h
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.hpc0dqwvnx
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.eovubh0rxu
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.pnsni0ml1o
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.imlhhcedkr
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.kulfykvvqa
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtB.bgybglbgav
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtB.nukezu5xk3
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% rtB.p51dkbkwid
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% rtB.cmlcurmh4c
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% rtB.lc0gh4vn0y
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% rtB.ce2llznftg
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 23;
	
	  ;% rtB.ajqsccxh4n
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 24;
	
	  ;% rtB.ohra4d5w4r
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% rtB.b1ptcc5egb
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% rtB.oilte4fptr
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% rtB.idj5hyxoz3
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 31;
	
	  ;% rtB.ex0skiip24
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 35;
	
	  ;% rtB.frvw5tfr5q
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 36;
	
	  ;% rtB.h4xihyt1ug
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 40;
	
	  ;% rtB.iwg44exs5g
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 199;
	
	  ;% rtB.kbdwxc5gyv
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 225;
	
	  ;% rtB.hpnhpaq3hf
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 226;
	
	  ;% rtB.kw2mc2f54g
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 227;
	
	  ;% rtB.np4sgj0uze
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 228;
	
	  ;% rtB.ibafq0ggxu
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 229;
	
	  ;% rtB.mt1rpkiyfp
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 230;
	
	  ;% rtB.jnh32a12mk
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 231;
	
	  ;% rtB.gsqpfetcre
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 232;
	
	  ;% rtB.cokmhxd3cw
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 233;
	
	  ;% rtB.bisq51qkxp
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 234;
	
	  ;% rtB.gp3dcunmfo
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 235;
	
	  ;% rtB.afvbv15lpm
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 236;
	
	  ;% rtB.o1kjfgygqq
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 237;
	
	  ;% rtB.nj0zvfpbxs
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 238;
	
	  ;% rtB.oswn5ymim2
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 239;
	
	  ;% rtB.g1gbvczb2o
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 240;
	
	  ;% rtB.c2v2toypds
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 241;
	
	  ;% rtB.fxp4n1nqzj
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 242;
	
	  ;% rtB.mw5rzz05or
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 243;
	
	  ;% rtB.ixh4gmo224
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 244;
	
	  ;% rtB.fm33dmmmls
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 245;
	
	  ;% rtB.kp54qwa2gg
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 246;
	
	  ;% rtB.arg5blkvtg
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 247;
	
	  ;% rtB.aiu4fdl0gc
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 248;
	
	  ;% rtB.eihpzfi2ln
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 249;
	
	  ;% rtB.hezoo43y0q
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 250;
	
	  ;% rtB.ofcnur01ss
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 251;
	
	  ;% rtB.afxisy1b20
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 252;
	
	  ;% rtB.n1uuisg4fw
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 253;
	
	  ;% rtB.eua13yagug
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 254;
	
	  ;% rtB.bmp4rhxpul
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 255;
	
	  ;% rtB.fzd10ahxco
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 256;
	
	  ;% rtB.enecbqrfz5
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 257;
	
	  ;% rtB.mntq0tppuk
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 258;
	
	  ;% rtB.h0sb2533vd
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 259;
	
	  ;% rtB.hic1rjtsai
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 260;
	
	  ;% rtB.hewx2df0ek
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 261;
	
	  ;% rtB.hfz5bihucl
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 262;
	
	  ;% rtB.k4fqogeply
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 263;
	
	  ;% rtB.d4yrrkxbew
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 264;
	
	  ;% rtB.jeyupwj05d
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 265;
	
	  ;% rtB.povy1e3cdf
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 266;
	
	  ;% rtB.oww2w4mlsz
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 267;
	
	  ;% rtB.b5bpctebld
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 268;
	
	  ;% rtB.e2o0qyzahq
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 269;
	
	  ;% rtB.kbsdtbfy5k
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 270;
	
	  ;% rtB.f5ta3mfjzs
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 271;
	
	  ;% rtB.gcgeoe3iiq
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 272;
	
	  ;% rtB.nxju1b0nfk
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 273;
	
	  ;% rtB.fsoikihjt1
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 274;
	
	  ;% rtB.gjyfuvtq0v
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 275;
	
	  ;% rtB.ihgmb1kpmh
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 276;
	
	  ;% rtB.epdjm1qtac
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 277;
	
	  ;% rtB.fwtfj3b0hp
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 278;
	
	  ;% rtB.g4doefl2of
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 279;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtB.awqcje34vp
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.kvdej4nyky
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.cwstdnv15s
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.hf5hmpwr00
	  section.data(4).logicalSrcIdx = 82;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.nqc1swz1f5
	  section.data(5).logicalSrcIdx = 83;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.aw0sdhxkut
	  section.data(6).logicalSrcIdx = 84;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    nTotSects     = 8;
    sectIdxOffset = 2;
    
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
    ;% Auto data (rtDW)
    ;%
      section.nData     = 55;
      section.data(55)  = dumData; %prealloc
      
	  ;% rtDW.hdz0nups2p
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bqgmk2ugv4
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtDW.auveueqvz5
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtDW.kyjsjkxfrc
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtDW.jxp1qqkjt1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtDW.ibcfck1opc
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtDW.lpi2q22kbk
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtDW.jt0sfxu401
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 135;
	
	  ;% rtDW.bdoob1ijr3
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 136;
	
	  ;% rtDW.jlot4ajqhq
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 137;
	
	  ;% rtDW.lrcapd2g5t
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 138;
	
	  ;% rtDW.jwkyerowmb
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 139;
	
	  ;% rtDW.lbvma42sos
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 140;
	
	  ;% rtDW.gfeprm5f5a
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 141;
	
	  ;% rtDW.jjebi2i5un
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 142;
	
	  ;% rtDW.ebmpnozmec
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 143;
	
	  ;% rtDW.l4lzpabl4t
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 144;
	
	  ;% rtDW.lpfa0xqegk
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 145;
	
	  ;% rtDW.ppix1t4koq
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 146;
	
	  ;% rtDW.grpjnlftxq
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 147;
	
	  ;% rtDW.ecmyri45ls
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 148;
	
	  ;% rtDW.j5dfwnlbxm
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 149;
	
	  ;% rtDW.pnojpqs3ns
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 150;
	
	  ;% rtDW.gwyanuw3x0
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 151;
	
	  ;% rtDW.ho5z3w1sbb
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 152;
	
	  ;% rtDW.cx3y5wj24t
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 153;
	
	  ;% rtDW.liyidkg1og
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 154;
	
	  ;% rtDW.hq3xers3h0
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 155;
	
	  ;% rtDW.f053xx0l23
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 156;
	
	  ;% rtDW.iayqwjxn30
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 157;
	
	  ;% rtDW.g522ownwqo
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 158;
	
	  ;% rtDW.motifvjzhr
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 159;
	
	  ;% rtDW.ocq00sjeyj
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 160;
	
	  ;% rtDW.edd2kbkzs3
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 161;
	
	  ;% rtDW.iwqu4lrnkv
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 162;
	
	  ;% rtDW.e4ptdvhtkx
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 163;
	
	  ;% rtDW.a4o1phii2z
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 164;
	
	  ;% rtDW.d5beywmeax
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 165;
	
	  ;% rtDW.o1pj5ffxoy
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 166;
	
	  ;% rtDW.nmu44g4cwh
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 167;
	
	  ;% rtDW.ipprpfttv3
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 168;
	
	  ;% rtDW.jwcmyh4tyw
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 169;
	
	  ;% rtDW.fadr5pbwq1
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 170;
	
	  ;% rtDW.jetkaz1b2y
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 171;
	
	  ;% rtDW.c2nm3gd1a4
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 172;
	
	  ;% rtDW.f0oqest1i1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 173;
	
	  ;% rtDW.dewhsbzzvs
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 174;
	
	  ;% rtDW.hksk41e2yx
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 175;
	
	  ;% rtDW.ljdesx2yzv
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 176;
	
	  ;% rtDW.bmrkjzbemi
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 177;
	
	  ;% rtDW.pb0fxdtdzl
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 178;
	
	  ;% rtDW.kzaxa1cwm5
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 179;
	
	  ;% rtDW.a5wlka4qb2
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 180;
	
	  ;% rtDW.ogm11qxgfe
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 181;
	
	  ;% rtDW.luocivfdwy
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 182;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% rtDW.bgwsy3m1jh
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.j4btagyhoo
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ljvsw4ftil
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.djuug5w32t
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.d3dsrtwi0j
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ni2bvu1xg1
	  section.data(6).logicalSrcIdx = 60;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.frpy0o3adk
	  section.data(7).logicalSrcIdx = 61;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.pco3n20tlq
	  section.data(8).logicalSrcIdx = 62;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.d3bgeeko12
	  section.data(9).logicalSrcIdx = 63;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.fwa4citlig
	  section.data(10).logicalSrcIdx = 64;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.j553pujwhq
	  section.data(11).logicalSrcIdx = 65;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.dcorct0idw
	  section.data(12).logicalSrcIdx = 66;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.fwmkchozeq.AQHandles
	  section.data(13).logicalSrcIdx = 67;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.haruhqhvxm.LoggedData
	  section.data(14).logicalSrcIdx = 68;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.nvuyb1yzrc.AQHandles
	  section.data(15).logicalSrcIdx = 69;
	  section.data(15).dtTransOffset = 17;
	
	  ;% rtDW.k4mh4yu0ov.AQHandles
	  section.data(16).logicalSrcIdx = 70;
	  section.data(16).dtTransOffset = 18;
	
	  ;% rtDW.nsk5nlbpt3.LoggedData
	  section.data(17).logicalSrcIdx = 71;
	  section.data(17).dtTransOffset = 19;
	
	  ;% rtDW.mkjlrssi4i.LoggedData
	  section.data(18).logicalSrcIdx = 72;
	  section.data(18).dtTransOffset = 23;
	
	  ;% rtDW.iak0awbnmq
	  section.data(19).logicalSrcIdx = 73;
	  section.data(19).dtTransOffset = 25;
	
	  ;% rtDW.mwaj5uxciv
	  section.data(20).logicalSrcIdx = 74;
	  section.data(20).dtTransOffset = 26;
	
	  ;% rtDW.ng4gmlk2i5
	  section.data(21).logicalSrcIdx = 75;
	  section.data(21).dtTransOffset = 27;
	
	  ;% rtDW.flsmaquu11
	  section.data(22).logicalSrcIdx = 76;
	  section.data(22).dtTransOffset = 28;
	
	  ;% rtDW.ocujfrzzrp
	  section.data(23).logicalSrcIdx = 77;
	  section.data(23).dtTransOffset = 29;
	
	  ;% rtDW.iphuwwyg2r
	  section.data(24).logicalSrcIdx = 78;
	  section.data(24).dtTransOffset = 30;
	
	  ;% rtDW.p4eex3535n
	  section.data(25).logicalSrcIdx = 79;
	  section.data(25).dtTransOffset = 31;
	
	  ;% rtDW.a5txtrw5jr
	  section.data(26).logicalSrcIdx = 80;
	  section.data(26).dtTransOffset = 32;
	
	  ;% rtDW.lxt5anhnhb
	  section.data(27).logicalSrcIdx = 81;
	  section.data(27).dtTransOffset = 33;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.doyt1502bn
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.csvpkvttn4
	  section.data(2).logicalSrcIdx = 83;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ex3mrpp4j3
	  section.data(3).logicalSrcIdx = 84;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.b4zx4xqegz
	  section.data(4).logicalSrcIdx = 85;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.letqwzpvfw
	  section.data(5).logicalSrcIdx = 86;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.dhg2x3hhw4
	  section.data(6).logicalSrcIdx = 87;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fto133wy4o
	  section.data(1).logicalSrcIdx = 88;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtDW.laeadqjoyo
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hnibndvd1j
	  section.data(2).logicalSrcIdx = 90;
	  section.data(2).dtTransOffset = 36;
	
	  ;% rtDW.ggh5d2ostt
	  section.data(3).logicalSrcIdx = 91;
	  section.data(3).dtTransOffset = 37;
	
	  ;% rtDW.ddn5xcth0s
	  section.data(4).logicalSrcIdx = 92;
	  section.data(4).dtTransOffset = 38;
	
	  ;% rtDW.m4mwptfw3a
	  section.data(5).logicalSrcIdx = 93;
	  section.data(5).dtTransOffset = 39;
	
	  ;% rtDW.mqhuvls5ex
	  section.data(6).logicalSrcIdx = 94;
	  section.data(6).dtTransOffset = 40;
	
	  ;% rtDW.l3nkgsx0lg
	  section.data(7).logicalSrcIdx = 95;
	  section.data(7).dtTransOffset = 41;
	
	  ;% rtDW.eeda03zvsk
	  section.data(8).logicalSrcIdx = 96;
	  section.data(8).dtTransOffset = 42;
	
	  ;% rtDW.dmjstp1pnq
	  section.data(9).logicalSrcIdx = 97;
	  section.data(9).dtTransOffset = 43;
	
	  ;% rtDW.hgmprgjhr2
	  section.data(10).logicalSrcIdx = 98;
	  section.data(10).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.c3pebqdhtw
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.n3ddpqpuun
	  section.data(2).logicalSrcIdx = 100;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.mvd0gisct2
	  section.data(3).logicalSrcIdx = 101;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.l4lq0poyio
	  section.data(4).logicalSrcIdx = 102;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.bfjoxab0mk
	  section.data(5).logicalSrcIdx = 103;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ksdc555p1f
	  section.data(6).logicalSrcIdx = 104;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.pkc5pvpbud
	  section.data(7).logicalSrcIdx = 105;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.dr430txhud
	  section.data(8).logicalSrcIdx = 106;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.bcuawr35dl
	  section.data(9).logicalSrcIdx = 107;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.l1z2owbfnm
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lz0tgfsnu0
	  section.data(2).logicalSrcIdx = 109;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.oknt3qnnbn
	  section.data(3).logicalSrcIdx = 110;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.kzq4yloq2t
	  section.data(4).logicalSrcIdx = 111;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.fnn2bvdaoo
	  section.data(5).logicalSrcIdx = 112;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.moizrwcmqn
	  section.data(6).logicalSrcIdx = 113;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.f54g14zkss
	  section.data(7).logicalSrcIdx = 114;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.g3mio5fr0t
	  section.data(8).logicalSrcIdx = 115;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.kqc5wee2bc
	  section.data(9).logicalSrcIdx = 116;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% rtDW.iw3cho4vxe
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.kjsrm0r1qu
	  section.data(2).logicalSrcIdx = 118;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.lqtqsmmd1w
	  section.data(3).logicalSrcIdx = 119;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.m5i40ct5vz
	  section.data(4).logicalSrcIdx = 120;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.hm42zo1kvb
	  section.data(5).logicalSrcIdx = 121;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.kuylzd02lp
	  section.data(6).logicalSrcIdx = 122;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.o1zlpawevl
	  section.data(7).logicalSrcIdx = 123;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.e1uf5s5z1k
	  section.data(8).logicalSrcIdx = 124;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.gq2nzjnf0w
	  section.data(9).logicalSrcIdx = 125;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.eibahmjyhj
	  section.data(10).logicalSrcIdx = 126;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.gov5rlozbf
	  section.data(11).logicalSrcIdx = 127;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.gob230sujf
	  section.data(12).logicalSrcIdx = 128;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.ecisw5adre
	  section.data(13).logicalSrcIdx = 129;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.kurl1epm13
	  section.data(14).logicalSrcIdx = 130;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
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


  targMap.checksum0 = 67555714;
  targMap.checksum1 = 1362381361;
  targMap.checksum2 = 3890521108;
  targMap.checksum3 = 1778704554;

