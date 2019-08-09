#include "filler.h"

// How to run
// make -C./libft && gcc 1_read_map.c test_put.c -L./libft/build -lft -I./libft -o read.filler
// touch test_out test_debug
// ./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./read.filler -f ./resources/maps/map00 -t 1
//
// or
//
// ./test_run.sh

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

int main(void)
{
    int fdw;
    int fd_debug;
    char *path2file;
    char *line;

    int player;
    t_map org;
    t_map map;
    t_map tmp;
    t_map pie;

    int out;

    player = 0;

    path2file = "test_out";
    fdw = open(path2file, O_RDWR);

    while (get_next_line(0, &line) == 1)
	{
        if (init_map(line, &pie, PIE_KW))
        {
            line = ft_itoa(make_map(&org, &map));
            //debug_print(line, 1, 1);
            set_val_map(&map, player);
            out = find_place(player, &map, &pie);
            if(SHOW_SEND)
                send_debug(&map, out, calc_score(&map, &pie, out));
            send_position(&map, out);
            continue;
        }
        if (init_map(line, &org, MAP_KW))
            continue;
        set_player(line, &player);
        write(fdw, line, ft_strlen(line));
        write(fdw, "\n", 1);
		free(line);
	}

    debug_print(NULL, 0, -1);
    
}