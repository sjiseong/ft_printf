/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned_integer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:10:48 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 17:29:16 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_unsigned_int(unsigned long long n, t_form *form, char *s, int base)
{
	if (!n && !form->prec)
		s = ft_strdup("");
	else
		s = ft_ulltoa_base(n, base);
	s = prepend(s, '0', form->prec - ft_strlen(s));
	form->flag -= form->prec != -1 ? form->flag & F_ZERO : 0;
	if (form->type == 'X')
		ft_capitalize(s);
	if (form->flag & F_ZERO && !(form->flag & F_MINUS))
		s = prepend(s, '0', form->width - ft_strlen(s) - 2);
	if (form->flag & F_HASH  && (n || form->type == 'o') &&
			(form->type == 'x' || form->type == 'X' || form->type == 'o'))
	{
		if (form->type == 'x' || form->type == 'X')
			s = prepend(s, form->type, 1);
		s = prepend(s, '0', 1);
	}
	else if (form->flag & F_ZERO && !(form->flag & F_MINUS))
		s = prepend(s, '0', 2);
	if (form->flag & F_MINUS)
		s = append(s, ' ', form->width - ft_strlen(s));
	s = prepend(s, ' ', form->width - ft_strlen(s));
	return (ft_putstr_free(s));
}

int	printf_unsigned_integer(t_form *form, va_list ap)
{
	unsigned long long	n;
	char			*s;
	int			base;

	n = 0;
	s = 0;
	if (form->len == L_ll)
		n = va_arg(ap, unsigned long long);
	else if (form->len == L_l)
		n = va_arg(ap, unsigned long);
	else if (form->len == 0)
		n = va_arg(ap, unsigned int);
	else if (form->len == L_h)
		n = (unsigned short)va_arg(ap, int);
	else if (form->len == L_hh)
		n = (unsigned char)va_arg(ap, int);
	base = (form->type == 'x' || form->type == 'X') ? 16 : 10;
	base = (form->type == 'o') ? 8 : base;
	return (printf_unsigned_int(n, form, s, base));
}
