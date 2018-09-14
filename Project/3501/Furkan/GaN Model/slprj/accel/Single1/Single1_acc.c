#include "__cf_Single1.h"
#include <math.h>
#include "Single1_acc.h"
#include "Single1_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void mdlOutputs ( SimStruct * S , int_T tid ) { jfqvqrw3vn * _rtB ;
mfaqvaa0wo * _rtP ; pnqmfnukko * _rtDW ; _rtDW = ( ( pnqmfnukko * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( mfaqvaa0wo * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( jfqvqrw3vn * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> knzh0jk1o3 =
_rtDW -> lzmffwpvon ; _rtB -> dwa1ry3fsr = _rtDW -> ea3pwmvlfc ;
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
akfdmz1ru3 > _rtP -> P_3 ) { _rtB -> lhb3jrzmzn = _rtP -> P_3 ; } else if (
_rtB -> akfdmz1ru3 < _rtP -> P_4 ) { _rtB -> lhb3jrzmzn = _rtP -> P_4 ; }
else { _rtB -> lhb3jrzmzn = _rtB -> akfdmz1ru3 ; } _rtB -> abqyzqh3d3 [ 0 ] =
_rtB -> lhb3jrzmzn ; _rtB -> abqyzqh3d3 [ 1 ] = 0.0 ; _rtB -> abqyzqh3d3 [ 2
] = 0.0 ; _rtDW -> fbmmozm2nf [ 0 ] = ! ( _rtB -> abqyzqh3d3 [ 0 ] == _rtDW
-> fbmmozm2nf [ 1 ] ) ; _rtDW -> fbmmozm2nf [ 1 ] = _rtB -> abqyzqh3d3 [ 0 ]
; _rtB -> abqyzqh3d3 [ 3 ] = _rtDW -> fbmmozm2nf [ 0 ] ; _rtB -> fylhywusn4 =
_rtDW -> kbw3pfqf4m ; _rtB -> bpvqcwdgsk [ 0 ] = _rtB -> fylhywusn4 ; _rtB ->
bpvqcwdgsk [ 1 ] = 0.0 ; _rtB -> bpvqcwdgsk [ 2 ] = 0.0 ; _rtDW -> kkik12evym
[ 0 ] = ! ( _rtB -> bpvqcwdgsk [ 0 ] == _rtDW -> kkik12evym [ 1 ] ) ; _rtDW
-> kkik12evym [ 1 ] = _rtB -> bpvqcwdgsk [ 0 ] ; _rtB -> bpvqcwdgsk [ 3 ] =
_rtDW -> kkik12evym [ 0 ] ; _rtB -> b1phk1f3g4 = _rtDW -> mmk0tkmbyv ; _rtB
-> pg5xtpe534 [ 0 ] = _rtB -> b1phk1f3g4 ; _rtB -> pg5xtpe534 [ 1 ] = 0.0 ;
_rtB -> pg5xtpe534 [ 2 ] = 0.0 ; _rtDW -> m2hhixc3kl [ 0 ] = ! ( _rtB ->
pg5xtpe534 [ 0 ] == _rtDW -> m2hhixc3kl [ 1 ] ) ; _rtDW -> m2hhixc3kl [ 1 ] =
_rtB -> pg5xtpe534 [ 0 ] ; _rtB -> pg5xtpe534 [ 3 ] = _rtDW -> m2hhixc3kl [ 0
] ; _rtB -> lehgpmxpad = _rtDW -> iluqelevce ; _rtB -> cgjg2bvukr [ 0 ] =
_rtB -> lehgpmxpad ; _rtB -> cgjg2bvukr [ 1 ] = 0.0 ; _rtB -> cgjg2bvukr [ 2
] = 0.0 ; _rtDW -> agn1txjylx [ 0 ] = ! ( _rtB -> cgjg2bvukr [ 0 ] == _rtDW
-> agn1txjylx [ 1 ] ) ; _rtDW -> agn1txjylx [ 1 ] = _rtB -> cgjg2bvukr [ 0 ]
; _rtB -> cgjg2bvukr [ 3 ] = _rtDW -> agn1txjylx [ 0 ] ; ssCallAccelRunBlock
( S , 2 , 12 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 2 , 13 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 2 , 14 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 2 , 15 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 2 , 44 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> f2wkdhtpsh = _rtB -> cro5uolyit [ 1 ] - _rtB
-> fzsx14hlgl [ 4 ] ; _rtB -> bbmyvifcwj = _rtB -> fzsx14hlgl [ 1 ] + _rtB ->
fzsx14hlgl [ 2 ] ; ssCallAccelRunBlock ( S , 2 , 49 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 50 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 52 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 53 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 54 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER (
tid ) ; } static void mdlOutputsTID1 ( SimStruct * S , int_T tid ) {
jfqvqrw3vn * _rtB ; mfaqvaa0wo * _rtP ; _rtP = ( ( mfaqvaa0wo * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( jfqvqrw3vn * ) _ssGetModelBlockIO ( S ) )
; _rtB -> jptbcdy2ro = _rtP -> P_2 ; _rtB -> dqwwvqazlw = 0.0 ; _rtB ->
hdgi22unof = 0.0 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { jfqvqrw3vn * _rtB ;
pnqmfnukko * _rtDW ; _rtDW = ( ( pnqmfnukko * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( jfqvqrw3vn * ) _ssGetModelBlockIO ( S ) ) ; _rtDW -> lzmffwpvon = _rtB
-> fzsx14hlgl [ 4 ] ; _rtDW -> ea3pwmvlfc = _rtB -> cro5uolyit [ 1 ] ; _rtDW
-> kbw3pfqf4m = _rtB -> dauoctgzxj ; _rtDW -> mmk0tkmbyv = _rtB -> in4ewgjcs3
; _rtDW -> iluqelevce = _rtB -> grjysgz0ks ; ssCallAccelRunBlock ( S , 2 , 12
, SS_CALL_MDL_UPDATE ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID1 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 3226692501U ) ; ssSetChecksumVal ( S , 1 , 966667056U ) ;
ssSetChecksumVal ( S , 2 , 3906336583U ) ; ssSetChecksumVal ( S , 3 ,
2561755420U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
pnqmfnukko ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( jfqvqrw3vn ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
mfaqvaa0wo ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & aye2hdqvei ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID1 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
