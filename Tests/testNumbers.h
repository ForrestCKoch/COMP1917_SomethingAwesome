#ifndef TEST_NUMBERS_H
#define TEST_NUMBERS_H

#include "../algorithms.h"

#define SMALL_SAMPLE 1000
#define LARGE_SAMPLE 1000000

//This should be moved to a config file
#define TEST_FILE_INPUT "Tests/testNumbers.txt"
#define TEST_FILE_OUTPUT "Tests/testNumbersOutput.txt"
#define TEST_FILE_NUM 20

void addAllNumbersTests(void);
void testNumbersCmp(SortFunc sort, int sampleSize);
void smallTestNumbersCmp(void);
void largeTestNumbersCmp(void);
void testNumbersGetAmount(void);
void testNumbersFillArray(void);
void testNumbersWrite(void);

#endif
