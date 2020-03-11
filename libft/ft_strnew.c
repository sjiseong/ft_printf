/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:44:15 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 20:48:21 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	size++;
	str = (char*)malloc(sizeof(char) * size);
	if (!str)
		return (0);
	while (size--)
		str[size] = 0;
	return (str);
}
