# Phony
.PHONY: clean

VPATH = src include

# Variables
CC  = gcc
CF  = -g
SRC = ./src
INC = ./include
OBJ = OBJ = $(SRC:.c=.o)

main_ptr.out: main_ptr.o
main_rec.out: main_rec.o
main_sll.out: main_sll.o sll.o

%.out: %.o
	$(CC) $(CF) -I$(INC) $^ -o $@
%.o: %.c %.h
	$(CC) $(CF) -I$(INC) -c $@ $^

clean: 
	rm -rf *.o *.exe *.out *.gch
