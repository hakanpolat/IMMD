#include "__cf_HalfBridgeCapacitanceModellin.h"
#include <math.h>
#include "HalfBridgeCapacitanceModellin_acc.h"
#include "HalfBridgeCapacitanceModellin_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { po012mjauc * _rtB ;
lekc3bllao * _rtP ; omjvcygvxy * _rtDW ; _rtDW = ( ( omjvcygvxy * )
ssGetRootDWork ( S ) ) ; _rtP = ( ( lekc3bllao * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( po012mjauc * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> k1hcamhtia =
_rtDW -> ixfmswlz1z ; _rtB -> nmsr1vtoh2 = _rtDW -> pfykightns ;
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
bii1vd4ndd > _rtP -> P_2 ) { _rtB -> imies3leht = _rtP -> P_2 ; } else if (
_rtB -> bii1vd4ndd < _rtP -> P_3 ) { _rtB -> imies3leht = _rtP -> P_3 ; }
else { _rtB -> imies3leht = _rtB -> bii1vd4ndd ; } _rtB -> dunp4ygdmt [ 0 ] =
_rtB -> imies3leht ; _rtB -> dunp4ygdmt [ 1 ] = 0.0 ; _rtB -> dunp4ygdmt [ 2
] = 0.0 ; _rtDW -> hk2wjhbtyz [ 0 ] = ! ( _rtB -> dunp4ygdmt [ 0 ] == _rtDW
-> hk2wjhbtyz [ 1 ] ) ; _rtDW -> hk2wjhbtyz [ 1 ] = _rtB -> dunp4ygdmt [ 0 ]
; _rtB -> dunp4ygdmt [ 3 ] = _rtDW -> hk2wjhbtyz [ 0 ] ; _rtB -> l1nhjrbwvn =
_rtDW -> a0w3qwrsgu ; _rtB -> jfgskehivq = _rtDW -> dwsplmnwsj ;
ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
ak1acptpgw > _rtP -> P_6 ) { _rtB -> hh2mdtkk0s = _rtP -> P_6 ; } else if (
_rtB -> ak1acptpgw < _rtP -> P_7 ) { _rtB -> hh2mdtkk0s = _rtP -> P_7 ; }
else { _rtB -> hh2mdtkk0s = _rtB -> ak1acptpgw ; } _rtB -> bollqwwz4f [ 0 ] =
_rtB -> hh2mdtkk0s ; _rtB -> bollqwwz4f [ 1 ] = 0.0 ; _rtB -> bollqwwz4f [ 2
] = 0.0 ; _rtDW -> kqsgdatol1 [ 0 ] = ! ( _rtB -> bollqwwz4f [ 0 ] == _rtDW
-> kqsgdatol1 [ 1 ] ) ; _rtDW -> kqsgdatol1 [ 1 ] = _rtB -> bollqwwz4f [ 0 ]
; _rtB -> bollqwwz4f [ 3 ] = _rtDW -> kqsgdatol1 [ 0 ] ; ssCallAccelRunBlock
( S , 4 , 10 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 11 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 12 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 29 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 46 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 48 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 49 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> elmiiuba4g = _rtB -> fle1abreta [ 11 ] - _rtB -> fle1abreta [ 10
] ; _rtB -> djkzvuuxpt = _rtB -> fle1abreta [ 7 ] - _rtB -> fle1abreta [ 6 ]
; ssCallAccelRunBlock ( S , 4 , 84 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 85 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> d4a2ygw3f5
= _rtB -> fle1abreta [ 8 ] + _rtB -> fle1abreta [ 9 ] ; _rtB -> idvr4s0gia =
_rtB -> fle1abreta [ 5 ] + _rtB -> fle1abreta [ 4 ] ; ssCallAccelRunBlock ( S
, 4 , 88 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 90 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 91 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS
) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { po012mjauc * _rtB ;
omjvcygvxy * _rtDW ; _rtDW = ( ( omjvcygvxy * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( po012mjauc * ) _ssGetModelBlockIO ( S ) ) ; _rtDW -> ixfmswlz1z = _rtB
-> fle1abreta [ 6 ] ; _rtDW -> pfykightns = _rtB -> fle1abreta [ 7 ] ; _rtDW
-> a0w3qwrsgu = _rtB -> fle1abreta [ 10 ] ; _rtDW -> dwsplmnwsj = _rtB ->
fle1abreta [ 11 ] ; ssCallAccelRunBlock ( S , 4 , 10 , SS_CALL_MDL_UPDATE ) ;
UNUSED_PARAMETER ( tid ) ; } static void mdlInitializeSizes ( SimStruct * S )
{ ssSetChecksumVal ( S , 0 , 3343368711U ) ; ssSetChecksumVal ( S , 1 ,
2834706607U ) ; ssSetChecksumVal ( S , 2 , 4149860673U ) ; ssSetChecksumVal (
S , 3 , 3645628708U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
omjvcygvxy ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( po012mjauc ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
lekc3bllao ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & m3x1ho4xd4 ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
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
