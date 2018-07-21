#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "room.hpp"
#include "garage.hpp"
#include "backyard.hpp"
#include "bathroom.hpp"
#include "bedroom.hpp"
#include "kitchen.hpp"
#include "livingroom.hpp"
#include "gameplay.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;


Gameplay::Gameplay()
{
	garage = new Garage();
	kitchen = new Kitchen();
	backyard = new Backyard();
	livingroom = new Livingroom();
	bedroom = new Bedroom();
	bathroom = new Bathroom();

	garage->setDown(kitchen);
	kitchen->setUp(garage);
	kitchen->setDown(livingroom);
	kitchen->setLeft(backyard);
	backyard->setRight(kitchen);
	livingroom->setUp(kitchen);
	livingroom->setDown(bathroom);
	livingroom->setRight(bedroom);
	bathroom->setUp(livingroom);
	bedroom->setLeft(livingroom);

	position = kitchen;

}

/*****************************************
Prints the map and current user position
******************************************/
void Gameplay::maps()
{
	if (position->getName() == "Kitchen")
	{
		cout << "                ______________" << endl;
		cout << "               |    Garage    |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << " ______________|______________|" << endl;
		cout << "|   Backyard   |   Kitchen    |" << endl;
		cout << "|              |              |" << endl;
		cout << "|              |      X       |" << endl;
		cout << "|______________|______________|______________" << endl;
		cout << "               | Living room  |    Bedroom   |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |______________|______________|" << endl;
		cout << "               |   Bathroom   |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << "               |______________|" << endl;
	}
	else if (position->getName() == "Garage")
	{		
		cout << "                ______________" << endl;
		cout << "               |    Garage    |" << endl;
		cout << "               |              |" << endl;
		cout << "               |      X       |" << endl;
		cout << " ______________|______________|" << endl;
		cout << "|   Backyard   |   Kitchen    |" << endl;
		cout << "|              |              |" << endl;
		cout << "|              |              |" << endl;
		cout << "|______________|______________|______________" << endl;
		cout << "               | Living room  |    Bedroom   |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |______________|______________|" << endl;
		cout << "               |   Bathroom   |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << "               |______________|" << endl;
	}
	else if (position->getName() == "Backyard")
	{
		cout << "                ______________" << endl;
		cout << "               |    Garage    |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << " ______________|______________|" << endl;
		cout << "|   Backyard   |   Kitchen    |" << endl;
		cout << "|              |              |" << endl;
		cout << "|      X       |              |" << endl;
		cout << "|______________|______________|______________" << endl;
		cout << "               | Living room  |    Bedroom   |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |______________|______________|" << endl;
		cout << "               |   Bathroom   |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << "               |______________|" << endl;
	}
	else if (position->getName() == "Living Room")
	{
		cout << "                ______________" << endl;
		cout << "               |    Garage    |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << " ______________|______________|" << endl;
		cout << "|   Backyard   |   Kitchen    |" << endl;
		cout << "|              |              |" << endl;
		cout << "|              |              |" << endl;
		cout << "|______________|______________|______________" << endl;
		cout << "               | Living room  |    Bedroom   |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |      X       |              |" << endl;
		cout << "               |______________|______________|" << endl;
		cout << "               |   Bathroom   |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << "               |______________|" << endl;
	}
	else if (position->getName() == "Bedroom")
	{
		cout << "                ______________" << endl;
		cout << "               |    Garage    |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << " ______________|______________|" << endl;
		cout << "|   Backyard   |   Kitchen    |" << endl;
		cout << "|              |              |" << endl;
		cout << "|              |              |" << endl;
		cout << "|______________|______________|______________" << endl;
		cout << "               | Living room  |    Bedroom   |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |              |       X      |" << endl;
		cout << "               |______________|______________|" << endl;
		cout << "               |   Bathroom   |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << "               |______________|" << endl;
	}
	else
	{
		cout << "                ______________" << endl;
		cout << "               |    Garage    |" << endl;
		cout << "               |              |" << endl;
		cout << "               |              |" << endl;
		cout << " ______________|______________|" << endl;
		cout << "|   Backyard   |   Kitchen    |" << endl;
		cout << "|              |              |" << endl;
		cout << "|              |              |" << endl;
		cout << "|______________|______________|______________" << endl;
		cout << "               | Living room  |    Bedroom   |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |              |              |" << endl;
		cout << "               |______________|______________|" << endl;
		cout << "               |   Bathroom   |" << endl;
		cout << "               |              |" << endl;
		cout << "               |      X       |" << endl;
		cout << "               |______________|" << endl;
	}
}

