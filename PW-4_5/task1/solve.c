#include <math.h>
#include "solve.h"

void solve(double a, double b, double c, double * x1, double * x2, int * t) {
    double d;
    * t = 0;

    if (a != 0) * t += 100;
    if (b != 0) * t += 10;
    if (c != 0) * t += 1;

    switch ( * t) {
        case 100:
        case 101:
        case 110:
        case 111:
            d = b * b - 4 * a * c;
            if (d >= 0) {
                * x1 = (-b - sqrt(d)) / (2 * a);
                * x2 = (-b + sqrt(d)) / (2 * a);
                * t = 1;
            } else {
                * x1 = -b / (2 * a);
                * x2 = sqrt(-d) / (2 * a);
                * t = 2;
            }
            break;
        case 10:
        case 11:
            * x1 = -c / b;* x2 = 1.0 / 0;* t = 0;
            break;
        default:
            * x1 = 1.0 / 0;* x2 = 1.0 / 0;* t = -1;
    }
}
