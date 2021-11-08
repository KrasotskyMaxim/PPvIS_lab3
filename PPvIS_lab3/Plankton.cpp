#include "Plankton.h"
#include <vector>
#define new_world new_ocean[row][column][cell_position]

void Plankton::next(Ocean old_ocean, Ocean new_ocean)
{
    hp -= 20;
    int sum[STATES];

    sums(old_ocean, sum);
    if (hp <= 0)
        new_world = new Empty(row, column, cell_position);
    else
    {
        bool reproduction = false;
        for (int m = -1; m < 2; m++)
        {
            for (int n = -1; n < 2; n++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (border(row-m, column-n, k))
                    {
                        Living* pretend = old_ocean[row - m][column - n][k];
                        if (pretend->who() == 0)
                        {
                            //delete pretend;
                            new_ocean[row - m][column - n][k] = new Plankton(row - m, column - n, k);

                            std::vector<int> params{ row-m, column-n, k };
                            changed_cells.push_back(params);

                            reproduction = true;
                            break;
                        }
                    }
                }
                if (reproduction)
                    break;
            }
            if (reproduction)
                break;
        }  
    }
    new_world = new Plankton(row, column, cell_position, hp);
}
