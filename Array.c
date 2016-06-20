#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Array.h"

typedef struct _array{
    
    void * data;
    size_t size;
    size_t num;

}array;

Array newArray(size_t size, size_t num){
    
    Array a = NULL;

    if(size > 0 && num > 0){
        a = (array *)malloc(sizeof(array));
        assert(a);

        a->size = size;
        a->num = num;

        a->data = (void *)calloc(num, size);
        if(!a->data){
            exit(1);
        }
    }

    return a;
}

void disposeArray(Array *a){
    
    if(*a){
        free((*a)->data);
        (*a)->data = NULL;

        free(*a);
        *a = NULL;
    }
}

size_t getNumElmnts(Array a){
    
    assert(a);

    return a->num;
}

size_t getSizeElmnts(Array a){
    
    assert(a);

    return a->size;
}

void * getDataPtr(Array a){
    
    assert(a);

    return a->data;
}

void * getElmnt(size_t index, Array a){

    void *elmnt;
    // crash the program given invalid input
    assert(index < a->num);
    assert(a);

    elmnt = a->data + (a->size * index);

    return elmnt;
}

void setElmnt(size_t index, void * value, Array a){

    // crash the program given invalid input
    assert(index < a->num);
    assert(value);
    assert(a);

    memcpy(a->data + (index * a->size), value, a->size);

}
