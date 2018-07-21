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
#include "penguin.hpp"
#include "zoo.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

Zoo::Zoo(){}


void Zoo::startGame()
{
	tPin = new int[tigers];
	pPin = new int[penguins];
	tuPin = new int[turtles];

	cout << "Starting money in your bank is " << bank << endl;
	cout << "In order to start the game you need to buy 3 types of animals:" << endl;
	cout << "Tigers cost $10,000 each, Penguins cost $1,000 each, Turtles cost $100 each" << endl;

	//Ask user how many tigers they want to purchase
	cout << endl;
	cout << "How many tigers do you want to purchase? ($10,000 ea)" << endl;
	while (1)
	{
		//cin.ignore(100, '\n');
		string line;
		getline(cin, line);
		if (!line.empty())
		{
			stringstream x(line);
			if (x >> tigers && x.eof() && (tigers > 0 && tigers < 10))
			{
				break;
			}
		}
		cout << "Please enter a number greater than 0 and less than 10 (don't spend all your money in one place): " << endl;
	}		
	

	//sets newly bought tigers to 0 - they will turn 1 on first day of game
	for (int i = 0; i < tigers; i++)	
		{				
			tPin[i] = 0;
		}

	//looks for tigers in array and recalcs bank
	for (int i = 0; i < tigers; i++) 
		{		
			bank = bank - t->getCost();
		}


	cout << endl;
	cout << "Bank Account: " << bank;
	cout << endl;
	
	/////////////////////////////////////////////////////////////////////////////////////////////

	//ask user how many penguins they want to purchase
	cout << endl;
	cout << "How many penguins do you want to purchase? ($1,000 ea)" << endl;
	while (1)
	{
		//cin.ignore(100, '\n');
		string line;
		getline(cin, line);
		if (!line.empty())
		{
			stringstream x(line);
			if (x >> penguins && x.eof() && penguins > 0)
			{
				break;
			}
		}
		cout << "Please enter a number greater than 0: " << endl;
	}

	//sets newly bought penguins to 0 - they will turn 1 on first day of game
	for (int i = 0; i < penguins; i++)
	{
		pPin[i] = 0;
	}

	//looks for penguins in array and recalcs bank
	for (int i = 0; i < penguins; i++)
	{
		bank = bank - p->getCost();
	}


	cout << endl;
	cout << "Bank Account: " << bank;
	cout << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////

	//ask user how many turtles they want to purchase
	cout << endl;
	cout << "How many turtles do you want to purchase? ($100 ea)" << endl;
	while (1)
	{
		//cin.ignore(100, '\n');
		string line;
		getline(cin, line);
		if (!line.empty())
		{
			stringstream x(line);
			if (x >> turtles && x.eof() && turtles > 0)
			{
				break;
			}
		}
		cout << "Please enter a number greater than 0: " << endl;
	}

	//sets newly bought turtles to 0 - they will turn 1 on first day of game
	for (int i = 0; i < turtles; i++)
	{
		tuPin[i] = 0;
	}

	//looks for turtles in array and recalcs bank
	for (int i = 0; i < turtles; i++)
	{
		bank = bank - tu->getCost();
	}



	cout << endl;
	cout << "Bank Account: " << bank;
	cout << endl;
	
}

