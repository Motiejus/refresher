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
        arr[i] = strtol(argv[i], NULL, 10);

    (*sort)(arr, argc);

    printf("Result: ");
    for (i = 1; i < argc; i++)
        printf("%ld ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
