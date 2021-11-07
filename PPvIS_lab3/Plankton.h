#pragma once
#include "Living.h"
#include "Empty.h"

class Plankton : public Living
{
	int hp;
public:
	Plankton(int row, int column, int cell_position, int hp = 100)
	{
		this->row = row;
		this->column = column;
		this->cell_position = cell_position;
		this->hp = hp;
	}

	State who() { return PLANKTON; }
	Living* next(Ocean ocean);
};

