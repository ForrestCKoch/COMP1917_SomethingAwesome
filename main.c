#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "core.h"
#include "algorithms.h"
#include "modules.h"

//MOVE THIS OUT!
#define FILENAME_LENGTH 20
#define THREAD_POWER 0

int main(int argc, char *argv[]){

    char inputFile[FILENAME_LENGTH];
    char outputFile[FILENAME_LENGTH];

    SortFunc sort;
    dataStruct *modData;
    
    // Should we move this out of main?
    if(argc != 3){
	printf("Proper usage is \"./Prog input.file output.file\".\n");
	exit(1);
    }

    // Get file names
    strcpy(inputFile, argv[1]);
    strcpy(outputFile, argv[2]);

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
    createJob(inputFile, outputFile, THREAD_POWER, sort, modData);

    free(modData);
    modData = NULL;

    return EXIT_SUCCESS;
}
