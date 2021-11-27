#include "Model.h"

void Model::run()
{
	this->ocean_model(path);

	Ocean odd, even;

	this->init(odd);
	this->init(even);
	this->eden_plankton(even, settings::plankton);
	this->eden_shark(even, settings::shark);
	this->eden_whale(even, settings::whale);

	this->view(even, -1);

	for (int i = 0; i < CYCLES; ++i)
	{
		if (i % 2)
		{
			this->update(even, odd);
			this->view(even, i);
			this->clear(odd);
		}
		else
		{
			this->update(odd, even);
			this->view(odd, i);
			this->clear(even);
		}
	}
}

void Model::init(Ocean ocean)
{
	for (int m = 0; m < OCEAN_LENGHT; ++m)
		for (int n = 0; n < OCEAN_WIDTH; ++n)
			for (int i = 0; i < LIFE_IN_CELL; ++i)
			{
				ocean[m][n][i] = new Empty(m, n, i);
			}
}

void Model::eden(Ocean ocean)
{
	for (int m = 0; m < OCEAN_LENGHT; ++m)
		for (int n = 0; n < OCEAN_WIDTH; ++n)
		{
			for (int i = 0; i < LIFE_IN_CELL; ++i)
			{
				if (m == 1 && n == 1 && i == 1)
				{
					delete ocean[m][n][i];
					ocean[m][n][i] = new Plankton(m, n, i);
				}
			}
		}
}

void Model::eden_plankton(Ocean ocean, vector<vector<int>> params)
{
	for (auto vec : params)
	{
		delete ocean[vec[0]][vec[1]][vec[2]];
		ocean[vec[0]][vec[1]][vec[2]] = new Plankton(vec[0], vec[1], vec[2]);
	}
}

void Model::eden_shark(Ocean ocean, vector<vector<int>> params)
{
	for (auto vec : params)
	{
		delete ocean[vec[0]][vec[1]][vec[2]];
		ocean[vec[0]][vec[1]][vec[2]] = new Shark(vec[0], vec[1], vec[2], vec[3]);
	}
}

void Model::eden_whale(Ocean ocean, vector<vector<int>> params)
{
	for (auto vec : params)
	{
		delete ocean[vec[0]][vec[1]][vec[2]];
		ocean[vec[0]][vec[1]][vec[2]] = new Whale(vec[0], vec[1], vec[2], vec[3]);
	}
}

void Model::update(Ocean new_ocean, Ocean old_ocean)
{
	for (int m = 0; m < OCEAN_LENGHT; ++m)
		for (int n = 0; n < OCEAN_WIDTH; ++n)
			for (int i = 0; i < LIFE_IN_CELL; ++i)
			{
				if (!(changed_cell(m, n, i)))
					old_ocean[m][n][i]->next(old_ocean, new_ocean);
			}

	update_reproduct_animals(new_ocean);
	changed_cells.clear();
	reproducted_plankton.clear();
}

void Model::clear(Ocean ocean)
{
	for (int m = 0; m < OCEAN_LENGHT; ++m)
		for (int n = 0; n < OCEAN_WIDTH; ++n)
			for (int i = 0; i < LIFE_IN_CELL; i++)
				delete(ocean[m][n][i]);
}

void Model::view(Ocean ocean, int CYCLE)
{
	int i, j, k,
		emptyNum, planktonNum;

	cout << "\t   CYCLE " << CYCLE << endl;

	for (i = 0; i < OCEAN_LENGHT; i++)
	{
		cout << endl;
		for (j = 0; j < OCEAN_WIDTH; j++)
		{
			planktonNum = 0;
			emptyNum = 0;
#ifdef DEBUG
			for (k = 0; k < LIFE_IN_CELL; k++)
				if (ocean[i][j][k]->who() == 0)
				{
					cout << setw(16) << "e[" << i << "][" << j << "][" << k << "]";
					cout << setw(16) << "e[" << i << "][" << j << "][" << k << "]";
					//emptyNum++;
				}
				else if (ocean[i][j][k]->who() == 1)
				{
					cout << setw(16) << "p[" << i << "][" << j << "][" << k << "] - " << ocean[i][j][k]->get_hp();
					//planktonNum++;
				}
				else if (ocean[i][j][k]->who() == 2)
				{
					cout << setw(16) << "sh[" << i << "][" << j << "][" << k << "] - " << ocean[i][j][k]->get_hp() << " ,  " << ocean[i][j][k]->get_sex();
					//emptyNum++;
				}
				else if (ocean[i][j][k]->who() == 3)
				{
					cout << setw(16) << "w[" << i << "][" << j << "][" << k << "] - " << ocean[i][j][k]->get_hp() << " ,  " << ocean[i][j][k]->get_sex();
					//planktonNum++;
				}
#else
			int counter = 0;
			for (k = 0; k < LIFE_IN_CELL; k++)
			{
				if (ocean[i][j][k]->who() == 0)
				{
					cout << "\t\t" << "e";
					//emptyNum++;
				}
				else if (ocean[i][j][k]->who() == 1)
				{
					cout << "\t\t" << "PL," << ocean[i][j][k]->get_hp();
					//planktonNum++;
				}
				else if (ocean[i][j][k]->who() == 2)
				{
					cout << "\t\t" << "SH," << ocean[i][j][k]->get_hp() << "," << ocean[i][j][k]->get_sex() << "," << ocean[i][j][k]->get_age();
					//emptyNum++;
				}
				else if (ocean[i][j][k]->who() == 3)
				{
					cout << "\t\t" << "WH," << ocean[i][j][k]->get_hp() << "," << ocean[i][j][k]->get_sex() << "," << ocean[i][j][k]->get_age();
					//planktonNum++;
				}
			}
#endif
			cout << endl;
			//cout << setw(4) << "e-" << emptyNum << "p-" << planktonNum << " ";
		}
	}
}

void Model::update_reproduct_animals(Ocean ocean)
{
	for (auto vec : reproducted_plankton)
		ocean[vec[0]][vec[1]][vec[2]] = new Plankton(vec[0], vec[1], vec[2]);
}

void Model::ocean_model(std::string path)
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

bool Model::border(int row, int column)
{
	if ((row >= 0 && row < OCEAN_LENGHT) && (column >= 0 && column < OCEAN_WIDTH))
		return true;

	return false;
}

bool Model::changed_cell(int row, int column, int cell_position)
{
	for (auto vec : changed_cells)
	{
		if (row == vec[0] && column == vec[1] && cell_position == vec[2])
			return true;
	}

	return false;
}
