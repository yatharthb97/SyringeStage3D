
#include "grid.hpp"
#include<iostream>


int main()
{
	RasterGrid rgrid(10, 5);

	for(unsigned int i = 0; i < 100; i++)
	{
		unsigned int* state = rgrid.next();
		std::cout << state[0] << "," << state[1] << '\n';

	}
	//std::ofstream file("rgrid")
}


