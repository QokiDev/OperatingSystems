#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main(int argc, char * argv[]) {
    if (argc != 4) {
        printf("Error!!! You must invoke: task1 a b c\n");
        exit(EXIT_FAILURE);
    } else {
        double a, b, c, sol1, sol2;
        int type;

        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);

        solve(a, b, c, & sol1, & sol2, & type);

        switch (type) {
            case -1:
                printf("This is not equation\n");
                break;
            case 0:
                printf("Linear equation. x = %g\n", sol1);
                break;
            case 1:
                printf("Quadratic equation. x1 = %g, x2 = %g\n", sol1, sol2);
                break;
            case 2:
                printf("Quadratic equation. x = %g + I %g\n", sol1, sol2);
                break;
            default:
                fprintf(stderr, "\t%s\n", "Wrong Solution Selector");
        }
    }

    return EXIT_SUCCESS;
}
