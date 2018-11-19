#include "__cf_InverterWFETs.h"
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif
#include "nesl_rtw.h"
#include "InverterWFETs_d83d6795_1.h"
void InverterWFETs_d83d6795_1_gateway ( void ) { NeModelParameters
modelparams = { ( NeSolverType ) 0 , 0.001 , 1 , 1e-08 , 0 , 0 , 0 , 0 , (
SscLoggingSetting ) 0 , 464520489 , } ; NeSolverParameters solverparams = { 0
, 0 , 1 , 0 , 0 , 0.001 , 1e-06 , 1e-09 , 0 , 0 , 100 , 0 , 1 , 0 , 1e-09 , 1
, ( NeLocalSolverChoice ) 0 , 1e-08 , 1 , 3 , 2 , ( NeLinearAlgebraChoice ) 0
, ( NeEquationFormulationChoice ) 0 , 1024 , 1 , 0.001 , } ; const
NeOutputParameters * outputparameters = NULL ; NeDae * dae ; size_t
numOutputs = 0 ; { static const NeOutputParameters outputparameters_init [ ]
= { { 0 , 0 , "InverterWFETs/Solver\nConfiguration" , } , } ;
outputparameters = outputparameters_init ; numOutputs = sizeof (
outputparameters_init ) / sizeof ( outputparameters_init [ 0 ] ) ; }
InverterWFETs_d83d6795_1_dae ( & dae , & modelparams , & solverparams ) ;
nesl_register_simulator_group ( "InverterWFETs/Solver Configuration_1" , 1 ,
& dae , & solverparams , & modelparams , numOutputs , outputparameters , 0 )
; }
