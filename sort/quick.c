#include <stdio.h>

#include "sort.h"
static void swap(Itm *a, Itm *b) {
    Itm tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * arr[i] is the last element smaller than pivot
 * arr[j] is the first unknown element (not split)
 * arr[++i] is the first element larger than pivot
 */
static int partition(Itm *arr, int p, int r) {
    int j, i = p - 1;

    for (j = p; j < r; j++)
        if(arr[j] <= arr[r])
            swap(arr + ++i, arr + j);

    swap(arr+i+1, arr+r);
    return i+1;
}

static void quick_sort_f(Itm *arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quick_sort_f(arr, p, q-1);
        quick_sort_f(arr, q+1, r);
    }
}

static void quick_sort(Itm *arr, int len) {
    quick_sort_f(arr, 0, len - 1);
}

REGISTER_SORT(quick_sort);
