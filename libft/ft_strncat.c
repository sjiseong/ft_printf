/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:09:25 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 13:10:28 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;

	ptr = s1;
	while (*ptr)
		ptr++;
	while (n--)
	{
		if (!*s2)
			break ;
		*ptr++ = *s2++;
	}
	*ptr = 0;
	return (s1);
}
