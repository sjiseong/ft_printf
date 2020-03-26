/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:48:41 by sjiseong          #+#    #+#             */
/*   Updated: 2020/03/08 16:40:00 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ptype	*new_ptype(int index, int type)
{
	t_ptype	*ptype;

	ptype = (t_ptype*)malloc(sizeof(t_ptype));
	ptype->index = index;
	ptype->type = type;
	return (ptype);
}

void	add_ptype(t_list **ptr, char c)
{
	int	type;

	type = 0;
	if (cv == 'd' || cv == 'D' || cv == 'i')
		type = T_INT;
	else if (cv == 'u' || cv == 'U' || cv == 'x' || cv == 'X' || cv == 'o' ||
				cv == 'O')
		type = T_UINT;
	else if (cv == 'f' || cv == 'F' || cv == 'e' || cv == 'E' || cv == 'g' ||
				cv == 'G' || cv == 'a' || cv == 'A')
		type = T_DOUBLE;
	else if (cv == 's' || cv == 'S')
		type = T_STR;
	else if (cv == 'c' || cv == 'C')
		type = T_CHAR;
	else if (cv == 'p')
		type = T_PTR;
	ft_lstnewadd(ptr,
			new_ptype(get_parameter(tmp + 1), type), sizeof(t_ptype));
}

t_list	*sort_ptype_list(t_list *tmp, t_list *new, t_ptype *min, int pre)
{
	t_list	*tmp2

	while (tmp)
	{
		tmp2 = tmp;
		while (tmp2)
		{
			if ((!min || tmp2->content->index < min->index) &&
					tmp2->content->index > pre)
				min = tmp2->content;
			tmp2 = tmp2->next;
		}
		ft_lstnewadd(&new, min, sizeof(t_ptype));
		pre = min->index;
		min = 0;	
		tmp = tmp->next;
	}
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	return (new);
}

void	get_arg(t_list **lst, int type, va_list ap)
{
	if (type == T_INT)

}

t_list	*get_args(t_list *ptype_lst, va_list ap)
{
	int		i;
	t_list	*lst;

	ptype_lst = sort_ptype_list(ptype_lst, 0, 0, INT_MIN);
	i = 0;
	while (1)
	{
		if (!ptype_lst)
			break ;
		if (ptype_lst->content->index == i++)
			get_arg(&lst, ptype_lst->content->type, ap);
		ptype_lst = ptype_lst->next;
	}
}

t_list	*get_varlist(t_list *fmt_lst, va_list ap)
{
	t_list	*ptype_lst;
	char	*s;
	char	*tmp;

	while (fmt_lst)
	{
		s = (char*)(fmt_lst->content);
		tmp = s;
		if (s[0] == '%' && s[fmt_lst->content_size - 1] != '%')
		{
			while (tmp = ft_strchr(tmp, '*'))
			{
				ft_lstnewadd(&ptype_lst,
					new_ptype(get_parameter(tmp + 1), T_INT), sizeof(t_ptype));
			}
			add_ptype(&ptype_lst, s[1]);
		}
		fmt_lst = fmt_lst->next;
	}
	get_args(ptype_lst, ap);
}
