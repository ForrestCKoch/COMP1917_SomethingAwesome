#ifndef NUMBERS_H
#define NUMBERS_H

#include "modules.h"

#define OUTPUT_COL 10
#define NUMBERS_SIZE sizeof(int)

int numbersCmp(const void * a, const void * b);
int numbersGetAmount(FILE *fp);
void numbersFillArray(FILE *fp, int numElmnts, void *array);
void numbersWrite(FILE *fp, int numElmnts, void *array);
void numbersLoadModule(dataStruct *modData);


#endif
