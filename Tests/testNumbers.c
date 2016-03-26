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
    g_test_add_func("/Tests/Numbers/numbers", testNumbers);
    g_test_add_func("/Tests/Numbers/loadNumbers", testLoadNumbers);
}

void testNumbersCmp(SortFunc sort, int sampleSize){
    
    int *arry = (int *)malloc(sampleSize * NUMBERS_SIZE);

    int i;

    for(i = 0; i < sampleSize; i++){
	arry[i] = rand();
    }

    sort(arry, sampleSize, NUMBERS_SIZE, numbersCmp);

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
    int fib[] = {4181 ,2584 ,1597 ,987 ,610 ,377 ,233 , 144 ,89 ,
                 55 , 34, 21 ,13 ,8 ,5 ,3 ,2 ,1 ,1 ,0};
    int i;


    fp = fopen(TEST_FILE_INPUT, "r");
    if(fp == NULL){
	printf("Could not open file\n");
	exit(1);
    }

    array = malloc(NUMBERS_SIZE * TEST_FILE_NUM);

    nArray = array;

    numbersFillArray(fp, TEST_FILE_NUM, array);

    for(i = 0; i < TEST_FILE_NUM; i++){
	g_assert(fib[i] == nArray[i]);
    }
    
    fclose(fp);
    free(array);
}

void testNumbers(void){
    
    FILE *input;
    FILE *output;
    void *array;
    int numElmnts;

    void *testArray;
    int *testnArray;
    int i;

    input = fopen(TEST_FILE_INPUT, "r");
    if(input == NULL){
	printf("Could not open file\n");
	exit(1);
    }

    numElmnts = numbersGetAmount(input);
    array = malloc(numElmnts * NUMBERS_SIZE);

    numbersFillArray(input, numElmnts, array);
    fclose(input);

    myQsort(array, numElmnts, NUMBERS_SIZE, numbersCmp);

    output = fopen(TEST_FILE_OUTPUT, "w");
    if(output == NULL){
	printf("Could not open file\n");
	exit(1);
    }

    numbersWrite(output, numElmnts, array);

    fclose(output);
    free(array);

    //Confirm the output is valid!
    testArray = malloc(numElmnts * NUMBERS_SIZE);
    testnArray = testArray;

    input = fopen(TEST_FILE_OUTPUT, "r");
    if(input == NULL){
	printf("Could not open file\n");
	exit(1);
    }

    numbersFillArray(input, numElmnts, testArray);
    fclose(input);

    for(i = 0; i < numElmnts - 1; i++){
	g_assert(testnArray[i] <= testnArray[i + 1]);
    }
    free(testArray);
}
    

void testLoadNumbers(void){
    
    dataStruct *modData;
    
    modData = malloc(sizeof(dataStruct));

    loadModule(modData, NUMBERS);

    g_assert(modData->dataSize == NUMBERS_SIZE);
    g_assert(modData->getAmount == numbersGetAmount);
    g_assert(modData->cmp == numbersCmp);
    g_assert(modData->fillArray == numbersFillArray);
    g_assert(modData->writeFile == numbersWrite);
}
