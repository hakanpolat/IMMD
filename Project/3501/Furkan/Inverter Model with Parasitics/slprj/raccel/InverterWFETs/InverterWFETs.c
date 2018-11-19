#include "__cf_InverterWFETs.h"
#include "rt_logging_mmi.h"
#include "InverterWFETs_capi.h"
#include <math.h>
#include "InverterWFETs.h"
#include "InverterWFETs_private.h"
#include "InverterWFETs_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , & stopRequested ) ; }
rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "8.14 (R2018a) 06-Feb-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\InverterWFETs\\InverterWFETs_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; real_T look1_pbinlxpw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T prevIndex [ ] , uint32_T maxIndex ) { real_T frac
; uint32_T startIndex ; uint32_T iRght ; uint32_T iLeft ; uint32_T found ; if
( u0 <= bp0 [ 0U ] ) { startIndex = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [
1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { startIndex =
prevIndex [ 0U ] ; iLeft = 0U ; iRght = maxIndex ; found = 0U ; while ( found
== 0U ) { if ( u0 < bp0 [ startIndex ] ) { iRght = startIndex - 1U ;
startIndex = ( iRght + iLeft ) >> 1U ; } else if ( u0 < bp0 [ startIndex + 1U
] ) { found = 1U ; } else { iLeft = startIndex + 1U ; startIndex = ( iRght +
iLeft ) >> 1U ; } } frac = ( u0 - bp0 [ startIndex ] ) / ( bp0 [ startIndex +
1U ] - bp0 [ startIndex ] ) ; } else { startIndex = maxIndex - 1U ; frac = (
u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ;
} prevIndex [ 0U ] = startIndex ; return ( table [ startIndex + 1U ] - table
[ startIndex ] ) * frac + table [ startIndex ] ; } void MdlInitialize ( void
) { rtDW . cx3y5wj24t = rtP . Integ4_IC_hyg1orgnjy ; { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . liyidkg1og = rtP .
UnitDelay_InitialCondition_msrh1hb3tx ; rtDW . hq3xers3h0 = rtP .
UnitDelay1_InitialCondition_mjkrfyvx2n ; rtB . b5bpctebld = rtP .
RMS_Y0_bgjt2cqyc0 ; rtDW . f053xx0l23 = rtP . Integ4_IC ; { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . iayqwjxn30 = rtP .
UnitDelay_InitialCondition ; rtDW . g522ownwqo = rtP .
UnitDelay1_InitialCondition ; rtDW . motifvjzhr = rtP . Integ4_IC_pm40rzklkj
; { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnInitializeConditions (
rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW .
ocq00sjeyj = rtP . UnitDelay_InitialCondition_aoguy1temn ; rtDW . edd2kbkzs3
= rtP . UnitDelay1_InitialCondition_a5jgapepa0 ; rtB . g4doefl2of = rtP .
RMS_Y0 ; rtDW . l4lzpabl4t = rtP . Integ4_IC_cmkobyzxoi ; { SimStruct * rts =
ssGetSFunction ( rtS , 5 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . lpfa0xqegk = rtP .
UnitDelay_InitialCondition_fwom33d0us ; rtDW . ppix1t4koq = rtP .
UnitDelay1_InitialCondition_pav0c4wl2x ; rtB . ofcnur01ss = rtP .
RMS_Y0_jasmhly5vt ; rtDW . grpjnlftxq = rtP . Integ4_IC_eia2ftyj1x ; {
SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; sfcnInitializeConditions ( rts
) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . ecmyri45ls
= rtP . UnitDelay_InitialCondition_h222ofuws1 ; rtDW . j5dfwnlbxm = rtP .
UnitDelay1_InitialCondition_mgl10icrr2 ; rtDW . pnojpqs3ns = rtP .
Integ4_IC_id0g55h212 ; { SimStruct * rts = ssGetSFunction ( rtS , 4 ) ;
sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } rtDW . gwyanuw3x0 = rtP . UnitDelay_InitialCondition_pgrk2rptpk
; rtDW . ho5z3w1sbb = rtP . UnitDelay1_InitialCondition_ecwqqjll5r ; rtB .
hfz5bihucl = rtP . RMS_Y0_dzq0lqiuxk ; rtDW . jt0sfxu401 = rtP .
Integ4_IC_n3vsv1fujy ; { SimStruct * rts = ssGetSFunction ( rtS , 8 ) ;
sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } rtDW . bdoob1ijr3 = rtP . UnitDelay_InitialCondition_bqwauueqoj
; rtDW . jlot4ajqhq = rtP . UnitDelay1_InitialCondition_o2zq5zqj25 ; rtB .
bisq51qkxp = rtP . RMS_Y0_jys4w42uyu ; rtDW . lrcapd2g5t = rtP .
Integ4_IC_hlm5pnpjyb ; { SimStruct * rts = ssGetSFunction ( rtS , 6 ) ;
sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } rtDW . jwkyerowmb = rtP . UnitDelay_InitialCondition_mhq5umibzr
; rtDW . lbvma42sos = rtP . UnitDelay1_InitialCondition_csl0lzavbh ; rtDW .
gfeprm5f5a = rtP . Integ4_IC_e3ezkszlmy ; { SimStruct * rts = ssGetSFunction
( rtS , 7 ) ; sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } rtDW . jjebi2i5un = rtP .
UnitDelay_InitialCondition_liy42xpsvk ; rtDW . ebmpnozmec = rtP .
UnitDelay1_InitialCondition_kp4i0cv52p ; rtB . fm33dmmmls = rtP .
RMS_Y0_ka1uowgurp ; } void MdlStart ( void ) { NeslSimulator * tmp ;
boolean_T tmp_p ; NeuDiagnosticManager * diagnosticManager ;
NeModelParameters modelParameters ; real_T tmp_e ; NeuDiagnosticTree *
diagnosticTree ; char * msg ; real_T * parameterBundle_mRealParameters_mX ;
real_T tmp_i [ 4 ] ; int_T j ; NeslSimulationData * simulationData ; real_T
time ; NeModelParameters modelParameters_p ; real_T time_p ;
NeParameterBundle expl_temp ; { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } tmp = nesl_lease_simulator (
"InverterWFETs/Solver Configuration_1" , 0 , 0 ) ; rtDW . bgwsy3m1jh = ( void
* ) tmp ; tmp_p = pointer_is_null ( rtDW . bgwsy3m1jh ) ; if ( tmp_p ) {
InverterWFETs_d83d6795_1_gateway ( ) ; tmp = nesl_lease_simulator (
"InverterWFETs/Solver Configuration_1" , 0 , 0 ) ; rtDW . bgwsy3m1jh = ( void
* ) tmp ; } simulationData = nesl_create_simulation_data ( ) ; rtDW .
j4btagyhoo = ( void * ) simulationData ; diagnosticManager =
rtw_create_diagnostics ( ) ; rtDW . ljvsw4ftil = ( void * ) diagnosticManager
; modelParameters . mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters .
mSolverTolerance = 0.001 ; modelParameters . mVariableStepSolver = true ;
modelParameters . mFixedStepSize = 1.0E-8 ; modelParameters . mStartTime =
0.0 ; modelParameters . mLoadInitialState = false ; modelParameters .
mUseSimState = false ; modelParameters . mLinTrimCompile = false ;
modelParameters . mLoggingMode = SSC_LOGGING_NONE ; modelParameters .
mRTWModifiedTimeStamp = 4.64520489E+8 ; tmp_e = ( - 1.0 ) ; modelParameters .
mSolverTolerance = tmp_e ; tmp_e = 0.0 ; modelParameters . mFixedStepSize =
tmp_e ; tmp_p = true ; modelParameters . mVariableStepSolver = tmp_p ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ljvsw4ftil ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; j = nesl_initialize_simulator ( ( NeslSimulator * ) rtDW . bgwsy3m1jh , &
modelParameters , diagnosticManager ) ; if ( j != 0 ) { tmp_p =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
tmp_i [ 0 ] = rtP . Idc ; tmp_i [ 1 ] = rtP . LoadA ; tmp_i [ 2 ] = rtP .
LoadB ; tmp_i [ 3 ] = rtP . LoadC ; parameterBundle_mRealParameters_mX = &
tmp_i [ 0 ] ; expl_temp . mRealParameters . mN = 4 ; expl_temp .
mRealParameters . mX = parameterBundle_mRealParameters_mX ; expl_temp .
mLogicalParameters . mN = 0 ; expl_temp . mLogicalParameters . mX = NULL ;
expl_temp . mIntegerParameters . mN = 0 ; expl_temp . mIntegerParameters . mX
= NULL ; expl_temp . mIndexParameters . mN = 0 ; expl_temp . mIndexParameters
. mX = NULL ; nesl_simulator_set_rtps ( ( NeslSimulator * ) rtDW . bgwsy3m1jh
, expl_temp ) ; simulationData = ( NeslSimulationData * ) rtDW . j4btagyhoo ;
time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ;
simulationData -> mData -> mTime . mX = & time ; simulationData -> mData ->
mContStates . mN = 0 ; simulationData -> mData -> mContStates . mX = NULL ;
simulationData -> mData -> mDiscStates . mN = 123 ; simulationData -> mData
-> mDiscStates . mX = ( real_T * ) & rtDW . lpi2q22kbk ; simulationData ->
mData -> mModeVector . mN = 36 ; simulationData -> mData -> mModeVector . mX
= ( int32_T * ) & rtDW . laeadqjoyo ; tmp_p = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp_p ; simulationData -> mData -> mIsMajorTimeStep =
true ; tmp_p = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck ==
1U ) ; simulationData -> mData -> mIsSolverAssertCheck = tmp_p ; tmp_p =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp_p ; simulationData -> mData ->
mIsComputingJacobian = false ; simulationData -> mData -> mIsEvaluatingF0 =
false ; tmp_p = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp_p ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ljvsw4ftil ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; j =
ne_simulator_method ( ( NeslSimulator * ) rtDW . bgwsy3m1jh ,
NESL_SIM_INITIALIZEONCE , simulationData , diagnosticManager ) ; if ( j != 0
) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p )
{ msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg
) ; } } tmp = nesl_lease_simulator ( "InverterWFETs/Solver Configuration_1" ,
2 , 0 ) ; rtDW . frpy0o3adk = ( void * ) tmp ; tmp_p = pointer_is_null ( rtDW
. frpy0o3adk ) ; if ( tmp_p ) { InverterWFETs_d83d6795_1_gateway ( ) ; tmp =
nesl_lease_simulator ( "InverterWFETs/Solver Configuration_1" , 2 , 0 ) ;
rtDW . frpy0o3adk = ( void * ) tmp ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . pco3n20tlq = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
d3bgeeko12 = ( void * ) diagnosticManager ; modelParameters_p . mSolverType =
NE_SOLVER_TYPE_DAE ; modelParameters_p . mSolverTolerance = 0.001 ;
modelParameters_p . mVariableStepSolver = true ; modelParameters_p .
mFixedStepSize = 1.0E-8 ; modelParameters_p . mStartTime = 0.0 ;
modelParameters_p . mLoadInitialState = false ; modelParameters_p .
mUseSimState = false ; modelParameters_p . mLinTrimCompile = false ;
modelParameters_p . mLoggingMode = SSC_LOGGING_NONE ; modelParameters_p .
mRTWModifiedTimeStamp = 4.64520489E+8 ; tmp_e = ( - 1.0 ) ; modelParameters_p
. mSolverTolerance = tmp_e ; tmp_e = 0.0 ; modelParameters_p . mFixedStepSize
= tmp_e ; tmp_p = true ; modelParameters_p . mVariableStepSolver = tmp_p ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . d3bgeeko12 ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; j = nesl_initialize_simulator ( ( NeslSimulator * ) rtDW . frpy0o3adk , &
modelParameters_p , diagnosticManager ) ; if ( j != 0 ) { tmp_p =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . pco3n20tlq ; time_p = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_p ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; tmp_p = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp_p ; simulationData -> mData -> mIsMajorTimeStep =
true ; tmp_p = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck ==
1U ) ; simulationData -> mData -> mIsSolverAssertCheck = tmp_p ; tmp_p =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp_p ; simulationData -> mData ->
mIsComputingJacobian = false ; simulationData -> mData -> mIsEvaluatingF0 =
false ; tmp_p = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp_p ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . d3bgeeko12 ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; j =
ne_simulator_method ( ( NeslSimulator * ) rtDW . frpy0o3adk ,
NESL_SIM_INITIALIZEONCE , simulationData , diagnosticManager ) ; if ( j != 0
) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p )
{ msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg
) ; } } rtDW . ecisw5adre = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . jeyupwj05d = rtP .
K1_Value_eper5cnwey ; { SimStruct * rts = ssGetSFunction ( rtS , 2 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
rtDW . dr430txhud = 0 ; rtDW . kurl1epm13 = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . f5ta3mfjzs = rtP .
K1_Value ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnStart ( rts )
; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtB . ihgmb1kpmh =
rtP . K1_Value_gmfkjcymcu ; { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
rtDW . gov5rlozbf = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtB . aiu4fdl0gc = rtP . K1_Value_fiqnvvlbtv ; { SimStruct * rts =
ssGetSFunction ( rtS , 5 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } rtDW . bfjoxab0mk = 0 ; rtDW . gob230sujf = false
; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . eua13yagug = rtP
. K1_Value_d02xdalxac ; { SimStruct * rts = ssGetSFunction ( rtS , 3 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
rtB . h0sb2533vd = rtP . K1_Value_fri1a0ongp ; { SimStruct * rts =
ssGetSFunction ( rtS , 4 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } rtDW . gq2nzjnf0w = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . jnh32a12mk = rtP .
K1_Value_chvilvz2jj ; { SimStruct * rts = ssGetSFunction ( rtS , 8 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
rtDW . n3ddpqpuun = 0 ; rtDW . eibahmjyhj = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . o1kjfgygqq = rtP .
K1_Value_bvxfbao2pd ; { SimStruct * rts = ssGetSFunction ( rtS , 6 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
rtB . fxp4n1nqzj = rtP . K1_Value_fpmnopebgd ; { SimStruct * rts =
ssGetSFunction ( rtS , 7 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Capacitor A Current"
) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "Capacitor A Current" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "InverterWFETs/RMS5" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"Capacitor A Current" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. fwmkchozeq . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"dc66cac1-7b5b-4df5-b6ee-890096b78e03" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . fwmkchozeq . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . fwmkchozeq . AQHandles , "1e-08" ,
1.0E-8 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . fwmkchozeq .
AQHandles , ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . fwmkchozeq . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . fwmkchozeq . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } { void *
treeVector = ( NULL ) ; void * accessor = ( NULL ) ; const void *
signalDescriptor = ( NULL ) ; void * loggingInterval = ( NULL ) ; char *
datasetName = "tmp_raccel_logsout" ; if ( slioCatalogue && rtwIsLoggingToFile
( slioCatalogue ) ) { treeVector = rtwGetTreeVector ( ) ; { int_T
sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode ( 0 , "Capacitor A Current" ,
"zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" , "" , "1e-08" ,
1.0E-8 , ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor =
rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "Capacitor A Current" ,
"" , rt_dataMapInfo . mmi . InstanceMap . fullPath , "InverterWFETs/RMS5" , 1
, 0 , slioCatalogue , ( NULL ) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue
( ) ) { sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap .
fullPath , "InverterWFETs/RMS5" , 1 , "Capacitor A Current" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . fwmkchozeq . SlioLTF = accessor ;
} } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "TopVolt" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "TopVolt" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "InverterWFETs/Gate Driver" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "TopVolt" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . nvuyb1yzrc . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "90d94e91-0cd3-4957-abd3-6be0930c3ecb" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "1" ) ; if (
rtDW . nvuyb1yzrc . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW .
nvuyb1yzrc . AQHandles , "1e-08" , 1.0E-8 , ssGetTFinal ( rtS ) ) ;
sdiSetRunStartTime ( rtDW . nvuyb1yzrc . AQHandles , ssGetTaskTime ( rtS , 2
) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . nvuyb1yzrc . AQHandles , 1
, 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . nvuyb1yzrc . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "TopVolt" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" ,
"1" , "1e-08" , 1.0E-8 , ssGetTFinal ( rtS ) , treeVector ) ; }
signalDescriptor = rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 ,
"TopVolt" , "" , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"InverterWFETs/Gate Driver" , 1 , 0 , slioCatalogue , ( NULL ) , 0 , ( NULL )
, 0 ) ; if ( ! rt_slioCatalogue ( ) ) { sdiSlioIsLoggingSignal (
rt_dataMapInfo . mmi . InstanceMap . fullPath , "InverterWFETs/Gate Driver" ,
1 , "TopVolt" ) ; } if ( rtwLoggingOverride ( signalDescriptor ,
slioCatalogue ) ) { if ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) {
loggingInterval = rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo ->
rtwLogInfo ) ; } else { loggingInterval = sdiGetLoggingIntervals (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; datasetName = "" ; }
accessor = rtwGetAccessor ( signalDescriptor , loggingInterval ) ;
rtwAddR2Client ( accessor , signalDescriptor , slioCatalogue , datasetName ,
1 ) ; rtDW . nvuyb1yzrc . SlioLTF = accessor ; } } } } { void * slioCatalogue
= rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) )
: sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if
( ! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "TopCurr" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "TopCurr" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "InverterWFETs/Gate Driver" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "TopCurr" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 1 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . k4mh4yu0ov . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "7271724d-cc1d-4d6b-add3-da3b6b406d50" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "1" ) ; if (
rtDW . k4mh4yu0ov . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW .
k4mh4yu0ov . AQHandles , "1e-08" , 1.0E-8 , ssGetTFinal ( rtS ) ) ;
sdiSetRunStartTime ( rtDW . k4mh4yu0ov . AQHandles , ssGetTaskTime ( rtS , 2
) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . k4mh4yu0ov . AQHandles , 1
, 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . k4mh4yu0ov . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "TopCurr" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" ,
"1" , "1e-08" , 1.0E-8 , ssGetTFinal ( rtS ) , treeVector ) ; }
signalDescriptor = rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 ,
"TopCurr" , "" , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"InverterWFETs/Gate Driver" , 2 , 0 , slioCatalogue , ( NULL ) , 0 , ( NULL )
, 0 ) ; if ( ! rt_slioCatalogue ( ) ) { sdiSlioIsLoggingSignal (
rt_dataMapInfo . mmi . InstanceMap . fullPath , "InverterWFETs/Gate Driver" ,
2 , "TopCurr" ) ; } if ( rtwLoggingOverride ( signalDescriptor ,
slioCatalogue ) ) { if ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) {
loggingInterval = rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo ->
rtwLogInfo ) ; } else { loggingInterval = sdiGetLoggingIntervals (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; datasetName = "" ; }
accessor = rtwGetAccessor ( signalDescriptor , loggingInterval ) ;
rtwAddR2Client ( accessor , signalDescriptor , slioCatalogue , datasetName ,
1 ) ; rtDW . k4mh4yu0ov . SlioLTF = accessor ; } } } } MdlInitialize ( ) ; }
void MdlOutputs ( int_T tid ) { NeslSimulationData * simulationData ; real_T
time ; boolean_T tmp ; real_T tmp_p [ 24 ] ; int_T tmp_e [ 7 ] ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; int32_T tmp_i ; char * msg ; real_T time_p ; real_T tmp_m [ 183 ] ; int_T
tmp_g [ 8 ] ; real_T ojvbmgui5a ; srClearBC ( rtDW . bcuawr35dl ) ; srClearBC
( rtDW . pkc5pvpbud ) ; srClearBC ( rtDW . ksdc555p1f ) ; srClearBC ( rtDW .
l4lq0poyio ) ; srClearBC ( rtDW . mvd0gisct2 ) ; srClearBC ( rtDW .
c3pebqdhtw ) ; rtB . lcge5t1gjo = muDoubleScalarSin ( rtP . ffund * 2.0 *
3.1415926535897931 * ssGetTaskTime ( rtS , 0 ) + rtP .
SineWaveFunction1_Phase ) * rtP . ModulationIndex + rtP .
SineWaveFunction1_Bias ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
b1sdosls3i = rtP . Constant3_Value ; rtB . dvb12qxvf2 = rtP . Constant4_Value
; } ojvbmgui5a = look1_pbinlxpw ( muDoubleScalarRem ( ssGetT ( rtS ) + rtB .
b1sdosls3i , rtB . dvb12qxvf2 ) * rtP . uib1_Gain , rtP .
uDLookupTable_bp01Data , rtP . uDLookupTable_tableData , & rtDW . fto133wy4o
, 2U ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . czvszvgx5h = rtP .
Constant2_Value ; } rtB . hpc0dqwvnx = ojvbmgui5a - rtB . czvszvgx5h ; rtB .
eovubh0rxu = rtB . lcge5t1gjo - rtB . hpc0dqwvnx ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . iw3cho4vxe = ( rtB .
eovubh0rxu > rtP . Constant_Value_dlflefihkr ) ; } if ( rtDW . iw3cho4vxe ) {
rtB . pnsni0ml1o = rtP . Constant_Value ; } else { rtB . pnsni0ml1o = rtP .
Constant1_Value ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . imlhhcedkr
[ 0 ] = rtB . pnsni0ml1o ; rtB . imlhhcedkr [ 1 ] = 0.0 ; rtB . imlhhcedkr [
2 ] = 0.0 ; rtDW . hdz0nups2p [ 0 ] = ! ( rtB . imlhhcedkr [ 0 ] == rtDW .
hdz0nups2p [ 1 ] ) ; rtDW . hdz0nups2p [ 1 ] = rtB . imlhhcedkr [ 0 ] ; rtB .
imlhhcedkr [ 0 ] = rtDW . hdz0nups2p [ 1 ] ; rtB . imlhhcedkr [ 3 ] = rtDW .
hdz0nups2p [ 0 ] ; } rtB . kulfykvvqa = muDoubleScalarSin ( rtP . ffund * 2.0
* 3.1415926535897931 * ssGetTaskTime ( rtS , 0 ) + rtP .
SineWaveFunction_Phase ) * rtP . ModulationIndex + rtP .
SineWaveFunction_Bias ; rtB . bgybglbgav = rtB . kulfykvvqa - rtB .
hpc0dqwvnx ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . kjsrm0r1qu = ( rtB . bgybglbgav > rtP .
Constant_Value_l3unqqh2kq ) ; } if ( rtDW . kjsrm0r1qu ) { rtB . nukezu5xk3 =
rtP . Constant_Value ; } else { rtB . nukezu5xk3 = rtP . Constant1_Value ; }
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . lqtqsmmd1w = ( rtB . bgybglbgav <
rtP . Constant_Value_dxzjx5wwcr ) ; } if ( rtDW . lqtqsmmd1w ) { rtB .
cmlcurmh4c = rtP . Constant_Value ; } else { rtB . cmlcurmh4c = rtP .
Constant1_Value ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . p51dkbkwid
[ 0 ] = rtB . nukezu5xk3 ; rtB . p51dkbkwid [ 1 ] = 0.0 ; rtB . p51dkbkwid [
2 ] = 0.0 ; rtDW . bqgmk2ugv4 [ 0 ] = ! ( rtB . p51dkbkwid [ 0 ] == rtDW .
bqgmk2ugv4 [ 1 ] ) ; rtDW . bqgmk2ugv4 [ 1 ] = rtB . p51dkbkwid [ 0 ] ; rtB .
p51dkbkwid [ 0 ] = rtDW . bqgmk2ugv4 [ 1 ] ; rtB . p51dkbkwid [ 3 ] = rtDW .
bqgmk2ugv4 [ 0 ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . m5i40ct5vz = ( rtB . eovubh0rxu < rtP .
Constant_Value_a4nouejct5 ) ; } if ( rtDW . m5i40ct5vz ) { rtB . ce2llznftg =
rtP . Constant_Value ; } else { rtB . ce2llznftg = rtP . Constant1_Value ; }
} if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . lc0gh4vn0y [ 0 ] = rtB .
cmlcurmh4c ; rtB . lc0gh4vn0y [ 1 ] = 0.0 ; rtB . lc0gh4vn0y [ 2 ] = 0.0 ;
rtDW . auveueqvz5 [ 0 ] = ! ( rtB . lc0gh4vn0y [ 0 ] == rtDW . auveueqvz5 [ 1
] ) ; rtDW . auveueqvz5 [ 1 ] = rtB . lc0gh4vn0y [ 0 ] ; rtB . lc0gh4vn0y [ 0
] = rtDW . auveueqvz5 [ 1 ] ; rtB . lc0gh4vn0y [ 3 ] = rtDW . auveueqvz5 [ 0
] ; rtB . ajqsccxh4n [ 0 ] = rtB . ce2llznftg ; rtB . ajqsccxh4n [ 1 ] = 0.0
; rtB . ajqsccxh4n [ 2 ] = 0.0 ; rtDW . kyjsjkxfrc [ 0 ] = ! ( rtB .
ajqsccxh4n [ 0 ] == rtDW . kyjsjkxfrc [ 1 ] ) ; rtDW . kyjsjkxfrc [ 1 ] = rtB
. ajqsccxh4n [ 0 ] ; rtB . ajqsccxh4n [ 0 ] = rtDW . kyjsjkxfrc [ 1 ] ; rtB .
ajqsccxh4n [ 3 ] = rtDW . kyjsjkxfrc [ 0 ] ; } rtB . ohra4d5w4r =
muDoubleScalarSin ( rtP . ffund * 2.0 * 3.1415926535897931 * ssGetTaskTime (
rtS , 0 ) + rtP . SineWaveFunction2_Phase ) * rtP . ModulationIndex + rtP .
SineWaveFunction2_Bias ; rtB . b1ptcc5egb = rtB . ohra4d5w4r - rtB .
hpc0dqwvnx ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . hm42zo1kvb = ( rtB . b1ptcc5egb > rtP .
Constant_Value_cpsdmvnz4x ) ; } if ( rtDW . hm42zo1kvb ) { rtB . oilte4fptr =
rtP . Constant_Value ; } else { rtB . oilte4fptr = rtP . Constant1_Value ; }
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . kuylzd02lp = ( rtB . b1ptcc5egb <
rtP . Constant_Value_ln0n1kk0z4 ) ; } if ( rtDW . kuylzd02lp ) { rtB .
ex0skiip24 = rtP . Constant_Value ; } else { rtB . ex0skiip24 = rtP .
Constant1_Value ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . idj5hyxoz3
[ 0 ] = rtB . oilte4fptr ; rtB . idj5hyxoz3 [ 1 ] = 0.0 ; rtB . idj5hyxoz3 [
2 ] = 0.0 ; rtDW . jxp1qqkjt1 [ 0 ] = ! ( rtB . idj5hyxoz3 [ 0 ] == rtDW .
jxp1qqkjt1 [ 1 ] ) ; rtDW . jxp1qqkjt1 [ 1 ] = rtB . idj5hyxoz3 [ 0 ] ; rtB .
idj5hyxoz3 [ 0 ] = rtDW . jxp1qqkjt1 [ 1 ] ; rtB . idj5hyxoz3 [ 3 ] = rtDW .
jxp1qqkjt1 [ 0 ] ; rtB . frvw5tfr5q [ 0 ] = rtB . ex0skiip24 ; rtB .
frvw5tfr5q [ 1 ] = 0.0 ; rtB . frvw5tfr5q [ 2 ] = 0.0 ; rtDW . ibcfck1opc [ 0
] = ! ( rtB . frvw5tfr5q [ 0 ] == rtDW . ibcfck1opc [ 1 ] ) ; rtDW .
ibcfck1opc [ 1 ] = rtB . frvw5tfr5q [ 0 ] ; rtB . frvw5tfr5q [ 0 ] = rtDW .
ibcfck1opc [ 1 ] ; rtB . frvw5tfr5q [ 3 ] = rtDW . ibcfck1opc [ 0 ] ;
simulationData = ( NeslSimulationData * ) rtDW . j4btagyhoo ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 123 ; simulationData -> mData -> mDiscStates . mX = (
real_T * ) & rtDW . lpi2q22kbk ; simulationData -> mData -> mModeVector . mN
= 36 ; simulationData -> mData -> mModeVector . mX = ( int32_T * ) & rtDW .
laeadqjoyo ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS )
-> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = true ; tmp = ( ssGetMdlInfoPtr
( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; simulationData -> mData ->
mIsEvaluatingF0 = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . imlhhcedkr [ 0 ] ; tmp_p [ 1 ] = rtB . imlhhcedkr [ 1 ] ;
tmp_p [ 2 ] = rtB . imlhhcedkr [ 2 ] ; tmp_p [ 3 ] = rtB . imlhhcedkr [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . p51dkbkwid [ 0 ] ; tmp_p [ 5 ] = rtB .
p51dkbkwid [ 1 ] ; tmp_p [ 6 ] = rtB . p51dkbkwid [ 2 ] ; tmp_p [ 7 ] = rtB .
p51dkbkwid [ 3 ] ; tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . lc0gh4vn0y [ 0 ] ;
tmp_p [ 9 ] = rtB . lc0gh4vn0y [ 1 ] ; tmp_p [ 10 ] = rtB . lc0gh4vn0y [ 2 ]
; tmp_p [ 11 ] = rtB . lc0gh4vn0y [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] =
rtB . ajqsccxh4n [ 0 ] ; tmp_p [ 13 ] = rtB . ajqsccxh4n [ 1 ] ; tmp_p [ 14 ]
= rtB . ajqsccxh4n [ 2 ] ; tmp_p [ 15 ] = rtB . ajqsccxh4n [ 3 ] ; tmp_e [ 4
] = 16 ; tmp_p [ 16 ] = rtB . idj5hyxoz3 [ 0 ] ; tmp_p [ 17 ] = rtB .
idj5hyxoz3 [ 1 ] ; tmp_p [ 18 ] = rtB . idj5hyxoz3 [ 2 ] ; tmp_p [ 19 ] = rtB
. idj5hyxoz3 [ 3 ] ; tmp_e [ 5 ] = 20 ; tmp_p [ 20 ] = rtB . frvw5tfr5q [ 0 ]
; tmp_p [ 21 ] = rtB . frvw5tfr5q [ 1 ] ; tmp_p [ 22 ] = rtB . frvw5tfr5q [ 2
] ; tmp_p [ 23 ] = rtB . frvw5tfr5q [ 3 ] ; tmp_e [ 6 ] = 24 ; simulationData
-> mData -> mInputValues . mN = 24 ; simulationData -> mData -> mInputValues
. mX = & tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 7 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
simulationData -> mData -> mOutputs . mN = 159 ; simulationData -> mData ->
mOutputs . mX = & rtB . h4xihyt1ug [ 0 ] ; simulationData -> mData ->
mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX = NULL ;
tmp = ssIsSampleHit ( rtS , 2 , 0 ) ; simulationData -> mData ->
mIsFundamentalSampleHit = tmp ; simulationData -> mData -> mTolerances . mN =
0 ; simulationData -> mData -> mTolerances . mX = NULL ; simulationData ->
mData -> mCstateHasChanged = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ljvsw4ftil ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . bgwsy3m1jh ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
if ( simulationData -> mData -> mCstateHasChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } simulationData = (
NeslSimulationData * ) rtDW . pco3n20tlq ; time_p = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_p ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep = true
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData -> mData -> mIsComputingJacobian
= false ; simulationData -> mData -> mIsEvaluatingF0 = false ; tmp =
ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp_g [ 0 ] = 0 ; tmp_m [ 0 ] = rtB .
imlhhcedkr [ 0 ] ; tmp_m [ 1 ] = rtB . imlhhcedkr [ 1 ] ; tmp_m [ 2 ] = rtB .
imlhhcedkr [ 2 ] ; tmp_m [ 3 ] = rtB . imlhhcedkr [ 3 ] ; tmp_g [ 1 ] = 4 ;
tmp_m [ 4 ] = rtB . p51dkbkwid [ 0 ] ; tmp_m [ 5 ] = rtB . p51dkbkwid [ 1 ] ;
tmp_m [ 6 ] = rtB . p51dkbkwid [ 2 ] ; tmp_m [ 7 ] = rtB . p51dkbkwid [ 3 ] ;
tmp_g [ 2 ] = 8 ; tmp_m [ 8 ] = rtB . lc0gh4vn0y [ 0 ] ; tmp_m [ 9 ] = rtB .
lc0gh4vn0y [ 1 ] ; tmp_m [ 10 ] = rtB . lc0gh4vn0y [ 2 ] ; tmp_m [ 11 ] = rtB
. lc0gh4vn0y [ 3 ] ; tmp_g [ 3 ] = 12 ; tmp_m [ 12 ] = rtB . ajqsccxh4n [ 0 ]
; tmp_m [ 13 ] = rtB . ajqsccxh4n [ 1 ] ; tmp_m [ 14 ] = rtB . ajqsccxh4n [ 2
] ; tmp_m [ 15 ] = rtB . ajqsccxh4n [ 3 ] ; tmp_g [ 4 ] = 16 ; tmp_m [ 16 ] =
rtB . idj5hyxoz3 [ 0 ] ; tmp_m [ 17 ] = rtB . idj5hyxoz3 [ 1 ] ; tmp_m [ 18 ]
= rtB . idj5hyxoz3 [ 2 ] ; tmp_m [ 19 ] = rtB . idj5hyxoz3 [ 3 ] ; tmp_g [ 5
] = 20 ; tmp_m [ 20 ] = rtB . frvw5tfr5q [ 0 ] ; tmp_m [ 21 ] = rtB .
frvw5tfr5q [ 1 ] ; tmp_m [ 22 ] = rtB . frvw5tfr5q [ 2 ] ; tmp_m [ 23 ] = rtB
. frvw5tfr5q [ 3 ] ; tmp_g [ 6 ] = 24 ; memcpy ( & tmp_m [ 24 ] , & rtB .
h4xihyt1ug [ 0 ] , 159U * sizeof ( real_T ) ) ; tmp_g [ 7 ] = 183 ;
simulationData -> mData -> mInputValues . mN = 183 ; simulationData -> mData
-> mInputValues . mX = & tmp_m [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 8 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_g [ 0 ] ; simulationData -> mData -> mOutputs . mN = 26 ; simulationData
-> mData -> mOutputs . mX = & rtB . iwg44exs5g [ 0 ] ; simulationData ->
mData -> mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX =
NULL ; tmp = ssIsSampleHit ( rtS , 2 , 0 ) ; simulationData -> mData ->
mIsFundamentalSampleHit = tmp ; simulationData -> mData -> mTolerances . mN =
0 ; simulationData -> mData -> mTolerances . mX = NULL ; simulationData ->
mData -> mCstateHasChanged = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . d3bgeeko12 ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . frpy0o3adk ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
if ( simulationData -> mData -> mCstateHasChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . kbdwxc5gyv = (
rtB . iwg44exs5g [ 2 ] + rtB . iwg44exs5g [ 0 ] ) + rtB . iwg44exs5g [ 1 ] ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB . awqcje34vp ) { if ( ! rtDW .
ecisw5adre ) { if ( ssGetTaskTime ( rtS , 2 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . f54g14zkss = 1U
; rtDW . ecisw5adre = true ; } } else { if ( rtDW . ecisw5adre ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . cx3y5wj24t = rtB
. d4yrrkxbew ; rtDW . ecisw5adre = false ; } } } if ( rtDW . ecisw5adre ) {
rtB . k4fqogeply = rtB . kbdwxc5gyv * rtB . kbdwxc5gyv ; if ( rtDW .
f54g14zkss != 0 ) { rtB . d4yrrkxbew = rtDW . cx3y5wj24t ; } else { rtB .
d4yrrkxbew = rtP . Integ4_gainval_cmbswlryt5 * rtB . k4fqogeply + rtDW .
cx3y5wj24t ; } rtB . jeyupwj05d = rtP . K1_Value_eper5cnwey ; { SimStruct *
rts = ssGetSFunction ( rtS , 2 ) ; sfcnOutputs ( rts , 0 ) ; } if (
ssGetTaskTime ( rtS , 2 ) >= rtB . jeyupwj05d ) { rtB . oww2w4mlsz = ( rtB .
d4yrrkxbew - rtB . povy1e3cdf ) * rtP . K2_Value_poc3ahh3o0 + ( rtP .
Gain1_Gain_jvz4pavaqm * rtB . k4fqogeply - rtP . Gain_Gain_gpon2qmr4o * rtDW
. liyidkg1og ) ; } else { rtB . oww2w4mlsz = rtDW . hq3xers3h0 ; } if ( rtB .
oww2w4mlsz > rtP . Saturationtoavoidnegativesqrt_UpperSat ) { ojvbmgui5a =
rtP . Saturationtoavoidnegativesqrt_UpperSat ; } else if ( rtB . oww2w4mlsz <
rtP . Saturationtoavoidnegativesqrt_LowerSat ) { ojvbmgui5a = rtP .
Saturationtoavoidnegativesqrt_LowerSat ; } else { ojvbmgui5a = rtB .
oww2w4mlsz ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . dr430txhud != 0
) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . dr430txhud =
0 ; } rtB . b5bpctebld = muDoubleScalarSqrt ( ojvbmgui5a ) ; srUpdateBC (
rtDW . pkc5pvpbud ) ; } else if ( ojvbmgui5a < 0.0 ) { rtB . b5bpctebld = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( ojvbmgui5a ) ) ; rtDW . dr430txhud =
1 ; } else { rtB . b5bpctebld = muDoubleScalarSqrt ( ojvbmgui5a ) ; } } if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtB . kvdej4nyky ) { if ( ! rtDW .
kurl1epm13 ) { if ( ssGetTaskTime ( rtS , 2 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . letqwzpvfw = 1
; rtDW . g3mio5fr0t = 1U ; rtDW . dhg2x3hhw4 = 1 ; rtDW . kqc5wee2bc = 1U ;
rtDW . kurl1epm13 = true ; } } else { if ( rtDW . kurl1epm13 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . f053xx0l23 = rtB
. kbsdtbfy5k ; rtDW . motifvjzhr = rtB . gjyfuvtq0v ; rtDW . kurl1epm13 =
false ; } } } if ( rtDW . kurl1epm13 ) { if ( rtDW . letqwzpvfw != 0 ) { rtDW
. fadr5pbwq1 = muDoubleScalarSin ( 6.2831853071795862 * rtP . Fourier1_Freq *
ssGetTaskTime ( rtS , 2 ) ) ; rtDW . jetkaz1b2y = muDoubleScalarCos (
6.2831853071795862 * rtP . Fourier1_Freq * ssGetTaskTime ( rtS , 2 ) ) ; rtDW
. letqwzpvfw = 0 ; } rtB . e2o0qyzahq = ( ( ( rtDW . fadr5pbwq1 * rtP .
sinwt_PCos + rtDW . jetkaz1b2y * rtP . sinwt_PSin ) * rtP . sinwt_HCos + (
rtDW . jetkaz1b2y * rtP . sinwt_PCos - rtDW . fadr5pbwq1 * rtP . sinwt_PSin )
* rtP . sinwt_Hsin ) * rtP . sinwt_Amp + rtP . sinwt_Bias ) * rtB .
kbdwxc5gyv ; if ( rtDW . g3mio5fr0t != 0 ) { rtB . kbsdtbfy5k = rtDW .
f053xx0l23 ; } else { rtB . kbsdtbfy5k = rtP . Integ4_gainval * rtB .
e2o0qyzahq + rtDW . f053xx0l23 ; } rtB . f5ta3mfjzs = rtP . K1_Value ; {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnOutputs ( rts , 0 ) ; } if
( ssGetTaskTime ( rtS , 2 ) >= rtB . f5ta3mfjzs ) { rtB . nxju1b0nfk = ( rtB
. kbsdtbfy5k - rtB . gcgeoe3iiq ) * rtP . K2_Value + ( rtP .
Gain1_Gain_mpdvg40lot * rtB . e2o0qyzahq - rtP . Gain_Gain_nfdcqsmx05 * rtDW
. iayqwjxn30 ) ; } else { rtB . nxju1b0nfk = rtDW . g522ownwqo ; } if ( rtDW
. dhg2x3hhw4 != 0 ) { rtDW . c2nm3gd1a4 = muDoubleScalarSin (
6.2831853071795862 * rtP . Fourier1_Freq * ssGetTaskTime ( rtS , 2 ) ) ; rtDW
. f0oqest1i1 = muDoubleScalarCos ( 6.2831853071795862 * rtP . Fourier1_Freq *
ssGetTaskTime ( rtS , 2 ) ) ; rtDW . dhg2x3hhw4 = 0 ; } rtB . fsoikihjt1 = (
( ( rtDW . c2nm3gd1a4 * rtP . coswt_PCos + rtDW . f0oqest1i1 * rtP .
coswt_PSin ) * rtP . coswt_HCos + ( rtDW . f0oqest1i1 * rtP . coswt_PCos -
rtDW . c2nm3gd1a4 * rtP . coswt_PSin ) * rtP . coswt_Hsin ) * rtP . coswt_Amp
+ rtP . coswt_Bias ) * rtB . kbdwxc5gyv ; if ( rtDW . kqc5wee2bc != 0 ) { rtB
. gjyfuvtq0v = rtDW . motifvjzhr ; } else { rtB . gjyfuvtq0v = rtP .
Integ4_gainval_p0pakyry2d * rtB . fsoikihjt1 + rtDW . motifvjzhr ; } rtB .
ihgmb1kpmh = rtP . K1_Value_gmfkjcymcu ; { SimStruct * rts = ssGetSFunction (
rtS , 1 ) ; sfcnOutputs ( rts , 0 ) ; } if ( ssGetTaskTime ( rtS , 2 ) >= rtB
. ihgmb1kpmh ) { rtB . fwtfj3b0hp = ( rtB . gjyfuvtq0v - rtB . epdjm1qtac ) *
rtP . K2_Value_ehlwinmotq + ( rtP . Gain1_Gain * rtB . fsoikihjt1 - rtP .
Gain_Gain * rtDW . ocq00sjeyj ) ; } else { rtB . fwtfj3b0hp = rtDW .
edd2kbkzs3 ; } rtB . g4doefl2of = rtP . Gain_Gain_mzuc0gr3rr *
muDoubleScalarHypot ( rtB . nxju1b0nfk , rtB . fwtfj3b0hp ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . bcuawr35dl ) ; } } if ( rtB
. awqcje34vp ) { rtB . hpnhpaq3hf = rtB . b5bpctebld ; } else { rtB .
hpnhpaq3hf = rtB . g4doefl2of ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB
. cwstdnv15s ) { if ( ! rtDW . gov5rlozbf ) { if ( ssGetTaskTime ( rtS , 2 )
!= ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } rtDW . kzq4yloq2t = 1U ; rtDW . gov5rlozbf = true ; } } else { if ( rtDW
. gov5rlozbf ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW .
l4lzpabl4t = rtB . arg5blkvtg ; rtDW . gov5rlozbf = false ; } } } if ( rtDW .
gov5rlozbf ) { rtB . kp54qwa2gg = rtB . iwg44exs5g [ 2 ] * rtB . iwg44exs5g [
2 ] ; if ( rtDW . kzq4yloq2t != 0 ) { rtB . arg5blkvtg = rtDW . l4lzpabl4t ;
} else { rtB . arg5blkvtg = rtP . Integ4_gainval_cyxcyfj2ix * rtB .
kp54qwa2gg + rtDW . l4lzpabl4t ; } rtB . aiu4fdl0gc = rtP .
K1_Value_fiqnvvlbtv ; { SimStruct * rts = ssGetSFunction ( rtS , 5 ) ;
sfcnOutputs ( rts , 0 ) ; } if ( ssGetTaskTime ( rtS , 2 ) >= rtB .
aiu4fdl0gc ) { rtB . hezoo43y0q = ( rtB . arg5blkvtg - rtB . eihpzfi2ln ) *
rtP . K2_Value_kmw4g0e5by + ( rtP . Gain1_Gain_fdymcqm5hn * rtB . kp54qwa2gg
- rtP . Gain_Gain_lrl440wsi1 * rtDW . lpfa0xqegk ) ; } else { rtB .
hezoo43y0q = rtDW . ppix1t4koq ; } if ( rtB . hezoo43y0q > rtP .
Saturationtoavoidnegativesqrt_UpperSat_pkr45gxbax ) { ojvbmgui5a = rtP .
Saturationtoavoidnegativesqrt_UpperSat_pkr45gxbax ; } else if ( rtB .
hezoo43y0q < rtP . Saturationtoavoidnegativesqrt_LowerSat_faduiv0b3h ) {
ojvbmgui5a = rtP . Saturationtoavoidnegativesqrt_LowerSat_faduiv0b3h ; } else
{ ojvbmgui5a = rtB . hezoo43y0q ; } if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtDW . bfjoxab0mk != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; rtDW . bfjoxab0mk = 0 ; } rtB . ofcnur01ss = muDoubleScalarSqrt (
ojvbmgui5a ) ; srUpdateBC ( rtDW . l4lq0poyio ) ; } else if ( ojvbmgui5a <
0.0 ) { rtB . ofcnur01ss = - muDoubleScalarSqrt ( muDoubleScalarAbs (
ojvbmgui5a ) ) ; rtDW . bfjoxab0mk = 1 ; } else { rtB . ofcnur01ss =
muDoubleScalarSqrt ( ojvbmgui5a ) ; } } if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtB . hf5hmpwr00 ) { if ( ! rtDW . gob230sujf ) { if ( ssGetTaskTime ( rtS
, 2 ) != ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; } rtDW . ex3mrpp4j3 = 1 ; rtDW . fnn2bvdaoo = 1U ; rtDW . b4zx4xqegz
= 1 ; rtDW . moizrwcmqn = 1U ; rtDW . gob230sujf = true ; } } else { if (
rtDW . gob230sujf ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
rtDW . grpjnlftxq = rtB . n1uuisg4fw ; rtDW . pnojpqs3ns = rtB . mntq0tppuk ;
rtDW . gob230sujf = false ; } } } if ( rtDW . gob230sujf ) { if ( rtDW .
ex3mrpp4j3 != 0 ) { rtDW . o1pj5ffxoy = muDoubleScalarSin (
6.2831853071795862 * rtP . Fourier1_Freq_kyl1z2hreh * ssGetTaskTime ( rtS , 2
) ) ; rtDW . nmu44g4cwh = muDoubleScalarCos ( 6.2831853071795862 * rtP .
Fourier1_Freq_kyl1z2hreh * ssGetTaskTime ( rtS , 2 ) ) ; rtDW . ex3mrpp4j3 =
0 ; } rtB . afxisy1b20 = ( ( ( rtDW . o1pj5ffxoy * rtP .
sinwt_PCos_l0uzrah2yr + rtDW . nmu44g4cwh * rtP . sinwt_PSin_mqldsacd5r ) *
rtP . sinwt_HCos_phnvp0v0je + ( rtDW . nmu44g4cwh * rtP .
sinwt_PCos_l0uzrah2yr - rtDW . o1pj5ffxoy * rtP . sinwt_PSin_mqldsacd5r ) *
rtP . sinwt_Hsin_embht0yjxr ) * rtP . sinwt_Amp_oijvtutv4k + rtP .
sinwt_Bias_hpiubgslry ) * rtB . iwg44exs5g [ 2 ] ; if ( rtDW . fnn2bvdaoo !=
0 ) { rtB . n1uuisg4fw = rtDW . grpjnlftxq ; } else { rtB . n1uuisg4fw = rtP
. Integ4_gainval_b2hr2aosow * rtB . afxisy1b20 + rtDW . grpjnlftxq ; } rtB .
eua13yagug = rtP . K1_Value_d02xdalxac ; { SimStruct * rts = ssGetSFunction (
rtS , 3 ) ; sfcnOutputs ( rts , 0 ) ; } if ( ssGetTaskTime ( rtS , 2 ) >= rtB
. eua13yagug ) { rtB . fzd10ahxco = ( rtB . n1uuisg4fw - rtB . bmp4rhxpul ) *
rtP . K2_Value_gwlqxdyahb + ( rtP . Gain1_Gain_ju55l2bdzy * rtB . afxisy1b20
- rtP . Gain_Gain_evmlakd0vp * rtDW . ecmyri45ls ) ; } else { rtB .
fzd10ahxco = rtDW . j5dfwnlbxm ; } if ( rtDW . b4zx4xqegz != 0 ) { rtDW .
ipprpfttv3 = muDoubleScalarSin ( 6.2831853071795862 * rtP .
Fourier1_Freq_kyl1z2hreh * ssGetTaskTime ( rtS , 2 ) ) ; rtDW . jwcmyh4tyw =
muDoubleScalarCos ( 6.2831853071795862 * rtP . Fourier1_Freq_kyl1z2hreh *
ssGetTaskTime ( rtS , 2 ) ) ; rtDW . b4zx4xqegz = 0 ; } rtB . enecbqrfz5 = (
( ( rtDW . ipprpfttv3 * rtP . coswt_PCos_b2mnttqblm + rtDW . jwcmyh4tyw * rtP
. coswt_PSin_bcb2sivwyr ) * rtP . coswt_HCos_bibg2rjnu5 + ( rtDW . jwcmyh4tyw
* rtP . coswt_PCos_b2mnttqblm - rtDW . ipprpfttv3 * rtP .
coswt_PSin_bcb2sivwyr ) * rtP . coswt_Hsin_i0o0fsqk53 ) * rtP .
coswt_Amp_ckwsy1d5vd + rtP . coswt_Bias_hhsezuq143 ) * rtB . iwg44exs5g [ 2 ]
; if ( rtDW . moizrwcmqn != 0 ) { rtB . mntq0tppuk = rtDW . pnojpqs3ns ; }
else { rtB . mntq0tppuk = rtP . Integ4_gainval_nfkwaoa5zw * rtB . enecbqrfz5
+ rtDW . pnojpqs3ns ; } rtB . h0sb2533vd = rtP . K1_Value_fri1a0ongp ; {
SimStruct * rts = ssGetSFunction ( rtS , 4 ) ; sfcnOutputs ( rts , 0 ) ; } if
( ssGetTaskTime ( rtS , 2 ) >= rtB . h0sb2533vd ) { rtB . hewx2df0ek = ( rtB
. mntq0tppuk - rtB . hic1rjtsai ) * rtP . K2_Value_jtrzvmmebu + ( rtP .
Gain1_Gain_og1ztmrikp * rtB . enecbqrfz5 - rtP . Gain_Gain_cikg2wd54t * rtDW
. gwyanuw3x0 ) ; } else { rtB . hewx2df0ek = rtDW . ho5z3w1sbb ; } rtB .
hfz5bihucl = rtP . Gain_Gain_k2vac0i5eo * muDoubleScalarHypot ( rtB .
fzd10ahxco , rtB . hewx2df0ek ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . ksdc555p1f ) ; } } if ( rtB . cwstdnv15s ) { rtB .
kw2mc2f54g = rtB . ofcnur01ss ; } else { rtB . kw2mc2f54g = rtB . hfz5bihucl
; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB . nqc1swz1f5 ) { if ( ! rtDW
. gq2nzjnf0w ) { if ( ssGetTaskTime ( rtS , 2 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . l1z2owbfnm = 1U
; rtDW . gq2nzjnf0w = true ; } } else { if ( rtDW . gq2nzjnf0w ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . jt0sfxu401 = rtB
. mt1rpkiyfp ; rtDW . gq2nzjnf0w = false ; } } } if ( rtDW . gq2nzjnf0w ) {
rtB . ibafq0ggxu = rtB . iwg44exs5g [ 2 ] * rtB . iwg44exs5g [ 2 ] ; if (
rtDW . l1z2owbfnm != 0 ) { rtB . mt1rpkiyfp = rtDW . jt0sfxu401 ; } else {
rtB . mt1rpkiyfp = rtP . Integ4_gainval_aic2uxvjtz * rtB . ibafq0ggxu + rtDW
. jt0sfxu401 ; } rtB . jnh32a12mk = rtP . K1_Value_chvilvz2jj ; { SimStruct *
rts = ssGetSFunction ( rtS , 8 ) ; sfcnOutputs ( rts , 0 ) ; } if (
ssGetTaskTime ( rtS , 2 ) >= rtB . jnh32a12mk ) { rtB . cokmhxd3cw = ( rtB .
mt1rpkiyfp - rtB . gsqpfetcre ) * rtP . K2_Value_e5ticna4dr + ( rtP .
Gain1_Gain_iohcin0rw2 * rtB . ibafq0ggxu - rtP . Gain_Gain_ozgidwvo0b * rtDW
. bdoob1ijr3 ) ; } else { rtB . cokmhxd3cw = rtDW . jlot4ajqhq ; } if ( rtB .
cokmhxd3cw > rtP . Saturationtoavoidnegativesqrt_UpperSat_jebmupogt4 ) {
ojvbmgui5a = rtP . Saturationtoavoidnegativesqrt_UpperSat_jebmupogt4 ; } else
if ( rtB . cokmhxd3cw < rtP .
Saturationtoavoidnegativesqrt_LowerSat_hhpj4y3w4k ) { ojvbmgui5a = rtP .
Saturationtoavoidnegativesqrt_LowerSat_hhpj4y3w4k ; } else { ojvbmgui5a = rtB
. cokmhxd3cw ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . n3ddpqpuun !=
0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . n3ddpqpuun
= 0 ; } rtB . bisq51qkxp = muDoubleScalarSqrt ( ojvbmgui5a ) ; srUpdateBC (
rtDW . c3pebqdhtw ) ; } else if ( ojvbmgui5a < 0.0 ) { rtB . bisq51qkxp = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( ojvbmgui5a ) ) ; rtDW . n3ddpqpuun =
1 ; } else { rtB . bisq51qkxp = muDoubleScalarSqrt ( ojvbmgui5a ) ; } } if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtB . aw0sdhxkut ) { if ( ! rtDW .
eibahmjyhj ) { if ( ssGetTaskTime ( rtS , 2 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . doyt1502bn = 1
; rtDW . lz0tgfsnu0 = 1U ; rtDW . csvpkvttn4 = 1 ; rtDW . oknt3qnnbn = 1U ;
rtDW . eibahmjyhj = true ; } } else { if ( rtDW . eibahmjyhj ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . lrcapd2g5t = rtB
. afvbv15lpm ; rtDW . gfeprm5f5a = rtB . c2v2toypds ; rtDW . eibahmjyhj =
false ; } } } if ( rtDW . eibahmjyhj ) { if ( rtDW . doyt1502bn != 0 ) { rtDW
. iwqu4lrnkv = muDoubleScalarSin ( 6.2831853071795862 * rtP .
Fourier1_Freq_ckkrxwnziq * ssGetTaskTime ( rtS , 2 ) ) ; rtDW . e4ptdvhtkx =
muDoubleScalarCos ( 6.2831853071795862 * rtP . Fourier1_Freq_ckkrxwnziq *
ssGetTaskTime ( rtS , 2 ) ) ; rtDW . doyt1502bn = 0 ; } rtB . gp3dcunmfo = (
( ( rtDW . iwqu4lrnkv * rtP . sinwt_PCos_bqkynrur55 + rtDW . e4ptdvhtkx * rtP
. sinwt_PSin_ezmzcturha ) * rtP . sinwt_HCos_iatcouh3bm + ( rtDW . e4ptdvhtkx
* rtP . sinwt_PCos_bqkynrur55 - rtDW . iwqu4lrnkv * rtP .
sinwt_PSin_ezmzcturha ) * rtP . sinwt_Hsin_fwqz1kodyw ) * rtP .
sinwt_Amp_l2gdj0uf33 + rtP . sinwt_Bias_of4cf15cx1 ) * rtB . iwg44exs5g [ 2 ]
; if ( rtDW . lz0tgfsnu0 != 0 ) { rtB . afvbv15lpm = rtDW . lrcapd2g5t ; }
else { rtB . afvbv15lpm = rtP . Integ4_gainval_ad3r4knrp3 * rtB . gp3dcunmfo
+ rtDW . lrcapd2g5t ; } rtB . o1kjfgygqq = rtP . K1_Value_bvxfbao2pd ; {
SimStruct * rts = ssGetSFunction ( rtS , 6 ) ; sfcnOutputs ( rts , 0 ) ; } if
( ssGetTaskTime ( rtS , 2 ) >= rtB . o1kjfgygqq ) { rtB . oswn5ymim2 = ( rtB
. afvbv15lpm - rtB . nj0zvfpbxs ) * rtP . K2_Value_lfot5huboi + ( rtP .
Gain1_Gain_pp3awytfhp * rtB . gp3dcunmfo - rtP . Gain_Gain_cvnqvfbfob * rtDW
. jwkyerowmb ) ; } else { rtB . oswn5ymim2 = rtDW . lbvma42sos ; } if ( rtDW
. csvpkvttn4 != 0 ) { rtDW . a4o1phii2z = muDoubleScalarSin (
6.2831853071795862 * rtP . Fourier1_Freq_ckkrxwnziq * ssGetTaskTime ( rtS , 2
) ) ; rtDW . d5beywmeax = muDoubleScalarCos ( 6.2831853071795862 * rtP .
Fourier1_Freq_ckkrxwnziq * ssGetTaskTime ( rtS , 2 ) ) ; rtDW . csvpkvttn4 =
0 ; } rtB . g1gbvczb2o = ( ( ( rtDW . a4o1phii2z * rtP .
coswt_PCos_jfqix0kyk3 + rtDW . d5beywmeax * rtP . coswt_PSin_ien3v5if2m ) *
rtP . coswt_HCos_hrlrqukbrc + ( rtDW . d5beywmeax * rtP .
coswt_PCos_jfqix0kyk3 - rtDW . a4o1phii2z * rtP . coswt_PSin_ien3v5if2m ) *
rtP . coswt_Hsin_ipmmvop0j2 ) * rtP . coswt_Amp_mrrwl5kftw + rtP .
coswt_Bias_eabnppk3dd ) * rtB . iwg44exs5g [ 2 ] ; if ( rtDW . oknt3qnnbn !=
0 ) { rtB . c2v2toypds = rtDW . gfeprm5f5a ; } else { rtB . c2v2toypds = rtP
. Integ4_gainval_k5i2tkby2r * rtB . g1gbvczb2o + rtDW . gfeprm5f5a ; } rtB .
fxp4n1nqzj = rtP . K1_Value_fpmnopebgd ; { SimStruct * rts = ssGetSFunction (
rtS , 7 ) ; sfcnOutputs ( rts , 0 ) ; } if ( ssGetTaskTime ( rtS , 2 ) >= rtB
. fxp4n1nqzj ) { rtB . ixh4gmo224 = ( rtB . c2v2toypds - rtB . mw5rzz05or ) *
rtP . K2_Value_fdk4k2gepc + ( rtP . Gain1_Gain_h3dgnhtza4 * rtB . g1gbvczb2o
- rtP . Gain_Gain_irzzlkvume * rtDW . jjebi2i5un ) ; } else { rtB .
ixh4gmo224 = rtDW . ebmpnozmec ; } rtB . fm33dmmmls = rtP .
Gain_Gain_mjhuuub0oq * muDoubleScalarHypot ( rtB . oswn5ymim2 , rtB .
ixh4gmo224 ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
mvd0gisct2 ) ; } } if ( rtB . nqc1swz1f5 ) { rtB . np4sgj0uze = rtB .
bisq51qkxp ; } else { rtB . np4sgj0uze = rtB . fm33dmmmls ; } { if ( ( rtDW .
fwmkchozeq . AQHandles || rtDW . fwmkchozeq . SlioLTF ) && ssGetLogOutput (
rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . fwmkchozeq . AQHandles , rtDW .
fwmkchozeq . SlioLTF , 0 , ssGetTaskTime ( rtS , 2 ) , ( void * ) & rtB .
np4sgj0uze ) ; } } { if ( ( rtDW . nvuyb1yzrc . AQHandles || rtDW .
nvuyb1yzrc . SlioLTF ) && ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal (
rtDW . nvuyb1yzrc . AQHandles , rtDW . nvuyb1yzrc . SlioLTF , 0 ,
ssGetTaskTime ( rtS , 2 ) , ( void * ) & rtB . iwg44exs5g [ 4 ] ) ; } } { if
( ( rtDW . k4mh4yu0ov . AQHandles || rtDW . k4mh4yu0ov . SlioLTF ) &&
ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . k4mh4yu0ov .
AQHandles , rtDW . k4mh4yu0ov . SlioLTF , 0 , ssGetTaskTime ( rtS , 2 ) , (
void * ) & rtB . iwg44exs5g [ 3 ] ) ; } } } if ( ssIsSampleHit ( rtS , 2 , 0
) ) { } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T tid ) { rtB
. awqcje34vp = ( rtP . RMS3_TrueRMS != 0.0 ) ; rtB . kvdej4nyky = ! rtB .
awqcje34vp ; rtB . cwstdnv15s = ( rtP . RMS4_TrueRMS != 0.0 ) ; rtB .
hf5hmpwr00 = ! rtB . cwstdnv15s ; rtB . nqc1swz1f5 = ( rtP . RMS5_TrueRMS !=
0.0 ) ; rtB . aw0sdhxkut = ! rtB . nqc1swz1f5 ; UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { NeslSimulationData * simulationData ; real_T
time ; boolean_T tmp ; real_T tmp_p [ 24 ] ; int_T tmp_e [ 7 ] ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; int32_T tmp_i ; char * msg ; real_T HoldSine ; if ( ssIsSampleHit ( rtS , 2
, 0 ) ) { simulationData = ( NeslSimulationData * ) rtDW . j4btagyhoo ; time
= ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time ; simulationData -> mData -> mContStates . mN
= 0 ; simulationData -> mData -> mContStates . mX = NULL ; simulationData ->
mData -> mDiscStates . mN = 123 ; simulationData -> mData -> mDiscStates . mX
= ( real_T * ) & rtDW . lpi2q22kbk ; simulationData -> mData -> mModeVector .
mN = 36 ; simulationData -> mData -> mModeVector . mX = ( int32_T * ) & rtDW
. laeadqjoyo ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS
) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = true ; tmp = ( ssGetMdlInfoPtr
( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; simulationData -> mData ->
mIsEvaluatingF0 = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . imlhhcedkr [ 0 ] ; tmp_p [ 1 ] = rtB . imlhhcedkr [ 1 ] ;
tmp_p [ 2 ] = rtB . imlhhcedkr [ 2 ] ; tmp_p [ 3 ] = rtB . imlhhcedkr [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . p51dkbkwid [ 0 ] ; tmp_p [ 5 ] = rtB .
p51dkbkwid [ 1 ] ; tmp_p [ 6 ] = rtB . p51dkbkwid [ 2 ] ; tmp_p [ 7 ] = rtB .
p51dkbkwid [ 3 ] ; tmp_e [ 2 ] = 8 ; tmp_p [ 8 ] = rtB . lc0gh4vn0y [ 0 ] ;
tmp_p [ 9 ] = rtB . lc0gh4vn0y [ 1 ] ; tmp_p [ 10 ] = rtB . lc0gh4vn0y [ 2 ]
; tmp_p [ 11 ] = rtB . lc0gh4vn0y [ 3 ] ; tmp_e [ 3 ] = 12 ; tmp_p [ 12 ] =
rtB . ajqsccxh4n [ 0 ] ; tmp_p [ 13 ] = rtB . ajqsccxh4n [ 1 ] ; tmp_p [ 14 ]
= rtB . ajqsccxh4n [ 2 ] ; tmp_p [ 15 ] = rtB . ajqsccxh4n [ 3 ] ; tmp_e [ 4
] = 16 ; tmp_p [ 16 ] = rtB . idj5hyxoz3 [ 0 ] ; tmp_p [ 17 ] = rtB .
idj5hyxoz3 [ 1 ] ; tmp_p [ 18 ] = rtB . idj5hyxoz3 [ 2 ] ; tmp_p [ 19 ] = rtB
. idj5hyxoz3 [ 3 ] ; tmp_e [ 5 ] = 20 ; tmp_p [ 20 ] = rtB . frvw5tfr5q [ 0 ]
; tmp_p [ 21 ] = rtB . frvw5tfr5q [ 1 ] ; tmp_p [ 22 ] = rtB . frvw5tfr5q [ 2
] ; tmp_p [ 23 ] = rtB . frvw5tfr5q [ 3 ] ; tmp_e [ 6 ] = 24 ; simulationData
-> mData -> mInputValues . mN = 24 ; simulationData -> mData -> mInputValues
. mX = & tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 7 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ljvsw4ftil ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . bgwsy3m1jh ,
NESL_SIM_UPDATE , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
if ( rtDW . ecisw5adre ) { rtDW . f54g14zkss = 0U ; rtDW . cx3y5wj24t = rtP .
Integ4_gainval_cmbswlryt5 * rtB . k4fqogeply + rtB . d4yrrkxbew ; { SimStruct
* rts = ssGetSFunction ( rtS , 2 ) ; sfcnUpdate ( rts , 0 ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW . liyidkg1og = rtB .
k4fqogeply ; rtDW . hq3xers3h0 = rtB . oww2w4mlsz ; } if ( rtDW . kurl1epm13
) { HoldSine = rtDW . fadr5pbwq1 ; rtDW . fadr5pbwq1 = rtDW . fadr5pbwq1 *
rtP . sinwt_HCos + rtDW . jetkaz1b2y * rtP . sinwt_Hsin ; rtDW . jetkaz1b2y =
rtDW . jetkaz1b2y * rtP . sinwt_HCos - HoldSine * rtP . sinwt_Hsin ; rtDW .
g3mio5fr0t = 0U ; rtDW . f053xx0l23 = rtP . Integ4_gainval * rtB . e2o0qyzahq
+ rtB . kbsdtbfy5k ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ;
} rtDW . iayqwjxn30 = rtB . e2o0qyzahq ; rtDW . g522ownwqo = rtB . nxju1b0nfk
; HoldSine = rtDW . c2nm3gd1a4 ; rtDW . c2nm3gd1a4 = rtDW . c2nm3gd1a4 * rtP
. coswt_HCos + rtDW . f0oqest1i1 * rtP . coswt_Hsin ; rtDW . f0oqest1i1 =
rtDW . f0oqest1i1 * rtP . coswt_HCos - HoldSine * rtP . coswt_Hsin ; rtDW .
kqc5wee2bc = 0U ; rtDW . motifvjzhr = rtP . Integ4_gainval_p0pakyry2d * rtB .
fsoikihjt1 + rtB . gjyfuvtq0v ; { SimStruct * rts = ssGetSFunction ( rtS , 1
) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } rtDW . ocq00sjeyj = rtB . fsoikihjt1 ; rtDW . edd2kbkzs3 = rtB .
fwtfj3b0hp ; } if ( rtDW . gov5rlozbf ) { rtDW . kzq4yloq2t = 0U ; rtDW .
l4lzpabl4t = rtP . Integ4_gainval_cyxcyfj2ix * rtB . kp54qwa2gg + rtB .
arg5blkvtg ; { SimStruct * rts = ssGetSFunction ( rtS , 5 ) ; sfcnUpdate (
rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW .
lpfa0xqegk = rtB . kp54qwa2gg ; rtDW . ppix1t4koq = rtB . hezoo43y0q ; } if (
rtDW . gob230sujf ) { HoldSine = rtDW . o1pj5ffxoy ; rtDW . o1pj5ffxoy = rtDW
. o1pj5ffxoy * rtP . sinwt_HCos_phnvp0v0je + rtDW . nmu44g4cwh * rtP .
sinwt_Hsin_embht0yjxr ; rtDW . nmu44g4cwh = rtDW . nmu44g4cwh * rtP .
sinwt_HCos_phnvp0v0je - HoldSine * rtP . sinwt_Hsin_embht0yjxr ; rtDW .
fnn2bvdaoo = 0U ; rtDW . grpjnlftxq = rtP . Integ4_gainval_b2hr2aosow * rtB .
afxisy1b20 + rtB . n1uuisg4fw ; { SimStruct * rts = ssGetSFunction ( rtS , 3
) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } rtDW . ecmyri45ls = rtB . afxisy1b20 ; rtDW . j5dfwnlbxm = rtB .
fzd10ahxco ; HoldSine = rtDW . ipprpfttv3 ; rtDW . ipprpfttv3 = rtDW .
ipprpfttv3 * rtP . coswt_HCos_bibg2rjnu5 + rtDW . jwcmyh4tyw * rtP .
coswt_Hsin_i0o0fsqk53 ; rtDW . jwcmyh4tyw = rtDW . jwcmyh4tyw * rtP .
coswt_HCos_bibg2rjnu5 - HoldSine * rtP . coswt_Hsin_i0o0fsqk53 ; rtDW .
moizrwcmqn = 0U ; rtDW . pnojpqs3ns = rtP . Integ4_gainval_nfkwaoa5zw * rtB .
enecbqrfz5 + rtB . mntq0tppuk ; { SimStruct * rts = ssGetSFunction ( rtS , 4
) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } rtDW . gwyanuw3x0 = rtB . enecbqrfz5 ; rtDW . ho5z3w1sbb = rtB .
hewx2df0ek ; } if ( rtDW . gq2nzjnf0w ) { rtDW . l1z2owbfnm = 0U ; rtDW .
jt0sfxu401 = rtP . Integ4_gainval_aic2uxvjtz * rtB . ibafq0ggxu + rtB .
mt1rpkiyfp ; { SimStruct * rts = ssGetSFunction ( rtS , 8 ) ; sfcnUpdate (
rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtDW .
bdoob1ijr3 = rtB . ibafq0ggxu ; rtDW . jlot4ajqhq = rtB . cokmhxd3cw ; } if (
rtDW . eibahmjyhj ) { HoldSine = rtDW . iwqu4lrnkv ; rtDW . iwqu4lrnkv = rtDW
. iwqu4lrnkv * rtP . sinwt_HCos_iatcouh3bm + rtDW . e4ptdvhtkx * rtP .
sinwt_Hsin_fwqz1kodyw ; rtDW . e4ptdvhtkx = rtDW . e4ptdvhtkx * rtP .
sinwt_HCos_iatcouh3bm - HoldSine * rtP . sinwt_Hsin_fwqz1kodyw ; rtDW .
lz0tgfsnu0 = 0U ; rtDW . lrcapd2g5t = rtP . Integ4_gainval_ad3r4knrp3 * rtB .
gp3dcunmfo + rtB . afvbv15lpm ; { SimStruct * rts = ssGetSFunction ( rtS , 6
) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } rtDW . jwkyerowmb = rtB . gp3dcunmfo ; rtDW . lbvma42sos = rtB .
oswn5ymim2 ; HoldSine = rtDW . a4o1phii2z ; rtDW . a4o1phii2z = rtDW .
a4o1phii2z * rtP . coswt_HCos_hrlrqukbrc + rtDW . d5beywmeax * rtP .
coswt_Hsin_ipmmvop0j2 ; rtDW . d5beywmeax = rtDW . d5beywmeax * rtP .
coswt_HCos_hrlrqukbrc - HoldSine * rtP . coswt_Hsin_ipmmvop0j2 ; rtDW .
oknt3qnnbn = 0U ; rtDW . gfeprm5f5a = rtP . Integ4_gainval_k5i2tkby2r * rtB .
g1gbvczb2o + rtB . c2v2toypds ; { SimStruct * rts = ssGetSFunction ( rtS , 7
) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } rtDW . jjebi2i5un = rtB . g1gbvczb2o ; rtDW . ebmpnozmec = rtB .
ixh4gmo224 ; } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID4 ( int_T tid
) { UNUSED_PARAMETER ( tid ) ; } void MdlZeroCrossings ( void ) { ZCV *
_rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV
-> h1hyrdcllz = rtB . eovubh0rxu - rtP . Constant_Value_dlflefihkr ; _rtZCSV
-> okrolznbwl = rtB . bgybglbgav - rtP . Constant_Value_l3unqqh2kq ; _rtZCSV
-> ipf4r3df0b = rtB . bgybglbgav - rtP . Constant_Value_dxzjx5wwcr ; _rtZCSV
-> gngpeei5u4 = rtB . eovubh0rxu - rtP . Constant_Value_a4nouejct5 ; _rtZCSV
-> aydmc4pu5v = rtB . b1ptcc5egb - rtP . Constant_Value_cpsdmvnz4x ; _rtZCSV
-> honk40fjnb = rtB . b1ptcc5egb - rtP . Constant_Value_ln0n1kk0z4 ; } void
MdlTerminate ( void ) { neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . ljvsw4ftil ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . j4btagyhoo ) ; nesl_erase_simulator (
"InverterWFETs/Solver Configuration_1" ) ; neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . d3bgeeko12 ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . pco3n20tlq ) ; nesl_erase_simulator (
"InverterWFETs/Solver Configuration_1" ) ; { SimStruct * rts = ssGetSFunction
( rtS , 2 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction (
rtS , 1 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction (
rtS , 5 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction (
rtS , 3 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction (
rtS , 4 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction (
rtS , 8 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction (
rtS , 6 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction (
rtS , 7 ) ; sfcnTerminate ( rts ) ; } { if ( rtDW . fwmkchozeq . AQHandles )
{ sdiTerminateStreaming ( & rtDW . fwmkchozeq . AQHandles ) ; } if ( rtDW .
fwmkchozeq . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . fwmkchozeq .
SlioLTF ) ; } } { if ( rtDW . nvuyb1yzrc . AQHandles ) {
sdiTerminateStreaming ( & rtDW . nvuyb1yzrc . AQHandles ) ; } if ( rtDW .
nvuyb1yzrc . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . nvuyb1yzrc .
SlioLTF ) ; } } { if ( rtDW . k4mh4yu0ov . AQHandles ) {
sdiTerminateStreaming ( & rtDW . k4mh4yu0ov . AQHandles ) ; } if ( rtDW .
k4mh4yu0ov . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . k4mh4yu0ov .
SlioLTF ) ; } } if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 4 ) ; ssSetNumBlocks ( rtS , 468 ) ;
ssSetNumBlockIO ( rtS , 85 ) ; ssSetNumBlockParams ( rtS , 267 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 1.0E-8 ) ;
ssSetSampleTime ( rtS , 3 , 1.0E-5 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 67555714U ) ; ssSetChecksumVal ( rtS , 1 ,
1362381361U ) ; ssSetChecksumVal ( rtS , 2 , 3890521108U ) ; ssSetChecksumVal
( rtS , 3 , 1778704554U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { void * dwork =
( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork
, 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset
( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo (
rtS , & dtInfo ) ; dtInfo . numDataTypes = 17 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; } InverterWFETs_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"InverterWFETs" ) ; ssSetPath ( rtS , "InverterWFETs" ) ; ssSetTStart ( rtS ,
0.0 ) ; ssSetTFinal ( rtS , 0.025 ) ; { static RTWLogInfo rt_DataLoggingInfo
; rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; static uint8_T zcAttributes [ 6 ] = { ( ZC_EVENT_ALL
) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) } ; ssSetStepSize ( rtS , 1.0E-8 ) ; ssSetMinStepSize (
rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError (
rtS , 0 ) ; ssSetMaxStepSize ( rtS , 1.0E-8 ) ; ssSetSolverMaxOrder ( rtS , -
1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL )
) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetSolverZcSignalAttrib ( rtS ,
zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 6 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 6 ) ; } ssSetChecksumVal ( rtS , 0 , 67555714U
) ; ssSetChecksumVal ( rtS , 1 , 1362381361U ) ; ssSetChecksumVal ( rtS , 2 ,
3890521108U ) ; ssSetChecksumVal ( rtS , 3 , 1778704554U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 16 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . bcuawr35dl ; systemRan [ 2 ] = ( sysRanDType * ) &
rtDW . bcuawr35dl ; systemRan [ 3 ] = ( sysRanDType * ) & rtDW . bcuawr35dl ;
systemRan [ 4 ] = ( sysRanDType * ) & rtDW . pkc5pvpbud ; systemRan [ 5 ] = (
sysRanDType * ) & rtDW . pkc5pvpbud ; systemRan [ 6 ] = ( sysRanDType * ) &
rtDW . ksdc555p1f ; systemRan [ 7 ] = ( sysRanDType * ) & rtDW . ksdc555p1f ;
systemRan [ 8 ] = ( sysRanDType * ) & rtDW . ksdc555p1f ; systemRan [ 9 ] = (
sysRanDType * ) & rtDW . l4lq0poyio ; systemRan [ 10 ] = ( sysRanDType * ) &
rtDW . l4lq0poyio ; systemRan [ 11 ] = ( sysRanDType * ) & rtDW . mvd0gisct2
; systemRan [ 12 ] = ( sysRanDType * ) & rtDW . mvd0gisct2 ; systemRan [ 13 ]
= ( sysRanDType * ) & rtDW . mvd0gisct2 ; systemRan [ 14 ] = ( sysRanDType *
) & rtDW . c3pebqdhtw ; systemRan [ 15 ] = ( sysRanDType * ) & rtDW .
c3pebqdhtw ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } rtP . Saturationtoavoidnegativesqrt_UpperSat =
rtInf ; rtP . Saturationtoavoidnegativesqrt_UpperSat_pkr45gxbax = rtInf ; rtP
. Saturationtoavoidnegativesqrt_UpperSat_jebmupogt4 = rtInf ;
ssSetNumSFunctions ( rtS , 9 ) ; { static SimStruct childSFunctions [ 9 ] ;
static SimStruct * childSFunctionPtrs [ 9 ] ; ( void ) memset ( ( void * ) &
childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions ) ) ; ssSetSFunctions (
rtS , & childSFunctionPtrs [ 0 ] ) ; { int_T i ; for ( i = 0 ; i < 9 ; i ++ )
{ ssSetSFunction ( rtS , i , & childSFunctions [ i ] ) ; } } { SimStruct *
rts = ssGetSFunction ( rtS , 0 ) ; static time_T sfcnPeriod [ 1 ] ; static
time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( (
void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void
* ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; { static struct _ssBlkInfo2
_blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr (
rts , blkInfo2 ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; } { static struct _ssPortInputs inputPortInfo [ 2 ] ;
_ssSetNumInputPorts ( rts , 2 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static struct _ssInPortUnit inputPortUnits [ 2 ] ;
_ssSetPortInfo2ForInputUnits ( rts , & inputPortUnits [ 0 ] ) ; }
ssSetInputPortUnit ( rts , 0 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 2 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static real_T const *
sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . kbsdtbfy5k ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
f5ta3mfjzs ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . gcgeoe3iiq
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size ) ; ssSetSFcnParam ( rts , 1 , (
mxArray * ) rtP . SFunction_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray
* ) rtP . SFunction_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP
. SFunction_P4_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW . ogm11qxgfe
) ; ssSetIWork ( rts , ( int_T * ) & rtDW . dmjstp1pnq ) ; ssSetPWork ( rts ,
( void * * ) & rtDW . a5txtrw5jr ) ; { static struct _ssDWorkRecord
dWorkRecord [ 3 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ; ssSetDWorkWidth ( rts , 0 , 1
) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE ) ; ssSetDWorkComplexSignal (
rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW . ogm11qxgfe ) ;
ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1 , SS_INTEGER )
; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW .
dmjstp1pnq ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ; ssSetDWorkDataType ( rts , 2
, SS_POINTER ) ; ssSetDWorkComplexSignal ( rts , 2 , 0 ) ; ssSetDWork ( rts ,
2 , & rtDW . a5txtrw5jr ) ; } sfun_discreteVariableDelay ( rts ) ;
sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 1.0E-8 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ;
sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth ( rts , 0 , 1 ) ;
ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ; ssSetInputPortComplexSignal
( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts
, 0 , 0 ) ; ssSetInputPortWidth ( rts , 1 , 1 ) ; ssSetInputPortDataType (
rts , 1 , SS_DOUBLE ) ; ssSetInputPortComplexSignal ( rts , 1 , 0 ) ;
ssSetInputPortFrameData ( rts , 1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 )
; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . gjyfuvtq0v ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
ihgmb1kpmh ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . epdjm1qtac
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size_h24o5xofg5 ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . SFunction_P2_Size_ptok2c4vkm ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . SFunction_P3_Size_ojs5p0ceq0 ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . SFunction_P4_Size_kvdkozvfrz ) ; } ssSetRWork ( rts
, ( real_T * ) & rtDW . luocivfdwy ) ; ssSetIWork ( rts , ( int_T * ) & rtDW
. hgmprgjhr2 ) ; ssSetPWork ( rts , ( void * * ) & rtDW . lxt5anhnhb ) ; {
static struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
luocivfdwy ) ; ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1
, SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts ,
1 , & rtDW . hgmprgjhr2 ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . lxt5anhnhb ) ; }
sfun_discreteVariableDelay ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 1.0E-8 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth
( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetInputPortWidth (
rts , 1 , 1 ) ; ssSetInputPortDataType ( rts , 1 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 1 , 0 ) ; ssSetInputPortFrameData ( rts ,
1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . d4yrrkxbew ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
jeyupwj05d ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . povy1e3cdf
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS3/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size_cfue4013uz ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . SFunction_P2_Size_ay0oozdq4l ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . SFunction_P3_Size_eavq2jcrxn ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . SFunction_P4_Size_iuauhtkk0r ) ; } ssSetRWork ( rts
, ( real_T * ) & rtDW . a5wlka4qb2 ) ; ssSetIWork ( rts , ( int_T * ) & rtDW
. eeda03zvsk ) ; ssSetPWork ( rts , ( void * * ) & rtDW . p4eex3535n ) ; {
static struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
a5wlka4qb2 ) ; ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1
, SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts ,
1 , & rtDW . eeda03zvsk ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . p4eex3535n ) ; }
sfun_discreteVariableDelay ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 1.0E-8 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth
( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetInputPortWidth (
rts , 1 , 1 ) ; ssSetInputPortDataType ( rts , 1 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 1 , 0 ) ; ssSetInputPortFrameData ( rts ,
1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . n1uuisg4fw ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
eua13yagug ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . bmp4rhxpul
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size_drqbfawq2t ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . SFunction_P2_Size_mtui52flb0 ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . SFunction_P3_Size_koxhnafs0c ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . SFunction_P4_Size_jmx5nhnvsc ) ; } ssSetRWork ( rts
, ( real_T * ) & rtDW . pb0fxdtdzl ) ; ssSetIWork ( rts , ( int_T * ) & rtDW
. mqhuvls5ex ) ; ssSetPWork ( rts , ( void * * ) & rtDW . ocujfrzzrp ) ; {
static struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
pb0fxdtdzl ) ; ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1
, SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts ,
1 , & rtDW . mqhuvls5ex ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . ocujfrzzrp ) ; }
sfun_discreteVariableDelay ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 1.0E-8 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth
( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetInputPortWidth (
rts , 1 , 1 ) ; ssSetInputPortDataType ( rts , 1 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 1 , 0 ) ; ssSetInputPortFrameData ( rts ,
1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 4 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . mntq0tppuk ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
h0sb2533vd ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . hic1rjtsai
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size_mdfnofpkyb ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . SFunction_P2_Size_kn3dc1rpjw ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . SFunction_P3_Size_iffghakq0a ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . SFunction_P4_Size_ngg0llxaro ) ; } ssSetRWork ( rts
, ( real_T * ) & rtDW . kzaxa1cwm5 ) ; ssSetIWork ( rts , ( int_T * ) & rtDW
. l3nkgsx0lg ) ; ssSetPWork ( rts , ( void * * ) & rtDW . iphuwwyg2r ) ; {
static struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
kzaxa1cwm5 ) ; ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1
, SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts ,
1 , & rtDW . l3nkgsx0lg ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . iphuwwyg2r ) ; }
sfun_discreteVariableDelay ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 1.0E-8 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth
( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetInputPortWidth (
rts , 1 , 1 ) ; ssSetInputPortDataType ( rts , 1 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 1 , 0 ) ; ssSetInputPortFrameData ( rts ,
1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 5 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . arg5blkvtg ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
aiu4fdl0gc ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . eihpzfi2ln
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS4/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size_adklgix35t ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . SFunction_P2_Size_fn0kh1ozqy ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . SFunction_P3_Size_a4xnsyreel ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . SFunction_P4_Size_h30xo1wbyk ) ; } ssSetRWork ( rts
, ( real_T * ) & rtDW . bmrkjzbemi ) ; ssSetIWork ( rts , ( int_T * ) & rtDW
. m4mwptfw3a ) ; ssSetPWork ( rts , ( void * * ) & rtDW . flsmaquu11 ) ; {
static struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
bmrkjzbemi ) ; ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1
, SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts ,
1 , & rtDW . m4mwptfw3a ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . flsmaquu11 ) ; }
sfun_discreteVariableDelay ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 1.0E-8 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth
( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetInputPortWidth (
rts , 1 , 1 ) ; ssSetInputPortDataType ( rts , 1 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 1 , 0 ) ; ssSetInputPortFrameData ( rts ,
1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 6 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . afvbv15lpm ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
o1kjfgygqq ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . nj0zvfpbxs
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size_hdzfqts4px ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . SFunction_P2_Size_kygust4i13 ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . SFunction_P3_Size_gxecz1stla ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . SFunction_P4_Size_ehy32gbq1m ) ; } ssSetRWork ( rts
, ( real_T * ) & rtDW . hksk41e2yx ) ; ssSetIWork ( rts , ( int_T * ) & rtDW
. ggh5d2ostt ) ; ssSetPWork ( rts , ( void * * ) & rtDW . mwaj5uxciv ) ; {
static struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
hksk41e2yx ) ; ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1
, SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts ,
1 , & rtDW . ggh5d2ostt ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . mwaj5uxciv ) ; }
sfun_discreteVariableDelay ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 1.0E-8 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth
( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetInputPortWidth (
rts , 1 , 1 ) ; ssSetInputPortDataType ( rts , 1 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 1 , 0 ) ; ssSetInputPortFrameData ( rts ,
1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 7 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . c2v2toypds ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
fxp4n1nqzj ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . mw5rzz05or
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size_nurtgxf3pr ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . SFunction_P2_Size_abuhz0s45k ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . SFunction_P3_Size_iribng3jzq ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . SFunction_P4_Size_d34e4l0tlz ) ; } ssSetRWork ( rts
, ( real_T * ) & rtDW . ljdesx2yzv ) ; ssSetIWork ( rts , ( int_T * ) & rtDW
. ddn5xcth0s ) ; ssSetPWork ( rts , ( void * * ) & rtDW . ng4gmlk2i5 ) ; {
static struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
ljdesx2yzv ) ; ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1
, SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts ,
1 , & rtDW . ddn5xcth0s ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . ng4gmlk2i5 ) ; }
sfun_discreteVariableDelay ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 1.0E-8 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth
( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetInputPortWidth (
rts , 1 , 1 ) ; ssSetInputPortDataType ( rts , 1 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 1 , 0 ) ; ssSetInputPortFrameData ( rts ,
1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 8 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; ssSetStatesInfo2 ( rts , &
statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ; } {
static struct _ssPortInputs inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts ,
2 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . mt1rpkiyfp ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB .
jnh32a12mk ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidth ( rts , 1 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . gsqpfetcre
) ) ; } } ssSetModelName ( rts , "S-Function" ) ; ssSetPath ( rts ,
 "InverterWFETs/RMS5/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size_nq3uzrogtq ) ; ssSetSFcnParam ( rts , 1
, ( mxArray * ) rtP . SFunction_P2_Size_brp5zn1b4c ) ; ssSetSFcnParam ( rts ,
2 , ( mxArray * ) rtP . SFunction_P3_Size_dz2f5ik0lq ) ; ssSetSFcnParam ( rts
, 3 , ( mxArray * ) rtP . SFunction_P4_Size_go4cr2gil4 ) ; } ssSetRWork ( rts
, ( real_T * ) & rtDW . dewhsbzzvs ) ; ssSetIWork ( rts , ( int_T * ) & rtDW
. hnibndvd1j ) ; ssSetPWork ( rts , ( void * * ) & rtDW . iak0awbnmq ) ; {
static struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
dewhsbzzvs ) ; ssSetDWorkWidth ( rts , 1 , 1 ) ; ssSetDWorkDataType ( rts , 1
, SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts ,
1 , & rtDW . hnibndvd1j ) ; ssSetDWorkWidth ( rts , 2 , 1 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . iak0awbnmq ) ; }
sfun_discreteVariableDelay ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 1.0E-8 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ; ssSetInputPortWidth
( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts ,
0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetInputPortWidth (
rts , 1 , 1 ) ; ssSetInputPortDataType ( rts , 1 , SS_DOUBLE ) ;
ssSetInputPortComplexSignal ( rts , 1 , 0 ) ; ssSetInputPortFrameData ( rts ,
1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 ) ;
ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; ssSetOutputPortWidth (
rts , 0 , 1 ) ; ssSetOutputPortDataType ( rts , 0 , SS_DOUBLE ) ;
ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ; ssSetOutputPortFrameData ( rts
, 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; ssSetNumIWork ( rts , 1
) ; ssSetNumPWork ( rts , 1 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
