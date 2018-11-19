#include "__cf_InverterWFETs.h"
#include "ne_ds.h"
#include "InverterWFETs_d83d6795_1_ds_ic.h"
#include "InverterWFETs_d83d6795_1_ds_sys_struct.h"
#include "InverterWFETs_d83d6795_1_ds_externals.h"
#include "InverterWFETs_d83d6795_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T InverterWFETs_d83d6795_1_ds_ic ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out ;
real_T t0 [ 123 ] ; int32_T b ; real_T P_R_idx_0 ; real_T P_R_idx_2 ; real_T
P_R_idx_3 ; real_T P_R_idx_1 ; P_R_idx_0 = t1 -> mP_R . mX [ 0 ] ; P_R_idx_1
= t1 -> mP_R . mX [ 1 ] ; P_R_idx_2 = t1 -> mP_R . mX [ 2 ] ; P_R_idx_3 = t1
-> mP_R . mX [ 3 ] ; out = t2 -> mIC ; t0 [ 0ULL ] = 0.0 ; t0 [ 1ULL ] = 0.0
; t0 [ 2ULL ] = 270.0 ; t0 [ 3ULL ] = 0.0 ; t0 [ 4ULL ] = 0.0 ; t0 [ 5ULL ] =
0.0 ; t0 [ 6ULL ] = 0.0 ; t0 [ 7ULL ] = 270.0 ; t0 [ 8ULL ] = 0.0 ; t0 [ 9ULL
] = 0.0 ; t0 [ 10ULL ] = 0.0 ; t0 [ 11ULL ] = 270.0 ; t0 [ 12ULL ] = 0.0 ; t0
[ 13ULL ] = 0.0 ; t0 [ 14ULL ] = 0.0 ; t0 [ 15ULL ] = 0.0 ; t0 [ 16ULL ] =
0.0 ; t0 [ 17ULL ] = 0.0 ; t0 [ 18ULL ] = 0.0 ; t0 [ 19ULL ] = 0.0 ; t0 [
20ULL ] = 0.0 ; t0 [ 21ULL ] = 0.0 ; t0 [ 22ULL ] = 0.0 ; t0 [ 23ULL ] = 0.0
; t0 [ 24ULL ] = 0.0 ; t0 [ 25ULL ] = 0.0 ; t0 [ 26ULL ] = 0.0 ; t0 [ 27ULL ]
= 0.0 ; t0 [ 28ULL ] = 0.0 ; t0 [ 29ULL ] = 0.0 ; t0 [ 30ULL ] = 0.0 ; t0 [
31ULL ] = 0.0 ; t0 [ 32ULL ] = 0.0 ; t0 [ 33ULL ] = 0.0 ; t0 [ 34ULL ] = 0.0
; t0 [ 35ULL ] = 0.0 ; t0 [ 36ULL ] = 0.0 ; t0 [ 37ULL ] = 0.0 ; t0 [ 38ULL ]
= 0.0 ; t0 [ 39ULL ] = 0.0 ; t0 [ 40ULL ] = 0.0 ; t0 [ 41ULL ] = 0.0 ; t0 [
42ULL ] = 0.0 ; t0 [ 43ULL ] = 0.0 ; t0 [ 44ULL ] = 0.0 ; t0 [ 45ULL ] = 0.0
; t0 [ 46ULL ] = 0.0 ; t0 [ 47ULL ] = 0.0 ; t0 [ 48ULL ] = 0.0 ; t0 [ 49ULL ]
= 0.0 ; t0 [ 50ULL ] = 0.0 ; t0 [ 51ULL ] = 0.0 ; t0 [ 52ULL ] = 0.0 ; t0 [
53ULL ] = 0.0 ; t0 [ 54ULL ] = 0.0 ; t0 [ 55ULL ] = 0.0 ; t0 [ 56ULL ] = 0.0
; t0 [ 57ULL ] = P_R_idx_0 ; t0 [ 58ULL ] = 0.0 ; t0 [ 59ULL ] = 0.0 ; t0 [
60ULL ] = 0.0 ; t0 [ 61ULL ] = P_R_idx_2 ; t0 [ 62ULL ] = P_R_idx_3 ; t0 [
63ULL ] = P_R_idx_1 ; t0 [ 64ULL ] = 0.0 ; t0 [ 65ULL ] = 0.0 ; t0 [ 66ULL ]
= 0.0 ; t0 [ 67ULL ] = 0.0 ; t0 [ 68ULL ] = 0.0 ; t0 [ 69ULL ] = 0.0 ; t0 [
70ULL ] = 0.0 ; t0 [ 71ULL ] = 0.0 ; t0 [ 72ULL ] = 0.0 ; t0 [ 73ULL ] = 0.0
; t0 [ 74ULL ] = 0.0 ; t0 [ 75ULL ] = 0.0 ; t0 [ 76ULL ] = 0.0 ; t0 [ 77ULL ]
= 0.0 ; t0 [ 78ULL ] = 0.0 ; t0 [ 79ULL ] = 0.0 ; t0 [ 80ULL ] = 0.0 ; t0 [
81ULL ] = 0.0 ; t0 [ 82ULL ] = 0.0 ; t0 [ 83ULL ] = 0.0 ; t0 [ 84ULL ] = 0.0
; t0 [ 85ULL ] = 0.0 ; t0 [ 86ULL ] = 0.0 ; t0 [ 87ULL ] = 0.0 ; t0 [ 88ULL ]
= 0.0 ; t0 [ 89ULL ] = 0.0 ; t0 [ 90ULL ] = 0.0 ; t0 [ 91ULL ] = 0.0 ; t0 [
92ULL ] = 0.0 ; t0 [ 93ULL ] = 0.0 ; t0 [ 94ULL ] = 0.0 ; t0 [ 95ULL ] = 0.0
; t0 [ 96ULL ] = 0.0 ; t0 [ 97ULL ] = 0.0 ; t0 [ 98ULL ] = 0.0 ; t0 [ 99ULL ]
= 0.0 ; t0 [ 100ULL ] = 0.0 ; t0 [ 101ULL ] = 0.0 ; t0 [ 102ULL ] = 0.0 ; t0
[ 103ULL ] = 0.0 ; t0 [ 104ULL ] = 0.0 ; t0 [ 105ULL ] = 0.0 ; t0 [ 106ULL ]
= 0.0 ; t0 [ 107ULL ] = 0.0 ; t0 [ 108ULL ] = 0.0 ; t0 [ 109ULL ] = 0.0 ; t0
[ 110ULL ] = 0.0 ; t0 [ 111ULL ] = 0.0 ; t0 [ 112ULL ] = 0.0 ; t0 [ 113ULL ]
= 0.0 ; t0 [ 114ULL ] = 0.0 ; t0 [ 115ULL ] = 0.0 ; t0 [ 116ULL ] = 0.0 ; t0
[ 117ULL ] = 0.0 ; t0 [ 118ULL ] = 0.0 ; t0 [ 119ULL ] = 0.0 ; t0 [ 120ULL ]
= 0.0 ; t0 [ 121ULL ] = 0.0 ; t0 [ 122ULL ] = 0.0 ; for ( b = 0 ; b < 123 ; b
++ ) { out . mX [ b ] = t0 [ b ] ; } ( void ) sys ; ( void ) t2 ; return 0 ;
}
