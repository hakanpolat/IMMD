#include "__cf_InverterWFETs.h"
#include "ne_ds.h"
#include "InverterWFETs_d83d6795_1_ds_obs_act.h"
#include "InverterWFETs_d83d6795_1_ds_sys_struct.h"
#include "InverterWFETs_d83d6795_1_ds_externals.h"
#include "InverterWFETs_d83d6795_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T InverterWFETs_d83d6795_1_ds_obs_act ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t117 , NeDsMethodOutput * t118 ) { PmRealVector
out ; real_T Capacitor_i ; real_T Capacitor_n_v ; real_T Capacitor_p_v ;
real_T Capacitor1_i ; real_T Capacitor1_n_v ; real_T Capacitor1_p_v ; real_T
Capacitor2_i ; real_T Capacitor2_n_v ; real_T Capacitor2_p_v ; real_T
Gate_Driver_Controlled_Voltage_Source_n_v ; real_T
Gate_Driver_Controlled_Voltage_Source_p_v ; real_T
Gate_Driver_Current_Measure_Current_Sensor1_I ; real_T
Gate_Driver_Current_Measure_Current_Sensor1_n_v ; real_T
Gate_Driver_Diode_diode_i ; real_T
Gate_Driver_Diode_diode_junctionCapacitance_p_v ; real_T
Gate_Driver_Diode_diode_junctionCapacitance_v ; real_T
Gate_Driver_Inductor_n_v ; real_T
Gate_Driver_N_Channel_MOSFET_capacitor_DS_n_v ; real_T
Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver_N_Channel_MOSFET_capacitor_GD_p_v ; real_T
Gate_Driver_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver1_Controlled_Voltage_Source_n_v ; real_T
Gate_Driver1_Controlled_Voltage_Source_p_v ; real_T
Gate_Driver1_Current_Measure_Current_Sensor1_I ; real_T
Gate_Driver1_Current_Measure_Current_Sensor1_n_v ; real_T
Gate_Driver1_Diode_diode_i ; real_T
Gate_Driver1_Diode_diode_junctionCapacitance_p_v ; real_T
Gate_Driver1_Diode_diode_junctionCapacitance_v ; real_T
Gate_Driver1_Inductor_n_v ; real_T
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_n_v ; real_T
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver1_N_Channel_MOSFET_capacitor_GD_p_v ; real_T
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver2_Controlled_Voltage_Source_n_v ; real_T
Gate_Driver2_Controlled_Voltage_Source_p_v ; real_T
Gate_Driver2_Current_Measure_Current_Sensor1_I ; real_T
Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; real_T
Gate_Driver2_Diode_diode_i ; real_T
Gate_Driver2_Diode_diode_junctionCapacitance_p_v ; real_T
Gate_Driver2_Diode_diode_junctionCapacitance_v ; real_T
Gate_Driver2_Inductor_n_v ; real_T
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_n_v ; real_T
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_p_v ; real_T
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver3_Controlled_Voltage_Source_n_v ; real_T
Gate_Driver3_Controlled_Voltage_Source_p_v ; real_T
Gate_Driver3_Current_Measure_Current_Sensor1_I ; real_T
Gate_Driver3_Current_Measure_Current_Sensor1_n_v ; real_T
Gate_Driver3_Diode_diode_i ; real_T
Gate_Driver3_Diode_diode_junctionCapacitance_p_v ; real_T
Gate_Driver3_Diode_diode_junctionCapacitance_v ; real_T
Gate_Driver3_Inductor_n_v ; real_T
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_n_v ; real_T
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_p_v ; real_T
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver4_Controlled_Voltage_Source_n_v ; real_T
Gate_Driver4_Controlled_Voltage_Source_p_v ; real_T
Gate_Driver4_Current_Measure_Current_Sensor1_I ; real_T
Gate_Driver4_Current_Measure_Current_Sensor1_n_v ; real_T
Gate_Driver4_Diode_diode_i ; real_T
Gate_Driver4_Diode_diode_junctionCapacitance_p_v ; real_T
Gate_Driver4_Diode_diode_junctionCapacitance_v ; real_T
Gate_Driver4_Inductor_n_v ; real_T
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_n_v ; real_T
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver4_N_Channel_MOSFET_capacitor_GD_p_v ; real_T
Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v ; real_T
Gate_Driver5_Controlled_Voltage_Source_n_v ; real_T
Gate_Driver5_Controlled_Voltage_Source_p_v ; real_T
Gate_Driver5_Current_Measure_Current_Sensor1_I ; real_T
Gate_Driver5_Current_Measure_Current_Sensor1_n_v ; real_T
Gate_Driver5_Diode_diode_i ; real_T
Gate_Driver5_Diode_diode_junctionCapacitance_p_v ; real_T
Gate_Driver5_Diode_diode_junctionCapacitance_v ; real_T
Gate_Driver5_Inductor_n_v ; real_T
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_n_v ; real_T
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_p_v ; real_T
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; real_T
Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v ; real_T Inductor_v ; real_T
Inductor1_v ; real_T Inductor10_n_v ; real_T Inductor11_n_v ; real_T
Inductor11_p_v ; real_T Inductor12_p_v ; real_T Inductor13_v ; real_T
Inductor14_p_v ; real_T Inductor15_v ; real_T Inductor16_p_v ; real_T
Inductor17_v ; real_T Inductor2_v ; real_T Inductor3_v ; real_T Inductor4_v ;
real_T Inductor5_v ; real_T Inductor6_n_v ; real_T Inductor7_n_v ; real_T
Inductor8_n_v ; real_T Inductor9_n_v ; real_T
R_L_Load_Current_Measure2_Current_Sensor1_I ; real_T
R_L_Load_Current_Measure5_Current_Sensor1_I ; real_T R_L_Load_Inductor_p_v ;
real_T t0 [ 1076 ] ; real_T t4 ; real_T t5 ; real_T t6 ; real_T t8 ; real_T
t9 ; real_T t10 ; real_T t11 ; real_T t12 ; real_T t14 ; real_T t15 ; real_T
t16 ; real_T t18 ; real_T t19 ; real_T t20 ; real_T t21 ; real_T t22 ; real_T
t24 ; real_T t25 ; real_T t26 ; real_T t28 ; real_T t29 ; real_T t30 ; real_T
t31 ; real_T t32 ; real_T t34 ; real_T t35 ; real_T t36 ; real_T t38 ; real_T
t39 ; real_T t40 ; real_T t41 ; real_T t42 ; real_T t44 ; real_T t45 ; real_T
t46 ; real_T t48 ; real_T t49 ; real_T t50 ; real_T t51 ; real_T t52 ; real_T
t54 ; real_T t55 ; real_T t56 ; real_T t58 ; real_T t59 ; real_T t60 ; real_T
t61 ; real_T t62 ; real_T t63 ; real_T t64 ; real_T t65 ; real_T t66 ; real_T
t67 ; real_T t68 ; real_T t69 ; real_T t70 ; real_T t71 ; real_T t72 ; real_T
t73 ; real_T t74 ; real_T t75 ; real_T t77 ; real_T t78 ; real_T t79 ; real_T
t80 ; real_T t81 ; real_T t82 ; real_T t83 ; real_T t84 ; real_T t85 ; real_T
t86 ; real_T t87 ; real_T t91 ; real_T t92 ; real_T t93 ; real_T t96 ; real_T
t113 ; real_T t114 ; real_T t115 ; real_T X [ 123 ] ; int32_T b ; real_T
U_idx_0 ; real_T U_idx_1 ; real_T U_idx_2 ; real_T U_idx_3 ; real_T U_idx_4 ;
real_T U_idx_5 ; U_idx_0 = t117 -> mU . mX [ 0 ] ; U_idx_1 = t117 -> mU . mX
[ 1 ] ; U_idx_2 = t117 -> mU . mX [ 2 ] ; U_idx_3 = t117 -> mU . mX [ 3 ] ;
U_idx_4 = t117 -> mU . mX [ 4 ] ; U_idx_5 = t117 -> mU . mX [ 5 ] ; for ( b =
0 ; b < 123 ; b ++ ) { X [ b ] = t117 -> mX . mX [ b ] ; } out = t118 ->
mOBS_ACT ; Capacitor_i = X [ 64ULL ] * 1.0E-9 + X [ 0ULL ] ; Capacitor_n_v =
( X [ 1ULL ] * 0.001422 + X [ 65ULL ] * 1.000000000001422 ) + X [ 64ULL ] ;
Capacitor_p_v = ( ( ( X [ 0ULL ] * 0.0211 + X [ 1ULL ] * 0.001422 ) + X [
64ULL ] * 1.0000000000211 ) + X [ 65ULL ] * 1.000000000001422 ) + X [ 2ULL ]
; Capacitor1_i = X [ 66ULL ] * 1.0E-9 + X [ 3ULL ] ; Capacitor1_n_v = ( X [
4ULL ] * 0.000662 + X [ 67ULL ] * 1.0000000000006619 ) + X [ 66ULL ] ;
Capacitor1_p_v = ( ( ( ( ( ( ( X [ 0ULL ] * 0.0211 + X [ 5ULL ] * - 0.001037
) + X [ 1ULL ] * 0.001422 ) + X [ 6ULL ] * 0.000611 ) + X [ 64ULL ] *
1.0000000000211 ) + X [ 68ULL ] * - 1.0000000000010369 ) + X [ 65ULL ] *
1.000000000001422 ) + X [ 69ULL ] * 1.0000000000006111 ) + X [ 2ULL ] ;
Capacitor2_i = X [ 70ULL ] * 1.0E-9 + X [ 8ULL ] ; Capacitor2_n_v = ( X [
9ULL ] * 0.000595 + X [ 71ULL ] * 1.0000000000005951 ) + X [ 70ULL ] ;
Capacitor2_p_v = ( ( ( ( ( ( ( X [ 10ULL ] * 0.000867 + X [ 0ULL ] * 0.0211 )
+ X [ 5ULL ] * - 0.001037 ) + X [ 1ULL ] * 0.001422 ) + X [ 72ULL ] *
1.0000000000008671 ) + X [ 64ULL ] * 1.0000000000211 ) + X [ 68ULL ] * -
1.0000000000010369 ) + X [ 65ULL ] * 1.000000000001422 ) + X [ 2ULL ] ;
Gate_Driver_Controlled_Voltage_Source_n_v = ( ( ( ( X [ 13ULL ] * 0.0001 + -
X [ 14ULL ] ) + X [ 74ULL ] * 1.0000000000000002E-13 ) + X [ 76ULL ] * -
1.0E-6 ) + X [ 75ULL ] * - 0.0001 ) + X [ 77ULL ] ;
Gate_Driver_Controlled_Voltage_Source_p_v = ( ( ( ( ( X [ 13ULL ] * 0.0001 +
- X [ 14ULL ] ) + X [ 74ULL ] * 1.0000000000000002E-13 ) + X [ 76ULL ] * -
1.0E-6 ) + X [ 75ULL ] * - 0.0001 ) + U_idx_0 ) + X [ 77ULL ] ;
Gate_Driver_Current_Measure_Current_Sensor1_I = - X [ 13ULL ] + X [ 74ULL ] *
- 1.0E-9 ; Gate_Driver_Current_Measure_Current_Sensor1_n_v = ( X [ 13ULL ] *
- 0.00010000000000000005 + X [ 74ULL ] * - 1.0000000000001 ) + X [ 77ULL ] ;
Gate_Driver_Diode_diode_i = ( ( ( ( ( ( ( X [ 13ULL ] * 1.0E-5 + X [ 14ULL ]
* - 0.1 ) + X [ 15ULL ] * - 0.1 ) + - X [ 78ULL ] ) + X [ 74ULL ] *
1.0000000000000002E-14 ) + X [ 76ULL ] * - 1.0E-7 ) + X [ 79ULL ] * 1.0E-7 )
+ X [ 75ULL ] * - 1.0001101000000001 ) + U_idx_0 * 0.1 ;
Gate_Driver_Diode_diode_junctionCapacitance_p_v = ( ( ( ( ( ( ( X [ 13ULL ] *
0.0001 + - X [ 14ULL ] ) + X [ 78ULL ] * 1.0E-6 ) + X [ 74ULL ] *
1.0000000000000002E-13 ) + X [ 76ULL ] * - 1.0E-6 ) + X [ 75ULL ] * - 0.0001
) + U_idx_0 ) + X [ 16ULL ] ) + X [ 77ULL ] ;
Gate_Driver_Diode_diode_junctionCapacitance_v = X [ 78ULL ] * 1.0E-6 + X [
16ULL ] ; t4 = X [ 73ULL ] * 1.0E-9 + X [ 12ULL ] ; Gate_Driver_Inductor_n_v
= ( ( ( ( ( X [ 13ULL ] * 0.0001 + - X [ 14ULL ] ) + - X [ 73ULL ] ) + X [
74ULL ] * 1.0000000000000002E-13 ) + X [ 76ULL ] * - 1.0E-6 ) + X [ 75ULL ] *
- 0.0001 ) + X [ 77ULL ] ; t5 = ( X [ 13ULL ] * - 0.0001 + X [ 74ULL ] * -
1.0000000000000002E-13 ) + X [ 77ULL ] ; t6 = ( ( X [ 79ULL ] * - 1.0E-6 + X
[ 75ULL ] * 0.001001 ) + X [ 77ULL ] ) + X [ 15ULL ] ;
Gate_Driver_N_Channel_MOSFET_capacitor_DS_n_v = ( - X [ 14ULL ] + X [ 76ULL ]
* - 1.0E-6 ) + X [ 77ULL ] ; Gate_Driver_N_Channel_MOSFET_capacitor_DS_v = X
[ 76ULL ] * 1.0E-6 + X [ 14ULL ] ;
Gate_Driver_N_Channel_MOSFET_capacitor_GD_p_v = ( ( X [ 79ULL ] * - 1.0E-6 +
X [ 75ULL ] * 1.0E-6 ) + X [ 77ULL ] ) + X [ 15ULL ] ;
Gate_Driver_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 76ULL ] * 1.0E-6 + X
[ 79ULL ] * - 1.0E-6 ) + X [ 75ULL ] * 1.0E-6 ) + X [ 14ULL ] ) + X [ 15ULL ]
; t8 = ( ( ( - X [ 13ULL ] + X [ 74ULL ] * - 1.0E-9 ) + - X [ 76ULL ] ) + - X
[ 79ULL ] ) + X [ 75ULL ] ; t9 = ( X [ 74ULL ] * 1.0E-9 + - X [ 75ULL ] ) + X
[ 13ULL ] ; t10 = ( ( ( ( ( ( X [ 13ULL ] * 1.0E-5 + X [ 14ULL ] * - 0.1 ) +
X [ 15ULL ] * - 0.1 ) + X [ 74ULL ] * 1.0000000000000002E-14 ) + X [ 76ULL ]
* - 1.0E-7 ) + X [ 79ULL ] * 1.0E-7 ) + X [ 75ULL ] * -
0.00011009999999998899 ) + U_idx_0 * 0.1 ; t11 = ( ( ( ( ( ( X [ 13ULL ] * -
1.0E-5 + X [ 14ULL ] * 0.1 ) + X [ 15ULL ] * 0.1 ) + X [ 74ULL ] * -
1.0000000000000002E-14 ) + X [ 76ULL ] * 1.0E-7 ) + X [ 79ULL ] * - 1.0E-7 )
+ X [ 75ULL ] * 1.0001101000000001 ) + U_idx_0 * - 0.1 ; t12 = - ( t5 -
Gate_Driver_Controlled_Voltage_Source_n_v ) / - 1.0 ;
Gate_Driver1_Controlled_Voltage_Source_n_v = ( ( ( ( X [ 19ULL ] * 0.0001 + -
X [ 20ULL ] ) + X [ 81ULL ] * 1.0000000000000002E-13 ) + X [ 83ULL ] * -
1.0E-6 ) + X [ 82ULL ] * - 0.0001 ) + X [ 84ULL ] ;
Gate_Driver1_Controlled_Voltage_Source_p_v = ( ( ( ( ( X [ 19ULL ] * 0.0001 +
- X [ 20ULL ] ) + X [ 81ULL ] * 1.0000000000000002E-13 ) + X [ 83ULL ] * -
1.0E-6 ) + X [ 82ULL ] * - 0.0001 ) + U_idx_1 ) + X [ 84ULL ] ;
Gate_Driver1_Current_Measure_Current_Sensor1_I = - X [ 19ULL ] + X [ 81ULL ]
* - 1.0E-9 ; Gate_Driver1_Current_Measure_Current_Sensor1_n_v = ( X [ 19ULL ]
* - 0.00010000000000000005 + X [ 81ULL ] * - 1.0000000000001001 ) + X [ 84ULL
] ; Gate_Driver1_Diode_diode_i = ( ( ( ( ( ( ( X [ 19ULL ] * 1.0E-5 + X [
20ULL ] * - 0.1 ) + X [ 21ULL ] * - 0.1 ) + - X [ 85ULL ] ) + X [ 81ULL ] *
1.0000000000000002E-14 ) + X [ 83ULL ] * - 1.0E-7 ) + X [ 86ULL ] * 1.0E-7 )
+ X [ 82ULL ] * - 1.0001101000000001 ) + U_idx_1 * 0.1 ;
Gate_Driver1_Diode_diode_junctionCapacitance_p_v = ( ( ( ( ( ( ( X [ 19ULL ]
* 0.0001 + - X [ 20ULL ] ) + X [ 85ULL ] * 1.0E-6 ) + X [ 81ULL ] *
1.0000000000000002E-13 ) + X [ 83ULL ] * - 1.0E-6 ) + X [ 82ULL ] * - 0.0001
) + U_idx_1 ) + X [ 22ULL ] ) + X [ 84ULL ] ;
Gate_Driver1_Diode_diode_junctionCapacitance_v = X [ 85ULL ] * 1.0E-6 + X [
22ULL ] ; t14 = X [ 80ULL ] * 1.0E-9 + X [ 18ULL ] ;
Gate_Driver1_Inductor_n_v = ( ( ( ( ( X [ 19ULL ] * 0.0001 + - X [ 20ULL ] )
+ - X [ 80ULL ] ) + X [ 81ULL ] * 1.0000000000000002E-13 ) + X [ 83ULL ] * -
1.0E-6 ) + X [ 82ULL ] * - 0.0001 ) + X [ 84ULL ] ; t15 = ( X [ 19ULL ] * -
0.0001 + X [ 81ULL ] * - 1.0000000000000002E-13 ) + X [ 84ULL ] ; t16 = ( ( X
[ 86ULL ] * - 1.0E-6 + X [ 82ULL ] * 0.001001 ) + X [ 84ULL ] ) + X [ 21ULL ]
; Gate_Driver1_N_Channel_MOSFET_capacitor_DS_n_v = ( - X [ 20ULL ] + X [
83ULL ] * - 1.0E-6 ) + X [ 84ULL ] ;
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v = X [ 83ULL ] * 1.0E-6 + X [
20ULL ] ; Gate_Driver1_N_Channel_MOSFET_capacitor_GD_p_v = ( ( X [ 86ULL ] *
- 1.0E-6 + X [ 82ULL ] * 1.0E-6 ) + X [ 84ULL ] ) + X [ 21ULL ] ;
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 83ULL ] * 1.0E-6 + X
[ 86ULL ] * - 1.0E-6 ) + X [ 82ULL ] * 1.0E-6 ) + X [ 20ULL ] ) + X [ 21ULL ]
; t18 = ( ( ( - X [ 19ULL ] + X [ 81ULL ] * - 1.0E-9 ) + - X [ 83ULL ] ) + -
X [ 86ULL ] ) + X [ 82ULL ] ; t19 = ( X [ 81ULL ] * 1.0E-9 + - X [ 82ULL ] )
+ X [ 19ULL ] ; t20 = ( ( ( ( ( ( X [ 19ULL ] * 1.0E-5 + X [ 20ULL ] * - 0.1
) + X [ 21ULL ] * - 0.1 ) + X [ 81ULL ] * 1.0000000000000002E-14 ) + X [
83ULL ] * - 1.0E-7 ) + X [ 86ULL ] * 1.0E-7 ) + X [ 82ULL ] * -
0.00011009999999998899 ) + U_idx_1 * 0.1 ; t21 = ( ( ( ( ( ( X [ 19ULL ] * -
1.0E-5 + X [ 20ULL ] * 0.1 ) + X [ 21ULL ] * 0.1 ) + X [ 81ULL ] * -
1.0000000000000002E-14 ) + X [ 83ULL ] * 1.0E-7 ) + X [ 86ULL ] * - 1.0E-7 )
+ X [ 82ULL ] * 1.0001101000000001 ) + U_idx_1 * - 0.1 ; t22 = - ( t15 -
Gate_Driver1_Controlled_Voltage_Source_n_v ) / - 1.0 ;
Gate_Driver2_Controlled_Voltage_Source_n_v = ( ( ( ( ( ( X [ 25ULL ] * 0.0001
+ - X [ 26ULL ] ) + - X [ 27ULL ] ) + X [ 88ULL ] * 1.0000000000000002E-13 )
+ X [ 90ULL ] * - 1.0E-6 ) + X [ 92ULL ] * 1.0E-6 ) + X [ 89ULL ] * -
0.000101 ) + X [ 91ULL ] ; Gate_Driver2_Controlled_Voltage_Source_p_v = ( ( (
( ( ( ( X [ 25ULL ] * 0.0001 + - X [ 26ULL ] ) + - X [ 27ULL ] ) + X [ 88ULL
] * 1.0000000000000002E-13 ) + X [ 90ULL ] * - 1.0E-6 ) + X [ 92ULL ] *
1.0E-6 ) + X [ 89ULL ] * - 0.000101 ) + U_idx_2 ) + X [ 91ULL ] ;
Gate_Driver2_Current_Measure_Current_Sensor1_I = - X [ 25ULL ] + X [ 88ULL ]
* - 1.0E-9 ; Gate_Driver2_Current_Measure_Current_Sensor1_n_v = ( ( ( ( X [
25ULL ] * - 0.00010000000000000002 + - X [ 27ULL ] ) + X [ 88ULL ] * -
1.0000000000001 ) + X [ 92ULL ] * 1.0E-6 ) + X [ 89ULL ] * - 1.0E-6 ) + X [
91ULL ] ; Gate_Driver2_Diode_diode_i = ( ( ( ( ( ( ( X [ 25ULL ] * 1.0E-5 + X
[ 26ULL ] * - 0.1 ) + X [ 27ULL ] * - 0.1 ) + - X [ 93ULL ] ) + X [ 88ULL ] *
1.0000000000000002E-14 ) + X [ 90ULL ] * - 1.0E-7 ) + X [ 92ULL ] * 1.0E-7 )
+ X [ 89ULL ] * - 1.0001101 ) + U_idx_2 * 0.1 ;
Gate_Driver2_Diode_diode_junctionCapacitance_p_v = ( ( ( ( ( ( ( ( ( X [
25ULL ] * 0.0001 + - X [ 26ULL ] ) + - X [ 27ULL ] ) + X [ 93ULL ] * 1.0E-6 )
+ X [ 88ULL ] * 1.0000000000000002E-13 ) + X [ 90ULL ] * - 1.0E-6 ) + X [
92ULL ] * 1.0E-6 ) + X [ 89ULL ] * - 0.000101 ) + U_idx_2 ) + X [ 28ULL ] ) +
X [ 91ULL ] ; Gate_Driver2_Diode_diode_junctionCapacitance_v = X [ 93ULL ] *
1.0E-6 + X [ 28ULL ] ; t24 = X [ 87ULL ] * 1.0E-9 + X [ 24ULL ] ;
Gate_Driver2_Inductor_n_v = ( ( ( ( ( ( ( X [ 25ULL ] * 0.0001 + - X [ 26ULL
] ) + - X [ 27ULL ] ) + - X [ 87ULL ] ) + X [ 88ULL ] *
1.0000000000000002E-13 ) + X [ 90ULL ] * - 1.0E-6 ) + X [ 92ULL ] * 1.0E-6 )
+ X [ 89ULL ] * - 0.000101 ) + X [ 91ULL ] ; t25 = ( ( ( ( X [ 25ULL ] * -
0.0001 + - X [ 27ULL ] ) + X [ 88ULL ] * - 1.0000000000000002E-13 ) + X [
92ULL ] * 1.0E-6 ) + X [ 89ULL ] * - 1.0E-6 ) + X [ 91ULL ] ; t26 = X [ 89ULL
] * 0.001 + X [ 91ULL ] ; Gate_Driver2_N_Channel_MOSFET_capacitor_DS_n_v = (
( ( ( - X [ 26ULL ] + - X [ 27ULL ] ) + X [ 90ULL ] * - 1.0E-6 ) + X [ 92ULL
] * 1.0E-6 ) + X [ 89ULL ] * - 1.0E-6 ) + X [ 91ULL ] ;
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_p_v = ( ( - X [ 27ULL ] + X [
92ULL ] * 1.0E-6 ) + X [ 89ULL ] * - 1.0E-6 ) + X [ 91ULL ] ;
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v = X [ 90ULL ] * 1.0E-6 + X [
26ULL ] ; Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 90ULL ] *
1.0E-6 + X [ 92ULL ] * - 1.0E-6 ) + X [ 89ULL ] * 1.0E-6 ) + X [ 26ULL ] ) +
X [ 27ULL ] ; t28 = ( ( ( - X [ 25ULL ] + X [ 88ULL ] * - 1.0E-9 ) + - X [
90ULL ] ) + - X [ 92ULL ] ) + X [ 89ULL ] ; t29 = ( X [ 88ULL ] * 1.0E-9 + -
X [ 89ULL ] ) + X [ 25ULL ] ; t30 = ( ( ( ( ( ( X [ 25ULL ] * 1.0E-5 + X [
26ULL ] * - 0.1 ) + X [ 27ULL ] * - 0.1 ) + X [ 88ULL ] *
1.0000000000000002E-14 ) + X [ 90ULL ] * - 1.0E-7 ) + X [ 92ULL ] * 1.0E-7 )
+ X [ 89ULL ] * - 0.00011009999999998899 ) + U_idx_2 * 0.1 ; t31 = ( ( ( ( (
( X [ 25ULL ] * - 1.0E-5 + X [ 26ULL ] * 0.1 ) + X [ 27ULL ] * 0.1 ) + X [
88ULL ] * - 1.0000000000000002E-14 ) + X [ 90ULL ] * 1.0E-7 ) + X [ 92ULL ] *
- 1.0E-7 ) + X [ 89ULL ] * 1.0001101 ) + U_idx_2 * - 0.1 ; t32 = - ( t25 -
Gate_Driver2_Controlled_Voltage_Source_n_v ) / - 1.0 ;
Gate_Driver3_Controlled_Voltage_Source_n_v = ( ( ( ( ( ( X [ 31ULL ] * 0.0001
+ - X [ 32ULL ] ) + - X [ 33ULL ] ) + X [ 95ULL ] * 1.0000000000000002E-13 )
+ X [ 97ULL ] * - 1.0E-6 ) + X [ 99ULL ] * 1.0E-6 ) + X [ 96ULL ] * -
0.000101 ) + X [ 98ULL ] ; Gate_Driver3_Controlled_Voltage_Source_p_v = ( ( (
( ( ( ( X [ 31ULL ] * 0.0001 + - X [ 32ULL ] ) + - X [ 33ULL ] ) + X [ 95ULL
] * 1.0000000000000002E-13 ) + X [ 97ULL ] * - 1.0E-6 ) + X [ 99ULL ] *
1.0E-6 ) + X [ 96ULL ] * - 0.000101 ) + U_idx_3 ) + X [ 98ULL ] ;
Gate_Driver3_Current_Measure_Current_Sensor1_I = - X [ 31ULL ] + X [ 95ULL ]
* - 1.0E-9 ; Gate_Driver3_Current_Measure_Current_Sensor1_n_v = ( ( ( ( X [
31ULL ] * - 9.9999999999999991E-5 + - X [ 33ULL ] ) + X [ 95ULL ] * -
1.0000000000001001 ) + X [ 99ULL ] * 1.0E-6 ) + X [ 96ULL ] * - 1.0E-6 ) + X
[ 98ULL ] ; Gate_Driver3_Diode_diode_i = ( ( ( ( ( ( ( X [ 31ULL ] * 1.0E-5 +
X [ 32ULL ] * - 0.1 ) + X [ 33ULL ] * - 0.1 ) + - X [ 100ULL ] ) + X [ 95ULL
] * 1.0000000000000002E-14 ) + X [ 97ULL ] * - 1.0E-7 ) + X [ 99ULL ] *
1.0E-7 ) + X [ 96ULL ] * - 1.0001101 ) + U_idx_3 * 0.1 ;
Gate_Driver3_Diode_diode_junctionCapacitance_p_v = ( ( ( ( ( ( ( ( ( X [
31ULL ] * 0.0001 + - X [ 32ULL ] ) + - X [ 33ULL ] ) + X [ 100ULL ] * 1.0E-6
) + X [ 95ULL ] * 1.0000000000000002E-13 ) + X [ 97ULL ] * - 1.0E-6 ) + X [
99ULL ] * 1.0E-6 ) + X [ 96ULL ] * - 0.000101 ) + U_idx_3 ) + X [ 34ULL ] ) +
X [ 98ULL ] ; Gate_Driver3_Diode_diode_junctionCapacitance_v = X [ 100ULL ] *
1.0E-6 + X [ 34ULL ] ; t34 = X [ 94ULL ] * 1.0E-9 + X [ 30ULL ] ;
Gate_Driver3_Inductor_n_v = ( ( ( ( ( ( ( X [ 31ULL ] * 0.0001 + - X [ 32ULL
] ) + - X [ 33ULL ] ) + - X [ 94ULL ] ) + X [ 95ULL ] *
1.0000000000000002E-13 ) + X [ 97ULL ] * - 1.0E-6 ) + X [ 99ULL ] * 1.0E-6 )
+ X [ 96ULL ] * - 0.000101 ) + X [ 98ULL ] ; t35 = ( ( ( ( X [ 31ULL ] * -
0.0001 + - X [ 33ULL ] ) + X [ 95ULL ] * - 1.0000000000000002E-13 ) + X [
99ULL ] * 1.0E-6 ) + X [ 96ULL ] * - 1.0E-6 ) + X [ 98ULL ] ; t36 = X [ 96ULL
] * 0.001 + X [ 98ULL ] ; Gate_Driver3_N_Channel_MOSFET_capacitor_DS_n_v = (
( ( ( - X [ 32ULL ] + - X [ 33ULL ] ) + X [ 97ULL ] * - 1.0E-6 ) + X [ 99ULL
] * 1.0E-6 ) + X [ 96ULL ] * - 1.0E-6 ) + X [ 98ULL ] ;
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_p_v = ( ( - X [ 33ULL ] + X [
99ULL ] * 1.0E-6 ) + X [ 96ULL ] * - 1.0E-6 ) + X [ 98ULL ] ;
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v = X [ 97ULL ] * 1.0E-6 + X [
32ULL ] ; Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 97ULL ] *
1.0E-6 + X [ 99ULL ] * - 1.0E-6 ) + X [ 96ULL ] * 1.0E-6 ) + X [ 32ULL ] ) +
X [ 33ULL ] ; t38 = ( ( ( - X [ 31ULL ] + X [ 95ULL ] * - 1.0E-9 ) + - X [
97ULL ] ) + - X [ 99ULL ] ) + X [ 96ULL ] ; t39 = ( X [ 95ULL ] * 1.0E-9 + -
X [ 96ULL ] ) + X [ 31ULL ] ; t40 = ( ( ( ( ( ( X [ 31ULL ] * 1.0E-5 + X [
32ULL ] * - 0.1 ) + X [ 33ULL ] * - 0.1 ) + X [ 95ULL ] *
1.0000000000000002E-14 ) + X [ 97ULL ] * - 1.0E-7 ) + X [ 99ULL ] * 1.0E-7 )
+ X [ 96ULL ] * - 0.00011009999999998899 ) + U_idx_3 * 0.1 ; t41 = ( ( ( ( (
( X [ 31ULL ] * - 1.0E-5 + X [ 32ULL ] * 0.1 ) + X [ 33ULL ] * 0.1 ) + X [
95ULL ] * - 1.0000000000000002E-14 ) + X [ 97ULL ] * 1.0E-7 ) + X [ 99ULL ] *
- 1.0E-7 ) + X [ 96ULL ] * 1.0001101 ) + U_idx_3 * - 0.1 ; t42 = - ( t35 -
Gate_Driver3_Controlled_Voltage_Source_n_v ) / - 1.0 ;
Gate_Driver4_Controlled_Voltage_Source_n_v = ( ( ( ( X [ 37ULL ] * 0.0001 + -
X [ 38ULL ] ) + X [ 102ULL ] * 1.0000000000000002E-13 ) + X [ 104ULL ] * -
1.0E-6 ) + X [ 103ULL ] * - 0.0001 ) + X [ 105ULL ] ;
Gate_Driver4_Controlled_Voltage_Source_p_v = ( ( ( ( ( X [ 37ULL ] * 0.0001 +
- X [ 38ULL ] ) + X [ 102ULL ] * 1.0000000000000002E-13 ) + X [ 104ULL ] * -
1.0E-6 ) + X [ 103ULL ] * - 0.0001 ) + U_idx_4 ) + X [ 105ULL ] ;
Gate_Driver4_Current_Measure_Current_Sensor1_I = - X [ 37ULL ] + X [ 102ULL ]
* - 1.0E-9 ; Gate_Driver4_Current_Measure_Current_Sensor1_n_v = ( X [ 37ULL ]
* - 0.00010000000000000005 + X [ 102ULL ] * - 1.0000000000001 ) + X [ 105ULL
] ; Gate_Driver4_Diode_diode_i = ( ( ( ( ( ( ( X [ 37ULL ] * 1.0E-5 + X [
38ULL ] * - 0.1 ) + X [ 39ULL ] * - 0.1 ) + - X [ 106ULL ] ) + X [ 102ULL ] *
1.0000000000000002E-14 ) + X [ 104ULL ] * - 1.0E-7 ) + X [ 107ULL ] * 1.0E-7
) + X [ 103ULL ] * - 1.0001101000000001 ) + U_idx_4 * 0.1 ;
Gate_Driver4_Diode_diode_junctionCapacitance_p_v = ( ( ( ( ( ( ( X [ 37ULL ]
* 0.0001 + - X [ 38ULL ] ) + X [ 106ULL ] * 1.0E-6 ) + X [ 102ULL ] *
1.0000000000000002E-13 ) + X [ 104ULL ] * - 1.0E-6 ) + X [ 103ULL ] * -
0.0001 ) + U_idx_4 ) + X [ 40ULL ] ) + X [ 105ULL ] ;
Gate_Driver4_Diode_diode_junctionCapacitance_v = X [ 106ULL ] * 1.0E-6 + X [
40ULL ] ; t44 = X [ 101ULL ] * 1.0E-9 + X [ 36ULL ] ;
Gate_Driver4_Inductor_n_v = ( ( ( ( ( X [ 37ULL ] * 0.0001 + - X [ 38ULL ] )
+ - X [ 101ULL ] ) + X [ 102ULL ] * 1.0000000000000002E-13 ) + X [ 104ULL ] *
- 1.0E-6 ) + X [ 103ULL ] * - 0.0001 ) + X [ 105ULL ] ; t45 = ( X [ 37ULL ] *
- 0.0001 + X [ 102ULL ] * - 1.0000000000000002E-13 ) + X [ 105ULL ] ; t46 = (
( X [ 107ULL ] * - 1.0E-6 + X [ 103ULL ] * 0.001001 ) + X [ 105ULL ] ) + X [
39ULL ] ; Gate_Driver4_N_Channel_MOSFET_capacitor_DS_n_v = ( - X [ 38ULL ] +
X [ 104ULL ] * - 1.0E-6 ) + X [ 105ULL ] ;
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v = X [ 104ULL ] * 1.0E-6 + X [
38ULL ] ; Gate_Driver4_N_Channel_MOSFET_capacitor_GD_p_v = ( ( X [ 107ULL ] *
- 1.0E-6 + X [ 103ULL ] * 1.0E-6 ) + X [ 105ULL ] ) + X [ 39ULL ] ;
Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 104ULL ] * 1.0E-6 +
X [ 107ULL ] * - 1.0E-6 ) + X [ 103ULL ] * 1.0E-6 ) + X [ 38ULL ] ) + X [
39ULL ] ; t48 = ( ( ( - X [ 37ULL ] + X [ 102ULL ] * - 1.0E-9 ) + - X [
104ULL ] ) + - X [ 107ULL ] ) + X [ 103ULL ] ; t49 = ( X [ 102ULL ] * 1.0E-9
+ - X [ 103ULL ] ) + X [ 37ULL ] ; t50 = ( ( ( ( ( ( X [ 37ULL ] * 1.0E-5 + X
[ 38ULL ] * - 0.1 ) + X [ 39ULL ] * - 0.1 ) + X [ 102ULL ] *
1.0000000000000002E-14 ) + X [ 104ULL ] * - 1.0E-7 ) + X [ 107ULL ] * 1.0E-7
) + X [ 103ULL ] * - 0.00011009999999998899 ) + U_idx_4 * 0.1 ; t51 = ( ( ( (
( ( X [ 37ULL ] * - 1.0E-5 + X [ 38ULL ] * 0.1 ) + X [ 39ULL ] * 0.1 ) + X [
102ULL ] * - 1.0000000000000002E-14 ) + X [ 104ULL ] * 1.0E-7 ) + X [ 107ULL
] * - 1.0E-7 ) + X [ 103ULL ] * 1.0001101000000001 ) + U_idx_4 * - 0.1 ; t52
= - ( t45 - Gate_Driver4_Controlled_Voltage_Source_n_v ) / - 1.0 ;
Gate_Driver5_Controlled_Voltage_Source_n_v = ( ( ( ( ( ( X [ 43ULL ] * 0.0001
+ - X [ 44ULL ] ) + - X [ 45ULL ] ) + X [ 109ULL ] * 1.0000000000000002E-13 )
+ X [ 111ULL ] * - 1.0E-6 ) + X [ 113ULL ] * 1.0E-6 ) + X [ 110ULL ] * -
0.000101 ) + X [ 112ULL ] ; Gate_Driver5_Controlled_Voltage_Source_p_v = ( (
( ( ( ( ( X [ 43ULL ] * 0.0001 + - X [ 44ULL ] ) + - X [ 45ULL ] ) + X [
109ULL ] * 1.0000000000000002E-13 ) + X [ 111ULL ] * - 1.0E-6 ) + X [ 113ULL
] * 1.0E-6 ) + X [ 110ULL ] * - 0.000101 ) + U_idx_5 ) + X [ 112ULL ] ;
Gate_Driver5_Current_Measure_Current_Sensor1_I = - X [ 43ULL ] + X [ 109ULL ]
* - 1.0E-9 ; Gate_Driver5_Current_Measure_Current_Sensor1_n_v = ( ( ( ( X [
43ULL ] * - 9.9999999999999991E-5 + - X [ 45ULL ] ) + X [ 109ULL ] * -
1.0000000000001 ) + X [ 113ULL ] * 1.0E-6 ) + X [ 110ULL ] * - 1.0E-6 ) + X [
112ULL ] ; Gate_Driver5_Diode_diode_i = ( ( ( ( ( ( ( X [ 43ULL ] * 1.0E-5 +
X [ 44ULL ] * - 0.1 ) + X [ 45ULL ] * - 0.1 ) + - X [ 114ULL ] ) + X [ 109ULL
] * 1.0000000000000002E-14 ) + X [ 111ULL ] * - 1.0E-7 ) + X [ 113ULL ] *
1.0E-7 ) + X [ 110ULL ] * - 1.0001101 ) + U_idx_5 * 0.1 ;
Gate_Driver5_Diode_diode_junctionCapacitance_p_v = ( ( ( ( ( ( ( ( ( X [
43ULL ] * 0.0001 + - X [ 44ULL ] ) + - X [ 45ULL ] ) + X [ 114ULL ] * 1.0E-6
) + X [ 109ULL ] * 1.0000000000000002E-13 ) + X [ 111ULL ] * - 1.0E-6 ) + X [
113ULL ] * 1.0E-6 ) + X [ 110ULL ] * - 0.000101 ) + U_idx_5 ) + X [ 46ULL ] )
+ X [ 112ULL ] ; Gate_Driver5_Diode_diode_junctionCapacitance_v = X [ 114ULL
] * 1.0E-6 + X [ 46ULL ] ; t54 = X [ 108ULL ] * 1.0E-9 + X [ 42ULL ] ;
Gate_Driver5_Inductor_n_v = ( ( ( ( ( ( ( X [ 43ULL ] * 0.0001 + - X [ 44ULL
] ) + - X [ 45ULL ] ) + - X [ 108ULL ] ) + X [ 109ULL ] *
1.0000000000000002E-13 ) + X [ 111ULL ] * - 1.0E-6 ) + X [ 113ULL ] * 1.0E-6
) + X [ 110ULL ] * - 0.000101 ) + X [ 112ULL ] ; t55 = ( ( ( ( X [ 43ULL ] *
- 0.0001 + - X [ 45ULL ] ) + X [ 109ULL ] * - 1.0000000000000002E-13 ) + X [
113ULL ] * 1.0E-6 ) + X [ 110ULL ] * - 1.0E-6 ) + X [ 112ULL ] ; t56 = X [
110ULL ] * 0.001 + X [ 112ULL ] ;
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_n_v = ( ( ( ( - X [ 44ULL ] + - X
[ 45ULL ] ) + X [ 111ULL ] * - 1.0E-6 ) + X [ 113ULL ] * 1.0E-6 ) + X [
110ULL ] * - 1.0E-6 ) + X [ 112ULL ] ;
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_p_v = ( ( - X [ 45ULL ] + X [
113ULL ] * 1.0E-6 ) + X [ 110ULL ] * - 1.0E-6 ) + X [ 112ULL ] ;
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v = X [ 111ULL ] * 1.0E-6 + X [
44ULL ] ; Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v = ( ( ( X [ 111ULL ] *
1.0E-6 + X [ 113ULL ] * - 1.0E-6 ) + X [ 110ULL ] * 1.0E-6 ) + X [ 44ULL ] )
+ X [ 45ULL ] ; t58 = ( ( ( - X [ 43ULL ] + X [ 109ULL ] * - 1.0E-9 ) + - X [
111ULL ] ) + - X [ 113ULL ] ) + X [ 110ULL ] ; t59 = ( X [ 109ULL ] * 1.0E-9
+ - X [ 110ULL ] ) + X [ 43ULL ] ; t60 = ( ( ( ( ( ( X [ 43ULL ] * 1.0E-5 + X
[ 44ULL ] * - 0.1 ) + X [ 45ULL ] * - 0.1 ) + X [ 109ULL ] *
1.0000000000000002E-14 ) + X [ 111ULL ] * - 1.0E-7 ) + X [ 113ULL ] * 1.0E-7
) + X [ 110ULL ] * - 0.00011009999999998899 ) + U_idx_5 * 0.1 ; t61 = ( ( ( (
( ( X [ 43ULL ] * - 1.0E-5 + X [ 44ULL ] * 0.1 ) + X [ 45ULL ] * 0.1 ) + X [
109ULL ] * - 1.0000000000000002E-14 ) + X [ 111ULL ] * 1.0E-7 ) + X [ 113ULL
] * - 1.0E-7 ) + X [ 110ULL ] * 1.0001101 ) + U_idx_5 * - 0.1 ; t62 = - ( t55
- Gate_Driver5_Controlled_Voltage_Source_n_v ) / - 1.0 ; t63 = ( ( ( ( ( X [
13ULL ] * 0.000854 + X [ 0ULL ] * 0.0211 ) + X [ 1ULL ] * 0.001422 ) + X [
74ULL ] * 8.540000000000001E-13 ) + X [ 64ULL ] * 1.0000000000211 ) + X [
65ULL ] * 1.000000000001422 ) + X [ 2ULL ] ; Inductor_v = ( ( ( ( ( ( - X [
2ULL ] + X [ 13ULL ] * - 0.0009540000000000001 ) + X [ 0ULL ] * - 0.0211 ) +
X [ 1ULL ] * - 0.001422 ) + X [ 74ULL ] * - 1.0000000000009539 ) + X [ 64ULL
] * - 1.0000000000211 ) + X [ 65ULL ] * - 1.000000000001422 ) + X [ 77ULL ] ;
t64 = ( ( X [ 30ULL ] * 0.000664 + X [ 1ULL ] * 0.001422 ) + X [ 94ULL ] *
6.6391336872584361E-13 ) + X [ 65ULL ] * 1.000000000001422 ; Inductor1_v = (
( ( ( ( ( ( ( ( ( X [ 30ULL ] * - 0.000664 + X [ 31ULL ] * 0.0001 ) + - X [
32ULL ] ) + - X [ 33ULL ] ) + X [ 1ULL ] * - 0.001422 ) + X [ 94ULL ] * -
1.0000000000006639 ) + X [ 95ULL ] * 1.0000000000000002E-13 ) + X [ 97ULL ] *
- 1.0E-6 ) + X [ 99ULL ] * 1.0E-6 ) + X [ 96ULL ] * - 0.000101 ) + X [ 65ULL
] * - 1.000000000001422 ) + X [ 98ULL ] ; t65 = X [ 72ULL ] * 1.0E-9 + X [
10ULL ] ; Inductor10_n_v = ( ( ( ( ( ( ( X [ 10ULL ] * 0.000867 + X [ 0ULL ]
* 0.0211 ) + X [ 5ULL ] * - 0.001037 ) + X [ 1ULL ] * 0.001422 ) + X [ 72ULL
] * 8.6708418223224726E-13 ) + X [ 64ULL ] * 1.0000000000211 ) + X [ 68ULL ]
* - 1.0000000000010369 ) + X [ 65ULL ] * 1.000000000001422 ) + X [ 2ULL ] ;
t66 = X [ 71ULL ] * 1.0E-9 + X [ 9ULL ] ; Inductor11_n_v = X [ 9ULL ] *
0.000595 + X [ 71ULL ] * 5.9500000000000009E-13 ; Inductor11_p_v = X [ 9ULL ]
* 0.000595 + X [ 71ULL ] * 1.0000000000005951 ; t67 = ( ( ( ( ( ( X [ 12ULL ]
* - 0.0002188 + X [ 13ULL ] * 0.0001 ) + - X [ 14ULL ] ) + X [ 73ULL ] * -
1.0000000000002187 ) + X [ 74ULL ] * 1.0000000000000002E-13 ) + X [ 76ULL ] *
- 1.0E-6 ) + X [ 75ULL ] * - 0.0001 ) + X [ 77ULL ] ; Inductor12_p_v = ( ( (
( ( ( ( X [ 12ULL ] * - 0.0002188 + X [ 13ULL ] * 0.0001 ) + - X [ 14ULL ] )
+ X [ 73ULL ] * - 1.0000000000002187 ) + X [ 74ULL ] * 1.0000000000000002E-13
) + X [ 76ULL ] * - 1.0E-6 ) + X [ 75ULL ] * - 0.0001 ) + X [ 77ULL ] ) + X [
115ULL ] ; t68 = ( ( ( ( X [ 31ULL ] * - 0.0003188 + - X [ 33ULL ] ) + X [
95ULL ] * - 1.0000000000003189 ) + X [ 99ULL ] * 1.0E-6 ) + X [ 96ULL ] * -
1.0E-6 ) + X [ 98ULL ] ; Inductor13_v = ( ( ( ( ( ( ( ( ( ( ( ( ( X [ 12ULL ]
* - 0.0002188 + X [ 13ULL ] * 0.0001 ) + - X [ 14ULL ] ) + X [ 31ULL ] *
0.0003188 ) + X [ 73ULL ] * - 1.0000000000002187 ) + X [ 74ULL ] *
1.0000000000000002E-13 ) + X [ 76ULL ] * - 1.0E-6 ) + X [ 75ULL ] * - 0.0001
) + X [ 95ULL ] * 1.0000000000003189 ) + - X [ 98ULL ] ) + X [ 99ULL ] * -
1.0E-6 ) + X [ 96ULL ] * 1.0E-6 ) + X [ 77ULL ] ) + X [ 33ULL ] ) + X [
115ULL ] ; t69 = ( ( ( ( ( ( X [ 18ULL ] * - 0.000218 + X [ 19ULL ] * 0.0001
) + - X [ 20ULL ] ) + X [ 80ULL ] * - 1.000000000000218 ) + X [ 81ULL ] *
1.0000000000000002E-13 ) + X [ 83ULL ] * - 1.0E-6 ) + X [ 82ULL ] * - 0.0001
) + X [ 84ULL ] ; Inductor14_p_v = ( ( ( ( ( ( ( X [ 18ULL ] * - 0.000218 + X
[ 19ULL ] * 0.0001 ) + - X [ 20ULL ] ) + X [ 80ULL ] * - 1.000000000000218 )
+ X [ 81ULL ] * 1.0000000000000002E-13 ) + X [ 83ULL ] * - 1.0E-6 ) + X [
82ULL ] * - 0.0001 ) + X [ 84ULL ] ) + X [ 116ULL ] ; t70 = ( ( ( ( X [ 25ULL
] * - 0.00031800000000000003 + - X [ 27ULL ] ) + X [ 88ULL ] * -
1.000000000000318 ) + X [ 92ULL ] * 1.0E-6 ) + X [ 89ULL ] * - 1.0E-6 ) + X [
91ULL ] ; Inductor15_v = ( ( ( ( ( ( ( ( ( ( ( ( ( X [ 18ULL ] * - 0.000218 +
X [ 19ULL ] * 0.0001 ) + - X [ 20ULL ] ) + X [ 25ULL ] *
0.00031800000000000003 ) + X [ 80ULL ] * - 1.000000000000218 ) + X [ 81ULL ]
* 1.0000000000000002E-13 ) + X [ 83ULL ] * - 1.0E-6 ) + X [ 82ULL ] * -
0.0001 ) + X [ 88ULL ] * 1.000000000000318 ) + - X [ 91ULL ] ) + X [ 92ULL ]
* - 1.0E-6 ) + X [ 89ULL ] * 1.0E-6 ) + X [ 84ULL ] ) + X [ 27ULL ] ) + X [
116ULL ] ; t71 = ( ( ( ( ( ( X [ 36ULL ] * - 0.0002183 + X [ 37ULL ] * 0.0001
) + - X [ 38ULL ] ) + X [ 101ULL ] * - 1.0000000000002183 ) + X [ 102ULL ] *
1.0000000000000002E-13 ) + X [ 104ULL ] * - 1.0E-6 ) + X [ 103ULL ] * -
0.0001 ) + X [ 105ULL ] ; Inductor16_p_v = ( ( ( ( ( ( ( X [ 36ULL ] * -
0.0002183 + X [ 37ULL ] * 0.0001 ) + - X [ 38ULL ] ) + X [ 101ULL ] * -
1.0000000000002183 ) + X [ 102ULL ] * 1.0000000000000002E-13 ) + X [ 104ULL ]
* - 1.0E-6 ) + X [ 103ULL ] * - 0.0001 ) + X [ 105ULL ] ) + X [ 117ULL ] ;
t72 = ( ( ( ( X [ 43ULL ] * - 0.0003183 + - X [ 45ULL ] ) + X [ 109ULL ] * -
1.0000000000003182 ) + X [ 113ULL ] * 1.0E-6 ) + X [ 110ULL ] * - 1.0E-6 ) +
X [ 112ULL ] ; Inductor17_v = ( ( ( ( ( ( ( ( ( ( ( ( ( X [ 36ULL ] * -
0.0002183 + X [ 37ULL ] * 0.0001 ) + - X [ 38ULL ] ) + X [ 43ULL ] *
0.0003183 ) + X [ 101ULL ] * - 1.0000000000002183 ) + X [ 102ULL ] *
1.0000000000000002E-13 ) + X [ 104ULL ] * - 1.0E-6 ) + X [ 103ULL ] * -
0.0001 ) + X [ 109ULL ] * 1.0000000000003182 ) + - X [ 112ULL ] ) + X [
113ULL ] * - 1.0E-6 ) + X [ 110ULL ] * 1.0E-6 ) + X [ 105ULL ] ) + X [ 45ULL
] ) + X [ 117ULL ] ; t73 = X [ 1ULL ] * 0.001422 + X [ 65ULL ] *
1.000000000001422 ; t74 = X [ 4ULL ] * 0.000662 + X [ 67ULL ] *
1.0000000000006619 ; t75 = ( ( ( ( ( ( ( ( ( X [ 19ULL ] * 0.000813 + X [
0ULL ] * 0.0211 ) + X [ 5ULL ] * - 0.001037 ) + X [ 1ULL ] * 0.001422 ) + X [
6ULL ] * 0.000611 ) + X [ 81ULL ] * 8.1300000000000007E-13 ) + X [ 64ULL ] *
1.0000000000211 ) + X [ 68ULL ] * - 1.0000000000010369 ) + X [ 65ULL ] *
1.000000000001422 ) + X [ 69ULL ] * 1.0000000000006111 ) + X [ 2ULL ] ;
Inductor2_v = ( ( ( ( ( ( ( ( ( ( - X [ 2ULL ] + X [ 19ULL ] * -
0.00091300000000000007 ) + X [ 0ULL ] * - 0.0211 ) + X [ 5ULL ] * 0.001037 )
+ X [ 1ULL ] * - 0.001422 ) + X [ 6ULL ] * - 0.000611 ) + X [ 81ULL ] * -
1.000000000000913 ) + X [ 64ULL ] * - 1.0000000000211 ) + X [ 68ULL ] *
1.0000000000010369 ) + X [ 65ULL ] * - 1.000000000001422 ) + X [ 69ULL ] * -
1.0000000000006111 ) + X [ 84ULL ] ; t77 = X [ 118ULL ] * 1.0E-9 + X [ 57ULL
] ; t78 = ( ( X [ 24ULL ] * 0.000664 + X [ 4ULL ] * 0.000662 ) + X [ 87ULL ]
* 6.64E-13 ) + X [ 67ULL ] * 1.0000000000006619 ; Inductor3_v = ( ( ( ( ( ( (
( ( ( X [ 24ULL ] * - 0.000664 + X [ 25ULL ] * 0.0001 ) + - X [ 26ULL ] ) + -
X [ 27ULL ] ) + X [ 4ULL ] * - 0.000662 ) + X [ 87ULL ] * -
1.0000000000006639 ) + X [ 88ULL ] * 1.0000000000000002E-13 ) + X [ 90ULL ] *
- 1.0E-6 ) + X [ 92ULL ] * 1.0E-6 ) + X [ 89ULL ] * - 0.000101 ) + X [ 67ULL
] * - 1.0000000000006619 ) + X [ 91ULL ] ; t79 = ( ( ( ( ( ( ( ( ( X [ 37ULL
] * 0.000854 + X [ 10ULL ] * 0.000867 ) + X [ 0ULL ] * 0.0211 ) + X [ 5ULL ]
* - 0.001037 ) + X [ 1ULL ] * 0.001422 ) + X [ 102ULL ] *
8.540000000000001E-13 ) + X [ 72ULL ] * 1.0000000000008671 ) + X [ 64ULL ] *
1.0000000000211 ) + X [ 68ULL ] * - 1.0000000000010369 ) + X [ 65ULL ] *
1.000000000001422 ) + X [ 2ULL ] ; Inductor4_v = ( ( ( ( ( ( ( ( ( ( - X [
2ULL ] + X [ 37ULL ] * - 0.0009540000000000001 ) + X [ 10ULL ] * - 0.000867 )
+ X [ 0ULL ] * - 0.0211 ) + X [ 5ULL ] * 0.001037 ) + X [ 1ULL ] * - 0.001422
) + X [ 102ULL ] * - 1.0000000000009539 ) + X [ 72ULL ] * -
1.0000000000008671 ) + X [ 64ULL ] * - 1.0000000000211 ) + X [ 68ULL ] *
1.0000000000010369 ) + X [ 65ULL ] * - 1.000000000001422 ) + X [ 105ULL ] ;
t80 = ( ( X [ 42ULL ] * 0.000664 + X [ 9ULL ] * 0.000595 ) + X [ 108ULL ] *
6.64E-13 ) + X [ 71ULL ] * 1.0000000000005951 ; Inductor5_v = ( ( ( ( ( ( ( (
( ( X [ 42ULL ] * - 0.000664 + X [ 43ULL ] * 0.0001 ) + - X [ 44ULL ] ) + - X
[ 45ULL ] ) + X [ 9ULL ] * - 0.000595 ) + X [ 108ULL ] * - 1.0000000000006639
) + X [ 109ULL ] * 1.0000000000000002E-13 ) + X [ 111ULL ] * - 1.0E-6 ) + X [
113ULL ] * 1.0E-6 ) + X [ 110ULL ] * - 0.000101 ) + X [ 71ULL ] * -
1.0000000000005951 ) + X [ 112ULL ] ; t81 = X [ 68ULL ] * 1.0E-9 + X [ 5ULL ]
; Inductor6_n_v = ( ( ( ( X [ 0ULL ] * 0.0211 + X [ 1ULL ] * 0.001422 ) + X [
64ULL ] * 1.0000000000211 ) + - X [ 68ULL ] ) + X [ 65ULL ] *
1.000000000001422 ) + X [ 2ULL ] ; t82 = X [ 65ULL ] * 1.0E-9 + X [ 1ULL ] ;
Inductor7_n_v = X [ 1ULL ] * 0.001422 + X [ 65ULL ] * 1.4220000000000002E-12
; t83 = X [ 69ULL ] * 1.0E-9 + X [ 6ULL ] ; Inductor8_n_v = ( ( ( ( ( ( ( X [
0ULL ] * 0.0211 + X [ 5ULL ] * - 0.001037 ) + X [ 1ULL ] * 0.001422 ) + X [
6ULL ] * 0.000611 ) + X [ 64ULL ] * 1.0000000000211 ) + X [ 68ULL ] * -
1.0000000000010369 ) + X [ 65ULL ] * 1.000000000001422 ) + X [ 69ULL ] *
6.1106675275368616E-13 ) + X [ 2ULL ] ; t84 = X [ 67ULL ] * 1.0E-9 + X [ 4ULL
] ; Inductor9_n_v = X [ 4ULL ] * 0.000662 + X [ 67ULL ] *
6.6200000000000011E-13 ; t85 = X [ 119ULL ] * 1.0E-9 + X [ 61ULL ] ;
R_L_Load_Current_Measure2_Current_Sensor1_I = X [ 120ULL ] * 1.0E-9 + X [
62ULL ] ; R_L_Load_Current_Measure5_Current_Sensor1_I = X [ 121ULL ] * 1.0E-9
+ X [ 63ULL ] ; R_L_Load_Inductor_p_v = X [ 122ULL ] + X [ 121ULL ] ; t86 = X
[ 122ULL ] + X [ 119ULL ] ; t87 = X [ 122ULL ] + X [ 120ULL ] ; t91 = - (
Inductor14_p_v - Inductor16_p_v ) / - 1.0 ; t92 = - ( Inductor12_p_v -
Inductor16_p_v ) / - 1.0 ; t93 = - ( Inductor12_p_v - Inductor14_p_v ) / -
1.0 ; t96 = ( ( ( ( ( X [ 0ULL ] * 0.0211 + X [ 5ULL ] * - 0.001037 ) + X [
1ULL ] * 0.001422 ) + X [ 64ULL ] * 1.0000000000211 ) + X [ 68ULL ] * -
1.0000000000010369 ) + X [ 65ULL ] * 1.000000000001422 ) + X [ 2ULL ] ; t113
= - ( Capacitor1_p_v - t74 ) / - 1.0 ; t114 = - ( Capacitor2_p_v -
Inductor11_p_v ) / - 1.0 ; t115 = - ( Capacitor_p_v - t73 ) / - 1.0 ; t0 [
0ULL ] = Capacitor_i ; t0 [ 1ULL ] = - ( Capacitor_i * Capacitor_i * 2.11E-5
) / - 1.0 * 1000.0 ; t0 [ 2ULL ] = ( X [ 0ULL ] * 0.0211 + X [ 64ULL ] *
2.1100000000000003E-11 ) + X [ 2ULL ] ; t0 [ 3ULL ] = X [ 2ULL ] ; t0 [ 4ULL
] = Capacitor_n_v ; t0 [ 5ULL ] = Capacitor_p_v ; t0 [ 6ULL ] = Capacitor1_i
; t0 [ 7ULL ] = - ( Capacitor1_i * Capacitor1_i * 2.11E-5 ) / - 1.0 * 1000.0
; t0 [ 8ULL ] = ( X [ 3ULL ] * 0.0211 + X [ 66ULL ] * 2.1100000000000003E-11
) + X [ 7ULL ] ; t0 [ 9ULL ] = X [ 7ULL ] ; t0 [ 10ULL ] = Capacitor1_n_v ;
t0 [ 11ULL ] = Capacitor1_p_v ; t0 [ 12ULL ] = Capacitor2_i ; t0 [ 13ULL ] =
- ( Capacitor2_i * Capacitor2_i * 2.11E-5 ) / - 1.0 * 1000.0 ; t0 [ 14ULL ] =
( X [ 8ULL ] * 0.0211 + X [ 70ULL ] * 2.1100000000000003E-11 ) + X [ 11ULL ]
; t0 [ 15ULL ] = X [ 11ULL ] ; t0 [ 16ULL ] = Capacitor2_n_v ; t0 [ 17ULL ] =
Capacitor2_p_v ; t0 [ 18ULL ] = Capacitor1_i ; t0 [ 19ULL ] = Capacitor1_i ;
t0 [ 20ULL ] = Capacitor1_p_v ; t0 [ 21ULL ] = Capacitor1_p_v ; t0 [ 22ULL ]
= 0.0 ; t0 [ 23ULL ] = Capacitor1_p_v ; t0 [ 24ULL ] = Capacitor1_p_v ; t0 [
25ULL ] = Capacitor2_i ; t0 [ 26ULL ] = Capacitor2_i ; t0 [ 27ULL ] =
Capacitor2_p_v ; t0 [ 28ULL ] = Capacitor2_p_v ; t0 [ 29ULL ] = 0.0 ; t0 [
30ULL ] = Capacitor2_p_v ; t0 [ 31ULL ] = Capacitor2_p_v ; t0 [ 32ULL ] =
Capacitor_i ; t0 [ 33ULL ] = Capacitor_i ; t0 [ 34ULL ] = Capacitor_p_v ; t0
[ 35ULL ] = Capacitor_p_v ; t0 [ 36ULL ] = 0.0 ; t0 [ 37ULL ] = Capacitor_p_v
; t0 [ 38ULL ] = Capacitor_p_v ; t0 [ 39ULL ] = 0.0 ; t0 [ 40ULL ] = ( ( ( X
[ 73ULL ] * 1.0E-9 + X [ 74ULL ] * 1.0E-9 ) + - X [ 75ULL ] ) + X [ 12ULL ] )
+ X [ 13ULL ] ; t0 [ 41ULL ] = Gate_Driver_Controlled_Voltage_Source_n_v ; t0
[ 42ULL ] = Gate_Driver_Controlled_Voltage_Source_p_v ; t0 [ 43ULL ] =
U_idx_0 ; t0 [ 44ULL ] = U_idx_0 ; t0 [ 45ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_I ; t0 [ 46ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_I ; t0 [ 47ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_n_v ; t0 [ 48ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_n_v ; t0 [ 49ULL ] = 0.0 ; t0 [
50ULL ] = Gate_Driver_Current_Measure_Current_Sensor1_n_v ; t0 [ 51ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_n_v ; t0 [ 52ULL ] = 0.0 ; t0 [
53ULL ] = X [ 78ULL ] ; t0 [ 54ULL ] = X [ 16ULL ] ; t0 [ 55ULL ] = X [ 78ULL
] ; t0 [ 56ULL ] = Gate_Driver_Controlled_Voltage_Source_p_v ; t0 [ 57ULL ] =
Gate_Driver_Diode_diode_junctionCapacitance_p_v ; t0 [ 58ULL ] =
Gate_Driver_Diode_diode_junctionCapacitance_v ; t0 [ 59ULL ] = - (
Gate_Driver_Diode_diode_i * Gate_Driver_Diode_diode_junctionCapacitance_v *
0.001 ) / - 1.0 * 1000.0 ; t0 [ 60ULL ] =
Gate_Driver_Diode_diode_junctionCapacitance_v ; t0 [ 61ULL ] =
Gate_Driver_Diode_diode_i ; t0 [ 62ULL ] =
Gate_Driver_Controlled_Voltage_Source_p_v ; t0 [ 63ULL ] =
Gate_Driver_Diode_diode_junctionCapacitance_p_v ; t0 [ 64ULL ] =
Gate_Driver_Diode_diode_junctionCapacitance_v ; t0 [ 65ULL ] = X [ 78ULL ] ;
t0 [ 66ULL ] = Gate_Driver_Diode_diode_junctionCapacitance_v ; t0 [ 67ULL ] =
Gate_Driver_Controlled_Voltage_Source_p_v ; t0 [ 68ULL ] =
Gate_Driver_Diode_diode_junctionCapacitance_p_v ; t0 [ 69ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_n_v ; t0 [ 70ULL ] = t4 ; t0 [
71ULL ] = X [ 12ULL ] ; t0 [ 72ULL ] = - ( X [ 73ULL ] * X [ 73ULL ] *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 73ULL ] = X [ 73ULL ] ; t0 [
74ULL ] = Gate_Driver_Inductor_n_v ; t0 [ 75ULL ] =
Gate_Driver_Controlled_Voltage_Source_n_v ; t0 [ 76ULL ] = -
Gate_Driver_Current_Measure_Current_Sensor1_I ; t0 [ 77ULL ] = X [ 13ULL ] ;
t0 [ 78ULL ] = - ( X [ 74ULL ] * X [ 74ULL ] * 1.0000000000000002E-12 ) / -
1.0 * 1000.0 ; t0 [ 79ULL ] = X [ 74ULL ] ; t0 [ 80ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_n_v ; t0 [ 81ULL ] = t5 ; t0 [
82ULL ] = t5 ; t0 [ 83ULL ] = t6 ; t0 [ 84ULL ] =
Gate_Driver_Controlled_Voltage_Source_n_v ; t0 [ 85ULL ] = X [ 14ULL ] ; t0 [
86ULL ] = X [ 76ULL ] ; t0 [ 87ULL ] =
Gate_Driver_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 88ULL ] = X [ 77ULL ] ;
t0 [ 89ULL ] = Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 90ULL ] = X
[ 15ULL ] ; t0 [ 91ULL ] = - X [ 79ULL ] + X [ 75ULL ] ; t0 [ 92ULL ] = X [
77ULL ] ; t0 [ 93ULL ] = Gate_Driver_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [
94ULL ] = ( X [ 79ULL ] * - 1.0E-6 + X [ 75ULL ] * 1.0E-6 ) + X [ 15ULL ] ;
t0 [ 95ULL ] = X [ 17ULL ] ; t0 [ 96ULL ] = X [ 79ULL ] ; t0 [ 97ULL ] =
Gate_Driver_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 98ULL ] =
Gate_Driver_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [ 99ULL ] =
Gate_Driver_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 100ULL ] = - (
Gate_Driver_Current_Measure_Current_Sensor1_I *
Gate_Driver_Current_Measure_Current_Sensor1_I * 1.0000000000000001E-7 ) / -
1.0 * 1000.0 ; t0 [ 101ULL ] = Gate_Driver_Current_Measure_Current_Sensor1_I
; t0 [ 102ULL ] = X [ 77ULL ] ; t0 [ 103ULL ] = t5 ; t0 [ 104ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_I * 0.0001 ; t0 [ 105ULL ] = - (
X [ 75ULL ] * X [ 75ULL ] * 1.0E-6 ) / - 1.0 * 1000.0 ; t0 [ 106ULL ] = X [
75ULL ] ; t0 [ 107ULL ] = Gate_Driver_N_Channel_MOSFET_capacitor_GD_p_v ; t0
[ 108ULL ] = t6 ; t0 [ 109ULL ] = X [ 75ULL ] * 0.001 ; t0 [ 110ULL ] = X [
77ULL ] ; t0 [ 111ULL ] = Gate_Driver_N_Channel_MOSFET_capacitor_GD_p_v ; t0
[ 112ULL ] = Gate_Driver_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 113ULL ] =
t8 ; t0 [ 114ULL ] = 0.0 ; t0 [ 115ULL ] = - (
Gate_Driver_N_Channel_MOSFET_capacitor_DS_v * t8 * 0.001 ) / - 1.0 * 1000.0 ;
t0 [ 116ULL ] = Gate_Driver_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 117ULL ] =
Gate_Driver_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 118ULL ] =
Gate_Driver_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 119ULL ] = X [ 77ULL ] ;
t0 [ 120ULL ] = Gate_Driver_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [ 121ULL ]
= - ( t9 * t9 * 1.0000000000000001E-7 ) / - 1.0 * 1000.0 ; t0 [ 122ULL ] = t9
; t0 [ 123ULL ] = Gate_Driver_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 124ULL
] = Gate_Driver_Controlled_Voltage_Source_n_v ; t0 [ 125ULL ] = t9 * 0.0001 ;
t0 [ 126ULL ] = - ( t10 * t10 * 0.01 ) / - 1.0 * 1000.0 ; t0 [ 127ULL ] = t10
; t0 [ 128ULL ] = t6 ; t0 [ 129ULL ] =
Gate_Driver_Controlled_Voltage_Source_p_v ; t0 [ 130ULL ] = t10 * 10.0 ; t0 [
131ULL ] = t6 ; t0 [ 132ULL ] = Gate_Driver_Controlled_Voltage_Source_p_v ;
t0 [ 133ULL ] = - ( t11 * t11 * 0.002 ) / - 1.0 * 1000.0 ; t0 [ 134ULL ] =
t11 ; t0 [ 135ULL ] = t6 ; t0 [ 136ULL ] =
Gate_Driver_Diode_diode_junctionCapacitance_p_v ; t0 [ 137ULL ] = t11 * 2.0 ;
t0 [ 138ULL ] = t6 ; t0 [ 139ULL ] =
Gate_Driver_Diode_diode_junctionCapacitance_p_v ; t0 [ 140ULL ] =
Gate_Driver_Inductor_n_v ; t0 [ 141ULL ] = t5 ; t0 [ 142ULL ] =
Gate_Driver_Controlled_Voltage_Source_n_v ; t0 [ 143ULL ] = t12 ; t0 [ 144ULL
] = 0.0 ; t0 [ 145ULL ] = Gate_Driver_Controlled_Voltage_Source_n_v ; t0 [
146ULL ] = t5 ; t0 [ 147ULL ] = t12 ; t0 [ 148ULL ] = ( ( ( X [ 80ULL ] *
1.0E-9 + X [ 81ULL ] * 1.0E-9 ) + - X [ 82ULL ] ) + X [ 18ULL ] ) + X [ 19ULL
] ; t0 [ 149ULL ] = Gate_Driver1_Controlled_Voltage_Source_n_v ; t0 [ 150ULL
] = Gate_Driver1_Controlled_Voltage_Source_p_v ; t0 [ 151ULL ] = U_idx_1 ; t0
[ 152ULL ] = U_idx_1 ; t0 [ 153ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_I ; t0 [ 154ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_I ; t0 [ 155ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_n_v ; t0 [ 156ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_n_v ; t0 [ 157ULL ] = 0.0 ; t0 [
158ULL ] = Gate_Driver1_Current_Measure_Current_Sensor1_n_v ; t0 [ 159ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_n_v ; t0 [ 160ULL ] = 0.0 ; t0 [
161ULL ] = X [ 85ULL ] ; t0 [ 162ULL ] = X [ 22ULL ] ; t0 [ 163ULL ] = X [
85ULL ] ; t0 [ 164ULL ] = Gate_Driver1_Controlled_Voltage_Source_p_v ; t0 [
165ULL ] = Gate_Driver1_Diode_diode_junctionCapacitance_p_v ; t0 [ 166ULL ] =
Gate_Driver1_Diode_diode_junctionCapacitance_v ; t0 [ 167ULL ] = - (
Gate_Driver1_Diode_diode_i * Gate_Driver1_Diode_diode_junctionCapacitance_v *
0.001 ) / - 1.0 * 1000.0 ; t0 [ 168ULL ] =
Gate_Driver1_Diode_diode_junctionCapacitance_v ; t0 [ 169ULL ] =
Gate_Driver1_Diode_diode_i ; t0 [ 170ULL ] =
Gate_Driver1_Controlled_Voltage_Source_p_v ; t0 [ 171ULL ] =
Gate_Driver1_Diode_diode_junctionCapacitance_p_v ; t0 [ 172ULL ] =
Gate_Driver1_Diode_diode_junctionCapacitance_v ; t0 [ 173ULL ] = X [ 85ULL ]
; t0 [ 174ULL ] = Gate_Driver1_Diode_diode_junctionCapacitance_v ; t0 [
175ULL ] = Gate_Driver1_Controlled_Voltage_Source_p_v ; t0 [ 176ULL ] =
Gate_Driver1_Diode_diode_junctionCapacitance_p_v ; t0 [ 177ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_n_v ; t0 [ 178ULL ] = t14 ; t0 [
179ULL ] = X [ 18ULL ] ; t0 [ 180ULL ] = - ( X [ 80ULL ] * X [ 80ULL ] *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 181ULL ] = X [ 80ULL ] ; t0
[ 182ULL ] = Gate_Driver1_Inductor_n_v ; t0 [ 183ULL ] =
Gate_Driver1_Controlled_Voltage_Source_n_v ; t0 [ 184ULL ] = -
Gate_Driver1_Current_Measure_Current_Sensor1_I ; t0 [ 185ULL ] = X [ 19ULL ]
; t0 [ 186ULL ] = - ( X [ 81ULL ] * X [ 81ULL ] * 1.0000000000000002E-12 ) /
- 1.0 * 1000.0 ; t0 [ 187ULL ] = X [ 81ULL ] ; t0 [ 188ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_n_v ; t0 [ 189ULL ] = t15 ; t0 [
190ULL ] = t15 ; t0 [ 191ULL ] = t16 ; t0 [ 192ULL ] =
Gate_Driver1_Controlled_Voltage_Source_n_v ; t0 [ 193ULL ] = X [ 20ULL ] ; t0
[ 194ULL ] = X [ 83ULL ] ; t0 [ 195ULL ] =
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 196ULL ] = X [ 84ULL ]
; t0 [ 197ULL ] = Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 198ULL
] = X [ 21ULL ] ; t0 [ 199ULL ] = - X [ 86ULL ] + X [ 82ULL ] ; t0 [ 200ULL ]
= X [ 84ULL ] ; t0 [ 201ULL ] =
Gate_Driver1_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [ 202ULL ] = ( X [ 86ULL
] * - 1.0E-6 + X [ 82ULL ] * 1.0E-6 ) + X [ 21ULL ] ; t0 [ 203ULL ] = X [
23ULL ] ; t0 [ 204ULL ] = X [ 86ULL ] ; t0 [ 205ULL ] =
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 206ULL ] =
Gate_Driver1_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [ 207ULL ] =
Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 208ULL ] = - (
Gate_Driver1_Current_Measure_Current_Sensor1_I *
Gate_Driver1_Current_Measure_Current_Sensor1_I * 1.0000000000000001E-7 ) / -
1.0 * 1000.0 ; t0 [ 209ULL ] = Gate_Driver1_Current_Measure_Current_Sensor1_I
; t0 [ 210ULL ] = X [ 84ULL ] ; t0 [ 211ULL ] = t15 ; t0 [ 212ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_I * 0.0001 ; t0 [ 213ULL ] = - (
X [ 82ULL ] * X [ 82ULL ] * 1.0E-6 ) / - 1.0 * 1000.0 ; t0 [ 214ULL ] = X [
82ULL ] ; t0 [ 215ULL ] = Gate_Driver1_N_Channel_MOSFET_capacitor_GD_p_v ; t0
[ 216ULL ] = t16 ; t0 [ 217ULL ] = X [ 82ULL ] * 0.001 ; t0 [ 218ULL ] = X [
84ULL ] ; t0 [ 219ULL ] = Gate_Driver1_N_Channel_MOSFET_capacitor_GD_p_v ; t0
[ 220ULL ] = Gate_Driver1_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 221ULL ] =
t18 ; t0 [ 222ULL ] = 0.0 ; t0 [ 223ULL ] = - (
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v * t18 * 0.001 ) / - 1.0 * 1000.0
; t0 [ 224ULL ] = Gate_Driver1_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 225ULL
] = Gate_Driver1_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 226ULL ] =
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 227ULL ] = X [ 84ULL ]
; t0 [ 228ULL ] = Gate_Driver1_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [
229ULL ] = - ( t19 * t19 * 1.0000000000000001E-7 ) / - 1.0 * 1000.0 ; t0 [
230ULL ] = t19 ; t0 [ 231ULL ] =
Gate_Driver1_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 232ULL ] =
Gate_Driver1_Controlled_Voltage_Source_n_v ; t0 [ 233ULL ] = t19 * 0.0001 ;
t0 [ 234ULL ] = - ( t20 * t20 * 0.01 ) / - 1.0 * 1000.0 ; t0 [ 235ULL ] = t20
; t0 [ 236ULL ] = t16 ; t0 [ 237ULL ] =
Gate_Driver1_Controlled_Voltage_Source_p_v ; t0 [ 238ULL ] = t20 * 10.0 ; t0
[ 239ULL ] = t16 ; t0 [ 240ULL ] = Gate_Driver1_Controlled_Voltage_Source_p_v
; t0 [ 241ULL ] = - ( t21 * t21 * 0.002 ) / - 1.0 * 1000.0 ; t0 [ 242ULL ] =
t21 ; t0 [ 243ULL ] = t16 ; t0 [ 244ULL ] =
Gate_Driver1_Diode_diode_junctionCapacitance_p_v ; t0 [ 245ULL ] = t21 * 2.0
; t0 [ 246ULL ] = t16 ; t0 [ 247ULL ] =
Gate_Driver1_Diode_diode_junctionCapacitance_p_v ; t0 [ 248ULL ] =
Gate_Driver1_Inductor_n_v ; t0 [ 249ULL ] = t15 ; t0 [ 250ULL ] =
Gate_Driver1_Controlled_Voltage_Source_n_v ; t0 [ 251ULL ] = t22 ; t0 [
252ULL ] = 0.0 ; t0 [ 253ULL ] = Gate_Driver1_Controlled_Voltage_Source_n_v ;
t0 [ 254ULL ] = t15 ; t0 [ 255ULL ] = t22 ; t0 [ 256ULL ] = ( ( ( X [ 87ULL ]
* 1.0E-9 + X [ 88ULL ] * 1.0E-9 ) + - X [ 89ULL ] ) + X [ 24ULL ] ) + X [
25ULL ] ; t0 [ 257ULL ] = Gate_Driver2_Controlled_Voltage_Source_n_v ; t0 [
258ULL ] = Gate_Driver2_Controlled_Voltage_Source_p_v ; t0 [ 259ULL ] =
U_idx_2 ; t0 [ 260ULL ] = U_idx_2 ; t0 [ 261ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_I ; t0 [ 262ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_I ; t0 [ 263ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; t0 [ 264ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; t0 [ 265ULL ] = 0.0 ; t0 [
266ULL ] = Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; t0 [ 267ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; t0 [ 268ULL ] = 0.0 ; t0 [
269ULL ] = X [ 93ULL ] ; t0 [ 270ULL ] = X [ 28ULL ] ; t0 [ 271ULL ] = X [
93ULL ] ; t0 [ 272ULL ] = Gate_Driver2_Controlled_Voltage_Source_p_v ; t0 [
273ULL ] = Gate_Driver2_Diode_diode_junctionCapacitance_p_v ; t0 [ 274ULL ] =
Gate_Driver2_Diode_diode_junctionCapacitance_v ; t0 [ 275ULL ] = - (
Gate_Driver2_Diode_diode_i * Gate_Driver2_Diode_diode_junctionCapacitance_v *
0.001 ) / - 1.0 * 1000.0 ; t0 [ 276ULL ] =
Gate_Driver2_Diode_diode_junctionCapacitance_v ; t0 [ 277ULL ] =
Gate_Driver2_Diode_diode_i ; t0 [ 278ULL ] =
Gate_Driver2_Controlled_Voltage_Source_p_v ; t0 [ 279ULL ] =
Gate_Driver2_Diode_diode_junctionCapacitance_p_v ; t0 [ 280ULL ] =
Gate_Driver2_Diode_diode_junctionCapacitance_v ; t0 [ 281ULL ] = X [ 93ULL ]
; t0 [ 282ULL ] = Gate_Driver2_Diode_diode_junctionCapacitance_v ; t0 [
283ULL ] = Gate_Driver2_Controlled_Voltage_Source_p_v ; t0 [ 284ULL ] =
Gate_Driver2_Diode_diode_junctionCapacitance_p_v ; t0 [ 285ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; t0 [ 286ULL ] = t24 ; t0 [
287ULL ] = X [ 24ULL ] ; t0 [ 288ULL ] = - ( X [ 87ULL ] * X [ 87ULL ] *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 289ULL ] = X [ 87ULL ] ; t0
[ 290ULL ] = Gate_Driver2_Inductor_n_v ; t0 [ 291ULL ] =
Gate_Driver2_Controlled_Voltage_Source_n_v ; t0 [ 292ULL ] = -
Gate_Driver2_Current_Measure_Current_Sensor1_I ; t0 [ 293ULL ] = X [ 25ULL ]
; t0 [ 294ULL ] = - ( X [ 88ULL ] * X [ 88ULL ] * 1.0000000000000002E-12 ) /
- 1.0 * 1000.0 ; t0 [ 295ULL ] = X [ 88ULL ] ; t0 [ 296ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; t0 [ 297ULL ] = t25 ; t0 [
298ULL ] = t25 ; t0 [ 299ULL ] = t26 ; t0 [ 300ULL ] =
Gate_Driver2_Controlled_Voltage_Source_n_v ; t0 [ 301ULL ] = X [ 26ULL ] ; t0
[ 302ULL ] = X [ 90ULL ] ; t0 [ 303ULL ] =
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 304ULL ] =
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 305ULL ] =
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 306ULL ] = X [ 27ULL ] ;
t0 [ 307ULL ] = - X [ 92ULL ] + X [ 89ULL ] ; t0 [ 308ULL ] =
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 309ULL ] = X [ 91ULL ]
; t0 [ 310ULL ] = ( X [ 92ULL ] * - 1.0E-6 + X [ 89ULL ] * 1.0E-6 ) + X [
27ULL ] ; t0 [ 311ULL ] = X [ 29ULL ] ; t0 [ 312ULL ] = X [ 92ULL ] ; t0 [
313ULL ] = Gate_Driver2_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 314ULL ] = X
[ 91ULL ] ; t0 [ 315ULL ] = Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v ; t0
[ 316ULL ] = - ( Gate_Driver2_Current_Measure_Current_Sensor1_I *
Gate_Driver2_Current_Measure_Current_Sensor1_I * 1.0000000000000001E-7 ) / -
1.0 * 1000.0 ; t0 [ 317ULL ] = Gate_Driver2_Current_Measure_Current_Sensor1_I
; t0 [ 318ULL ] = Gate_Driver2_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [
319ULL ] = t25 ; t0 [ 320ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_I * 0.0001 ; t0 [ 321ULL ] = - (
X [ 89ULL ] * X [ 89ULL ] * 1.0E-6 ) / - 1.0 * 1000.0 ; t0 [ 322ULL ] = X [
89ULL ] ; t0 [ 323ULL ] = X [ 91ULL ] ; t0 [ 324ULL ] = t26 ; t0 [ 325ULL ] =
X [ 89ULL ] * 0.001 ; t0 [ 326ULL ] =
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 327ULL ] = X [ 91ULL ]
; t0 [ 328ULL ] = Gate_Driver2_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [
329ULL ] = t28 ; t0 [ 330ULL ] = 0.0 ; t0 [ 331ULL ] = - (
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v * t28 * 0.001 ) / - 1.0 * 1000.0
; t0 [ 332ULL ] = Gate_Driver2_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 333ULL
] = Gate_Driver2_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 334ULL ] =
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 335ULL ] =
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 336ULL ] = X [ 91ULL ]
; t0 [ 337ULL ] = - ( t29 * t29 * 1.0000000000000001E-7 ) / - 1.0 * 1000.0 ;
t0 [ 338ULL ] = t29 ; t0 [ 339ULL ] =
Gate_Driver2_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 340ULL ] =
Gate_Driver2_Controlled_Voltage_Source_n_v ; t0 [ 341ULL ] = t29 * 0.0001 ;
t0 [ 342ULL ] = - ( t30 * t30 * 0.01 ) / - 1.0 * 1000.0 ; t0 [ 343ULL ] = t30
; t0 [ 344ULL ] = t26 ; t0 [ 345ULL ] =
Gate_Driver2_Controlled_Voltage_Source_p_v ; t0 [ 346ULL ] = t30 * 10.0 ; t0
[ 347ULL ] = t26 ; t0 [ 348ULL ] = Gate_Driver2_Controlled_Voltage_Source_p_v
; t0 [ 349ULL ] = - ( t31 * t31 * 0.002 ) / - 1.0 * 1000.0 ; t0 [ 350ULL ] =
t31 ; t0 [ 351ULL ] = t26 ; t0 [ 352ULL ] =
Gate_Driver2_Diode_diode_junctionCapacitance_p_v ; t0 [ 353ULL ] = t31 * 2.0
; t0 [ 354ULL ] = t26 ; t0 [ 355ULL ] =
Gate_Driver2_Diode_diode_junctionCapacitance_p_v ; t0 [ 356ULL ] =
Gate_Driver2_Inductor_n_v ; t0 [ 357ULL ] = t25 ; t0 [ 358ULL ] =
Gate_Driver2_Controlled_Voltage_Source_n_v ; t0 [ 359ULL ] = t32 ; t0 [
360ULL ] = 0.0 ; t0 [ 361ULL ] = Gate_Driver2_Controlled_Voltage_Source_n_v ;
t0 [ 362ULL ] = t25 ; t0 [ 363ULL ] = t32 ; t0 [ 364ULL ] = ( ( ( X [ 94ULL ]
* 1.0E-9 + X [ 95ULL ] * 1.0E-9 ) + - X [ 96ULL ] ) + X [ 30ULL ] ) + X [
31ULL ] ; t0 [ 365ULL ] = Gate_Driver3_Controlled_Voltage_Source_n_v ; t0 [
366ULL ] = Gate_Driver3_Controlled_Voltage_Source_p_v ; t0 [ 367ULL ] =
U_idx_3 ; t0 [ 368ULL ] = U_idx_3 ; t0 [ 369ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_I ; t0 [ 370ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_I ; t0 [ 371ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_n_v ; t0 [ 372ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_n_v ; t0 [ 373ULL ] = 0.0 ; t0 [
374ULL ] = Gate_Driver3_Current_Measure_Current_Sensor1_n_v ; t0 [ 375ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_n_v ; t0 [ 376ULL ] = 0.0 ; t0 [
377ULL ] = X [ 100ULL ] ; t0 [ 378ULL ] = X [ 34ULL ] ; t0 [ 379ULL ] = X [
100ULL ] ; t0 [ 380ULL ] = Gate_Driver3_Controlled_Voltage_Source_p_v ; t0 [
381ULL ] = Gate_Driver3_Diode_diode_junctionCapacitance_p_v ; t0 [ 382ULL ] =
Gate_Driver3_Diode_diode_junctionCapacitance_v ; t0 [ 383ULL ] = - (
Gate_Driver3_Diode_diode_i * Gate_Driver3_Diode_diode_junctionCapacitance_v *
0.001 ) / - 1.0 * 1000.0 ; t0 [ 384ULL ] =
Gate_Driver3_Diode_diode_junctionCapacitance_v ; t0 [ 385ULL ] =
Gate_Driver3_Diode_diode_i ; t0 [ 386ULL ] =
Gate_Driver3_Controlled_Voltage_Source_p_v ; t0 [ 387ULL ] =
Gate_Driver3_Diode_diode_junctionCapacitance_p_v ; t0 [ 388ULL ] =
Gate_Driver3_Diode_diode_junctionCapacitance_v ; t0 [ 389ULL ] = X [ 100ULL ]
; t0 [ 390ULL ] = Gate_Driver3_Diode_diode_junctionCapacitance_v ; t0 [
391ULL ] = Gate_Driver3_Controlled_Voltage_Source_p_v ; t0 [ 392ULL ] =
Gate_Driver3_Diode_diode_junctionCapacitance_p_v ; t0 [ 393ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_n_v ; t0 [ 394ULL ] = t34 ; t0 [
395ULL ] = X [ 30ULL ] ; t0 [ 396ULL ] = - ( X [ 94ULL ] * X [ 94ULL ] *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 397ULL ] = X [ 94ULL ] ; t0
[ 398ULL ] = Gate_Driver3_Inductor_n_v ; t0 [ 399ULL ] =
Gate_Driver3_Controlled_Voltage_Source_n_v ; t0 [ 400ULL ] = -
Gate_Driver3_Current_Measure_Current_Sensor1_I ; t0 [ 401ULL ] = X [ 31ULL ]
; t0 [ 402ULL ] = - ( X [ 95ULL ] * X [ 95ULL ] * 1.0000000000000002E-12 ) /
- 1.0 * 1000.0 ; t0 [ 403ULL ] = X [ 95ULL ] ; t0 [ 404ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_n_v ; t0 [ 405ULL ] = t35 ; t0 [
406ULL ] = t35 ; t0 [ 407ULL ] = t36 ; t0 [ 408ULL ] =
Gate_Driver3_Controlled_Voltage_Source_n_v ; t0 [ 409ULL ] = X [ 32ULL ] ; t0
[ 410ULL ] = X [ 97ULL ] ; t0 [ 411ULL ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 412ULL ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 413ULL ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 414ULL ] = X [ 33ULL ] ;
t0 [ 415ULL ] = - X [ 99ULL ] + X [ 96ULL ] ; t0 [ 416ULL ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 417ULL ] = X [ 98ULL ]
; t0 [ 418ULL ] = ( X [ 99ULL ] * - 1.0E-6 + X [ 96ULL ] * 1.0E-6 ) + X [
33ULL ] ; t0 [ 419ULL ] = X [ 35ULL ] ; t0 [ 420ULL ] = X [ 99ULL ] ; t0 [
421ULL ] = Gate_Driver3_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 422ULL ] = X
[ 98ULL ] ; t0 [ 423ULL ] = Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v ; t0
[ 424ULL ] = - ( Gate_Driver3_Current_Measure_Current_Sensor1_I *
Gate_Driver3_Current_Measure_Current_Sensor1_I * 1.0000000000000001E-7 ) / -
1.0 * 1000.0 ; t0 [ 425ULL ] = Gate_Driver3_Current_Measure_Current_Sensor1_I
; t0 [ 426ULL ] = Gate_Driver3_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [
427ULL ] = t35 ; t0 [ 428ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_I * 0.0001 ; t0 [ 429ULL ] = - (
X [ 96ULL ] * X [ 96ULL ] * 1.0E-6 ) / - 1.0 * 1000.0 ; t0 [ 430ULL ] = X [
96ULL ] ; t0 [ 431ULL ] = X [ 98ULL ] ; t0 [ 432ULL ] = t36 ; t0 [ 433ULL ] =
X [ 96ULL ] * 0.001 ; t0 [ 434ULL ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 435ULL ] = X [ 98ULL ]
; t0 [ 436ULL ] = Gate_Driver3_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [
437ULL ] = t38 ; t0 [ 438ULL ] = 0.0 ; t0 [ 439ULL ] = - (
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v * t38 * 0.001 ) / - 1.0 * 1000.0
; t0 [ 440ULL ] = Gate_Driver3_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 441ULL
] = Gate_Driver3_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 442ULL ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 443ULL ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 444ULL ] = X [ 98ULL ]
; t0 [ 445ULL ] = - ( t39 * t39 * 1.0000000000000001E-7 ) / - 1.0 * 1000.0 ;
t0 [ 446ULL ] = t39 ; t0 [ 447ULL ] =
Gate_Driver3_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 448ULL ] =
Gate_Driver3_Controlled_Voltage_Source_n_v ; t0 [ 449ULL ] = t39 * 0.0001 ;
t0 [ 450ULL ] = - ( t40 * t40 * 0.01 ) / - 1.0 * 1000.0 ; t0 [ 451ULL ] = t40
; t0 [ 452ULL ] = t36 ; t0 [ 453ULL ] =
Gate_Driver3_Controlled_Voltage_Source_p_v ; t0 [ 454ULL ] = t40 * 10.0 ; t0
[ 455ULL ] = t36 ; t0 [ 456ULL ] = Gate_Driver3_Controlled_Voltage_Source_p_v
; t0 [ 457ULL ] = - ( t41 * t41 * 0.002 ) / - 1.0 * 1000.0 ; t0 [ 458ULL ] =
t41 ; t0 [ 459ULL ] = t36 ; t0 [ 460ULL ] =
Gate_Driver3_Diode_diode_junctionCapacitance_p_v ; t0 [ 461ULL ] = t41 * 2.0
; t0 [ 462ULL ] = t36 ; t0 [ 463ULL ] =
Gate_Driver3_Diode_diode_junctionCapacitance_p_v ; t0 [ 464ULL ] =
Gate_Driver3_Inductor_n_v ; t0 [ 465ULL ] = t35 ; t0 [ 466ULL ] =
Gate_Driver3_Controlled_Voltage_Source_n_v ; t0 [ 467ULL ] = t42 ; t0 [
468ULL ] = 0.0 ; t0 [ 469ULL ] = Gate_Driver3_Controlled_Voltage_Source_n_v ;
t0 [ 470ULL ] = t35 ; t0 [ 471ULL ] = t42 ; t0 [ 472ULL ] = ( ( ( X [ 101ULL
] * 1.0E-9 + X [ 102ULL ] * 1.0E-9 ) + - X [ 103ULL ] ) + X [ 36ULL ] ) + X [
37ULL ] ; t0 [ 473ULL ] = Gate_Driver4_Controlled_Voltage_Source_n_v ; t0 [
474ULL ] = Gate_Driver4_Controlled_Voltage_Source_p_v ; t0 [ 475ULL ] =
U_idx_4 ; t0 [ 476ULL ] = U_idx_4 ; t0 [ 477ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_I ; t0 [ 478ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_I ; t0 [ 479ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_n_v ; t0 [ 480ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_n_v ; t0 [ 481ULL ] = 0.0 ; t0 [
482ULL ] = Gate_Driver4_Current_Measure_Current_Sensor1_n_v ; t0 [ 483ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_n_v ; t0 [ 484ULL ] = 0.0 ; t0 [
485ULL ] = X [ 106ULL ] ; t0 [ 486ULL ] = X [ 40ULL ] ; t0 [ 487ULL ] = X [
106ULL ] ; t0 [ 488ULL ] = Gate_Driver4_Controlled_Voltage_Source_p_v ; t0 [
489ULL ] = Gate_Driver4_Diode_diode_junctionCapacitance_p_v ; t0 [ 490ULL ] =
Gate_Driver4_Diode_diode_junctionCapacitance_v ; t0 [ 491ULL ] = - (
Gate_Driver4_Diode_diode_i * Gate_Driver4_Diode_diode_junctionCapacitance_v *
0.001 ) / - 1.0 * 1000.0 ; t0 [ 492ULL ] =
Gate_Driver4_Diode_diode_junctionCapacitance_v ; t0 [ 493ULL ] =
Gate_Driver4_Diode_diode_i ; t0 [ 494ULL ] =
Gate_Driver4_Controlled_Voltage_Source_p_v ; t0 [ 495ULL ] =
Gate_Driver4_Diode_diode_junctionCapacitance_p_v ; t0 [ 496ULL ] =
Gate_Driver4_Diode_diode_junctionCapacitance_v ; t0 [ 497ULL ] = X [ 106ULL ]
; t0 [ 498ULL ] = Gate_Driver4_Diode_diode_junctionCapacitance_v ; t0 [
499ULL ] = Gate_Driver4_Controlled_Voltage_Source_p_v ; t0 [ 500ULL ] =
Gate_Driver4_Diode_diode_junctionCapacitance_p_v ; t0 [ 501ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_n_v ; t0 [ 502ULL ] = t44 ; t0 [
503ULL ] = X [ 36ULL ] ; t0 [ 504ULL ] = - ( X [ 101ULL ] * X [ 101ULL ] *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 505ULL ] = X [ 101ULL ] ; t0
[ 506ULL ] = Gate_Driver4_Inductor_n_v ; t0 [ 507ULL ] =
Gate_Driver4_Controlled_Voltage_Source_n_v ; t0 [ 508ULL ] = -
Gate_Driver4_Current_Measure_Current_Sensor1_I ; t0 [ 509ULL ] = X [ 37ULL ]
; t0 [ 510ULL ] = - ( X [ 102ULL ] * X [ 102ULL ] * 1.0000000000000002E-12 )
/ - 1.0 * 1000.0 ; t0 [ 511ULL ] = X [ 102ULL ] ; t0 [ 512ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_n_v ; t0 [ 513ULL ] = t45 ; t0 [
514ULL ] = t45 ; t0 [ 515ULL ] = t46 ; t0 [ 516ULL ] =
Gate_Driver4_Controlled_Voltage_Source_n_v ; t0 [ 517ULL ] = X [ 38ULL ] ; t0
[ 518ULL ] = X [ 104ULL ] ; t0 [ 519ULL ] =
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 520ULL ] = X [ 105ULL ]
; t0 [ 521ULL ] = Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 522ULL
] = X [ 39ULL ] ; t0 [ 523ULL ] = - X [ 107ULL ] + X [ 103ULL ] ; t0 [ 524ULL
] = X [ 105ULL ] ; t0 [ 525ULL ] =
Gate_Driver4_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [ 526ULL ] = ( X [ 107ULL
] * - 1.0E-6 + X [ 103ULL ] * 1.0E-6 ) + X [ 39ULL ] ; t0 [ 527ULL ] = X [
41ULL ] ; t0 [ 528ULL ] = X [ 107ULL ] ; t0 [ 529ULL ] =
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 530ULL ] =
Gate_Driver4_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [ 531ULL ] =
Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 532ULL ] = - (
Gate_Driver4_Current_Measure_Current_Sensor1_I *
Gate_Driver4_Current_Measure_Current_Sensor1_I * 1.0000000000000001E-7 ) / -
1.0 * 1000.0 ; t0 [ 533ULL ] = Gate_Driver4_Current_Measure_Current_Sensor1_I
; t0 [ 534ULL ] = X [ 105ULL ] ; t0 [ 535ULL ] = t45 ; t0 [ 536ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_I * 0.0001 ; t0 [ 537ULL ] = - (
X [ 103ULL ] * X [ 103ULL ] * 1.0E-6 ) / - 1.0 * 1000.0 ; t0 [ 538ULL ] = X [
103ULL ] ; t0 [ 539ULL ] = Gate_Driver4_N_Channel_MOSFET_capacitor_GD_p_v ;
t0 [ 540ULL ] = t46 ; t0 [ 541ULL ] = X [ 103ULL ] * 0.001 ; t0 [ 542ULL ] =
X [ 105ULL ] ; t0 [ 543ULL ] = Gate_Driver4_N_Channel_MOSFET_capacitor_GD_p_v
; t0 [ 544ULL ] = Gate_Driver4_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [
545ULL ] = t48 ; t0 [ 546ULL ] = 0.0 ; t0 [ 547ULL ] = - (
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v * t48 * 0.001 ) / - 1.0 * 1000.0
; t0 [ 548ULL ] = Gate_Driver4_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 549ULL
] = Gate_Driver4_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 550ULL ] =
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 551ULL ] = X [ 105ULL ]
; t0 [ 552ULL ] = Gate_Driver4_N_Channel_MOSFET_capacitor_GD_p_v ; t0 [
553ULL ] = - ( t49 * t49 * 1.0000000000000001E-7 ) / - 1.0 * 1000.0 ; t0 [
554ULL ] = t49 ; t0 [ 555ULL ] =
Gate_Driver4_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 556ULL ] =
Gate_Driver4_Controlled_Voltage_Source_n_v ; t0 [ 557ULL ] = t49 * 0.0001 ;
t0 [ 558ULL ] = - ( t50 * t50 * 0.01 ) / - 1.0 * 1000.0 ; t0 [ 559ULL ] = t50
; t0 [ 560ULL ] = t46 ; t0 [ 561ULL ] =
Gate_Driver4_Controlled_Voltage_Source_p_v ; t0 [ 562ULL ] = t50 * 10.0 ; t0
[ 563ULL ] = t46 ; t0 [ 564ULL ] = Gate_Driver4_Controlled_Voltage_Source_p_v
; t0 [ 565ULL ] = - ( t51 * t51 * 0.002 ) / - 1.0 * 1000.0 ; t0 [ 566ULL ] =
t51 ; t0 [ 567ULL ] = t46 ; t0 [ 568ULL ] =
Gate_Driver4_Diode_diode_junctionCapacitance_p_v ; t0 [ 569ULL ] = t51 * 2.0
; t0 [ 570ULL ] = t46 ; t0 [ 571ULL ] =
Gate_Driver4_Diode_diode_junctionCapacitance_p_v ; t0 [ 572ULL ] =
Gate_Driver4_Inductor_n_v ; t0 [ 573ULL ] = t45 ; t0 [ 574ULL ] =
Gate_Driver4_Controlled_Voltage_Source_n_v ; t0 [ 575ULL ] = t52 ; t0 [
576ULL ] = 0.0 ; t0 [ 577ULL ] = Gate_Driver4_Controlled_Voltage_Source_n_v ;
t0 [ 578ULL ] = t45 ; t0 [ 579ULL ] = t52 ; t0 [ 580ULL ] = ( ( ( X [ 108ULL
] * 1.0E-9 + X [ 109ULL ] * 1.0E-9 ) + - X [ 110ULL ] ) + X [ 42ULL ] ) + X [
43ULL ] ; t0 [ 581ULL ] = Gate_Driver5_Controlled_Voltage_Source_n_v ; t0 [
582ULL ] = Gate_Driver5_Controlled_Voltage_Source_p_v ; t0 [ 583ULL ] =
U_idx_5 ; t0 [ 584ULL ] = U_idx_5 ; t0 [ 585ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_I ; t0 [ 586ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_I ; t0 [ 587ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_n_v ; t0 [ 588ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_n_v ; t0 [ 589ULL ] = 0.0 ; t0 [
590ULL ] = Gate_Driver5_Current_Measure_Current_Sensor1_n_v ; t0 [ 591ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_n_v ; t0 [ 592ULL ] = 0.0 ; t0 [
593ULL ] = X [ 114ULL ] ; t0 [ 594ULL ] = X [ 46ULL ] ; t0 [ 595ULL ] = X [
114ULL ] ; t0 [ 596ULL ] = Gate_Driver5_Controlled_Voltage_Source_p_v ; t0 [
597ULL ] = Gate_Driver5_Diode_diode_junctionCapacitance_p_v ; t0 [ 598ULL ] =
Gate_Driver5_Diode_diode_junctionCapacitance_v ; t0 [ 599ULL ] = - (
Gate_Driver5_Diode_diode_i * Gate_Driver5_Diode_diode_junctionCapacitance_v *
0.001 ) / - 1.0 * 1000.0 ; t0 [ 600ULL ] =
Gate_Driver5_Diode_diode_junctionCapacitance_v ; t0 [ 601ULL ] =
Gate_Driver5_Diode_diode_i ; t0 [ 602ULL ] =
Gate_Driver5_Controlled_Voltage_Source_p_v ; t0 [ 603ULL ] =
Gate_Driver5_Diode_diode_junctionCapacitance_p_v ; t0 [ 604ULL ] =
Gate_Driver5_Diode_diode_junctionCapacitance_v ; t0 [ 605ULL ] = X [ 114ULL ]
; t0 [ 606ULL ] = Gate_Driver5_Diode_diode_junctionCapacitance_v ; t0 [
607ULL ] = Gate_Driver5_Controlled_Voltage_Source_p_v ; t0 [ 608ULL ] =
Gate_Driver5_Diode_diode_junctionCapacitance_p_v ; t0 [ 609ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_n_v ; t0 [ 610ULL ] = t54 ; t0 [
611ULL ] = X [ 42ULL ] ; t0 [ 612ULL ] = - ( X [ 108ULL ] * X [ 108ULL ] *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 613ULL ] = X [ 108ULL ] ; t0
[ 614ULL ] = Gate_Driver5_Inductor_n_v ; t0 [ 615ULL ] =
Gate_Driver5_Controlled_Voltage_Source_n_v ; t0 [ 616ULL ] = -
Gate_Driver5_Current_Measure_Current_Sensor1_I ; t0 [ 617ULL ] = X [ 43ULL ]
; t0 [ 618ULL ] = - ( X [ 109ULL ] * X [ 109ULL ] * 1.0000000000000002E-12 )
/ - 1.0 * 1000.0 ; t0 [ 619ULL ] = X [ 109ULL ] ; t0 [ 620ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_n_v ; t0 [ 621ULL ] = t55 ; t0 [
622ULL ] = t55 ; t0 [ 623ULL ] = t56 ; t0 [ 624ULL ] =
Gate_Driver5_Controlled_Voltage_Source_n_v ; t0 [ 625ULL ] = X [ 44ULL ] ; t0
[ 626ULL ] = X [ 111ULL ] ; t0 [ 627ULL ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 628ULL ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 629ULL ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 630ULL ] = X [ 45ULL ] ;
t0 [ 631ULL ] = - X [ 113ULL ] + X [ 110ULL ] ; t0 [ 632ULL ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 633ULL ] = X [ 112ULL ]
; t0 [ 634ULL ] = ( X [ 113ULL ] * - 1.0E-6 + X [ 110ULL ] * 1.0E-6 ) + X [
45ULL ] ; t0 [ 635ULL ] = X [ 47ULL ] ; t0 [ 636ULL ] = X [ 113ULL ] ; t0 [
637ULL ] = Gate_Driver5_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 638ULL ] = X
[ 112ULL ] ; t0 [ 639ULL ] = Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v ;
t0 [ 640ULL ] = - ( Gate_Driver5_Current_Measure_Current_Sensor1_I *
Gate_Driver5_Current_Measure_Current_Sensor1_I * 1.0000000000000001E-7 ) / -
1.0 * 1000.0 ; t0 [ 641ULL ] = Gate_Driver5_Current_Measure_Current_Sensor1_I
; t0 [ 642ULL ] = Gate_Driver5_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [
643ULL ] = t55 ; t0 [ 644ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_I * 0.0001 ; t0 [ 645ULL ] = - (
X [ 110ULL ] * X [ 110ULL ] * 1.0E-6 ) / - 1.0 * 1000.0 ; t0 [ 646ULL ] = X [
110ULL ] ; t0 [ 647ULL ] = X [ 112ULL ] ; t0 [ 648ULL ] = t56 ; t0 [ 649ULL ]
= X [ 110ULL ] * 0.001 ; t0 [ 650ULL ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 651ULL ] = X [ 112ULL ]
; t0 [ 652ULL ] = Gate_Driver5_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [
653ULL ] = t58 ; t0 [ 654ULL ] = 0.0 ; t0 [ 655ULL ] = - (
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v * t58 * 0.001 ) / - 1.0 * 1000.0
; t0 [ 656ULL ] = Gate_Driver5_N_Channel_MOSFET_capacitor_DS_v ; t0 [ 657ULL
] = Gate_Driver5_N_Channel_MOSFET_capacitor_GS_v ; t0 [ 658ULL ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 659ULL ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_p_v ; t0 [ 660ULL ] = X [ 112ULL ]
; t0 [ 661ULL ] = - ( t59 * t59 * 1.0000000000000001E-7 ) / - 1.0 * 1000.0 ;
t0 [ 662ULL ] = t59 ; t0 [ 663ULL ] =
Gate_Driver5_N_Channel_MOSFET_capacitor_DS_n_v ; t0 [ 664ULL ] =
Gate_Driver5_Controlled_Voltage_Source_n_v ; t0 [ 665ULL ] = t59 * 0.0001 ;
t0 [ 666ULL ] = - ( t60 * t60 * 0.01 ) / - 1.0 * 1000.0 ; t0 [ 667ULL ] = t60
; t0 [ 668ULL ] = t56 ; t0 [ 669ULL ] =
Gate_Driver5_Controlled_Voltage_Source_p_v ; t0 [ 670ULL ] = t60 * 10.0 ; t0
[ 671ULL ] = t56 ; t0 [ 672ULL ] = Gate_Driver5_Controlled_Voltage_Source_p_v
; t0 [ 673ULL ] = - ( t61 * t61 * 0.002 ) / - 1.0 * 1000.0 ; t0 [ 674ULL ] =
t61 ; t0 [ 675ULL ] = t56 ; t0 [ 676ULL ] =
Gate_Driver5_Diode_diode_junctionCapacitance_p_v ; t0 [ 677ULL ] = t61 * 2.0
; t0 [ 678ULL ] = t56 ; t0 [ 679ULL ] =
Gate_Driver5_Diode_diode_junctionCapacitance_p_v ; t0 [ 680ULL ] =
Gate_Driver5_Inductor_n_v ; t0 [ 681ULL ] = t55 ; t0 [ 682ULL ] =
Gate_Driver5_Controlled_Voltage_Source_n_v ; t0 [ 683ULL ] = t62 ; t0 [
684ULL ] = 0.0 ; t0 [ 685ULL ] = Gate_Driver5_Controlled_Voltage_Source_n_v ;
t0 [ 686ULL ] = t55 ; t0 [ 687ULL ] = t62 ; t0 [ 688ULL ] = -
Gate_Driver_Current_Measure_Current_Sensor1_I ; t0 [ 689ULL ] = X [ 48ULL ] ;
t0 [ 690ULL ] = - ( Inductor_v * Inductor_v * 1.0000000000000002E-12 ) / -
1.0 * 1000.0 ; t0 [ 691ULL ] = Inductor_v ; t0 [ 692ULL ] = t63 ; t0 [ 693ULL
] = Gate_Driver_Current_Measure_Current_Sensor1_n_v ; t0 [ 694ULL ] = t34 ;
t0 [ 695ULL ] = X [ 49ULL ] ; t0 [ 696ULL ] = - ( Inductor1_v * Inductor1_v *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 697ULL ] = Inductor1_v ; t0
[ 698ULL ] = t64 ; t0 [ 699ULL ] = Gate_Driver3_Inductor_n_v ; t0 [ 700ULL ]
= t65 ; t0 [ 701ULL ] = X [ 10ULL ] ; t0 [ 702ULL ] = - ( X [ 72ULL ] * X [
72ULL ] * 1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 703ULL ] = X [
72ULL ] ; t0 [ 704ULL ] = Inductor10_n_v ; t0 [ 705ULL ] = Capacitor2_p_v ;
t0 [ 706ULL ] = t66 ; t0 [ 707ULL ] = X [ 9ULL ] ; t0 [ 708ULL ] = - ( X [
71ULL ] * X [ 71ULL ] * 1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [
709ULL ] = X [ 71ULL ] ; t0 [ 710ULL ] = Inductor11_n_v ; t0 [ 711ULL ] =
Inductor11_p_v ; t0 [ 712ULL ] = - t4 ; t0 [ 713ULL ] = X [ 50ULL ] ; t0 [
714ULL ] = - ( X [ 115ULL ] * X [ 115ULL ] * 1.0000000000000002E-12 ) / - 1.0
* 1000.0 ; t0 [ 715ULL ] = X [ 115ULL ] ; t0 [ 716ULL ] = t67 ; t0 [ 717ULL ]
= Inductor12_p_v ; t0 [ 718ULL ] =
Gate_Driver3_Current_Measure_Current_Sensor1_I ; t0 [ 719ULL ] = X [ 51ULL ]
; t0 [ 720ULL ] = - ( Inductor13_v * Inductor13_v * 1.0000000000000002E-12 )
/ - 1.0 * 1000.0 ; t0 [ 721ULL ] = Inductor13_v ; t0 [ 722ULL ] = t68 ; t0 [
723ULL ] = Inductor12_p_v ; t0 [ 724ULL ] = - t14 ; t0 [ 725ULL ] = X [ 52ULL
] ; t0 [ 726ULL ] = - ( X [ 116ULL ] * X [ 116ULL ] * 1.0000000000000002E-12
) / - 1.0 * 1000.0 ; t0 [ 727ULL ] = X [ 116ULL ] ; t0 [ 728ULL ] = t69 ; t0
[ 729ULL ] = Inductor14_p_v ; t0 [ 730ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_I ; t0 [ 731ULL ] = X [ 53ULL ]
; t0 [ 732ULL ] = - ( Inductor15_v * Inductor15_v * 1.0000000000000002E-12 )
/ - 1.0 * 1000.0 ; t0 [ 733ULL ] = Inductor15_v ; t0 [ 734ULL ] = t70 ; t0 [
735ULL ] = Inductor14_p_v ; t0 [ 736ULL ] = - t44 ; t0 [ 737ULL ] = X [ 54ULL
] ; t0 [ 738ULL ] = - ( X [ 117ULL ] * X [ 117ULL ] * 1.0000000000000002E-12
) / - 1.0 * 1000.0 ; t0 [ 739ULL ] = X [ 117ULL ] ; t0 [ 740ULL ] = t71 ; t0
[ 741ULL ] = Inductor16_p_v ; t0 [ 742ULL ] =
Gate_Driver5_Current_Measure_Current_Sensor1_I ; t0 [ 743ULL ] = X [ 55ULL ]
; t0 [ 744ULL ] = - ( Inductor17_v * Inductor17_v * 1.0000000000000002E-12 )
/ - 1.0 * 1000.0 ; t0 [ 745ULL ] = Inductor17_v ; t0 [ 746ULL ] = t72 ; t0 [
747ULL ] = Inductor16_p_v ; t0 [ 748ULL ] = Capacitor_i ; t0 [ 749ULL ] = X [
0ULL ] ; t0 [ 750ULL ] = - ( X [ 64ULL ] * X [ 64ULL ] *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 751ULL ] = X [ 64ULL ] ; t0
[ 752ULL ] = t73 ; t0 [ 753ULL ] = Capacitor_n_v ; t0 [ 754ULL ] =
Capacitor1_i ; t0 [ 755ULL ] = X [ 3ULL ] ; t0 [ 756ULL ] = - ( X [ 66ULL ] *
X [ 66ULL ] * 1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 757ULL ] = X [
66ULL ] ; t0 [ 758ULL ] = t74 ; t0 [ 759ULL ] = Capacitor1_n_v ; t0 [ 760ULL
] = - Gate_Driver1_Current_Measure_Current_Sensor1_I ; t0 [ 761ULL ] = X [
56ULL ] ; t0 [ 762ULL ] = - ( Inductor2_v * Inductor2_v *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 763ULL ] = Inductor2_v ; t0
[ 764ULL ] = t75 ; t0 [ 765ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_n_v ; t0 [ 766ULL ] =
Capacitor2_i ; t0 [ 767ULL ] = X [ 8ULL ] ; t0 [ 768ULL ] = - ( X [ 70ULL ] *
X [ 70ULL ] * 1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 769ULL ] = X [
70ULL ] ; t0 [ 770ULL ] = Inductor11_p_v ; t0 [ 771ULL ] = Capacitor2_n_v ;
t0 [ 772ULL ] = t77 ; t0 [ 773ULL ] = X [ 57ULL ] ; t0 [ 774ULL ] = - ( X [
118ULL ] * X [ 118ULL ] * 1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [
775ULL ] = X [ 118ULL ] ; t0 [ 776ULL ] = - X [ 118ULL ] ; t0 [ 777ULL ] =
0.0 ; t0 [ 778ULL ] = t24 ; t0 [ 779ULL ] = X [ 58ULL ] ; t0 [ 780ULL ] = - (
Inductor3_v * Inductor3_v * 1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [
781ULL ] = Inductor3_v ; t0 [ 782ULL ] = t78 ; t0 [ 783ULL ] =
Gate_Driver2_Inductor_n_v ; t0 [ 784ULL ] = -
Gate_Driver4_Current_Measure_Current_Sensor1_I ; t0 [ 785ULL ] = X [ 59ULL ]
; t0 [ 786ULL ] = - ( Inductor4_v * Inductor4_v * 1.0000000000000002E-12 ) /
- 1.0 * 1000.0 ; t0 [ 787ULL ] = Inductor4_v ; t0 [ 788ULL ] = t79 ; t0 [
789ULL ] = Gate_Driver4_Current_Measure_Current_Sensor1_n_v ; t0 [ 790ULL ] =
t54 ; t0 [ 791ULL ] = X [ 60ULL ] ; t0 [ 792ULL ] = - ( Inductor5_v *
Inductor5_v * 1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 793ULL ] =
Inductor5_v ; t0 [ 794ULL ] = t80 ; t0 [ 795ULL ] = Gate_Driver5_Inductor_n_v
; t0 [ 796ULL ] = t81 ; t0 [ 797ULL ] = X [ 5ULL ] ; t0 [ 798ULL ] = - ( X [
68ULL ] * X [ 68ULL ] * 1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [
799ULL ] = X [ 68ULL ] ; t0 [ 800ULL ] = Inductor6_n_v ; t0 [ 801ULL ] =
Capacitor_p_v ; t0 [ 802ULL ] = t82 ; t0 [ 803ULL ] = X [ 1ULL ] ; t0 [
804ULL ] = - ( X [ 65ULL ] * X [ 65ULL ] * 1.0000000000000002E-12 ) / - 1.0 *
1000.0 ; t0 [ 805ULL ] = X [ 65ULL ] ; t0 [ 806ULL ] = Inductor7_n_v ; t0 [
807ULL ] = t73 ; t0 [ 808ULL ] = t83 ; t0 [ 809ULL ] = X [ 6ULL ] ; t0 [
810ULL ] = - ( X [ 69ULL ] * X [ 69ULL ] * 1.0000000000000002E-12 ) / - 1.0 *
1000.0 ; t0 [ 811ULL ] = X [ 69ULL ] ; t0 [ 812ULL ] = Inductor8_n_v ; t0 [
813ULL ] = Capacitor1_p_v ; t0 [ 814ULL ] = t84 ; t0 [ 815ULL ] = X [ 4ULL ]
; t0 [ 816ULL ] = - ( X [ 67ULL ] * X [ 67ULL ] * 1.0000000000000002E-12 ) /
- 1.0 * 1000.0 ; t0 [ 817ULL ] = X [ 67ULL ] ; t0 [ 818ULL ] = Inductor9_n_v
; t0 [ 819ULL ] = t74 ; t0 [ 820ULL ] = Inductor12_p_v ; t0 [ 821ULL ] =
Inductor14_p_v ; t0 [ 822ULL ] = Inductor16_p_v ; t0 [ 823ULL ] = t85 ; t0 [
824ULL ] = t85 ; t0 [ 825ULL ] = Inductor14_p_v ; t0 [ 826ULL ] =
Inductor14_p_v ; t0 [ 827ULL ] = 0.0 ; t0 [ 828ULL ] = Inductor14_p_v ; t0 [
829ULL ] = Inductor14_p_v ; t0 [ 830ULL ] =
R_L_Load_Current_Measure2_Current_Sensor1_I ; t0 [ 831ULL ] =
R_L_Load_Current_Measure2_Current_Sensor1_I ; t0 [ 832ULL ] = Inductor16_p_v
; t0 [ 833ULL ] = Inductor16_p_v ; t0 [ 834ULL ] = 0.0 ; t0 [ 835ULL ] =
Inductor16_p_v ; t0 [ 836ULL ] = Inductor16_p_v ; t0 [ 837ULL ] =
R_L_Load_Current_Measure5_Current_Sensor1_I ; t0 [ 838ULL ] =
R_L_Load_Current_Measure5_Current_Sensor1_I ; t0 [ 839ULL ] = Inductor12_p_v
; t0 [ 840ULL ] = Inductor12_p_v ; t0 [ 841ULL ] = 0.0 ; t0 [ 842ULL ] =
Inductor12_p_v ; t0 [ 843ULL ] = Inductor12_p_v ; t0 [ 844ULL ] =
R_L_Load_Current_Measure5_Current_Sensor1_I ; t0 [ 845ULL ] = X [ 63ULL ] ;
t0 [ 846ULL ] = - ( X [ 121ULL ] * X [ 121ULL ] * 1.0000000000000002E-12 ) /
- 1.0 * 1000.0 ; t0 [ 847ULL ] = X [ 121ULL ] ; t0 [ 848ULL ] = X [ 122ULL ]
; t0 [ 849ULL ] = R_L_Load_Inductor_p_v ; t0 [ 850ULL ] = t85 ; t0 [ 851ULL ]
= X [ 61ULL ] ; t0 [ 852ULL ] = - ( X [ 119ULL ] * X [ 119ULL ] *
1.0000000000000002E-12 ) / - 1.0 * 1000.0 ; t0 [ 853ULL ] = X [ 119ULL ] ; t0
[ 854ULL ] = X [ 122ULL ] ; t0 [ 855ULL ] = t86 ; t0 [ 856ULL ] =
R_L_Load_Current_Measure2_Current_Sensor1_I ; t0 [ 857ULL ] = X [ 62ULL ] ;
t0 [ 858ULL ] = - ( X [ 120ULL ] * X [ 120ULL ] * 1.0000000000000002E-12 ) /
- 1.0 * 1000.0 ; t0 [ 859ULL ] = X [ 120ULL ] ; t0 [ 860ULL ] = X [ 122ULL ]
; t0 [ 861ULL ] = t87 ; t0 [ 862ULL ] = - (
R_L_Load_Current_Measure5_Current_Sensor1_I *
R_L_Load_Current_Measure5_Current_Sensor1_I * 0.010620318644611201 ) / - 1.0
* 1000.0 ; t0 [ 863ULL ] = R_L_Load_Current_Measure5_Current_Sensor1_I ; t0 [
864ULL ] = R_L_Load_Inductor_p_v ; t0 [ 865ULL ] = Inductor12_p_v ; t0 [
866ULL ] = R_L_Load_Current_Measure5_Current_Sensor1_I * 10.620318644611201 ;
t0 [ 867ULL ] = R_L_Load_Inductor_p_v ; t0 [ 868ULL ] = Inductor12_p_v ; t0 [
869ULL ] = - ( t85 * t85 * 0.010620318644611201 ) / - 1.0 * 1000.0 ; t0 [
870ULL ] = t85 ; t0 [ 871ULL ] = t86 ; t0 [ 872ULL ] = Inductor14_p_v ; t0 [
873ULL ] = t85 * 10.620318644611201 ; t0 [ 874ULL ] = t86 ; t0 [ 875ULL ] =
Inductor14_p_v ; t0 [ 876ULL ] = - (
R_L_Load_Current_Measure2_Current_Sensor1_I *
R_L_Load_Current_Measure2_Current_Sensor1_I * 0.010620318644611201 ) / - 1.0
* 1000.0 ; t0 [ 877ULL ] = R_L_Load_Current_Measure2_Current_Sensor1_I ; t0 [
878ULL ] = t87 ; t0 [ 879ULL ] = Inductor16_p_v ; t0 [ 880ULL ] =
R_L_Load_Current_Measure2_Current_Sensor1_I * 10.620318644611201 ; t0 [
881ULL ] = t87 ; t0 [ 882ULL ] = Inductor16_p_v ; t0 [ 883ULL ] =
Inductor14_p_v ; t0 [ 884ULL ] = Inductor16_p_v ; t0 [ 885ULL ] = t91 ; t0 [
886ULL ] = 0.0 ; t0 [ 887ULL ] = Inductor16_p_v ; t0 [ 888ULL ] =
Inductor14_p_v ; t0 [ 889ULL ] = t91 ; t0 [ 890ULL ] = Inductor12_p_v ; t0 [
891ULL ] = Inductor16_p_v ; t0 [ 892ULL ] = t92 ; t0 [ 893ULL ] = 0.0 ; t0 [
894ULL ] = Inductor16_p_v ; t0 [ 895ULL ] = Inductor12_p_v ; t0 [ 896ULL ] =
t92 ; t0 [ 897ULL ] = Inductor12_p_v ; t0 [ 898ULL ] = Inductor14_p_v ; t0 [
899ULL ] = t93 ; t0 [ 900ULL ] = 0.0 ; t0 [ 901ULL ] = Inductor14_p_v ; t0 [
902ULL ] = Inductor12_p_v ; t0 [ 903ULL ] = t93 ; t0 [ 904ULL ] = - (
Gate_Driver_Current_Measure_Current_Sensor1_I *
Gate_Driver_Current_Measure_Current_Sensor1_I * 8.540000000000001E-7 ) / -
1.0 * 1000.0 ; t0 [ 905ULL ] = -
Gate_Driver_Current_Measure_Current_Sensor1_I ; t0 [ 906ULL ] = Capacitor_p_v
; t0 [ 907ULL ] = t63 ; t0 [ 908ULL ] =
Gate_Driver_Current_Measure_Current_Sensor1_I * - 0.000854 ; t0 [ 909ULL ] =
Capacitor_p_v ; t0 [ 910ULL ] = t63 ; t0 [ 911ULL ] = - ( t34 * t34 * 6.64E-7
) / - 1.0 * 1000.0 ; t0 [ 912ULL ] = t34 ; t0 [ 913ULL ] = t73 ; t0 [ 914ULL
] = t64 ; t0 [ 915ULL ] = t34 * 0.000664 ; t0 [ 916ULL ] = t73 ; t0 [ 917ULL
] = t64 ; t0 [ 918ULL ] = - ( t65 * t65 * 8.67E-7 ) / - 1.0 * 1000.0 ; t0 [
919ULL ] = t65 ; t0 [ 920ULL ] = t96 ; t0 [ 921ULL ] = Inductor10_n_v ; t0 [
922ULL ] = t65 * 0.000867 ; t0 [ 923ULL ] = t96 ; t0 [ 924ULL ] =
Inductor10_n_v ; t0 [ 925ULL ] = - ( t66 * t66 * 5.95E-7 ) / - 1.0 * 1000.0 ;
t0 [ 926ULL ] = t66 ; t0 [ 927ULL ] = 0.0 ; t0 [ 928ULL ] = Inductor11_n_v ;
t0 [ 929ULL ] = t66 * 0.000595 ; t0 [ 930ULL ] = 0.0 ; t0 [ 931ULL ] =
Inductor11_n_v ; t0 [ 932ULL ] = - ( t4 * t4 * 2.188E-7 ) / - 1.0 * 1000.0 ;
t0 [ 933ULL ] = - t4 ; t0 [ 934ULL ] = Gate_Driver_Inductor_n_v ; t0 [ 935ULL
] = t67 ; t0 [ 936ULL ] = t4 * - 0.0002188 ; t0 [ 937ULL ] =
Gate_Driver_Inductor_n_v ; t0 [ 938ULL ] = t67 ; t0 [ 939ULL ] = - (
Gate_Driver3_Current_Measure_Current_Sensor1_I *
Gate_Driver3_Current_Measure_Current_Sensor1_I * 2.188E-7 ) / - 1.0 * 1000.0
; t0 [ 940ULL ] = Gate_Driver3_Current_Measure_Current_Sensor1_I ; t0 [
941ULL ] = Gate_Driver3_Current_Measure_Current_Sensor1_n_v ; t0 [ 942ULL ] =
t68 ; t0 [ 943ULL ] = Gate_Driver3_Current_Measure_Current_Sensor1_I *
0.0002188 ; t0 [ 944ULL ] = Gate_Driver3_Current_Measure_Current_Sensor1_n_v
; t0 [ 945ULL ] = t68 ; t0 [ 946ULL ] = - ( t14 * t14 * 2.1800000000000002E-7
) / - 1.0 * 1000.0 ; t0 [ 947ULL ] = - t14 ; t0 [ 948ULL ] =
Gate_Driver1_Inductor_n_v ; t0 [ 949ULL ] = t69 ; t0 [ 950ULL ] = t14 * -
0.000218 ; t0 [ 951ULL ] = Gate_Driver1_Inductor_n_v ; t0 [ 952ULL ] = t69 ;
t0 [ 953ULL ] = - ( Gate_Driver2_Current_Measure_Current_Sensor1_I *
Gate_Driver2_Current_Measure_Current_Sensor1_I * 2.1800000000000002E-7 ) / -
1.0 * 1000.0 ; t0 [ 954ULL ] = Gate_Driver2_Current_Measure_Current_Sensor1_I
; t0 [ 955ULL ] = Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; t0 [
956ULL ] = t70 ; t0 [ 957ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_I * 0.000218 ; t0 [ 958ULL ] =
Gate_Driver2_Current_Measure_Current_Sensor1_n_v ; t0 [ 959ULL ] = t70 ; t0 [
960ULL ] = - ( t44 * t44 * 2.183E-7 ) / - 1.0 * 1000.0 ; t0 [ 961ULL ] = -
t44 ; t0 [ 962ULL ] = Gate_Driver4_Inductor_n_v ; t0 [ 963ULL ] = t71 ; t0 [
964ULL ] = t44 * - 0.0002183 ; t0 [ 965ULL ] = Gate_Driver4_Inductor_n_v ; t0
[ 966ULL ] = t71 ; t0 [ 967ULL ] = - (
Gate_Driver5_Current_Measure_Current_Sensor1_I *
Gate_Driver5_Current_Measure_Current_Sensor1_I * 2.183E-7 ) / - 1.0 * 1000.0
; t0 [ 968ULL ] = Gate_Driver5_Current_Measure_Current_Sensor1_I ; t0 [
969ULL ] = Gate_Driver5_Current_Measure_Current_Sensor1_n_v ; t0 [ 970ULL ] =
t72 ; t0 [ 971ULL ] = Gate_Driver5_Current_Measure_Current_Sensor1_I *
0.0002183 ; t0 [ 972ULL ] = Gate_Driver5_Current_Measure_Current_Sensor1_n_v
; t0 [ 973ULL ] = t72 ; t0 [ 974ULL ] = - ( t77 * t77 * 0.01 ) / - 1.0 *
1000.0 ; t0 [ 975ULL ] = t77 ; t0 [ 976ULL ] = t96 ; t0 [ 977ULL ] = - X [
118ULL ] + 344.07407407407408 ; t0 [ 978ULL ] = t77 * 10.0 ; t0 [ 979ULL ] =
t96 ; t0 [ 980ULL ] = - X [ 118ULL ] + 344.07407407407408 ; t0 [ 981ULL ] = -
( Gate_Driver1_Current_Measure_Current_Sensor1_I *
Gate_Driver1_Current_Measure_Current_Sensor1_I * 8.1300000000000009E-7 ) / -
1.0 * 1000.0 ; t0 [ 982ULL ] = -
Gate_Driver1_Current_Measure_Current_Sensor1_I ; t0 [ 983ULL ] =
Capacitor1_p_v ; t0 [ 984ULL ] = t75 ; t0 [ 985ULL ] =
Gate_Driver1_Current_Measure_Current_Sensor1_I * - 0.000813 ; t0 [ 986ULL ] =
Capacitor1_p_v ; t0 [ 987ULL ] = t75 ; t0 [ 988ULL ] = - ( t24 * t24 *
6.64E-7 ) / - 1.0 * 1000.0 ; t0 [ 989ULL ] = t24 ; t0 [ 990ULL ] = t74 ; t0 [
991ULL ] = t78 ; t0 [ 992ULL ] = t24 * 0.000664 ; t0 [ 993ULL ] = t74 ; t0 [
994ULL ] = t78 ; t0 [ 995ULL ] = - (
Gate_Driver4_Current_Measure_Current_Sensor1_I *
Gate_Driver4_Current_Measure_Current_Sensor1_I * 8.540000000000001E-7 ) / -
1.0 * 1000.0 ; t0 [ 996ULL ] = -
Gate_Driver4_Current_Measure_Current_Sensor1_I ; t0 [ 997ULL ] =
Capacitor2_p_v ; t0 [ 998ULL ] = t79 ; t0 [ 999ULL ] =
Gate_Driver4_Current_Measure_Current_Sensor1_I * - 0.000854 ; t0 [ 1000ULL ]
= Capacitor2_p_v ; t0 [ 1001ULL ] = t79 ; t0 [ 1002ULL ] = - ( t54 * t54 *
6.64E-7 ) / - 1.0 * 1000.0 ; t0 [ 1003ULL ] = t54 ; t0 [ 1004ULL ] =
Inductor11_p_v ; t0 [ 1005ULL ] = t80 ; t0 [ 1006ULL ] = t54 * 0.000664 ; t0
[ 1007ULL ] = Inductor11_p_v ; t0 [ 1008ULL ] = t80 ; t0 [ 1009ULL ] = - (
t81 * t81 * 1.037E-6 ) / - 1.0 * 1000.0 ; t0 [ 1010ULL ] = t81 ; t0 [ 1011ULL
] = t96 ; t0 [ 1012ULL ] = Inductor6_n_v ; t0 [ 1013ULL ] = t81 * 0.001037 ;
t0 [ 1014ULL ] = t96 ; t0 [ 1015ULL ] = Inductor6_n_v ; t0 [ 1016ULL ] = - (
t82 * t82 * 1.4220000000000001E-6 ) / - 1.0 * 1000.0 ; t0 [ 1017ULL ] = t82 ;
t0 [ 1018ULL ] = 0.0 ; t0 [ 1019ULL ] = Inductor7_n_v ; t0 [ 1020ULL ] = t82
* 0.001422 ; t0 [ 1021ULL ] = 0.0 ; t0 [ 1022ULL ] = Inductor7_n_v ; t0 [
1023ULL ] = - ( t83 * t83 * 6.1100000000000006E-7 ) / - 1.0 * 1000.0 ; t0 [
1024ULL ] = t83 ; t0 [ 1025ULL ] = t96 ; t0 [ 1026ULL ] = Inductor8_n_v ; t0
[ 1027ULL ] = t83 * 0.000611 ; t0 [ 1028ULL ] = t96 ; t0 [ 1029ULL ] =
Inductor8_n_v ; t0 [ 1030ULL ] = - ( t84 * t84 * 6.6200000000000008E-7 ) / -
1.0 * 1000.0 ; t0 [ 1031ULL ] = t84 ; t0 [ 1032ULL ] = 0.0 ; t0 [ 1033ULL ] =
Inductor9_n_v ; t0 [ 1034ULL ] = t84 * 0.000662 ; t0 [ 1035ULL ] = 0.0 ; t0 [
1036ULL ] = Inductor9_n_v ; t0 [ 1037ULL ] = Capacitor1_p_v ; t0 [ 1038ULL ]
= t74 ; t0 [ 1039ULL ] = t113 ; t0 [ 1040ULL ] = 0.0 ; t0 [ 1041ULL ] = t74 ;
t0 [ 1042ULL ] = Capacitor1_p_v ; t0 [ 1043ULL ] = t113 ; t0 [ 1044ULL ] =
Capacitor2_p_v ; t0 [ 1045ULL ] = Inductor11_p_v ; t0 [ 1046ULL ] = t114 ; t0
[ 1047ULL ] = 0.0 ; t0 [ 1048ULL ] = Inductor11_p_v ; t0 [ 1049ULL ] =
Capacitor2_p_v ; t0 [ 1050ULL ] = t114 ; t0 [ 1051ULL ] = Capacitor_p_v ; t0
[ 1052ULL ] = t73 ; t0 [ 1053ULL ] = t115 ; t0 [ 1054ULL ] = 0.0 ; t0 [
1055ULL ] = t73 ; t0 [ 1056ULL ] = Capacitor_p_v ; t0 [ 1057ULL ] = t115 ; t0
[ 1058ULL ] = - t77 ; t0 [ 1059ULL ] = - X [ 118ULL ] ; t0 [ 1060ULL ] = - X
[ 118ULL ] + 344.07407407407408 ; t0 [ 1061ULL ] = 344.07407407407408 ; t0 [
1062ULL ] = - t34 ; t0 [ 1063ULL ] = - t34 ; t0 [ 1064ULL ] =
Gate_Driver3_Inductor_n_v ; t0 [ 1065ULL ] = Gate_Driver3_Inductor_n_v ; t0 [
1066ULL ] = 0.0 ; t0 [ 1067ULL ] = Gate_Driver3_Inductor_n_v ; t0 [ 1068ULL ]
= Gate_Driver3_Inductor_n_v ; t0 [ 1069ULL ] = t77 ; t0 [ 1070ULL ] = t77 ;
t0 [ 1071ULL ] = t96 ; t0 [ 1072ULL ] = t96 ; t0 [ 1073ULL ] = 0.0 ; t0 [
1074ULL ] = t96 ; t0 [ 1075ULL ] = t96 ; for ( b = 0 ; b < 1076 ; b ++ ) {
out . mX [ b ] = t0 [ b ] ; } ( void ) sys ; ( void ) t118 ; return 0 ; }
