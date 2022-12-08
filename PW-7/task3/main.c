#include <stdio.h>
#include <stdlib.h>
#include "task.h"


int main(void) {
    int array_size = 5;
    printf("Read/Write Lock\n");
    {
        TPARAM init;
        TARRAY arr;
        tarray_init(&arr, array_size);
        init.arr = &arr;
        init.num_readers = 4;
        init.num_writers = 3;
        init.num_reps = 10;
        task_solution(&init);
        tarray_dest(&arr);
    }

    printf("\n\nNext Session...\n");
    array_size = 4;
    {
        TPARAM init;
        TARRAY arr;
        tarray_init(&arr, array_size);
        init.arr = &arr;
        init.num_readers = 3;
        init.num_writers = 2;
        init.num_reps = 5;
        task_solution(&init);
        tarray_dest(&arr);
    }

    return EXIT_SUCCESS;
}
