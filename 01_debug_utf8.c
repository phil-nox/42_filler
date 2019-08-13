#include "filler.h"

int ft_putstrfile(char const *s)
{
	int idx;
	int fdd;
	
	fdd = get_fdd();
	
	idx = 0;
	while (s[idx])
		++idx;
	return (write(fdd, s, idx));
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