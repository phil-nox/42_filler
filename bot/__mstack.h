/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __mstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:44:51 by wgorold           #+#    #+#             */
/*   Updated: 2019/08/06 17:54:38 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MSTACK_H
# define __MSTACK_H

#include "libft.h"

int	free_mstack(void *to_free);
void	free_all_mstack(void);
int	add_mstack(void *to_add);

#endif