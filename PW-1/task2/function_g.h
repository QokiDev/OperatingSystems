#include <math.h>
#include <stdlib.h>

// g(x)=exp(−∣x∣)cos(x)
double g(double x) {
    return exp(-1 * fabs(x)) * cos(x);
}
