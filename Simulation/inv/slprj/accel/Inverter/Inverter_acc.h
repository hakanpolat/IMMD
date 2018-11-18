#include "__cf_Inverter.h"
#ifndef RTW_HEADER_Inverter_acc_h_
#define RTW_HEADER_Inverter_acc_h_
#include <stddef.h>
#include <float.h>
#ifndef Inverter_acc_COMMON_INCLUDES_
#define Inverter_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "Inverter_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
typedef struct { real_T B_8_0_0 ; real_T B_8_3_0 ; real_T B_8_5_0 ; real_T
B_8_7_0 ; real_T B_8_8_0 ; real_T B_8_11_0 ; real_T B_8_13_0 ; real_T
B_8_15_0 ; real_T B_8_17_0 ; real_T B_8_19_0 ; real_T B_8_21_0 ; real_T
B_8_22_0 ; real_T B_8_23_0 ; real_T B_8_25_0 ; real_T B_8_27_0 ; real_T
B_8_31_0 ; real_T B_8_32_0 ; real_T B_8_33_0 ; real_T B_8_36_0 ; real_T
B_8_37_0 ; real_T B_8_38_0 ; real_T B_8_41_0 ; real_T B_8_42_0 ; real_T
B_8_45_0 ; real_T B_8_46_0 [ 4 ] ; real_T B_8_47_0 ; real_T B_8_49_0 ; real_T
B_8_52_0 ; real_T B_8_53_0 ; real_T B_8_56_0 ; real_T B_8_57_0 ; real_T
B_8_60_0 ; real_T B_8_61_0 [ 4 ] ; real_T B_8_62_0 ; real_T B_8_64_0 ; real_T
B_8_65_0 ; real_T B_8_66_0 ; real_T B_8_69_0 ; real_T B_8_70_0 ; real_T
B_8_73_0 ; real_T B_8_74_0 ; real_T B_8_77_0 ; real_T B_8_78_0 [ 4 ] ; real_T
B_8_79_0 ; real_T B_8_81_0 ; real_T B_8_84_0 ; real_T B_8_85_0 ; real_T
B_8_88_0 ; real_T B_8_89_0 ; real_T B_8_92_0 ; real_T B_8_93_0 [ 4 ] ; real_T
B_8_94_0 ; real_T B_8_96_0 ; real_T B_8_97_0 ; real_T B_8_98_0 ; real_T
B_8_101_0 ; real_T B_8_102_0 ; real_T B_8_105_0 ; real_T B_8_106_0 ; real_T
B_8_109_0 ; real_T B_8_110_0 [ 4 ] ; real_T B_8_111_0 ; real_T B_8_113_0 ;
real_T B_8_116_0 ; real_T B_8_117_0 ; real_T B_8_120_0 ; real_T B_8_121_0 ;
real_T B_8_124_0 ; real_T B_8_125_0 [ 4 ] ; real_T B_8_126_0 [ 85 ] ; real_T
B_8_127_0 [ 24 ] ; real_T B_8_128_0 ; real_T B_8_145_0 ; real_T B_8_147_0 ; }
B_Inverter_T ; typedef struct { real_T DelayInput2_DSTATE ; real_T
INPUT_1_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_c ; real_T
INPUT_2_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_d ; real_T
INPUT_3_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_l ; real_T
INPUT_4_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_n ; real_T
INPUT_5_1_1_discrete [ 2 ] ; real_T DelayInput2_DSTATE_p ; real_T
INPUT_6_1_1_discrete [ 2 ] ; real_T STATE_1_DiscStates [ 79 ] ; real_T
Memory_PreviousInput ; real_T Memory_PreviousInput_p ; real_T Mean_AccVal ;
struct { real_T modelTStart ; } TransportDelay_RWORK ; struct { real_T
modelTStart ; } TransportDelay_RWORK_d ; struct { void * TUbufferPtrs [ 2 ] ;
} TransportDelay_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_b ; void * STATE_1_Simulator ; void *
STATE_1_SimulationData ; void * STATE_1_DiagnosticManager ; void *
STATE_1_VariableLogger ; void * STATE_1_ZeroCrossingLogger ; void *
STATE_1_SampleTimeIdx ; void * OUTPUT_1_0_Simulator ; void *
OUTPUT_1_0_SimulationData ; void * OUTPUT_1_0_DiagnosticManager ; void *
OUTPUT_1_0_VariableLogger ; void * OUTPUT_1_0_ZeroCrossingLogger ; void *
OUTPUT_1_0_SampleTimeIdx ; void * Scope2_PWORK [ 2 ] ; void *
ToWorkspace_PWORK ; void * Scope_PWORK [ 3 ] ; void * Scope1_PWORK [ 3 ] ;
void * Scope12_PWORK [ 4 ] ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_i ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_ib ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_n ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_np ; int32_T
TmpAtomicSubsysAtSwitch2Inport3_sysIdxToRun_a ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_g ; uint32_T m_bpIndex ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_n ; int_T STATE_1_Modes [ 6 ] ; boolean_T Compare_Mode ;
boolean_T Compare_Mode_g ; boolean_T Compare_Mode_p ; boolean_T
Compare_Mode_j ; boolean_T Compare_Mode_h ; boolean_T Compare_Mode_i ;
boolean_T STATE_1_CallSimulatorOutput ; boolean_T
OUTPUT_1_0_CallSimulatorOutput ; char_T pad_OUTPUT_1_0_CallSimulatorOutput [
4 ] ; } DW_Inverter_T ; typedef struct { real_T integrator_CSTATE ; real_T
integrator_CSTATE_f ; } X_Inverter_T ; typedef struct { real_T
integrator_CSTATE ; real_T integrator_CSTATE_f ; } XDot_Inverter_T ; typedef
struct { boolean_T integrator_CSTATE ; boolean_T integrator_CSTATE_f ; }
XDis_Inverter_T ; typedef struct { real_T integrator_CSTATE ; real_T
integrator_CSTATE_f ; } CStateAbsTol_Inverter_T ; typedef struct { real_T
Compare_RelopInput_ZC ; real_T Compare_RelopInput_ZC_e ; real_T
Compare_RelopInput_ZC_p ; real_T Compare_RelopInput_ZC_a ; real_T
Compare_RelopInput_ZC_n ; real_T Compare_RelopInput_ZC_j ; } ZCV_Inverter_T ;
typedef struct { ZCSigState Compare_RelopInput_ZCE ; ZCSigState
Compare_RelopInput_ZCE_f ; ZCSigState Compare_RelopInput_ZCE_k ; ZCSigState
Compare_RelopInput_ZCE_g ; ZCSigState Compare_RelopInput_ZCE_n ; ZCSigState
Compare_RelopInput_ZCE_i ; } PrevZCX_Inverter_T ; typedef struct { const
real_T B_8_34_0 ; const real_T B_8_50_0 ; const real_T B_8_67_0 ; const
real_T B_8_82_0 ; const real_T B_8_99_0 ; const real_T B_8_114_0 ; }
ConstB_Inverter_T ;
#define Inverter_rtC(S) ((ConstB_Inverter_T *) _ssGetConstBlockIO(S))
struct P_Inverter_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T
P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ;
real_T P_21 ; real_T P_22 [ 3 ] ; real_T P_23 [ 3 ] ; real_T P_24 ; real_T
P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ;
real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T
P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ;
real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T
P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T P_52 ;
real_T P_53 ; real_T P_54 ; real_T P_55 ; real_T P_56 ; real_T P_57 ; real_T
P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ; real_T P_62 ; real_T P_63 ;
real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T P_67 ; real_T P_68 ; real_T
P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ; } ; extern P_Inverter_T
Inverter_rtDefaultP ; extern const ConstB_Inverter_T Inverter_rtInvariant ;
#endif
