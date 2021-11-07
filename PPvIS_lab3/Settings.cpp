#include "Settings.h"

void settings::ocean_model(std::string path)
{
	std::fstream fs;

	try
	{
		fs.open(path, std::fstream::in);
		std::cout << "\nsuccessful open file!\n";
	}
	catch (const std::exception&)
	{
		std::cout << "\nFile open error!\n";
	}

	fs.close();
}
