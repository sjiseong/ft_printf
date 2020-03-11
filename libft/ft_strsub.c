/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:43:35 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/20 14:21:14 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*tmp;

	if (!s)
		return (0);
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	tmp = substr;
	s += start;
	while (len--)
		*tmp++ = *s++;
	*tmp = 0;
	return (substr);
}
