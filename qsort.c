#include "utils.h"


void quickSort(int *arr, int n, int type);
void _quickSortIndex(int *arr, int begin, int end);
void _quickSortPointer(int *begin, int *end);
int partitionLomuto(int *arr, int begin, int end);


void quickSort(int *arr, int n, int type) {

    if(type == INDEX)
        _quickSortIndex(arr, 0, n-1);
    else if(type == POINTER)
        _quickSortPointer(arr, arr + n);
}

void _quickSortIndex(int *arr, int begin, int end) {

    if(begin < end) {
        int pivot = partitionLomuto(arr, begin, end);
        _quickSortIndex(arr, begin, pivot-1);
        _quickSortIndex(arr, pivot+1, end);
    }
}

void _quickSortPointer(int *begin, int *end) {};

int partitionLomuto(int *arr, int begin, int end) {

    int pivot = arr[end];
    int i = begin;

    for(int j=begin; j < end; j++)
        if(arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }

    swap(&arr[i], &arr[end]);

    return i;
}