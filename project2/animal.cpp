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

Animal::Animal()
{
	
}


int Animal::getCost()
{
	return cost;
}

int Animal::getBabies()
{
	return numBabies;
}

int Animal::getFoodCost()
{
	return foodCost;
}

int Animal::getPayoff()
{
	return payoff;
}

Animal::~Animal()
{

}