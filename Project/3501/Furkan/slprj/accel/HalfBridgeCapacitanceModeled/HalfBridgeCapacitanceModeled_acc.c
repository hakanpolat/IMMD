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
_rtB = ( ( mf5tsskwnw * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> c0zq44dn1q =
_rtDW -> k4tttsuv1x ; _rtB -> ifel3rqijc = _rtDW -> kwxbgzipo4 ;
ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
e5z1mchaey > _rtP -> P_2 ) { _rtB -> dpqgdoapyo = _rtP -> P_2 ; } else if (
_rtB -> e5z1mchaey < _rtP -> P_3 ) { _rtB -> dpqgdoapyo = _rtP -> P_3 ; }
else { _rtB -> dpqgdoapyo = _rtB -> e5z1mchaey ; } _rtB -> jwnx40ilip [ 0 ] =
_rtB -> dpqgdoapyo ; _rtB -> jwnx40ilip [ 1 ] = 0.0 ; _rtB -> jwnx40ilip [ 2
] = 0.0 ; _rtDW -> ivhc2koyg1 [ 0 ] = ! ( _rtB -> jwnx40ilip [ 0 ] == _rtDW
-> ivhc2koyg1 [ 1 ] ) ; _rtDW -> ivhc2koyg1 [ 1 ] = _rtB -> jwnx40ilip [ 0 ]
; _rtB -> jwnx40ilip [ 3 ] = _rtDW -> ivhc2koyg1 [ 0 ] ; _rtB -> omnu0rasmz =
_rtDW -> fk1exdnnfd ; _rtB -> fkjfr2nky1 = _rtDW -> dladgm052y ;
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
p1be1hbiil > _rtP -> P_6 ) { _rtB -> ebeata0d2x = _rtP -> P_6 ; } else if (
_rtB -> p1be1hbiil < _rtP -> P_7 ) { _rtB -> ebeata0d2x = _rtP -> P_7 ; }
else { _rtB -> ebeata0d2x = _rtB -> p1be1hbiil ; } _rtB -> d1psxqmeia [ 0 ] =
_rtB -> ebeata0d2x ; _rtB -> d1psxqmeia [ 1 ] = 0.0 ; _rtB -> d1psxqmeia [ 2
] = 0.0 ; _rtDW -> j1rfzotlsp [ 0 ] = ! ( _rtB -> d1psxqmeia [ 0 ] == _rtDW
-> j1rfzotlsp [ 1 ] ) ; _rtDW -> j1rfzotlsp [ 1 ] = _rtB -> d1psxqmeia [ 0 ]
; _rtB -> d1psxqmeia [ 3 ] = _rtDW -> j1rfzotlsp [ 0 ] ; ssCallAccelRunBlock
( S , 4 , 10 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 11 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 12 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 21 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 22 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 39 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 41 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 42 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 4 , 60 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
a112fjtgwp = _rtB -> dziaii4uco [ 3 ] - _rtB -> fg4yinl54e [ 8 ] ; _rtB ->
mhve5jzcwf = _rtB -> dziaii4uco [ 1 ] - _rtB -> fg4yinl54e [ 4 ] ;
ssCallAccelRunBlock ( S , 4 , 82 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> gqbvawpeal
= _rtB -> fg4yinl54e [ 5 ] + _rtB -> fg4yinl54e [ 6 ] ; _rtB -> ldndwfoeyr =
_rtB -> fg4yinl54e [ 2 ] + _rtB -> fg4yinl54e [ 1 ] ; ssCallAccelRunBlock ( S
, 4 , 85 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> p2cu5mozr1 = _rtB -> dziaii4uco [
3 ] - _rtB -> fg4yinl54e [ 8 ] ; if ( _rtB -> fg4yinl54e [ 7 ] > _rtP -> P_8
) { _rtB -> omzjjyzsho = _rtP -> P_8 ; } else if ( _rtB -> fg4yinl54e [ 7 ] <
_rtP -> P_9 ) { _rtB -> omzjjyzsho = _rtP -> P_9 ; } else { _rtB ->
omzjjyzsho = _rtB -> fg4yinl54e [ 7 ] ; } u0 = _rtP -> P_10 * _rtB ->
dziaii4uco [ 2 ] ; if ( u0 > _rtP -> P_11 ) { _rtB -> lvlebcf42d = _rtP ->
P_11 ; } else if ( u0 < _rtP -> P_12 ) { _rtB -> lvlebcf42d = _rtP -> P_12 ;
} else { _rtB -> lvlebcf42d = u0 ; } u0 = _rtP -> P_13 * _rtB -> fg4yinl54e [
6 ] ; if ( u0 > _rtP -> P_14 ) { _rtB -> hdvust2xot = _rtP -> P_14 ; } else
if ( u0 < _rtP -> P_15 ) { _rtB -> hdvust2xot = _rtP -> P_15 ; } else { _rtB
-> hdvust2xot = u0 ; } u0 = ( _rtB -> fg4yinl54e [ 5 ] + _rtB -> fg4yinl54e [
6 ] ) * _rtP -> P_16 ; if ( u0 > _rtP -> P_17 ) { _rtB -> hwz4nf0l01 = _rtP
-> P_17 ; } else if ( u0 < _rtP -> P_18 ) { _rtB -> hwz4nf0l01 = _rtP -> P_18
; } else { _rtB -> hwz4nf0l01 = u0 ; } u0 = _rtP -> P_19 * _rtB -> fg4yinl54e
[ 5 ] ; if ( u0 > _rtP -> P_20 ) { _rtB -> it2xv0120p = _rtP -> P_20 ; } else
if ( u0 < _rtP -> P_21 ) { _rtB -> it2xv0120p = _rtP -> P_21 ; } else { _rtB
-> it2xv0120p = u0 ; } ssCallAccelRunBlock ( S , 4 , 97 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 4 , 98 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
mzkmlcvsnd = _rtB -> dziaii4uco [ 1 ] - _rtB -> fg4yinl54e [ 4 ] ; if ( _rtB
-> fg4yinl54e [ 3 ] > _rtP -> P_22 ) { _rtB -> g5zmjlslo1 = _rtP -> P_22 ; }
else if ( _rtB -> fg4yinl54e [ 3 ] < _rtP -> P_23 ) { _rtB -> g5zmjlslo1 =
_rtP -> P_23 ; } else { _rtB -> g5zmjlslo1 = _rtB -> fg4yinl54e [ 3 ] ; } u0
= _rtP -> P_24 * _rtB -> d4oaa5vy34 ; if ( u0 > _rtP -> P_25 ) { _rtB ->
ey51rwwxto = _rtP -> P_25 ; } else if ( u0 < _rtP -> P_26 ) { _rtB ->
ey51rwwxto = _rtP -> P_26 ; } else { _rtB -> ey51rwwxto = u0 ; } u0 = _rtP ->
P_27 * _rtB -> fg4yinl54e [ 2 ] ; if ( u0 > _rtP -> P_28 ) { _rtB ->
axim4z2wkv = _rtP -> P_28 ; } else if ( u0 < _rtP -> P_29 ) { _rtB ->
axim4z2wkv = _rtP -> P_29 ; } else { _rtB -> axim4z2wkv = u0 ; } u0 = ( _rtB
-> fg4yinl54e [ 2 ] + _rtB -> fg4yinl54e [ 1 ] ) * _rtP -> P_30 ; if ( u0 >
_rtP -> P_31 ) { _rtB -> jl5g0wl0u1 = _rtP -> P_31 ; } else if ( u0 < _rtP ->
P_32 ) { _rtB -> jl5g0wl0u1 = _rtP -> P_32 ; } else { _rtB -> jl5g0wl0u1 = u0
; } u0 = _rtP -> P_33 * _rtB -> fg4yinl54e [ 1 ] ; if ( u0 > _rtP -> P_34 ) {
_rtB -> egxnusmyri = _rtP -> P_34 ; } else if ( u0 < _rtP -> P_35 ) { _rtB ->
egxnusmyri = _rtP -> P_35 ; } else { _rtB -> egxnusmyri = u0 ; }
ssCallAccelRunBlock ( S , 4 , 110 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
nkxwllxkcu = _rtP -> P_36 * _rtB -> lvlebcf42d ; _rtB -> objdriefi4 = _rtP ->
P_37 * _rtB -> hdvust2xot ; _rtB -> hhhofhqcox = _rtP -> P_38 * _rtB ->
hwz4nf0l01 ; ssCallAccelRunBlock ( S , 4 , 114 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 116 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 117 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 118 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER (
tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { mf5tsskwnw * _rtB ;
k2thubfcsq * _rtDW ; _rtDW = ( ( k2thubfcsq * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( mf5tsskwnw * ) _ssGetModelBlockIO ( S ) ) ; _rtDW -> k4tttsuv1x = _rtB
-> fg4yinl54e [ 8 ] ; _rtDW -> kwxbgzipo4 = _rtB -> dziaii4uco [ 3 ] ; _rtDW
-> fk1exdnnfd = _rtB -> fg4yinl54e [ 4 ] ; _rtDW -> dladgm052y = _rtB ->
dziaii4uco [ 1 ] ; ssCallAccelRunBlock ( S , 4 , 10 , SS_CALL_MDL_UPDATE ) ;
UNUSED_PARAMETER ( tid ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 4028186368U ) ; ssSetChecksumVal ( S , 1 ,
2118566482U ) ; ssSetChecksumVal ( S , 2 , 1418403972U ) ; ssSetChecksumVal (
S , 3 , 2480594519U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
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
