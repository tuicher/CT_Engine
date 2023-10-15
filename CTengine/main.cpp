#include "CTEngine.hpp"


// STD libs
#include <stdexcept>
#include <cstdlib>
#include <iostream>

int main() 
{
	CTE::CTEngine eng{};

	try 
	{
		eng.run();
	} 
	catch (const std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
		return  EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}