#ifndef TIGER_HPP
#define TIGER_HPP

#include "animal.hpp"

class Tiger : public Animal {

public:
	
	Tiger();
	int getCost();
	int getFoodCost();
	int getPayoff();
	int getBabies();

	~Tiger();	

};


#endif 
