
# Microprocessors & Computer Architecture

---


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Recall: Digital Systems Concepts</summary>
  

  Multiplexer, Adders (Half & Full)
  Transistors, Flip Flops, Latches

  General information about registers

</details>


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 0.</summary>
  
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

<details>
<summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 2.</summary>

#### Memory Locations and Addresses
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


</details>



<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">ASM Self Study</summary>
  

  


</details>