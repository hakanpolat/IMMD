#include "__cf_Inverter.h"
#include <math.h>
#include "Inverter_acc.h"
#include "Inverter_acc_private.h"
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
boolean_T Inverter_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr ,
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
return ( true ) ; } real_T Inverter_acc_rt_TDelayInterpolate ( real_T
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
_ssReportDiagnosticAsWarning ( S , diag ) ; } static void mdlOutputs (
SimStruct * S , int_T tid ) { real_T B_8_1_0 ; real_T B_8_9_0 ; real_T
rtb_B_8_118_0 ; real_T rtb_B_8_103_0 ; real_T rtb_B_8_86_0 ; real_T
rtb_B_8_71_0 ; real_T rtb_B_8_54_0 ; real_T rtb_B_8_39_0 ; real_T
rtb_B_8_26_0 ; boolean_T rtb_B_8_119_0 ; boolean_T rtb_B_8_104_0 ; boolean_T
rtb_B_8_87_0 ; boolean_T rtb_B_8_72_0 ; boolean_T rtb_B_8_55_0 ; boolean_T
rtb_B_8_40_0 ; boolean_T rtb_B_8_4_0 ; real_T rtb_B_8_112_0 ; real_T
rtb_B_8_95_0 ; real_T rtb_B_8_80_0 ; real_T rtb_B_8_63_0 ; real_T
rtb_B_8_48_0 ; real_T rtb_B_8_20_0 ; int32_T isHit ; B_Inverter_T * _rtB ;
P_Inverter_T * _rtP ; X_Inverter_T * _rtX ; DW_Inverter_T * _rtDW ; _rtDW = (
( DW_Inverter_T * ) ssGetRootDWork ( S ) ) ; _rtX = ( ( X_Inverter_T * )
ssGetContStates ( S ) ) ; _rtP = ( ( P_Inverter_T * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( B_Inverter_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_8_0_0 =
_rtX -> integrator_CSTATE ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * *
) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_3 ; B_8_1_0 =
Inverter_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer
, _rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail , _rtDW ->
TransportDelay_IWORK . Head , _rtP -> P_4 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_8_3_0 = _rtP -> P_5 ; } rtb_B_8_4_0 = ( ssGetT ( S ) >= _rtB -> B_8_3_0 ) ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_5_0 =
_rtDW -> Memory_PreviousInput ; } if ( rtb_B_8_4_0 ) { _rtB -> B_8_7_0 = (
_rtB -> B_8_0_0 - B_8_1_0 ) * _rtP -> P_1 ; } else { _rtB -> B_8_7_0 = _rtB
-> B_8_5_0 ; } _rtB -> B_8_8_0 = _rtX -> integrator_CSTATE_f ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 0
] ; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_b .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_8 ; B_8_9_0 = Inverter_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK_n .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_n . Last , _rtDW ->
TransportDelay_IWORK_n . Tail , _rtDW -> TransportDelay_IWORK_n . Head , _rtP
-> P_9 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && (
ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_11_0 = _rtP -> P_10 ; }
rtb_B_8_4_0 = ( ssGetT ( S ) >= _rtB -> B_8_11_0 ) ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_13_0 = _rtDW ->
Memory_PreviousInput_p ; } if ( rtb_B_8_4_0 ) { _rtB -> B_8_15_0 = ( _rtB ->
B_8_8_0 - B_8_9_0 ) * _rtP -> P_0 ; } else { _rtB -> B_8_15_0 = _rtB ->
B_8_13_0 ; } _rtB -> B_8_17_0 = muDoubleScalarHypot ( _rtB -> B_8_7_0 , _rtB
-> B_8_15_0 ) ; ssCallAccelRunBlock ( S , 8 , 18 , SS_CALL_MDL_OUTPUTS ) ;
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { rtb_B_8_20_0 = _rtP
-> P_13 ; _rtB -> B_8_21_0 = _rtB -> B_8_19_0 * _rtP -> P_13 ; } _rtB ->
B_8_23_0 = muDoubleScalarSin ( _rtP -> P_17 * ssGetTaskTime ( S , 0 ) + _rtP
-> P_18 ) * _rtP -> P_15 + _rtP -> P_16 ; isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { _rtB -> B_8_25_0 = _rtP -> P_19 ; } rtb_B_8_26_0 =
ssGetT ( S ) + _rtB -> B_8_25_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_8_27_0 = _rtP -> P_20 ; } rtb_B_8_26_0 =
look1_pbinlxpw ( _rtP -> P_21 * muDoubleScalarRem ( rtb_B_8_26_0 , _rtB ->
B_8_27_0 ) , _rtP -> P_23 , _rtP -> P_22 , & _rtDW -> m_bpIndex , 2U ) ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_31_0 =
_rtP -> P_24 ; } _rtB -> B_8_32_0 = rtb_B_8_26_0 - _rtB -> B_8_31_0 ; _rtB ->
B_8_33_0 = _rtB -> B_8_23_0 - _rtB -> B_8_32_0 ; isHit = ssIsSampleHit ( S ,
1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Compare_Mode = ( _rtB -> B_8_33_0 > Inverter_rtC ( S ) -> B_8_34_0 ) ; } if (
_rtDW -> Compare_Mode ) { _rtB -> B_8_37_0 = _rtB -> B_8_22_0 ; } else { _rtB
-> B_8_37_0 = _rtB -> B_8_36_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_8_38_0 = _rtDW -> DelayInput2_DSTATE ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_8_39_0 = _rtB ->
B_8_37_0 - _rtB -> B_8_38_0 ; rtb_B_8_40_0 = ( rtb_B_8_39_0 > _rtB ->
B_8_21_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_8_42_0 = _rtB -> B_8_41_0 * rtb_B_8_20_0 ; } isHit = ssIsSampleHit ( S ,
1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_8_40_0 ) { rtb_B_8_39_0 = _rtB ->
B_8_21_0 ; } else { if ( rtb_B_8_39_0 < _rtB -> B_8_42_0 ) { rtb_B_8_39_0 =
_rtB -> B_8_42_0 ; } } _rtB -> B_8_45_0 = rtb_B_8_39_0 + _rtB -> B_8_38_0 ; }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_46_0 [
0 ] = _rtB -> B_8_45_0 ; _rtB -> B_8_46_0 [ 1 ] = 0.0 ; _rtB -> B_8_46_0 [ 2
] = 0.0 ; _rtDW -> INPUT_1_1_1_discrete [ 0 ] = ! ( _rtB -> B_8_46_0 [ 0 ] ==
_rtDW -> INPUT_1_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_1_1_1_discrete [ 1 ] =
_rtB -> B_8_46_0 [ 0 ] ; _rtB -> B_8_46_0 [ 0 ] = _rtDW ->
INPUT_1_1_1_discrete [ 1 ] ; _rtB -> B_8_46_0 [ 3 ] = _rtDW ->
INPUT_1_1_1_discrete [ 0 ] ; rtb_B_8_48_0 = _rtP -> P_30 ; _rtB -> B_8_49_0 =
_rtB -> B_8_47_0 * _rtP -> P_30 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Compare_Mode_g = ( _rtB -> B_8_33_0 < Inverter_rtC ( S ) -> B_8_50_0 ) ; } if
( _rtDW -> Compare_Mode_g ) { _rtB -> B_8_52_0 = _rtB -> B_8_22_0 ; } else {
_rtB -> B_8_52_0 = _rtB -> B_8_36_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 )
; if ( isHit != 0 ) { _rtB -> B_8_53_0 = _rtDW -> DelayInput2_DSTATE_c ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_8_54_0 = _rtB
-> B_8_52_0 - _rtB -> B_8_53_0 ; rtb_B_8_55_0 = ( rtb_B_8_54_0 > _rtB ->
B_8_49_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_8_57_0 = _rtB -> B_8_56_0 * rtb_B_8_48_0 ; } isHit = ssIsSampleHit ( S ,
1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_8_55_0 ) { rtb_B_8_54_0 = _rtB ->
B_8_49_0 ; } else { if ( rtb_B_8_54_0 < _rtB -> B_8_57_0 ) { rtb_B_8_54_0 =
_rtB -> B_8_57_0 ; } } _rtB -> B_8_60_0 = rtb_B_8_54_0 + _rtB -> B_8_53_0 ; }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_61_0 [
0 ] = _rtB -> B_8_60_0 ; _rtB -> B_8_61_0 [ 1 ] = 0.0 ; _rtB -> B_8_61_0 [ 2
] = 0.0 ; _rtDW -> INPUT_2_1_1_discrete [ 0 ] = ! ( _rtB -> B_8_61_0 [ 0 ] ==
_rtDW -> INPUT_2_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_2_1_1_discrete [ 1 ] =
_rtB -> B_8_61_0 [ 0 ] ; _rtB -> B_8_61_0 [ 0 ] = _rtDW ->
INPUT_2_1_1_discrete [ 1 ] ; _rtB -> B_8_61_0 [ 3 ] = _rtDW ->
INPUT_2_1_1_discrete [ 0 ] ; rtb_B_8_63_0 = _rtP -> P_35 ; _rtB -> B_8_64_0 =
_rtB -> B_8_62_0 * _rtP -> P_35 ; } _rtB -> B_8_65_0 = muDoubleScalarSin (
_rtP -> P_38 * ssGetTaskTime ( S , 0 ) + _rtP -> P_39 ) * _rtP -> P_36 + _rtP
-> P_37 ; _rtB -> B_8_66_0 = _rtB -> B_8_65_0 - _rtB -> B_8_32_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> Compare_Mode_p = ( _rtB -> B_8_66_0 > Inverter_rtC ( S )
-> B_8_67_0 ) ; } if ( _rtDW -> Compare_Mode_p ) { _rtB -> B_8_69_0 = _rtB ->
B_8_22_0 ; } else { _rtB -> B_8_69_0 = _rtB -> B_8_36_0 ; } } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_70_0 = _rtDW ->
DelayInput2_DSTATE_d ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { rtb_B_8_71_0 = _rtB -> B_8_69_0 - _rtB -> B_8_70_0 ; rtb_B_8_72_0 = (
rtb_B_8_71_0 > _rtB -> B_8_64_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_8_74_0 = _rtB -> B_8_73_0 * rtb_B_8_63_0 ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_8_72_0 )
{ rtb_B_8_71_0 = _rtB -> B_8_64_0 ; } else { if ( rtb_B_8_71_0 < _rtB ->
B_8_74_0 ) { rtb_B_8_71_0 = _rtB -> B_8_74_0 ; } } _rtB -> B_8_77_0 =
rtb_B_8_71_0 + _rtB -> B_8_70_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_8_78_0 [ 0 ] = _rtB -> B_8_77_0 ; _rtB -> B_8_78_0
[ 1 ] = 0.0 ; _rtB -> B_8_78_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_3_1_1_discrete [
0 ] = ! ( _rtB -> B_8_78_0 [ 0 ] == _rtDW -> INPUT_3_1_1_discrete [ 1 ] ) ;
_rtDW -> INPUT_3_1_1_discrete [ 1 ] = _rtB -> B_8_78_0 [ 0 ] ; _rtB ->
B_8_78_0 [ 0 ] = _rtDW -> INPUT_3_1_1_discrete [ 1 ] ; _rtB -> B_8_78_0 [ 3 ]
= _rtDW -> INPUT_3_1_1_discrete [ 0 ] ; rtb_B_8_80_0 = _rtP -> P_44 ; _rtB ->
B_8_81_0 = _rtB -> B_8_79_0 * _rtP -> P_44 ; } isHit = ssIsSampleHit ( S , 1
, 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Compare_Mode_j = ( _rtB -> B_8_66_0 < Inverter_rtC ( S ) -> B_8_82_0 ) ; } if
( _rtDW -> Compare_Mode_j ) { _rtB -> B_8_84_0 = _rtB -> B_8_22_0 ; } else {
_rtB -> B_8_84_0 = _rtB -> B_8_36_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 )
; if ( isHit != 0 ) { _rtB -> B_8_85_0 = _rtDW -> DelayInput2_DSTATE_l ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_8_86_0 = _rtB
-> B_8_84_0 - _rtB -> B_8_85_0 ; rtb_B_8_87_0 = ( rtb_B_8_86_0 > _rtB ->
B_8_81_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_8_89_0 = _rtB -> B_8_88_0 * rtb_B_8_80_0 ; } isHit = ssIsSampleHit ( S ,
1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_8_87_0 ) { rtb_B_8_86_0 = _rtB ->
B_8_81_0 ; } else { if ( rtb_B_8_86_0 < _rtB -> B_8_89_0 ) { rtb_B_8_86_0 =
_rtB -> B_8_89_0 ; } } _rtB -> B_8_92_0 = rtb_B_8_86_0 + _rtB -> B_8_85_0 ; }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_93_0 [
0 ] = _rtB -> B_8_92_0 ; _rtB -> B_8_93_0 [ 1 ] = 0.0 ; _rtB -> B_8_93_0 [ 2
] = 0.0 ; _rtDW -> INPUT_4_1_1_discrete [ 0 ] = ! ( _rtB -> B_8_93_0 [ 0 ] ==
_rtDW -> INPUT_4_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_4_1_1_discrete [ 1 ] =
_rtB -> B_8_93_0 [ 0 ] ; _rtB -> B_8_93_0 [ 0 ] = _rtDW ->
INPUT_4_1_1_discrete [ 1 ] ; _rtB -> B_8_93_0 [ 3 ] = _rtDW ->
INPUT_4_1_1_discrete [ 0 ] ; rtb_B_8_95_0 = _rtP -> P_49 ; _rtB -> B_8_96_0 =
_rtB -> B_8_94_0 * _rtP -> P_49 ; } _rtB -> B_8_97_0 = muDoubleScalarSin (
_rtP -> P_52 * ssGetTaskTime ( S , 0 ) + _rtP -> P_53 ) * _rtP -> P_50 + _rtP
-> P_51 ; _rtB -> B_8_98_0 = _rtB -> B_8_97_0 - _rtB -> B_8_32_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> Compare_Mode_h = ( _rtB -> B_8_98_0 > Inverter_rtC ( S )
-> B_8_99_0 ) ; } if ( _rtDW -> Compare_Mode_h ) { _rtB -> B_8_101_0 = _rtB
-> B_8_22_0 ; } else { _rtB -> B_8_101_0 = _rtB -> B_8_36_0 ; } } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_102_0 = _rtDW
-> DelayInput2_DSTATE_n ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit
!= 0 ) { rtb_B_8_103_0 = _rtB -> B_8_101_0 - _rtB -> B_8_102_0 ;
rtb_B_8_104_0 = ( rtb_B_8_103_0 > _rtB -> B_8_96_0 ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_106_0 = _rtB ->
B_8_105_0 * rtb_B_8_95_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit
!= 0 ) { if ( rtb_B_8_104_0 ) { rtb_B_8_103_0 = _rtB -> B_8_96_0 ; } else {
if ( rtb_B_8_103_0 < _rtB -> B_8_106_0 ) { rtb_B_8_103_0 = _rtB -> B_8_106_0
; } } _rtB -> B_8_109_0 = rtb_B_8_103_0 + _rtB -> B_8_102_0 ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_110_0 [ 0 ] =
_rtB -> B_8_109_0 ; _rtB -> B_8_110_0 [ 1 ] = 0.0 ; _rtB -> B_8_110_0 [ 2 ] =
0.0 ; _rtDW -> INPUT_5_1_1_discrete [ 0 ] = ! ( _rtB -> B_8_110_0 [ 0 ] ==
_rtDW -> INPUT_5_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_5_1_1_discrete [ 1 ] =
_rtB -> B_8_110_0 [ 0 ] ; _rtB -> B_8_110_0 [ 0 ] = _rtDW ->
INPUT_5_1_1_discrete [ 1 ] ; _rtB -> B_8_110_0 [ 3 ] = _rtDW ->
INPUT_5_1_1_discrete [ 0 ] ; rtb_B_8_112_0 = _rtP -> P_58 ; _rtB -> B_8_113_0
= _rtB -> B_8_111_0 * _rtP -> P_58 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Compare_Mode_i = ( _rtB -> B_8_98_0 < Inverter_rtC ( S ) -> B_8_114_0 ) ; }
if ( _rtDW -> Compare_Mode_i ) { _rtB -> B_8_116_0 = _rtB -> B_8_22_0 ; }
else { _rtB -> B_8_116_0 = _rtB -> B_8_36_0 ; } } isHit = ssIsSampleHit ( S ,
2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_117_0 = _rtDW ->
DelayInput2_DSTATE_p ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { rtb_B_8_118_0 = _rtB -> B_8_116_0 - _rtB -> B_8_117_0 ; rtb_B_8_119_0 =
( rtb_B_8_118_0 > _rtB -> B_8_113_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 )
; if ( isHit != 0 ) { _rtB -> B_8_121_0 = _rtB -> B_8_120_0 * rtb_B_8_112_0 ;
} isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
rtb_B_8_119_0 ) { rtb_B_8_118_0 = _rtB -> B_8_113_0 ; } else { if (
rtb_B_8_118_0 < _rtB -> B_8_121_0 ) { rtb_B_8_118_0 = _rtB -> B_8_121_0 ; } }
_rtB -> B_8_124_0 = rtb_B_8_118_0 + _rtB -> B_8_117_0 ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_8_125_0 [ 0 ] =
_rtB -> B_8_124_0 ; _rtB -> B_8_125_0 [ 1 ] = 0.0 ; _rtB -> B_8_125_0 [ 2 ] =
0.0 ; _rtDW -> INPUT_6_1_1_discrete [ 0 ] = ! ( _rtB -> B_8_125_0 [ 0 ] ==
_rtDW -> INPUT_6_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_6_1_1_discrete [ 1 ] =
_rtB -> B_8_125_0 [ 0 ] ; _rtB -> B_8_125_0 [ 0 ] = _rtDW ->
INPUT_6_1_1_discrete [ 1 ] ; _rtB -> B_8_125_0 [ 3 ] = _rtDW ->
INPUT_6_1_1_discrete [ 0 ] ; ssCallAccelRunBlock ( S , 8 , 126 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 8 , 127 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_8_128_0 = _rtB -> B_8_127_0 [ 0 ] ;
ssCallAccelRunBlock ( S , 8 , 129 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 8 , 130 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 8 , 131 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
B_8_145_0 = ( muDoubleScalarSin ( _rtP -> P_67 * ssGetTaskTime ( S , 0 ) +
_rtP -> P_68 ) * _rtP -> P_65 + _rtP -> P_66 ) * _rtB -> B_8_127_0 [ 0 ] ;
_rtB -> B_8_147_0 = ( muDoubleScalarSin ( _rtP -> P_71 * ssGetTaskTime ( S ,
0 ) + _rtP -> P_72 ) * _rtP -> P_69 + _rtP -> P_70 ) * _rtB -> B_8_127_0 [ 0
] ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 8 , 160 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 8 , 161 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 8 , 196 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER
( tid ) ; } static void mdlOutputsTID4 ( SimStruct * S , int_T tid ) {
B_Inverter_T * _rtB ; P_Inverter_T * _rtP ; _rtP = ( ( P_Inverter_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Inverter_T * ) _ssGetModelBlockIO ( S )
) ; _rtB -> B_8_19_0 = _rtP -> P_12 ; _rtB -> B_8_22_0 = _rtP -> P_14 ; _rtB
-> B_8_36_0 = _rtP -> P_26 ; _rtB -> B_8_41_0 = _rtP -> P_28 ; _rtB ->
B_8_47_0 = _rtP -> P_29 ; _rtB -> B_8_56_0 = _rtP -> P_33 ; _rtB -> B_8_62_0
= _rtP -> P_34 ; _rtB -> B_8_73_0 = _rtP -> P_42 ; _rtB -> B_8_79_0 = _rtP ->
P_43 ; _rtB -> B_8_88_0 = _rtP -> P_47 ; _rtB -> B_8_94_0 = _rtP -> P_48 ;
_rtB -> B_8_105_0 = _rtP -> P_56 ; _rtB -> B_8_111_0 = _rtP -> P_57 ; _rtB ->
B_8_120_0 = _rtP -> P_61 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { int32_T isHit ;
B_Inverter_T * _rtB ; P_Inverter_T * _rtP ; DW_Inverter_T * _rtDW ; _rtDW = (
( DW_Inverter_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_Inverter_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Inverter_T * ) _ssGetModelBlockIO ( S )
) ; { real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK . Head = ( ( _rtDW -> TransportDelay_IWORK .
Head < ( _rtDW -> TransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK
. Head == _rtDW -> TransportDelay_IWORK . Tail ) { if ( !
Inverter_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay_IWORK .
CircularBufSize , & _rtDW -> TransportDelay_IWORK . Tail , & _rtDW ->
TransportDelay_IWORK . Head , & _rtDW -> TransportDelay_IWORK . Last ,
simTime - _rtP -> P_3 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> TransportDelay_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
tBuffer ) [ _rtDW -> TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer )
[ _rtDW -> TransportDelay_IWORK . Head ] = _rtB -> B_8_0_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput = _rtB -> B_8_7_0 ; } { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 0 ] ; real_T * *
tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 1
] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_n . Head =
( ( _rtDW -> TransportDelay_IWORK_n . Head < ( _rtDW ->
TransportDelay_IWORK_n . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK_n . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_n . Head == _rtDW -> TransportDelay_IWORK_n . Tail ) {
if ( ! Inverter_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_n . CircularBufSize , & _rtDW -> TransportDelay_IWORK_n
. Tail , & _rtDW -> TransportDelay_IWORK_n . Head , & _rtDW ->
TransportDelay_IWORK_n . Last , simTime - _rtP -> P_8 , tBuffer , uBuffer , (
NULL ) , ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_n .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * tBuffer ) [ _rtDW -> TransportDelay_IWORK_n . Head ] =
simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_n . Head ] = _rtB ->
B_8_8_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW
-> Memory_PreviousInput_p = _rtB -> B_8_15_0 ; } isHit = ssIsSampleHit ( S ,
2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> DelayInput2_DSTATE = _rtB -> B_8_45_0
; _rtDW -> DelayInput2_DSTATE_c = _rtB -> B_8_60_0 ; _rtDW ->
DelayInput2_DSTATE_d = _rtB -> B_8_77_0 ; _rtDW -> DelayInput2_DSTATE_l =
_rtB -> B_8_92_0 ; _rtDW -> DelayInput2_DSTATE_n = _rtB -> B_8_109_0 ; _rtDW
-> DelayInput2_DSTATE_p = _rtB -> B_8_124_0 ; ssCallAccelRunBlock ( S , 8 ,
126 , SS_CALL_MDL_UPDATE ) ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID4 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_Inverter_T * _rtB ;
XDot_Inverter_T * _rtXdot ; _rtXdot = ( ( XDot_Inverter_T * ) ssGetdX ( S ) )
; _rtB = ( ( B_Inverter_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot ->
integrator_CSTATE = _rtB -> B_8_145_0 ; _rtXdot -> integrator_CSTATE_f = _rtB
-> B_8_147_0 ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_Inverter_T * _rtB ;
ZCV_Inverter_T * _rtZCSV ; _rtZCSV = ( ( ZCV_Inverter_T * )
ssGetSolverZcSignalVector ( S ) ) ; _rtB = ( ( B_Inverter_T * )
_ssGetModelBlockIO ( S ) ) ; _rtZCSV -> Compare_RelopInput_ZC = _rtB ->
B_8_33_0 - Inverter_rtC ( S ) -> B_8_34_0 ; _rtZCSV ->
Compare_RelopInput_ZC_e = _rtB -> B_8_33_0 - Inverter_rtC ( S ) -> B_8_50_0 ;
_rtZCSV -> Compare_RelopInput_ZC_p = _rtB -> B_8_66_0 - Inverter_rtC ( S ) ->
B_8_67_0 ; _rtZCSV -> Compare_RelopInput_ZC_a = _rtB -> B_8_66_0 -
Inverter_rtC ( S ) -> B_8_82_0 ; _rtZCSV -> Compare_RelopInput_ZC_n = _rtB ->
B_8_98_0 - Inverter_rtC ( S ) -> B_8_99_0 ; _rtZCSV ->
Compare_RelopInput_ZC_j = _rtB -> B_8_98_0 - Inverter_rtC ( S ) -> B_8_114_0
; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S ,
0 , 201771087U ) ; ssSetChecksumVal ( S , 1 , 3976334263U ) ;
ssSetChecksumVal ( S , 2 , 1115299710U ) ; ssSetChecksumVal ( S , 3 ,
2876648845U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "9.1" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_Inverter_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_Inverter_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_Inverter_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & Inverter_rtDefaultP ) ; _ssSetConstBlockIO ( S , & Inverter_rtInvariant )
; } static void mdlInitializeSampleTimes ( SimStruct * S ) {
slAccRegPrmChangeFcn ( S , mdlOutputsTID4 ) ; } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
