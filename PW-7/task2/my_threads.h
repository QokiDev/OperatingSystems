#ifndef OPERATING_SYSTEM_MY_THREADS_H
#define OPERATING_SYSTEM_MY_THREADS_H

typedef struct arg_str {
    int n;
    double a, b, eps;
    double (*f)(double);
} TARG;

double Thread_NIntegrate(const TARG * arg);

#endif
