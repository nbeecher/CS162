#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "room.hpp"
#include "kitchen.hpp"

using std::cin;
using std::cout;
using std::endl;

Kitchen::Kitchen()
{
	name = "Kitchen";
}

/*****************************************
challenge fucntion for the kitchen
- checks to see if user has all the
ingredients.
if they do they win
otherwise they keep searching the house
******************************************/
int Kitchen::challenge()
{
		
	cout << "Are you ready to bake your pizza and win the game??  (Y or N)" << endl;
	cin >> input;
	if (input == 'N' || input == 'n')
	{
		cout << "Keep collecting the tasty ingredients" << endl;	
		return NULL;
		
	}
	else if (input == 'Y' || input == 'y')
	{
		return 6;	
	}
	else
	{
		cout << "Not sure what you're saying dude.  You must be getting delirious from hunger." << endl;
		return NULL;
	}
	
}

/*****************************************
no health depletion for kicthen
******************************************/
int Kitchen::healthDeplete()
{
	return NULL;
}