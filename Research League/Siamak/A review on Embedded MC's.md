#A brief review on Embedded Micro Computer Systems
A system combined of mechanical and electrical parts to perform a specific task an has a computer embedded inside.

![](/Images/Embedded_Systems.png)
#######Embedded systems block diagram
####An embedded system is a real-time system. In a real-time system, we can put an upper bound on the time required to perform the input-calculation-output sequence. This response time is called interface latency.
####Another real-time requirement that exists in embedded systems is the execution of the periodic tasks.

##An embedded system components
####Software:Ordered sequence of very specific instructions stored in memory, defining what and when certain tasks are to be performed.
####Processor:Executes the software by retrieving and interpreting instructions.
####Ports:Physical connection between the computer and outside world.
####Bus:A collection of wires used to pass information between modules.
####Ram:The computer can store information in RAM by writing to it,or it can retrieve previously stored data by reading from it. RAM's are volatile. Static RAM's are not Volatile.
####ROM:Information is programmed into ROM using more complex techniques. ROM's are not volatile.
####EEPROM:Electrically Erasable Read Only Memories.
 
##Von Neumann Architecture
All information is connected across the same bus.

![](/Images/Von_Neumann.jpg)

##Harvard Architecture
Allows doing two jobs at the same time.

![](/Images/Harvard.jpg)

##Development Process of an  Embedded MC system
####Editor:Create source code
####Compiler:Build the object code
####Simulator:test the code
####Real Target:Deployment
In a real system, we choose the real micro-controller via its' JTAG debugger as the target. In this way, the object code is downloaded into the EEPROM. In particular, we will use JTAG debugger connected via a USB cable to download and debug programs. The JTAG is both a leader and debugger.
##MEMORY
Each memory cell contains one byte of information, and each byte has a unique and sequential address. The memory is called byte-addressable because each byte has a separate address.
We read and write to memory specifying address.
###Read Only Memory (ROM)
####The information is programmed or burned into the device, and during normal operation it only allows read access.
###Random Access Memory (RAM)
####Used to store temporary information, and during normal operation we can read and write data in it. 
####Writing on RAM is 10,000 times faster than writing on ROM.
####ROM is much denser than RAM.
####The basic storage element is called a Register.