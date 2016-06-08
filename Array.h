#ifndef ARRAY_H
#define ARRAY_H

/*  
    The Array ADT serves as an easy way to deal with void * 
    data types removing the need for the user to work with
    memcpy and pointers to memory.
*/

typedef struct _array * Array;

/*  
    returns an Array with "num" # of elements each
    "size" # of bytes.  Needs to be free'd with disposeArray
*/

Array newArray(size_t size, size_t num);
void disposeArray(Array *a);
size_t getNumElmnts(Array a);
size_t getSizeElmnts(Array a);

//  Returns a pointer to the first elemnt in the array
void * getDataPtr(Array a);

/*  Returns a pointer to the element at given index
    Be careful as altering this memory will change the array
    Dereference and typecast result to get value
        i.e *(int *)getElment(0, a) will return
            the int stored in the first index
*/

void * getElmnt(size_t index, Array a);

/*  Sets element at given index to given value
    Note this copies the value so a subsequent change to
    value will not affect the Array.

    Values should be typecast to set.
        i.e int x = 1;
            setElmnt(0, (void *)&x, a);
*/
void setElmnt(size_t index, void * value, Array a);

#endif
