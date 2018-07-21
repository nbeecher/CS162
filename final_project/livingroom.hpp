#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP


class Livingroom : public Room {

public:

	Livingroom();	
	int challenge();
	int healthDeplete();

private:

	char input;

};


#endif 
