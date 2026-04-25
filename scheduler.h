#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "processes.h"

void round_robin(Process p[], int n);
void ml_scheduler(Process p[], int n);

#endif