#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <string>
#include <sstream>
#include "room.hpp"
#include "bathroom.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

Bathroom::Bathroom()
{
	name = "Bathroom";
}

/*****************************************
challenge fucntion for the bathroom
the user must go through 3 areas to find the
peps - correct answer is to look behind the 
toilet
******************************************/
int Bathroom::challenge()
{
	while (choice != 3)
	{
		menu();
		while (1)
		{

			string line;
			getline(cin, line);
			if (!line.empty())
			{
				stringstream s(line);
				if (s >> choice && s.eof() && (choice > 0 && choice < 5))
				{
					break;
				}
			}
			cout << "Please enter number between 1 and 4: " << endl;
		}

		if (choice == 1)
		{
			cout << "Just some TUMS.  You might need those after your pizza." << endl;
			

		}

		else if (choice == 2)
		{
			cout << "Nothing here." << endl;
			
		}

		else if (choice == 3)
		{
			cout << "There's the pepperoni!" << endl;
			cout << "Don't worry... it's seeled in a package." << endl;
			return 5;
			
			break;
		}
		else
		{
			cout << "You chose to exit the bathroom." << endl;
			return NULL;
			break;

		}
	}


}

/*****************************************
health fucntion
if user fails then he loses points
******************************************/
int Bathroom::healthDeplete()
{
	//if user fails in the bathroom they get docked 1 points
	return 1;
}

void Bathroom::menu()
{
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "  1.  Open the cabinet                " << endl;
	cout << "  2.  Pull back the shower curtain    " << endl;
	cout << "  3.  Look behind the toilet          " << endl;
	cout << "  4.  Give up					       " << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << endl;
	cout << "Choose an action:" << endl;
}