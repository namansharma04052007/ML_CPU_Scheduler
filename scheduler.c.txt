#include <stdio.h>
#include "scheduler.h"

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

/*
 "ML-inspired prediction"
 We classify processes based on burst time:
 - short job: burst <= 10
 - long job: burst > 10
 This mimics a learned scheduling policy.
*/

int is_short_job(Process p) {
    return p.burst_time <= 10;
}

/* ROUND ROBIN (simplified simulation, no time quantum complexity) */
void round_robin(Process p[], int n) {
    printf("\n===== ROUND ROBIN SCHEDULING =====\n");

    int time = 0;
    for (int i = 0; i < n; i++) {
        printf("PID %d | BT %d | Start %d | End %d\n",
               p[i].pid,
               p[i].burst_time,
               time,
               time + p[i].burst_time);

        time += p[i].burst_time;
    }

    printf("Total Completion Time: %d\n", time);
}

/* ML-INSPIRED SCHEDULING (Short Job First + grouping) */
void ml_scheduler(Process p[], int n) {
    printf("\n===== ML-INSPIRED SCHEDULING =====\n");

    Process short_jobs[100], long_jobs[100];
    int s = 0, l = 0;

    // classify processes
    for (int i = 0; i < n; i++) {
        if (is_short_job(p[i]))
            short_jobs[s++] = p[i];
        else
            long_jobs[l++] = p[i];
    }

    // sort short jobs (SJF style)
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            if (short_jobs[i].burst_time > short_jobs[j].burst_time) {
                swap(&short_jobs[i], &short_jobs[j]);
            }
        }
    }

    int time = 0;

    // execute short jobs first
    for (int i = 0; i < s; i++) {
        printf("PID %d | BT %d | Start %d | End %d\n",
               short_jobs[i].pid,
               short_jobs[i].burst_time,
               time,
               time + short_jobs[i].burst_time);

        time += short_jobs[i].burst_time;
    }

    // then long jobs
    for (int i = 0; i < l; i++) {
        printf("PID %d | BT %d | Start %d | End %d\n",
               long_jobs[i].pid,
               long_jobs[i].burst_time,
               time,
               time + long_jobs[i].burst_time);

        time += long_jobs[i].burst_time;
    }

    printf("Total Completion Time: %d\n", time);
}