#include "Empty.h"
#define new_world new_ocean[row][column][cell_position]

void Empty::next(Ocean old_ocean, Ocean new_ocean)
{
    int sum[STATES];

    sums(old_ocean, sum);
    if (sum[PLANKTON])
        new_world = new Plankton(row, column, cell_position);
    else
        new_world = new Empty(row, column, cell_position);
}
