#include "__cf_InverterWFETs.h"
#include "ne_ds.h"
#include "InverterWFETs_d83d6795_1_ds_zc.h"
#include "InverterWFETs_d83d6795_1_ds_sys_struct.h"
#include "InverterWFETs_d83d6795_1_ds_externals.h"
#include "InverterWFETs_d83d6795_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T InverterWFETs_d83d6795_1_ds_zc ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t25 , NeDsMethodOutput * t26 ) { PmRealVector out ;
real_T Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; real_T t0 ; real_T t1 ; real_T
t2 ; real_T t3 ; real_T t4 ; real_T t5 ; real_T t6 ; real_T t7 ; real_T t8 ;
real_T t9 ; real_T t10 ; real_T t11 ; real_T t12 ; real_T t13 ; real_T t14 ;
real_T t15 ; real_T t16 ; real_T t17 ; real_T t18 ; real_T t19 ; real_T t20 ;
real_T t21 ; real_T t22 ; real_T t23 ; real_T X [ 123 ] ; int32_T b ; int32_T
M_idx_1 ; int32_T M_idx_5 ; int32_T M_idx_11 ; int32_T M_idx_18 ; int32_T
M_idx_25 ; int32_T M_idx_33 ; int32_T M_idx_30 ; int32_T M_idx_8 ; int32_T
M_idx_15 ; int32_T M_idx_21 ; int32_T M_idx_28 ; int32_T M_idx_2 ; int32_T
M_idx_12 ; int32_T M_idx_6 ; int32_T M_idx_13 ; int32_T M_idx_19 ; int32_T
M_idx_26 ; int32_T M_idx_34 ; M_idx_1 = t25 -> mM . mX [ 1 ] ; M_idx_2 = t25
-> mM . mX [ 2 ] ; M_idx_5 = t25 -> mM . mX [ 5 ] ; M_idx_6 = t25 -> mM . mX
[ 6 ] ; M_idx_8 = t25 -> mM . mX [ 8 ] ; M_idx_11 = t25 -> mM . mX [ 11 ] ;
M_idx_12 = t25 -> mM . mX [ 12 ] ; M_idx_13 = t25 -> mM . mX [ 13 ] ;
M_idx_15 = t25 -> mM . mX [ 15 ] ; M_idx_18 = t25 -> mM . mX [ 18 ] ;
M_idx_19 = t25 -> mM . mX [ 19 ] ; M_idx_21 = t25 -> mM . mX [ 21 ] ;
M_idx_25 = t25 -> mM . mX [ 25 ] ; M_idx_26 = t25 -> mM . mX [ 26 ] ;
M_idx_28 = t25 -> mM . mX [ 28 ] ; M_idx_30 = t25 -> mM . mX [ 30 ] ;
M_idx_33 = t25 -> mM . mX [ 33 ] ; M_idx_34 = t25 -> mM . mX [ 34 ] ; for ( b
= 0 ; b < 123 ; b ++ ) { X [ b ] = t25 -> mX . mX [ b ] ; } out = t26 -> mZC
; Gate_Driver_N_Channel_MOSFET_capacitor_DS_v = X [ 76ULL ] * 1.0E-6 + X [
14ULL ] ; t19 = ( ( ( X [ 76ULL ] * 1.0E-6 + X [ 79ULL ] * - 1.0E-6 ) + X [
75ULL ] * 1.0E-6 ) + X [ 14ULL ] ) + X [ 15ULL ] ;
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v = X [ 83ULL ] * 1.0E-6 + X [
20ULL ] ; Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 83ULL ] *
1.0E-6 + X [ 86ULL ] * - 1.0E-6 ) + X [ 82ULL ] * 1.0E-6 ) + X [ 20ULL ] ) +
X [ 21ULL ] ; Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v = X [ 90ULL ] *
1.0E-6 + X [ 26ULL ] ; t20 = ( ( ( X [ 90ULL ] * 1.0E-6 + X [ 92ULL ] * -
1.0E-6 ) + X [ 89ULL ] * 1.0E-6 ) + X [ 26ULL ] ) + X [ 27ULL ] ;
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v = X [ 97ULL ] * 1.0E-6 + X [
32ULL ] ; t21 = ( ( ( X [ 97ULL ] * 1.0E-6 + X [ 99ULL ] * - 1.0E-6 ) + X [
96ULL ] * 1.0E-6 ) + X [ 32ULL ] ) + X [ 33ULL ] ;
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v = X [ 104ULL ] * 1.0E-6 + X [
38ULL ] ; t22 = ( ( ( X [ 104ULL ] * 1.0E-6 + X [ 107ULL ] * - 1.0E-6 ) + X [
103ULL ] * 1.0E-6 ) + X [ 38ULL ] ) + X [ 39ULL ] ;
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v = X [ 111ULL ] * 1.0E-6 + X [
44ULL ] ; t23 = ( ( ( X [ 111ULL ] * 1.0E-6 + X [ 113ULL ] * - 1.0E-6 ) + X [
110ULL ] * 1.0E-6 ) + X [ 44ULL ] ) + X [ 45ULL ] ; t8 = t20 -
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; t9 = t21 -
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; t10 = t22 -
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; t11 = t23 -
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; t7 = t19 -
Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; t12 =
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v -
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; if ( ! ( M_idx_1 != 0 ) ) { t0
= - ( t7 - 1.7 ) ; } else { t0 = 0.0 ; } if ( ! ( M_idx_5 != 0 ) ) { t1 = - (
t8 - 1.7 ) ; } else { t1 = 0.0 ; } if ( ! ( M_idx_11 != 0 ) ) { t2 = - ( t9 -
1.7 ) ; } else { t2 = 0.0 ; } if ( ! ( M_idx_18 != 0 ) ) { t3 = - ( t10 - 1.7
) ; } else { t3 = 0.0 ; } if ( ! ( M_idx_25 != 0 ) ) { t4 = - ( t11 - 1.7 ) ;
} else { t4 = 0.0 ; } if ( ! ( M_idx_33 != 0 ) ) { t5 = - ( t12 - 1.7 ) ; }
else { t5 = 0.0 ; } if ( ( ! ( M_idx_1 != 0 ) ) && ( ! ( M_idx_30 != 0 ) ) )
{ t6 = ( t7 - 1.7 ) - ( - Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ) ; }
else { t6 = 0.0 ; } if ( ( ! ( M_idx_5 != 0 ) ) && ( ! ( M_idx_8 != 0 ) ) ) {
t7 = ( t8 - 1.7 ) - ( - Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ) ; }
else { t7 = 0.0 ; } if ( ( ! ( M_idx_11 != 0 ) ) && ( ! ( M_idx_15 != 0 ) ) )
{ t8 = ( t9 - 1.7 ) - ( - Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ) ; }
else { t8 = 0.0 ; } if ( ( ! ( M_idx_18 != 0 ) ) && ( ! ( M_idx_21 != 0 ) ) )
{ t9 = ( t10 - 1.7 ) - ( - Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ) ; }
else { t9 = 0.0 ; } if ( ( ! ( M_idx_25 != 0 ) ) && ( ! ( M_idx_28 != 0 ) ) )
{ t10 = ( t11 - 1.7 ) - ( - Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ) ;
} else { t10 = 0.0 ; } if ( ( ! ( M_idx_33 != 0 ) ) && ( ! ( M_idx_2 != 0 ) )
) { t11 = ( t12 - 1.7 ) - ( - Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v )
; } else { t11 = 0.0 ; } if ( ( ! ( M_idx_12 != 0 ) ) && ( M_idx_1 != 0 ) ) {
t12 = ( t19 - 1.7 ) - Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; } else {
t12 = 0.0 ; } if ( ( ! ( M_idx_6 != 0 ) ) && ( M_idx_5 != 0 ) ) { t13 = ( t20
- 1.7 ) - Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; } else { t13 = 0.0 ;
} if ( ( ! ( M_idx_13 != 0 ) ) && ( M_idx_11 != 0 ) ) { t14 = ( t21 - 1.7 ) -
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; } else { t14 = 0.0 ; } if ( (
! ( M_idx_19 != 0 ) ) && ( M_idx_18 != 0 ) ) { t15 = ( t22 - 1.7 ) -
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; } else { t15 = 0.0 ; } if ( (
! ( M_idx_26 != 0 ) ) && ( M_idx_25 != 0 ) ) { t16 = ( t23 - 1.7 ) -
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; } else { t16 = 0.0 ; } if ( (
! ( M_idx_34 != 0 ) ) && ( M_idx_33 != 0 ) ) { t17 = (
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v - 1.7 ) -
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; } else { t17 = 0.0 ; } if (
M_idx_1 != 0 ) { t18 = - ( t19 - 1.7 ) ; } else { t18 = 0.0 ; } if ( M_idx_5
!= 0 ) { t19 = - ( t20 - 1.7 ) ; } else { t19 = 0.0 ; } if ( M_idx_11 != 0 )
{ t20 = - ( t21 - 1.7 ) ; } else { t20 = 0.0 ; } if ( M_idx_18 != 0 ) { t21 =
- ( t22 - 1.7 ) ; } else { t21 = 0.0 ; } if ( M_idx_25 != 0 ) { t22 = - ( t23
- 1.7 ) ; } else { t22 = 0.0 ; } if ( M_idx_33 != 0 ) { t23 = - (
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v - 1.7 ) ; } else { t23 = 0.0 ; }
out . mX [ 0 ] = ( X [ 78ULL ] * 1.0E-6 + X [ 16ULL ] ) - 0.6 ; out . mX [ 1
] = ( X [ 85ULL ] * 1.0E-6 + X [ 22ULL ] ) - 0.6 ; out . mX [ 2 ] = ( X [
93ULL ] * 1.0E-6 + X [ 28ULL ] ) - 0.6 ; out . mX [ 3 ] = ( X [ 100ULL ] *
1.0E-6 + X [ 34ULL ] ) - 0.6 ; out . mX [ 4 ] = ( X [ 106ULL ] * 1.0E-6 + X [
40ULL ] ) - 0.6 ; out . mX [ 5 ] = ( X [ 114ULL ] * 1.0E-6 + X [ 46ULL ] ) -
0.6 ; out . mX [ 6 ] = Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; out . mX
[ 7 ] = Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; out . mX [ 8 ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; out . mX [ 9 ] =
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; out . mX [ 10 ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; out . mX [ 11 ] =
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; out . mX [ 12 ] = t0 ; out .
mX [ 13 ] = t1 ; out . mX [ 14 ] = t2 ; out . mX [ 15 ] = t3 ; out . mX [ 16
] = t4 ; out . mX [ 17 ] = t5 ; out . mX [ 18 ] = t6 ; out . mX [ 19 ] = t7 ;
out . mX [ 20 ] = t8 ; out . mX [ 21 ] = t9 ; out . mX [ 22 ] = t10 ; out .
mX [ 23 ] = t11 ; out . mX [ 24 ] = t12 ; out . mX [ 25 ] = t13 ; out . mX [
26 ] = t14 ; out . mX [ 27 ] = t15 ; out . mX [ 28 ] = t16 ; out . mX [ 29 ]
= t17 ; out . mX [ 30 ] = t18 ; out . mX [ 31 ] = t19 ; out . mX [ 32 ] = t20
; out . mX [ 33 ] = t21 ; out . mX [ 34 ] = t22 ; out . mX [ 35 ] = t23 ; (
void ) sys ; ( void ) t26 ; return 0 ; }
