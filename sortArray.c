#include <pthread.h>
#include <assert.h>
#include "defs.h"

typedef struct _threadArgs{
    Array array;
    SortFunc sort;
    CmpFunc cmp;
    size_t depth;
} threadArgs;

static void *sortThread(void *args);
static void mergeThreads(threadArgs dest, Array one, Array two);

void sortArray(size_t depth, Array a, SortFunc sort, CmpFunc cmp){
    
    if(!depth){
        //Special Case
        size_t num = getNumElmnts(a);
        size_t size = getSizeElmnts(a);
        void *data = getDataPtr(a);
        sort(data, num, size, cmp);
    }else{
        threadArgs args = {a, sort, cmp, depth};
        sortThread((void *)&args);
    }
}

static void *sortThread(void *args){
    
    threadArgs *tArgs;
    tArgs = args;

    if(tArgs->depth){
        //Split array, start a new thread to call sortThread on each
        Array a = tArgs->array;

        int num = getNumElmnts(a);
        int size = getSizeElmnts(a);

        int half = num / 2;

        Array one = newArray(size, num - half);
        Array two = newArray(size, half);

        for(int i = 0; i < half; i++){
            setElmnt(i, getElmnt(i * 2, a), one);
            setElmnt(i, getElmnt(1 + (i * 2), a), two);
        }

        // now for odd case one should be larger
        if(half != num - half){
            setElmnt(half, getElmnt(num - 1, a), one);
        }

        threadArgs threadOne = {one, tArgs->sort, tArgs->cmp, tArgs->depth - 1};
        threadArgs threadTwo = {two, tArgs->sort, tArgs->cmp, tArgs->depth - 1};

        pthread_t tidOne, tidTwo;

        pthread_create(&tidOne, NULL, sortThread, (void *)&threadOne);
        pthread_create(&tidTwo, NULL, sortThread, (void *)&threadTwo);

        pthread_join(tidOne, NULL);
        pthread_join(tidTwo, NULL);

        mergeThreads(*tArgs, one, two);

        disposeArray(&one);
        disposeArray(&two);
    }else{
        
        SortFunc sort = tArgs->sort;
        CmpFunc cmp = tArgs->cmp;
        Array a = tArgs->array;

        int num = getNumElmnts(a);
        int size = getSizeElmnts(a);

        void *data = getDataPtr(a);

        sort(data, num, size, cmp);

    }
    return NULL;
}
        
static void mergeThreads(threadArgs dest, Array one, Array two){
    
    CmpFunc cmp = dest.cmp;

    Array master = dest.array;

    size_t putOne = 0;
    size_t putTwo = 0;

    size_t lenOne = getNumElmnts(one);
    size_t lenTwo = getNumElmnts(two);

    assert(lenOne + lenTwo == getNumElmnts(master));

    while(putOne != lenOne && putTwo != lenTwo){
        
        void *valOne = getElmnt(putOne, one);
        void *valTwo = getElmnt(putTwo, two);

        if(cmp(valOne, valTwo) < 0){
            //put valOne
            setElmnt(putOne + putTwo, valOne, master);
            putOne++;
        }else{
            setElmnt(putOne + putTwo, valTwo, master);
            putTwo++;
        }
    }

    while(putOne != lenOne){
        void *val = getElmnt(putOne, one);
        setElmnt(putOne + putTwo, val, master);
        putOne++;
    }

    while(putTwo != lenTwo){
        void *val = getElmnt(putOne, one);
        setElmnt(putOne + putTwo, val, master);
        putTwo++;
    }
}
