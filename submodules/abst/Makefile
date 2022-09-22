.PHONY : clean

VPATH =  src inc usr /mingw64/lib /mingw64/include

GPP = g++
GXX = gcc
COMPILE_FLAGS = -std=c++20
INCLUDE_FLAGS = -I ./inc

ut: ut.o peripheral.o driver.o library.o
	$(GXX) $^ -o $@
	mv $@ ./build/$@
	rm *.o
ut.o: UT.c
	$(GXX) -c $< $(INCLUDE_FLAGS)
library.o: library.c library.h
	$(GXX) -c $< $(INCLUDE_FLAGS)
driver.o: driver.c driver.h
	$(GXX) -c $< $(INCLUDE_FLAGS)
peripheral.o: peripheral.c peripheral.h
	$(GXX) -c $< $(INCLUDE_FLAGS)

clean:
	rm *.o *.exe