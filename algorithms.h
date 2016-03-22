#ifndef ALGORITHMS_H
#define ALGORITHMS_H

void myQsort(void *arry, int numElements, int sizeElements,
		  int (*cmpFunc)(const void * a, const void *b));

#endif
