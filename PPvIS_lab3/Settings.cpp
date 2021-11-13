#include "Settings.h"

void settings::ocean_model(std::string path)
{
	std::fstream fs;
	std::vector<int> params;
	int animal_count;

	try
	{
		fs.open(path, std::fstream::in);
		std::cout << "\nsuccessful open file!\n";
	}
	catch (const std::exception&)
	{
		std::cout << "\nFile open error!\n";
	}

	fs >> CYCLES;
	fs >> animal_count;
	int iter = 0;

	while (iter < animal_count)
	{
		int position;
		for (int i = 0; i < 3; i++)
		{
			fs >> position;
			params.push_back(position);
		}
		iter++;
		plankton.push_back(params);
		params.clear();
	}
	
	fs >> animal_count;
	iter = 0;

	while (iter < animal_count)
	{
		int position;
		for (int i = 0; i < 4; i++)
		{
			fs >> position;
			params.push_back(position);
		}
		iter++;
		shark.push_back(params);
		params.clear();
	}

	fs >> animal_count;
	iter = 0;

	while (iter < animal_count)
	{
		int position;
		for (int i = 0; i < 4; i++)
		{
			fs >> position;
			params.push_back(position);
		}
		iter++;
		whale.push_back(params);
		params.clear();
	}

	fs.close();
}

bool settings::border(int row, int column)
{
	if ((row >= 0 && row < OCEAN_LENGHT) && (column >= 0 && column < OCEAN_WIDTH))
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
