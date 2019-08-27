/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:48:26 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/10 02:29:16 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strnew(size_t size)
{
	void *out;

	if (size == (size_t)-1)
		return (NULL);
	if (!(out = malloc(size + 1)))
		return (NULL);
	ft_bzero(out, size + 1);
	return (out);
}
