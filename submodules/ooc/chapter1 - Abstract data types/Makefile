.PHONY : clean
.INTERMEDIATE : 
VPATH =  src inc usr /mingw64/lib /mingw64/include

GPP = g++
GXX = gcc
COMPILE_FLAGS = -std=c++20
INCLUDE_FLAGS = -I ./

all: staticHeapSet dynamicMemBag bitmapImpl

staticHeapSet: heapImpl.c
	$(GXX) $< $(INCLUDE_FLAGS)
	mv a.exe $@
dynamicMemBag: bagImpl.c
	$(GXX) $< $(INCLUDE_FLAGS)
	mv a.exe $@
bitmapImpl: bitmapImpl.c
	$(GXX) $< $(INCLUDE_FLAGS)
	mv a.exe $@

clean:
	rm *.exe