#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char ** argv) {
    int opt;
    char * file_name = NULL;
    int specific = 0;

    while (opt = getopt(argc, argv, "ho:c")) != -1 {
        switch (opt) {
            case 'h':
                printf("Help string\n");
                exit(EXIT_SUCCESS);
            case 'c':
                specific = 1;
                break;
            case 'o':
                file_name = optarg;
                break;
            case '?':
                fprintf(stderr, "Unknown option ignored\n");
                break;
            default:
                fprintf(stderr, "Unknown error!\n");
                exit(EXIT_FAILURE);
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "Error! No input files found!\n");
        exit(EXIT_FAILURE);
    }

    printf("Output file: ");

    if (file_name == NULL) {
        printf("a.out\n");
    } else {
        printf("%s\n", file_name);
    }

    if (specific) {
        printf("Specific work regime\n");
    } else {
        printf("Ordinary work regime\n");
    }

    {
        int i;
        for (i = optind; i < argc; i++)
            printf("\tInput file: %s\n", argv[i]);
    }

    return EXIT_SUCCESS;
}
