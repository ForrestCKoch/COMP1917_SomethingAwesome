#include <glib.h>
#include <stdlib.h>
#include <time.h>
#include "tests.h"

int main(int argc, char *argv[]){
    
    srand(time(NULL));

    g_test_init(&argc, &argv, NULL);

    addTestArray();

    return g_test_run();
}
