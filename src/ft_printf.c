/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:53:52 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/11 13:15:11 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_each(t_form *form, va_list ap)
{
	if (form->type_size == T_INT || form->type_size == T_UINT)
		printf_integer(form, ap);
	else if (form->type_size == T_DOUBLE)
		printf_double(form, ap);
	return (0);
}

int	printf_list(t_list *lst, va_list ap)
{
	char	*s;
	int		ret;
	int		tmp;
	t_form	*form;

	ret = 0;
	while (lst)
	{
		s = (char*)(lst->content);
		if (s[0] == '%')
		{
			if (s[lst->content_size - 1] == '%')
				ret += write(1, "%", 1);
			else
			{
				form = get_form(s, s[lst->content_size - 1]);
				if ((tmp = printf_each(form, ap)) == -1)
					return (-1);
				ret += tmp;
			}
		}
		else
			ret += write(1, s, lst->content_size);
		lst = lst->next;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*fmt_lst;
//	t_list	*var_lst;
	int		ret;
	
	va_start(ap, format);
	fmt_lst = fmt_split((char*)format);
//	var_lst = get_varlist(fmt_lst, ap);
	ret = printf_list(fmt_lst, ap);
/*	while (lst)
	{
		printf("lst : %s\n", lst->content);
		lst = lst->next;
	}
*/
	va_end(ap);
	return (0);
}

int	main()
{
	double f = 1234.56789;
/*	ft_printf("%+010.5d, %10-i, %+-0 5.10c\n", 42, 42, 42);
	printf("%+010.5d, %10-i, %+-0 5.10c\n", 42, 42, 42);
	ft_printf("%+010.5u, %#10-x, %+-0 5.10o\n", 42, 42, 42);
	printf("%+010.5u, %#10-x, %+-0 5.10o\n", 42, 42, 42);*/
	ft_printf("%f, %10.5f, %+0- #f, %10.0f\n", f, f, f, f);
	printf("%f, %10.5f, %+0- #f, %10.0f\n", f, f, f, f);
	return 0;
}
