#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "core.h"
#include "algorithms.h"
#include "modules.h"

//MOVE THIS OUT!
#define FILENAME_LENGTH 20
#define THREAD_POWER 2

int main(int argc, char *argv[]){

    char inputFile[FILENAME_LENGTH];
    char outputFile[FILENAME_LENGTH];

    int threadPower;

    time_t start;
    time_t end;
    int sec;

    SortFunc sort;
    dataStruct *modData;
    
    // Should we move this out of main?
    if(argc != 4){
	printf("Proper usage is \"./Prog input.file output.file threadPower\".\n");
	exit(1);
    }

    // Get file names
    strcpy(inputFile, argv[1]);
    strcpy(outputFile, argv[2]);
    threadPower = atoi(argv[3]);

    modData = (dataStruct *)malloc(sizeof(dataStruct));
    loadModule(modData, "NUMBERS");

    sort = loadSort("MYQSORT");

    // createJob should take in: 
    //	    - name of input/outputfiles
    //	    - sorting algorithm to use
    //	    - number threads to use
    //	    - data info struct?:
    //		- pointer to data read function
    //		- pointer to compare function
    //		- size of data?
    // createJob();
    start = time(NULL);
    createJob(inputFile, outputFile, threadPower, sort, modData);
    end = time(NULL);
    
    free(modData);
    modData = NULL;

    sec = end - start;
    printf("%d seconds to sort\n", sec);

    return EXIT_SUCCESS;
}
