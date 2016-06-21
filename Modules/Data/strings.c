#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../defs.h"

#define MAX_STRLEN 32
#define COL_SIZE 16
#define COLUMNS 4

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

    int col = 0;
    int numElmnts = getNumElmnts(a);
    for(int i = 0; i < numElmnts; i++){
        fprintf(fp, "%s ", (char *)getElmnt(i, a));
        col++;
        if(col == COLUMNS){
            fprintf(fp, "\n");
            col = 0;
        }else {
            int len = strlen((char *)getElmnt(i, a));
            while(len < COL_SIZE){
                fprintf(fp, " ");
                len++;
            }
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
