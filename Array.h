#ifndef ARRAY_H
#define ARRAY_H

typedef struct _array * Array;

Array newArray(size_t size, size_t num);
void disposeArray(Array *a);
size_t getNumElmnts(Array a);
size_t getSizeElmnts(Array a);
void * getDataPtr(Array a);
void * getElmnt(size_t index, Array a);
void setElmnt(size_t index, void * value, Array a);

#endif
