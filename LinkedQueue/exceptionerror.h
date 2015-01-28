#ifndef OUTOFBOUND_H
#define OUTOFBOUND_H
#include <iostream>
class OutofBounds
{
public:
	OutofBounds()
	{
		std::cerr << "Out of Bounds" << std::endl;
		//std::exit(1);
	}
};

class NoMem
{
public:
	NoMem(){
		std::cerr << "No Memory" << std::endl;
		//std::exit(1);
	}

};
#endif
