CFLAGS= -g -Wall -lm -pthread $(GLIB) $(GMODULE)
GLIB= `pkg-config --cflags --libs glib-2.0`
GMODULE= `pkg-config --cflags --libs gmodule-2.0`
MODULES= 
FILES= Array.c sortArray.c requestHandler.c
TEST_FILES= Tests/runTests.c Tests/testArray.c Tests/testSort.c Tests/testNumbers.c


all:

	gcc $(CFLAGS) -o Run main.c $(FILES)

tests:

	gcc $(CFLAGS) -o RunTests $(TEST_FILES) $(FILES)
