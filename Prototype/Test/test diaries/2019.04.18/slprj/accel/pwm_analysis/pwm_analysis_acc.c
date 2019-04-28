#include "__cf_pwm_analysis.h"
#include <math.h>
#include "pwm_analysis_acc.h"
#include "pwm_analysis_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr ,
int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * tBufPtr , real_T * * uBufPtr , real_T * * xBufPtr , boolean_T
isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr ) { int_T
testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf =
* tBufPtr ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if (
istransportdelay ) { numBuffer = 3 ; xBuf = * xBufPtr ; } testIdx = ( tail <
( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] )
&& ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T * tempU ; real_T *
tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T newBufSz = bufSz + 1024
; if ( newBufSz > * maxNewBufSzPtr ) { * maxNewBufSzPtr = newBufSz ; } tempU
= ( real_T * ) utMalloc ( numBuffer * newBufSz * sizeof ( real_T ) ) ; if (
tempU == ( NULL ) ) { return ( false ) ; } tempT = tempU + newBufSz ; if (
istransportdelay ) tempX = tempT + newBufSz ; for ( j = tail ; j < bufSz ; j
++ ) { tempT [ j - tail ] = tBuf [ j ] ; tempU [ j - tail ] = uBuf [ j ] ; if
( istransportdelay ) tempX [ j - tail ] = xBuf [ j ] ; } for ( j = 0 ; j <
tail ; j ++ ) { tempT [ j + bufSz - tail ] = tBuf [ j ] ; tempU [ j + bufSz -
tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j + bufSz - tail ] =
xBuf [ j ] ; } if ( * lastPtr > tail ) { * lastPtr -= tail ; } else { *
lastPtr += ( bufSz - tail ) ; } * tailPtr = 0 ; * headPtr = bufSz ; utFree (
uBuf ) ; * bufSzPtr = newBufSz ; * tBufPtr = tempT ; * uBufPtr = tempU ; if (
istransportdelay ) * xBufPtr = tempX ; } else { * tailPtr = testIdx ; }
return ( true ) ; } real_T pwm_analysis_acc_rt_TDelayInterpolate ( real_T
tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T bufSz ,
int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput ,
boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) { int_T i ;
real_T yout , t1 , t2 , u1 , u2 ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } real_T look1_pbinlxpw ( real_T
u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) { real_T frac ; uint32_T iRght ; uint32_T iLeft ;
uint32_T bpIdx ; uint32_T found ; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac
= ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [
maxIndex ] ) { bpIdx = prevIndex [ 0U ] ; iLeft = 0U ; iRght = maxIndex ;
found = 0U ; while ( found == 0U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght =
bpIdx - 1U ; bpIdx = ( iRght + iLeft ) >> 1U ; } else if ( u0 < bp0 [ bpIdx +
1U ] ) { found = 1U ; } else { iLeft = bpIdx + 1U ; bpIdx = ( iRght + iLeft )
>> 1U ; } } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [
bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex -
1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; } prevIndex [ 0U ] =
bpIdx ; return ( table [ bpIdx + 1U ] - table [ bpIdx ] ) * frac + table [
bpIdx ] ; } void rt_ssGetBlockPath ( SimStruct * S , int_T sysIdx , int_T
blkIdx , char_T * * path ) { _ssGetBlockPath ( S , sysIdx , blkIdx , path ) ;
} void rt_ssSet_slErrMsg ( SimStruct * S , void * diag ) { if ( !
_ssIsErrorStatusAslErrMsg ( S ) ) { _ssSet_slErrMsg ( S , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( SimStruct * S , void * diag ) {
_ssReportDiagnosticAsWarning ( S , diag ) ; } void pwm_analysis_RMS_Init (
SimStruct * S , DW_RMS_pwm_analysis_T * localDW , P_RMS_pwm_analysis_T *
localP , X_RMS_pwm_analysis_T * localX ) { localX -> integrator_CSTATE_ov =
localP -> P_2 ; localDW -> Memory_PreviousInput = localP -> P_6 ; localX ->
integrator_CSTATE_gh = localP -> P_7 ; localDW -> Memory_PreviousInput_p =
localP -> P_11 ; } void pwm_analysis_RMS_Disable ( SimStruct * S ,
DW_RMS_pwm_analysis_T * localDW ) { localDW -> RMS_MODE = false ; } void
pwm_analysis_RMS ( SimStruct * S , boolean_T rtu_Enable , real_T rtu_In ,
B_RMS_pwm_analysis_T * localB , DW_RMS_pwm_analysis_T * localDW ,
P_RMS_pwm_analysis_T * localP , X_RMS_pwm_analysis_T * localX ) { real_T
B_17_1_0 ; real_T B_17_9_0 ; real_T rtb_B_17_2_0 ; boolean_T rtb_B_17_4_0 ;
real_T rtb_B_17_10_0 ; boolean_T rtb_B_17_12_0 ; int32_T isHit ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( rtu_Enable ) { if ( ! localDW -> RMS_MODE ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } localDW -> RMS_MODE =
true ; } } else { if ( localDW -> RMS_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; pwm_analysis_RMS_Disable (
S , localDW ) ; } } } if ( localDW -> RMS_MODE ) { isHit = ssIsContinuousTask
( S , 0 ) ; if ( isHit != 0 ) { localB -> B_17_0_0 = localX ->
integrator_CSTATE_ov ; { real_T * * uBuffer = ( real_T * * ) & localDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * *
) & localDW -> TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - localP -> P_3 ; B_17_1_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , localDW -> TransportDelay_IWORK . CircularBufSize , & localDW ->
TransportDelay_IWORK . Last , localDW -> TransportDelay_IWORK . Tail ,
localDW -> TransportDelay_IWORK . Head , localP -> P_4 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_17_2_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { localB -> B_17_3_0 = localP -> P_5 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_17_4_0 = (
rtb_B_17_2_0 >= localB -> B_17_3_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { localB -> B_17_5_0 = localDW -> Memory_PreviousInput ;
} isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_17_4_0 ) { localB -> B_17_7_0 = ( localB -> B_17_0_0 - B_17_1_0 ) *
localP -> P_1 ; } else { localB -> B_17_7_0 = localB -> B_17_5_0 ; } localB
-> B_17_8_0 = localX -> integrator_CSTATE_gh ; { real_T * * uBuffer = (
real_T * * ) & localDW -> TransportDelay_PWORK_n . TUbufferPtrs [ 0 ] ;
real_T * * tBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK_n .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - localP -> P_8 ; B_17_9_0 = pwm_analysis_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , localDW -> TransportDelay_IWORK_m
. CircularBufSize , & localDW -> TransportDelay_IWORK_m . Last , localDW ->
TransportDelay_IWORK_m . Tail , localDW -> TransportDelay_IWORK_m . Head ,
localP -> P_9 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } rtb_B_17_10_0 = ssGetT
( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localB ->
B_17_11_0 = localP -> P_10 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { rtb_B_17_12_0 = ( rtb_B_17_10_0 >= localB -> B_17_11_0 ) ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localB -> B_17_13_0
= localDW -> Memory_PreviousInput_p ; } isHit = ssIsContinuousTask ( S , 0 )
; if ( isHit != 0 ) { if ( rtb_B_17_12_0 ) { localB -> B_17_15_0 = ( localB
-> B_17_8_0 - B_17_9_0 ) * localP -> P_0 ; } else { localB -> B_17_15_0 =
localB -> B_17_13_0 ; } localB -> B_17_19_0 = ( muDoubleScalarSin ( localP ->
P_14 * ssGetTaskTime ( S , 0 ) + localP -> P_15 ) * localP -> P_12 + localP
-> P_13 ) * rtu_In ; localB -> B_17_21_0 = ( muDoubleScalarSin ( localP ->
P_18 * ssGetTaskTime ( S , 0 ) + localP -> P_19 ) * localP -> P_16 + localP
-> P_17 ) * rtu_In ; localB -> B_17_22_0 = localP -> P_20 *
muDoubleScalarHypot ( localB -> B_17_7_0 , localB -> B_17_15_0 ) ; } if (
ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( localDW -> RMS_SubsysRanBC ) ;
} } } void pwm_analysis_RMS_Update ( SimStruct * S , B_RMS_pwm_analysis_T *
localB , DW_RMS_pwm_analysis_T * localDW , P_RMS_pwm_analysis_T * localP ) {
int32_T isHit ; if ( localDW -> RMS_MODE ) { isHit = ssIsContinuousTask ( S ,
0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = ( real_T * * ) & localDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * *
) & localDW -> TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; localDW -> TransportDelay_IWORK . Head = ( ( localDW ->
TransportDelay_IWORK . Head < ( localDW -> TransportDelay_IWORK .
CircularBufSize - 1 ) ) ? ( localDW -> TransportDelay_IWORK . Head + 1 ) : 0
) ; if ( localDW -> TransportDelay_IWORK . Head == localDW ->
TransportDelay_IWORK . Tail ) { if ( !
pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize , & localDW -> TransportDelay_IWORK .
Tail , & localDW -> TransportDelay_IWORK . Head , & localDW ->
TransportDelay_IWORK . Last , simTime - localP -> P_3 , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & localDW -> TransportDelay_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ localDW -> TransportDelay_IWORK . Head ] =
simTime ; ( * uBuffer ) [ localDW -> TransportDelay_IWORK . Head ] = localB
-> B_17_0_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
localDW -> Memory_PreviousInput = localB -> B_17_7_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & localDW -> TransportDelay_PWORK_n . TUbufferPtrs [ 0 ] ;
real_T * * tBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK_n .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; localDW ->
TransportDelay_IWORK_m . Head = ( ( localDW -> TransportDelay_IWORK_m . Head
< ( localDW -> TransportDelay_IWORK_m . CircularBufSize - 1 ) ) ? ( localDW
-> TransportDelay_IWORK_m . Head + 1 ) : 0 ) ; if ( localDW ->
TransportDelay_IWORK_m . Head == localDW -> TransportDelay_IWORK_m . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK_m . CircularBufSize , & localDW ->
TransportDelay_IWORK_m . Tail , & localDW -> TransportDelay_IWORK_m . Head ,
& localDW -> TransportDelay_IWORK_m . Last , simTime - localP -> P_8 ,
tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & localDW ->
TransportDelay_IWORK_m . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ localDW ->
TransportDelay_IWORK_m . Head ] = simTime ; ( * uBuffer ) [ localDW ->
TransportDelay_IWORK_m . Head ] = localB -> B_17_8_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localDW ->
Memory_PreviousInput_p = localB -> B_17_15_0 ; } } } void
pwm_analysis_RMS_Deriv ( SimStruct * S , B_RMS_pwm_analysis_T * localB ,
DW_RMS_pwm_analysis_T * localDW , XDot_RMS_pwm_analysis_T * localXdot ) { if
( localDW -> RMS_MODE ) { localXdot -> integrator_CSTATE_ov = localB ->
B_17_19_0 ; localXdot -> integrator_CSTATE_gh = localB -> B_17_21_0 ; } else
{ { real_T * dx ; int_T i ; dx = & ( localXdot -> integrator_CSTATE_ov ) ;
for ( i = 0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } } } } void
pwm_analysis_RMS_Term ( SimStruct * const S ) { } void
pwm_analysis_TrueRMS_Init ( SimStruct * S , DW_TrueRMS_pwm_analysis_T *
localDW , P_TrueRMS_pwm_analysis_T * localP , X_TrueRMS_pwm_analysis_T *
localX ) { localX -> integrator_CSTATE_h = localP -> P_1 ; localDW ->
Memory_PreviousInput = localP -> P_5 ; } void pwm_analysis_TrueRMS_Disable (
SimStruct * S , DW_TrueRMS_pwm_analysis_T * localDW ) { localDW ->
TrueRMS_MODE = false ; } void pwm_analysis_TrueRMS ( SimStruct * S ,
boolean_T rtu_Enable , real_T rtu_In , B_TrueRMS_pwm_analysis_T * localB ,
DW_TrueRMS_pwm_analysis_T * localDW , P_TrueRMS_pwm_analysis_T * localP ,
X_TrueRMS_pwm_analysis_T * localX ) { real_T B_19_2_0 ; real_T rtb_B_19_0_0 ;
int32_T isHit ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) &&
( ssIsMajorTimeStep ( S ) != 0 ) ) { if ( rtu_Enable ) { if ( ! localDW ->
TrueRMS_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } localDW -> TrueRMS_MODE
= true ; } } else { if ( localDW -> TrueRMS_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
pwm_analysis_TrueRMS_Disable ( S , localDW ) ; } } } if ( localDW ->
TrueRMS_MODE ) { isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) {
rtb_B_19_0_0 = ssGetT ( S ) ; localB -> B_19_1_0 = localX ->
integrator_CSTATE_h ; { real_T * * uBuffer = ( real_T * * ) & localDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * *
) & localDW -> TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - localP -> P_2 ; B_19_2_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , localDW -> TransportDelay_IWORK . CircularBufSize , & localDW ->
TransportDelay_IWORK . Last , localDW -> TransportDelay_IWORK . Tail ,
localDW -> TransportDelay_IWORK . Head , localP -> P_3 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localB ->
B_19_3_0 = localP -> P_4 ; localB -> B_19_4_0 = localDW ->
Memory_PreviousInput ; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit !=
0 ) { if ( rtb_B_19_0_0 >= localB -> B_19_3_0 ) { localB -> B_19_7_0 = (
localB -> B_19_1_0 - B_19_2_0 ) * localP -> P_0 ; } else { localB -> B_19_7_0
= localB -> B_19_4_0 ; } localB -> B_19_8_0 = rtu_In * rtu_In ; if ( localB
-> B_19_7_0 > localP -> P_6 ) { rtb_B_19_0_0 = localP -> P_6 ; } else if (
localB -> B_19_7_0 < localP -> P_7 ) { rtb_B_19_0_0 = localP -> P_7 ; } else
{ rtb_B_19_0_0 = localB -> B_19_7_0 ; } localB -> B_19_10_0 =
muDoubleScalarSqrt ( rtb_B_19_0_0 ) ; } if ( ssIsMajorTimeStep ( S ) != 0 ) {
srUpdateBC ( localDW -> TrueRMS_SubsysRanBC ) ; } } } void
pwm_analysis_TrueRMS_Update ( SimStruct * S , B_TrueRMS_pwm_analysis_T *
localB , DW_TrueRMS_pwm_analysis_T * localDW , P_TrueRMS_pwm_analysis_T *
localP ) { int32_T isHit ; if ( localDW -> TrueRMS_MODE ) { isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & localDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; localDW -> TransportDelay_IWORK .
Head = ( ( localDW -> TransportDelay_IWORK . Head < ( localDW ->
TransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( localDW ->
TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( localDW ->
TransportDelay_IWORK . Head == localDW -> TransportDelay_IWORK . Tail ) { if
( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize , & localDW -> TransportDelay_IWORK .
Tail , & localDW -> TransportDelay_IWORK . Head , & localDW ->
TransportDelay_IWORK . Last , simTime - localP -> P_2 , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & localDW -> TransportDelay_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ localDW -> TransportDelay_IWORK . Head ] =
simTime ; ( * uBuffer ) [ localDW -> TransportDelay_IWORK . Head ] = localB
-> B_19_1_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
localDW -> Memory_PreviousInput = localB -> B_19_7_0 ; } } } void
pwm_analysis_TrueRMS_Deriv ( SimStruct * S , B_TrueRMS_pwm_analysis_T *
localB , DW_TrueRMS_pwm_analysis_T * localDW , XDot_TrueRMS_pwm_analysis_T *
localXdot ) { if ( localDW -> TrueRMS_MODE ) { localXdot ->
integrator_CSTATE_h = localB -> B_19_8_0 ; } else { localXdot ->
integrator_CSTATE_h = 0.0 ; } } void pwm_analysis_TrueRMS_Term ( SimStruct *
const S ) { } static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T
B_75_61_0 ; real_T B_75_74_0 ; real_T B_75_82_0 ; real_T B_75_93_0 ; real_T
B_75_102_0 ; real_T B_75_113_0 ; real_T B_75_125_0 ; real_T B_75_133_0 ;
real_T B_75_144_0 ; real_T B_75_152_0 ; real_T B_75_163_0 ; real_T B_75_171_0
; real_T B_75_200_0 ; real_T B_75_289_0 ; real_T B_75_329_0 ; real_T
B_75_409_0 ; real_T rtb_B_75_3_0 ; real_T rtb_B_75_5_0 ; real_T rtb_B_75_9_0
; boolean_T rtb_B_75_19_0 ; boolean_T rtb_B_75_23_0 ; boolean_T rtb_B_75_27_0
; real_T rtb_B_75_62_0 ; boolean_T rtb_B_75_64_0 ; real_T rtb_B_75_75_0 ;
boolean_T rtb_B_75_77_0 ; real_T rtb_B_75_83_0 ; boolean_T rtb_B_75_85_0 ;
real_T rtb_B_75_94_0 ; boolean_T rtb_B_75_96_0 ; real_T rtb_B_75_103_0 ;
boolean_T rtb_B_75_105_0 ; real_T rtb_B_75_114_0 ; boolean_T rtb_B_75_116_0 ;
real_T rtb_B_75_126_0 ; boolean_T rtb_B_75_128_0 ; real_T rtb_B_75_134_0 ;
boolean_T rtb_B_75_136_0 ; real_T rtb_B_75_145_0 ; boolean_T rtb_B_75_147_0 ;
real_T rtb_B_75_153_0 ; boolean_T rtb_B_75_155_0 ; real_T rtb_B_75_164_0 ;
boolean_T rtb_B_75_166_0 ; real_T rtb_B_75_172_0 ; boolean_T rtb_B_75_174_0 ;
real_T rtb_B_75_201_0 ; boolean_T rtb_B_75_203_0 ; real_T rtb_B_75_286_0 ;
real_T rtb_B_75_290_0 ; boolean_T rtb_B_75_292_0 ; real_T rtb_B_75_296_0 ;
real_T rtb_B_75_326_0 ; real_T rtb_B_75_330_0 ; boolean_T rtb_B_75_332_0 ;
real_T rtb_B_75_336_0 ; real_T rtb_B_75_406_0 ; real_T rtb_B_75_410_0 ;
boolean_T rtb_B_75_412_0 ; real_T rtb_B_75_416_0 ; real_T rtb_B_75_2_0 ;
real_T rtb_B_75_22_0 ; real_T rtb_B_75_26_0 ; real_T rtb_RealImagtoComplex_re
; int32_T isHit ; B_pwm_analysis_T * _rtB ; P_pwm_analysis_T * _rtP ;
X_pwm_analysis_T * _rtX ; DW_pwm_analysis_T * _rtDW ; _rtDW = ( (
DW_pwm_analysis_T * ) ssGetRootDWork ( S ) ) ; _rtX = ( ( X_pwm_analysis_T *
) ssGetContStates ( S ) ) ; _rtP = ( ( P_pwm_analysis_T * ) ssGetModelRtp ( S
) ) ; _rtB = ( ( B_pwm_analysis_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 1 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsContinuousTask ( S , 0 ) ; if
( isHit != 0 ) { rtb_B_75_2_0 = muDoubleScalarSin ( _rtP -> P_41 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_42 ) * _rtP -> P_39 + _rtP -> P_40 ;
rtb_B_75_3_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_75_4_0 = _rtP -> P_43 ; } isHit = ssIsContinuousTask
( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_5_0 = rtb_B_75_3_0 + _rtB ->
B_75_4_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_75_6_0 = _rtP -> P_44 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { rtb_B_75_9_0 = look1_pbinlxpw ( _rtP -> P_45 *
muDoubleScalarRem ( rtb_B_75_5_0 , _rtB -> B_75_6_0 ) , _rtP -> P_47 , _rtP
-> P_46 , & _rtDW -> m_bpIndex , 2U ) ; } isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { _rtB -> B_75_10_0 = _rtP -> P_48 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_14_0 = ( (
rtb_B_75_9_0 - _rtB -> B_75_10_0 ) + _rtB -> B_75_12_0 ) * _rtP -> P_50 ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_15_0 =
_rtDW -> Delay_DSTATE ; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_75_16_0 = ssGetT ( S ) ; ssCallAccelRunBlock ( S , 74 , 0
, SS_CALL_MDL_OUTPUTS ) ; rtb_B_75_19_0 = ( _rtB -> B_74_0_1 != 0.0 ) ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_20_0 =
_rtDW -> ICic_PreviousInput ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_75_19_0 ) { _rtB -> B_75_21_0 = rtb_B_75_2_0 ; }
else { _rtB -> B_75_21_0 = _rtB -> B_75_20_0 ; } rtb_B_75_22_0 =
muDoubleScalarSin ( _rtP -> P_56 * ssGetTaskTime ( S , 0 ) + _rtP -> P_57 ) *
_rtP -> P_54 + _rtP -> P_55 ; rtb_B_75_23_0 = ( _rtB -> B_74_0_1 != 0.0 ) ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_24_0 =
_rtDW -> ICic_PreviousInput_i ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_75_23_0 ) { _rtB -> B_75_25_0 = rtb_B_75_22_0 ; }
else { _rtB -> B_75_25_0 = _rtB -> B_75_24_0 ; } rtb_B_75_26_0 =
muDoubleScalarSin ( _rtP -> P_61 * ssGetTaskTime ( S , 0 ) + _rtP -> P_62 ) *
_rtP -> P_59 + _rtP -> P_60 ; rtb_B_75_27_0 = ( _rtB -> B_74_0_1 != 0.0 ) ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_28_0 =
_rtDW -> ICic_PreviousInput_g ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_75_27_0 ) { _rtB -> B_75_29_0 = rtb_B_75_26_0 ; }
else { _rtB -> B_75_29_0 = _rtB -> B_75_28_0 ; } } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 75 , 30 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_75_31_0 = _rtDW -> Delay1_DSTATE ; _rtB ->
B_75_32_0 = _rtDW -> Delay2_DSTATE ; _rtB -> B_75_33_0 = _rtDW ->
Delay3_DSTATE ; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 8 , 0 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 35 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsContinuousTask ( S , 0 ) ; if
( isHit != 0 ) { ssCallAccelRunBlock ( S , 9 , 0 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_75_37_0 = _rtB -> B_9_0_1 - _rtB -> B_9_0_3 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 38 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 75 , 39 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_75_49_0 = _rtP -> P_67 * _rtB -> B_75_1_0 [
12 ] ; } pwm_analysis_TrueRMS ( S , _rtB -> B_75_51_0 , _rtB -> B_75_49_0 , &
_rtB -> TrueRMS , & _rtDW -> TrueRMS , & _rtP -> TrueRMS , & _rtX -> TrueRMS
) ; pwm_analysis_RMS ( S , _rtB -> B_75_53_0 , _rtB -> B_75_49_0 , & _rtB ->
RMS , & _rtDW -> RMS , & _rtP -> RMS , & _rtX -> RMS ) ; isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( _rtB -> B_75_51_0 ) {
_rtB -> B_75_55_0 = _rtB -> TrueRMS . B_19_10_0 ; } else { _rtB -> B_75_55_0
= _rtB -> RMS . B_17_22_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { ssCallAccelRunBlock ( S , 75 , 56 , SS_CALL_MDL_OUTPUTS ) ; }
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_60_0
= _rtX -> integrator_CSTATE ; { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_70 ; B_75_61_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , _rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail , _rtDW ->
TransportDelay_IWORK . Head , _rtP -> P_71 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_62_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_63_0 = _rtP -> P_72 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_64_0 = (
rtb_B_75_62_0 >= _rtB -> B_75_63_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { _rtB -> B_75_65_0 = _rtDW -> Memory_PreviousInput ; }
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_75_64_0
) { _rtB -> B_75_67_0 = ( _rtB -> B_75_60_0 - B_75_61_0 ) * _rtP -> P_8 ; }
else { _rtB -> B_75_67_0 = _rtB -> B_75_65_0 ; } } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 75 , 68 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_75_69_0 = _rtP -> P_74 * _rtB -> B_75_1_0 [
10 ] ; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_75_73_0 = _rtX -> integrator_CSTATE_e ; { real_T * * uBuffer = ( real_T * *
) & _rtDW -> TransportDelay_PWORK_h . TUbufferPtrs [ 0 ] ; real_T * * tBuffer
= ( real_T * * ) & _rtDW -> TransportDelay_PWORK_h . TUbufferPtrs [ 1 ] ;
real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_76 ;
B_75_74_0 = pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_p . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_p . Last , _rtDW -> TransportDelay_IWORK_p .
Tail , _rtDW -> TransportDelay_IWORK_p . Head , _rtP -> P_77 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } rtb_B_75_75_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_76_0 = _rtP -> P_78 ; }
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_77_0 = (
rtb_B_75_75_0 >= _rtB -> B_75_76_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { _rtB -> B_75_78_0 = _rtDW -> Memory_PreviousInput_k ; }
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_75_77_0
) { _rtB -> B_75_80_0 = ( _rtB -> B_75_73_0 - B_75_74_0 ) * _rtP -> P_7 ; }
else { _rtB -> B_75_80_0 = _rtB -> B_75_78_0 ; } _rtB -> B_75_81_0 = _rtX ->
integrator_CSTATE_g ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_81 ; B_75_82_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , _rtDW -> TransportDelay_IWORK_l . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_l . Last , _rtDW -> TransportDelay_IWORK_l . Tail ,
_rtDW -> TransportDelay_IWORK_l . Head , _rtP -> P_82 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_83_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_84_0 = _rtP -> P_83 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_85_0 = (
rtb_B_75_83_0 >= _rtB -> B_75_84_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { _rtB -> B_75_86_0 = _rtDW -> Memory_PreviousInput_a ; }
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_75_85_0
) { _rtB -> B_75_88_0 = ( _rtB -> B_75_81_0 - B_75_82_0 ) * _rtP -> P_6 ; }
else { _rtB -> B_75_88_0 = _rtB -> B_75_86_0 ; } _rtB -> B_75_90_0 =
muDoubleScalarHypot ( _rtB -> B_75_80_0 , _rtB -> B_75_88_0 ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 91 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsContinuousTask ( S , 0 ) ; if
( isHit != 0 ) { _rtB -> B_75_92_0 = _rtX -> integrator_CSTATE_k ; { real_T *
* uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_i . TUbufferPtrs [
0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_i .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_86 ; B_75_93_0 = pwm_analysis_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_m .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_m . Last , _rtDW ->
TransportDelay_IWORK_m . Tail , _rtDW -> TransportDelay_IWORK_m . Head , _rtP
-> P_87 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } rtb_B_75_94_0 = ssGetT
( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_75_95_0 = _rtP -> P_88 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { rtb_B_75_96_0 = ( rtb_B_75_94_0 >= _rtB -> B_75_95_0 ) ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_97_0 =
_rtDW -> Memory_PreviousInput_l ; } isHit = ssIsContinuousTask ( S , 0 ) ; if
( isHit != 0 ) { if ( rtb_B_75_96_0 ) { _rtB -> B_75_99_0 = ( _rtB ->
B_75_92_0 - B_75_93_0 ) * _rtP -> P_9 ; } else { _rtB -> B_75_99_0 = _rtB ->
B_75_97_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 75 , 100 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_101_0 = _rtX
-> integrator_CSTATE_b ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_m . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_m . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_91 ; B_75_102_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , _rtDW -> TransportDelay_IWORK_c . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_c . Last , _rtDW -> TransportDelay_IWORK_c . Tail ,
_rtDW -> TransportDelay_IWORK_c . Head , _rtP -> P_92 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_103_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_104_0 = _rtP -> P_93 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_105_0 = (
rtb_B_75_103_0 >= _rtB -> B_75_104_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { _rtB -> B_75_106_0 = _rtDW -> Memory_PreviousInput_e
; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_75_105_0 ) { _rtB -> B_75_108_0 = ( _rtB -> B_75_101_0 - B_75_102_0 ) *
_rtP -> P_10 ; } else { _rtB -> B_75_108_0 = _rtB -> B_75_106_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 109 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsContinuousTask ( S , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_110_0 = _rtB -> B_75_99_0 + _rtB ->
B_75_108_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 75 , 111 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_112_0 = _rtX
-> integrator_CSTATE_a ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_b . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_96 ; B_75_113_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , _rtDW -> TransportDelay_IWORK_k . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_k . Last , _rtDW -> TransportDelay_IWORK_k . Tail ,
_rtDW -> TransportDelay_IWORK_k . Head , _rtP -> P_97 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_114_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_115_0 = _rtP -> P_98 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_116_0 = (
rtb_B_75_114_0 >= _rtB -> B_75_115_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { _rtB -> B_75_117_0 = _rtDW -> Memory_PreviousInput_k4
; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_75_116_0 ) { _rtB -> B_75_119_0 = ( _rtB -> B_75_112_0 - B_75_113_0 ) *
_rtP -> P_11 ; } else { _rtB -> B_75_119_0 = _rtB -> B_75_117_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 120 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsContinuousTask ( S , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_122_0 = _rtB -> B_75_110_0 / _rtB ->
B_75_119_0 * _rtP -> P_100 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { ssCallAccelRunBlock ( S , 75 , 123 , SS_CALL_MDL_OUTPUTS ) ; }
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_124_0
= _rtX -> integrator_CSTATE_i ; { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> TransportDelay_PWORK_a . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_a . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_102 ;
B_75_125_0 = pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_ml . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_ml . Last , _rtDW -> TransportDelay_IWORK_ml .
Tail , _rtDW -> TransportDelay_IWORK_ml . Head , _rtP -> P_103 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } rtb_B_75_126_0 = ssGetT ( S ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_127_0 = _rtP
-> P_104 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) {
rtb_B_75_128_0 = ( rtb_B_75_126_0 >= _rtB -> B_75_127_0 ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_129_0 = _rtDW
-> Memory_PreviousInput_ki ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_75_128_0 ) { _rtB -> B_75_131_0 = ( _rtB ->
B_75_124_0 - B_75_125_0 ) * _rtP -> P_1 ; } else { _rtB -> B_75_131_0 = _rtB
-> B_75_129_0 ; } _rtB -> B_75_132_0 = _rtX -> integrator_CSTATE_d ; { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_mw .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_mw . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S )
; real_T tMinusDelay = simTime - _rtP -> P_107 ; B_75_133_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , _rtDW -> TransportDelay_IWORK_i . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_i . Last , _rtDW -> TransportDelay_IWORK_i . Tail ,
_rtDW -> TransportDelay_IWORK_i . Head , _rtP -> P_108 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_134_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_135_0 = _rtP -> P_109 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_136_0 = (
rtb_B_75_134_0 >= _rtB -> B_75_135_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { _rtB -> B_75_137_0 = _rtDW -> Memory_PreviousInput_f
; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_75_136_0 ) { _rtB -> B_75_139_0 = ( _rtB -> B_75_132_0 - B_75_133_0 ) *
_rtP -> P_0 ; } else { _rtB -> B_75_139_0 = _rtB -> B_75_137_0 ; } _rtB ->
B_75_141_0 = muDoubleScalarHypot ( _rtB -> B_75_131_0 , _rtB -> B_75_139_0 )
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 75 , 142 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_143_0 = _rtX
-> integrator_CSTATE_p ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_mz . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & _rtDW -> TransportDelay_PWORK_mz . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_112 ;
B_75_144_0 = pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_is . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_is . Last , _rtDW -> TransportDelay_IWORK_is .
Tail , _rtDW -> TransportDelay_IWORK_is . Head , _rtP -> P_113 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } rtb_B_75_145_0 = ssGetT ( S ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_146_0 = _rtP
-> P_114 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) {
rtb_B_75_147_0 = ( rtb_B_75_145_0 >= _rtB -> B_75_146_0 ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_148_0 = _rtDW
-> Memory_PreviousInput_p ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_75_147_0 ) { _rtB -> B_75_150_0 = ( _rtB ->
B_75_143_0 - B_75_144_0 ) * _rtP -> P_3 ; } else { _rtB -> B_75_150_0 = _rtB
-> B_75_148_0 ; } _rtB -> B_75_151_0 = _rtX -> integrator_CSTATE_f ; { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_ba .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_ba . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S )
; real_T tMinusDelay = simTime - _rtP -> P_117 ; B_75_152_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , _rtDW -> TransportDelay_IWORK_n . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_n . Last , _rtDW -> TransportDelay_IWORK_n . Tail ,
_rtDW -> TransportDelay_IWORK_n . Head , _rtP -> P_118 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_153_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_154_0 = _rtP -> P_119 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_155_0 = (
rtb_B_75_153_0 >= _rtB -> B_75_154_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { _rtB -> B_75_156_0 = _rtDW -> Memory_PreviousInput_pj
; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_75_155_0 ) { _rtB -> B_75_158_0 = ( _rtB -> B_75_151_0 - B_75_152_0 ) *
_rtP -> P_2 ; } else { _rtB -> B_75_158_0 = _rtB -> B_75_156_0 ; } _rtB ->
B_75_160_0 = muDoubleScalarHypot ( _rtB -> B_75_150_0 , _rtB -> B_75_158_0 )
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 75 , 161 , SS_CALL_MDL_OUTPUTS ) ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_162_0 = _rtX
-> integrator_CSTATE_o ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_e . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_e . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_122 ; B_75_163_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , _rtDW -> TransportDelay_IWORK_o . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_o . Last , _rtDW -> TransportDelay_IWORK_o . Tail ,
_rtDW -> TransportDelay_IWORK_o . Head , _rtP -> P_123 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_164_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_165_0 = _rtP -> P_124 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_166_0 = (
rtb_B_75_164_0 >= _rtB -> B_75_165_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { _rtB -> B_75_167_0 = _rtDW -> Memory_PreviousInput_n
; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_75_166_0 ) { _rtB -> B_75_169_0 = ( _rtB -> B_75_162_0 - B_75_163_0 ) *
_rtP -> P_5 ; } else { _rtB -> B_75_169_0 = _rtB -> B_75_167_0 ; } _rtB ->
B_75_170_0 = _rtX -> integrator_CSTATE_m ; { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_f . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_f . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_127 ; B_75_171_0 = pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_p5 .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_p5 . Last , _rtDW ->
TransportDelay_IWORK_p5 . Tail , _rtDW -> TransportDelay_IWORK_p5 . Head ,
_rtP -> P_128 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } rtb_B_75_172_0 = ssGetT
( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_75_173_0 = _rtP -> P_129 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { rtb_B_75_174_0 = ( rtb_B_75_172_0 >= _rtB -> B_75_173_0 ) ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_175_0
= _rtDW -> Memory_PreviousInput_lp ; } isHit = ssIsContinuousTask ( S , 0 ) ;
if ( isHit != 0 ) { if ( rtb_B_75_174_0 ) { _rtB -> B_75_177_0 = ( _rtB ->
B_75_170_0 - B_75_171_0 ) * _rtP -> P_4 ; } else { _rtB -> B_75_177_0 = _rtB
-> B_75_175_0 ; } _rtB -> B_75_179_0 = muDoubleScalarHypot ( _rtB ->
B_75_169_0 , _rtB -> B_75_177_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 75 , 180 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 75 , 181 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 182 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 183 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_75_184_0 = _rtP -> P_131 * _rtB -> B_75_1_0 [ 9 ] ; _rtB -> B_75_185_0 =
_rtP -> P_132 * _rtB -> B_75_1_0 [ 11 ] ; _rtB -> B_75_186_0 = _rtB ->
B_75_184_0 * _rtB -> B_75_185_0 ; _rtB -> B_75_188_0 = _rtP -> P_134 * _rtB
-> B_75_1_0 [ 14 ] ; _rtB -> B_75_189_0 = _rtP -> P_133 * _rtB -> B_75_1_0 [
8 ] * _rtB -> B_75_188_0 ; _rtB -> B_75_190_0 = _rtB -> B_75_186_0 + _rtB ->
B_75_189_0 ; ssCallAccelRunBlock ( S , 75 , 191 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_75_194_0 = _rtP -> P_135 * _rtB -> B_75_1_0 [ 6 ] * ( _rtP -> P_136
* _rtB -> B_75_1_0 [ 15 ] ) ; ssCallAccelRunBlock ( S , 75 , 195 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_75_197_0 = _rtB -> B_75_190_0 / _rtB ->
B_75_194_0 * _rtP -> P_137 ; ssCallAccelRunBlock ( S , 75 , 198 ,
SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_75_199_0 = _rtX -> integrator_CSTATE_av ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_gg . TUbufferPtrs [
0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_gg
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_139 ; B_75_200_0 = pwm_analysis_acc_rt_TDelayInterpolate
( tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW ->
TransportDelay_IWORK_cf . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_cf . Last , _rtDW -> TransportDelay_IWORK_cf . Tail ,
_rtDW -> TransportDelay_IWORK_cf . Head , _rtP -> P_140 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_201_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_202_0 = _rtP -> P_141 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_203_0 = (
rtb_B_75_201_0 >= _rtB -> B_75_202_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { _rtB -> B_75_204_0 = _rtDW -> Memory_PreviousInput_aw
; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_75_203_0 ) { _rtB -> B_75_206_0 = ( _rtB -> B_75_199_0 - B_75_200_0 ) *
_rtP -> P_12 ; } else { _rtB -> B_75_206_0 = _rtB -> B_75_204_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 207 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_75_208_0 = _rtP -> P_143 * _rtB
-> B_75_1_0 [ 13 ] ; ssCallAccelRunBlock ( S , 75 , 209 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 75 , 210 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 211 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 212 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 213 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 214 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtDW ->
systemEnable != 0 ) { _rtDW -> lastSin = muDoubleScalarSin ( _rtP -> P_146 *
ssGetTaskTime ( S , 1 ) ) ; _rtDW -> lastCos = muDoubleScalarCos ( _rtP ->
P_146 * ssGetTaskTime ( S , 1 ) ) ; _rtDW -> systemEnable = 0 ; } _rtB ->
B_75_216_0 = ( ( ( _rtDW -> lastSin * _rtP -> P_150 + _rtDW -> lastCos * _rtP
-> P_149 ) * _rtP -> P_148 + ( _rtDW -> lastCos * _rtP -> P_150 - _rtDW ->
lastSin * _rtP -> P_149 ) * _rtP -> P_147 ) * _rtP -> P_144 + _rtP -> P_145 )
* _rtB -> B_75_185_0 ; if ( _rtDW -> Integ4_SYSTEM_ENABLE != 0 ) { _rtB ->
B_75_217_0 = _rtDW -> Integ4_DSTATE ; } else { _rtB -> B_75_217_0 = _rtP ->
P_151 * _rtB -> B_75_216_0 + _rtDW -> Integ4_DSTATE ; } _rtB -> B_75_218_0 =
_rtP -> P_153 ; ssCallAccelRunBlock ( S , 75 , 219 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssGetTaskTime ( S , 1 ) >= _rtB -> B_75_218_0 ) { _rtB -> B_75_226_0 = (
_rtB -> B_75_217_0 - _rtB -> B_75_219_0 ) * _rtP -> P_162 + ( _rtP -> P_20 *
_rtB -> B_75_216_0 - _rtP -> P_19 * _rtDW -> UnitDelay_DSTATE ) ; } else {
_rtB -> B_75_226_0 = _rtDW -> UnitDelay1_DSTATE ; } if ( _rtDW ->
systemEnable_l != 0 ) { _rtDW -> lastSin_e = muDoubleScalarSin ( _rtP ->
P_167 * ssGetTaskTime ( S , 1 ) ) ; _rtDW -> lastCos_k = muDoubleScalarCos (
_rtP -> P_167 * ssGetTaskTime ( S , 1 ) ) ; _rtDW -> systemEnable_l = 0 ; }
_rtB -> B_75_228_0 = ( ( ( _rtDW -> lastSin_e * _rtP -> P_171 + _rtDW ->
lastCos_k * _rtP -> P_170 ) * _rtP -> P_169 + ( _rtDW -> lastCos_k * _rtP ->
P_171 - _rtDW -> lastSin_e * _rtP -> P_170 ) * _rtP -> P_168 ) * _rtP ->
P_165 + _rtP -> P_166 ) * _rtB -> B_75_185_0 ; if ( _rtDW ->
Integ4_SYSTEM_ENABLE_j != 0 ) { _rtB -> B_75_229_0 = _rtDW -> Integ4_DSTATE_j
; } else { _rtB -> B_75_229_0 = _rtP -> P_172 * _rtB -> B_75_228_0 + _rtDW ->
Integ4_DSTATE_j ; } _rtB -> B_75_230_0 = _rtP -> P_174 ; ssCallAccelRunBlock
( S , 75 , 231 , SS_CALL_MDL_OUTPUTS ) ; if ( ssGetTaskTime ( S , 1 ) >= _rtB
-> B_75_230_0 ) { _rtB -> B_75_238_0 = ( _rtB -> B_75_229_0 - _rtB ->
B_75_231_0 ) * _rtP -> P_183 + ( _rtP -> P_18 * _rtB -> B_75_228_0 - _rtP ->
P_17 * _rtDW -> UnitDelay_DSTATE_j ) ; } else { _rtB -> B_75_238_0 = _rtDW ->
UnitDelay1_DSTATE_a ; } rtb_RealImagtoComplex_re = _rtB -> B_75_226_0 ;
rtb_B_75_2_0 = _rtB -> B_75_238_0 ; _rtB -> B_75_241_0 = _rtP -> P_186 *
muDoubleScalarAtan2 ( _rtB -> B_75_238_0 , _rtB -> B_75_226_0 ) ;
ssCallAccelRunBlock ( S , 75 , 242 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_75_244_0 = _rtB -> B_75_241_0 + _rtB -> B_75_243_0 ; ssCallAccelRunBlock (
S , 75 , 245 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_75_246_0 = _rtP -> P_188 *
muDoubleScalarHypot ( rtb_RealImagtoComplex_re , rtb_B_75_2_0 ) ;
ssCallAccelRunBlock ( S , 75 , 247 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtDW ->
systemEnable_g != 0 ) { _rtDW -> lastSin_f = muDoubleScalarSin ( _rtP ->
P_191 * ssGetTaskTime ( S , 1 ) ) ; _rtDW -> lastCos_p = muDoubleScalarCos (
_rtP -> P_191 * ssGetTaskTime ( S , 1 ) ) ; _rtDW -> systemEnable_g = 0 ; }
_rtB -> B_75_249_0 = ( ( ( _rtDW -> lastSin_f * _rtP -> P_195 + _rtDW ->
lastCos_p * _rtP -> P_194 ) * _rtP -> P_193 + ( _rtDW -> lastCos_p * _rtP ->
P_195 - _rtDW -> lastSin_f * _rtP -> P_194 ) * _rtP -> P_192 ) * _rtP ->
P_189 + _rtP -> P_190 ) * _rtB -> B_75_184_0 ; if ( _rtDW ->
Integ4_SYSTEM_ENABLE_b != 0 ) { _rtB -> B_75_250_0 = _rtDW -> Integ4_DSTATE_k
; } else { _rtB -> B_75_250_0 = _rtP -> P_196 * _rtB -> B_75_249_0 + _rtDW ->
Integ4_DSTATE_k ; } _rtB -> B_75_251_0 = _rtP -> P_198 ; ssCallAccelRunBlock
( S , 75 , 252 , SS_CALL_MDL_OUTPUTS ) ; if ( ssGetTaskTime ( S , 1 ) >= _rtB
-> B_75_251_0 ) { _rtB -> B_75_259_0 = ( _rtB -> B_75_250_0 - _rtB ->
B_75_252_0 ) * _rtP -> P_207 + ( _rtP -> P_16 * _rtB -> B_75_249_0 - _rtP ->
P_15 * _rtDW -> UnitDelay_DSTATE_k ) ; } else { _rtB -> B_75_259_0 = _rtDW ->
UnitDelay1_DSTATE_b ; } if ( _rtDW -> systemEnable_ld != 0 ) { _rtDW ->
lastSin_ej = muDoubleScalarSin ( _rtP -> P_212 * ssGetTaskTime ( S , 1 ) ) ;
_rtDW -> lastCos_a = muDoubleScalarCos ( _rtP -> P_212 * ssGetTaskTime ( S ,
1 ) ) ; _rtDW -> systemEnable_ld = 0 ; } _rtB -> B_75_261_0 = ( ( ( _rtDW ->
lastSin_ej * _rtP -> P_216 + _rtDW -> lastCos_a * _rtP -> P_215 ) * _rtP ->
P_214 + ( _rtDW -> lastCos_a * _rtP -> P_216 - _rtDW -> lastSin_ej * _rtP ->
P_215 ) * _rtP -> P_213 ) * _rtP -> P_210 + _rtP -> P_211 ) * _rtB ->
B_75_184_0 ; if ( _rtDW -> Integ4_SYSTEM_ENABLE_d != 0 ) { _rtB -> B_75_262_0
= _rtDW -> Integ4_DSTATE_a ; } else { _rtB -> B_75_262_0 = _rtP -> P_217 *
_rtB -> B_75_261_0 + _rtDW -> Integ4_DSTATE_a ; } _rtB -> B_75_263_0 = _rtP
-> P_219 ; ssCallAccelRunBlock ( S , 75 , 264 , SS_CALL_MDL_OUTPUTS ) ; if (
ssGetTaskTime ( S , 1 ) >= _rtB -> B_75_263_0 ) { _rtB -> B_75_271_0 = ( _rtB
-> B_75_262_0 - _rtB -> B_75_264_0 ) * _rtP -> P_228 + ( _rtP -> P_14 * _rtB
-> B_75_261_0 - _rtP -> P_13 * _rtDW -> UnitDelay_DSTATE_n ) ; } else { _rtB
-> B_75_271_0 = _rtDW -> UnitDelay1_DSTATE_a0 ; } rtb_RealImagtoComplex_re =
muDoubleScalarAtan2 ( _rtB -> B_75_271_0 , _rtB -> B_75_259_0 ) ; _rtB ->
B_75_274_0 = _rtP -> P_231 * muDoubleScalarHypot ( _rtB -> B_75_259_0 , _rtB
-> B_75_271_0 ) ; _rtB -> B_75_276_0 = _rtB -> B_75_274_0 * _rtB ->
B_75_246_0 * _rtP -> P_232 ; _rtB -> B_75_278_0 = muDoubleScalarCos ( _rtP ->
P_233 * _rtB -> B_75_244_0 ) ; _rtB -> B_75_279_0 = _rtB -> B_75_276_0 * _rtB
-> B_75_278_0 ; ssCallAccelRunBlock ( S , 75 , 280 , SS_CALL_MDL_OUTPUTS ) ;
} pwm_analysis_TrueRMS ( S , _rtB -> B_75_282_0 , _rtB -> B_75_185_0 , & _rtB
-> TrueRMS_a , & _rtDW -> TrueRMS_a , & _rtP -> TrueRMS_a , & _rtX ->
TrueRMS_a ) ; pwm_analysis_RMS ( S , _rtB -> B_75_284_0 , _rtB -> B_75_185_0
, & _rtB -> RMS_d , & _rtDW -> RMS_d , & _rtP -> RMS_d , & _rtX -> RMS_d ) ;
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( _rtB ->
B_75_282_0 ) { rtb_B_75_286_0 = _rtB -> TrueRMS_a . B_19_10_0 ; } else {
rtb_B_75_286_0 = _rtB -> RMS_d . B_17_22_0 ; } rtb_B_75_286_0 *=
rtb_B_75_286_0 ; _rtB -> B_75_288_0 = _rtX -> integrator_CSTATE_fs ; { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_n . TUbufferPtrs
[ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_n
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_236 ; B_75_289_0 = pwm_analysis_acc_rt_TDelayInterpolate
( tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_a
. CircularBufSize , & _rtDW -> TransportDelay_IWORK_a . Last , _rtDW ->
TransportDelay_IWORK_a . Tail , _rtDW -> TransportDelay_IWORK_a . Head , _rtP
-> P_237 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } rtb_B_75_290_0 = ssGetT
( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_75_291_0 = _rtP -> P_238 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { rtb_B_75_292_0 = ( rtb_B_75_290_0 >= _rtB -> B_75_291_0 ) ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_293_0
= _rtDW -> Memory_PreviousInput_d ; } isHit = ssIsContinuousTask ( S , 0 ) ;
if ( isHit != 0 ) { if ( rtb_B_75_292_0 ) { _rtB -> B_75_295_0 = ( _rtB ->
B_75_288_0 - B_75_289_0 ) * _rtP -> P_26 ; } else { _rtB -> B_75_295_0 = _rtB
-> B_75_293_0 ; } rtb_B_75_296_0 = _rtB -> B_75_295_0 * _rtB -> B_75_295_0 ;
} pwm_analysis_TrueRMS ( S , _rtB -> B_75_298_0 , _rtB -> B_75_185_0 , & _rtB
-> TrueRMS_p , & _rtDW -> TrueRMS_p , & _rtP -> TrueRMS_p , & _rtX ->
TrueRMS_p ) ; pwm_analysis_RMS ( S , _rtB -> B_75_300_0 , _rtB -> B_75_185_0
, & _rtB -> RMS_j , & _rtDW -> RMS_j , & _rtP -> RMS_j , & _rtX -> RMS_j ) ;
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( _rtB ->
B_75_298_0 ) { rtb_B_75_2_0 = _rtB -> TrueRMS_p . B_19_10_0 ; } else {
rtb_B_75_2_0 = _rtB -> RMS_j . B_17_22_0 ; } rtb_B_75_2_0 *= rtb_B_75_2_0 ;
if ( rtb_B_75_2_0 > _rtP -> P_241 ) { rtb_B_75_290_0 = _rtP -> P_241 ; } else
if ( rtb_B_75_2_0 < _rtP -> P_242 ) { rtb_B_75_290_0 = _rtP -> P_242 ; } else
{ rtb_B_75_290_0 = rtb_B_75_2_0 ; } rtb_B_75_296_0 = ( ( rtb_B_75_286_0 -
rtb_B_75_296_0 ) - rtb_B_75_2_0 ) / rtb_B_75_290_0 ; if ( rtb_B_75_296_0 >
_rtP -> P_243 ) { rtb_B_75_296_0 = _rtP -> P_243 ; } else { if (
rtb_B_75_296_0 < _rtP -> P_244 ) { rtb_B_75_296_0 = _rtP -> P_244 ; } } _rtB
-> B_75_309_0 = _rtP -> P_245 * muDoubleScalarSqrt ( rtb_B_75_296_0 ) ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock
( S , 75 , 310 , SS_CALL_MDL_OUTPUTS ) ; } pwm_analysis_TrueRMS ( S , _rtB ->
B_75_312_0 , _rtB -> B_75_185_0 , & _rtB -> TrueRMS_i , & _rtDW -> TrueRMS_i
, & _rtP -> TrueRMS_i , & _rtX -> TrueRMS_i ) ; pwm_analysis_RMS ( S , _rtB
-> B_75_314_0 , _rtB -> B_75_185_0 , & _rtB -> RMS_lk , & _rtDW -> RMS_lk , &
_rtP -> RMS_lk , & _rtX -> RMS_lk ) ; isHit = ssIsContinuousTask ( S , 0 ) ;
if ( isHit != 0 ) { if ( _rtB -> B_75_312_0 ) { _rtB -> B_75_316_0 = _rtB ->
TrueRMS_i . B_19_10_0 ; } else { _rtB -> B_75_316_0 = _rtB -> RMS_lk .
B_17_22_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 75 , 317 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 318 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 319 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 320 , SS_CALL_MDL_OUTPUTS ) ; }
pwm_analysis_TrueRMS ( S , _rtB -> B_75_322_0 , _rtB -> B_75_184_0 , & _rtB
-> TrueRMS_k , & _rtDW -> TrueRMS_k , & _rtP -> TrueRMS_k , & _rtX ->
TrueRMS_k ) ; pwm_analysis_RMS ( S , _rtB -> B_75_324_0 , _rtB -> B_75_184_0
, & _rtB -> RMS_f , & _rtDW -> RMS_f , & _rtP -> RMS_f , & _rtX -> RMS_f ) ;
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( _rtB ->
B_75_322_0 ) { rtb_B_75_326_0 = _rtB -> TrueRMS_k . B_19_10_0 ; } else {
rtb_B_75_326_0 = _rtB -> RMS_f . B_17_22_0 ; } rtb_B_75_326_0 *=
rtb_B_75_326_0 ; _rtB -> B_75_328_0 = _rtX -> integrator_CSTATE_m2 ; { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_ny .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_ny . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S )
; real_T tMinusDelay = simTime - _rtP -> P_249 ; B_75_329_0 =
pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , *
uBuffer , _rtDW -> TransportDelay_IWORK_ih . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_ih . Last , _rtDW -> TransportDelay_IWORK_ih . Tail ,
_rtDW -> TransportDelay_IWORK_ih . Head , _rtP -> P_250 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } rtb_B_75_330_0 = ssGetT ( S ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_331_0 = _rtP -> P_251 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { rtb_B_75_332_0 = (
rtb_B_75_330_0 >= _rtB -> B_75_331_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { _rtB -> B_75_333_0 = _rtDW -> Memory_PreviousInput_b
; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_75_332_0 ) { _rtB -> B_75_335_0 = ( _rtB -> B_75_328_0 - B_75_329_0 ) *
_rtP -> P_25 ; } else { _rtB -> B_75_335_0 = _rtB -> B_75_333_0 ; }
rtb_B_75_336_0 = _rtB -> B_75_335_0 * _rtB -> B_75_335_0 ; }
pwm_analysis_TrueRMS ( S , _rtB -> B_75_338_0 , _rtB -> B_75_184_0 , & _rtB
-> TrueRMS_j , & _rtDW -> TrueRMS_j , & _rtP -> TrueRMS_j , & _rtX ->
TrueRMS_j ) ; pwm_analysis_RMS ( S , _rtB -> B_75_340_0 , _rtB -> B_75_184_0
, & _rtB -> RMS_o , & _rtDW -> RMS_o , & _rtP -> RMS_o , & _rtX -> RMS_o ) ;
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( _rtB ->
B_75_338_0 ) { rtb_B_75_296_0 = _rtB -> TrueRMS_j . B_19_10_0 ; } else {
rtb_B_75_296_0 = _rtB -> RMS_o . B_17_22_0 ; } rtb_B_75_296_0 *=
rtb_B_75_296_0 ; if ( rtb_B_75_296_0 > _rtP -> P_254 ) { rtb_B_75_330_0 =
_rtP -> P_254 ; } else if ( rtb_B_75_296_0 < _rtP -> P_255 ) { rtb_B_75_330_0
= _rtP -> P_255 ; } else { rtb_B_75_330_0 = rtb_B_75_296_0 ; } rtb_B_75_296_0
= ( ( rtb_B_75_326_0 - rtb_B_75_336_0 ) - rtb_B_75_296_0 ) / rtb_B_75_330_0 ;
if ( rtb_B_75_296_0 > _rtP -> P_256 ) { rtb_B_75_296_0 = _rtP -> P_256 ; }
else { if ( rtb_B_75_296_0 < _rtP -> P_257 ) { rtb_B_75_296_0 = _rtP -> P_257
; } } _rtB -> B_75_349_0 = _rtP -> P_258 * muDoubleScalarSqrt (
rtb_B_75_296_0 ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ ssCallAccelRunBlock ( S , 75 , 350 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 351 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 75 , 352 , SS_CALL_MDL_OUTPUTS ) ; }
pwm_analysis_TrueRMS ( S , _rtB -> B_75_354_0 , _rtB -> B_75_184_0 , & _rtB
-> TrueRMS_h , & _rtDW -> TrueRMS_h , & _rtP -> TrueRMS_h , & _rtX ->
TrueRMS_h ) ; pwm_analysis_RMS ( S , _rtB -> B_75_356_0 , _rtB -> B_75_184_0
, & _rtB -> RMS_l , & _rtDW -> RMS_l , & _rtP -> RMS_l , & _rtX -> RMS_l ) ;
isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( _rtB ->
B_75_354_0 ) { _rtB -> B_75_358_0 = _rtB -> TrueRMS_h . B_19_10_0 ; } else {
_rtB -> B_75_358_0 = _rtB -> RMS_l . B_17_22_0 ; } } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 75 , 359 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_75_360_0 = _rtP -> P_260 *
rtb_RealImagtoComplex_re ; ssCallAccelRunBlock ( S , 75 , 361 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 75 , 362 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_75_363_0 = _rtP -> P_261 * _rtB -> B_75_1_0
[ 7 ] ; } pwm_analysis_TrueRMS ( S , _rtB -> B_75_365_0 , _rtB -> B_75_363_0
, & _rtB -> TrueRMS_f , & _rtDW -> TrueRMS_f , & _rtP -> TrueRMS_f , & _rtX
-> TrueRMS_f ) ; pwm_analysis_RMS ( S , _rtB -> B_75_367_0 , _rtB ->
B_75_363_0 , & _rtB -> RMS_g , & _rtDW -> RMS_g , & _rtP -> RMS_g , & _rtX ->
RMS_g ) ; isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if (
_rtB -> B_75_365_0 ) { _rtB -> B_75_369_0 = _rtB -> TrueRMS_f . B_19_10_0 ; }
else { _rtB -> B_75_369_0 = _rtB -> RMS_g . B_17_22_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 370 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtDW -> systemEnable_c != 0 ) {
_rtDW -> lastSin_n = muDoubleScalarSin ( _rtP -> P_265 * ssGetTaskTime ( S ,
1 ) ) ; _rtDW -> lastCos_g = muDoubleScalarCos ( _rtP -> P_265 *
ssGetTaskTime ( S , 1 ) ) ; _rtDW -> systemEnable_c = 0 ; } _rtB ->
B_75_372_0 = ( ( ( _rtDW -> lastSin_n * _rtP -> P_269 + _rtDW -> lastCos_g *
_rtP -> P_268 ) * _rtP -> P_267 + ( _rtDW -> lastCos_g * _rtP -> P_269 -
_rtDW -> lastSin_n * _rtP -> P_268 ) * _rtP -> P_266 ) * _rtP -> P_263 + _rtP
-> P_264 ) * _rtB -> B_75_363_0 ; if ( _rtDW -> Integ4_SYSTEM_ENABLE_j2 != 0
) { _rtB -> B_75_373_0 = _rtDW -> Integ4_DSTATE_i ; } else { _rtB ->
B_75_373_0 = _rtP -> P_270 * _rtB -> B_75_372_0 + _rtDW -> Integ4_DSTATE_i ;
} _rtB -> B_75_374_0 = _rtP -> P_272 ; ssCallAccelRunBlock ( S , 75 , 375 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssGetTaskTime ( S , 1 ) >= _rtB -> B_75_374_0 )
{ _rtB -> B_75_382_0 = ( _rtB -> B_75_373_0 - _rtB -> B_75_375_0 ) * _rtP ->
P_281 + ( _rtP -> P_24 * _rtB -> B_75_372_0 - _rtP -> P_23 * _rtDW ->
UnitDelay_DSTATE_g ) ; } else { _rtB -> B_75_382_0 = _rtDW ->
UnitDelay1_DSTATE_o ; } if ( _rtDW -> systemEnable_a != 0 ) { _rtDW ->
lastSin_m = muDoubleScalarSin ( _rtP -> P_286 * ssGetTaskTime ( S , 1 ) ) ;
_rtDW -> lastCos_i = muDoubleScalarCos ( _rtP -> P_286 * ssGetTaskTime ( S ,
1 ) ) ; _rtDW -> systemEnable_a = 0 ; } _rtB -> B_75_384_0 = ( ( ( _rtDW ->
lastSin_m * _rtP -> P_290 + _rtDW -> lastCos_i * _rtP -> P_289 ) * _rtP ->
P_288 + ( _rtDW -> lastCos_i * _rtP -> P_290 - _rtDW -> lastSin_m * _rtP ->
P_289 ) * _rtP -> P_287 ) * _rtP -> P_284 + _rtP -> P_285 ) * _rtB ->
B_75_363_0 ; if ( _rtDW -> Integ4_SYSTEM_ENABLE_g != 0 ) { _rtB -> B_75_385_0
= _rtDW -> Integ4_DSTATE_az ; } else { _rtB -> B_75_385_0 = _rtP -> P_291 *
_rtB -> B_75_384_0 + _rtDW -> Integ4_DSTATE_az ; } _rtB -> B_75_386_0 = _rtP
-> P_293 ; ssCallAccelRunBlock ( S , 75 , 387 , SS_CALL_MDL_OUTPUTS ) ; if (
ssGetTaskTime ( S , 1 ) >= _rtB -> B_75_386_0 ) { _rtB -> B_75_394_0 = ( _rtB
-> B_75_385_0 - _rtB -> B_75_387_0 ) * _rtP -> P_302 + ( _rtP -> P_22 * _rtB
-> B_75_384_0 - _rtP -> P_21 * _rtDW -> UnitDelay_DSTATE_b ) ; } else { _rtB
-> B_75_394_0 = _rtDW -> UnitDelay1_DSTATE_n ; } rtb_RealImagtoComplex_re =
_rtB -> B_75_382_0 ; rtb_B_75_2_0 = _rtB -> B_75_394_0 ; _rtB -> B_75_397_0 =
_rtP -> P_305 * muDoubleScalarHypot ( _rtB -> B_75_382_0 , _rtB -> B_75_394_0
) ; ssCallAccelRunBlock ( S , 75 , 398 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_75_399_0 = _rtP -> P_306 * muDoubleScalarAtan2 ( rtb_B_75_2_0 ,
rtb_RealImagtoComplex_re ) ; ssCallAccelRunBlock ( S , 75 , 400 ,
SS_CALL_MDL_OUTPUTS ) ; } pwm_analysis_TrueRMS ( S , _rtB -> B_75_402_0 ,
_rtB -> B_75_363_0 , & _rtB -> TrueRMS_ff , & _rtDW -> TrueRMS_ff , & _rtP ->
TrueRMS_ff , & _rtX -> TrueRMS_ff ) ; pwm_analysis_RMS ( S , _rtB ->
B_75_404_0 , _rtB -> B_75_363_0 , & _rtB -> RMS_p , & _rtDW -> RMS_p , & _rtP
-> RMS_p , & _rtX -> RMS_p ) ; isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { if ( _rtB -> B_75_402_0 ) { rtb_B_75_406_0 = _rtB ->
TrueRMS_ff . B_19_10_0 ; } else { rtb_B_75_406_0 = _rtB -> RMS_p . B_17_22_0
; } rtb_B_75_406_0 *= rtb_B_75_406_0 ; _rtB -> B_75_408_0 = _rtX ->
integrator_CSTATE_kg ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_bu . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & _rtDW -> TransportDelay_PWORK_bu . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_309 ;
B_75_409_0 = pwm_analysis_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_cs . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_cs . Last , _rtDW -> TransportDelay_IWORK_cs .
Tail , _rtDW -> TransportDelay_IWORK_cs . Head , _rtP -> P_310 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } rtb_B_75_410_0 = ssGetT ( S ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_411_0 = _rtP
-> P_311 ; } isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) {
rtb_B_75_412_0 = ( rtb_B_75_410_0 >= _rtB -> B_75_411_0 ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_75_413_0 = _rtDW
-> Memory_PreviousInput_c ; } isHit = ssIsContinuousTask ( S , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_75_412_0 ) { _rtB -> B_75_415_0 = ( _rtB ->
B_75_408_0 - B_75_409_0 ) * _rtP -> P_27 ; } else { _rtB -> B_75_415_0 = _rtB
-> B_75_413_0 ; } rtb_B_75_416_0 = _rtB -> B_75_415_0 * _rtB -> B_75_415_0 ;
} pwm_analysis_TrueRMS ( S , _rtB -> B_75_418_0 , _rtB -> B_75_363_0 , & _rtB
-> TrueRMS_hu , & _rtDW -> TrueRMS_hu , & _rtP -> TrueRMS_hu , & _rtX ->
TrueRMS_hu ) ; pwm_analysis_RMS ( S , _rtB -> B_75_420_0 , _rtB -> B_75_363_0
, & _rtB -> RMS_js , & _rtDW -> RMS_js , & _rtP -> RMS_js , & _rtX -> RMS_js
) ; isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { if ( _rtB ->
B_75_418_0 ) { rtb_RealImagtoComplex_re = _rtB -> TrueRMS_hu . B_19_10_0 ; }
else { rtb_RealImagtoComplex_re = _rtB -> RMS_js . B_17_22_0 ; }
rtb_RealImagtoComplex_re *= rtb_RealImagtoComplex_re ; if (
rtb_RealImagtoComplex_re > _rtP -> P_314 ) { rtb_B_75_326_0 = _rtP -> P_314 ;
} else if ( rtb_RealImagtoComplex_re < _rtP -> P_315 ) { rtb_B_75_326_0 =
_rtP -> P_315 ; } else { rtb_B_75_326_0 = rtb_RealImagtoComplex_re ; }
rtb_B_75_296_0 = ( ( rtb_B_75_406_0 - rtb_B_75_416_0 ) -
rtb_RealImagtoComplex_re ) / rtb_B_75_326_0 ; if ( rtb_B_75_296_0 > _rtP ->
P_316 ) { rtb_B_75_296_0 = _rtP -> P_316 ; } else { if ( rtb_B_75_296_0 <
_rtP -> P_317 ) { rtb_B_75_296_0 = _rtP -> P_317 ; } } _rtB -> B_75_429_0 =
_rtP -> P_318 * muDoubleScalarSqrt ( rtb_B_75_296_0 ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
75 , 430 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsContinuousTask ( S , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_75_432_0 = ( muDoubleScalarSin ( _rtP -> P_321
* ssGetTaskTime ( S , 0 ) + _rtP -> P_322 ) * _rtP -> P_319 + _rtP -> P_320 )
* _rtB -> B_75_190_0 ; _rtB -> B_75_434_0 = ( muDoubleScalarSin ( _rtP ->
P_325 * ssGetTaskTime ( S , 0 ) + _rtP -> P_326 ) * _rtP -> P_323 + _rtP ->
P_324 ) * _rtB -> B_75_190_0 ; _rtB -> B_75_436_0 = ( muDoubleScalarSin (
_rtP -> P_329 * ssGetTaskTime ( S , 0 ) + _rtP -> P_330 ) * _rtP -> P_327 +
_rtP -> P_328 ) * _rtB -> B_75_194_0 ; _rtB -> B_75_438_0 = (
muDoubleScalarSin ( _rtP -> P_333 * ssGetTaskTime ( S , 0 ) + _rtP -> P_334 )
* _rtP -> P_331 + _rtP -> P_332 ) * _rtB -> B_75_194_0 ; _rtB -> B_75_440_0 =
( muDoubleScalarSin ( _rtP -> P_337 * ssGetTaskTime ( S , 0 ) + _rtP -> P_338
) * _rtP -> P_335 + _rtP -> P_336 ) * _rtB -> B_75_190_0 ; _rtB -> B_75_442_0
= ( muDoubleScalarSin ( _rtP -> P_341 * ssGetTaskTime ( S , 0 ) + _rtP ->
P_342 ) * _rtP -> P_339 + _rtP -> P_340 ) * _rtB -> B_75_190_0 ; _rtB ->
B_75_444_0 = ( muDoubleScalarSin ( _rtP -> P_345 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_346 ) * _rtP -> P_343 + _rtP -> P_344 ) * _rtB -> B_75_194_0 ; _rtB
-> B_75_446_0 = ( muDoubleScalarSin ( _rtP -> P_349 * ssGetTaskTime ( S , 0 )
+ _rtP -> P_350 ) * _rtP -> P_347 + _rtP -> P_348 ) * _rtB -> B_75_194_0 ; }
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID3 ( SimStruct * S ,
int_T tid ) { B_pwm_analysis_T * _rtB ; P_pwm_analysis_T * _rtP ; _rtP = ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_pwm_analysis_T * )
_ssGetModelBlockIO ( S ) ) ; _rtB -> B_75_0_0 = _rtP -> P_28 ; _rtB ->
B_75_12_0 = _rtP -> P_49 ; _rtB -> B_75_17_0 = _rtP -> P_52 ; _rtB ->
B_75_51_0 = ( _rtP -> P_68 != 0.0 ) ; _rtB -> B_75_53_0 = ! _rtB -> B_75_51_0
; _rtB -> B_75_243_0 = _rtP -> P_187 ; _rtB -> B_75_282_0 = ( _rtP -> P_234
!= 0.0 ) ; _rtB -> B_75_284_0 = ! _rtB -> B_75_282_0 ; _rtB -> B_75_298_0 = (
_rtP -> P_240 != 0.0 ) ; _rtB -> B_75_300_0 = ! _rtB -> B_75_298_0 ; _rtB ->
B_75_312_0 = ( _rtP -> P_246 != 0.0 ) ; _rtB -> B_75_314_0 = ! _rtB ->
B_75_312_0 ; _rtB -> B_75_322_0 = ( _rtP -> P_247 != 0.0 ) ; _rtB ->
B_75_324_0 = ! _rtB -> B_75_322_0 ; _rtB -> B_75_338_0 = ( _rtP -> P_253 !=
0.0 ) ; _rtB -> B_75_340_0 = ! _rtB -> B_75_338_0 ; _rtB -> B_75_354_0 = (
_rtP -> P_259 != 0.0 ) ; _rtB -> B_75_356_0 = ! _rtB -> B_75_354_0 ; _rtB ->
B_75_365_0 = ( _rtP -> P_262 != 0.0 ) ; _rtB -> B_75_367_0 = ! _rtB ->
B_75_365_0 ; _rtB -> B_75_402_0 = ( _rtP -> P_307 != 0.0 ) ; _rtB ->
B_75_404_0 = ! _rtB -> B_75_402_0 ; _rtB -> B_75_418_0 = ( _rtP -> P_313 !=
0.0 ) ; _rtB -> B_75_420_0 = ! _rtB -> B_75_418_0 ; UNUSED_PARAMETER ( tid )
; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T HoldSine ;
int32_T isHit ; B_pwm_analysis_T * _rtB ; P_pwm_analysis_T * _rtP ;
DW_pwm_analysis_T * _rtDW ; _rtDW = ( ( DW_pwm_analysis_T * ) ssGetRootDWork
( S ) ) ; _rtP = ( ( P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_pwm_analysis_T * ) _ssGetModelBlockIO ( S ) ) ; isHit = ssIsSampleHit ( S ,
1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 75 , 1 ,
SS_CALL_MDL_UPDATE ) ; _rtDW -> Delay_DSTATE = _rtB -> B_75_14_0 ; _rtDW ->
ICic_PreviousInput = _rtB -> B_75_21_0 ; _rtDW -> ICic_PreviousInput_i = _rtB
-> B_75_25_0 ; _rtDW -> ICic_PreviousInput_g = _rtB -> B_75_29_0 ; _rtDW ->
Delay1_DSTATE = _rtB -> B_8_0_1 ; _rtDW -> Delay2_DSTATE = _rtB -> B_8_0_2 ;
_rtDW -> Delay3_DSTATE = _rtB -> B_8_0_3 ; } pwm_analysis_TrueRMS_Update ( S
, & _rtB -> TrueRMS , & _rtDW -> TrueRMS , & _rtP -> TrueRMS ) ;
pwm_analysis_RMS_Update ( S , & _rtB -> RMS , & _rtDW -> RMS , & _rtP -> RMS
) ; isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK . Head = ( ( _rtDW -> TransportDelay_IWORK . Head < (
_rtDW -> TransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK
. Head == _rtDW -> TransportDelay_IWORK . Tail ) { if ( !
pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK . CircularBufSize , & _rtDW -> TransportDelay_IWORK .
Tail , & _rtDW -> TransportDelay_IWORK . Head , & _rtDW ->
TransportDelay_IWORK . Last , simTime - _rtP -> P_70 , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK . Head ] = _rtB ->
B_75_60_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput = _rtB -> B_75_67_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_h . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_h . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_p .
Head = ( ( _rtDW -> TransportDelay_IWORK_p . Head < ( _rtDW ->
TransportDelay_IWORK_p . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_p . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_p . Head == _rtDW -> TransportDelay_IWORK_p . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_p . CircularBufSize , & _rtDW -> TransportDelay_IWORK_p
. Tail , & _rtDW -> TransportDelay_IWORK_p . Head , & _rtDW ->
TransportDelay_IWORK_p . Last , simTime - _rtP -> P_76 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_p .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_p . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_p . Head ] = _rtB ->
B_75_73_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_k = _rtB -> B_75_80_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_l .
Head = ( ( _rtDW -> TransportDelay_IWORK_l . Head < ( _rtDW ->
TransportDelay_IWORK_l . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_l . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_l . Head == _rtDW -> TransportDelay_IWORK_l . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_l . CircularBufSize , & _rtDW -> TransportDelay_IWORK_l
. Tail , & _rtDW -> TransportDelay_IWORK_l . Head , & _rtDW ->
TransportDelay_IWORK_l . Last , simTime - _rtP -> P_81 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_l .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_l . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_l . Head ] = _rtB ->
B_75_81_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_a = _rtB -> B_75_88_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_i . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_i . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_m .
Head = ( ( _rtDW -> TransportDelay_IWORK_m . Head < ( _rtDW ->
TransportDelay_IWORK_m . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_m . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_m . Head == _rtDW -> TransportDelay_IWORK_m . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_m . CircularBufSize , & _rtDW -> TransportDelay_IWORK_m
. Tail , & _rtDW -> TransportDelay_IWORK_m . Head , & _rtDW ->
TransportDelay_IWORK_m . Last , simTime - _rtP -> P_86 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_m .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_m . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_m . Head ] = _rtB ->
B_75_92_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_l = _rtB -> B_75_99_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_m . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_m . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_c .
Head = ( ( _rtDW -> TransportDelay_IWORK_c . Head < ( _rtDW ->
TransportDelay_IWORK_c . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_c . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_c . Head == _rtDW -> TransportDelay_IWORK_c . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_c . CircularBufSize , & _rtDW -> TransportDelay_IWORK_c
. Tail , & _rtDW -> TransportDelay_IWORK_c . Head , & _rtDW ->
TransportDelay_IWORK_c . Last , simTime - _rtP -> P_91 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_c .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_c . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_c . Head ] = _rtB ->
B_75_101_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_e = _rtB -> B_75_108_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_k .
Head = ( ( _rtDW -> TransportDelay_IWORK_k . Head < ( _rtDW ->
TransportDelay_IWORK_k . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_k . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_k . Head == _rtDW -> TransportDelay_IWORK_k . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_k . CircularBufSize , & _rtDW -> TransportDelay_IWORK_k
. Tail , & _rtDW -> TransportDelay_IWORK_k . Head , & _rtDW ->
TransportDelay_IWORK_k . Last , simTime - _rtP -> P_96 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_k .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_k . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_k . Head ] = _rtB ->
B_75_112_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_k4 = _rtB -> B_75_119_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_a . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_a . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_ml .
Head = ( ( _rtDW -> TransportDelay_IWORK_ml . Head < ( _rtDW ->
TransportDelay_IWORK_ml . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_ml . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_ml . Head == _rtDW -> TransportDelay_IWORK_ml . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_ml . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_ml . Tail , & _rtDW -> TransportDelay_IWORK_ml . Head ,
& _rtDW -> TransportDelay_IWORK_ml . Last , simTime - _rtP -> P_102 , tBuffer
, uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_ml . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_ml . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_ml . Head ] = _rtB -> B_75_124_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_ki = _rtB -> B_75_131_0 ; } isHit = ssIsContinuousTask (
S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> TransportDelay_PWORK_mw . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_mw . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_i . Head = ( ( _rtDW
-> TransportDelay_IWORK_i . Head < ( _rtDW -> TransportDelay_IWORK_i .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_i . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_i . Head == _rtDW ->
TransportDelay_IWORK_i . Tail ) { if ( !
pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_i . CircularBufSize , & _rtDW -> TransportDelay_IWORK_i
. Tail , & _rtDW -> TransportDelay_IWORK_i . Head , & _rtDW ->
TransportDelay_IWORK_i . Last , simTime - _rtP -> P_107 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_i .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_i . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_i . Head ] = _rtB ->
B_75_132_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_f = _rtB -> B_75_139_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_mz . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_mz .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK_is . Head = ( ( _rtDW -> TransportDelay_IWORK_is . Head
< ( _rtDW -> TransportDelay_IWORK_is . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_is . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_is . Head == _rtDW -> TransportDelay_IWORK_is . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_is . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_is . Tail , & _rtDW -> TransportDelay_IWORK_is . Head ,
& _rtDW -> TransportDelay_IWORK_is . Last , simTime - _rtP -> P_112 , tBuffer
, uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_is . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_is . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_is . Head ] = _rtB -> B_75_143_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_p = _rtB -> B_75_150_0 ; } isHit = ssIsContinuousTask (
S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> TransportDelay_PWORK_ba . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_ba . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_n . Head = ( ( _rtDW
-> TransportDelay_IWORK_n . Head < ( _rtDW -> TransportDelay_IWORK_n .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_n . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_n . Head == _rtDW ->
TransportDelay_IWORK_n . Tail ) { if ( !
pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_n . CircularBufSize , & _rtDW -> TransportDelay_IWORK_n
. Tail , & _rtDW -> TransportDelay_IWORK_n . Head , & _rtDW ->
TransportDelay_IWORK_n . Last , simTime - _rtP -> P_117 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_n .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_n . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_n . Head ] = _rtB ->
B_75_151_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_pj = _rtB -> B_75_158_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_e . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_e . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_o .
Head = ( ( _rtDW -> TransportDelay_IWORK_o . Head < ( _rtDW ->
TransportDelay_IWORK_o . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_o . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_o . Head == _rtDW -> TransportDelay_IWORK_o . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_o . CircularBufSize , & _rtDW -> TransportDelay_IWORK_o
. Tail , & _rtDW -> TransportDelay_IWORK_o . Head , & _rtDW ->
TransportDelay_IWORK_o . Last , simTime - _rtP -> P_122 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_o .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_o . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_o . Head ] = _rtB ->
B_75_162_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_n = _rtB -> B_75_169_0 ; } isHit =
ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_f . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_f . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_p5 .
Head = ( ( _rtDW -> TransportDelay_IWORK_p5 . Head < ( _rtDW ->
TransportDelay_IWORK_p5 . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_p5 . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_p5 . Head == _rtDW -> TransportDelay_IWORK_p5 . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_p5 . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_p5 . Tail , & _rtDW -> TransportDelay_IWORK_p5 . Head ,
& _rtDW -> TransportDelay_IWORK_p5 . Last , simTime - _rtP -> P_127 , tBuffer
, uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_p5 . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_p5 . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_p5 . Head ] = _rtB -> B_75_170_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_lp = _rtB -> B_75_177_0 ; } isHit = ssIsContinuousTask (
S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> TransportDelay_PWORK_gg . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_gg . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_cf . Head = ( ( _rtDW
-> TransportDelay_IWORK_cf . Head < ( _rtDW -> TransportDelay_IWORK_cf .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_cf . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_cf . Head == _rtDW ->
TransportDelay_IWORK_cf . Tail ) { if ( !
pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_cf . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_cf . Tail , & _rtDW -> TransportDelay_IWORK_cf . Head ,
& _rtDW -> TransportDelay_IWORK_cf . Last , simTime - _rtP -> P_139 , tBuffer
, uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_cf . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_cf . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_cf . Head ] = _rtB -> B_75_199_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_aw = _rtB -> B_75_206_0 ; HoldSine = _rtDW -> lastSin ;
_rtDW -> lastSin = _rtDW -> lastSin * _rtP -> P_148 + _rtDW -> lastCos * _rtP
-> P_147 ; _rtDW -> lastCos = _rtDW -> lastCos * _rtP -> P_148 - HoldSine *
_rtP -> P_147 ; _rtDW -> Integ4_SYSTEM_ENABLE = 0U ; _rtDW -> Integ4_DSTATE =
_rtP -> P_151 * _rtB -> B_75_216_0 + _rtB -> B_75_217_0 ; ssCallAccelRunBlock
( S , 75 , 219 , SS_CALL_MDL_UPDATE ) ; _rtDW -> UnitDelay_DSTATE = _rtB ->
B_75_216_0 ; _rtDW -> UnitDelay1_DSTATE = _rtB -> B_75_226_0 ; HoldSine =
_rtDW -> lastSin_e ; _rtDW -> lastSin_e = _rtDW -> lastSin_e * _rtP -> P_169
+ _rtDW -> lastCos_k * _rtP -> P_168 ; _rtDW -> lastCos_k = _rtDW ->
lastCos_k * _rtP -> P_169 - HoldSine * _rtP -> P_168 ; _rtDW ->
Integ4_SYSTEM_ENABLE_j = 0U ; _rtDW -> Integ4_DSTATE_j = _rtP -> P_172 * _rtB
-> B_75_228_0 + _rtB -> B_75_229_0 ; ssCallAccelRunBlock ( S , 75 , 231 ,
SS_CALL_MDL_UPDATE ) ; _rtDW -> UnitDelay_DSTATE_j = _rtB -> B_75_228_0 ;
_rtDW -> UnitDelay1_DSTATE_a = _rtB -> B_75_238_0 ; HoldSine = _rtDW ->
lastSin_f ; _rtDW -> lastSin_f = _rtDW -> lastSin_f * _rtP -> P_193 + _rtDW
-> lastCos_p * _rtP -> P_192 ; _rtDW -> lastCos_p = _rtDW -> lastCos_p * _rtP
-> P_193 - HoldSine * _rtP -> P_192 ; _rtDW -> Integ4_SYSTEM_ENABLE_b = 0U ;
_rtDW -> Integ4_DSTATE_k = _rtP -> P_196 * _rtB -> B_75_249_0 + _rtB ->
B_75_250_0 ; ssCallAccelRunBlock ( S , 75 , 252 , SS_CALL_MDL_UPDATE ) ;
_rtDW -> UnitDelay_DSTATE_k = _rtB -> B_75_249_0 ; _rtDW ->
UnitDelay1_DSTATE_b = _rtB -> B_75_259_0 ; HoldSine = _rtDW -> lastSin_ej ;
_rtDW -> lastSin_ej = _rtDW -> lastSin_ej * _rtP -> P_214 + _rtDW ->
lastCos_a * _rtP -> P_213 ; _rtDW -> lastCos_a = _rtDW -> lastCos_a * _rtP ->
P_214 - HoldSine * _rtP -> P_213 ; _rtDW -> Integ4_SYSTEM_ENABLE_d = 0U ;
_rtDW -> Integ4_DSTATE_a = _rtP -> P_217 * _rtB -> B_75_261_0 + _rtB ->
B_75_262_0 ; ssCallAccelRunBlock ( S , 75 , 264 , SS_CALL_MDL_UPDATE ) ;
_rtDW -> UnitDelay_DSTATE_n = _rtB -> B_75_261_0 ; _rtDW ->
UnitDelay1_DSTATE_a0 = _rtB -> B_75_271_0 ; } pwm_analysis_TrueRMS_Update ( S
, & _rtB -> TrueRMS_a , & _rtDW -> TrueRMS_a , & _rtP -> TrueRMS_a ) ;
pwm_analysis_RMS_Update ( S , & _rtB -> RMS_d , & _rtDW -> RMS_d , & _rtP ->
RMS_d ) ; isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_n . TUbufferPtrs
[ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_n
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK_a . Head = ( ( _rtDW -> TransportDelay_IWORK_a . Head <
( _rtDW -> TransportDelay_IWORK_a . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_a . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_a . Head == _rtDW -> TransportDelay_IWORK_a . Tail ) {
if ( ! pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_a . CircularBufSize , & _rtDW -> TransportDelay_IWORK_a
. Tail , & _rtDW -> TransportDelay_IWORK_a . Head , & _rtDW ->
TransportDelay_IWORK_a . Last , simTime - _rtP -> P_236 , tBuffer , uBuffer ,
( NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_a .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_a . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_a . Head ] = _rtB ->
B_75_288_0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput_d = _rtB -> B_75_295_0 ; }
pwm_analysis_TrueRMS_Update ( S , & _rtB -> TrueRMS_p , & _rtDW -> TrueRMS_p
, & _rtP -> TrueRMS_p ) ; pwm_analysis_RMS_Update ( S , & _rtB -> RMS_j , &
_rtDW -> RMS_j , & _rtP -> RMS_j ) ; pwm_analysis_TrueRMS_Update ( S , & _rtB
-> TrueRMS_i , & _rtDW -> TrueRMS_i , & _rtP -> TrueRMS_i ) ;
pwm_analysis_RMS_Update ( S , & _rtB -> RMS_lk , & _rtDW -> RMS_lk , & _rtP
-> RMS_lk ) ; pwm_analysis_TrueRMS_Update ( S , & _rtB -> TrueRMS_k , & _rtDW
-> TrueRMS_k , & _rtP -> TrueRMS_k ) ; pwm_analysis_RMS_Update ( S , & _rtB
-> RMS_f , & _rtDW -> RMS_f , & _rtP -> RMS_f ) ; isHit = ssIsContinuousTask
( S , 0 ) ; if ( isHit != 0 ) { { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> TransportDelay_PWORK_ny . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_ny . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_ih . Head = ( ( _rtDW
-> TransportDelay_IWORK_ih . Head < ( _rtDW -> TransportDelay_IWORK_ih .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_ih . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_ih . Head == _rtDW ->
TransportDelay_IWORK_ih . Tail ) { if ( !
pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_ih . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_ih . Tail , & _rtDW -> TransportDelay_IWORK_ih . Head ,
& _rtDW -> TransportDelay_IWORK_ih . Last , simTime - _rtP -> P_249 , tBuffer
, uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_ih . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_ih . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_ih . Head ] = _rtB -> B_75_328_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_b = _rtB -> B_75_335_0 ; } pwm_analysis_TrueRMS_Update (
S , & _rtB -> TrueRMS_j , & _rtDW -> TrueRMS_j , & _rtP -> TrueRMS_j ) ;
pwm_analysis_RMS_Update ( S , & _rtB -> RMS_o , & _rtDW -> RMS_o , & _rtP ->
RMS_o ) ; pwm_analysis_TrueRMS_Update ( S , & _rtB -> TrueRMS_h , & _rtDW ->
TrueRMS_h , & _rtP -> TrueRMS_h ) ; pwm_analysis_RMS_Update ( S , & _rtB ->
RMS_l , & _rtDW -> RMS_l , & _rtP -> RMS_l ) ; pwm_analysis_TrueRMS_Update (
S , & _rtB -> TrueRMS_f , & _rtDW -> TrueRMS_f , & _rtP -> TrueRMS_f ) ;
pwm_analysis_RMS_Update ( S , & _rtB -> RMS_g , & _rtDW -> RMS_g , & _rtP ->
RMS_g ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { HoldSine
= _rtDW -> lastSin_n ; _rtDW -> lastSin_n = _rtDW -> lastSin_n * _rtP ->
P_267 + _rtDW -> lastCos_g * _rtP -> P_266 ; _rtDW -> lastCos_g = _rtDW ->
lastCos_g * _rtP -> P_267 - HoldSine * _rtP -> P_266 ; _rtDW ->
Integ4_SYSTEM_ENABLE_j2 = 0U ; _rtDW -> Integ4_DSTATE_i = _rtP -> P_270 *
_rtB -> B_75_372_0 + _rtB -> B_75_373_0 ; ssCallAccelRunBlock ( S , 75 , 375
, SS_CALL_MDL_UPDATE ) ; _rtDW -> UnitDelay_DSTATE_g = _rtB -> B_75_372_0 ;
_rtDW -> UnitDelay1_DSTATE_o = _rtB -> B_75_382_0 ; HoldSine = _rtDW ->
lastSin_m ; _rtDW -> lastSin_m = _rtDW -> lastSin_m * _rtP -> P_288 + _rtDW
-> lastCos_i * _rtP -> P_287 ; _rtDW -> lastCos_i = _rtDW -> lastCos_i * _rtP
-> P_288 - HoldSine * _rtP -> P_287 ; _rtDW -> Integ4_SYSTEM_ENABLE_g = 0U ;
_rtDW -> Integ4_DSTATE_az = _rtP -> P_291 * _rtB -> B_75_384_0 + _rtB ->
B_75_385_0 ; ssCallAccelRunBlock ( S , 75 , 387 , SS_CALL_MDL_UPDATE ) ;
_rtDW -> UnitDelay_DSTATE_b = _rtB -> B_75_384_0 ; _rtDW ->
UnitDelay1_DSTATE_n = _rtB -> B_75_394_0 ; } pwm_analysis_TrueRMS_Update ( S
, & _rtB -> TrueRMS_ff , & _rtDW -> TrueRMS_ff , & _rtP -> TrueRMS_ff ) ;
pwm_analysis_RMS_Update ( S , & _rtB -> RMS_p , & _rtDW -> RMS_p , & _rtP ->
RMS_p ) ; isHit = ssIsContinuousTask ( S , 0 ) ; if ( isHit != 0 ) { { real_T
* * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_bu .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_bu . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S )
; _rtDW -> TransportDelay_IWORK_cs . Head = ( ( _rtDW ->
TransportDelay_IWORK_cs . Head < ( _rtDW -> TransportDelay_IWORK_cs .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_cs . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_cs . Head == _rtDW ->
TransportDelay_IWORK_cs . Tail ) { if ( !
pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_cs . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_cs . Tail , & _rtDW -> TransportDelay_IWORK_cs . Head ,
& _rtDW -> TransportDelay_IWORK_cs . Last , simTime - _rtP -> P_309 , tBuffer
, uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_cs . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_cs . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_cs . Head ] = _rtB -> B_75_408_0 ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_c = _rtB -> B_75_415_0 ; } pwm_analysis_TrueRMS_Update (
S , & _rtB -> TrueRMS_hu , & _rtDW -> TrueRMS_hu , & _rtP -> TrueRMS_hu ) ;
pwm_analysis_RMS_Update ( S , & _rtB -> RMS_js , & _rtDW -> RMS_js , & _rtP
-> RMS_js ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_pwm_analysis_T * _rtB ;
XDot_pwm_analysis_T * _rtXdot ; DW_pwm_analysis_T * _rtDW ; _rtDW = ( (
DW_pwm_analysis_T * ) ssGetRootDWork ( S ) ) ; _rtXdot = ( (
XDot_pwm_analysis_T * ) ssGetdX ( S ) ) ; _rtB = ( ( B_pwm_analysis_T * )
_ssGetModelBlockIO ( S ) ) ; pwm_analysis_TrueRMS_Deriv ( S , & _rtB ->
TrueRMS , & _rtDW -> TrueRMS , & _rtXdot -> TrueRMS ) ;
pwm_analysis_RMS_Deriv ( S , & _rtB -> RMS , & _rtDW -> RMS , & _rtXdot ->
RMS ) ; _rtXdot -> integrator_CSTATE = _rtB -> B_75_69_0 ; _rtXdot ->
integrator_CSTATE_e = _rtB -> B_75_444_0 ; _rtXdot -> integrator_CSTATE_g =
_rtB -> B_75_446_0 ; _rtXdot -> integrator_CSTATE_k = _rtB -> B_75_186_0 ;
_rtXdot -> integrator_CSTATE_b = _rtB -> B_75_189_0 ; _rtXdot ->
integrator_CSTATE_a = _rtB -> B_75_194_0 ; _rtXdot -> integrator_CSTATE_i =
_rtB -> B_75_432_0 ; _rtXdot -> integrator_CSTATE_d = _rtB -> B_75_434_0 ;
_rtXdot -> integrator_CSTATE_p = _rtB -> B_75_436_0 ; _rtXdot ->
integrator_CSTATE_f = _rtB -> B_75_438_0 ; _rtXdot -> integrator_CSTATE_o =
_rtB -> B_75_440_0 ; _rtXdot -> integrator_CSTATE_m = _rtB -> B_75_442_0 ;
_rtXdot -> integrator_CSTATE_av = _rtB -> B_75_190_0 ;
pwm_analysis_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_a , & _rtDW -> TrueRMS_a ,
& _rtXdot -> TrueRMS_a ) ; pwm_analysis_RMS_Deriv ( S , & _rtB -> RMS_d , &
_rtDW -> RMS_d , & _rtXdot -> RMS_d ) ; _rtXdot -> integrator_CSTATE_fs =
_rtB -> B_75_185_0 ; pwm_analysis_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_p , &
_rtDW -> TrueRMS_p , & _rtXdot -> TrueRMS_p ) ; pwm_analysis_RMS_Deriv ( S ,
& _rtB -> RMS_j , & _rtDW -> RMS_j , & _rtXdot -> RMS_j ) ;
pwm_analysis_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_i , & _rtDW -> TrueRMS_i ,
& _rtXdot -> TrueRMS_i ) ; pwm_analysis_RMS_Deriv ( S , & _rtB -> RMS_lk , &
_rtDW -> RMS_lk , & _rtXdot -> RMS_lk ) ; pwm_analysis_TrueRMS_Deriv ( S , &
_rtB -> TrueRMS_k , & _rtDW -> TrueRMS_k , & _rtXdot -> TrueRMS_k ) ;
pwm_analysis_RMS_Deriv ( S , & _rtB -> RMS_f , & _rtDW -> RMS_f , & _rtXdot
-> RMS_f ) ; _rtXdot -> integrator_CSTATE_m2 = _rtB -> B_75_184_0 ;
pwm_analysis_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_j , & _rtDW -> TrueRMS_j ,
& _rtXdot -> TrueRMS_j ) ; pwm_analysis_RMS_Deriv ( S , & _rtB -> RMS_o , &
_rtDW -> RMS_o , & _rtXdot -> RMS_o ) ; pwm_analysis_TrueRMS_Deriv ( S , &
_rtB -> TrueRMS_h , & _rtDW -> TrueRMS_h , & _rtXdot -> TrueRMS_h ) ;
pwm_analysis_RMS_Deriv ( S , & _rtB -> RMS_l , & _rtDW -> RMS_l , & _rtXdot
-> RMS_l ) ; pwm_analysis_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_f , & _rtDW
-> TrueRMS_f , & _rtXdot -> TrueRMS_f ) ; pwm_analysis_RMS_Deriv ( S , & _rtB
-> RMS_g , & _rtDW -> RMS_g , & _rtXdot -> RMS_g ) ;
pwm_analysis_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_ff , & _rtDW -> TrueRMS_ff
, & _rtXdot -> TrueRMS_ff ) ; pwm_analysis_RMS_Deriv ( S , & _rtB -> RMS_p ,
& _rtDW -> RMS_p , & _rtXdot -> RMS_p ) ; _rtXdot -> integrator_CSTATE_kg =
_rtB -> B_75_363_0 ; pwm_analysis_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_hu ,
& _rtDW -> TrueRMS_hu , & _rtXdot -> TrueRMS_hu ) ; pwm_analysis_RMS_Deriv (
S , & _rtB -> RMS_js , & _rtDW -> RMS_js , & _rtXdot -> RMS_js ) ; } static
void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 ,
3977025417U ) ; ssSetChecksumVal ( S , 1 , 648497785U ) ; ssSetChecksumVal (
S , 2 , 2398741438U ) ; ssSetChecksumVal ( S , 3 , 3047280472U ) ; { mxArray
* slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" )
; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat ,
1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "9.1" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( DW_pwm_analysis_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_pwm_analysis_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_pwm_analysis_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & pwm_analysis_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> P_241 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> P_243 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> P_254 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> P_256 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> P_314 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> P_316 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_hu . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_ff . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_p . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_a . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_j . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_k . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_i . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_f . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS_h . P_6 = rtInf ; ( (
P_pwm_analysis_T * ) ssGetModelRtp ( S ) ) -> TrueRMS . P_6 = rtInf ; }
static void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS
; SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID3 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
