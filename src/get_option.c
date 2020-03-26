/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:51:48 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 17:28:53 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_num(char c)
{
	if (c == '+')
		return (F_PLUS);
	else if (c == '-')
		return (F_MINUS);
	else if (c == '0')
		return (F_ZERO);
	else if (c == '#')
		return (F_HASH);
	else if (c == ' ')
		return (F_SPACE);
	else if (c == '\'')
		return (F_APOS);
	return (0);
}

int	get_parameter(char *s)
{
	static int	param;
	char		*tmp;

	param = 1;
	tmp = s;
	while (*s < '0' || *s > '9')
		s++;
	if (*s != '$')
		return (param++);
	param = ft_atoi(tmp);
	return (param);
}

int	get_flag(char *s)
{
	int		flag;
	int		tmp;

	flag = 0;
	while (*s)
	{
		if ((tmp = flag_num(*s)))
		{
			if (tmp == F_ZERO)
				if (ft_isdigit(*(s - 1)))
					tmp = 0;
			if (!(flag & tmp))
				flag += tmp;
		}
		s++;
	}
	return (flag);
}

int	get_width(char *s)
{
	int		i;
	int		is_width;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			is_width = 1;
			if (s[i + 1] == '$')
				is_width = 0;
			i--;
			while (i >= 0 && s[i] >= '0' && s[i] <= '9')
				i--;
			if (is_width && s[i] != '.')
				return (ft_atoi(s + i + 1));
		}
		i--;
	}
	return (0);
}

int	get_precision(char *s)
{
	int		i;
	int		is_prec;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			is_prec = 1;
			if (s[i + 1] == '$')
				is_prec = 0;
			i--;
			while (i >= 0 && s[i] >= '0' && s[i] <= '9')
				i--;
			if (is_prec && s[i] == '.')
				return (ft_atoi(s + i + 1));
		}
		else if (s[i] == '.')
			return (0);
		i--;
	}
	return (-1);
}

int	length_num(char *s)
{
	if (*s == 'h')
		if (*(s + 1) == 'h')
			return (L_hh);
		else
			return (L_h);
	else if (*s == 'l')
		if (*(s + 1) == 'l')
			return (L_ll);
		else
			return (L_l);
	else if (*s == 'L')
		return (L_L);
	return (0);
}

int	get_type_size(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'c' || c == 'C')
		return (T_INT);
	else if (c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'o' || c == 'O')
		return (T_UINT);
	else if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' ||
				c == 'G' || c == 'a' || c == 'A')
		return (T_DOUBLE);
	else if (c == 's' || c == 'S')
		return (T_STR);
	else if (c == 'p')
		return (T_PTR);
	return (0);
}

int	get_length(char *s, int type_size)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	while (s[i])
	{
		if ((tmp = length_num(s + i)))
		{
			if (tmp == L_hh || tmp == L_ll)
				i++;
			if (type_size == T_INT || type_size == T_UINT)
			{
				if (tmp == L_hh || tmp == L_h || tmp == L_l || tmp == L_ll)
					len = tmp > len ? tmp : len;
			}
			else if (type_size == T_DOUBLE)
				if (tmp == L_l || tmp == L_L)
					len = tmp > len ? tmp : len;
		}
		i++;
	}
	return (len);
}
