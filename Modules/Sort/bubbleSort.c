#include <string.h>
#include <stdlib.h>
#include "../../defs.h"

#define TRUE 1
#define FALSE 0

void swap(void *a, void *b, size_t size);

void sort(void *array, size_t num, size_t size, CmpFunc cmp){

    int sorted = FALSE;

    // stop 1 element before the end b/c of comparison
    void *stopAddr = array + ((num - 1) * size);

    while(!sorted){
        
        int changed = FALSE;

        for(void *ptr = array; ptr != stopAddr; ptr += size){
            if(cmp(ptr, ptr + size) > 0){
                swap(ptr, ptr + size, size);
                changed = TRUE;
            }
        }

        if(!changed){
            sorted = TRUE;
        }
    }
}

void swap(void *a, void *b, size_t size){
    
    void *tmp = malloc(size);

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);

    free(tmp);
}
