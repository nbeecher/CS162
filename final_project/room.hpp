#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room {

public:

	Room();
	virtual std::string getName();
	virtual int challenge();
	virtual int healthDeplete();
	virtual void setUp(Room* next);
	virtual void setDown(Room* next);
	virtual void setLeft(Room* next);
	virtual void setRight(Room* next);
	virtual Room* getUp();
	virtual Room* getDown();
	virtual Room* getLeft();
	virtual Room* getRight();

	virtual ~Room();

	Room* up;
	Room* down;
	Room* left;
	Room* right;

protected:

	std::string name;	
	
};


#endif 
