/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:59:58 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 15:15:46 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char*)s1;
	ptr2 = (char*)s2;
	if (!*ptr2)
		return (ptr1);
	while (*ptr1)
	{
		if (*ptr1 == *ptr2)
		{
			s1 = ptr1;
			while (*++ptr2)
			{
				if (*ptr2 != *++ptr1)
					break ;
			}
			if (!*ptr2)
				return ((char*)s1);
			ptr1 = (char*)s1;
			ptr2 = (char*)s2;
		}
		ptr1++;
	}
	return (0);
}
