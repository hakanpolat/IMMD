#include "__cf_InverterWFETs.h"
#ifndef RTW_HEADER_InverterWFETs_h_
#define RTW_HEADER_InverterWFETs_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef InverterWFETs_COMMON_INCLUDES_
#define InverterWFETs_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "InverterWFETs_d83d6795_1_gateway.h"
#endif
#include "InverterWFETs_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#define MODEL_NAME InverterWFETs
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (85) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T lcge5t1gjo ; real_T b1sdosls3i ; real_T dvb12qxvf2 ;
real_T czvszvgx5h ; real_T hpc0dqwvnx ; real_T eovubh0rxu ; real_T pnsni0ml1o
; real_T imlhhcedkr [ 4 ] ; real_T kulfykvvqa ; real_T bgybglbgav ; real_T
nukezu5xk3 ; real_T p51dkbkwid [ 4 ] ; real_T cmlcurmh4c ; real_T lc0gh4vn0y
[ 4 ] ; real_T ce2llznftg ; real_T ajqsccxh4n [ 4 ] ; real_T ohra4d5w4r ;
real_T b1ptcc5egb ; real_T oilte4fptr ; real_T idj5hyxoz3 [ 4 ] ; real_T
ex0skiip24 ; real_T frvw5tfr5q [ 4 ] ; real_T h4xihyt1ug [ 159 ] ; real_T
iwg44exs5g [ 26 ] ; real_T kbdwxc5gyv ; real_T hpnhpaq3hf ; real_T kw2mc2f54g
; real_T np4sgj0uze ; real_T ibafq0ggxu ; real_T mt1rpkiyfp ; real_T
jnh32a12mk ; real_T gsqpfetcre ; real_T cokmhxd3cw ; real_T bisq51qkxp ;
real_T gp3dcunmfo ; real_T afvbv15lpm ; real_T o1kjfgygqq ; real_T nj0zvfpbxs
; real_T oswn5ymim2 ; real_T g1gbvczb2o ; real_T c2v2toypds ; real_T
fxp4n1nqzj ; real_T mw5rzz05or ; real_T ixh4gmo224 ; real_T fm33dmmmls ;
real_T kp54qwa2gg ; real_T arg5blkvtg ; real_T aiu4fdl0gc ; real_T eihpzfi2ln
; real_T hezoo43y0q ; real_T ofcnur01ss ; real_T afxisy1b20 ; real_T
n1uuisg4fw ; real_T eua13yagug ; real_T bmp4rhxpul ; real_T fzd10ahxco ;
real_T enecbqrfz5 ; real_T mntq0tppuk ; real_T h0sb2533vd ; real_T hic1rjtsai
; real_T hewx2df0ek ; real_T hfz5bihucl ; real_T k4fqogeply ; real_T
d4yrrkxbew ; real_T jeyupwj05d ; real_T povy1e3cdf ; real_T oww2w4mlsz ;
real_T b5bpctebld ; real_T e2o0qyzahq ; real_T kbsdtbfy5k ; real_T f5ta3mfjzs
; real_T gcgeoe3iiq ; real_T nxju1b0nfk ; real_T fsoikihjt1 ; real_T
gjyfuvtq0v ; real_T ihgmb1kpmh ; real_T epdjm1qtac ; real_T fwtfj3b0hp ;
real_T g4doefl2of ; boolean_T awqcje34vp ; boolean_T kvdej4nyky ; boolean_T
cwstdnv15s ; boolean_T hf5hmpwr00 ; boolean_T nqc1swz1f5 ; boolean_T
aw0sdhxkut ; } B ; typedef struct { real_T hdz0nups2p [ 2 ] ; real_T
bqgmk2ugv4 [ 2 ] ; real_T auveueqvz5 [ 2 ] ; real_T kyjsjkxfrc [ 2 ] ; real_T
jxp1qqkjt1 [ 2 ] ; real_T ibcfck1opc [ 2 ] ; real_T lpi2q22kbk [ 123 ] ;
real_T jt0sfxu401 ; real_T bdoob1ijr3 ; real_T jlot4ajqhq ; real_T lrcapd2g5t
; real_T jwkyerowmb ; real_T lbvma42sos ; real_T gfeprm5f5a ; real_T
jjebi2i5un ; real_T ebmpnozmec ; real_T l4lzpabl4t ; real_T lpfa0xqegk ;
real_T ppix1t4koq ; real_T grpjnlftxq ; real_T ecmyri45ls ; real_T j5dfwnlbxm
; real_T pnojpqs3ns ; real_T gwyanuw3x0 ; real_T ho5z3w1sbb ; real_T
cx3y5wj24t ; real_T liyidkg1og ; real_T hq3xers3h0 ; real_T f053xx0l23 ;
real_T iayqwjxn30 ; real_T g522ownwqo ; real_T motifvjzhr ; real_T ocq00sjeyj
; real_T edd2kbkzs3 ; real_T iwqu4lrnkv ; real_T e4ptdvhtkx ; real_T
a4o1phii2z ; real_T d5beywmeax ; real_T o1pj5ffxoy ; real_T nmu44g4cwh ;
real_T ipprpfttv3 ; real_T jwcmyh4tyw ; real_T fadr5pbwq1 ; real_T jetkaz1b2y
; real_T c2nm3gd1a4 ; real_T f0oqest1i1 ; real_T dewhsbzzvs ; real_T
hksk41e2yx ; real_T ljdesx2yzv ; real_T bmrkjzbemi ; real_T pb0fxdtdzl ;
real_T kzaxa1cwm5 ; real_T a5wlka4qb2 ; real_T ogm11qxgfe ; real_T luocivfdwy
; void * bgwsy3m1jh ; void * j4btagyhoo ; void * ljvsw4ftil ; void *
djuug5w32t ; void * d3dsrtwi0j ; void * ni2bvu1xg1 ; void * frpy0o3adk ; void
* pco3n20tlq ; void * d3bgeeko12 ; void * fwa4citlig ; void * j553pujwhq ;
void * dcorct0idw ; struct { void * AQHandles ; void * SlioLTF ; } fwmkchozeq
; struct { void * LoggedData [ 4 ] ; } haruhqhvxm ; struct { void * AQHandles
; void * SlioLTF ; } nvuyb1yzrc ; struct { void * AQHandles ; void * SlioLTF
; } k4mh4yu0ov ; struct { void * LoggedData [ 4 ] ; } nsk5nlbpt3 ; struct {
void * LoggedData [ 2 ] ; } mkjlrssi4i ; void * iak0awbnmq ; void *
mwaj5uxciv ; void * ng4gmlk2i5 ; void * flsmaquu11 ; void * ocujfrzzrp ; void
* iphuwwyg2r ; void * p4eex3535n ; void * a5txtrw5jr ; void * lxt5anhnhb ;
int32_T doyt1502bn ; int32_T csvpkvttn4 ; int32_T ex3mrpp4j3 ; int32_T
b4zx4xqegz ; int32_T letqwzpvfw ; int32_T dhg2x3hhw4 ; uint32_T fto133wy4o ;
int_T laeadqjoyo [ 36 ] ; int_T hnibndvd1j ; int_T ggh5d2ostt ; int_T
ddn5xcth0s ; int_T m4mwptfw3a ; int_T mqhuvls5ex ; int_T l3nkgsx0lg ; int_T
eeda03zvsk ; int_T dmjstp1pnq ; int_T hgmprgjhr2 ; int8_T c3pebqdhtw ; int8_T
n3ddpqpuun ; int8_T mvd0gisct2 ; int8_T l4lq0poyio ; int8_T bfjoxab0mk ;
int8_T ksdc555p1f ; int8_T pkc5pvpbud ; int8_T dr430txhud ; int8_T bcuawr35dl
; uint8_T l1z2owbfnm ; uint8_T lz0tgfsnu0 ; uint8_T oknt3qnnbn ; uint8_T
kzq4yloq2t ; uint8_T fnn2bvdaoo ; uint8_T moizrwcmqn ; uint8_T f54g14zkss ;
uint8_T g3mio5fr0t ; uint8_T kqc5wee2bc ; boolean_T iw3cho4vxe ; boolean_T
kjsrm0r1qu ; boolean_T lqtqsmmd1w ; boolean_T m5i40ct5vz ; boolean_T
hm42zo1kvb ; boolean_T kuylzd02lp ; boolean_T o1zlpawevl ; boolean_T
e1uf5s5z1k ; boolean_T gq2nzjnf0w ; boolean_T eibahmjyhj ; boolean_T
gov5rlozbf ; boolean_T gob230sujf ; boolean_T ecisw5adre ; boolean_T
kurl1epm13 ; } DW ; typedef struct { real_T h1hyrdcllz ; real_T okrolznbwl ;
real_T ipf4r3df0b ; real_T gngpeei5u4 ; real_T aydmc4pu5v ; real_T honk40fjnb
; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ;
struct P_ { real_T Idc ; real_T LoadA ; real_T LoadB ; real_T LoadC ; real_T
ModulationIndex ; real_T ffund ; real_T Fourier1_Freq ; real_T
Fourier1_Freq_kyl1z2hreh ; real_T Fourier1_Freq_ckkrxwnziq ; real_T
RMS3_TrueRMS ; real_T RMS4_TrueRMS ; real_T RMS5_TrueRMS ; real_T Gain_Gain ;
real_T Gain1_Gain ; real_T Gain_Gain_nfdcqsmx05 ; real_T
Gain1_Gain_mpdvg40lot ; real_T RMS_Y0 ; real_T sinwt_Amp ; real_T sinwt_Bias
; real_T sinwt_Hsin ; real_T sinwt_HCos ; real_T sinwt_PSin ; real_T
sinwt_PCos ; real_T Integ4_gainval ; real_T Integ4_IC ; real_T K1_Value ;
real_T SFunction_P1_Size [ 2 ] ; real_T SFunction_P1 ; real_T
SFunction_P2_Size [ 2 ] ; real_T SFunction_P2 ; real_T SFunction_P3_Size [ 2
] ; real_T SFunction_P3 ; real_T SFunction_P4_Size [ 2 ] ; real_T
SFunction_P4 ; real_T K2_Value ; real_T UnitDelay_InitialCondition ; real_T
UnitDelay1_InitialCondition ; real_T coswt_Amp ; real_T coswt_Bias ; real_T
coswt_Hsin ; real_T coswt_HCos ; real_T coswt_PSin ; real_T coswt_PCos ;
real_T Integ4_gainval_p0pakyry2d ; real_T Integ4_IC_pm40rzklkj ; real_T
K1_Value_gmfkjcymcu ; real_T SFunction_P1_Size_h24o5xofg5 [ 2 ] ; real_T
SFunction_P1_mve5jzjn2t ; real_T SFunction_P2_Size_ptok2c4vkm [ 2 ] ; real_T
SFunction_P2_dnazov5g1j ; real_T SFunction_P3_Size_ojs5p0ceq0 [ 2 ] ; real_T
SFunction_P3_ivpagtbovw ; real_T SFunction_P4_Size_kvdkozvfrz [ 2 ] ; real_T
SFunction_P4_gtch0vha02 ; real_T K2_Value_ehlwinmotq ; real_T
UnitDelay_InitialCondition_aoguy1temn ; real_T
UnitDelay1_InitialCondition_a5jgapepa0 ; real_T Gain_Gain_mzuc0gr3rr ; real_T
Gain1_Gain_jvz4pavaqm ; real_T Gain_Gain_gpon2qmr4o ; real_T
RMS_Y0_bgjt2cqyc0 ; real_T Integ4_gainval_cmbswlryt5 ; real_T
Integ4_IC_hyg1orgnjy ; real_T K1_Value_eper5cnwey ; real_T
SFunction_P1_Size_cfue4013uz [ 2 ] ; real_T SFunction_P1_ces20fopyh ; real_T
SFunction_P2_Size_ay0oozdq4l [ 2 ] ; real_T SFunction_P2_czfhe53zlo ; real_T
SFunction_P3_Size_eavq2jcrxn [ 2 ] ; real_T SFunction_P3_dso1nd4g1i ; real_T
SFunction_P4_Size_iuauhtkk0r [ 2 ] ; real_T SFunction_P4_o1nsl2odxy ; real_T
UnitDelay_InitialCondition_msrh1hb3tx ; real_T K2_Value_poc3ahh3o0 ; real_T
UnitDelay1_InitialCondition_mjkrfyvx2n ; real_T
Saturationtoavoidnegativesqrt_UpperSat ; real_T
Saturationtoavoidnegativesqrt_LowerSat ; real_T Gain_Gain_cikg2wd54t ; real_T
Gain1_Gain_og1ztmrikp ; real_T Gain_Gain_evmlakd0vp ; real_T
Gain1_Gain_ju55l2bdzy ; real_T RMS_Y0_dzq0lqiuxk ; real_T
sinwt_Amp_oijvtutv4k ; real_T sinwt_Bias_hpiubgslry ; real_T
sinwt_Hsin_embht0yjxr ; real_T sinwt_HCos_phnvp0v0je ; real_T
sinwt_PSin_mqldsacd5r ; real_T sinwt_PCos_l0uzrah2yr ; real_T
Integ4_gainval_b2hr2aosow ; real_T Integ4_IC_eia2ftyj1x ; real_T
K1_Value_d02xdalxac ; real_T SFunction_P1_Size_drqbfawq2t [ 2 ] ; real_T
SFunction_P1_meab1fmohc ; real_T SFunction_P2_Size_mtui52flb0 [ 2 ] ; real_T
SFunction_P2_mtpqswmwzj ; real_T SFunction_P3_Size_koxhnafs0c [ 2 ] ; real_T
SFunction_P3_dvfpjfg0ac ; real_T SFunction_P4_Size_jmx5nhnvsc [ 2 ] ; real_T
SFunction_P4_odxtskcuwt ; real_T K2_Value_gwlqxdyahb ; real_T
UnitDelay_InitialCondition_h222ofuws1 ; real_T
UnitDelay1_InitialCondition_mgl10icrr2 ; real_T coswt_Amp_ckwsy1d5vd ; real_T
coswt_Bias_hhsezuq143 ; real_T coswt_Hsin_i0o0fsqk53 ; real_T
coswt_HCos_bibg2rjnu5 ; real_T coswt_PSin_bcb2sivwyr ; real_T
coswt_PCos_b2mnttqblm ; real_T Integ4_gainval_nfkwaoa5zw ; real_T
Integ4_IC_id0g55h212 ; real_T K1_Value_fri1a0ongp ; real_T
SFunction_P1_Size_mdfnofpkyb [ 2 ] ; real_T SFunction_P1_cc5kyrw4xh ; real_T
SFunction_P2_Size_kn3dc1rpjw [ 2 ] ; real_T SFunction_P2_jxgkcddozl ; real_T
SFunction_P3_Size_iffghakq0a [ 2 ] ; real_T SFunction_P3_demgfrwqa1 ; real_T
SFunction_P4_Size_ngg0llxaro [ 2 ] ; real_T SFunction_P4_lg3wpmfbov ; real_T
K2_Value_jtrzvmmebu ; real_T UnitDelay_InitialCondition_pgrk2rptpk ; real_T
UnitDelay1_InitialCondition_ecwqqjll5r ; real_T Gain_Gain_k2vac0i5eo ; real_T
Gain1_Gain_fdymcqm5hn ; real_T Gain_Gain_lrl440wsi1 ; real_T
RMS_Y0_jasmhly5vt ; real_T Integ4_gainval_cyxcyfj2ix ; real_T
Integ4_IC_cmkobyzxoi ; real_T K1_Value_fiqnvvlbtv ; real_T
SFunction_P1_Size_adklgix35t [ 2 ] ; real_T SFunction_P1_hkfef4lit1 ; real_T
SFunction_P2_Size_fn0kh1ozqy [ 2 ] ; real_T SFunction_P2_de1rgculkk ; real_T
SFunction_P3_Size_a4xnsyreel [ 2 ] ; real_T SFunction_P3_epvfavtoo2 ; real_T
SFunction_P4_Size_h30xo1wbyk [ 2 ] ; real_T SFunction_P4_nl142gpj5w ; real_T
UnitDelay_InitialCondition_fwom33d0us ; real_T K2_Value_kmw4g0e5by ; real_T
UnitDelay1_InitialCondition_pav0c4wl2x ; real_T
Saturationtoavoidnegativesqrt_UpperSat_pkr45gxbax ; real_T
Saturationtoavoidnegativesqrt_LowerSat_faduiv0b3h ; real_T
Gain_Gain_irzzlkvume ; real_T Gain1_Gain_h3dgnhtza4 ; real_T
Gain_Gain_cvnqvfbfob ; real_T Gain1_Gain_pp3awytfhp ; real_T
RMS_Y0_ka1uowgurp ; real_T sinwt_Amp_l2gdj0uf33 ; real_T
sinwt_Bias_of4cf15cx1 ; real_T sinwt_Hsin_fwqz1kodyw ; real_T
sinwt_HCos_iatcouh3bm ; real_T sinwt_PSin_ezmzcturha ; real_T
sinwt_PCos_bqkynrur55 ; real_T Integ4_gainval_ad3r4knrp3 ; real_T
Integ4_IC_hlm5pnpjyb ; real_T K1_Value_bvxfbao2pd ; real_T
SFunction_P1_Size_hdzfqts4px [ 2 ] ; real_T SFunction_P1_gejrt01jyf ; real_T
SFunction_P2_Size_kygust4i13 [ 2 ] ; real_T SFunction_P2_ek1xdjc2tb ; real_T
SFunction_P3_Size_gxecz1stla [ 2 ] ; real_T SFunction_P3_ckfk1oml4o ; real_T
SFunction_P4_Size_ehy32gbq1m [ 2 ] ; real_T SFunction_P4_ljqgukgmbn ; real_T
K2_Value_lfot5huboi ; real_T UnitDelay_InitialCondition_mhq5umibzr ; real_T
UnitDelay1_InitialCondition_csl0lzavbh ; real_T coswt_Amp_mrrwl5kftw ; real_T
coswt_Bias_eabnppk3dd ; real_T coswt_Hsin_ipmmvop0j2 ; real_T
coswt_HCos_hrlrqukbrc ; real_T coswt_PSin_ien3v5if2m ; real_T
coswt_PCos_jfqix0kyk3 ; real_T Integ4_gainval_k5i2tkby2r ; real_T
Integ4_IC_e3ezkszlmy ; real_T K1_Value_fpmnopebgd ; real_T
SFunction_P1_Size_nurtgxf3pr [ 2 ] ; real_T SFunction_P1_fsncrxesv5 ; real_T
SFunction_P2_Size_abuhz0s45k [ 2 ] ; real_T SFunction_P2_mbvxvar4qa ; real_T
SFunction_P3_Size_iribng3jzq [ 2 ] ; real_T SFunction_P3_eixmpunjta ; real_T
SFunction_P4_Size_d34e4l0tlz [ 2 ] ; real_T SFunction_P4_f2joxh0nvg ; real_T
K2_Value_fdk4k2gepc ; real_T UnitDelay_InitialCondition_liy42xpsvk ; real_T
UnitDelay1_InitialCondition_kp4i0cv52p ; real_T Gain_Gain_mjhuuub0oq ; real_T
Gain1_Gain_iohcin0rw2 ; real_T Gain_Gain_ozgidwvo0b ; real_T
RMS_Y0_jys4w42uyu ; real_T Integ4_gainval_aic2uxvjtz ; real_T
Integ4_IC_n3vsv1fujy ; real_T K1_Value_chvilvz2jj ; real_T
SFunction_P1_Size_nq3uzrogtq [ 2 ] ; real_T SFunction_P1_msdslcv5o3 ; real_T
SFunction_P2_Size_brp5zn1b4c [ 2 ] ; real_T SFunction_P2_hxiv5xbvlo ; real_T
SFunction_P3_Size_dz2f5ik0lq [ 2 ] ; real_T SFunction_P3_fugjw14aid ; real_T
SFunction_P4_Size_go4cr2gil4 [ 2 ] ; real_T SFunction_P4_keejlnirow ; real_T
UnitDelay_InitialCondition_bqwauueqoj ; real_T K2_Value_e5ticna4dr ; real_T
UnitDelay1_InitialCondition_o2zq5zqj25 ; real_T
Saturationtoavoidnegativesqrt_UpperSat_jebmupogt4 ; real_T
Saturationtoavoidnegativesqrt_LowerSat_hhpj4y3w4k ; real_T Constant_Value ;
real_T SineWaveFunction1_Bias ; real_T SineWaveFunction1_Phase ; real_T
Constant3_Value ; real_T Constant4_Value ; real_T uib1_Gain ; real_T
uDLookupTable_tableData [ 3 ] ; real_T uDLookupTable_bp01Data [ 3 ] ; real_T
Constant2_Value ; real_T Constant_Value_dlflefihkr ; real_T Constant1_Value ;
real_T SineWaveFunction_Bias ; real_T SineWaveFunction_Phase ; real_T
Constant_Value_l3unqqh2kq ; real_T Constant_Value_dxzjx5wwcr ; real_T
Constant_Value_a4nouejct5 ; real_T SineWaveFunction2_Bias ; real_T
SineWaveFunction2_Phase ; real_T Constant_Value_cpsdmvnz4x ; real_T
Constant_Value_ln0n1kk0z4 ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo * InverterWFETs_GetCAPIStaticMap
( void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
