/**
	\brief file with the main functions for manage the ocean model
	
	This file contains main function and ither methods for generate, build,
	populate, view and clear ocean model.
*/
#include <iostream>
#include <iomanip>
#include "Living.h"
#include "Settings.h"
#include "Empty.h"
#include <vector>
#include "Shark.h"
#include "Whale.h"
#include "Model.h"
using namespace std;

//#define DEBUG


/*!
	work with ocean model in depend of user settings

	function logic can be like that example:
	\code
		
int main()
{
	cout << "Enter path: ";
	cin >> settings::path;

	ocean_model(path);

	Ocean odd, even;

	init(odd);
	init(even);
	eden_plankton(even, settings::plankton);
	eden_shark(even, settings::shark);
	eden_whale(even, settings::whale);

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

	system("pause");
	return 0;
}

	\encode
*/
int main()
{
	cout << "Enter path: ";
	cin >> settings::path;

	Model model(settings::path);

	system("pause");
	return 0;
}