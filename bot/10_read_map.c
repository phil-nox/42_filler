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

int set_map_job(t_game *game, char *keyword, int fd_in)
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
        get_next_line(fd_in, &line);
        if(add_mstack(line))
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
        free_mstack(line);
    }
    return (0);
}

int one_time_game_malloc(t_game *game)
{
    int idx;

    game->org->map = (int **)malloc((game->org->row) * sizeof(int **));
        if(add_mstack(game->org->map))
            return (1);
    game->map->map = (int **)malloc((game->org->row) * sizeof(int **));
        if(add_mstack(game->org->map))
            return (1);
    game->adv->map = (int **)malloc((game->org->row) * sizeof(int **));
        if(add_mstack(game->org->map))
            return (1);
    game->pie->map = (int **)malloc((game->org->row) * sizeof(int **));
        if(add_mstack(game->pie->map))
            return (1);
    
    idx = -1;
    while (++idx < game->org->row)
    {
        game->org->map[idx] = (int *)malloc((game->org->col) * sizeof(int *));
        if(add_mstack(game->org->map[idx]))
            return (1);
        game->map->map[idx] = (int *)malloc((game->org->col) * sizeof(int *));
        if(add_mstack(game->org->map[idx]))
            return (1);
        game->adv->map[idx] = (int *)malloc((game->org->col) * sizeof(int *));
        if(add_mstack(game->org->map[idx]))
            return (1);
        game->pie->map[idx] = (int *)malloc((game->org->col) * sizeof(int *));
        if(add_mstack(game->pie->map[idx]))
            return (1);
    }
    return (0);
}


int set_map(t_game *game, char *keyword, int fd_in)
{
    char *line;
    t_map *trg;

    trg = (keyword == MAP_KW) ? game->org : game->pie;

    if (keyword == MAP_KW)
    {
        if (trg->map == NULL)
            if(one_time_game_malloc(game))
                return (-1);
        get_next_line(fd_in, &line);
        if(add_mstack(line))
            return (-1);
        free_mstack(line);
    }
    set_map_job (game, keyword, fd_in);
    return (1);
}

int init_map(char *line, t_game *game, char *keyword, int fd_in)
{
    t_map *trg;
    int out;
    char *num;

    if (!ft_strstr(line, keyword))
        return (0);

    if (game->show_read_debug)
        debug_print(line, 1, 0);

    trg = (keyword == MAP_KW) ? game->org : game->pie;
    trg->row = ft_atoi(line + ft_strlen(keyword));
    num = ft_itoa(trg->row); //TO_DO function return number of char in int
    if(add_mstack(num))
            return (-1);
    trg->col = ft_atoi(line + ft_strlen(keyword) + ft_strlen(num));
    
    if(trg->map != NULL && (game->pie->row > game->org->row || game->pie->col > game->org->col))
    {
        debug_print("⚠️⚠️⚠️⚠️ pie > org ⚠️⚠️⚠️⚠️", 1, 0);
        debug_print(line, 1, 0);
    }

    free_mstack(num);
    free_mstack(line);
    

    out = set_map(game, keyword, fd_in);
    if (out != -1 && game->show_read_debug)
    {
        debug_value_map_color(trg, "");
        if (keyword == PIE_KW)
            debug_print("<<<<<<<< END INPUT <<<<<<<<", 1, 0);
    }
    return (out);
}