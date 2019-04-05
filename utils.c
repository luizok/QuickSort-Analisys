#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int* generateIntArray(int n, int min, int max) {

    int *arr = (int*) malloc(n * sizeof(int));

    for(int i=0; i < n; i++)
        arr[i] = min + rand() % (max - min);

        return arr;
}

void printArray(int *arr, int n) {

    for(int i=0; i < n; i++)
        printf("%d  ", arr[i]);
    
    printf("\n");
}

int randPivot(int begin, int end) {

    int r = begin + rand() % (end - begin);

    return r;
}