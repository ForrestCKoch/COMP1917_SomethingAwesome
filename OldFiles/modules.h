#ifndef MODULES_H
#define MODULES_H
#include <stdio.h>

//include identifiers for modules here
#define NUMBERS "NUMBERS"
#define STRINGS "STRINGS"


typedef int (*CmpFunc)(const void *a, const void *b);
typedef int (*GetAmountFunc)(FILE *fp);
typedef void (*FillFunc)(FILE *fp, int numElmnts, void *array);
typedef void (*WriteFunc)(FILE *fp, int numElmnts, void *array);

typedef struct _dataStruct{
    int dataSize;
    GetAmountFunc getAmount;
    CmpFunc cmp;
    FillFunc fillArray;
    WriteFunc writeFile;
} dataStruct;

void loadModule(dataStruct *modData, char *module);

//I can't get this to work any other way!!!!
#define __ERROR__ {\
    printf("Error: ");\
    printf("%d, ", __LINE__);\
    printf("%s, ", __func__);\
    printf("%s\n", __FILE__);}\

#endif
