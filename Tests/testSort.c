#include <glib.h>
#include <stdlib.h>
#include "tests.h"
#include "../defs.h"

void addTestSort(void){
    
    g_test_add_func("/Tests/testSort", testSort);
}

static int int_cmp(const void *a, const void *b);

void testSort(void){    

    for(int depth = 0; depth < 8; depth++){
        const int TEST_SIZE = 100000000;
        Array a = newArray(sizeof(int), TEST_SIZE);

        for(int i = 0; i < TEST_SIZE; i++){
            setElmnt(i, (void *)rand(), a);
        }

        void sortArray(depth, a, qsort, int_cmp);

        for(int i = 0; i < TEST_SIZE - 1; i++){
            int a = *(int *)getElmnt(i, a);
            int b = *(int *)getElmnt(i + 1, a);
            g_assert(a <= b);
        }
    }
}
    
static int int_cmp(const void *a, const void *b) {

    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
	/* integer comparison: returns negative if b > a 
	and positive if a > b */ 
}
