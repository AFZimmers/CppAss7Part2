#Makefile for Assignment 7 part 2
#Alexander Zimmermann ZMMALE001

CC=g++
CCFLAGS=-std=c++11

SRC = $(wildcard src/*.cpp *.h)
OBJ = $(SRC:.cpp=.o)

PROG = ANN

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o ANN
	
.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SRC) > incl.defs

clean:
	rm -f *.o
	rm -f ANN
