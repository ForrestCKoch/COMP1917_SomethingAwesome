CFLAGS = -g -Wall
GLIB = `pkg-config --cflags --libs glib-2.0`
OBJECTS = compareFunctions.o algorithms.o

all:
	make compFuncs
	make algorithms
	make testAlgorithms
	make tests
clean:
	rm $(OBJECTS) Tests/testAlgorithms.o Tests/TestsMain

compFuncs:
	gcc $(CFLAGS) -c -o compareFunctions.o compareFunctions.c

algorithms:
	gcc $(CFLAGS) -c -o algorithms.o algorithms.c

testAlgorithms: algorithms.o compareFunctions.o
	gcc $(CFLAGS) -c -o Tests/testAlgorithms.o Tests/testAlgorithms.c compareFunctions.o algorithms.o $(GLIB)

tests: Tests/testAlgorithms.o algorithms.o
	gcc $(CFLAGS) -o Tests/TestsMain Tests/testMain.c Tests/testAlgorithms.o $(OBJECTS) $(GLIB)
