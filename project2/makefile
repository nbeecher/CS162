PROGS := project2

all: $(PROGS)

project2: main.cpp animal.o tiger.o penguin.o turtle.o zoo.o
	g++ -std=c++11 main.cpp animal.o tiger.o penguin.o turtle.o zoo.o -o project2

animal.o: animal.cpp animal.hpp
	g++ -c animal.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -c tiger.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -c penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -c turtle.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -c zoo.cpp

clean: 
	rm -f $(PROGS) *.o