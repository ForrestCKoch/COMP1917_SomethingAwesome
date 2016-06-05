#include <stdlib.h>
#include <stdio.h>
#include "defs.h"

int main(int argc, char *argv[]){
    
    if(argc != 5){
        printf("Proper usage is: ./Run in.file out.file dataMod sortMod threadPower\n");
        exit(1);
    }

    size_t depth = atoi(argv[5]);
    char *input = argv[1];
    char *output = argv[2];
    char *dataMod = argv[3];
    char *sortMod = argv[4];


    sortRequestHandler(depth, input, output, dataMod, sortMod);

    return 0;
}
