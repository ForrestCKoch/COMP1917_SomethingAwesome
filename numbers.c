#include <stdio.h>
#include <stdlib.h>
#include "modules.h"
#include "numbers.h"

int numbersCmp(const void * a, const void * b){

    const int pa = *(const int *)a;
    const int pb = *(const int *)b;

    return(pa - pb);
}

int numbersGetAmount(FILE *fp){

    FILE *input;
    int val;
    int count = 0;

    input = fp;

    rewind(input);

    while(fscanf(input, "%d", &val) != EOF){
	count++;
    }

    return count;
}

void numbersFillArray(FILE *fp, int numElmnts, void *array){
    
    FILE *input;
    int *numArray;
    int val;
    int count = 0;

    input = fp;
    numArray = array;

    rewind(input);

    while(fscanf(input, "%d", &val) != EOF){
	numArray[count] = val;
	count++;
    }

    if(count != numElmnts){
	__ERROR__;
	exit(1);
    }
}

void numbersWrite(FILE *fp, int numElmnts, void *array){

    FILE *output;
    int *numArray;
    int i;
    int j = 0;

    output = fp;
    numArray = array;

    for(i = 0; i < numElmnts; i++){
	
	fprintf(output, "%d ", numArray[i]);
	j++;
	if(j == OUTPUT_COL){
	    fprintf(output, "\n");
	    j = 0;
	}
    }
}

