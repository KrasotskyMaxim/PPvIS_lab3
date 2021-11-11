#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace settings
{
	const int OCEAN_LENGHT = 5;
	const int OCEAN_WIDTH = 5;
	const int LIFE_IN_CELL = 4;
	std::vector<std::vector<int>> changed_cells;
	std::vector<std::vector<int>> reproducted_plankton;

	const int DSHARK = 7; // , DHERRING = 5, DWHALE = 9,
	const int CYCLES = 11;

	void ocean_model(std::string path);
	bool border(int row, int column);
	bool changed_cell(int row, int column, int cell_position);

	enum State
	{
		EMPTY,
		PLANKTON,
		//HERRING,
		SHARK,
		//WHALE,
		STATES
	};

	enum Size
	{
		NONE,
		SMALL,
		MEDIUM,
		BIG,
		SIZES
	};

	enum Sex
	{
		NOT,
		FEMALE,
		MALE,
		SEXES
	};
}

