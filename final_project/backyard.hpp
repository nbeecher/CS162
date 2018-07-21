#ifndef BACKYARD_HPP
#define BACKYARD_HPP


class Backyard : public Room {

public:

	Backyard();
	int genRand();
	int challenge();
	int healthDeplete();
	
private:

	int R;

};


#endif 
