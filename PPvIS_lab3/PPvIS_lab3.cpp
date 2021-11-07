#include <iostream>
#include "Living.h"
#include "Settings.h"
#include "Empty.h"
using namespace std;

void init(Ocean ocean);
void eden(Ocean ocean);
void pr_state(Ocean ocean);
void update(Ocean new_ocean, Ocean old_ocean);
void clear(Ocean ocean);


int main()
{
	Ocean odd, even;

	init(odd);
	init(even);
	eden(even);

	for (int i = 0; i < CYCLES; ++i)
	{
		if (i % 2)
		{
			update(even, odd);
			clear(odd);
		}
		else
		{
			update(odd, even);
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
				if (m == 0 && n == 0 && i == 0)
				{
					delete ocean[m][n][i];
					ocean[m][n][i] = new Plankton(m, n, i);
				}
			}
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
				new_ocean[m][n][i] = old_ocean[m][n][i]->next(old_ocean);
}

void clear(Ocean ocean)
{
	for (int m = 0; m < OCEAN_LENGHT; ++m)
		for (int n = 0; n < OCEAN_WIDTH; ++n)
			for (int i = 0; i < LIFE_IN_CELL; i++)
				delete(ocean[m][n][i]);
}
