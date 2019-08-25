#include "filler.h"

int send_to_fd(char *line, int fd_map)
{
	return (write(fd_map, line, ft_strlen(line)));
}

int map_human(int input, int fd_map)
{
	if (input == -3)
		return send_to_fd("T", fd_map);
	if (input == -2)
		return send_to_fd("X", fd_map);
	if (input == 0)
		return send_to_fd("O", fd_map);
	return send_to_fd(".", fd_map);
}

void send_map_to_view(t_game *game, int fd_map)
{
	int row;
	int col;

	row = -1;
	while (++row < game->org->row)
	{
		col = -1;
		while (++col < game->org->col)
			map_human(game->org->map[row][col], fd_map);
		send_to_fd("\n", fd_map);
	}
	send_to_fd("\n", fd_map);
}