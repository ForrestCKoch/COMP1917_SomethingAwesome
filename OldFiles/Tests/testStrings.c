#include <glib.h>
#include <string.h>
#include "testStrings.h"
#include "../strings.h"
#include "../algorithms.h"

void addAllStringsTests(void){
    
    g_test_add_func("/Tests/Strings/stringsCmpTest", testStringsCmp);
}

void testStringsCmp(void){

    int i;

    char *strArry[TEST_STRING_GROUP_ELEMENTS] = {TEST_STRING_GROUP};

    myQsort(strArry, TEST_STRING_GROUP_ELEMENTS, sizeof(char *), stringCmp);

    for(i = 0; i < TEST_STRING_GROUP_ELEMENTS - 1; i++){
	g_assert(strcmp(strArry[i], strArry[i + 1]) <= 0);
    }
}
