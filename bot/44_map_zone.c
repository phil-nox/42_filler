#include "filler.h"

void zones(t_map *fre, t_map *att, t_map *map)
{
    int row;
    int col;
    int tmp_att;
    int tmp_map;

    row = -1;
    while (++row < att->row)
    {
        col = -1;
        while (++col < att->col)
        {
            tmp_att = get_val(att, row, col);
            tmp_map = get_val(map, row, col);
            if (tmp_att < 1)
            {
                set_val(fre, row, col, tmp_att);
                continue;
            }
            if (tmp_att > tmp_map)
                set_val(fre, row, col, -5);
            if (tmp_att < tmp_map)
                set_val(fre, row, col, -7);
            if (tmp_att == tmp_map)
                set_val(fre, row, col, -6);
        }
    }
}

void zone_diff(t_map *fre, t_map *zon)
{
    int row;
    int col;
    int tmp_fre;
    int tmp_zon;

    row = -1;
    while (++row < fre->row)
    {
        col = -1;
        while (++col < fre->col)
        {
            tmp_fre = get_val(fre, row, col);
            tmp_zon = get_val(zon, row, col);
            if (tmp_fre == -2 || tmp_fre == 0 || tmp_fre != tmp_zon)
                continue;
            set_val(fre, row, col, -8);
        }
    }
}