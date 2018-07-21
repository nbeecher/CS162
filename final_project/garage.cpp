#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "room.hpp"
#include "garage.hpp"

using std::cin;
using std::cout;
using std::endl;

Garage::Garage()
{
	name = "Garage";

}

int Garage::genRand()
{
	int min = 1;
	int max = 100;

	R = rand() % max + 1;

	return R;
}

/*****************************************
challenge fucntion for the garage
- 35% of the time the user will be scared
by a mouse and not be able to collect the 
dough
******************************************/
int Garage::challenge()
{

	int p = genRand();

	if (p < 35)
	{
		cout << "AAAAHHHHH!  A mouse!!!" << endl;
		cout << "You are too scared to grab the dough and failed." << endl;
		return NULL;
	}
	else
	{
		cout << "The mouse didn't surprise you." << endl;
		cout << "You've retrieved the dough!!!" << endl;
		return 1;
	}

}

/*****************************************
health fucntion
if user is scared by mouse then he loses
hunger points
******************************************/
int Garage::healthDeplete()
{
	//if user fails in the garage they get docked 3 points
	return 3;
}