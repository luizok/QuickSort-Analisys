#include <stdlib.h>
#include "utils.h"
#include "partition.h"


void quickSort(int *arr, int n, int type);
void _quickSortIndex(int *arr, int begin, int end);
void _quickSortPointer(int *begin, int *end);

void quickSort(int *arr, int n, int type) {

    if(type == INDEX)
        _quickSortIndex(arr, 0, n-1);
    else if(type == POINTER)
        _quickSortPointer(arr, arr + n);
}

void _quickSortIndex(int *arr, int begin, int end) {

    if(begin < end) {
        int pivot = partitionLomutoIndex(arr, begin, end);
        _quickSortIndex(arr, begin, pivot-1);
        _quickSortIndex(arr, pivot+1, end);
    }
}

void _quickSortPointer(int *begin, int *end) {

    if(begin < end) {

        int *pivot = partitionLomutoPointer(begin, end);
        _quickSortPointer(begin, pivot-1);
        _quickSortPointer(pivot+1, end);
    }
};
