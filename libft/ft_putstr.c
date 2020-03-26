/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:49:13 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/10 22:03:05 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putstr(char const *s)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
