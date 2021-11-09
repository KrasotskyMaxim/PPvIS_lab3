#include "Plankton.h"
#include <vector>
#define new_world new_ocean[row][column][cell_position]
#define old_world old_ocean[new_row][new_column]

void Plankton::next(Ocean old_ocean, Ocean new_ocean)
{
    hp -= 20;
    int sum[STATES];

    bool reproduction = false;
    bool self_reproduction = false;

    sums(old_ocean, sum);
    if (hp <= 0)
        new_world = new Empty(row, column, cell_position);
    else
    {
        for (int m = -1; m < 2; m++)
        {
            for (int n = -1; n < 2; n++)
            {
                int new_row = row - m;
                int new_column = column - n;

                if (border(new_row, new_column))
                {
                    old_ocean[new_row][new_column][0]->sums(old_ocean, sum);

                    if (sum[PLANKTON] > 0)
                    {
                        if (new_row == row && new_column == column)
                            self_reproduction = true;
                        else
                        {
                            for (int k = 0; k < LIFE_IN_CELL; k++)
                               if (old_world[k]->who() == 1)
                               {
                                   new_ocean[new_row][new_column][k] = new Plankton(new_row, new_column, k);

                                   std::vector<int> repr_params{ new_row, new_column, k };
                                   reproducted_plankton.push_back(repr_params);

                                   reproduction = true;
                                   break;
                               }
                        }
                    }
                    else
                    {
                        for (int k = 0; k < LIFE_IN_CELL; k++)
                            if (old_world[k]->who() == 0)
                            {
                                new_ocean[new_row][new_column][k] = new Plankton(new_row, new_column, k);

                                std::vector<int> update_params{ new_row, new_column, k };
                                changed_cells.push_back(update_params);

                                reproduction = true;
                                break;
                            }
                    }
                        /*Living* pretend = old_ocean[new_row][new_column][k];

                        if (pretend->who() == 0)
                        {
                            //delete pretend;
                            new_ocean[new_row][new_column][k] = new Plankton(new_row, new_column, k);

                            std::vector<int> params{ new_row, new_column, k };
                            changed_cells.push_back(params);

                            reproduction = true;
                            break;
                        }
                        else if (pretend->who() == 1)
                        {
                            new_ocean[new_row][new_column][k] = new Plankton(new_row, new_column, k);
                            reproduction = true;
                        }*/
                }
                if (reproduction)
                    break;
            }
            if (reproduction)
                break;
        }

        if (self_reproduction)
            hp = 100;
        new_world = new Plankton(row, column, cell_position, hp);
    }
}
