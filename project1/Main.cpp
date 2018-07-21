/*********************************************************************
** Program name:  Langton's Ant - Project 1
** Author:	Nicole Beecher
** Date:	10/08/2017
** This program moves an ant around an user defined board based on
specific movement rules.  If the space is white the ant moves right 90
degrees and if the space is black the ant moves left 90 degrees.  The
program then turns the previous space to the opposite color.  The ant
will do this until its reached the user defined number of steps.
*********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "Board.hpp"
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

void Menu();
void Menu2();

int main()
{
	int rows;
	int cols;
	int steps;
	int xcoord;
	int ycoord;
	int choice;
	int counter = 0;
	bool gameStatus;	

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


	if (choice == 1) {
		gameStatus = true;
		//system("cls");
	}
	else if (choice == 2) {
		cout << "You chose to quit.  Goodbye. " << endl;
		//system("pause");
		return 0;
	}


	while (gameStatus == true) {
		//Ask user for size of game board - number of rows and columns
		cout << "You will choose your game board size" << endl;
		cout << "How many rows: ";
		while (!(cin >> rows)) {
			cout << "Rows must be an number: " << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		cout << "How many columns: ";
		while (!(cin >> cols)) {
			cout << "Columns must be an number: " << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		
		//asks user for number of steps during simulation
		cout << "How many steps during simulation?: ";
		while (!(cin >> steps)) {
			cout << "Steps must be an number: " << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}


		//asks user for starting row
		cout << "Where do you want the ant to start? " << endl;
		cout << "Row: ";
		while (1)
		{
			cin.ignore(100, '\n');
			string line;
			getline(cin, line);
			if (!line.empty())
			{
				stringstream x(line);
				if (x >> xcoord && x.eof() && (xcoord <= rows && xcoord > 0))
				{
					break;
				}
			}
			cout << "Please enter number less than or equal to rows and greater than 0: " << endl;
		}
		
		//ask user for starting column
		cout << "Column: ";
		while (1)
		{

			string line;
			getline(cin, line);
			if (!line.empty())
			{
				stringstream y(line);
				if (y >> ycoord && y.eof() && (ycoord <= cols && ycoord > 0))
				{
					break;
				}
			}
			cout << "Please enter number less than or equal to columns and greater than 0: " << endl;
		}


		cout << endl;

		//create board
		Board bo(rows, cols, xcoord, ycoord);
		bo.createBoard();
	
		//system("cls");

		//start the ants movements until number of steps is achieved
		while (steps != 0) {
			bo.printBoard();
			bo.runAnt();
			//system("pause");
			//system("cls");
			steps--;
		}

		cout << "Game over!" << endl;

		//system("pause");
		//system("cls");

		//free memory
		bo.freeMemory();

		//call menu 2 that allows player to play again or quit
		Menu2();
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

		if (choice == 1) {
			gameStatus = true;
			//system("cls");
		}
		else if (choice == 2) {
			cout << "You chose to quit.  Goodbye. " << endl;
			//system("pause");
			return 0;
		}

	}//end of while loop for whole game


	Board freeMemory();
	return 0;
}


void Menu() {

	cout << "********** Menu **********" << endl;
	cout << "1.  Start Langton's Ant simulation" << endl;
	cout << "2.  Quit" << endl;
	cout << "**************************" << endl;
}
void Menu2() {

	cout << "********** Menu **********" << endl;
	cout << "1.  Play Again?" << endl;
	cout << "2.  Quit" << endl;
	cout << "**************************" << endl;
}


