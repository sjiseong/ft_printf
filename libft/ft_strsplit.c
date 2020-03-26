/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:30:13 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/24 17:08:21 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_c(char *str, char c)
{
	int	cnum;

	cnum = 0;
	while (*str)
	{
		if (*str++ != c)
			continue ;
		while (*str == c)
			str++;
		cnum++;
	}
	if (*--str == c)
		cnum--;
	return (cnum);
}

static int		split(char *s, char c, char **arr)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[j] != c && s[j] != 0)
			j++;
		if (!(arr[k] = (char*)malloc(sizeof(char) * (j - i + 1))))
			return (0);
		ft_strncpy(arr[k], s + i, j - i);
		arr[k][j - i] = 0;
		k++;
		while (s[j] == c)
			j++;
		i = j;
	}
	arr[k] = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	while (*s == c)
		s++;
	if (!(arr = (char**)malloc(sizeof(char*) * (count_c((char*)s, c) + 2))))
		return (0);
	if (!split((char*)s, c, arr))
		return (0);
	return (arr);
}
