.PHONY : clean

all:
	+$(MAKE) -C submodules/math
	+$(MAKE) -C submodules/algo
	+$(MAKE) -C submodules/abst
#	+$(MAKE) -C submodules/tuner

clean:
	rm *.o *.exe