PROGS := project1

all: $(PROGS)

project1: Main.cpp Board.o
	g++ -std=c++11 Main.cpp Board.o -o project1

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp

clean: 
	rm -f $(PROGS) *.o