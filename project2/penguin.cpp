/*********************************************************************
** Program name:  Zoo Tycoon - Project 2
** Author:	Nicole Beecher
** Date:	10/22/2017
** Zoo tycoon is a game that allows players to run a zoo business. 
Different types of animals cost different prices, have different 
maintenance costs, and of course, return a different profit at the 
end of each day. For this game, the player will be the proud owner of 
a virtual zoo that has spaces to house tigers, penguins and turtles.
*********************************************************************/
#include <iostream>
#include "animal.hpp"
#include "penguin.hpp"



Penguin::Penguin()
{

}

int Penguin::getCost()
{
	int tCost = 1000;
	return tCost;

}

int Penguin::getFoodCost()
{
	int tCost = foodCost;
	return tCost;
}

int Penguin::getBabies()
{

	numBabies = 5;
	
	return numBabies;
}

int Penguin::getPayoff()
{
	int tPayoff = getCost() * .1;
	return tPayoff;
}

Penguin::~Penguin()
{

}