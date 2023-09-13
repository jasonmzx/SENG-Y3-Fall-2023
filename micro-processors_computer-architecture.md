
# Microprocessors & Computer Architecture

---


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Recall: Digital Systems Concepts</summary>
  

  Multiplexer, Adders (Half & Full)
  Transistors, Flip Flops, Latches

  General information about registers

</details>


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 0. | Introduction</summary>
  
## Basic Info & Textbook :
**Computer Organization and Embedded Systems, 6th Edition**
- Authors: Carl Hamacher, Zvonko Vranesic, Safwat Zaky, Naraig
Manjikian,
- Publisher: McGraw‐Hill , 2011

| Category    | Weight   |
|-------------|----------|
| Quizzes     | 10%      |
| Assignments | 10%      |
| Labs        | 15%      |
| Midterm     | 20%      |
| Final       | 45%      |

#### Quizzes:
• Lockdown browser will be used in quizzes.
• Expect a quiz every week. *(I will drop the lowest quiz mark)*
#### Tutorial Assignments:
• There will be assignment in almost every tutorial
#### Midterm:
• will be on **Oct. 4th** during the class time.
• No midterm deferral, marks will be added to the final exam

---

#### ** Course Overview: **

- Introduction to Computer Architecture:
    - CPU, ALU, I/O devices, Busses and Memory – RAM and ROM;
    - RISC vs. CISC architecture;
    - Assembly language programming using a microprocessor and the Hardware/Software Development Tool;
    - Register block and associated registers;
- Microcontroller systems: Interrupt, timer, memory, clock and reset generation
- Analog to Digital conversion (A/D) and Serial Communication Interface Systems.


---

| Week of  | Topic                               | Other Info                |
|----------|-------------------------------------|---------------------------|
| Sep. 05  | Introduction                        |                           |
| Sep. 11  | Basic Structure of Computers        |                           |
| Sep. 18  | Introduction to Microcontrollers    |                           |
| Sep. 25  | Instruction Set Architecture        |                           |
| Oct. 02  | Instruction Set Architecture Midterm| Midterm **( October. 4th )**    |
| Oct. 09  | Fall Study Week                     |                           |
| Oct. 16  | Basic Input/output                  |                           |
| Oct. 23  | Software                            |                           |
| Oct. 30  | Pipelining                          |                           |
| Nov. 06  | Memory Hierarchy                    |                           |
| Nov. 13  | Computer Arithmetic                  |                           |
| Nov. 20  | Serial Communication Interface Systems|                       |
| Nov. 27  | A/D converters, Review              |                           |


</details>

---

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 1. | Basic Structure of Computers</summary>

**Computers just add numbers, most important circuit in any given Computer System**

| Computer Types                      | Description |
|-------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Embedded Computers**             | - Integrated into a larger device or system for monitoring and control of physical processes.<br> - Used for specific purposes, e.g., industrial automation, appliances, telecommunication, and vehicles. |
| **Personal Computers (PCs)**       | - Widespread use in homes, education, and offices.<br> - Support various applications: computation, document preparation, design, entertainment, communication, and internet browsing.<br><br> **Classifications:** Desktop, Workstation, Portable/Notebook. |
| **Servers and Enterprise Systems** | - Large computers shared by many users over networks.<br> - Host large databases and provide information processing for organizations.                                                          |
| **Supercomputers and Grid Computers** | - Offer highest performance, used in demanding computations (e.g., weather forecasting, engineering, science).<br> - Expensive and large.<br> - Grid computers are cost-effective, using distributed networked PCs and storage. |
| **Cloud Computing**                | - Users access distributed computing and storage resources via the internet.<br> - Operated as a utility, charging on a pay-as-you-use basis.                                               |

<br>

![MPCA](./static/mpca_1.png)

*Every Computer has a CPU *(Central Processing Unit)*

CPU's can have multiple cores.

### Functional Units
---
**Input:**

Computers accept coded information through input units.

*Example devices:* Keyboard, Trackpad, Mouse, Mic, Camera, Communication Lines (Network)

**Output:**

It's function is to send processed results, out to the world.


*Example devices:* Text & Graphical Displays, Printers, LCD Displays, LEDs

Some Devices provide Input & Ouput like *Touch Screen Displays*!

**Memory Unit:**

It's function is to storage programs and data

Stores data in flipflops **(1 flipflop = 1 bit)**

*Classes of Storage:*
- Primary Memory
- Cache Memory
- Secondary Memory

### Classes of Storage (explained):

**Interconnection Network**

