/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:38:15 by sjiseong          #+#    #+#             */
/*   Updated: 2020/02/24 17:35:39 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		lst->content = 0;
		lst->content_size = 0;
	}
	else
	{
		lst->content = (void*)malloc(content_size);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = 0;
	return (lst);
}
