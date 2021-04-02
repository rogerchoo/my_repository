CC = g++
CFLAGS = -c -g
LDFLAGS = 
OBJECTS = TicTacToe.o

all : program

program : $(OBJECTS)
	$(CC) $(LDFLAGS) -o TicTacToe TicTacToe.o

TicTacToe.o : TicTacToe.cpp
	$(CC) $(CFLAGS) TicTacToe.cpp

clean :
	del $(OBJECTS) *.exe