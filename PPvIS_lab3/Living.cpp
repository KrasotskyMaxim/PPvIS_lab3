#include "Living.h"

void Living::sums(Ocean ocean, int sm[])
{
	sm[EMPTY] = sm[PLANKTON] = sm[SHARK] = sm[WHALE] = 0;

	for (int k = 0;  k < LIFE_IN_CELL; k++)
	{
		sm[ocean[row][column][k]->who()]++;
	}
}


