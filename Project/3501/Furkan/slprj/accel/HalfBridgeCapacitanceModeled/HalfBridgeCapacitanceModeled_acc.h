#include "__cf_HalfBridgeCapacitanceModeled.h"
#ifndef RTW_HEADER_HalfBridgeCapacitanceModeled_acc_h_
#define RTW_HEADER_HalfBridgeCapacitanceModeled_acc_h_
#include <stddef.h>
#ifndef HalfBridgeCapacitanceModeled_acc_COMMON_INCLUDES_
#define HalfBridgeCapacitanceModeled_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "HalfBridgeCapacitanceModeled_acc_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T j005oaxjqt ; real_T mulg0w00i2 ; real_T n5jpc0wex5 ;
real_T kh3tfcu5vi [ 4 ] ; real_T n1evvt3xh1 ; real_T aqsilutw5q [ 4 ] ;
real_T ibdod0ubnf ; real_T cjhsld1awu [ 4 ] ; real_T b5pcyzhmlp ; real_T
d3gbnbmpk4 [ 4 ] ; real_T ogczjtsgpi ; real_T mmftbuacch ; real_T dmufbnh0sx
; real_T mdgg0wmdjj [ 4 ] ; real_T bwtou3x4g4 ; real_T gq0ucptp2p [ 4 ] ;
real_T dlpdd5jv3u ; real_T pqhjdeledm [ 4 ] ; real_T nzlrz1umrb ; real_T
dsxeyvkdjx [ 4 ] ; real_T omin4wlltj [ 72 ] ; real_T chmh3fg5od [ 6 ] ;
real_T hqpmwocbtz [ 11 ] ; real_T ofjj3lw5ty [ 3 ] ; real_T nf0teusgox ;
real_T kggm5et1g5 ; real_T oydbg4l3qo ; real_T iyzybzoobe ; real_T a3ylbyllpe
; real_T hegfsqur2j ; real_T phsn4h4sku ; real_T driqemtwwb ; real_T
b3fwmghnht ; real_T akio2bwzlt ; real_T jhh2rjacna ; real_T jtdtrm1htu ;
real_T h4ko42kr5q ; real_T lil21ygd5g ; real_T ebgpnbilse ; real_T antpa0l42b
; real_T jz2rlz1uk3 ; real_T e11rbic1fi ; real_T fbl43ucpwt ; real_T
e5z1mchaey ; real_T dci5ki2rht ; real_T j2qnvrmoqm ; real_T axu3wjezm1 ;
real_T p1be1hbiil ; real_T amxy5v1kpi ; real_T fa2ezlss1t ; real_T gp1tagw3wt
; } mf5tsskwnw ; typedef struct { real_T fk1exdnnfd ; real_T psgyjhqxra ;
real_T mo1xt51uh1 [ 2 ] ; real_T h54fxmxusj ; real_T j1rfzotlsp [ 2 ] ;
real_T grerghy41e ; real_T ivhc2koyg1 [ 2 ] ; real_T bysd0w5zrf ; real_T
ockadzinvw [ 2 ] ; real_T k4tttsuv1x ; real_T i0dg5annvh ; real_T ayvzhfjzkg
[ 2 ] ; real_T pjie2yzgii ; real_T p2qzarllpd [ 2 ] ; real_T j3ql31excc ;
real_T l44351rnt5 [ 2 ] ; real_T a44o1k1cpl ; real_T ljozhb5sim [ 2 ] ;
real_T ef2ek315pw [ 52 ] ; void * cm02ywbbmi ; void * pzngznomk1 ; void *
g3auelqpue ; void * aiod414oir ; void * g55f3cg1wt ; void * g2g2hw1but ; void
* ci1wokceqj ; void * gr32avpzjd ; void * cfxzzqbtll ; void * e413kc4nzp ;
void * lzchhoqfh5 [ 3 ] ; void * ehmkhulz2g ; void * fz0f0e0kfm ; void *
bue15emjfs ; void * ngtsgrjztu ; void * b0u1byqmnk ; void * oywvdnou2a [ 2 ]
; void * kikyu0m24e [ 8 ] ; void * ns5md23b44 ; void * e4vbiex4pm ; void *
ojncwwkx2d ; void * fz1bzjl3er ; void * pd3tu1g5q2 ; void * f3mdjc25pf ; void
* gmjg3vp3gd ; void * hliq4ipusp ; void * pwxwzz44n0 [ 8 ] ; void *
fchwhbps4f [ 8 ] ; void * bjudafs0sa [ 4 ] ; void * aw4yrtx0xo [ 8 ] ; void *
j1yi5ppdx2 [ 5 ] ; void * efwiqx1oqa ; void * dbuioewkls ; void * dfe2cvxzbz
; int_T mfb3x13kkz [ 20 ] ; boolean_T p2xxgvjvp3 ; boolean_T fch30bgbsd ;
boolean_T n254wcrgfr ; boolean_T fw05n5bu2z ; char_T dmat3tgyaa [ 4 ] ; }
k2thubfcsq ; struct ddcfacl1ei_ { real_T P_0 ; real_T P_1 ; real_T P_2 ;
real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ;
real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T
P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ;
real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T
P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ;
real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T
P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ;
real_T P_42 ; real_T P_43 ; real_T P_44 ; } ; extern ddcfacl1ei kxwe1mgi1m ;
#endif
