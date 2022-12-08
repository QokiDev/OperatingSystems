#include "function_f.h"
#include "function_g.h"
#include <stdio.h>

int main() {
    double x;

    printf("Enter the number: ");
    scanf("%lf", & x);

    printf("f(%lf) = %.5lf\n", x, f(x));
    printf("g(%lf) = %.5lf\n\n", x, g(x));

    return 0;
}
