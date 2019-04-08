#include "utils.h"

#include <stdio.h>



int medianOfMedians(int *arr, int begin, int end) {

    int n = end - begin;
    int mod5 = n % 5;
    int div5 = n / 5;

    if(n < 2) {
        printArray(arr, n);
        return 0;
    }

    int i;
    for(i=0; i < div5; i++) {
        selectionSort(&arr[5 * i], n >= 5 ? 5 : mod5);
        swap(&arr[i], &arr[5 * i + 2]);
    }

    if(n % 5 != 0) {
        selectionSort(&arr[5 * div5], mod5);
        swap(&arr[i], &arr[5 * div5 + mod5 / 2]);
    }

    printArray(arr, n);

    return medianOfMedians(arr, 0, div5 + (mod5 ? 1 : 0));
}

int choosePivot(int *arr, int begin, int end, int type) {

    switch(type) {
        case LAST: return end;
        case MID:  return begin + (end - begin) / 2;
        case MD5:  return medianOfMedians(arr, begin, end);
        case RAND: return randInt(begin, end);
    }
}

int partitionLomutoIndex(int *arr, int begin, int end) {

    int pivot = medianOfMedians(arr, begin, end);
    int i = begin;

    for(int j=begin; j < end; j++)
        if(arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }

    swap(&arr[i], &arr[end]);

    return i;
}

int *partitionLomutoPointer(int *begin, int *end) {

    int *pivot = end;
    int *lower = begin;

    for(int *addr=begin; addr != end; addr++)
        if(*addr <= *pivot) {
            swap(addr, lower);
            lower++;
        }

    swap(lower, end);

    return lower;
};

int partitionHoare(int *arr, int begin, int end) {

    int pivot = arr[begin + (end - end) / 2];
    int i = begin - 1;
    int j = end + 1;

    while(1) {
        do { i++; } while(arr[i] < pivot);
        do { j--; } while(arr[j] > pivot);

        if(i >= j) return j;

        swap(&arr[i], &arr[j]);
    }
}