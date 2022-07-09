.PHONY : clean
.INTERMEDIATE : utilityUT.o callbackUT.o cmplx.o

VPATH =  src include

GXX = gcc
GPP = g++
INCLUDEFLAGS = -I ./include 
PORTAUDIOFLAGS = -I ./opt/portaudio/src/common -lportaudio

utilityUT: utilityUT.o
	$(GXX) $^ -o $@ $(PORTAUDIOFLAGS)
	mv $@ ./build/$@
utilityUT.o: utilityUT.c
	$(GXX) -c $< $(PORTAUDIOFLAGS)

callbackUT: callbackUT.o
	$(GXX) $^ -o $@ $(PORTAUDIOFLAGS)
	mv $@ ./build/$@
callbackUT.o: callbackUT.c
	$(GXX) -c $< $(PORTAUDIOFLAGS)

clean:
	rm *.o *.exe