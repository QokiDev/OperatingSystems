#ifndef OPERATING_SYSTEM_TASK_H
#define OPERATING_SYSTEM_TASK_H

#include "tarray.h"

typedef struct {
    int num_readers;
    int num_writers;
    int num_reps;
    TARRAY * arr;
} TPARAM;

void task_solution(TPARAM * init);

#endif //OPERATING_SYSTEM_TASK_H
