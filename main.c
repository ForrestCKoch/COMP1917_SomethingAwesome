#include <stdlib.h>
#include <stdio.h>
#include "defs.h"

int main(int argc, char *argv[]){
    
    // i.e ./Run test.txt output.txt numbers myQsort 0
    if(argc != 6){
        printf("Proper usage is: ./Run in.file out.file dataMod sortMod threadPower\n");
        exit(1);
    }

    // 2^depth will be the # threads used
    size_t depth = atoi(argv[5]);

    // input/output files
    char *input = argv[1];
    char *output = argv[2];

    // name of data & sorting mods to be used
    char *dataMod = argv[3];
    char *sortMod = argv[4];


    //send request
    sortRequestHandler(depth, input, output, dataMod, sortMod);

    return 0;
}
