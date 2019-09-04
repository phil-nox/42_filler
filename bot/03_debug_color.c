#include "filler.h"

int map_print(int input)
{
	if (input <= -8)
		return ft_putstrfile("⬛️");
	if (input == -7)
		return ft_putstrfile("🈴");
	if (input == -6)
		return ft_putstrfile("⚛️");
	if (input == -5)
		return ft_putstrfile("🈯️");
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
		return ft_putstrfile("1️⃣");
	if (input == 2)
		return ft_putstrfile("2️⃣");
	if (input == 3)
		return ft_putstrfile("3️⃣");
	if (input == 4)
		return ft_putstrfile("4️⃣");
	if (input == 5)
		return ft_putstrfile("5️⃣");
	if (input == 6)
		return ft_putstrfile("6️⃣");
	if (input == 7)
		return ft_putstrfile("7️⃣");
	if (input == 8)
		return ft_putstrfile("8️⃣");
	if (input == 9)
		return ft_putstrfile("9️⃣");
	if (input == 10)
		return ft_putstrfile("🔟");
	if (input == 11)
		return ft_putstrfile("🔢");
	if (input == 12)
		return ft_putstrfile("🔼");
	if (input == 13)
		return ft_putstrfile("⬆️");
	if (input == 14)
		return ft_putstrfile("⏫");
		/*
	if (input == 14)
		return ft_putstrfile("✅");
	if (input == 15)
		return ft_putstrfile("⚛️");
		*/
	return ft_putstrfile("☑️");
}

void debug_value_map_color(t_map *map, char *tab)
{
	int row;
	int col;

	row = -1;
	while (++row < map->row)
	{
		col = -1;
		ft_putstrfile(tab);
		while (++col < map->col)
			map_print(map->map[row][col]);
		ft_putstrfile("\n");
	}
	ft_putstrfile("\n");
}