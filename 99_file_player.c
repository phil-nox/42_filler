#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
//#include <stdio.h>

#define FIFO_NAME "human_player"

size_t	ftt_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int main(void)
{
    // gcc -Wall -Wextra -Werror 99_file_player.c -o 99_player.filler

    // ./99_player.filler  
    // echo '1 2' > FIFO_NAME

    // ./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./99_player.filler -f ./resources/maps/map00
    // echo '8 2' > FIFO_NAME

    int fd;
    int pos;
    char line[100];
    line[0] = '\0';

    unlink(FIFO_NAME);
    if (mkfifo(FIFO_NAME, 0777) != 0)
    {
        //perror("mkfifo() error"); //#include <stdio.h>
        return (1);
    }
    fd = open(FIFO_NAME, O_RDONLY);

    while (1)
    {
        pos = read(fd, line, 100);
        line[pos] = '\0';
        write(1, line, ftt_strlen(line));
        if (line[0] == 'x')
        {
            close(fd);
            unlink(FIFO_NAME);
            return (0);
        }
    }
}