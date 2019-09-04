#include "filler.h"

void as_map(t_map *src, t_map *trg)
{
    int idx;
    int idxc;

    trg->row = src->row;
    trg->col = src->col;
    idx = -1;
    while (++idx < src->row)
    {
        idxc = -1;
        while (++idxc < src->col)
            trg->map[idx][idxc] = src->map[idx][idxc];
    }
}
