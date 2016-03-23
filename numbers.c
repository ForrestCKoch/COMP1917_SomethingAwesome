#include "numbers.h"

int lowHighNum(const void * a, const void * b){
    const int pa = *(const int *)a;
    const int pb = *(const int *)b;

    return(pa - pb);
}
