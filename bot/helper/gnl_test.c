/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:19:25 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 22:21:49 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*
** // How to run
** // make -C./libft && gcc gnl_test.c -L./libft/build -lft -I./libft && ./a.out
**
** // Clean up
** // make fclean -C./libft && rm -f a.out
*/

int	main(void)
{
	int		fd;
	char	*path2file;
	char	*line;

	path2file = "README.md";
	fd = open(path2file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		write(1, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}
