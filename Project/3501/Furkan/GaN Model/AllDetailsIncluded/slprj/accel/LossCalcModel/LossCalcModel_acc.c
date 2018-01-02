#include "__cf_LossCalcModel.h"
#include <math.h>
#include "LossCalcModel_acc.h"
#include "LossCalcModel_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T jjneigch43 ;
ervgzdocgz * _rtB ; hkfi5rlfjg * _rtP ; nh52is3qev * _rtDW ; _rtDW = ( (
nh52is3qev * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( hkfi5rlfjg * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( ervgzdocgz * ) _ssGetModelBlockIO ( S ) )
; if ( ssIsSampleHit ( S , 1 , tid ) ) { _rtB -> lw025pinyl = _rtDW ->
behv34xaa4 ; _rtB -> dezwsn5cjo = _rtDW -> gfxcdccpoj ; ssCallAccelRunBlock (
S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> blre2rovhg > _rtP -> P_2 ) {
_rtB -> gv04iwib24 = _rtP -> P_2 ; } else if ( _rtB -> blre2rovhg < _rtP ->
P_3 ) { _rtB -> gv04iwib24 = _rtP -> P_3 ; } else { _rtB -> gv04iwib24 = _rtB
-> blre2rovhg ; } _rtB -> afajddmblg [ 0 ] = _rtB -> gv04iwib24 ; _rtB ->
afajddmblg [ 1 ] = 0.0 ; _rtB -> afajddmblg [ 2 ] = 0.0 ; _rtDW -> d4lnlv4nxq
[ 0 ] = ! ( _rtB -> afajddmblg [ 0 ] == _rtDW -> d4lnlv4nxq [ 1 ] ) ; _rtDW
-> d4lnlv4nxq [ 1 ] = _rtB -> afajddmblg [ 0 ] ; _rtB -> afajddmblg [ 3 ] =
_rtDW -> d4lnlv4nxq [ 0 ] ; _rtB -> evnmr24in1 = _rtDW -> is40czrpuj ; _rtB
-> itx2fny1ho = _rtDW -> j0ixxjqwpa ; ssCallAccelRunBlock ( S , 1 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> mehcln5xr1 > _rtP -> P_6 ) { _rtB ->
c2hqyqaef1 = _rtP -> P_6 ; } else if ( _rtB -> mehcln5xr1 < _rtP -> P_7 ) {
_rtB -> c2hqyqaef1 = _rtP -> P_7 ; } else { _rtB -> c2hqyqaef1 = _rtB ->
mehcln5xr1 ; } _rtB -> niknb02dad [ 0 ] = _rtB -> c2hqyqaef1 ; _rtB ->
niknb02dad [ 1 ] = 0.0 ; _rtB -> niknb02dad [ 2 ] = 0.0 ; _rtDW -> psbmiatt01
[ 0 ] = ! ( _rtB -> niknb02dad [ 0 ] == _rtDW -> psbmiatt01 [ 1 ] ) ; _rtDW
-> psbmiatt01 [ 1 ] = _rtB -> niknb02dad [ 0 ] ; _rtB -> niknb02dad [ 3 ] =
_rtDW -> psbmiatt01 [ 0 ] ; _rtB -> dybjy2aiaa = _rtDW -> pqvlm13exl ; _rtB
-> aor0cybm5m [ 0 ] = _rtB -> dybjy2aiaa ; _rtB -> aor0cybm5m [ 1 ] = 0.0 ;
_rtB -> aor0cybm5m [ 2 ] = 0.0 ; _rtDW -> airxlstqgu [ 0 ] = ! ( _rtB ->
aor0cybm5m [ 0 ] == _rtDW -> airxlstqgu [ 1 ] ) ; _rtDW -> airxlstqgu [ 1 ] =
_rtB -> aor0cybm5m [ 0 ] ; _rtB -> aor0cybm5m [ 3 ] = _rtDW -> airxlstqgu [ 0
] ; _rtB -> gjyk1z2wzv = _rtDW -> pog3zl35jc ; _rtB -> iplls55jb1 [ 0 ] =
_rtB -> gjyk1z2wzv ; _rtB -> iplls55jb1 [ 1 ] = 0.0 ; _rtB -> iplls55jb1 [ 2
] = 0.0 ; _rtDW -> iiflbjwyuo [ 0 ] = ! ( _rtB -> iplls55jb1 [ 0 ] == _rtDW
-> iiflbjwyuo [ 1 ] ) ; _rtDW -> iiflbjwyuo [ 1 ] = _rtB -> iplls55jb1 [ 0 ]
; _rtB -> iplls55jb1 [ 3 ] = _rtDW -> iiflbjwyuo [ 0 ] ; _rtB -> bwh21wwayp =
_rtDW -> ptrcomptr2 ; _rtB -> n4hhnmkbzu [ 0 ] = _rtB -> bwh21wwayp ; _rtB ->
n4hhnmkbzu [ 1 ] = 0.0 ; _rtB -> n4hhnmkbzu [ 2 ] = 0.0 ; _rtDW -> lucjh5axsj
[ 0 ] = ! ( _rtB -> n4hhnmkbzu [ 0 ] == _rtDW -> lucjh5axsj [ 1 ] ) ; _rtDW
-> lucjh5axsj [ 1 ] = _rtB -> n4hhnmkbzu [ 0 ] ; _rtB -> n4hhnmkbzu [ 3 ] =
_rtDW -> lucjh5axsj [ 0 ] ; _rtB -> a10tx2bvax = _rtDW -> hjqd5gta3b ; _rtB
-> iauyl2vjs2 [ 0 ] = _rtB -> a10tx2bvax ; _rtB -> iauyl2vjs2 [ 1 ] = 0.0 ;
_rtB -> iauyl2vjs2 [ 2 ] = 0.0 ; _rtDW -> nfdej3gnqd [ 0 ] = ! ( _rtB ->
iauyl2vjs2 [ 0 ] == _rtDW -> nfdej3gnqd [ 1 ] ) ; _rtDW -> nfdej3gnqd [ 1 ] =
_rtB -> iauyl2vjs2 [ 0 ] ; _rtB -> iauyl2vjs2 [ 3 ] = _rtDW -> nfdej3gnqd [ 0
] ; _rtB -> i1qno5mb2d = _rtDW -> nnscaihtc5 ; _rtB -> dx0oxjhqzv [ 0 ] =
_rtB -> i1qno5mb2d ; _rtB -> dx0oxjhqzv [ 1 ] = 0.0 ; _rtB -> dx0oxjhqzv [ 2
] = 0.0 ; _rtDW -> d2ahpais1y [ 0 ] = ! ( _rtB -> dx0oxjhqzv [ 0 ] == _rtDW
-> d2ahpais1y [ 1 ] ) ; _rtDW -> d2ahpais1y [ 1 ] = _rtB -> dx0oxjhqzv [ 0 ]
; _rtB -> dx0oxjhqzv [ 3 ] = _rtDW -> d2ahpais1y [ 0 ] ; _rtB -> dtwd4qa2hj =
_rtDW -> bmdztsj5fi ; _rtB -> ehw4yxsw5s [ 0 ] = _rtB -> dtwd4qa2hj ; _rtB ->
ehw4yxsw5s [ 1 ] = 0.0 ; _rtB -> ehw4yxsw5s [ 2 ] = 0.0 ; _rtDW -> jcgph53zyu
[ 0 ] = ! ( _rtB -> ehw4yxsw5s [ 0 ] == _rtDW -> jcgph53zyu [ 1 ] ) ; _rtDW
-> jcgph53zyu [ 1 ] = _rtB -> ehw4yxsw5s [ 0 ] ; _rtB -> ehw4yxsw5s [ 3 ] =
_rtDW -> jcgph53zyu [ 0 ] ; ssCallAccelRunBlock ( S , 5 , 22 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 23 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 24 ,
SS_CALL_MDL_OUTPUTS ) ; jjneigch43 = _rtB -> gv04iwib24 * _rtB -> oyb1mumiru
; ssCallAccelRunBlock ( S , 5 , 27 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
auitzjv2hy = jjneigch43 + _rtB -> lwwoim3q2k [ 3 ] ; _rtB -> mhdi1f55fb =
_rtP -> P_15 * _rtB -> auitzjv2hy ; ssCallAccelRunBlock ( S , 5 , 30 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 31 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> lfvd50jbmc = _rtB -> auitzjv2hy * _rtB ->
btl11ckk1o [ 0 ] ; _rtB -> nzwvc5arqd = _rtB -> neawynovys * _rtB ->
lfvd50jbmc ; if ( ( ( _rtB -> btl11ckk1o [ 13 ] > 0.0 ) && ( _rtDW ->
bn4h4wyzct <= 0 ) ) || ( ( _rtB -> btl11ckk1o [ 13 ] <= 0.0 ) && ( _rtDW ->
bn4h4wyzct == 1 ) ) ) { _rtDW -> dns5xae0w2 = _rtP -> P_18 ; } _rtB ->
lukwhglwn5 = _rtDW -> dns5xae0w2 ; ssCallAccelRunBlock ( S , 5 , 36 ,
SS_CALL_MDL_OUTPUTS ) ; jjneigch43 = _rtB -> c2hqyqaef1 * _rtB -> b3flw5zkbr
; ssCallAccelRunBlock ( S , 5 , 39 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
etrkkj25dq = jjneigch43 + _rtB -> mymmj0xixp [ 3 ] ; _rtB -> kruy3lmdop =
_rtB -> etrkkj25dq * _rtB -> btl11ckk1o [ 1 ] ; _rtB -> fyh0gqlnu2 = _rtB ->
dsx4x4vw51 * _rtB -> kruy3lmdop ; if ( ( ( _rtB -> btl11ckk1o [ 12 ] > 0.0 )
&& ( _rtDW -> ezedtwztwi <= 0 ) ) || ( ( _rtB -> btl11ckk1o [ 12 ] <= 0.0 )
&& ( _rtDW -> ezedtwztwi == 1 ) ) ) { _rtDW -> oofpjzwgki = _rtP -> P_22 ; }
_rtB -> di0qvpyo5d = _rtDW -> oofpjzwgki ; ssCallAccelRunBlock ( S , 5 , 45 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> maj5nus1d0 = _rtB -> auitzjv2hy * _rtB ->
btl11ckk1o [ 1 ] ; _rtB -> erjcnftoke = _rtB -> fffjmcwscq * _rtB ->
maj5nus1d0 ; if ( ssIsSpecialSampleHit ( S , 2 , 1 , tid ) ) { _rtB ->
gzaywj0m0k = _rtDW -> ndxj5hxpsk ; } if ( ( ( _rtB -> gzaywj0m0k > 0.0 ) && (
_rtDW -> knxq55wgwe <= 0 ) ) || ( ( _rtB -> gzaywj0m0k <= 0.0 ) && ( _rtDW ->
knxq55wgwe == 1 ) ) ) { _rtDW -> h3uwavlggl = _rtP -> P_26 ; } if ( _rtDW ->
h3uwavlggl > _rtP -> P_27 ) { _rtB -> i4l5pce01l = _rtP -> P_27 ; } else if (
_rtDW -> h3uwavlggl < _rtP -> P_28 ) { _rtB -> i4l5pce01l = _rtP -> P_28 ; }
else { _rtB -> i4l5pce01l = _rtDW -> h3uwavlggl ; } ssCallAccelRunBlock ( S ,
5 , 52 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) {
_rtB -> ic0erukf35 = ssGetT ( S ) ; } if ( ssIsSampleHit ( S , 1 , tid ) &&
ssIsSpecialSampleHit ( S , 2 , 1 , tid ) ) { _rtB -> h40uwl2bqk = _rtB ->
ic0erukf35 ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { ssCallAccelRunBlock ( S
, 4 , 0 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> bieafzxuj0 = _rtB -> lwwoim3q2k
[ 1 ] - _rtB -> btl11ckk1o [ 11 ] ; _rtB -> dmbviyn5jv = _rtB -> mymmj0xixp [
2 ] - _rtB -> btl11ckk1o [ 7 ] ; _rtB -> flkclcjgjo = _rtB -> btl11ckk1o [ 8
] + _rtB -> btl11ckk1o [ 9 ] ; _rtB -> kjxcsdgv2b = _rtB -> btl11ckk1o [ 5 ]
+ _rtB -> btl11ckk1o [ 4 ] ; ssCallAccelRunBlock ( S , 5 , 170 ,
SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID3 ( SimStruct * S , int_T tid ) { ervgzdocgz * _rtB ; hkfi5rlfjg
* _rtP ; _rtP = ( ( hkfi5rlfjg * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
ervgzdocgz * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> oyb1mumiru = _rtP -> P_14
; _rtB -> neawynovys = _rtP -> P_16 ; _rtB -> b3flw5zkbr = _rtP -> P_19 ;
_rtB -> dsx4x4vw51 = _rtP -> P_20 ; _rtB -> fffjmcwscq = _rtP -> P_23 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { ervgzdocgz * _rtB ;
hkfi5rlfjg * _rtP ; nh52is3qev * _rtDW ; _rtDW = ( ( nh52is3qev * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( hkfi5rlfjg * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( ervgzdocgz * ) _ssGetModelBlockIO ( S ) ) ; if ( ssIsSampleHit ( S
, 1 , tid ) ) { _rtDW -> behv34xaa4 = _rtB -> btl11ckk1o [ 11 ] ; _rtDW ->
gfxcdccpoj = _rtB -> lwwoim3q2k [ 1 ] ; _rtDW -> is40czrpuj = _rtB ->
btl11ckk1o [ 7 ] ; _rtDW -> j0ixxjqwpa = _rtB -> mymmj0xixp [ 2 ] ; _rtDW ->
pqvlm13exl = _rtB -> dquijvdhzz ; _rtDW -> pog3zl35jc = _rtB -> npj41ioagy ;
_rtDW -> ptrcomptr2 = _rtB -> jlpzk2ndhi ; _rtDW -> hjqd5gta3b = _rtB ->
hubl4clfby ; _rtDW -> nnscaihtc5 = _rtB -> o4tgcxszpc ; _rtDW -> bmdztsj5fi =
_rtB -> cptrsu1zox ; ssCallAccelRunBlock ( S , 5 , 22 , SS_CALL_MDL_UPDATE )
; _rtDW -> dns5xae0w2 += _rtP -> P_17 * _rtB -> lfvd50jbmc ; if ( _rtB ->
btl11ckk1o [ 13 ] > 0.0 ) { _rtDW -> bn4h4wyzct = 1 ; } else if ( _rtB ->
btl11ckk1o [ 13 ] < 0.0 ) { _rtDW -> bn4h4wyzct = - 1 ; } else if ( _rtB ->
btl11ckk1o [ 13 ] == 0.0 ) { _rtDW -> bn4h4wyzct = 0 ; } else { _rtDW ->
bn4h4wyzct = 2 ; } _rtDW -> oofpjzwgki += _rtP -> P_21 * _rtB -> kruy3lmdop ;
if ( _rtB -> btl11ckk1o [ 12 ] > 0.0 ) { _rtDW -> ezedtwztwi = 1 ; } else if
( _rtB -> btl11ckk1o [ 12 ] < 0.0 ) { _rtDW -> ezedtwztwi = - 1 ; } else if (
_rtB -> btl11ckk1o [ 12 ] == 0.0 ) { _rtDW -> ezedtwztwi = 0 ; } else { _rtDW
-> ezedtwztwi = 2 ; } } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW ->
ndxj5hxpsk = _rtB -> oiqto4vji0 ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtDW -> h3uwavlggl += _rtP -> P_25 * _rtB -> maj5nus1d0 ; if ( _rtB ->
gzaywj0m0k > 0.0 ) { _rtDW -> knxq55wgwe = 1 ; } else if ( _rtB -> gzaywj0m0k
< 0.0 ) { _rtDW -> knxq55wgwe = - 1 ; } else if ( _rtB -> gzaywj0m0k == 0.0 )
{ _rtDW -> knxq55wgwe = 0 ; } else { _rtDW -> knxq55wgwe = 2 ; } }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 2175587048U ) ; ssSetChecksumVal ( S , 1 , 257681091U ) ;
ssSetChecksumVal ( S , 2 , 105594698U ) ; ssSetChecksumVal ( S , 3 ,
4152867793U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
nh52is3qev ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( ervgzdocgz ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
hkfi5rlfjg ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & nduks53xmf ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 3 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 4 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID3 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
