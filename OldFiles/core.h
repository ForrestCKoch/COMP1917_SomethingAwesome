#ifndef CORE_H
#define CORE_H

#include "modules.h"
#include "algorithms.h"

typedef struct _threadStruct{
    SortFunc sort;
    CmpFunc cmp;
    int cycles;
    int numElmnts;
    int dataSize;
    void *array;
} ThreadStruct;

void createJob(char *input, char *output, int threads,
	       SortFunc sort, dataStruct *modData);

void *splitArray(void *threadData);

void insertSort(ThreadStruct *ouput, ThreadStruct *inputOne,
		ThreadStruct *inputTwo);
#endif
