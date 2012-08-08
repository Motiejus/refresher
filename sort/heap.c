#include "sort.h"

static void swap(Itm *a, Itm *b) {
    Itm tmp = *a;
    *a = *b;
    *b = tmp;
}

static void max_heapify(Itm *arr, int i, int len) {
    int max = i;

    if (i*2   <= len && arr[i*2]   > arr[max]) max = i*2;
    if (i*2+1 <= len && arr[i*2+1] > arr[max]) max = i*2+1;

    if (i != max) {
        swap(arr + i, arr + max);
        max_heapify(arr, max, len);
    }
}

static void heap_sort(Itm *arr, int len) {
    int i;
    Itm *arr2 = arr;
    arr2--; /* heapify 1-based array */
    for (i = len/2; i >= 1; i--)
        max_heapify(arr2, i, len);

    /* heap sort */
    for (i = len; i >= 2; i--) {
        swap(arr2 + 1, arr2 + i);
        max_heapify(arr2, 1, i-1);
    }
}

REGISTER_SORT(heap_sort);
