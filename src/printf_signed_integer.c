/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_signed_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:10:48 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 17:29:16 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*lltoa_no_flag(long long n)
{
	char	*s;
	char	*tmp;

	tmp = ft_lltoa_base(n, 10);
	if (tmp[0] == '-')
	{
		s = ft_strdup(tmp + 1);
		free(tmp);
	}
	else
		s = tmp;
	return (s);
}

static int	printf_char(char c, t_form *form, char *s)
{
	int	is_nonprint;

	is_nonprint = 0;
	ft_bzero((s = (char*)malloc(3)), 3);
	if (c >= 0 && c < 32)
	{
		s[0] = '^';
		s[1] = '@' + c;
		is_nonprint = 1;
	}
	else
		s[0] = c;
	if (form->flag & F_MINUS)
		s = append(s, ' ', form->width - 1);
	else
		s = prepend(s, ' ', form->width - 1);
	return (ft_putstr_free(s) - is_nonprint);
}

int		printf_signed_int(long long n, t_form *form, char *s)
{
	if (!n && !form->prec)
		s = ft_strdup("");
	else
		s = lltoa_no_flag(n);
	s = prepend(s, '0', form->prec - ft_strlen(s));
	form->flag -= form->prec != -1 ? form->flag & F_ZERO : 0;
	if (form->flag & F_MINUS)
	{
		s = add_flag_sign_integer(s, form, n);
		s = append(s, ' ', form->width - ft_strlen(s));
	}
	else
	{
		if (form->flag & F_ZERO)
			s = prepend(s, '0', form->width - ft_strlen(s) - 
			(form->flag & F_PLUS || form->flag & F_SPACE || n < 0 ? 1 : 0));
		s = add_flag_sign_integer(s, form, n);
		s = prepend(s, ' ', form->width - ft_strlen(s));
	}
	return (ft_putstr_free(s));
}

int		printf_signed_integer(t_form *form, va_list ap)
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
	return (form->type == 'c' || form->type == 'C' ?
		printf_char(n, form, s) : printf_signed_int(n, form, s));
}
