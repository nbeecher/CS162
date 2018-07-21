#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "room.hpp"
#include <vector>

class Gameplay {

public:

	Gameplay();
	void maps();
	void getNextMove();
	void mainPlay();
	void showItems();
	void checkHealth(int i);
	~Gameplay();

private:

	Room* position;	

	Room* garage;
	Room* kitchen;
	Room* backyard;
	Room* livingroom;
	Room* bedroom;
	Room* bathroom;

	std::vector<int> items;

	int c;
	int kitchenCounter = 0;
	int doughCounter = 0;
	int sauceCounter = 0;
	int cheeseCounter = 0;
	int basilCounter = 0;
	int pepCounter = 0;
	int playerHealth = 10;
};


#endif 
