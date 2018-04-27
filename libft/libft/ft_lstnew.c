/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:35:28 by bandre            #+#    #+#             */
/*   Updated: 2016/11/09 16:12:17 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)mem_stock(sizeof(t_list));
	if (new)
	{
		if (content)
		{
			new->content = (void*)mem_stock(content_size);
			if (new->content)
				ft_memcpy(new->content, content, content_size);
			else
				return (NULL);
			new->content_size = content_size;
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
		return (new);
	}
	else
		return (NULL);
}
