#include <iostream>
#include <string>
#include "room.hpp"


Room::Room()
{
	up = NULL;
	down = NULL;
	left = NULL;
	right = NULL;
}

std::string Room::getName()
{
	return name;
}

int Room::challenge()
{
	return NULL;
}

int Room::healthDeplete()
{
	return NULL;
}

void Room::setUp(Room* next)
{
	up = next;
}
void Room::setDown(Room* next)
{
	down = next;
}
void Room::setLeft(Room* next)
{
	left = next;
}
void Room::setRight(Room* next)
{
	right = next;
}

Room* Room::getUp()
{
	return up;
}
Room* Room::getDown()
{
	return down;
}
Room* Room::getLeft()
{
	return left;
}
Room* Room::getRight()
{
	return right;
}

Room::~Room()
{
	delete up;
	delete down;
	delete left;
	delete right;
}