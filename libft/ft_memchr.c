/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:55:36 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 01:05:39 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*ptr;

	uc = (unsigned char)c;
	ptr = (unsigned char*)s;
	while (n--)
	{
		if (*ptr == uc)
			return (ptr);
		ptr++;
	}
	return (0);
}
