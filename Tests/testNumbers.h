#ifndef TEST_NUMBERS_H
#define TEST_NUMBERS_H

#include "../algorithms.h"

#define SMALL_SAMPLE 1000
#define LARGE_SAMPLE 100000000

void addAllNumbersTests(void);
void testNumbersCmp(SortFunc sort, int sampleSize);
void smallTestNumbersCmp(void);
void largeTestNumbersCmp(void);

#endif
