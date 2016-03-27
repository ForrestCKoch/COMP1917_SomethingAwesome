#ifndef CORE_H
#define CORE_H

#include "modules.h"
#include "algorithms.h"

void createJob(char *input, char *output, int threads,
	       SortFunc sort, dataStruct *modData);

void threadedSort(SortFunc sort, CmpFunc cmp, int threads, void *array,
		  int numElmnts, int dataSize);
#endif
