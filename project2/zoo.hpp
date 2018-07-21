#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

class Zoo {

public:

	Zoo();
	void startGame();
	void runGame();
	void sickness();
	void zAttend();
	void babyEvent();
	void randomEvent();
	void freeMemory();

	~Zoo();

private:	

	int bank = 100000;
	int tigers = 0;
	int penguins = 0;
	int turtles = 0;

	int days = 1;
	int quit;

	int tSize = 10;
	int pSize = 10;
	int tuSize = 10;
	int t1;
	int pp;
	int tp;
	int tup;
	int tb;
	int pb;
	int tub;
	char buyT;
	char buyP;
	char buyTu;

	Tiger tiger;	
	Penguin penguin;
	Turtle turtle;

	Animal* t = &tiger;
	Animal* p = &penguin;
	Animal* tu = &turtle;

	int *tPin;
	int *pPin;
	int *tuPin;

};

#endif 