The actual "Flow" of how data is working to preform operations.

**Primary (Main) memory**

Main Memory (RAM), after you turn it off, flipflops will loose their contents.


**Cache Memory**

It is an adjunct to main memory to facilitate high instruction execution rate.

It is a smaller faster RAM unit that is used to hold sections of a program that are currently being executed, along with any associated data.

Cache is tightly coupled with the processor and is usually contained on the
same integrated‐circuit chip

- *Speeds up Processing, Speeds up READ/WRITE*
- *Cache takes small amount of Data from RAM, and uses it for the CPU's current task*

**Secondary Memory**

External Storage (Hard-Disk) usually an SSD now.


**Arithmetic and Logic Unit (ALU):**

Does Additional, has `add`
Does Multiplication, has `mul`

Does Logic Other Operations *(bit-shift, jump)*

**Control Unit:**

ALU & Control Unit make up the processor

It's function is to "Control" everyone, Oh this needs an addition? Give it to the Adder!

**Relies on timing** heavily! Programs need to be ran in order to work properly.


**Processor is composed of:**
- Arithmetic and Logic circuits
- Timing and control circuits
- Registers

**NOTE:** Processors don't deal with the RAM Directly, they just interact with the *Cache Memory* which is constantly being pulled from RAM

Cache gets stored into Registers on CPU *(known as Processor Registers)*

---

### Basic Operational Concepts

![MPCA_3](./static/MCPA_3.png)

- Hardware, Lowest Level, can't operation without system Software

- Systems Software, Utilities that are really commonly used so the developper doesn't have to define every fn. *(Keyboard Inputs, STD IN, STD OUT, etc...)*

- Applications Software, the programs you write, to solve specific problems... *(Ontop of the Systems Software)*


#### Instructions and Programs:

An **instruction** specifies an operation & the location of it's data operands.

A **32-bit** word typically holds one encoded instruction.

---

![MPCA4](./static/MCPA_4.png)

Just for `C = A + B`

Load R2 (Register 2), A *Loads in 32-bits from Address A, 4 bytes*
Load R3 (Register 3), B *Loads in 32-bits from Address B, 4 bytes*

ADD R4 (Register 4), than adds R2 & R3 *With Addition, you activate the "Adder" circuit, and you'll get a result in temporary Register*

STORE R4 (Register 4) *Store the actual memory to Address C*

**LOAD** > Load from Memory
**STORE** > Store to Memory

Here we assumed that **A** & **B** where already loaded in, that's why we are just "Loading" it in.

---

![MPCA](./static/MCPA_5.png)

**Program Counter (PC)** : Has the Address of the Instruction to be ran Next. Since it's sequentially going down the list of Instructions.

**Instruction Register (IR)** : Holds the current Instruction(s), The IR is connected to all the Control Circuitry *(MUX, Adders, etc...)*

**Control circuits** and the arithmetic and logic unit (ALU) fetch and execute
instructions

**The processor-memory interface** is a circuit which manages the transfer of data between the main memory and the processor

**Registers** are Hyper-specific parts of the CPU, whereas the **Cache** Just takes in Memory from the RAM, for Quick Access.

---

#### I/O Devices with CPU

Alot of I/O Devices have specific **Interrupt-Service Routine**

It acts very similar as the essential *Read* / *Write* Operations, the different is Interrupts; When is stuff actually being pressed, or clicked.

These **Interrupt Service Routines** are usually proprietary systems, that's why we need Hardware Drivers for some I/O Devices 

---

#### Number Representation and Arithmetic Operations




</details>

---

<details>
<summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 2. | Memory Locations and Addresses</summary>

- Memory consists of many **Millions** of cells
- Each cell holds **1 bit** of information. *(HI or LOW)*
- Memory size set by **k** (number of address bits)
- A "word" is a group of **n** bits
  - Word Length can be **16** to **64** bits.

**Memory** is a collection of consecutive words of the size specified by the Word Length.

Each Memory **byte** has distinct address

![MPCA_2](./static/MPCA_2.png)

Numbers **0** to **2^k − 1** are used as addresses
for successive locations in the memory.

Data is sent to Memory via an **ADDRESS BUS** Which is a Multiplexer (MUX) with **n** inputs.

Some Processors are 32bit, meaning each **Word Length** is 32 bits

**BYTE** : 8 bit
**Word** : ranges from 16 to 64 bits

Address Assignments per byte *( byte-adressable )*

![m10](./static/mpca_10.png)

#### Big & Little Endian Addressing:

