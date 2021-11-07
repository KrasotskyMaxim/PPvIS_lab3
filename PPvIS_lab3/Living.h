#pragma once
#include "Settings.h"
using namespace settings;

class Living;

typedef Living* Ocean[OCEAN_LENGHT][OCEAN_WIDTH][LIFE_IN_CELL];

class Living
{
public:
	virtual State who() = 0;
	virtual void next(Ocean ocean, Ocean new_ocean) = 0;

protected:
	int row, column, cell_position;
	void sums(Ocean ocean, int sm[]);
};

