#include "filler.h"

void place_pie(t_game *game, int row, int col)
{
    int r;
    int c;

    r = -1;
    c = -1;
    as_map(game->map, game->adv);
    while (++r < game->pie->row)
    {
        c = -1;
        while(++c < game->pie->col)
        {
            if (game->pie->map[r][c] == -1)
                continue;
            set_val(game->adv, row + r, col + c, -3);
        }
    }
}


int is_a_place(t_game *game, int row, int col)
{
    int r;
    int c;
    char tmp;
    int count;
    int row_game;
    int col_game;

    r = -1;
    c = -1;
    count = 0;
    while (++r < game->pie->row)
    {
        c = -1;
        while(++c < game->pie->col)
        {
            if (game->pie->map[r][c] == -1)
                continue;
            if (!in_borders(game, row + r, col + c))
                return (-1);
            if (row + r < 0)
                row_game = game->map->row + (row + r);
            else
                row_game = (row + r);
            
            if (col + c < 0)
                col_game = game->map->col + (col + c);
            else
                col_game = (col + c);

            tmp = game->map->map[row_game][col_game];
            if (tmp == 0)
                return (-2);
            if (tmp == -2)
                count += 1;
            if (count > 1)
                return (-3);
        }
    }
    if (count == 0)
        return (0);
    return (1);
}

int find_place(t_game *game)
{
    int row;
    int col;
    int plc;
    int count;
    t_map *map;
    t_map *pie;
     
    map = game->map;
    pie = game->pie;

    count = 0;
    row = - pie->row;
    while(++row < map->row)
    {
        col = - pie->col;
        while(++col < map->row)
        {
            plc = is_a_place(game, row, col);
            if (plc == 1)
            {
                count++;
                place_pie(game, row, col);
                if (game->show_place)
                {
                    debug_value_map_color(game->adv);
                    ft_putstrfile("\n");
                }
                // this one
                reset_val_map(game, row, col);

                // just last 
                // make a adv with new algoritm 
                game->pnt[0] = row;
                game->pnt[1] = col;
            }
        }

    }
    if (game->show_place)
        ft_putstrfile("........ END PLACE ........\n");
    return (count);
}