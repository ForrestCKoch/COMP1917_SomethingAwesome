CFLAGS = -g -Wall
GLIB = `pkg-config --cflags --libs glib-2.0`
OBJECTS = algorithms.o numbers.o strings.o
TEST_OBJECTS = Tests/testNumbers.o Tests/testStrings.o

all:
	make numbers
	make strings
	make algorithms
	make testNumbers
	make testStrings
	make tests
clean:
	rm $(OBJECTS) $(TEST_OBJECTS) Tests/TestsMain

numbers:
	gcc $(CFLAGS) -c -o numbers.o numbers.c

strings:
	gcc $(CFLAGS) -c -o strings.o strings.c

algorithms:
	gcc $(CFLAGS) -c -o algorithms.o algorithms.c

testNumbers: algorithms.o numbers.o
	gcc $(CFLAGS) -c -o Tests/testNumbers.o Tests/testNumbers.c algorithms.o numbers.o $(GLIB)

testStrings: algorithms.o strings.o
	gcc $(CFLAGS) -c -o Tests/testStrings.o Tests/testStrings.c algorithms.o strings.o $(GLIB)

tests: Tests/testNumbers.o Tests/testStrings.o
	gcc $(CFLAGS) -o Tests/TestsMain Tests/testMain.c $(TEST_OBJECTS) $(OBJECTS) $(GLIB)
