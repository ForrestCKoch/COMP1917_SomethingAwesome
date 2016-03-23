#include <stdlib.h>
#include "algorithms.h"

void myQsort(void *arry, int numElements, int sizeElements, CmpFunc func){

    qsort(arry, numElements, sizeElements, func);
}
