#include <stdlib.h>
#include "../../defs.h"

void sort(void *array, size_t num, size_t size, CmpFunc cmp){

    qsort(array, num, size, cmp);
}
