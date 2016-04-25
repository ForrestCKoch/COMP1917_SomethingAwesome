#include <stdio.h>
#include <stdlib.h>

#include "core.h"
#include "modules.h"
#include "algorithms.h"

void createJob(char *input, char *output, int threadPower,
	       SortFunc sort, dataStruct *modData){
    
    FILE *inputFile;
    FILE *outputFile;
    void *array;
    int numElmnts;
    ThreadStruct *threadData;

    inputFile = fopen(input, "r");
    if(inputFile == NULL){
	printf("Could not open file: %s\n", input);
	exit(1);
    }
    
    numElmnts = modData->getAmount(inputFile);

    array = malloc(numElmnts * modData->dataSize);

    modData->fillArray(inputFile, numElmnts, array);
    fclose(inputFile);

    //fill threadData
    threadData = (ThreadStruct *)malloc(sizeof(ThreadStruct));
    threadData->sort = sort;
    threadData->cmp = modData->cmp;
    threadData->cycles = threadPower;
    threadData->numElmnts = numElmnts;
    threadData->dataSize = modData->dataSize;
    threadData->array = array;

    //special case if we don't need to bother splitting up
    if(!threadPower){
	sort(array, numElmnts, modData->dataSize, modData->cmp);
    }
    else{
	//This is where all the action is!
	splitArray(threadData);
    }

    outputFile = fopen(output, "w");
    if(outputFile == NULL){
	printf("Could not open file: %s\n", output);
	exit(1);
    }

    modData->writeFile(outputFile, numElmnts, array);
    free(array);
    array = NULL;
    free(threadData);
    threadData = NULL;
    fclose(outputFile);
    outputFile = NULL;
}

void splitArray(ThreadStruct *threadData){

    if(cycles){
	//divide up and have sorted
	ThreadStruct threadOne;
	ThreadStruct threadTwo;
	void *arrayOne;
	void *arrayTwo;

	//Keep track of how many elements in each array
	int numOne;
	int numTwo;

	pthread_t threadOne;
	pthread_t threadTwo;

	numOne = numElmnts / 2;
	if(numElmnts % 2){
	    numTwo = numOne + 1;
	} else{
	    numTwo = numOne
	}

	assert(numOne + numTwo = numElmnts);
	
	arrayOne = (void *)malloc(numOne * dataSize);
	arrayTwo = (void *)malloc(numTwo * dataSize);
	
	//copy first half of array into arrayOne
	memcpy(array, arrayOne, numOne * dataSize);
	//copy second half of array into arrayTwo
	memcpy((array + (numOne * dataSize)), arrayTwo, numTwo * dataSize);

	pthread_create(&threadOne, NULL, splitArray, (void*)/*THREADSTRUCT*/);

// PICK UP FROM HERE


