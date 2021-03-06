/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:53:23 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/27 20:03:27 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;

	s2 = (char*)malloc(n + 1);
	if (!s2)
		return (s2);
	s2[n] = 0;
	while (n--)
		s2[n] = s1[n];
	return (s2);
}
