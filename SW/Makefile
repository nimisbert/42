# Phony
.PHONY: clean

VPATH = src include

# Variables
CC  = gcc
CF  = -g
SRC = ./src
INC = ./include
OBJ = OBJ = $(SRC:.c=.o)

main_ptr.out: main_ptr.o		# Chapitre 2 : manipulation de pointeurs
main_rec.out: main_rec.o		# Chapitre 3 : recursivitee
main_sll.out: main_sll.o sll.o  # Chapitre 5 : listes simplement chainees
dll.o : dll.c dll.h 			# Chapitre 5 : listes doublement chainees TODO test

%.out: %.o
	$(CC) $(CF) -I$(INC) $^ -o $@
%.o: %.c %.h
	$(CC) $(CF) -I$(INC) -c $@ $^

clean: 
	rm -rf *.o *.exe *.out *.gch
