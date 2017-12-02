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
_rtDW -> fk1exdnnfd ; _rtB -> mulg0w00i2 = _rtDW -> psgyjhqxra ;
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
p1be1hbiil > _rtP -> P_2 ) { _rtB -> n5jpc0wex5 = _rtP -> P_2 ; } else if (
_rtB -> p1be1hbiil < _rtP -> P_3 ) { _rtB -> n5jpc0wex5 = _rtP -> P_3 ; }
else { _rtB -> n5jpc0wex5 = _rtB -> p1be1hbiil ; } _rtB -> kh3tfcu5vi [ 0 ] =
_rtB -> n5jpc0wex5 ; _rtB -> kh3tfcu5vi [ 1 ] = 0.0 ; _rtB -> kh3tfcu5vi [ 2
] = 0.0 ; _rtDW -> mo1xt51uh1 [ 0 ] = ! ( _rtB -> kh3tfcu5vi [ 0 ] == _rtDW
-> mo1xt51uh1 [ 1 ] ) ; _rtDW -> mo1xt51uh1 [ 1 ] = _rtB -> kh3tfcu5vi [ 0 ]
; _rtB -> kh3tfcu5vi [ 3 ] = _rtDW -> mo1xt51uh1 [ 0 ] ; _rtB -> n1evvt3xh1 =
_rtDW -> h54fxmxusj ; _rtB -> aqsilutw5q [ 0 ] = _rtB -> n1evvt3xh1 ; _rtB ->
aqsilutw5q [ 1 ] = 0.0 ; _rtB -> aqsilutw5q [ 2 ] = 0.0 ; _rtDW -> j1rfzotlsp
[ 0 ] = ! ( _rtB -> aqsilutw5q [ 0 ] == _rtDW -> j1rfzotlsp [ 1 ] ) ; _rtDW
-> j1rfzotlsp [ 1 ] = _rtB -> aqsilutw5q [ 0 ] ; _rtB -> aqsilutw5q [ 3 ] =
_rtDW -> j1rfzotlsp [ 0 ] ; _rtB -> ibdod0ubnf = _rtDW -> grerghy41e ; _rtB
-> cjhsld1awu [ 0 ] = _rtB -> ibdod0ubnf ; _rtB -> cjhsld1awu [ 1 ] = 0.0 ;
_rtB -> cjhsld1awu [ 2 ] = 0.0 ; _rtDW -> ivhc2koyg1 [ 0 ] = ! ( _rtB ->
cjhsld1awu [ 0 ] == _rtDW -> ivhc2koyg1 [ 1 ] ) ; _rtDW -> ivhc2koyg1 [ 1 ] =
_rtB -> cjhsld1awu [ 0 ] ; _rtB -> cjhsld1awu [ 3 ] = _rtDW -> ivhc2koyg1 [ 0
] ; _rtB -> b5pcyzhmlp = _rtDW -> bysd0w5zrf ; _rtB -> d3gbnbmpk4 [ 0 ] =
_rtB -> b5pcyzhmlp ; _rtB -> d3gbnbmpk4 [ 1 ] = 0.0 ; _rtB -> d3gbnbmpk4 [ 2
] = 0.0 ; _rtDW -> ockadzinvw [ 0 ] = ! ( _rtB -> d3gbnbmpk4 [ 0 ] == _rtDW
-> ockadzinvw [ 1 ] ) ; _rtDW -> ockadzinvw [ 1 ] = _rtB -> d3gbnbmpk4 [ 0 ]
; _rtB -> d3gbnbmpk4 [ 3 ] = _rtDW -> ockadzinvw [ 0 ] ; _rtB -> ogczjtsgpi =
_rtDW -> k4tttsuv1x ; _rtB -> mmftbuacch = _rtDW -> i0dg5annvh ;
ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
e5z1mchaey > _rtP -> P_9 ) { _rtB -> dmufbnh0sx = _rtP -> P_9 ; } else if (
_rtB -> e5z1mchaey < _rtP -> P_10 ) { _rtB -> dmufbnh0sx = _rtP -> P_10 ; }
else { _rtB -> dmufbnh0sx = _rtB -> e5z1mchaey ; } _rtB -> mdgg0wmdjj [ 0 ] =
_rtB -> dmufbnh0sx ; _rtB -> mdgg0wmdjj [ 1 ] = 0.0 ; _rtB -> mdgg0wmdjj [ 2
] = 0.0 ; _rtDW -> ayvzhfjzkg [ 0 ] = ! ( _rtB -> mdgg0wmdjj [ 0 ] == _rtDW
-> ayvzhfjzkg [ 1 ] ) ; _rtDW -> ayvzhfjzkg [ 1 ] = _rtB -> mdgg0wmdjj [ 0 ]
; _rtB -> mdgg0wmdjj [ 3 ] = _rtDW -> ayvzhfjzkg [ 0 ] ; _rtB -> bwtou3x4g4 =
_rtDW -> pjie2yzgii ; _rtB -> gq0ucptp2p [ 0 ] = _rtB -> bwtou3x4g4 ; _rtB ->
gq0ucptp2p [ 1 ] = 0.0 ; _rtB -> gq0ucptp2p [ 2 ] = 0.0 ; _rtDW -> p2qzarllpd
[ 0 ] = ! ( _rtB -> gq0ucptp2p [ 0 ] == _rtDW -> p2qzarllpd [ 1 ] ) ; _rtDW
-> p2qzarllpd [ 1 ] = _rtB -> gq0ucptp2p [ 0 ] ; _rtB -> gq0ucptp2p [ 3 ] =
_rtDW -> p2qzarllpd [ 0 ] ; _rtB -> dlpdd5jv3u = _rtDW -> j3ql31excc ; _rtB
-> pqhjdeledm [ 0 ] = _rtB -> dlpdd5jv3u ; _rtB -> pqhjdeledm [ 1 ] = 0.0 ;
_rtB -> pqhjdeledm [ 2 ] = 0.0 ; _rtDW -> l44351rnt5 [ 0 ] = ! ( _rtB ->
pqhjdeledm [ 0 ] == _rtDW -> l44351rnt5 [ 1 ] ) ; _rtDW -> l44351rnt5 [ 1 ] =
_rtB -> pqhjdeledm [ 0 ] ; _rtB -> pqhjdeledm [ 3 ] = _rtDW -> l44351rnt5 [ 0
] ; _rtB -> nzlrz1umrb = _rtDW -> a44o1k1cpl ; _rtB -> dsxeyvkdjx [ 0 ] =
_rtB -> nzlrz1umrb ; _rtB -> dsxeyvkdjx [ 1 ] = 0.0 ; _rtB -> dsxeyvkdjx [ 2
] = 0.0 ; _rtDW -> ljozhb5sim [ 0 ] = ! ( _rtB -> dsxeyvkdjx [ 0 ] == _rtDW
-> ljozhb5sim [ 1 ] ) ; _rtDW -> ljozhb5sim [ 1 ] = _rtB -> dsxeyvkdjx [ 0 ]
; _rtB -> dsxeyvkdjx [ 3 ] = _rtDW -> ljozhb5sim [ 0 ] ; ssCallAccelRunBlock
( S , 4 , 22 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 23 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 24 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 33 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 34 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 51 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 65 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 66 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 4 , 84 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 120 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
nf0teusgox = _rtB -> ofjj3lw5ty [ 1 ] - _rtB -> hqpmwocbtz [ 8 ] ; _rtB ->
kggm5et1g5 = _rtB -> chmh3fg5od [ 3 ] - _rtB -> hqpmwocbtz [ 4 ] ; _rtB ->
oydbg4l3qo = _rtB -> hqpmwocbtz [ 5 ] + _rtB -> hqpmwocbtz [ 6 ] ; _rtB ->
iyzybzoobe = _rtB -> hqpmwocbtz [ 2 ] + _rtB -> hqpmwocbtz [ 1 ] ;
ssCallAccelRunBlock ( S , 4 , 125 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
a3ylbyllpe = _rtB -> ofjj3lw5ty [ 1 ] - _rtB -> hqpmwocbtz [ 8 ] ; if ( _rtB
-> hqpmwocbtz [ 7 ] > _rtP -> P_14 ) { _rtB -> hegfsqur2j = _rtP -> P_14 ; }
else if ( _rtB -> hqpmwocbtz [ 7 ] < _rtP -> P_15 ) { _rtB -> hegfsqur2j =
_rtP -> P_15 ; } else { _rtB -> hegfsqur2j = _rtB -> hqpmwocbtz [ 7 ] ; } u0
= _rtP -> P_16 * _rtB -> ofjj3lw5ty [ 0 ] ; if ( u0 > _rtP -> P_17 ) { _rtB
-> phsn4h4sku = _rtP -> P_17 ; } else if ( u0 < _rtP -> P_18 ) { _rtB ->
phsn4h4sku = _rtP -> P_18 ; } else { _rtB -> phsn4h4sku = u0 ; } u0 = _rtP ->
P_19 * _rtB -> hqpmwocbtz [ 6 ] ; if ( u0 > _rtP -> P_20 ) { _rtB ->
driqemtwwb = _rtP -> P_20 ; } else if ( u0 < _rtP -> P_21 ) { _rtB ->
driqemtwwb = _rtP -> P_21 ; } else { _rtB -> driqemtwwb = u0 ; } u0 = ( _rtB
-> hqpmwocbtz [ 5 ] + _rtB -> hqpmwocbtz [ 6 ] ) * _rtP -> P_22 ; if ( u0 >
_rtP -> P_23 ) { _rtB -> b3fwmghnht = _rtP -> P_23 ; } else if ( u0 < _rtP ->
P_24 ) { _rtB -> b3fwmghnht = _rtP -> P_24 ; } else { _rtB -> b3fwmghnht = u0
; } u0 = _rtP -> P_25 * _rtB -> hqpmwocbtz [ 5 ] ; if ( u0 > _rtP -> P_26 ) {
_rtB -> akio2bwzlt = _rtP -> P_26 ; } else if ( u0 < _rtP -> P_27 ) { _rtB ->
akio2bwzlt = _rtP -> P_27 ; } else { _rtB -> akio2bwzlt = u0 ; }
ssCallAccelRunBlock ( S , 4 , 137 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 138 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
jhh2rjacna = _rtB -> chmh3fg5od [ 3 ] - _rtB -> hqpmwocbtz [ 4 ] ; if ( _rtB
-> hqpmwocbtz [ 3 ] > _rtP -> P_28 ) { _rtB -> jtdtrm1htu = _rtP -> P_28 ; }
else if ( _rtB -> hqpmwocbtz [ 3 ] < _rtP -> P_29 ) { _rtB -> jtdtrm1htu =
_rtP -> P_29 ; } else { _rtB -> jtdtrm1htu = _rtB -> hqpmwocbtz [ 3 ] ; } u0
= _rtP -> P_30 * _rtB -> chmh3fg5od [ 1 ] ; if ( u0 > _rtP -> P_31 ) { _rtB
-> h4ko42kr5q = _rtP -> P_31 ; } else if ( u0 < _rtP -> P_32 ) { _rtB ->
h4ko42kr5q = _rtP -> P_32 ; } else { _rtB -> h4ko42kr5q = u0 ; } u0 = _rtP ->
P_33 * _rtB -> hqpmwocbtz [ 2 ] ; if ( u0 > _rtP -> P_34 ) { _rtB ->
lil21ygd5g = _rtP -> P_34 ; } else if ( u0 < _rtP -> P_35 ) { _rtB ->
lil21ygd5g = _rtP -> P_35 ; } else { _rtB -> lil21ygd5g = u0 ; } u0 = ( _rtB
-> hqpmwocbtz [ 2 ] + _rtB -> hqpmwocbtz [ 1 ] ) * _rtP -> P_36 ; if ( u0 >
_rtP -> P_37 ) { _rtB -> ebgpnbilse = _rtP -> P_37 ; } else if ( u0 < _rtP ->
P_38 ) { _rtB -> ebgpnbilse = _rtP -> P_38 ; } else { _rtB -> ebgpnbilse = u0
; } u0 = _rtP -> P_39 * _rtB -> hqpmwocbtz [ 1 ] ; if ( u0 > _rtP -> P_40 ) {
_rtB -> antpa0l42b = _rtP -> P_40 ; } else if ( u0 < _rtP -> P_41 ) { _rtB ->
antpa0l42b = _rtP -> P_41 ; } else { _rtB -> antpa0l42b = u0 ; }
ssCallAccelRunBlock ( S , 4 , 150 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
jz2rlz1uk3 = _rtP -> P_42 * _rtB -> phsn4h4sku ; _rtB -> e11rbic1fi = _rtP ->
P_43 * _rtB -> driqemtwwb ; _rtB -> fbl43ucpwt = _rtP -> P_44 * _rtB ->
b3fwmghnht ; ssCallAccelRunBlock ( S , 4 , 154 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 156 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 157 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 158 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER (
tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { mf5tsskwnw * _rtB ;
k2thubfcsq * _rtDW ; _rtDW = ( ( k2thubfcsq * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( mf5tsskwnw * ) _ssGetModelBlockIO ( S ) ) ; _rtDW -> fk1exdnnfd = _rtB
-> hqpmwocbtz [ 4 ] ; _rtDW -> psgyjhqxra = _rtB -> chmh3fg5od [ 3 ] ; _rtDW
-> h54fxmxusj = _rtB -> fa2ezlss1t ; _rtDW -> grerghy41e = _rtB -> amxy5v1kpi
; _rtDW -> bysd0w5zrf = _rtB -> gp1tagw3wt ; _rtDW -> k4tttsuv1x = _rtB ->
hqpmwocbtz [ 8 ] ; _rtDW -> i0dg5annvh = _rtB -> ofjj3lw5ty [ 1 ] ; _rtDW ->
pjie2yzgii = _rtB -> j2qnvrmoqm ; _rtDW -> j3ql31excc = _rtB -> axu3wjezm1 ;
_rtDW -> a44o1k1cpl = _rtB -> dci5ki2rht ; ssCallAccelRunBlock ( S , 4 , 22 ,
SS_CALL_MDL_UPDATE ) ; UNUSED_PARAMETER ( tid ) ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 2407172958U
) ; ssSetChecksumVal ( S , 1 , 1537738080U ) ; ssSetChecksumVal ( S , 2 ,
3438805034U ) ; ssSetChecksumVal ( S , 3 , 265910301U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.7" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( k2thubfcsq ) ) { ssSetErrorStatus ( S ,
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