void Zoo::runGame()
{
	//loop to run game
	while (1)
	{
		srand(time(NULL));

		//subtracts feeding costs for tigers from bank
		for (int i = 0; i < tigers; i++)
		{
			tb = t->getFoodCost();
			bank = bank - tb;
		}

		//subtracts feeding costs for penguins from bank
		for (int i = 0; i < penguins; i++)
		{
			pb = p->getFoodCost();
			bank = bank - pb;
		}

		//subtracts feeding costs for turtles from bank
		for (int i = 0; i < turtles; i++)
		{
			tub = tu->getFoodCost();
			bank = bank - tub;
		}
		

		cout << endl;
		cout << "Day: " << days << endl;
		cout << endl;
		cout << tb * tigers << " dollars was deducted from your bank account to feed the tigers. ($50 per tiger)" << endl;
		cout << pb * penguins << " dollars was deducted from your bank account to feed the penguins. ($10 per penguins)" << endl;
		cout << tub * turtles << " dollars was deducted from your bank account to feed the turtles. ($5 per turtles)" << endl;
		cout << endl;
		cout << "Bank Account: " << bank << endl;
		cout << endl;		
		
		//increase tiger age by 1		
		for (int i = 0; i < tigers; i++)
		{						
			tPin[i] = tPin[i] + 1;
		}

		//increase penguins age by 1		
		for (int i = 0; i < penguins; i++)
		{
			pPin[i] = pPin[i] + 1;
		}

		//increase turtles age by 1		
		for (int i = 0; i < turtles; i++)
		{
			tuPin[i] = tuPin[i] + 1;
		}

		//prints tiger array
		cout << endl;
		cout << "Tigers: ";
		for (int i = 0; i < tigers; i++)
		{			
			cout << tPin[i] << "  ";
		}

		//prints penguins array
		cout << endl;
		cout << "Penguins: ";
		for (int i = 0; i < penguins; i++)
		{
			cout << pPin[i] << "  ";
		}

		//prints turtles array
		cout << endl;
		cout << "Turtles: ";
		for (int i = 0; i < turtles; i++)
		{
			cout << tuPin[i] << "  ";
		}



		//call random even
		cout << endl;
		randomEvent();


		
		//calcuate profit for day based on payoff for tigers
		for (int i = 0; i < tigers; i++)
		{
			tp = t->getPayoff();
			bank = bank + tp;
		}		
		cout << endl;
		cout << "Your payoff for tigers today is $" << tigers * tp << " and will be added to your bank account." << endl;
		

		//calcuate profit for day based on payoff for penguins
		for (int i = 0; i < penguins; i++)
		{
			pp = p->getPayoff();
			bank = bank + pp;
		}		
		cout << "Your payoff for penguins today is $" << penguins * pp << " and will be added to your bank account." << endl;
		

		//calcuate profit for day based on payoff for turtles
		for (int i = 0; i < turtles; i++)
		{
			tup = tu->getPayoff();
			bank = bank + tup;
		}		
		cout << "Your payoff for turtles today is $" << turtles * tup << " and will be added to your bank account." << endl;
		

		cout << endl;
		cout << "Bank Account: " << bank << endl;
		//ask user if they want to buy an adult tiger
		cout << endl;
		cout << "Would you like to buy an adult Tiger? (y or n)" << endl;
		do {
			cin >> buyT;
			if ((buyT == 'y') || (buyT == 'n'))
			{
				break;
			}
			else
			{
				cout << "Please enter y or n: " << endl;
			}
		} while ((buyT != 'y' && buyT != 'n'));

		if (buyT == 'y')
		{
			tigers = tigers + 1;
			int mTigers = tigers - 1;

			for (int i = mTigers; i < tigers; i++)
			{
				tPin[i] = 2;
			}

			bank = bank - t->getCost();
			cout << "Bank Account: " << bank << endl;
		}


		cout << endl;
		cout << "Bank Account: " << bank << endl;
		//ask user if they want to buy an adult penguin
		cout << endl;
		cout << "Would you like to buy an adult Penguin? (y or n)" << endl;
		do {
			cin >> buyP;
			if ((buyP == 'y') || (buyP == 'n'))
			{
				break;
			}
			else
			{
				cout << "Please enter y or n: " << endl;
			}
		} while ((buyP != 'y' && buyP != 'n'));

		if (buyP == 'y')
		{
			penguins = penguins + 1;
			int mPenguins = penguins - 1;

			for (int i = mPenguins; i < penguins; i++)
			{
				pPin[i] = 2;
			}

			bank = bank - p->getCost();
			cout << "Bank Account: " << bank << endl;
		}


		cout << endl;
		cout << "Bank Account: " << bank << endl;
		//ask user if they want to buy an adult turtle
		cout << endl;
		cout << "Would you like to buy an adult Turtle? (y or n)" << endl;
		do {
			cin >> buyTu;
			if ((buyTu == 'y') || (buyTu == 'n'))
			{
				break;
			}
			else
			{
				cout << "Please enter y or n: " << endl;
			}
		} while ((buyTu != 'y' && buyTu != 'n'));

		if (buyTu == 'y')
		{
			turtles = turtles + 1;
			int mTurtles = turtles - 1;

			for (int i = mTurtles; i < turtles; i++)
			{
				tuPin[i] = 2;
			}

			bank = bank - tu->getCost();
			cout << "Bank Account: " << bank << endl;
		}



		cout << "End of day Bank Account: " << bank << endl;
		cout << endl;


	

		cout << "Continue to next day? " << endl;
		cout << "Type 1 to continue or 2 to quit" << endl;
		while (1)
		{
			cin.ignore(100, '\n');
			string line;
			getline(cin, line);
			if (!line.empty())
			{
				stringstream x(line);
				if (x >> quit && x.eof() && (quit == 1 || quit == 2))
				{
					break;
				}
			}
			cout << "Please enter number 1 or 2: " << endl;
		}

		if (quit == 2) 
		{
			break;
		}

		//ends game if user runs out of money
		if (bank < 0)
		{
			cout << endl;
			cout << "You went bankrupt.  Game over." << endl;
			break;
		}

		//system("cls");
		days++;

	}//end of while loop

	
	
}


