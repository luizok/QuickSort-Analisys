#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "qsort.h"


int main(int argc, char **argv) {

    int n = 30;
    int *arr = generateIntArray(n, 0, n);

    printArray(arr, n);
    quickSort(arr, n);
    printArray(arr, n);

    return EXIT_SUCCESS;
}