#include "Empty.h"

Living* Empty::next(Ocean ocean)
{
    int sum[STATES];

    sums(ocean, sum);
    if (sum[PLANKTON])
        return (new Plankton(row, column, cell_position));
    else
        return (new Empty(row, column, cell_position));
}
