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
_rtB = ( ( br0bjo30ls * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> in01yvxcm4 =
_rtDW -> p2o5kz3ov0 ; _rtB -> brvfkgjbtd = _rtDW -> fx2jvwkgcd ;
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
n3nux03j5o > _rtP -> P_3 ) { _rtB -> jzudrn0uol = _rtP -> P_3 ; } else if (
_rtB -> n3nux03j5o < _rtP -> P_4 ) { _rtB -> jzudrn0uol = _rtP -> P_4 ; }
else { _rtB -> jzudrn0uol = _rtB -> n3nux03j5o ; } _rtB -> fpb4q24tdx [ 0 ] =
_rtB -> jzudrn0uol ; _rtB -> fpb4q24tdx [ 1 ] = 0.0 ; _rtB -> fpb4q24tdx [ 2
] = 0.0 ; _rtDW -> kuhmcqrtwx [ 0 ] = ! ( _rtB -> fpb4q24tdx [ 0 ] == _rtDW
-> kuhmcqrtwx [ 1 ] ) ; _rtDW -> kuhmcqrtwx [ 1 ] = _rtB -> fpb4q24tdx [ 0 ]
; _rtB -> fpb4q24tdx [ 3 ] = _rtDW -> kuhmcqrtwx [ 0 ] ; _rtB -> bhbvfi5xxx =
_rtDW -> ihf2admcco ; _rtB -> fpjrhsulkp = _rtDW -> luibyjq2go ;
ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
gqaio3bm3j > _rtP -> P_8 ) { _rtB -> a2hfhesuiz = _rtP -> P_8 ; } else if (
_rtB -> gqaio3bm3j < _rtP -> P_9 ) { _rtB -> a2hfhesuiz = _rtP -> P_9 ; }
else { _rtB -> a2hfhesuiz = _rtB -> gqaio3bm3j ; } _rtB -> h10fohsusz [ 0 ] =
_rtB -> a2hfhesuiz ; _rtB -> h10fohsusz [ 1 ] = 0.0 ; _rtB -> h10fohsusz [ 2
] = 0.0 ; _rtDW -> mklbjyogld [ 0 ] = ! ( _rtB -> h10fohsusz [ 0 ] == _rtDW
-> mklbjyogld [ 1 ] ) ; _rtDW -> mklbjyogld [ 1 ] = _rtB -> h10fohsusz [ 0 ]
; _rtB -> h10fohsusz [ 3 ] = _rtDW -> mklbjyogld [ 0 ] ; ssCallAccelRunBlock
( S , 4 , 12 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 13 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 14 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 15 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 16 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 17 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 18 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 19 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> j3ypa0mbl1 = _rtP -> P_10 * _rtB ->
by2q2h5ll0 [ 14 ] ; _rtB -> bitpkdzjyj = _rtP -> P_11 * _rtB -> by2q2h5ll0 [
13 ] ; ssCallAccelRunBlock ( S , 4 , 22 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 23 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> kmqy0lb2lu
= _rtDW -> eyznma1tg2 ; _rtB -> e5mhmzezvt = _rtDW -> kxvpz5hftl ; _rtB ->
nmce3cftsf = _rtDW -> omodumqesx ; ssCallAccelRunBlock ( S , 4 , 63 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 65 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 4 , 103 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 104 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 105 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 106 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 107 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 108 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
nl530bddcv = _rtB -> by2q2h5ll0 [ 10 ] - _rtB -> by2q2h5ll0 [ 9 ] ; _rtB ->
najhc1tlea = _rtB -> jv5ct4p4lc [ 2 ] - _rtB -> jv5ct4p4lc [ 1 ] ;
ssCallAccelRunBlock ( S , 4 , 111 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
gtck23sc0v = _rtB -> by2q2h5ll0 [ 6 ] + _rtB -> by2q2h5ll0 [ 7 ] ; _rtB ->
elye40vlzn = _rtB -> by2q2h5ll0 [ 4 ] + _rtB -> by2q2h5ll0 [ 3 ] ;
ssCallAccelRunBlock ( S , 4 , 114 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER (
tid ) ; } static void mdlOutputsTID1 ( SimStruct * S , int_T tid ) {
br0bjo30ls * _rtB ; eqopz54blq * _rtP ; _rtP = ( ( eqopz54blq * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( br0bjo30ls * ) _ssGetModelBlockIO ( S ) )
; _rtB -> egwsl4aupl = _rtP -> P_2 ; _rtB -> copcp1pjqu = _rtP -> P_7 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { br0bjo30ls * _rtB ;
afav0isfr2 * _rtDW ; _rtDW = ( ( afav0isfr2 * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( br0bjo30ls * ) _ssGetModelBlockIO ( S ) ) ; _rtDW -> p2o5kz3ov0 = _rtB
-> jv5ct4p4lc [ 1 ] ; _rtDW -> fx2jvwkgcd = _rtB -> jv5ct4p4lc [ 2 ] ; _rtDW
-> ihf2admcco = _rtB -> by2q2h5ll0 [ 9 ] ; _rtDW -> luibyjq2go = _rtB ->
by2q2h5ll0 [ 10 ] ; ssCallAccelRunBlock ( S , 4 , 12 , SS_CALL_MDL_UPDATE ) ;
_rtDW -> eyznma1tg2 = _rtB -> dy2qxjwyet ; _rtDW -> kxvpz5hftl = _rtB ->
bnnjwr1zch ; _rtDW -> omodumqesx = _rtB -> n1boq1nz4n ; UNUSED_PARAMETER (
tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID1 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 3950583880U ) ; ssSetChecksumVal ( S , 1 , 1167708387U ) ;
ssSetChecksumVal ( S , 2 , 4247753868U ) ; ssSetChecksumVal ( S , 3 ,
1097666948U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
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
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID1 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
