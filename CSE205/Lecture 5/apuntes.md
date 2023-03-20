### Lecture 3 - Speeding Up with Pipelining

#### The SEQ processor

- **Implementation:**
    - Express every instruction as series of simple steps
    - Follow same general flow for each instruction type
    - Built from registers, memories, predesdigned combos

#### Pipelinning
Split the fetch, execute cycle in independent stages

- Use this idea to speed up a processor
  - Reduce circuit depth and thus stabilization time
  - Allows faster clocking
  - Multiple circuit "stages" operate in parallel
  - Overall faster throughput: instructions/second