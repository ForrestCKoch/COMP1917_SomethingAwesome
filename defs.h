#ifndef DEFS_H
#define DEFS_H

#include "Array.h"

typedef void (*CmpFunc)(const void * a, const void * b);
typedef void (*SortFunc)(void *array, size_t num, size_t size, CmpFunc cmp);

void sortArray(size_t depth, Array, SortFunc, CmpFunc);


#endif
