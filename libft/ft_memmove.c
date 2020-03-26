/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:16:49 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 00:51:42 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!len || dst == src)
		return (dst);
	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (d > s)
	{
		while (i++ < len)
			d[len - i] = s[len - i];
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}
