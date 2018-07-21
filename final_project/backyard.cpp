#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "room.hpp"
#include "backyard.hpp"

using std::cin;
using std::cout;
using std::endl;

Backyard::Backyard()
{
	name = "Backyard";
}

int Backyard::genRand()
{
	int min = 1;
	int max = 100;

	R = rand() % max + 1;

	return R;
}

/*****************************************
challenge fucntion for the backyard
- 35% of the time the user will be distracted
by the dog and forget to pick up the sauce
******************************************/
int Backyard::challenge()
{
	int p = genRand();

	if (p < 35)
	{
		cout << "The dog greets you with his toy.  You spend time playing fetch with him and forget the task at hand." << endl;
		cout << "You did not find the sauce." << endl;
		return NULL;
	}
	else
	{
		cout << "The dog was busy chasing squirrels and didn't distract you!" << endl;
		cout << "You retrieved the sauce!!!" << endl;
		return 2;
		
	}
}

/*****************************************
health fucntion
if user fails then he loses points
******************************************/
int Backyard::healthDeplete()
{
	//if user fails in the backyard they get docked 2 points
	return 2;
}