#include "filler.h"

void debug_print(char *str, int next_line, int to_free)
{
    static int fdd;
    char *path2debug;

    if (to_free == -1)
    {
        close(fdd);
        return ;
    }

    if (fdd < 1)
    {
        path2debug = "test_debug";
        fdd = open(path2debug, O_RDWR); 
    }
    write(fdd, str, ft_strlen(str));
    
    if (next_line)
        write(fdd, "\n", 1);

    if (to_free)
        free(str);
}

void find_debug(t_map *map, int pos, int res)
{
    if (SHOW_FIND_DEBUG != 1 && res != 1)
        return ;
    debug_print(ft_itoa(pos), 0, 1);
    debug_print("\t ", 0, 0);
    debug_print(ft_itoa(row_p(map, pos)), 0, 1);
    debug_print(" ", 0, 0);
    debug_print(ft_itoa(col_p(map, pos) - SHIFT_M), 0, 1);
    if(res == -1)
        debug_print("\t- out border", 1, 0);
    if(res == -2)
        debug_print("\t- enemy", 1, 0);
    if(res == -3)
         debug_print("\t- more then one", 1, 0);
     if(res == 0)
         debug_print("\t- void", 1, 0);
     if(res == 1)
        debug_print("\t- <== Good", 1, 0);
}