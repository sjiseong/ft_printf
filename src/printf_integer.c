/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:10:48 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 17:29:16 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_signed_int(long long n, t_form *form, char *s)
{
	if (form->type == 'd' || form->type == 'i')
	{
		s = ft_lltoa_base(n, 10);
		s = prepend(s, '0', form->prec - ft_strlen(s));
		form->flag -= form->prec ? F_ZERO : 0;
	}
	if (form->type == 'c' || form->type == 'C')
	{
		ft_bzero((s = (char*)malloc(2)), 2);
		s[0] = (char)n;
	}
	if (form->flag & F_MINUS)
	{
		s = add_flag_sign_integer(s, form, n);
		s = append(s, ' ', form->width - ft_strlen(s));
	}
	else
	{
		if (form->flag & F_ZERO)
			s = prepend(s, '0', form->width - ft_strlen(s) - 
					(form->flag & F_PLUS || form->flag & F_SPACE ? 1 : 0));
		s = add_flag_sign_integer(s, form, n);
		s = prepend(s, ' ', form->width - ft_strlen(s));
	}
	return (ft_putstr_free(s));	
}

int	printf_unsigned_int(unsigned long long n, t_form *form, char *s)
{
	if (form->type == 'u')
		s = ft_ulltoa_base(n, 10);
	else if (form->type == 'x' || form->type == 'X')
		s = ft_ulltoa_base(n, 16);
	else if (form->type == 'o')
		s = ft_ulltoa_base(n, 8);
	s = prepend(s, '0', form->prec - ft_strlen(s));
	form->flag -= form->prec != -1 ? form->flag & F_ZERO : 0;
	if (form->type == 'X')
		ft_capitalize(s);
	if (form->flag & F_HASH  && n &&
			(form->type == 'x' || form->type == 'X' || form->type == 'o'))
	{
		if (form->type == 'x' || form->type == 'X')
			s = prepend(s, form->type, 1);
		s = prepend(s, '0', 1);
	}
	if (form->flag & F_MINUS)
		s = append(s, ' ', form->width - ft_strlen(s));
	else if (form->flag & F_ZERO)
		s = prepend(s, '0', form->width - ft_strlen(s));
	s = prepend(s, ' ', form->width - ft_strlen(s));
	return (ft_putstr_free(s));
}

int	printf_integer(t_form *form, va_list ap)
{
	long long	n;
	char		*s;

	n = 0;
	s = 0;
	if (form->len == L_ll)
		n = va_arg(ap, long long);
	else if (form->len == L_l)
		n = va_arg(ap, long);
	else if (form->len == 0)
		n = va_arg(ap, int);
	else if (form->len == L_h)
		n = (short)va_arg(ap, int);
	else if (form->len == L_hh)
		n = (char)va_arg(ap, int);
	if (form->type_size == T_INT) 
		return (printf_signed_int(n, form, s));
	else if (form->type_size == T_UINT)
		return (printf_unsigned_int(n, form, s));
	return (0);
}
