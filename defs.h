#ifndef DEFS_H
#define DEFS_H

#include "Array.h"

#define MODULE_DIR "/home/forrest/Documents/COMP1917/SomethingAwesome/"\
                   "COMP1917_SomethingAwesome/Modules"

/* Functions to be implemented by modules */
typedef int (*CmpFunc)(const void *a, const void *b);
typedef void (*SortFunc)(void *array, size_t num, size_t size, CmpFunc cmp);
typedef Array (*ReadFunc)(char *filename);
typedef void (*WriteFunc)(Array a, char *filename);

void sortRequestHandler(int depth, char *input, char *output, char *data, char *sort);
void sortArray(size_t depth, Array, SortFunc, CmpFunc);


#endif
