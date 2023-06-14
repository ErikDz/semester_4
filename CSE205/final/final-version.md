



---

### CH 6: Memory hierarchy

#### Locality
- Arrays get allocated with "Row Major":  the elements of a 3D array are stored in memory row by row, plane by plane, in a contiguous block of memory.

#### Cache Memories
- $M=2^m$: Computer system where each memory address has $m$ bits
- $S=2^s$: Cache sets. Each set consistes of $E$ cache lines. Each cache line has $B=2^b$ bytes ($B$ is the block size), a valid bit, and $t=m-(b+s)$  tag bits that uniquely identify the block in memory.

A cache's organisation can be characterized by the tuple:
$$(S,E,B,m)\\C=S\times E\times B\text{ which is the cache size}$$

![Cache org](../images/cse205-cache_organisation.png)


### CH7: Linking

- **Linking:** the process of collecting and combining various pieces of code and data into a single file that can be *loaded* and executed

#### Object Files, Symbol Resolution, Static Libraries

##### Static Linking
How it works:
  1. **Symbol resolution:**
     - Programs define and reference symbols *(variables and functions)*
     - Symbols definitions are stored in the *symbol table*
       - symbol table is an array of structs
       - each entry includes: name, size and location of symbol
     - Symbol resolution: associate each symbol reference with exactly one symbol def

2. **Relocation:** 
   - Compilers and assemblers generate multiple code and data sections, each starting at addr 0
   - Merges separate code and data sections into single sections
   - Relocates symbols from their relative locatiosn in the `.o` files to their final absolute memory locations in the executable
   - Updates all reference to these symbols to reflect their new positions
> The linker goes through all code & data sections & modifies the symbol references to point to the news memory locations.

##### Three Kinds of Object Files (Modules)
- **Relocatable object file (.o):** code and data to be combined with other relocatable objects

- **Executable object file (a.out):** code & data to be copied directly into memory

- **Shared object file (.so):** type of relocatable that can be loaded and linked dynamically (load or run time)

##### Executable and Linkable Format (ELF)

ELF Object File Format:
- **Elf header (16-bytes):**
  - architecture, byte ordering
  - file type (.o, exec, .so)
  - machine type, etc

- **Section header table:**
  - Offsets and size in file, alignment requirements, flags

- **Program header table:** (describes segments)
  - Segment = one or more sections, position in file, virtual addresses, memory permissions (rwx)


##### Symbol tables (.symbtab)
- **Strong sybmol:** functions and initialized globals
- **Weak symbol:** uninitialized globals

##### Linker Symbol Rules
1. Multiple strong symbols are not allowed
   - Each item can be defined only once
   - Otherwise: linker error

2. Strong symbol and multiple weak symbols, choose strong
   - ref to weak resolve to strong

3. If multiple weak symbols, pick arbitrary

#### Shared Libraries
- **Load-time Dynamic Linking:** occurs automatically when an executable is loaded before it starts running
  - Load `.text` and `.data` sections of shared libraries; perform relocation

- **Run-time Dynamic Linking:** occurs during program execution using calls to the `dlopen()` interface.

##### Position-Independent Code (PIC)
- References within the same module use PC-relative addressing
- References to external variables: **Global Offset Table (GOT)**
  - Library's code shared by all processes, but data segment duplicated in each
  - Whenever an objct module is loaded, the distance between the code and data segments never changes 
  - Store global references in the data segment in the GOT and generate relocation records for each GOT entry
- References to external functions: **Procedure Linkage Table (PLT)**

### CH 8: Exceptional Control Flow

#### Processes

- `int fork(void)`: Works from call downwards. Child process **pid**=0.
- If `waitpid` (wait but with process id) has as an argument `-1` then it means all child processes
> Can use `WIFEXITED` and `WEXITSTATUS` to get info abt exit status

##### Signals
- A **signal** is a notification sent to a process when a certain event occurs in the system

- `int kill(pid_t pid, int sig)`: send signal to process

