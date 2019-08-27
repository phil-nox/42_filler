#include "human.h"

size_t	ftt_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int load_view(int *fd_adp, int *fd_map)
{   

    *fd_adp = open(FIFO_ADP, O_RDONLY);
    printf("fd_adp=%d\n", *fd_adp);
    if (*fd_adp < 1)
    {
        write(1, "Failed with open() FIFO_ADP\n", 29);
        return (1);
    }
    write(1, "open_adp:\tdone\n", 16);

    *fd_map = open(FIFO_MAP, O_RDONLY);
    printf("fd_map=%d\n", *fd_map);
    if (*fd_map < 1)
    {
        write(1, "Failed with open() FIFO_MAP\n", 29);
        return (1);
    }
    write(1, "open_map:\tdone\n", 16);

    write(1, "open:\tdone\n", 12);

    write(1, "start! wait fd_map&fd_adp\n", 27);
    return (0);
}

int main(void)
{
    // read human_model.c

    int fd_adp;
    int fd_map;
    int pos;
    char line[BUF_SIZE];
    line[0] = '\0';

    if (load_view(&fd_adp, &fd_map))
        return (1);
    
    //while ((pos = read(fd_adp, line, BUF_SIZE)))
    while ((pos = read(fd_map, line, BUF_SIZE)))
    {
        line[pos] = '\0';
        write(1, line, ftt_strlen(line));
        /*
        while ((pos = read(fd_adp, line, BUF_SIZE)))
        {
            line[pos] = '\0';
            write(1, line, ftt_strlen(line));
        }
        */
    }

    while ((pos = read(fd_adp, line, BUF_SIZE)))
    {
        line[pos] = '\0';
        write(1, line, ftt_strlen(line));
        /*
        while ((pos = read(fd_adp, line, BUF_SIZE)))
        {
            line[pos] = '\0';
            write(1, line, ftt_strlen(line));
        }
        */
    }

    close(fd_adp);
    close(fd_map);
    return (0);
}