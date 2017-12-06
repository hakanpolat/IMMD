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
static void mdlOutputs ( SimStruct * S , int_T tid ) { mf5tsskwnw * _rtB ;
ddcfacl1ei * _rtP ; k2thubfcsq * _rtDW ; _rtDW = ( ( k2thubfcsq * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( ddcfacl1ei * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( mf5tsskwnw * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> j005oaxjqt =
_rtDW -> fk1exdnnfd ; _rtB -> mulg0w00i2 = _rtDW -> psgyjhqxra ;
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
p1be1hbiil > _rtP -> P_2 ) { _rtB -> n5jpc0wex5 = _rtP -> P_2 ; } else if (
_rtB -> p1be1hbiil < _rtP -> P_3 ) { _rtB -> n5jpc0wex5 = _rtP -> P_3 ; }
else { _rtB -> n5jpc0wex5 = _rtB -> p1be1hbiil ; } _rtB -> mep4rku20g [ 0 ] =
_rtB -> n5jpc0wex5 ; _rtB -> mep4rku20g [ 1 ] = 0.0 ; _rtB -> mep4rku20g [ 2
] = 0.0 ; _rtDW -> j1rfzotlsp [ 0 ] = ! ( _rtB -> mep4rku20g [ 0 ] == _rtDW
-> j1rfzotlsp [ 1 ] ) ; _rtDW -> j1rfzotlsp [ 1 ] = _rtB -> mep4rku20g [ 0 ]
; _rtB -> mep4rku20g [ 3 ] = _rtDW -> j1rfzotlsp [ 0 ] ; _rtB -> frfi1jw32t =
_rtDW -> k4tttsuv1x ; _rtB -> f3xre0gpil = _rtDW -> i0dg5annvh ;
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
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 13 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 50 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 52 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
d2xw4gwspf = _rtB -> ecll0l32po [ 11 ] - _rtB -> ecll0l32po [ 10 ] ; _rtB ->
lutxn2voa4 = _rtB -> ecll0l32po [ 7 ] - _rtB -> ecll0l32po [ 5 ] ;
ssCallAccelRunBlock ( S , 4 , 98 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> pan3w5z5zt
= _rtB -> ecll0l32po [ 8 ] + _rtB -> ecll0l32po [ 9 ] ; _rtB -> jl4rxnwbve =
_rtB -> ecll0l32po [ 3 ] + _rtB -> ecll0l32po [ 2 ] ; ssCallAccelRunBlock ( S
, 4 , 101 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 103 ,
SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { mf5tsskwnw * _rtB ;
k2thubfcsq * _rtDW ; _rtDW = ( ( k2thubfcsq * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( mf5tsskwnw * ) _ssGetModelBlockIO ( S ) ) ; _rtDW -> fk1exdnnfd = _rtB
-> ecll0l32po [ 5 ] ; _rtDW -> psgyjhqxra = _rtB -> ecll0l32po [ 7 ] ; _rtDW
-> k4tttsuv1x = _rtB -> ecll0l32po [ 10 ] ; _rtDW -> i0dg5annvh = _rtB ->
ecll0l32po [ 11 ] ; ssCallAccelRunBlock ( S , 4 , 10 , SS_CALL_MDL_UPDATE ) ;
UNUSED_PARAMETER ( tid ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 3706128184U ) ; ssSetChecksumVal ( S , 1 ,
2833603092U ) ; ssSetChecksumVal ( S , 2 , 851734586U ) ; ssSetChecksumVal (
S , 3 , 3508898816U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
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
