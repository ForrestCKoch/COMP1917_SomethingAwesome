#include <glib.h>
#include "tests.h"
#include "../Array.h"
#include <stdio.h>

void testArray(void);
void testNewArray(void);
void testDisposeArray(void);

void addTestArray(void){

    g_test_add_func("/Tests/testArray", testArray);

}

void testArray(void){

    Array testArray;

    // ************************************************************************
    // Creation tests
    // ************************************************************************
    
    // newArray should return NULL if given invalid arguments
    testArray = newArray(sizeof(int), 0);
    g_assert(testArray == NULL);

    /*
    testArray = newArray(sizeof(int), -1);
    g_assert(testArray == NULL);
    */

    // newArray should return pointer if successful
    testArray = newArray(sizeof(int), 4);
    g_assert(testArray);
    g_assert(getDataPtr(testArray));

    // disposeArray should make testArray point to NULL
    disposeArray(&testArray);
    g_assert(testArray == NULL);

    // disposeArray shouldn't crash if passing NULL pointer
    disposeArray(&testArray);
    g_assert(testArray == NULL);

    // ************************************************************************
    // Getter/Setter tests
    // ************************************************************************

    // should we use #defines instead?
    const int TEST_SIZE = 10000;
    const int TEST_DATA_SIZE = sizeof(int);

    testArray = newArray(TEST_DATA_SIZE, TEST_SIZE);
    g_assert(testArray);

    int numElmnts = getNumElmnts(testArray);
    g_assert(numElmnts == TEST_SIZE);

    int sizeElmnts = getSizeElmnts(testArray);
    g_assert(sizeElmnts == TEST_DATA_SIZE);

    for(int i = 0; i < TEST_SIZE; i++){
        setElmnt(i, (void *)&i, testArray);
    }

    for(int i = 0; i < TEST_SIZE; i++){
        int value = *(int *)getElmnt(i, testArray);
        g_assert(value == i);
    }

    disposeArray(&testArray);
}
