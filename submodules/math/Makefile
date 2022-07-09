.PHONY : clean
.INTERMEDIATE : cmplx.o complex.o mandelbrot.o svgReaderUT.o 

VPATH =  src inc usr /mingw64/lib /mingw64/include

GPP = g++
GXX = gcc
COMPILE_FLAGS = -std=c++20
INCLUDE_FLAGS = -I ./inc
LIBRARY_FLAGS =  -L/d/msys64/mingw64/lib  -lSDL2main -lmingw32 -lSDL2main -lSDL2 -mwindows 

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

cmplxUT: cmplxUT.o complex.o
	$(GPP) $^ $(LIBRARY_FLAGS) -o $@
	mv $@ ./build/$@
cmplxUT.o: cmplxUT.cpp
	$(GPP) -c $< $(INCLUDE_FLAGS) 
complex.o: complex.cpp
	$(GPP) -c $< $(INCLUDE_FLAGS) 

mandelbrot: mandelbrot.o
	$(GPP) $^ $(LIBRARY_FLAGS) -o $@
	mv $@ ./build/$@
mandelbrot.o: mandelbrot.cpp
	$(GPP) -c $< $(COMPILE_FLAGS)

fourier_series: fourier_series.o
	$(GPP) $^ $(LIBRARY_FLAGS) -o $@
	mv $@ ./build/$@
fourier_series.o: fourier_series.cpp
	$(GPP) -c $< $(COMPILE_FLAGS)

svgReaderUT: svgReaderUT.o
	$(GPP) $^ -o $@
	mv $@ ./build/$@
svgReaderUT.o: svgReaderUT.cpp
	$(GPP) -c $< $(COMPILE_FLAGS)

huffmanUT: huffmanUT.o huffman.o
	$(GXX) $^ -o $@
	mv $@ ./build/$@
huffmanUT.o: huffmanUT.c
	$(GXX) -c $< $(INCLUDE_FLAGS)
huffman.o: huffman.c huffman.h
	$(GXX) -c $< $(INCLUDE_FLAGS)

clean:
	rm *.o *.exe