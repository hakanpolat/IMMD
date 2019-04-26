#include "__cf_pwm_analysis.h"
#ifndef RTW_HEADER_pwm_analysis_acc_private_h_
#define RTW_HEADER_pwm_analysis_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "pwm_analysis_acc.h"
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
boolean_T pwm_analysis_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr ,
int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * tBufPtr , real_T * * uBufPtr , real_T * * xBufPtr , boolean_T
isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr ) ; real_T
pwm_analysis_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart ,
real_T * tBuf , real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T
oldestIdx , int_T newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) ; extern real_T look1_pbinlxpw ( real_T u0 ,
const real_T bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) ; void pwm_analysis_RMS_Init ( SimStruct * S ,
DW_RMS_pwm_analysis_T * localDW , P_RMS_pwm_analysis_T * localP ,
X_RMS_pwm_analysis_T * localX ) ; void pwm_analysis_RMS_Deriv ( SimStruct * S
, B_RMS_pwm_analysis_T * localB , DW_RMS_pwm_analysis_T * localDW ,
XDot_RMS_pwm_analysis_T * localXdot ) ; void pwm_analysis_RMS_Disable (
SimStruct * S , DW_RMS_pwm_analysis_T * localDW ) ; void
pwm_analysis_RMS_Update ( SimStruct * S , B_RMS_pwm_analysis_T * localB ,
DW_RMS_pwm_analysis_T * localDW , P_RMS_pwm_analysis_T * localP ) ; void
pwm_analysis_RMS ( SimStruct * S , boolean_T rtu_Enable , real_T rtu_In ,
B_RMS_pwm_analysis_T * localB , DW_RMS_pwm_analysis_T * localDW ,
P_RMS_pwm_analysis_T * localP , X_RMS_pwm_analysis_T * localX ) ; void
pwm_analysis_TrueRMS_Init ( SimStruct * S , DW_TrueRMS_pwm_analysis_T *
localDW , P_TrueRMS_pwm_analysis_T * localP , X_TrueRMS_pwm_analysis_T *
localX ) ; void pwm_analysis_TrueRMS_Deriv ( SimStruct * S ,
B_TrueRMS_pwm_analysis_T * localB , DW_TrueRMS_pwm_analysis_T * localDW ,
XDot_TrueRMS_pwm_analysis_T * localXdot ) ; void pwm_analysis_TrueRMS_Disable
( SimStruct * S , DW_TrueRMS_pwm_analysis_T * localDW ) ; void
pwm_analysis_TrueRMS_Update ( SimStruct * S , B_TrueRMS_pwm_analysis_T *
localB , DW_TrueRMS_pwm_analysis_T * localDW , P_TrueRMS_pwm_analysis_T *
localP ) ; void pwm_analysis_TrueRMS ( SimStruct * S , boolean_T rtu_Enable ,
real_T rtu_In , B_TrueRMS_pwm_analysis_T * localB , DW_TrueRMS_pwm_analysis_T
* localDW , P_TrueRMS_pwm_analysis_T * localP , X_TrueRMS_pwm_analysis_T *
localX ) ;
#endif
