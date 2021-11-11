#pragma once
#include "Settings.h"
#include "Living.h"
#include "Predator.h"
#include "Empty.h"

class Shark : public Predator
{
public:
	Shark(int row, int column, int cell_position, int sex, int size = 0, int hp = 100, int age = 0) : Predator(row, column, cell_position, sex, size, hp, age) { this->move = 2; }

	void next(Ocean old_ocean, Ocean new_ocean);
	State who() { return SHARK; }

	int get_hp() { return this->hp; }
	int get_age() { return this->age; }
	int get_sex() { return this->sex; }
	int get_size() { return this->size; }

	void set_hp(int hp) { this->hp = hp; }
	void set_age(int age) { this->age = age; }

};

