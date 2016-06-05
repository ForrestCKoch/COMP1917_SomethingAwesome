CFLAGS= -g -Wall -lm -pthread $(GLIB)
GLIB= `pkg-config --cflags --libs glib-2.0`
GMODULE= `pkg-config --cflags --libs gmodule-2.0`
MODULES= 
FILES= Array.c sortArray.c requestHandler.c
TEST_FILES= Tests/runTests.c Tests/testArray.c Tests/testSort.c


all:

	gcc $(CFLAGS) -o Run main.c $(FILES) $(GMODULE)

tests:

	gcc $(CFLAGS) -o RunTests $(TEST_FILES) $(FILES)
