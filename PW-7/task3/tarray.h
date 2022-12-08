#ifndef OPERATING_SYSTEM_TARRAY_H
#define OPERATING_SYSTEM_TARRAY_H

#include <stdio.h>
#include <pthread.h>

typedef struct {
    double * res;
    int size;
    pthread_rwlock_t lock;
} TARRAY;

void tarray_init(TARRAY * arr, int num);
void tarray_dest(TARRAY * arr);
void tarray_set(TARRAY * arr, int ind, double val);
double tarray_get(TARRAY * arr, int ind);
void tarray_print(TARRAY * arr, FILE ** fptr);

#endif //OPERATING_SYSTEM_TARRAY_H
