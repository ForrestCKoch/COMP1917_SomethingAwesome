#ifndef NUMBERS_H
#define NUMBERS_H

#define OUTPUT_COL 10

int numbersCmp(const void * a, const void * b);
int numbersGetAmount(FILE *fp);
void numbersFillArray(FILE *fp, int numElmnts, void *array);
void numbersWrite(FILE *fp, int numElmnts, void *array);


#endif
