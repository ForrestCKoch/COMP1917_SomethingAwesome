#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "modules.h"

typedef void (*SortFunc)(void *arry, int numElmnts,
			 int sizeElmnts, CmpFunc cmp);
			 
SortFunc loadSort(char *alg);
void myQsort(void *arry, int numElmnts, int sizeElmnts, CmpFunc cmp);

#endif
