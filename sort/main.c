#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int main(const int argc, const char ** argv) {
    Itm *arr;
    int i;

    if((arr = calloc(argc, sizeof(Itm))) == NULL) {
        perror("malloc");
        return 1;
    }

    for (i = 1; i < argc; i++)
        arr[i-1] = strtol(argv[i], NULL, 10);

    printf("Before: ");
    for (i = 0; i < argc - 1; i++)
        printf("%3ld ", arr[i]);

    (*sort)(arr, argc - 1);

    printf("\nResult: ");
    for (i = 0; i < argc - 1; i++)
        printf("%3ld ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
