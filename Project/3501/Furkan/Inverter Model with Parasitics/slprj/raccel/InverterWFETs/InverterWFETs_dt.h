#include "__cf_InverterWFETs.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) , sizeof ( struct_nxjvkMAWNMdcRzZZdKzTgC
) , sizeof ( struct_UskKbK8yRC8GsXIo0cWURE ) , sizeof (
struct_eLgyfQcxb2WnpXMf1nKTTD ) } ; static const char_T * rtDataTypeNames [ ]
= { "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "struct_nxjvkMAWNMdcRzZZdKzTgC" ,
"struct_UskKbK8yRC8GsXIo0cWURE" , "struct_eLgyfQcxb2WnpXMf1nKTTD" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . lcge5t1gjo
) , 0 , 0 , 280 } , { ( char_T * ) ( & rtB . awqcje34vp ) , 8 , 0 , 6 } , { (
char_T * ) ( & rtDW . hdz0nups2p [ 0 ] ) , 0 , 0 , 183 } , { ( char_T * ) ( &
rtDW . bgwsy3m1jh ) , 11 , 0 , 34 } , { ( char_T * ) ( & rtDW . doyt1502bn )
, 6 , 0 , 6 } , { ( char_T * ) ( & rtDW . fto133wy4o ) , 7 , 0 , 1 } , { (
char_T * ) ( & rtDW . laeadqjoyo [ 0 ] ) , 10 , 0 , 45 } , { ( char_T * ) ( &
rtDW . c3pebqdhtw ) , 2 , 0 , 9 } , { ( char_T * ) ( & rtDW . l1z2owbfnm ) ,
3 , 0 , 9 } , { ( char_T * ) ( & rtDW . iw3cho4vxe ) , 8 , 0 , 14 } } ;
static DataTypeTransitionTable rtBTransTable = { 10U , rtBTransitions } ;
static DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . Idc
) , 0 , 0 , 267 } } ; static DataTypeTransitionTable rtPTransTable = { 1U ,
rtPTransitions } ;
