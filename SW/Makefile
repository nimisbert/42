# Phony
.PHONY: clean

# Variables
CC  = gcc
SRC = $(src/*.c)
INC = $(inc/*.h)
OBJ = $(SRC:.c=.o)

ptr: ptr.o

# Pattern matching
%.o: %.c 
	$(CC) -I inc/ -o $@ -c $< $(CF)

clean: 
	rm -rf *.o *.exe
