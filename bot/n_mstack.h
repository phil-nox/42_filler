/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_mstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:44:51 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/21 20:15:29 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef N_MSTACK_H
# define N_MSTACK_H

# include "libft_full.h"

t_list	**get_mstack(void);
int		free_mstack(void *to_free);
int		free_all_mstack(void);
int		add_mstack(void *to_add);
int		num_mstack();

#endif
