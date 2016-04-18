#include <stdio.h>
#include <stdlib.h>

#include "core.h"
#include "modules.h"
#include "algorithms.h"

void createJob(char *input, char *output, int threads,
	       SortFunc sort, dataStruct *modData){
    
    FILE *inputFile;
    FILE *outputFile;
    void *array;
    int numElmnts;

    inputFile = fopen(input, "r");
    if(inputFile == NULL){
	printf("Could not open file: %s\n", input);
	exit(1);
    }
    
    numElmnts = modData->getAmount(inputFile);

    array = malloc(numElmnts * modData->dataSize);

    modData->fillArray(inputFile, numElmnts, array);
    fclose(inputFile);

    threadedSort(sort, modData->cmp, threads, array, 
		 numElmnts, modData->dataSize);

    outputFile = fopen(output, "w");
    if(outputFile == NULL){
	printf("Could not open file: %s\n", output);
	exit(1);
    }

    modData->writeFile(outputFile, numElmnts, array);
    free(array);
    array = NULL;
    fclose(outputFile);
    outputFile = NULL;
}

void threadedSort(SortFunc sort, CmpFunc cmp, int threads, void *array,
		  int numElmnts, int dataSize){
    
    sort(array, numElmnts, dataSize, cmp);
}
