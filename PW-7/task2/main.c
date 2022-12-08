#include <stdio.h>
#include <stdlib.h>

#define ONE_THREAD
#undef ONE_THREAD

#ifdef ONE_THREAD
#include "integr.h"
#else
#include "my_threads.h"
#endif

double fun(double x) {
    return 4.0 - x*x;
}

int main(void) {
    double res;
    printf("Integral Calculation\n");
#ifdef ONE_THREAD
    printf("Test Application without Threads\n");
	res = NIntegrate(fun, 0.0, 2.0, 1.0e-6);
#else
    printf("Threaded Application\n");
    {
        TARG arg = {5, 0.0, 2.0, 1.0e-6, fun};
        res = Thread_NIntegrate(&arg);
    }
#endif
    printf("\tRes: %g\n", res);

    return EXIT_SUCCESS;
}
