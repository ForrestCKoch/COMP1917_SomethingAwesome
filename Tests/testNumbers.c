#include <glib.h>
#include <gmodule.h>
#include <stdlib.h>
#include "tests.h"
#include "../defs.h"

void testNumbers(void);

void addTestNumbers(void){
    
    g_test_add_func("/Tests/testNumbers", testNumbers);
}

void testNumbers(void){

    int depth = 0;
    char *input = "Tests/testNumbersInput.txt";
    char *output = "Tests/testNumbersOutput.txt";
    char *expect = "Tests/testNumbersExpected.txt";

    char *dataMod = "numbers";
    char *sortMod = "myQsort";

    sortRequestHandler(depth, input, output, dataMod, sortMod);

    ReadFunc readFile = NULL;
    GModule *module;
    gchar *path = g_module_build_path(MODULE_DIR, "numbers");

    module = g_module_open(path, G_MODULE_BIND_LAZY);

    g_module_symbol(module, "readFile", (gpointer *)&readFile);

    Array result = readFile(output);
    Array expected = readFile(expect);

    g_assert(getNumElmnts(result) == getNumElmnts(expected));

    int numElmnts = getNumElmnts(result);

    for(int i = 0; i < numElmnts; i++){
        int r = *(int *)getElmnt(i, result);
        int e = *(int *)getElmnt(i, expected);
        g_assert(r == e);
    }

    g_module_close(module);
}
