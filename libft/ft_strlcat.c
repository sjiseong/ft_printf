/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:15:52 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/25 12:30:31 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= dstsize)
		return (dstsize + slen);
	dstsize -= dlen + 1;
	while (*dst)
		dst++;
	while (dstsize--)
	{
		if (!*src)
			break ;
		*dst++ = *src++;
	}
	*dst = 0;
	return (dlen + slen);
}
