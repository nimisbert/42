.PHONY : clean
.INTERMEDIATE : 

VPATH =  src inc usr /mingw64/lib /mingw64/include

GXX = gcc
COMPILE_FLAGS = -std=gnu99
INCLUDE_FLAGS = -I ./inc

spiegelUT: spiegelUT.o spiegel3.o spiegel4.o spiegel5.o spiegel9.o spiegel10.o
	$(GXX) $^ -o $@
	mv $@ ./build/$@
	rm *.o
spiegelUT.o: spiegelUT.c
	$(GXX) -c $< $(INCLUDE_FLAGS)
spiegel3.o: spiegel3.c spiegel3.h
	$(GXX) -c $< $(INCLUDE_FLAGS)
spiegel4.o: spiegel4.c spiegel4.h
	$(GXX) -c $< $(INCLUDE_FLAGS)
spiegel5.o: spiegel5.c spiegel5.h
	$(GXX) -c $< $(INCLUDE_FLAGS)
spiegel9.o: spiegel9.c spiegel9.h
	$(GXX) -c $< $(INCLUDE_FLAGS)
spiegel10.o: spiegel10.c spiegel10.h
	$(GXX) -c $< $(INCLUDE_FLAGS)

clean:
	rm *.o *.exe