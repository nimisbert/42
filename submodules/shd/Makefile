.PHONY : clean
.INTERMEDIATE : 
VPATH =  /mingw64/lib /mingw64/include

GPP = g++
GXX = gcc
COMPILE_FLAGS = -std=c++20
INCLUDE_FLAGS = -I.
LIBRARY_FLAGS = -L.

all: simpler

tutoBased:
# BUILD square library
	gcc -fpic square.c -c -I.
	gcc -fpic -o libsquare.so.1.2.3 square.o -shared -Wl,-soname,libsquare.so.1
	ln -s libsquare.so.1.2.3 libsquare.so.1
	ln -s libsquare.so.1 libsquare.so
# BUILD cube library dependent on square library
	gcc -fpic cube.c -L. libsquare.so -c -I.
	gcc -fpic -o libcube.so.1.2.3 cube.o libsquare.so -L. -shared -Wl,-soname,libcube.so.1
	ln -s libcube.so.1.2.3 libcube.so.1
	ln -s libcube.so.1 libcube.so
# BUILD main program using square and cube library
	gcc main.c -o main -I. libsquare.so libcube.so

simpleton:
# BUILD squares
	gcc -fpic square.c -c -I.
	gcc -fpic -o libsquare.so square.o -shared -W
# BUILD cube 
	gcc -fpic cube.c -c -I. 
	gcc -fpic -o libcube.so cube.o -L. libsquare.so -shared -W
# BUILD main
	gcc main.c -o main -I. -L. libsquare.so libcube.so

clean:
	rm *.o *.exe *.so*