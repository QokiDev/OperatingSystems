#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>

#define A 0
#define B 10
#define C 10
#define D 20
#define R 5

void main(int argc, char const * argv[]) {
    pid_t pid;
    int count_dots = 100000; /*2147483646*/
    char str[11];
    int result = 0;
    int check[(int)(ceil((double) count_dots / 250.0))];

    for (int i = 0; i < (int) ceil((double) count_dots / 250.0); i++) {
        pid = fork();

        if (pid == 0) {
            if ((i == (ceil((double) count_dots / 250.0) - 1)) && ((count_dots % 250) != 0))
                sprintf(str, "%i'\0'", count_dots % 250);
            else
                sprintf(str, "%i'\0'", 250);

            execlp("./d.out", "d.out", str, NULL);
            printf("%s\n", "Error");
        } else if (pid > 0) {
            if (wait( & result) == -1) {
                printf("error wait\n");
                return 1;
            }

            if (WIFEXITED(result))
                check[i] = WEXITSTATUS(result);
        }
    }

    double hits = 0;
    for (int i = 0; i < (int) ceil((double) count_dots / 250.0); i++)
        hits = hits + (double) check[i];

    double square_rect = (double)((B - A) * (D - C));
	double square_fig = (((double) hits) * square_rect) / ((double) count_dots);

    printf("Square of rectangle: %f\n", square_rect);
    printf("Square of figure: %f\n", square_fig);
    printf("Pi = %f\n", square_fig / (double)(R * R));

    return 0;
}
