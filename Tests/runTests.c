#include <glib.h>
#include <stdlib.h>
#include <time.h>
#include "tests.h"

int main(int argc, char *argv[]){
    
    srand(0);

    g_test_init(&argc, &argv, NULL);

    addTestArray();
    addTestSort();

    return g_test_run();
}
