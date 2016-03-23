#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//MOVE THIS OUT!
#define FILENAME_LENGTH 20

int main(int argc, char *argv[]){

    char inputFile[FILENAME_LENGTH];
    char outputFile[FILENAME_LENGTH];

    // Should we move this out of main?
    if(argc != 3){
	printf("Proper usage is \"./Prog input.file output.file\".\n");
	exit(1);
    }

    // Get file names
    strcpy(inputFile, argv[1]);
    strcpy(outputFile, argv[2]);



    return EXIT_SUCCESS;
}
