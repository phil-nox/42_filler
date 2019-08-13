#include "filler.h"

void send_position(int row, int col)
{
    char *line;

    line = ft_itoa(row);
    write(1, line, ft_strlen(line));
    free(line);

    line = " ";
    write(1, line, ft_strlen(line));
    
    line = ft_itoa(col);
    write(1, line, ft_strlen(line));
    free(line);

    line = "\n";
    write(1, line, ft_strlen(line));
}