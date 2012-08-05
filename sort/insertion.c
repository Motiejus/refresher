#include "sort.h"

static void swap(Itm *a, Itm *b) {
    Itm tmp = *a;
    *a = *b;
    *b = tmp;
}

static void insertion_sort(Itm *arr, int len) {
    int i, j;

    for(i = 0; i < len; i++)

        for (j = i; j > 0; j--)
            if (arr[j] < arr[j-1])
                swap(&arr[j-1], &arr[j]);
            else
                break;
}

REGISTER_SORT(insertion_sort);
