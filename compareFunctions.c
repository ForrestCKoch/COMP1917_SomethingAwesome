#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compareFunctions.h"

int lowHighNum(const void * a, const void * b){
    const int pa = *(const int *)a;
    const int pb = *(const int *)b;

    return(pa - pb);
}

int myStrCmp(const void * a, const void * b){
    const char *pa = *(const char **)a;
    const char *pb = *(const char **)b;

    return(strcmp(pa, pb));
}
