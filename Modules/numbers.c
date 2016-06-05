#include <stdio.h>
#include <stdlib.h>
#include "../defs.h"

int getAmount(FILE *fp);

int cmp(const void * a, const void * b){

    const int pa = *(const int *) a;
    const int pb = *(const int *) b;

    return (pa-pb);
}

Array readFile(char *filename){

    int val;
    int count = 0;
    FILE *fp = fopen(filename, "r");
    if(!fp){
        printf("Could not open %s\n", filename);
        exit(1);
    }

    Array data = newArray(sizeof(int), getAmount(fp));

    rewind(fp);

    while(fscanf(fp, "%d", &val) != EOF){
        setElmnt(count, (void *)&val, data);
        count++;
    }

    fclose(fp);

    return data;
}

void writeFile(Array a, char *filename){

    FILE *fp = fopen(filename, "w");
    if(!fp){
        printf("Could not open %s\n", filename);
        exit(1);
    }

    int row = 0;
    int numElmnts = getNumElmnts(a);
    for(int i = 0; i < numElmnts; i++){
        fprintf(fp, "%d ", *(int *)getElmnt(i, a));
        row++;
        if(row >= 80){
            fprintf(fp, "\n");
            row = 0;
        }
    }

    fclose(fp);
}

int getAmount(FILE *fp){

    FILE *input = fp;
    int val;
    int count = 0;

    rewind(input);

    while(fscanf(input, "%d", &val) != EOF){
        count++;
    }

    return count;
}
