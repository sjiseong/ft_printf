/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:01:28 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 15:43:54 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*append(char *s, char c, int n)
{
	char	*new;
	int		i;

	if (n < 1)
		return (s);
	new = (char*)malloc(ft_strlen(s) + n);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	while (n--)
		new[i++] = c;
	new[i] = 0;
	free(s);
	return (new);
}

char	*prepend(char *s, char c, int n)
{
	char	*new;
	int		i;
	int		j;

	if (n < 1)
		return (s);
	new = (char*)malloc(ft_strlen(s) + n);
	i = 0;
	j = 0;
	while (n--)
		new[i++] = c;
	while (s[j])
		new[i++] = s[j++];
	new[i] = 0;
	free(s);
	return (new);
}

char	*add_flag_sign_integer(char *s, t_form *form, int n)
{
	if (form->type == 'd' || form->type == 'i')
	{
		if (form->flag & F_PLUS && n >= 0)
			s = prepend(s, '+', 1);
		else if (form->flag & F_SPACE && n >= 0)
			s = prepend(s, ' ', 1);
		else if (((form->flag & F_PLUS) || (form->flag & F_SPACE)) && n < 0)
			s = prepend(s, '-', 1);
	}
	return (s);
}

char	*add_flag_sign_double(char *s, t_form *form, double f)
{
	if (form->type_size == T_DOUBLE)
	{
		if (form->flag & F_PLUS && f >= 0)
			s = prepend(s, '+', 1);
		else if (form->flag & F_SPACE && f >= 0)
			s = prepend(s, ' ', 1);
		else if (((form->flag & F_PLUS) || (form->flag & F_SPACE)) && f < 0)
			s = prepend(s, '-', 1);
	}
	return (s);
}

int		ft_putstr_free(char *s)
{
	int	ret;

	ret = ft_putstr(s);
	free(s);
	return (ret);
}
