### CH 6: Memory hierarchy

#### Locality

- Arrays get allocated with "Row Major":  the elements of a 3D array are stored in memory row by row, plane by plane, in a contiguous block of memory.

```
arr[0][0][0]  arr[0][0][1]  arr[0][0][2]  ...  arr[0][0][Z-1]
arr[0][1][0]  arr[0][1][1]  arr[0][1][2]  ...  arr[0][1][Z-1]
.             .             .                   .
.             .             .                   .
arr[0][Y-1][0]  arr[0][Y-1][1]  arr[0][Y-1][2]  ...  arr[0][Y-1][Z-1]

arr[1][0][0]  arr[1][0][1]  arr[1][0][2]  ...  arr[1][0][Z-1]
arr[1][1][0]  arr[1][1][1]  arr[1][1][2]  ...  arr[1][1][Z-1]
.             .             .                   .
.             .             .                   .

```
- **Stride-k**: How much a program jumps around. Best is to access by order (basd on row major)

#### Cache Memories
- $M=2^m$: Computer system where each memory address has $m$ bits
- $S=2^s$: Cache sets. Each set consistes of $E$ cache lines. Each cache line has $B=2^b$ bytes ($B$ is the block size), a valid bit, and $t=m-(b+s)$  tag bits that uniquely identify the block in memory.

A cache's organisation can be characterized by the tuple:
$$(S,E,B,m)\\C=S\times E\times B\text{ which is the cache size}$$

![Cache org](../images/cse205-cache_organisation.png)

When accessing an address from cache, the following steps are taken:
1. The address is split into three fields: tag, set, and block offset.
2. The set field is used to select the set.
3. The tag field is compared with the tags of all the cache lines in the set.
4. If there is a match, the cache line is selected and the data is returned.
5. If there is no match, the cache line is selected for replacement and the data is returned. (policies for replacement vary: random, least recently used, least frequently used, et)
6. If the cache line is dirty, it is written back to memory.
7. The tag field is stored in the tag field of the cache line.
8. The valid bit is set to 1.
9. The data is stored in the cache line.


##### Direct-Mapped Caches
Caches grouped into different classes based on E
- **Direct mapped cache:** $E=1$

- **Set selection in Direct-Mapped Caches:** 
  1. Extract set index
  2. Extract the word: A copy of the word is stored in the line iff the valid bit is set and the tag matches
  3. If the tag matches, the word is returned
  4. If the tag does not match, the word is fetched from memory and stored in the line. The tag is updated and the valid bit is set to 1.

##### Fully Associatives Caches (S=1)
- A block can be stored anywhere in the cache
- Maximize use of cache memory
- Less risk of conflicts
- Finding data in cache takes more effort


- Problem 6.11
  1. Pq coño 


### CH 8: Exceptional Control Flow

#### Processes
- **Process:** An instance of a program in execution
 
- `int fork(void)`
  - Creates a new process (child) that is identical to the calling process
  - Returns 0 to the child process
  - Returns child's **pid** to the parent process
  ```c
  pid_t pid = fork();
  if (pid==0){
    printf("hello from child\n");
  }else{
    printf("hello from parent\n")
  }
  ```
> Works from the line it was executed downwards

- `int wait(int *child_status)`
  - suspends current process until one of its children terminates
  - return value is the **pid** of the child process that terminated
  - if `child_status != NULL`, then the object it points to will be set to a status indicating why the child process terminated
  ```c
  void fork9(){
    int child_status;

    int (fork()==0){
      printf("hello from child");
    }else{
      printf("hello from parent");
      wait(&child_status);
      printf("Child has terminated")
    }
  }
  ```
> If `waitpid` (wait but with process id) has as an argument `-1` then it means all child processes
> Can use `WIFEXITED` and `WEXITSTATUS` to get info abt exit status

- `int execve(char *filename, char *argv[], char *envp[])`: 
  - Loads and runs in current process:
    - Executable filename
    - With argument list argv
    - And environment variable list envp: 
  - Loads and runs in current process:
    - Executable filename
    - With argument list argv
    - And environment variable list envp
  - Does not return

##### Signals
- A **signal** is a notification sent to a process when a certain event occurs in the system

| ID Name | Default Action | Corresponding Event |
|---------|----------------|---------------------|
| 2 SIGINT | Terminate | Interrupt (ctrl-c) | 
| 9 SIGKILL | Terminate | Kill program | 
| 11 SIGSEGV | Terminate & Dump| Segmentation Violation | 
| 14 SIGALARM | Terminate | Timer signal | 
| 17 SIGCHLD | Ignore | Child stopped or terminated | 

- `int kill(pid_t pid, int sig)`: send signal to process

