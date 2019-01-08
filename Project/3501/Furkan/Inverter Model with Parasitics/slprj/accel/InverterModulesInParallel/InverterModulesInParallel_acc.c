#include "__cf_InverterModulesInParallel.h"
#include <math.h>
#include "InverterModulesInParallel_acc.h"
#include "InverterModulesInParallel_acc_private.h"
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
boolean_T InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T
* bufSzPtr , int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T
tMinusDelay , real_T * * tBufPtr , real_T * * uBufPtr , real_T * * xBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
{ int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T
* tBuf = * tBufPtr ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if (
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
return ( true ) ; } real_T InverterModulesInParallel_acc_rt_TDelayInterpolate
( real_T tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T
bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput
, boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) { int_T i ;
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
SimStruct * S , int_T tid ) { real_T rtb_B_20_206_0 ; real_T rtb_B_20_191_0 ;
real_T rtb_B_20_174_0 ; real_T rtb_B_20_159_0 ; real_T rtb_B_20_142_0 ;
real_T rtb_B_20_127_0 ; real_T rtb_B_20_110_0 ; real_T rtb_B_20_95_0 ; real_T
rtb_B_20_78_0 ; real_T rtb_B_20_63_0 ; real_T rtb_B_20_35_0 ; real_T
rtb_B_20_20_0 ; real_T rtb_B_20_7_0 ; boolean_T rtb_B_20_207_0 ; boolean_T
rtb_B_20_192_0 ; boolean_T rtb_B_20_175_0 ; boolean_T rtb_B_20_160_0 ;
boolean_T rtb_B_20_143_0 ; boolean_T rtb_B_20_128_0 ; boolean_T
rtb_B_20_111_0 ; boolean_T rtb_B_20_96_0 ; boolean_T rtb_B_20_79_0 ;
boolean_T rtb_B_20_64_0 ; boolean_T rtb_B_20_36_0 ; boolean_T rtb_B_20_21_0 ;
real_T rtb_B_20_200_0 ; real_T rtb_B_20_183_0 ; real_T rtb_B_20_168_0 ;
real_T rtb_B_20_151_0 ; real_T rtb_B_20_136_0 ; real_T rtb_B_20_119_0 ;
real_T rtb_B_20_104_0 ; real_T rtb_B_20_87_0 ; real_T rtb_B_20_72_0 ; real_T
rtb_B_20_44_0 ; real_T rtb_B_20_29_0 ; real_T rtb_B_20_1_0 ; int32_T isHit ;
B_InverterModulesInParallel_T * _rtB ; P_InverterModulesInParallel_T * _rtP ;
X_InverterModulesInParallel_T * _rtX ; DW_InverterModulesInParallel_T * _rtDW
; _rtDW = ( ( DW_InverterModulesInParallel_T * ) ssGetRootDWork ( S ) ) ;
_rtX = ( ( X_InverterModulesInParallel_T * ) ssGetContStates ( S ) ) ; _rtP =
( ( P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_1_0 = _rtP -> P_52
; _rtB -> B_20_2_0 = _rtB -> B_20_0_0 * _rtP -> P_52 ; } _rtB -> B_20_4_0 =
muDoubleScalarSin ( _rtP -> P_56 * ssGetTaskTime ( S , 0 ) + _rtP -> P_57 ) *
_rtP -> P_54 + _rtP -> P_55 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_20_6_0 = _rtP -> P_58 ; } rtb_B_20_7_0 = ssGetT ( S
) + _rtB -> B_20_6_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_20_8_0 = _rtP -> P_59 ; } rtb_B_20_7_0 = look1_pbinlxpw ( _rtP
-> P_60 * muDoubleScalarRem ( rtb_B_20_7_0 , _rtB -> B_20_8_0 ) , _rtP ->
P_62 , _rtP -> P_61 , & _rtDW -> m_bpIndex , 2U ) ; isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_20_12_0 = _rtP -> P_63 ; } _rtB ->
B_20_13_0 = rtb_B_20_7_0 - _rtB -> B_20_12_0 ; _rtB -> B_20_14_0 = _rtB ->
B_20_4_0 - _rtB -> B_20_13_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode =
( _rtB -> B_20_14_0 > InverterModulesInParallel_rtC ( S ) -> B_20_15_0 ) ; }
if ( _rtDW -> Compare_Mode ) { _rtB -> B_20_18_0 = _rtB -> B_20_3_0 ; } else
{ _rtB -> B_20_18_0 = _rtB -> B_20_17_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_20_19_0 = _rtDW -> DelayInput2_DSTATE ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_20_0 =
_rtB -> B_20_18_0 - _rtB -> B_20_19_0 ; rtb_B_20_21_0 = ( rtb_B_20_20_0 >
_rtB -> B_20_2_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_20_23_0 = _rtB -> B_20_22_0 * rtb_B_20_1_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_21_0 ) {
rtb_B_20_20_0 = _rtB -> B_20_2_0 ; } else { if ( rtb_B_20_20_0 < _rtB ->
B_20_23_0 ) { rtb_B_20_20_0 = _rtB -> B_20_23_0 ; } } _rtB -> B_20_26_0 =
rtb_B_20_20_0 + _rtB -> B_20_19_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_27_0 [ 0 ] = _rtB -> B_20_26_0 ; _rtB ->
B_20_27_0 [ 1 ] = 0.0 ; _rtB -> B_20_27_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_1_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_27_0 [ 0 ] == _rtDW ->
INPUT_1_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_1_1_1_discrete [ 1 ] = _rtB ->
B_20_27_0 [ 0 ] ; _rtB -> B_20_27_0 [ 0 ] = _rtDW -> INPUT_1_1_1_discrete [ 1
] ; _rtB -> B_20_27_0 [ 3 ] = _rtDW -> INPUT_1_1_1_discrete [ 0 ] ;
rtb_B_20_29_0 = _rtP -> P_69 ; _rtB -> B_20_30_0 = _rtB -> B_20_28_0 * _rtP
-> P_69 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_g = ( _rtB ->
B_20_14_0 < InverterModulesInParallel_rtC ( S ) -> B_20_31_0 ) ; } if ( _rtDW
-> Compare_Mode_g ) { _rtB -> B_20_33_0 = _rtB -> B_20_3_0 ; } else { _rtB ->
B_20_33_0 = _rtB -> B_20_17_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_20_34_0 = _rtDW -> DelayInput2_DSTATE_c ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_35_0 = _rtB ->
B_20_33_0 - _rtB -> B_20_34_0 ; rtb_B_20_36_0 = ( rtb_B_20_35_0 > _rtB ->
B_20_30_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_20_38_0 = _rtB -> B_20_37_0 * rtb_B_20_29_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_36_0 ) {
rtb_B_20_35_0 = _rtB -> B_20_30_0 ; } else { if ( rtb_B_20_35_0 < _rtB ->
B_20_38_0 ) { rtb_B_20_35_0 = _rtB -> B_20_38_0 ; } } _rtB -> B_20_41_0 =
rtb_B_20_35_0 + _rtB -> B_20_34_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_42_0 [ 0 ] = _rtB -> B_20_41_0 ; _rtB ->
B_20_42_0 [ 1 ] = 0.0 ; _rtB -> B_20_42_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_2_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_42_0 [ 0 ] == _rtDW ->
INPUT_2_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_2_1_1_discrete [ 1 ] = _rtB ->
B_20_42_0 [ 0 ] ; _rtB -> B_20_42_0 [ 0 ] = _rtDW -> INPUT_2_1_1_discrete [ 1
] ; _rtB -> B_20_42_0 [ 3 ] = _rtDW -> INPUT_2_1_1_discrete [ 0 ] ;
rtb_B_20_44_0 = _rtP -> P_74 ; _rtB -> B_20_45_0 = _rtB -> B_20_43_0 * _rtP
-> P_74 ; } _rtB -> B_20_47_0 = muDoubleScalarSin ( _rtP -> P_78 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_79 ) * _rtP -> P_76 + _rtP -> P_77 ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_20_49_0 =
_rtP -> P_80 ; } rtb_B_20_29_0 = ssGetT ( S ) + _rtB -> B_20_49_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_20_51_0 = _rtP ->
P_81 ; } rtb_B_20_29_0 = look1_pbinlxpw ( _rtP -> P_82 * muDoubleScalarRem (
rtb_B_20_29_0 , _rtB -> B_20_51_0 ) , _rtP -> P_84 , _rtP -> P_83 , & _rtDW
-> m_bpIndex_a , 2U ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_20_55_0 = _rtP -> P_85 ; } _rtB -> B_20_56_0 = rtb_B_20_29_0 -
_rtB -> B_20_55_0 ; _rtB -> B_20_57_0 = _rtB -> B_20_47_0 - _rtB -> B_20_56_0
; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_h = ( _rtB ->
B_20_57_0 > InverterModulesInParallel_rtC ( S ) -> B_20_58_0 ) ; } if ( _rtDW
-> Compare_Mode_h ) { _rtB -> B_20_61_0 = _rtB -> B_20_46_0 ; } else { _rtB
-> B_20_61_0 = _rtB -> B_20_60_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_62_0 = _rtDW -> DelayInput2_DSTATE_o ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_63_0 =
_rtB -> B_20_61_0 - _rtB -> B_20_62_0 ; rtb_B_20_64_0 = ( rtb_B_20_63_0 >
_rtB -> B_20_45_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_20_66_0 = _rtB -> B_20_65_0 * rtb_B_20_44_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_64_0 ) {
rtb_B_20_63_0 = _rtB -> B_20_45_0 ; } else { if ( rtb_B_20_63_0 < _rtB ->
B_20_66_0 ) { rtb_B_20_63_0 = _rtB -> B_20_66_0 ; } } _rtB -> B_20_69_0 =
rtb_B_20_63_0 + _rtB -> B_20_62_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_70_0 [ 0 ] = _rtB -> B_20_69_0 ; _rtB ->
B_20_70_0 [ 1 ] = 0.0 ; _rtB -> B_20_70_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_11_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_70_0 [ 0 ] == _rtDW ->
INPUT_11_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_11_1_1_discrete [ 1 ] = _rtB
-> B_20_70_0 [ 0 ] ; _rtB -> B_20_70_0 [ 0 ] = _rtDW -> INPUT_11_1_1_discrete
[ 1 ] ; _rtB -> B_20_70_0 [ 3 ] = _rtDW -> INPUT_11_1_1_discrete [ 0 ] ;
rtb_B_20_72_0 = _rtP -> P_91 ; _rtB -> B_20_73_0 = _rtB -> B_20_71_0 * _rtP
-> P_91 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_i = ( _rtB ->
B_20_57_0 < InverterModulesInParallel_rtC ( S ) -> B_20_74_0 ) ; } if ( _rtDW
-> Compare_Mode_i ) { _rtB -> B_20_76_0 = _rtB -> B_20_46_0 ; } else { _rtB
-> B_20_76_0 = _rtB -> B_20_60_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_77_0 = _rtDW -> DelayInput2_DSTATE_k ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_78_0 =
_rtB -> B_20_76_0 - _rtB -> B_20_77_0 ; rtb_B_20_79_0 = ( rtb_B_20_78_0 >
_rtB -> B_20_73_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_20_81_0 = _rtB -> B_20_80_0 * rtb_B_20_72_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_79_0 ) {
rtb_B_20_78_0 = _rtB -> B_20_73_0 ; } else { if ( rtb_B_20_78_0 < _rtB ->
B_20_81_0 ) { rtb_B_20_78_0 = _rtB -> B_20_81_0 ; } } _rtB -> B_20_84_0 =
rtb_B_20_78_0 + _rtB -> B_20_77_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_85_0 [ 0 ] = _rtB -> B_20_84_0 ; _rtB ->
B_20_85_0 [ 1 ] = 0.0 ; _rtB -> B_20_85_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_12_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_85_0 [ 0 ] == _rtDW ->
INPUT_12_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_12_1_1_discrete [ 1 ] = _rtB
-> B_20_85_0 [ 0 ] ; _rtB -> B_20_85_0 [ 0 ] = _rtDW -> INPUT_12_1_1_discrete
[ 1 ] ; _rtB -> B_20_85_0 [ 3 ] = _rtDW -> INPUT_12_1_1_discrete [ 0 ] ;
rtb_B_20_87_0 = _rtP -> P_96 ; _rtB -> B_20_88_0 = _rtB -> B_20_86_0 * _rtP
-> P_96 ; } _rtB -> B_20_89_0 = muDoubleScalarSin ( _rtP -> P_99 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_100 ) * _rtP -> P_97 + _rtP -> P_98 ;
_rtB -> B_20_90_0 = _rtB -> B_20_89_0 - _rtB -> B_20_13_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> Compare_Mode_p = ( _rtB -> B_20_90_0 >
InverterModulesInParallel_rtC ( S ) -> B_20_91_0 ) ; } if ( _rtDW ->
Compare_Mode_p ) { _rtB -> B_20_93_0 = _rtB -> B_20_3_0 ; } else { _rtB ->
B_20_93_0 = _rtB -> B_20_17_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_20_94_0 = _rtDW -> DelayInput2_DSTATE_d ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_95_0 = _rtB ->
B_20_93_0 - _rtB -> B_20_94_0 ; rtb_B_20_96_0 = ( rtb_B_20_95_0 > _rtB ->
B_20_88_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_20_98_0 = _rtB -> B_20_97_0 * rtb_B_20_87_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_96_0 ) {
rtb_B_20_95_0 = _rtB -> B_20_88_0 ; } else { if ( rtb_B_20_95_0 < _rtB ->
B_20_98_0 ) { rtb_B_20_95_0 = _rtB -> B_20_98_0 ; } } _rtB -> B_20_101_0 =
rtb_B_20_95_0 + _rtB -> B_20_94_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_102_0 [ 0 ] = _rtB -> B_20_101_0 ; _rtB ->
B_20_102_0 [ 1 ] = 0.0 ; _rtB -> B_20_102_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_3_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_102_0 [ 0 ] == _rtDW ->
INPUT_3_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_3_1_1_discrete [ 1 ] = _rtB ->
B_20_102_0 [ 0 ] ; _rtB -> B_20_102_0 [ 0 ] = _rtDW -> INPUT_3_1_1_discrete [
1 ] ; _rtB -> B_20_102_0 [ 3 ] = _rtDW -> INPUT_3_1_1_discrete [ 0 ] ;
rtb_B_20_104_0 = _rtP -> P_105 ; _rtB -> B_20_105_0 = _rtB -> B_20_103_0 *
_rtP -> P_105 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_j = ( _rtB ->
B_20_90_0 < InverterModulesInParallel_rtC ( S ) -> B_20_106_0 ) ; } if (
_rtDW -> Compare_Mode_j ) { _rtB -> B_20_108_0 = _rtB -> B_20_3_0 ; } else {
_rtB -> B_20_108_0 = _rtB -> B_20_17_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_20_109_0 = _rtDW -> DelayInput2_DSTATE_f
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_110_0
= _rtB -> B_20_108_0 - _rtB -> B_20_109_0 ; rtb_B_20_111_0 = ( rtb_B_20_110_0
> _rtB -> B_20_105_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_20_113_0 = _rtB -> B_20_112_0 * rtb_B_20_104_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_111_0 ) {
rtb_B_20_110_0 = _rtB -> B_20_105_0 ; } else { if ( rtb_B_20_110_0 < _rtB ->
B_20_113_0 ) { rtb_B_20_110_0 = _rtB -> B_20_113_0 ; } } _rtB -> B_20_116_0 =
rtb_B_20_110_0 + _rtB -> B_20_109_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_117_0 [ 0 ] = _rtB -> B_20_116_0 ; _rtB ->
B_20_117_0 [ 1 ] = 0.0 ; _rtB -> B_20_117_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_4_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_117_0 [ 0 ] == _rtDW ->
INPUT_4_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_4_1_1_discrete [ 1 ] = _rtB ->
B_20_117_0 [ 0 ] ; _rtB -> B_20_117_0 [ 0 ] = _rtDW -> INPUT_4_1_1_discrete [
1 ] ; _rtB -> B_20_117_0 [ 3 ] = _rtDW -> INPUT_4_1_1_discrete [ 0 ] ;
rtb_B_20_119_0 = _rtP -> P_110 ; _rtB -> B_20_120_0 = _rtB -> B_20_118_0 *
_rtP -> P_110 ; } _rtB -> B_20_121_0 = muDoubleScalarSin ( _rtP -> P_113 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_114 ) * _rtP -> P_111 + _rtP -> P_112 ;
_rtB -> B_20_122_0 = _rtB -> B_20_121_0 - _rtB -> B_20_13_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> Compare_Mode_hp = ( _rtB -> B_20_122_0 >
InverterModulesInParallel_rtC ( S ) -> B_20_123_0 ) ; } if ( _rtDW ->
Compare_Mode_hp ) { _rtB -> B_20_125_0 = _rtB -> B_20_3_0 ; } else { _rtB ->
B_20_125_0 = _rtB -> B_20_17_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_20_126_0 = _rtDW -> DelayInput2_DSTATE_n ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_127_0 = _rtB ->
B_20_125_0 - _rtB -> B_20_126_0 ; rtb_B_20_128_0 = ( rtb_B_20_127_0 > _rtB ->
B_20_120_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_20_130_0 = _rtB -> B_20_129_0 * rtb_B_20_119_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_128_0 ) {
rtb_B_20_127_0 = _rtB -> B_20_120_0 ; } else { if ( rtb_B_20_127_0 < _rtB ->
B_20_130_0 ) { rtb_B_20_127_0 = _rtB -> B_20_130_0 ; } } _rtB -> B_20_133_0 =
rtb_B_20_127_0 + _rtB -> B_20_126_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_134_0 [ 0 ] = _rtB -> B_20_133_0 ; _rtB ->
B_20_134_0 [ 1 ] = 0.0 ; _rtB -> B_20_134_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_5_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_134_0 [ 0 ] == _rtDW ->
INPUT_5_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_5_1_1_discrete [ 1 ] = _rtB ->
B_20_134_0 [ 0 ] ; _rtB -> B_20_134_0 [ 0 ] = _rtDW -> INPUT_5_1_1_discrete [
1 ] ; _rtB -> B_20_134_0 [ 3 ] = _rtDW -> INPUT_5_1_1_discrete [ 0 ] ;
rtb_B_20_136_0 = _rtP -> P_119 ; _rtB -> B_20_137_0 = _rtB -> B_20_135_0 *
_rtP -> P_119 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_iz = ( _rtB ->
B_20_122_0 < InverterModulesInParallel_rtC ( S ) -> B_20_138_0 ) ; } if (
_rtDW -> Compare_Mode_iz ) { _rtB -> B_20_140_0 = _rtB -> B_20_3_0 ; } else {
_rtB -> B_20_140_0 = _rtB -> B_20_17_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_20_141_0 = _rtDW -> DelayInput2_DSTATE_m
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_142_0
= _rtB -> B_20_140_0 - _rtB -> B_20_141_0 ; rtb_B_20_143_0 = ( rtb_B_20_142_0
> _rtB -> B_20_137_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_20_145_0 = _rtB -> B_20_144_0 * rtb_B_20_136_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_143_0 ) {
rtb_B_20_142_0 = _rtB -> B_20_137_0 ; } else { if ( rtb_B_20_142_0 < _rtB ->
B_20_145_0 ) { rtb_B_20_142_0 = _rtB -> B_20_145_0 ; } } _rtB -> B_20_148_0 =
rtb_B_20_142_0 + _rtB -> B_20_141_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_149_0 [ 0 ] = _rtB -> B_20_148_0 ; _rtB ->
B_20_149_0 [ 1 ] = 0.0 ; _rtB -> B_20_149_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_6_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_149_0 [ 0 ] == _rtDW ->
INPUT_6_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_6_1_1_discrete [ 1 ] = _rtB ->
B_20_149_0 [ 0 ] ; _rtB -> B_20_149_0 [ 0 ] = _rtDW -> INPUT_6_1_1_discrete [
1 ] ; _rtB -> B_20_149_0 [ 3 ] = _rtDW -> INPUT_6_1_1_discrete [ 0 ] ;
rtb_B_20_151_0 = _rtP -> P_124 ; _rtB -> B_20_152_0 = _rtB -> B_20_150_0 *
_rtP -> P_124 ; } _rtB -> B_20_153_0 = muDoubleScalarSin ( _rtP -> P_127 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_128 ) * _rtP -> P_125 + _rtP -> P_126 ;
_rtB -> B_20_154_0 = _rtB -> B_20_153_0 - _rtB -> B_20_56_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> Compare_Mode_ja = ( _rtB -> B_20_154_0 >
InverterModulesInParallel_rtC ( S ) -> B_20_155_0 ) ; } if ( _rtDW ->
Compare_Mode_ja ) { _rtB -> B_20_157_0 = _rtB -> B_20_46_0 ; } else { _rtB ->
B_20_157_0 = _rtB -> B_20_60_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_20_158_0 = _rtDW -> DelayInput2_DSTATE_dc ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_159_0 =
_rtB -> B_20_157_0 - _rtB -> B_20_158_0 ; rtb_B_20_160_0 = ( rtb_B_20_159_0 >
_rtB -> B_20_152_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_20_162_0 = _rtB -> B_20_161_0 * rtb_B_20_151_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_160_0 ) {
rtb_B_20_159_0 = _rtB -> B_20_152_0 ; } else { if ( rtb_B_20_159_0 < _rtB ->
B_20_162_0 ) { rtb_B_20_159_0 = _rtB -> B_20_162_0 ; } } _rtB -> B_20_165_0 =
rtb_B_20_159_0 + _rtB -> B_20_158_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_166_0 [ 0 ] = _rtB -> B_20_165_0 ; _rtB ->
B_20_166_0 [ 1 ] = 0.0 ; _rtB -> B_20_166_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_7_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_166_0 [ 0 ] == _rtDW ->
INPUT_7_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_7_1_1_discrete [ 1 ] = _rtB ->
B_20_166_0 [ 0 ] ; _rtB -> B_20_166_0 [ 0 ] = _rtDW -> INPUT_7_1_1_discrete [
1 ] ; _rtB -> B_20_166_0 [ 3 ] = _rtDW -> INPUT_7_1_1_discrete [ 0 ] ;
rtb_B_20_168_0 = _rtP -> P_133 ; _rtB -> B_20_169_0 = _rtB -> B_20_167_0 *
_rtP -> P_133 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_c = ( _rtB ->
B_20_154_0 < InverterModulesInParallel_rtC ( S ) -> B_20_170_0 ) ; } if (
_rtDW -> Compare_Mode_c ) { _rtB -> B_20_172_0 = _rtB -> B_20_46_0 ; } else {
_rtB -> B_20_172_0 = _rtB -> B_20_60_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_20_173_0 = _rtDW -> DelayInput2_DSTATE_dj
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_174_0
= _rtB -> B_20_172_0 - _rtB -> B_20_173_0 ; rtb_B_20_175_0 = ( rtb_B_20_174_0
> _rtB -> B_20_169_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_20_177_0 = _rtB -> B_20_176_0 * rtb_B_20_168_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_175_0 ) {
rtb_B_20_174_0 = _rtB -> B_20_169_0 ; } else { if ( rtb_B_20_174_0 < _rtB ->
B_20_177_0 ) { rtb_B_20_174_0 = _rtB -> B_20_177_0 ; } } _rtB -> B_20_180_0 =
rtb_B_20_174_0 + _rtB -> B_20_173_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_181_0 [ 0 ] = _rtB -> B_20_180_0 ; _rtB ->
B_20_181_0 [ 1 ] = 0.0 ; _rtB -> B_20_181_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_8_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_181_0 [ 0 ] == _rtDW ->
INPUT_8_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_8_1_1_discrete [ 1 ] = _rtB ->
B_20_181_0 [ 0 ] ; _rtB -> B_20_181_0 [ 0 ] = _rtDW -> INPUT_8_1_1_discrete [
1 ] ; _rtB -> B_20_181_0 [ 3 ] = _rtDW -> INPUT_8_1_1_discrete [ 0 ] ;
rtb_B_20_183_0 = _rtP -> P_138 ; _rtB -> B_20_184_0 = _rtB -> B_20_182_0 *
_rtP -> P_138 ; } _rtB -> B_20_185_0 = muDoubleScalarSin ( _rtP -> P_141 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_142 ) * _rtP -> P_139 + _rtP -> P_140 ;
_rtB -> B_20_186_0 = _rtB -> B_20_185_0 - _rtB -> B_20_56_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> Compare_Mode_l = ( _rtB -> B_20_186_0 >
InverterModulesInParallel_rtC ( S ) -> B_20_187_0 ) ; } if ( _rtDW ->
Compare_Mode_l ) { _rtB -> B_20_189_0 = _rtB -> B_20_46_0 ; } else { _rtB ->
B_20_189_0 = _rtB -> B_20_60_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_20_190_0 = _rtDW -> DelayInput2_DSTATE_a ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_191_0 = _rtB ->
B_20_189_0 - _rtB -> B_20_190_0 ; rtb_B_20_192_0 = ( rtb_B_20_191_0 > _rtB ->
B_20_184_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_20_194_0 = _rtB -> B_20_193_0 * rtb_B_20_183_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_192_0 ) {
rtb_B_20_191_0 = _rtB -> B_20_184_0 ; } else { if ( rtb_B_20_191_0 < _rtB ->
B_20_194_0 ) { rtb_B_20_191_0 = _rtB -> B_20_194_0 ; } } _rtB -> B_20_197_0 =
rtb_B_20_191_0 + _rtB -> B_20_190_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_198_0 [ 0 ] = _rtB -> B_20_197_0 ; _rtB ->
B_20_198_0 [ 1 ] = 0.0 ; _rtB -> B_20_198_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_9_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_198_0 [ 0 ] == _rtDW ->
INPUT_9_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_9_1_1_discrete [ 1 ] = _rtB ->
B_20_198_0 [ 0 ] ; _rtB -> B_20_198_0 [ 0 ] = _rtDW -> INPUT_9_1_1_discrete [
1 ] ; _rtB -> B_20_198_0 [ 3 ] = _rtDW -> INPUT_9_1_1_discrete [ 0 ] ;
rtb_B_20_200_0 = _rtP -> P_147 ; _rtB -> B_20_201_0 = _rtB -> B_20_199_0 *
_rtP -> P_147 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_o = ( _rtB ->
B_20_186_0 < InverterModulesInParallel_rtC ( S ) -> B_20_202_0 ) ; } if (
_rtDW -> Compare_Mode_o ) { _rtB -> B_20_204_0 = _rtB -> B_20_46_0 ; } else {
_rtB -> B_20_204_0 = _rtB -> B_20_60_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_20_205_0 = _rtDW -> DelayInput2_DSTATE_nv
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_20_206_0
= _rtB -> B_20_204_0 - _rtB -> B_20_205_0 ; rtb_B_20_207_0 = ( rtb_B_20_206_0
> _rtB -> B_20_201_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_20_209_0 = _rtB -> B_20_208_0 * rtb_B_20_200_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_20_207_0 ) {
rtb_B_20_206_0 = _rtB -> B_20_201_0 ; } else { if ( rtb_B_20_206_0 < _rtB ->
B_20_209_0 ) { rtb_B_20_206_0 = _rtB -> B_20_209_0 ; } } _rtB -> B_20_212_0 =
rtb_B_20_206_0 + _rtB -> B_20_205_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_20_213_0 [ 0 ] = _rtB -> B_20_212_0 ; _rtB ->
B_20_213_0 [ 1 ] = 0.0 ; _rtB -> B_20_213_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_10_1_1_discrete [ 0 ] = ! ( _rtB -> B_20_213_0 [ 0 ] == _rtDW ->
INPUT_10_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_10_1_1_discrete [ 1 ] = _rtB
-> B_20_213_0 [ 0 ] ; _rtB -> B_20_213_0 [ 0 ] = _rtDW ->
INPUT_10_1_1_discrete [ 1 ] ; _rtB -> B_20_213_0 [ 3 ] = _rtDW ->
INPUT_10_1_1_discrete [ 0 ] ; ssCallAccelRunBlock ( S , 20 , 214 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 215 ,
SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit
!= 0 ) && ( ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB -> B_20_217_0 ) { if
( ! _rtDW -> TrueRMS_MODE_e ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart (
S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( void ) memset
( & ( ( ( XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) )
-> integrator_CSTATE_c ) , 0 , 3 * sizeof ( boolean_T ) ) ; _rtDW ->
TrueRMS_MODE_e = true ; } } else { if ( _rtDW -> TrueRMS_MODE_e ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & ( ( (
XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_c ) , 1 , 3 * sizeof ( boolean_T ) ) ; _rtDW ->
TrueRMS_MODE_e = false ; } } } if ( _rtDW -> TrueRMS_MODE_e ) { _rtB ->
B_16_1_0 [ 0 ] = _rtX -> integrator_CSTATE_c [ 0 ] ; _rtB -> B_16_1_0 [ 1 ] =
_rtX -> integrator_CSTATE_c [ 1 ] ; _rtB -> B_16_1_0 [ 2 ] = _rtX ->
integrator_CSTATE_c [ 2 ] ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_b . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 3 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & _rtB ->
B_16_2_0 [ 0 ] ; int_T * iw_Tail = & _rtDW -> TransportDelay_IWORK_g . Tail [
0 ] ; int_T * iw_Head = & _rtDW -> TransportDelay_IWORK_g . Head [ 0 ] ;
int_T * iw_Last = & _rtDW -> TransportDelay_IWORK_g . Last [ 0 ] ; int_T *
iw_CircularBufSize = & _rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 0
] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( ( _rtP -> P_25 > 0.0 )
? _rtP -> P_25 : 0.0 ) ; tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
InverterModulesInParallel_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail
[ i1 ] , iw_Head [ i1 ] , _rtP -> P_26 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; tBuffer ++ ; uBuffer ++ ; } } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_16_3_0 = _rtP -> P_27 ; _rtB -> B_16_4_0 [ 0 ] =
_rtDW -> Memory_PreviousInput_k [ 0 ] ; _rtB -> B_16_4_0 [ 1 ] = _rtDW ->
Memory_PreviousInput_k [ 1 ] ; _rtB -> B_16_4_0 [ 2 ] = _rtDW ->
Memory_PreviousInput_k [ 2 ] ; } if ( ssGetT ( S ) >= _rtB -> B_16_3_0 ) {
_rtB -> B_15_0_0 [ 0 ] = _rtB -> B_16_1_0 [ 0 ] - _rtB -> B_16_2_0 [ 0 ] ;
_rtB -> B_15_1_0 [ 0 ] = _rtP -> P_22 * _rtB -> B_15_0_0 [ 0 ] ; _rtB ->
B_16_7_0 [ 0 ] = _rtB -> B_15_1_0 [ 0 ] ; _rtB -> B_15_0_0 [ 1 ] = _rtB ->
B_16_1_0 [ 1 ] - _rtB -> B_16_2_0 [ 1 ] ; _rtB -> B_15_1_0 [ 1 ] = _rtP ->
P_22 * _rtB -> B_15_0_0 [ 1 ] ; _rtB -> B_16_7_0 [ 1 ] = _rtB -> B_15_1_0 [ 1
] ; _rtB -> B_15_0_0 [ 2 ] = _rtB -> B_16_1_0 [ 2 ] - _rtB -> B_16_2_0 [ 2 ]
; _rtB -> B_15_1_0 [ 2 ] = _rtP -> P_22 * _rtB -> B_15_0_0 [ 2 ] ; _rtB ->
B_16_7_0 [ 2 ] = _rtB -> B_15_1_0 [ 2 ] ; } else { _rtB -> B_16_7_0 [ 0 ] =
_rtB -> B_16_4_0 [ 0 ] ; _rtB -> B_16_7_0 [ 1 ] = _rtB -> B_16_4_0 [ 1 ] ;
_rtB -> B_16_7_0 [ 2 ] = _rtB -> B_16_4_0 [ 2 ] ; } _rtB -> B_16_8_0 [ 0 ] =
_rtB -> B_20_215_0 [ 3 ] * _rtB -> B_20_215_0 [ 3 ] ; _rtB -> B_16_8_0 [ 1 ]
= _rtB -> B_20_215_0 [ 1 ] * _rtB -> B_20_215_0 [ 1 ] ; _rtB -> B_16_8_0 [ 2
] = _rtB -> B_20_215_0 [ 2 ] * _rtB -> B_20_215_0 [ 2 ] ; if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 0 ] = _rtB -> B_16_7_0 [ 0 ] >= _rtP
-> P_29 ? 1 : _rtB -> B_16_7_0 [ 0 ] > _rtP -> P_30 ? 0 : - 1 ; _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 1 ] = _rtB -> B_16_7_0 [ 1 ] >= _rtP
-> P_29 ? 1 : _rtB -> B_16_7_0 [ 1 ] > _rtP -> P_30 ? 0 : - 1 ; _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 2 ] = _rtB -> B_16_7_0 [ 2 ] >= _rtP
-> P_29 ? 1 : _rtB -> B_16_7_0 [ 2 ] > _rtP -> P_30 ? 0 : - 1 ; } _rtB ->
B_16_9_0 [ 0 ] = _rtDW -> Saturationtoavoidnegativesqrt_MODE_c [ 0 ] == 1 ?
_rtP -> P_29 : _rtDW -> Saturationtoavoidnegativesqrt_MODE_c [ 0 ] == - 1 ?
_rtP -> P_30 : _rtB -> B_16_7_0 [ 0 ] ; _rtB -> B_16_9_0 [ 1 ] = _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 1 ] == 1 ? _rtP -> P_29 : _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 1 ] == - 1 ? _rtP -> P_30 : _rtB ->
B_16_7_0 [ 1 ] ; _rtB -> B_16_9_0 [ 2 ] = _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 2 ] == 1 ? _rtP -> P_29 : _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 2 ] == - 1 ? _rtP -> P_30 : _rtB ->
B_16_7_0 [ 2 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) { if ( _rtDW ->
Sqrt_DWORK1 != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW
-> Sqrt_DWORK1 = 0 ; } _rtB -> B_16_10_0 [ 0 ] = muDoubleScalarSqrt ( _rtB ->
B_16_9_0 [ 0 ] ) ; _rtB -> B_16_10_0 [ 1 ] = muDoubleScalarSqrt ( _rtB ->
B_16_9_0 [ 1 ] ) ; _rtB -> B_16_10_0 [ 2 ] = muDoubleScalarSqrt ( _rtB ->
B_16_9_0 [ 2 ] ) ; srUpdateBC ( _rtDW -> TrueRMS_SubsysRanBC_i ) ; } else {
if ( _rtB -> B_16_9_0 [ 0 ] < 0.0 ) { _rtB -> B_16_10_0 [ 0 ] = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB -> B_16_9_0 [ 0 ] ) ) ; } else
{ _rtB -> B_16_10_0 [ 0 ] = muDoubleScalarSqrt ( _rtB -> B_16_9_0 [ 0 ] ) ; }
if ( _rtB -> B_16_9_0 [ 0 ] < 0.0 ) { _rtDW -> Sqrt_DWORK1 = 1 ; } if ( _rtB
-> B_16_9_0 [ 1 ] < 0.0 ) { _rtB -> B_16_10_0 [ 1 ] = - muDoubleScalarSqrt (
muDoubleScalarAbs ( _rtB -> B_16_9_0 [ 1 ] ) ) ; } else { _rtB -> B_16_10_0 [
1 ] = muDoubleScalarSqrt ( _rtB -> B_16_9_0 [ 1 ] ) ; } if ( _rtB -> B_16_9_0
[ 1 ] < 0.0 ) { _rtDW -> Sqrt_DWORK1 = 1 ; } if ( _rtB -> B_16_9_0 [ 2 ] <
0.0 ) { _rtB -> B_16_10_0 [ 2 ] = - muDoubleScalarSqrt ( muDoubleScalarAbs (
_rtB -> B_16_9_0 [ 2 ] ) ) ; } else { _rtB -> B_16_10_0 [ 2 ] =
muDoubleScalarSqrt ( _rtB -> B_16_9_0 [ 2 ] ) ; } if ( _rtB -> B_16_9_0 [ 2 ]
< 0.0 ) { _rtDW -> Sqrt_DWORK1 = 1 ; } } } isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB ->
B_20_219_0 ) { if ( ! _rtDW -> RMS_MODE_h ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } (
void ) memset ( & ( ( ( XDis_InverterModulesInParallel_T * )
ssGetContStateDisabled ( S ) ) -> integrator_CSTATE_o ) , 0 , 6 * sizeof (
boolean_T ) ) ; _rtDW -> RMS_MODE_h = true ; } } else { if ( _rtDW ->
RMS_MODE_h ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void )
memset ( & ( ( ( XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled
( S ) ) -> integrator_CSTATE_o ) , 1 , 6 * sizeof ( boolean_T ) ) ; _rtDW ->
RMS_MODE_h = false ; } } } if ( _rtDW -> RMS_MODE_h ) { _rtB -> B_14_0_0 [ 0
] = _rtX -> integrator_CSTATE_o [ 0 ] ; _rtB -> B_14_0_0 [ 1 ] = _rtX ->
integrator_CSTATE_o [ 1 ] ; _rtB -> B_14_0_0 [ 2 ] = _rtX ->
integrator_CSTATE_o [ 2 ] ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_f . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_f . TUbufferPtrs [ 3 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & _rtB ->
B_14_1_0 [ 0 ] ; int_T * iw_Tail = & _rtDW -> TransportDelay_IWORK_j . Tail [
0 ] ; int_T * iw_Head = & _rtDW -> TransportDelay_IWORK_j . Head [ 0 ] ;
int_T * iw_Last = & _rtDW -> TransportDelay_IWORK_j . Last [ 0 ] ; int_T *
iw_CircularBufSize = & _rtDW -> TransportDelay_IWORK_j . CircularBufSize [ 0
] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( ( _rtP -> P_4 > 0.0 ) ?
_rtP -> P_4 : 0.0 ) ; tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
InverterModulesInParallel_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail
[ i1 ] , iw_Head [ i1 ] , _rtP -> P_5 , 0 , ( boolean_T ) ( ssIsMinorTimeStep
( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) ) ) ; tBuffer ++ ;
uBuffer ++ ; } } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_14_3_0 = _rtP -> P_6 ; } rtb_B_20_21_0 = ( ssGetT ( S ) >= _rtB ->
B_14_3_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_14_5_0 [ 0 ] = _rtDW -> Memory_PreviousInput_e [ 0 ] ; _rtB -> B_14_5_0
[ 1 ] = _rtDW -> Memory_PreviousInput_e [ 1 ] ; _rtB -> B_14_5_0 [ 2 ] =
_rtDW -> Memory_PreviousInput_e [ 2 ] ; } if ( rtb_B_20_21_0 ) { _rtB ->
B_13_0_0 [ 0 ] = _rtB -> B_14_0_0 [ 0 ] - _rtB -> B_14_1_0 [ 0 ] ; _rtB ->
B_13_1_0 [ 0 ] = _rtP -> P_1 * _rtB -> B_13_0_0 [ 0 ] ; _rtB -> B_14_7_0 [ 0
] = _rtB -> B_13_1_0 [ 0 ] ; _rtB -> B_13_0_0 [ 1 ] = _rtB -> B_14_0_0 [ 1 ]
- _rtB -> B_14_1_0 [ 1 ] ; _rtB -> B_13_1_0 [ 1 ] = _rtP -> P_1 * _rtB ->
B_13_0_0 [ 1 ] ; _rtB -> B_14_7_0 [ 1 ] = _rtB -> B_13_1_0 [ 1 ] ; _rtB ->
B_13_0_0 [ 2 ] = _rtB -> B_14_0_0 [ 2 ] - _rtB -> B_14_1_0 [ 2 ] ; _rtB ->
B_13_1_0 [ 2 ] = _rtP -> P_1 * _rtB -> B_13_0_0 [ 2 ] ; _rtB -> B_14_7_0 [ 2
] = _rtB -> B_13_1_0 [ 2 ] ; } else { _rtB -> B_14_7_0 [ 0 ] = _rtB ->
B_14_5_0 [ 0 ] ; _rtB -> B_14_7_0 [ 1 ] = _rtB -> B_14_5_0 [ 1 ] ; _rtB ->
B_14_7_0 [ 2 ] = _rtB -> B_14_5_0 [ 2 ] ; } _rtB -> B_14_8_0 [ 0 ] = _rtX ->
integrator_CSTATE_a [ 0 ] ; _rtB -> B_14_8_0 [ 1 ] = _rtX ->
integrator_CSTATE_a [ 1 ] ; _rtB -> B_14_8_0 [ 2 ] = _rtX ->
integrator_CSTATE_a [ 2 ] ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_i . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_i . TUbufferPtrs [ 3 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & _rtB ->
B_14_9_0 [ 0 ] ; int_T * iw_Tail = & _rtDW -> TransportDelay_IWORK_d . Tail [
0 ] ; int_T * iw_Head = & _rtDW -> TransportDelay_IWORK_d . Head [ 0 ] ;
int_T * iw_Last = & _rtDW -> TransportDelay_IWORK_d . Last [ 0 ] ; int_T *
iw_CircularBufSize = & _rtDW -> TransportDelay_IWORK_d . CircularBufSize [ 0
] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( ( _rtP -> P_9 > 0.0 ) ?
_rtP -> P_9 : 0.0 ) ; tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
InverterModulesInParallel_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail
[ i1 ] , iw_Head [ i1 ] , _rtP -> P_10 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; tBuffer ++ ; uBuffer ++ ; } } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_14_11_0 = _rtP -> P_11 ; } rtb_B_20_21_0 = (
ssGetT ( S ) >= _rtB -> B_14_11_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_14_13_0 [ 0 ] = _rtDW -> Memory_PreviousInput_m
[ 0 ] ; _rtB -> B_14_13_0 [ 1 ] = _rtDW -> Memory_PreviousInput_m [ 1 ] ;
_rtB -> B_14_13_0 [ 2 ] = _rtDW -> Memory_PreviousInput_m [ 2 ] ; } if (
rtb_B_20_21_0 ) { _rtB -> B_12_0_0 [ 0 ] = _rtB -> B_14_8_0 [ 0 ] - _rtB ->
B_14_9_0 [ 0 ] ; _rtB -> B_12_1_0 [ 0 ] = _rtP -> P_0 * _rtB -> B_12_0_0 [ 0
] ; _rtB -> B_14_15_0 [ 0 ] = _rtB -> B_12_1_0 [ 0 ] ; _rtB -> B_12_0_0 [ 1 ]
= _rtB -> B_14_8_0 [ 1 ] - _rtB -> B_14_9_0 [ 1 ] ; _rtB -> B_12_1_0 [ 1 ] =
_rtP -> P_0 * _rtB -> B_12_0_0 [ 1 ] ; _rtB -> B_14_15_0 [ 1 ] = _rtB ->
B_12_1_0 [ 1 ] ; _rtB -> B_12_0_0 [ 2 ] = _rtB -> B_14_8_0 [ 2 ] - _rtB ->
B_14_9_0 [ 2 ] ; _rtB -> B_12_1_0 [ 2 ] = _rtP -> P_0 * _rtB -> B_12_0_0 [ 2
] ; _rtB -> B_14_15_0 [ 2 ] = _rtB -> B_12_1_0 [ 2 ] ; } else { _rtB ->
B_14_15_0 [ 0 ] = _rtB -> B_14_13_0 [ 0 ] ; _rtB -> B_14_15_0 [ 1 ] = _rtB ->
B_14_13_0 [ 1 ] ; _rtB -> B_14_15_0 [ 2 ] = _rtB -> B_14_13_0 [ 2 ] ; } _rtB
-> B_14_16_0 [ 0 ] . re = _rtB -> B_14_7_0 [ 0 ] ; _rtB -> B_14_16_0 [ 0 ] .
im = _rtB -> B_14_15_0 [ 0 ] ; _rtB -> B_14_16_0 [ 1 ] . re = _rtB ->
B_14_7_0 [ 1 ] ; _rtB -> B_14_16_0 [ 1 ] . im = _rtB -> B_14_15_0 [ 1 ] ;
_rtB -> B_14_16_0 [ 2 ] . re = _rtB -> B_14_7_0 [ 2 ] ; _rtB -> B_14_16_0 [ 2
] . im = _rtB -> B_14_15_0 [ 2 ] ; rtb_B_20_200_0 = muDoubleScalarSin ( _rtP
-> P_15 * ssGetTaskTime ( S , 0 ) + _rtP -> P_16 ) * _rtP -> P_13 + _rtP ->
P_14 ; _rtB -> B_14_19_0 [ 0 ] = _rtB -> B_20_215_0 [ 3 ] * rtb_B_20_200_0 ;
_rtB -> B_14_19_0 [ 1 ] = _rtB -> B_20_215_0 [ 1 ] * rtb_B_20_200_0 ; _rtB ->
B_14_19_0 [ 2 ] = _rtB -> B_20_215_0 [ 2 ] * rtb_B_20_200_0 ; rtb_B_20_200_0
= muDoubleScalarSin ( _rtP -> P_19 * ssGetTaskTime ( S , 0 ) + _rtP -> P_20 )
* _rtP -> P_17 + _rtP -> P_18 ; _rtB -> B_14_21_0 [ 0 ] = _rtB -> B_20_215_0
[ 3 ] * rtb_B_20_200_0 ; _rtB -> B_14_21_0 [ 1 ] = _rtB -> B_20_215_0 [ 1 ] *
rtb_B_20_200_0 ; _rtB -> B_14_21_0 [ 2 ] = _rtB -> B_20_215_0 [ 2 ] *
rtb_B_20_200_0 ; _rtB -> B_14_22_0 [ 0 ] = _rtP -> P_21 * muDoubleScalarHypot
( _rtB -> B_14_16_0 [ 0 ] . re , _rtB -> B_14_16_0 [ 0 ] . im ) ; _rtB ->
B_14_22_0 [ 1 ] = _rtP -> P_21 * muDoubleScalarHypot ( _rtB -> B_14_16_0 [ 1
] . re , _rtB -> B_14_16_0 [ 1 ] . im ) ; _rtB -> B_14_22_0 [ 2 ] = _rtP ->
P_21 * muDoubleScalarHypot ( _rtB -> B_14_16_0 [ 2 ] . re , _rtB -> B_14_16_0
[ 2 ] . im ) ; if ( ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW ->
RMS_SubsysRanBC_n ) ; } } if ( _rtB -> B_20_217_0 ) { _rtB -> B_20_221_0 [ 0
] = _rtB -> B_16_10_0 [ 0 ] ; _rtB -> B_20_221_0 [ 1 ] = _rtB -> B_16_10_0 [
1 ] ; _rtB -> B_20_221_0 [ 2 ] = _rtB -> B_16_10_0 [ 2 ] ; } else { _rtB ->
B_20_221_0 [ 0 ] = _rtB -> B_14_22_0 [ 0 ] ; _rtB -> B_20_221_0 [ 1 ] = _rtB
-> B_14_22_0 [ 1 ] ; _rtB -> B_20_221_0 [ 2 ] = _rtB -> B_14_22_0 [ 2 ] ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK . AQHandles || _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK . SlioLTF ) &&
ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK . AQHandles , _rtDW ->
HiddenToAsyncQueue_InsertedFor_RMS_at_outport_0_PWORK . SlioLTF , 0 ,
ssGetTaskTime ( S , 1 ) , ( void * ) & _rtB -> B_20_221_0 [ 0 ] ) ; } } }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { if ( _rtB ->
B_20_215_0 [ 25 ] > _rtP -> P_157 ) { _rtB -> B_20_223_0 = _rtP -> P_157 ; }
else if ( _rtB -> B_20_215_0 [ 25 ] < _rtP -> P_158 ) { _rtB -> B_20_223_0 =
_rtP -> P_158 ; } else { _rtB -> B_20_223_0 = _rtB -> B_20_215_0 [ 25 ] ; }
if ( _rtB -> B_20_215_0 [ 23 ] > _rtP -> P_159 ) { _rtB -> B_20_224_0 = _rtP
-> P_159 ; } else if ( _rtB -> B_20_215_0 [ 23 ] < _rtP -> P_160 ) { _rtB ->
B_20_224_0 = _rtP -> P_160 ; } else { _rtB -> B_20_224_0 = _rtB -> B_20_215_0
[ 23 ] ; } if ( _rtB -> B_20_215_0 [ 24 ] > _rtP -> P_161 ) { _rtB ->
B_20_225_0 = _rtP -> P_161 ; } else if ( _rtB -> B_20_215_0 [ 24 ] < _rtP ->
P_162 ) { _rtB -> B_20_225_0 = _rtP -> P_162 ; } else { _rtB -> B_20_225_0 =
_rtB -> B_20_215_0 [ 24 ] ; } if ( _rtB -> B_20_215_0 [ 51 ] > _rtP -> P_163
) { _rtB -> B_20_226_0 = _rtP -> P_163 ; } else if ( _rtB -> B_20_215_0 [ 51
] < _rtP -> P_164 ) { _rtB -> B_20_226_0 = _rtP -> P_164 ; } else { _rtB ->
B_20_226_0 = _rtB -> B_20_215_0 [ 51 ] ; } if ( _rtB -> B_20_215_0 [ 49 ] >
_rtP -> P_165 ) { _rtB -> B_20_227_0 = _rtP -> P_165 ; } else if ( _rtB ->
B_20_215_0 [ 49 ] < _rtP -> P_166 ) { _rtB -> B_20_227_0 = _rtP -> P_166 ; }
else { _rtB -> B_20_227_0 = _rtB -> B_20_215_0 [ 49 ] ; } if ( _rtB ->
B_20_215_0 [ 50 ] > _rtP -> P_167 ) { _rtB -> B_20_228_0 = _rtP -> P_167 ; }
else if ( _rtB -> B_20_215_0 [ 50 ] < _rtP -> P_168 ) { _rtB -> B_20_228_0 =
_rtP -> P_168 ; } else { _rtB -> B_20_228_0 = _rtB -> B_20_215_0 [ 50 ] ; }
ssCallAccelRunBlock ( S , 20 , 229 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 230 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
B_20_215_0 [ 26 ] > _rtP -> P_169 ) { _rtB -> B_20_231_0 = _rtP -> P_169 ; }
else if ( _rtB -> B_20_215_0 [ 26 ] < _rtP -> P_170 ) { _rtB -> B_20_231_0 =
_rtP -> P_170 ; } else { _rtB -> B_20_231_0 = _rtB -> B_20_215_0 [ 26 ] ; }
if ( _rtB -> B_20_215_0 [ 52 ] > _rtP -> P_171 ) { _rtB -> B_20_232_0 = _rtP
-> P_171 ; } else if ( _rtB -> B_20_215_0 [ 52 ] < _rtP -> P_172 ) { _rtB ->
B_20_232_0 = _rtP -> P_172 ; } else { _rtB -> B_20_232_0 = _rtB -> B_20_215_0
[ 52 ] ; } ssCallAccelRunBlock ( S , 20 , 233 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 20 , 300 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 502 , SS_CALL_MDL_OUTPUTS ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( _rtB -> B_20_640_0 ) { if ( ! _rtDW -> RMS_MODE ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( void ) memset ( & ( (
( XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_e ) , 0 , 2 * sizeof ( boolean_T ) ) ; _rtDW -> RMS_MODE =
true ; } } else { if ( _rtDW -> RMS_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & ( ( (
XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_e ) , 1 , 2 * sizeof ( boolean_T ) ) ; _rtDW -> RMS_MODE =
false ; } } } if ( _rtDW -> RMS_MODE ) { _rtB -> B_17_3_0 = (
muDoubleScalarSin ( _rtP -> P_36 * ssGetTaskTime ( S , 0 ) + _rtP -> P_37 ) *
_rtP -> P_34 + _rtP -> P_35 ) * _rtB -> B_20_215_0 [ 4 ] ; _rtB -> B_17_5_0 =
( muDoubleScalarSin ( _rtP -> P_40 * ssGetTaskTime ( S , 0 ) + _rtP -> P_41 )
* _rtP -> P_38 + _rtP -> P_39 ) * _rtB -> B_20_215_0 [ 4 ] ; if (
ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW -> RMS_SubsysRanBC ) ; }
} isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && (
ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB -> B_20_639_0 ) { if ( ! _rtDW
-> TrueRMS_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( (
XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE = 0 ; _rtDW -> TrueRMS_MODE = true ; } } else { if ( _rtDW
-> TrueRMS_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( (
XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE = 1 ; _rtDW -> TrueRMS_MODE = false ; } } } if ( _rtDW ->
TrueRMS_MODE ) { _rtB -> B_19_1_0 = _rtX -> integrator_CSTATE ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_45 ; _rtB -> B_19_2_0 =
InverterModulesInParallel_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK . CircularBufSize , &
_rtDW -> TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail ,
_rtDW -> TransportDelay_IWORK . Head , _rtP -> P_46 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_19_3_0 = _rtP -> P_47 ; _rtB -> B_19_4_0 = _rtDW -> Memory_PreviousInput ;
} if ( ssGetT ( S ) >= _rtB -> B_19_3_0 ) { _rtB -> B_18_0_0 = _rtB ->
B_19_1_0 - _rtB -> B_19_2_0 ; _rtB -> B_18_1_0 = _rtP -> P_42 * _rtB ->
B_18_0_0 ; _rtB -> B_19_7_0 = _rtB -> B_18_1_0 ; } else { _rtB -> B_19_7_0 =
_rtB -> B_19_4_0 ; } _rtB -> B_19_8_0 = _rtB -> B_20_215_0 [ 4 ] * _rtB ->
B_20_215_0 [ 4 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Saturationtoavoidnegativesqrt_MODE = _rtB -> B_19_7_0 >= _rtP -> P_49 ? 1 :
_rtB -> B_19_7_0 > _rtP -> P_50 ? 0 : - 1 ; srUpdateBC ( _rtDW ->
TrueRMS_SubsysRanBC ) ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { ssCallAccelRunBlock ( S , 20 , 659 , SS_CALL_MDL_OUTPUTS ) ; }
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID4 ( SimStruct * S ,
int_T tid ) { B_InverterModulesInParallel_T * _rtB ;
P_InverterModulesInParallel_T * _rtP ; _rtP = ( (
P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB ->
B_20_0_0 = _rtP -> P_51 ; _rtB -> B_20_3_0 = _rtP -> P_53 ; _rtB -> B_20_17_0
= _rtP -> P_65 ; _rtB -> B_20_22_0 = _rtP -> P_67 ; _rtB -> B_20_28_0 = _rtP
-> P_68 ; _rtB -> B_20_37_0 = _rtP -> P_72 ; _rtB -> B_20_43_0 = _rtP -> P_73
; _rtB -> B_20_46_0 = _rtP -> P_75 ; _rtB -> B_20_60_0 = _rtP -> P_87 ; _rtB
-> B_20_65_0 = _rtP -> P_89 ; _rtB -> B_20_71_0 = _rtP -> P_90 ; _rtB ->
B_20_80_0 = _rtP -> P_94 ; _rtB -> B_20_86_0 = _rtP -> P_95 ; _rtB ->
B_20_97_0 = _rtP -> P_103 ; _rtB -> B_20_103_0 = _rtP -> P_104 ; _rtB ->
B_20_112_0 = _rtP -> P_108 ; _rtB -> B_20_118_0 = _rtP -> P_109 ; _rtB ->
B_20_129_0 = _rtP -> P_117 ; _rtB -> B_20_135_0 = _rtP -> P_118 ; _rtB ->
B_20_144_0 = _rtP -> P_122 ; _rtB -> B_20_150_0 = _rtP -> P_123 ; _rtB ->
B_20_161_0 = _rtP -> P_131 ; _rtB -> B_20_167_0 = _rtP -> P_132 ; _rtB ->
B_20_176_0 = _rtP -> P_136 ; _rtB -> B_20_182_0 = _rtP -> P_137 ; _rtB ->
B_20_193_0 = _rtP -> P_145 ; _rtB -> B_20_199_0 = _rtP -> P_146 ; _rtB ->
B_20_208_0 = _rtP -> P_150 ; _rtB -> B_20_217_0 = ( _rtP -> P_156 != 0.0 ) ;
_rtB -> B_20_219_0 = ! _rtB -> B_20_217_0 ; _rtB -> B_20_639_0 = ( _rtP ->
P_173 != 0.0 ) ; _rtB -> B_20_640_0 = ! _rtB -> B_20_639_0 ; UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { int32_T isHit ;
B_InverterModulesInParallel_T * _rtB ; P_InverterModulesInParallel_T * _rtP ;
DW_InverterModulesInParallel_T * _rtDW ; _rtDW = ( (
DW_InverterModulesInParallel_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> DelayInput2_DSTATE
= _rtB -> B_20_26_0 ; _rtDW -> DelayInput2_DSTATE_c = _rtB -> B_20_41_0 ;
_rtDW -> DelayInput2_DSTATE_o = _rtB -> B_20_69_0 ; _rtDW ->
DelayInput2_DSTATE_k = _rtB -> B_20_84_0 ; _rtDW -> DelayInput2_DSTATE_d =
_rtB -> B_20_101_0 ; _rtDW -> DelayInput2_DSTATE_f = _rtB -> B_20_116_0 ;
_rtDW -> DelayInput2_DSTATE_n = _rtB -> B_20_133_0 ; _rtDW ->
DelayInput2_DSTATE_m = _rtB -> B_20_148_0 ; _rtDW -> DelayInput2_DSTATE_dc =
_rtB -> B_20_165_0 ; _rtDW -> DelayInput2_DSTATE_dj = _rtB -> B_20_180_0 ;
_rtDW -> DelayInput2_DSTATE_a = _rtB -> B_20_197_0 ; _rtDW ->
DelayInput2_DSTATE_nv = _rtB -> B_20_212_0 ; ssCallAccelRunBlock ( S , 20 ,
214 , SS_CALL_MDL_UPDATE ) ; } if ( _rtDW -> TrueRMS_MODE_e ) { { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 0
] ; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_b .
TUbufferPtrs [ 3 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] = ( ( _rtDW -> TransportDelay_IWORK_g .
Head [ 0 ] < ( _rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 0 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_g . Head [ 0 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_g . Head [ 0 ] == _rtDW -> TransportDelay_IWORK_g .
Tail [ 0 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK_g . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK_g .
Head [ 0 ] , & _rtDW -> TransportDelay_IWORK_g . Last [ 0 ] , simTime - _rtP
-> P_25 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_g . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] ] = _rtB -> B_16_1_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_g .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_g . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_g . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_g .
Tail [ 1 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_g . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_g .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_g . Last [ 1 ] , simTime - _rtP
-> P_25 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_g . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] ] = _rtB -> B_16_1_0 [ 1 ] ; _rtDW ->
TransportDelay_IWORK_g . Head [ 2 ] = ( ( _rtDW -> TransportDelay_IWORK_g .
Head [ 2 ] < ( _rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 2 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_g . Head [ 2 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_g . Head [ 2 ] == _rtDW -> TransportDelay_IWORK_g .
Tail [ 2 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 2 ] , & _rtDW ->
TransportDelay_IWORK_g . Tail [ 2 ] , & _rtDW -> TransportDelay_IWORK_g .
Head [ 2 ] , & _rtDW -> TransportDelay_IWORK_g . Last [ 2 ] , simTime - _rtP
-> P_25 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_g . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 2 ] ] = _rtB -> B_16_1_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_k [ 0 ] = _rtB -> B_16_7_0 [ 0 ] ; _rtDW ->
Memory_PreviousInput_k [ 1 ] = _rtB -> B_16_7_0 [ 1 ] ; _rtDW ->
Memory_PreviousInput_k [ 2 ] = _rtB -> B_16_7_0 [ 2 ] ; } } if ( _rtDW ->
RMS_MODE_h ) { { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_f . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_f . TUbufferPtrs [ 3 ] ; real_T simTime =
ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_j . Head [ 0 ] = ( ( _rtDW ->
TransportDelay_IWORK_j . Head [ 0 ] < ( _rtDW -> TransportDelay_IWORK_j .
CircularBufSize [ 0 ] - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_j . Head [ 0
] + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK_j . Head [ 0 ] == _rtDW ->
TransportDelay_IWORK_j . Tail [ 0 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_j . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK_j . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK_j .
Head [ 0 ] , & _rtDW -> TransportDelay_IWORK_j . Last [ 0 ] , simTime - _rtP
-> P_4 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_j . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 0 ] ] = _rtB -> B_14_0_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_j . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_j .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_j . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_j . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_j . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_j .
Tail [ 1 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_j . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_j . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_j .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_j . Last [ 1 ] , simTime - _rtP
-> P_4 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_j . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 1 ] ] = _rtB -> B_14_0_0 [ 1 ] ; _rtDW ->
TransportDelay_IWORK_j . Head [ 2 ] = ( ( _rtDW -> TransportDelay_IWORK_j .
Head [ 2 ] < ( _rtDW -> TransportDelay_IWORK_j . CircularBufSize [ 2 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_j . Head [ 2 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_j . Head [ 2 ] == _rtDW -> TransportDelay_IWORK_j .
Tail [ 2 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_j . CircularBufSize [ 2 ] , & _rtDW ->
TransportDelay_IWORK_j . Tail [ 2 ] , & _rtDW -> TransportDelay_IWORK_j .
Head [ 2 ] , & _rtDW -> TransportDelay_IWORK_j . Last [ 2 ] , simTime - _rtP
-> P_4 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_j . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_j . Head [ 2 ] ] = _rtB -> B_14_0_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_e [ 0 ] = _rtB -> B_14_7_0 [ 0 ] ; _rtDW ->
Memory_PreviousInput_e [ 1 ] = _rtB -> B_14_7_0 [ 1 ] ; _rtDW ->
Memory_PreviousInput_e [ 2 ] = _rtB -> B_14_7_0 [ 2 ] ; } { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_i . TUbufferPtrs [ 0
] ; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_i .
TUbufferPtrs [ 3 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK_d . Head [ 0 ] = ( ( _rtDW -> TransportDelay_IWORK_d .
Head [ 0 ] < ( _rtDW -> TransportDelay_IWORK_d . CircularBufSize [ 0 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_d . Head [ 0 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_d . Head [ 0 ] == _rtDW -> TransportDelay_IWORK_d .
Tail [ 0 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_d . CircularBufSize [ 0 ] , & _rtDW ->
TransportDelay_IWORK_d . Tail [ 0 ] , & _rtDW -> TransportDelay_IWORK_d .
Head [ 0 ] , & _rtDW -> TransportDelay_IWORK_d . Last [ 0 ] , simTime - _rtP
-> P_9 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_d . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_d . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_d . Head [ 0 ] ] = _rtB -> B_14_8_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_d . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_d .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_d . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_d . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_d . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_d .
Tail [ 1 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_d . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_d . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_d .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_d . Last [ 1 ] , simTime - _rtP
-> P_9 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_d . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_d . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_d . Head [ 1 ] ] = _rtB -> B_14_8_0 [ 1 ] ; _rtDW ->
TransportDelay_IWORK_d . Head [ 2 ] = ( ( _rtDW -> TransportDelay_IWORK_d .
Head [ 2 ] < ( _rtDW -> TransportDelay_IWORK_d . CircularBufSize [ 2 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_d . Head [ 2 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_d . Head [ 2 ] == _rtDW -> TransportDelay_IWORK_d .
Tail [ 2 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_d . CircularBufSize [ 2 ] , & _rtDW ->
TransportDelay_IWORK_d . Tail [ 2 ] , & _rtDW -> TransportDelay_IWORK_d .
Head [ 2 ] , & _rtDW -> TransportDelay_IWORK_d . Last [ 2 ] , simTime - _rtP
-> P_9 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_d . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_d . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_d . Head [ 2 ] ] = _rtB -> B_14_8_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_m [ 0 ] = _rtB -> B_14_15_0 [ 0 ] ; _rtDW ->
Memory_PreviousInput_m [ 1 ] = _rtB -> B_14_15_0 [ 1 ] ; _rtDW ->
Memory_PreviousInput_m [ 2 ] = _rtB -> B_14_15_0 [ 2 ] ; } } if ( _rtDW ->
TrueRMS_MODE ) { { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * *
) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK . Head = ( ( _rtDW ->
TransportDelay_IWORK . Head < ( _rtDW -> TransportDelay_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay_IWORK . Head == _rtDW -> TransportDelay_IWORK
. Tail ) { if ( ! InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf
( & _rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Tail , & _rtDW -> TransportDelay_IWORK . Head , &
_rtDW -> TransportDelay_IWORK . Last , simTime - _rtP -> P_45 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head ] = _rtB -> B_19_1_0 ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput = _rtB ->
B_19_7_0 ; } } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID4 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_InverterModulesInParallel_T
* _rtB ; XDot_InverterModulesInParallel_T * _rtXdot ;
DW_InverterModulesInParallel_T * _rtDW ; _rtDW = ( (
DW_InverterModulesInParallel_T * ) ssGetRootDWork ( S ) ) ; _rtXdot = ( (
XDot_InverterModulesInParallel_T * ) ssGetdX ( S ) ) ; _rtB = ( (
B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ; if ( _rtDW ->
TrueRMS_MODE_e ) { _rtXdot -> integrator_CSTATE_c [ 0 ] = _rtB -> B_16_8_0 [
0 ] ; _rtXdot -> integrator_CSTATE_c [ 1 ] = _rtB -> B_16_8_0 [ 1 ] ; _rtXdot
-> integrator_CSTATE_c [ 2 ] = _rtB -> B_16_8_0 [ 2 ] ; } else { { real_T *
dx ; int_T i ; dx = & ( ( ( XDot_InverterModulesInParallel_T * ) ssGetdX ( S
) ) -> integrator_CSTATE_c [ 0 ] ) ; for ( i = 0 ; i < 3 ; i ++ ) { dx [ i ]
= 0.0 ; } } } if ( _rtDW -> RMS_MODE_h ) { _rtXdot -> integrator_CSTATE_o [ 0
] = _rtB -> B_14_19_0 [ 0 ] ; _rtXdot -> integrator_CSTATE_a [ 0 ] = _rtB ->
B_14_21_0 [ 0 ] ; _rtXdot -> integrator_CSTATE_o [ 1 ] = _rtB -> B_14_19_0 [
1 ] ; _rtXdot -> integrator_CSTATE_a [ 1 ] = _rtB -> B_14_21_0 [ 1 ] ;
_rtXdot -> integrator_CSTATE_o [ 2 ] = _rtB -> B_14_19_0 [ 2 ] ; _rtXdot ->
integrator_CSTATE_a [ 2 ] = _rtB -> B_14_21_0 [ 2 ] ; } else { { real_T * dx
; int_T i ; dx = & ( ( ( XDot_InverterModulesInParallel_T * ) ssGetdX ( S ) )
-> integrator_CSTATE_o [ 0 ] ) ; for ( i = 0 ; i < 6 ; i ++ ) { dx [ i ] =
0.0 ; } } } if ( _rtDW -> RMS_MODE ) { _rtXdot -> integrator_CSTATE_e = _rtB
-> B_17_5_0 ; _rtXdot -> integrator_CSTATE_i = _rtB -> B_17_3_0 ; } else { {
real_T * dx ; int_T i ; dx = & ( ( ( XDot_InverterModulesInParallel_T * )
ssGetdX ( S ) ) -> integrator_CSTATE_e ) ; for ( i = 0 ; i < 2 ; i ++ ) { dx
[ i ] = 0.0 ; } } } if ( _rtDW -> TrueRMS_MODE ) { _rtXdot ->
integrator_CSTATE = _rtB -> B_19_8_0 ; } else { ( (
XDot_InverterModulesInParallel_T * ) ssGetdX ( S ) ) -> integrator_CSTATE =
0.0 ; } }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) {
B_InverterModulesInParallel_T * _rtB ; P_InverterModulesInParallel_T * _rtP ;
ZCV_InverterModulesInParallel_T * _rtZCSV ; DW_InverterModulesInParallel_T *
_rtDW ; _rtDW = ( ( DW_InverterModulesInParallel_T * ) ssGetRootDWork ( S ) )
; _rtZCSV = ( ( ZCV_InverterModulesInParallel_T * ) ssGetSolverZcSignalVector
( S ) ) ; _rtP = ( ( P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) )
; _rtB = ( ( B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ;
_rtZCSV -> Compare_RelopInput_ZC = _rtB -> B_20_14_0 -
InverterModulesInParallel_rtC ( S ) -> B_20_15_0 ; _rtZCSV ->
Compare_RelopInput_ZC_e = _rtB -> B_20_14_0 - InverterModulesInParallel_rtC (
S ) -> B_20_31_0 ; _rtZCSV -> Compare_RelopInput_ZC_d = _rtB -> B_20_57_0 -
InverterModulesInParallel_rtC ( S ) -> B_20_58_0 ; _rtZCSV ->
Compare_RelopInput_ZC_a = _rtB -> B_20_57_0 - InverterModulesInParallel_rtC (
S ) -> B_20_74_0 ; _rtZCSV -> Compare_RelopInput_ZC_p = _rtB -> B_20_90_0 -
InverterModulesInParallel_rtC ( S ) -> B_20_91_0 ; _rtZCSV ->
Compare_RelopInput_ZC_av = _rtB -> B_20_90_0 - InverterModulesInParallel_rtC
( S ) -> B_20_106_0 ; _rtZCSV -> Compare_RelopInput_ZC_n = _rtB -> B_20_122_0
- InverterModulesInParallel_rtC ( S ) -> B_20_123_0 ; _rtZCSV ->
Compare_RelopInput_ZC_j = _rtB -> B_20_122_0 - InverterModulesInParallel_rtC
( S ) -> B_20_138_0 ; _rtZCSV -> Compare_RelopInput_ZC_o = _rtB -> B_20_154_0
- InverterModulesInParallel_rtC ( S ) -> B_20_155_0 ; _rtZCSV ->
Compare_RelopInput_ZC_i = _rtB -> B_20_154_0 - InverterModulesInParallel_rtC
( S ) -> B_20_170_0 ; _rtZCSV -> Compare_RelopInput_ZC_f = _rtB -> B_20_186_0
- InverterModulesInParallel_rtC ( S ) -> B_20_187_0 ; _rtZCSV ->
Compare_RelopInput_ZC_pd = _rtB -> B_20_186_0 - InverterModulesInParallel_rtC
( S ) -> B_20_202_0 ; if ( _rtDW -> TrueRMS_MODE_e ) { _rtZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 0 ] = _rtB -> B_16_7_0 [ 0 ] -
_rtP -> P_29 ; _rtZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC_d [ 0 ] =
_rtB -> B_16_7_0 [ 0 ] - _rtP -> P_30 ; _rtZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 1 ] = _rtB -> B_16_7_0 [ 1 ] -
_rtP -> P_29 ; _rtZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC_d [ 1 ] =
_rtB -> B_16_7_0 [ 1 ] - _rtP -> P_30 ; _rtZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 2 ] = _rtB -> B_16_7_0 [ 2 ] -
_rtP -> P_29 ; _rtZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC_d [ 2 ] =
_rtB -> B_16_7_0 [ 2 ] - _rtP -> P_30 ; } else { { real_T * zcsv = & ( ( (
ZCV_InverterModulesInParallel_T * ) ssGetSolverZcSignalVector ( S ) ) ->
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 0 ] ) ; int_T i ; for ( i = 0 ; i
< 6 ; i ++ ) { zcsv [ i ] = 0.0 ; } } } if ( _rtDW -> TrueRMS_MODE ) {
_rtZCSV -> Saturationtoavoidnegativesqrt_UprLim_ZC = _rtB -> B_19_7_0 - _rtP
-> P_49 ; _rtZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC = _rtB ->
B_19_7_0 - _rtP -> P_50 ; } else { { real_T * zcsv = & ( ( (
ZCV_InverterModulesInParallel_T * ) ssGetSolverZcSignalVector ( S ) ) ->
Saturationtoavoidnegativesqrt_UprLim_ZC ) ; int_T i ; for ( i = 0 ; i < 2 ; i
++ ) { zcsv [ i ] = 0.0 ; } } } } static void mdlInitializeSizes ( SimStruct
* S ) { ssSetChecksumVal ( S , 0 , 334351492U ) ; ssSetChecksumVal ( S , 1 ,
545527817U ) ; ssSetChecksumVal ( S , 2 , 1301060072U ) ; ssSetChecksumVal (
S , 3 , 2968489587U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "9.1" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_InverterModulesInParallel_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_InverterModulesInParallel_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_InverterModulesInParallel_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & InverterModulesInParallel_rtDefaultP ) ; _ssSetConstBlockIO ( S , &
InverterModulesInParallel_rtInvariant ) ; rt_InitInfAndNaN ( sizeof ( real_T
) ) ; ( ( P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) -> P_29 =
rtInf ; ( ( P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) -> P_49 =
rtInf ; } static void mdlInitializeSampleTimes ( SimStruct * S ) {
slAccRegPrmChangeFcn ( S , mdlOutputsTID4 ) ; } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
