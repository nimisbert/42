# Phony
.PHONY: clean

# Variables
CC  = gcc
SRC = $(./*.c)
INC = $(./*.h)
OBJ = $(SRC:.c=.o)

ptr: ptr.o
rec: rec.o
sll: main_sll.o sll.o

# Pattern matching
# not using Makefile buitlin, pattern matching, for exercice puproses
%.o: %.c %.h
	$(CC) -I $(INC) -o $@ -c $^ $(CF)
%.o: %.c
	$(CC) -I $(INC) -o $@ -c $< $(CF)
clean: 
	rm -rf *.o *.exe
