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
#ifndef BOARD_HPP
#define BOARD_HPP


class Board{

public:
	Board(int r, int c, int x, int y);	
	void createBoard();
	void printBoard();
	void runAnt();
	void freeMemory();
	

private:
	
	int rows;
	int cols;
	int xcoord;
	int ycoord;	
	int yback, yforward;
	int xback, xforward;
	char **board;
	char black = '#';
	char white = ' ';
	char ant = '*';
	char rborder = '-';
	char cborder = '|';
	char tempColor = white;
	enum Direction {north, south, east, west};
	int face = north;
};

#endif 
