/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:39:06 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/25 14:15:01 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	tmp = f(lst);
	new->content = tmp->content;
	new->content_size = tmp->content_size;
	new->next = ft_lstmap(lst->next, f);
	return (new);
}
