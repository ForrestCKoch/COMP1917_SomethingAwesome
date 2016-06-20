# COMP1917_SomethingAwesome
Uses multi-threading to sort a given data set

NOTE:   due to my lazy coding, the #define's in defs.h for
        SORT_MOD_DIR AND DATA_MOD_DIR need to be adjusted to the whatever directory
        your Modules folder is in.  This needs to be the ABSOLUTE path (i.e /home/user/foo/bar/COMP1917_SomethingAwesome/Modules/Data)

Compile tests with make tests.
Compile program with make all or just make.

You do not need to recompile base code when adding new modules.
However modules need to be compiled as follow:
gcc -shared -fPIC -o libmoduleName.so moduleName.c

Currently available modules:
    
    For Data:
        numbers

    For Sorting:
        myQsort
        bubbleSort
