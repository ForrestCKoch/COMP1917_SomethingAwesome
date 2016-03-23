#ifndef TEST_ALGORITHMS_H
#define TEST_ALGORITHMS_H

#include "../algorithms.h"

#define SMALL_SAMPLE 1000
#define LARGE_SAMPLE 1000000

typedef void (*SortFunc)(void *arry, int numElements, int sizeElements,
			 CmpFunc cmp);

void addAllAlgorithms(void);
void testNumArry(SortFunc sort, int sampleSize);
void testStrArry(SortFunc sort);
void smallNumQsortTest(void);
void largeNumQsortTest(void);
void strQsortTest(void);

#define TEST_STRING_GROUP_ELEMENTS 6
#define TEST_STRING_GROUP "MARTHA", "BRADY", "TOM", "TOMAS", "BRET", "ALICE"


#endif
