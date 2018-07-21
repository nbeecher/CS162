#ifndef BEDROOM_HPP
#define BEDROOM_HPP


class Bedroom : public Room {

public:

	Bedroom();	
	int challenge();
	int healthDeplete();


private:

	char guess;

};


#endif 
