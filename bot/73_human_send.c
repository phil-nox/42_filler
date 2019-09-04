#include "human.h"
#include "filler.h"

int send_to_fd(char *line, int fd_map)
{
	return (write(fd_map, line, ft_strlen(line)));
}

int send_to_fd_ln(char *line, int fd_map)
{
	write(fd_map, line, ft_strlen(line));
    return write(fd_map, "\n", 1);
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

void send_map_to_view(t_game *game, t_map *show, int fd_map, int with_pie)
{
	int row;
	int col;
	int valid_place;

	if (with_pie)
	{
		valid_place = (is_a_place(game, game->map, game->pnt[0], game->pnt[1]) == 1) ? 1 : -3;
		place_pie_for_view(game, valid_place);
	}
	row = -1;
	send_to_fd("++\n", fd_map);
	while (++row < show->row)
	{
		col = -1;
		while (++col < show->col)
			map_human(show->map[row][col], fd_map);
		send_to_fd("\n", fd_map);
	}
}

int map_incoming (t_game *game, char *line, int fd)
{
    int error;

    error = 0;

    if ((error = init_map(line, game, PIE_KW, fd))) // -1 bad malloc
    {
        as_map(game->org, game->map);
        return (1);
    }
    if (error == -1)
    {
        free_all_mstack();
        return (-1);
    }

    if ((error = init_map(line, game, MAP_KW, fd))) // -1 bad malloc
        return (0);
    if (error == -1)
    {
        free_all_mstack();
        return (-1);
    }

    set_player_adv(line, game);
	free_mstack(line);
    return (0);
}

int cmd_apply(t_game *game, int fd_map, char input)
{
    if (input == 's')
    {
        if (is_a_place(game, game->map, game->pnt[0] + 1, game->pnt[1]) == -1)
            return (0);
        game->pnt[0] += 1;
        send_map_to_view(game, game->adv, fd_map, 1);
        return (0);
    }
    if (input == 'w')
    {
        if (is_a_place(game, game->map, game->pnt[0] - 1, game->pnt[1]) == -1)
            return (0);
        game->pnt[0] -= 1;
        send_map_to_view(game, game->adv, fd_map, 1);
        return (0);
    }
    if (input == 'd')
    {
        if (is_a_place(game, game->map, game->pnt[0], game->pnt[1] + 1) == -1)
            return (0);
        game->pnt[1] += 1;
        send_map_to_view(game, game->adv, fd_map, 1);
        return (0);
    }
    if (input == 'a')
    {
        if (is_a_place(game, game->map, game->pnt[0], game->pnt[1] - 1) == -1)
            return (0);
        game->pnt[1] -= 1;
        send_map_to_view(game, game->adv, fd_map, 1);
        return (0);
    }
    if (input == 'e')
    {
        send_position(game->pnt[0], game->pnt[1], 0);
        return (1);
    }
    return (0);
}

void game_pack_init(t_game_pack *game_p)
{
	game_p->game.pnt[0] = 0;
    game_p->game.pnt[1] = 0;
    game_p->org.map = NULL;
    game_p->map.map = NULL;
    game_p->adv.map = NULL;
    game_p->pie.map = NULL;
    game_p->game.org = &(game_p->org);
    game_p->game.map = &(game_p->map);
    game_p->game.adv = &(game_p->adv);
    game_p->game.pie = &(game_p->pie);
    game_p->game.show_read_debug = 0;
    game_p->game.show_set_wave_debug = 0;
    game_p->game.show_set_debug = 0;
    game_p->game.show_send = 0;
    game_p->game.show_reset_wave_debug = 0;
	game_p->cmd_l[0] = '\0';
}