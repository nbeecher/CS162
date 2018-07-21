#ifndef KITCHEN_HPP
#define KITCHEN_HPP


class Kitchen : public Room {

public:

	Kitchen();	
	int challenge();
	int healthDeplete();

private:

	char input;

};


#endif 
