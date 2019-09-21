/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:44:51 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/21 20:20:22 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft_full.h"

# define FIFO_MAP "mypipe.map"
# define FIFO_CMD "mypipe.cmd"
# define FIFO_ADP "mypipe.adp"
# define FIFO_VM "mypipe.vm"
# define TMP_PTY "tmp_pty"
# define BUF_SIZE 1024
#endif
