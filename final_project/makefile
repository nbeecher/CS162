PROGS := final

all: $(PROGS)

final: main.cpp backyard.o bathroom.o bedroom.o gameplay.o garage.o kitchen.o livingroom.o room.o
	g++ -std=c++11 main.cpp backyard.o bathroom.o bedroom.o gameplay.o garage.o kitchen.o livingroom.o room.o -o final

backyard.o: backyard.cpp backyard.hpp
	g++ -c backyard.cpp

bathroom.o: bathroom.cpp bathroom.hpp
	g++ -c bathroom.cpp

bedroom.o: bedroom.cpp bedroom.hpp
	g++ -c bedroom.cpp

gameplay.o: gameplay.cpp gameplay.hpp
	g++ -c gameplay.cpp

garage.o: garage.cpp garage.hpp
	g++ -c garage.cpp

kitchen.o: kitchen.cpp kitchen.hpp
	g++ -c kitchen.cpp

livingroom.o: livingroom.cpp livingroom.hpp
	g++ -c livingroom.cpp

room.o: room.cpp room.hpp
	g++ -c room.cpp

clean: 
	rm -f $(PROGS) *.o