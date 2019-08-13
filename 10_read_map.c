#include "filler.h"

int set_player_adv(char *line, t_game *game)
{
    if (ft_strstr(line, PLY_KW) != NULL)
    {
        game->player = *(line + 10) - 48;
        return (1);
    }
    else
       return (0);
}

int set_map_job(t_game *game, char *keyword)
{
    int idx;
    int idxc;
    char *line;
    char tmp;
    t_map *trg;

    trg = (keyword == MAP_KW) ? game->org : game->pie;

    idx = -1;
    while (++idx < trg->row)
    {
        get_next_line(0, &line);
        trg->map[idx] = (int *)malloc((trg->col) * sizeof(int *));
        if(!trg->map[idx])
            return (-1);
        idxc = -1;
        while (++idxc < trg->col)
        {
            tmp = (keyword == MAP_KW) ? line[idxc + SHIFT_M] : line[idxc];
            if (tmp == 'o' || tmp == 'O')
                trg->map[idx][idxc] = (game->player == 1) ? -2 : 0;
            else if (tmp == 'x' || tmp == 'X')
                trg->map[idx][idxc] = (game->player == 2) ? -2 : 0;
            else if (tmp == '.')
                trg->map[idx][idxc] = -1;
            else if (tmp == '*')
                trg->map[idx][idxc] = -3;
            else
                trg->map[idx][idxc] = -4; //error
        }
        free(line);
    }
    return (0);
}


int set_map(t_game *game, char *keyword)
{
    char *line;
    t_map *trg;

    trg = (keyword == MAP_KW) ? game->org : game->pie;

    if (keyword == MAP_KW)
    {
        get_next_line(0, &line);
        free(line);
    }
    trg->map = (int **)malloc((trg->row) * sizeof(int **));
    if (!trg->map)
        return (-1);
    set_map_job (game, keyword);
    return (1);
}

int init_map(char *line, t_game *game, char *keyword)
{
    t_map *trg;
    int out;

    if (!ft_strstr(line, keyword))
        return (0);

    if (game->show_read_debug)
        debug_print(line, 1, 0);

    trg = (keyword == MAP_KW) ? game->org : game->pie;
    trg->row = ft_atoi(line + ft_strlen(keyword));
    trg->col = ft_atoi(line + ft_strlen(keyword) + ft_strlen(ft_itoa(trg->row)));
    free(line);

    out = set_map(game, keyword);
    if (game->show_read_debug)
    {
        debug_value_map_color(trg);
        if (keyword == PIE_KW)
            debug_print("<<<<<<<< END INPUT <<<<<<<<", 1, 0);
    }
    return (out);
}