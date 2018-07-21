#ifndef GARAGE_HPP
#define GARAGE_HPP


class Garage : public Room {

public:

	Garage();
	int genRand();
	int challenge();
	int healthDeplete();

private:

	int R;

};


#endif 
