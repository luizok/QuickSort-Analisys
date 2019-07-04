#include <stdlib.h>
#include "utils.h"
#include "partition.h"
#include "badinstance.h"


int escrever_instancia(int *v, int n) {
        int i;
        int *pos = (int*) malloc(n * sizeof(int));
        if(pos == NULL)
            return 1;

        for (i = 0; i < n; ++i) pos[i] = i;

        for (i = n-1; i != -1; --i)
        {
        int p = escolher_pivo(0, i);  v[ pos[p] ] = i;

        swap( &pos[p], &pos[0] );  swap( &pos[0], &pos[i] );
        }

        return 0;
}