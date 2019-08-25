#include "human.h"

size_t	ftt_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int load_model(int *fd_cmd, int *fd_map)
{
    unlink(FIFO_MAP);
    unlink(FIFO_CMD);
    write(1, "unlink:\tdone\n", 14);

    if (mkfifo(FIFO_MAP, 0777) != 0 || mkfifo(FIFO_CMD, 0777) != 0)
    {
        //perror("mkfifo() error"); //#include <stdio.h>
        write(1, "Failed with mkfifo()", 21);
        return (1);
    }
    write(1, "mkfifo:\tdone\n", 14);

    *fd_cmd = open(FIFO_CMD, O_RDONLY);
    if (*fd_cmd < 1 )
    {
        write(1, "Failed with open() FIFO_CMD\n", 29);
        return (1);
    }
    write(1, "open_cmd:\tdone\n", 16);

    *fd_map = open(FIFO_MAP, O_WRONLY);
    if (*fd_map < 1)
    {
        write(1, "Failed with open() FIFO_MAP\n", 29);
        return (1);
    }
    write(1, "open_map:\tdone\n", 16);
    write(1, "open:\tdone\n", 12);
    write(1, "start! wait fd_cmd\n", 20);
    return (0);
}


int main(void)
{
    // gcc -Wall -Wextra -Werror human_model.c -o human_model.filler && gcc -Wall -Wextra -Werror human_view_control.c -o human_view_control.filler

    // ./human_model.filler 
    // ./human_view_control.filler #(new terminal, some folder)
    // echo '1 2' > mypipe.cmd #FIFO_CMD #(new terminal, some folder)

    int fd_cmd;
    int fd_map;
    int pos;
    char line[BUF_SIZE];
    line[0] = '\0';

    if (load_model(&fd_cmd, &fd_map))
        return (1);

    while ((pos = read(fd_cmd, line, BUF_SIZE)))
    {
        line[pos] = '\0';
        write(1, line, ftt_strlen(line));
        if (line[0] != '>')
            write(fd_map, line, ftt_strlen(line));
        if (line[0] == 'x')
        {
            write(fd_map, line, ftt_strlen(line));
            break;
        }
    }
    close(fd_cmd);
    close(fd_map);
    unlink(FIFO_MAP);
    unlink(FIFO_CMD);
    return (0);
}