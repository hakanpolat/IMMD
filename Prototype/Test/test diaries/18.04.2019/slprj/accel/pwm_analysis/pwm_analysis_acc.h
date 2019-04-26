#include "__cf_pwm_analysis.h"
#ifndef RTW_HEADER_pwm_analysis_acc_h_
#define RTW_HEADER_pwm_analysis_acc_h_
#include <stddef.h>
#include <float.h>
#ifndef pwm_analysis_acc_COMMON_INCLUDES_
#define pwm_analysis_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "pwm_analysis_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_17_0_0 ; real_T B_17_3_0 ; real_T B_17_5_0 ; real_T
B_17_7_0 ; real_T B_17_8_0 ; real_T B_17_11_0 ; real_T B_17_13_0 ; real_T
B_17_15_0 ; real_T B_17_19_0 ; real_T B_17_21_0 ; real_T B_17_22_0 ; }
B_RMS_pwm_analysis_T ; typedef struct { real_T Memory_PreviousInput ; real_T
Memory_PreviousInput_p ; struct { real_T modelTStart ; } TransportDelay_RWORK
; struct { real_T modelTStart ; } TransportDelay_RWORK_m ; struct { void *
TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK ; struct { void * TUbufferPtrs [
2 ] ; } TransportDelay_PWORK_n ; int32_T RMS_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_k ; struct { int_T Tail ; int_T
Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_m ; int8_T
RMS_SubsysRanBC ; boolean_T RMS_MODE ; char_T pad_RMS_MODE [ 2 ] ; }
DW_RMS_pwm_analysis_T ; typedef struct { real_T integrator_CSTATE_ov ; real_T
integrator_CSTATE_gh ; } X_RMS_pwm_analysis_T ; typedef struct { real_T
integrator_CSTATE_ov ; real_T integrator_CSTATE_gh ; }
XDot_RMS_pwm_analysis_T ; typedef struct { boolean_T integrator_CSTATE_ov ;
boolean_T integrator_CSTATE_gh ; } XDis_RMS_pwm_analysis_T ; typedef struct {
real_T B_19_1_0 ; real_T B_19_3_0 ; real_T B_19_4_0 ; real_T B_19_7_0 ;
real_T B_19_8_0 ; real_T B_19_10_0 ; } B_TrueRMS_pwm_analysis_T ; typedef
struct { real_T Memory_PreviousInput ; struct { real_T modelTStart ; }
TransportDelay_RWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK ; int32_T TrueRMS_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; struct { int_T Tail ; int_T Head
; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; int8_T TrueRMS_SubsysRanBC ; boolean_T TrueRMS_MODE ;
char_T pad_TrueRMS_MODE [ 2 ] ; } DW_TrueRMS_pwm_analysis_T ; typedef struct
{ real_T integrator_CSTATE_h ; } X_TrueRMS_pwm_analysis_T ; typedef struct {
real_T integrator_CSTATE_h ; } XDot_TrueRMS_pwm_analysis_T ; typedef struct {
boolean_T integrator_CSTATE_h ; } XDis_TrueRMS_pwm_analysis_T ; typedef
struct { real_T B_75_0_0 ; real_T B_75_1_0 [ 16 ] ; real_T B_75_1_1 [ 6 ] ;
real_T B_75_4_0 ; real_T B_75_6_0 ; real_T B_75_10_0 ; real_T B_75_12_0 ;
real_T B_75_14_0 ; real_T B_75_15_0 ; real_T B_75_16_0 ; real_T B_75_17_0 ;
real_T B_75_20_0 ; real_T B_75_21_0 ; real_T B_75_24_0 ; real_T B_75_25_0 ;
real_T B_75_28_0 ; real_T B_75_29_0 ; real_T B_75_31_0 ; real_T B_75_32_0 ;
real_T B_75_33_0 ; real_T B_75_37_0 ; real_T B_75_49_0 ; real_T B_75_55_0 ;
real_T B_75_60_0 ; real_T B_75_63_0 ; real_T B_75_65_0 ; real_T B_75_67_0 ;
real_T B_75_69_0 ; real_T B_75_73_0 ; real_T B_75_76_0 ; real_T B_75_78_0 ;
real_T B_75_80_0 ; real_T B_75_81_0 ; real_T B_75_84_0 ; real_T B_75_86_0 ;
real_T B_75_88_0 ; real_T B_75_90_0 ; real_T B_75_92_0 ; real_T B_75_95_0 ;
real_T B_75_97_0 ; real_T B_75_99_0 ; real_T B_75_101_0 ; real_T B_75_104_0 ;
real_T B_75_106_0 ; real_T B_75_108_0 ; real_T B_75_110_0 ; real_T B_75_112_0
; real_T B_75_115_0 ; real_T B_75_117_0 ; real_T B_75_119_0 ; real_T
B_75_122_0 ; real_T B_75_124_0 ; real_T B_75_127_0 ; real_T B_75_129_0 ;
real_T B_75_131_0 ; real_T B_75_132_0 ; real_T B_75_135_0 ; real_T B_75_137_0
; real_T B_75_139_0 ; real_T B_75_141_0 ; real_T B_75_143_0 ; real_T
B_75_146_0 ; real_T B_75_148_0 ; real_T B_75_150_0 ; real_T B_75_151_0 ;
real_T B_75_154_0 ; real_T B_75_156_0 ; real_T B_75_158_0 ; real_T B_75_160_0
; real_T B_75_162_0 ; real_T B_75_165_0 ; real_T B_75_167_0 ; real_T
B_75_169_0 ; real_T B_75_170_0 ; real_T B_75_173_0 ; real_T B_75_175_0 ;
real_T B_75_177_0 ; real_T B_75_179_0 ; real_T B_75_184_0 ; real_T B_75_185_0
; real_T B_75_186_0 ; real_T B_75_188_0 ; real_T B_75_189_0 ; real_T
B_75_190_0 ; real_T B_75_194_0 ; real_T B_75_197_0 ; real_T B_75_199_0 ;
real_T B_75_202_0 ; real_T B_75_204_0 ; real_T B_75_206_0 ; real_T B_75_208_0
; real_T B_75_216_0 ; real_T B_75_217_0 ; real_T B_75_218_0 ; real_T
B_75_219_0 ; real_T B_75_226_0 ; real_T B_75_228_0 ; real_T B_75_229_0 ;
real_T B_75_230_0 ; real_T B_75_231_0 ; real_T B_75_238_0 ; real_T B_75_241_0
; real_T B_75_243_0 ; real_T B_75_244_0 ; real_T B_75_246_0 ; real_T
B_75_249_0 ; real_T B_75_250_0 ; real_T B_75_251_0 ; real_T B_75_252_0 ;
real_T B_75_259_0 ; real_T B_75_261_0 ; real_T B_75_262_0 ; real_T B_75_263_0
; real_T B_75_264_0 ; real_T B_75_271_0 ; real_T B_75_274_0 ; real_T
B_75_276_0 ; real_T B_75_278_0 ; real_T B_75_279_0 ; real_T B_75_288_0 ;
real_T B_75_291_0 ; real_T B_75_293_0 ; real_T B_75_295_0 ; real_T B_75_309_0
; real_T B_75_316_0 ; real_T B_75_328_0 ; real_T B_75_331_0 ; real_T
B_75_333_0 ; real_T B_75_335_0 ; real_T B_75_349_0 ; real_T B_75_358_0 ;
real_T B_75_360_0 ; real_T B_75_363_0 ; real_T B_75_369_0 ; real_T B_75_372_0
; real_T B_75_373_0 ; real_T B_75_374_0 ; real_T B_75_375_0 ; real_T
B_75_382_0 ; real_T B_75_384_0 ; real_T B_75_385_0 ; real_T B_75_386_0 ;
real_T B_75_387_0 ; real_T B_75_394_0 ; real_T B_75_397_0 ; real_T B_75_399_0
; real_T B_75_408_0 ; real_T B_75_411_0 ; real_T B_75_413_0 ; real_T
B_75_415_0 ; real_T B_75_429_0 ; real_T B_75_432_0 ; real_T B_75_434_0 ;
real_T B_75_436_0 ; real_T B_75_438_0 ; real_T B_75_440_0 ; real_T B_75_442_0
; real_T B_75_444_0 ; real_T B_75_446_0 ; real_T B_74_0_1 ; real_T B_74_0_2 ;
real_T B_74_0_3 ; real_T B_9_0_1 ; real_T B_9_0_2 ; real_T B_9_0_3 ; real_T
B_9_0_4 ; real_T B_9_0_5 ; real_T B_9_0_6 ; real_T B_8_0_1 ; real_T B_8_0_2 ;
real_T B_8_0_3 ; boolean_T B_75_51_0 ; boolean_T B_75_53_0 ; boolean_T
B_75_282_0 ; boolean_T B_75_284_0 ; boolean_T B_75_298_0 ; boolean_T
B_75_300_0 ; boolean_T B_75_312_0 ; boolean_T B_75_314_0 ; boolean_T
B_75_322_0 ; boolean_T B_75_324_0 ; boolean_T B_75_338_0 ; boolean_T
B_75_340_0 ; boolean_T B_75_354_0 ; boolean_T B_75_356_0 ; boolean_T
B_75_365_0 ; boolean_T B_75_367_0 ; boolean_T B_75_402_0 ; boolean_T
B_75_404_0 ; boolean_T B_75_418_0 ; boolean_T B_75_420_0 ; char_T
pad_B_75_420_0 [ 4 ] ; B_TrueRMS_pwm_analysis_T TrueRMS_hu ;
B_RMS_pwm_analysis_T RMS_js ; B_TrueRMS_pwm_analysis_T TrueRMS_ff ;
B_RMS_pwm_analysis_T RMS_p ; B_TrueRMS_pwm_analysis_T TrueRMS_p ;
B_RMS_pwm_analysis_T RMS_j ; B_TrueRMS_pwm_analysis_T TrueRMS_a ;
B_RMS_pwm_analysis_T RMS_d ; B_TrueRMS_pwm_analysis_T TrueRMS_j ;
B_RMS_pwm_analysis_T RMS_o ; B_TrueRMS_pwm_analysis_T TrueRMS_k ;
B_RMS_pwm_analysis_T RMS_f ; B_TrueRMS_pwm_analysis_T TrueRMS_i ;
B_RMS_pwm_analysis_T RMS_lk ; B_TrueRMS_pwm_analysis_T TrueRMS_f ;
B_RMS_pwm_analysis_T RMS_g ; B_TrueRMS_pwm_analysis_T TrueRMS_h ;
B_RMS_pwm_analysis_T RMS_l ; B_TrueRMS_pwm_analysis_T TrueRMS ;
B_RMS_pwm_analysis_T RMS ; } B_pwm_analysis_T ; typedef struct { real_T
StateSpace_DSTATE [ 5 ] ; real_T Delay_DSTATE ; real_T Delay1_DSTATE ; real_T
Delay2_DSTATE ; real_T Delay3_DSTATE ; real_T Integ4_DSTATE ; real_T
UnitDelay_DSTATE ; real_T UnitDelay1_DSTATE ; real_T Integ4_DSTATE_j ; real_T
UnitDelay_DSTATE_j ; real_T UnitDelay1_DSTATE_a ; real_T Integ4_DSTATE_k ;
real_T UnitDelay_DSTATE_k ; real_T UnitDelay1_DSTATE_b ; real_T
Integ4_DSTATE_a ; real_T UnitDelay_DSTATE_n ; real_T UnitDelay1_DSTATE_a0 ;
real_T Integ4_DSTATE_i ; real_T UnitDelay_DSTATE_g ; real_T
UnitDelay1_DSTATE_o ; real_T Integ4_DSTATE_az ; real_T UnitDelay_DSTATE_b ;
real_T UnitDelay1_DSTATE_n ; real_T ICic_PreviousInput ; real_T
ICic_PreviousInput_i ; real_T ICic_PreviousInput_g ; real_T
Memory_PreviousInput ; real_T Memory_PreviousInput_k ; real_T
Memory_PreviousInput_a ; real_T Memory_PreviousInput_l ; real_T
Memory_PreviousInput_e ; real_T Memory_PreviousInput_k4 ; real_T
Memory_PreviousInput_ki ; real_T Memory_PreviousInput_f ; real_T
Memory_PreviousInput_p ; real_T Memory_PreviousInput_pj ; real_T
Memory_PreviousInput_n ; real_T Memory_PreviousInput_lp ; real_T
Memory_PreviousInput_aw ; real_T lastSin ; real_T lastCos ; real_T lastSin_e
; real_T lastCos_k ; real_T lastSin_f ; real_T lastCos_p ; real_T lastSin_ej
; real_T lastCos_a ; real_T Memory_PreviousInput_d ; real_T
Memory_PreviousInput_b ; real_T lastSin_n ; real_T lastCos_g ; real_T
lastSin_m ; real_T lastCos_i ; real_T Memory_PreviousInput_c ; struct {
real_T modelTStart ; } TransportDelay_RWORK ; struct { real_T modelTStart ; }
TransportDelay_RWORK_j ; struct { real_T modelTStart ; }
TransportDelay_RWORK_k ; struct { real_T modelTStart ; }
TransportDelay_RWORK_b ; struct { real_T modelTStart ; }
TransportDelay_RWORK_kd ; struct { real_T modelTStart ; }
TransportDelay_RWORK_p ; struct { real_T modelTStart ; }
TransportDelay_RWORK_i ; struct { real_T modelTStart ; }
TransportDelay_RWORK_e ; struct { real_T modelTStart ; }
TransportDelay_RWORK_h ; struct { real_T modelTStart ; }
TransportDelay_RWORK_d ; struct { real_T modelTStart ; }
TransportDelay_RWORK_p0 ; struct { real_T modelTStart ; }
TransportDelay_RWORK_ht ; struct { real_T modelTStart ; }
TransportDelay_RWORK_ew ; real_T SFunction_RWORK ; real_T SFunction_RWORK_h ;
real_T SFunction_RWORK_n ; real_T SFunction_RWORK_c ; struct { real_T
modelTStart ; } TransportDelay_RWORK_jr ; struct { real_T modelTStart ; }
TransportDelay_RWORK_m ; real_T SFunction_RWORK_f ; real_T SFunction_RWORK_fy
; struct { real_T modelTStart ; } TransportDelay_RWORK_o ; struct { void * AS
; void * BS ; void * CS ; void * DS ; void * DX_COL ; void * BD_COL ; void *
TMP1 ; void * TMP2 ; void * XTMP ; void * SWITCH_STATUS ; void *
SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ; void * USWLAST ; void *
XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ; void * IDX_SW_CHG ; void
* Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW ; void *
SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } StateSpace_PWORK ; void *
Scope_PWORK [ 3 ] ; void * Scope1_PWORK [ 4 ] ; void * Scope2_PWORK ; void *
Scope6_PWORK [ 4 ] ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_h ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_g ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_i ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_m ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_b ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_a ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_mw ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_mz ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_ba ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_e ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_f ; void * Scope10_PWORK ; void * Scope11_PWORK ; void *
Scope12_PWORK ; void * Scope13_PWORK ; void * Scope14_PWORK ; void *
Scope15_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_gg ; void * Scope16_PWORK ; void * Scope3_PWORK [ 4 ] ;
void * Scope4_PWORK ; void * Scope5_PWORK ; void * Scope7_PWORK ; void *
Scope8_PWORK ; void * Scope9_PWORK ; void * SFunction_PWORK ; void *
SFunction_PWORK_n ; void * SFunction_PWORK_o ; void * SFunction_PWORK_ni ;
struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_n ; void *
Scope1_PWORK_j ; void * Scope2_PWORK_p ; void * Scope3_PWORK_j ; struct {
void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_ny ; void *
SFunction_PWORK_m ; void * SFunction_PWORK_m1 ; struct { void * TUbufferPtrs
[ 2 ] ; } TransportDelay_PWORK_bu ; int32_T systemEnable ; int32_T
systemEnable_l ; int32_T systemEnable_g ; int32_T systemEnable_ld ; int32_T
systemEnable_c ; int32_T systemEnable_a ; int32_T
interruptgenerator_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_f ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_k ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_e ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_c ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_fm ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_p ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_b ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_g ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_kx ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_j ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_i ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_gi ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_m ; int32_T IMMDpwm_sysIdxToRun ;
int32_T IMMDcontrol_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_fa ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_d ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_kx3 ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_dy ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_cn ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_gk ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_n ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_d1 ; uint32_T m_bpIndex ; int_T
StateSpace_IWORK [ 11 ] ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK ; struct
{ int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_p ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_l ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_m ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_c ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_k ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_ml ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_i ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_is ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_n ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_o ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_p5 ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_cf ;
int_T SFunction_IWORK ; int_T SFunction_IWORK_k ; int_T SFunction_IWORK_m ;
int_T SFunction_IWORK_l ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_a ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_ih ; int_T SFunction_IWORK_d ; int_T
SFunction_IWORK_b ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_cs ; uint8_T
Integ4_SYSTEM_ENABLE ; uint8_T Integ4_SYSTEM_ENABLE_j ; uint8_T
Integ4_SYSTEM_ENABLE_b ; uint8_T Integ4_SYSTEM_ENABLE_d ; uint8_T
Integ4_SYSTEM_ENABLE_j2 ; uint8_T Integ4_SYSTEM_ENABLE_g ; char_T
pad_Integ4_SYSTEM_ENABLE_g [ 6 ] ; DW_TrueRMS_pwm_analysis_T TrueRMS_hu ;
DW_RMS_pwm_analysis_T RMS_js ; DW_TrueRMS_pwm_analysis_T TrueRMS_ff ;
DW_RMS_pwm_analysis_T RMS_p ; DW_TrueRMS_pwm_analysis_T TrueRMS_p ;
DW_RMS_pwm_analysis_T RMS_j ; DW_TrueRMS_pwm_analysis_T TrueRMS_a ;
DW_RMS_pwm_analysis_T RMS_d ; DW_TrueRMS_pwm_analysis_T TrueRMS_j ;
DW_RMS_pwm_analysis_T RMS_o ; DW_TrueRMS_pwm_analysis_T TrueRMS_k ;
DW_RMS_pwm_analysis_T RMS_f ; DW_TrueRMS_pwm_analysis_T TrueRMS_i ;
DW_RMS_pwm_analysis_T RMS_lk ; DW_TrueRMS_pwm_analysis_T TrueRMS_f ;
DW_RMS_pwm_analysis_T RMS_g ; DW_TrueRMS_pwm_analysis_T TrueRMS_h ;
DW_RMS_pwm_analysis_T RMS_l ; DW_TrueRMS_pwm_analysis_T TrueRMS ;
DW_RMS_pwm_analysis_T RMS ; } DW_pwm_analysis_T ; typedef struct { real_T
integrator_CSTATE ; real_T integrator_CSTATE_e ; real_T integrator_CSTATE_g ;
real_T integrator_CSTATE_k ; real_T integrator_CSTATE_b ; real_T
integrator_CSTATE_a ; real_T integrator_CSTATE_i ; real_T integrator_CSTATE_d
; real_T integrator_CSTATE_p ; real_T integrator_CSTATE_f ; real_T
integrator_CSTATE_o ; real_T integrator_CSTATE_m ; real_T
integrator_CSTATE_av ; real_T integrator_CSTATE_fs ; real_T
integrator_CSTATE_m2 ; real_T integrator_CSTATE_kg ; X_TrueRMS_pwm_analysis_T
TrueRMS_hu ; X_RMS_pwm_analysis_T RMS_js ; X_TrueRMS_pwm_analysis_T
TrueRMS_ff ; X_RMS_pwm_analysis_T RMS_p ; X_TrueRMS_pwm_analysis_T TrueRMS_p
; X_RMS_pwm_analysis_T RMS_j ; X_TrueRMS_pwm_analysis_T TrueRMS_a ;
X_RMS_pwm_analysis_T RMS_d ; X_TrueRMS_pwm_analysis_T TrueRMS_j ;
X_RMS_pwm_analysis_T RMS_o ; X_TrueRMS_pwm_analysis_T TrueRMS_k ;
X_RMS_pwm_analysis_T RMS_f ; X_TrueRMS_pwm_analysis_T TrueRMS_i ;
X_RMS_pwm_analysis_T RMS_lk ; X_TrueRMS_pwm_analysis_T TrueRMS_f ;
X_RMS_pwm_analysis_T RMS_g ; X_TrueRMS_pwm_analysis_T TrueRMS_h ;
X_RMS_pwm_analysis_T RMS_l ; X_TrueRMS_pwm_analysis_T TrueRMS ;
X_RMS_pwm_analysis_T RMS ; } X_pwm_analysis_T ; typedef struct { real_T
integrator_CSTATE ; real_T integrator_CSTATE_e ; real_T integrator_CSTATE_g ;
real_T integrator_CSTATE_k ; real_T integrator_CSTATE_b ; real_T
integrator_CSTATE_a ; real_T integrator_CSTATE_i ; real_T integrator_CSTATE_d
; real_T integrator_CSTATE_p ; real_T integrator_CSTATE_f ; real_T
integrator_CSTATE_o ; real_T integrator_CSTATE_m ; real_T
integrator_CSTATE_av ; real_T integrator_CSTATE_fs ; real_T
integrator_CSTATE_m2 ; real_T integrator_CSTATE_kg ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_hu ; XDot_RMS_pwm_analysis_T RMS_js ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_ff ; XDot_RMS_pwm_analysis_T RMS_p ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_p ; XDot_RMS_pwm_analysis_T RMS_j ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_a ; XDot_RMS_pwm_analysis_T RMS_d ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_j ; XDot_RMS_pwm_analysis_T RMS_o ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_k ; XDot_RMS_pwm_analysis_T RMS_f ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_i ; XDot_RMS_pwm_analysis_T RMS_lk ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_f ; XDot_RMS_pwm_analysis_T RMS_g ;
XDot_TrueRMS_pwm_analysis_T TrueRMS_h ; XDot_RMS_pwm_analysis_T RMS_l ;
XDot_TrueRMS_pwm_analysis_T TrueRMS ; XDot_RMS_pwm_analysis_T RMS ; }
XDot_pwm_analysis_T ; typedef struct { boolean_T integrator_CSTATE ;
boolean_T integrator_CSTATE_e ; boolean_T integrator_CSTATE_g ; boolean_T
integrator_CSTATE_k ; boolean_T integrator_CSTATE_b ; boolean_T
integrator_CSTATE_a ; boolean_T integrator_CSTATE_i ; boolean_T
integrator_CSTATE_d ; boolean_T integrator_CSTATE_p ; boolean_T
integrator_CSTATE_f ; boolean_T integrator_CSTATE_o ; boolean_T
integrator_CSTATE_m ; boolean_T integrator_CSTATE_av ; boolean_T
integrator_CSTATE_fs ; boolean_T integrator_CSTATE_m2 ; boolean_T
integrator_CSTATE_kg ; XDis_TrueRMS_pwm_analysis_T TrueRMS_hu ;
XDis_RMS_pwm_analysis_T RMS_js ; XDis_TrueRMS_pwm_analysis_T TrueRMS_ff ;
XDis_RMS_pwm_analysis_T RMS_p ; XDis_TrueRMS_pwm_analysis_T TrueRMS_p ;
XDis_RMS_pwm_analysis_T RMS_j ; XDis_TrueRMS_pwm_analysis_T TrueRMS_a ;
XDis_RMS_pwm_analysis_T RMS_d ; XDis_TrueRMS_pwm_analysis_T TrueRMS_j ;
XDis_RMS_pwm_analysis_T RMS_o ; XDis_TrueRMS_pwm_analysis_T TrueRMS_k ;
XDis_RMS_pwm_analysis_T RMS_f ; XDis_TrueRMS_pwm_analysis_T TrueRMS_i ;
XDis_RMS_pwm_analysis_T RMS_lk ; XDis_TrueRMS_pwm_analysis_T TrueRMS_f ;
XDis_RMS_pwm_analysis_T RMS_g ; XDis_TrueRMS_pwm_analysis_T TrueRMS_h ;
XDis_RMS_pwm_analysis_T RMS_l ; XDis_TrueRMS_pwm_analysis_T TrueRMS ;
XDis_RMS_pwm_analysis_T RMS ; } XDis_pwm_analysis_T ; struct
P_RMS_pwm_analysis_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T
P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ;
} ; struct P_TrueRMS_pwm_analysis_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ;
real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; } ; struct
P_pwm_analysis_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T
P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ;
real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T
P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 [ 2 ] ; real_T P_30 [ 25 ] ;
real_T P_31 [ 2 ] ; real_T P_32 [ 35 ] ; real_T P_33 [ 2 ] ; real_T P_34 [ 80
] ; real_T P_35 [ 2 ] ; real_T P_36 [ 112 ] ; real_T P_37 [ 2 ] ; real_T P_38
[ 5 ] ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ; real_T P_43 ;
real_T P_44 ; real_T P_45 ; real_T P_46 [ 3 ] ; real_T P_47 [ 3 ] ; real_T
P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T P_52 ; real_T P_53 ;
real_T P_54 ; real_T P_55 ; real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T
P_59 ; real_T P_60 ; real_T P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ;
real_T P_65 ; real_T P_66 ; real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T
P_70 ; real_T P_71 ; real_T P_72 ; real_T P_73 ; real_T P_74 ; real_T P_75 ;
real_T P_76 ; real_T P_77 ; real_T P_78 ; real_T P_79 ; real_T P_80 ; real_T
P_81 ; real_T P_82 ; real_T P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ;
real_T P_87 ; real_T P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T
P_92 ; real_T P_93 ; real_T P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ;
real_T P_98 ; real_T P_99 ; real_T P_100 ; real_T P_101 ; real_T P_102 ;
real_T P_103 ; real_T P_104 ; real_T P_105 ; real_T P_106 ; real_T P_107 ;
real_T P_108 ; real_T P_109 ; real_T P_110 ; real_T P_111 ; real_T P_112 ;
real_T P_113 ; real_T P_114 ; real_T P_115 ; real_T P_116 ; real_T P_117 ;
real_T P_118 ; real_T P_119 ; real_T P_120 ; real_T P_121 ; real_T P_122 ;
real_T P_123 ; real_T P_124 ; real_T P_125 ; real_T P_126 ; real_T P_127 ;
real_T P_128 ; real_T P_129 ; real_T P_130 ; real_T P_131 ; real_T P_132 ;
real_T P_133 ; real_T P_134 ; real_T P_135 ; real_T P_136 ; real_T P_137 ;
real_T P_138 ; real_T P_139 ; real_T P_140 ; real_T P_141 ; real_T P_142 ;
real_T P_143 ; real_T P_144 ; real_T P_145 ; real_T P_146 ; real_T P_147 ;
real_T P_148 ; real_T P_149 ; real_T P_150 ; real_T P_151 ; real_T P_152 ;
real_T P_153 ; real_T P_154 [ 2 ] ; real_T P_155 ; real_T P_156 [ 2 ] ;
real_T P_157 ; real_T P_158 [ 2 ] ; real_T P_159 ; real_T P_160 [ 2 ] ;
real_T P_161 ; real_T P_162 ; real_T P_163 ; real_T P_164 ; real_T P_165 ;
real_T P_166 ; real_T P_167 ; real_T P_168 ; real_T P_169 ; real_T P_170 ;
real_T P_171 ; real_T P_172 ; real_T P_173 ; real_T P_174 ; real_T P_175 [ 2
] ; real_T P_176 ; real_T P_177 [ 2 ] ; real_T P_178 ; real_T P_179 [ 2 ] ;
real_T P_180 ; real_T P_181 [ 2 ] ; real_T P_182 ; real_T P_183 ; real_T
P_184 ; real_T P_185 ; real_T P_186 ; real_T P_187 ; real_T P_188 ; real_T
P_189 ; real_T P_190 ; real_T P_191 ; real_T P_192 ; real_T P_193 ; real_T
P_194 ; real_T P_195 ; real_T P_196 ; real_T P_197 ; real_T P_198 ; real_T
P_199 [ 2 ] ; real_T P_200 ; real_T P_201 [ 2 ] ; real_T P_202 ; real_T P_203
[ 2 ] ; real_T P_204 ; real_T P_205 [ 2 ] ; real_T P_206 ; real_T P_207 ;
real_T P_208 ; real_T P_209 ; real_T P_210 ; real_T P_211 ; real_T P_212 ;
real_T P_213 ; real_T P_214 ; real_T P_215 ; real_T P_216 ; real_T P_217 ;
real_T P_218 ; real_T P_219 ; real_T P_220 [ 2 ] ; real_T P_221 ; real_T
P_222 [ 2 ] ; real_T P_223 ; real_T P_224 [ 2 ] ; real_T P_225 ; real_T P_226
[ 2 ] ; real_T P_227 ; real_T P_228 ; real_T P_229 ; real_T P_230 ; real_T
P_231 ; real_T P_232 ; real_T P_233 ; real_T P_234 ; real_T P_235 ; real_T
P_236 ; real_T P_237 ; real_T P_238 ; real_T P_239 ; real_T P_240 ; real_T
P_241 ; real_T P_242 ; real_T P_243 ; real_T P_244 ; real_T P_245 ; real_T
P_246 ; real_T P_247 ; real_T P_248 ; real_T P_249 ; real_T P_250 ; real_T
P_251 ; real_T P_252 ; real_T P_253 ; real_T P_254 ; real_T P_255 ; real_T
P_256 ; real_T P_257 ; real_T P_258 ; real_T P_259 ; real_T P_260 ; real_T
P_261 ; real_T P_262 ; real_T P_263 ; real_T P_264 ; real_T P_265 ; real_T
P_266 ; real_T P_267 ; real_T P_268 ; real_T P_269 ; real_T P_270 ; real_T
P_271 ; real_T P_272 ; real_T P_273 [ 2 ] ; real_T P_274 ; real_T P_275 [ 2 ]
; real_T P_276 ; real_T P_277 [ 2 ] ; real_T P_278 ; real_T P_279 [ 2 ] ;
real_T P_280 ; real_T P_281 ; real_T P_282 ; real_T P_283 ; real_T P_284 ;
real_T P_285 ; real_T P_286 ; real_T P_287 ; real_T P_288 ; real_T P_289 ;
real_T P_290 ; real_T P_291 ; real_T P_292 ; real_T P_293 ; real_T P_294 [ 2
] ; real_T P_295 ; real_T P_296 [ 2 ] ; real_T P_297 ; real_T P_298 [ 2 ] ;
real_T P_299 ; real_T P_300 [ 2 ] ; real_T P_301 ; real_T P_302 ; real_T
P_303 ; real_T P_304 ; real_T P_305 ; real_T P_306 ; real_T P_307 ; real_T
P_308 ; real_T P_309 ; real_T P_310 ; real_T P_311 ; real_T P_312 ; real_T
P_313 ; real_T P_314 ; real_T P_315 ; real_T P_316 ; real_T P_317 ; real_T
P_318 ; real_T P_319 ; real_T P_320 ; real_T P_321 ; real_T P_322 ; real_T
P_323 ; real_T P_324 ; real_T P_325 ; real_T P_326 ; real_T P_327 ; real_T
P_328 ; real_T P_329 ; real_T P_330 ; real_T P_331 ; real_T P_332 ; real_T
P_333 ; real_T P_334 ; real_T P_335 ; real_T P_336 ; real_T P_337 ; real_T
P_338 ; real_T P_339 ; real_T P_340 ; real_T P_341 ; real_T P_342 ; real_T
P_343 ; real_T P_344 ; real_T P_345 ; real_T P_346 ; real_T P_347 ; real_T
P_348 ; real_T P_349 ; real_T P_350 ; uint32_T P_351 ; uint32_T P_352 ;
uint32_T P_353 ; uint32_T P_354 ; P_TrueRMS_pwm_analysis_T TrueRMS_hu ;
P_RMS_pwm_analysis_T RMS_js ; P_TrueRMS_pwm_analysis_T TrueRMS_ff ;
P_RMS_pwm_analysis_T RMS_p ; P_TrueRMS_pwm_analysis_T TrueRMS_p ;
P_RMS_pwm_analysis_T RMS_j ; P_TrueRMS_pwm_analysis_T TrueRMS_a ;
P_RMS_pwm_analysis_T RMS_d ; P_TrueRMS_pwm_analysis_T TrueRMS_j ;
P_RMS_pwm_analysis_T RMS_o ; P_TrueRMS_pwm_analysis_T TrueRMS_k ;
P_RMS_pwm_analysis_T RMS_f ; P_TrueRMS_pwm_analysis_T TrueRMS_i ;
P_RMS_pwm_analysis_T RMS_lk ; P_TrueRMS_pwm_analysis_T TrueRMS_f ;
P_RMS_pwm_analysis_T RMS_g ; P_TrueRMS_pwm_analysis_T TrueRMS_h ;
P_RMS_pwm_analysis_T RMS_l ; P_TrueRMS_pwm_analysis_T TrueRMS ;
P_RMS_pwm_analysis_T RMS ; } ; extern P_pwm_analysis_T
pwm_analysis_rtDefaultP ;
#endif