**Big Endian** addressing; assigns lower addresses to more significant *(leftmost)* bytes of word.

**Little Endian** addressing; assigns lower addresses to less significant *(right-most)* bytes of word.

`450` in Binary: `0b111000010` (Length: 9 bits)

HIGHER ORDER BYTE: `00000001`
LOWER ORDER BYTE: `11000010`

![m11](./static/mpca_11.png)

**NOTE** here `x000001C2` is stored in Big Endian in Memory

![m12](./static/mpca_12.png)

#### Word Alignment:
- Number of bytes per word is normally a power of 2
- Word locations have aligned addresses if they begin at byte addresses that are multiples of the number of bytes in a word
![m13](./static/mpca_13.png)

#### Memory Operations

- In a computer, both the instructions that tell the program what to do and the data that the program works with are stored in the memory.

- When the computer wants to carry out an instruction, it needs to bring the part of memory that holds that instruction into the processor.

- Similarly, if the computer needs to work with data or store results, it has to move that data between the memory and the processor.

There are two main operations that involve the memory:
  - **Read**: This is when the computer retrieves information from the memory.
  - **Write**: This is when the computer puts information into the memory.

---

**Read Operation: Three Steps (Using Specified Registers)**

1. Load the address into the Memory Address Register (MAR).
2. Issue a read control signal ("0") by the CPU.
3. After the memory delay, load the word into the Memory Data Register (MDR).

**Example:**

Suppose you have a computer program that needs to read a value from memory. Let's say you want to read the value at memory address 1000.

   - Load 1000 into the Memory Address Register (MAR).
   - CPU sends a read control signal ("0").
   - After a short delay, the value stored at memory address 1000 is loaded into the Memory Data Register (MDR).

**Write Operation: Three Steps (Using Specified Registers)**

1. Load the new word into the Memory Data Register (MDR) by the CPU, and also load the address where the word should be stored into the Memory Address Register (MAR).
2. Issue a write control signal ("1") by the CPU.
3. After the memory delay, store the word from the MDR into the desired location in memory.

**Example:**

Let's say you want to write the value 42 into memory address 2000 in your computer's memory.

   - Load 42 into the Memory Data Register (MDR) and load 2000 into the Memory Address Register (MAR).
   - CPU sends a write control signal ("1").
   - After a short delay, the value 42 is stored at memory address 2000 in the computer's memory.

</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 2. | Instructions and Instruction Sequencing</summary>

- Tasks like Adding two numbers, Testing for conditionals, I/O (keyboard input, screen output)

- Computer must be able to do four types of operations; 
  - Data Transfer between memory and processor registers
  - Arithmetic and logic operations on data
  - Program sequencing and control
  - I/O transfers

### Register Transfer Notation (RTN)

* RTN is used to describe hardware-level data transfers and operations
* Possible locations that may be involved in such transfers are:
  * Memory locations
  * Processor registers
  * Registers in the I/O subsystem
* We identify such locations symbolically with convenient names such as:
  * Names that represent the addresses of memory location may be LOC, PLACE, A, or VAR2
  * Predefined names for the processor registers may be R0, R1, ...
  * Registers in the I/O subsystem may be identified by names such as DATAIN or OUTSTATUS

* Use [...] to denote contents of a location
* Use ← to denote transfer to a destination
  * Example: R2 ← [LOC]
    * Transfer from LOC in memory to register R2
* RTN can be extended to also show arithmetic operations involving locations
  * Example: R4 ← [R2] + [R3]
    * Add the contents of registers R2 and R3, place the sum in register R4
* Right-hand expression always denotes a value
* Left-hand side is the name of the location where the value to be placed.
* The words “transfer” and “move” mean “copy”
  * Transferring data from a source location A to a destination location B means that the contents of location A are read and then written into location B.
  * In this operation, only the contents of the destination will change.
Instructions and Instruction Sequencing

#### Assembly-Language Notation

  * It is needed to represent machine instructions and programs
  * It is called Assembly language
  * Example: the assembly-language instructions are:
    * Load R2, LOC → R2 ← [LOC]
    * Add R4, R2, R3 → R4 ← [R2] + [R3]
  * An instruction specifies the desired operation and the operands that are involved
  * Examples in this chapter will use English words for the operations (e.g., Load, Store, and Add). This helps emphasize fundamental concepts
  * Commercial processors use mnemonics, usually abbreviations (e.g., LD, ST, and ADD)
  * Mnemonics differ from processor to processor

---

Lec 2 ; Page. 16+ TODO
</details>

---

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">ASM Self Study</summary>
</details>