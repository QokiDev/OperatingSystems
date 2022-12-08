#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

long int val = 0;

void *increment(void *arg) {
    long i, num = *((long *)arg);
    for (i = 0; i < num; i++) {
        val += 1;
    }

    return NULL;
}

void *decrement(void *arg) {
    long i, num = *((long *)arg);
    for (i = 0; i < num; i++) {
        val -= 1;
    }

    return NULL;
}

int main() {
    pthread_t id1, id2;
    long n;
    printf("Enter n: ");
    scanf("%ld", &n);

    printf("Before: %ld\n", val);
    printf("Start ScoreThreads...\n");

    if (pthread_create(&id1, NULL, increment, (void*)&n)) {
        fprintf(stderr, "ERROR! Cannot Create Thread\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&id2, NULL, decrement, (void*)&n)) {
        fprintf(stderr, "ERROR! Cannot Create Thread\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    printf("After: %ld\n", val);

    return 0;
}
