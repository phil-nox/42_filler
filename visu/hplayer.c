#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define FIFO_CMD	"fifo_2"
#define	FIFO_MAP	"fifo_1"
#define BUFF_SZ		4096

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

    int fdcmd;
//	int fdcmd_tmp;
//	int	fdmap_tmp;
	int	fdmap;
//	int fd_test;
	int		r_cnt1 = 0;
	int		r_cnt2 = 0;
	char	buff1[BUFF_SZ];
	char	buff2[BUFF_SZ];

/* 	unlink(FIFO_MAP);
  if (mkfifo(FIFO_MAP, 0777) != 0)
    {
		printf("%s\n", strerror(errno));
        return (1);
    }*/
//	fdmap_tmp = open(FIFO_MAP, O_RDONLY);
//	fdcmd_tmp = open(FIFO_CMD, O_WRONLY);
	fdcmd = open(FIFO_CMD, O_RDONLY);
    fdmap = open(FIFO_MAP, O_WRONLY);
//	fdcmd = open(FIFO_CMD, O_RDONLY|O_NONBLOCK);

//int fd_test = open("test", O_RDWR|O_APPEND);
//if (fd_test == -1)
//	printf("%s\n", strerror(errno));
   while (1)
    {
		r_cnt1 = read(0, buff1, BUFF_SZ);
		if (r_cnt1 > 0)
			write(fdmap, buff1, r_cnt1);

        r_cnt2 = read(fdcmd, buff2, BUFF_SZ);
        write(1, buff2, r_cnt2);//ftt_strlen(buff2));
		if (r_cnt1 <= 0)
			write(fdmap, "+-\n", 3);
//        if (line[0] == 'x')
//        {
//            close(fd);
//            unlink(FIFO_NAME);
//			close(fd_map);
//			unlink(FIFO_MAP);
//            return (0);
//			}
    }
}
