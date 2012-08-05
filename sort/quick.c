#include <stdio.h>

#include "sort.h"
static void swap(Itm *a, Itm *b) {
    Itm tmp = *a;
    *a = *b;
    *b = tmp;
}

static int partition(Itm *arr, int left, int right) {
    int pivotIdx = left;

    printf("\nLeft: %d, Right: %d, Values: %ld %ld", left, right, *(arr + left), *(arr + right));

    while (left < right) {
        while (arr[left] <= arr[pivotIdx]) left++;
        while (arr[right] > arr[pivotIdx]) right--;
        if (left < right) swap(&arr[left], &arr[right]);
    }
    return pivotIdx;
}

static void quick_sort_f(Itm *arr, int left, int right) {
    int pivotIdx = partition(arr, left, right);
    if (left < right) {
        quick_sort_f(arr, left, pivotIdx);
        quick_sort_f(arr, pivotIdx + 1, right);
    }
}

static void quick_sort(Itm *arr, int len) {
    quick_sort_f(arr, 0, len - 1);
}

REGISTER_SORT(quick_sort);
