#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "utils.h"
#include "qsort.h"
#include "badinstance.h"


void calcTime(int *backup, int *arr, int n, int iterType, int recType, int pivot, char *alg) {

    clock_t begin, end;
    double diff;
    memcpy(arr, backup, n * sizeof(int));

    begin = clock();
    quickSort(arr, n, iterType, recType, pivot);
    end = clock();

    diff = ((double)(end - begin)) / CLOCKS_PER_SEC;

    printf("%32s executado em %f's, esta ordernado? %s\n", alg, diff, isSorted(arr, n) ? "TRUE" : "FALSE");
}


int main(int argc, char **argv) {

    srand(time(NULL));

    int instance;
    int n, min, max;
    int *backup;
    int *arr;

    printf("Que tipo de instancia voce deseja?\n");
    printf("0 - Aleatorio\n1 - Pior caso\n");
    scanf("%d", &instance);

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if(instance == 0) {

        printf("Digite o valor minimo e maximo, respectivamente: ");
        scanf("%d %d", &min, &max);

        backup = generateIntArray(n, min, max);
    } else if(instance == 1) {

        backup = (int*) malloc(n * sizeof(int));
        escrever_instancia(backup, n);

        printArray(backup, n);
    }

    arr = (int*) malloc(n * sizeof(int));

    // Pointers
    calcTime(backup, arr, n, POINTER, -1, -1, "Pointers");

    // Index last element
    calcTime(backup, arr, n , INDEX, REC, LAST, "Index (last element)");

    // Middle element
    calcTime(backup, arr, n , INDEX, REC, MID, "Index (middle element)");

    // Median of Median
    calcTime(backup, arr, n , INDEX, REC, MD5, "Index (Median of Median)");

    // random
    calcTime(backup, arr, n , INDEX, REC, RAND, "Index (random)");

    // Tail recursion
    calcTime(backup, arr, n , INDEX, TAIL, -1, "Index (tail recursion)");


    return EXIT_SUCCESS;
}