void Zoo::sickness()
{
	cout << endl;

	srand(time(NULL));

	int chooseA;

	chooseA = rand() % 3 + 1;

	//kill a tiger
	if (chooseA == 1)
	{
		cout << endl;
		cout << "A tiger died!" << endl;
		int randT;
		randT = rand() % tigers + 1;
		for (int i = 0; i < tigers; i++)
		{
			tPin[randT] = 0;			
		}

		//prints tiger array with 0 for death spot
		for (int i = 0; i < tigers; i++)
		{
			cout << tPin[i] << "  ";

		}

		for (int i = 0; i < tigers; i++)
		{
			if (tPin[i] == 0)
			{
				tPin[i] = tPin[i + 1];
				tPin[i + 1] = 0;
				
			}
		}
		--tigers;

		//prints tiger array after death
		cout << endl;
		for (int i = 0; i < tigers; i++)
		{
			cout << tPin[i] << "  ";

		}

	}

	//kill a penguin
	else if (chooseA == 2)
	{
		cout << endl;
		cout << "A penguin died!" << endl;
		int randP;
		randP = rand() % penguins + 1;
		for (int i = 0; i < penguins; i++)
		{
			pPin[randP] = 0;
		}

		//prints penguin array with 0 for death spot
		for (int i = 0; i < penguins; i++)
		{
			cout << pPin[i] << "  ";

		}

		for (int i = 0; i < penguins; i++)
		{
			if (pPin[i] == 0)
			{
				pPin[i] = pPin[i + 1];
				pPin[i + 1] = 0;

			}
		}
		--penguins;

		//prints penguins array after death
		cout << endl;
		for (int i = 0; i < penguins; i++)
		{
			cout << pPin[i] << "  ";

		}

	}

	//kill a turtle
	else if (chooseA == 3)
	{
		cout << endl;
		cout << "A turtle died!" << endl;
		int randTu;
		randTu = rand() % turtles + 1;
		for (int i = 0; i < turtles; i++)
		{
			tuPin[randTu] = 0;
		}

		//prints turtle array with 0 for death spot
		for (int i = 0; i < turtles; i++)
		{
			cout << tuPin[i] << "  ";

		}

		for (int i = 0; i < turtles; i++)
		{
			if (tuPin[i] == 0)
			{
				tuPin[i] = tuPin[i + 1];
				tuPin[i + 1] = 0;

			}
		}
		--turtles;

		//prints turtle array after death
		cout << endl;
		for (int i = 0; i < turtles; i++)
		{
			cout << tuPin[i] << "  ";

		}

	}

}

void Zoo::zAttend()
{
	srand(time(NULL));

	cout << endl;
	cout << "There's a boom in Zoo attendance today!" << endl;
	int rBonus;
	rBonus = rand() % (501 - 250) + 250;
	cout << "You made " << rBonus << " for each Tiger, and ";
	rBonus = rBonus * tigers;
	cout << rBonus << " will be deposited into your bank account!" << endl;
	bank = bank + rBonus;	

}

