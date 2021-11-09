#include <iostream>
#include <iomanip>
#include "Living.h"
#include "Settings.h"
#include "Empty.h"
#include <vector>
using namespace std;

void init(Ocean ocean);
void eden(Ocean ocean);
void eden(Ocean ocean, vector<vector<int>> params);
void pr_state(Ocean ocean);
void update(Ocean new_ocean, Ocean old_ocean);
void clear(Ocean ocean);
void view(Ocean ocean, int CYCLE);
void update_reproduct_animals(Ocean ocean);


int main()
{
	Ocean odd, even;
	vector<vector<int>> animals{ {0, 0, 0}, {0, 1, 2}, {3, 3, 3} };

	init(odd);
	init(even);
	eden(even, animals);

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

void eden(Ocean ocean, vector<vector<int>> params)
{
	for (auto vec : params)
	{
		delete ocean[vec[0]][vec[1]][vec[2]];
		ocean[vec[0]][vec[1]][vec[2]] = new Plankton(vec[0], vec[1], vec[2]);
	}
}

void pr_state(Ocean ocean)
{
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
				else
				{
					cout << setw(16) <<"p[" << i << "][" << j << "][" << k << "] - " << ocean[i][j][k]->get_hp();
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
