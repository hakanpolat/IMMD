# Introduction to C
C is a structured language. Three basic templates are Sequential, Decision and Iterative.

## Integrated Development Environment (IDE)
* Editor
* Compiler:Converts a high level language to machine language
* Linker:Build software system
##### Startup.s
##### UART.c
##### main.c
* Loader:Places the object code in memory
* DEbugger:Verifies the system to work properly

## Pre-processor Directions Section
#### #include <stdio.h> //diamond brace for sys lib: Standard I/O
#### #include "uart.h" //quotes for user lib: UART Lib
This is essential to tell the system where to find the functions used in the code.

## Subroutines Section
### Main:Mandatory subroutine for a C program to be executed.
#### int main(void){   }

## Punctuation marks Meanings

![](/Images/Punctuation_marks.png)

## Sections of a Program
#### There are four sections of a C program:
##### 1.The first section is the documentation section, which includes the purpose of the software, the authors, the date, and any copyright information. When the software involves external hardware we will add information about how the external hardware is connected.
##### 2.The second section is the pre-processor directives. We will use the pre-processor directive #include to connect this software with other modules. We use diamond braces to include system libraries, like the standard I/O, and we use quotes to link up with other user code within the project. In this case the uart module is software we wrote to perform I/O with the universal asynchronous receiver/transmitter (uart). We will discuss modular programming in great detail in this class.
##### 3.The third section is global declarations section. This section will include global variables and function prototypes for functions defined in this module.
##### 4.The last section will be the functions themselves. In this class we will use the terms subroutine, procedure, function, and program interchangeably. Every software system in C has exactly one main program, which defines where it begins execution.
There are two types of comments. The first type explains how to use the software. These comments are usually placed at the top of the file, within the header file, or at the start of a function. The reader of these comments will be writing software that uses or calls these routines. The second type of comments assists a future programmer (ourselves included) in changing, debugging or extending these routines. We usually place these comments within the body of the functions. The comments on the right of each line are examples of the second type.
Preprocessor directives begin with # in the first column. As the name implies preprocessor commands are processed first. I.e., the compiler passes through the program handling the preprocessor directives. Although there are many possibilities (assembly language, conditional compilation, interrupt service routines), I thought I’d mention the two most important ones early in the class. We create a macro using #define  to define constants.

##### #define SIZE 10 //Basically, wherever SIZE is found as a token, it is replaced with the 10.

A second important directive is the #include, which allows you to include another entire file at that position within the program. The #include directive will include the file named tm4c123gh6pm.h at this point in the program. This file will define all the I/O port names for the TM4C123.

##### #include "tm4c123gh6pm.h"



## Variable Types
Variables are used to hold information. In C, we define a variable by specifying the name of the variable and the type.

![](/Images/Variable_Types.png)

## Special character operators

![](/Images/char_operators.png)

## Precedence and associativity determine the order of operation

![](/Images/precedence.png)

## Function Syntax
A function is a sequence of operations that can be invoked from other places within the software. We can pass zero or more parameters into a function. A function can have zero or one output parameter. It is important for the C programmer to distinguish the two terms declaration and definition. A function declaration specifies its name, its input parameters and its output parameter. Another name for a function declaration is prototype. A data structure declaration specifies its type and format. On the other hand, a function definition specifies the exact sequence of operations to execute when it is called. A function definition will generate object code, which are machine instructions to be loaded into memory that perform the intended operations. A data structure definition will reserve space in memory for it. The confusing part is that the definition will repeat the declaration specifications. The C compiler performs just one pass through the code, and we must declare data/functions before we can access/invoke them. To run, of course, all data and functions must be defined.

## If-Then Conditional and While Loop

## Scanf for Getting User Input

## C Keywords and Punctuation


![](/Images/keywords.png)
