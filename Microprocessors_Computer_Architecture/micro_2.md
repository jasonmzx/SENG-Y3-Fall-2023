


## Chapter 4 : Software

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;"> October 25th </summary>
  
![MCPA_asmp111111](../static/MPCA_ch4_1.png)

*High Level Languages build constructs* For loops, If statements, look at Python, lots of High Level Abstraction

*In Assembly you need to trace, it's harder*

**Compiler** : Program that takes High Level Constructs and converts into Assembly
- Optimizations are done at the Compiler level

**Assembly** : Takes Assembly Files, and turns it into Machine Code
- No optimizations are done, only directly translations here

Object files aren't Executable !!!

**Linker** : Link all the functions together, so that the program can be executed. *(Since the program goes Instruction by Instruction, and so everything needs to be together, including source files, library files which are already compiled object files)*

-  For EX: if I use `cos()` and don't include `<cmath>` I'll get **Linker** Error.
Now the **Executable File** from the Linker, is able to Execute

**Loader** : You can use Origins, in Assembly, which the Loader will take into account (Put labels at origin: **0x1000**, and Instructions at **0x400**)

#### Loader Header
- Loader reads the "Header" of the File for origin info, how to load it in...
- Hey Loader, we've got some libraries that might not be resolved yet... `cos()` for ex: pls know where this fn is in memory, and use it

- It's stored in memory once, and All programs using the `cos()` knows where it is, and Calls it. *(Loader Only Knows where it is)*

---

### Assembler Process

We know we've got 3 formats **J Type**, **R Type**, **I Type**

##### Two-Pass Assembler

#### First Pass

In the first pass, the assembler goes through the source code to generate all machine instructions and populate the symbol table with addresses of labels.

**Example:**
```assembly
LOOP:  ADD R1, R2
       SUB R3, R4
       JMP END
       MUL R1, R2
END:   HLT
```

In the first pass, the symbol table might look like: *(Pass 1 builds the symbol table)*

```
| Label | Address |
|-------|---------|
| LOOP  | 0000    |
| END   | 0011    |

```

#### Second Pass

During the second pass, the assembler uses the symbol table to resolve unknown branch offsets or addresses.

**Example:**
From the previous code, JMP END can now be resolved to jump to address 0011.

After the second pass, the machine code might look like:

```assembly
ADD R1, R2
SUB R3, R4
JMP 0011
MUL R1, R2
HLT
```

---




</details>


---

## Chapter 5: Basic Processing Unit

<details>
<summary style="font-size: 30px; font-weight: 500; cursor: pointer;"> Addressing Modes Review </summary>

  Addressing modes in computer architecture dictate how the instructions in a machine language program identify the data they operate upon or the destinations where they deposit results. Different addressing modes offer various ways to specify this data.

  **Immediate Mode:**

  The operand is a constant value and is present within the instruction itself. *(operand is IMMED16 here)*
  For example, in the instruction `ADD R1, 5`, the value "5" is an immediate operand.

  **Register Mode:**

  The operand is a register; the name or number of the register is given in the instruction.

  *Example:* `ADD R1, R2` adds the contents of register R2 to register R1.

  **Absolute or Direct Mode:**

  The address of the operand is given directly in the instruction.
  Example: `LOAD R1, 1000` loads the content of **memory location 1000** into register R1.

  **Indirect Mode:**

  The **address of the operand** is held in a register or memory location. The instruction specifies this register or memory location, and the actual operand is fetched from the resulting address. *(Here the operand holds an address)*

  *Example:* If R2 contains the address 2000, `LOAD R1, (R2)` loads the content of memory location 2000 into R1.

  **Indexed Mode:**

  This mode uses the sum of a base address and an index register to find the effective address.
  *Example:* If the instruction is `LOAD R1, 100(R2)` and R2 contains the value 50, then the data is loaded into R1 from memory location 150 (100 + 50).

  **Auto-increment and Auto-decrement Mode:**

  In auto-increment, after fetching the operand, the content of the register *(usually an address)* is automatically incremented. This is useful for accessing consecutive memory locations.
  In auto-decrement, the content of the register is decremented before fetching the operand.

  <br>

  *Example AUTO-INCR*: If R2 contains the address 1000, `LOAD R1, (R2)+` loads the content of memory location 1000 into R1 and then increments R2 to 1001. 

  <br>

  *EXAMPLE AUTO-DECR*
  If it was `LOAD R1, -(R2)`, R2 would first decrement to 999, then its content would be loaded into R1.

  ---

  ### Bringing it back to this Chapter:

  Every instruction cycle begins with fetching the next instruction from memory. Once fetched, the CPU decodes the instruction to determine which operation to perform and which addressing mode is used. The addressing mode will then dictate how the CPU retrieves or identifies the operands for the operation.

  **Operand Fetches**
  Based on the addressing mode, the data path will be set up differently to fetch operands!


  **Immediate Mode:** The operand data might be fetched as part of the instruction itself. Thus, the operand would be directly routed from the instruction register.

  **Direct or Absolute Mode:** The operand's address is directly specified. The CPU uses this address to fetch the operand from memory.

  **Register Mode:** The operand is in a CPU register, so no memory access is required. The data path will route data from the specified register.

  **Indexed Mode:** The CPU must add the base and index values to get the effective address. This involves the ALU in the data path to calculate the sum, and then memory is accessed using the effective address.

  **Indirect Mode:** The data path will first fetch an address from a register or memory location and then use that address to fetch the operand from memory.

  **Auto-increment/Auto-decrement Mode:** The data path fetches data from the memory address specified in a register. Then, the ALU increments (or decrements) the register's value.
</details>


  <details>
    <summary style="font-size: 30px; font-weight: 500; cursor: pointer;"> Fundementals & Instruction Execution</summary>

  proc. = processor

  **Processing Unit**
  - Executions of instructions, by the proc.
  - Functional Units of proc. how they are connected
  - Hardware for control signals (Control Unit)
  - Micro-programmed control

  ### SLOW
  One Logic Circuit taking a long time, and it's quite sequential *(NOT CONCURRENT)*

  ![wdqwdqef](../static/MPCA_6_slow.png)

  ### Much Faster *(Pipeline)*
  Way more Thruput, and in a pipeline, the "Station" *(Smaller logic circuit)* is able to process a portion of the Compute!

  **Example:** Report writing *(Abstract, Intro, Body, Conclusion)* at every stage in pipeline, one paragraph is added, and once the *Intro* Writer finishes Intro for Report #1, next cylce he can do Report #2's Intro. **THRU-PUT is 5x!!!**

  ![wdqwdqef](../static/MPCA_6_faster.png)
  ![wdqwdqef2](../static/MPCA_6_faster_1.png)
  
  **Notes**
  - In Pipeline, Stages should do equal amount of work, in a timeframe *(As our clock cycle is designed to support a whole stage/operation to preform within the single cycle)*
  - Design stages to keep clock cycle short *(Therefore, Frequency *(GHz)* gets faster, as `f = 1/l` , where `l` is clock cycle length)
  ---

  ### Instruction Executions

  We can have `n` stages, but due to Hardware limitations we usually have **5** with RISC and NIOS 2
  The **5** Steps we define, need to be as generic as possible to support the ut-most variety of instructions

  ![ix](../static/MPCA_6_i1.png)

  ![ix](../static/MPCA_6_i2.png)

  ![ix](../static/MPCA_6_i3.png)


</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;"> Pipelining </summary>

</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;"> Data Path </summary>


</details>


