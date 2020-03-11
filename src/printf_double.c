/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:04:47 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 13:16:55 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_decimal(char *s, long double f, int len)
{
	int		i;
	int		j;
	double	round;
	char	*dec;
	char	*ret;

	len = (len == -1) ? 6 : len;
	i = 0;
	j = 1;
	round = 0.5;
	while (i++ < len)
		round *= 10;
	f += round;
	while (i-- > 0)
	{
		f *= 10;
		j *= 10;
	}
	dec = ft_lltoa_base((long long)f % j, 10);
	ret = ft_strjoin(s, dec);
	free(s);
	free(dec);
	return (ret);
}

int	printf_double(t_form *form, va_list ap)
{
	long double	f;
	char		*s;

	if (form->len == 0 || form->len == L_l)
		f = va_arg(ap, double);
	else if (form->len == L_L)
		f = va_arg(ap, long double);
	s = ft_lltoa_base((long long)f, 10);
	s = append(s, '.', 1);
	s = add_decimal(s, f, form->prec);
	if (form->flag & F_MINUS)
		s = append(s, ' ', form->width - ft_strlen(s) -
				((form->flag & F_PLUS || form->flag & F_SPACE) ? 1 : 0));
	else if (form->flag & F_ZERO)
		s = prepend(s, '0', form->width - ft_strlen(s) - 
				((form->flag & F_PLUS || form->flag & F_SPACE) ? 1 : 0));
	s = add_flag_sign_double(s, form, f);
	s = prepend(s, ' ', form->width - ft_strlen(s));
	return (ft_putstr(s));
}
