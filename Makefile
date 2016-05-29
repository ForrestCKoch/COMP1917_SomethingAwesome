CFLAGS= -g -Wall -lm -pthread $(GLIB)
GLIB= `pkg-config --cflags --libs glib-2.0`
MODULES=
FILES= Array.c
TEST_FILES= Tests/runTests.c Tests/testArray.c 


all:


tests:

	gcc $(CFLAGS) -o RunTests $(TEST_FILES) $(FILES)
