#include "utils.h"


int partitionLomutoIndex(int *arr, int begin, int end) {

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

// int partitionHoare(int *arr, int begin, int end) {

//     int pivot = arr[end];
//     int i = begin;
//     int j = end;

//     while(i <= j) {
//         while(arr[i] < pivot) i++;
//         while(arr[j] > pivot) j--;

//         if(i <= j) {
//             swap(&arr[i], &arr[j]);
//             i++;
//             j--;
//         }

//         return i;
//     }
// }

int choosePivot(int begin, int end, int type) {

    switch(type) {
        case LAST: return end;
        case MID:  return begin + (end - begin) / 2;
        case MD5:  return 0; // medianOfmedians();
        case RAND: return randInt(begin, end);
    }
}