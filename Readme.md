# Linux GPU-Aware Task Scheduler

## Overview
This project implements a user-space, GPU-aware task scheduler in C++, inspired by Linux OS scheduling and heterogeneous computing concepts.  

It demonstrates how tasks can be scheduled and routed between CPUs and GPUs based on workload characteristics. GPU execution is simulated to focus on scheduling logic, not kernel optimization.  

## Features  
- Shortest Job First Scheduling used 
- Multi-core CPU executor  
- Simulated GPU executor  
- CPU vs GPU task routing  
- Thread-safe run queue using mutexes and condition variables  
- OS-inspired design    

## Architecture  

           Task Submission
                  |  
                  v  
        +----------------------+  
        |  Scheduler Queue     |  
        | (Priority Run Queue) |   
        +----------------------+  
           |              |  
           v              v  
+----------------+   +------------------+  
|  CPU Executor  |   |   GPU Executor   |  
| (Thread Pool)  |   | (Simulated GPU)  |  
+----------------+   +------------------+     

## Scheduling Policy  
- Each task has a type (CPU or GPU) and an estimated cost  
- Shortest Job First (SJF) policy determines execution order
- CPU-bound tasks run on CPU worker threads
- GPU-bound tasks run on the GPU executor thread

## Concepts Demonstrated  
- Linux scheduling fundamentals  
- Thread pools & concurrency  
- Condition variables & mutexes  
- Accelerator-aware scheduling  
- System software design patterns    

## Build & Run
```bash
make
./build/scheduler