void Zoo::babyEvent()
{
	cout << endl;

	srand(time(NULL));

	int chooseA;

	chooseA = rand() % 3 + 1;

	//see if any tigers can have a baby - age >= 3
	if (chooseA == 1)
	{
		//return true if array contains atleast 1 adult tiger
		bool aTigers;

		for (int i = 0; i < tigers; i++)
		{
			if (tPin[i] >= 3)
			{
				aTigers = true;
			}
			else
			{
				aTigers = false;
			}
		}

		if (aTigers == true)
		{
			cout << "A baby tiger has been born!" << endl;
			tigers = tigers + t->getBabies();
			int mTigers = tigers - 1;

			for (int i = mTigers; i < tigers; i++)
			{
				tPin[i] = 0;
			}

		}
		else if (aTigers == false)
		{
			//check if a penguin is old enough
			bool aPenguin;

			for (int i = 0; i < penguins; i++)
			{
				if (pPin[i] >= 3)
				{
					aPenguin = true;
				}
				else
				{
					aPenguin = false;
				}
			}

			if (aPenguin == true)
			{
				cout << "Five baby penguins have been born!" << endl;
				penguins = penguins + p->getBabies();
				int mPenguin = penguins - 1;

				for (int i = mPenguin; i < penguins; i++)
				{
					pPin[i] = 0;
				}

			}
			else if (aPenguin == false)
			{
				//check if a turtle is old enough
				bool aTurtles;

				for (int i = 0; i < turtles; i++)
				{
					if (tuPin[i] >= 3)
					{
						aTurtles = true;
					}
					else
					{
						aTurtles = false;
					}
				}

				if (aTurtles == true)
				{
					cout << "Ten baby turtles have been born!" << endl;
					turtles = turtles + tu->getBabies();
					int mTurtles = turtles - 1;

					for (int i = mTurtles; i < turtles; i++)
					{
						tuPin[i] = 0;
					}

				}
				else
				{
					cout << "No animal is old enough to have babies." << endl;
				}
			}
		}

	}
			

	//see if any penguins can have a baby - age >= 3
	else if (chooseA == 2)
	{
		//return true if array contains atleast 1 adult penguin
		bool aPenguin;

		for (int i = 0; i < penguins; i++)
		{
			if (pPin[i] >= 3)
			{
				aPenguin = true;
			}
			else
			{
				aPenguin = false;
			}
		}

		if (aPenguin == true)
		{
			cout << "Five baby penguins have been born!" << endl;
			penguins = penguins + p->getBabies();
			int mPenguin = penguins - 5;

			for (int i = mPenguin; i < penguins; i++)
			{
				pPin[i] = 0;
			}

		}
		else if (aPenguin == false)
		{
			//check if there is an adult tiger
			bool aTigers;

			for (int i = 0; i < tigers; i++)
			{
				if (tPin[i] >= 3)
				{
					aTigers = true;
				}
				else
				{
					aTigers = false;
				}
			}

			if (aTigers == true)
			{
				cout << "A baby tiger has been born!" << endl;
				tigers = tigers + t->getBabies();
				int mTigers = tigers - 1;

				for (int i = mTigers; i < tigers; i++)
				{
					tPin[i] = 0;
				}

			}
			else if (aTigers == false)
			{
				//check if there is an adult turtle
				bool aTurtles;

				for (int i = 0; i < turtles; i++)
				{
					if (tuPin[i] >= 3)
					{
						aTurtles = true;
					}
					else
					{
						aTurtles = false;
					}
				}

				if (aTurtles == true)
				{
					cout << "Ten baby turtles have been born!" << endl;
					turtles = turtles + tu->getBabies();
					int mTurtles = turtles - 1;

					for (int i = mTurtles; i < turtles; i++)
					{
						tuPin[i] = 0;
					}

				}
				else
				{
					cout << "No animals are old enough to have babies." << endl;
				}
			}
		}

	}

	//see if any turtles can have a baby - age >= 3
	else if (chooseA == 3) 
	{
		//return true if array contains atleast 1 adult turtle
		bool aTurtles;

		for (int i = 0; i < turtles; i++)
		{
			if (tuPin[i] >= 3)
			{
				aTurtles = true;
			}
			else
			{
				aTurtles = false;
			}
		}

		if (aTurtles == true)
		{
			cout << "Ten baby turtles have been born!" << endl;
			turtles = turtles + tu->getBabies();
			int mTurtles = turtles - 10;

			for (int i = mTurtles; i < turtles; i++)
			{
				tuPin[i] = 0;
			}

		}
		else if (aTurtles == false)
		{
			//check if there are any adult tigers
			bool aTigers;

			for (int i = 0; i < tigers; i++)
			{
				if (tPin[i] >= 3)
				{
					aTigers = true;
				}
				else
				{
					aTigers = false;
				}
			}

			if (aTigers == true)
			{
				cout << "A baby tiger has been born!" << endl;
				tigers = tigers + t->getBabies();
				int mTigers = tigers - 1;

				for (int i = mTigers; i < tigers; i++)
				{
					tPin[i] = 0;
				}

			}
			else if (aTigers == false)
			{
				//check if there are any adult penguins
				bool aPenguin;

				for (int i = 0; i < penguins; i++)
				{
					if (pPin[i] >= 3)
					{
						aPenguin = true;
					}
					else
					{
						aPenguin = false;
					}
				}

				if (aPenguin == true)
				{
					cout << "Five baby penguins have been born!" << endl;
					penguins = penguins + p->getBabies();
					int mPenguin = penguins - 1;

					for (int i = mPenguin; i < penguins; i++)
					{
						pPin[i] = 0;
					}

				}
				else
				{
					cout << "No animals are old enough to have babies." << endl;
				}
			}
		}
	}


}

void Zoo::randomEvent()
{
	srand(time(NULL));

	int chooseA = 1;

	chooseA = rand() % 3 + 1;

	if (chooseA == 1)
	{
		cout << "Oh no! A sickness occured at the zoo." << endl;
		sickness();		
	}
	else if (chooseA == 2)
	{		
		zAttend();
	}
	else
	{
		babyEvent();
	}
}

Zoo::~Zoo()
{

}

void Zoo::freeMemory() {
	//Free the dynamically allocated memory

	delete[] tPin;
	delete[] pPin;
	delete[] tuPin;

}