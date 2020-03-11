/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:03:46 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 18:18:34 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	while (*str == '\t' || *str == '\v' || *str == '\f' ||
			*str == '\r' || *str == '\n' || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	else if (*str != '+')
		str--;
	str++;
	i = 0;
	while (*str)
	{
		if (*str < 48 || *str > 57)
			break ;
		i *= 10;
		i += *str - 48;
		str++;
	}
	return (i * sign);
}
