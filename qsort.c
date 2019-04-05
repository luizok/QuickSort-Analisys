#include "utils.h"


void quickSort(int *arr, int n);
void _quickSort(int *arr, int begin, int end);
int partitionLomuto(int *arr, int begin, int end);


void quickSort(int *arr, int n) {

    _quickSort(arr, 0, n-1);
}

void _quickSort(int *arr, int begin, int end) {

    if(begin < end) {
        int pivot = partitionLomuto(arr, begin, end);
        _quickSort(arr, begin, pivot-1);
        _quickSort(arr, pivot+1, end);
    }
}

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