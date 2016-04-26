#include <stdio.h>
#include <stdlib.h>

#include "core.h"
#include "modules.h"
#include "algorithms.h"
#include <assert.h>
#include <string.h>
#include <pthread.h>

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

    //This is where all the action is!
    splitArray(threadData);

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

void *splitArray(void *Data){

    ThreadStruct *threadData;
    threadData = Data;

    if(threadData->cycles){
	//divide up and have sorted
	ThreadStruct *threadOne = malloc(sizeof(ThreadStruct));
	ThreadStruct *threadTwo = malloc(sizeof(ThreadStruct));

	//This should be put into a separate function
	threadOne->cycles = threadData->cycles - 1;
	threadTwo->cycles = threadData->cycles - 1;

	threadOne->dataSize = threadData->dataSize;
	threadTwo->dataSize = threadData->dataSize;

	threadOne->sort = threadData->sort;
	threadTwo->sort = threadData->sort;

	threadOne->cmp = threadData->cmp;
	threadTwo->cmp = threadData->cmp;

	pthread_t tidOne;
	pthread_t tidTwo;

	int numElmnts = threadData->numElmnts;
	int dataSize = threadData->dataSize;

	//Keep track of how many elements in each array
	threadOne->numElmnts = numElmnts / 2;
	if(numElmnts % 2){
	    threadTwo->numElmnts = threadOne->numElmnts + 1;
	} else{
	    threadTwo->numElmnts = threadOne->numElmnts;
	}

	assert(threadOne->numElmnts + threadTwo->numElmnts == numElmnts);
	
	threadOne->array = (void *)malloc(threadOne->numElmnts * dataSize);
	threadTwo->array = (void *)malloc(threadTwo->numElmnts * dataSize);
	
	//copy first half of array into arrayOne
	memcpy(threadOne->array, threadData->array, threadOne->numElmnts * dataSize);
	//copy second half of array into arrayTwo
	memcpy(threadTwo->array, threadData->array + (threadOne->numElmnts * dataSize), 
	       threadTwo->numElmnts * dataSize);

	pthread_create(&tidOne, NULL, splitArray, (void*)threadOne);
	pthread_create(&tidTwo, NULL, splitArray, (void*)threadTwo);

// PICK UP FROM HERE
	pthread_join(tidOne, NULL);
	pthread_join(tidTwo, NULL);
    
	insertSort(threadData, threadOne, threadTwo);
    
	free(threadOne->array);
	free(threadTwo->array);
	free(threadOne);
	free(threadTwo);

    }else{
    
	threadData->sort(threadData->array, threadData->numElmnts,
			 threadData->dataSize, threadData->cmp);
    }

    return NULL;
}

void insertSort(ThreadStruct *output, ThreadStruct *inputOne,
		ThreadStruct *inputTwo){

    CmpFunc cmp = output->cmp;

    int lengthOne = inputOne->numElmnts;
    int lengthTwo = inputTwo->numElmnts;

    int dataSize = output->dataSize;

    int i = 0;
    int j = 0;

    //Let's pray there's no overflow here!
    while(lengthOne != i && lengthTwo != j){
	if(cmp(inputOne->array + (i * dataSize), 
		inputTwo->array + (j * dataSize)) > 0){
	    
	    memcpy(output->array + ((i + j) * dataSize),
		   inputOne->array + (i * dataSize), dataSize);
	    i++;
	
	}else{

	    memcpy(output->array + ((i + j) * dataSize),
		   inputTwo->array + (j * dataSize), dataSize);
	    j++;
	}
    }

    while(lengthOne != i){
	
	memcpy(output->array + ((i + j) * dataSize),
	       inputOne->array + (i * dataSize), dataSize);
	i++;
    }
    while(lengthTwo != j){

	memcpy(output->array + ((i + j) * dataSize),
	       inputTwo->array + (j * dataSize), dataSize);
	j++;
    }
}
