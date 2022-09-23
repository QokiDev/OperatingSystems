#include <math.h>
#include <stdlib.h>

// f(x)=exp(−∣x∣)sin(x)
double f(double x) {
    return exp(-1 * fabs(x)) * sin(x);
}
