#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// f(x)=exp(−∣x∣)sin(x)
double f(double x) {
    return exp(-1 * fabs(x)) * sin(x);
}

// g(x)=exp(−∣x∣)cos(x)
double g(double x) {
    return exp(-1 * fabs(x)) * cos(x);
}

int main() {
    double x;

    printf("Enter the number: ");
    scanf("%lf", & x);

    printf("f(%lf) = %.5lf\n", x, f(x));
    printf("g(%lf) = %.5lf\n\n", x, g(x));

    return 0;
}
