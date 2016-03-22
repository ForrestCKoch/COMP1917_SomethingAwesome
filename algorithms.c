#include <stdlib.h>
#include "algorithms.h"

void myQsort(void *arry, int numElements, int sizeElements, 
	     int (*cmpFunc)(const void * a, const void * b)){

    qsort(arry, numElements, sizeElements, cmpFunc);
}
