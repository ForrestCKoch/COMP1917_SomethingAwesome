CFLAGS = -g -Wall
GLIB = `pkg-config --cflags --libs glib-2.0`
MODULES = numbers.o strings.o
OBJECTS = algorithms.o numbers.o strings.o modules.o core.o
TEST_OBJECTS = Tests/testNumbers.o Tests/testStrings.o

all:
	make numbers
	make strings
	make modules
	make algorithms
	make core
	make main
	make testNumbers
	make testStrings
	make tests
clean:
	rm ./Main $(OBJECTS) $(TEST_OBJECTS) Tests/TestsMain Tests/testNumbersOutput.txt

modules: $(MODULES)
	gcc $(CFLAGS) -c -o modules.o modules.c

numbers:
	gcc $(CFLAGS) -c -o numbers.o numbers.c

strings:
	gcc $(CFLAGS) -c -o strings.o strings.c

algorithms:
	gcc $(CFLAGS) -c -o algorithms.o algorithms.c

core: modules.o algorithms.o
	gcc $(CFLAGS) -c -o core.o core.c

main: $(OBJECTS)
	gcc $(CFLAGS) -o Main main.c $(OBJECTS)

testNumbers: algorithms.o numbers.o
	gcc $(CFLAGS) -c -o Tests/testNumbers.o Tests/testNumbers.c  $(GLIB)

testStrings: algorithms.o strings.o
	gcc $(CFLAGS) -c -o Tests/testStrings.o Tests/testStrings.c $(GLIB)

tests: Tests/testNumbers.o Tests/testStrings.o
	gcc $(CFLAGS) -o Tests/TestsMain Tests/testMain.c $(TEST_OBJECTS) $(OBJECTS) $(GLIB)
