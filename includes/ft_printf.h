/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:35:13 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 16:04:45 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# include <stdio.h>

typedef	struct	s_param_type
{
	int	index;
	int	type;
}				t_ptype;

typedef	struct	s_form
{
	int		param;
	int		flag;
	int		width;
	int		prec;
	int		len;
	char	type;
	int		type_size;
}				t_form;

# define T_INT		1
# define T_UINT		2
# define T_DOUBLE	4
# define T_STR		8
# define T_PTR		16

# define L_hh		1
# define L_h		2
# define L_l		4
# define L_ll		8
# define L_L		16

# define F_PLUS		1
# define F_MINUS	2
# define F_ZERO		4
# define F_HASH		8
# define F_SPACE	16
# define F_APOS		32

/*
**	util
*/

char			*prepend(char *s, char c, int n);
char			*append(char *s, char c, int n);
char			*add_flag_sign_integer(char *s, t_form *form, long long n);
char			*add_flag_sign_double(char *s, t_form *form, long double f);
int				ft_putstr_free(char *s);

/*
**	printf each type
*/

int				printf_signed_integer(t_form *form, va_list ap);
int				printf_unsigned_integer(t_form *form, va_list ap);
int				printf_double(t_form *form, va_list ap);
int				printf_string(t_form *form, va_list ap);
int				printf_pointer(t_form *form, va_list ap);

/*
**	format
*/

t_list			*fmt_split(char *s);
t_form			*get_form(char *s, char type);

/*
**	get_option
*/

int				is_flag(char c);
int				get_parameter(char *s);
int				get_flag(char *s);
int				get_width(char *s);
int				get_precision(char *s);
int				get_length(char *s, int type_size);
int				get_type_size(char c);
#endif
