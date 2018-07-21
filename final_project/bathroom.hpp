#ifndef BATHROOM_HPP
#define BATHROOM_HPP


class Bathroom : public Room {

public:

	Bathroom();
	void menu();
	int challenge();
	int healthDeplete();

private:

	int choice;

};


#endif 
