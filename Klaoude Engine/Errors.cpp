#include "Errors.h"

#include <iostream>

namespace KlaoudeEngine
{
	void fatalError(std::string errorString)
	{
		std::cout << "[Fatal ERROR] : " << errorString << std::endl;
		system("Pause");
		exit(1);
	}
}