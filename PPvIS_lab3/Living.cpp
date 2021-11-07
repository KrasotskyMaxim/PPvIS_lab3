#include "Living.h"

void Living::sums(Ocean ocean, int sm[])
{
	sm[EMPTY] = sm[PLANKTON] = 0;

	sm[ocean[row][column][cell_position]->who()]++;
}
