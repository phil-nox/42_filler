#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

// How to run
// make -C./libft && gcc ./helper/read_map.c -L./libft/build -lft -I./libft -o read.filler
// touch out
// echo -e "hello world\nok and" | ./a.out  

// Clean up
// make fclean -C./libft && rm -f a.out


typedef	struct		s_map
{
	int			    row;
	int 			col;
	char**        	map;
}					t_map;

# define PLY_KW "$$$ exec p"
int set_player(char *line, int *player)
{
    if (*player != 1 || *player != 2)
    {
        if (ft_strstr(line, PLY_KW) != NULL)
        {
            *player = *(line + 10) - 48;
            return (0);
        }
        else
            return (1); // error
    }
    return (0);
}

# define MAP_KW "Plateau "
# define PIE_KW "Piece "

int set_map(t_map *trg, char *keyword)
{
    char *line;
    int idx;

    if (ft_strcmp(keyword, PIE_KW))
    {
        get_next_line(0, &line);
        free(line);
    }
    trg->map = (char **)malloc((trg->row) * sizeof(char **));
    idx = -1;
    while (++idx < trg->row)
        get_next_line(0, &(trg->map[idx]));
    return (1);
}


int init_map(char *line, t_map *trg, char *keyword)
{
    if (ft_strstr(line, keyword) == NULL)
        return (0);
    trg->row = ft_atoi(line + ft_strlen(keyword));
    trg->col = ft_atoi(line + ft_strlen(keyword) + ft_strlen(ft_itoa(trg->row)));
    free(line);
    set_map(trg, keyword);
    return (1);
}

int main(void)
{
    int fdw, fdd;
    int fd_debug;
    char *path2file;
    char *path2debug;
    char *line;

    int player;
    t_map map;
    t_map pie;



    player = 0;

    
    path2file = "out";
    path2debug = "debug"; 
    fdw = open(path2file, O_RDWR);
    fdd = open(path2debug, O_RDWR);

    while (get_next_line(0, &line) == 1)
	{

        if (init_map(line, &pie, PIE_KW))
            continue;
        if (init_map(line, &map, MAP_KW))
            continue;
        set_player(line, &player);
        write(fdw, line, ft_strlen(line));
        write(fdw, "\n", 1);
		free(line);
	}
	close(fdw);






    # define DB_PLY "player= "
    # define DB_ROW "map->row= "
    # define DB_COL "map->col= "

    write(fdd, DB_PLY, ft_strlen(DB_PLY));
    line = ft_itoa(player);
    write(fdd, line, ft_strlen(line));
    free(line);
    write(fdd, "\n", 1);

    write(fdd, DB_ROW, ft_strlen(DB_ROW));
    line = ft_itoa(map.row);
    write(fdd, line, ft_strlen(line));
    free(line);
    write(fdd, "\n", 1);

    write(fdd, DB_COL, ft_strlen(DB_COL));
    line = ft_itoa(map.col);
    write(fdd, line, ft_strlen(line));
    free(line);
    write(fdd, "\n", 1);
    write(fdd, "\n", 1);

    int idx;

    idx = -1;
    while (++idx < map.row)
    {
        write(fdd, map.map[idx], ft_strlen(map.map[idx]));
        write(fdd, "\n", 1);
    }
    write(fdd, "\n", 1);

    idx = -1;
    while (++idx < pie.row)
    {
        write(fdd, pie.map[idx], ft_strlen(pie.map[idx]));
        write(fdd, "\n", 1);
    }

    close(fdd);
}