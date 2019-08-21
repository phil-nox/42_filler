#include "filler.h"

void as_map(t_map *src, t_map *trg)
{
    int idx;
    int idxc;

    idx = -1;
    while (++idx < src->row)
    {
        idxc = -1;
        while (++idxc < src->col)
            trg->map[idx][idxc] = src->map[idx][idxc];
    }
}

int cpy_map(t_map *src, t_map *trg)
{
    int idx;
    //int malloc_failed;

    trg->row = src->row;
    trg->col = src->col;

    trg->map = (int **)malloc((trg->row) * sizeof(int **));
    if(add_mstack(trg->map))
            return (1);
    //if (!trg->map)
	//	return (1);
    
    //malloc_failed = 0;
    idx = -1;
    while (++idx < trg->row)
    {
        trg->map[idx] = (int *)malloc((trg->col) * sizeof(int *));
        if(add_mstack(trg->map[idx]))
            return (1);
        /*
        {
            malloc_failed = 1;
            break;
        }
        */
    }
    /*
    if (malloc_failed)
    {
        while (--idx > -1)
            free(trg->map[idx]);
        free(trg->map);
        return (1);
    }
    */
    return (0);
}

int make_map(t_game *game, t_map *src, t_map *trg)
{
    //if (cpy_map(src, trg))
    //    return (1);
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