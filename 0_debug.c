#include "filler.h"

int get_fdd()
{
	static int fdd;
	char *path2debug;

	if (fdd < 1)
	{
		path2debug = "test_debug";
		fdd = open(path2debug, O_RDWR); 
	}
	return (fdd);
}

int ft_pututf8(char const *s)
{
	int idx;
	int fdd;
	
	fdd = get_fdd();

	idx = 1;
	if ((*s & 0xC0) == 0xC0)
		idx = 2;
	if ((*s & 0xE0) == 0xE0)
		idx = 3;
	if ((*s & 0xF0) == 0xF0)
		idx = 4;

	return (write(fdd, s, idx));
}

void ft_putallchar(int c)
{
	ft_pututf8((char *)&c);
}

void debug_print(char *str, int next_line, int to_free)
{
	int fdd;
	
	fdd = get_fdd();
	if (to_free == -1)
	{
		close(fdd);
		return ;
	}

	write(fdd, str, ft_strlen(str));
	
	if (next_line)
		write(fdd, "\n", 1);

	if (to_free)
		free(str);
}

void find_debug(t_map *map, int pos, int res, int tmp_score)
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
	 {
		debug_print("\t- <== good ", 0, 0);
		debug_print(ft_itoa(tmp_score), 1, 1);
	 }
	 if(res == 2)
	 {
		debug_print("\t- => SEND ", 0, 0);
		debug_print(ft_itoa(tmp_score), 1, 1);
	 }
}

void send_debug(t_map *map, int pos, int tmp_score)
{
	debug_print(ft_itoa(pos), 0, 1);
	debug_print("\t ", 0, 0);
	debug_print(ft_itoa(row_p(map, pos)), 0, 1);
	debug_print(" ", 0, 0);
	debug_print(ft_itoa(col_pg(map, pos)), 0, 1);
	debug_print("\t- => SEND ", 0, 0);
	debug_print(ft_itoa(tmp_score), 1, 1);
}


void debug_value_map(t_map *map)
{
	int idx;

	idx = -1;
	while (++idx < map->row)
		debug_print(map->map[idx], 1, 0);
	 debug_print("\n", 1, 0);
}

int map_print(char input)
{
	if (input == 'y')
		return ft_pututf8("🦑");
	if (input == 'z')
		return ft_pututf8("🐢");
	if (input == '.')
		return ft_pututf8("🔹");
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