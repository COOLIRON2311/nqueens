OFLAGS=-O3 -march=native
# OFLAGS=-g -O0
all: build test

.ONESHELL:
framework:
	cd catch2
	g++ $(OFLAGS) -c catch_amalgamated.cpp -o catch_amalgamated.o

main:
	g++ $(OFLAGS) main.cpp -o a
	./a.exe

build:
	g++ $(OFLAGS) tests.cpp catch2\catch_amalgamated.o -Icatch2 -o tests

test:
	.\tests.exe --benchmark-samples 1

clean:
	rm *.exe
