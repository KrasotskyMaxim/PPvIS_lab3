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
	virtual int get_hp() = 0;
	virtual int get_sex() = 0;
	virtual int get_age() = 0;
	virtual int get_size() = 0;

	virtual void set_hp(int hp) = 0;
	virtual void set_age(int age) = 0;

	void sums(Ocean ocean, int sm[]);

protected:
	int row, column, cell_position;
	
};

