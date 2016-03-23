CFLAGS = -g -Wall
GLIB = `pkg-config --cflags --libs glib-2.0`
OBJECTS = algorithms.o numbers.o strings.o

all:
	make numbers
	make strings
	make algorithms
	make testAlgorithms
	make tests
clean:
	rm $(OBJECTS) Tests/testAlgorithms.o Tests/TestsMain

numbers:
	gcc $(CFLAGS) -c -o numbers.o numbers.c

strings:
	gcc $(CFLAGS) -c -o strings.o strings.c

algorithms:
	gcc $(CFLAGS) -c -o algorithms.o algorithms.c

testAlgorithms: algorithms.o numbers.o strings.o
	gcc $(CFLAGS) -c -o Tests/testAlgorithms.o Tests/testAlgorithms.c numbers.o strings.o algorithms.o $(GLIB)

tests: Tests/testAlgorithms.o algorithms.o
	gcc $(CFLAGS) -o Tests/TestsMain Tests/testMain.c Tests/testAlgorithms.o $(OBJECTS) $(GLIB)
