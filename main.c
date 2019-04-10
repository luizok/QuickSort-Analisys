#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "qsort.h"


int main(int argc, char **argv) {

    srand(time(NULL));

    int n, min, max;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    printf("Digite o valor minimo e maximo, respectivamente: ");
    scanf("%d %d", &min, &max);

    int *arr = generateIntArray(n, min, max);

    int idxPtr = -1;
    int recTail = -1;
    int pivot = -1;

    while(idxPtr != 0 && idxPtr != 1) {
        printf("\n0 - Via indices\n1 - Via ponteiros\n: ");
        scanf("%d", &idxPtr);
    
        if(idxPtr == 1)
            quickSort(arr, n, POINTER, -1);

        else if(idxPtr == 0) {
            while(recTail != 0 && recTail != 1) {
                printf("\n0 - Recursiva\n1 - Chamada de cauda\n: ");
                scanf("%d", &recTail);

                if(recTail == 0) {
                    while(!(0 <= pivot && pivot <= 3)) {
                        printf("\nPivo: \n");
                        printf("0 - Ultimo elemento\n");
                        printf("1 - Elemento do meio\n");
                        printf("2 - Mediana das medianas\n");
                        printf("3 - Aleatorio\n");

                        scanf("%d", &pivot);
                    }

                    quickSort(arr, n , INDEX, pivot);

                } else if(recTail == 1)
                    quickSort(arr, n, POINTER, TAIL);

                else
                    printf("Opcao invalida\n");
            }

        } else
            printf("Opcao invalida\n");
    }

    printArray(arr, n);
    printf("Vetor esta ordenado (x[i] <= x[i+1])? %d\n", isSorted(arr, n));

    return EXIT_SUCCESS;
}