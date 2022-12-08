#ifndef OPERATING_SYSTEM_THREADS_H
#define OPERATING_SYSTEM_THREADS_H

#include "tarray.h"

typedef struct {
    int num_thread;
    int num_reps;
    TARRAY * arr;
} TARG;

void * write_thread(void * arg);
void * read_thread(void * arg);
void * detach_thread(void * arg);

#endif //OPERATING_SYSTEM_THREADS_H
