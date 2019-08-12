#include "filler.h"

int map_print(char input)
{
	if (input == 'w')
		return ft_pututf8("🎯");
	if (input == 'y')
		return ft_pututf8("🦑");
	if (input == 'z')
		return ft_pututf8("🐢");
	if (input == '.')
		return ft_pututf8("🔹");
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
	int idx;
	int pos;

	idx = -1;
	while (++idx < map->row)
	{
		pos = -1;
		while (map->map[idx][++pos])
		{
			if (pos < 4)
				continue;
			map_print(map->map[idx][pos]);
		}
		ft_pututf8("\n");
	}
	debug_print("\n", 1, 0);
}

void debug_value_map_color_adv(t_map *map, char *str)
{
	int idx;
	int pos;

	idx = -1;
	while (++idx < map->row)
	{
		pos = -1;
		debug_print(str, 0, 0);
		while (map->map[idx][++pos])
		{
			if (pos < 4)
				continue;
			map_print(map->map[idx][pos]);
		}
		ft_pututf8("\n");
	}
	debug_print("\n", 1, 0);
}