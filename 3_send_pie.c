#include "filler.h"

void send_position(t_map *map, int pos)
{
    char *line;

    line = ft_itoa(row_p(map, pos));
    write(1, line, ft_strlen(line));
    free(line);

    line = " ";
    write(1, line, ft_strlen(line));
    
    line = ft_itoa(col_p(map, pos) - SHIFT_M);
    write(1, line, ft_strlen(line));
    free(line);

    line = "\n";
    write(1, line, ft_strlen(line));
}