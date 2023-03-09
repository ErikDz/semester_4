### Lecture 4 - y86

#### Instructions
- The instruction is the fundamental unit of work

- Specifies two things:
  - **opcode:** operation to be performed
  - **operands:** data/locations to be used for operation

- The instructions and their formats are known as the *Instruction Set Architecture (ISA)*

#### SEQ Stages
- **Fetch:** Read instruction from instruction memory
- **Decode:** Read program registers
- **Execute:** Compute value or address
- **Memory:** Read or write data
- **Write back:** Write program registers
- **PC:** Update program counter

#### Word-Oriented Memory Organization
In computer memory, data is stored in individual bytes. Each byte has a unique address that specifies its location in memory.

When we refer to the address of a word in memory, we are actually referring to the address of the first byte in that word. Once we know the address of the first byte in a word, we can locate the rest of the bytes that belong to that word by simply incrementing the address. 

In computer architecture, endianness refers to the order in which bytes are stored in memory.

- **Big-endian** refers to the format where the most significant byte of a multi-byte value is stored first at the lowest address. In this case, the byte at address 0001 contains the value DD.

- **Little-endian** on the other hand, refers to the format where the least significant byte of a multi-byte value is stored first at the lowest address. In this case, the byte at address 0001 contains the value CA. This format is used by Intel processors, Apple M1, and AArch64.

#### Y86 Instructions (part 1)
- Four move intructions
  - `irmovq, rrmovq, mrmovq, rmmovq`
  - The source is either immediate (i), register (r), or memory (m)
  - The destination is either register (r) or memory (m)

- Four integer operation instructions
  - `addq, subq, andq, xorq`
  - operate on register data
  - set three condition codes `zf,sf,of` (zero, sign, overflow)

- Seven jump instructions
  - `jmp, jle, jl, je, jne, jge, jg`
  - branches taken according to the type of branch and settings of condition codes

- Six conditional move instructions 
  - `cmovle,cmovl,cmove,cmovne,covge,cmovg`
  - same register-register format as `rrmovq`
  - destinaton register updated *only* if the condtion codes satisfy the constraint

- The nop (do nothing) and halt (stop the machine) instructions
  - `nop,halt`

#### Condition Codes
- **ZF** (zero flag): most recent operation yielded zero.
- **SF** (sign flag): most recent operation yielded a negative value.
- **OF** (overflow flag): most recent operation overflowed 2's component
Updated by `addq,subq,andq,xorq` (only)

- Conditions checked by contitional jumps and movs:
  - E :`zf` *(b=a iff b-a=0)*
  - NE: `zf^1` *$b\ne a \iff !(b-a=0)$* 
  - L : `sf^of` *b<a iff b-a<0 or overflow to +ve*
  - LE: `zf|(sf^of)` *$b\le a \iff b-a\le 0$ or overflow to +ve* 
  - GE: `(sf^of)^1` *($b\ge a \iff b\ge a \iff !(b-a<0)$)*
  - G: `(sf^of^1)&(zf^1)` *$!(b-a\ge 0)$*


#### SEQ Summary

- **Implementation**
  - Express every instruction as series of simple steps
  - Follow same general flow for each instruction type
  - Assemble registers, memories, predesgined combinational blocks
  - Connect with control logic

- **Limitations**
  - Too slow to be practical
  - In one cycle, must propagate through instuction memory, register file, ALU and data memory
  - Would need to run clock very slowly
  - Hardware units only active for fraction of clock cycle