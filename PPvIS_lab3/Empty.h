#pragma once
#include "Living.h"
#include "Plankton.h"
using namespace settings;


class Empty : public Living
{
public:
	Empty(int row, int column, int cell_position)
	{
		this->row = row;
		this->column = column;
		this->cell_position = cell_position;
	}

	State who() { return EMPTY; }
	Living* next(Ocean ocean);
};