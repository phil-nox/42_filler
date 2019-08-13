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

void debug_num(int num, int next_line)
{
	debug_print(ft_itoa(num), next_line, 1);
}