##### Signal handlers
- `handler_t *signal(int signum, handler_t *handler)`: The signal function modifies the default action associated with the receipt of a signal signum
  - Values of handler:
    - **SIG_ING**: Ignore signals of type signum
    - **SIG_DFL**: Revert to the default action on receipt of signals of type signum
    - Otherwise, hadnler is the address of signal handler

> Misc: `sleep()` returns the number of seconds actually slept. If it gets interrupted (since it's blocking), it will return the n of seconds slept b4 interrupt

### Ch 9: Virtual memory
- **n-bit address space:** address space with $N=2^n$ addresses

#### VM as a Tool for Caching
- **Page hit:** reference to VM word that is in physical memory (DRAM cache hit)
- **Page fault:** reference to VM word that is not in physical memory (DRAM cache miss)

##### Handling Page Fault
1. Page miss causes page fault (exception)
2. Page fault handler selects a victim to be evicted (random address from DRAM)
3. Offending instruction is restarted: page hit 
> Waiting until the last moment to swap a page into memory is known as **demand paging**

##### Locality to the recue
- Programs tend to access a set of active virtual pages called the **working set**
- If (working set size < main memory size)
  - Good performance
- If (SUM(working set sizes)>main memory size)
  - **Thrashing:** Performance meltdown where pages are swapped (copied) in and out continuously

##### VM address translation
| Symbol | Description |
|--------|-------------|
| $N=2^n$ | Number of addresses in virtual address space |
| $M=2^m$ | Number of addresses in physcial address space | 
| $P=2^p$ | Page size (bytes) |
|---------|--------------------|
| VPO | Virtual page offset (bytes) |
| VPN | Virtual page number |
|-----|-----------------------|
| PPO | Physical page offset (bytes) |
| PPN | Physical page number |



- The n-bit virtual address has two components:
  - a $p$-bit virtual page offset (VPO)
  - an $(n-p)$-bit virtual page number (VPN)
> Since the physical and virtual pages are both $P$ bytes, the physical page offset (PPO) is dientical to the VPO

##### TLB
![tlb](../images/cse205-TLB.png)

- $T=2^t$: number of sets in TLB


- **Process:**
  1. Extract the VPN from the virtual address.
  2. Extract TLB index & TLB tag
  3. Find PPN trhoguh the TLB
  4. Concatenate PPN from the PTE with the VPO from the virtual address (forms a physical address)
  > PPO=VPO!!!
  > Also, in order to find other way round, find VPO=PPO, rest is PPN
  5. Send newly created physical address to cache
  6. Extract from it the CO, CI and CT
  7. If found, then good if not, page fault

### CH 9.9 Dynamic memory allocation

#### Implicit free lists
- **Implicit free list:** free blocks are kept in a linked list, with each free block containing a header and a padding
The header (usually one-word 4bytes) encodes the block size as well as whether the block is free or allocated. If we impose a double-word alignment constraint, then the block size is always a multiple of 8 and the 3 low-order bits are always zero. Thus, we can use these 3 bits to encode the block status (free or allocated) etc. 

To determine block size:
- We round up the sum of the request payload and the header size to the nearest multiple of the alignment requirement.
> **Example:** Suppose that the alignment requirement is 8 bytes and the header is one-word. Then `malloc(2)` is 4+2=6 rounded up to 8.

##### Finding a free block
- **First fit:** Search list from beginning, choose **first** free block that fits
- **Next fit:** Like first fit, but restarts where previous search finished
- **Best fit:** Search the list, choose the **best** free block: fits, with fewest bytes left over

##### Allocating in Free Block
Once the allocator has located a free block that fits, it must make another policy decision about how much of the free block to allocate
- Allocating in a free block: **splitting^: 

##### Freeing a block
- Simplest implementation:
  - Need only clear the "allocated" flag
> **Problem:** Once  a block has been freed, the split still remains, so even if there is enough space, on this case the allocator won't be able to allocate it

##### Coalescing 
- Join **(coalesce)** with next/previous pblocks, if they are free
  - Coalescing with next block

##### Bidirectional Coalescing
- **Boundary tags**
  - Replicate size/allocated word at "bottom" (end) of blocks
  - Allows to traverse the "list" backwards but requires extra space
> Blocks are of the form:
> 
> | Size | a |
> |------|---|
> | Payload and padding | 
> | **Size** | **a** |

##### Implicit Lists: Summary
- Allocate cost:
  - Linear-time worst case
- Free cost: 
  - constant-time worst case
  - even with coalescing
- Memory usage:
  - will depend on placement policy
  - First-fit, next-fit or best-fit

#### Explicit free list.
- **Explicit list** among the free blocks using pointers
- Maintain list(s) of **free** blocks, not **all** blocks
  - The "next" free block could be anywhere
  - We now need to store forward and backward pointers, not just sizes

Structure of a **free** block now:
| Size | 0 |
|------|---|
| Next ptr | |
| Prev ptr | |
| | |
| **Size** | **0** |

##### Freeing with free lists
Insertion Policy:
- **LIFO (last-in-first-out) policy:** Insert freed block at the beginning of the free list
  - **+ve:** simple and constant time, even with coalescing
  > When freeing with LIFO, always coalesce when possible

- **Address-ordered policy:**
  - Insert freed blocks so that free list blocks are always in address order:
  > addr(prev) < addr(curr) < addr(next)
  - **-ve:** requires linear-time search
  - **+ve:** studies suggest fragmentation is lower than LIFO

#### Segregated free list
- Different free list for different size classes
##### Segregated List (Seglist) Allocators
- Each **size class** (blocks of size 3, 5-8, 9-inf ...) of blocks has its own free list

- Given an array of free lists, each one for some size class
- To allocate a block of size $n$:
  - Search appropriate free list for block of size $m\ge n$
  - If appropriate block is found: Split block and place fragment on appropriate list (opt)
  - If no block found, try next larger class
  - Repeat until block is found

- If no block found:
  - Request additional heap memory from OS
  - Allocate block of $n$ bytes from this new memory
  - Place remainder as a single free block in appropriate size class

- To free block: Coalesce and place on appropriate list (opt)

##### Buddy Systems
- Each class a power of two. Start with heap of size $2^m$. All classes empty, except class $m$ containing a single block of size $2^m$
- Allocate block of size $2^k$
  - Find free block of size $2^j$ where $k\le j \le m$
  - If $j=k$ then done
  - Otherwise, slit block in half recursively, putting the remaining halfs ("buddies" ) on the appropriate free lists
- **Freeing:** Recursively coalesce with free buddies until no longer possible
> If A is freed and A is 32bit, and it has a buddy (free space of 32bit) we coalesque.
> Now it is 64 bits, see if there is a free buddy...

##### Key Allocator Policies
- Free block organization
- Placement policy:
  - First-fit, next-fit, best-fit, etc.
  - Trades off lower throughput for less fragmentation
- Coalescing policy:
  - **Immediate coalescing:** coalesce each time `free` is called
  - **Deferred coalescing:**
    - Coalesce as you scan the list for `malloc`
    - Coalesce when the amount of external fragmentation reaches threshold

##### Garbage Collection: Mark-and-sweep collecting
- When out of space:
  - Use extra **mark bit** in the head of each block
  - **Mark:** start at roots and set mark bit on each reachable block
  - **Sweep:** Scan all blocks and free blocks that are not marked

### CH10: System I/O

- `int open(const char *path, int oflags);` Unix processes begin life with open descriptors assigned to stdin (descriptor 0),
stdout (descriptor 1), and stderr (descriptor 2). The open function always returns the lowest unopened descriptor

- `fork()`: Recall that **the child inherits the parent’s descriptor table** and that all processes shared the same open file table

- `ssize_t read(int fd, void *buf, size_t count);`: On success, the number of bytes read is returned (zero indicates end of file), and the file position is advanced by this number.

- `int dup2(int oldfd, int newfd);`: the file descriptor newfd is adjusted so that it now refers to the same open file description as oldfd.
> Example: o redirect standard input (descriptor 0) to descriptor 5, we would call dup2(5,0), or equivalently, dup2(5,STDIN_FILENO).