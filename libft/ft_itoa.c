/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:05:59 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/24 17:09:48 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	reverse(char *str)
{
	int		len;
	int		i;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

static char	*alloc_str(int n)
{
	int		size;
	char	*str;

	size = 0;
	if (!n)
		size++;
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		is_neg;

	if (!(str = alloc_str(n)))
		return (0);
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	i = 0;
	if (!n)
		str[i++] = '0';
	while (n)
	{
		str[i++] = ((n < 0) ? -(n % 10) : n % 10) + 48;
		n /= 10;
	}
	if (is_neg)
		str[i++] = '-';
	str[i] = 0;
	reverse(str);
	return (str);
}
