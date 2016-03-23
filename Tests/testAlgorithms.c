#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include "testAlgorithms.h"
#include "../compareFunctions.h"
#include "../algorithms.h"


void addAllAlgorithms(void){

    g_test_add_func("/Tests/Algorithms/smallNumQsortTest", smallNumQsortTest);
    g_test_add_func("/Tests/Algorithms/largeNumQsortTest", largeNumQsortTest);
    g_test_add_func("/Tests/Algorithms/strQsortTest", strQsortTest);
}


void testNumArry(SortFunc sort, int sampleSize){

    int *arry = (int *)malloc(sampleSize * sizeof(int));
    
    int i;

    for(i = 0; i < sampleSize; i++){
	arry[i] = (int) rand();
    }

    sort(arry, sampleSize, sizeof(int), lowHighNum);

    for(i = 0; i < sampleSize - 1; i++){
	g_assert(arry[i] <= arry[i + 1]);
    }

    free(arry);
}

void testStrArry(SortFunc sort){
    int i;

    char *strArry[TEST_STRING_GROUP_ELEMENTS] = {TEST_STRING_GROUP};

    sort(strArry, TEST_STRING_GROUP_ELEMENTS, sizeof(char *), myStrCmp);

    for(i = 0; i < TEST_STRING_GROUP_ELEMENTS - 1; i++){
	g_assert(strcmp(strArry[i], strArry[i + 1]) <= 0);
    }
}

void smallNumQsortTest(void){

    testNumArry(myQsort, SMALL_SAMPLE);
}

void largeNumQsortTest(void){
    
    testNumArry(myQsort, LARGE_SAMPLE);
}

void strQsortTest(void){
    
    testStrArry(myQsort);
}
