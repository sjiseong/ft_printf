/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:49:57 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/10 19:53:33 by sjiseong         ###   ########.fr       */
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

static char	*alloc_str(long long n, int base)
{
	int		size;
	char	*str;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= base;
		size++;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	return (str);
}

char		*ft_itoa_base(int n, int base)
{
	char	*str;
	int		i;
	int		is_neg;
	int		tmp;

	if (!(str = alloc_str(n, base)))
		return (0);
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	i = 0;
	if (!n)
		str[i++] = '0';
	while (n)
	{
		tmp = ((n < 0) ? -(n % base) : n % base);
		str[i++] = tmp < 10 ? tmp + '0' : tmp - 10 + 'a';
		n /= base;
	}
	if (is_neg)
		str[i++] = '-';
	str[i] = 0;
	reverse(str);
	return (str);
}

char		*ft_uitoa_base(unsigned int n, int base)
{
	char	*str;
	int		i;
	int		tmp;

	if (!(str = alloc_str(n, base)))
		return (0);
	i = 0;
	if (!n)
		str[i++] = '0';
	while (n)
	{
		tmp = n % base;
		str[i++] = tmp < 10 ? tmp + '0' : tmp - 10 + 'a';
		n /= base;
	}
	str[i] = 0;
	reverse(str);
	return (str);
}
