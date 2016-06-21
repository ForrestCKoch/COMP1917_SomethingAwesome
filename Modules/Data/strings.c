#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../defs.h"

#define MAX_STRLEN 256

int getAmount(FILE *fp);

int cmp(const void * a, const void * b){

    return strcmp((char *)a, (char *)b);
}

Array readFile(char *filename){

    char buffer[MAX_STRLEN];
    int count = 0;

    FILE *fp = fopen(filename, "r");
    if(!fp){
        printf("Could not open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    Array data = newArray(sizeof(char) * MAX_STRLEN, getAmount(fp));

    rewind(fp);

    while(fscanf(fp, "%s", buffer) != EOF){
        setElmnt(count, (void *)buffer, data);
        count++;
    }

    fclose(fp);

    return data;
}

void writeFile(Array a, char *filename){

    FILE *fp = fopen(filename, "w");
    if(!fp){
        printf("Could not open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int row = 0;
    int numElmnts = getNumElmnts(a);
    for(int i = 0; i < numElmnts; i++){
        fprintf(fp, "%s ", (char *)getElmnt(i, a));
        row++;
        if(row == 8){
            fprintf(fp, "\n");
            row = 0;
        }else {
            fprintf(fp, "\t");
        }
    }

    fclose(fp);
}

int getAmount(FILE *fp){
    
    FILE *input = fp;
    char buffer[MAX_STRLEN] = {0};
    int count = 0;

    rewind(input);

    while(fscanf(input, "%s", buffer) != EOF){
        count++;
    }

    return count;
}
