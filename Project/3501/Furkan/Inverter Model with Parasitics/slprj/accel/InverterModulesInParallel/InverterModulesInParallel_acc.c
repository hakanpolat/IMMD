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
SimStruct * S , int_T tid ) { real_T rtb_B_18_206_0 ; real_T rtb_B_18_191_0 ;
real_T rtb_B_18_174_0 ; real_T rtb_B_18_159_0 ; real_T rtb_B_18_142_0 ;
real_T rtb_B_18_127_0 ; real_T rtb_B_18_110_0 ; real_T rtb_B_18_95_0 ; real_T
rtb_B_18_78_0 ; real_T rtb_B_18_63_0 ; real_T rtb_B_18_35_0 ; real_T
rtb_B_18_20_0 ; real_T rtb_B_18_7_0 ; boolean_T rtb_B_18_207_0 ; boolean_T
rtb_B_18_192_0 ; boolean_T rtb_B_18_175_0 ; boolean_T rtb_B_18_160_0 ;
boolean_T rtb_B_18_143_0 ; boolean_T rtb_B_18_128_0 ; boolean_T
rtb_B_18_111_0 ; boolean_T rtb_B_18_96_0 ; boolean_T rtb_B_18_79_0 ;
boolean_T rtb_B_18_64_0 ; boolean_T rtb_B_18_36_0 ; boolean_T rtb_B_18_21_0 ;
real_T rtb_B_18_200_0 ; real_T rtb_B_18_183_0 ; real_T rtb_B_18_168_0 ;
real_T rtb_B_18_151_0 ; real_T rtb_B_18_136_0 ; real_T rtb_B_18_119_0 ;
real_T rtb_B_18_104_0 ; real_T rtb_B_18_87_0 ; real_T rtb_B_18_72_0 ; real_T
rtb_B_18_44_0 ; real_T rtb_B_18_29_0 ; real_T rtb_B_18_1_0 ; int32_T isHit ;
B_InverterModulesInParallel_T * _rtB ; P_InverterModulesInParallel_T * _rtP ;
X_InverterModulesInParallel_T * _rtX ; DW_InverterModulesInParallel_T * _rtDW
; _rtDW = ( ( DW_InverterModulesInParallel_T * ) ssGetRootDWork ( S ) ) ;
_rtX = ( ( X_InverterModulesInParallel_T * ) ssGetContStates ( S ) ) ; _rtP =
( ( P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_1_0 = _rtP -> P_41
; _rtB -> B_18_2_0 = _rtB -> B_18_0_0 * _rtP -> P_41 ; } _rtB -> B_18_4_0 =
muDoubleScalarSin ( _rtP -> P_45 * ssGetTaskTime ( S , 0 ) + _rtP -> P_46 ) *
_rtP -> P_43 + _rtP -> P_44 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_18_6_0 = _rtP -> P_47 ; } rtb_B_18_7_0 = ssGetT ( S
) + _rtB -> B_18_6_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_18_8_0 = _rtP -> P_48 ; } rtb_B_18_7_0 = look1_pbinlxpw ( _rtP
-> P_49 * muDoubleScalarRem ( rtb_B_18_7_0 , _rtB -> B_18_8_0 ) , _rtP ->
P_51 , _rtP -> P_50 , & _rtDW -> m_bpIndex , 2U ) ; isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_18_12_0 = _rtP -> P_52 ; } _rtB ->
B_18_13_0 = rtb_B_18_7_0 - _rtB -> B_18_12_0 ; _rtB -> B_18_14_0 = _rtB ->
B_18_4_0 - _rtB -> B_18_13_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode =
( _rtB -> B_18_14_0 > InverterModulesInParallel_rtC ( S ) -> B_18_15_0 ) ; }
if ( _rtDW -> Compare_Mode ) { _rtB -> B_18_18_0 = _rtB -> B_18_3_0 ; } else
{ _rtB -> B_18_18_0 = _rtB -> B_18_17_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_18_19_0 = _rtDW -> DelayInput2_DSTATE ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_20_0 =
_rtB -> B_18_18_0 - _rtB -> B_18_19_0 ; rtb_B_18_21_0 = ( rtb_B_18_20_0 >
_rtB -> B_18_2_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_18_23_0 = _rtB -> B_18_22_0 * rtb_B_18_1_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_21_0 ) {
rtb_B_18_20_0 = _rtB -> B_18_2_0 ; } else { if ( rtb_B_18_20_0 < _rtB ->
B_18_23_0 ) { rtb_B_18_20_0 = _rtB -> B_18_23_0 ; } } _rtB -> B_18_26_0 =
rtb_B_18_20_0 + _rtB -> B_18_19_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_27_0 [ 0 ] = _rtB -> B_18_26_0 ; _rtB ->
B_18_27_0 [ 1 ] = 0.0 ; _rtB -> B_18_27_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_1_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_27_0 [ 0 ] == _rtDW ->
INPUT_1_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_1_1_1_discrete [ 1 ] = _rtB ->
B_18_27_0 [ 0 ] ; _rtB -> B_18_27_0 [ 0 ] = _rtDW -> INPUT_1_1_1_discrete [ 1
] ; _rtB -> B_18_27_0 [ 3 ] = _rtDW -> INPUT_1_1_1_discrete [ 0 ] ;
rtb_B_18_29_0 = _rtP -> P_58 ; _rtB -> B_18_30_0 = _rtB -> B_18_28_0 * _rtP
-> P_58 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_g = ( _rtB ->
B_18_14_0 < InverterModulesInParallel_rtC ( S ) -> B_18_31_0 ) ; } if ( _rtDW
-> Compare_Mode_g ) { _rtB -> B_18_33_0 = _rtB -> B_18_3_0 ; } else { _rtB ->
B_18_33_0 = _rtB -> B_18_17_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_18_34_0 = _rtDW -> DelayInput2_DSTATE_c ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_35_0 = _rtB ->
B_18_33_0 - _rtB -> B_18_34_0 ; rtb_B_18_36_0 = ( rtb_B_18_35_0 > _rtB ->
B_18_30_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_18_38_0 = _rtB -> B_18_37_0 * rtb_B_18_29_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_36_0 ) {
rtb_B_18_35_0 = _rtB -> B_18_30_0 ; } else { if ( rtb_B_18_35_0 < _rtB ->
B_18_38_0 ) { rtb_B_18_35_0 = _rtB -> B_18_38_0 ; } } _rtB -> B_18_41_0 =
rtb_B_18_35_0 + _rtB -> B_18_34_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_42_0 [ 0 ] = _rtB -> B_18_41_0 ; _rtB ->
B_18_42_0 [ 1 ] = 0.0 ; _rtB -> B_18_42_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_2_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_42_0 [ 0 ] == _rtDW ->
INPUT_2_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_2_1_1_discrete [ 1 ] = _rtB ->
B_18_42_0 [ 0 ] ; _rtB -> B_18_42_0 [ 0 ] = _rtDW -> INPUT_2_1_1_discrete [ 1
] ; _rtB -> B_18_42_0 [ 3 ] = _rtDW -> INPUT_2_1_1_discrete [ 0 ] ;
rtb_B_18_44_0 = _rtP -> P_63 ; _rtB -> B_18_45_0 = _rtB -> B_18_43_0 * _rtP
-> P_63 ; } _rtB -> B_18_47_0 = muDoubleScalarSin ( _rtP -> P_67 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_68 ) * _rtP -> P_65 + _rtP -> P_66 ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_18_49_0 =
_rtP -> P_69 ; } rtb_B_18_29_0 = ssGetT ( S ) + _rtB -> B_18_49_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_18_51_0 = _rtP ->
P_70 ; } rtb_B_18_29_0 = look1_pbinlxpw ( _rtP -> P_71 * muDoubleScalarRem (
rtb_B_18_29_0 , _rtB -> B_18_51_0 ) , _rtP -> P_73 , _rtP -> P_72 , & _rtDW
-> m_bpIndex_a , 2U ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_18_55_0 = _rtP -> P_74 ; } _rtB -> B_18_56_0 = rtb_B_18_29_0 -
_rtB -> B_18_55_0 ; _rtB -> B_18_57_0 = _rtB -> B_18_47_0 - _rtB -> B_18_56_0
; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_h = ( _rtB ->
B_18_57_0 > InverterModulesInParallel_rtC ( S ) -> B_18_58_0 ) ; } if ( _rtDW
-> Compare_Mode_h ) { _rtB -> B_18_61_0 = _rtB -> B_18_46_0 ; } else { _rtB
-> B_18_61_0 = _rtB -> B_18_60_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_62_0 = _rtDW -> DelayInput2_DSTATE_o ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_63_0 =
_rtB -> B_18_61_0 - _rtB -> B_18_62_0 ; rtb_B_18_64_0 = ( rtb_B_18_63_0 >
_rtB -> B_18_45_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_18_66_0 = _rtB -> B_18_65_0 * rtb_B_18_44_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_64_0 ) {
rtb_B_18_63_0 = _rtB -> B_18_45_0 ; } else { if ( rtb_B_18_63_0 < _rtB ->
B_18_66_0 ) { rtb_B_18_63_0 = _rtB -> B_18_66_0 ; } } _rtB -> B_18_69_0 =
rtb_B_18_63_0 + _rtB -> B_18_62_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_70_0 [ 0 ] = _rtB -> B_18_69_0 ; _rtB ->
B_18_70_0 [ 1 ] = 0.0 ; _rtB -> B_18_70_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_11_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_70_0 [ 0 ] == _rtDW ->
INPUT_11_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_11_1_1_discrete [ 1 ] = _rtB
-> B_18_70_0 [ 0 ] ; _rtB -> B_18_70_0 [ 0 ] = _rtDW -> INPUT_11_1_1_discrete
[ 1 ] ; _rtB -> B_18_70_0 [ 3 ] = _rtDW -> INPUT_11_1_1_discrete [ 0 ] ;
rtb_B_18_72_0 = _rtP -> P_80 ; _rtB -> B_18_73_0 = _rtB -> B_18_71_0 * _rtP
-> P_80 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_i = ( _rtB ->
B_18_57_0 < InverterModulesInParallel_rtC ( S ) -> B_18_74_0 ) ; } if ( _rtDW
-> Compare_Mode_i ) { _rtB -> B_18_76_0 = _rtB -> B_18_46_0 ; } else { _rtB
-> B_18_76_0 = _rtB -> B_18_60_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_77_0 = _rtDW -> DelayInput2_DSTATE_k ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_78_0 =
_rtB -> B_18_76_0 - _rtB -> B_18_77_0 ; rtb_B_18_79_0 = ( rtb_B_18_78_0 >
_rtB -> B_18_73_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0
) { _rtB -> B_18_81_0 = _rtB -> B_18_80_0 * rtb_B_18_72_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_79_0 ) {
rtb_B_18_78_0 = _rtB -> B_18_73_0 ; } else { if ( rtb_B_18_78_0 < _rtB ->
B_18_81_0 ) { rtb_B_18_78_0 = _rtB -> B_18_81_0 ; } } _rtB -> B_18_84_0 =
rtb_B_18_78_0 + _rtB -> B_18_77_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_85_0 [ 0 ] = _rtB -> B_18_84_0 ; _rtB ->
B_18_85_0 [ 1 ] = 0.0 ; _rtB -> B_18_85_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_12_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_85_0 [ 0 ] == _rtDW ->
INPUT_12_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_12_1_1_discrete [ 1 ] = _rtB
-> B_18_85_0 [ 0 ] ; _rtB -> B_18_85_0 [ 0 ] = _rtDW -> INPUT_12_1_1_discrete
[ 1 ] ; _rtB -> B_18_85_0 [ 3 ] = _rtDW -> INPUT_12_1_1_discrete [ 0 ] ;
rtb_B_18_87_0 = _rtP -> P_85 ; _rtB -> B_18_88_0 = _rtB -> B_18_86_0 * _rtP
-> P_85 ; } _rtB -> B_18_89_0 = muDoubleScalarSin ( _rtP -> P_88 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_89 ) * _rtP -> P_86 + _rtP -> P_87 ; _rtB
-> B_18_90_0 = _rtB -> B_18_89_0 - _rtB -> B_18_13_0 ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) {
_rtDW -> Compare_Mode_p = ( _rtB -> B_18_90_0 > InverterModulesInParallel_rtC
( S ) -> B_18_91_0 ) ; } if ( _rtDW -> Compare_Mode_p ) { _rtB -> B_18_93_0 =
_rtB -> B_18_3_0 ; } else { _rtB -> B_18_93_0 = _rtB -> B_18_17_0 ; } } isHit
= ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_18_94_0 = _rtDW
-> DelayInput2_DSTATE_d ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit
!= 0 ) { rtb_B_18_95_0 = _rtB -> B_18_93_0 - _rtB -> B_18_94_0 ;
rtb_B_18_96_0 = ( rtb_B_18_95_0 > _rtB -> B_18_88_0 ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_18_98_0 = _rtB ->
B_18_97_0 * rtb_B_18_87_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_18_96_0 ) { rtb_B_18_95_0 = _rtB -> B_18_88_0 ; }
else { if ( rtb_B_18_95_0 < _rtB -> B_18_98_0 ) { rtb_B_18_95_0 = _rtB ->
B_18_98_0 ; } } _rtB -> B_18_101_0 = rtb_B_18_95_0 + _rtB -> B_18_94_0 ; }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_18_102_0
[ 0 ] = _rtB -> B_18_101_0 ; _rtB -> B_18_102_0 [ 1 ] = 0.0 ; _rtB ->
B_18_102_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_3_1_1_discrete [ 0 ] = ! ( _rtB ->
B_18_102_0 [ 0 ] == _rtDW -> INPUT_3_1_1_discrete [ 1 ] ) ; _rtDW ->
INPUT_3_1_1_discrete [ 1 ] = _rtB -> B_18_102_0 [ 0 ] ; _rtB -> B_18_102_0 [
0 ] = _rtDW -> INPUT_3_1_1_discrete [ 1 ] ; _rtB -> B_18_102_0 [ 3 ] = _rtDW
-> INPUT_3_1_1_discrete [ 0 ] ; rtb_B_18_104_0 = _rtP -> P_94 ; _rtB ->
B_18_105_0 = _rtB -> B_18_103_0 * _rtP -> P_94 ; } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW
-> Compare_Mode_j = ( _rtB -> B_18_90_0 < InverterModulesInParallel_rtC ( S )
-> B_18_106_0 ) ; } if ( _rtDW -> Compare_Mode_j ) { _rtB -> B_18_108_0 =
_rtB -> B_18_3_0 ; } else { _rtB -> B_18_108_0 = _rtB -> B_18_17_0 ; } }
isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_18_109_0
= _rtDW -> DelayInput2_DSTATE_f ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { rtb_B_18_110_0 = _rtB -> B_18_108_0 - _rtB -> B_18_109_0 ;
rtb_B_18_111_0 = ( rtb_B_18_110_0 > _rtB -> B_18_105_0 ) ; } isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_18_113_0 = _rtB
-> B_18_112_0 * rtb_B_18_104_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( rtb_B_18_111_0 ) { rtb_B_18_110_0 = _rtB -> B_18_105_0 ;
} else { if ( rtb_B_18_110_0 < _rtB -> B_18_113_0 ) { rtb_B_18_110_0 = _rtB
-> B_18_113_0 ; } } _rtB -> B_18_116_0 = rtb_B_18_110_0 + _rtB -> B_18_109_0
; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_18_117_0 [ 0 ] = _rtB -> B_18_116_0 ; _rtB -> B_18_117_0 [ 1 ] = 0.0 ; _rtB
-> B_18_117_0 [ 2 ] = 0.0 ; _rtDW -> INPUT_4_1_1_discrete [ 0 ] = ! ( _rtB ->
B_18_117_0 [ 0 ] == _rtDW -> INPUT_4_1_1_discrete [ 1 ] ) ; _rtDW ->
INPUT_4_1_1_discrete [ 1 ] = _rtB -> B_18_117_0 [ 0 ] ; _rtB -> B_18_117_0 [
0 ] = _rtDW -> INPUT_4_1_1_discrete [ 1 ] ; _rtB -> B_18_117_0 [ 3 ] = _rtDW
-> INPUT_4_1_1_discrete [ 0 ] ; rtb_B_18_119_0 = _rtP -> P_99 ; _rtB ->
B_18_120_0 = _rtB -> B_18_118_0 * _rtP -> P_99 ; } _rtB -> B_18_121_0 =
muDoubleScalarSin ( _rtP -> P_102 * ssGetTaskTime ( S , 0 ) + _rtP -> P_103 )
* _rtP -> P_100 + _rtP -> P_101 ; _rtB -> B_18_122_0 = _rtB -> B_18_121_0 -
_rtB -> B_18_13_0 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_hp = ( _rtB ->
B_18_122_0 > InverterModulesInParallel_rtC ( S ) -> B_18_123_0 ) ; } if (
_rtDW -> Compare_Mode_hp ) { _rtB -> B_18_125_0 = _rtB -> B_18_3_0 ; } else {
_rtB -> B_18_125_0 = _rtB -> B_18_17_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_18_126_0 = _rtDW -> DelayInput2_DSTATE_n
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_127_0
= _rtB -> B_18_125_0 - _rtB -> B_18_126_0 ; rtb_B_18_128_0 = ( rtb_B_18_127_0
> _rtB -> B_18_120_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_18_130_0 = _rtB -> B_18_129_0 * rtb_B_18_119_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_128_0 ) {
rtb_B_18_127_0 = _rtB -> B_18_120_0 ; } else { if ( rtb_B_18_127_0 < _rtB ->
B_18_130_0 ) { rtb_B_18_127_0 = _rtB -> B_18_130_0 ; } } _rtB -> B_18_133_0 =
rtb_B_18_127_0 + _rtB -> B_18_126_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_134_0 [ 0 ] = _rtB -> B_18_133_0 ; _rtB ->
B_18_134_0 [ 1 ] = 0.0 ; _rtB -> B_18_134_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_5_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_134_0 [ 0 ] == _rtDW ->
INPUT_5_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_5_1_1_discrete [ 1 ] = _rtB ->
B_18_134_0 [ 0 ] ; _rtB -> B_18_134_0 [ 0 ] = _rtDW -> INPUT_5_1_1_discrete [
1 ] ; _rtB -> B_18_134_0 [ 3 ] = _rtDW -> INPUT_5_1_1_discrete [ 0 ] ;
rtb_B_18_136_0 = _rtP -> P_108 ; _rtB -> B_18_137_0 = _rtB -> B_18_135_0 *
_rtP -> P_108 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_iz = ( _rtB ->
B_18_122_0 < InverterModulesInParallel_rtC ( S ) -> B_18_138_0 ) ; } if (
_rtDW -> Compare_Mode_iz ) { _rtB -> B_18_140_0 = _rtB -> B_18_3_0 ; } else {
_rtB -> B_18_140_0 = _rtB -> B_18_17_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_18_141_0 = _rtDW -> DelayInput2_DSTATE_m
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_142_0
= _rtB -> B_18_140_0 - _rtB -> B_18_141_0 ; rtb_B_18_143_0 = ( rtb_B_18_142_0
> _rtB -> B_18_137_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_18_145_0 = _rtB -> B_18_144_0 * rtb_B_18_136_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_143_0 ) {
rtb_B_18_142_0 = _rtB -> B_18_137_0 ; } else { if ( rtb_B_18_142_0 < _rtB ->
B_18_145_0 ) { rtb_B_18_142_0 = _rtB -> B_18_145_0 ; } } _rtB -> B_18_148_0 =
rtb_B_18_142_0 + _rtB -> B_18_141_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_149_0 [ 0 ] = _rtB -> B_18_148_0 ; _rtB ->
B_18_149_0 [ 1 ] = 0.0 ; _rtB -> B_18_149_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_6_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_149_0 [ 0 ] == _rtDW ->
INPUT_6_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_6_1_1_discrete [ 1 ] = _rtB ->
B_18_149_0 [ 0 ] ; _rtB -> B_18_149_0 [ 0 ] = _rtDW -> INPUT_6_1_1_discrete [
1 ] ; _rtB -> B_18_149_0 [ 3 ] = _rtDW -> INPUT_6_1_1_discrete [ 0 ] ;
rtb_B_18_151_0 = _rtP -> P_113 ; _rtB -> B_18_152_0 = _rtB -> B_18_150_0 *
_rtP -> P_113 ; } _rtB -> B_18_153_0 = muDoubleScalarSin ( _rtP -> P_116 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_117 ) * _rtP -> P_114 + _rtP -> P_115 ;
_rtB -> B_18_154_0 = _rtB -> B_18_153_0 - _rtB -> B_18_56_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> Compare_Mode_ja = ( _rtB -> B_18_154_0 >
InverterModulesInParallel_rtC ( S ) -> B_18_155_0 ) ; } if ( _rtDW ->
Compare_Mode_ja ) { _rtB -> B_18_157_0 = _rtB -> B_18_46_0 ; } else { _rtB ->
B_18_157_0 = _rtB -> B_18_60_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_18_158_0 = _rtDW -> DelayInput2_DSTATE_dc ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_159_0 =
_rtB -> B_18_157_0 - _rtB -> B_18_158_0 ; rtb_B_18_160_0 = ( rtb_B_18_159_0 >
_rtB -> B_18_152_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_18_162_0 = _rtB -> B_18_161_0 * rtb_B_18_151_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_160_0 ) {
rtb_B_18_159_0 = _rtB -> B_18_152_0 ; } else { if ( rtb_B_18_159_0 < _rtB ->
B_18_162_0 ) { rtb_B_18_159_0 = _rtB -> B_18_162_0 ; } } _rtB -> B_18_165_0 =
rtb_B_18_159_0 + _rtB -> B_18_158_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_166_0 [ 0 ] = _rtB -> B_18_165_0 ; _rtB ->
B_18_166_0 [ 1 ] = 0.0 ; _rtB -> B_18_166_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_7_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_166_0 [ 0 ] == _rtDW ->
INPUT_7_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_7_1_1_discrete [ 1 ] = _rtB ->
B_18_166_0 [ 0 ] ; _rtB -> B_18_166_0 [ 0 ] = _rtDW -> INPUT_7_1_1_discrete [
1 ] ; _rtB -> B_18_166_0 [ 3 ] = _rtDW -> INPUT_7_1_1_discrete [ 0 ] ;
rtb_B_18_168_0 = _rtP -> P_122 ; _rtB -> B_18_169_0 = _rtB -> B_18_167_0 *
_rtP -> P_122 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_c = ( _rtB ->
B_18_154_0 < InverterModulesInParallel_rtC ( S ) -> B_18_170_0 ) ; } if (
_rtDW -> Compare_Mode_c ) { _rtB -> B_18_172_0 = _rtB -> B_18_46_0 ; } else {
_rtB -> B_18_172_0 = _rtB -> B_18_60_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_18_173_0 = _rtDW -> DelayInput2_DSTATE_dj
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_174_0
= _rtB -> B_18_172_0 - _rtB -> B_18_173_0 ; rtb_B_18_175_0 = ( rtb_B_18_174_0
> _rtB -> B_18_169_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_18_177_0 = _rtB -> B_18_176_0 * rtb_B_18_168_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_175_0 ) {
rtb_B_18_174_0 = _rtB -> B_18_169_0 ; } else { if ( rtb_B_18_174_0 < _rtB ->
B_18_177_0 ) { rtb_B_18_174_0 = _rtB -> B_18_177_0 ; } } _rtB -> B_18_180_0 =
rtb_B_18_174_0 + _rtB -> B_18_173_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_181_0 [ 0 ] = _rtB -> B_18_180_0 ; _rtB ->
B_18_181_0 [ 1 ] = 0.0 ; _rtB -> B_18_181_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_8_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_181_0 [ 0 ] == _rtDW ->
INPUT_8_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_8_1_1_discrete [ 1 ] = _rtB ->
B_18_181_0 [ 0 ] ; _rtB -> B_18_181_0 [ 0 ] = _rtDW -> INPUT_8_1_1_discrete [
1 ] ; _rtB -> B_18_181_0 [ 3 ] = _rtDW -> INPUT_8_1_1_discrete [ 0 ] ;
rtb_B_18_183_0 = _rtP -> P_127 ; _rtB -> B_18_184_0 = _rtB -> B_18_182_0 *
_rtP -> P_127 ; } _rtB -> B_18_185_0 = muDoubleScalarSin ( _rtP -> P_130 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_131 ) * _rtP -> P_128 + _rtP -> P_129 ;
_rtB -> B_18_186_0 = _rtB -> B_18_185_0 - _rtB -> B_18_56_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsMajorTimeStep ( S
) != 0 ) { _rtDW -> Compare_Mode_l = ( _rtB -> B_18_186_0 >
InverterModulesInParallel_rtC ( S ) -> B_18_187_0 ) ; } if ( _rtDW ->
Compare_Mode_l ) { _rtB -> B_18_189_0 = _rtB -> B_18_46_0 ; } else { _rtB ->
B_18_189_0 = _rtB -> B_18_60_0 ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_18_190_0 = _rtDW -> DelayInput2_DSTATE_a ; } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_191_0 = _rtB ->
B_18_189_0 - _rtB -> B_18_190_0 ; rtb_B_18_192_0 = ( rtb_B_18_191_0 > _rtB ->
B_18_184_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_18_194_0 = _rtB -> B_18_193_0 * rtb_B_18_183_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_192_0 ) {
rtb_B_18_191_0 = _rtB -> B_18_184_0 ; } else { if ( rtb_B_18_191_0 < _rtB ->
B_18_194_0 ) { rtb_B_18_191_0 = _rtB -> B_18_194_0 ; } } _rtB -> B_18_197_0 =
rtb_B_18_191_0 + _rtB -> B_18_190_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_198_0 [ 0 ] = _rtB -> B_18_197_0 ; _rtB ->
B_18_198_0 [ 1 ] = 0.0 ; _rtB -> B_18_198_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_9_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_198_0 [ 0 ] == _rtDW ->
INPUT_9_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_9_1_1_discrete [ 1 ] = _rtB ->
B_18_198_0 [ 0 ] ; _rtB -> B_18_198_0 [ 0 ] = _rtDW -> INPUT_9_1_1_discrete [
1 ] ; _rtB -> B_18_198_0 [ 3 ] = _rtDW -> INPUT_9_1_1_discrete [ 0 ] ;
rtb_B_18_200_0 = _rtP -> P_136 ; _rtB -> B_18_201_0 = _rtB -> B_18_199_0 *
_rtP -> P_136 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW -> Compare_Mode_o = ( _rtB ->
B_18_186_0 < InverterModulesInParallel_rtC ( S ) -> B_18_202_0 ) ; } if (
_rtDW -> Compare_Mode_o ) { _rtB -> B_18_204_0 = _rtB -> B_18_46_0 ; } else {
_rtB -> B_18_204_0 = _rtB -> B_18_60_0 ; } } isHit = ssIsSampleHit ( S , 2 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_18_205_0 = _rtDW -> DelayInput2_DSTATE_nv
; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { rtb_B_18_206_0
= _rtB -> B_18_204_0 - _rtB -> B_18_205_0 ; rtb_B_18_207_0 = ( rtb_B_18_206_0
> _rtB -> B_18_201_0 ) ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { _rtB -> B_18_209_0 = _rtB -> B_18_208_0 * rtb_B_18_200_0 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( rtb_B_18_207_0 ) {
rtb_B_18_206_0 = _rtB -> B_18_201_0 ; } else { if ( rtb_B_18_206_0 < _rtB ->
B_18_209_0 ) { rtb_B_18_206_0 = _rtB -> B_18_209_0 ; } } _rtB -> B_18_212_0 =
rtb_B_18_206_0 + _rtB -> B_18_205_0 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_18_213_0 [ 0 ] = _rtB -> B_18_212_0 ; _rtB ->
B_18_213_0 [ 1 ] = 0.0 ; _rtB -> B_18_213_0 [ 2 ] = 0.0 ; _rtDW ->
INPUT_10_1_1_discrete [ 0 ] = ! ( _rtB -> B_18_213_0 [ 0 ] == _rtDW ->
INPUT_10_1_1_discrete [ 1 ] ) ; _rtDW -> INPUT_10_1_1_discrete [ 1 ] = _rtB
-> B_18_213_0 [ 0 ] ; _rtB -> B_18_213_0 [ 0 ] = _rtDW ->
INPUT_10_1_1_discrete [ 1 ] ; _rtB -> B_18_213_0 [ 3 ] = _rtDW ->
INPUT_10_1_1_discrete [ 0 ] ; ssCallAccelRunBlock ( S , 18 , 214 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 18 , 215 ,
SS_CALL_MDL_OUTPUTS ) ; { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule1_at_outport_5_PWORK . AQHandles ||
_rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule1_at_outport_5_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule1_at_outport_5_PWORK . AQHandles ,
_rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule1_at_outport_5_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_18_215_0 [ 30
] ) ; } } if ( _rtB -> B_18_215_0 [ 25 ] > _rtP -> P_145 ) { _rtB ->
B_18_217_0 = _rtP -> P_145 ; } else if ( _rtB -> B_18_215_0 [ 25 ] < _rtP ->
P_146 ) { _rtB -> B_18_217_0 = _rtP -> P_146 ; } else { _rtB -> B_18_217_0 =
_rtB -> B_18_215_0 [ 25 ] ; } if ( _rtB -> B_18_215_0 [ 23 ] > _rtP -> P_147
) { _rtB -> B_18_218_0 = _rtP -> P_147 ; } else if ( _rtB -> B_18_215_0 [ 23
] < _rtP -> P_148 ) { _rtB -> B_18_218_0 = _rtP -> P_148 ; } else { _rtB ->
B_18_218_0 = _rtB -> B_18_215_0 [ 23 ] ; } if ( _rtB -> B_18_215_0 [ 24 ] >
_rtP -> P_149 ) { _rtB -> B_18_219_0 = _rtP -> P_149 ; } else if ( _rtB ->
B_18_215_0 [ 24 ] < _rtP -> P_150 ) { _rtB -> B_18_219_0 = _rtP -> P_150 ; }
else { _rtB -> B_18_219_0 = _rtB -> B_18_215_0 [ 24 ] ; } { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK . AQHandles [ 0
] || _rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK . AQHandles [ 0
] , _rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_18_217_0 ) ;
sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK . AQHandles [ 1
] , _rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK .
SlioLTF , 1 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_18_218_0 ) ;
sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK . AQHandles [ 2
] , _rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_2_1_PWORK .
SlioLTF , 2 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_18_219_0 ) ; }
} { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK . AQHandles [ 0
] || _rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK . AQHandles [ 0
] , _rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_18_215_0 [ 3 ]
) ; sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK . AQHandles [ 1
] , _rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK .
SlioLTF , 1 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_18_215_0 [ 1 ]
) ; sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK . AQHandles [ 2
] , _rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_3_1_PWORK .
SlioLTF , 2 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_18_215_0 [ 2 ]
) ; } } { if ( ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_5_PWORK . AQHandles ||
_rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_5_PWORK .
SlioLTF ) && ssGetLogOutput ( S ) ) { sdiSlioSdiWriteSignal ( _rtDW ->
HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_5_PWORK . AQHandles ,
_rtDW -> HiddenToAsyncQueue_InsertedFor_3phModule_at_outport_5_PWORK .
SlioLTF , 0 , ssGetTaskTime ( S , 2 ) , ( void * ) & _rtB -> B_18_215_0 [ 4 ]
) ; } } ssCallAccelRunBlock ( S , 18 , 223 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 18 , 224 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
B_18_215_0 [ 26 ] > _rtP -> P_151 ) { _rtB -> B_18_225_0 = _rtP -> P_151 ; }
else if ( _rtB -> B_18_215_0 [ 26 ] < _rtP -> P_152 ) { _rtB -> B_18_225_0 =
_rtP -> P_152 ; } else { _rtB -> B_18_225_0 = _rtB -> B_18_215_0 [ 26 ] ; }
if ( _rtB -> B_18_215_0 [ 52 ] > _rtP -> P_153 ) { _rtB -> B_18_226_0 = _rtP
-> P_153 ; } else if ( _rtB -> B_18_215_0 [ 52 ] < _rtP -> P_154 ) { _rtB ->
B_18_226_0 = _rtP -> P_154 ; } else { _rtB -> B_18_226_0 = _rtB -> B_18_215_0
[ 52 ] ; } ssCallAccelRunBlock ( S , 18 , 227 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 18 , 228 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 18 , 295 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 18 , 485 , SS_CALL_MDL_OUTPUTS ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( _rtB -> B_18_635_0 ) { if ( ! _rtDW -> RMS_MODE_h ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( void ) memset ( & ( (
( XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_a ) , 0 , 6 * sizeof ( boolean_T ) ) ; _rtDW -> RMS_MODE_h
= true ; } } else { if ( _rtDW -> RMS_MODE_h ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & ( ( (
XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_a ) , 1 , 6 * sizeof ( boolean_T ) ) ; _rtDW -> RMS_MODE_h
= false ; } } } if ( _rtDW -> RMS_MODE_h ) { rtb_B_18_200_0 =
muDoubleScalarSin ( _rtP -> P_5 * ssGetTaskTime ( S , 0 ) + _rtP -> P_6 ) *
_rtP -> P_3 + _rtP -> P_4 ; _rtB -> B_12_3_0 [ 0 ] = _rtB -> B_18_215_0 [ 3 ]
* rtb_B_18_200_0 ; _rtB -> B_12_3_0 [ 1 ] = _rtB -> B_18_215_0 [ 1 ] *
rtb_B_18_200_0 ; _rtB -> B_12_3_0 [ 2 ] = _rtB -> B_18_215_0 [ 2 ] *
rtb_B_18_200_0 ; rtb_B_18_200_0 = muDoubleScalarSin ( _rtP -> P_9 *
ssGetTaskTime ( S , 0 ) + _rtP -> P_10 ) * _rtP -> P_7 + _rtP -> P_8 ; _rtB
-> B_12_5_0 [ 0 ] = _rtB -> B_18_215_0 [ 3 ] * rtb_B_18_200_0 ; _rtB ->
B_12_5_0 [ 1 ] = _rtB -> B_18_215_0 [ 1 ] * rtb_B_18_200_0 ; _rtB -> B_12_5_0
[ 2 ] = _rtB -> B_18_215_0 [ 2 ] * rtb_B_18_200_0 ; if ( ssIsMajorTimeStep (
S ) != 0 ) { srUpdateBC ( _rtDW -> RMS_SubsysRanBC_n ) ; } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S
) != 0 ) ) { if ( _rtB -> B_18_634_0 ) { if ( ! _rtDW -> TrueRMS_MODE_e ) {
if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( void ) memset ( & ( (
( XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_c ) , 0 , 3 * sizeof ( boolean_T ) ) ; _rtDW ->
TrueRMS_MODE_e = true ; } } else { if ( _rtDW -> TrueRMS_MODE_e ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & ( ( (
XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_c ) , 1 , 3 * sizeof ( boolean_T ) ) ; _rtDW ->
TrueRMS_MODE_e = false ; } } } if ( _rtDW -> TrueRMS_MODE_e ) { _rtB ->
B_14_1_0 [ 0 ] = _rtX -> integrator_CSTATE_c [ 0 ] ; _rtB -> B_14_1_0 [ 1 ] =
_rtX -> integrator_CSTATE_c [ 1 ] ; _rtB -> B_14_1_0 [ 2 ] = _rtX ->
integrator_CSTATE_c [ 2 ] ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_b . TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 3 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay ; { int_T i1 ; real_T * y0 = & _rtB ->
B_14_2_0 [ 0 ] ; int_T * iw_Tail = & _rtDW -> TransportDelay_IWORK_g . Tail [
0 ] ; int_T * iw_Head = & _rtDW -> TransportDelay_IWORK_g . Head [ 0 ] ;
int_T * iw_Last = & _rtDW -> TransportDelay_IWORK_g . Last [ 0 ] ; int_T *
iw_CircularBufSize = & _rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 0
] ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { tMinusDelay = ( ( _rtP -> P_14 > 0.0 )
? _rtP -> P_14 : 0.0 ) ; tMinusDelay = simTime - tMinusDelay ; y0 [ i1 ] =
InverterModulesInParallel_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail
[ i1 ] , iw_Head [ i1 ] , _rtP -> P_15 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; tBuffer ++ ; uBuffer ++ ; } } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { _rtB -> B_14_3_0 = _rtP -> P_16 ; _rtB -> B_14_4_0 [ 0 ] =
_rtDW -> Memory_PreviousInput_k [ 0 ] ; _rtB -> B_14_4_0 [ 1 ] = _rtDW ->
Memory_PreviousInput_k [ 1 ] ; _rtB -> B_14_4_0 [ 2 ] = _rtDW ->
Memory_PreviousInput_k [ 2 ] ; } if ( ssGetT ( S ) >= _rtB -> B_14_3_0 ) {
_rtB -> B_13_0_0 [ 0 ] = _rtB -> B_14_1_0 [ 0 ] - _rtB -> B_14_2_0 [ 0 ] ;
_rtB -> B_13_1_0 [ 0 ] = _rtP -> P_11 * _rtB -> B_13_0_0 [ 0 ] ; _rtB ->
B_14_7_0 [ 0 ] = _rtB -> B_13_1_0 [ 0 ] ; _rtB -> B_13_0_0 [ 1 ] = _rtB ->
B_14_1_0 [ 1 ] - _rtB -> B_14_2_0 [ 1 ] ; _rtB -> B_13_1_0 [ 1 ] = _rtP ->
P_11 * _rtB -> B_13_0_0 [ 1 ] ; _rtB -> B_14_7_0 [ 1 ] = _rtB -> B_13_1_0 [ 1
] ; _rtB -> B_13_0_0 [ 2 ] = _rtB -> B_14_1_0 [ 2 ] - _rtB -> B_14_2_0 [ 2 ]
; _rtB -> B_13_1_0 [ 2 ] = _rtP -> P_11 * _rtB -> B_13_0_0 [ 2 ] ; _rtB ->
B_14_7_0 [ 2 ] = _rtB -> B_13_1_0 [ 2 ] ; } else { _rtB -> B_14_7_0 [ 0 ] =
_rtB -> B_14_4_0 [ 0 ] ; _rtB -> B_14_7_0 [ 1 ] = _rtB -> B_14_4_0 [ 1 ] ;
_rtB -> B_14_7_0 [ 2 ] = _rtB -> B_14_4_0 [ 2 ] ; } _rtB -> B_14_8_0 [ 0 ] =
_rtB -> B_18_215_0 [ 3 ] * _rtB -> B_18_215_0 [ 3 ] ; _rtB -> B_14_8_0 [ 1 ]
= _rtB -> B_18_215_0 [ 1 ] * _rtB -> B_18_215_0 [ 1 ] ; _rtB -> B_14_8_0 [ 2
] = _rtB -> B_18_215_0 [ 2 ] * _rtB -> B_18_215_0 [ 2 ] ; if (
ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 0 ] = _rtB -> B_14_7_0 [ 0 ] >= _rtP
-> P_18 ? 1 : _rtB -> B_14_7_0 [ 0 ] > _rtP -> P_19 ? 0 : - 1 ; _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 1 ] = _rtB -> B_14_7_0 [ 1 ] >= _rtP
-> P_18 ? 1 : _rtB -> B_14_7_0 [ 1 ] > _rtP -> P_19 ? 0 : - 1 ; _rtDW ->
Saturationtoavoidnegativesqrt_MODE_c [ 2 ] = _rtB -> B_14_7_0 [ 2 ] >= _rtP
-> P_18 ? 1 : _rtB -> B_14_7_0 [ 2 ] > _rtP -> P_19 ? 0 : - 1 ; srUpdateBC (
_rtDW -> TrueRMS_SubsysRanBC_i ) ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( ( isHit != 0 ) && ( ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB ->
B_18_640_0 ) { if ( ! _rtDW -> RMS_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } (
void ) memset ( & ( ( ( XDis_InverterModulesInParallel_T * )
ssGetContStateDisabled ( S ) ) -> integrator_CSTATE_e ) , 0 , 2 * sizeof (
boolean_T ) ) ; _rtDW -> RMS_MODE = true ; } } else { if ( _rtDW -> RMS_MODE
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & (
( ( XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE_e ) , 1 , 2 * sizeof ( boolean_T ) ) ; _rtDW -> RMS_MODE =
false ; } } } if ( _rtDW -> RMS_MODE ) { _rtB -> B_15_3_0 = (
muDoubleScalarSin ( _rtP -> P_25 * ssGetTaskTime ( S , 0 ) + _rtP -> P_26 ) *
_rtP -> P_23 + _rtP -> P_24 ) * _rtB -> B_18_215_0 [ 4 ] ; _rtB -> B_15_5_0 =
( muDoubleScalarSin ( _rtP -> P_29 * ssGetTaskTime ( S , 0 ) + _rtP -> P_30 )
* _rtP -> P_27 + _rtP -> P_28 ) * _rtB -> B_18_215_0 [ 4 ] ; if (
ssIsMajorTimeStep ( S ) != 0 ) { srUpdateBC ( _rtDW -> RMS_SubsysRanBC ) ; }
} isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) && (
ssIsMajorTimeStep ( S ) != 0 ) ) { if ( _rtB -> B_18_639_0 ) { if ( ! _rtDW
-> TrueRMS_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( (
XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE = 0 ; _rtDW -> TrueRMS_MODE = true ; } } else { if ( _rtDW
-> TrueRMS_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( (
XDis_InverterModulesInParallel_T * ) ssGetContStateDisabled ( S ) ) ->
integrator_CSTATE = 1 ; _rtDW -> TrueRMS_MODE = false ; } } } if ( _rtDW ->
TrueRMS_MODE ) { _rtB -> B_17_1_0 = _rtX -> integrator_CSTATE ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_34 ; _rtB -> B_17_2_0 =
InverterModulesInParallel_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK . CircularBufSize , &
_rtDW -> TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail ,
_rtDW -> TransportDelay_IWORK . Head , _rtP -> P_35 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_17_3_0 = _rtP -> P_36 ; _rtB -> B_17_4_0 = _rtDW -> Memory_PreviousInput ;
} if ( ssGetT ( S ) >= _rtB -> B_17_3_0 ) { _rtB -> B_16_0_0 = _rtB ->
B_17_1_0 - _rtB -> B_17_2_0 ; _rtB -> B_16_1_0 = _rtP -> P_31 * _rtB ->
B_16_0_0 ; _rtB -> B_17_7_0 = _rtB -> B_16_1_0 ; } else { _rtB -> B_17_7_0 =
_rtB -> B_17_4_0 ; } _rtB -> B_17_8_0 = _rtB -> B_18_215_0 [ 4 ] * _rtB ->
B_18_215_0 [ 4 ] ; if ( ssIsMajorTimeStep ( S ) != 0 ) { _rtDW ->
Saturationtoavoidnegativesqrt_MODE = _rtB -> B_17_7_0 >= _rtP -> P_38 ? 1 :
_rtB -> B_17_7_0 > _rtP -> P_39 ? 0 : - 1 ; srUpdateBC ( _rtDW ->
TrueRMS_SubsysRanBC ) ; } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { ssCallAccelRunBlock ( S , 18 , 659 , SS_CALL_MDL_OUTPUTS ) ; }
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID4 ( SimStruct * S ,
int_T tid ) { B_InverterModulesInParallel_T * _rtB ;
P_InverterModulesInParallel_T * _rtP ; _rtP = ( (
P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB ->
B_18_0_0 = _rtP -> P_40 ; _rtB -> B_18_3_0 = _rtP -> P_42 ; _rtB -> B_18_17_0
= _rtP -> P_54 ; _rtB -> B_18_22_0 = _rtP -> P_56 ; _rtB -> B_18_28_0 = _rtP
-> P_57 ; _rtB -> B_18_37_0 = _rtP -> P_61 ; _rtB -> B_18_43_0 = _rtP -> P_62
; _rtB -> B_18_46_0 = _rtP -> P_64 ; _rtB -> B_18_60_0 = _rtP -> P_76 ; _rtB
-> B_18_65_0 = _rtP -> P_78 ; _rtB -> B_18_71_0 = _rtP -> P_79 ; _rtB ->
B_18_80_0 = _rtP -> P_83 ; _rtB -> B_18_86_0 = _rtP -> P_84 ; _rtB ->
B_18_97_0 = _rtP -> P_92 ; _rtB -> B_18_103_0 = _rtP -> P_93 ; _rtB ->
B_18_112_0 = _rtP -> P_97 ; _rtB -> B_18_118_0 = _rtP -> P_98 ; _rtB ->
B_18_129_0 = _rtP -> P_106 ; _rtB -> B_18_135_0 = _rtP -> P_107 ; _rtB ->
B_18_144_0 = _rtP -> P_111 ; _rtB -> B_18_150_0 = _rtP -> P_112 ; _rtB ->
B_18_161_0 = _rtP -> P_120 ; _rtB -> B_18_167_0 = _rtP -> P_121 ; _rtB ->
B_18_176_0 = _rtP -> P_125 ; _rtB -> B_18_182_0 = _rtP -> P_126 ; _rtB ->
B_18_193_0 = _rtP -> P_134 ; _rtB -> B_18_199_0 = _rtP -> P_135 ; _rtB ->
B_18_208_0 = _rtP -> P_139 ; _rtB -> B_18_634_0 = ( _rtP -> P_155 != 0.0 ) ;
_rtB -> B_18_635_0 = ! _rtB -> B_18_634_0 ; _rtB -> B_18_639_0 = ( _rtP ->
P_156 != 0.0 ) ; _rtB -> B_18_640_0 = ! _rtB -> B_18_639_0 ; UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { int32_T isHit ;
B_InverterModulesInParallel_T * _rtB ; P_InverterModulesInParallel_T * _rtP ;
DW_InverterModulesInParallel_T * _rtDW ; _rtDW = ( (
DW_InverterModulesInParallel_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtDW -> DelayInput2_DSTATE
= _rtB -> B_18_26_0 ; _rtDW -> DelayInput2_DSTATE_c = _rtB -> B_18_41_0 ;
_rtDW -> DelayInput2_DSTATE_o = _rtB -> B_18_69_0 ; _rtDW ->
DelayInput2_DSTATE_k = _rtB -> B_18_84_0 ; _rtDW -> DelayInput2_DSTATE_d =
_rtB -> B_18_101_0 ; _rtDW -> DelayInput2_DSTATE_f = _rtB -> B_18_116_0 ;
_rtDW -> DelayInput2_DSTATE_n = _rtB -> B_18_133_0 ; _rtDW ->
DelayInput2_DSTATE_m = _rtB -> B_18_148_0 ; _rtDW -> DelayInput2_DSTATE_dc =
_rtB -> B_18_165_0 ; _rtDW -> DelayInput2_DSTATE_dj = _rtB -> B_18_180_0 ;
_rtDW -> DelayInput2_DSTATE_a = _rtB -> B_18_197_0 ; _rtDW ->
DelayInput2_DSTATE_nv = _rtB -> B_18_212_0 ; ssCallAccelRunBlock ( S , 18 ,
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
-> P_14 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_g . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 0 ] ] = _rtB -> B_14_1_0 [ 0 ] ; _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] = ( ( _rtDW -> TransportDelay_IWORK_g .
Head [ 1 ] < ( _rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 1 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_g . Head [ 1 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_g . Head [ 1 ] == _rtDW -> TransportDelay_IWORK_g .
Tail [ 1 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 1 ] , & _rtDW ->
TransportDelay_IWORK_g . Tail [ 1 ] , & _rtDW -> TransportDelay_IWORK_g .
Head [ 1 ] , & _rtDW -> TransportDelay_IWORK_g . Last [ 1 ] , simTime - _rtP
-> P_14 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_g . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] ] = simTime ; ( * uBuffer ++ ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 1 ] ] = _rtB -> B_14_1_0 [ 1 ] ; _rtDW ->
TransportDelay_IWORK_g . Head [ 2 ] = ( ( _rtDW -> TransportDelay_IWORK_g .
Head [ 2 ] < ( _rtDW -> TransportDelay_IWORK_g . CircularBufSize [ 2 ] - 1 )
) ? ( _rtDW -> TransportDelay_IWORK_g . Head [ 2 ] + 1 ) : 0 ) ; if ( _rtDW
-> TransportDelay_IWORK_g . Head [ 2 ] == _rtDW -> TransportDelay_IWORK_g .
Tail [ 2 ] ) { if ( !
InverterModulesInParallel_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_g . CircularBufSize [ 2 ] , & _rtDW ->
TransportDelay_IWORK_g . Tail [ 2 ] , & _rtDW -> TransportDelay_IWORK_g .
Head [ 2 ] , & _rtDW -> TransportDelay_IWORK_g . Last [ 2 ] , simTime - _rtP
-> P_14 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_g . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 2 ] ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_g . Head [ 2 ] ] = _rtB -> B_14_1_0 [ 2 ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_k [ 0 ] = _rtB -> B_14_7_0 [ 0 ] ; _rtDW ->
Memory_PreviousInput_k [ 1 ] = _rtB -> B_14_7_0 [ 1 ] ; _rtDW ->
Memory_PreviousInput_k [ 2 ] = _rtB -> B_14_7_0 [ 2 ] ; } } if ( _rtDW ->
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
_rtDW -> TransportDelay_IWORK . Last , simTime - _rtP -> P_34 , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head ] = _rtB -> B_17_1_0 ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput = _rtB ->
B_17_7_0 ; } } UNUSED_PARAMETER ( tid ) ; }
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
RMS_MODE_h ) { _rtXdot -> integrator_CSTATE_a [ 0 ] = _rtB -> B_12_5_0 [ 0 ]
; _rtXdot -> integrator_CSTATE_o [ 0 ] = _rtB -> B_12_3_0 [ 0 ] ; _rtXdot ->
integrator_CSTATE_a [ 1 ] = _rtB -> B_12_5_0 [ 1 ] ; _rtXdot ->
integrator_CSTATE_o [ 1 ] = _rtB -> B_12_3_0 [ 1 ] ; _rtXdot ->
integrator_CSTATE_a [ 2 ] = _rtB -> B_12_5_0 [ 2 ] ; _rtXdot ->
integrator_CSTATE_o [ 2 ] = _rtB -> B_12_3_0 [ 2 ] ; } else { { real_T * dx ;
int_T i ; dx = & ( ( ( XDot_InverterModulesInParallel_T * ) ssGetdX ( S ) )
-> integrator_CSTATE_a [ 0 ] ) ; for ( i = 0 ; i < 6 ; i ++ ) { dx [ i ] =
0.0 ; } } } if ( _rtDW -> TrueRMS_MODE_e ) { _rtXdot -> integrator_CSTATE_c [
0 ] = _rtB -> B_14_8_0 [ 0 ] ; _rtXdot -> integrator_CSTATE_c [ 1 ] = _rtB ->
B_14_8_0 [ 1 ] ; _rtXdot -> integrator_CSTATE_c [ 2 ] = _rtB -> B_14_8_0 [ 2
] ; } else { { real_T * dx ; int_T i ; dx = & ( ( (
XDot_InverterModulesInParallel_T * ) ssGetdX ( S ) ) -> integrator_CSTATE_c [
0 ] ) ; for ( i = 0 ; i < 3 ; i ++ ) { dx [ i ] = 0.0 ; } } } if ( _rtDW ->
RMS_MODE ) { _rtXdot -> integrator_CSTATE_e = _rtB -> B_15_5_0 ; _rtXdot ->
integrator_CSTATE_i = _rtB -> B_15_3_0 ; } else { { real_T * dx ; int_T i ;
dx = & ( ( ( XDot_InverterModulesInParallel_T * ) ssGetdX ( S ) ) ->
integrator_CSTATE_e ) ; for ( i = 0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } } }
if ( _rtDW -> TrueRMS_MODE ) { _rtXdot -> integrator_CSTATE = _rtB ->
B_17_8_0 ; } else { ( ( XDot_InverterModulesInParallel_T * ) ssGetdX ( S ) )
-> integrator_CSTATE = 0.0 ; } }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) {
B_InverterModulesInParallel_T * _rtB ; P_InverterModulesInParallel_T * _rtP ;
ZCV_InverterModulesInParallel_T * _rtZCSV ; DW_InverterModulesInParallel_T *
_rtDW ; _rtDW = ( ( DW_InverterModulesInParallel_T * ) ssGetRootDWork ( S ) )
; _rtZCSV = ( ( ZCV_InverterModulesInParallel_T * ) ssGetSolverZcSignalVector
( S ) ) ; _rtP = ( ( P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) )
; _rtB = ( ( B_InverterModulesInParallel_T * ) _ssGetModelBlockIO ( S ) ) ;
_rtZCSV -> Compare_RelopInput_ZC = _rtB -> B_18_14_0 -
InverterModulesInParallel_rtC ( S ) -> B_18_15_0 ; _rtZCSV ->
Compare_RelopInput_ZC_e = _rtB -> B_18_14_0 - InverterModulesInParallel_rtC (
S ) -> B_18_31_0 ; _rtZCSV -> Compare_RelopInput_ZC_d = _rtB -> B_18_57_0 -
InverterModulesInParallel_rtC ( S ) -> B_18_58_0 ; _rtZCSV ->
Compare_RelopInput_ZC_a = _rtB -> B_18_57_0 - InverterModulesInParallel_rtC (
S ) -> B_18_74_0 ; _rtZCSV -> Compare_RelopInput_ZC_p = _rtB -> B_18_90_0 -
InverterModulesInParallel_rtC ( S ) -> B_18_91_0 ; _rtZCSV ->
Compare_RelopInput_ZC_av = _rtB -> B_18_90_0 - InverterModulesInParallel_rtC
( S ) -> B_18_106_0 ; _rtZCSV -> Compare_RelopInput_ZC_n = _rtB -> B_18_122_0
- InverterModulesInParallel_rtC ( S ) -> B_18_123_0 ; _rtZCSV ->
Compare_RelopInput_ZC_j = _rtB -> B_18_122_0 - InverterModulesInParallel_rtC
( S ) -> B_18_138_0 ; _rtZCSV -> Compare_RelopInput_ZC_o = _rtB -> B_18_154_0
- InverterModulesInParallel_rtC ( S ) -> B_18_155_0 ; _rtZCSV ->
Compare_RelopInput_ZC_i = _rtB -> B_18_154_0 - InverterModulesInParallel_rtC
( S ) -> B_18_170_0 ; _rtZCSV -> Compare_RelopInput_ZC_f = _rtB -> B_18_186_0
- InverterModulesInParallel_rtC ( S ) -> B_18_187_0 ; _rtZCSV ->
Compare_RelopInput_ZC_pd = _rtB -> B_18_186_0 - InverterModulesInParallel_rtC
( S ) -> B_18_202_0 ; if ( _rtDW -> TrueRMS_MODE_e ) { _rtZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 0 ] = _rtB -> B_14_7_0 [ 0 ] -
_rtP -> P_18 ; _rtZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC_d [ 0 ] =
_rtB -> B_14_7_0 [ 0 ] - _rtP -> P_19 ; _rtZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 1 ] = _rtB -> B_14_7_0 [ 1 ] -
_rtP -> P_18 ; _rtZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC_d [ 1 ] =
_rtB -> B_14_7_0 [ 1 ] - _rtP -> P_19 ; _rtZCSV ->
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 2 ] = _rtB -> B_14_7_0 [ 2 ] -
_rtP -> P_18 ; _rtZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC_d [ 2 ] =
_rtB -> B_14_7_0 [ 2 ] - _rtP -> P_19 ; } else { { real_T * zcsv = & ( ( (
ZCV_InverterModulesInParallel_T * ) ssGetSolverZcSignalVector ( S ) ) ->
Saturationtoavoidnegativesqrt_UprLim_ZC_i [ 0 ] ) ; int_T i ; for ( i = 0 ; i
< 6 ; i ++ ) { zcsv [ i ] = 0.0 ; } } } if ( _rtDW -> TrueRMS_MODE ) {
_rtZCSV -> Saturationtoavoidnegativesqrt_UprLim_ZC = _rtB -> B_17_7_0 - _rtP
-> P_38 ; _rtZCSV -> Saturationtoavoidnegativesqrt_LwrLim_ZC = _rtB ->
B_17_7_0 - _rtP -> P_39 ; } else { { real_T * zcsv = & ( ( (
ZCV_InverterModulesInParallel_T * ) ssGetSolverZcSignalVector ( S ) ) ->
Saturationtoavoidnegativesqrt_UprLim_ZC ) ; int_T i ; for ( i = 0 ; i < 2 ; i
++ ) { zcsv [ i ] = 0.0 ; } } } } static void mdlInitializeSizes ( SimStruct
* S ) { ssSetChecksumVal ( S , 0 , 2693451532U ) ; ssSetChecksumVal ( S , 1 ,
2302314703U ) ; ssSetChecksumVal ( S , 2 , 3546223786U ) ; ssSetChecksumVal (
S , 3 , 3056272162U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
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
) ) ; ( ( P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) -> P_18 =
rtInf ; ( ( P_InverterModulesInParallel_T * ) ssGetModelRtp ( S ) ) -> P_38 =
rtInf ; } static void mdlInitializeSampleTimes ( SimStruct * S ) {
slAccRegPrmChangeFcn ( S , mdlOutputsTID4 ) ; } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
