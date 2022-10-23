.PHONY : clean
.INTERMEDIATE : 
VPATH = . /mingw64/lib /mingw64/include

GPP = g++
GXX = gcc
COMPILE_FLAGS = -std=c++20
INCLUDE_FLAGS = -I.
LIBRARY_FLAGS = -F.

all: main

main: main.c libnew.so libmyString.so
	gcc main.c -o main -I. -L. libnew.so libmyString.so

libmyString.so: myString.o libnew.so
	gcc -fpic -o libmyString.so myString.o -L. libnew.so -shared -W
myString.o: myString.c myString.h
	gcc -fpic myString.c -c -I.
	
libnew.so: new.o
	gcc -fpic -o libnew.so new.o -shared -W
new.o : new.c new.h
	gcc -fpic new.c -c -I.

clean:
	rm *.o *.exe *.so*