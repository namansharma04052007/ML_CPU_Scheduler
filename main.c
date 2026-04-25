#include <stdio.h>
#include "scheduler.h"

int main() {

    Process p[] = {
        {1, 5, 0},
        {2, 12, 0},
        {3, 7, 0},
        {4, 20, 0},
        {5, 3, 0},
        {6, 15, 0}
    };

    int n = sizeof(p) / sizeof(p[0]);

    printf("===== INPUT PROCESSES =====\n");
    for (int i = 0; i < n; i++) {
        printf("PID %d | Burst Time %d\n", p[i].pid, p[i].burst_time);
    }

    round_robin(p, n);
    ml_scheduler(p, n);

    return 0;
}