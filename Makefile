.PHONY : clean

all:
	+$(MAKE) -C submodules/math
	+$(MAKE) -C submodules/tuner

clean:
	rm *.o *.exe