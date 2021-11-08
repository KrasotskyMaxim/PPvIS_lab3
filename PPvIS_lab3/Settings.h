#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace settings
{
	const int OCEAN_LENGHT = 3;
	const int OCEAN_WIDTH = 3;
	const int LIFE_IN_CELL = 4;
	std::vector<std::vector<int>> changed_cells;

	//const int DPLANKTON = 3, DHERRING = 5, DSHARK = 7, DWHALE = 9, 
	const int CYCLES = 10;

	void ocean_model(std::string path);
	bool border(int row, int column, int cell_position);
	bool changed_cell(int row, int column, int cell_position);

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

