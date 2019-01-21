#include "__cf_InverterModulesInSeries.h"
#ifndef RTW_HEADER_InverterModulesInSeries_acc_h_
#define RTW_HEADER_InverterModulesInSeries_acc_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#ifndef InverterModulesInSeries_acc_COMMON_INCLUDES_
#define InverterModulesInSeries_acc_COMMON_INCLUDES_
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
#include "InverterModulesInSeries_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { creal_T B_22_16_0 [ 3 ] ; real_T B_22_0_0 [ 3 ] ; real_T
B_22_1_0 [ 3 ] ; real_T B_22_3_0 ; real_T B_22_5_0 [ 3 ] ; real_T B_22_7_0 [
3 ] ; real_T B_22_8_0 [ 3 ] ; real_T B_22_9_0 [ 3 ] ; real_T B_22_11_0 ;
real_T B_22_13_0 [ 3 ] ; real_T B_22_15_0 [ 3 ] ; real_T B_22_19_0 [ 3 ] ;
real_T B_22_21_0 [ 3 ] ; real_T B_22_22_0 [ 3 ] ; real_T B_21_0_0 [ 3 ] ;
real_T B_21_1_0 [ 3 ] ; real_T B_20_0_0 [ 3 ] ; real_T B_20_1_0 [ 3 ] ; }
B_RMS_InverterModulesInSeries_T ; typedef struct { real_T
Memory_PreviousInput [ 3 ] ; real_T Memory_PreviousInput_m [ 3 ] ; struct {
real_T modelTStart ; } TransportDelay_RWORK ; struct { real_T modelTStart ; }
TransportDelay_RWORK_k ; struct { void * TUbufferPtrs [ 6 ] ; }
TransportDelay_PWORK ; struct { void * TUbufferPtrs [ 6 ] ; }
TransportDelay_PWORK_i ; int32_T RMS_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_e ; struct { int_T Tail [ 3 ] ;
int_T Head [ 3 ] ; int_T Last [ 3 ] ; int_T CircularBufSize [ 3 ] ; int_T
MaxNewBufSize ; } TransportDelay_IWORK ; struct { int_T Tail [ 3 ] ; int_T
Head [ 3 ] ; int_T Last [ 3 ] ; int_T CircularBufSize [ 3 ] ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_d ; int8_T RMS_SubsysRanBC ; boolean_T
RMS_MODE ; char_T pad_RMS_MODE [ 2 ] ; } DW_RMS_InverterModulesInSeries_T ;
typedef struct { real_T integrator_CSTATE_oy [ 3 ] ; real_T
integrator_CSTATE_aa [ 3 ] ; } X_RMS_InverterModulesInSeries_T ; typedef
struct { real_T integrator_CSTATE_oy [ 3 ] ; real_T integrator_CSTATE_aa [ 3
] ; } XDot_RMS_InverterModulesInSeries_T ; typedef struct { boolean_T
integrator_CSTATE_oy [ 3 ] ; boolean_T integrator_CSTATE_aa [ 3 ] ; }
XDis_RMS_InverterModulesInSeries_T ; typedef struct { real_T
integrator_CSTATE_oy [ 3 ] ; real_T integrator_CSTATE_aa [ 3 ] ; }
XAbsTol_RMS_InverterModulesInSeries_T ; typedef struct { real_T B_24_1_0 [ 3
] ; real_T B_24_2_0 [ 3 ] ; real_T B_24_3_0 ; real_T B_24_4_0 [ 3 ] ; real_T
B_24_7_0 [ 3 ] ; real_T B_24_8_0 [ 3 ] ; real_T B_24_9_0 [ 3 ] ; real_T
B_24_10_0 [ 3 ] ; real_T B_23_0_0 [ 3 ] ; real_T B_23_1_0 [ 3 ] ; }
B_TrueRMS_InverterModulesInSeries_T ; typedef struct { real_T
Memory_PreviousInput [ 3 ] ; struct { real_T modelTStart ; }
TransportDelay_RWORK ; struct { void * TUbufferPtrs [ 6 ] ; }
TransportDelay_PWORK ; int32_T TrueRMS_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; struct { int_T Tail [ 3 ] ;
int_T Head [ 3 ] ; int_T Last [ 3 ] ; int_T CircularBufSize [ 3 ] ; int_T
MaxNewBufSize ; } TransportDelay_IWORK ; int_T
Saturationtoavoidnegativesqrt_MODE [ 3 ] ; int8_T TrueRMS_SubsysRanBC ;
int8_T Sqrt_DWORK1 ; boolean_T TrueRMS_MODE ; char_T pad_TrueRMS_MODE [ 5 ] ;
} DW_TrueRMS_InverterModulesInSeries_T ; typedef struct { real_T
integrator_CSTATE_cc [ 3 ] ; } X_TrueRMS_InverterModulesInSeries_T ; typedef
struct { real_T integrator_CSTATE_cc [ 3 ] ; }
XDot_TrueRMS_InverterModulesInSeries_T ; typedef struct { boolean_T
integrator_CSTATE_cc [ 3 ] ; } XDis_TrueRMS_InverterModulesInSeries_T ;
typedef struct { real_T integrator_CSTATE_cc [ 3 ] ; }
XAbsTol_TrueRMS_InverterModulesInSeries_T ; typedef struct { real_T
Saturationtoavoidnegativesqrt_UprLim_ZC [ 3 ] ; real_T
Saturationtoavoidnegativesqrt_LwrLim_ZC [ 3 ] ; }
ZCV_TrueRMS_InverterModulesInSeries_T ; typedef struct { ZCSigState
Saturationtoavoidnegativesqrt_UprLim_ZCE [ 3 ] ; ZCSigState
Saturationtoavoidnegativesqrt_LwrLim_ZCE [ 3 ] ; }
ZCE_TrueRMS_InverterModulesInSeries_T ; typedef struct { real_T B_33_4_0 ;
real_T B_33_6_0 ; real_T B_33_7_0 ; real_T B_33_8_0 ; real_T B_33_10_0 ;
real_T B_33_12_0 ; real_T B_33_16_0 ; real_T B_33_17_0 ; real_T B_33_18_0 ;
real_T B_33_21_0 ; real_T B_33_22_0 ; real_T B_33_23_0 ; real_T B_33_26_0 ;
real_T B_33_27_0 ; real_T B_33_30_0 ; real_T B_33_31_0 [ 4 ] ; real_T
B_33_32_0 ; real_T B_33_34_0 ; real_T B_33_37_0 ; real_T B_33_38_0 ; real_T
B_33_41_0 ; real_T B_33_42_0 ; real_T B_33_45_0 ; real_T B_33_46_0 [ 4 ] ;
real_T B_33_47_0 ; real_T B_33_49_0 ; real_T B_33_50_0 ; real_T B_33_51_0 ;
real_T B_33_54_0 ; real_T B_33_55_0 ; real_T B_33_58_0 ; real_T B_33_59_0 ;
real_T B_33_62_0 ; real_T B_33_63_0 [ 4 ] ; real_T B_33_64_0 ; real_T
B_33_66_0 ; real_T B_33_69_0 ; real_T B_33_70_0 ; real_T B_33_73_0 ; real_T
B_33_74_0 ; real_T B_33_77_0 ; real_T B_33_78_0 [ 4 ] ; real_T B_33_79_0 ;
real_T B_33_81_0 ; real_T B_33_82_0 ; real_T B_33_83_0 ; real_T B_33_86_0 ;
real_T B_33_87_0 ; real_T B_33_90_0 ; real_T B_33_91_0 ; real_T B_33_94_0 ;
real_T B_33_95_0 [ 4 ] ; real_T B_33_96_0 ; real_T B_33_98_0 ; real_T
B_33_101_0 ; real_T B_33_102_0 ; real_T B_33_105_0 ; real_T B_33_106_0 ;
real_T B_33_109_0 ; real_T B_33_110_0 [ 4 ] ; real_T B_33_111_0 ; real_T
B_33_113_0 ; real_T B_33_114_0 ; real_T B_33_115_0 ; real_T B_33_117_0 ;
real_T B_33_119_0 ; real_T B_33_123_0 ; real_T B_33_124_0 ; real_T B_33_125_0
; real_T B_33_128_0 ; real_T B_33_129_0 ; real_T B_33_130_0 ; real_T
B_33_133_0 ; real_T B_33_134_0 ; real_T B_33_137_0 ; real_T B_33_138_0 [ 4 ]
; real_T B_33_139_0 ; real_T B_33_141_0 ; real_T B_33_144_0 ; real_T
B_33_145_0 ; real_T B_33_148_0 ; real_T B_33_149_0 ; real_T B_33_152_0 ;
real_T B_33_153_0 [ 4 ] ; real_T B_33_154_0 ; real_T B_33_156_0 ; real_T
B_33_157_0 ; real_T B_33_158_0 ; real_T B_33_161_0 ; real_T B_33_162_0 ;
real_T B_33_165_0 ; real_T B_33_166_0 ; real_T B_33_169_0 ; real_T B_33_170_0
[ 4 ] ; real_T B_33_171_0 ; real_T B_33_173_0 ; real_T B_33_176_0 ; real_T
B_33_177_0 ; real_T B_33_180_0 ; real_T B_33_181_0 ; real_T B_33_184_0 ;
real_T B_33_185_0 [ 4 ] ; real_T B_33_186_0 ; real_T B_33_188_0 ; real_T
B_33_189_0 ; real_T B_33_190_0 ; real_T B_33_193_0 ; real_T B_33_194_0 ;
real_T B_33_197_0 ; real_T B_33_198_0 ; real_T B_33_201_0 ; real_T B_33_202_0
[ 4 ] ; real_T B_33_203_0 ; real_T B_33_205_0 ; real_T B_33_208_0 ; real_T
B_33_209_0 ; real_T B_33_212_0 ; real_T B_33_213_0 ; real_T B_33_216_0 ;
real_T B_33_217_0 [ 4 ] ; real_T B_33_218_0 [ 191 ] ; real_T B_33_219_0 [ 54
] ; real_T B_33_220_0 ; real_T B_33_221_0 ; real_T B_33_222_0 ; real_T
B_33_226_0 ; real_T B_33_227_0 ; real_T B_33_228_0 ; real_T B_33_237_0 [ 3 ]
; real_T B_33_244_0 [ 3 ] ; real_T B_33_246_0 ; real_T B_33_248_0 ; real_T
B_33_255_0 ; real_T B_33_258_0 ; real_T B_33_260_0 ; real_T B_33_262_0 ;
real_T B_33_263_0 ; real_T B_33_266_0 ; real_T B_33_268_0 ; real_T B_33_270_0
; real_T B_33_273_0 ; real_T B_33_276_0 ; real_T B_33_278_0 ; real_T
B_33_280_0 ; real_T B_33_281_0 ; real_T B_33_284_0 ; real_T B_33_286_0 ;
real_T B_33_288_0 ; real_T B_33_291_0 ; real_T B_33_292_0 ; real_T B_33_295_0
; real_T B_33_297_0 ; real_T B_33_299_0 ; real_T B_33_300_0 ; real_T
B_33_303_0 ; real_T B_33_305_0 ; real_T B_33_307_0 ; real_T B_33_310_0 ;
real_T B_33_313_0 ; real_T B_33_315_0 ; real_T B_33_317_0 ; real_T B_33_318_0
; real_T B_33_321_0 ; real_T B_33_323_0 ; real_T B_33_325_0 ; real_T
B_33_328_0 ; real_T B_33_331_0 ; real_T B_33_333_0 ; real_T B_33_335_0 ;
real_T B_33_337_0 ; real_T B_33_339_0 ; real_T B_33_341_0 ; real_T B_33_343_0
; real_T B_33_345_0 ; real_T B_27_1_0 ; real_T B_27_2_0 ; real_T B_27_3_0 ;
real_T B_27_4_0 ; real_T B_27_7_0 ; real_T B_27_8_0 ; real_T B_26_0_0 ;
real_T B_26_1_0 ; real_T B_25_3_0 ; real_T B_25_5_0 ; boolean_T B_33_233_0 ;
boolean_T B_33_235_0 ; boolean_T B_33_240_0 ; boolean_T B_33_242_0 ;
boolean_T B_33_751_0 ; boolean_T B_33_752_0 ; char_T pad_B_33_752_0 [ 2 ] ;
B_TrueRMS_InverterModulesInSeries_T TrueRMS_o ;
B_RMS_InverterModulesInSeries_T RMS_m ; B_TrueRMS_InverterModulesInSeries_T
TrueRMS ; B_RMS_InverterModulesInSeries_T RMS ; } B_InverterModulesInSeries_T
; typedef struct { real_T DelayInput2_DSTATE ; real_T INPUT_1_1_1_discrete [
2 ] ; real_T DelayInput2_DSTATE_c ; real_T INPUT_2_1_1_discrete [ 2 ] ;
real_T DelayInput2_DSTATE_d ; real_T INPUT_3_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_f ; real_T INPUT_4_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_n ; real_T INPUT_5_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_m ; real_T INPUT_6_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_dc ; real_T INPUT_7_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_dj ; real_T INPUT_8_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_a ; real_T INPUT_9_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_nv ; real_T INPUT_10_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_o ; real_T INPUT_11_1_1_discrete [ 2 ] ; real_T
DelayInput2_DSTATE_k ; real_T INPUT_12_1_1_discrete [ 2 ] ; real_T
STATE_1_DiscStates [ 179 ] ; real_T Memory_PreviousInput ; real_T
Memory_PreviousInput_e ; real_T Memory_PreviousInput_k ; real_T
Memory_PreviousInput_h ; real_T Memory_PreviousInput_a ; real_T
Memory_PreviousInput_c ; real_T Memory_PreviousInput_f ; real_T
Memory_PreviousInput_eh ; real_T Memory_PreviousInput_p ; struct { real_T
modelTStart ; } TransportDelay_RWORK ; struct { real_T modelTStart ; }
TransportDelay_RWORK_g ; struct { real_T modelTStart ; }
TransportDelay_RWORK_i ; struct { real_T modelTStart ; }
TransportDelay_RWORK_a ; struct { real_T modelTStart ; }
TransportDelay_RWORK_l ; struct { real_T modelTStart ; }
TransportDelay_RWORK_e ; struct { real_T modelTStart ; }
TransportDelay_RWORK_ie ; struct { real_T modelTStart ; }
TransportDelay_RWORK_gs ; struct { real_T modelTStart ; }
TransportDelay_RWORK_lx ; void * STATE_1_Simulator ; void *
STATE_1_SimulationData ; void * STATE_1_DiagnosticManager ; void *
STATE_1_VariableLogger ; void * STATE_1_ZeroCrossingLogger ; void *
STATE_1_SampleTimeIdx ; void * OUTPUT_1_0_Simulator ; void *
OUTPUT_1_0_SimulationData ; void * OUTPUT_1_0_DiagnosticManager ; void *
OUTPUT_1_0_VariableLogger ; void * OUTPUT_1_0_ZeroCrossingLogger ; void *
OUTPUT_1_0_SampleTimeIdx ; struct { void * AQHandles [ 3 ] ; void * SlioLTF ;
} HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK ; struct { void
* AQHandles [ 3 ] ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK ; struct { void *
AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_5_PWORK ; struct { void *
AQHandles [ 3 ] ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK ; struct { void *
AQHandles [ 3 ] ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK ; struct { void *
AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_5_PWORK ; struct { void *
AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_RMS2_at_outport_0_PWORK ; struct { void *
AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK ; struct { void *
AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_Saturation1_at_outport_0_PWORK ; struct { void
* AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_Saturation_at_outport_0_PWORK ; void *
Scope_PWORK [ 2 ] ; void * Scope1_PWORK [ 2 ] ; void * Scope2_PWORK [ 2 ] ;
void * Scope6_PWORK [ 2 ] ; void * Scope8_PWORK [ 2 ] ; struct { void *
TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK ; struct { void * TUbufferPtrs [
2 ] ; } TransportDelay_PWORK_i ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_o ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_m ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_j ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_p ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_jk ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_g ; void * Scope9_PWORK [ 2 ] ; void * Scope12_PWORK [ 4
] ; void * Scope12_PWORK_g [ 4 ] ; struct { void * AQHandles ; void * SlioLTF
; } HiddenToAsyncQueue_InsertedFor_Gain_at_outport_0_PWORK ; struct { void *
AQHandles ; void * SlioLTF ; }
HiddenToAsyncQueue_InsertedFor_Saturation2_at_outport_0_PWORK ; struct { void
* TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_oj ; int32_T
TrueRMS_sysIdxToRun ; int32_T TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ;
int32_T RMS_sysIdxToRun ; int32_T TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun
; int32_T TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_i ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_f ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_h ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_b ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_g ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_g1 ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_ii ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_c ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_n ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_np ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_a ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_g ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_d ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_o ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_e ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_c ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_j ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_h ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_n ; uint32_T m_bpIndex ; uint32_T
m_bpIndex_a ; int_T STATE_1_Modes [ 12 ] ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_c ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_m ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_d ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_e ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_p ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_l ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_o ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_dv ; int_T
Saturationtoavoidnegativesqrt_MODE ; int8_T TrueRMS_SubsysRanBC ; int8_T
RMS_SubsysRanBC ; boolean_T Compare_Mode ; boolean_T Compare_Mode_g ;
boolean_T Compare_Mode_p ; boolean_T Compare_Mode_j ; boolean_T
Compare_Mode_h ; boolean_T Compare_Mode_i ; boolean_T Compare_Mode_ja ;
boolean_T Compare_Mode_c ; boolean_T Compare_Mode_l ; boolean_T
Compare_Mode_o ; boolean_T Compare_Mode_hj ; boolean_T Compare_Mode_i4 ;
boolean_T STATE_1_CallSimulatorOutput ; boolean_T
OUTPUT_1_0_CallSimulatorOutput ; boolean_T TrueRMS_MODE ; boolean_T RMS_MODE
; char_T pad_RMS_MODE [ 2 ] ; DW_TrueRMS_InverterModulesInSeries_T TrueRMS_o
; DW_RMS_InverterModulesInSeries_T RMS_m ;
DW_TrueRMS_InverterModulesInSeries_T TrueRMS ;
DW_RMS_InverterModulesInSeries_T RMS ; } DW_InverterModulesInSeries_T ;
typedef struct { real_T integrator_CSTATE ; real_T integrator_CSTATE_c ;
real_T integrator_CSTATE_l ; real_T integrator_CSTATE_a ; real_T
integrator_CSTATE_o ; real_T integrator_CSTATE_h ; real_T
integrator_CSTATE_oe ; real_T integrator_CSTATE_f ;
X_TrueRMS_InverterModulesInSeries_T TrueRMS_o ;
X_RMS_InverterModulesInSeries_T RMS_m ; real_T integrator_CSTATE_m ; real_T
integrator_CSTATE_e ; real_T integrator_CSTATE_i ;
X_TrueRMS_InverterModulesInSeries_T TrueRMS ; X_RMS_InverterModulesInSeries_T
RMS ; } X_InverterModulesInSeries_T ; typedef struct { real_T
integrator_CSTATE ; real_T integrator_CSTATE_c ; real_T integrator_CSTATE_l ;
real_T integrator_CSTATE_a ; real_T integrator_CSTATE_o ; real_T
integrator_CSTATE_h ; real_T integrator_CSTATE_oe ; real_T
integrator_CSTATE_f ; XDot_TrueRMS_InverterModulesInSeries_T TrueRMS_o ;
XDot_RMS_InverterModulesInSeries_T RMS_m ; real_T integrator_CSTATE_m ;
real_T integrator_CSTATE_e ; real_T integrator_CSTATE_i ;
XDot_TrueRMS_InverterModulesInSeries_T TrueRMS ;
XDot_RMS_InverterModulesInSeries_T RMS ; } XDot_InverterModulesInSeries_T ;
typedef struct { boolean_T integrator_CSTATE ; boolean_T integrator_CSTATE_c
; boolean_T integrator_CSTATE_l ; boolean_T integrator_CSTATE_a ; boolean_T
integrator_CSTATE_o ; boolean_T integrator_CSTATE_h ; boolean_T
integrator_CSTATE_oe ; boolean_T integrator_CSTATE_f ;
XDis_TrueRMS_InverterModulesInSeries_T TrueRMS_o ;
XDis_RMS_InverterModulesInSeries_T RMS_m ; boolean_T integrator_CSTATE_m ;
boolean_T integrator_CSTATE_e ; boolean_T integrator_CSTATE_i ;
XDis_TrueRMS_InverterModulesInSeries_T TrueRMS ;
XDis_RMS_InverterModulesInSeries_T RMS ; } XDis_InverterModulesInSeries_T ;
typedef struct { real_T integrator_CSTATE ; real_T integrator_CSTATE_c ;
real_T integrator_CSTATE_l ; real_T integrator_CSTATE_a ; real_T
integrator_CSTATE_o ; real_T integrator_CSTATE_h ; real_T
integrator_CSTATE_oe ; real_T integrator_CSTATE_f ;
XAbsTol_TrueRMS_InverterModulesInSeries_T TrueRMS_o ;
XAbsTol_RMS_InverterModulesInSeries_T RMS_m ; real_T integrator_CSTATE_m ;
real_T integrator_CSTATE_e ; real_T integrator_CSTATE_i ;
XAbsTol_TrueRMS_InverterModulesInSeries_T TrueRMS ;
XAbsTol_RMS_InverterModulesInSeries_T RMS ; }
CStateAbsTol_InverterModulesInSeries_T ; typedef struct { real_T
Compare_RelopInput_ZC ; real_T Compare_RelopInput_ZC_e ; real_T
Compare_RelopInput_ZC_p ; real_T Compare_RelopInput_ZC_a ; real_T
Compare_RelopInput_ZC_n ; real_T Compare_RelopInput_ZC_j ; real_T
Compare_RelopInput_ZC_o ; real_T Compare_RelopInput_ZC_i ; real_T
Compare_RelopInput_ZC_f ; real_T Compare_RelopInput_ZC_pd ; real_T
Compare_RelopInput_ZC_d ; real_T Compare_RelopInput_ZC_aj ;
ZCV_TrueRMS_InverterModulesInSeries_T TrueRMS_o ; real_T
Saturationtoavoidnegativesqrt_UprLim_ZC_f ; real_T
Saturationtoavoidnegativesqrt_LwrLim_ZC_p ;
ZCV_TrueRMS_InverterModulesInSeries_T TrueRMS ; }
ZCV_InverterModulesInSeries_T ; typedef struct { ZCSigState
Compare_RelopInput_ZCE ; ZCSigState Compare_RelopInput_ZCE_f ; ZCSigState
Compare_RelopInput_ZCE_k ; ZCSigState Compare_RelopInput_ZCE_g ; ZCSigState
Compare_RelopInput_ZCE_n ; ZCSigState Compare_RelopInput_ZCE_i ; ZCSigState
Compare_RelopInput_ZCE_h ; ZCSigState Compare_RelopInput_ZCE_m ; ZCSigState
Compare_RelopInput_ZCE_ib ; ZCSigState Compare_RelopInput_ZCE_md ; ZCSigState
Compare_RelopInput_ZCE_j ; ZCSigState Compare_RelopInput_ZCE_fo ;
ZCE_TrueRMS_InverterModulesInSeries_T TrueRMS_o ; ZCSigState
Saturationtoavoidnegativesqrt_UprLim_ZCE_h ; ZCSigState
Saturationtoavoidnegativesqrt_LwrLim_ZCE_f ;
ZCE_TrueRMS_InverterModulesInSeries_T TrueRMS ; }
PrevZCX_InverterModulesInSeries_T ; typedef struct { const real_T B_33_19_0 ;
const real_T B_33_35_0 ; const real_T B_33_52_0 ; const real_T B_33_67_0 ;
const real_T B_33_84_0 ; const real_T B_33_99_0 ; const real_T B_33_126_0 ;
const real_T B_33_142_0 ; const real_T B_33_159_0 ; const real_T B_33_174_0 ;
const real_T B_33_191_0 ; const real_T B_33_206_0 ; }
ConstB_InverterModulesInSeries_T ;
#define InverterModulesInSeries_rtC(S) ((ConstB_InverterModulesInSeries_T *) _ssGetConstBlockIO(S))
struct P_RMS_InverterModulesInSeries_T_ { real_T P_0 ; real_T P_1 ; real_T
P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T
P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ;
real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T
P_19 ; real_T P_20 ; real_T P_21 ; } ; struct
P_TrueRMS_InverterModulesInSeries_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ;
real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ;
} ; struct P_InverterModulesInSeries_T_ { real_T P_0 ; real_T P_1 ; real_T
P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T
P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ;
real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T
P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ;
real_T P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T
P_30 ; real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ;
real_T P_36 ; real_T P_37 ; real_T P_38 [ 3 ] ; real_T P_39 [ 3 ] ; real_T
P_40 ; real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ;
real_T P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T
P_51 ; real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 ; real_T P_56 ;
real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ; real_T
P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T P_67 ;
real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ; real_T
P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ; real_T P_78 ;
real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T P_83 ; real_T
P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 [ 3 ] ; real_T
P_89 [ 3 ] ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ; real_T
P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T P_99 ;
real_T P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T P_104 ;
real_T P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T P_109 ;
real_T P_110 ; real_T P_111 ; real_T P_112 ; real_T P_113 ; real_T P_114 ;
real_T P_115 ; real_T P_116 ; real_T P_117 ; real_T P_118 ; real_T P_119 ;
real_T P_120 ; real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ;
real_T P_125 ; real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ;
real_T P_130 ; real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ;
real_T P_135 ; real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T P_139 ;
real_T P_140 ; real_T P_141 ; real_T P_142 ; real_T P_143 ; real_T P_144 ;
real_T P_145 ; real_T P_146 ; real_T P_147 ; real_T P_148 ; real_T P_149 ;
real_T P_150 ; real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T P_154 ;
real_T P_155 ; real_T P_156 ; real_T P_157 ; real_T P_158 ; real_T P_159 ;
real_T P_160 ; real_T P_161 ; real_T P_162 ; real_T P_163 ; real_T P_164 ;
real_T P_165 ; real_T P_166 ; real_T P_167 ; real_T P_168 ; real_T P_169 ;
real_T P_170 ; real_T P_171 ; real_T P_172 ; real_T P_173 ; real_T P_174 ;
real_T P_175 ; real_T P_176 ; real_T P_177 ; real_T P_178 ; real_T P_179 ;
real_T P_180 ; real_T P_181 ; real_T P_182 ; real_T P_183 ; real_T P_184 ;
real_T P_185 ; real_T P_186 ; real_T P_187 ; real_T P_188 ; real_T P_189 ;
real_T P_190 ; real_T P_191 ; real_T P_192 ; real_T P_193 ; real_T P_194 ;
real_T P_195 ; real_T P_196 ; real_T P_197 ; real_T P_198 ; real_T P_199 ;
real_T P_200 ; real_T P_201 ; real_T P_202 ; real_T P_203 ; real_T P_204 ;
real_T P_205 ; real_T P_206 ; real_T P_207 ; real_T P_208 ; real_T P_209 ;
real_T P_210 ; real_T P_211 ; real_T P_212 ; real_T P_213 ; real_T P_214 ;
real_T P_215 ; real_T P_216 ; real_T P_217 ; real_T P_218 ; real_T P_219 ;
real_T P_220 ; real_T P_221 ; real_T P_222 ; real_T P_223 ; real_T P_224 ;
real_T P_225 ; real_T P_226 ; P_TrueRMS_InverterModulesInSeries_T TrueRMS_o ;
P_RMS_InverterModulesInSeries_T RMS_m ; P_TrueRMS_InverterModulesInSeries_T
TrueRMS ; P_RMS_InverterModulesInSeries_T RMS ; } ; extern
P_InverterModulesInSeries_T InverterModulesInSeries_rtDefaultP ; extern const
ConstB_InverterModulesInSeries_T InverterModulesInSeries_rtInvariant ;
#endif
