#include "filler.h"

int map_print(int input)
{
	if (input == -4)
		return ft_putstrfile("🚨");
	if (input == -3)
		return ft_putstrfile("🎯");
	if (input == -2)
		return ft_putstrfile("🦑");
	if (input == -1)
		return ft_putstrfile("🔹");
	if (input == 0)
		return ft_putstrfile("🐢");
	if (input == 1)
		return ft_putstrfile("👆🏼");
	if (input == 2)
		return ft_putstrfile("👆🏽");
	if (input == 2)
		return ft_putstrfile("👆🏾");
	if (input == 3)
		return ft_putstrfile("👆🏿");
	if (input == 4)
		return ft_putstrfile("✌🏼");
	if (input == 5)
		return ft_putstrfile("✌🏽");
	if (input == 6)
		return ft_putstrfile("✌🏾");
	if (input == 7)
		return ft_putstrfile("✌🏿");
	if (input == 8)
		return ft_putstrfile("🖖🏼");
	if (input == 9)
		return ft_putstrfile("🖖🏽");
	if (input == 10)
		return ft_putstrfile("🖖🏾");
	if (input == 11)
		return ft_putstrfile("🖖🏿");
	if (input == 12)
		return ft_putstrfile("🖐🏼");
	if (input == 13)
		return ft_putstrfile("🖐🏽");
	if (input == 14)
		return ft_putstrfile("🖐🏾");
	if (input == 15)
		return ft_putstrfile("🖐🏿");
	return ft_putstrfile("⬛️");
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
		ft_putstrfile("\n");
	}
	ft_putstrfile("\n");
}