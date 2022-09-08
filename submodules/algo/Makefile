.PHONY : clean

VPATH =  src inc usr /mingw64/lib /mingw64/include

GPP = g++
GXX = gcc
COMPILE_FLAGS = -std=c++20
INCLUDE_FLAGS = -I ./inc

listUT: listUT.o list.o
	$(GXX) $^ -o $@
	mv $@ ./build/$@
	rm *.o
listUT.o: listUT.c
	$(GXX) -c $< $(INCLUDE_FLAGS)
list.o: list.c list.h
	$(GXX) -c $< $(INCLUDE_FLAGS)

clean:
	rm *.o *.exe