/*****************************************
asks user for next move in the house-
validates input-
sets new position
******************************************/
void Gameplay::getNextMove()
{
	cout << endl;
	cout << "You are in the " << position->getName() << endl;
	cout << "Choose next movement: " << endl;
	cout << endl;
	if (position->getUp() != NULL)
	{
		cout << "1. Up" << endl;
	}
	if (position->getDown() != NULL)
	{
		cout << "2. Down" << endl;
	}
	if (position->getLeft() != NULL)
	{
		cout << "3. Left" << endl;
	}
	if (position->getRight() != NULL)
	{
		cout << "4. Right" << endl;
	}
	cout << "5. Quit" << endl;
	cout << endl;

	//input validation
	while (1)
	{
		//cin.clear();
		string line;
		getline(cin, line);
		if (!line.empty())
		{
			stringstream x(line);
			if (x >> c && x.eof() && (c >= 1 && c < 6))
			{
				break;
			}
			else
			{
				cout << "Please enter a number between 1 and 5: " << endl;
				cin.clear();
				cin.ignore();				
			}
		}

	}

	if (c == 1)
	{
		if (position->getUp() == NULL)
		{
			cout << "You can't move up. Try again." << endl;

		}
		else
		{
			position = position->getUp();
		}
		
	}
	else if (c == 2)
	{
		if (position->getDown() == NULL)
		{
			cout << "You can't move down. Try again." << endl;

		}
		else
		{
			position = position->getDown();
		}
	}
	else if (c == 3)
	{
		if (position->getLeft() == NULL)
		{
			cout << "You can't move left. Try again." << endl;

		}
		else
		{
			position = position->getLeft();
		}
	}
	else if (c == 4)
	{
		if (position->getRight() == NULL)
		{
			cout << "You can't move right. Try again." << endl;

		}
		else
		{
			position = position->getRight();
		}
	}
	else
	{		
		exit(1);
		//return;
	}

	
}

