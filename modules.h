#ifndef MODULES_H
#define MODULES_H
#include <stdio.h>

typedef int (*CmpFunc)(const void *a, const void *b);
typedef int (*GetAmountFunc)(FILE *fp);
typedef void (*FillFunc)(FILE *fp, int numElmnts, void *array);
typedef void (*WriteFunc)(FILE *fp, int numElmnts, void *array);

typedef struct _dataStruct{
    int dataSize;
    int numElmnts;
    CmpFunc cmp;
    FillFunc fillArray;
    WriteFunc writeFile;
} dataStruct;

void loadModule(dataStruct modData, char *module);

#endif
