#include "__cf_InverterModulesInParallel.h"
#ifndef RTW_HEADER_InverterModulesInParallel_acc_h_
#define RTW_HEADER_InverterModulesInParallel_acc_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#ifndef InverterModulesInParallel_acc_COMMON_INCLUDES_
#define InverterModulesInParallel_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "InverterModulesInParallel_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_18_0_0 ; real_T B_18_2_0 ; real_T B_18_3_0 ; real_T
B_18_4_0 ; real_T B_18_6_0 ; real_T B_18_8_0 ; real_T B_18_12_0 ; real_T
B_18_13_0 ; real_T B_18_14_0 ; real_T B_18_17_0 ; real_T B_18_18_0 ; real_T
B_18_19_0 ; real_T B_18_22_0 ; real_T B_18_23_0 ; real_T B_18_26_0 ; real_T
B_18_27_0 [ 4 ] ; real_T B_18_28_0 ; real_T B_18_30_0 ; real_T B_18_33_0 ;
real_T B_18_34_0 ; real_T B_18_37_0 ; real_T B_18_38_0 ; real_T B_18_41_0 ;
real_T B_18_42_0 [ 4 ] ; real_T B_18_43_0 ; real_T B_18_45_0 ; real_T
B_18_46_0 ; real_T B_18_47_0 ; real_T B_18_49_0 ; real_T B_18_51_0 ; real_T
B_18_55_0 ; real_T B_18_56_0 ; real_T B_18_57_0 ; real_T B_18_60_0 ; real_T
B_18_61_0 ; real_T B_18_62_0 ; real_T B_18_65_0 ; real_T B_18_66_0 ; real_T
B_18_69_0 ; real_T B_18_70_0 [ 4 ] ; real_T B_18_71_0 ; real_T B_18_73_0 ;
real_T B_18_76_0 ; real_T B_18_77_0 ; real_T B_18_80_0 ; real_T B_18_81_0 ;
real_T B_18_84_0 ; real_T B_18_85_0 [ 4 ] ; real_T B_18_86_0 ; real_T
B_18_88_0 ; real_T B_18_89_0 ; real_T B_18_90_0 ; real_T B_18_93_0 ; real_T
B_18_94_0 ; real_T B_18_97_0 ; real_T B_18_98_0 ; real_T B_18_101_0 ; real_T
B_18_102_0 [ 4 ] ; real_T B_18_103_0 ; real_T B_18_105_0 ; real_T B_18_108_0
; real_T B_18_109_0 ; real_T B_18_112_0 ; real_T B_18_113_0 ; real_T
B_18_116_0 ; real_T B_18_117_0 [ 4 ] ; real_T B_18_118_0 ; real_T B_18_120_0
; real_T B_18_121_0 ; real_T B_18_122_0 ; real_T B_18_125_0 ; real_T
B_18_126_0 ; real_T B_18_129_0 ; real_T B_18_130_0 ; real_T B_18_133_0 ;
real_T B_18_134_0 [ 4 ] ; real_T B_18_135_0 ; real_T B_18_137_0 ; real_T
B_18_140_0 ; real_T B_18_141_0 ; real_T B_18_144_0 ; real_T B_18_145_0 ;
real_T B_18_148_0 ; real_T B_18_149_0 [ 4 ] ; real_T B_18_150_0 ; real_T
B_18_152_0 ; real_T B_18_153_0 ; real_T B_18_154_0 ; real_T B_18_157_0 ;
real_T B_18_158_0 ; real_T B_18_161_0 ; real_T B_18_162_0 ; real_T B_18_165_0
; real_T B_18_166_0 [ 4 ] ; real_T B_18_167_0 ; real_T B_18_169_0 ; real_T
B_18_172_0 ; real_T B_18_173_0 ; real_T B_18_176_0 ; real_T B_18_177_0 ;
real_T B_18_180_0 ; real_T B_18_181_0 [ 4 ] ; real_T B_18_182_0 ; real_T
B_18_184_0 ; real_T B_18_185_0 ; real_T B_18_186_0 ; real_T B_18_189_0 ;
real_T B_18_190_0 ; real_T B_18_193_0 ; real_T B_18_194_0 ; real_T B_18_197_0
; real_T B_18_198_0 [ 4 ] ; real_T B_18_199_0 ; real_T B_18_201_0 ; real_T
B_18_204_0 ; real_T B_18_205_0 ; real_T B_18_208_0 ; real_T B_18_209_0 ;
real_T B_18_212_0 ; real_T B_18_213_0 [ 4 ] ; real_T B_18_214_0 [ 191 ] ;
real_T B_18_215_0 [ 53 ] ; real_T B_18_217_0 ; real_T B_18_218_0 ; real_T
B_18_219_0 ; real_T B_18_225_0 ; real_T B_18_226_0 ; real_T B_17_1_0 ; real_T
B_17_2_0 ; real_T B_17_3_0 ; real_T B_17_4_0 ; real_T B_17_7_0 ; real_T
B_17_8_0 ; real_T B_16_0_0 ; real_T B_16_1_0 ; real_T B_15_3_0 ; real_T
B_15_5_0 ; real_T B_14_1_0 [ 3 ] ; real_T B_14_2_0 [ 3 ] ; real_T B_14_3_0 ;
real_T B_14_4_0 [ 3 ] ; real_T B_14_7_0 [ 3 ] ; real_T B_14_8_0 [ 3 ] ;
real_T B_13_0_0 [ 3 ] ; real_T B_13_1_0 [ 3 ] ; real_T B_12_3_0 [ 3 ] ;
real_T B_12_5_0 [ 3 ] ; boolean_T B_18_634_0 ; boolean_T B_18_635_0 ;
boolean_T B_18_639_0 ; boolean_T B_18_640_0 ; char_T pad_B_18_640_0 [ 4 ] ; }
B_InverterModulesInParallel_T ; typedef struct { real_T DelayInput2_DSTATE ;
real_T INPUT_1_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_c ; real_T
INPUT_2_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_o ; real_T
INPUT_11_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_k ; real_T
INPUT_12_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_d ; real_T
INPUT_3_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_f ; real_T
INPUT_4_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_n ; real_T
INPUT_5_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_m ; real_T
INPUT_6_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_dc ; real_T
INPUT_7_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_dj ; real_T
INPUT_8_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_a ; real_T
INPUT_9_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_nv ; real_T
INPUT_10_1_1_discrete [ 2 ] ; real_T STATE_1_DiscStates [ 179 ] ; real_T
Memory_PreviousInput ; real_T Memory_PreviousInput_k [ 3 ] ; struct { real_T
modelTStart ; } TransportDelay_RWORK ; struct { real_T modelTStart ; }
TransportDelay_RWORK_f ; void * STATE_1_Simulator ; void *
STATE_1_SimulationData ; void * STATE_1_DiagnosticManager ; void *
STATE_1_VariableLogger ; void * STATE_1_ZeroCrossingLogger ; void *
STATE_1_SampleTimeIdx ; void * OUTPUT_1_0_Simulator ; void *
OUTPUT_1_0_SimulationData ; void * OUTPUT_1_0_DiagnosticManager ; void *
OUTPUT_1_0_VariableLogger ; void * OUTPUT_1_0_ZeroCrossingLogger ; void *
OUTPUT_1_0_SampleTimeIdx ; struct { void * AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_3phModule1_at_outport_5_PWORK ; struct { void
* AQHandles [ 3 ] ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK ; struct { void
* AQHandles [ 3 ] ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK ; struct { void
* AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_5_PWORK ; void *
Scope_PWORK [ 2 ] ; void * Scope1_PWORK [ 2 ] ; void * Scope2_PWORK [ 2 ] ;
void * Scope6_PWORK [ 2 ] ; void * Scope12_PWORK [ 4 ] ; void *
Scope12_PWORK_g [ 4 ] ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK ; struct { void * TUbufferPtrs [ 6 ] ; }
TransportDelay_PWORK_b ; int32_T TrueRMS_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T RMS_sysIdxToRun ;
int32_T TrueRMS_sysIdxToRun_c ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_d ; int32_T RMS_sysIdxToRun_a ;
int32_T TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_i ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_f ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_h ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_b ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_g ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_g1 ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_ii ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_c ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_n ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_np ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_a ; uint32_T m_bpIndex ; uint32_T
m_bpIndex_a ; int_T STATE_1_Modes [ 12 ] ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; struct { int_T Tail [ 3 ] ; int_T Head [ 3 ] ; int_T
Last [ 3 ] ; int_T CircularBufSize [ 3 ] ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_g ; int_T Saturationtoavoidnegativesqrt_MODE ; int_T
Saturationtoavoidnegativesqrt_MODE_c [ 3 ] ; int8_T TrueRMS_SubsysRanBC ;
int8_T RMS_SubsysRanBC ; int8_T TrueRMS_SubsysRanBC_i ; int8_T
RMS_SubsysRanBC_n ; boolean_T Compare_Mode ; boolean_T Compare_Mode_g ;
boolean_T Compare_Mode_h ; boolean_T Compare_Mode_i ; boolean_T
Compare_Mode_p ; boolean_T Compare_Mode_j ; boolean_T Compare_Mode_hp ;
boolean_T Compare_Mode_iz ; boolean_T Compare_Mode_ja ; boolean_T
Compare_Mode_c ; boolean_T Compare_Mode_l ; boolean_T Compare_Mode_o ;
boolean_T STATE_1_CallSimulatorOutput ; boolean_T
OUTPUT_1_0_CallSimulatorOutput ; boolean_T TrueRMS_MODE ; boolean_T RMS_MODE
; boolean_T TrueRMS_MODE_e ; boolean_T RMS_MODE_h ; char_T pad_RMS_MODE_h [ 2
] ; } DW_InverterModulesInParallel_T ; typedef struct { real_T
integrator_CSTATE ; real_T integrator_CSTATE_e ; real_T integrator_CSTATE_i ;
real_T integrator_CSTATE_c [ 3 ] ; real_T integrator_CSTATE_a [ 3 ] ; real_T
integrator_CSTATE_o [ 3 ] ; } X_InverterModulesInParallel_T ; typedef struct
{ real_T integrator_CSTATE ; real_T integrator_CSTATE_e ; real_T
integrator_CSTATE_i ; real_T integrator_CSTATE_c [ 3 ] ; real_T
integrator_CSTATE_a [ 3 ] ; real_T integrator_CSTATE_o [ 3 ] ; }
XDot_InverterModulesInParallel_T ; typedef struct { boolean_T
integrator_CSTATE ; boolean_T integrator_CSTATE_e ; boolean_T
integrator_CSTATE_i ; boolean_T integrator_CSTATE_c [ 3 ] ; boolean_T
integrator_CSTATE_a [ 3 ] ; boolean_T integrator_CSTATE_o [ 3 ] ; }
XDis_InverterModulesInParallel_T ; typedef struct { real_T integrator_CSTATE
; real_T integrator_CSTATE_e ; real_T integrator_CSTATE_i ; real_T
integrator_CSTATE_c [ 3 ] ; real_T integrator_CSTATE_a [ 3 ] ; real_T
integrator_CSTATE_o [ 3 ] ; } CStateAbsTol_InverterModulesInParallel_T ;
typedef struct { real_T Compare_RelopInput_ZC ; real_T
Compare_RelopInput_ZC_e ; real_T Compare_RelopInput_ZC_d ; real_T
Compare_RelopInput_ZC_a ; real_T Compare_RelopInput_ZC_p ; real_T
Compare_RelopInput_ZC_av ; real_T Compare_RelopInput_ZC_n ; real_T
Compare_RelopInput_ZC_j ; real_T Compare_RelopInput_ZC_o ; real_T
Compare_RelopInput_ZC_i ; real_T Compare_RelopInput_ZC_f ; real_T
Compare_RelopInput_ZC_pd ; real_T Saturationtoavoidnegativesqrt_UprLim_ZC ;
real_T Saturationtoavoidnegativesqrt_LwrLim_ZC ; real_T
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 3 ] ; real_T
Saturationtoavoidnegativesqrt_LwrLim_ZC_d [ 3 ] ; }
ZCV_InverterModulesInParallel_T ; typedef struct { ZCSigState
Compare_RelopInput_ZCE ; ZCSigState Compare_RelopInput_ZCE_f ; ZCSigState
Compare_RelopInput_ZCE_j ; ZCSigState Compare_RelopInput_ZCE_fo ; ZCSigState
Compare_RelopInput_ZCE_k ; ZCSigState Compare_RelopInput_ZCE_g ; ZCSigState
Compare_RelopInput_ZCE_n ; ZCSigState Compare_RelopInput_ZCE_i ; ZCSigState
Compare_RelopInput_ZCE_h ; ZCSigState Compare_RelopInput_ZCE_m ; ZCSigState
Compare_RelopInput_ZCE_ib ; ZCSigState Compare_RelopInput_ZCE_md ; ZCSigState
Saturationtoavoidnegativesqrt_UprLim_ZCE ; ZCSigState
Saturationtoavoidnegativesqrt_LwrLim_ZCE ; ZCSigState
Saturationtoavoidnegativesqrt_UprLim_ZCE_c [ 3 ] ; ZCSigState
Saturationtoavoidnegativesqrt_LwrLim_ZCE_e [ 3 ] ; }
PrevZCX_InverterModulesInParallel_T ; typedef struct { const real_T B_18_15_0
; const real_T B_18_31_0 ; const real_T B_18_58_0 ; const real_T B_18_74_0 ;
const real_T B_18_91_0 ; const real_T B_18_106_0 ; const real_T B_18_123_0 ;
const real_T B_18_138_0 ; const real_T B_18_155_0 ; const real_T B_18_170_0 ;
const real_T B_18_187_0 ; const real_T B_18_202_0 ; }
ConstB_InverterModulesInParallel_T ;
#define InverterModulesInParallel_rtC(S) ((ConstB_InverterModulesInParallel_T *) _ssGetConstBlockIO(S))
struct P_InverterModulesInParallel_T_ { real_T P_0 ; real_T P_1 ; real_T P_2
; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8
; real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T
P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ;
real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T
P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ;
real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T
P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ;
real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T
P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 [ 3 ] ; real_T P_51 [ 3 ] ;
real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 ; real_T P_56 ; real_T
P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ; real_T P_62 ;
real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T P_67 ; real_T
P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 [ 3 ] ; real_T
P_73 [ 3 ] ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ; real_T
P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T P_83 ;
real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ; real_T
P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ; real_T P_94 ;
real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T P_99 ; real_T
P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T P_104 ; real_T
P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T P_109 ; real_T
P_110 ; real_T P_111 ; real_T P_112 ; real_T P_113 ; real_T P_114 ; real_T
P_115 ; real_T P_116 ; real_T P_117 ; real_T P_118 ; real_T P_119 ; real_T
P_120 ; real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ; real_T
P_125 ; real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ; real_T
P_130 ; real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ; real_T
P_135 ; real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T P_139 ; real_T
P_140 ; real_T P_141 ; real_T P_142 ; real_T P_143 ; real_T P_144 ; real_T
P_145 ; real_T P_146 ; real_T P_147 ; real_T P_148 ; real_T P_149 ; real_T
P_150 ; real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T P_154 ; real_T
P_155 ; real_T P_156 ; } ; extern P_InverterModulesInParallel_T
InverterModulesInParallel_rtDefaultP ; extern const
ConstB_InverterModulesInParallel_T InverterModulesInParallel_rtInvariant ;
#endif
