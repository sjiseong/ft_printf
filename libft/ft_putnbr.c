/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:53:50 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/24 17:08:53 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	printnbr(long n, char c)
{
	if (!n)
		return ;
	printnbr(n / 10, c);
	c = n % 10 + 48;
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	long	ln;
	char	c;

	ln = (long)n;
	if (ln < 0)
	{
		write(1, "-", 1);
		ln = -ln;
	}
	c = 0;
	if (!n)
		write(1, "0", 1);
	else
		printnbr(ln, c);
}
