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

bool settings::border(int row, int column, int cell_position)
{
	if ((row >= 0 && row < OCEAN_LENGHT) && (column >= 0 && column < OCEAN_WIDTH) && (cell_position >= 0 && cell_position < LIFE_IN_CELL))
		return true;

	return false;
}

bool settings::changed_cell(int row, int column, int cell_position)
{
	for (auto vec : changed_cells)
	{
		if (row == vec[0] && column == vec[1] && cell_position == vec[2])
			return true;
	}

	return false;
}
