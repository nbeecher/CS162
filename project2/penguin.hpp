#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "animal.hpp"

class Penguin : public Animal {

public:

	Penguin();
	int getCost();
	int getFoodCost();
	int getPayoff();
	int getBabies();

	~Penguin();

};


#endif 
