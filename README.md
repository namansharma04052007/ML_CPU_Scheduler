# ML-Based CPU Scheduling Simulator in C

## 1. Project Title
ML-Based CPU Scheduling Simulator in C

---

## 2. Problem Statement
Traditional CPU scheduling algorithms like Round Robin do not consider process burst characteristics while deciding execution order. This can lead to increased waiting time for short processes. The goal of this project is to simulate an improved scheduling approach using a simple ML-inspired decision mechanism.

---

## 3. Objective
To implement and compare:
- Round Robin Scheduling (baseline OS algorithm)
- ML-inspired scheduling that prioritizes short jobs first

and analyze their performance in terms of execution order and total completion time.

---

## 4. Concepts Used
- CPU Scheduling (Operating System)
- Process Management
- Burst Time Analysis
- Heuristic-based ML-inspired classification
- C Programming (Structures and Arrays)

---

## 5. Approach / Working
1. A set of processes is defined with PID, burst time, and arrival time.
2. Round Robin scheduling executes processes in input order.
3. ML-inspired scheduler classifies processes:
   - Short jobs (burst time ≤ 10)
   - Long jobs (burst time > 10)
4. Short jobs are executed first in sorted order, followed by long jobs.
5. Execution order and total completion time are displayed.

---

## 6. How to Compile and Run

Use GCC compiler:

```bash
gcc main.c scheduler.c -o scheduler
./scheduler
