#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "room.hpp"
#include "livingroom.hpp"

using std::cin;
using std::cout;
using std::endl;

Livingroom::Livingroom()
{
	name = "Living Room";
}

/*****************************************
challenge fucntion for the living room
if the user says yes to turning off the tv
then the roommate gets up and reveals the 
cheese -
otherwise they fail to find the cheese
******************************************/
int Livingroom::challenge()
{
	cout << "Do you want to turn off the TV?" << endl;
	cin >> input;

	if (input == 'N' || input == 'n')
	{
		cout << "Nothing happened.  Keep searching." << endl;
		return NULL;
	}
	
	else if (input == 'Y' || input == 'y')
	{
		cout << "Your roommate gets up from the couch and... VOILA!  There's the cheese." << endl;
		return 3;
		
	}
	else
	{
		cout << "Nothing happened.  Keep searching." << endl;
		return NULL;
	}
}

/*****************************************
health fucntion
if user fails then he loses points
******************************************/
int Livingroom::healthDeplete()
{
	//if user fails in the Living room they get docked 2 points
	return 2;
}