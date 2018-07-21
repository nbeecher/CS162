
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
#include "turtle.hpp"



Turtle::Turtle()
{

}

int Turtle::getCost()
{
	int tCost = 100;
	return tCost;

}

int Turtle::getFoodCost()
{
	int tCost = foodCost * .5;
	return tCost;
}

int Turtle::getBabies()
{

	numBabies = 10;

	return numBabies;
}

int Turtle::getPayoff()
{
	int tPayoff = getCost() * .05;
	return tPayoff;
}

Turtle::~Turtle()
{

}