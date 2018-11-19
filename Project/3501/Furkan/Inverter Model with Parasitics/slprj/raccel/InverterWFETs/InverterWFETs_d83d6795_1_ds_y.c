#include "__cf_InverterWFETs.h"
#include "ne_ds.h"
#include "InverterWFETs_d83d6795_1_ds_y.h"
#include "InverterWFETs_d83d6795_1_ds_sys_struct.h"
#include "InverterWFETs_d83d6795_1_ds_externals.h"
#include "InverterWFETs_d83d6795_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T InverterWFETs_d83d6795_1_ds_y ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t13 , NeDsMethodOutput * t14 ) { PmRealVector out ;
real_T R_L_Load_Voltage_Measure1_Voltage_Sensor3_V ; real_T
R_L_Load_Voltage_Measure2_Voltage_Sensor3_V ; real_T
R_L_Load_Voltage_Measure3_Voltage_Sensor3_V ; real_T t11 ; real_T X [ 123 ] ;
int32_T b ; for ( b = 0 ; b < 123 ; b ++ ) { X [ b ] = t13 -> mX . mX [ b ] ;
} out = t14 -> mY ; R_L_Load_Voltage_Measure3_Voltage_Sensor3_V = ( ( ( ( ( (
( X [ 12ULL ] * - 0.0002188 + X [ 13ULL ] * 0.0001 ) + - X [ 14ULL ] ) + X [
73ULL ] * - 1.0000000000002187 ) + X [ 74ULL ] * 1.0000000000000002E-13 ) + X
[ 76ULL ] * - 1.0E-6 ) + X [ 75ULL ] * - 0.0001 ) + X [ 77ULL ] ) + X [
115ULL ] ; t11 = ( ( ( ( ( ( ( X [ 18ULL ] * - 0.000218 + X [ 19ULL ] *
0.0001 ) + - X [ 20ULL ] ) + X [ 80ULL ] * - 1.000000000000218 ) + X [ 81ULL
] * 1.0000000000000002E-13 ) + X [ 83ULL ] * - 1.0E-6 ) + X [ 82ULL ] * -
0.0001 ) + X [ 84ULL ] ) + X [ 116ULL ] ;
R_L_Load_Voltage_Measure2_Voltage_Sensor3_V = ( ( ( ( ( ( ( X [ 36ULL ] * -
0.0002183 + X [ 37ULL ] * 0.0001 ) + - X [ 38ULL ] ) + X [ 101ULL ] * -
1.0000000000002183 ) + X [ 102ULL ] * 1.0000000000000002E-13 ) + X [ 104ULL ]
* - 1.0E-6 ) + X [ 103ULL ] * - 0.0001 ) + X [ 105ULL ] ) + X [ 117ULL ] ;
R_L_Load_Voltage_Measure1_Voltage_Sensor3_V = - ( t11 -
R_L_Load_Voltage_Measure2_Voltage_Sensor3_V ) / - 1.0 ;
R_L_Load_Voltage_Measure2_Voltage_Sensor3_V = - (
R_L_Load_Voltage_Measure3_Voltage_Sensor3_V -
R_L_Load_Voltage_Measure2_Voltage_Sensor3_V ) / - 1.0 ;
R_L_Load_Voltage_Measure3_Voltage_Sensor3_V = - (
R_L_Load_Voltage_Measure3_Voltage_Sensor3_V - t11 ) / - 1.0 ; out . mX [ 0 ]
= X [ 66ULL ] * 1.0E-9 + X [ 3ULL ] ; out . mX [ 1 ] = X [ 70ULL ] * 1.0E-9 +
X [ 8ULL ] ; out . mX [ 2 ] = X [ 64ULL ] * 1.0E-9 + X [ 0ULL ] ; out . mX [
3 ] = - X [ 13ULL ] + X [ 74ULL ] * - 1.0E-9 ; out . mX [ 4 ] = - ( ( ( X [
13ULL ] * - 0.0001 + X [ 74ULL ] * - 1.0000000000000002E-13 ) + X [ 77ULL ] )
- ( ( ( ( ( X [ 13ULL ] * 0.0001 + - X [ 14ULL ] ) + X [ 74ULL ] *
1.0000000000000002E-13 ) + X [ 76ULL ] * - 1.0E-6 ) + X [ 75ULL ] * - 0.0001
) + X [ 77ULL ] ) ) / - 1.0 ; out . mX [ 5 ] = - X [ 19ULL ] + X [ 81ULL ] *
- 1.0E-9 ; out . mX [ 6 ] = - ( ( ( X [ 19ULL ] * - 0.0001 + X [ 81ULL ] * -
1.0000000000000002E-13 ) + X [ 84ULL ] ) - ( ( ( ( ( X [ 19ULL ] * 0.0001 + -
X [ 20ULL ] ) + X [ 81ULL ] * 1.0000000000000002E-13 ) + X [ 83ULL ] * -
1.0E-6 ) + X [ 82ULL ] * - 0.0001 ) + X [ 84ULL ] ) ) / - 1.0 ; out . mX [ 7
] = - X [ 25ULL ] + X [ 88ULL ] * - 1.0E-9 ; out . mX [ 8 ] = - ( ( ( ( ( ( X
[ 25ULL ] * - 0.0001 + - X [ 27ULL ] ) + X [ 88ULL ] * -
1.0000000000000002E-13 ) + X [ 92ULL ] * 1.0E-6 ) + X [ 89ULL ] * - 1.0E-6 )
+ X [ 91ULL ] ) - ( ( ( ( ( ( ( X [ 25ULL ] * 0.0001 + - X [ 26ULL ] ) + - X
[ 27ULL ] ) + X [ 88ULL ] * 1.0000000000000002E-13 ) + X [ 90ULL ] * - 1.0E-6
) + X [ 92ULL ] * 1.0E-6 ) + X [ 89ULL ] * - 0.000101 ) + X [ 91ULL ] ) ) / -
1.0 ; out . mX [ 9 ] = - X [ 31ULL ] + X [ 95ULL ] * - 1.0E-9 ; out . mX [ 10
] = - ( ( ( ( ( ( X [ 31ULL ] * - 0.0001 + - X [ 33ULL ] ) + X [ 95ULL ] * -
1.0000000000000002E-13 ) + X [ 99ULL ] * 1.0E-6 ) + X [ 96ULL ] * - 1.0E-6 )
+ X [ 98ULL ] ) - ( ( ( ( ( ( ( X [ 31ULL ] * 0.0001 + - X [ 32ULL ] ) + - X
[ 33ULL ] ) + X [ 95ULL ] * 1.0000000000000002E-13 ) + X [ 97ULL ] * - 1.0E-6
) + X [ 99ULL ] * 1.0E-6 ) + X [ 96ULL ] * - 0.000101 ) + X [ 98ULL ] ) ) / -
1.0 ; out . mX [ 11 ] = - X [ 37ULL ] + X [ 102ULL ] * - 1.0E-9 ; out . mX [
12 ] = - ( ( ( X [ 37ULL ] * - 0.0001 + X [ 102ULL ] * -
1.0000000000000002E-13 ) + X [ 105ULL ] ) - ( ( ( ( ( X [ 37ULL ] * 0.0001 +
- X [ 38ULL ] ) + X [ 102ULL ] * 1.0000000000000002E-13 ) + X [ 104ULL ] * -
1.0E-6 ) + X [ 103ULL ] * - 0.0001 ) + X [ 105ULL ] ) ) / - 1.0 ; out . mX [
13 ] = - X [ 43ULL ] + X [ 109ULL ] * - 1.0E-9 ; out . mX [ 14 ] = - ( ( ( (
( ( X [ 43ULL ] * - 0.0001 + - X [ 45ULL ] ) + X [ 109ULL ] * -
1.0000000000000002E-13 ) + X [ 113ULL ] * 1.0E-6 ) + X [ 110ULL ] * - 1.0E-6
) + X [ 112ULL ] ) - ( ( ( ( ( ( ( X [ 43ULL ] * 0.0001 + - X [ 44ULL ] ) + -
X [ 45ULL ] ) + X [ 109ULL ] * 1.0000000000000002E-13 ) + X [ 111ULL ] * -
1.0E-6 ) + X [ 113ULL ] * 1.0E-6 ) + X [ 110ULL ] * - 0.000101 ) + X [ 112ULL
] ) ) / - 1.0 ; out . mX [ 15 ] = X [ 119ULL ] * 1.0E-9 + X [ 61ULL ] ; out .
mX [ 16 ] = X [ 120ULL ] * 1.0E-9 + X [ 62ULL ] ; out . mX [ 17 ] = X [
121ULL ] * 1.0E-9 + X [ 63ULL ] ; out . mX [ 18 ] =
R_L_Load_Voltage_Measure1_Voltage_Sensor3_V ; out . mX [ 19 ] =
R_L_Load_Voltage_Measure2_Voltage_Sensor3_V ; out . mX [ 20 ] =
R_L_Load_Voltage_Measure3_Voltage_Sensor3_V ; out . mX [ 21 ] = - ( ( ( ( ( (
( ( ( X [ 0ULL ] * 0.0211 + X [ 5ULL ] * - 0.001037 ) + X [ 1ULL ] * 0.001422
) + X [ 6ULL ] * 0.000611 ) + X [ 64ULL ] * 1.0000000000211 ) + X [ 68ULL ] *
- 1.0000000000010369 ) + X [ 65ULL ] * 1.000000000001422 ) + X [ 69ULL ] *
1.0000000000006111 ) + X [ 2ULL ] ) - ( X [ 4ULL ] * 0.000662 + X [ 67ULL ] *
1.0000000000006619 ) ) / - 1.0 ; out . mX [ 22 ] = - ( ( ( ( ( ( ( ( ( X [
10ULL ] * 0.000867 + X [ 0ULL ] * 0.0211 ) + X [ 5ULL ] * - 0.001037 ) + X [
1ULL ] * 0.001422 ) + X [ 72ULL ] * 1.0000000000008671 ) + X [ 64ULL ] *
1.0000000000211 ) + X [ 68ULL ] * - 1.0000000000010369 ) + X [ 65ULL ] *
1.000000000001422 ) + X [ 2ULL ] ) - ( X [ 9ULL ] * 0.000595 + X [ 71ULL ] *
1.0000000000005951 ) ) / - 1.0 ; out . mX [ 23 ] = - ( ( ( ( ( X [ 0ULL ] *
0.0211 + X [ 1ULL ] * 0.001422 ) + X [ 64ULL ] * 1.0000000000211 ) + X [
65ULL ] * 1.000000000001422 ) + X [ 2ULL ] ) - ( X [ 1ULL ] * 0.001422 + X [
65ULL ] * 1.000000000001422 ) ) / - 1.0 ; out . mX [ 24 ] = - ( X [ 94ULL ] *
1.0E-9 + X [ 30ULL ] ) ; out . mX [ 25 ] = X [ 118ULL ] * 1.0E-9 + X [ 57ULL
] ; ( void ) sys ; ( void ) t14 ; return 0 ; }
