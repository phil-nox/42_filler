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