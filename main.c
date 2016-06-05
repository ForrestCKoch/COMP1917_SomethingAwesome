#include <stdlib.h>
#include "defs.h"

int main(int argc, char *argv[]){
    
    int depth = 0;
    char *input = "input.txt";
    char *output = "output.txt";
    char *dataMod = "numbers";
    char *sortMod = "myQsort";


    sortRequestHandler(depth, input, output, dataMod, sortMod);

    return 0;
}
