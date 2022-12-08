#ifndef OPERATING_SYSTEM_INTEGR_H
#define OPERATING_SYSTEM_INTEGR_H

double integrate(double (*f)(double x), double a, double b, unsigned long n);
double NIntegrate(double (*f)(double x), double a, double b, double eps);

#endif
