#include <glib.h>
#include <stdlib.h>
#include "testNumbers.h"
#include "../numbers.h"
#include "../algorithms.h"

void addAllNumbersTests(void){

    g_test_add_func("/Tests/Numbers/smallNumberCmp", smallTestNumbersCmp);
    g_test_add_func("/Tests/Numbers/largeNumberCmp", largeTestNumbersCmp);
}

void testNumbersCmp(SortFunc sort, int sampleSize){
    
    int *arry = (int *)malloc(sampleSize * sizeof(int));

    int i;

    for(i = 0; i < sampleSize; i++){
	arry[i] = rand();
    }

    sort(arry, sampleSize, sizeof(int), numberCmp);

    for(i = 0; i < sampleSize - 1; i++){
	g_assert(arry[i] <= arry[i + 1]);
    }

    free(arry);
}

void smallTestNumbersCmp(void){
    
    testNumbersCmp(myQsort, SMALL_SAMPLE);
}

void largeTestNumbersCmp(void){

    testNumbersCmp(myQsort, LARGE_SAMPLE);
}
