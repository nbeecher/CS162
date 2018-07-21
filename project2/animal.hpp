#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {

public:
	Animal();	
	virtual int getCost();
	virtual int getBabies();
	virtual int getFoodCost();
	virtual int getPayoff();

	~Animal();

protected:
	
	int cost = 0;
	int numBabies = 0;
	const int foodCost = 10;
	int payoff = 0;

};


#endif 
