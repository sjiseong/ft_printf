/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:45:12 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 00:15:38 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	uc;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*s == uc)
		{
			*d++ = *s;
			return (d);
		}
		*d++ = *s++;
	}
	return (0);
}
