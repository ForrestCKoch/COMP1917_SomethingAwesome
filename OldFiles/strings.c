#include <string.h>
#include "strings.h"
//^^^ is that a bad header name? lol

int stringCmp(const void * a, const void * b){
    const char *pa = *(const char **)a;
    const char *pb = *(const char **)b;

    return(strcmp(pa, pb));
}

void stringsLoadModule(dataStruct *modData){
//insert code here
}
