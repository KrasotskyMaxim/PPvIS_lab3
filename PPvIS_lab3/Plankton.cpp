#include "Plankton.h"

Living* Plankton::next(Ocean ocean)
{
    hp -= 20;
    int sum[STATES];

    sums(ocean, sum);
    if (hp <= 0)
        return (new Empty(row, column, cell_position));
    else
        return new Plankton(row, column, cell_position, hp);
}
