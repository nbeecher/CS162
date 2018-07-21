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
#include "Board.hpp"
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

/*Pull values from user input and assign them to private variables*/
Board::Board(int r, int c, int x, int y) {
	rows = r;
	cols = c;
	xcoord = x;
	ycoord = y;	
	rows = rows + 2;
	cols = cols + 2;
}

void Board::createBoard() {

	board = new char *[rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new char[cols];
	}

	//default start (empty board / ant starting position)
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == xcoord && j == ycoord) {
					board[i][j] = ant;
			}else{
				board[i][j] = white;

			}
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = rborder;
		}
	}


	for (int i = rows - 1; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = rborder;
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 1; j++) {
			board[i][j] = cborder;
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = cols - 1; j < cols; j++) {
			board[i][j] = cborder;
		}
	}
}	



void Board::printBoard() {

	for (int a = 0; a < rows; a++) {
		for (int k = 0; k < rows; k++) {
			cout << board[a][k];
		}
		cout << endl;
	}

}

void Board::runAnt() {	

	if (face == north && tempColor == white) {

		//check next column for color and store
		yforward = ycoord + 1;

		if (board[xcoord][yforward] == white && board[xcoord][yforward] != cborder) {
			tempColor = white;
		}
		else if (board[xcoord][yforward] == black && board[xcoord][yforward] != cborder) {
			tempColor = black;
		}

		if (board[xcoord][yforward] != cborder) {
			//since the ant will be going right we add 1 to the column for ycoord and print ant.
			ycoord++;
			board[xcoord][ycoord] = ant;


			//sets the value for the last cell to yback to change color.
			yback = ycoord - 1;

			board[xcoord][yback] = black;

			//updates direction ant is facing
			face = east;
		}
		else {
			face = rand() % 4;
		}
	}


	else if (face == east && tempColor == white) {

		//sets the value for the next x cell to yforward to check for color
		xforward = xcoord + 1;

		if (board[xforward][ycoord] == white && board[xforward][ycoord] != rborder) {
			tempColor = white;
		}
		else if (board[xforward][ycoord] == black && board[xforward][ycoord] != rborder) {
			tempColor = black;
		}

		if (board[xforward][ycoord] != rborder) {
			//since the ant will be going right we add 1 to the column for xcoord and print ant.
			xcoord++;
			board[xcoord][ycoord] = ant;


			//sets the value for the last cell to xback to change color.
			xback = xcoord - 1;

			board[xback][ycoord] = black;

			//updates direction ant is facing
			face = south;
		}
		else {
			face = rand() % 4;
		}
	}


	else if (face == south && tempColor == white) {

		//sets the value for the next y cell to yforward to check for color
		yforward = ycoord - 1;

		if (board[xcoord][yforward] == white && board[xcoord][yforward] != cborder) {
			tempColor = white;
		}
		else if (board[xcoord][yforward] == black && board[xcoord][yforward] != cborder) {
			tempColor = black;
		}

		if (board[xcoord][yforward] != cborder) {
			//since the ant will be going right we add 1 to the column for ycoord and print ant.
			ycoord--;
			board[xcoord][ycoord] = ant;


			//sets the value for the last cell to yback to change color.
			yback = ycoord + 1;

			board[xcoord][yback] = black;

			//updates direction ant is facing
			face = west;
		}
		else {
			face = rand() % 4;
		}
	}

	else if (face == west && tempColor == white) {

		//sets the value for the next x cell to yforward to check for color
		xforward = xcoord - 1;

		if (board[xforward][ycoord] == white && board[xforward][ycoord] != rborder) {
			tempColor = white;
		}
		else if (board[xforward][ycoord] == black && board[xforward][ycoord] != rborder) {
			tempColor = black;
		}

		if (board[xforward][ycoord] != rborder) {
			//since the ant will be going right we add 1 to the column for xcoord and print ant.
			xcoord--;
			board[xcoord][ycoord] = ant;


			//sets the value for the last cell to xback to change color.
			xback = xcoord + 1;

			board[xback][ycoord] = black;

			//updates direction ant is facing
			face = north;
		}
		else {
			face = rand() % 4;
		}
	}

	/*****************************************************************/

	else if (face == north && tempColor == black) {

		//check next column for color and store
		yforward = ycoord - 1;

		if (board[xcoord][yforward] == white && board[xcoord][yforward] != cborder) {
			tempColor = white;
		}
		else if (board[xcoord][yforward] == black && board[xcoord][yforward] != cborder) {
			tempColor = black;
		}

		if (board[xcoord][yforward] != cborder) {

			//since the ant will be going right we add 1 to the column for ycoord and print ant.
			ycoord--;
			board[xcoord][ycoord] = ant;


			//sets the value for the last cell to yback to change color.
			yback = ycoord + 1;

			board[xcoord][yback] = white;

			//updates direction ant is facing
			face = west;
		}
		else {
			face = rand() % 4;
		}
	}


	else if (face == east && tempColor == black) {

		//sets the value for the next x cell to yforward to check for color
		xforward = xcoord - 1;

		if (board[xforward][ycoord] == white && board[xforward][ycoord] != rborder) {
			tempColor = white;
		}
		else if (board[xforward][ycoord] == black && board[xforward][ycoord] != rborder) {
			tempColor = black;
		}

		if (board[xforward][ycoord] != rborder) {
			//since the ant will be going right we add 1 to the column for xcoord and print ant.
			xcoord--;
			board[xcoord][ycoord] = ant;


			//sets the value for the last cell to xback to change color.
			xback = xcoord + 1;

			board[xback][ycoord] = white;

			//updates direction ant is facing
			face = south;
		}
		else {
			face = rand() % 4;
		}
	}


	else if (face == south && tempColor == black) {

		//sets the value for the next y cell to yforward to check for color
		yforward = ycoord + 1;

		if (board[xcoord][yforward] == white && board[xcoord][yforward] != cborder) {
			tempColor = white;
		}
		else if (board[xcoord][yforward] == black && board[xcoord][yforward] != cborder) {
			tempColor = black;
		}

		if (board[xcoord][yforward] != cborder) {

			//since the ant will be going right we add 1 to the column for ycoord and print ant.
			ycoord++;
			board[xcoord][ycoord] = ant;


			//sets the value for the last cell to yback to change color.
			yback = ycoord - 1;

			board[xcoord][yback] = white;

			//updates direction ant is facing
			face = east;
		}
		else {
			face = rand() % 4;
		}
	}

	else //(face == west && tempColor == black) 
	{

		//sets the value for the next x cell to yforward to check for color
		xforward = xcoord + 1;

		if (board[xforward][ycoord] == white && board[xforward][ycoord] != rborder) {
			tempColor = white;
		}
		else if (board[xforward][ycoord] == black && board[xforward][ycoord] != rborder) {
			tempColor = black;
		}

		if (board[xforward][ycoord] != rborder) {

			//since the ant will be going right we add 1 to the column for xcoord and print ant.
			xcoord++;
			board[xcoord][ycoord] = ant;


			//sets the value for the last cell to xback to change color.
			xback = xcoord - 1;

			board[xback][ycoord] = white;

			//updates direction ant is facing
			face = south;
		}
		else {
			face = rand() % 4;
		}

	}

	
}

void Board::freeMemory() {
	//Free the dynamically allocated memory
	for (int i = 0; i < rows; i++) {		
			delete[] board[i];		
	}

	delete[] board;

}








