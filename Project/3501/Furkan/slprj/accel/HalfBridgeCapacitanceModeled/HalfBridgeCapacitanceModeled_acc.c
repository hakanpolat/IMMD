#include "__cf_HalfBridgeCapacitanceModeled.h"
#include <math.h>
#include "HalfBridgeCapacitanceModeled_acc.h"
#include "HalfBridgeCapacitanceModeled_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T u0 ; mf5tsskwnw
* _rtB ; ddcfacl1ei * _rtP ; k2thubfcsq * _rtDW ; _rtDW = ( ( k2thubfcsq * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( ddcfacl1ei * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( mf5tsskwnw * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> j005oaxjqt =
_rtDW -> fk1exdnnfd ; _rtB -> dm1c2yrrde = _rtDW -> dladgm052y ;
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
p1be1hbiil > _rtP -> P_2 ) { _rtB -> n5jpc0wex5 = _rtP -> P_2 ; } else if (
_rtB -> p1be1hbiil < _rtP -> P_3 ) { _rtB -> n5jpc0wex5 = _rtP -> P_3 ; }
else { _rtB -> n5jpc0wex5 = _rtB -> p1be1hbiil ; } _rtB -> mep4rku20g [ 0 ] =
_rtB -> n5jpc0wex5 ; _rtB -> mep4rku20g [ 1 ] = 0.0 ; _rtB -> mep4rku20g [ 2
] = 0.0 ; _rtDW -> j1rfzotlsp [ 0 ] = ! ( _rtB -> mep4rku20g [ 0 ] == _rtDW
-> j1rfzotlsp [ 1 ] ) ; _rtDW -> j1rfzotlsp [ 1 ] = _rtB -> mep4rku20g [ 0 ]
; _rtB -> mep4rku20g [ 3 ] = _rtDW -> j1rfzotlsp [ 0 ] ; _rtB -> frfi1jw32t =
_rtDW -> k4tttsuv1x ; _rtB -> a50c31bw4j = _rtDW -> kwxbgzipo4 ;
ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
e5z1mchaey > _rtP -> P_6 ) { _rtB -> jcyeajk1ew = _rtP -> P_6 ; } else if (
_rtB -> e5z1mchaey < _rtP -> P_7 ) { _rtB -> jcyeajk1ew = _rtP -> P_7 ; }
else { _rtB -> jcyeajk1ew = _rtB -> e5z1mchaey ; } _rtB -> bbmq1fslf1 [ 0 ] =
_rtB -> jcyeajk1ew ; _rtB -> bbmq1fslf1 [ 1 ] = 0.0 ; _rtB -> bbmq1fslf1 [ 2
] = 0.0 ; _rtDW -> ivhc2koyg1 [ 0 ] = ! ( _rtB -> bbmq1fslf1 [ 0 ] == _rtDW
-> ivhc2koyg1 [ 1 ] ) ; _rtDW -> ivhc2koyg1 [ 1 ] = _rtB -> bbmq1fslf1 [ 0 ]
; _rtB -> bbmq1fslf1 [ 3 ] = _rtDW -> ivhc2koyg1 [ 0 ] ; ssCallAccelRunBlock
( S , 4 , 10 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 11 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 12 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 21 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 38 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 40 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 41 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 4 , 59 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
asdj5ggpfn = _rtB -> dziaii4uco [ 11 ] - _rtB -> dziaii4uco [ 10 ] ; if (
_rtB -> dziaii4uco [ 9 ] > _rtP -> P_8 ) { _rtB -> buofmhkmcl = _rtP -> P_8 ;
} else if ( _rtB -> dziaii4uco [ 9 ] < _rtP -> P_9 ) { _rtB -> buofmhkmcl =
_rtP -> P_9 ; } else { _rtB -> buofmhkmcl = _rtB -> dziaii4uco [ 9 ] ; }
ssCallAccelRunBlock ( S , 4 , 81 , SS_CALL_MDL_OUTPUTS ) ; u0 = _rtP -> P_10
* _rtB -> i2t1wkrjkr ; if ( u0 > _rtP -> P_11 ) { _rtB -> ldskd0vibn = _rtP
-> P_11 ; } else if ( u0 < _rtP -> P_12 ) { _rtB -> ldskd0vibn = _rtP -> P_12
; } else { _rtB -> ldskd0vibn = u0 ; } u0 = _rtP -> P_13 * _rtB -> dziaii4uco
[ 8 ] ; if ( u0 > _rtP -> P_14 ) { _rtB -> fmtz4yap45 = _rtP -> P_14 ; } else
if ( u0 < _rtP -> P_15 ) { _rtB -> fmtz4yap45 = _rtP -> P_15 ; } else { _rtB
-> fmtz4yap45 = u0 ; } u0 = ( _rtB -> dziaii4uco [ 7 ] + _rtB -> dziaii4uco [
8 ] ) * _rtP -> P_16 ; if ( u0 > _rtP -> P_17 ) { _rtB -> p2y3gmekiu = _rtP
-> P_17 ; } else if ( u0 < _rtP -> P_18 ) { _rtB -> p2y3gmekiu = _rtP -> P_18
; } else { _rtB -> p2y3gmekiu = u0 ; } u0 = _rtP -> P_19 * _rtB -> dziaii4uco
[ 7 ] ; if ( u0 > _rtP -> P_20 ) { _rtB -> c21xiron4l = _rtP -> P_20 ; } else
if ( u0 < _rtP -> P_21 ) { _rtB -> c21xiron4l = _rtP -> P_21 ; } else { _rtB
-> c21xiron4l = u0 ; } ssCallAccelRunBlock ( S , 4 , 91 , SS_CALL_MDL_OUTPUTS
) ; if ( _rtB -> dziaii4uco [ 4 ] > _rtP -> P_22 ) { _rtB -> cbac5xomue =
_rtP -> P_22 ; } else if ( _rtB -> dziaii4uco [ 4 ] < _rtP -> P_23 ) { _rtB
-> cbac5xomue = _rtP -> P_23 ; } else { _rtB -> cbac5xomue = _rtB ->
dziaii4uco [ 4 ] ; } ssCallAccelRunBlock ( S , 4 , 93 , SS_CALL_MDL_OUTPUTS )
; _rtB -> dfndxc30aq = _rtB -> dziaii4uco [ 6 ] - _rtB -> dziaii4uco [ 5 ] ;
ssCallAccelRunBlock ( S , 4 , 95 , SS_CALL_MDL_OUTPUTS ) ; u0 = _rtP -> P_24
* _rtB -> bg3e2k3rgb ; if ( u0 > _rtP -> P_25 ) { _rtB -> fscapo3u1p = _rtP
-> P_25 ; } else if ( u0 < _rtP -> P_26 ) { _rtB -> fscapo3u1p = _rtP -> P_26
; } else { _rtB -> fscapo3u1p = u0 ; } u0 = _rtP -> P_27 * _rtB -> dziaii4uco
[ 3 ] ; if ( u0 > _rtP -> P_28 ) { _rtB -> fcf3dbxc2i = _rtP -> P_28 ; } else
if ( u0 < _rtP -> P_29 ) { _rtB -> fcf3dbxc2i = _rtP -> P_29 ; } else { _rtB
-> fcf3dbxc2i = u0 ; } u0 = ( _rtB -> dziaii4uco [ 3 ] + _rtB -> dziaii4uco [
2 ] ) * _rtP -> P_30 ; if ( u0 > _rtP -> P_31 ) { _rtB -> ekirqbns1v = _rtP
-> P_31 ; } else if ( u0 < _rtP -> P_32 ) { _rtB -> ekirqbns1v = _rtP -> P_32
; } else { _rtB -> ekirqbns1v = u0 ; } u0 = _rtP -> P_33 * _rtB -> dziaii4uco
[ 2 ] ; if ( u0 > _rtP -> P_34 ) { _rtB -> ola04sntvq = _rtP -> P_34 ; } else
if ( u0 < _rtP -> P_35 ) { _rtB -> ola04sntvq = _rtP -> P_35 ; } else { _rtB
-> ola04sntvq = u0 ; } ssCallAccelRunBlock ( S , 4 , 105 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> liwgyyxfis = _rtP -> P_36 * _rtB ->
ldskd0vibn ; _rtB -> nfagx5zfb5 = _rtP -> P_37 * _rtB -> fmtz4yap45 ; _rtB ->
hpolmo33vd = _rtP -> P_38 * _rtB -> p2y3gmekiu ; ssCallAccelRunBlock ( S , 4
, 109 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 111 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 112 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 113 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS
) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { mf5tsskwnw * _rtB ;
k2thubfcsq * _rtDW ; _rtDW = ( ( k2thubfcsq * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( mf5tsskwnw * ) _ssGetModelBlockIO ( S ) ) ; _rtDW -> fk1exdnnfd = _rtB
-> dziaii4uco [ 5 ] ; _rtDW -> dladgm052y = _rtB -> dziaii4uco [ 6 ] ; _rtDW
-> k4tttsuv1x = _rtB -> dziaii4uco [ 10 ] ; _rtDW -> kwxbgzipo4 = _rtB ->
dziaii4uco [ 11 ] ; ssCallAccelRunBlock ( S , 4 , 10 , SS_CALL_MDL_UPDATE ) ;
UNUSED_PARAMETER ( tid ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 1478557603U ) ; ssSetChecksumVal ( S , 1 ,
1046454943U ) ; ssSetChecksumVal ( S , 2 , 189399374U ) ; ssSetChecksumVal (
S , 3 , 3663366593U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
k2thubfcsq ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( mf5tsskwnw ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
ddcfacl1ei ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & kxwe1mgi1m ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 3 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
