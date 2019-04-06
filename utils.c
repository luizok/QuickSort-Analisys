#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int randInt(int min, int max) {

    int r = min + rand() % (max - min);

    return r;
}

int* generateIntArray(int n, int min, int max) {

    int *arr = (int*) malloc(n * sizeof(int));

    for(int i=0; i < n; i++)
        arr[i] = randInt(min, max);

        return arr;
}

void printArray(int *arr, int n) {

    for(int i=0; i < n; i++)
        printf("%d  ", arr[i]);
    
    printf("\n");
}

int isSorted(int *arr, int n) {

    for(int i=0; i < n-1; i++)
        if(arr[i] > arr[i+1])
            return 0;

    return 1;
}
