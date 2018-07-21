/***********************************************************************
** Program name:  Final Project
** Author:	Nicole Beecher
** Date:	12/05/2017
** Description: Final project that implements all knowledge learned over
	entire term.
	Pizza game - User can move around spaces in the house collecting
	ingredients to make a pizza.  If the user collects all the items
	and makes their way back to the kitchen to cook the pizza before
	their hunger runs out then they win the game.
************************************************************************/

#include <iostream>
#include <cstdlib> 
#include <ctime>

#include "gameplay.hpp"
#include "garage.hpp"
#include "room.hpp"
#include "bedroom.hpp"
#include "bathroom.hpp"

using std::cout;
using std::cin;
using std::endl;

void introduction();


int main()
{
	srand(time(NULL));

	introduction();
	
	Gameplay g;
	while (1)
	{
		g.mainPlay();
		
	}

	//system("pause");
	return 0;
}

void introduction()
{
	cout << "Welcome!" << endl;
	cout << "It's midnight during finals week and you're starving." << endl;
	cout << "You go to the kitchen to make a pizza." << endl;
	cout << "What the...." << endl;
	cout << "It appears your gluten-free, organic, free-range, vegan, hipster roommate ";
	cout << "hid your pizza ingredients throughout the house." << endl;
	cout << "You must search the house for all the ingredients before ";
	cout << "you can make your pizza." << endl;
	cout << "Once you find all the ingredients (dough, sauce, cheese, pepperoni, and basil) ";
	cout << "make your way back to the kitchen to bake your pizza and win the game." << endl;
	cout << "But beware, each time you fail to find an ingredient you hunger level depletes." << endl;
	cout << "If it gets to 0 you lose the game." << endl;
	cout << "Good luck, may the sauce be with you." << endl;
	cout << endl;
	cout << "OH! I almost forgot.  X marks your spot in the house." << endl;
	cout << "So, as you can see you start in the Kitchen." << endl;
	cout << endl;

}

