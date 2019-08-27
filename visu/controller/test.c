#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define FIFO_CMD		"../fifo_2"
#define BUFF_SZ			512

int32_t		g_fdcmd = -1;

static inline int8_t	ft_data_valid(void)
{
	if ((g_fdcmd = open(FIFO_CMD, O_RDONLY)) == -1)
	{
		printf("fifo error: %s\n", strerror(errno));
		return (0);
	}
	return (1);
}

int32_t					main(void)
{
	int32_t cnt;
	char	*buff[BUFF_SZ];

	if (!ft_data_valid())
		return (1);
	while (1)
	{
		cnt = read(g_fdcmd, buff, BUFF_SZ);		
		write(1, buff, cnt);
	}
    return (0);
}
