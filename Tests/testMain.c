#include <glib.h>
#include <stdlib.h>
#include <time.h>
#include "testAlgorithms.h"
//DONT FORGET TO INCLUDE NECCESSARY FILES!

int main(int argc, char *argv[]){

    //NOTE: Do some research on glib's random functions
    //	    I think they may provide protection over
    //	    seeding multiple times with srand
    srand(time(NULL));

    g_test_init(&argc, &argv, NULL);
 
    //Insert g_test_add_func's here
    addAllAlgorithms();

    return g_test_run();
}
