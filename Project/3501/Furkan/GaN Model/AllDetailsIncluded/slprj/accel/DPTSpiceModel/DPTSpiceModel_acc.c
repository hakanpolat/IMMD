#include "__cf_DPTSpiceModel.h"
#include <math.h>
#include "DPTSpiceModel_acc.h"
#include "DPTSpiceModel_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void mdlOutputs ( SimStruct * S , int_T tid ) { br0bjo30ls * _rtB ;
eqopz54blq * _rtP ; afav0isfr2 * _rtDW ; _rtDW = ( ( afav0isfr2 * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( eqopz54blq * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( br0bjo30ls * ) _ssGetModelBlockIO ( S ) ) ; if ( ssIsSampleHit ( S
, 1 , tid ) ) { _rtB -> hukfl4xqxk = _rtDW -> eyg3oidtli ; _rtB -> h5v41yjmzz
= _rtDW -> cvdcfw050e ; ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS
) ; if ( _rtB -> kce0jf44e2 > _rtP -> P_2 ) { _rtB -> j1mwuqnzuw = _rtP ->
P_2 ; } else if ( _rtB -> kce0jf44e2 < _rtP -> P_3 ) { _rtB -> j1mwuqnzuw =
_rtP -> P_3 ; } else { _rtB -> j1mwuqnzuw = _rtB -> kce0jf44e2 ; } _rtB ->
cnl1wnmmea [ 0 ] = _rtB -> j1mwuqnzuw ; _rtB -> cnl1wnmmea [ 1 ] = 0.0 ; _rtB
-> cnl1wnmmea [ 2 ] = 0.0 ; _rtDW -> fkbxtuyju0 [ 0 ] = ! ( _rtB ->
cnl1wnmmea [ 0 ] == _rtDW -> fkbxtuyju0 [ 1 ] ) ; _rtDW -> fkbxtuyju0 [ 1 ] =
_rtB -> cnl1wnmmea [ 0 ] ; _rtB -> cnl1wnmmea [ 3 ] = _rtDW -> fkbxtuyju0 [ 0
] ; _rtB -> l2fccmkpzx = _rtDW -> mbitatipws ; _rtB -> ixmlvdnimh [ 0 ] =
_rtB -> l2fccmkpzx ; _rtB -> ixmlvdnimh [ 1 ] = 0.0 ; _rtB -> ixmlvdnimh [ 2
] = 0.0 ; _rtDW -> kuhmcqrtwx [ 0 ] = ! ( _rtB -> ixmlvdnimh [ 0 ] == _rtDW
-> kuhmcqrtwx [ 1 ] ) ; _rtDW -> kuhmcqrtwx [ 1 ] = _rtB -> ixmlvdnimh [ 0 ]
; _rtB -> ixmlvdnimh [ 3 ] = _rtDW -> kuhmcqrtwx [ 0 ] ; _rtB -> njccpham0d =
_rtDW -> bkyncdkmqi ; _rtB -> d3hhmpma4g [ 0 ] = _rtB -> njccpham0d ; _rtB ->
d3hhmpma4g [ 1 ] = 0.0 ; _rtB -> d3hhmpma4g [ 2 ] = 0.0 ; _rtDW -> mklbjyogld
[ 0 ] = ! ( _rtB -> d3hhmpma4g [ 0 ] == _rtDW -> mklbjyogld [ 1 ] ) ; _rtDW
-> mklbjyogld [ 1 ] = _rtB -> d3hhmpma4g [ 0 ] ; _rtB -> d3hhmpma4g [ 3 ] =
_rtDW -> mklbjyogld [ 0 ] ; _rtB -> ja5j0irj0j = _rtDW -> d1xpqpqshy ; _rtB
-> opyvi204ga [ 0 ] = _rtB -> ja5j0irj0j ; _rtB -> opyvi204ga [ 1 ] = 0.0 ;
_rtB -> opyvi204ga [ 2 ] = 0.0 ; _rtDW -> bp3feyvuhg [ 0 ] = ! ( _rtB ->
opyvi204ga [ 0 ] == _rtDW -> bp3feyvuhg [ 1 ] ) ; _rtDW -> bp3feyvuhg [ 1 ] =
_rtB -> opyvi204ga [ 0 ] ; _rtB -> opyvi204ga [ 3 ] = _rtDW -> bp3feyvuhg [ 0
] ; _rtB -> bnrafwosbt = _rtDW -> bevxbtkozj ; _rtB -> o2uz5wlgzl = _rtDW ->
lcyit0bqeh ; ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; if (
_rtB -> ewumnltn1c > _rtP -> P_9 ) { _rtB -> mbq40hv3wz = _rtP -> P_9 ; }
else if ( _rtB -> ewumnltn1c < _rtP -> P_10 ) { _rtB -> mbq40hv3wz = _rtP ->
P_10 ; } else { _rtB -> mbq40hv3wz = _rtB -> ewumnltn1c ; } _rtB ->
jn34tngylm [ 0 ] = _rtB -> mbq40hv3wz ; _rtB -> jn34tngylm [ 1 ] = 0.0 ; _rtB
-> jn34tngylm [ 2 ] = 0.0 ; _rtDW -> ggdzvf2rxm [ 0 ] = ! ( _rtB ->
jn34tngylm [ 0 ] == _rtDW -> ggdzvf2rxm [ 1 ] ) ; _rtDW -> ggdzvf2rxm [ 1 ] =
_rtB -> jn34tngylm [ 0 ] ; _rtB -> jn34tngylm [ 3 ] = _rtDW -> ggdzvf2rxm [ 0
] ; _rtB -> bipimnifep = _rtDW -> eo5tk1135j ; _rtB -> flcss555x1 [ 0 ] =
_rtB -> bipimnifep ; _rtB -> flcss555x1 [ 1 ] = 0.0 ; _rtB -> flcss555x1 [ 2
] = 0.0 ; _rtDW -> cxufyyseoh [ 0 ] = ! ( _rtB -> flcss555x1 [ 0 ] == _rtDW
-> cxufyyseoh [ 1 ] ) ; _rtDW -> cxufyyseoh [ 1 ] = _rtB -> flcss555x1 [ 0 ]
; _rtB -> flcss555x1 [ 3 ] = _rtDW -> cxufyyseoh [ 0 ] ; _rtB -> mh4vv24yfa =
_rtDW -> ees2bta2x3 ; _rtB -> fzrocwxu0k [ 0 ] = _rtB -> mh4vv24yfa ; _rtB ->
fzrocwxu0k [ 1 ] = 0.0 ; _rtB -> fzrocwxu0k [ 2 ] = 0.0 ; _rtDW -> ikfq5upkr2
[ 0 ] = ! ( _rtB -> fzrocwxu0k [ 0 ] == _rtDW -> ikfq5upkr2 [ 1 ] ) ; _rtDW
-> ikfq5upkr2 [ 1 ] = _rtB -> fzrocwxu0k [ 0 ] ; _rtB -> fzrocwxu0k [ 3 ] =
_rtDW -> ikfq5upkr2 [ 0 ] ; _rtB -> egw50y0vtp = _rtDW -> lc2as1150l ; _rtB
-> bjqc5ribai [ 0 ] = _rtB -> egw50y0vtp ; _rtB -> bjqc5ribai [ 1 ] = 0.0 ;
_rtB -> bjqc5ribai [ 2 ] = 0.0 ; _rtDW -> h1ugov1xqc [ 0 ] = ! ( _rtB ->
bjqc5ribai [ 0 ] == _rtDW -> h1ugov1xqc [ 1 ] ) ; _rtDW -> h1ugov1xqc [ 1 ] =
_rtB -> bjqc5ribai [ 0 ] ; _rtB -> bjqc5ribai [ 3 ] = _rtDW -> h1ugov1xqc [ 0
] ; ssCallAccelRunBlock ( S , 5 , 22 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 23 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 24 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 25 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> nvkvozjk11
= _rtP -> P_14 * _rtB -> mlhliquzc0 [ 3 ] ; _rtB -> a3wbuzpxbg = _rtP -> P_15
* _rtB -> mlhliquzc0 [ 1 ] ; ssCallAccelRunBlock ( S , 5 , 28 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 29 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 30 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> lm4lpfxr2l = _rtB -> hfn0eqou5r [ 3 ] * _rtB
-> glvoj1yx13 [ 0 ] ; _rtB -> cmyrhag3yw = _rtB -> iyp1flovtl * _rtB ->
lm4lpfxr2l ; if ( ( ( _rtB -> glvoj1yx13 [ 12 ] > 0.0 ) && ( _rtDW ->
hs12px2cvt <= 0 ) ) || ( ( _rtB -> glvoj1yx13 [ 12 ] <= 0.0 ) && ( _rtDW ->
hs12px2cvt == 1 ) ) ) { _rtDW -> amm5wk5tke = _rtP -> P_18 ; } _rtB ->
htgbfskd2c = _rtDW -> amm5wk5tke ; ssCallAccelRunBlock ( S , 5 , 35 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> nwctq5w01f = _rtB -> mlhliquzc0 [ 3 ] * _rtB
-> glvoj1yx13 [ 1 ] ; _rtB -> e0jfjz42e4 = _rtB -> jhkmc00gek * _rtB ->
nwctq5w01f ; if ( ( ( _rtB -> glvoj1yx13 [ 11 ] > 0.0 ) && ( _rtDW ->
g5asi25nti <= 0 ) ) || ( ( _rtB -> glvoj1yx13 [ 11 ] <= 0.0 ) && ( _rtDW ->
g5asi25nti == 1 ) ) ) { _rtDW -> cvkrn1poca = _rtP -> P_21 ; } _rtB ->
jz2hcdl0bn = _rtDW -> cvkrn1poca ; ssCallAccelRunBlock ( S , 5 , 40 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> glyyaoalxs = _rtB -> glvoj1yx13 [ 0 ] * _rtB
-> mlhliquzc0 [ 3 ] ; _rtB -> p1cqorbrav = _rtB -> ik3urpb5dh * _rtB ->
glyyaoalxs ; if ( ssIsSpecialSampleHit ( S , 2 , 1 , tid ) ) { _rtB ->
g1rd5i0ami = _rtDW -> ih0fhhacgx ; } if ( ( ( _rtB -> g1rd5i0ami > 0.0 ) && (
_rtDW -> pkajq3h1jf <= 0 ) ) || ( ( _rtB -> g1rd5i0ami <= 0.0 ) && ( _rtDW ->
pkajq3h1jf == 1 ) ) ) { _rtDW -> dzljk1kggf = _rtP -> P_25 ; } if ( _rtDW ->
dzljk1kggf > _rtP -> P_26 ) { _rtB -> eoro1afmi4 = _rtP -> P_26 ; } else if (
_rtDW -> dzljk1kggf < _rtP -> P_27 ) { _rtB -> eoro1afmi4 = _rtP -> P_27 ; }
else { _rtB -> eoro1afmi4 = _rtDW -> dzljk1kggf ; } ssCallAccelRunBlock ( S ,
5 , 47 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsContinuousTask ( S , tid ) ) {
_rtB -> mznprmqtum = ssGetT ( S ) ; } if ( ssIsSampleHit ( S , 1 , tid ) &&
ssIsSpecialSampleHit ( S , 2 , 1 , tid ) ) { _rtB -> cweio5e5ds = _rtB ->
mznprmqtum ; } if ( ssIsSampleHit ( S , 2 , tid ) ) { ssCallAccelRunBlock ( S
, 4 , 0 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtB -> af3twncavj = _rtB -> glvoj1yx13 [ 13 ] + _rtB -> glvoj1yx13 [ 14 ] ;
ssCallAccelRunBlock ( S , 5 , 100 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> gjcxaqqmay
= _rtB -> hfn0eqou5r [ 1 ] - _rtB -> glvoj1yx13 [ 10 ] ; _rtB -> frcqy3hdcq =
_rtB -> mlhliquzc0 [ 2 ] - _rtB -> glvoj1yx13 [ 6 ] ; _rtB -> nye1mznmmm =
_rtB -> glvoj1yx13 [ 7 ] + _rtB -> glvoj1yx13 [ 8 ] ; _rtB -> lp4swr5wwk =
_rtB -> glvoj1yx13 [ 4 ] + _rtB -> glvoj1yx13 [ 3 ] ; ssCallAccelRunBlock ( S
, 5 , 158 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 2 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 227 ,
SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID3 ( SimStruct * S , int_T tid ) { br0bjo30ls * _rtB ; eqopz54blq
* _rtP ; _rtP = ( ( eqopz54blq * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
br0bjo30ls * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> iyp1flovtl = _rtP -> P_16
; _rtB -> jhkmc00gek = _rtP -> P_19 ; _rtB -> ik3urpb5dh = _rtP -> P_22 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { br0bjo30ls * _rtB ;
eqopz54blq * _rtP ; afav0isfr2 * _rtDW ; _rtDW = ( ( afav0isfr2 * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( eqopz54blq * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( br0bjo30ls * ) _ssGetModelBlockIO ( S ) ) ; if ( ssIsSampleHit ( S
, 1 , tid ) ) { _rtDW -> eyg3oidtli = _rtB -> glvoj1yx13 [ 6 ] ; _rtDW ->
cvdcfw050e = _rtB -> mlhliquzc0 [ 2 ] ; _rtDW -> mbitatipws = _rtB ->
fwgf03s03v ; _rtDW -> bkyncdkmqi = _rtB -> auo2jipuel ; _rtDW -> d1xpqpqshy =
_rtB -> iuaylk0qla ; _rtDW -> bevxbtkozj = _rtB -> glvoj1yx13 [ 10 ] ; _rtDW
-> lcyit0bqeh = _rtB -> hfn0eqou5r [ 1 ] ; _rtDW -> eo5tk1135j = _rtB ->
ivzmn50w5o ; _rtDW -> ees2bta2x3 = _rtB -> cfcl0ndpgh ; _rtDW -> lc2as1150l =
_rtB -> jrcvrlqsyv ; ssCallAccelRunBlock ( S , 5 , 22 , SS_CALL_MDL_UPDATE )
; _rtDW -> amm5wk5tke += _rtP -> P_17 * _rtB -> lm4lpfxr2l ; if ( _rtB ->
glvoj1yx13 [ 12 ] > 0.0 ) { _rtDW -> hs12px2cvt = 1 ; } else if ( _rtB ->
glvoj1yx13 [ 12 ] < 0.0 ) { _rtDW -> hs12px2cvt = - 1 ; } else if ( _rtB ->
glvoj1yx13 [ 12 ] == 0.0 ) { _rtDW -> hs12px2cvt = 0 ; } else { _rtDW ->
hs12px2cvt = 2 ; } _rtDW -> cvkrn1poca += _rtP -> P_20 * _rtB -> nwctq5w01f ;
if ( _rtB -> glvoj1yx13 [ 11 ] > 0.0 ) { _rtDW -> g5asi25nti = 1 ; } else if
( _rtB -> glvoj1yx13 [ 11 ] < 0.0 ) { _rtDW -> g5asi25nti = - 1 ; } else if (
_rtB -> glvoj1yx13 [ 11 ] == 0.0 ) { _rtDW -> g5asi25nti = 0 ; } else { _rtDW
-> g5asi25nti = 2 ; } } if ( ssIsSampleHit ( S , 2 , tid ) ) { _rtDW ->
ih0fhhacgx = _rtB -> knw5ygp3ln ; } if ( ssIsSampleHit ( S , 1 , tid ) ) {
_rtDW -> dzljk1kggf += _rtP -> P_24 * _rtB -> glyyaoalxs ; if ( _rtB ->
g1rd5i0ami > 0.0 ) { _rtDW -> pkajq3h1jf = 1 ; } else if ( _rtB -> g1rd5i0ami
< 0.0 ) { _rtDW -> pkajq3h1jf = - 1 ; } else if ( _rtB -> g1rd5i0ami == 0.0 )
{ _rtDW -> pkajq3h1jf = 0 ; } else { _rtDW -> pkajq3h1jf = 2 ; } }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 2210595209U ) ; ssSetChecksumVal ( S , 1 , 2091754207U ) ;
ssSetChecksumVal ( S , 2 , 3797599530U ) ; ssSetChecksumVal ( S , 3 ,
1353043175U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
afav0isfr2 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( br0bjo30ls ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
eqopz54blq ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & dljov40pch ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
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
