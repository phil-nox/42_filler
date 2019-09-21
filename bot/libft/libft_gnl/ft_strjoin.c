/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:22:40 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/09 23:31:07 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *arr[3];

	if (!s1 && !s2)
		return (NULL);
	arr[0] = (s1) ? (char *)s1 : (char *)s2;
	arr[1] = (!s1) ? NULL : (char *)s2;
	arr[2] = NULL;
	return (ft_strajoin(arr));
}
