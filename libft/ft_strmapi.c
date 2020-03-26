/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:25:07 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/19 21:32:42 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*ns;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	ns = (char*)malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (0);
	while (s[i])
	{
		ns[i] = f(i, s[i]);
		i++;
	}
	ns[i] = 0;
	return (ns);
}