/*****************************************
loops through gameplay until user wins,
loses, or quits
******************************************/
void Gameplay::mainPlay()
{
	while(1)
	{
		cout << endl;
		cout << "Hunger level: " << playerHealth << endl;
		cout << endl;

		if (position->getName() == "Kitchen")
		{
			maps();

			//Begining of game doesn't ask you if you're ready
			//to bake the pizza for obvious reasons
			if (kitchenCounter == 0)
			{
				//getNextMove();
				kitchenCounter++;
			}
			else
			{
				//user claims they are ready to bake their pizza
				//but we need to check they have all their ingredients
				if (position->challenge() == 6)
				{
					if (items.size() > 4)
					{
						cout << endl;
						showItems();
						cout << endl;
						cout << "You have all the ingredients to bake your pizza!" << endl;
						cout << "You won!!" << endl;
						//system("pause");
						exit(1);
					}
					else
					{
						cout << endl;
						showItems();
						cout << endl;
						cout << endl;
						cout << "You do not have all the ingredients." << endl;
						cout << "Keep trying." << endl;
					}
				}
			}
			
			getNextMove();
		}
		else if (position->getName() == "Garage")
		{
			
			maps();	

			//Verifies user hasn't collected dough yet
			if (doughCounter == 0)
			{				
				if (position->challenge() == 1)
				{
					items.push_back(1);
					doughCounter++;
				}
				else
				{
					//Player fails to retrieve item and takes a hit to health
					playerHealth = playerHealth - position->healthDeplete();
					checkHealth(playerHealth);
				}
			}
			//if user has collected dough a message will pop up telling them so and to 
			//choose another room
			else
			{
				cout << endl;
				cout << "You have already collected the dough." << endl;
				cout << "Try another room." << endl;
				cout << endl;
			}

			//cout << endl;
			//showItems();
			cout << endl;
			getNextMove();
		}
		else if (position->getName() == "Backyard")
		{
			maps();

			//Verifies user hasn't collected dough yet
			if (sauceCounter == 0)			{

				if (position->challenge() == 2)
				{
					items.push_back(2);
					sauceCounter++;
				}
				else
				{
					//Player fails to retrieve item and takes a hit to health
					playerHealth = playerHealth - position->healthDeplete();
					checkHealth(playerHealth);
				}
			}
			//if user has collected dough a message will pop up telling them so and to 
			//choose another room
			else
			{
				cout << endl;
				cout << "You have already collected the sauce." << endl;
				cout << "Try another room." << endl;
				cout << endl;
			}
			//cout << endl;
			//showItems();
			cout << endl;
			getNextMove();
		}
		else if (position->getName() == "Living Room")
		{
			maps();

			//Verifies user hasn't collected dough yet
			if (cheeseCounter == 0)
			{
				if (position->challenge() == 3)
				{
					items.push_back(3);
					cheeseCounter++;
				}
				else
				{
					//Player fails to retrieve item and takes a hit to health
					playerHealth = playerHealth - position->healthDeplete();
					checkHealth(playerHealth);
				}
			}
			//if user has collected dough a message will pop up telling them so and to 
			//choose another room
			else
			{
				cout << endl;
				cout << "You have already collected the cheese." << endl;
				cout << "Try another room." << endl;
				cout << endl;
			}
			//cout << endl;
			//showItems();
			cout << endl;
			getNextMove();
		}
		else if (position->getName() == "Bedroom")
		{
			maps();

			//Verifies user hasn't collected dough yet
			if (basilCounter == 0)
			{
				if (position->challenge() == 4)
				{
					items.push_back(4);
					basilCounter++;
				}
				else
				{
					//Player fails to retrieve item and takes a hit to health
					playerHealth = playerHealth - position->healthDeplete();
					checkHealth(playerHealth);
				}
			}
			//if user has collected dough a message will pop up telling them so and to 
			//choose another room
			else
			{
				cout << endl;
				cout << "You have already collected the basil." << endl;
				cout << "Try another room." << endl;
				cout << endl;
			}
			//cout << endl;
			//showItems();
			cout << endl;
			getNextMove();
		}
		else if (position->getName() == "Bathroom")
		{
			maps();

			//Verifies user hasn't collected dough yet
			if (pepCounter == 0)
			{
				if (position->challenge() == 5)
				{
					items.push_back(5);
					pepCounter++;
				}
				else
				{
					//Player fails to retrieve item and takes a hit to health
					playerHealth = playerHealth - position->healthDeplete();
					checkHealth(playerHealth);
				}
			}
			//if user has collected dough a message will pop up telling them so and to 
			//choose another room
			else
			{
				cout << endl;
				cout << "You have already collected the pepperoni." << endl;
				cout << "Try another room." << endl;
				cout << endl;
			}
			//cout << endl;
			//showItems();
			cout << endl;
			getNextMove();
		}


	}//end of while

	return;

}//end of function

 /*****************************************
prints items in vector (ingredients)
 ******************************************/
void Gameplay::showItems()
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == 1)
		{
			cout << "Dough" <<  " ";
		}
		else if (items[i] == 2)
		{
			cout << "Sauce" << " ";
		}
		else if (items[i] == 3)
		{
			cout << "Cheese" << " ";
		}
		else if (items[i] == 4)
		{
			cout << "Basil" << " ";
		}
		else if (items[i] == 5)
		{
			cout << "Pepperoni" << " ";
		}
	}
}

/*****************************************
This function checks if health is 0 or less
than 0
******************************************/
void Gameplay::checkHealth(int i)
{
	if (i <= 0)
	{
		cout << "Your hunger level is too much bare, so you ";
		cout << "order a pizza and call it a night." << endl;
		cout << "You lost the game." << endl;
		//system("pause");
		exit(1);
	}
}

Gameplay::~Gameplay()
{
	delete position;
	delete garage;
	delete kitchen;
	delete backyard;
	delete livingroom;
	delete bedroom;
	delete bathroom;
}
