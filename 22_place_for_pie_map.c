#include "filler.h"

void as_map(t_map *src, t_map *trg)
{
    int idx;

    idx = -1;
    while (++idx < src->row)
        ft_strcpy(trg->map[idx], src->map[idx]);
}

int cpy_map(t_map *src, t_map *trg)
{
    int idx;
    int malloc_failed;

    trg->row = src->row;
    trg->col = src->col;
    trg->player = src->player;

    trg->map = (char **)malloc((trg->row) * sizeof(char **));
    if (!trg->map)
		return (1);
    
    malloc_failed = 0;
    idx = -1;
    while (++idx < trg->row)
    {
        if((trg->map[idx] = ft_strnew(trg->col + SHIFT_M)) == NULL)
        {
            malloc_failed = 1;
            break;
        }
    }
    if (malloc_failed)
    {
        while (--idx > -1)
            free(trg->map[idx]);
        free(trg->map);
        return (1);
    }
    return (0);
}

int make_map(t_map *src, t_map *trg)
{
    if (cpy_map(src, trg))
        return (1);
    as_map(src, trg);
    return (0);
}

void place_pie(int pos, t_map *pie, t_map *adv)
{
    char to_place;
    int r;
    int c;

    //to_place = (adv->player == 1) ? 'y' : 'z';
    to_place = 'w';
    r = -1;
    c = -1;
    while (++r < pie->row)
    {
        c = -1;
        while(++c < pie->col)
        {
            if (pie->map[r][c] == '.')
                continue;
            set_val(adv, pos + c + r * (adv->col),to_place);
        }
    }
}