/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 01:42:31 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/20 09:53:56 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*odst;

	odst = dst;
	while (len--)
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = 0;
	return (odst);
}
