#pragma once
#include <iostream>
#include <string>
#include <fstream>


namespace settings
{
	const int OCEAN_LENGHT = 3;
	const int OCEAN_WIDTH = 3;
	const int LIFE_IN_CELL = 4;

	const int DPLANKTON = 3, DHERRING = 5, DSHARK = 7, DWHALE = 9, CYCLES = 10;

	void ocean_model(std::string path);

	enum State
	{
		EMPTY,
		PLANKTON,
		//HERRING,
		//SHARK,
		//WHALE,
		STATES
	};
}

