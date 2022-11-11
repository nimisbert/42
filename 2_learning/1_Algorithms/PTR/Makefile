.PHONY: clean
CC = gcc
CF = 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
OUT = ut

all: $(OUT)

ut: $(OBJ)
	$(CC) -o $@ $^
#ut.o : ?.h


%.o: %.c %.h
	$(CC) -o $@ -c $< $(CF)

clean: 
	rm -rf *.o *.exe