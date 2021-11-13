/*!
	c\brief ontains namespace settings for ocean model
	
	file contains namespace for global settings for every ocen model in application
*/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/*!
	\brief namespace of ocean model settings

	this namespace contains all settings for ocen model in application
*/
namespace settings
{
	std::string path;

	const int OCEAN_LENGHT = 5;
	const int OCEAN_WIDTH = 5;
	const int LIFE_IN_CELL = 4;
	std::vector<std::vector<int>> changed_cells; ///< changed after updating cells coordinates
	std::vector<std::vector<int>> reproducted_plankton; ///< changed after plankton reproduction cells coordinates

	const int DSHARK = 7;
	const int DWHALE = 9;
	int CYCLES;

	/*!
		ocean model settings from file

		get ocean model settings from .txt file and set it data into variables

		\aram path
	*/
	void ocean_model(std::string path);
	/*!
		check ocean model border

		check if current cell depends on the ocean model and it can be reached

		\param row, column

		\return true-if ocean model cell, false-if cell doesn`t depend of ocean model 
	*/
	bool border(int row, int column);
	/*!
		answer if cell was changing

		receive coordinates of cell, ckeck and answer if cell will be change

		\param row, column, cell_position

		\return true-if cell was changing, false-if cell didn`t changed
	*/
	bool changed_cell(int row, int column, int cell_position);

	enum State
	{
		EMPTY,
		PLANKTON,
		SHARK,
		WHALE,
		STATES
	};

	enum Size
	{
		SMALL,
		MEDIUM,
		BIG,
		SIZES
	};

	enum Sex
	{
		FEMALE,
		MALE,
		SEXES
	};

	std::vector<std::vector<int>> plankton, whale, shark; ///< params of populaton positions
}

