/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form->t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:06:13 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/10 17:51:37 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion(char c)
{
	if (c == '%' || c == 'd' || c == 'i' || c == 'u' || c == 'f' || c == 'F' ||
	c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'x' || c == 'X' ||
	c == 'o' || c == 's' || c == 'c' || c == 'p' || c == 'a' || c == 'A' ||
	c == 'n')
		return (1);
	return (0);
}

t_list	*fmt_split(char *s)
{
	t_list	*lst;
	char	*tmp;

	lst = 0;
	while (*s)
	{
		if (*s == '%')
		{
			tmp = s++;
			while (*s && !(is_conversion(*s)))
				s++;
			if (*s)
				s++;
			tmp = ft_strndup(tmp, s - tmp);
			ft_lstnewadd(&lst, tmp, ft_strlen(tmp));
		}
		else
		{
			tmp = s++;
			while (*s && *s != '%')
				s++;
			tmp = ft_strndup(tmp, s - tmp);
			ft_lstnewadd(&lst, tmp, ft_strlen(tmp));
		}
	}
	return (lst);
}

t_form	*get_form(char *s, char type)
{
	t_form	*form;
//	char	*tmp;

//	tmp = s;
	form = (t_form*)malloc(sizeof(t_form));
	form->flag = get_flag(s);
	form->width = get_width(s);
	form->prec = get_precision(s);
	form->type = type;
	form->type_size = get_type_size(type);
	form->len = get_length(s, form->type_size);
//	form->param = get_parameter(tmp);
	return (form);
}
