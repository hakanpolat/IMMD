#include "__cf_InverterWFETs.h"
#include "ne_ds.h"
#include "InverterWFETs_d83d6795_1_ds_y.h"
#include "InverterWFETs_d83d6795_1_ds_tdxy_p.h"
#include "InverterWFETs_d83d6795_1_ds_slv.h"
#include "InverterWFETs_d83d6795_1_ds_zc.h"
#include "InverterWFETs_d83d6795_1_ds_obs_all.h"
#include "InverterWFETs_d83d6795_1_ds_obs_exp.h"
#include "InverterWFETs_d83d6795_1_ds_m_p.h"
#include "InverterWFETs_d83d6795_1_ds_dnf_v_x.h"
#include "InverterWFETs_d83d6795_1_ds_obs_act.h"
#include "InverterWFETs_d83d6795_1_ds_vmf.h"
#include "InverterWFETs_d83d6795_1_ds_tdxf_p.h"
#include "InverterWFETs_d83d6795_1_ds_vmm.h"
#include "InverterWFETs_d83d6795_1_ds_dxy_p.h"
#include "InverterWFETs_d83d6795_1_ds_a_p.h"
#include "InverterWFETs_d83d6795_1_ds_ic.h"
#include "InverterWFETs_d83d6795_1_ds_log.h"
#include "InverterWFETs_d83d6795_1_ds_a.h"
#include "InverterWFETs_d83d6795_1_ds_dxf_p.h"
#include "InverterWFETs_d83d6795_1_ds_dxf.h"
#include "InverterWFETs_d83d6795_1_ds_m.h"
#include "InverterWFETs_d83d6795_1_ds_dxy.h"
#include "InverterWFETs_d83d6795_1_ds_lv.h"
#include "InverterWFETs_d83d6795_1_ds_mode.h"
#include "InverterWFETs_d83d6795_1_ds_f.h"
#include "InverterWFETs_d83d6795_1_ds.h"
#include "ssc_ml_fun.h"
#include "InverterWFETs_d83d6795_1_ds_external_struct.h"
#include "InverterWFETs_d83d6795_1_ds_sys_struct.h"
#include "InverterWFETs_d83d6795_1_ds_externals.h"
static int32_T ds_dxm_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_dxm
( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dum_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dum ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_dtm_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dtm ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_b_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_b ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_c_p ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_c ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_slf ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_slf0 ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_duf_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_duf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_dtf_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dtf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_ddf_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_ddf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_tduf_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dnf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dnf ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_icr ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_icr_im ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_icr_id ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dxicr ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_dxicr_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_tduicr_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_mduy_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_mdxy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_tduy_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_duy_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_duy
( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dty_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dty ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_cache_r ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_cache_i ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_update_r ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_update_i ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_sfo ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_sfp ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_init_r ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_init_i ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_assert ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_passert ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_del_t ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_del_v ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_del_v0 ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_del_tmax ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxdelt_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dxdelt ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dudelt_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput
* in , NeDsMethodOutput * out ) ; static int32_T ds_dudelt ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_dtdelt_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dtdelt ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dp_l ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dp_i ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_dp_j ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_dp_r ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_qx (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_qu ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_qt ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_q1 ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_qx_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_qu_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_qt_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_q1_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_var_tol ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_eq_tol ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static NeDsMethodOutput * ds_output_m_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_m ( const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_vmm ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_dxm_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxm ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dum_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dum ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dtm_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dtm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_a_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_a ( const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_b_p ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_b ( const NeDynamicSystem *
ds , PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_c_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_c ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_f ( const NeDynamicSystem *
ds , PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_vmf (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_slf ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_slf0 ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxf_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dxf ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_duf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_duf ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dtf_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dtf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_ddf_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_ddf ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_tduf_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_tdxf_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dnf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dnf ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dnf_v_x ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_ic ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_icr ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_icr_im ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_icr_id (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dxicr ( const NeDynamicSystem * ds , PmAllocator
* allocator ) ; static NeDsMethodOutput * ds_output_dxicr_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_tduicr_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_mduy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_mdxy_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_tduy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_tdxy_p (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_y ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_dxy_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxy ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_duy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_duy ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dty_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dty ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_mode ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_zc ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_cache_r ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_cache_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_update_r ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_update_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_sfo ( const NeDynamicSystem * ds , PmAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_sfp ( const NeDynamicSystem
* ds , PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_init_r
( const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_init_i ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_log ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_assert ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_passert ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_del_t ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_del_v ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_del_v0 ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_del_tmax (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dxdelt_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dxdelt (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dudelt_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dudelt (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dtdelt_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dtdelt (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_obs_exp ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_obs_act (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_obs_all ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dp_l ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dp_i ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dp_j ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dp_r ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_qx ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_qu ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_qt ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_q1 ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_qx_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_qu_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_qt_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_q1_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_var_tol (
const NeDynamicSystem * ds , PmAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_eq_tol ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) ; static NeDsMethodOutput * ds_output_lv ( const
NeDynamicSystem * ds , PmAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_slv ( const NeDynamicSystem * ds , PmAllocator * allocator ) ;
static void release_reference ( NeDynamicSystem * ds ) ; static void
get_reference ( NeDynamicSystem * ds ) ; static NeDynamicSystem * diagnostics
( const NeDynamicSystem * ds ) ; static void expand ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , PmRealVector * out ) ; static
NeEquationData s_equation_data [ 123 ] = { { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Capacitor" , 1U , 0U , TRUE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Capacitor1" , 1U , 1U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Capacitor2" , 1U , 2U , TRUE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/Diode" , 1U , 3U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver/Inductor" , 2U
, 4U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/Inductor1" , 2U , 6U , TRUE , 1.0 , "1" , } , { ""
, 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 8U , TRUE , 1.0 , "1" , }
, { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 9U , TRUE , 1.0 , "1" , }
, { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 10U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 11U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver1/Inductor" , 2U
, 12U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/Inductor1" , 2U , 14U , TRUE , 1.0 , "1" , } , {
"" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 16U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 17U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 18U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 19U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver2/Inductor" , 2U
, 20U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/Inductor1" , 2U , 22U , TRUE , 1.0 , "1" , } , {
"" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 24U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 25U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 26U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 27U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver3/Inductor" , 2U
, 28U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/Inductor1" , 2U , 30U , TRUE , 1.0 , "1" , } , {
"" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 32U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 33U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 34U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 35U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver4/Inductor" , 2U
, 36U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/Inductor1" , 2U , 38U , TRUE , 1.0 , "1" , } , {
"" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 40U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 41U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 42U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 43U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver5/Inductor" , 2U
, 44U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/Inductor1" , 2U , 46U , TRUE , 1.0 , "1" , } , {
"" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 48U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 49U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 50U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor" , 2U ,
51U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor1" , 2U , 53U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor10" , 2U , 55U , TRUE , 1.0
, "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor11" , 2U , 57U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor12" , 2U , 59U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor13" , 2U , 61U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor14" , 2U , 63U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor15" , 2U , 65U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor16" , 2U , 67U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor17" , 2U , 69U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor18" , 2U , 71U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor19" , 2U , 73U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor2" , 2U , 75U , TRUE , 1.0
, "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor20" , 2U , 77U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor21" , 2U , 79U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor3" , 2U , 81U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor4" , 2U , 83U , TRUE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor5"
, 2U , 85U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor6" , 2U , 87U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor7" , 2U , 89U , TRUE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor8"
, 2U , 91U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor9" , 2U , 93U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "InverterWFETs/R L Load/Inductor" , 2U , 95U , TRUE
, 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/R L Load/Inductor1" , 2U , 97U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/R L Load/Inductor2" , 2U ,
99U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Capacitor1" , 1U , 101U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Capacitor2" , 1U , 102U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/Diode" , 3U , 103U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 106U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 11U , 107U , FALSE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver/Resistor1" , 1U , 118U , TRUE , 1.0 , "1" , } , {
"" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver" , 3U ,
119U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/Diode" , 3U , 122U , TRUE , 1.0 , "1" , } , { ""
, 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 125U , TRUE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 11U , 126U , FALSE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver1/Resistor1" , 1U , 137U , TRUE , 1.0 , "1" , } , {
"" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver1" , 3U ,
138U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/Diode" , 3U , 141U , TRUE , 1.0 , "1" , } , { ""
, 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 144U , TRUE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 11U , 145U , FALSE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver2/Resistor1" , 1U , 156U , TRUE , 1.0 , "1" , } , {
"" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver2" , 3U ,
157U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/Diode" , 3U , 160U , TRUE , 1.0 , "1" , } , { ""
, 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 163U , TRUE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 11U , 164U , FALSE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver3/Resistor1" , 1U , 175U , TRUE , 1.0 , "1" , } , {
"" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver3" , 3U ,
176U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/Diode" , 3U , 179U , TRUE , 1.0 , "1" , } , { ""
, 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 182U , TRUE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 11U , 183U , FALSE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver4/Resistor1" , 1U , 194U , TRUE , 1.0 , "1" , } , {
"" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver4" , 3U ,
195U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/Diode" , 3U , 198U , TRUE , 1.0 , "1" , } , { ""
, 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 201U , TRUE , 1.0 , "1"
, } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 11U , 202U , FALSE , 1.0 ,
"1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Gate Driver5/Resistor1" , 1U , 213U , TRUE , 1.0 , "1" , } , {
"" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Gate Driver5" , 3U ,
214U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor" , 1U , 217U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor1" , 1U , 218U , TRUE , 1.0
, "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor12" , 1U , 219U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor13" , 1U , 220U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor14" , 1U , 221U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor15" , 1U , 222U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor16" , 1U , 223U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor17" , 1U , 224U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor2" , 1U , 225U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor3" , 1U , 226U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Inductor4" , 1U , 227U , TRUE , 1.0 , "1" , } , { "" , 0U , 8
, NE_EQUATION_DOMAIN_TIME , "InverterWFETs/Inductor5" , 1U , 228U , TRUE ,
1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/R L Load/Resistor" , 1U , 229U , TRUE , 1.0 , "1" , } , { "" ,
0U , 8 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/R L Load/Resistor1" , 1U ,
230U , TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/R L Load/Resistor2" , 1U , 231U , TRUE , 1.0 , "1" , } , { ""
, 0U , 1 , NE_EQUATION_DOMAIN_TIME , "InverterWFETs/R L Load" , 2U , 232U ,
TRUE , 1.0 , "1" , } , { "" , 0U , 8 , NE_EQUATION_DOMAIN_TIME ,
"InverterWFETs/Resistor18" , 1U , 234U , TRUE , 1.0 , "1" , } , { "" , 0U , 1
, NE_EQUATION_DOMAIN_TIME , "" , 4U , 235U , TRUE , 1.0 , "1" , } , { "" , 0U
, 1 , NE_EQUATION_DOMAIN_TIME , "" , 4U , 239U , TRUE , 1.0 , "1" , } , { ""
, 0U , 1 , NE_EQUATION_DOMAIN_TIME , "" , 3U , 243U , TRUE , 1.0 , "1" , } ,
{ "" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "" , 3U , 246U , TRUE , 1.0 , "1" ,
} , { "" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "" , 3U , 249U , TRUE , 1.0 ,
"1" , } , { "" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "" , 4U , 252U , TRUE ,
1.0 , "1" , } , { "" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "" , 4U , 256U ,
TRUE , 1.0 , "1" , } , { "" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "" , 4U ,
260U , TRUE , 1.0 , "1" , } , { "" , 0U , 1 , NE_EQUATION_DOMAIN_TIME , "" ,
4U , 264U , TRUE , 1.0 , "1" , } , { "" , 0U , 1 , NE_EQUATION_DOMAIN_TIME ,
"" , 3U , 268U , TRUE , 1.0 , "1" , } } ; static NeVariableData
s_variable_data [ 123 ] = { { "Inductor18.i_L" , 0U , 0 ,
"InverterWFETs/Inductor18" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor7.i_L" , 0U , 0
, "InverterWFETs/Inductor7" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Capacitor.vc" , 0U , 0 ,
"InverterWFETs/Capacitor" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , { "Inductor19.i_L" , 0U ,
0 , "InverterWFETs/Inductor19" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor9.i_L" , 0U , 0
, "InverterWFETs/Inductor9" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor6.i_L" , 0U , 0
, "InverterWFETs/Inductor6" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor8.i_L" , 0U , 0
, "InverterWFETs/Inductor8" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Capacitor1.vc" , 0U , 0
, "InverterWFETs/Capacitor1" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , { "Inductor20.i_L" , 0U ,
0 , "InverterWFETs/Inductor20" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor11.i_L" , 0U , 0
, "InverterWFETs/Inductor11" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor10.i_L" , 0U , 0
, "InverterWFETs/Inductor10" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Capacitor2.vc" , 0U , 0
, "InverterWFETs/Capacitor2" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver.Inductor.i_L" , 0U , 0 , "InverterWFETs/Gate Driver/Inductor" ,
1.0 , "1" , 0.0 , TRUE , 1U , 1U , NE_INIT_MODE_MANDATORY ,
"Inductor current" , } , { "Gate_Driver.Inductor1.i_L" , 0U , 0 ,
"InverterWFETs/Gate Driver/Inductor1" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_DS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_GD.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver.Diode.diode.junctionCapacitance.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver/Diode" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_NONE , "Capacitor voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_GS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver1.Inductor.i_L" , 0U , 0 , "InverterWFETs/Gate Driver1/Inductor"
, 1.0 , "1" , 0.0 , TRUE , 1U , 1U , NE_INIT_MODE_MANDATORY ,
"Inductor current" , } , { "Gate_Driver1.Inductor1.i_L" , 0U , 0 ,
"InverterWFETs/Gate Driver1/Inductor1" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_DS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_GD.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver1.Diode.diode.junctionCapacitance.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver1/Diode" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_NONE , "Capacitor voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_GS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver2.Inductor.i_L" , 0U , 0 , "InverterWFETs/Gate Driver2/Inductor"
, 1.0 , "1" , 0.0 , TRUE , 1U , 1U , NE_INIT_MODE_MANDATORY ,
"Inductor current" , } , { "Gate_Driver2.Inductor1.i_L" , 0U , 0 ,
"InverterWFETs/Gate Driver2/Inductor1" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_DS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_GD.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver2.Diode.diode.junctionCapacitance.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver2/Diode" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_NONE , "Capacitor voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_GS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver3.Inductor.i_L" , 0U , 0 , "InverterWFETs/Gate Driver3/Inductor"
, 1.0 , "1" , 0.0 , TRUE , 1U , 1U , NE_INIT_MODE_MANDATORY ,
"Inductor current" , } , { "Gate_Driver3.Inductor1.i_L" , 0U , 0 ,
"InverterWFETs/Gate Driver3/Inductor1" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_DS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_GD.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver3.Diode.diode.junctionCapacitance.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver3/Diode" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_NONE , "Capacitor voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_GS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver4.Inductor.i_L" , 0U , 0 , "InverterWFETs/Gate Driver4/Inductor"
, 1.0 , "1" , 0.0 , TRUE , 1U , 1U , NE_INIT_MODE_MANDATORY ,
"Inductor current" , } , { "Gate_Driver4.Inductor1.i_L" , 0U , 0 ,
"InverterWFETs/Gate Driver4/Inductor1" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_DS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_GD.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver4.Diode.diode.junctionCapacitance.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver4/Diode" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_NONE , "Capacitor voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_GS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver5.Inductor.i_L" , 0U , 0 , "InverterWFETs/Gate Driver5/Inductor"
, 1.0 , "1" , 0.0 , TRUE , 1U , 1U , NE_INIT_MODE_MANDATORY ,
"Inductor current" , } , { "Gate_Driver5.Inductor1.i_L" , 0U , 0 ,
"InverterWFETs/Gate Driver5/Inductor1" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_DS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_GD.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , {
"Gate_Driver5.Diode.diode.junctionCapacitance.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver5/Diode" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_NONE , "Capacitor voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_GS.vc" , 0U , 0 ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Capacitor voltage" , } , { "Inductor.i_L" , 0U
, 0 , "InverterWFETs/Inductor" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor1.i_L" , 0U , 0
, "InverterWFETs/Inductor1" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor12.i_L" , 0U , 0
, "InverterWFETs/Inductor12" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor13.i_L" , 0U , 0
, "InverterWFETs/Inductor13" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor14.i_L" , 0U , 0
, "InverterWFETs/Inductor14" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor15.i_L" , 0U , 0
, "InverterWFETs/Inductor15" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor16.i_L" , 0U , 0
, "InverterWFETs/Inductor16" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor17.i_L" , 0U , 0
, "InverterWFETs/Inductor17" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor2.i_L" , 0U , 0
, "InverterWFETs/Inductor2" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor21.i_L" , 0U , 0
, "InverterWFETs/Inductor21" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor3.i_L" , 0U , 0
, "InverterWFETs/Inductor3" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor4.i_L" , 0U , 0
, "InverterWFETs/Inductor4" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "Inductor5.i_L" , 0U , 0
, "InverterWFETs/Inductor5" , 1.0 , "1" , 0.0 , TRUE , 1U , 1U ,
NE_INIT_MODE_MANDATORY , "Inductor current" , } , { "R_L_Load.Inductor1.i_L"
, 0U , 0 , "InverterWFETs/R L Load/Inductor1" , 1.0 , "1" , 0.0 , TRUE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Inductor current" , } , {
"R_L_Load.Inductor2.i_L" , 0U , 0 , "InverterWFETs/R L Load/Inductor2" , 1.0
, "1" , 0.0 , TRUE , 1U , 1U , NE_INIT_MODE_MANDATORY , "Inductor current" ,
} , { "R_L_Load.Inductor.i_L" , 0U , 0 , "InverterWFETs/R L Load/Inductor" ,
1.0 , "1" , 0.0 , TRUE , 1U , 1U , NE_INIT_MODE_MANDATORY ,
"Inductor current" , } , { "Inductor18.v" , 0U , 0 ,
"InverterWFETs/Inductor18" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor7.v" , 0U , 0 ,
"InverterWFETs/Inductor7" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor19.v" , 0U , 0 ,
"InverterWFETs/Inductor19" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor9.v" , 0U , 0 ,
"InverterWFETs/Inductor9" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor6.v" , 0U , 0 ,
"InverterWFETs/Inductor6" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor8.v" , 0U , 0 ,
"InverterWFETs/Inductor8" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor20.v" , 0U , 0 ,
"InverterWFETs/Inductor20" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor11.v" , 0U , 0 ,
"InverterWFETs/Inductor11" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor10.v" , 0U , 0 ,
"InverterWFETs/Inductor10" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Gate_Driver.Inductor.v" , 0U , 0 ,
"InverterWFETs/Gate Driver/Inductor" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Gate_Driver.Inductor1.v" , 0U , 0 ,
"InverterWFETs/Gate Driver/Inductor1" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.gate_resistor.i" , 0U , 0 ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U ,
1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_DS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U ,
1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_DS.p.v" , 0U , 1 ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U ,
1U , NE_INIT_MODE_NONE , "Voltage" , } , { "Gate_Driver.Diode.i_capacitor" ,
0U , 0 , "InverterWFETs/Gate Driver/Diode" , 1.0 , "1" , 0.0 , FALSE , 1U ,
1U , NE_INIT_MODE_MANDATORY , "Junction capacitance current" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_GS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U ,
1U , NE_INIT_MODE_NONE , "Current" , } , { "Gate_Driver1.Inductor.v" , 0U , 0
, "InverterWFETs/Gate Driver1/Inductor" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Gate_Driver1.Inductor1.v" , 0U , 0 ,
"InverterWFETs/Gate Driver1/Inductor1" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.gate_resistor.i" , 0U , 0 ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_DS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_DS.p.v" , 0U , 1 ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Voltage" , } , { "Gate_Driver1.Diode.i_capacitor"
, 0U , 0 , "InverterWFETs/Gate Driver1/Diode" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_MANDATORY , "Junction capacitance current" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_GS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , { "Gate_Driver2.Inductor.v" , 0U ,
0 , "InverterWFETs/Gate Driver2/Inductor" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U
, NE_INIT_MODE_NONE , "Voltage" , } , { "Gate_Driver2.Inductor1.v" , 0U , 0 ,
"InverterWFETs/Gate Driver2/Inductor1" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.gate_resistor.i" , 0U , 0 ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_DS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_GD.p.v" , 0U , 1 ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_GS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , { "Gate_Driver2.Diode.i_capacitor"
, 0U , 0 , "InverterWFETs/Gate Driver2/Diode" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_MANDATORY , "Junction capacitance current" , } , {
"Gate_Driver3.Inductor.v" , 0U , 0 , "InverterWFETs/Gate Driver3/Inductor" ,
1.0 , "1" , 0.0 , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver3.Inductor1.v" , 0U , 0 , "InverterWFETs/Gate Driver3/Inductor1"
, 1.0 , "1" , 0.0 , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.gate_resistor.i" , 0U , 0 ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_DS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_GD.p.v" , 0U , 1 ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_GS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , { "Gate_Driver3.Diode.i_capacitor"
, 0U , 0 , "InverterWFETs/Gate Driver3/Diode" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_MANDATORY , "Junction capacitance current" , } , {
"Gate_Driver4.Inductor.v" , 0U , 0 , "InverterWFETs/Gate Driver4/Inductor" ,
1.0 , "1" , 0.0 , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver4.Inductor1.v" , 0U , 0 , "InverterWFETs/Gate Driver4/Inductor1"
, 1.0 , "1" , 0.0 , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.gate_resistor.i" , 0U , 0 ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_DS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_DS.p.v" , 0U , 1 ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Voltage" , } , { "Gate_Driver4.Diode.i_capacitor"
, 0U , 0 , "InverterWFETs/Gate Driver4/Diode" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_MANDATORY , "Junction capacitance current" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_GS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , { "Gate_Driver5.Inductor.v" , 0U ,
0 , "InverterWFETs/Gate Driver5/Inductor" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U
, NE_INIT_MODE_NONE , "Voltage" , } , { "Gate_Driver5.Inductor1.v" , 0U , 0 ,
"InverterWFETs/Gate Driver5/Inductor1" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.gate_resistor.i" , 0U , 0 ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_DS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_GD.p.v" , 0U , 1 ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_GS.i" , 0U , 0 ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "Current" , } , { "Gate_Driver5.Diode.i_capacitor"
, 0U , 0 , "InverterWFETs/Gate Driver5/Diode" , 1.0 , "1" , 0.0 , FALSE , 1U
, 1U , NE_INIT_MODE_MANDATORY , "Junction capacitance current" , } , {
"Inductor12.v" , 0U , 0 , "InverterWFETs/Inductor12" , 1.0 , "1" , 0.0 ,
FALSE , 1U , 1U , NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor14.v" , 0U ,
0 , "InverterWFETs/Inductor14" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor16.v" , 0U , 0 ,
"InverterWFETs/Inductor16" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "Inductor21.v" , 0U , 0 ,
"InverterWFETs/Inductor21" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "R_L_Load.Inductor1.v" , 0U , 0 ,
"InverterWFETs/R L Load/Inductor1" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "R_L_Load.Inductor2.v" , 0U , 0 ,
"InverterWFETs/R L Load/Inductor2" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "R_L_Load.Inductor.v" , 0U , 0 ,
"InverterWFETs/R L Load/Inductor" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } , { "R_L_Load.Inductor.n.v" , 0U , 1 ,
"InverterWFETs/R L Load/Inductor" , 1.0 , "1" , 0.0 , FALSE , 1U , 1U ,
NE_INIT_MODE_NONE , "Voltage" , } } ; static NeVariableData * s_discrete_data
= NULL ; static NeObservableData s_observable_data [ 1076 ] = { {
"Capacitor.i" , "InverterWFETs/Capacitor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Capacitor.power_dissipated" , "InverterWFETs/Capacitor" ,
1U , 1U , "W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "power_dissipated" , } , { "Capacitor.v" ,
"InverterWFETs/Capacitor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Capacitor.vc" , "InverterWFETs/Capacitor" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE
, FALSE , TRUE , "Capacitor voltage" , } , { "Capacitor.n.v" ,
"InverterWFETs/Capacitor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Capacitor.p.v" , "InverterWFETs/Capacitor" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Capacitor1.i" , "InverterWFETs/Capacitor1"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , {
"Capacitor1.power_dissipated" , "InverterWFETs/Capacitor1" , 1U , 1U , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "power_dissipated" , } , { "Capacitor1.v" ,
"InverterWFETs/Capacitor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Capacitor1.vc" , "InverterWFETs/Capacitor1" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE ,
TRUE , FALSE , TRUE , "Capacitor voltage" , } , { "Capacitor1.n.v" ,
"InverterWFETs/Capacitor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Capacitor1.p.v" , "InverterWFETs/Capacitor1" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Capacitor2.i" ,
"InverterWFETs/Capacitor2" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Capacitor2.power_dissipated" , "InverterWFETs/Capacitor2"
, 1U , 1U , "W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "power_dissipated" , } , { "Capacitor2.v" ,
"InverterWFETs/Capacitor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Capacitor2.vc" , "InverterWFETs/Capacitor2" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE ,
TRUE , FALSE , TRUE , "Capacitor voltage" , } , { "Capacitor2.n.v" ,
"InverterWFETs/Capacitor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Capacitor2.p.v" , "InverterWFETs/Capacitor2" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Current_Measure1.Current_Sensor1.I" ,
"InverterWFETs/Current Measure1/Current Sensor1" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "I" , } , { "Current_Measure1.Current_Sensor1.i1" ,
"InverterWFETs/Current Measure1/Current Sensor1" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Current" , } , { "Current_Measure1.Current_Sensor1.n.v" ,
"InverterWFETs/Current Measure1/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Current_Measure1.Current_Sensor1.p.v" ,
"InverterWFETs/Current Measure1/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Current_Measure1.Current_Sensor1.v1" ,
"InverterWFETs/Current Measure1/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Current_Measure1.I0.v" , "InverterWFETs/Current Measure1"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , FALSE , "Voltage" , } , { "Current_Measure1.I1.v" ,
"InverterWFETs/Current Measure1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Current_Measure2.Current_Sensor1.I" ,
"InverterWFETs/Current Measure2/Current Sensor1" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "I" , } , { "Current_Measure2.Current_Sensor1.i1" ,
"InverterWFETs/Current Measure2/Current Sensor1" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Current" , } , { "Current_Measure2.Current_Sensor1.n.v" ,
"InverterWFETs/Current Measure2/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Current_Measure2.Current_Sensor1.p.v" ,
"InverterWFETs/Current Measure2/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Current_Measure2.Current_Sensor1.v1" ,
"InverterWFETs/Current Measure2/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Current_Measure2.I0.v" , "InverterWFETs/Current Measure2"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , FALSE , "Voltage" , } , { "Current_Measure2.I1.v" ,
"InverterWFETs/Current Measure2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Current_Measure3.Current_Sensor1.I" ,
"InverterWFETs/Current Measure3/Current Sensor1" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "I" , } , { "Current_Measure3.Current_Sensor1.i1" ,
"InverterWFETs/Current Measure3/Current Sensor1" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Current" , } , { "Current_Measure3.Current_Sensor1.n.v" ,
"InverterWFETs/Current Measure3/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Current_Measure3.Current_Sensor1.p.v" ,
"InverterWFETs/Current Measure3/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Current_Measure3.Current_Sensor1.v1" ,
"InverterWFETs/Current Measure3/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Current_Measure3.I0.v" , "InverterWFETs/Current Measure3"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , FALSE , "Voltage" , } , { "Current_Measure3.I1.v" ,
"InverterWFETs/Current Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Electrical_Reference.V.v" ,
"InverterWFETs/Electrical Reference" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Controlled_Voltage_Source.i" ,
"InverterWFETs/Gate Driver/Controlled Voltage Source" , 1U , 1U , "A" , 1.0 ,
"A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "i" , } , { "Gate_Driver.Controlled_Voltage_Source.n.v" ,
"InverterWFETs/Gate Driver/Controlled Voltage Source" , 1U , 1U , "V" , 1.0 ,
"V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver.Controlled_Voltage_Source.p.v" ,
"InverterWFETs/Gate Driver/Controlled Voltage Source" , 1U , 1U , "V" , 1.0 ,
"V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver.Controlled_Voltage_Source.v" ,
"InverterWFETs/Gate Driver/Controlled Voltage Source" , 1U , 1U , "V" , 1.0 ,
"V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "v" , } , { "Gate_Driver.Controlled_Voltage_Source.vT" ,
"InverterWFETs/Gate Driver/Controlled Voltage Source" , 1U , 1U , "V" , 1.0 ,
"V" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "vT" , } , { "Gate_Driver.Current_Measure.Current_Sensor1.I" ,
"InverterWFETs/Gate Driver/Current Measure/Current Sensor1" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "Gate_Driver.Current_Measure.Current_Sensor1.i1" ,
"InverterWFETs/Gate Driver/Current Measure/Current Sensor1" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , {
"Gate_Driver.Current_Measure.Current_Sensor1.n.v" ,
"InverterWFETs/Gate Driver/Current Measure/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver.Current_Measure.Current_Sensor1.p.v" ,
"InverterWFETs/Gate Driver/Current Measure/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver.Current_Measure.Current_Sensor1.v1" ,
"InverterWFETs/Gate Driver/Current Measure/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver.Current_Measure.I0.v" ,
"InverterWFETs/Gate Driver/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver.Current_Measure.I1.v" ,
"InverterWFETs/Gate Driver/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver.Diode.diode.H.T" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Temperature" , } , { "Gate_Driver.Diode.diode.i_capacitor" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance current" , } , {
"Gate_Driver.Diode.diode.junctionCapacitance.vc" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , TRUE , FALSE , TRUE ,
"Capacitor voltage" , } , { "Gate_Driver.Diode.diode.junctionCapacitance.i" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.Diode.diode.junctionCapacitance.n.v" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Diode.diode.junctionCapacitance.p.v" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Diode.diode.junctionCapacitance.v" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Diode.diode.power_dissipated" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.Diode.diode.v_capacitor" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance voltage" , } , { "Gate_Driver.Diode.diode.i" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.Diode.diode.n.v" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Diode.diode.p.v" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Diode.diode.v" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Diode.i_capacitor" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , FALSE , FALSE ,
TRUE , "Junction capacitance current" , } , { "Gate_Driver.Diode.v_capacitor"
, "InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Junction capacitance voltage" , } , { "Gate_Driver.Diode.n.v" ,
"InverterWFETs/Gate Driver/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Diode.p.v" , "InverterWFETs/Gate Driver/Diode"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , { "Gate_Driver.Drain.v" ,
"InverterWFETs/Gate Driver" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver.Inductor.i" ,
"InverterWFETs/Gate Driver/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.Inductor.i_L" ,
"InverterWFETs/Gate Driver/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver.Inductor.power_dissipated" ,
"InverterWFETs/Gate Driver/Inductor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.Inductor.v" ,
"InverterWFETs/Gate Driver/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Inductor.n.v" ,
"InverterWFETs/Gate Driver/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Inductor.p.v" ,
"InverterWFETs/Gate Driver/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Inductor1.i" ,
"InverterWFETs/Gate Driver/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.Inductor1.i_L" ,
"InverterWFETs/Gate Driver/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver.Inductor1.power_dissipated" ,
"InverterWFETs/Gate Driver/Inductor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.Inductor1.v" ,
"InverterWFETs/Gate Driver/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Inductor1.n.v" ,
"InverterWFETs/Gate Driver/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Inductor1.p.v" ,
"InverterWFETs/Gate Driver/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.D.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.G.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.S.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_DS.vc" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_DS.i" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_DS.n.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_DS.p.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_DS.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_GD.vc" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_GD.i" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_GD.n.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_GD.p.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_GD.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_GS.vc" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.capacitor_GS.i" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_GS.n.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_GS.p.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.capacitor_GS.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.drain_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.N_Channel_MOSFET.drain_resistor.i" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.N_Channel_MOSFET.drain_resistor.n.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.drain_resistor.p.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.drain_resistor.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.gate_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.N_Channel_MOSFET.gate_resistor.i" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.N_Channel_MOSFET.gate_resistor.n.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.gate_resistor.p.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.gate_resistor.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.mos.D.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.mos.G.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.mos.S.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.mos.ids" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source current" , } , { "Gate_Driver.N_Channel_MOSFET.mos.igs" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Gate-source current" , } , {
"Gate_Driver.N_Channel_MOSFET.mos.power_dissipated" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.N_Channel_MOSFET.mos.vds" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source voltage" , } , { "Gate_Driver.N_Channel_MOSFET.mos.vgs" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Gate-source voltage" , } , { "Gate_Driver.N_Channel_MOSFET.node2.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.node3.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.node_gate_resistor.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver.N_Channel_MOSFET.source_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.N_Channel_MOSFET.source_resistor.i" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.N_Channel_MOSFET.source_resistor.n.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.source_resistor.p.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.N_Channel_MOSFET.source_resistor.v" ,
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver/Resistor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.Resistor.Resistor.i" ,
"InverterWFETs/Gate Driver/Resistor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.Resistor.Resistor.n.v" ,
"InverterWFETs/Gate Driver/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor.Resistor.p.v" ,
"InverterWFETs/Gate Driver/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor.Resistor.v" ,
"InverterWFETs/Gate Driver/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor.n.v" ,
"InverterWFETs/Gate Driver/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor.p.v" ,
"InverterWFETs/Gate Driver/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor1.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver/Resistor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver.Resistor1.Resistor.i" ,
"InverterWFETs/Gate Driver/Resistor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver.Resistor1.Resistor.n.v" ,
"InverterWFETs/Gate Driver/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor1.Resistor.p.v" ,
"InverterWFETs/Gate Driver/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor1.Resistor.v" ,
"InverterWFETs/Gate Driver/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor1.n.v" ,
"InverterWFETs/Gate Driver/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Resistor1.p.v" ,
"InverterWFETs/Gate Driver/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver.Source.v" , "InverterWFETs/Gate Driver" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , FALSE , "Voltage" , } , { "Gate_Driver.Voltage_Measure3.V0.v"
, "InverterWFETs/Gate Driver/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver.Voltage_Measure3.V1.v" ,
"InverterWFETs/Gate Driver/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver.Voltage_Measure3.Voltage_Sensor3.V" ,
"InverterWFETs/Gate Driver/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "Gate_Driver.Voltage_Measure3.Voltage_Sensor3.i1"
, "InverterWFETs/Gate Driver/Voltage Measure3/Voltage Sensor3" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver.Voltage_Measure3.Voltage_Sensor3.n.v" ,
"InverterWFETs/Gate Driver/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver.Voltage_Measure3.Voltage_Sensor3.p.v" ,
"InverterWFETs/Gate Driver/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver.Voltage_Measure3.Voltage_Sensor3.v1" ,
"InverterWFETs/Gate Driver/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver1.Controlled_Voltage_Source.i" ,
"InverterWFETs/Gate Driver1/Controlled Voltage Source" , 1U , 1U , "A" , 1.0
, "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "i" , } , { "Gate_Driver1.Controlled_Voltage_Source.n.v" ,
"InverterWFETs/Gate Driver1/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver1.Controlled_Voltage_Source.p.v" ,
"InverterWFETs/Gate Driver1/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver1.Controlled_Voltage_Source.v" ,
"InverterWFETs/Gate Driver1/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "v" , } , { "Gate_Driver1.Controlled_Voltage_Source.vT" ,
"InverterWFETs/Gate Driver1/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "vT" , } , { "Gate_Driver1.Current_Measure.Current_Sensor1.I" ,
"InverterWFETs/Gate Driver1/Current Measure/Current Sensor1" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "Gate_Driver1.Current_Measure.Current_Sensor1.i1"
, "InverterWFETs/Gate Driver1/Current Measure/Current Sensor1" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver1.Current_Measure.Current_Sensor1.n.v" ,
"InverterWFETs/Gate Driver1/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver1.Current_Measure.Current_Sensor1.p.v" ,
"InverterWFETs/Gate Driver1/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver1.Current_Measure.Current_Sensor1.v1" ,
"InverterWFETs/Gate Driver1/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver1.Current_Measure.I0.v" ,
"InverterWFETs/Gate Driver1/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver1.Current_Measure.I1.v" ,
"InverterWFETs/Gate Driver1/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver1.Diode.diode.H.T" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Temperature" , } , { "Gate_Driver1.Diode.diode.i_capacitor" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance current" , } , {
"Gate_Driver1.Diode.diode.junctionCapacitance.vc" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , TRUE , FALSE , TRUE ,
"Capacitor voltage" , } , { "Gate_Driver1.Diode.diode.junctionCapacitance.i"
, "InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.Diode.diode.junctionCapacitance.n.v" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Diode.diode.junctionCapacitance.p.v" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Diode.diode.junctionCapacitance.v" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Diode.diode.power_dissipated" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.Diode.diode.v_capacitor" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance voltage" , } , { "Gate_Driver1.Diode.diode.i" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.Diode.diode.n.v" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Diode.diode.p.v" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Diode.diode.v" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Diode.i_capacitor" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , FALSE , FALSE ,
TRUE , "Junction capacitance current" , } , {
"Gate_Driver1.Diode.v_capacitor" , "InverterWFETs/Gate Driver1/Diode" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Junction capacitance voltage" , } , {
"Gate_Driver1.Diode.n.v" , "InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver1.Diode.p.v" ,
"InverterWFETs/Gate Driver1/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Drain.v" , "InverterWFETs/Gate Driver1" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , { "Gate_Driver1.Inductor.i" ,
"InverterWFETs/Gate Driver1/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.Inductor.i_L" ,
"InverterWFETs/Gate Driver1/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver1.Inductor.power_dissipated" ,
"InverterWFETs/Gate Driver1/Inductor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.Inductor.v" ,
"InverterWFETs/Gate Driver1/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Inductor.n.v" ,
"InverterWFETs/Gate Driver1/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Inductor.p.v" ,
"InverterWFETs/Gate Driver1/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Inductor1.i" ,
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.Inductor1.i_L" ,
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver1.Inductor1.power_dissipated" ,
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.Inductor1.v" ,
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Inductor1.n.v" ,
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Inductor1.p.v" ,
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.D.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.G.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.S.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_DS.vc" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_DS.i" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_DS.n.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_DS.p.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_DS.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_GD.vc" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_GD.i" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_GD.n.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_GD.p.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_GD.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_GS.vc" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.capacitor_GS.i" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_GS.n.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_GS.p.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.capacitor_GS.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.drain_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.N_Channel_MOSFET.drain_resistor.i" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.N_Channel_MOSFET.drain_resistor.n.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.drain_resistor.p.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.drain_resistor.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.gate_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.N_Channel_MOSFET.gate_resistor.i" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.N_Channel_MOSFET.gate_resistor.n.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.gate_resistor.p.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.gate_resistor.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.mos.D.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.mos.G.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.mos.S.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.mos.ids" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source current" , } , { "Gate_Driver1.N_Channel_MOSFET.mos.igs" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Gate-source current" , } , {
"Gate_Driver1.N_Channel_MOSFET.mos.power_dissipated" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.N_Channel_MOSFET.mos.vds" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.mos.vgs" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Gate-source voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.node2.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.node3.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.node_gate_resistor.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver1.N_Channel_MOSFET.source_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.N_Channel_MOSFET.source_resistor.i"
, "InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.N_Channel_MOSFET.source_resistor.n.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.source_resistor.p.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.N_Channel_MOSFET.source_resistor.v" ,
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver1/Resistor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.Resistor.Resistor.i" ,
"InverterWFETs/Gate Driver1/Resistor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.Resistor.Resistor.n.v" ,
"InverterWFETs/Gate Driver1/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor.Resistor.p.v" ,
"InverterWFETs/Gate Driver1/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor.Resistor.v" ,
"InverterWFETs/Gate Driver1/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor.n.v" ,
"InverterWFETs/Gate Driver1/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor.p.v" ,
"InverterWFETs/Gate Driver1/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor1.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver1/Resistor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver1.Resistor1.Resistor.i" ,
"InverterWFETs/Gate Driver1/Resistor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver1.Resistor1.Resistor.n.v" ,
"InverterWFETs/Gate Driver1/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor1.Resistor.p.v" ,
"InverterWFETs/Gate Driver1/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor1.Resistor.v" ,
"InverterWFETs/Gate Driver1/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor1.n.v" ,
"InverterWFETs/Gate Driver1/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Resistor1.p.v" ,
"InverterWFETs/Gate Driver1/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver1.Source.v" , "InverterWFETs/Gate Driver1" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , {
"Gate_Driver1.Voltage_Measure3.V0.v" ,
"InverterWFETs/Gate Driver1/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver1.Voltage_Measure3.V1.v" ,
"InverterWFETs/Gate Driver1/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver1.Voltage_Measure3.Voltage_Sensor3.V" ,
"InverterWFETs/Gate Driver1/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "Gate_Driver1.Voltage_Measure3.Voltage_Sensor3.i1"
, "InverterWFETs/Gate Driver1/Voltage Measure3/Voltage Sensor3" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver1.Voltage_Measure3.Voltage_Sensor3.n.v" ,
"InverterWFETs/Gate Driver1/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver1.Voltage_Measure3.Voltage_Sensor3.p.v" ,
"InverterWFETs/Gate Driver1/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver1.Voltage_Measure3.Voltage_Sensor3.v1" ,
"InverterWFETs/Gate Driver1/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver2.Controlled_Voltage_Source.i" ,
"InverterWFETs/Gate Driver2/Controlled Voltage Source" , 1U , 1U , "A" , 1.0
, "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "i" , } , { "Gate_Driver2.Controlled_Voltage_Source.n.v" ,
"InverterWFETs/Gate Driver2/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver2.Controlled_Voltage_Source.p.v" ,
"InverterWFETs/Gate Driver2/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver2.Controlled_Voltage_Source.v" ,
"InverterWFETs/Gate Driver2/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "v" , } , { "Gate_Driver2.Controlled_Voltage_Source.vT" ,
"InverterWFETs/Gate Driver2/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "vT" , } , { "Gate_Driver2.Current_Measure.Current_Sensor1.I" ,
"InverterWFETs/Gate Driver2/Current Measure/Current Sensor1" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "Gate_Driver2.Current_Measure.Current_Sensor1.i1"
, "InverterWFETs/Gate Driver2/Current Measure/Current Sensor1" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver2.Current_Measure.Current_Sensor1.n.v" ,
"InverterWFETs/Gate Driver2/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver2.Current_Measure.Current_Sensor1.p.v" ,
"InverterWFETs/Gate Driver2/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver2.Current_Measure.Current_Sensor1.v1" ,
"InverterWFETs/Gate Driver2/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver2.Current_Measure.I0.v" ,
"InverterWFETs/Gate Driver2/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver2.Current_Measure.I1.v" ,
"InverterWFETs/Gate Driver2/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver2.Diode.diode.H.T" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Temperature" , } , { "Gate_Driver2.Diode.diode.i_capacitor" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance current" , } , {
"Gate_Driver2.Diode.diode.junctionCapacitance.vc" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , TRUE , FALSE , TRUE ,
"Capacitor voltage" , } , { "Gate_Driver2.Diode.diode.junctionCapacitance.i"
, "InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.Diode.diode.junctionCapacitance.n.v" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Diode.diode.junctionCapacitance.p.v" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Diode.diode.junctionCapacitance.v" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Diode.diode.power_dissipated" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.Diode.diode.v_capacitor" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance voltage" , } , { "Gate_Driver2.Diode.diode.i" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.Diode.diode.n.v" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Diode.diode.p.v" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Diode.diode.v" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Diode.i_capacitor" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , FALSE , FALSE ,
TRUE , "Junction capacitance current" , } , {
"Gate_Driver2.Diode.v_capacitor" , "InverterWFETs/Gate Driver2/Diode" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Junction capacitance voltage" , } , {
"Gate_Driver2.Diode.n.v" , "InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver2.Diode.p.v" ,
"InverterWFETs/Gate Driver2/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Drain.v" , "InverterWFETs/Gate Driver2" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , { "Gate_Driver2.Inductor.i" ,
"InverterWFETs/Gate Driver2/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.Inductor.i_L" ,
"InverterWFETs/Gate Driver2/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver2.Inductor.power_dissipated" ,
"InverterWFETs/Gate Driver2/Inductor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.Inductor.v" ,
"InverterWFETs/Gate Driver2/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Inductor.n.v" ,
"InverterWFETs/Gate Driver2/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Inductor.p.v" ,
"InverterWFETs/Gate Driver2/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Inductor1.i" ,
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.Inductor1.i_L" ,
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver2.Inductor1.power_dissipated" ,
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.Inductor1.v" ,
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Inductor1.n.v" ,
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Inductor1.p.v" ,
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.D.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.G.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.S.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_DS.vc" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_DS.i" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_DS.n.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_DS.p.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_DS.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_GD.vc" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_GD.i" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_GD.n.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_GD.p.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_GD.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_GS.vc" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.capacitor_GS.i" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_GS.n.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_GS.p.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.capacitor_GS.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.drain_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.N_Channel_MOSFET.drain_resistor.i" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.N_Channel_MOSFET.drain_resistor.n.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.drain_resistor.p.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.drain_resistor.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.gate_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.N_Channel_MOSFET.gate_resistor.i" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.N_Channel_MOSFET.gate_resistor.n.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.gate_resistor.p.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.gate_resistor.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.mos.D.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.mos.G.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.mos.S.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.mos.ids" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source current" , } , { "Gate_Driver2.N_Channel_MOSFET.mos.igs" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Gate-source current" , } , {
"Gate_Driver2.N_Channel_MOSFET.mos.power_dissipated" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.N_Channel_MOSFET.mos.vds" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.mos.vgs" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Gate-source voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.node2.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.node3.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.node_gate_resistor.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver2.N_Channel_MOSFET.source_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.N_Channel_MOSFET.source_resistor.i"
, "InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.N_Channel_MOSFET.source_resistor.n.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.source_resistor.p.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.N_Channel_MOSFET.source_resistor.v" ,
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver2/Resistor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.Resistor.Resistor.i" ,
"InverterWFETs/Gate Driver2/Resistor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.Resistor.Resistor.n.v" ,
"InverterWFETs/Gate Driver2/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor.Resistor.p.v" ,
"InverterWFETs/Gate Driver2/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor.Resistor.v" ,
"InverterWFETs/Gate Driver2/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor.n.v" ,
"InverterWFETs/Gate Driver2/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor.p.v" ,
"InverterWFETs/Gate Driver2/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor1.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver2/Resistor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver2.Resistor1.Resistor.i" ,
"InverterWFETs/Gate Driver2/Resistor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver2.Resistor1.Resistor.n.v" ,
"InverterWFETs/Gate Driver2/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor1.Resistor.p.v" ,
"InverterWFETs/Gate Driver2/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor1.Resistor.v" ,
"InverterWFETs/Gate Driver2/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor1.n.v" ,
"InverterWFETs/Gate Driver2/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Resistor1.p.v" ,
"InverterWFETs/Gate Driver2/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver2.Source.v" , "InverterWFETs/Gate Driver2" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , {
"Gate_Driver2.Voltage_Measure3.V0.v" ,
"InverterWFETs/Gate Driver2/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver2.Voltage_Measure3.V1.v" ,
"InverterWFETs/Gate Driver2/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver2.Voltage_Measure3.Voltage_Sensor3.V" ,
"InverterWFETs/Gate Driver2/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "Gate_Driver2.Voltage_Measure3.Voltage_Sensor3.i1"
, "InverterWFETs/Gate Driver2/Voltage Measure3/Voltage Sensor3" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver2.Voltage_Measure3.Voltage_Sensor3.n.v" ,
"InverterWFETs/Gate Driver2/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver2.Voltage_Measure3.Voltage_Sensor3.p.v" ,
"InverterWFETs/Gate Driver2/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver2.Voltage_Measure3.Voltage_Sensor3.v1" ,
"InverterWFETs/Gate Driver2/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver3.Controlled_Voltage_Source.i" ,
"InverterWFETs/Gate Driver3/Controlled Voltage Source" , 1U , 1U , "A" , 1.0
, "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "i" , } , { "Gate_Driver3.Controlled_Voltage_Source.n.v" ,
"InverterWFETs/Gate Driver3/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver3.Controlled_Voltage_Source.p.v" ,
"InverterWFETs/Gate Driver3/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver3.Controlled_Voltage_Source.v" ,
"InverterWFETs/Gate Driver3/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "v" , } , { "Gate_Driver3.Controlled_Voltage_Source.vT" ,
"InverterWFETs/Gate Driver3/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "vT" , } , { "Gate_Driver3.Current_Measure.Current_Sensor1.I" ,
"InverterWFETs/Gate Driver3/Current Measure/Current Sensor1" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "Gate_Driver3.Current_Measure.Current_Sensor1.i1"
, "InverterWFETs/Gate Driver3/Current Measure/Current Sensor1" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver3.Current_Measure.Current_Sensor1.n.v" ,
"InverterWFETs/Gate Driver3/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver3.Current_Measure.Current_Sensor1.p.v" ,
"InverterWFETs/Gate Driver3/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver3.Current_Measure.Current_Sensor1.v1" ,
"InverterWFETs/Gate Driver3/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver3.Current_Measure.I0.v" ,
"InverterWFETs/Gate Driver3/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver3.Current_Measure.I1.v" ,
"InverterWFETs/Gate Driver3/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver3.Diode.diode.H.T" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Temperature" , } , { "Gate_Driver3.Diode.diode.i_capacitor" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance current" , } , {
"Gate_Driver3.Diode.diode.junctionCapacitance.vc" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , TRUE , FALSE , TRUE ,
"Capacitor voltage" , } , { "Gate_Driver3.Diode.diode.junctionCapacitance.i"
, "InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.Diode.diode.junctionCapacitance.n.v" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Diode.diode.junctionCapacitance.p.v" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Diode.diode.junctionCapacitance.v" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Diode.diode.power_dissipated" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.Diode.diode.v_capacitor" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance voltage" , } , { "Gate_Driver3.Diode.diode.i" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.Diode.diode.n.v" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Diode.diode.p.v" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Diode.diode.v" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Diode.i_capacitor" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , FALSE , FALSE ,
TRUE , "Junction capacitance current" , } , {
"Gate_Driver3.Diode.v_capacitor" , "InverterWFETs/Gate Driver3/Diode" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Junction capacitance voltage" , } , {
"Gate_Driver3.Diode.n.v" , "InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver3.Diode.p.v" ,
"InverterWFETs/Gate Driver3/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Drain.v" , "InverterWFETs/Gate Driver3" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , { "Gate_Driver3.Inductor.i" ,
"InverterWFETs/Gate Driver3/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.Inductor.i_L" ,
"InverterWFETs/Gate Driver3/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver3.Inductor.power_dissipated" ,
"InverterWFETs/Gate Driver3/Inductor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.Inductor.v" ,
"InverterWFETs/Gate Driver3/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Inductor.n.v" ,
"InverterWFETs/Gate Driver3/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Inductor.p.v" ,
"InverterWFETs/Gate Driver3/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Inductor1.i" ,
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.Inductor1.i_L" ,
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver3.Inductor1.power_dissipated" ,
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.Inductor1.v" ,
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Inductor1.n.v" ,
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Inductor1.p.v" ,
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.D.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.G.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.S.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_DS.vc" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_DS.i" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_DS.n.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_DS.p.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_DS.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_GD.vc" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_GD.i" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_GD.n.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_GD.p.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_GD.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_GS.vc" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.capacitor_GS.i" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_GS.n.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_GS.p.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.capacitor_GS.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.drain_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.N_Channel_MOSFET.drain_resistor.i" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.N_Channel_MOSFET.drain_resistor.n.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.drain_resistor.p.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.drain_resistor.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.gate_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.N_Channel_MOSFET.gate_resistor.i" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.N_Channel_MOSFET.gate_resistor.n.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.gate_resistor.p.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.gate_resistor.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.mos.D.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.mos.G.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.mos.S.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.mos.ids" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source current" , } , { "Gate_Driver3.N_Channel_MOSFET.mos.igs" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Gate-source current" , } , {
"Gate_Driver3.N_Channel_MOSFET.mos.power_dissipated" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.N_Channel_MOSFET.mos.vds" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.mos.vgs" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Gate-source voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.node2.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.node3.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.node_gate_resistor.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver3.N_Channel_MOSFET.source_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.N_Channel_MOSFET.source_resistor.i"
, "InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.N_Channel_MOSFET.source_resistor.n.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.source_resistor.p.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.N_Channel_MOSFET.source_resistor.v" ,
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver3/Resistor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.Resistor.Resistor.i" ,
"InverterWFETs/Gate Driver3/Resistor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.Resistor.Resistor.n.v" ,
"InverterWFETs/Gate Driver3/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor.Resistor.p.v" ,
"InverterWFETs/Gate Driver3/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor.Resistor.v" ,
"InverterWFETs/Gate Driver3/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor.n.v" ,
"InverterWFETs/Gate Driver3/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor.p.v" ,
"InverterWFETs/Gate Driver3/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor1.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver3/Resistor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver3.Resistor1.Resistor.i" ,
"InverterWFETs/Gate Driver3/Resistor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver3.Resistor1.Resistor.n.v" ,
"InverterWFETs/Gate Driver3/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor1.Resistor.p.v" ,
"InverterWFETs/Gate Driver3/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor1.Resistor.v" ,
"InverterWFETs/Gate Driver3/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor1.n.v" ,
"InverterWFETs/Gate Driver3/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Resistor1.p.v" ,
"InverterWFETs/Gate Driver3/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver3.Source.v" , "InverterWFETs/Gate Driver3" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , {
"Gate_Driver3.Voltage_Measure3.V0.v" ,
"InverterWFETs/Gate Driver3/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver3.Voltage_Measure3.V1.v" ,
"InverterWFETs/Gate Driver3/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver3.Voltage_Measure3.Voltage_Sensor3.V" ,
"InverterWFETs/Gate Driver3/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "Gate_Driver3.Voltage_Measure3.Voltage_Sensor3.i1"
, "InverterWFETs/Gate Driver3/Voltage Measure3/Voltage Sensor3" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver3.Voltage_Measure3.Voltage_Sensor3.n.v" ,
"InverterWFETs/Gate Driver3/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver3.Voltage_Measure3.Voltage_Sensor3.p.v" ,
"InverterWFETs/Gate Driver3/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver3.Voltage_Measure3.Voltage_Sensor3.v1" ,
"InverterWFETs/Gate Driver3/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver4.Controlled_Voltage_Source.i" ,
"InverterWFETs/Gate Driver4/Controlled Voltage Source" , 1U , 1U , "A" , 1.0
, "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "i" , } , { "Gate_Driver4.Controlled_Voltage_Source.n.v" ,
"InverterWFETs/Gate Driver4/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver4.Controlled_Voltage_Source.p.v" ,
"InverterWFETs/Gate Driver4/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver4.Controlled_Voltage_Source.v" ,
"InverterWFETs/Gate Driver4/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "v" , } , { "Gate_Driver4.Controlled_Voltage_Source.vT" ,
"InverterWFETs/Gate Driver4/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "vT" , } , { "Gate_Driver4.Current_Measure.Current_Sensor1.I" ,
"InverterWFETs/Gate Driver4/Current Measure/Current Sensor1" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "Gate_Driver4.Current_Measure.Current_Sensor1.i1"
, "InverterWFETs/Gate Driver4/Current Measure/Current Sensor1" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver4.Current_Measure.Current_Sensor1.n.v" ,
"InverterWFETs/Gate Driver4/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver4.Current_Measure.Current_Sensor1.p.v" ,
"InverterWFETs/Gate Driver4/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver4.Current_Measure.Current_Sensor1.v1" ,
"InverterWFETs/Gate Driver4/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver4.Current_Measure.I0.v" ,
"InverterWFETs/Gate Driver4/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver4.Current_Measure.I1.v" ,
"InverterWFETs/Gate Driver4/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver4.Diode.diode.H.T" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Temperature" , } , { "Gate_Driver4.Diode.diode.i_capacitor" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance current" , } , {
"Gate_Driver4.Diode.diode.junctionCapacitance.vc" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , TRUE , FALSE , TRUE ,
"Capacitor voltage" , } , { "Gate_Driver4.Diode.diode.junctionCapacitance.i"
, "InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.Diode.diode.junctionCapacitance.n.v" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Diode.diode.junctionCapacitance.p.v" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Diode.diode.junctionCapacitance.v" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Diode.diode.power_dissipated" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.Diode.diode.v_capacitor" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance voltage" , } , { "Gate_Driver4.Diode.diode.i" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.Diode.diode.n.v" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Diode.diode.p.v" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Diode.diode.v" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Diode.i_capacitor" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , FALSE , FALSE ,
TRUE , "Junction capacitance current" , } , {
"Gate_Driver4.Diode.v_capacitor" , "InverterWFETs/Gate Driver4/Diode" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Junction capacitance voltage" , } , {
"Gate_Driver4.Diode.n.v" , "InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver4.Diode.p.v" ,
"InverterWFETs/Gate Driver4/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Drain.v" , "InverterWFETs/Gate Driver4" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , { "Gate_Driver4.Inductor.i" ,
"InverterWFETs/Gate Driver4/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.Inductor.i_L" ,
"InverterWFETs/Gate Driver4/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver4.Inductor.power_dissipated" ,
"InverterWFETs/Gate Driver4/Inductor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.Inductor.v" ,
"InverterWFETs/Gate Driver4/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Inductor.n.v" ,
"InverterWFETs/Gate Driver4/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Inductor.p.v" ,
"InverterWFETs/Gate Driver4/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Inductor1.i" ,
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.Inductor1.i_L" ,
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver4.Inductor1.power_dissipated" ,
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.Inductor1.v" ,
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Inductor1.n.v" ,
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Inductor1.p.v" ,
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.D.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.G.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.S.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_DS.vc" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_DS.i" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_DS.n.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_DS.p.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_DS.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_GD.vc" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_GD.i" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_GD.n.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_GD.p.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_GD.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_GS.vc" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.capacitor_GS.i" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_GS.n.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_GS.p.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.capacitor_GS.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.drain_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.N_Channel_MOSFET.drain_resistor.i" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.N_Channel_MOSFET.drain_resistor.n.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.drain_resistor.p.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.drain_resistor.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.gate_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.N_Channel_MOSFET.gate_resistor.i" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.N_Channel_MOSFET.gate_resistor.n.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.gate_resistor.p.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.gate_resistor.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.mos.D.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.mos.G.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.mos.S.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.mos.ids" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source current" , } , { "Gate_Driver4.N_Channel_MOSFET.mos.igs" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Gate-source current" , } , {
"Gate_Driver4.N_Channel_MOSFET.mos.power_dissipated" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.N_Channel_MOSFET.mos.vds" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.mos.vgs" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Gate-source voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.node2.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.node3.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.node_gate_resistor.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver4.N_Channel_MOSFET.source_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.N_Channel_MOSFET.source_resistor.i"
, "InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.N_Channel_MOSFET.source_resistor.n.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.source_resistor.p.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.N_Channel_MOSFET.source_resistor.v" ,
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver4/Resistor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.Resistor.Resistor.i" ,
"InverterWFETs/Gate Driver4/Resistor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.Resistor.Resistor.n.v" ,
"InverterWFETs/Gate Driver4/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor.Resistor.p.v" ,
"InverterWFETs/Gate Driver4/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor.Resistor.v" ,
"InverterWFETs/Gate Driver4/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor.n.v" ,
"InverterWFETs/Gate Driver4/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor.p.v" ,
"InverterWFETs/Gate Driver4/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor1.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver4/Resistor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver4.Resistor1.Resistor.i" ,
"InverterWFETs/Gate Driver4/Resistor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver4.Resistor1.Resistor.n.v" ,
"InverterWFETs/Gate Driver4/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor1.Resistor.p.v" ,
"InverterWFETs/Gate Driver4/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor1.Resistor.v" ,
"InverterWFETs/Gate Driver4/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor1.n.v" ,
"InverterWFETs/Gate Driver4/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Resistor1.p.v" ,
"InverterWFETs/Gate Driver4/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver4.Source.v" , "InverterWFETs/Gate Driver4" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , {
"Gate_Driver4.Voltage_Measure3.V0.v" ,
"InverterWFETs/Gate Driver4/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver4.Voltage_Measure3.V1.v" ,
"InverterWFETs/Gate Driver4/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver4.Voltage_Measure3.Voltage_Sensor3.V" ,
"InverterWFETs/Gate Driver4/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "Gate_Driver4.Voltage_Measure3.Voltage_Sensor3.i1"
, "InverterWFETs/Gate Driver4/Voltage Measure3/Voltage Sensor3" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver4.Voltage_Measure3.Voltage_Sensor3.n.v" ,
"InverterWFETs/Gate Driver4/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver4.Voltage_Measure3.Voltage_Sensor3.p.v" ,
"InverterWFETs/Gate Driver4/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver4.Voltage_Measure3.Voltage_Sensor3.v1" ,
"InverterWFETs/Gate Driver4/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver5.Controlled_Voltage_Source.i" ,
"InverterWFETs/Gate Driver5/Controlled Voltage Source" , 1U , 1U , "A" , 1.0
, "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "i" , } , { "Gate_Driver5.Controlled_Voltage_Source.n.v" ,
"InverterWFETs/Gate Driver5/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver5.Controlled_Voltage_Source.p.v" ,
"InverterWFETs/Gate Driver5/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "Voltage" , } , { "Gate_Driver5.Controlled_Voltage_Source.v" ,
"InverterWFETs/Gate Driver5/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "v" , } , { "Gate_Driver5.Controlled_Voltage_Source.vT" ,
"InverterWFETs/Gate Driver5/Controlled Voltage Source" , 1U , 1U , "V" , 1.0
, "V" , NE_NOMINAL_SOURCE_FIXED , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
TRUE , "vT" , } , { "Gate_Driver5.Current_Measure.Current_Sensor1.I" ,
"InverterWFETs/Gate Driver5/Current Measure/Current Sensor1" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "Gate_Driver5.Current_Measure.Current_Sensor1.i1"
, "InverterWFETs/Gate Driver5/Current Measure/Current Sensor1" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver5.Current_Measure.Current_Sensor1.n.v" ,
"InverterWFETs/Gate Driver5/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver5.Current_Measure.Current_Sensor1.p.v" ,
"InverterWFETs/Gate Driver5/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver5.Current_Measure.Current_Sensor1.v1" ,
"InverterWFETs/Gate Driver5/Current Measure/Current Sensor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver5.Current_Measure.I0.v" ,
"InverterWFETs/Gate Driver5/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver5.Current_Measure.I1.v" ,
"InverterWFETs/Gate Driver5/Current Measure" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver5.Diode.diode.H.T" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "K" , 1.0 , "K" ,
NE_NOMINAL_SOURCE_DERIVED , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Temperature" , } , { "Gate_Driver5.Diode.diode.i_capacitor" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance current" , } , {
"Gate_Driver5.Diode.diode.junctionCapacitance.vc" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , TRUE , FALSE , TRUE ,
"Capacitor voltage" , } , { "Gate_Driver5.Diode.diode.junctionCapacitance.i"
, "InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.Diode.diode.junctionCapacitance.n.v" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Diode.diode.junctionCapacitance.p.v" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Diode.diode.junctionCapacitance.v" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Diode.diode.power_dissipated" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.Diode.diode.v_capacitor" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Junction capacitance voltage" , } , { "Gate_Driver5.Diode.diode.i" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.Diode.diode.n.v" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Diode.diode.p.v" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Diode.diode.v" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Diode.i_capacitor" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , FALSE , FALSE ,
TRUE , "Junction capacitance current" , } , {
"Gate_Driver5.Diode.v_capacitor" , "InverterWFETs/Gate Driver5/Diode" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Junction capacitance voltage" , } , {
"Gate_Driver5.Diode.n.v" , "InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Gate_Driver5.Diode.p.v" ,
"InverterWFETs/Gate Driver5/Diode" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Drain.v" , "InverterWFETs/Gate Driver5" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , { "Gate_Driver5.Inductor.i" ,
"InverterWFETs/Gate Driver5/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.Inductor.i_L" ,
"InverterWFETs/Gate Driver5/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver5.Inductor.power_dissipated" ,
"InverterWFETs/Gate Driver5/Inductor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.Inductor.v" ,
"InverterWFETs/Gate Driver5/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Inductor.n.v" ,
"InverterWFETs/Gate Driver5/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Inductor.p.v" ,
"InverterWFETs/Gate Driver5/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Inductor1.i" ,
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.Inductor1.i_L" ,
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Gate_Driver5.Inductor1.power_dissipated" ,
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.Inductor1.v" ,
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Inductor1.n.v" ,
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Inductor1.p.v" ,
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.D.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.G.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.S.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_DS.vc" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_DS.i" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_DS.n.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_DS.p.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_DS.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_GD.vc" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_GD.i" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_GD.n.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_GD.p.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_GD.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_GS.vc" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Capacitor voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.capacitor_GS.i" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_GS.n.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_GS.p.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.capacitor_GS.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.drain_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.N_Channel_MOSFET.drain_resistor.i" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.N_Channel_MOSFET.drain_resistor.n.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.drain_resistor.p.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.drain_resistor.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.gate_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.N_Channel_MOSFET.gate_resistor.i" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.N_Channel_MOSFET.gate_resistor.n.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.gate_resistor.p.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.gate_resistor.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.mos.D.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.mos.G.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.mos.S.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.mos.ids" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source current" , } , { "Gate_Driver5.N_Channel_MOSFET.mos.igs" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Gate-source current" , } , {
"Gate_Driver5.N_Channel_MOSFET.mos.power_dissipated" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.N_Channel_MOSFET.mos.vds" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Drain-source voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.mos.vgs" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Gate-source voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.node2.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.node3.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.node_gate_resistor.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , {
"Gate_Driver5.N_Channel_MOSFET.source_resistor.power_dissipated" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.N_Channel_MOSFET.source_resistor.i"
, "InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.N_Channel_MOSFET.source_resistor.n.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.source_resistor.p.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.N_Channel_MOSFET.source_resistor.v" ,
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver5/Resistor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.Resistor.Resistor.i" ,
"InverterWFETs/Gate Driver5/Resistor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.Resistor.Resistor.n.v" ,
"InverterWFETs/Gate Driver5/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor.Resistor.p.v" ,
"InverterWFETs/Gate Driver5/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor.Resistor.v" ,
"InverterWFETs/Gate Driver5/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor.n.v" ,
"InverterWFETs/Gate Driver5/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor.p.v" ,
"InverterWFETs/Gate Driver5/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor1.Resistor.power_dissipated" ,
"InverterWFETs/Gate Driver5/Resistor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Gate_Driver5.Resistor1.Resistor.i" ,
"InverterWFETs/Gate Driver5/Resistor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Gate_Driver5.Resistor1.Resistor.n.v" ,
"InverterWFETs/Gate Driver5/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor1.Resistor.p.v" ,
"InverterWFETs/Gate Driver5/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor1.Resistor.v" ,
"InverterWFETs/Gate Driver5/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor1.n.v" ,
"InverterWFETs/Gate Driver5/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Resistor1.p.v" ,
"InverterWFETs/Gate Driver5/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Gate_Driver5.Source.v" , "InverterWFETs/Gate Driver5" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , FALSE , "Voltage" , } , {
"Gate_Driver5.Voltage_Measure3.V0.v" ,
"InverterWFETs/Gate Driver5/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver5.Voltage_Measure3.V1.v" ,
"InverterWFETs/Gate Driver5/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Gate_Driver5.Voltage_Measure3.Voltage_Sensor3.V" ,
"InverterWFETs/Gate Driver5/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "Gate_Driver5.Voltage_Measure3.Voltage_Sensor3.i1"
, "InverterWFETs/Gate Driver5/Voltage Measure3/Voltage Sensor3" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, FALSE , TRUE , "Current" , } , {
"Gate_Driver5.Voltage_Measure3.Voltage_Sensor3.n.v" ,
"InverterWFETs/Gate Driver5/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver5.Voltage_Measure3.Voltage_Sensor3.p.v" ,
"InverterWFETs/Gate Driver5/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"Gate_Driver5.Voltage_Measure3.Voltage_Sensor3.v1" ,
"InverterWFETs/Gate Driver5/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor.i" , "InverterWFETs/Inductor" , 1U
, 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Current" , } , { "Inductor.i_L" ,
"InverterWFETs/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor.power_dissipated" ,
"InverterWFETs/Inductor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor.v" , "InverterWFETs/Inductor" , 1U , 1U
, "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor.n.v" ,
"InverterWFETs/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor.p.v" , "InverterWFETs/Inductor" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor1.i" , "InverterWFETs/Inductor1" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor1.i_L" ,
"InverterWFETs/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor1.power_dissipated" ,
"InverterWFETs/Inductor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor1.v" , "InverterWFETs/Inductor1" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor1.n.v" ,
"InverterWFETs/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor1.p.v" , "InverterWFETs/Inductor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor10.i" , "InverterWFETs/Inductor10"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor10.i_L" ,
"InverterWFETs/Inductor10" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor10.power_dissipated" ,
"InverterWFETs/Inductor10" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor10.v" , "InverterWFETs/Inductor10" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor10.n.v" ,
"InverterWFETs/Inductor10" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor10.p.v" , "InverterWFETs/Inductor10" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor11.i" ,
"InverterWFETs/Inductor11" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Inductor11.i_L" , "InverterWFETs/Inductor11" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE ,
TRUE , FALSE , TRUE , "Inductor current" , } , {
"Inductor11.power_dissipated" , "InverterWFETs/Inductor11" , 1U , 1U , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Power dissipated" , } , { "Inductor11.v" ,
"InverterWFETs/Inductor11" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor11.n.v" , "InverterWFETs/Inductor11" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor11.p.v" ,
"InverterWFETs/Inductor11" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor12.i" , "InverterWFETs/Inductor12" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , { "Inductor12.i_L" ,
"InverterWFETs/Inductor12" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor12.power_dissipated" ,
"InverterWFETs/Inductor12" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor12.v" , "InverterWFETs/Inductor12" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor12.n.v" ,
"InverterWFETs/Inductor12" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor12.p.v" , "InverterWFETs/Inductor12" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor13.i" ,
"InverterWFETs/Inductor13" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Inductor13.i_L" , "InverterWFETs/Inductor13" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE ,
TRUE , FALSE , TRUE , "Inductor current" , } , {
"Inductor13.power_dissipated" , "InverterWFETs/Inductor13" , 1U , 1U , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Power dissipated" , } , { "Inductor13.v" ,
"InverterWFETs/Inductor13" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor13.n.v" , "InverterWFETs/Inductor13" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor13.p.v" ,
"InverterWFETs/Inductor13" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor14.i" , "InverterWFETs/Inductor14" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , { "Inductor14.i_L" ,
"InverterWFETs/Inductor14" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor14.power_dissipated" ,
"InverterWFETs/Inductor14" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor14.v" , "InverterWFETs/Inductor14" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor14.n.v" ,
"InverterWFETs/Inductor14" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor14.p.v" , "InverterWFETs/Inductor14" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor15.i" ,
"InverterWFETs/Inductor15" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Inductor15.i_L" , "InverterWFETs/Inductor15" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE ,
TRUE , FALSE , TRUE , "Inductor current" , } , {
"Inductor15.power_dissipated" , "InverterWFETs/Inductor15" , 1U , 1U , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Power dissipated" , } , { "Inductor15.v" ,
"InverterWFETs/Inductor15" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor15.n.v" , "InverterWFETs/Inductor15" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor15.p.v" ,
"InverterWFETs/Inductor15" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor16.i" , "InverterWFETs/Inductor16" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , { "Inductor16.i_L" ,
"InverterWFETs/Inductor16" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor16.power_dissipated" ,
"InverterWFETs/Inductor16" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor16.v" , "InverterWFETs/Inductor16" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor16.n.v" ,
"InverterWFETs/Inductor16" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor16.p.v" , "InverterWFETs/Inductor16" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor17.i" ,
"InverterWFETs/Inductor17" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Inductor17.i_L" , "InverterWFETs/Inductor17" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE ,
TRUE , FALSE , TRUE , "Inductor current" , } , {
"Inductor17.power_dissipated" , "InverterWFETs/Inductor17" , 1U , 1U , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Power dissipated" , } , { "Inductor17.v" ,
"InverterWFETs/Inductor17" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor17.n.v" , "InverterWFETs/Inductor17" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor17.p.v" ,
"InverterWFETs/Inductor17" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor18.i" , "InverterWFETs/Inductor18" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , { "Inductor18.i_L" ,
"InverterWFETs/Inductor18" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor18.power_dissipated" ,
"InverterWFETs/Inductor18" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor18.v" , "InverterWFETs/Inductor18" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor18.n.v" ,
"InverterWFETs/Inductor18" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor18.p.v" , "InverterWFETs/Inductor18" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor19.i" ,
"InverterWFETs/Inductor19" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Inductor19.i_L" , "InverterWFETs/Inductor19" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE ,
TRUE , FALSE , TRUE , "Inductor current" , } , {
"Inductor19.power_dissipated" , "InverterWFETs/Inductor19" , 1U , 1U , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Power dissipated" , } , { "Inductor19.v" ,
"InverterWFETs/Inductor19" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor19.n.v" , "InverterWFETs/Inductor19" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor19.p.v" ,
"InverterWFETs/Inductor19" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor2.i" , "InverterWFETs/Inductor2" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , { "Inductor2.i_L" , "InverterWFETs/Inductor2"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL ,
NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE , TRUE , "Inductor current" , }
, { "Inductor2.power_dissipated" , "InverterWFETs/Inductor2" , 1U , 1U , "W"
, 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Power dissipated" , } , { "Inductor2.v" ,
"InverterWFETs/Inductor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor2.n.v" , "InverterWFETs/Inductor2" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor2.p.v" , "InverterWFETs/Inductor2"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor20.i" ,
"InverterWFETs/Inductor20" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Inductor20.i_L" , "InverterWFETs/Inductor20" , 1U , 1U ,
"A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE ,
TRUE , FALSE , TRUE , "Inductor current" , } , {
"Inductor20.power_dissipated" , "InverterWFETs/Inductor20" , 1U , 1U , "W" ,
1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Power dissipated" , } , { "Inductor20.v" ,
"InverterWFETs/Inductor20" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor20.n.v" , "InverterWFETs/Inductor20" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor20.p.v" ,
"InverterWFETs/Inductor20" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor21.i" , "InverterWFETs/Inductor21" , 1U , 1U , "A"
, 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , { "Inductor21.i_L" ,
"InverterWFETs/Inductor21" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor21.power_dissipated" ,
"InverterWFETs/Inductor21" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor21.v" , "InverterWFETs/Inductor21" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor21.n.v" ,
"InverterWFETs/Inductor21" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor21.p.v" , "InverterWFETs/Inductor21" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Inductor3.i" , "InverterWFETs/Inductor3"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor3.i_L" ,
"InverterWFETs/Inductor3" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor3.power_dissipated" ,
"InverterWFETs/Inductor3" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor3.v" , "InverterWFETs/Inductor3" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor3.n.v" ,
"InverterWFETs/Inductor3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor3.p.v" , "InverterWFETs/Inductor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor4.i" , "InverterWFETs/Inductor4" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor4.i_L" ,
"InverterWFETs/Inductor4" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor4.power_dissipated" ,
"InverterWFETs/Inductor4" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor4.v" , "InverterWFETs/Inductor4" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor4.n.v" ,
"InverterWFETs/Inductor4" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor4.p.v" , "InverterWFETs/Inductor4" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor5.i" , "InverterWFETs/Inductor5" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor5.i_L" ,
"InverterWFETs/Inductor5" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor5.power_dissipated" ,
"InverterWFETs/Inductor5" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor5.v" , "InverterWFETs/Inductor5" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor5.n.v" ,
"InverterWFETs/Inductor5" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor5.p.v" , "InverterWFETs/Inductor5" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor6.i" , "InverterWFETs/Inductor6" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor6.i_L" ,
"InverterWFETs/Inductor6" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor6.power_dissipated" ,
"InverterWFETs/Inductor6" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor6.v" , "InverterWFETs/Inductor6" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor6.n.v" ,
"InverterWFETs/Inductor6" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor6.p.v" , "InverterWFETs/Inductor6" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor7.i" , "InverterWFETs/Inductor7" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor7.i_L" ,
"InverterWFETs/Inductor7" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor7.power_dissipated" ,
"InverterWFETs/Inductor7" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor7.v" , "InverterWFETs/Inductor7" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor7.n.v" ,
"InverterWFETs/Inductor7" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor7.p.v" , "InverterWFETs/Inductor7" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor8.i" , "InverterWFETs/Inductor8" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor8.i_L" ,
"InverterWFETs/Inductor8" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor8.power_dissipated" ,
"InverterWFETs/Inductor8" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor8.v" , "InverterWFETs/Inductor8" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor8.n.v" ,
"InverterWFETs/Inductor8" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor8.p.v" , "InverterWFETs/Inductor8" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Inductor9.i" , "InverterWFETs/Inductor9" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Inductor9.i_L" ,
"InverterWFETs/Inductor9" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "Inductor9.power_dissipated" ,
"InverterWFETs/Inductor9" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Inductor9.v" , "InverterWFETs/Inductor9" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Inductor9.n.v" ,
"InverterWFETs/Inductor9" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Inductor9.p.v" , "InverterWFETs/Inductor9" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "R_L_Load.A.v" , "InverterWFETs/R L Load" ,
1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , FALSE , "Voltage" , } , { "R_L_Load.B.v" ,
"InverterWFETs/R L Load" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.C.v" , "InverterWFETs/R L Load" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , FALSE , "Voltage" , } , {
"R_L_Load.Current_Measure1.Current_Sensor1.I" ,
"InverterWFETs/R L Load/Current Measure1/Current Sensor1" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "R_L_Load.Current_Measure1.Current_Sensor1.i1" ,
"InverterWFETs/R L Load/Current Measure1/Current Sensor1" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , {
"R_L_Load.Current_Measure1.Current_Sensor1.n.v" ,
"InverterWFETs/R L Load/Current Measure1/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Current_Measure1.Current_Sensor1.p.v" ,
"InverterWFETs/R L Load/Current Measure1/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Current_Measure1.Current_Sensor1.v1" ,
"InverterWFETs/R L Load/Current Measure1/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "R_L_Load.Current_Measure1.I0.v" ,
"InverterWFETs/R L Load/Current Measure1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Current_Measure1.I1.v" ,
"InverterWFETs/R L Load/Current Measure1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Current_Measure2.Current_Sensor1.I" ,
"InverterWFETs/R L Load/Current Measure2/Current Sensor1" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "R_L_Load.Current_Measure2.Current_Sensor1.i1" ,
"InverterWFETs/R L Load/Current Measure2/Current Sensor1" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , {
"R_L_Load.Current_Measure2.Current_Sensor1.n.v" ,
"InverterWFETs/R L Load/Current Measure2/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Current_Measure2.Current_Sensor1.p.v" ,
"InverterWFETs/R L Load/Current Measure2/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Current_Measure2.Current_Sensor1.v1" ,
"InverterWFETs/R L Load/Current Measure2/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "R_L_Load.Current_Measure2.I0.v" ,
"InverterWFETs/R L Load/Current Measure2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Current_Measure2.I1.v" ,
"InverterWFETs/R L Load/Current Measure2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Current_Measure5.Current_Sensor1.I" ,
"InverterWFETs/R L Load/Current Measure5/Current Sensor1" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "I" , } , { "R_L_Load.Current_Measure5.Current_Sensor1.i1" ,
"InverterWFETs/R L Load/Current Measure5/Current Sensor1" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Current" , } , {
"R_L_Load.Current_Measure5.Current_Sensor1.n.v" ,
"InverterWFETs/R L Load/Current Measure5/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Current_Measure5.Current_Sensor1.p.v" ,
"InverterWFETs/R L Load/Current Measure5/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Current_Measure5.Current_Sensor1.v1" ,
"InverterWFETs/R L Load/Current Measure5/Current Sensor1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "R_L_Load.Current_Measure5.I0.v" ,
"InverterWFETs/R L Load/Current Measure5" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Current_Measure5.I1.v" ,
"InverterWFETs/R L Load/Current Measure5" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Inductor.i" , "InverterWFETs/R L Load/Inductor" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "R_L_Load.Inductor.i_L" ,
"InverterWFETs/R L Load/Inductor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "R_L_Load.Inductor.power_dissipated" ,
"InverterWFETs/R L Load/Inductor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "R_L_Load.Inductor.v" ,
"InverterWFETs/R L Load/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Inductor.n.v" , "InverterWFETs/R L Load/Inductor"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , { "R_L_Load.Inductor.p.v" ,
"InverterWFETs/R L Load/Inductor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Inductor1.i" , "InverterWFETs/R L Load/Inductor1"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "R_L_Load.Inductor1.i_L" ,
"InverterWFETs/R L Load/Inductor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "R_L_Load.Inductor1.power_dissipated" ,
"InverterWFETs/R L Load/Inductor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "R_L_Load.Inductor1.v" ,
"InverterWFETs/R L Load/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Inductor1.n.v" ,
"InverterWFETs/R L Load/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Inductor1.p.v" ,
"InverterWFETs/R L Load/Inductor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Inductor2.i" , "InverterWFETs/R L Load/Inductor2"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "R_L_Load.Inductor2.i_L" ,
"InverterWFETs/R L Load/Inductor2" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_MANDATORY , FALSE , TRUE , FALSE ,
TRUE , "Inductor current" , } , { "R_L_Load.Inductor2.power_dissipated" ,
"InverterWFETs/R L Load/Inductor2" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "R_L_Load.Inductor2.v" ,
"InverterWFETs/R L Load/Inductor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Inductor2.n.v" ,
"InverterWFETs/R L Load/Inductor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Inductor2.p.v" ,
"InverterWFETs/R L Load/Inductor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor.Resistor.power_dissipated" ,
"InverterWFETs/R L Load/Resistor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "R_L_Load.Resistor.Resistor.i" ,
"InverterWFETs/R L Load/Resistor" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "R_L_Load.Resistor.Resistor.n.v" ,
"InverterWFETs/R L Load/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor.Resistor.p.v" ,
"InverterWFETs/R L Load/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor.Resistor.v" ,
"InverterWFETs/R L Load/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor.n.v" , "InverterWFETs/R L Load/Resistor"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , { "R_L_Load.Resistor.p.v" ,
"InverterWFETs/R L Load/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor1.Resistor.power_dissipated" ,
"InverterWFETs/R L Load/Resistor1" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "R_L_Load.Resistor1.Resistor.i" ,
"InverterWFETs/R L Load/Resistor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "R_L_Load.Resistor1.Resistor.n.v" ,
"InverterWFETs/R L Load/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor1.Resistor.p.v" ,
"InverterWFETs/R L Load/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor1.Resistor.v" ,
"InverterWFETs/R L Load/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor1.n.v" ,
"InverterWFETs/R L Load/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor1.p.v" ,
"InverterWFETs/R L Load/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor2.Resistor.power_dissipated" ,
"InverterWFETs/R L Load/Resistor2" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "R_L_Load.Resistor2.Resistor.i" ,
"InverterWFETs/R L Load/Resistor2" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "R_L_Load.Resistor2.Resistor.n.v" ,
"InverterWFETs/R L Load/Resistor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor2.Resistor.p.v" ,
"InverterWFETs/R L Load/Resistor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor2.Resistor.v" ,
"InverterWFETs/R L Load/Resistor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor2.n.v" ,
"InverterWFETs/R L Load/Resistor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Resistor2.p.v" ,
"InverterWFETs/R L Load/Resistor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "R_L_Load.Voltage_Measure1.V0.v" ,
"InverterWFETs/R L Load/Voltage Measure1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Voltage_Measure1.V1.v" ,
"InverterWFETs/R L Load/Voltage Measure1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Voltage_Measure1.Voltage_Sensor3.V" ,
"InverterWFETs/R L Load/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "R_L_Load.Voltage_Measure1.Voltage_Sensor3.i1" ,
"InverterWFETs/R L Load/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Current" , } , {
"R_L_Load.Voltage_Measure1.Voltage_Sensor3.n.v" ,
"InverterWFETs/R L Load/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Voltage_Measure1.Voltage_Sensor3.p.v" ,
"InverterWFETs/R L Load/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Voltage_Measure1.Voltage_Sensor3.v1" ,
"InverterWFETs/R L Load/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "R_L_Load.Voltage_Measure2.V0.v" ,
"InverterWFETs/R L Load/Voltage Measure2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Voltage_Measure2.V1.v" ,
"InverterWFETs/R L Load/Voltage Measure2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Voltage_Measure2.Voltage_Sensor3.V" ,
"InverterWFETs/R L Load/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "R_L_Load.Voltage_Measure2.Voltage_Sensor3.i1" ,
"InverterWFETs/R L Load/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Current" , } , {
"R_L_Load.Voltage_Measure2.Voltage_Sensor3.n.v" ,
"InverterWFETs/R L Load/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Voltage_Measure2.Voltage_Sensor3.p.v" ,
"InverterWFETs/R L Load/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Voltage_Measure2.Voltage_Sensor3.v1" ,
"InverterWFETs/R L Load/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "R_L_Load.Voltage_Measure3.V0.v" ,
"InverterWFETs/R L Load/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Voltage_Measure3.V1.v" ,
"InverterWFETs/R L Load/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "R_L_Load.Voltage_Measure3.Voltage_Sensor3.V" ,
"InverterWFETs/R L Load/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "V" , } , { "R_L_Load.Voltage_Measure3.Voltage_Sensor3.i1" ,
"InverterWFETs/R L Load/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "A" ,
1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE ,
FALSE , TRUE , "Current" , } , {
"R_L_Load.Voltage_Measure3.Voltage_Sensor3.n.v" ,
"InverterWFETs/R L Load/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Voltage_Measure3.Voltage_Sensor3.p.v" ,
"InverterWFETs/R L Load/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , {
"R_L_Load.Voltage_Measure3.Voltage_Sensor3.v1" ,
"InverterWFETs/R L Load/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor.Resistor.power_dissipated" ,
"InverterWFETs/Resistor" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor.Resistor.i" , "InverterWFETs/Resistor" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Resistor.Resistor.n.v" ,
"InverterWFETs/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor.Resistor.p.v" , "InverterWFETs/Resistor" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor.Resistor.v" ,
"InverterWFETs/Resistor" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor.n.v" , "InverterWFETs/Resistor" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor.p.v" , "InverterWFETs/Resistor" ,
1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , {
"Resistor1.Resistor.power_dissipated" , "InverterWFETs/Resistor1" , 1U , 1U ,
"W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Power dissipated" , } , { "Resistor1.Resistor.i" ,
"InverterWFETs/Resistor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor1.Resistor.n.v" , "InverterWFETs/Resistor1" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor1.Resistor.p.v" ,
"InverterWFETs/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor1.Resistor.v" , "InverterWFETs/Resistor1" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor1.n.v" ,
"InverterWFETs/Resistor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor1.p.v" , "InverterWFETs/Resistor1" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor10.Resistor.power_dissipated" ,
"InverterWFETs/Resistor10" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor10.Resistor.i" ,
"InverterWFETs/Resistor10" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor10.Resistor.n.v" , "InverterWFETs/Resistor10" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor10.Resistor.p.v" ,
"InverterWFETs/Resistor10" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor10.Resistor.v" , "InverterWFETs/Resistor10" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor10.n.v" ,
"InverterWFETs/Resistor10" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor10.p.v" , "InverterWFETs/Resistor10" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor11.Resistor.power_dissipated" ,
"InverterWFETs/Resistor11" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor11.Resistor.i" ,
"InverterWFETs/Resistor11" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor11.Resistor.n.v" , "InverterWFETs/Resistor11" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor11.Resistor.p.v" ,
"InverterWFETs/Resistor11" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor11.Resistor.v" , "InverterWFETs/Resistor11" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor11.n.v" ,
"InverterWFETs/Resistor11" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor11.p.v" , "InverterWFETs/Resistor11" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor12.Resistor.power_dissipated" ,
"InverterWFETs/Resistor12" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor12.Resistor.i" ,
"InverterWFETs/Resistor12" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor12.Resistor.n.v" , "InverterWFETs/Resistor12" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor12.Resistor.p.v" ,
"InverterWFETs/Resistor12" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor12.Resistor.v" , "InverterWFETs/Resistor12" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor12.n.v" ,
"InverterWFETs/Resistor12" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor12.p.v" , "InverterWFETs/Resistor12" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor13.Resistor.power_dissipated" ,
"InverterWFETs/Resistor13" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor13.Resistor.i" ,
"InverterWFETs/Resistor13" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor13.Resistor.n.v" , "InverterWFETs/Resistor13" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor13.Resistor.p.v" ,
"InverterWFETs/Resistor13" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor13.Resistor.v" , "InverterWFETs/Resistor13" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor13.n.v" ,
"InverterWFETs/Resistor13" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor13.p.v" , "InverterWFETs/Resistor13" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor14.Resistor.power_dissipated" ,
"InverterWFETs/Resistor14" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor14.Resistor.i" ,
"InverterWFETs/Resistor14" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor14.Resistor.n.v" , "InverterWFETs/Resistor14" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor14.Resistor.p.v" ,
"InverterWFETs/Resistor14" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor14.Resistor.v" , "InverterWFETs/Resistor14" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor14.n.v" ,
"InverterWFETs/Resistor14" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor14.p.v" , "InverterWFETs/Resistor14" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor15.Resistor.power_dissipated" ,
"InverterWFETs/Resistor15" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor15.Resistor.i" ,
"InverterWFETs/Resistor15" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor15.Resistor.n.v" , "InverterWFETs/Resistor15" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor15.Resistor.p.v" ,
"InverterWFETs/Resistor15" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor15.Resistor.v" , "InverterWFETs/Resistor15" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor15.n.v" ,
"InverterWFETs/Resistor15" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor15.p.v" , "InverterWFETs/Resistor15" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor16.Resistor.power_dissipated" ,
"InverterWFETs/Resistor16" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor16.Resistor.i" ,
"InverterWFETs/Resistor16" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor16.Resistor.n.v" , "InverterWFETs/Resistor16" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor16.Resistor.p.v" ,
"InverterWFETs/Resistor16" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor16.Resistor.v" , "InverterWFETs/Resistor16" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor16.n.v" ,
"InverterWFETs/Resistor16" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor16.p.v" , "InverterWFETs/Resistor16" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor17.Resistor.power_dissipated" ,
"InverterWFETs/Resistor17" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor17.Resistor.i" ,
"InverterWFETs/Resistor17" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor17.Resistor.n.v" , "InverterWFETs/Resistor17" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor17.Resistor.p.v" ,
"InverterWFETs/Resistor17" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor17.Resistor.v" , "InverterWFETs/Resistor17" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor17.n.v" ,
"InverterWFETs/Resistor17" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor17.p.v" , "InverterWFETs/Resistor17" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor18.Resistor.power_dissipated" ,
"InverterWFETs/Resistor18" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor18.Resistor.i" ,
"InverterWFETs/Resistor18" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor18.Resistor.n.v" , "InverterWFETs/Resistor18" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor18.Resistor.p.v" ,
"InverterWFETs/Resistor18" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor18.Resistor.v" , "InverterWFETs/Resistor18" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor18.n.v" ,
"InverterWFETs/Resistor18" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor18.p.v" , "InverterWFETs/Resistor18" , 1U , 1U ,
"V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE
, FALSE , TRUE , "Voltage" , } , { "Resistor2.Resistor.power_dissipated" ,
"InverterWFETs/Resistor2" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor2.Resistor.i" , "InverterWFETs/Resistor2"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Resistor2.Resistor.n.v" ,
"InverterWFETs/Resistor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor2.Resistor.p.v" , "InverterWFETs/Resistor2" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor2.Resistor.v" ,
"InverterWFETs/Resistor2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor2.n.v" , "InverterWFETs/Resistor2" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor2.p.v" , "InverterWFETs/Resistor2"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , {
"Resistor3.Resistor.power_dissipated" , "InverterWFETs/Resistor3" , 1U , 1U ,
"W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Power dissipated" , } , { "Resistor3.Resistor.i" ,
"InverterWFETs/Resistor3" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor3.Resistor.n.v" , "InverterWFETs/Resistor3" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor3.Resistor.p.v" ,
"InverterWFETs/Resistor3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor3.Resistor.v" , "InverterWFETs/Resistor3" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor3.n.v" ,
"InverterWFETs/Resistor3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor3.p.v" , "InverterWFETs/Resistor3" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor4.Resistor.power_dissipated" ,
"InverterWFETs/Resistor4" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor4.Resistor.i" , "InverterWFETs/Resistor4"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Resistor4.Resistor.n.v" ,
"InverterWFETs/Resistor4" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor4.Resistor.p.v" , "InverterWFETs/Resistor4" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor4.Resistor.v" ,
"InverterWFETs/Resistor4" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor4.n.v" , "InverterWFETs/Resistor4" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor4.p.v" , "InverterWFETs/Resistor4"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , {
"Resistor5.Resistor.power_dissipated" , "InverterWFETs/Resistor5" , 1U , 1U ,
"W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Power dissipated" , } , { "Resistor5.Resistor.i" ,
"InverterWFETs/Resistor5" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor5.Resistor.n.v" , "InverterWFETs/Resistor5" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor5.Resistor.p.v" ,
"InverterWFETs/Resistor5" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor5.Resistor.v" , "InverterWFETs/Resistor5" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor5.n.v" ,
"InverterWFETs/Resistor5" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor5.p.v" , "InverterWFETs/Resistor5" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor6.Resistor.power_dissipated" ,
"InverterWFETs/Resistor6" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor6.Resistor.i" , "InverterWFETs/Resistor6"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Resistor6.Resistor.n.v" ,
"InverterWFETs/Resistor6" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor6.Resistor.p.v" , "InverterWFETs/Resistor6" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor6.Resistor.v" ,
"InverterWFETs/Resistor6" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor6.n.v" , "InverterWFETs/Resistor6" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor6.p.v" , "InverterWFETs/Resistor6"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , {
"Resistor7.Resistor.power_dissipated" , "InverterWFETs/Resistor7" , 1U , 1U ,
"W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Power dissipated" , } , { "Resistor7.Resistor.i" ,
"InverterWFETs/Resistor7" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor7.Resistor.n.v" , "InverterWFETs/Resistor7" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor7.Resistor.p.v" ,
"InverterWFETs/Resistor7" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor7.Resistor.v" , "InverterWFETs/Resistor7" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor7.n.v" ,
"InverterWFETs/Resistor7" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor7.p.v" , "InverterWFETs/Resistor7" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor8.Resistor.power_dissipated" ,
"InverterWFETs/Resistor8" , 1U , 1U , "W" , 1.0 , "kW" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Power dissipated" , } , { "Resistor8.Resistor.i" , "InverterWFETs/Resistor8"
, 1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "Resistor8.Resistor.n.v" ,
"InverterWFETs/Resistor8" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor8.Resistor.p.v" , "InverterWFETs/Resistor8" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor8.Resistor.v" ,
"InverterWFETs/Resistor8" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor8.n.v" , "InverterWFETs/Resistor8" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Resistor8.p.v" , "InverterWFETs/Resistor8"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Voltage" , } , {
"Resistor9.Resistor.power_dissipated" , "InverterWFETs/Resistor9" , 1U , 1U ,
"W" , 1.0 , "kW" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Power dissipated" , } , { "Resistor9.Resistor.i" ,
"InverterWFETs/Resistor9" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Current" , } , { "Resistor9.Resistor.n.v" , "InverterWFETs/Resistor9" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor9.Resistor.p.v" ,
"InverterWFETs/Resistor9" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor9.Resistor.v" , "InverterWFETs/Resistor9" , 1U ,
1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE ,
FALSE , FALSE , TRUE , "Voltage" , } , { "Resistor9.n.v" ,
"InverterWFETs/Resistor9" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Resistor9.p.v" , "InverterWFETs/Resistor9" , 1U , 1U , "V"
, 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , TRUE , "Voltage" , } , { "Voltage_Measure1.V0.v" ,
"InverterWFETs/Voltage Measure1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Voltage_Measure1.V1.v" , "InverterWFETs/Voltage Measure1"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , FALSE , "Voltage" , } , {
"Voltage_Measure1.Voltage_Sensor3.V" ,
"InverterWFETs/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "V" , } , { "Voltage_Measure1.Voltage_Sensor3.i1" ,
"InverterWFETs/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Current" , } , { "Voltage_Measure1.Voltage_Sensor3.n.v" ,
"InverterWFETs/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Measure1.Voltage_Sensor3.p.v" ,
"InverterWFETs/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Measure1.Voltage_Sensor3.v1" ,
"InverterWFETs/Voltage Measure1/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Measure2.V0.v" ,
"InverterWFETs/Voltage Measure2" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Voltage_Measure2.V1.v" , "InverterWFETs/Voltage Measure2"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , FALSE , "Voltage" , } , {
"Voltage_Measure2.Voltage_Sensor3.V" ,
"InverterWFETs/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "V" , } , { "Voltage_Measure2.Voltage_Sensor3.i1" ,
"InverterWFETs/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Current" , } , { "Voltage_Measure2.Voltage_Sensor3.n.v" ,
"InverterWFETs/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Measure2.Voltage_Sensor3.p.v" ,
"InverterWFETs/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Measure2.Voltage_Sensor3.v1" ,
"InverterWFETs/Voltage Measure2/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Measure3.V0.v" ,
"InverterWFETs/Voltage Measure3" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE ,
"Voltage" , } , { "Voltage_Measure3.V1.v" , "InverterWFETs/Voltage Measure3"
, 1U , 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , FALSE , "Voltage" , } , {
"Voltage_Measure3.Voltage_Sensor3.V" ,
"InverterWFETs/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "V" , } , { "Voltage_Measure3.Voltage_Sensor3.i1" ,
"InverterWFETs/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "A" , 1.0 , "A"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Current" , } , { "Voltage_Measure3.Voltage_Sensor3.n.v" ,
"InverterWFETs/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Measure3.Voltage_Sensor3.p.v" ,
"InverterWFETs/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Measure3.Voltage_Sensor3.v1" ,
"InverterWFETs/Voltage Measure3/Voltage Sensor3" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE
, "Voltage" , } , { "Voltage_Source.i" , "InverterWFETs/Voltage Source" , 1U
, 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Current (positive in)" , } , { "Voltage_Source.n.v"
, "InverterWFETs/Voltage Source" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "Voltage_Source.p.v" , "InverterWFETs/Voltage Source" , 1U
, 1U , "V" , 1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE
, FALSE , FALSE , TRUE , "Voltage" , } , { "Voltage_Source.v" ,
"InverterWFETs/Voltage Source" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "x5.Current_Sensor1.I" ,
"InverterWFETs/(5)/Current Sensor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"I" , } , { "x5.Current_Sensor1.i1" , "InverterWFETs/(5)/Current Sensor1" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "x5.Current_Sensor1.n.v" ,
"InverterWFETs/(5)/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "x5.Current_Sensor1.p.v" ,
"InverterWFETs/(5)/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "x5.Current_Sensor1.v1" ,
"InverterWFETs/(5)/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "x5.I0.v" , "InverterWFETs/(5)" , 1U , 1U , "V" , 1.0 , "V"
, NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , FALSE
, "Voltage" , } , { "x5.I1.v" , "InverterWFETs/(5)" , 1U , 1U , "V" , 1.0 ,
"V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
FALSE , "Voltage" , } , { "x51.Current_Sensor1.I" ,
"InverterWFETs/(5)1/Current Sensor1" , 1U , 1U , "A" , 1.0 , "A" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"I" , } , { "x51.Current_Sensor1.i1" , "InverterWFETs/(5)1/Current Sensor1" ,
1U , 1U , "A" , 1.0 , "A" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE ,
FALSE , FALSE , FALSE , TRUE , "Current" , } , { "x51.Current_Sensor1.n.v" ,
"InverterWFETs/(5)1/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "x51.Current_Sensor1.p.v" ,
"InverterWFETs/(5)1/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "x51.Current_Sensor1.v1" ,
"InverterWFETs/(5)1/Current Sensor1" , 1U , 1U , "V" , 1.0 , "V" ,
NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , TRUE , FALSE , FALSE , TRUE ,
"Voltage" , } , { "x51.I0.v" , "InverterWFETs/(5)1" , 1U , 1U , "V" , 1.0 ,
"V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE , FALSE ,
FALSE , "Voltage" , } , { "x51.I1.v" , "InverterWFETs/(5)1" , 1U , 1U , "V" ,
1.0 , "V" , NE_NOMINAL_SOURCE_MODEL , NE_INIT_MODE_NONE , FALSE , FALSE ,
FALSE , FALSE , "Voltage" , } } ; static NeModeData * s_major_mode_data =
NULL ; static NeZCData s_zc_data [ 36 ] = { {
"InverterWFETs/Gate Driver/Diode" , 1U , 0U , "Gate_Driver.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver1/Diode" , 1U , 1U ,
"Gate_Driver1.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver2/Diode" , 1U , 2U ,
"Gate_Driver2.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver3/Diode" , 1U , 3U ,
"Gate_Driver3.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver4/Diode" , 1U , 4U ,
"Gate_Driver4.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver5/Diode" , 1U , 5U ,
"Gate_Driver5.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U
, 6U , "Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U
, 7U , "Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U
, 8U , "Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U
, 9U , "Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U
, 10U , "Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U
, 11U , "Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U ,
12U , "Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U
, 13U , "Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U
, 14U , "Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U
, 15U , "Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U
, 16U , "Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U
, 17U , "Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U ,
18U , "Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U
, 19U , "Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U
, 20U , "Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U
, 21U , "Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U
, 22U , "Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U
, 23U , "Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U
, 24U , "Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U
, 25U , "Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U
, 26U , "Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U
, 27U , "Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U
, 28U , "Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U
, 29U , "Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_FALSE , } , { "InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U
, 30U , "Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U
, 31U , "Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U
, 32U , "Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U
, 33U , "Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U
, 34U , "Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } , { "InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U
, 35U , "Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, NE_ZC_TYPE_TRUE , } } ; static NeRange s_range [ 36 ] = { {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } } ; static NeAssertData
s_assert_data [ 190 ] = { { "InverterWFETs/Capacitor" , 1U , 0U , "Capacitor"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Capacitor" , 1U , 1U , "Capacitor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Capacitor" , 1U , 2U , "Capacitor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Capacitor" , 1U , 3U , "Capacitor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Capacitor1" , 1U , 4U , "Capacitor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Capacitor1" , 1U , 5U , "Capacitor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Capacitor1" , 1U , 6U , "Capacitor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Capacitor1" , 1U , 7U , "Capacitor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Capacitor2" , 1U , 8U , "Capacitor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Capacitor2" , 1U , 9U , "Capacitor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Capacitor2" , 1U , 10U , "Capacitor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Capacitor2" , 1U , 11U , "Capacitor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver/Inductor" , 1U , 12U , "Gate_Driver.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver/Inductor" , 1U , 13U , "Gate_Driver.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver/Inductor" , 1U , 14U , "Gate_Driver.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver/Inductor" , 1U , 15U , "Gate_Driver.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver/Inductor1" , 1U , 16U , "Gate_Driver.Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver/Inductor1" , 1U , 17U , "Gate_Driver.Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver/Inductor1" , 1U , 18U , "Gate_Driver.Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver/Inductor1" , 1U , 19U , "Gate_Driver.Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver1/Inductor" , 1U , 20U , "Gate_Driver1.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver1/Inductor" , 1U , 21U , "Gate_Driver1.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver1/Inductor" , 1U , 22U , "Gate_Driver1.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver1/Inductor" , 1U , 23U , "Gate_Driver1.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 24U , "Gate_Driver1.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 25U , "Gate_Driver1.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 26U , "Gate_Driver1.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver1/Inductor1" , 1U , 27U , "Gate_Driver1.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver2/Inductor" , 1U , 28U , "Gate_Driver2.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver2/Inductor" , 1U , 29U , "Gate_Driver2.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver2/Inductor" , 1U , 30U , "Gate_Driver2.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver2/Inductor" , 1U , 31U , "Gate_Driver2.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 32U , "Gate_Driver2.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 33U , "Gate_Driver2.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 34U , "Gate_Driver2.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver2/Inductor1" , 1U , 35U , "Gate_Driver2.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver3/Inductor" , 1U , 36U , "Gate_Driver3.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver3/Inductor" , 1U , 37U , "Gate_Driver3.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver3/Inductor" , 1U , 38U , "Gate_Driver3.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver3/Inductor" , 1U , 39U , "Gate_Driver3.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 40U , "Gate_Driver3.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 41U , "Gate_Driver3.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 42U , "Gate_Driver3.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver3/Inductor1" , 1U , 43U , "Gate_Driver3.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver4/Inductor" , 1U , 44U , "Gate_Driver4.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver4/Inductor" , 1U , 45U , "Gate_Driver4.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver4/Inductor" , 1U , 46U , "Gate_Driver4.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver4/Inductor" , 1U , 47U , "Gate_Driver4.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 48U , "Gate_Driver4.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 49U , "Gate_Driver4.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 50U , "Gate_Driver4.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver4/Inductor1" , 1U , 51U , "Gate_Driver4.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver5/Inductor" , 1U , 52U , "Gate_Driver5.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver5/Inductor" , 1U , 53U , "Gate_Driver5.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver5/Inductor" , 1U , 54U , "Gate_Driver5.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver5/Inductor" , 1U , 55U , "Gate_Driver5.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 56U , "Gate_Driver5.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 57U , "Gate_Driver5.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 58U , "Gate_Driver5.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver5/Inductor1" , 1U , 59U , "Gate_Driver5.Inductor1"
,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor" , 1U , 60U , "Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor" , 1U , 61U , "Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor" , 1U , 62U , "Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor" , 1U , 63U , "Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor1" , 1U , 64U , "Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor1" , 1U , 65U , "Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor1" , 1U , 66U , "Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor1" , 1U , 67U , "Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor10" , 1U , 68U , "Inductor10" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor10" , 1U , 69U , "Inductor10" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor10" , 1U , 70U , "Inductor10" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor10" , 1U , 71U , "Inductor10" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor11" , 1U , 72U , "Inductor11" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor11" , 1U , 73U , "Inductor11" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor11" , 1U , 74U , "Inductor11" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor11" , 1U , 75U , "Inductor11" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor12" , 1U , 76U , "Inductor12" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor12" , 1U , 77U , "Inductor12" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor12" , 1U , 78U , "Inductor12" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor12" , 1U , 79U , "Inductor12" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor13" , 1U , 80U , "Inductor13" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor13" , 1U , 81U , "Inductor13" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor13" , 1U , 82U , "Inductor13" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor13" , 1U , 83U , "Inductor13" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor14" , 1U , 84U , "Inductor14" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor14" , 1U , 85U , "Inductor14" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor14" , 1U , 86U , "Inductor14" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor14" , 1U , 87U , "Inductor14" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor15" , 1U , 88U , "Inductor15" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor15" , 1U , 89U , "Inductor15" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor15" , 1U , 90U , "Inductor15" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor15" , 1U , 91U , "Inductor15" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor16" , 1U , 92U , "Inductor16" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor16" , 1U , 93U , "Inductor16" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor16" , 1U , 94U , "Inductor16" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor16" , 1U , 95U , "Inductor16" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor17" , 1U , 96U , "Inductor17" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor17" , 1U , 97U , "Inductor17" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor17" , 1U , 98U , "Inductor17" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor17" , 1U , 99U , "Inductor17" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor18" , 1U , 100U , "Inductor18" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor18" , 1U , 101U , "Inductor18" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor18" , 1U , 102U , "Inductor18" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor18" , 1U , 103U , "Inductor18" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor19" , 1U , 104U , "Inductor19" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor19" , 1U , 105U , "Inductor19" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor19" , 1U , 106U , "Inductor19" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor19" , 1U , 107U , "Inductor19" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor2" , 1U , 108U , "Inductor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor2" , 1U , 109U , "Inductor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor2" , 1U , 110U , "Inductor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor2" , 1U , 111U , "Inductor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor20" , 1U , 112U , "Inductor20" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor20" , 1U , 113U , "Inductor20" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor20" , 1U , 114U , "Inductor20" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor20" , 1U , 115U , "Inductor20" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor21" , 1U , 116U , "Inductor21" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor21" , 1U , 117U , "Inductor21" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor21" , 1U , 118U , "Inductor21" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor21" , 1U , 119U , "Inductor21" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor3" , 1U , 120U , "Inductor3" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor3" , 1U , 121U , "Inductor3" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor3" , 1U , 122U , "Inductor3" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor3" , 1U , 123U , "Inductor3" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor4" , 1U , 124U , "Inductor4" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor4" , 1U , 125U , "Inductor4" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor4" , 1U , 126U , "Inductor4" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor4" , 1U , 127U , "Inductor4" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor5" , 1U , 128U , "Inductor5" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor5" , 1U , 129U , "Inductor5" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor5" , 1U , 130U , "Inductor5" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor5" , 1U , 131U , "Inductor5" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor6" , 1U , 132U , "Inductor6" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor6" , 1U , 133U , "Inductor6" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor6" , 1U , 134U , "Inductor6" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor6" , 1U , 135U , "Inductor6" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor7" , 1U , 136U , "Inductor7" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor7" , 1U , 137U , "Inductor7" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor7" , 1U , 138U , "Inductor7" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor7" , 1U , 139U , "Inductor7" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor8" , 1U , 140U , "Inductor8" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor8" , 1U , 141U , "Inductor8" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor8" , 1U , 142U , "Inductor8" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor8" , 1U , 143U , "Inductor8" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor9" , 1U , 144U , "Inductor9" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor9" , 1U , 145U , "Inductor9" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Inductor9" , 1U , 146U , "Inductor9" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Inductor9" , 1U , 147U , "Inductor9" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/R L Load/Inductor" , 1U , 148U , "R_L_Load.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/R L Load/Inductor" , 1U , 149U , "R_L_Load.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/R L Load/Inductor" , 1U , 150U , "R_L_Load.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/R L Load/Inductor" , 1U , 151U , "R_L_Load.Inductor" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/R L Load/Inductor1" , 1U , 152U , "R_L_Load.Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/R L Load/Inductor1" , 1U , 153U , "R_L_Load.Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/R L Load/Inductor1" , 1U , 154U , "R_L_Load.Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/R L Load/Inductor1" , 1U , 155U , "R_L_Load.Inductor1" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/R L Load/Inductor2" , 1U , 156U , "R_L_Load.Inductor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/R L Load/Inductor2" , 1U , 157U , "R_L_Load.Inductor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/R L Load/Inductor2" , 1U , 158U , "R_L_Load.Inductor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/R L Load/Inductor2" , 1U , 159U , "R_L_Load.Inductor2" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver/Diode" , 1U , 160U , "Gate_Driver.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:core:asserts:RequireDenominatorNonzero" , } , {
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 161U ,
"Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 162U ,
"Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 163U ,
"Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver/N-Channel MOSFET" , 1U , 164U ,
"Gate_Driver.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver1/Diode" , 1U , 165U , "Gate_Driver1.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:core:asserts:RequireDenominatorNonzero" , } , {
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 166U ,
"Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 167U ,
"Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 168U ,
"Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver1/N-Channel MOSFET" , 1U , 169U ,
"Gate_Driver1.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver2/Diode" , 1U , 170U , "Gate_Driver2.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:core:asserts:RequireDenominatorNonzero" , } , {
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 171U ,
"Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 172U ,
"Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 173U ,
"Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver2/N-Channel MOSFET" , 1U , 174U ,
"Gate_Driver2.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver3/Diode" , 1U , 175U , "Gate_Driver3.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:core:asserts:RequireDenominatorNonzero" , } , {
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 176U ,
"Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 177U ,
"Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 178U ,
"Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver3/N-Channel MOSFET" , 1U , 179U ,
"Gate_Driver3.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver4/Diode" , 1U , 180U , "Gate_Driver4.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:core:asserts:RequireDenominatorNonzero" , } , {
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 181U ,
"Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 182U ,
"Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 183U ,
"Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver4/N-Channel MOSFET" , 1U , 184U ,
"Gate_Driver4.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver5/Diode" , 1U , 185U , "Gate_Driver5.Diode.diode" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, FALSE , "In divide, the denominator must be nonzero." ,
"physmod:common:mf:core:asserts:RequireDenominatorNonzero" , } , {
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 186U ,
"Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 187U ,
"Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } , {
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 188U ,
"Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireExponentPositive" , } , {
"InverterWFETs/Gate Driver5/N-Channel MOSFET" , 1U , 189U ,
"Gate_Driver5.N_Channel_MOSFET.mos" ,
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, TRUE ,
 "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases."
, "physmod:common:mf:core:asserts:RequireBaseNonnegative" , } } ; static
NeRange s_assert_range [ 190 ] = { {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 34U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 34U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 34U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 34U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 34U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 34U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } } ; static NeAssertData *
s_param_assert_data = NULL ; static NeRange * s_param_assert_range = NULL ;
static NeRange s_equation_range [ 271 ] = { {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 32U , 5U , 32U , 25U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/capacitor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 7U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 28U , 7U , 28U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 31U , 5U , 31U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sources/controlled_voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 7U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 28U , 7U , 28U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 31U , 5U , 31U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sources/controlled_voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 7U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 28U , 7U , 28U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 31U , 5U , 31U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sources/controlled_voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 7U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 28U , 7U , 28U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 31U , 5U , 31U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sources/controlled_voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 7U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 28U , 7U , 28U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 31U , 5U , 31U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sources/controlled_voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 25U , 8U , 25U , 14U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 26U , 7U , 26U , 37U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/pwl_diode.ssc"
, 28U , 7U , 28U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+elements/capacitor.ssc"
, 31U , 5U , 31U , 18U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+semiconductors/mosfet.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sources/controlled_voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 23U , 5U , 23U , 19U , NE_RANGE_TYPE_NORMAL , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/current.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/current.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/current.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/current.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/voltage.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/current.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/elec/elec/+elec/+passive/inductor.sscp"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/current.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , { "" , 1U , 1U , 1U , 1U
, NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/+sensors/current.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } , {
 "C:/Program Files/MATLAB/R2018a/toolbox/physmod/simscape/library/m/+foundation/+electrical/branch.ssc"
, 1U , 1U , 1U , 1U , NE_RANGE_TYPE_PROTECTED , } } ; static NeParameterData
* s_logical_parameter_data = NULL ; static NeParameterData *
s_integer_parameter_data = NULL ; static NeParameterData *
s_index_parameter_data = NULL ; static NeParameterData s_real_parameter_data
[ 4 ] = { { "Idc" , "" , "" , 0U , 1U , } , { "LoadA" , "" , "" , 0U , 1U , }
, { "LoadB" , "" , "" , 0U , 1U , } , { "LoadC" , "" , "" , 0U , 1U , } } ;
static NeDsMethodOutput * ds_output_m_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mM_P . mNumCol = 123 ; out -> mM_P .
mNumRow = 123 ; out -> mM_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 124 ) ; out -> mM_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 64 ) ; return out
; } static NeDsMethodOutput * ds_output_m ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mM . mN = 64 ; out -> mM . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 64 ) ; return out
; } static NeDsMethodOutput * ds_output_vmm ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mVMM . mN = 64 ; out -> mVMM . mX = (
boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T ) , 64
) ; return out ; } static NeDsMethodOutput * ds_output_dxm_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXM_P . mNumCol = 123 ; out ->
mDXM_P . mNumRow = 64 ; out -> mDXM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 124 ) ; out -> mDXM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dxm ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXM . mN = 0 ; out -> mDXM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dum_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUM_P . mNumCol = 6 ; out ->
mDUM_P . mNumRow = 64 ; out -> mDUM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 7 ) ; out -> mDUM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dum ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUM . mN = 0 ; out -> mDUM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dtm_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTM_P . mNumCol = 1 ; out ->
mDTM_P . mNumRow = 64 ; out -> mDTM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dtm ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTM . mN = 0 ; out -> mDTM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_a_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mA_P . mNumCol = 123 ; out ->
mA_P . mNumRow = 123 ; out -> mA_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 124 ) ; out -> mA_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 672 )
; return out ; } static NeDsMethodOutput * ds_output_a ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mA . mN = 672 ; out -> mA . mX =
( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 672 )
; return out ; } static NeDsMethodOutput * ds_output_b_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mB_P . mNumCol = 6 ; out -> mB_P
. mNumRow = 123 ; out -> mB_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 7 ) ; out -> mB_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 12 ) ; return out
; } static NeDsMethodOutput * ds_output_b ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mB . mN = 12 ; out -> mB . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 12 ) ; return out
; } static NeDsMethodOutput * ds_output_c_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mC_P . mNumCol = 1 ; out -> mC_P . mNumRow
= 123 ; out -> mC_P . mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( int32_T ) , 2 ) ; out -> mC_P . mIr = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_c ( const NeDynamicSystem * ds , PmAllocator *
allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput
* ) allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ;
out -> mC . mN = 0 ; out -> mC . mX = ( real_T * ) allocator -> mCallocFcn (
allocator , sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput
* ds_output_f ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mF .
mN = 123 ; out -> mF . mX = ( real_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( real_T ) , 123 ) ; return out ; } static NeDsMethodOutput *
ds_output_vmf ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mVMF .
mN = 123 ; out -> mVMF . mX = ( boolean_T * ) allocator -> mCallocFcn (
allocator , sizeof ( boolean_T ) , 123 ) ; return out ; } static
NeDsMethodOutput * ds_output_slf ( const NeDynamicSystem * ds , PmAllocator *
allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput
* ) allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ;
out -> mSLF . mN = 123 ; out -> mSLF . mX = ( boolean_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( boolean_T ) , 123 ) ; return out ; } static
NeDsMethodOutput * ds_output_slf0 ( const NeDynamicSystem * ds , PmAllocator
* allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mSLF0 . mN = 123 ; out -> mSLF0 . mX = (
boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T ) ,
123 ) ; return out ; } static NeDsMethodOutput * ds_output_dxf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXF_P . mNumCol = 123 ; out ->
mDXF_P . mNumRow = 123 ; out -> mDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 124 ) ; out -> mDXF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 96 ) ;
return out ; } static NeDsMethodOutput * ds_output_dxf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXF . mN = 96 ; out -> mDXF .
mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
96 ) ; return out ; } static NeDsMethodOutput * ds_output_duf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUF_P . mNumCol = 6 ; out ->
mDUF_P . mNumRow = 123 ; out -> mDUF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 7 ) ; out -> mDUF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 6 ) ;
return out ; } static NeDsMethodOutput * ds_output_duf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUF . mN = 6 ; out -> mDUF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 6 )
; return out ; } static NeDsMethodOutput * ds_output_dtf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTF_P . mNumCol = 1 ; out ->
mDTF_P . mNumRow = 123 ; out -> mDTF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dtf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTF . mN = 0 ; out -> mDTF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_ddf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDF_P . mNumCol = 0 ; out ->
mDDF_P . mNumRow = 123 ; out -> mDDF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; out -> mDDF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_ddf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDF . mN = 0 ; out -> mDDF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_tduf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDUF_P . mNumCol = 6 ; out ->
mTDUF_P . mNumRow = 123 ; out -> mTDUF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 7 ) ; out -> mTDUF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 18 ) ;
return out ; } static NeDsMethodOutput * ds_output_tdxf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDXF_P . mNumCol = 123 ; out ->
mTDXF_P . mNumRow = 123 ; out -> mTDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 124 ) ; out -> mTDXF_P . mIr =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 768
) ; return out ; } static NeDsMethodOutput * ds_output_dnf_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDNF_P . mNumCol = 104 ; out ->
mDNF_P . mNumRow = 123 ; out -> mDNF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 105 ) ; out -> mDNF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dnf ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDNF . mN = 0 ; out -> mDNF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dnf_v_x ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDNF_V_X . mN = 123 ; out ->
mDNF_V_X . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof
( boolean_T ) , 123 ) ; return out ; } static NeDsMethodOutput * ds_output_ic
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mIC . mN = 123 ; out
-> mIC . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 123 ) ; return out ; } static NeDsMethodOutput * ds_output_icr (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mICR . mN = 0 ; out ->
mICR . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_icr_im (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mICR_IM . mN = 0 ; out
-> mICR_IM . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_icr_id
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mICR_ID . mN = 0 ; out
-> mICR_ID . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( boolean_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_dxicr ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXICR
. mN = 0 ; out -> mDXICR . mX = ( real_T * ) allocator -> mCallocFcn (
allocator , sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput
* ds_output_dxicr_p ( const NeDynamicSystem * ds , PmAllocator * allocator )
{ NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * )
allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out
-> mDXICR_P . mNumCol = 123 ; out -> mDXICR_P . mNumRow = 0 ; out -> mDXICR_P
. mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T
) , 124 ) ; out -> mDXICR_P . mIr = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput
* ds_output_tduicr_p ( const NeDynamicSystem * ds , PmAllocator * allocator )
{ NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * )
allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out
-> mTDUICR_P . mNumCol = 6 ; out -> mTDUICR_P . mNumRow = 0 ; out ->
mTDUICR_P . mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 7 ) ; out -> mTDUICR_P . mIr = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_mduy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mMDUY_P . mNumCol = 6 ; out -> mMDUY_P .
mNumRow = 26 ; out -> mMDUY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 7 ) ; out -> mMDUY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_mdxy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mMDXY_P . mNumCol = 123 ; out -> mMDXY_P .
mNumRow = 26 ; out -> mMDXY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 124 ) ; out -> mMDXY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_tduy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mTDUY_P . mNumCol = 6 ; out -> mTDUY_P .
mNumRow = 26 ; out -> mTDUY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 7 ) ; out -> mTDUY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_tdxy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mTDXY_P . mNumCol = 123 ; out -> mTDXY_P .
mNumRow = 26 ; out -> mTDXY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 124 ) ; out -> mTDXY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 151 ) ; return out
; } static NeDsMethodOutput * ds_output_y ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mY . mN = 26 ; out -> mY . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 26 ) ; return out
; } static NeDsMethodOutput * ds_output_dxy_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXY_P . mNumCol = 123 ; out -> mDXY_P .
mNumRow = 26 ; out -> mDXY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 124 ) ; out -> mDXY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 151 ) ; return out
; } static NeDsMethodOutput * ds_output_dxy ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXY . mN = 151 ; out -> mDXY . mX = (
real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 151 ) ;
return out ; } static NeDsMethodOutput * ds_output_duy_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUY_P . mNumCol = 6 ; out ->
mDUY_P . mNumRow = 26 ; out -> mDUY_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 7 ) ; out -> mDUY_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_duy ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUY . mN = 0 ; out -> mDUY . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dty_p ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTY_P . mNumCol = 1 ; out ->
mDTY_P . mNumRow = 26 ; out -> mDTY_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTY_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dty ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTY . mN = 0 ; out -> mDTY . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_mode ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mMODE . mN = 36 ; out -> mMODE .
mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) ,
36 ) ; return out ; } static NeDsMethodOutput * ds_output_zc ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mZC . mN = 36 ; out -> mZC . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 36 )
; return out ; } static NeDsMethodOutput * ds_output_cache_r ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mCACHE_R . mN = 0 ; out ->
mCACHE_R . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_cache_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mCACHE_I . mN = 0 ;
out -> mCACHE_I . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_update_r ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mUPDATE_R . mN = 0 ; out -> mUPDATE_R . mX = ( real_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_update_i ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mUPDATE_I . mN = 0 ; out -> mUPDATE_I . mX
= ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0
) ; return out ; } static NeDsMethodOutput * ds_output_sfo ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSFO . mN = 0 ; out -> mSFO . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_sfp ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSFP . mN = 0 ; out -> mSFP . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_init_r ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mINIT_R . mN = 0 ; out ->
mINIT_R . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_init_i (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mINIT_I . mN = 0 ; out
-> mINIT_I . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_log (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mLOG . mN = 1076 ; out
-> mLOG . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 1076 ) ; return out ; } static NeDsMethodOutput * ds_output_assert
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mASSERT . mN = 190 ;
out -> mASSERT . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( int32_T ) , 190 ) ; return out ; } static NeDsMethodOutput *
ds_output_passert ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mPASSERT . mN = 0 ; out -> mPASSERT . mX = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_del_t ( const NeDynamicSystem * ds , PmAllocator
* allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDEL_T . mN = 0 ; out -> mDEL_T . mX = (
real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_del_v ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_V . mN = 0 ; out -> mDEL_V
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_v0 ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_V0 . mN = 0 ; out ->
mDEL_V0 . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_tmax
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_TMAX . mN = 0 ;
out -> mDEL_TMAX . mX = ( real_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_dxdelt_p ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mDXDELT_P . mNumCol = 123 ; out -> mDXDELT_P . mNumRow = 0 ; out -> mDXDELT_P
. mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T
) , 124 ) ; out -> mDXDELT_P . mIr = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput
* ds_output_dxdelt ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mDXDELT . mN = 0 ; out -> mDXDELT . mX = ( real_T * ) allocator -> mCallocFcn
( allocator , sizeof ( real_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_dudelt_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUDELT_P . mNumCol = 6 ; out -> mDUDELT_P
. mNumRow = 0 ; out -> mDUDELT_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 7 ) ; out -> mDUDELT_P . mIr =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dudelt ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUDELT . mN = 0 ; out ->
mDUDELT . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dtdelt_p
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTDELT_P . mNumCol =
1 ; out -> mDTDELT_P . mNumRow = 0 ; out -> mDTDELT_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out ->
mDTDELT_P . mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dtdelt
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTDELT . mN = 0 ; out
-> mDTDELT . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_obs_exp (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mOBS_EXP . mN = 1076 ;
out -> mOBS_EXP . mX = ( real_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( real_T ) , 1076 ) ; return out ; } static NeDsMethodOutput *
ds_output_obs_act ( const NeDynamicSystem * ds , PmAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mOBS_ACT . mN = 1076 ; out -> mOBS_ACT . mX = ( real_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( real_T ) , 1076 ) ; return out ; } static
NeDsMethodOutput * ds_output_obs_all ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mOBS_ALL . mN = 1076 ; out -> mOBS_ALL . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 1076
) ; return out ; } static NeDsMethodOutput * ds_output_dp_l ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDP_L . mN = 0 ; out -> mDP_L .
mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_dp_i ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDP_I . mN = 0 ; out -> mDP_I .
mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_dp_j ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDP_J . mN = 0 ; out -> mDP_J .
mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_dp_r ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDP_R . mN = 0 ; out -> mDP_R .
mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0
) ; return out ; } static NeDsMethodOutput * ds_output_qx ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mQX . mN = 0 ; out -> mQX . mX =
( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_qu ( const NeDynamicSystem
* ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQU . mN = 0 ; out -> mQU . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out
; } static NeDsMethodOutput * ds_output_qt ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQT . mN = 0 ; out -> mQT . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out
; } static NeDsMethodOutput * ds_output_q1 ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQ1 . mN = 0 ; out -> mQ1 . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out
; } static NeDsMethodOutput * ds_output_qx_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQX_P . mNumCol = 123 ; out -> mQX_P .
mNumRow = 123 ; out -> mQX_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 124 ) ; out -> mQX_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_qu_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQU_P . mNumCol = 6 ; out -> mQU_P .
mNumRow = 123 ; out -> mQU_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 7 ) ; out -> mQU_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_qt_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQT_P . mNumCol = 1 ; out -> mQT_P .
mNumRow = 123 ; out -> mQT_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mQT_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_q1_p ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mQ1_P . mNumCol = 1 ; out -> mQ1_P .
mNumRow = 123 ; out -> mQ1_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mQ1_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_var_tol ( const NeDynamicSystem * ds ,
PmAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mVAR_TOL . mN = 123 ; out -> mVAR_TOL . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 123
) ; return out ; } static NeDsMethodOutput * ds_output_eq_tol ( const
NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mEQ_TOL . mN = 123 ; out ->
mEQ_TOL . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 123 ) ; return out ; } static NeDsMethodOutput * ds_output_lv (
const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mLV . mN = 123 ; out
-> mLV . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof (
boolean_T ) , 123 ) ; return out ; } static NeDsMethodOutput * ds_output_slv
( const NeDynamicSystem * ds , PmAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSLV . mN = 123 ; out
-> mSLV . mX = ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof (
boolean_T ) , 123 ) ; return out ; } static void release_reference (
NeDynamicSystem * ds ) { _NeDynamicSystem * _ds ; _ds = ( _NeDynamicSystem *
) ds ; if ( -- _ds -> mRefCnt == 0 ) { _ds -> mAlloc . mFreeFcn ( & _ds ->
mAlloc , _ds ) ; } } static void get_reference ( NeDynamicSystem * ds ) {
_NeDynamicSystem * _ds ; _ds = ( _NeDynamicSystem * ) ds ; ++ _ds -> mRefCnt
; } static NeDynamicSystem * diagnostics ( const NeDynamicSystem * ds ) {
_NeDynamicSystem * _ds = ( _NeDynamicSystem * ) ds ; ne_ds_get_reference ( &
_ds -> mBase ) ; return & _ds -> mBase ; } static void expand ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , PmRealVector * out )
{ ( void ) ds ; memcpy ( out -> mX , in -> mX . mX , sizeof ( real_T ) * out
-> mN ) ; } NeDynamicSystem * InverterWFETs_d83d6795_1_dae_ds ( PmAllocator *
allocator ) { NeDynamicSystem * ds ; _NeDynamicSystem * _ds ; static
NeDsIoInfo input_info [ 6 ] ; static NeDsIoInfo output_info [ 26 ] ; _ds = (
_NeDynamicSystem * ) allocator -> mCallocFcn ( allocator , sizeof (
_NeDynamicSystem ) , 1 ) ; _ds -> mAlloc = * allocator ; _ds -> mRefCnt = 1 ;
ds = & _ds -> mBase ; ds -> mNumVariables = 123 ; ds ->
mNumDiscreteRealVariables = 0 ; ds -> mNumDifferentialVariables = 64 ; ds ->
mNumEquations = 123 ; ds -> mNumICResiduals = 0 ; ds -> mNumModes = 36 ; ds
-> mNumMajorModes = 0 ; ds -> mNumRealCache = 0 ; ds -> mNumIntCache = 0 ; ds
-> mNumObservables = 1076 ; ds -> mNumObservableElements = 1076 ; ds ->
mNumZcs = 36 ; ds -> mNumAsserts = 190 ; ds -> mNumAssertRanges = 190 ; ds ->
mNumParamAsserts = 0 ; ds -> mNumParamAssertRanges = 0 ; ds -> mNumRanges =
36 ; ds -> mNumEquationRanges = 271 ; ds -> mNumFundamentalSamples = 0 ; ds
-> mNumDelays = 0 ; ds -> mNumLogicalParameters = 0 ; ds ->
mNumIntegerParameters = 0 ; ds -> mNumIndexParameters = 0 ; ds ->
mNumRealParameters = 4 ; ds -> mNumLogicalDerivedParameters = 0 ; ds ->
mNumIntegerDerivedParameters = 0 ; ds -> mNumIndexDerivedParameters = 0 ; ds
-> mNumRealDerivedParameters = 0 ; ds -> mIsOutputLinear = TRUE ; ds ->
mIsOutputSwitchedLinear = TRUE ; ds -> mNumIo [ NE_INPUT_IO_TYPE ] = 6 ;
input_info [ 0 ] . mIdentifier = "Gate_Driver.Controlled_Voltage_Source.vT" ;
input_info [ 0 ] . mM = 1 ; input_info [ 0 ] . mN = 1 ; input_info [ 0 ] .
mName = "Gate_Driver.Controlled_Voltage_Source.vT" ; input_info [ 0 ] . mUnit
= "V" ; input_info [ 1 ] . mIdentifier =
"Gate_Driver1.Controlled_Voltage_Source.vT" ; input_info [ 1 ] . mM = 1 ;
input_info [ 1 ] . mN = 1 ; input_info [ 1 ] . mName =
"Gate_Driver1.Controlled_Voltage_Source.vT" ; input_info [ 1 ] . mUnit = "V"
; input_info [ 2 ] . mIdentifier =
"Gate_Driver2.Controlled_Voltage_Source.vT" ; input_info [ 2 ] . mM = 1 ;
input_info [ 2 ] . mN = 1 ; input_info [ 2 ] . mName =
"Gate_Driver2.Controlled_Voltage_Source.vT" ; input_info [ 2 ] . mUnit = "V"
; input_info [ 3 ] . mIdentifier =
"Gate_Driver3.Controlled_Voltage_Source.vT" ; input_info [ 3 ] . mM = 1 ;
input_info [ 3 ] . mN = 1 ; input_info [ 3 ] . mName =
"Gate_Driver3.Controlled_Voltage_Source.vT" ; input_info [ 3 ] . mUnit = "V"
; input_info [ 4 ] . mIdentifier =
"Gate_Driver4.Controlled_Voltage_Source.vT" ; input_info [ 4 ] . mM = 1 ;
input_info [ 4 ] . mN = 1 ; input_info [ 4 ] . mName =
"Gate_Driver4.Controlled_Voltage_Source.vT" ; input_info [ 4 ] . mUnit = "V"
; input_info [ 5 ] . mIdentifier =
"Gate_Driver5.Controlled_Voltage_Source.vT" ; input_info [ 5 ] . mM = 1 ;
input_info [ 5 ] . mN = 1 ; input_info [ 5 ] . mName =
"Gate_Driver5.Controlled_Voltage_Source.vT" ; input_info [ 5 ] . mUnit = "V"
; ds -> mIo [ NE_INPUT_IO_TYPE ] = input_info ; ds -> mNumIo [
NE_OUTPUT_IO_TYPE ] = 26 ; output_info [ 0 ] . mIdentifier =
"Current_Measure1.Current_Sensor1.I" ; output_info [ 0 ] . mM = 1 ;
output_info [ 0 ] . mN = 1 ; output_info [ 0 ] . mName =
"Current_Measure1.Current_Sensor1.I" ; output_info [ 0 ] . mUnit = "A" ;
output_info [ 1 ] . mIdentifier = "Current_Measure2.Current_Sensor1.I" ;
output_info [ 1 ] . mM = 1 ; output_info [ 1 ] . mN = 1 ; output_info [ 1 ] .
mName = "Current_Measure2.Current_Sensor1.I" ; output_info [ 1 ] . mUnit =
"A" ; output_info [ 2 ] . mIdentifier = "Current_Measure3.Current_Sensor1.I"
; output_info [ 2 ] . mM = 1 ; output_info [ 2 ] . mN = 1 ; output_info [ 2 ]
. mName = "Current_Measure3.Current_Sensor1.I" ; output_info [ 2 ] . mUnit =
"A" ; output_info [ 3 ] . mIdentifier =
"Gate_Driver.Current_Measure.Current_Sensor1.I" ; output_info [ 3 ] . mM = 1
; output_info [ 3 ] . mN = 1 ; output_info [ 3 ] . mName =
"Gate_Driver.Current_Measure.Current_Sensor1.I" ; output_info [ 3 ] . mUnit =
"A" ; output_info [ 4 ] . mIdentifier =
"Gate_Driver.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 4 ] . mM = 1
; output_info [ 4 ] . mN = 1 ; output_info [ 4 ] . mName =
"Gate_Driver.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 4 ] . mUnit
= "V" ; output_info [ 5 ] . mIdentifier =
"Gate_Driver1.Current_Measure.Current_Sensor1.I" ; output_info [ 5 ] . mM = 1
; output_info [ 5 ] . mN = 1 ; output_info [ 5 ] . mName =
"Gate_Driver1.Current_Measure.Current_Sensor1.I" ; output_info [ 5 ] . mUnit
= "A" ; output_info [ 6 ] . mIdentifier =
"Gate_Driver1.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 6 ] . mM =
1 ; output_info [ 6 ] . mN = 1 ; output_info [ 6 ] . mName =
"Gate_Driver1.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 6 ] . mUnit
= "V" ; output_info [ 7 ] . mIdentifier =
"Gate_Driver2.Current_Measure.Current_Sensor1.I" ; output_info [ 7 ] . mM = 1
; output_info [ 7 ] . mN = 1 ; output_info [ 7 ] . mName =
"Gate_Driver2.Current_Measure.Current_Sensor1.I" ; output_info [ 7 ] . mUnit
= "A" ; output_info [ 8 ] . mIdentifier =
"Gate_Driver2.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 8 ] . mM =
1 ; output_info [ 8 ] . mN = 1 ; output_info [ 8 ] . mName =
"Gate_Driver2.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 8 ] . mUnit
= "V" ; output_info [ 9 ] . mIdentifier =
"Gate_Driver3.Current_Measure.Current_Sensor1.I" ; output_info [ 9 ] . mM = 1
; output_info [ 9 ] . mN = 1 ; output_info [ 9 ] . mName =
"Gate_Driver3.Current_Measure.Current_Sensor1.I" ; output_info [ 9 ] . mUnit
= "A" ; output_info [ 10 ] . mIdentifier =
"Gate_Driver3.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 10 ] . mM =
1 ; output_info [ 10 ] . mN = 1 ; output_info [ 10 ] . mName =
"Gate_Driver3.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 10 ] .
mUnit = "V" ; output_info [ 11 ] . mIdentifier =
"Gate_Driver4.Current_Measure.Current_Sensor1.I" ; output_info [ 11 ] . mM =
1 ; output_info [ 11 ] . mN = 1 ; output_info [ 11 ] . mName =
"Gate_Driver4.Current_Measure.Current_Sensor1.I" ; output_info [ 11 ] . mUnit
= "A" ; output_info [ 12 ] . mIdentifier =
"Gate_Driver4.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 12 ] . mM =
1 ; output_info [ 12 ] . mN = 1 ; output_info [ 12 ] . mName =
"Gate_Driver4.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 12 ] .
mUnit = "V" ; output_info [ 13 ] . mIdentifier =
"Gate_Driver5.Current_Measure.Current_Sensor1.I" ; output_info [ 13 ] . mM =
1 ; output_info [ 13 ] . mN = 1 ; output_info [ 13 ] . mName =
"Gate_Driver5.Current_Measure.Current_Sensor1.I" ; output_info [ 13 ] . mUnit
= "A" ; output_info [ 14 ] . mIdentifier =
"Gate_Driver5.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 14 ] . mM =
1 ; output_info [ 14 ] . mN = 1 ; output_info [ 14 ] . mName =
"Gate_Driver5.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 14 ] .
mUnit = "V" ; output_info [ 15 ] . mIdentifier =
"R_L_Load.Current_Measure1.Current_Sensor1.I" ; output_info [ 15 ] . mM = 1 ;
output_info [ 15 ] . mN = 1 ; output_info [ 15 ] . mName =
"R_L_Load.Current_Measure1.Current_Sensor1.I" ; output_info [ 15 ] . mUnit =
"A" ; output_info [ 16 ] . mIdentifier =
"R_L_Load.Current_Measure2.Current_Sensor1.I" ; output_info [ 16 ] . mM = 1 ;
output_info [ 16 ] . mN = 1 ; output_info [ 16 ] . mName =
"R_L_Load.Current_Measure2.Current_Sensor1.I" ; output_info [ 16 ] . mUnit =
"A" ; output_info [ 17 ] . mIdentifier =
"R_L_Load.Current_Measure5.Current_Sensor1.I" ; output_info [ 17 ] . mM = 1 ;
output_info [ 17 ] . mN = 1 ; output_info [ 17 ] . mName =
"R_L_Load.Current_Measure5.Current_Sensor1.I" ; output_info [ 17 ] . mUnit =
"A" ; output_info [ 18 ] . mIdentifier =
"R_L_Load.Voltage_Measure1.Voltage_Sensor3.V" ; output_info [ 18 ] . mM = 1 ;
output_info [ 18 ] . mN = 1 ; output_info [ 18 ] . mName =
"R_L_Load.Voltage_Measure1.Voltage_Sensor3.V" ; output_info [ 18 ] . mUnit =
"V" ; output_info [ 19 ] . mIdentifier =
"R_L_Load.Voltage_Measure2.Voltage_Sensor3.V" ; output_info [ 19 ] . mM = 1 ;
output_info [ 19 ] . mN = 1 ; output_info [ 19 ] . mName =
"R_L_Load.Voltage_Measure2.Voltage_Sensor3.V" ; output_info [ 19 ] . mUnit =
"V" ; output_info [ 20 ] . mIdentifier =
"R_L_Load.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 20 ] . mM = 1 ;
output_info [ 20 ] . mN = 1 ; output_info [ 20 ] . mName =
"R_L_Load.Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 20 ] . mUnit =
"V" ; output_info [ 21 ] . mIdentifier = "Voltage_Measure1.Voltage_Sensor3.V"
; output_info [ 21 ] . mM = 1 ; output_info [ 21 ] . mN = 1 ; output_info [
21 ] . mName = "Voltage_Measure1.Voltage_Sensor3.V" ; output_info [ 21 ] .
mUnit = "V" ; output_info [ 22 ] . mIdentifier =
"Voltage_Measure2.Voltage_Sensor3.V" ; output_info [ 22 ] . mM = 1 ;
output_info [ 22 ] . mN = 1 ; output_info [ 22 ] . mName =
"Voltage_Measure2.Voltage_Sensor3.V" ; output_info [ 22 ] . mUnit = "V" ;
output_info [ 23 ] . mIdentifier = "Voltage_Measure3.Voltage_Sensor3.V" ;
output_info [ 23 ] . mM = 1 ; output_info [ 23 ] . mN = 1 ; output_info [ 23
] . mName = "Voltage_Measure3.Voltage_Sensor3.V" ; output_info [ 23 ] . mUnit
= "V" ; output_info [ 24 ] . mIdentifier = "x5.Current_Sensor1.I" ;
output_info [ 24 ] . mM = 1 ; output_info [ 24 ] . mN = 1 ; output_info [ 24
] . mName = "x5.Current_Sensor1.I" ; output_info [ 24 ] . mUnit = "A" ;
output_info [ 25 ] . mIdentifier = "x51.Current_Sensor1.I" ; output_info [ 25
] . mM = 1 ; output_info [ 25 ] . mN = 1 ; output_info [ 25 ] . mName =
"x51.Current_Sensor1.I" ; output_info [ 25 ] . mUnit = "A" ; ds -> mIo [
NE_OUTPUT_IO_TYPE ] = output_info ; ds -> mReleaseReference =
release_reference ; ds -> mGetReference = get_reference ; ds ->
mDiagnosticsDsFcn = diagnostics ; ds -> mExpandFcn = expand ; ds -> mMethods
[ NE_DS_METHOD_M_P ] = InverterWFETs_d83d6795_1_ds_m_p ; ds -> mMakeOutput [
NE_DS_METHOD_M_P ] = ds_output_m_p ; ds -> mMethods [ NE_DS_METHOD_M ] =
InverterWFETs_d83d6795_1_ds_m ; ds -> mMakeOutput [ NE_DS_METHOD_M ] =
ds_output_m ; ds -> mMethods [ NE_DS_METHOD_VMM ] =
InverterWFETs_d83d6795_1_ds_vmm ; ds -> mMakeOutput [ NE_DS_METHOD_VMM ] =
ds_output_vmm ; ds -> mMethods [ NE_DS_METHOD_DXM_P ] = ds_dxm_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DXM_P ] = ds_output_dxm_p ; ds -> mMethods [
NE_DS_METHOD_DXM ] = ds_dxm ; ds -> mMakeOutput [ NE_DS_METHOD_DXM ] =
ds_output_dxm ; ds -> mMethods [ NE_DS_METHOD_DUM_P ] = ds_dum_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DUM_P ] = ds_output_dum_p ; ds -> mMethods [
NE_DS_METHOD_DUM ] = ds_dum ; ds -> mMakeOutput [ NE_DS_METHOD_DUM ] =
ds_output_dum ; ds -> mMethods [ NE_DS_METHOD_DTM_P ] = ds_dtm_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DTM_P ] = ds_output_dtm_p ; ds -> mMethods [
NE_DS_METHOD_DTM ] = ds_dtm ; ds -> mMakeOutput [ NE_DS_METHOD_DTM ] =
ds_output_dtm ; ds -> mMethods [ NE_DS_METHOD_A_P ] =
InverterWFETs_d83d6795_1_ds_a_p ; ds -> mMakeOutput [ NE_DS_METHOD_A_P ] =
ds_output_a_p ; ds -> mMethods [ NE_DS_METHOD_A ] =
InverterWFETs_d83d6795_1_ds_a ; ds -> mMakeOutput [ NE_DS_METHOD_A ] =
ds_output_a ; ds -> mMethods [ NE_DS_METHOD_B_P ] = ds_b_p ; ds ->
mMakeOutput [ NE_DS_METHOD_B_P ] = ds_output_b_p ; ds -> mMethods [
NE_DS_METHOD_B ] = ds_b ; ds -> mMakeOutput [ NE_DS_METHOD_B ] = ds_output_b
; ds -> mMethods [ NE_DS_METHOD_C_P ] = ds_c_p ; ds -> mMakeOutput [
NE_DS_METHOD_C_P ] = ds_output_c_p ; ds -> mMethods [ NE_DS_METHOD_C ] = ds_c
; ds -> mMakeOutput [ NE_DS_METHOD_C ] = ds_output_c ; ds -> mMethods [
NE_DS_METHOD_F ] = InverterWFETs_d83d6795_1_ds_f ; ds -> mMakeOutput [
NE_DS_METHOD_F ] = ds_output_f ; ds -> mMethods [ NE_DS_METHOD_VMF ] =
InverterWFETs_d83d6795_1_ds_vmf ; ds -> mMakeOutput [ NE_DS_METHOD_VMF ] =
ds_output_vmf ; ds -> mMethods [ NE_DS_METHOD_SLF ] = ds_slf ; ds ->
mMakeOutput [ NE_DS_METHOD_SLF ] = ds_output_slf ; ds -> mMethods [
NE_DS_METHOD_SLF0 ] = ds_slf0 ; ds -> mMakeOutput [ NE_DS_METHOD_SLF0 ] =
ds_output_slf0 ; ds -> mMethods [ NE_DS_METHOD_DXF_P ] =
InverterWFETs_d83d6795_1_ds_dxf_p ; ds -> mMakeOutput [ NE_DS_METHOD_DXF_P ]
= ds_output_dxf_p ; ds -> mMethods [ NE_DS_METHOD_DXF ] =
InverterWFETs_d83d6795_1_ds_dxf ; ds -> mMakeOutput [ NE_DS_METHOD_DXF ] =
ds_output_dxf ; ds -> mMethods [ NE_DS_METHOD_DUF_P ] = ds_duf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DUF_P ] = ds_output_duf_p ; ds -> mMethods [
NE_DS_METHOD_DUF ] = ds_duf ; ds -> mMakeOutput [ NE_DS_METHOD_DUF ] =
ds_output_duf ; ds -> mMethods [ NE_DS_METHOD_DTF_P ] = ds_dtf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DTF_P ] = ds_output_dtf_p ; ds -> mMethods [
NE_DS_METHOD_DTF ] = ds_dtf ; ds -> mMakeOutput [ NE_DS_METHOD_DTF ] =
ds_output_dtf ; ds -> mMethods [ NE_DS_METHOD_DDF_P ] = ds_ddf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DDF_P ] = ds_output_ddf_p ; ds -> mMethods [
NE_DS_METHOD_DDF ] = ds_ddf ; ds -> mMakeOutput [ NE_DS_METHOD_DDF ] =
ds_output_ddf ; ds -> mMethods [ NE_DS_METHOD_TDUF_P ] = ds_tduf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_TDUF_P ] = ds_output_tduf_p ; ds -> mMethods [
NE_DS_METHOD_TDXF_P ] = InverterWFETs_d83d6795_1_ds_tdxf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_TDXF_P ] = ds_output_tdxf_p ; ds -> mMethods [
NE_DS_METHOD_DNF_P ] = ds_dnf_p ; ds -> mMakeOutput [ NE_DS_METHOD_DNF_P ] =
ds_output_dnf_p ; ds -> mMethods [ NE_DS_METHOD_DNF ] = ds_dnf ; ds ->
mMakeOutput [ NE_DS_METHOD_DNF ] = ds_output_dnf ; ds -> mMethods [
NE_DS_METHOD_DNF_V_X ] = InverterWFETs_d83d6795_1_ds_dnf_v_x ; ds ->
mMakeOutput [ NE_DS_METHOD_DNF_V_X ] = ds_output_dnf_v_x ; ds -> mMethods [
NE_DS_METHOD_IC ] = InverterWFETs_d83d6795_1_ds_ic ; ds -> mMakeOutput [
NE_DS_METHOD_IC ] = ds_output_ic ; ds -> mMethods [ NE_DS_METHOD_ICR ] =
ds_icr ; ds -> mMakeOutput [ NE_DS_METHOD_ICR ] = ds_output_icr ; ds ->
mMethods [ NE_DS_METHOD_ICR_IM ] = ds_icr_im ; ds -> mMakeOutput [
NE_DS_METHOD_ICR_IM ] = ds_output_icr_im ; ds -> mMethods [
NE_DS_METHOD_ICR_ID ] = ds_icr_id ; ds -> mMakeOutput [ NE_DS_METHOD_ICR_ID ]
= ds_output_icr_id ; ds -> mMethods [ NE_DS_METHOD_DXICR ] = ds_dxicr ; ds ->
mMakeOutput [ NE_DS_METHOD_DXICR ] = ds_output_dxicr ; ds -> mMethods [
NE_DS_METHOD_DXICR_P ] = ds_dxicr_p ; ds -> mMakeOutput [
NE_DS_METHOD_DXICR_P ] = ds_output_dxicr_p ; ds -> mMethods [
NE_DS_METHOD_TDUICR_P ] = ds_tduicr_p ; ds -> mMakeOutput [
NE_DS_METHOD_TDUICR_P ] = ds_output_tduicr_p ; ds -> mMethods [
NE_DS_METHOD_MDUY_P ] = ds_mduy_p ; ds -> mMakeOutput [ NE_DS_METHOD_MDUY_P ]
= ds_output_mduy_p ; ds -> mMethods [ NE_DS_METHOD_MDXY_P ] = ds_mdxy_p ; ds
-> mMakeOutput [ NE_DS_METHOD_MDXY_P ] = ds_output_mdxy_p ; ds -> mMethods [
NE_DS_METHOD_TDUY_P ] = ds_tduy_p ; ds -> mMakeOutput [ NE_DS_METHOD_TDUY_P ]
= ds_output_tduy_p ; ds -> mMethods [ NE_DS_METHOD_TDXY_P ] =
InverterWFETs_d83d6795_1_ds_tdxy_p ; ds -> mMakeOutput [ NE_DS_METHOD_TDXY_P
] = ds_output_tdxy_p ; ds -> mMethods [ NE_DS_METHOD_Y ] =
InverterWFETs_d83d6795_1_ds_y ; ds -> mMakeOutput [ NE_DS_METHOD_Y ] =
ds_output_y ; ds -> mMethods [ NE_DS_METHOD_DXY_P ] =
InverterWFETs_d83d6795_1_ds_dxy_p ; ds -> mMakeOutput [ NE_DS_METHOD_DXY_P ]
= ds_output_dxy_p ; ds -> mMethods [ NE_DS_METHOD_DXY ] =
InverterWFETs_d83d6795_1_ds_dxy ; ds -> mMakeOutput [ NE_DS_METHOD_DXY ] =
ds_output_dxy ; ds -> mMethods [ NE_DS_METHOD_DUY_P ] = ds_duy_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DUY_P ] = ds_output_duy_p ; ds -> mMethods [
NE_DS_METHOD_DUY ] = ds_duy ; ds -> mMakeOutput [ NE_DS_METHOD_DUY ] =
ds_output_duy ; ds -> mMethods [ NE_DS_METHOD_DTY_P ] = ds_dty_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DTY_P ] = ds_output_dty_p ; ds -> mMethods [
NE_DS_METHOD_DTY ] = ds_dty ; ds -> mMakeOutput [ NE_DS_METHOD_DTY ] =
ds_output_dty ; ds -> mMethods [ NE_DS_METHOD_MODE ] =
InverterWFETs_d83d6795_1_ds_mode ; ds -> mMakeOutput [ NE_DS_METHOD_MODE ] =
ds_output_mode ; ds -> mMethods [ NE_DS_METHOD_ZC ] =
InverterWFETs_d83d6795_1_ds_zc ; ds -> mMakeOutput [ NE_DS_METHOD_ZC ] =
ds_output_zc ; ds -> mMethods [ NE_DS_METHOD_CACHE_R ] = ds_cache_r ; ds ->
mMakeOutput [ NE_DS_METHOD_CACHE_R ] = ds_output_cache_r ; ds -> mMethods [
NE_DS_METHOD_CACHE_I ] = ds_cache_i ; ds -> mMakeOutput [
NE_DS_METHOD_CACHE_I ] = ds_output_cache_i ; ds -> mMethods [
NE_DS_METHOD_UPDATE_R ] = ds_update_r ; ds -> mMakeOutput [
NE_DS_METHOD_UPDATE_R ] = ds_output_update_r ; ds -> mMethods [
NE_DS_METHOD_UPDATE_I ] = ds_update_i ; ds -> mMakeOutput [
NE_DS_METHOD_UPDATE_I ] = ds_output_update_i ; ds -> mMethods [
NE_DS_METHOD_SFO ] = ds_sfo ; ds -> mMakeOutput [ NE_DS_METHOD_SFO ] =
ds_output_sfo ; ds -> mMethods [ NE_DS_METHOD_SFP ] = ds_sfp ; ds ->
mMakeOutput [ NE_DS_METHOD_SFP ] = ds_output_sfp ; ds -> mMethods [
NE_DS_METHOD_INIT_R ] = ds_init_r ; ds -> mMakeOutput [ NE_DS_METHOD_INIT_R ]
= ds_output_init_r ; ds -> mMethods [ NE_DS_METHOD_INIT_I ] = ds_init_i ; ds
-> mMakeOutput [ NE_DS_METHOD_INIT_I ] = ds_output_init_i ; ds -> mMethods [
NE_DS_METHOD_LOG ] = InverterWFETs_d83d6795_1_ds_log ; ds -> mMakeOutput [
NE_DS_METHOD_LOG ] = ds_output_log ; ds -> mMethods [ NE_DS_METHOD_ASSERT ] =
ds_assert ; ds -> mMakeOutput [ NE_DS_METHOD_ASSERT ] = ds_output_assert ; ds
-> mMethods [ NE_DS_METHOD_PASSERT ] = ds_passert ; ds -> mMakeOutput [
NE_DS_METHOD_PASSERT ] = ds_output_passert ; ds -> mMethods [
NE_DS_METHOD_DEL_T ] = ds_del_t ; ds -> mMakeOutput [ NE_DS_METHOD_DEL_T ] =
ds_output_del_t ; ds -> mMethods [ NE_DS_METHOD_DEL_V ] = ds_del_v ; ds ->
mMakeOutput [ NE_DS_METHOD_DEL_V ] = ds_output_del_v ; ds -> mMethods [
NE_DS_METHOD_DEL_V0 ] = ds_del_v0 ; ds -> mMakeOutput [ NE_DS_METHOD_DEL_V0 ]
= ds_output_del_v0 ; ds -> mMethods [ NE_DS_METHOD_DEL_TMAX ] = ds_del_tmax ;
ds -> mMakeOutput [ NE_DS_METHOD_DEL_TMAX ] = ds_output_del_tmax ; ds ->
mMethods [ NE_DS_METHOD_DXDELT_P ] = ds_dxdelt_p ; ds -> mMakeOutput [
NE_DS_METHOD_DXDELT_P ] = ds_output_dxdelt_p ; ds -> mMethods [
NE_DS_METHOD_DXDELT ] = ds_dxdelt ; ds -> mMakeOutput [ NE_DS_METHOD_DXDELT ]
= ds_output_dxdelt ; ds -> mMethods [ NE_DS_METHOD_DUDELT_P ] = ds_dudelt_p ;
ds -> mMakeOutput [ NE_DS_METHOD_DUDELT_P ] = ds_output_dudelt_p ; ds ->
mMethods [ NE_DS_METHOD_DUDELT ] = ds_dudelt ; ds -> mMakeOutput [
NE_DS_METHOD_DUDELT ] = ds_output_dudelt ; ds -> mMethods [
NE_DS_METHOD_DTDELT_P ] = ds_dtdelt_p ; ds -> mMakeOutput [
NE_DS_METHOD_DTDELT_P ] = ds_output_dtdelt_p ; ds -> mMethods [
NE_DS_METHOD_DTDELT ] = ds_dtdelt ; ds -> mMakeOutput [ NE_DS_METHOD_DTDELT ]
= ds_output_dtdelt ; ds -> mMethods [ NE_DS_METHOD_OBS_EXP ] =
InverterWFETs_d83d6795_1_ds_obs_exp ; ds -> mMakeOutput [
NE_DS_METHOD_OBS_EXP ] = ds_output_obs_exp ; ds -> mMethods [
NE_DS_METHOD_OBS_ACT ] = InverterWFETs_d83d6795_1_ds_obs_act ; ds ->
mMakeOutput [ NE_DS_METHOD_OBS_ACT ] = ds_output_obs_act ; ds -> mMethods [
NE_DS_METHOD_OBS_ALL ] = InverterWFETs_d83d6795_1_ds_obs_all ; ds ->
mMakeOutput [ NE_DS_METHOD_OBS_ALL ] = ds_output_obs_all ; ds -> mMethods [
NE_DS_METHOD_DP_L ] = ds_dp_l ; ds -> mMakeOutput [ NE_DS_METHOD_DP_L ] =
ds_output_dp_l ; ds -> mMethods [ NE_DS_METHOD_DP_I ] = ds_dp_i ; ds ->
mMakeOutput [ NE_DS_METHOD_DP_I ] = ds_output_dp_i ; ds -> mMethods [
NE_DS_METHOD_DP_J ] = ds_dp_j ; ds -> mMakeOutput [ NE_DS_METHOD_DP_J ] =
ds_output_dp_j ; ds -> mMethods [ NE_DS_METHOD_DP_R ] = ds_dp_r ; ds ->
mMakeOutput [ NE_DS_METHOD_DP_R ] = ds_output_dp_r ; ds -> mMethods [
NE_DS_METHOD_QX ] = ds_qx ; ds -> mMakeOutput [ NE_DS_METHOD_QX ] =
ds_output_qx ; ds -> mMethods [ NE_DS_METHOD_QU ] = ds_qu ; ds -> mMakeOutput
[ NE_DS_METHOD_QU ] = ds_output_qu ; ds -> mMethods [ NE_DS_METHOD_QT ] =
ds_qt ; ds -> mMakeOutput [ NE_DS_METHOD_QT ] = ds_output_qt ; ds -> mMethods
[ NE_DS_METHOD_Q1 ] = ds_q1 ; ds -> mMakeOutput [ NE_DS_METHOD_Q1 ] =
ds_output_q1 ; ds -> mMethods [ NE_DS_METHOD_QX_P ] = ds_qx_p ; ds ->
mMakeOutput [ NE_DS_METHOD_QX_P ] = ds_output_qx_p ; ds -> mMethods [
NE_DS_METHOD_QU_P ] = ds_qu_p ; ds -> mMakeOutput [ NE_DS_METHOD_QU_P ] =
ds_output_qu_p ; ds -> mMethods [ NE_DS_METHOD_QT_P ] = ds_qt_p ; ds ->
mMakeOutput [ NE_DS_METHOD_QT_P ] = ds_output_qt_p ; ds -> mMethods [
NE_DS_METHOD_Q1_P ] = ds_q1_p ; ds -> mMakeOutput [ NE_DS_METHOD_Q1_P ] =
ds_output_q1_p ; ds -> mMethods [ NE_DS_METHOD_VAR_TOL ] = ds_var_tol ; ds ->
mMakeOutput [ NE_DS_METHOD_VAR_TOL ] = ds_output_var_tol ; ds -> mMethods [
NE_DS_METHOD_EQ_TOL ] = ds_eq_tol ; ds -> mMakeOutput [ NE_DS_METHOD_EQ_TOL ]
= ds_output_eq_tol ; ds -> mMethods [ NE_DS_METHOD_LV ] =
InverterWFETs_d83d6795_1_ds_lv ; ds -> mMakeOutput [ NE_DS_METHOD_LV ] =
ds_output_lv ; ds -> mMethods [ NE_DS_METHOD_SLV ] =
InverterWFETs_d83d6795_1_ds_slv ; ds -> mMakeOutput [ NE_DS_METHOD_SLV ] =
ds_output_slv ; ds -> mEquationData = s_equation_data ; ds -> mVariableData =
s_variable_data ; ds -> mDiscreteData = s_discrete_data ; ds ->
mObservableData = s_observable_data ; ds -> mMajorModeData =
s_major_mode_data ; ds -> mZCData = s_zc_data ; ds -> mRanges = s_range ; ds
-> mAssertData = s_assert_data ; ds -> mAssertRanges = s_assert_range ; ds ->
mParamAssertData = s_param_assert_data ; ds -> mParamAssertRanges =
s_param_assert_range ; ds -> mEquationRanges = s_equation_range ; ds ->
mLogicalParameters = s_logical_parameter_data ; ds -> mIntegerParameters =
s_integer_parameter_data ; ds -> mIndexParameters = s_index_parameter_data ;
ds -> mRealParameters = s_real_parameter_data ; return ( NeDynamicSystem * )
_ds ; } static int32_T ds_assert ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmIntVector out ;
int32_T t0 [ 190 ] ; int32_T b ; ( void ) t1 ; out = t2 -> mASSERT ; for ( b
= 0 ; b < 190 ; b ++ ) { t0 [ b ] = 1 ; } for ( b = 0 ; b < 190 ; b ++ ) {
out . mX [ b ] = t0 [ b ] ; } ( void ) sys ; ( void ) t2 ; return 0 ; }
static int32_T ds_passert ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_del_v ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_del_v0 ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_del_tmax ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_del_t ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_dxdelt ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_dxdelt_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
int32_T b ; ( void ) t1 ; out = t2 -> mDXDELT_P ; out . mNumCol = 123ULL ;
out . mNumRow = 0ULL ; for ( b = 0 ; b < 124 ; b ++ ) { out . mJc [ b ] = 0 ;
} ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dudelt ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_dudelt_p ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 ->
mDUDELT_P ; out . mNumCol = 6ULL ; out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0
; out . mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc
[ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; ( void ) sys ; ( void
) t2 ; return 0 ; } static int32_T ds_dtdelt ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; (
void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dtdelt_p ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 -> mDTDELT_P ; out .
mNumCol = 1ULL ; out . mNumRow = 0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ]
= 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_cache_r (
const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_init_r ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_update_r ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_cache_i ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_init_i ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_update_i ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_sfp ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_sfo ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_duf ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmRealVector out ; ( void ) t1 ; out = t2 -> mDUF ; out . mX [ 0 ] =
0.1 ; out . mX [ 1 ] = 0.1 ; out . mX [ 2 ] = 0.1 ; out . mX [ 3 ] = 0.1 ;
out . mX [ 4 ] = 0.1 ; out . mX [ 5 ] = 0.1 ; ( void ) sys ; ( void ) t2 ;
return 0 ; } static int32_T ds_duf_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; out = t2 -> mDUF_P ; out . mNumCol = 6ULL ; out . mNumRow =
123ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 1 ; out . mJc [ 2 ] = 2 ;
out . mJc [ 3 ] = 3 ; out . mJc [ 4 ] = 4 ; out . mJc [ 5 ] = 5 ; out . mJc [
6 ] = 6 ; out . mIr [ 0 ] = 66 ; out . mIr [ 1 ] = 71 ; out . mIr [ 2 ] = 76
; out . mIr [ 3 ] = 81 ; out . mIr [ 4 ] = 86 ; out . mIr [ 5 ] = 91 ; ( void
) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dtf ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_dtf_p ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 ->
mDTF_P ; out . mNumCol = 1ULL ; out . mNumRow = 123ULL ; out . mJc [ 0 ] = 0
; out . mJc [ 1 ] = 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static
int32_T ds_b ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1
, NeDsMethodOutput * t2 ) { PmRealVector out ; ( void ) t1 ; out = t2 -> mB ;
out . mX [ 0 ] = - 0.6 ; out . mX [ 1 ] = 0.0 ; out . mX [ 2 ] = - 0.6 ; out
. mX [ 3 ] = 0.0 ; out . mX [ 4 ] = - 0.6 ; out . mX [ 5 ] = 0.0 ; out . mX [
6 ] = - 0.6 ; out . mX [ 7 ] = 0.0 ; out . mX [ 8 ] = - 0.6 ; out . mX [ 9 ]
= 0.0 ; out . mX [ 10 ] = - 0.6 ; out . mX [ 11 ] = 0.0 ; ( void ) sys ; (
void ) t2 ; return 0 ; } static int32_T ds_b_p ( const NeDynamicSystem * sys
, const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) {
PmSparsityPattern out ; ( void ) t1 ; out = t2 -> mB_P ; out . mNumCol = 6ULL
; out . mNumRow = 123ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 2 ; out .
mJc [ 2 ] = 4 ; out . mJc [ 3 ] = 6 ; out . mJc [ 4 ] = 8 ; out . mJc [ 5 ] =
10 ; out . mJc [ 6 ] = 12 ; out . mIr [ 0 ] = 69 ; out . mIr [ 1 ] = 70 ; out
. mIr [ 2 ] = 74 ; out . mIr [ 3 ] = 75 ; out . mIr [ 4 ] = 79 ; out . mIr [
5 ] = 80 ; out . mIr [ 6 ] = 84 ; out . mIr [ 7 ] = 85 ; out . mIr [ 8 ] = 89
; out . mIr [ 9 ] = 90 ; out . mIr [ 10 ] = 94 ; out . mIr [ 11 ] = 95 ; (
void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_c ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_c_p ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 ->
mC_P ; out . mNumCol = 1ULL ; out . mNumRow = 123ULL ; out . mJc [ 0 ] = 0 ;
out . mJc [ 1 ] = 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static
int32_T ds_tduf_p ( const NeDynamicSystem * sys , const NeDynamicSystemInput
* t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; out =
t2 -> mTDUF_P ; out . mNumCol = 6ULL ; out . mNumRow = 123ULL ; out . mJc [ 0
] = 0 ; out . mJc [ 1 ] = 3 ; out . mJc [ 2 ] = 6 ; out . mJc [ 3 ] = 9 ; out
. mJc [ 4 ] = 12 ; out . mJc [ 5 ] = 15 ; out . mJc [ 6 ] = 18 ; out . mIr [
0 ] = 66 ; out . mIr [ 1 ] = 69 ; out . mIr [ 2 ] = 70 ; out . mIr [ 3 ] = 71
; out . mIr [ 4 ] = 74 ; out . mIr [ 5 ] = 75 ; out . mIr [ 6 ] = 76 ; out .
mIr [ 7 ] = 79 ; out . mIr [ 8 ] = 80 ; out . mIr [ 9 ] = 81 ; out . mIr [ 10
] = 84 ; out . mIr [ 11 ] = 85 ; out . mIr [ 12 ] = 86 ; out . mIr [ 13 ] =
89 ; out . mIr [ 14 ] = 90 ; out . mIr [ 15 ] = 91 ; out . mIr [ 16 ] = 94 ;
out . mIr [ 17 ] = 95 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static
int32_T ds_ddf ( const NeDynamicSystem * sys , const NeDynamicSystemInput *
t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ;
return 0 ; } static int32_T ds_ddf_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; out = t2 -> mDDF_P ; out . mNumCol = 0ULL ; out . mNumRow =
123ULL ; out . mJc [ 0 ] = 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; }
static int32_T ds_slf ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out ;
boolean_T t0 [ 123 ] ; int32_T b ; ( void ) t1 ; out = t2 -> mSLF ; for ( b =
0 ; b < 123 ; b ++ ) { t0 [ b ] = false ; } for ( b = 0 ; b < 123 ; b ++ ) {
out . mX [ b ] = t0 [ b ] ; } ( void ) sys ; ( void ) t2 ; return 0 ; }
static int32_T ds_dnf ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dnf_p ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; int32_T b ; ( void ) t1 ; out = t2 -> mDNF_P ;
out . mNumCol = 104ULL ; out . mNumRow = 123ULL ; for ( b = 0 ; b < 105 ; b
++ ) { out . mJc [ b ] = 0 ; } ( void ) sys ; ( void ) t2 ; return 0 ; }
static int32_T ds_slf0 ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out ;
boolean_T t0 [ 123 ] ; int32_T b ; ( void ) t1 ; out = t2 -> mSLF0 ; for ( b
= 0 ; b < 123 ; b ++ ) { t0 [ b ] = false ; } for ( b = 0 ; b < 123 ; b ++ )
{ out . mX [ b ] = t0 [ b ] ; } ( void ) sys ; ( void ) t2 ; return 0 ; }
static int32_T ds_icr ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_icr_im ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_icr_id ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_dxicr ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dxicr_p ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; int32_T b ; ( void ) t1 ; out = t2 -> mDXICR_P
; out . mNumCol = 123ULL ; out . mNumRow = 0ULL ; for ( b = 0 ; b < 124 ; b
++ ) { out . mJc [ b ] = 0 ; } ( void ) sys ; ( void ) t2 ; return 0 ; }
static int32_T ds_tduicr_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; out = t2 -> mTDUICR_P ; out . mNumCol = 6ULL ; out . mNumRow =
0ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out
. mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ]
= 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dxm ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_dxm_p ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; int32_T b ; ( void ) t1 ;
out = t2 -> mDXM_P ; out . mNumCol = 123ULL ; out . mNumRow = 64ULL ; for ( b
= 0 ; b < 124 ; b ++ ) { out . mJc [ b ] = 0 ; } ( void ) sys ; ( void ) t2 ;
return 0 ; } static int32_T ds_dum ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dum_p ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 -> mDUM_P ; out .
mNumCol = 6ULL ; out . mNumRow = 64ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1
] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out
. mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_dtm ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dtm_p ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 -> mDTM_P ; out .
mNumCol = 1ULL ; out . mNumRow = 64ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1
] = 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dp_l (
const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_dp_i ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dp_j ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_dp_r ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_qx ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_qu ( const NeDynamicSystem
* sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void )
t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_qt ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_q1 ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_qx_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
int32_T b ; ( void ) t1 ; out = t2 -> mQX_P ; out . mNumCol = 123ULL ; out .
mNumRow = 123ULL ; for ( b = 0 ; b < 124 ; b ++ ) { out . mJc [ b ] = 0 ; } (
void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_qu_p ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 -> mQU_P ; out .
mNumCol = 6ULL ; out . mNumRow = 123ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1
] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out
. mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_qt_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; out = t2 -> mQT_P ; out . mNumCol = 1ULL ; out . mNumRow =
123ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) sys ; ( void )
t2 ; return 0 ; } static int32_T ds_q1_p ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern
out ; ( void ) t1 ; out = t2 -> mQ1_P ; out . mNumCol = 1ULL ; out . mNumRow
= 123ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; ( void ) sys ; ( void
) t2 ; return 0 ; } static int32_T ds_var_tol ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out
; real_T t0 [ 123 ] ; int32_T b ; ( void ) t1 ; out = t2 -> mVAR_TOL ; for (
b = 0 ; b < 123 ; b ++ ) { t0 [ b ] = 1.0E-9 ; } for ( b = 0 ; b < 123 ; b ++
) { out . mX [ b ] = t0 [ b ] ; } ( void ) sys ; ( void ) t2 ; return 0 ; }
static int32_T ds_eq_tol ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out ;
real_T t0 [ 123 ] ; int32_T b ; ( void ) t1 ; out = t2 -> mEQ_TOL ; for ( b =
0 ; b < 123 ; b ++ ) { t0 [ b ] = 1.0E-9 ; } for ( b = 0 ; b < 123 ; b ++ ) {
out . mX [ b ] = t0 [ b ] ; } ( void ) sys ; ( void ) t2 ; return 0 ; }
static int32_T ds_duy ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { ( void ) t1 ; ( void )
sys ; ( void ) t2 ; return 0 ; } static int32_T ds_duy_p ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 -> mDUY_P ; out .
mNumCol = 6ULL ; out . mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1
] = 0 ; out . mJc [ 2 ] = 0 ; out . mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out
. mJc [ 5 ] = 0 ; out . mJc [ 6 ] = 0 ; ( void ) sys ; ( void ) t2 ; return 0
; } static int32_T ds_mduy_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; out = t2 -> mMDUY_P ; out . mNumCol = 6ULL ; out . mNumRow =
26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out
. mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ]
= 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_mdxy_p (
const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; int32_T b ; ( void ) t1 ;
out = t2 -> mMDXY_P ; out . mNumCol = 123ULL ; out . mNumRow = 26ULL ; for (
b = 0 ; b < 124 ; b ++ ) { out . mJc [ b ] = 0 ; } ( void ) sys ; ( void ) t2
; return 0 ; } static int32_T ds_tduy_p ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern out ;
( void ) t1 ; out = t2 -> mTDUY_P ; out . mNumCol = 6ULL ; out . mNumRow =
26ULL ; out . mJc [ 0 ] = 0 ; out . mJc [ 1 ] = 0 ; out . mJc [ 2 ] = 0 ; out
. mJc [ 3 ] = 0 ; out . mJc [ 4 ] = 0 ; out . mJc [ 5 ] = 0 ; out . mJc [ 6 ]
= 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T ds_dty ( const
NeDynamicSystem * sys , const NeDynamicSystemInput * t1 , NeDsMethodOutput *
t2 ) { ( void ) t1 ; ( void ) sys ; ( void ) t2 ; return 0 ; } static int32_T
ds_dty_p ( const NeDynamicSystem * sys , const NeDynamicSystemInput * t1 ,
NeDsMethodOutput * t2 ) { PmSparsityPattern out ; ( void ) t1 ; out = t2 ->
mDTY_P ; out . mNumCol = 1ULL ; out . mNumRow = 26ULL ; out . mJc [ 0 ] = 0 ;
out . mJc [ 1 ] = 0 ; ( void ) sys ; ( void ) t2 ; return 0 ; }
