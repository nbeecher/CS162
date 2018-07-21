#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <string>
#include <sstream>
#include "room.hpp"
#include "bedroom.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

Bedroom::Bedroom()
{
	name = "Bedroom";
}

/*****************************************
challenge fucntion for the bedroom
a monster comes out from under the bed and
asks the user a riddle
if the user gets it right then the monster
gives up the basil
correct answer is 0
******************************************/
int Bedroom::challenge()
{
	cout << "'RRRRAH!" << endl;  
	cout << "I'm the monster from under your bed and I'm holding your basil hostage...'" << endl;
	cout << "'Unless you can answer me a riddle....'" << endl;
	cout << "'What number do you get when you multiply all of the" << endl;
	cout << "numbers on a telephone's number pad?'" << endl;

	cout << endl;
	cout << "I will be nice and give you multiple choices:" << endl;
	cout << "A. 362880" << endl;
	cout << "B. 0" << endl;
	cout << "C. 100" << endl;
	cout << "D. 36000" << endl;

	cin >> guess;

	if (guess == 'A' || guess == 'a')
	{
		cout << endl;
		cout << "That's wrong." << endl;
		cout << "'HA HA HA... your precious basil stays with me' - Monster " << endl;
		return NULL;
		
	}
	else if (guess == 'B' || guess == 'b')
	{
		cout << endl;
		cout << "That's correct!" << endl;
		cout << "You won your basil from the monster!" << endl;
		return 4;
	}
	else if (guess == 'C' || guess == 'c')
	{
		cout << endl;
		cout << "That's wrong." << endl;
		cout << "'HA HA HA... your precious basil stays with me' - Monster " << endl;
		return NULL;

	}
	if (guess == 'D' || guess == 'd')
	{
		cout << endl;
		cout << "That's wrong." << endl;
		cout << "'HA HA HA... your precious basil stays with me' - Monster " << endl;
		return NULL;

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
int Bedroom::healthDeplete()
{
	//if user fails in the bedroom they get docked 1 points
	return 1;
}