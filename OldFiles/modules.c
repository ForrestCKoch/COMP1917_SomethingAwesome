#include <string.h> 
#include "modules.h" 

//ADD MODULE INCLUDES HERE #include "numbers.h"
#include "numbers.h"
#include "strings.h"


void loadModule(dataStruct *modData, char *module){
    
    //INSERT HOOK TO MODULE LOADER HERE
    if(!strcmp(module, NUMBERS)){
	numbersLoadModule(modData);
    } else if(!strcmp(module, STRINGS)){
	stringsLoadModule(modData);
    } else{
	printf("UNKNOWN MODULE: %s\n", module);
    }
}
	

