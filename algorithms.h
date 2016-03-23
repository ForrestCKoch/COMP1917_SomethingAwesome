#ifndef ALGORITHMS_H
#define ALGORITHMS_H

typedef int (*CmpFunc)(const void * a, const void *b);

void myQsort(void *arry, int numElements, int sizeElements, CmpFunc cmp);

#endif
