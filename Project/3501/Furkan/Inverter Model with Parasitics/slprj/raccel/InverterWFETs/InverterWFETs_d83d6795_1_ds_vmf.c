#include "__cf_InverterWFETs.h"
#include "ne_ds.h"
#include "InverterWFETs_d83d6795_1_ds_vmf.h"
#include "InverterWFETs_d83d6795_1_ds_sys_struct.h"
#include "InverterWFETs_d83d6795_1_ds_externals.h"
#include "InverterWFETs_d83d6795_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T InverterWFETs_d83d6795_1_ds_vmf ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out ;
boolean_T t0 [ 123 ] ; int32_T b ; static boolean_T _cg_const_1 [ 123 ] = {
false , false , false , false , false , false , false , false , false , false
, false , false , false , false , false , false , false , false , false ,
false , false , false , false , false , false , false , false , false , false
, false , false , false , false , false , false , false , false , false ,
false , false , false , false , false , false , false , false , false , false
, false , false , false , false , false , false , false , false , false ,
false , false , false , false , false , false , false , false , false , true
, false , true , false , false , true , false , true , false , false , true ,
false , true , false , false , true , false , true , false , false , true ,
false , true , false , false , true , false , true , false , false , false ,
false , false , false , false , false , false , false , false , false , false
, false , false , false , false , false , false , false , false , false ,
false , false , false , false , false , false , false } ; ( void ) t1 ; out =
t2 -> mVMF ; for ( b = 0 ; b < 123 ; b ++ ) { t0 [ b ] = _cg_const_1 [ b ] ;
} for ( b = 0 ; b < 123 ; b ++ ) { out . mX [ b ] = t0 [ b ] ; } ( void ) sys
; ( void ) t2 ; return 0 ; }
