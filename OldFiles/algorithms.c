#include <stdlib.h>
#include <string.h>
#include "algorithms.h"

//Link in your algorithms here
SortFunc loadSort(char *alg){
    SortFunc sort;

    if(!(strcmp(alg, "MYQSORT"))){
	sort = myQsort;
    } else{
	printf("UNKNOWN ALG\n");
	exit(1);
    }
    
    return sort;
}

void myQsort(void *arry, int numElements, int sizeElements, CmpFunc func){

    qsort(arry, numElements, sizeElements, func);
}
