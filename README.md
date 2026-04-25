# ML-Based CPU Scheduling Simulator in C

## Description
This project simulates CPU scheduling algorithms in an Operating System using C. It compares Round Robin scheduling with an ML-inspired scheduling approach that prioritizes short jobs first.

## OS Concepts Used
- CPU Scheduling
- Process Management
- Burst Time Scheduling
- Scheduling Optimization

## Approach
Processes are classified based on burst time:
- Short jobs (≤ 10 units)
- Long jobs (> 10 units)

ML-inspired scheduling executes short jobs first, improving response time for smaller tasks.

## How to Compile and Run

```bash
gcc main.c scheduler.c -o scheduler
./scheduler