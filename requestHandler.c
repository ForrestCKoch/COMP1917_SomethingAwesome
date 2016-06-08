#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

static GModule * openModule(gchar *modStr);
static void loadFunc(GModule *mod, gpointer *func, gchar *funcName);

void sortRequestHandler(int depth, char *input, char *output, char *dataStr, char*sortStr){
    
    GModule *dataMod = openModule(dataStr);
    GModule *sortMod = openModule(sortStr);

    CmpFunc cmp = NULL;
    SortFunc sort = NULL;
    ReadFunc readFile = NULL;
    WriteFunc writeFile = NULL;

    loadFunc(dataMod, (gpointer *)&cmp, "cmp");
    loadFunc(dataMod, (gpointer *)&readFile, "readFile");
    loadFunc(dataMod, (gpointer *)&writeFile, "writeFile");
    loadFunc(sortMod, (gpointer *)&sort, "sort");

    Array data = readFile(input);

    sortArray(depth, data, sort, cmp);

    writeFile(data, output);

    disposeArray(&data);

    g_module_close(dataMod);
    dataMod = NULL;

    g_module_close(sortMod);
    sortMod = NULL;
}

static GModule * openModule(gchar *modStr){

    GModule *module;

    gchar * modPath = g_module_build_path(MODULE_DIR, modStr);

    if(!modPath){
        printf("Could not find module:%s in module directory: %s\n",
                modStr, MODULE_DIR);
        exit(1);
    }

    module = g_module_open(modPath, G_MODULE_BIND_LAZY);

    if(!module){
        printf("Error openning module at %s\n", modPath);
        exit(1);
    }
    g_free(modPath);

    return module;
}
        
static void loadFunc(GModule *mod, gpointer *func, gchar *funcName){
    
    g_module_symbol(mod, funcName, func);
    if(!func){
        printf("Error loading function %s from module %s\n", 
                funcName, g_module_name(mod));
        exit(1);
    }
}
