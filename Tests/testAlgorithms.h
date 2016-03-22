#ifndef TEST_ALGORITHMS_H
#define TEST_ALGORITHMS_H

#define SMALL_SAMPLE 1000
#define LARGE_SAMPLE 1000000

void addAllAlgorithms(void);
void testNumArry(void (*sort)(void *arry, int numElements, int sizeElements, 
		 int (*cmpFunc)(const void * a, const void * b)), int sampleSize);
void testStrArry(void (*sort)(void *arry, int numElements, int sizeElements,
		 int (*cmpFunc)(const void * a, const void * b)));
void smallNumQsortTest(void);
void largeNumQsortTest(void);
void strQsortTest(void);

#define TEST_STRING_GROUP_ELEMENTS 6
#define TEST_STRING_GROUP "MARTHA", "BRADY", "TOM", "TOMAS", "BRET", "ALICE"


#endif
