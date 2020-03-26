/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 01:36:48 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 01:41:21 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char	*odst;

	odst = dst;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
	return (odst);
}
