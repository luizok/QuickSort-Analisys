#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "qsort.h"


int main(int argc, char **argv) {

    srand(time(NULL));
    int n = 20;
    int *arr = generateIntArray(n, 0, n);

    printArray(arr, n);
    printf("Array is sorted? %d\n", isSorted(arr, n));
    quickSort(arr, n, INDEX, REC);
    printArray(arr, n);
    printf("Array is sorted? %d\n", isSorted(arr, n));

    return EXIT_SUCCESS;
}