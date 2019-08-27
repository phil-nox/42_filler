#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// How to run
// make -C./libft && gcc gnl_test.c -L./libft/build -lft -I./libft && ./a.out

// Clean up
// make fclean -C./libft && rm -f a.out

int main(void)
{
    int fd;
    char *path2file;
    char *line;

    path2file = "README.md";
    fd = open(path2file, O_RDONLY);

    while (get_next_line(fd, &line) == 1)
	{
        printf("%s\n", line);
		free(line);
	}
	close(fd);
}