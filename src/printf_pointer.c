/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:05:05 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 16:24:09 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_string(t_form *form, va_list ap)
{
	char	*s;

	s = va_arg(ap, char*);
	if (!s)
		s = strdup("(null)");
	else if (form->prec < (int)ft_strlen(s))
		s = strndup(s, form->prec);
	else
		s = strdup(s);
	if (form->flag & F_MINUS)
		s = append(s, ' ', form->width - ft_strlen(s));
	else
		s = prepend(s, ' ', form->width - ft_strlen(s));
	return (ft_putstr_free(s));
}

int	printf_pointer(t_form *form, va_list ap)
{
	char	*s;
	char	*tmp;

	tmp = ft_ulltoa_base((unsigned long long)va_arg(ap, void*), 16);
	s = ft_strjoin("0x", tmp);
	free(tmp);
	if (form->flag & F_MINUS)
		s = append(s, ' ', form->width - ft_strlen(s));
	else
		s = prepend(s, ' ', form->width - ft_strlen(s));
	return (ft_putstr_free(s));
}
