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
_rtB = ( ( br0bjo30ls * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> egeb13mijv =
_rtDW -> ihf2admcco ; _rtB -> jvqyf0npbn = _rtDW -> luibyjq2go ;
ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
gqaio3bm3j > _rtP -> P_3 ) { _rtB -> fbt2uztdts = _rtP -> P_3 ; } else if (
_rtB -> gqaio3bm3j < _rtP -> P_4 ) { _rtB -> fbt2uztdts = _rtP -> P_4 ; }
else { _rtB -> fbt2uztdts = _rtB -> gqaio3bm3j ; } _rtB -> gbvi5h1ksh [ 0 ] =
_rtB -> fbt2uztdts ; _rtB -> gbvi5h1ksh [ 1 ] = 0.0 ; _rtB -> gbvi5h1ksh [ 2
] = 0.0 ; _rtDW -> ggdzvf2rxm [ 0 ] = ! ( _rtB -> gbvi5h1ksh [ 0 ] == _rtDW
-> ggdzvf2rxm [ 1 ] ) ; _rtDW -> ggdzvf2rxm [ 1 ] = _rtB -> gbvi5h1ksh [ 0 ]
; _rtB -> gbvi5h1ksh [ 3 ] = _rtDW -> ggdzvf2rxm [ 0 ] ; _rtB -> ncn1sadzmn =
_rtDW -> p2o5kz3ov0 ; _rtB -> nqqs3lir1m = _rtDW -> fx2jvwkgcd ;
ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
n3nux03j5o > _rtP -> P_8 ) { _rtB -> dm43pmkcbp = _rtP -> P_8 ; } else if (
_rtB -> n3nux03j5o < _rtP -> P_9 ) { _rtB -> dm43pmkcbp = _rtP -> P_9 ; }
else { _rtB -> dm43pmkcbp = _rtB -> n3nux03j5o ; } _rtB -> ou14dk1kvi [ 0 ] =
_rtB -> dm43pmkcbp ; _rtB -> ou14dk1kvi [ 1 ] = 0.0 ; _rtB -> ou14dk1kvi [ 2
] = 0.0 ; _rtDW -> fkbxtuyju0 [ 0 ] = ! ( _rtB -> ou14dk1kvi [ 0 ] == _rtDW
-> fkbxtuyju0 [ 1 ] ) ; _rtDW -> fkbxtuyju0 [ 1 ] = _rtB -> ou14dk1kvi [ 0 ]
; _rtB -> ou14dk1kvi [ 3 ] = _rtDW -> fkbxtuyju0 [ 0 ] ; _rtB -> pf1dwrryfa =
_rtDW -> kxvpz5hftl ; _rtB -> l25hc2gsnp [ 0 ] = _rtB -> pf1dwrryfa ; _rtB ->
l25hc2gsnp [ 1 ] = 0.0 ; _rtB -> l25hc2gsnp [ 2 ] = 0.0 ; _rtDW -> kuhmcqrtwx
[ 0 ] = ! ( _rtB -> l25hc2gsnp [ 0 ] == _rtDW -> kuhmcqrtwx [ 1 ] ) ; _rtDW
-> kuhmcqrtwx [ 1 ] = _rtB -> l25hc2gsnp [ 0 ] ; _rtB -> l25hc2gsnp [ 3 ] =
_rtDW -> kuhmcqrtwx [ 0 ] ; _rtB -> fs5zhvfu3l = _rtDW -> eyznma1tg2 ; _rtB
-> p5yhrikes3 [ 0 ] = _rtB -> fs5zhvfu3l ; _rtB -> p5yhrikes3 [ 1 ] = 0.0 ;
_rtB -> p5yhrikes3 [ 2 ] = 0.0 ; _rtDW -> mklbjyogld [ 0 ] = ! ( _rtB ->
p5yhrikes3 [ 0 ] == _rtDW -> mklbjyogld [ 1 ] ) ; _rtDW -> mklbjyogld [ 1 ] =
_rtB -> p5yhrikes3 [ 0 ] ; _rtB -> p5yhrikes3 [ 3 ] = _rtDW -> mklbjyogld [ 0
] ; _rtB -> jkbnxpicvr = _rtDW -> omodumqesx ; _rtB -> l5z1xhucjy [ 0 ] =
_rtB -> jkbnxpicvr ; _rtB -> l5z1xhucjy [ 1 ] = 0.0 ; _rtB -> l5z1xhucjy [ 2
] = 0.0 ; _rtDW -> bp3feyvuhg [ 0 ] = ! ( _rtB -> l5z1xhucjy [ 0 ] == _rtDW
-> bp3feyvuhg [ 1 ] ) ; _rtDW -> bp3feyvuhg [ 1 ] = _rtB -> l5z1xhucjy [ 0 ]
; _rtB -> l5z1xhucjy [ 3 ] = _rtDW -> bp3feyvuhg [ 0 ] ; _rtB -> lwlqvzvhwr =
_rtDW -> nqmf50oljk ; _rtB -> bwotbb5z53 [ 0 ] = _rtB -> lwlqvzvhwr ; _rtB ->
bwotbb5z53 [ 1 ] = 0.0 ; _rtB -> bwotbb5z53 [ 2 ] = 0.0 ; _rtDW -> cxufyyseoh
[ 0 ] = ! ( _rtB -> bwotbb5z53 [ 0 ] == _rtDW -> cxufyyseoh [ 1 ] ) ; _rtDW
-> cxufyyseoh [ 1 ] = _rtB -> bwotbb5z53 [ 0 ] ; _rtB -> bwotbb5z53 [ 3 ] =
_rtDW -> cxufyyseoh [ 0 ] ; _rtB -> dk2bknopa0 = _rtDW -> dfct4jdzdt ; _rtB
-> jv0f50m4jo [ 0 ] = _rtB -> dk2bknopa0 ; _rtB -> jv0f50m4jo [ 1 ] = 0.0 ;
_rtB -> jv0f50m4jo [ 2 ] = 0.0 ; _rtDW -> ikfq5upkr2 [ 0 ] = ! ( _rtB ->
jv0f50m4jo [ 0 ] == _rtDW -> ikfq5upkr2 [ 1 ] ) ; _rtDW -> ikfq5upkr2 [ 1 ] =
_rtB -> jv0f50m4jo [ 0 ] ; _rtB -> jv0f50m4jo [ 3 ] = _rtDW -> ikfq5upkr2 [ 0
] ; _rtB -> anxge0xdmn = _rtDW -> f0gdsc2o2v ; _rtB -> c2yjljbcno [ 0 ] =
_rtB -> anxge0xdmn ; _rtB -> c2yjljbcno [ 1 ] = 0.0 ; _rtB -> c2yjljbcno [ 2
] = 0.0 ; _rtDW -> h1ugov1xqc [ 0 ] = ! ( _rtB -> c2yjljbcno [ 0 ] == _rtDW
-> h1ugov1xqc [ 1 ] ) ; _rtDW -> h1ugov1xqc [ 1 ] = _rtB -> c2yjljbcno [ 0 ]
; _rtB -> c2yjljbcno [ 3 ] = _rtDW -> h1ugov1xqc [ 0 ] ; ssCallAccelRunBlock
( S , 4 , 24 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 25 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 26 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 27 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 28 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 29 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 30 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 31 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 32 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 33 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> c1wztzesm2 = _rtP -> P_16 * _rtB ->
kfxavjhu2i [ 3 ] ; _rtB -> e5r2fxd3sr = _rtP -> P_17 * _rtB -> cvnnwohswh [ 3
] ; ssCallAccelRunBlock ( S , 4 , 36 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 37 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 86 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 4 , 138 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 139 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 140 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 141 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 142 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 143 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> chwisuucil = _rtB -> kfxavjhu2i [ 2 ] - _rtB
-> ltimbjqik1 [ 9 ] ; _rtB -> lfj2yftyxi = _rtB -> cvnnwohswh [ 1 ] - _rtB ->
ltimbjqik1 [ 5 ] ; _rtB -> ihas0i3pfr = _rtB -> ltimbjqik1 [ 6 ] + _rtB ->
ltimbjqik1 [ 7 ] ; _rtB -> oi3ppmjgiz = _rtB -> ltimbjqik1 [ 3 ] + _rtB ->
ltimbjqik1 [ 2 ] ; ssCallAccelRunBlock ( S , 4 , 148 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER
( tid ) ; } static void mdlOutputsTID1 ( SimStruct * S , int_T tid ) {
br0bjo30ls * _rtB ; eqopz54blq * _rtP ; _rtP = ( ( eqopz54blq * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( br0bjo30ls * ) _ssGetModelBlockIO ( S ) )
; _rtB -> fsucpymtrj = _rtP -> P_2 ; _rtB -> ecqszzvelx = _rtP -> P_7 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { br0bjo30ls * _rtB ;
afav0isfr2 * _rtDW ; _rtDW = ( ( afav0isfr2 * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( br0bjo30ls * ) _ssGetModelBlockIO ( S ) ) ; _rtDW -> ihf2admcco = _rtB
-> ltimbjqik1 [ 9 ] ; _rtDW -> luibyjq2go = _rtB -> kfxavjhu2i [ 2 ] ; _rtDW
-> p2o5kz3ov0 = _rtB -> ltimbjqik1 [ 5 ] ; _rtDW -> fx2jvwkgcd = _rtB ->
cvnnwohswh [ 1 ] ; _rtDW -> kxvpz5hftl = _rtB -> bnnjwr1zch ; _rtDW ->
eyznma1tg2 = _rtB -> dy2qxjwyet ; _rtDW -> omodumqesx = _rtB -> n1boq1nz4n ;
_rtDW -> nqmf50oljk = _rtB -> ho3hfck4qp ; _rtDW -> dfct4jdzdt = _rtB ->
g3h5lekge1 ; _rtDW -> f0gdsc2o2v = _rtB -> n0f5ddqkjb ; ssCallAccelRunBlock (
S , 4 , 24 , SS_CALL_MDL_UPDATE ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID1 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 3146911662U ) ; ssSetChecksumVal ( S , 1 , 2888121552U ) ;
ssSetChecksumVal ( S , 2 , 1860773658U ) ; ssSetChecksumVal ( S , 3 ,
1748822809U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
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
