#include "__cf_InverterModulesInSeries2016a.h"
#include <math.h>
#include "InverterModulesInSeries2016a_acc.h"
#include "InverterModulesInSeries2016a_acc_private.h"
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
boolean_T InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf (
int_T * bufSzPtr , int_T * tailPtr , int_T * headPtr , int_T * lastPtr ,
real_T tMinusDelay , real_T * * tBufPtr , real_T * * uBufPtr , real_T * *
xBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay , int_T *
maxNewBufSzPtr ) { int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = *
bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T * xBuf = ( NULL ) ; int_T
numBuffer = 2 ; if ( istransportdelay ) { numBuffer = 3 ; xBuf = * xBufPtr ;
} testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay
<= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T *
tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T
newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr ) { *
maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer *
newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false )
; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( real_T tMinusDelay ,
real_T tStart , real_T * tBuf , real_T * uBuf , int_T bufSz , int_T * lastIdx
, int_T oldestIdx , int_T newIdx , real_T initOutput , boolean_T discrete ,
boolean_T minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2
, u1 , u2 ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay >
tStart ) ) return initOutput ; if ( tMinusDelay <= tStart ) return initOutput
; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return (
uBuf [ oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if (
oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [
tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 )
{ if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput
) { if ( newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; }
newIdx -- ; } else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; }
newIdx = bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) {
while ( tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < (
bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay
) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i
+ 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) { double tempEps = (
DBL_EPSILON ) * 128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf
[ i ] ) ; if ( tempEps > localEps ) { localEps = tempEps ; } localEps =
localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout =
uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else {
yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ]
; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1
] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay
>= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 = ( t2 -
tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2
; } } return ( yout ) ; } real_T look1_pbinlxpw ( real_T u0 , const real_T
bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] , uint32_T maxIndex
) { real_T frac ; uint32_T iRght ; uint32_T iLeft ; uint32_T bpIdx ; uint32_T
found ; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac = ( u0 - bp0 [ 0U ] ) / (
bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx =
prevIndex [ 0U ] ; iLeft = 0U ; iRght = maxIndex ; found = 0U ; while ( found
== 0U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx - 1U ; bpIdx = ( iRght +
iLeft ) >> 1U ; } else if ( u0 < bp0 [ bpIdx + 1U ] ) { found = 1U ; } else {
iLeft = bpIdx + 1U ; bpIdx = ( iRght + iLeft ) >> 1U ; } } frac = ( u0 - bp0
[ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx =
maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] -
bp0 [ maxIndex - 1U ] ) ; } prevIndex [ 0U ] = bpIdx ; return ( table [ bpIdx
+ 1U ] - table [ bpIdx ] ) * frac + table [ bpIdx ] ; } void
rt_ssGetBlockPath ( SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * *
path ) { _ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void
rt_ssSet_slErrMsg ( SimStruct * S , void * diag ) { if ( !
_ssIsErrorStatusAslErrMsg ( S ) ) { _ssSet_slErrMsg ( S , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( SimStruct * S , void * diag ) {
_ssReportDiagnosticAsWarning ( S , diag ) ; } void
InverterModulesInSeries2016a_RMS_Init ( SimStruct * S ,
B_RMS_InverterModulesInSeries2016a_T * localB ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ,
P_RMS_InverterModulesInSeries2016a_T * localP ,
X_RMS_InverterModulesInSeries2016a_T * localX ) { localX ->
integrator_CSTATE_oy [ 0 ] = localP -> P_3 ; localDW -> Memory_PreviousInput
[ 0 ] = localP -> P_7 ; localX -> integrator_CSTATE_aa [ 0 ] = localP -> P_8
; localDW -> Memory_PreviousInput_m [ 0 ] = localP -> P_12 ; localB ->
B_22_22_0 [ 0 ] = localP -> P_2 ; localX -> integrator_CSTATE_oy [ 1 ] =
localP -> P_3 ; localDW -> Memory_PreviousInput [ 1 ] = localP -> P_7 ;
localX -> integrator_CSTATE_aa [ 1 ] = localP -> P_8 ; localDW ->
Memory_PreviousInput_m [ 1 ] = localP -> P_12 ; localB -> B_22_22_0 [ 1 ] =
localP -> P_2 ; localX -> integrator_CSTATE_oy [ 2 ] = localP -> P_3 ;
localDW -> Memory_PreviousInput [ 2 ] = localP -> P_7 ; localX ->
integrator_CSTATE_aa [ 2 ] = localP -> P_8 ; localDW ->
Memory_PreviousInput_m [ 2 ] = localP -> P_12 ; localB -> B_22_22_0 [ 2 ] =
localP -> P_2 ; } void InverterModulesInSeries2016a_RMS_Disable ( SimStruct *
S , DW_RMS_InverterModulesInSeries2016a_T * localDW ) { localDW -> RMS_MODE =
false ; } void InverterModulesInSeries2016a_RMS ( SimStruct * S , boolean_T
rtu_Enable , real_T rtu_In , const real_T rtu_In_k [ 2 ] ,
B_RMS_InverterModulesInSeries2016a_T * localB ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ,
P_RMS_InverterModulesInSeries2016a_T * localP ,
X_RMS_InverterModulesInSeries2016a_T * localX ,
XDis_RMS_InverterModulesInSeries2016a_T * localXdis ) { boolean_T
rtb_B_22_4_0 ; real_T rtb_B_22_18_0 ; int32_T isHit ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S ) != 0 ) ) { if
( rtu_Enable ) { if ( ! localDW -> RMS_MODE ) { if ( ssGetTaskTime ( S , 1 )
!= ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
( void ) memset ( & ( localXdis -> integrator_CSTATE_oy ) , 0 , 6 * sizeof (
boolean_T ) ) ; localDW -> RMS_MODE = true ; } } else { if ( localDW ->
RMS_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void )
memset ( & ( localXdis -> integrator_CSTATE_oy ) , 1 , 6 * sizeof ( boolean_T
) ) ; InverterModulesInSeries2016a_RMS_Disable ( S , localDW ) ; } } } if (
localDW -> RMS_MODE ) { localB -> B_22_0_0 [ 0 ] = localX ->
integrator_CSTATE_oy [ 0 ] ; localB -> B_22_0_0 [ 1 ] = localX ->
integrator_CSTATE_oy [ 1 ] ; localB -> B_22_0_0 [ 2 ] = localX ->
integrator_CSTATE_oy [ 2 ] ; { real_T * * uBuffer = ( real_T * * ) & localDW
-> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & localDW -> TransportDelay_PWORK . TUbufferPtrs [ 3 ] ; real_T simTime
= ssGetT ( S ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & localB ->
B_22_1_0 [ 0 ] ; int_T * iw_Tail = & localDW -> TransportDelay_IWORK . Tail [
0 ] ; int_T * iw_Head = & localDW -> TransportDelay_IWORK . Head [ 0 ] ;
int_T * iw_Last = & localDW -> TransportDelay_IWORK . Last [ 0 ] ; int_T *
iw_CircularBufSize = & localDW -> TransportDelay_IWORK . CircularBufSize [ 0
] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( ( localP -> P_4 > 0.0 )
? localP -> P_4 : 0.0 ) ; tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail
[ i1 ] , iw_Head [ i1 ] , localP -> P_5 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; tBuffer ++ ; uBuffer ++ ; } } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { localB -> B_22_3_0 = localP -> P_6 ; } rtb_B_22_4_0 = (
ssGetT ( S ) >= localB -> B_22_3_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { localB -> B_22_5_0 [ 0 ] = localDW ->
Memory_PreviousInput [ 0 ] ; localB -> B_22_5_0 [ 1 ] = localDW ->
Memory_PreviousInput [ 1 ] ; localB -> B_22_5_0 [ 2 ] = localDW ->
Memory_PreviousInput [ 2 ] ; } if ( rtb_B_22_4_0 ) { localB -> B_21_0_0 [ 0 ]
= localB -> B_22_0_0 [ 0 ] - localB -> B_22_1_0 [ 0 ] ; localB -> B_21_1_0 [
0 ] = localP -> P_1 * localB -> B_21_0_0 [ 0 ] ; localB -> B_22_7_0 [ 0 ] =
localB -> B_21_1_0 [ 0 ] ; localB -> B_21_0_0 [ 1 ] = localB -> B_22_0_0 [ 1
] - localB -> B_22_1_0 [ 1 ] ; localB -> B_21_1_0 [ 1 ] = localP -> P_1 *
localB -> B_21_0_0 [ 1 ] ; localB -> B_22_7_0 [ 1 ] = localB -> B_21_1_0 [ 1
] ; localB -> B_21_0_0 [ 2 ] = localB -> B_22_0_0 [ 2 ] - localB -> B_22_1_0
[ 2 ] ; localB -> B_21_1_0 [ 2 ] = localP -> P_1 * localB -> B_21_0_0 [ 2 ] ;
localB -> B_22_7_0 [ 2 ] = localB -> B_21_1_0 [ 2 ] ; } else { localB ->
B_22_7_0 [ 0 ] = localB -> B_22_5_0 [ 0 ] ; localB -> B_22_7_0 [ 1 ] = localB
-> B_22_5_0 [ 1 ] ; localB -> B_22_7_0 [ 2 ] = localB -> B_22_5_0 [ 2 ] ; }
localB -> B_22_8_0 [ 0 ] = localX -> integrator_CSTATE_aa [ 0 ] ; localB ->
B_22_8_0 [ 1 ] = localX -> integrator_CSTATE_aa [ 1 ] ; localB -> B_22_8_0 [
2 ] = localX -> integrator_CSTATE_aa [ 2 ] ; { real_T * * uBuffer = ( real_T
* * ) & localDW -> TransportDelay_PWORK_i . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK_i . TUbufferPtrs [
3 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay ; { int_T i1 ;
real_T * y0 = & localB -> B_22_9_0 [ 0 ] ; int_T * iw_Tail = & localDW ->
TransportDelay_IWORK_d . Tail [ 0 ] ; int_T * iw_Head = & localDW ->
TransportDelay_IWORK_d . Head [ 0 ] ; int_T * iw_Last = & localDW ->
TransportDelay_IWORK_d . Last [ 0 ] ; int_T * iw_CircularBufSize = & localDW
-> TransportDelay_IWORK_d . CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 3 ;
i1 ++ ) { tMinusDelay = ( ( localP -> P_9 > 0.0 ) ? localP -> P_9 : 0.0 ) ;
tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail
[ i1 ] , iw_Head [ i1 ] , localP -> P_10 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; tBuffer ++ ; uBuffer ++ ; } } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { localB -> B_22_11_0 = localP -> P_11 ; } rtb_B_22_4_0 = (
ssGetT ( S ) >= localB -> B_22_11_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { localB -> B_22_13_0 [ 0 ] = localDW ->
Memory_PreviousInput_m [ 0 ] ; localB -> B_22_13_0 [ 1 ] = localDW ->
Memory_PreviousInput_m [ 1 ] ; localB -> B_22_13_0 [ 2 ] = localDW ->
Memory_PreviousInput_m [ 2 ] ; } if ( rtb_B_22_4_0 ) { localB -> B_20_0_0 [ 0
] = localB -> B_22_8_0 [ 0 ] - localB -> B_22_9_0 [ 0 ] ; localB -> B_20_1_0
[ 0 ] = localP -> P_0 * localB -> B_20_0_0 [ 0 ] ; localB -> B_22_15_0 [ 0 ]
= localB -> B_20_1_0 [ 0 ] ; localB -> B_20_0_0 [ 1 ] = localB -> B_22_8_0 [
1 ] - localB -> B_22_9_0 [ 1 ] ; localB -> B_20_1_0 [ 1 ] = localP -> P_0 *
localB -> B_20_0_0 [ 1 ] ; localB -> B_22_15_0 [ 1 ] = localB -> B_20_1_0 [ 1
] ; localB -> B_20_0_0 [ 2 ] = localB -> B_22_8_0 [ 2 ] - localB -> B_22_9_0
[ 2 ] ; localB -> B_20_1_0 [ 2 ] = localP -> P_0 * localB -> B_20_0_0 [ 2 ] ;
localB -> B_22_15_0 [ 2 ] = localB -> B_20_1_0 [ 2 ] ; } else { localB ->
B_22_15_0 [ 0 ] = localB -> B_22_13_0 [ 0 ] ; localB -> B_22_15_0 [ 1 ] =
localB -> B_22_13_0 [ 1 ] ; localB -> B_22_15_0 [ 2 ] = localB -> B_22_13_0 [
2 ] ; } localB -> B_22_16_0 [ 0 ] . re = localB -> B_22_7_0 [ 0 ] ; localB ->
B_22_16_0 [ 0 ] . im = localB -> B_22_15_0 [ 0 ] ; localB -> B_22_16_0 [ 1 ]
. re = localB -> B_22_7_0 [ 1 ] ; localB -> B_22_16_0 [ 1 ] . im = localB ->
B_22_15_0 [ 1 ] ; localB -> B_22_16_0 [ 2 ] . re = localB -> B_22_7_0 [ 2 ] ;
localB -> B_22_16_0 [ 2 ] . im = localB -> B_22_15_0 [ 2 ] ; rtb_B_22_18_0 =
muDoubleScalarSin ( localP -> P_15 * ssGetTaskTime ( S , 0 ) + localP -> P_16
) * localP -> P_13 + localP -> P_14 ; localB -> B_22_19_0 [ 0 ] = rtu_In *
rtb_B_22_18_0 ; localB -> B_22_19_0 [ 1 ] = rtu_In_k [ 0 ] * rtb_B_22_18_0 ;
localB -> B_22_19_0 [ 2 ] = rtu_In_k [ 1 ] * rtb_B_22_18_0 ; rtb_B_22_18_0 =
muDoubleScalarSin ( localP -> P_19 * ssGetTaskTime ( S , 0 ) + localP -> P_20
) * localP -> P_17 + localP -> P_18 ; localB -> B_22_21_0 [ 0 ] = rtu_In *
rtb_B_22_18_0 ; localB -> B_22_21_0 [ 1 ] = rtu_In_k [ 0 ] * rtb_B_22_18_0 ;
localB -> B_22_21_0 [ 2 ] = rtu_In_k [ 1 ] * rtb_B_22_18_0 ; localB ->
B_22_22_0 [ 0 ] = localP -> P_21 * muDoubleScalarHypot ( localB -> B_22_16_0
[ 0 ] . re , localB -> B_22_16_0 [ 0 ] . im ) ; localB -> B_22_22_0 [ 1 ] =
localP -> P_21 * muDoubleScalarHypot ( localB -> B_22_16_0 [ 1 ] . re ,
localB -> B_22_16_0 [ 1 ] . im ) ; localB -> B_22_22_0 [ 2 ] = localP -> P_21
* muDoubleScalarHypot ( localB -> B_22_16_0 [ 2 ] . re , localB -> B_22_16_0
[ 2 ] . im ) ; if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( localDW ->
RMS_SubsysRanBC ) ; } } } void InverterModulesInSeries2016a_RMS_Update (
SimStruct * S , B_RMS_InverterModulesInSeries2016a_T * localB ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ,
P_RMS_InverterModulesInSeries2016a_T * localP ) { int32_T isHit ; if (
localDW -> RMS_MODE ) { { real_T * * uBuffer = ( real_T * * ) & localDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * *
) & localDW -> TransportDelay_PWORK . TUbufferPtrs [ 3 ] ; real_T simTime =
ssGetT ( S ) ; localDW -> TransportDelay_IWORK . Head [ 0 ] = ( ( localDW ->
TransportDelay_IWORK . Head [ 0 ] < ( localDW -> TransportDelay_IWORK .
CircularBufSize [ 0 ] - 1 ) ) ? ( localDW -> TransportDelay_IWORK . Head [ 0
] + 1 ) : 0 ) ; if ( localDW -> TransportDelay_IWORK . Head [ 0 ] == localDW
-> TransportDelay_IWORK . Tail [ 0 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize [ 0 ] , & localDW ->
TransportDelay_IWORK . Tail [ 0 ] , & localDW -> TransportDelay_IWORK . Head
[ 0 ] , & localDW -> TransportDelay_IWORK . Last [ 0 ] , simTime - localP ->
P_4 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & localDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ localDW
-> TransportDelay_IWORK . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ localDW
-> TransportDelay_IWORK . Head [ 0 ] ] = localB -> B_22_0_0 [ 0 ] ; localDW
-> TransportDelay_IWORK . Head [ 1 ] = ( ( localDW -> TransportDelay_IWORK .
Head [ 1 ] < ( localDW -> TransportDelay_IWORK . CircularBufSize [ 1 ] - 1 )
) ? ( localDW -> TransportDelay_IWORK . Head [ 1 ] + 1 ) : 0 ) ; if ( localDW
-> TransportDelay_IWORK . Head [ 1 ] == localDW -> TransportDelay_IWORK .
Tail [ 1 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize [ 1 ] , & localDW ->
TransportDelay_IWORK . Tail [ 1 ] , & localDW -> TransportDelay_IWORK . Head
[ 1 ] , & localDW -> TransportDelay_IWORK . Last [ 1 ] , simTime - localP ->
P_4 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & localDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ localDW
-> TransportDelay_IWORK . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ localDW
-> TransportDelay_IWORK . Head [ 1 ] ] = localB -> B_22_0_0 [ 1 ] ; localDW
-> TransportDelay_IWORK . Head [ 2 ] = ( ( localDW -> TransportDelay_IWORK .
Head [ 2 ] < ( localDW -> TransportDelay_IWORK . CircularBufSize [ 2 ] - 1 )
) ? ( localDW -> TransportDelay_IWORK . Head [ 2 ] + 1 ) : 0 ) ; if ( localDW
-> TransportDelay_IWORK . Head [ 2 ] == localDW -> TransportDelay_IWORK .
Tail [ 2 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize [ 2 ] , & localDW ->
TransportDelay_IWORK . Tail [ 2 ] , & localDW -> TransportDelay_IWORK . Head
[ 2 ] , & localDW -> TransportDelay_IWORK . Last [ 2 ] , simTime - localP ->
P_4 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & localDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ localDW ->
TransportDelay_IWORK . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ localDW ->
TransportDelay_IWORK . Head [ 2 ] ] = localB -> B_22_0_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localDW ->
Memory_PreviousInput [ 0 ] = localB -> B_22_7_0 [ 0 ] ; localDW ->
Memory_PreviousInput [ 1 ] = localB -> B_22_7_0 [ 1 ] ; localDW ->
Memory_PreviousInput [ 2 ] = localB -> B_22_7_0 [ 2 ] ; } { real_T * *
uBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK_i . TUbufferPtrs [
0 ] ; real_T * * tBuffer = ( real_T * * ) & localDW -> TransportDelay_PWORK_i
. TUbufferPtrs [ 3 ] ; real_T simTime = ssGetT ( S ) ; localDW ->
TransportDelay_IWORK_d . Head [ 0 ] = ( ( localDW -> TransportDelay_IWORK_d .
Head [ 0 ] < ( localDW -> TransportDelay_IWORK_d . CircularBufSize [ 0 ] - 1
) ) ? ( localDW -> TransportDelay_IWORK_d . Head [ 0 ] + 1 ) : 0 ) ; if (
localDW -> TransportDelay_IWORK_d . Head [ 0 ] == localDW ->
TransportDelay_IWORK_d . Tail [ 0 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK_d . CircularBufSize [ 0 ] , & localDW ->
TransportDelay_IWORK_d . Tail [ 0 ] , & localDW -> TransportDelay_IWORK_d .
Head [ 0 ] , & localDW -> TransportDelay_IWORK_d . Last [ 0 ] , simTime -
localP -> P_9 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , &
localDW -> TransportDelay_IWORK_d . MaxNewBufSize ) ) { ssSetErrorStatus ( S
, "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [
localDW -> TransportDelay_IWORK_d . Head [ 0 ] ] = simTime ; ( * uBuffer ++ )
[ localDW -> TransportDelay_IWORK_d . Head [ 0 ] ] = localB -> B_22_8_0 [ 0 ]
; localDW -> TransportDelay_IWORK_d . Head [ 1 ] = ( ( localDW ->
TransportDelay_IWORK_d . Head [ 1 ] < ( localDW -> TransportDelay_IWORK_d .
CircularBufSize [ 1 ] - 1 ) ) ? ( localDW -> TransportDelay_IWORK_d . Head [
1 ] + 1 ) : 0 ) ; if ( localDW -> TransportDelay_IWORK_d . Head [ 1 ] ==
localDW -> TransportDelay_IWORK_d . Tail [ 1 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK_d . CircularBufSize [ 1 ] , & localDW ->
TransportDelay_IWORK_d . Tail [ 1 ] , & localDW -> TransportDelay_IWORK_d .
Head [ 1 ] , & localDW -> TransportDelay_IWORK_d . Last [ 1 ] , simTime -
localP -> P_9 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , &
localDW -> TransportDelay_IWORK_d . MaxNewBufSize ) ) { ssSetErrorStatus ( S
, "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [
localDW -> TransportDelay_IWORK_d . Head [ 1 ] ] = simTime ; ( * uBuffer ++ )
[ localDW -> TransportDelay_IWORK_d . Head [ 1 ] ] = localB -> B_22_8_0 [ 1 ]
; localDW -> TransportDelay_IWORK_d . Head [ 2 ] = ( ( localDW ->
TransportDelay_IWORK_d . Head [ 2 ] < ( localDW -> TransportDelay_IWORK_d .
CircularBufSize [ 2 ] - 1 ) ) ? ( localDW -> TransportDelay_IWORK_d . Head [
2 ] + 1 ) : 0 ) ; if ( localDW -> TransportDelay_IWORK_d . Head [ 2 ] ==
localDW -> TransportDelay_IWORK_d . Tail [ 2 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK_d . CircularBufSize [ 2 ] , & localDW ->
TransportDelay_IWORK_d . Tail [ 2 ] , & localDW -> TransportDelay_IWORK_d .
Head [ 2 ] , & localDW -> TransportDelay_IWORK_d . Last [ 2 ] , simTime -
localP -> P_9 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , &
localDW -> TransportDelay_IWORK_d . MaxNewBufSize ) ) { ssSetErrorStatus ( S
, "tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ localDW
-> TransportDelay_IWORK_d . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ localDW
-> TransportDelay_IWORK_d . Head [ 2 ] ] = localB -> B_22_8_0 [ 2 ] ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localDW ->
Memory_PreviousInput_m [ 0 ] = localB -> B_22_15_0 [ 0 ] ; localDW ->
Memory_PreviousInput_m [ 1 ] = localB -> B_22_15_0 [ 1 ] ; localDW ->
Memory_PreviousInput_m [ 2 ] = localB -> B_22_15_0 [ 2 ] ; } } } void
InverterModulesInSeries2016a_RMS_Deriv ( SimStruct * S ,
B_RMS_InverterModulesInSeries2016a_T * localB ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ,
XDot_RMS_InverterModulesInSeries2016a_T * localXdot ) { if ( localDW ->
RMS_MODE ) { localXdot -> integrator_CSTATE_oy [ 0 ] = localB -> B_22_19_0 [
0 ] ; localXdot -> integrator_CSTATE_aa [ 0 ] = localB -> B_22_21_0 [ 0 ] ;
localXdot -> integrator_CSTATE_oy [ 1 ] = localB -> B_22_19_0 [ 1 ] ;
localXdot -> integrator_CSTATE_aa [ 1 ] = localB -> B_22_21_0 [ 1 ] ;
localXdot -> integrator_CSTATE_oy [ 2 ] = localB -> B_22_19_0 [ 2 ] ;
localXdot -> integrator_CSTATE_aa [ 2 ] = localB -> B_22_21_0 [ 2 ] ; } else
{ { real_T * dx ; int_T i ; dx = & ( localXdot -> integrator_CSTATE_oy [ 0 ]
) ; for ( i = 0 ; i < 6 ; i ++ ) { dx [ i ] = 0.0 ; } } } } void
InverterModulesInSeries2016a_RMS_Term ( SimStruct * const S ) { } void
InverterModulesInSeries2016a_TrueRMS_Init ( SimStruct * S ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
P_TrueRMS_InverterModulesInSeries2016a_T * localP ,
X_TrueRMS_InverterModulesInSeries2016a_T * localX ) { localX ->
integrator_CSTATE_cc [ 0 ] = localP -> P_2 ; localDW -> Memory_PreviousInput
[ 0 ] = localP -> P_6 ; localB -> B_24_10_0 [ 0 ] = localP -> P_1 ; localX ->
integrator_CSTATE_cc [ 1 ] = localP -> P_2 ; localDW -> Memory_PreviousInput
[ 1 ] = localP -> P_6 ; localB -> B_24_10_0 [ 1 ] = localP -> P_1 ; localX ->
integrator_CSTATE_cc [ 2 ] = localP -> P_2 ; localDW -> Memory_PreviousInput
[ 2 ] = localP -> P_6 ; localB -> B_24_10_0 [ 2 ] = localP -> P_1 ; } void
InverterModulesInSeries2016a_TrueRMS_Disable ( SimStruct * S ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ) { localDW ->
TrueRMS_MODE = false ; } void InverterModulesInSeries2016a_TrueRMS (
SimStruct * S , boolean_T rtu_Enable , real_T rtu_In , const real_T rtu_In_j
[ 2 ] , B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
P_TrueRMS_InverterModulesInSeries2016a_T * localP ,
X_TrueRMS_InverterModulesInSeries2016a_T * localX ,
XDis_TrueRMS_InverterModulesInSeries2016a_T * localXdis ) { int32_T isHit ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && (
ssIsMajorTimeStep ( S ) != 0 ) ) { if ( rtu_Enable ) { if ( ! localDW ->
TrueRMS_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( void ) memset ( & (
localXdis -> integrator_CSTATE_cc ) , 0 , 3 * sizeof ( boolean_T ) ) ;
localDW -> TrueRMS_MODE = true ; } } else { if ( localDW -> TrueRMS_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & (
localXdis -> integrator_CSTATE_cc ) , 1 , 3 * sizeof ( boolean_T ) ) ;
InverterModulesInSeries2016a_TrueRMS_Disable ( S , localDW ) ; } } } if (
localDW -> TrueRMS_MODE ) { localB -> B_24_1_0 [ 0 ] = localX ->
integrator_CSTATE_cc [ 0 ] ; localB -> B_24_1_0 [ 1 ] = localX ->
integrator_CSTATE_cc [ 1 ] ; localB -> B_24_1_0 [ 2 ] = localX ->
integrator_CSTATE_cc [ 2 ] ; { real_T * * uBuffer = ( real_T * * ) & localDW
-> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & localDW -> TransportDelay_PWORK . TUbufferPtrs [ 3 ] ; real_T simTime
= ssGetT ( S ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & localB ->
B_24_2_0 [ 0 ] ; int_T * iw_Tail = & localDW -> TransportDelay_IWORK . Tail [
0 ] ; int_T * iw_Head = & localDW -> TransportDelay_IWORK . Head [ 0 ] ;
int_T * iw_Last = & localDW -> TransportDelay_IWORK . Last [ 0 ] ; int_T *
iw_CircularBufSize = & localDW -> TransportDelay_IWORK . CircularBufSize [ 0
] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( ( localP -> P_3 > 0.0 )
? localP -> P_3 : 0.0 ) ; tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail
[ i1 ] , iw_Head [ i1 ] , localP -> P_4 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; tBuffer ++ ; uBuffer ++ ; } } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { localB -> B_24_3_0 = localP -> P_5 ; localB -> B_24_4_0 [ 0
] = localDW -> Memory_PreviousInput [ 0 ] ; localB -> B_24_4_0 [ 1 ] =
localDW -> Memory_PreviousInput [ 1 ] ; localB -> B_24_4_0 [ 2 ] = localDW ->
Memory_PreviousInput [ 2 ] ; } if ( ssGetT ( S ) >= localB -> B_24_3_0 ) {
localB -> B_23_0_0 [ 0 ] = localB -> B_24_1_0 [ 0 ] - localB -> B_24_2_0 [ 0
] ; localB -> B_23_1_0 [ 0 ] = localP -> P_0 * localB -> B_23_0_0 [ 0 ] ;
localB -> B_24_7_0 [ 0 ] = localB -> B_23_1_0 [ 0 ] ; localB -> B_23_0_0 [ 1
] = localB -> B_24_1_0 [ 1 ] - localB -> B_24_2_0 [ 1 ] ; localB -> B_23_1_0
[ 1 ] = localP -> P_0 * localB -> B_23_0_0 [ 1 ] ; localB -> B_24_7_0 [ 1 ] =
localB -> B_23_1_0 [ 1 ] ; localB -> B_23_0_0 [ 2 ] = localB -> B_24_1_0 [ 2
] - localB -> B_24_2_0 [ 2 ] ; localB -> B_23_1_0 [ 2 ] = localP -> P_0 *
localB -> B_23_0_0 [ 2 ] ; localB -> B_24_7_0 [ 2 ] = localB -> B_23_1_0 [ 2
] ; } else { localB -> B_24_7_0 [ 0 ] = localB -> B_24_4_0 [ 0 ] ; localB ->
B_24_7_0 [ 1 ] = localB -> B_24_4_0 [ 1 ] ; localB -> B_24_7_0 [ 2 ] = localB
-> B_24_4_0 [ 2 ] ; } localB -> B_24_8_0 [ 0 ] = rtu_In * rtu_In ; localB ->
B_24_8_0 [ 1 ] = rtu_In_j [ 0 ] * rtu_In_j [ 0 ] ; localB -> B_24_8_0 [ 2 ] =
rtu_In_j [ 1 ] * rtu_In_j [ 1 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) {
localDW -> Saturationtoavoidnegativesqrt_MODE [ 0 ] = localB -> B_24_7_0 [ 0
] >= localP -> P_7 ? 1 : localB -> B_24_7_0 [ 0 ] > localP -> P_8 ? 0 : - 1 ;
localDW -> Saturationtoavoidnegativesqrt_MODE [ 1 ] = localB -> B_24_7_0 [ 1
] >= localP -> P_7 ? 1 : localB -> B_24_7_0 [ 1 ] > localP -> P_8 ? 0 : - 1 ;
localDW -> Saturationtoavoidnegativesqrt_MODE [ 2 ] = localB -> B_24_7_0 [ 2
] >= localP -> P_7 ? 1 : localB -> B_24_7_0 [ 2 ] > localP -> P_8 ? 0 : - 1 ;
} localB -> B_24_9_0 [ 0 ] = localDW -> Saturationtoavoidnegativesqrt_MODE [
0 ] == 1 ? localP -> P_7 : localDW -> Saturationtoavoidnegativesqrt_MODE [ 0
] == - 1 ? localP -> P_8 : localB -> B_24_7_0 [ 0 ] ; localB -> B_24_9_0 [ 1
] = localDW -> Saturationtoavoidnegativesqrt_MODE [ 1 ] == 1 ? localP -> P_7
: localDW -> Saturationtoavoidnegativesqrt_MODE [ 1 ] == - 1 ? localP -> P_8
: localB -> B_24_7_0 [ 1 ] ; localB -> B_24_9_0 [ 2 ] = localDW ->
Saturationtoavoidnegativesqrt_MODE [ 2 ] == 1 ? localP -> P_7 : localDW ->
Saturationtoavoidnegativesqrt_MODE [ 2 ] == - 1 ? localP -> P_8 : localB ->
B_24_7_0 [ 2 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( localDW ->
Sqrt_DWORK1 != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
localDW -> Sqrt_DWORK1 = 0 ; } localB -> B_24_10_0 [ 0 ] = muDoubleScalarSqrt
( localB -> B_24_9_0 [ 0 ] ) ; localB -> B_24_10_0 [ 1 ] = muDoubleScalarSqrt
( localB -> B_24_9_0 [ 1 ] ) ; localB -> B_24_10_0 [ 2 ] = muDoubleScalarSqrt
( localB -> B_24_9_0 [ 2 ] ) ; srUpdateBC ( localDW -> TrueRMS_SubsysRanBC )
; } else { if ( localB -> B_24_9_0 [ 0 ] < 0.0 ) { localB -> B_24_10_0 [ 0 ]
= - muDoubleScalarSqrt ( muDoubleScalarAbs ( localB -> B_24_9_0 [ 0 ] ) ) ; }
else { localB -> B_24_10_0 [ 0 ] = muDoubleScalarSqrt ( localB -> B_24_9_0 [
0 ] ) ; } if ( localB -> B_24_9_0 [ 0 ] < 0.0 ) { localDW -> Sqrt_DWORK1 = 1
; } if ( localB -> B_24_9_0 [ 1 ] < 0.0 ) { localB -> B_24_10_0 [ 1 ] = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( localB -> B_24_9_0 [ 1 ] ) ) ; }
else { localB -> B_24_10_0 [ 1 ] = muDoubleScalarSqrt ( localB -> B_24_9_0 [
1 ] ) ; } if ( localB -> B_24_9_0 [ 1 ] < 0.0 ) { localDW -> Sqrt_DWORK1 = 1
; } if ( localB -> B_24_9_0 [ 2 ] < 0.0 ) { localB -> B_24_10_0 [ 2 ] = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( localB -> B_24_9_0 [ 2 ] ) ) ; }
else { localB -> B_24_10_0 [ 2 ] = muDoubleScalarSqrt ( localB -> B_24_9_0 [
2 ] ) ; } if ( localB -> B_24_9_0 [ 2 ] < 0.0 ) { localDW -> Sqrt_DWORK1 = 1
; } } } } void InverterModulesInSeries2016a_TrueRMS_Update ( SimStruct * S ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
P_TrueRMS_InverterModulesInSeries2016a_T * localP ) { int32_T isHit ; if (
localDW -> TrueRMS_MODE ) { { real_T * * uBuffer = ( real_T * * ) & localDW
-> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T
* * ) & localDW -> TransportDelay_PWORK . TUbufferPtrs [ 3 ] ; real_T simTime
= ssGetT ( S ) ; localDW -> TransportDelay_IWORK . Head [ 0 ] = ( ( localDW
-> TransportDelay_IWORK . Head [ 0 ] < ( localDW -> TransportDelay_IWORK .
CircularBufSize [ 0 ] - 1 ) ) ? ( localDW -> TransportDelay_IWORK . Head [ 0
] + 1 ) : 0 ) ; if ( localDW -> TransportDelay_IWORK . Head [ 0 ] == localDW
-> TransportDelay_IWORK . Tail [ 0 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize [ 0 ] , & localDW ->
TransportDelay_IWORK . Tail [ 0 ] , & localDW -> TransportDelay_IWORK . Head
[ 0 ] , & localDW -> TransportDelay_IWORK . Last [ 0 ] , simTime - localP ->
P_3 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & localDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ localDW
-> TransportDelay_IWORK . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ localDW
-> TransportDelay_IWORK . Head [ 0 ] ] = localB -> B_24_1_0 [ 0 ] ; localDW
-> TransportDelay_IWORK . Head [ 1 ] = ( ( localDW -> TransportDelay_IWORK .
Head [ 1 ] < ( localDW -> TransportDelay_IWORK . CircularBufSize [ 1 ] - 1 )
) ? ( localDW -> TransportDelay_IWORK . Head [ 1 ] + 1 ) : 0 ) ; if ( localDW
-> TransportDelay_IWORK . Head [ 1 ] == localDW -> TransportDelay_IWORK .
Tail [ 1 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize [ 1 ] , & localDW ->
TransportDelay_IWORK . Tail [ 1 ] , & localDW -> TransportDelay_IWORK . Head
[ 1 ] , & localDW -> TransportDelay_IWORK . Last [ 1 ] , simTime - localP ->
P_3 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & localDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ localDW
-> TransportDelay_IWORK . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ localDW
-> TransportDelay_IWORK . Head [ 1 ] ] = localB -> B_24_1_0 [ 1 ] ; localDW
-> TransportDelay_IWORK . Head [ 2 ] = ( ( localDW -> TransportDelay_IWORK .
Head [ 2 ] < ( localDW -> TransportDelay_IWORK . CircularBufSize [ 2 ] - 1 )
) ? ( localDW -> TransportDelay_IWORK . Head [ 2 ] + 1 ) : 0 ) ; if ( localDW
-> TransportDelay_IWORK . Head [ 2 ] == localDW -> TransportDelay_IWORK .
Tail [ 2 ] ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & localDW ->
TransportDelay_IWORK . CircularBufSize [ 2 ] , & localDW ->
TransportDelay_IWORK . Tail [ 2 ] , & localDW -> TransportDelay_IWORK . Head
[ 2 ] , & localDW -> TransportDelay_IWORK . Last [ 2 ] , simTime - localP ->
P_3 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & localDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ localDW ->
TransportDelay_IWORK . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ localDW ->
TransportDelay_IWORK . Head [ 2 ] ] = localB -> B_24_1_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { localDW ->
Memory_PreviousInput [ 0 ] = localB -> B_24_7_0 [ 0 ] ; localDW ->
Memory_PreviousInput [ 1 ] = localB -> B_24_7_0 [ 1 ] ; localDW ->
Memory_PreviousInput [ 2 ] = localB -> B_24_7_0 [ 2 ] ; } } } void
InverterModulesInSeries2016a_TrueRMS_Deriv ( SimStruct * S ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
XDot_TrueRMS_InverterModulesInSeries2016a_T * localXdot ) { if ( localDW ->
TrueRMS_MODE ) { localXdot -> integrator_CSTATE_cc [ 0 ] = localB -> B_24_8_0
[ 0 ] ; localXdot -> integrator_CSTATE_cc [ 1 ] = localB -> B_24_8_0 [ 1 ] ;
localXdot -> integrator_CSTATE_cc [ 2 ] = localB -> B_24_8_0 [ 2 ] ; } else {
{ real_T * dx ; int_T i ; dx = & ( localXdot -> integrator_CSTATE_cc [ 0 ] )
; for ( i = 0 ; i < 3 ; i ++ ) { dx [ i ] = 0.0 ; } } } } void
InverterModulesInSeries2016a_TrueRMS_ZC ( SimStruct * S ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
P_TrueRMS_InverterModulesInSeries2016a_T * localP ,
ZCV_TrueRMS_InverterModulesInSeries2016a_T * localZCSV ) { if ( localDW ->
TrueRMS_MODE ) { localZCSV -> Saturationtoavoidnegativesqrt_UprLim_ZC [ 0 ] =
localB -> B_24_7_0 [ 0 ] - localP -> P_7 ; localZCSV ->
Saturationtoavoidnegativesqrt_LwrLim_ZC [ 0 ] = localB -> B_24_7_0 [ 0 ] -
localP -> P_8 ; localZCSV -> Saturationtoavoidnegativesqrt_UprLim_ZC [ 1 ] =
localB -> B_24_7_0 [ 1 ] - localP -> P_7 ; localZCSV ->
Saturationtoavoidnegativesqrt_LwrLim_ZC [ 1 ] = localB -> B_24_7_0 [ 1 ] -
localP -> P_8 ; localZCSV -> Saturationtoavoidnegativesqrt_UprLim_ZC [ 2 ] =
localB -> B_24_7_0 [ 2 ] - localP -> P_7 ; localZCSV ->
Saturationtoavoidnegativesqrt_LwrLim_ZC [ 2 ] = localB -> B_24_7_0 [ 2 ] -
localP -> P_8 ; } else { { real_T * zcsv = & ( localZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC [ 0 ] ) ; int_T i ; for ( i = 0 ; i <
6 ; i ++ ) { zcsv [ i ] = 0.0 ; } } } } void
InverterModulesInSeries2016a_TrueRMS_Term ( SimStruct * const S ) { } static
void mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_33_256_0 ; real_T
B_33_264_0 ; real_T B_33_274_0 ; real_T B_33_282_0 ; real_T B_33_293_0 ;
real_T B_33_301_0 ; real_T B_33_311_0 ; real_T B_33_319_0 ; real_T B_33_755_0
; real_T B_33_756_0 ; real_T rtb_B_33_210_0 ; real_T rtb_B_33_195_0 ; real_T
rtb_B_33_178_0 ; real_T rtb_B_33_163_0 ; real_T rtb_B_33_146_0 ; real_T
rtb_B_33_131_0 ; real_T rtb_B_33_103_0 ; real_T rtb_B_33_88_0 ; real_T
rtb_B_33_71_0 ; real_T rtb_B_33_56_0 ; real_T rtb_B_33_39_0 ; real_T
rtb_B_33_24_0 ; real_T rtb_B_33_11_0 ; boolean_T rtb_B_33_211_0 ; boolean_T
rtb_B_33_196_0 ; boolean_T rtb_B_33_179_0 ; boolean_T rtb_B_33_164_0 ;
boolean_T rtb_B_33_147_0 ; boolean_T rtb_B_33_132_0 ; boolean_T
rtb_B_33_104_0 ; boolean_T rtb_B_33_89_0 ; boolean_T rtb_B_33_72_0 ;
boolean_T rtb_B_33_57_0 ; boolean_T rtb_B_33_40_0 ; boolean_T rtb_B_33_25_0 ;
real_T rtb_B_33_204_0 ; real_T rtb_B_33_187_0 ; real_T rtb_B_33_172_0 ;
real_T rtb_B_33_155_0 ; real_T rtb_B_33_140_0 ; real_T rtb_B_33_112_0 ;
real_T rtb_B_33_97_0 ; real_T rtb_B_33_80_0 ; real_T rtb_B_33_65_0 ; real_T
rtb_B_33_48_0 ; real_T rtb_B_33_33_0 ; real_T rtb_B_33_5_0 ; int32_T isHit ;
B_InverterModulesInSeries2016a_T * _rtB ; P_InverterModulesInSeries2016a_T *
_rtP ; X_InverterModulesInSeries2016a_T * _rtX ;
DW_InverterModulesInSeries2016a_T * _rtDW ; _rtDW = ( (
DW_InverterModulesInSeries2016a_T * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
X_InverterModulesInSeries2016a_T * ) ssGetContStates ( S ) ) ; _rtP = ( (
P_InverterModulesInSeries2016a_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInSeries2016a_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { rtb_B_33_5_0 = _rtP -> P_29
; _rtB -> B_33_6_0 = _rtB -> B_33_4_0 * _rtP -> P_29 ; } _rtB -> B_33_8_0 =
muDoubleScalarSin ( _rtP -> P_33 * ssGetTaskTime ( S , 0 ) + _rtP -> P_34 ) *
_rtP -> P_31 + _rtP -> P_32 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_33_10_0 = _rtP -> P_35 ; } rtb_B_33_11_0 = ssGetT (
S ) + _rtB -> B_33_10_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_33_12_0 = _rtP -> P_36 ; } rtb_B_33_11_0 = look1_pbinlxpw (
_rtP -> P_37 * muDoubleScalarRem ( rtb_B_33_11_0 , _rtB -> B_33_12_0 ) , _rtP
-> P_39 , _rtP -> P_38 , & _rtDW -> m_bpIndex , 2U ) ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_16_0 = _rtP -> P_40 ; } _rtB
-> B_33_17_0 = rtb_B_33_11_0 - _rtB -> B_33_16_0 ; _rtB -> B_33_18_0 = _rtB
-> B_33_8_0 - _rtB -> B_33_17_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode =
( _rtB -> B_33_18_0 > InverterModulesInSeries2016a_rtC ( S ) -> B_33_19_0 ) ;
} if ( _rtDW -> Compare_Mode ) { _rtB -> B_33_22_0 = _rtB -> B_33_7_0 ; }
else { _rtB -> B_33_22_0 = _rtB -> B_33_21_0 ; } } isHit = ssIsSampleHit ( S
, 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_23_0 = _rtDW ->
DelayInput2_DSTATE ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { rtb_B_33_24_0 = _rtB -> B_33_22_0 - _rtB -> B_33_23_0 ; rtb_B_33_25_0 = (
rtb_B_33_24_0 > _rtB -> B_33_6_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_33_27_0 = _rtB -> B_33_26_0 * rtb_B_33_5_0 ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_33_25_0
) { rtb_B_33_24_0 = _rtB -> B_33_6_0 ; } else { if ( rtb_B_33_24_0 < _rtB ->
B_33_27_0 ) { rtb_B_33_24_0 = _rtB -> B_33_27_0 ; } } _rtB -> B_33_30_0 =
rtb_B_33_24_0 + _rtB -> B_33_23_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_33_31_0 [ 0 ] = _rtB -> B_33_30_0 ; _rtB ->
B_33_31_0 [ 1 ] = 0.0 ; _rtB -> B_33_31_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_1_1_1_discrete [ 0 ] = ! ( _rtB -> B_33_31_0 [ 0 ] == _rtDW ->
INPUT_1_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_1_1_1_discrete [ 1 ] = _rtB ->
B_33_31_0 [ 0 ] ; _rtB -> B_33_31_0 [ 0 ] = _rtDW -> INPUT_1_1_1_discrete [ 1
] ; _rtB -> B_33_31_0 [ 3 ] = _rtDW -> INPUT_1_1_1_discrete [ 0 ] ;
rtb_B_33_33_0 = _rtP -> P_46 ; _rtB -> B_33_34_0 = _rtB -> B_33_32_0 * _rtP
-> P_46 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_g = ( _rtB ->
B_33_18_0 < InverterModulesInSeries2016a_rtC ( S ) -> B_33_35_0 ) ; } if (
_rtDW -> Compare_Mode_g ) { _rtB -> B_33_37_0 = _rtB -> B_33_7_0 ; } else {
_rtB -> B_33_37_0 = _rtB -> B_33_21_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0
) ; if ( isHit != 0 ) { _rtB -> B_33_38_0 = _rtDW -> DelayInput2_DSTATE_c ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_33_39_0 =
_rtB -> B_33_37_0 - _rtB -> B_33_38_0 ; rtb_B_33_40_0 = ( rtb_B_33_39_0 >
_rtB -> B_33_34_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_42_0 = _rtB -> B_33_41_0 * rtb_B_33_33_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_33_40_0 ) {
rtb_B_33_39_0 = _rtB -> B_33_34_0 ; } else { if ( rtb_B_33_39_0 < _rtB ->
B_33_42_0 ) { rtb_B_33_39_0 = _rtB -> B_33_42_0 ; } } _rtB -> B_33_45_0 =
rtb_B_33_39_0 + _rtB -> B_33_38_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_33_46_0 [ 0 ] = _rtB -> B_33_45_0 ; _rtB ->
B_33_46_0 [ 1 ] = 0.0 ; _rtB -> B_33_46_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_2_1_1_discrete [ 0 ] = ! ( _rtB -> B_33_46_0 [ 0 ] == _rtDW ->
INPUT_2_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_2_1_1_discrete [ 1 ] = _rtB ->
B_33_46_0 [ 0 ] ; _rtB -> B_33_46_0 [ 0 ] = _rtDW -> INPUT_2_1_1_discrete [ 1
] ; _rtB -> B_33_46_0 [ 3 ] = _rtDW -> INPUT_2_1_1_discrete [ 0 ] ;
rtb_B_33_48_0 = _rtP -> P_51 ; _rtB -> B_33_49_0 = _rtB -> B_33_47_0 * _rtP
-> P_51 ; } _rtB -> B_33_50_0 = muDoubleScalarSin ( _rtP -> P_54 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_55 ) * _rtP -> P_52 + _rtP -> P_53 ; _rtB
-> B_33_51_0 = _rtB -> B_33_50_0 - _rtB -> B_33_17_0 ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) {
_rtDW -> Compare_Mode_p = ( _rtB -> B_33_51_0 >
InverterModulesInSeries2016a_rtC ( S ) -> B_33_52_0 ) ; } if ( _rtDW ->
Compare_Mode_p ) { _rtB -> B_33_54_0 = _rtB -> B_33_7_0 ; } else { _rtB ->
B_33_54_0 = _rtB -> B_33_21_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_33_55_0 = _rtDW -> DelayInput2_DSTATE_d ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_33_56_0 = _rtB ->
B_33_54_0 - _rtB -> B_33_55_0 ; rtb_B_33_57_0 = ( rtb_B_33_56_0 > _rtB ->
B_33_49_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_33_59_0 = _rtB -> B_33_58_0 * rtb_B_33_48_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_33_57_0 ) {
rtb_B_33_56_0 = _rtB -> B_33_49_0 ; } else { if ( rtb_B_33_56_0 < _rtB ->
B_33_59_0 ) { rtb_B_33_56_0 = _rtB -> B_33_59_0 ; } } _rtB -> B_33_62_0 =
rtb_B_33_56_0 + _rtB -> B_33_55_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_33_63_0 [ 0 ] = _rtB -> B_33_62_0 ; _rtB ->
B_33_63_0 [ 1 ] = 0.0 ; _rtB -> B_33_63_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_3_1_1_discrete [ 0 ] = ! ( _rtB -> B_33_63_0 [ 0 ] == _rtDW ->
INPUT_3_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_3_1_1_discrete [ 1 ] = _rtB ->
B_33_63_0 [ 0 ] ; _rtB -> B_33_63_0 [ 0 ] = _rtDW -> INPUT_3_1_1_discrete [ 1
] ; _rtB -> B_33_63_0 [ 3 ] = _rtDW -> INPUT_3_1_1_discrete [ 0 ] ;
rtb_B_33_65_0 = _rtP -> P_60 ; _rtB -> B_33_66_0 = _rtB -> B_33_64_0 * _rtP
-> P_60 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_j = ( _rtB ->
B_33_51_0 < InverterModulesInSeries2016a_rtC ( S ) -> B_33_67_0 ) ; } if (
_rtDW -> Compare_Mode_j ) { _rtB -> B_33_69_0 = _rtB -> B_33_7_0 ; } else {
_rtB -> B_33_69_0 = _rtB -> B_33_21_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0
) ; if ( isHit != 0 ) { _rtB -> B_33_70_0 = _rtDW -> DelayInput2_DSTATE_f ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_33_71_0 =
_rtB -> B_33_69_0 - _rtB -> B_33_70_0 ; rtb_B_33_72_0 = ( rtb_B_33_71_0 >
_rtB -> B_33_66_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_74_0 = _rtB -> B_33_73_0 * rtb_B_33_65_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_33_72_0 ) {
rtb_B_33_71_0 = _rtB -> B_33_66_0 ; } else { if ( rtb_B_33_71_0 < _rtB ->
B_33_74_0 ) { rtb_B_33_71_0 = _rtB -> B_33_74_0 ; } } _rtB -> B_33_77_0 =
rtb_B_33_71_0 + _rtB -> B_33_70_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_33_78_0 [ 0 ] = _rtB -> B_33_77_0 ; _rtB ->
B_33_78_0 [ 1 ] = 0.0 ; _rtB -> B_33_78_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_4_1_1_discrete [ 0 ] = ! ( _rtB -> B_33_78_0 [ 0 ] == _rtDW ->
INPUT_4_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_4_1_1_discrete [ 1 ] = _rtB ->
B_33_78_0 [ 0 ] ; _rtB -> B_33_78_0 [ 0 ] = _rtDW -> INPUT_4_1_1_discrete [ 1
] ; _rtB -> B_33_78_0 [ 3 ] = _rtDW -> INPUT_4_1_1_discrete [ 0 ] ;
rtb_B_33_80_0 = _rtP -> P_65 ; _rtB -> B_33_81_0 = _rtB -> B_33_79_0 * _rtP
-> P_65 ; } _rtB -> B_33_82_0 = muDoubleScalarSin ( _rtP -> P_68 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_69 ) * _rtP -> P_66 + _rtP -> P_67 ; _rtB
-> B_33_83_0 = _rtB -> B_33_82_0 - _rtB -> B_33_17_0 ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) {
_rtDW -> Compare_Mode_h = ( _rtB -> B_33_83_0 >
InverterModulesInSeries2016a_rtC ( S ) -> B_33_84_0 ) ; } if ( _rtDW ->
Compare_Mode_h ) { _rtB -> B_33_86_0 = _rtB -> B_33_7_0 ; } else { _rtB ->
B_33_86_0 = _rtB -> B_33_21_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_33_87_0 = _rtDW -> DelayInput2_DSTATE_n ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_33_88_0 = _rtB ->
B_33_86_0 - _rtB -> B_33_87_0 ; rtb_B_33_89_0 = ( rtb_B_33_88_0 > _rtB ->
B_33_81_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_33_91_0 = _rtB -> B_33_90_0 * rtb_B_33_80_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_33_89_0 ) {
rtb_B_33_88_0 = _rtB -> B_33_81_0 ; } else { if ( rtb_B_33_88_0 < _rtB ->
B_33_91_0 ) { rtb_B_33_88_0 = _rtB -> B_33_91_0 ; } } _rtB -> B_33_94_0 =
rtb_B_33_88_0 + _rtB -> B_33_87_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_33_95_0 [ 0 ] = _rtB -> B_33_94_0 ; _rtB ->
B_33_95_0 [ 1 ] = 0.0 ; _rtB -> B_33_95_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_5_1_1_discrete [ 0 ] = ! ( _rtB -> B_33_95_0 [ 0 ] == _rtDW ->
INPUT_5_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_5_1_1_discrete [ 1 ] = _rtB ->
B_33_95_0 [ 0 ] ; _rtB -> B_33_95_0 [ 0 ] = _rtDW -> INPUT_5_1_1_discrete [ 1
] ; _rtB -> B_33_95_0 [ 3 ] = _rtDW -> INPUT_5_1_1_discrete [ 0 ] ;
rtb_B_33_97_0 = _rtP -> P_74 ; _rtB -> B_33_98_0 = _rtB -> B_33_96_0 * _rtP
-> P_74 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_i = ( _rtB ->
B_33_83_0 < InverterModulesInSeries2016a_rtC ( S ) -> B_33_99_0 ) ; } if (
_rtDW -> Compare_Mode_i ) { _rtB -> B_33_101_0 = _rtB -> B_33_7_0 ; } else {
_rtB -> B_33_101_0 = _rtB -> B_33_21_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_33_102_0 = _rtDW -> DelayInput2_DSTATE_m
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_33_103_0
= _rtB -> B_33_101_0 - _rtB -> B_33_102_0 ; rtb_B_33_104_0 = ( rtb_B_33_103_0
> _rtB -> B_33_98_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_33_106_0 = _rtB -> B_33_105_0 * rtb_B_33_97_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_33_104_0 ) {
rtb_B_33_103_0 = _rtB -> B_33_98_0 ; } else { if ( rtb_B_33_103_0 < _rtB ->
B_33_106_0 ) { rtb_B_33_103_0 = _rtB -> B_33_106_0 ; } } _rtB -> B_33_109_0 =
rtb_B_33_103_0 + _rtB -> B_33_102_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_33_110_0 [ 0 ] = _rtB -> B_33_109_0 ; _rtB ->
B_33_110_0 [ 1 ] = 0.0 ; _rtB -> B_33_110_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_6_1_1_discrete [ 0 ] = ! ( _rtB -> B_33_110_0 [ 0 ] == _rtDW ->
INPUT_6_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_6_1_1_discrete [ 1 ] = _rtB ->
B_33_110_0 [ 0 ] ; _rtB -> B_33_110_0 [ 0 ] = _rtDW -> INPUT_6_1_1_discrete [
1 ] ; _rtB -> B_33_110_0 [ 3 ] = _rtDW -> INPUT_6_1_1_discrete [ 0 ] ;
rtb_B_33_112_0 = _rtP -> P_79 ; _rtB -> B_33_113_0 = _rtB -> B_33_111_0 *
_rtP -> P_79 ; } _rtB -> B_33_115_0 = muDoubleScalarSin ( _rtP -> P_83 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_84 ) * _rtP -> P_81 + _rtP -> P_82 ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_117_0
= _rtP -> P_85 ; } rtb_B_33_97_0 = ssGetT ( S ) + _rtB -> B_33_117_0 ; isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_119_0 = _rtP
-> P_86 ; } rtb_B_33_97_0 = look1_pbinlxpw ( _rtP -> P_87 * muDoubleScalarRem
( rtb_B_33_97_0 , _rtB -> B_33_119_0 ) , _rtP -> P_89 , _rtP -> P_88 , &
_rtDW -> m_bpIndex_a , 2U ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_33_123_0 = _rtP -> P_90 ; } _rtB -> B_33_124_0 =
rtb_B_33_97_0 - _rtB -> B_33_123_0 ; _rtB -> B_33_125_0 = _rtB -> B_33_115_0
- _rtB -> B_33_124_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_ja = ( _rtB
-> B_33_125_0 > InverterModulesInSeries2016a_rtC ( S ) -> B_33_126_0 ) ; } if
( _rtDW -> Compare_Mode_ja ) { _rtB -> B_33_129_0 = _rtB -> B_33_114_0 ; }
else { _rtB -> B_33_129_0 = _rtB -> B_33_128_0 ; } } isHit = ssIsSampleHit (
S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_130_0 = _rtDW ->
DelayInput2_DSTATE_dc ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { rtb_B_33_131_0 = _rtB -> B_33_129_0 - _rtB -> B_33_130_0 ;
rtb_B_33_132_0 = ( rtb_B_33_131_0 > _rtB -> B_33_113_0 ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_134_0 = _rtB
-> B_33_133_0 * rtb_B_33_112_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_33_132_0 ) { rtb_B_33_131_0 = _rtB -> B_33_113_0 ;
} else { if ( rtb_B_33_131_0 < _rtB -> B_33_134_0 ) { rtb_B_33_131_0 = _rtB
-> B_33_134_0 ; } } _rtB -> B_33_137_0 = rtb_B_33_131_0 + _rtB -> B_33_130_0
; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_33_138_0 [ 0 ] = _rtB -> B_33_137_0 ; _rtB -> B_33_138_0 [ 1 ] = 0.0 ; _rtB
-> B_33_138_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_7_1_1_discrete [ 0 ] = ! ( _rtB ->
B_33_138_0 [ 0 ] == _rtDW -> INPUT_7_1_1_discrete [ 1 ] ) ; _rtDW ->
INPUT_7_1_1_discrete [ 1 ] = _rtB -> B_33_138_0 [ 0 ] ; _rtB -> B_33_138_0 [
0 ] = _rtDW -> INPUT_7_1_1_discrete [ 1 ] ; _rtB -> B_33_138_0 [ 3 ] = _rtDW
-> INPUT_7_1_1_discrete [ 0 ] ; rtb_B_33_140_0 = _rtP -> P_96 ; _rtB ->
B_33_141_0 = _rtB -> B_33_139_0 * _rtP -> P_96 ; } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW
-> Compare_Mode_c = ( _rtB -> B_33_125_0 < InverterModulesInSeries2016a_rtC (
S ) -> B_33_142_0 ) ; } if ( _rtDW -> Compare_Mode_c ) { _rtB -> B_33_144_0 =
_rtB -> B_33_114_0 ; } else { _rtB -> B_33_144_0 = _rtB -> B_33_128_0 ; } }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_145_0
= _rtDW -> DelayInput2_DSTATE_dj ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { rtb_B_33_146_0 = _rtB -> B_33_144_0 - _rtB -> B_33_145_0 ;
rtb_B_33_147_0 = ( rtb_B_33_146_0 > _rtB -> B_33_141_0 ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_149_0 = _rtB
-> B_33_148_0 * rtb_B_33_140_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_33_147_0 ) { rtb_B_33_146_0 = _rtB -> B_33_141_0 ;
} else { if ( rtb_B_33_146_0 < _rtB -> B_33_149_0 ) { rtb_B_33_146_0 = _rtB
-> B_33_149_0 ; } } _rtB -> B_33_152_0 = rtb_B_33_146_0 + _rtB -> B_33_145_0
; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_33_153_0 [ 0 ] = _rtB -> B_33_152_0 ; _rtB -> B_33_153_0 [ 1 ] = 0.0 ; _rtB
-> B_33_153_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_8_1_1_discrete [ 0 ] = ! ( _rtB ->
B_33_153_0 [ 0 ] == _rtDW -> INPUT_8_1_1_discrete [ 1 ] ) ; _rtDW ->
INPUT_8_1_1_discrete [ 1 ] = _rtB -> B_33_153_0 [ 0 ] ; _rtB -> B_33_153_0 [
0 ] = _rtDW -> INPUT_8_1_1_discrete [ 1 ] ; _rtB -> B_33_153_0 [ 3 ] = _rtDW
-> INPUT_8_1_1_discrete [ 0 ] ; rtb_B_33_155_0 = _rtP -> P_101 ; _rtB ->
B_33_156_0 = _rtB -> B_33_154_0 * _rtP -> P_101 ; } _rtB -> B_33_157_0 =
muDoubleScalarSin ( _rtP -> P_104 * ssGetTaskTime ( S , 0 ) + _rtP -> P_105 )
* _rtP -> P_102 + _rtP -> P_103 ; _rtB -> B_33_158_0 = _rtB -> B_33_157_0 -
_rtB -> B_33_124_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_l = ( _rtB ->
B_33_158_0 > InverterModulesInSeries2016a_rtC ( S ) -> B_33_159_0 ) ; } if (
_rtDW -> Compare_Mode_l ) { _rtB -> B_33_161_0 = _rtB -> B_33_114_0 ; } else
{ _rtB -> B_33_161_0 = _rtB -> B_33_128_0 ; } } isHit = ssIsSampleHit ( S , 2
, 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_162_0 = _rtDW ->
DelayInput2_DSTATE_a ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { rtb_B_33_163_0 = _rtB -> B_33_161_0 - _rtB -> B_33_162_0 ;
rtb_B_33_164_0 = ( rtb_B_33_163_0 > _rtB -> B_33_156_0 ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_166_0 = _rtB
-> B_33_165_0 * rtb_B_33_155_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_33_164_0 ) { rtb_B_33_163_0 = _rtB -> B_33_156_0 ;
} else { if ( rtb_B_33_163_0 < _rtB -> B_33_166_0 ) { rtb_B_33_163_0 = _rtB
-> B_33_166_0 ; } } _rtB -> B_33_169_0 = rtb_B_33_163_0 + _rtB -> B_33_162_0
; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_33_170_0 [ 0 ] = _rtB -> B_33_169_0 ; _rtB -> B_33_170_0 [ 1 ] = 0.0 ; _rtB
-> B_33_170_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_9_1_1_discrete [ 0 ] = ! ( _rtB ->
B_33_170_0 [ 0 ] == _rtDW -> INPUT_9_1_1_discrete [ 1 ] ) ; _rtDW ->
INPUT_9_1_1_discrete [ 1 ] = _rtB -> B_33_170_0 [ 0 ] ; _rtB -> B_33_170_0 [
0 ] = _rtDW -> INPUT_9_1_1_discrete [ 1 ] ; _rtB -> B_33_170_0 [ 3 ] = _rtDW
-> INPUT_9_1_1_discrete [ 0 ] ; rtb_B_33_172_0 = _rtP -> P_110 ; _rtB ->
B_33_173_0 = _rtB -> B_33_171_0 * _rtP -> P_110 ; } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW
-> Compare_Mode_o = ( _rtB -> B_33_158_0 < InverterModulesInSeries2016a_rtC (
S ) -> B_33_174_0 ) ; } if ( _rtDW -> Compare_Mode_o ) { _rtB -> B_33_176_0 =
_rtB -> B_33_114_0 ; } else { _rtB -> B_33_176_0 = _rtB -> B_33_128_0 ; } }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_177_0
= _rtDW -> DelayInput2_DSTATE_nv ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { rtb_B_33_178_0 = _rtB -> B_33_176_0 - _rtB -> B_33_177_0 ;
rtb_B_33_179_0 = ( rtb_B_33_178_0 > _rtB -> B_33_173_0 ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_181_0 = _rtB
-> B_33_180_0 * rtb_B_33_172_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_33_179_0 ) { rtb_B_33_178_0 = _rtB -> B_33_173_0 ;
} else { if ( rtb_B_33_178_0 < _rtB -> B_33_181_0 ) { rtb_B_33_178_0 = _rtB
-> B_33_181_0 ; } } _rtB -> B_33_184_0 = rtb_B_33_178_0 + _rtB -> B_33_177_0
; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_33_185_0 [ 0 ] = _rtB -> B_33_184_0 ; _rtB -> B_33_185_0 [ 1 ] = 0.0 ; _rtB
-> B_33_185_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_10_1_1_discrete [ 0 ] = ! ( _rtB
-> B_33_185_0 [ 0 ] == _rtDW -> INPUT_10_1_1_discrete [ 1 ] ) ; _rtDW ->
INPUT_10_1_1_discrete [ 1 ] = _rtB -> B_33_185_0 [ 0 ] ; _rtB -> B_33_185_0 [
0 ] = _rtDW -> INPUT_10_1_1_discrete [ 1 ] ; _rtB -> B_33_185_0 [ 3 ] = _rtDW
-> INPUT_10_1_1_discrete [ 0 ] ; rtb_B_33_187_0 = _rtP -> P_115 ; _rtB ->
B_33_188_0 = _rtB -> B_33_186_0 * _rtP -> P_115 ; } _rtB -> B_33_189_0 =
muDoubleScalarSin ( _rtP -> P_118 * ssGetTaskTime ( S , 0 ) + _rtP -> P_119 )
* _rtP -> P_116 + _rtP -> P_117 ; _rtB -> B_33_190_0 = _rtB -> B_33_189_0 -
_rtB -> B_33_124_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_hj = ( _rtB ->
B_33_190_0 > InverterModulesInSeries2016a_rtC ( S ) -> B_33_191_0 ) ; } if (
_rtDW -> Compare_Mode_hj ) { _rtB -> B_33_193_0 = _rtB -> B_33_114_0 ; } else
{ _rtB -> B_33_193_0 = _rtB -> B_33_128_0 ; } } isHit = ssIsSampleHit ( S , 2
, 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_194_0 = _rtDW ->
DelayInput2_DSTATE_o ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { rtb_B_33_195_0 = _rtB -> B_33_193_0 - _rtB -> B_33_194_0 ;
rtb_B_33_196_0 = ( rtb_B_33_195_0 > _rtB -> B_33_188_0 ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_198_0 = _rtB
-> B_33_197_0 * rtb_B_33_187_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_33_196_0 ) { rtb_B_33_195_0 = _rtB -> B_33_188_0 ;
} else { if ( rtb_B_33_195_0 < _rtB -> B_33_198_0 ) { rtb_B_33_195_0 = _rtB
-> B_33_198_0 ; } } _rtB -> B_33_201_0 = rtb_B_33_195_0 + _rtB -> B_33_194_0
; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_33_202_0 [ 0 ] = _rtB -> B_33_201_0 ; _rtB -> B_33_202_0 [ 1 ] = 0.0 ; _rtB
-> B_33_202_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_11_1_1_discrete [ 0 ] = ! ( _rtB
-> B_33_202_0 [ 0 ] == _rtDW -> INPUT_11_1_1_discrete [ 1 ] ) ; _rtDW ->
INPUT_11_1_1_discrete [ 1 ] = _rtB -> B_33_202_0 [ 0 ] ; _rtB -> B_33_202_0 [
0 ] = _rtDW -> INPUT_11_1_1_discrete [ 1 ] ; _rtB -> B_33_202_0 [ 3 ] = _rtDW
-> INPUT_11_1_1_discrete [ 0 ] ; rtb_B_33_204_0 = _rtP -> P_124 ; _rtB ->
B_33_205_0 = _rtB -> B_33_203_0 * _rtP -> P_124 ; } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW
-> Compare_Mode_i4 = ( _rtB -> B_33_190_0 < InverterModulesInSeries2016a_rtC
( S ) -> B_33_206_0 ) ; } if ( _rtDW -> Compare_Mode_i4 ) { _rtB ->
B_33_208_0 = _rtB -> B_33_114_0 ; } else { _rtB -> B_33_208_0 = _rtB ->
B_33_128_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_33_209_0 = _rtDW -> DelayInput2_DSTATE_k ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_33_210_0 = _rtB -> B_33_208_0 -
_rtB -> B_33_209_0 ; rtb_B_33_211_0 = ( rtb_B_33_210_0 > _rtB -> B_33_205_0 )
; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_33_213_0 = _rtB -> B_33_212_0 * rtb_B_33_204_0 ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_33_211_0 ) { rtb_B_33_210_0 =
_rtB -> B_33_205_0 ; } else { if ( rtb_B_33_210_0 < _rtB -> B_33_213_0 ) {
rtb_B_33_210_0 = _rtB -> B_33_213_0 ; } } _rtB -> B_33_216_0 = rtb_B_33_210_0
+ _rtB -> B_33_209_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_33_217_0 [ 0 ] = _rtB -> B_33_216_0 ; _rtB -> B_33_217_0 [ 1
] = 0.0 ; _rtB -> B_33_217_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_12_1_1_discrete [ 0
] = ! ( _rtB -> B_33_217_0 [ 0 ] == _rtDW -> INPUT_12_1_1_discrete [ 1 ] ) ;
_rtDW -> INPUT_12_1_1_discrete [ 1 ] = _rtB -> B_33_217_0 [ 0 ] ; _rtB ->
B_33_217_0 [ 0 ] = _rtDW -> INPUT_12_1_1_discrete [ 1 ] ; _rtB -> B_33_217_0
[ 3 ] = _rtDW -> INPUT_12_1_1_discrete [ 0 ] ; ssCallAccelRunBlock ( S , 33 ,
218 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 33 , 219 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> B_33_219_0 [ 25 ] > _rtP -> P_133 ) {
_rtB -> B_33_220_0 = _rtP -> P_133 ; } else if ( _rtB -> B_33_219_0 [ 25 ] <
_rtP -> P_134 ) { _rtB -> B_33_220_0 = _rtP -> P_134 ; } else { _rtB ->
B_33_220_0 = _rtB -> B_33_219_0 [ 25 ] ; } if ( _rtB -> B_33_219_0 [ 23 ] >
_rtP -> P_135 ) { _rtB -> B_33_221_0 = _rtP -> P_135 ; } else if ( _rtB ->
B_33_219_0 [ 23 ] < _rtP -> P_136 ) { _rtB -> B_33_221_0 = _rtP -> P_136 ; }
else { _rtB -> B_33_221_0 = _rtB -> B_33_219_0 [ 23 ] ; } if ( _rtB ->
B_33_219_0 [ 24 ] > _rtP -> P_137 ) { _rtB -> B_33_222_0 = _rtP -> P_137 ; }
else if ( _rtB -> B_33_219_0 [ 24 ] < _rtP -> P_138 ) { _rtB -> B_33_222_0 =
_rtP -> P_138 ; } else { _rtB -> B_33_222_0 = _rtB -> B_33_219_0 [ 24 ] ; } {
if ( ( _rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK .
AQHandles [ 0 ] || _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK . SlioLTF ) &&
ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK . AQHandles [ 0 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_220_0 ) ;
sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK . AQHandles [ 1 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK .
SlioLTF , 1 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_221_0 ) ;
sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK . AQHandles [ 2 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_2_1_PWORK .
SlioLTF , 2 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_222_0 ) ; }
} { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK . AQHandles [ 0 ]
|| _rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK . AQHandles [ 0 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_219_0 [ 3 ]
) ; sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK . AQHandles [ 1 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK .
SlioLTF , 1 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_219_0 [ 1 ]
) ; sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK . AQHandles [ 2 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_3_1_PWORK .
SlioLTF , 2 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_219_0 [ 2 ]
) ; } } { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_5_PWORK . AQHandles ||
_rtDW -> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_5_PWORK . SlioLTF
) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module1_at_outport_5_PWORK . AQHandles , _rtDW
-> HiddenToAsyncQueue_InsertedFor_Module1_at_outport_5_PWORK . SlioLTF , 0 ,
ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_219_0 [ 4 ] ) ; } } if (
_rtB -> B_33_219_0 [ 51 ] > _rtP -> P_139 ) { _rtB -> B_33_226_0 = _rtP ->
P_139 ; } else if ( _rtB -> B_33_219_0 [ 51 ] < _rtP -> P_140 ) { _rtB ->
B_33_226_0 = _rtP -> P_140 ; } else { _rtB -> B_33_226_0 = _rtB -> B_33_219_0
[ 51 ] ; } if ( _rtB -> B_33_219_0 [ 49 ] > _rtP -> P_141 ) { _rtB ->
B_33_227_0 = _rtP -> P_141 ; } else if ( _rtB -> B_33_219_0 [ 49 ] < _rtP ->
P_142 ) { _rtB -> B_33_227_0 = _rtP -> P_142 ; } else { _rtB -> B_33_227_0 =
_rtB -> B_33_219_0 [ 49 ] ; } if ( _rtB -> B_33_219_0 [ 50 ] > _rtP -> P_143
) { _rtB -> B_33_228_0 = _rtP -> P_143 ; } else if ( _rtB -> B_33_219_0 [ 50
] < _rtP -> P_144 ) { _rtB -> B_33_228_0 = _rtP -> P_144 ; } else { _rtB ->
B_33_228_0 = _rtB -> B_33_219_0 [ 50 ] ; } { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK . AQHandles [ 0 ]
|| _rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK . AQHandles [ 0 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_226_0 ) ;
sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK . AQHandles [ 1 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK .
SlioLTF , 1 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_227_0 ) ;
sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK . AQHandles [ 2 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_2_1_PWORK .
SlioLTF , 2 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_228_0 ) ; }
} { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK . AQHandles [ 0 ]
|| _rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK . AQHandles [ 0 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_219_0 [ 29
] ) ; sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK . AQHandles [ 1 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK .
SlioLTF , 1 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_219_0 [ 27
] ) ; sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK . AQHandles [ 2 ]
, _rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_3_1_PWORK .
SlioLTF , 2 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_219_0 [ 28
] ) ; } } { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_5_PWORK . AQHandles ||
_rtDW -> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_5_PWORK . SlioLTF
) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Module2_at_outport_5_PWORK . AQHandles , _rtDW
-> HiddenToAsyncQueue_InsertedFor_Module2_at_outport_5_PWORK . SlioLTF , 0 ,
ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_219_0 [ 30 ] ) ; } } }
InverterModulesInSeries2016a_TrueRMS ( S , _rtB -> B_33_233_0 , _rtB ->
B_33_219_0 [ 29 ] , & _rtB -> B_33_219_0 [ 27 ] , & _rtB -> TrueRMS_o , &
_rtDW -> TrueRMS_o , & _rtP -> TrueRMS_o , & _rtX -> TrueRMS_o , & ( (
XDis_InverterModulesInSeries2016a_T * ) ssGetContStateDisabled ( S ) ) ->
TrueRMS_o ) ; InverterModulesInSeries2016a_RMS ( S , _rtB -> B_33_235_0 ,
_rtB -> B_33_219_0 [ 29 ] , & _rtB -> B_33_219_0 [ 27 ] , & _rtB -> RMS_m , &
_rtDW -> RMS_m , & _rtP -> RMS_m , & _rtX -> RMS_m , & ( (
XDis_InverterModulesInSeries2016a_T * ) ssGetContStateDisabled ( S ) ) ->
RMS_m ) ; if ( _rtB -> B_33_233_0 ) { _rtB -> B_33_237_0 [ 0 ] = _rtB ->
TrueRMS_o . B_24_10_0 [ 0 ] ; _rtB -> B_33_237_0 [ 1 ] = _rtB -> TrueRMS_o .
B_24_10_0 [ 1 ] ; _rtB -> B_33_237_0 [ 2 ] = _rtB -> TrueRMS_o . B_24_10_0 [
2 ] ; } else { _rtB -> B_33_237_0 [ 0 ] = _rtB -> RMS_m . B_22_22_0 [ 0 ] ;
_rtB -> B_33_237_0 [ 1 ] = _rtB -> RMS_m . B_22_22_0 [ 1 ] ; _rtB ->
B_33_237_0 [ 2 ] = _rtB -> RMS_m . B_22_22_0 [ 2 ] ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS2_at_outport_0_PWORK . AQHandles || _rtDW
-> HiddenToAsyncQueue_InsertedFor_RMS2_at_outport_0_PWORK . SlioLTF ) &&
ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS2_at_outport_0_PWORK . AQHandles , _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS2_at_outport_0_PWORK . SlioLTF , 0 ,
ssGetTaskTime ( S , 1 ) , ( void * ) & _rtB -> B_33_237_0 [ 0 ] ) ; } } }
InverterModulesInSeries2016a_TrueRMS ( S , _rtB -> B_33_240_0 , _rtB ->
B_33_219_0 [ 3 ] , & _rtB -> B_33_219_0 [ 1 ] , & _rtB -> TrueRMS , & _rtDW
-> TrueRMS , & _rtP -> TrueRMS , & _rtX -> TrueRMS , & ( (
XDis_InverterModulesInSeries2016a_T * ) ssGetContStateDisabled ( S ) ) ->
TrueRMS ) ; InverterModulesInSeries2016a_RMS ( S , _rtB -> B_33_242_0 , _rtB
-> B_33_219_0 [ 3 ] , & _rtB -> B_33_219_0 [ 1 ] , & _rtB -> RMS , & _rtDW ->
RMS , & _rtP -> RMS , & _rtX -> RMS , & ( (
XDis_InverterModulesInSeries2016a_T * ) ssGetContStateDisabled ( S ) ) -> RMS
) ; if ( _rtB -> B_33_240_0 ) { _rtB -> B_33_244_0 [ 0 ] = _rtB -> TrueRMS .
B_24_10_0 [ 0 ] ; _rtB -> B_33_244_0 [ 1 ] = _rtB -> TrueRMS . B_24_10_0 [ 1
] ; _rtB -> B_33_244_0 [ 2 ] = _rtB -> TrueRMS . B_24_10_0 [ 2 ] ; } else {
_rtB -> B_33_244_0 [ 0 ] = _rtB -> RMS . B_22_22_0 [ 0 ] ; _rtB -> B_33_244_0
[ 1 ] = _rtB -> RMS . B_22_22_0 [ 1 ] ; _rtB -> B_33_244_0 [ 2 ] = _rtB ->
RMS . B_22_22_0 [ 2 ] ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { { if ( ( _rtDW -> HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK
. AQHandles || _rtDW -> HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK
. SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK . AQHandles , _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK . SlioLTF , 0 ,
ssGetTaskTime ( S , 1 ) , ( void * ) & _rtB -> B_33_244_0 [ 0 ] ) ; } } }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { if ( _rtB ->
B_33_219_0 [ 52 ] > _rtP -> P_147 ) { _rtB -> B_33_246_0 = _rtP -> P_147 ; }
else if ( _rtB -> B_33_219_0 [ 52 ] < _rtP -> P_148 ) { _rtB -> B_33_246_0 =
_rtP -> P_148 ; } else { _rtB -> B_33_246_0 = _rtB -> B_33_219_0 [ 52 ] ; } {
if ( ( _rtDW -> HiddenToAsyncQueue_InsertedFor_Saturation1_at_outport_0_PWORK
. AQHandles || _rtDW ->
HiddenToAsyncQueue_InsertedFor_Saturation1_at_outport_0_PWORK . SlioLTF ) &&
ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Saturation1_at_outport_0_PWORK . AQHandles ,
_rtDW -> HiddenToAsyncQueue_InsertedFor_Saturation1_at_outport_0_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_246_0 ) ; }
} if ( _rtB -> B_33_219_0 [ 26 ] > _rtP -> P_149 ) { _rtB -> B_33_248_0 =
_rtP -> P_149 ; } else if ( _rtB -> B_33_219_0 [ 26 ] < _rtP -> P_150 ) {
_rtB -> B_33_248_0 = _rtP -> P_150 ; } else { _rtB -> B_33_248_0 = _rtB ->
B_33_219_0 [ 26 ] ; } { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Saturation_at_outport_0_PWORK . AQHandles ||
_rtDW -> HiddenToAsyncQueue_InsertedFor_Saturation_at_outport_0_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Saturation_at_outport_0_PWORK . AQHandles ,
_rtDW -> HiddenToAsyncQueue_InsertedFor_Saturation_at_outport_0_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_33_248_0 ) ; }
} ssCallAccelRunBlock ( S , 33 , 250 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 33 , 251 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 33 , 252 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 33 , 253 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 33 , 254 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
B_33_255_0 = _rtX -> integrator_CSTATE ; { real_T * * uBuffer = ( real_T * *
) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer =
( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_152 ;
B_33_256_0 = InverterModulesInSeries2016a_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK .
CircularBufSize , & _rtDW -> TransportDelay_IWORK . Last , _rtDW ->
TransportDelay_IWORK . Tail , _rtDW -> TransportDelay_IWORK . Head , _rtP ->
P_153 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_258_0 = _rtP -> P_154 ; }
rtb_B_33_25_0 = ( ssGetT ( S ) >= _rtB -> B_33_258_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_260_0 = _rtDW
-> Memory_PreviousInput ; } if ( rtb_B_33_25_0 ) { _rtB -> B_33_262_0 = (
_rtB -> B_33_255_0 - B_33_256_0 ) * _rtP -> P_1 ; } else { _rtB -> B_33_262_0
= _rtB -> B_33_260_0 ; } _rtB -> B_33_263_0 = _rtX -> integrator_CSTATE_c ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_i .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_i . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_157 ; B_33_264_0 =
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_c . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_c . Last , _rtDW -> TransportDelay_IWORK_c .
Tail , _rtDW -> TransportDelay_IWORK_c . Head , _rtP -> P_158 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_266_0 = _rtP -> P_159 ; } rtb_B_33_25_0 = ( ssGetT ( S ) >=
_rtB -> B_33_266_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_268_0 = _rtDW -> Memory_PreviousInput_e ; } if (
rtb_B_33_25_0 ) { _rtB -> B_33_270_0 = ( _rtB -> B_33_263_0 - B_33_264_0 ) *
_rtP -> P_0 ; } else { _rtB -> B_33_270_0 = _rtB -> B_33_268_0 ; }
rtb_B_33_5_0 = _rtB -> B_33_262_0 ; rtb_B_33_11_0 = _rtB -> B_33_270_0 ; _rtB
-> B_33_273_0 = _rtX -> integrator_CSTATE_l ; { real_T * * uBuffer = ( real_T
* * ) & _rtDW -> TransportDelay_PWORK_o . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_o . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_162 ; B_33_274_0 = InverterModulesInSeries2016a_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_m .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_m . Last , _rtDW ->
TransportDelay_IWORK_m . Tail , _rtDW -> TransportDelay_IWORK_m . Head , _rtP
-> P_163 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_276_0 = _rtP -> P_164 ; }
rtb_B_33_25_0 = ( ssGetT ( S ) >= _rtB -> B_33_276_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_278_0 = _rtDW
-> Memory_PreviousInput_k ; } if ( rtb_B_33_25_0 ) { _rtB -> B_33_280_0 = (
_rtB -> B_33_273_0 - B_33_274_0 ) * _rtP -> P_3 ; } else { _rtB -> B_33_280_0
= _rtB -> B_33_278_0 ; } _rtB -> B_33_281_0 = _rtX -> integrator_CSTATE_a ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_m .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_m . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_167 ; B_33_282_0 =
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_d . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_d . Last , _rtDW -> TransportDelay_IWORK_d .
Tail , _rtDW -> TransportDelay_IWORK_d . Head , _rtP -> P_168 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_284_0 = _rtP -> P_169 ; } rtb_B_33_25_0 = ( ssGetT ( S ) >=
_rtB -> B_33_284_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_286_0 = _rtDW -> Memory_PreviousInput_h ; } if (
rtb_B_33_25_0 ) { _rtB -> B_33_288_0 = ( _rtB -> B_33_281_0 - B_33_282_0 ) *
_rtP -> P_2 ; } else { _rtB -> B_33_288_0 = _rtB -> B_33_286_0 ; } _rtB ->
B_33_291_0 = muDoubleScalarHypot ( rtb_B_33_5_0 , rtb_B_33_11_0 ) *
muDoubleScalarHypot ( _rtB -> B_33_280_0 , _rtB -> B_33_288_0 ) ; _rtB ->
B_33_292_0 = _rtX -> integrator_CSTATE_o ; { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_j . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_j . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_172 ; B_33_293_0 = InverterModulesInSeries2016a_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_e .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_e . Last , _rtDW ->
TransportDelay_IWORK_e . Tail , _rtDW -> TransportDelay_IWORK_e . Head , _rtP
-> P_173 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_295_0 = _rtP -> P_174 ; }
rtb_B_33_25_0 = ( ssGetT ( S ) >= _rtB -> B_33_295_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_297_0 = _rtDW
-> Memory_PreviousInput_a ; } if ( rtb_B_33_25_0 ) { _rtB -> B_33_299_0 = (
_rtB -> B_33_292_0 - B_33_293_0 ) * _rtP -> P_5 ; } else { _rtB -> B_33_299_0
= _rtB -> B_33_297_0 ; } _rtB -> B_33_300_0 = _rtX -> integrator_CSTATE_h ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_p .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_p . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_177 ; B_33_301_0 =
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_p . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_p . Last , _rtDW -> TransportDelay_IWORK_p .
Tail , _rtDW -> TransportDelay_IWORK_p . Head , _rtP -> P_178 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_303_0 = _rtP -> P_179 ; } rtb_B_33_25_0 = ( ssGetT ( S ) >=
_rtB -> B_33_303_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_305_0 = _rtDW -> Memory_PreviousInput_c ; } if (
rtb_B_33_25_0 ) { _rtB -> B_33_307_0 = ( _rtB -> B_33_300_0 - B_33_301_0 ) *
_rtP -> P_4 ; } else { _rtB -> B_33_307_0 = _rtB -> B_33_305_0 ; }
rtb_B_33_5_0 = _rtB -> B_33_299_0 ; rtb_B_33_11_0 = _rtB -> B_33_307_0 ; _rtB
-> B_33_310_0 = _rtX -> integrator_CSTATE_oe ; { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_jk . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_jk .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_182 ; B_33_311_0 =
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_l . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_l . Last , _rtDW -> TransportDelay_IWORK_l .
Tail , _rtDW -> TransportDelay_IWORK_l . Head , _rtP -> P_183 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_313_0 = _rtP -> P_184 ; } rtb_B_33_25_0 = ( ssGetT ( S ) >=
_rtB -> B_33_313_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_33_315_0 = _rtDW -> Memory_PreviousInput_f ; } if (
rtb_B_33_25_0 ) { _rtB -> B_33_317_0 = ( _rtB -> B_33_310_0 - B_33_311_0 ) *
_rtP -> P_7 ; } else { _rtB -> B_33_317_0 = _rtB -> B_33_315_0 ; } _rtB ->
B_33_318_0 = _rtX -> integrator_CSTATE_f ; { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_187 ; B_33_319_0 = InverterModulesInSeries2016a_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_o .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_o . Last , _rtDW ->
TransportDelay_IWORK_o . Tail , _rtDW -> TransportDelay_IWORK_o . Head , _rtP
-> P_188 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_321_0 = _rtP -> P_189 ; }
rtb_B_33_25_0 = ( ssGetT ( S ) >= _rtB -> B_33_321_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_33_323_0 = _rtDW
-> Memory_PreviousInput_eh ; } if ( rtb_B_33_25_0 ) { _rtB -> B_33_325_0 = (
_rtB -> B_33_318_0 - B_33_319_0 ) * _rtP -> P_6 ; } else { _rtB -> B_33_325_0
= _rtB -> B_33_323_0 ; } _rtB -> B_33_328_0 = muDoubleScalarHypot (
rtb_B_33_5_0 , rtb_B_33_11_0 ) * muDoubleScalarHypot ( _rtB -> B_33_317_0 ,
_rtB -> B_33_325_0 ) ; ssCallAccelRunBlock ( S , 33 , 329 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_33_331_0 = ( muDoubleScalarSin ( _rtP ->
P_193 * ssGetTaskTime ( S , 0 ) + _rtP -> P_194 ) * _rtP -> P_191 + _rtP ->
P_192 ) * _rtB -> B_33_248_0 ; _rtB -> B_33_333_0 = ( muDoubleScalarSin (
_rtP -> P_197 * ssGetTaskTime ( S , 0 ) + _rtP -> P_198 ) * _rtP -> P_195 +
_rtP -> P_196 ) * _rtB -> B_33_248_0 ; _rtB -> B_33_335_0 = (
muDoubleScalarSin ( _rtP -> P_201 * ssGetTaskTime ( S , 0 ) + _rtP -> P_202 )
* _rtP -> P_199 + _rtP -> P_200 ) * _rtB -> B_33_219_0 [ 4 ] ; _rtB ->
B_33_337_0 = ( muDoubleScalarSin ( _rtP -> P_205 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_206 ) * _rtP -> P_203 + _rtP -> P_204 ) * _rtB -> B_33_219_0 [ 4 ]
; _rtB -> B_33_339_0 = ( muDoubleScalarSin ( _rtP -> P_209 * ssGetTaskTime (
S , 0 ) + _rtP -> P_210 ) * _rtP -> P_207 + _rtP -> P_208 ) * _rtB ->
B_33_246_0 ; _rtB -> B_33_341_0 = ( muDoubleScalarSin ( _rtP -> P_213 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_214 ) * _rtP -> P_211 + _rtP -> P_212 ) *
_rtB -> B_33_246_0 ; _rtB -> B_33_343_0 = ( muDoubleScalarSin ( _rtP -> P_217
* ssGetTaskTime ( S , 0 ) + _rtP -> P_218 ) * _rtP -> P_215 + _rtP -> P_216 )
* _rtB -> B_33_219_0 [ 30 ] ; _rtB -> B_33_345_0 = ( muDoubleScalarSin ( _rtP
-> P_221 * ssGetTaskTime ( S , 0 ) + _rtP -> P_222 ) * _rtP -> P_219 + _rtP
-> P_220 ) * _rtB -> B_33_219_0 [ 30 ] ; ssCallAccelRunBlock ( S , 33 , 412 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 33 , 614 ,
SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit !=
0 ) && ( ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB -> B_33_752_0 ) { if (
! _rtDW -> RMS_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( void ) memset ( & ( (
( XDis_InverterModulesInSeries2016a_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_e ) , 0 , 2 * sizeof ( boolean_T ) ) ; _rtDW -> RMS_MODE =
true ; } } else { if ( _rtDW -> RMS_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & ( ( (
XDis_InverterModulesInSeries2016a_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_e ) , 1 , 2 * sizeof ( boolean_T ) ) ; _rtDW -> RMS_MODE =
false ; } } } if ( _rtDW -> RMS_MODE ) { _rtB -> B_25_3_0 = (
muDoubleScalarSin ( _rtP -> P_13 * ssGetTaskTime ( S , 0 ) + _rtP -> P_14 ) *
_rtP -> P_11 + _rtP -> P_12 ) * _rtB -> B_33_219_0 [ 4 ] ; _rtB -> B_25_5_0 =
( muDoubleScalarSin ( _rtP -> P_17 * ssGetTaskTime ( S , 0 ) + _rtP -> P_18 )
* _rtP -> P_15 + _rtP -> P_16 ) * _rtB -> B_33_219_0 [ 4 ] ; if (
ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW -> RMS_SubsysRanBC ) ; }
} isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && (
ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB -> B_33_751_0 ) { if ( ! _rtDW
-> TrueRMS_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( (
XDis_InverterModulesInSeries2016a_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_m = 0 ; _rtDW -> TrueRMS_MODE = true ; } } else { if (
_rtDW -> TrueRMS_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
( ( XDis_InverterModulesInSeries2016a_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_m = 1 ; _rtDW -> TrueRMS_MODE = false ; } } } if ( _rtDW ->
TrueRMS_MODE ) { _rtB -> B_27_1_0 = _rtX -> integrator_CSTATE_m ; { real_T *
* uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_oj . TUbufferPtrs
[ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_oj . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S )
; real_T tMinusDelay = simTime - _rtP -> P_22 ; _rtB -> B_27_2_0 =
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_dv . CircularBufSize , &
_rtDW -> TransportDelay_IWORK_dv . Last , _rtDW -> TransportDelay_IWORK_dv .
Tail , _rtDW -> TransportDelay_IWORK_dv . Head , _rtP -> P_23 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) ==
ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_27_3_0 = _rtP -> P_24 ; _rtB -> B_27_4_0 = _rtDW ->
Memory_PreviousInput_p ; } if ( ssGetT ( S ) >= _rtB -> B_27_3_0 ) { _rtB ->
B_26_0_0 = _rtB -> B_27_1_0 - _rtB -> B_27_2_0 ; _rtB -> B_26_1_0 = _rtP ->
P_19 * _rtB -> B_26_0_0 ; _rtB -> B_27_7_0 = _rtB -> B_26_1_0 ; } else { _rtB
-> B_27_7_0 = _rtB -> B_27_4_0 ; } _rtB -> B_27_8_0 = _rtB -> B_33_219_0 [ 4
] * _rtB -> B_33_219_0 [ 4 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Saturationtoavoidnegativesqrt_MODE = _rtB -> B_27_7_0 >= _rtP -> P_26 ? 1 :
_rtB -> B_27_7_0 > _rtP -> P_27 ? 0 : - 1 ; srUpdateBC ( _rtDW ->
TrueRMS_SubsysRanBC ) ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { if ( _rtB -> B_33_219_0 [ 53 ] > _rtP -> P_224 ) { B_33_755_0 = _rtP
-> P_224 ; } else if ( _rtB -> B_33_219_0 [ 53 ] < _rtP -> P_225 ) {
B_33_755_0 = _rtP -> P_225 ; } else { B_33_755_0 = _rtB -> B_33_219_0 [ 53 ]
; } B_33_756_0 = _rtP -> P_226 * B_33_755_0 ; { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Gain_at_outport_0_PWORK . AQHandles || _rtDW
-> HiddenToAsyncQueue_InsertedFor_Gain_at_outport_0_PWORK . SlioLTF ) &&
ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Gain_at_outport_0_PWORK . AQHandles , _rtDW ->
HiddenToAsyncQueue_InsertedFor_Gain_at_outport_0_PWORK . SlioLTF , 0 ,
ssGetTaskTime ( S , 2 ) , ( void * ) & B_33_756_0 ) ; } } { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Saturation2_at_outport_0_PWORK . AQHandles ||
_rtDW -> HiddenToAsyncQueue_InsertedFor_Saturation2_at_outport_0_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_Saturation2_at_outport_0_PWORK . AQHandles ,
_rtDW -> HiddenToAsyncQueue_InsertedFor_Saturation2_at_outport_0_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & B_33_755_0 ) ; } }
ssCallAccelRunBlock ( S , 33 , 775 , SS_CALL_MDL_OUTPUTS ) ; }
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID4 ( SimStruct * S ,
int_T tid ) { B_InverterModulesInSeries2016a_T * _rtB ;
P_InverterModulesInSeries2016a_T * _rtP ; _rtP = ( (
P_InverterModulesInSeries2016a_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInSeries2016a_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB ->
B_33_4_0 = _rtP -> P_28 ; _rtB -> B_33_7_0 = _rtP -> P_30 ; _rtB -> B_33_21_0
= _rtP -> P_42 ; _rtB -> B_33_26_0 = _rtP -> P_44 ; _rtB -> B_33_32_0 = _rtP
-> P_45 ; _rtB -> B_33_41_0 = _rtP -> P_49 ; _rtB -> B_33_47_0 = _rtP -> P_50
; _rtB -> B_33_58_0 = _rtP -> P_58 ; _rtB -> B_33_64_0 = _rtP -> P_59 ; _rtB
-> B_33_73_0 = _rtP -> P_63 ; _rtB -> B_33_79_0 = _rtP -> P_64 ; _rtB ->
B_33_90_0 = _rtP -> P_72 ; _rtB -> B_33_96_0 = _rtP -> P_73 ; _rtB ->
B_33_105_0 = _rtP -> P_77 ; _rtB -> B_33_111_0 = _rtP -> P_78 ; _rtB ->
B_33_114_0 = _rtP -> P_80 ; _rtB -> B_33_128_0 = _rtP -> P_92 ; _rtB ->
B_33_133_0 = _rtP -> P_94 ; _rtB -> B_33_139_0 = _rtP -> P_95 ; _rtB ->
B_33_148_0 = _rtP -> P_99 ; _rtB -> B_33_154_0 = _rtP -> P_100 ; _rtB ->
B_33_165_0 = _rtP -> P_108 ; _rtB -> B_33_171_0 = _rtP -> P_109 ; _rtB ->
B_33_180_0 = _rtP -> P_113 ; _rtB -> B_33_186_0 = _rtP -> P_114 ; _rtB ->
B_33_197_0 = _rtP -> P_122 ; _rtB -> B_33_203_0 = _rtP -> P_123 ; _rtB ->
B_33_212_0 = _rtP -> P_127 ; _rtB -> B_33_233_0 = ( _rtP -> P_145 != 0.0 ) ;
_rtB -> B_33_235_0 = ! _rtB -> B_33_233_0 ; _rtB -> B_33_240_0 = ( _rtP ->
P_146 != 0.0 ) ; _rtB -> B_33_242_0 = ! _rtB -> B_33_240_0 ; _rtB ->
B_33_751_0 = ( _rtP -> P_223 != 0.0 ) ; _rtB -> B_33_752_0 = ! _rtB ->
B_33_751_0 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { int32_T isHit ;
B_InverterModulesInSeries2016a_T * _rtB ; P_InverterModulesInSeries2016a_T *
_rtP ; DW_InverterModulesInSeries2016a_T * _rtDW ; _rtDW = ( (
DW_InverterModulesInSeries2016a_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_InverterModulesInSeries2016a_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInSeries2016a_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> DelayInput2_DSTATE
= _rtB -> B_33_30_0 ; _rtDW -> DelayInput2_DSTATE_c = _rtB -> B_33_45_0 ;
_rtDW -> DelayInput2_DSTATE_d = _rtB -> B_33_62_0 ; _rtDW ->
DelayInput2_DSTATE_f = _rtB -> B_33_77_0 ; _rtDW -> DelayInput2_DSTATE_n =
_rtB -> B_33_94_0 ; _rtDW -> DelayInput2_DSTATE_m = _rtB -> B_33_109_0 ;
_rtDW -> DelayInput2_DSTATE_dc = _rtB -> B_33_137_0 ; _rtDW ->
DelayInput2_DSTATE_dj = _rtB -> B_33_152_0 ; _rtDW -> DelayInput2_DSTATE_a =
_rtB -> B_33_169_0 ; _rtDW -> DelayInput2_DSTATE_nv = _rtB -> B_33_184_0 ;
_rtDW -> DelayInput2_DSTATE_o = _rtB -> B_33_201_0 ; _rtDW ->
DelayInput2_DSTATE_k = _rtB -> B_33_216_0 ; ssCallAccelRunBlock ( S , 33 ,
218 , SS_CALL_MDL_UPDATE ) ; } InverterModulesInSeries2016a_TrueRMS_Update (
S , & _rtB -> TrueRMS_o , & _rtDW -> TrueRMS_o , & _rtP -> TrueRMS_o ) ;
InverterModulesInSeries2016a_RMS_Update ( S , & _rtB -> RMS_m , & _rtDW ->
RMS_m , & _rtP -> RMS_m ) ; InverterModulesInSeries2016a_TrueRMS_Update ( S ,
& _rtB -> TrueRMS , & _rtDW -> TrueRMS , & _rtP -> TrueRMS ) ;
InverterModulesInSeries2016a_RMS_Update ( S , & _rtB -> RMS , & _rtDW -> RMS
, & _rtP -> RMS ) ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * *
) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK . Head = ( ( _rtDW ->
TransportDelay_IWORK . Head < ( _rtDW -> TransportDelay_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay_IWORK . Head == _rtDW -> TransportDelay_IWORK
. Tail ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK . CircularBufSize , & _rtDW -> TransportDelay_IWORK .
Tail , & _rtDW -> TransportDelay_IWORK . Head , & _rtDW ->
TransportDelay_IWORK . Last , simTime - _rtP -> P_152 , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK . Head ] = _rtB ->
B_33_255_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput = _rtB -> B_33_262_0 ; } { real_T * * uBuffer =
( real_T * * ) & _rtDW -> TransportDelay_PWORK_i . TUbufferPtrs [ 0 ] ;
real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_i .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK_c . Head = ( ( _rtDW -> TransportDelay_IWORK_c . Head <
( _rtDW -> TransportDelay_IWORK_c . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_c . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_c . Head == _rtDW -> TransportDelay_IWORK_c . Tail ) {
if ( ! InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_c . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_c . Tail , & _rtDW -> TransportDelay_IWORK_c . Head , &
_rtDW -> TransportDelay_IWORK_c . Last , simTime - _rtP -> P_157 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_c . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_c . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_c . Head ] = _rtB -> B_33_263_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_e = _rtB -> B_33_270_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_o . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_o . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_m .
Head = ( ( _rtDW -> TransportDelay_IWORK_m . Head < ( _rtDW ->
TransportDelay_IWORK_m . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_m . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_m . Head == _rtDW -> TransportDelay_IWORK_m . Tail ) {
if ( ! InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_m . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_m . Tail , & _rtDW -> TransportDelay_IWORK_m . Head , &
_rtDW -> TransportDelay_IWORK_m . Last , simTime - _rtP -> P_162 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_m . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_m . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_m . Head ] = _rtB -> B_33_273_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_k = _rtB -> B_33_280_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_m . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_m . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_d .
Head = ( ( _rtDW -> TransportDelay_IWORK_d . Head < ( _rtDW ->
TransportDelay_IWORK_d . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_d . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_d . Head == _rtDW -> TransportDelay_IWORK_d . Tail ) {
if ( ! InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_d . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_d . Tail , & _rtDW -> TransportDelay_IWORK_d . Head , &
_rtDW -> TransportDelay_IWORK_d . Last , simTime - _rtP -> P_167 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_d . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_d . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_d . Head ] = _rtB -> B_33_281_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_h = _rtB -> B_33_288_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_j . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_j . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_e .
Head = ( ( _rtDW -> TransportDelay_IWORK_e . Head < ( _rtDW ->
TransportDelay_IWORK_e . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_e . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_e . Head == _rtDW -> TransportDelay_IWORK_e . Tail ) {
if ( ! InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_e . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_e . Tail , & _rtDW -> TransportDelay_IWORK_e . Head , &
_rtDW -> TransportDelay_IWORK_e . Last , simTime - _rtP -> P_172 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_e . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_e . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_e . Head ] = _rtB -> B_33_292_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_a = _rtB -> B_33_299_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_p . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_p .
Head = ( ( _rtDW -> TransportDelay_IWORK_p . Head < ( _rtDW ->
TransportDelay_IWORK_p . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_p . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_p . Head == _rtDW -> TransportDelay_IWORK_p . Tail ) {
if ( ! InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_p . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_p . Tail , & _rtDW -> TransportDelay_IWORK_p . Head , &
_rtDW -> TransportDelay_IWORK_p . Last , simTime - _rtP -> P_177 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_p . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] = _rtB -> B_33_300_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_c = _rtB -> B_33_307_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_jk . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_jk .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK_l . Head = ( ( _rtDW -> TransportDelay_IWORK_l . Head <
( _rtDW -> TransportDelay_IWORK_l . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_l . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_l . Head == _rtDW -> TransportDelay_IWORK_l . Tail ) {
if ( ! InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_l . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_l . Tail , & _rtDW -> TransportDelay_IWORK_l . Head , &
_rtDW -> TransportDelay_IWORK_l . Last , simTime - _rtP -> P_182 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_l . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_l . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_l . Head ] = _rtB -> B_33_310_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_f = _rtB -> B_33_317_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs
[ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_o .
Head = ( ( _rtDW -> TransportDelay_IWORK_o . Head < ( _rtDW ->
TransportDelay_IWORK_o . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_o . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_o . Head == _rtDW -> TransportDelay_IWORK_o . Tail ) {
if ( ! InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK_o . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_o . Tail , & _rtDW -> TransportDelay_IWORK_o . Head , &
_rtDW -> TransportDelay_IWORK_o . Last , simTime - _rtP -> P_187 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_o . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_o . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_o . Head ] = _rtB -> B_33_318_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_eh = _rtB -> B_33_325_0 ; } if ( _rtDW -> TrueRMS_MODE )
{ { real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_oj .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_oj . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S )
; _rtDW -> TransportDelay_IWORK_dv . Head = ( ( _rtDW ->
TransportDelay_IWORK_dv . Head < ( _rtDW -> TransportDelay_IWORK_dv .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_dv . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_dv . Head == _rtDW ->
TransportDelay_IWORK_dv . Tail ) { if ( !
InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_dv . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_dv . Tail , & _rtDW -> TransportDelay_IWORK_dv . Head ,
& _rtDW -> TransportDelay_IWORK_dv . Last , simTime - _rtP -> P_22 , tBuffer
, uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_dv . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_dv . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_dv . Head ] = _rtB -> B_27_1_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_p = _rtB ->
B_27_7_0 ; } } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID4 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) {
B_InverterModulesInSeries2016a_T * _rtB ; XDot_InverterModulesInSeries2016a_T
* _rtXdot ; DW_InverterModulesInSeries2016a_T * _rtDW ; _rtDW = ( (
DW_InverterModulesInSeries2016a_T * ) ssGetRootDWork ( S ) ) ; _rtXdot = ( (
XDot_InverterModulesInSeries2016a_T * ) ssGetdX ( S ) ) ; _rtB = ( (
B_InverterModulesInSeries2016a_T * ) _ssGetModelBlockIO ( S ) ) ;
InverterModulesInSeries2016a_TrueRMS_Deriv ( S , & _rtB -> TrueRMS_o , &
_rtDW -> TrueRMS_o , & _rtXdot -> TrueRMS_o ) ;
InverterModulesInSeries2016a_RMS_Deriv ( S , & _rtB -> RMS_m , & _rtDW ->
RMS_m , & _rtXdot -> RMS_m ) ; InverterModulesInSeries2016a_TrueRMS_Deriv ( S
, & _rtB -> TrueRMS , & _rtDW -> TrueRMS , & _rtXdot -> TrueRMS ) ;
InverterModulesInSeries2016a_RMS_Deriv ( S , & _rtB -> RMS , & _rtDW -> RMS ,
& _rtXdot -> RMS ) ; _rtXdot -> integrator_CSTATE = _rtB -> B_33_331_0 ;
_rtXdot -> integrator_CSTATE_c = _rtB -> B_33_333_0 ; _rtXdot ->
integrator_CSTATE_l = _rtB -> B_33_335_0 ; _rtXdot -> integrator_CSTATE_a =
_rtB -> B_33_337_0 ; _rtXdot -> integrator_CSTATE_o = _rtB -> B_33_339_0 ;
_rtXdot -> integrator_CSTATE_h = _rtB -> B_33_341_0 ; _rtXdot ->
integrator_CSTATE_oe = _rtB -> B_33_343_0 ; _rtXdot -> integrator_CSTATE_f =
_rtB -> B_33_345_0 ; if ( _rtDW -> RMS_MODE ) { _rtXdot ->
integrator_CSTATE_e = _rtB -> B_25_5_0 ; _rtXdot -> integrator_CSTATE_i =
_rtB -> B_25_3_0 ; } else { { real_T * dx ; int_T i ; dx = & ( ( (
XDot_InverterModulesInSeries2016a_T * ) ssGetdX ( S ) ) ->
integrator_CSTATE_e ) ; for ( i = 0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } } }
if ( _rtDW -> TrueRMS_MODE ) { _rtXdot -> integrator_CSTATE_m = _rtB ->
B_27_8_0 ; } else { ( ( XDot_InverterModulesInSeries2016a_T * ) ssGetdX ( S )
) -> integrator_CSTATE_m = 0.0 ; } }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) {
B_InverterModulesInSeries2016a_T * _rtB ; P_InverterModulesInSeries2016a_T *
_rtP ; ZCV_InverterModulesInSeries2016a_T * _rtZCSV ;
DW_InverterModulesInSeries2016a_T * _rtDW ; _rtDW = ( (
DW_InverterModulesInSeries2016a_T * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( (
ZCV_InverterModulesInSeries2016a_T * ) ssGetSolverZcSignalVector ( S ) ) ;
_rtP = ( ( P_InverterModulesInSeries2016a_T * ) ssGetModelRtp ( S ) ) ; _rtB
= ( ( B_InverterModulesInSeries2016a_T * ) _ssGetModelBlockIO ( S ) ) ;
_rtZCSV -> Compare_RelopInput_ZC = _rtB -> B_33_18_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_19_0 ; _rtZCSV ->
Compare_RelopInput_ZC_e = _rtB -> B_33_18_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_35_0 ; _rtZCSV ->
Compare_RelopInput_ZC_p = _rtB -> B_33_51_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_52_0 ; _rtZCSV ->
Compare_RelopInput_ZC_a = _rtB -> B_33_51_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_67_0 ; _rtZCSV ->
Compare_RelopInput_ZC_n = _rtB -> B_33_83_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_84_0 ; _rtZCSV ->
Compare_RelopInput_ZC_j = _rtB -> B_33_83_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_99_0 ; _rtZCSV ->
Compare_RelopInput_ZC_o = _rtB -> B_33_125_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_126_0 ; _rtZCSV ->
Compare_RelopInput_ZC_i = _rtB -> B_33_125_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_142_0 ; _rtZCSV ->
Compare_RelopInput_ZC_f = _rtB -> B_33_158_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_159_0 ; _rtZCSV ->
Compare_RelopInput_ZC_pd = _rtB -> B_33_158_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_174_0 ; _rtZCSV ->
Compare_RelopInput_ZC_d = _rtB -> B_33_190_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_191_0 ; _rtZCSV ->
Compare_RelopInput_ZC_aj = _rtB -> B_33_190_0 -
InverterModulesInSeries2016a_rtC ( S ) -> B_33_206_0 ;
InverterModulesInSeries2016a_TrueRMS_ZC ( S , & _rtB -> TrueRMS_o , & _rtDW
-> TrueRMS_o , & _rtP -> TrueRMS_o , & _rtZCSV -> TrueRMS_o ) ;
InverterModulesInSeries2016a_TrueRMS_ZC ( S , & _rtB -> TrueRMS , & _rtDW ->
TrueRMS , & _rtP -> TrueRMS , & _rtZCSV -> TrueRMS ) ; if ( _rtDW ->
TrueRMS_MODE ) { _rtZCSV -> Saturationtoavoidnegativesqrt_UprLim_ZC_f = _rtB
-> B_27_7_0 - _rtP -> P_26 ; _rtZCSV ->
Saturationtoavoidnegativesqrt_LwrLim_ZC_p = _rtB -> B_27_7_0 - _rtP -> P_27 ;
} else { { real_T * zcsv = & ( ( ( ZCV_InverterModulesInSeries2016a_T * )
ssGetSolverZcSignalVector ( S ) ) ->
Saturationtoavoidnegativesqrt_UprLim_ZC_f ) ; int_T i ; for ( i = 0 ; i < 2 ;
i ++ ) { zcsv [ i ] = 0.0 ; } } } } static void mdlInitializeSizes (
SimStruct * S ) { ssSetChecksumVal ( S , 0 , 2352101178U ) ; ssSetChecksumVal
( S , 1 , 4075456496U ) ; ssSetChecksumVal ( S , 2 , 3318505438U ) ;
ssSetChecksumVal ( S , 3 , 2621835700U ) ; { mxArray * slVerStructMat = NULL
; mxArray * slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ]
; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver"
) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0
, "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "9.1" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_InverterModulesInSeries2016a_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_InverterModulesInSeries2016a_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_InverterModulesInSeries2016a_T ) ) { static char msg [ 256 ] ; sprintf (
msg , "Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & InverterModulesInSeries2016a_rtDefaultP ) ; _ssSetConstBlockIO ( S , &
InverterModulesInSeries2016a_rtInvariant ) ; rt_InitInfAndNaN ( sizeof (
real_T ) ) ; ( ( P_InverterModulesInSeries2016a_T * ) ssGetModelRtp ( S ) )
-> P_26 = rtInf ; ( ( P_InverterModulesInSeries2016a_T * ) ssGetModelRtp ( S
) ) -> TrueRMS_o . P_7 = rtInf ; ( ( P_InverterModulesInSeries2016a_T * )
ssGetModelRtp ( S ) ) -> TrueRMS . P_7 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { slAccRegPrmChangeFcn ( S ,
mdlOutputsTID4 ) ; } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
