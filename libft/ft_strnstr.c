/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:18:01 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 16:44:04 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int	s2_len;
	int	i;

	if (!*s2)
		return ((char*)s1);
	s2_len = ft_strlen(s2);
	i = len - s2_len;
	while (*s1 && i-- > -1)
	{
		if (*s1 == *s2 && !ft_strncmp(s1, s2, s2_len))
			return ((char*)s1);
		s1++;
	}
	return (0);
}
