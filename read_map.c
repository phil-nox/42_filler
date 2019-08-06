#include "libft.h"
#include "get_next_line.h"
#include "filler.h"

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