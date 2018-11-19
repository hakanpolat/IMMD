#include "__cf_InverterWFETs.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "InverterWFETs_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "InverterWFETs.h"
#include "InverterWFETs_capi.h"
#include "InverterWFETs_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"InverterWFETs/Sine Wave Function" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 1 , 0 , TARGET_STRING ( "InverterWFETs/Sine Wave Function1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"InverterWFETs/Sine Wave Function2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 3 , 0 , TARGET_STRING ( "InverterWFETs/Subtract" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"InverterWFETs/Subtract1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
5 , 0 , TARGET_STRING ( "InverterWFETs/Subtract2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING ( "InverterWFETs/Sum" ) ,
TARGET_STRING ( "Sum Capacitor" ) , 0 , 0 , 0 , 0 , 1 } , { 7 , 0 ,
TARGET_STRING ( "InverterWFETs/Switch" ) , TARGET_STRING ( "at" ) , 0 , 0 , 0
, 0 , 2 } , { 8 , 0 , TARGET_STRING ( "InverterWFETs/Switch1" ) ,
TARGET_STRING ( "bt" ) , 0 , 0 , 0 , 0 , 2 } , { 9 , 0 , TARGET_STRING (
"InverterWFETs/Switch2" ) , TARGET_STRING ( "ct" ) , 0 , 0 , 0 , 0 , 2 } , {
10 , 0 , TARGET_STRING ( "InverterWFETs/Switch3" ) , TARGET_STRING ( "ab" ) ,
0 , 0 , 0 , 0 , 2 } , { 11 , 0 , TARGET_STRING ( "InverterWFETs/Switch4" ) ,
TARGET_STRING ( "bb" ) , 0 , 0 , 0 , 0 , 2 } , { 12 , 0 , TARGET_STRING (
"InverterWFETs/Switch5" ) , TARGET_STRING ( "cb" ) , 0 , 0 , 0 , 0 , 2 } , {
13 , 3 , TARGET_STRING ( "InverterWFETs/RMS3/RMS " ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 14 , 5 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS " ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 }
, { 15 , 0 , TARGET_STRING ( "InverterWFETs/RMS3/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 16 , 0 , TARGET_STRING (
"InverterWFETs/RMS3/Logical Operator" ) , TARGET_STRING ( "" ) , 0 , 1 , 0 ,
0 , 3 } , { 17 , 0 , TARGET_STRING ( "InverterWFETs/RMS3/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 18 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS " ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , {
19 , 10 , TARGET_STRING ( "InverterWFETs/RMS4/TrueRMS " ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"InverterWFETs/RMS4/Data Type Conversion" ) , TARGET_STRING ( "" ) , 0 , 1 ,
0 , 0 , 3 } , { 21 , 0 , TARGET_STRING (
"InverterWFETs/RMS4/Logical Operator" ) , TARGET_STRING ( "" ) , 0 , 1 , 0 ,
0 , 3 } , { 22 , 0 , TARGET_STRING ( "InverterWFETs/RMS4/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 23 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS " ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , {
24 , 15 , TARGET_STRING ( "InverterWFETs/RMS5/TrueRMS " ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"InverterWFETs/RMS5/Data Type Conversion" ) , TARGET_STRING ( "" ) , 0 , 1 ,
0 , 0 , 3 } , { 26 , 0 , TARGET_STRING (
"InverterWFETs/RMS5/Logical Operator" ) , TARGET_STRING ( "" ) , 0 , 1 , 0 ,
0 , 3 } , { 27 , 0 , TARGET_STRING ( "InverterWFETs/RMS5/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 28 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 }
, { 29 , 5 , TARGET_STRING ( "InverterWFETs/RMS3/TrueRMS /Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 30 , 5 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Sqrt" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 31 , 8 , TARGET_STRING ( "InverterWFETs/RMS4/RMS /Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 32 , 10 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 33 , 10 , TARGET_STRING ( "InverterWFETs/RMS4/TrueRMS /Sqrt" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 34 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 }
, { 35 , 15 , TARGET_STRING ( "InverterWFETs/RMS5/TrueRMS /Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 36 , 15 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Sqrt" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 37 , 0 , TARGET_STRING (
"InverterWFETs/Solver Configuration/EVAL_KEY/INPUT_1_1_1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 38 , 0 , TARGET_STRING (
"InverterWFETs/Solver Configuration/EVAL_KEY/INPUT_2_1_1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 39 , 0 , TARGET_STRING (
"InverterWFETs/Solver Configuration/EVAL_KEY/INPUT_3_1_1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 40 , 0 , TARGET_STRING (
"InverterWFETs/Solver Configuration/EVAL_KEY/INPUT_4_1_1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"InverterWFETs/Solver Configuration/EVAL_KEY/INPUT_5_1_1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 42 , 0 , TARGET_STRING (
"InverterWFETs/Solver Configuration/EVAL_KEY/INPUT_6_1_1" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 43 , 0 , TARGET_STRING (
"InverterWFETs/Solver Configuration/EVAL_KEY/OUTPUT_1_0" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 1 } , { 44 , 0 , TARGET_STRING (
"InverterWFETs/Solver Configuration/EVAL_KEY/STATE_1" ) , TARGET_STRING ( ""
) , 0 , 0 , 3 , 0 , 1 } , { 45 , 0 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/Constant2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 2 } , { 46 , 0 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/Constant3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 2 } , { 47 , 0 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/Constant4" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 2 } , { 48 , 0 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/Add3" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 49 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Product" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 50 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Product1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 51 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Product" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 52 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Product1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 53 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Product" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 54 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Product1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 55 , 5 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/K1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 56 , 5 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 57 , 5 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/Switch" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 58 , 10 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/K1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 59 , 10 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 60 , 10 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/Switch" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 61 , 15 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/K1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 62 , 15 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 63 , 15 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/Switch" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 64 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/K1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 65 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 66 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Switch" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 67 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 68 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 69 , 3 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Switch" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 70 , 5 , TARGET_STRING (
 "InverterWFETs/RMS3/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 71 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/K1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 72 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 73 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Switch" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 74 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 75 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 76 , 8 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Switch" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 77 , 10 , TARGET_STRING (
 "InverterWFETs/RMS4/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 78 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/K1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 79 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 80 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Switch" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 81 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/K1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 82 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 83 , 13 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Switch" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 84 , 15 , TARGET_STRING (
 "InverterWFETs/RMS5/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 85 , 3 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 86 , 3 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 87 , 8 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 88 , 8 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 89 , 13 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 90 , 13 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 91 , TARGET_STRING ( "InverterWFETs/RMS3" ) ,
TARGET_STRING ( "TrueRMS" ) , 0 , 0 , 0 } , { 92 , TARGET_STRING (
"InverterWFETs/RMS4" ) , TARGET_STRING ( "TrueRMS" ) , 0 , 0 , 0 } , { 93 ,
TARGET_STRING ( "InverterWFETs/RMS5" ) , TARGET_STRING ( "TrueRMS" ) , 0 , 0
, 0 } , { 94 , TARGET_STRING ( "InverterWFETs/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING ( "InverterWFETs/Constant1" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 96 , TARGET_STRING (
"InverterWFETs/Sine Wave Function" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 }
, { 97 , TARGET_STRING ( "InverterWFETs/Sine Wave Function" ) , TARGET_STRING
( "Phase" ) , 0 , 0 , 0 } , { 98 , TARGET_STRING (
"InverterWFETs/Sine Wave Function1" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0
} , { 99 , TARGET_STRING ( "InverterWFETs/Sine Wave Function1" ) ,
TARGET_STRING ( "Phase" ) , 0 , 0 , 0 } , { 100 , TARGET_STRING (
"InverterWFETs/Sine Wave Function2" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0
} , { 101 , TARGET_STRING ( "InverterWFETs/Sine Wave Function2" ) ,
TARGET_STRING ( "Phase" ) , 0 , 0 , 0 } , { 102 , TARGET_STRING (
"InverterWFETs/Compare To Zero/Constant" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 103 , TARGET_STRING ( "InverterWFETs/Compare To Zero1/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 104 , TARGET_STRING (
"InverterWFETs/Compare To Zero2/Constant" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 105 , TARGET_STRING ( "InverterWFETs/Compare To Zero3/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 106 , TARGET_STRING (
"InverterWFETs/Compare To Zero4/Constant" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 107 , TARGET_STRING ( "InverterWFETs/Compare To Zero5/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 108 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /RMS" ) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 ,
0 } , { 109 , TARGET_STRING ( "InverterWFETs/RMS3/RMS /Fourier1" ) ,
TARGET_STRING ( "Freq" ) , 0 , 0 , 0 } , { 110 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
111 , TARGET_STRING ( "InverterWFETs/RMS3/TrueRMS /RMS" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 112 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Saturation to avoid negative sqrt" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 113 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Saturation to avoid negative sqrt" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 114 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /RMS" ) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 ,
0 } , { 115 , TARGET_STRING ( "InverterWFETs/RMS4/RMS /Fourier1" ) ,
TARGET_STRING ( "Freq" ) , 0 , 0 , 0 } , { 116 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
117 , TARGET_STRING ( "InverterWFETs/RMS4/TrueRMS /RMS" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 118 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Saturation to avoid negative sqrt" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 119 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Saturation to avoid negative sqrt" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 120 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /RMS" ) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 ,
0 } , { 121 , TARGET_STRING ( "InverterWFETs/RMS5/RMS /Fourier1" ) ,
TARGET_STRING ( "Freq" ) , 0 , 0 , 0 } , { 122 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
123 , TARGET_STRING ( "InverterWFETs/RMS5/TrueRMS /RMS" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 124 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Saturation to avoid negative sqrt" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 125 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Saturation to avoid negative sqrt" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 126 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 127 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 128 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 129 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/1\\ib1" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 130 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/1-D Lookup Table" ) , TARGET_STRING (
"Table" ) , 0 , 4 , 0 } , { 131 , TARGET_STRING (
"InverterWFETs/Triangle Generator/Model/1-D Lookup Table" ) , TARGET_STRING (
"BreakpointsForDimension1" ) , 0 , 4 , 0 } , { 132 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 133 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "Bias" ) , 0 ,
0 , 0 } , { 134 , TARGET_STRING ( "InverterWFETs/RMS3/RMS /Fourier1/cos(wt)"
) , TARGET_STRING ( "SinH" ) , 0 , 0 , 0 } , { 135 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "CosH" ) , 0 ,
0 , 0 } , { 136 , TARGET_STRING ( "InverterWFETs/RMS3/RMS /Fourier1/cos(wt)"
) , TARGET_STRING ( "SinPhi" ) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "CosPhi" ) , 0
, 0 , 0 } , { 138 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 139 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "Bias" ) , 0 ,
0 , 0 } , { 140 , TARGET_STRING ( "InverterWFETs/RMS3/RMS /Fourier1/sin(wt)"
) , TARGET_STRING ( "SinH" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "CosH" ) , 0 ,
0 , 0 } , { 142 , TARGET_STRING ( "InverterWFETs/RMS3/RMS /Fourier1/sin(wt)"
) , TARGET_STRING ( "SinPhi" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "CosPhi" ) , 0
, 0 , 0 } , { 144 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 145 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "Bias" ) , 0 ,
0 , 0 } , { 146 , TARGET_STRING ( "InverterWFETs/RMS4/RMS /Fourier1/cos(wt)"
) , TARGET_STRING ( "SinH" ) , 0 , 0 , 0 } , { 147 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "CosH" ) , 0 ,
0 , 0 } , { 148 , TARGET_STRING ( "InverterWFETs/RMS4/RMS /Fourier1/cos(wt)"
) , TARGET_STRING ( "SinPhi" ) , 0 , 0 , 0 } , { 149 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "CosPhi" ) , 0
, 0 , 0 } , { 150 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 151 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "Bias" ) , 0 ,
0 , 0 } , { 152 , TARGET_STRING ( "InverterWFETs/RMS4/RMS /Fourier1/sin(wt)"
) , TARGET_STRING ( "SinH" ) , 0 , 0 , 0 } , { 153 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "CosH" ) , 0 ,
0 , 0 } , { 154 , TARGET_STRING ( "InverterWFETs/RMS4/RMS /Fourier1/sin(wt)"
) , TARGET_STRING ( "SinPhi" ) , 0 , 0 , 0 } , { 155 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "CosPhi" ) , 0
, 0 , 0 } , { 156 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 157 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "Bias" ) , 0 ,
0 , 0 } , { 158 , TARGET_STRING ( "InverterWFETs/RMS5/RMS /Fourier1/cos(wt)"
) , TARGET_STRING ( "SinH" ) , 0 , 0 , 0 } , { 159 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "CosH" ) , 0 ,
0 , 0 } , { 160 , TARGET_STRING ( "InverterWFETs/RMS5/RMS /Fourier1/cos(wt)"
) , TARGET_STRING ( "SinPhi" ) , 0 , 0 , 0 } , { 161 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/cos(wt)" ) , TARGET_STRING ( "CosPhi" ) , 0
, 0 , 0 } , { 162 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "Amplitude" )
, 0 , 0 , 0 } , { 163 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "Bias" ) , 0 ,
0 , 0 } , { 164 , TARGET_STRING ( "InverterWFETs/RMS5/RMS /Fourier1/sin(wt)"
) , TARGET_STRING ( "SinH" ) , 0 , 0 , 0 } , { 165 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "CosH" ) , 0 ,
0 , 0 } , { 166 , TARGET_STRING ( "InverterWFETs/RMS5/RMS /Fourier1/sin(wt)"
) , TARGET_STRING ( "SinPhi" ) , 0 , 0 , 0 } , { 167 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/sin(wt)" ) , TARGET_STRING ( "CosPhi" ) , 0
, 0 , 0 } , { 168 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/K1" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 169 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/K2" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 170 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 172 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 173 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 174 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 175 , TARGET_STRING (
"InverterWFETs/RMS3/TrueRMS /Mean value/Model/Unit Delay1" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 176 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/K1" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 177 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/K2" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 178 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 179 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 180 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 181 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 182 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 183 , TARGET_STRING (
"InverterWFETs/RMS4/TrueRMS /Mean value/Model/Unit Delay1" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 184 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/K1" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 185 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/K2" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 186 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 187 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/Integ4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 188 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 189 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 190 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 191 , TARGET_STRING (
"InverterWFETs/RMS5/TrueRMS /Mean value/Model/Unit Delay1" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 192 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/K1" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 193 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/K2" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 194 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 195 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 196 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 197 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 198 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 199 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Unit Delay1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 200 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 201 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/K2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 202 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "gainval" ) , 0 , 0 , 0 } , { 203 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 204 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 205 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Gain1" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 206 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Unit Delay" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 207 , TARGET_STRING (
"InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Unit Delay1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 208 , TARGET_STRING (
 "InverterWFETs/RMS3/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 209 , TARGET_STRING (
 "InverterWFETs/RMS3/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 210 , TARGET_STRING (
 "InverterWFETs/RMS3/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 211 , TARGET_STRING (
 "InverterWFETs/RMS3/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 212 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/K1" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 213 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/K2" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 214 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 215 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 216 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 217 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 218 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 219 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Unit Delay1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 220 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 221 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/K2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 222 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "gainval" ) , 0 , 0 , 0 } , { 223 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 224 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 225 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Gain1" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 226 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Unit Delay" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 227 , TARGET_STRING (
"InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Unit Delay1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 228 , TARGET_STRING (
 "InverterWFETs/RMS4/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 229 , TARGET_STRING (
 "InverterWFETs/RMS4/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 230 , TARGET_STRING (
 "InverterWFETs/RMS4/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 231 , TARGET_STRING (
 "InverterWFETs/RMS4/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 232 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/K1" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 233 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/K2" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 234 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING (
"gainval" ) , 0 , 0 , 0 } , { 235 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Integ4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 236 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 237 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 238 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 239 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Unit Delay1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 240 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/K1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 241 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/K2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 242 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "gainval" ) , 0 , 0 , 0 } , { 243 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Integ4" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 244 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 245 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Gain1" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 246 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Unit Delay" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 247 , TARGET_STRING (
"InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Unit Delay1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 248 , TARGET_STRING (
 "InverterWFETs/RMS5/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 249 , TARGET_STRING (
 "InverterWFETs/RMS5/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 250 , TARGET_STRING (
 "InverterWFETs/RMS5/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 251 , TARGET_STRING (
 "InverterWFETs/RMS5/TrueRMS /Mean value/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 252 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 253 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 254 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 255 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 256 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 257 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 258 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 259 , TARGET_STRING (
 "InverterWFETs/RMS3/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 260 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 261 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 262 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 263 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 264 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 265 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 266 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 267 , TARGET_STRING (
 "InverterWFETs/RMS4/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 268 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 269 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 270 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 271 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 272 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 273 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 274 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 275 , TARGET_STRING (
 "InverterWFETs/RMS5/RMS /Fourier1/Mean value1/Model/Discrete Variable Time Delay/S-Function"
) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0
, 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { {
276 , TARGET_STRING ( "Idc" ) , 0 , 0 , 0 } , { 277 , TARGET_STRING ( "LoadA"
) , 0 , 0 , 0 } , { 278 , TARGET_STRING ( "LoadB" ) , 0 , 0 , 0 } , { 279 ,
TARGET_STRING ( "LoadC" ) , 0 , 0 , 0 } , { 280 , TARGET_STRING (
"ModulationIndex" ) , 0 , 0 , 0 } , { 281 , TARGET_STRING ( "ffund" ) , 0 , 0
, 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . kulfykvvqa , & rtB . lcge5t1gjo ,
& rtB . ohra4d5w4r , & rtB . eovubh0rxu , & rtB . bgybglbgav , & rtB .
b1ptcc5egb , & rtB . kbdwxc5gyv , & rtB . pnsni0ml1o , & rtB . nukezu5xk3 , &
rtB . oilte4fptr , & rtB . ce2llznftg , & rtB . cmlcurmh4c , & rtB .
ex0skiip24 , & rtB . g4doefl2of , & rtB . b5bpctebld , & rtB . awqcje34vp , &
rtB . kvdej4nyky , & rtB . hpnhpaq3hf , & rtB . hfz5bihucl , & rtB .
ofcnur01ss , & rtB . cwstdnv15s , & rtB . hf5hmpwr00 , & rtB . kw2mc2f54g , &
rtB . fm33dmmmls , & rtB . bisq51qkxp , & rtB . nqc1swz1f5 , & rtB .
aw0sdhxkut , & rtB . np4sgj0uze , & rtB . g4doefl2of , & rtB . k4fqogeply , &
rtB . b5bpctebld , & rtB . hfz5bihucl , & rtB . kp54qwa2gg , & rtB .
ofcnur01ss , & rtB . fm33dmmmls , & rtB . ibafq0ggxu , & rtB . bisq51qkxp , &
rtB . imlhhcedkr [ 0 ] , & rtB . p51dkbkwid [ 0 ] , & rtB . lc0gh4vn0y [ 0 ]
, & rtB . ajqsccxh4n [ 0 ] , & rtB . idj5hyxoz3 [ 0 ] , & rtB . frvw5tfr5q [
0 ] , & rtB . iwg44exs5g [ 0 ] , & rtB . h4xihyt1ug [ 0 ] , & rtB .
czvszvgx5h , & rtB . b1sdosls3i , & rtB . dvb12qxvf2 , & rtB . hpc0dqwvnx , &
rtB . e2o0qyzahq , & rtB . fsoikihjt1 , & rtB . afxisy1b20 , & rtB .
enecbqrfz5 , & rtB . gp3dcunmfo , & rtB . g1gbvczb2o , & rtB . jeyupwj05d , &
rtB . d4yrrkxbew , & rtB . oww2w4mlsz , & rtB . aiu4fdl0gc , & rtB .
arg5blkvtg , & rtB . hezoo43y0q , & rtB . jnh32a12mk , & rtB . mt1rpkiyfp , &
rtB . cokmhxd3cw , & rtB . ihgmb1kpmh , & rtB . gjyfuvtq0v , & rtB .
fwtfj3b0hp , & rtB . f5ta3mfjzs , & rtB . kbsdtbfy5k , & rtB . nxju1b0nfk , &
rtB . povy1e3cdf , & rtB . h0sb2533vd , & rtB . mntq0tppuk , & rtB .
hewx2df0ek , & rtB . eua13yagug , & rtB . n1uuisg4fw , & rtB . fzd10ahxco , &
rtB . eihpzfi2ln , & rtB . fxp4n1nqzj , & rtB . c2v2toypds , & rtB .
ixh4gmo224 , & rtB . o1kjfgygqq , & rtB . afvbv15lpm , & rtB . oswn5ymim2 , &
rtB . gsqpfetcre , & rtB . epdjm1qtac , & rtB . gcgeoe3iiq , & rtB .
hic1rjtsai , & rtB . bmp4rhxpul , & rtB . mw5rzz05or , & rtB . nj0zvfpbxs , &
rtP . RMS3_TrueRMS , & rtP . RMS4_TrueRMS , & rtP . RMS5_TrueRMS , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . SineWaveFunction_Bias , &
rtP . SineWaveFunction_Phase , & rtP . SineWaveFunction1_Bias , & rtP .
SineWaveFunction1_Phase , & rtP . SineWaveFunction2_Bias , & rtP .
SineWaveFunction2_Phase , & rtP . Constant_Value_dlflefihkr , & rtP .
Constant_Value_l3unqqh2kq , & rtP . Constant_Value_cpsdmvnz4x , & rtP .
Constant_Value_a4nouejct5 , & rtP . Constant_Value_dxzjx5wwcr , & rtP .
Constant_Value_ln0n1kk0z4 , & rtP . RMS_Y0 , & rtP . Fourier1_Freq , & rtP .
Gain_Gain_mzuc0gr3rr , & rtP . RMS_Y0_bgjt2cqyc0 , & rtP .
Saturationtoavoidnegativesqrt_UpperSat , & rtP .
Saturationtoavoidnegativesqrt_LowerSat , & rtP . RMS_Y0_dzq0lqiuxk , & rtP .
Fourier1_Freq_kyl1z2hreh , & rtP . Gain_Gain_k2vac0i5eo , & rtP .
RMS_Y0_jasmhly5vt , & rtP . Saturationtoavoidnegativesqrt_UpperSat_pkr45gxbax
, & rtP . Saturationtoavoidnegativesqrt_LowerSat_faduiv0b3h , & rtP .
RMS_Y0_ka1uowgurp , & rtP . Fourier1_Freq_ckkrxwnziq , & rtP .
Gain_Gain_mjhuuub0oq , & rtP . RMS_Y0_jys4w42uyu , & rtP .
Saturationtoavoidnegativesqrt_UpperSat_jebmupogt4 , & rtP .
Saturationtoavoidnegativesqrt_LowerSat_hhpj4y3w4k , & rtP . Constant2_Value ,
& rtP . Constant3_Value , & rtP . Constant4_Value , & rtP . uib1_Gain , & rtP
. uDLookupTable_tableData [ 0 ] , & rtP . uDLookupTable_bp01Data [ 0 ] , &
rtP . coswt_Amp , & rtP . coswt_Bias , & rtP . coswt_Hsin , & rtP .
coswt_HCos , & rtP . coswt_PSin , & rtP . coswt_PCos , & rtP . sinwt_Amp , &
rtP . sinwt_Bias , & rtP . sinwt_Hsin , & rtP . sinwt_HCos , & rtP .
sinwt_PSin , & rtP . sinwt_PCos , & rtP . coswt_Amp_ckwsy1d5vd , & rtP .
coswt_Bias_hhsezuq143 , & rtP . coswt_Hsin_i0o0fsqk53 , & rtP .
coswt_HCos_bibg2rjnu5 , & rtP . coswt_PSin_bcb2sivwyr , & rtP .
coswt_PCos_b2mnttqblm , & rtP . sinwt_Amp_oijvtutv4k , & rtP .
sinwt_Bias_hpiubgslry , & rtP . sinwt_Hsin_embht0yjxr , & rtP .
sinwt_HCos_phnvp0v0je , & rtP . sinwt_PSin_mqldsacd5r , & rtP .
sinwt_PCos_l0uzrah2yr , & rtP . coswt_Amp_mrrwl5kftw , & rtP .
coswt_Bias_eabnppk3dd , & rtP . coswt_Hsin_ipmmvop0j2 , & rtP .
coswt_HCos_hrlrqukbrc , & rtP . coswt_PSin_ien3v5if2m , & rtP .
coswt_PCos_jfqix0kyk3 , & rtP . sinwt_Amp_l2gdj0uf33 , & rtP .
sinwt_Bias_of4cf15cx1 , & rtP . sinwt_Hsin_fwqz1kodyw , & rtP .
sinwt_HCos_iatcouh3bm , & rtP . sinwt_PSin_ezmzcturha , & rtP .
sinwt_PCos_bqkynrur55 , & rtP . K1_Value_eper5cnwey , & rtP .
K2_Value_poc3ahh3o0 , & rtP . Integ4_gainval_cmbswlryt5 , & rtP .
Integ4_IC_hyg1orgnjy , & rtP . Gain_Gain_gpon2qmr4o , & rtP .
Gain1_Gain_jvz4pavaqm , & rtP . UnitDelay_InitialCondition_msrh1hb3tx , & rtP
. UnitDelay1_InitialCondition_mjkrfyvx2n , & rtP . K1_Value_fiqnvvlbtv , &
rtP . K2_Value_kmw4g0e5by , & rtP . Integ4_gainval_cyxcyfj2ix , & rtP .
Integ4_IC_cmkobyzxoi , & rtP . Gain_Gain_lrl440wsi1 , & rtP .
Gain1_Gain_fdymcqm5hn , & rtP . UnitDelay_InitialCondition_fwom33d0us , & rtP
. UnitDelay1_InitialCondition_pav0c4wl2x , & rtP . K1_Value_chvilvz2jj , &
rtP . K2_Value_e5ticna4dr , & rtP . Integ4_gainval_aic2uxvjtz , & rtP .
Integ4_IC_n3vsv1fujy , & rtP . Gain_Gain_ozgidwvo0b , & rtP .
Gain1_Gain_iohcin0rw2 , & rtP . UnitDelay_InitialCondition_bqwauueqoj , & rtP
. UnitDelay1_InitialCondition_o2zq5zqj25 , & rtP . K1_Value_gmfkjcymcu , &
rtP . K2_Value_ehlwinmotq , & rtP . Integ4_gainval_p0pakyry2d , & rtP .
Integ4_IC_pm40rzklkj , & rtP . Gain_Gain , & rtP . Gain1_Gain , & rtP .
UnitDelay_InitialCondition_aoguy1temn , & rtP .
UnitDelay1_InitialCondition_a5jgapepa0 , & rtP . K1_Value , & rtP . K2_Value
, & rtP . Integ4_gainval , & rtP . Integ4_IC , & rtP . Gain_Gain_nfdcqsmx05 ,
& rtP . Gain1_Gain_mpdvg40lot , & rtP . UnitDelay_InitialCondition , & rtP .
UnitDelay1_InitialCondition , & rtP . SFunction_P1_ces20fopyh , & rtP .
SFunction_P2_czfhe53zlo , & rtP . SFunction_P3_dso1nd4g1i , & rtP .
SFunction_P4_o1nsl2odxy , & rtP . K1_Value_fri1a0ongp , & rtP .
K2_Value_jtrzvmmebu , & rtP . Integ4_gainval_nfkwaoa5zw , & rtP .
Integ4_IC_id0g55h212 , & rtP . Gain_Gain_cikg2wd54t , & rtP .
Gain1_Gain_og1ztmrikp , & rtP . UnitDelay_InitialCondition_pgrk2rptpk , & rtP
. UnitDelay1_InitialCondition_ecwqqjll5r , & rtP . K1_Value_d02xdalxac , &
rtP . K2_Value_gwlqxdyahb , & rtP . Integ4_gainval_b2hr2aosow , & rtP .
Integ4_IC_eia2ftyj1x , & rtP . Gain_Gain_evmlakd0vp , & rtP .
Gain1_Gain_ju55l2bdzy , & rtP . UnitDelay_InitialCondition_h222ofuws1 , & rtP
. UnitDelay1_InitialCondition_mgl10icrr2 , & rtP . SFunction_P1_hkfef4lit1 ,
& rtP . SFunction_P2_de1rgculkk , & rtP . SFunction_P3_epvfavtoo2 , & rtP .
SFunction_P4_nl142gpj5w , & rtP . K1_Value_fpmnopebgd , & rtP .
K2_Value_fdk4k2gepc , & rtP . Integ4_gainval_k5i2tkby2r , & rtP .
Integ4_IC_e3ezkszlmy , & rtP . Gain_Gain_irzzlkvume , & rtP .
Gain1_Gain_h3dgnhtza4 , & rtP . UnitDelay_InitialCondition_liy42xpsvk , & rtP
. UnitDelay1_InitialCondition_kp4i0cv52p , & rtP . K1_Value_bvxfbao2pd , &
rtP . K2_Value_lfot5huboi , & rtP . Integ4_gainval_ad3r4knrp3 , & rtP .
Integ4_IC_hlm5pnpjyb , & rtP . Gain_Gain_cvnqvfbfob , & rtP .
Gain1_Gain_pp3awytfhp , & rtP . UnitDelay_InitialCondition_mhq5umibzr , & rtP
. UnitDelay1_InitialCondition_csl0lzavbh , & rtP . SFunction_P1_msdslcv5o3 ,
& rtP . SFunction_P2_hxiv5xbvlo , & rtP . SFunction_P3_fugjw14aid , & rtP .
SFunction_P4_keejlnirow , & rtP . SFunction_P1_mve5jzjn2t , & rtP .
SFunction_P2_dnazov5g1j , & rtP . SFunction_P3_ivpagtbovw , & rtP .
SFunction_P4_gtch0vha02 , & rtP . SFunction_P1 , & rtP . SFunction_P2 , & rtP
. SFunction_P3 , & rtP . SFunction_P4 , & rtP . SFunction_P1_cc5kyrw4xh , &
rtP . SFunction_P2_jxgkcddozl , & rtP . SFunction_P3_demgfrwqa1 , & rtP .
SFunction_P4_lg3wpmfbov , & rtP . SFunction_P1_meab1fmohc , & rtP .
SFunction_P2_mtpqswmwzj , & rtP . SFunction_P3_dvfpjfg0ac , & rtP .
SFunction_P4_odxtskcuwt , & rtP . SFunction_P1_fsncrxesv5 , & rtP .
SFunction_P2_mbvxvar4qa , & rtP . SFunction_P3_eixmpunjta , & rtP .
SFunction_P4_f2joxh0nvg , & rtP . SFunction_P1_gejrt01jyf , & rtP .
SFunction_P2_ek1xdjc2tb , & rtP . SFunction_P3_ckfk1oml4o , & rtP .
SFunction_P4_ljqgukgmbn , & rtP . Idc , & rtP . LoadA , & rtP . LoadB , & rtP
. LoadC , & rtP . ModulationIndex , & rtP . ffund , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 4 , 1 , 26 , 1 , 159 , 1 , 1 , 3 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 1.0E-8 , 1.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 2 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 2 ] , 1 , 0 } , { ( NULL ) , ( NULL ) , 4 , 0 } } ;
static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 91 , (
NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 185 , rtModelParameters ,
6 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 67555714U ,
1362381361U , 3890521108U , 1778704554U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * InverterWFETs_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void InverterWFETs_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void InverterWFETs_host_InitializeDataMapInfo (
InverterWFETs_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
