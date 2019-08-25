#include "filler.h"

int send_to_fd(char *line, int fd_map)
{
	return (write(fd_map, line, ft_strlen(line)));
}

int map_human(int input, int fd_map)
{
	if (input == -3)
		return send_to_fd("F", fd_map);
	if (input == -2)
		return send_to_fd("O", fd_map);
	if (input == 0)
		return send_to_fd("X", fd_map);
	if (input == 1)
		return send_to_fd("T", fd_map);
	return send_to_fd(".", fd_map);
}

void place_pie_for_view(t_game *game, int val)
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
            set_val(game->adv, game->pnt[0] + r, game->pnt[1] + c, val);
        }
    }
}

void send_map_to_view(t_game *game, int fd_map)
{
	int row;
	int col;
	int valid_place;

	valid_place = (is_a_place(game, game->pnt[0], game->pnt[1]) == 1) ? 1 : -3;
	place_pie_for_view(game, valid_place);

	row = -1;
	while (++row < game->org->row)
	{
		col = -1;
		while (++col < game->org->col)
			map_human(game->adv->map[row][col], fd_map);
		send_to_fd("\n", fd_map);
	}
	send_to_fd("\n", fd_map);
}