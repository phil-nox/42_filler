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

int make_map(t_game *game, t_map *src, t_map *trg)
{
    trg->row = src->row;
    trg->col = src->col;
    as_map(src, trg);
    if (game->show_make_debug)
    {
        debug_value_map_color(trg);
        debug_print("^^^^^^^^ END COPY ^^^^^^^^", 1, 0);
    }
    return (0);
}