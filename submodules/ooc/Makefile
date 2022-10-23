.PHONY : clean
.INTERMEDIATE : 
VPATH =  src inc usr /mingw64/lib /mingw64/include

GPP = g++
GXX = gcc
COMPILE_FLAGS = -std=c++20
INCLUDE_FLAGS = -I ./inc

all:
#CHAPTER 1 : Abstract data types
	+$(MAKE) -C 'chapter1 - Abstract data types'
	+$(MAKE) -C 'chapter2 - Dynamic linkage'

clean:
	rm *.o *.exe