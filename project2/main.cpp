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
#include <string>
#include <sstream>
#include <cstdlib> 
#include <ctime>
#include "animal.hpp"
#include "tiger.hpp"
#include "zoo.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;


void Menu();

int main()
{
	int choice;
	srand(time(NULL));

	Menu();

	//user enters 1 or 2 to start the game or quit
	while (1)
	{

		string line;
		getline(cin, line);
		if (!line.empty())
		{
			stringstream s(line);
			if (s >> choice && s.eof() && (choice == 1 || choice == 2))
			{
				break;
			}
		}
		cout << "Please enter number 1 or 2: " << endl;
	}

	//system("cls");

	if (choice == 1) {		

		Zoo z;

		z.startGame();
		z.runGame();
		z.freeMemory();
	}

	if (choice == 2) {
		cout << "You chose to quit." << endl;
		//system("pause");

		return 0;
	}

	//system("pause");
	return 0;
}

void Menu() {

	cout << "############################################" << endl;
	cout << "#                                          #" << endl;
	cout << "#	 Welcome to Zoo Tycoon		   #" << endl;
	cout << "#                                          #" << endl;
	cout << "#	     Type 1 to PLAY		   #" << endl;
	cout << "#	     Type 2 to QUIT		   #" << endl;
	cout << "#                                          #" << endl;
	cout << "############################################" << endl;

}