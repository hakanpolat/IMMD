#include "__cf_InverterWFETs.h"
#include "ne_ds.h"
#include "InverterWFETs_d83d6795_1_ds_mode.h"
#include "InverterWFETs_d83d6795_1_ds_sys_struct.h"
#include "InverterWFETs_d83d6795_1_ds_externals.h"
#include "InverterWFETs_d83d6795_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T InverterWFETs_d83d6795_1_ds_mode ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmIntVector out ;
real_T Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v ; real_T intrm_sf_mf_14 ; real_T
intrm_sf_mf_19 ; real_T intrm_sf_mf_24 ; real_T intrm_sf_mf_29 ; real_T
intrm_sf_mf_4 ; real_T intrm_sf_mf_9 ; real_T X [ 123 ] ; int32_T b ; for ( b
= 0 ; b < 123 ; b ++ ) { X [ b ] = t1 -> mX . mX [ b ] ; } out = t2 -> mMODE
; Gate_Driver_N_Channel_MOSFET_capacitor_DS_v = X [ 76ULL ] * 1.0E-6 + X [
14ULL ] ; Gate_Driver_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 76ULL ] *
1.0E-6 + X [ 79ULL ] * - 1.0E-6 ) + X [ 75ULL ] * 1.0E-6 ) + X [ 14ULL ] ) +
X [ 15ULL ] ; Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v = X [ 83ULL ] *
1.0E-6 + X [ 20ULL ] ; Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X
[ 83ULL ] * 1.0E-6 + X [ 86ULL ] * - 1.0E-6 ) + X [ 82ULL ] * 1.0E-6 ) + X [
20ULL ] ) + X [ 21ULL ] ; Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v = X [
90ULL ] * 1.0E-6 + X [ 26ULL ] ; Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v
= ( ( ( X [ 90ULL ] * 1.0E-6 + X [ 92ULL ] * - 1.0E-6 ) + X [ 89ULL ] *
1.0E-6 ) + X [ 26ULL ] ) + X [ 27ULL ] ;
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v = X [ 97ULL ] * 1.0E-6 + X [
32ULL ] ; Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 97ULL ] *
1.0E-6 + X [ 99ULL ] * - 1.0E-6 ) + X [ 96ULL ] * 1.0E-6 ) + X [ 32ULL ] ) +
X [ 33ULL ] ; Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v = X [ 104ULL ] *
1.0E-6 + X [ 38ULL ] ; Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X
[ 104ULL ] * 1.0E-6 + X [ 107ULL ] * - 1.0E-6 ) + X [ 103ULL ] * 1.0E-6 ) + X
[ 38ULL ] ) + X [ 39ULL ] ; Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v = X
[ 111ULL ] * 1.0E-6 + X [ 44ULL ] ;
Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 111ULL ] * 1.0E-6 +
X [ 113ULL ] * - 1.0E-6 ) + X [ 110ULL ] * 1.0E-6 ) + X [ 44ULL ] ) + X [
45ULL ] ; intrm_sf_mf_14 = Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v -
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; intrm_sf_mf_19 =
Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v -
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; intrm_sf_mf_24 =
Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v -
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; intrm_sf_mf_29 =
Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v -
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; intrm_sf_mf_4 =
Gate_Driver_N_Channel_MOSFET_capacitor_GS_v -
Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; intrm_sf_mf_9 =
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v -
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; out . mX [ 0 ] = ( int32_T ) (
X [ 78ULL ] * 1.0E-6 + X [ 16ULL ] > 0.6 ) ; out . mX [ 1 ] = ( int32_T ) (
Gate_Driver_N_Channel_MOSFET_capacitor_DS_v >= 0.0 ) ; out . mX [ 2 ] = (
int32_T ) ( intrm_sf_mf_9 - 1.7 <= 0.0 ) ; out . mX [ 3 ] = ( int32_T ) (
intrm_sf_mf_9 - 1.7 > - Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ) ; out
. mX [ 4 ] = ( int32_T ) ( X [ 93ULL ] * 1.0E-6 + X [ 28ULL ] > 0.6 ) ; out .
mX [ 5 ] = ( int32_T ) ( Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v >= 0.0
) ; out . mX [ 6 ] = ( int32_T ) (
Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v - 1.7 <= 0.0 ) ; out . mX [ 7 ]
= ( int32_T ) ( Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v - 1.7 >
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ) ; out . mX [ 8 ] = ( int32_T )
( intrm_sf_mf_14 - 1.7 <= 0.0 ) ; out . mX [ 9 ] = ( int32_T ) (
intrm_sf_mf_14 - 1.7 > - Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ) ; out
. mX [ 10 ] = ( int32_T ) ( X [ 100ULL ] * 1.0E-6 + X [ 34ULL ] > 0.6 ) ; out
. mX [ 11 ] = ( int32_T ) ( Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v >=
0.0 ) ; out . mX [ 12 ] = ( int32_T ) (
Gate_Driver_N_Channel_MOSFET_capacitor_GS_v - 1.7 <= 0.0 ) ; out . mX [ 13 ]
= ( int32_T ) ( Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v - 1.7 <= 0.0 ) ;
out . mX [ 14 ] = ( int32_T ) ( Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v
- 1.7 > Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ) ; out . mX [ 15 ] = (
int32_T ) ( intrm_sf_mf_19 - 1.7 <= 0.0 ) ; out . mX [ 16 ] = ( int32_T ) (
intrm_sf_mf_19 - 1.7 > - Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ) ; out
. mX [ 17 ] = ( int32_T ) ( X [ 106ULL ] * 1.0E-6 + X [ 40ULL ] > 0.6 ) ; out
. mX [ 18 ] = ( int32_T ) ( Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v >=
0.0 ) ; out . mX [ 19 ] = ( int32_T ) (
Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v - 1.7 <= 0.0 ) ; out . mX [ 20 ]
= ( int32_T ) ( Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v - 1.7 >
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ) ; out . mX [ 21 ] = ( int32_T
) ( intrm_sf_mf_24 - 1.7 <= 0.0 ) ; out . mX [ 22 ] = ( int32_T ) (
intrm_sf_mf_24 - 1.7 > - Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ) ; out
. mX [ 23 ] = ( int32_T ) ( Gate_Driver_N_Channel_MOSFET_capacitor_GS_v - 1.7
> Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ) ; out . mX [ 24 ] = ( int32_T
) ( X [ 114ULL ] * 1.0E-6 + X [ 46ULL ] > 0.6 ) ; out . mX [ 25 ] = ( int32_T
) ( Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v >= 0.0 ) ; out . mX [ 26 ] =
( int32_T ) ( Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v - 1.7 <= 0.0 ) ;
out . mX [ 27 ] = ( int32_T ) ( Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v
- 1.7 > Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ) ; out . mX [ 28 ] = (
int32_T ) ( intrm_sf_mf_29 - 1.7 <= 0.0 ) ; out . mX [ 29 ] = ( int32_T ) (
intrm_sf_mf_29 - 1.7 > - Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ) ; out
. mX [ 30 ] = ( int32_T ) ( intrm_sf_mf_4 - 1.7 <= 0.0 ) ; out . mX [ 31 ] =
( int32_T ) ( intrm_sf_mf_4 - 1.7 > -
Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ) ; out . mX [ 32 ] = ( int32_T )
( X [ 85ULL ] * 1.0E-6 + X [ 22ULL ] > 0.6 ) ; out . mX [ 33 ] = ( int32_T )
( Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v >= 0.0 ) ; out . mX [ 34 ] = (
int32_T ) ( Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v - 1.7 <= 0.0 ) ; out
. mX [ 35 ] = ( int32_T ) ( Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v -
1.7 > Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ) ; ( void ) sys ; ( void
) t2 ; return 0 ; }
