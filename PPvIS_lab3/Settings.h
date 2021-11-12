#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace settings
{
	const int OCEAN_LENGHT = 7;
	const int OCEAN_WIDTH = 7;
	const int LIFE_IN_CELL = 4;
	std::vector<std::vector<int>> changed_cells;
	std::vector<std::vector<int>> reproducted_plankton;

	const int DSHARK = 7; 
	const int DWHALE = 9;
	const int CYCLES = 11;

	void ocean_model(std::string path);
	bool border(int row, int column);
	bool changed_cell(int row, int column, int cell_position);

	enum State
	{
		EMPTY,
		PLANKTON,
		SHARK,
		WHALE,
		STATES
	};

	enum Size
	{
		SMALL,
		MEDIUM,
		BIG,
		SIZES
	};

	enum Sex
	{
		FEMALE,
		MALE,
		SEXES
	};
}

