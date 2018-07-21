#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "animal.hpp"

class Turtle : public Animal {

public:

	Turtle();	
	int getCost();
	int getFoodCost();
	int getPayoff();
	int getBabies();

	~Turtle();

};


#endif 
