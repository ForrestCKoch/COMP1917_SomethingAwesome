#include <glib.h>
#include <stdlib.h>
#include "testNumbers.h"
#include "../numbers.h"
#include "../algorithms.h"

void addAllNumbersTests(void){

    g_test_add_func("/Tests/Numbers/smallNumberCmp", smallTestNumbersCmp);
    g_test_add_func("/Tests/Numbers/largeNumberCmp", largeTestNumbersCmp);
    g_test_add_func("/Tests/Numbers/numbersGetAmount", testNumbersGetAmount);
    g_test_add_func("/Tests/Numbers/numbersFillArray", testNumbersFillArray);
}

void testNumbersCmp(SortFunc sort, int sampleSize){
    
    int *arry = (int *)malloc(sampleSize * sizeof(int));

    int i;

    for(i = 0; i < sampleSize; i++){
	arry[i] = rand();
    }

    sort(arry, sampleSize, sizeof(int), numbersCmp);

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

void testNumbersGetAmount(void){
    
    FILE *fp;

    fp = fopen(TEST_FILE_INPUT, "r");
    if(fp == NULL){
	printf("Error, could not open file\n");
	exit(1);
    }

    g_assert(numbersGetAmount(fp) == TEST_FILE_NUM);

    fclose(fp);
}

void testNumbersFillArray(void){
    
    FILE *fp;
    void *array;
    int *nArray;
    int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 
	       144, 233, 377, 610, 987, 1597, 2584, 4181};
    int i;


    fp = fopen(TEST_FILE_INPUT, "r");
    if(fp == NULL){
	printf("Could not open file\n");
	exit(1);
    }

    array = malloc(sizeof(int) * TEST_FILE_NUM);

    nArray = array;

    numbersFillArray(fp, TEST_FILE_NUM, array);

    for(i = 0; i < TEST_FILE_NUM; i++){
	g_assert(fib[i] == nArray[i]);
    }
    
    fclose(fp);
}
