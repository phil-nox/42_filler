#include "filler.h"

int map_print(int input)
{
	if (input == -4)
		return ft_pututf8("🚨");
	if (input == -3)
		return ft_pututf8("🎯");
	if (input == -2)
		return ft_pututf8("🦑");
	if (input == -1)
		return ft_pututf8("🔹");
	if (input == 0)
		return ft_pututf8("🐢");
	if (input == 48)
		return ft_pututf8("⬛️");
	if (input == 49)
		return ft_pututf8("🌕");
	if (input == 50)
		return ft_pututf8("🌖");
	if (input == 51)
		return ft_pututf8("🌗");
	if (input == 52)
		return ft_pututf8("🌘");
	if (input == 53)
		return ft_pututf8("🌑");
	if (input == 54)
		return ft_pututf8("🕐");
	if (input == 55)
		return ft_pututf8("🕑");
	if (input == 56)
		return ft_pututf8("🕒");
	if (input == 57)
		return ft_pututf8("🕓");
	if (input == 58)
		return ft_pututf8("🕔");
	if (input == 59)
		return ft_pututf8("🕕");
	if (input == 60)
		return ft_pututf8("🕖");
	if (input == 61)
		return ft_pututf8("🕗");
	if (input == 62)
		return ft_pututf8("🕘");
	if (input == 63)
		return ft_pututf8("🕙");
	if (input == 63)
		return ft_pututf8("🕚");
	return ft_pututf8("🔳");
}

void debug_value_map_color(t_map *map)
{
	int row;
	int col;

	row = -1;
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->col)
			map_print(map->map[row][col]);
		ft_pututf8("\n");
	}
	ft_pututf8("\n");
}