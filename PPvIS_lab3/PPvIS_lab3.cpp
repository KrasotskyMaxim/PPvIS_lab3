/**
	\brief file with the main functions for manage the ocean model
	
	This file contains main function and ither methods for generate, build,
	populate, view and clear ocean model.
*/
#include <iostream>
#include <iomanip>
#include "Living.h"
#include "Settings.h"
#include "Empty.h"
#include <vector>
#include "Shark.h"
#include "Whale.h"
using namespace std;

/**
	initialize ocean model

	\param ocean
*/
void init(Ocean ocean);
/**
	populate ocean model in general case

	\param ocean
*/
void eden(Ocean ocean);
/**
	populate ocean model with planktons

	receive vector of planktons coordinates 

	\param ocean, params
*/
void eden_plankton(Ocean ocean, vector<vector<int>> params);
/**
	populate ocean model with sharks

	receive vector of sharks coordinates

	\param ocean, params
*/
void eden_shark(Ocean ocean, vector<vector<int>> params);
/**
	populate ocean model with whales

	receive vector of whales coordinates

	\param ocean, params
*/
void eden_whale(Ocean ocean, vector<vector<int>> params);
/**
	update the ocean model to the next life cycle

	\param old_ocean, new_ocean
*/
void update(Ocean new_ocean, Ocean old_ocean);
/**
	clear old_ocean after updating

	\param ocean
*/
void clear(Ocean ocean);
/**
	show in console the ocealn model condition on every cycle

	\param ocean, CYCLE
*/
void view(Ocean ocean, int CYCLE);
/**
	update ocean model according to new animals after reprodiction

	\param ocean
*/
void update_reproduct_animals(Ocean ocean);


/*!
	work with ocean model in depend of user settings

	function logic can be like that example:
	\code
		
int main()
{
	cout << "Enter path: ";
	cin >> settings::path;

	ocean_model(path);

	Ocean odd, even;

	init(odd);
	init(even);
	eden_plankton(even, settings::plankton);
	eden_shark(even, settings::shark);
	eden_whale(even, settings::whale);

	view(even, -1);

	for (int i = 0; i < CYCLES; ++i)
	{
		if (i % 2)
		{
			update(even, odd);
			view(even, i);
			clear(odd);
		}
		else
		{
			update(odd, even);
			view(odd, i);
			clear(even);
		}
	}

	system("pause");
	return 0;
}

	\encode
*/
int main()
{
	cout << "Enter path: ";
	cin >> settings::path;

	ocean_model(path);

	Ocean odd, even;	

	init(odd);
	init(even);
	eden_plankton(even, settings::plankton);
	eden_shark(even, settings::shark);
	eden_whale(even, settings::whale);

	view(even, -1);

	for (int i = 0; i < CYCLES; ++i)
	{
		if (i % 2)
		{
			update(even, odd);
			view(even, i);
			clear(odd);
		}
		else
		{
			update(odd, even);
			view(odd, i);
			clear(even);
		}
	}

	system("pause");
	return 0;
}


void init(Ocean ocean)
{
	for (int m = 0; m < OCEAN_LENGHT; ++m)
		for (int n = 0; n < OCEAN_WIDTH; ++n)
			for (int i = 0; i < LIFE_IN_CELL; ++i)
			{
				ocean[m][n][i] = new Empty(m, n, i);
			}
}

void eden(Ocean ocean)
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

void eden_plankton(Ocean ocean, vector<vector<int>> params)
{
	for (auto vec : params)
	{
		delete ocean[vec[0]][vec[1]][vec[2]];
		ocean[vec[0]][vec[1]][vec[2]] = new Plankton(vec[0], vec[1], vec[2]);
	}
}

void eden_shark(Ocean ocean, vector<vector<int>> params)
{
	for (auto vec : params)
	{
		delete ocean[vec[0]][vec[1]][vec[2]];
		ocean[vec[0]][vec[1]][vec[2]] = new Shark(vec[0], vec[1], vec[2], vec[3]);
	}
}

void eden_whale(Ocean ocean, vector<vector<int>> params)
{
	for (auto vec : params)
	{
		delete ocean[vec[0]][vec[1]][vec[2]];
		ocean[vec[0]][vec[1]][vec[2]] = new Whale(vec[0], vec[1], vec[2], vec[3]);
	}
}

void update(Ocean new_ocean, Ocean old_ocean)
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

void clear(Ocean ocean)
{
	for (int m = 0; m < OCEAN_LENGHT; ++m)
		for (int n = 0; n < OCEAN_WIDTH; ++n)
			for (int i = 0; i < LIFE_IN_CELL; i++)
				delete(ocean[m][n][i]);
}

void view(Ocean ocean, int CYCLE)
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

			for (k = 0; k < LIFE_IN_CELL; k++)
				if (ocean[i][j][k]->who() == 0)
				{
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
					cout << setw(16) << "sh[" << i << "][" << j << "][" << k << "] - " << ocean[i][j][k]->get_hp() << " ,  " <<ocean[i][j][k]->get_sex();
					//emptyNum++;
				}
				else if (ocean[i][j][k]->who() == 3)
				{
					cout << setw(16) << "w[" << i << "][" << j << "][" << k << "] - " << ocean[i][j][k]->get_hp() << " ,  " << ocean[i][j][k]->get_sex();
					//planktonNum++;
				}
				
					
			cout << endl;
			//cout << setw(4) << "e-" << emptyNum << "p-" << planktonNum << " ";
		}
	}
}

void update_reproduct_animals(Ocean ocean)
{
	for (auto vec : reproducted_plankton)
		ocean[vec[0]][vec[1]][vec[2]] = new Plankton(vec[0], vec[1], vec[2]);
}
