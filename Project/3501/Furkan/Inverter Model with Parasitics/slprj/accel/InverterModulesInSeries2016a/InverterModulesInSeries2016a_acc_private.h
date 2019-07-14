#include "__cf_InverterModulesInSeries2016a.h"
#ifndef RTW_HEADER_InverterModulesInSeries2016a_acc_private_h_
#define RTW_HEADER_InverterModulesInSeries2016a_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "InverterModulesInSeries2016a_acc.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T InverterModulesInSeries2016a_acc_rt_TDelayUpdateTailOrGrowBuf (
int_T * bufSzPtr , int_T * tailPtr , int_T * headPtr , int_T * lastPtr ,
real_T tMinusDelay , real_T * * tBufPtr , real_T * * uBufPtr , real_T * *
xBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay , int_T *
maxNewBufSzPtr ) ; real_T
InverterModulesInSeries2016a_acc_rt_TDelayInterpolate ( real_T tMinusDelay ,
real_T tStart , real_T * tBuf , real_T * uBuf , int_T bufSz , int_T * lastIdx
, int_T oldestIdx , int_T newIdx , real_T initOutput , boolean_T discrete ,
boolean_T minorStepAndTAtLastMajorOutput ) ; extern real_T look1_pbinlxpw (
real_T u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T
prevIndex [ ] , uint32_T maxIndex ) ; void
InverterModulesInSeries2016a_RMS_Init ( SimStruct * S ,
B_RMS_InverterModulesInSeries2016a_T * localB ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ,
P_RMS_InverterModulesInSeries2016a_T * localP ,
X_RMS_InverterModulesInSeries2016a_T * localX ) ; void
InverterModulesInSeries2016a_RMS_Deriv ( SimStruct * S ,
B_RMS_InverterModulesInSeries2016a_T * localB ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ,
XDot_RMS_InverterModulesInSeries2016a_T * localXdot ) ; void
InverterModulesInSeries2016a_RMS_Disable ( SimStruct * S ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ) ; void
InverterModulesInSeries2016a_RMS_Update ( SimStruct * S ,
B_RMS_InverterModulesInSeries2016a_T * localB ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ,
P_RMS_InverterModulesInSeries2016a_T * localP ) ; void
InverterModulesInSeries2016a_RMS ( SimStruct * S , boolean_T rtu_Enable ,
real_T rtu_In , const real_T rtu_In_k [ 2 ] ,
B_RMS_InverterModulesInSeries2016a_T * localB ,
DW_RMS_InverterModulesInSeries2016a_T * localDW ,
P_RMS_InverterModulesInSeries2016a_T * localP ,
X_RMS_InverterModulesInSeries2016a_T * localX ,
XDis_RMS_InverterModulesInSeries2016a_T * localXdis ) ; void
InverterModulesInSeries2016a_TrueRMS_Init ( SimStruct * S ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
P_TrueRMS_InverterModulesInSeries2016a_T * localP ,
X_TrueRMS_InverterModulesInSeries2016a_T * localX ) ; void
InverterModulesInSeries2016a_TrueRMS_Deriv ( SimStruct * S ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
XDot_TrueRMS_InverterModulesInSeries2016a_T * localXdot ) ; void
InverterModulesInSeries2016a_TrueRMS_ZC ( SimStruct * S ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
P_TrueRMS_InverterModulesInSeries2016a_T * localP ,
ZCV_TrueRMS_InverterModulesInSeries2016a_T * localZCSV ) ; void
InverterModulesInSeries2016a_TrueRMS_Disable ( SimStruct * S ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ) ; void
InverterModulesInSeries2016a_TrueRMS_Update ( SimStruct * S ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
P_TrueRMS_InverterModulesInSeries2016a_T * localP ) ; void
InverterModulesInSeries2016a_TrueRMS ( SimStruct * S , boolean_T rtu_Enable ,
real_T rtu_In , const real_T rtu_In_j [ 2 ] ,
B_TrueRMS_InverterModulesInSeries2016a_T * localB ,
DW_TrueRMS_InverterModulesInSeries2016a_T * localDW ,
P_TrueRMS_InverterModulesInSeries2016a_T * localP ,
X_TrueRMS_InverterModulesInSeries2016a_T * localX ,
XDis_TrueRMS_InverterModulesInSeries2016a_T * localXdis ) ;
#endif
