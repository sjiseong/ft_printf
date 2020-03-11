/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:17:09 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/24 17:27:11 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*ns;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	ns = (char*)malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (0);
	while (s[i])
	{
		ns[i] = f(s[i]);
		i++;
	}
	ns[i] = 0;
	return (ns);
}
