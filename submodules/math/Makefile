.PHONY : clean
.INTERMEDIATE : cmplx.o complex.o mandelbrot.o svgReaderUT.o 

VPATH =  src inc usr /mingw64/lib /mingw64/include

GPP = g++
GXX = gcc
COMPILE_FLAGS = -std=c++20
INCLUDE_FLAGS = -I ./inc

spiegelUT: spiegelUT.o spiegel3.o spiegel4.o
	$(GXX) $^ -o $@
	mv $@ ./build/$@
	rm *.o
spiegelUT.o: spiegelUT.c
	$(GXX) -c $< $(INCLUDE_FLAGS)
spiegel3.o: spiegel3.c spiegel3.h
	$(GXX) -c $< $(INCLUDE_FLAGS)
spiegel4.o: spiegel4.c spiegel4.h
	$(GXX) -c $< $(INCLUDE_FLAGS)


clean:
	rm *.o *.exe