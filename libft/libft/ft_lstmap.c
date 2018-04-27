/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:09:19 by bandre            #+#    #+#             */
/*   Updated: 2016/11/10 11:47:59 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *firstelem;
	t_list *temp;

	if (lst && f)
	{
		temp = ft_lstnew(lst->content, lst->content_size);
		temp = f(temp);
		firstelem = temp;
		lst = lst->next;
		while (lst)
		{
			temp->next = ft_lstnew(lst->content, lst->content_size);
			temp->next = f(temp->next);
			temp = temp->next;
			lst = lst->next;
		}
		return (firstelem);
	}
	else
		return (NULL);
}