##### Signal handlers
- `handler_t *signal(int signum, handler_t *handler)`: The signal function modifies the default action associated with the receipt of a signal signum
  - Values of handler:
    - **SIG_ING**: Ignore signals of type signum
    - **SIG_DFL**: Revert to the default action on receipt of signals of type signum
    - Otherwise, hadnler is the address of signal handler

> Misc: `sleep()` returns the number of seconds actually slept. If it gets interrupted (since it's blocking), it will return the n of seconds slept b4 interrupt

### Ch 9: Virtual memory
- **Virtual Adressing:** The CPU accesses main memory by generating a *virtual address* (VA) which is converted to the appropriate physical address before being sent to main memory.
> Task of converting a virtual address to a phisical one knownn as **address translation**
>

- **Address space:** An ordered set of nonnegative integer addresses
$$\{0,1,2,...\}$$
> If integers are consecutive we say it is a **linear address space**

In virtual memory, CPU generates virtual addrsses fro an address space of $N=2^n$ addresses called the *virtual address space*.

- **n-bit address space:** address space with $N=2^n$ addresses

#### VM as a Tool for Caching
- **Virtual Memory:** organized as an array of $N$ contiguous byte-size cells stored on the disk.
- The contents of the array on disk are cached in **physical memory** (DRAM cache). These cache blocks are called **pages** (of $P=2^p$) bytes.

<br>

- **Unallocated:** not yet allocated by the VM system (do not occupy any space on disk)
- **Cached:** allocated pages currently cached in physical memory
- **Uncached:** allocated pages that are not cached in physical memory

##### Page Tables
- A **page table** is an array of page table entries (PTEs) that maps virtual pages to physical pages 
> Let $n$ be the virtual address size. SInce each virtual page is $P=2^p$ bytes, there are a total of $2^n/2^p=2^{n-p}$ possible pages in the system, each of which needs a page table entry (PTE)
![page talbes](../images/cse205-page_tables.png)
> We have a  valid bit indicating whether the virtual page is currently cached in DRAM

- **Page hit:** reference to VM word that is in physical memory (DRAM cache hit)
- **Page fault:** reference to VM word that is not in physical memory (DRAM cache miss)

##### Handling Page Fault
1. Page miss causes page fault (exception)
2. Page fault handler selects a victim to be evicted (random address from DRAM)
3. Offending instruction is restarted: page hit 
> Waiting until the last moment to swap a page into memory is known as **demand paging**

##### Locality to the recue
- Virtual memory works because of locality
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


Address translation is a mapping between the virtual address space (VAS) and physical address space (PAS)

$$MAP:CAS\rightarrow PAS\cup \emptyset$$
where
$$MAP(A) = \begin{cases}
A' & \text{if data at virtaul addr. A are present at physical addr. A' in PAS}\\
\emptyset & \text{ if data at virtual addr. A are not present in physical memory} 
\end{cases}$$

- The n-bit virtual address has two components:
  - a $p$-bit virtual page offset (VPO)
  - an $(n-p)$-bit virtual page number (VPN)
> Since the physical and virtual pages are both $P$ bytes, the physical page offset (PPO) is dientical to the VPO

##### Address Translation: Page hit
1. Processor sends virtual address to MMU
2. MMU requests a page taable entry address from memory
3. Page table entry is fetched from page table in memory
4. MMU sends physical address to cache/memory
5. Cache/memory sends data word to processor


##### Address Translation: Page hit
1. Processor sends virtual address to MMU
2. MMU fetches PTE from page table in memory
3. Valid bit is zero, so MMU triggers page fault exception
4. Handler identifies victim (and, if dirty, pages it out to disk) (dirty means if address occupied even with valid bit 0)
5. Handler pages in new page and updates PTE in memory
6. Handler returns to original process, restarting faulting instruction
> Lo mismo q antes no???

##### Speeding up Translation with a TLB
- Page table entries (PTEs) are cached in L1 like any other memory word
  - PTE hit requires a small L1 delay
  - PTEs may be evicted by other data references

- Solution: **Translation Lookaside buffer** (TLB)
  - Small hardware cache in MMU
  - Maps virtual page numbers to physical page numbers 
  - Contains complete page table entries for a small number of pages

![tlb](../images/cse205-TLB.png)

- $T=2^t$: number of sets in TLB


- **Process:**
  1. Extract the VPN from the virtual address.
  2. Extract TLB index & TLB tag
  3. Find PPN trhoguh the TLB
  4. Concatenate PPN from the PTE with the VPO from the virtual address (forms a physical address)
  5. Send newly created physical address to cache
  6. Extract from it the CO, CI and CT
  7. If found, then good if not, page fault