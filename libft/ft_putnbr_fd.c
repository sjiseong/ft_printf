/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:16:53 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/24 17:09:08 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	printnbr_fd(long n, char c, int fd)
{
	if (!n)
		return ;
	printnbr_fd(n / 10, c, fd);
	c = n % 10 + 48;
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	ln = (long)n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	c = 0;
	if (!n)
		write(fd, "0", 1);
	else
		printnbr_fd(ln, c, fd);
}
