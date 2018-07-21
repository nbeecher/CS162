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
#include "tiger.hpp"



Tiger::Tiger()
{ 
	
}

/*
void Tiger::Age(int n)
{
	age = n;
}

int Tiger::getAge()
{
	return age;
}*/


int Tiger::getCost()
{
	int tCost = 10000;
	return tCost;

}

int Tiger::getFoodCost()
{
	int tCost = foodCost * 5;
	return tCost;
}

int Tiger::getBabies()
{
	
	numBabies = 1;
	
	return numBabies;
}

int Tiger::getPayoff()
{
	int tPayoff = getCost() * .2;
	return tPayoff;
}

Tiger::~Tiger()
{

}