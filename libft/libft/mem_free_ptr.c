/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:29:18 by bandre            #+#    #+#             */
/*   Updated: 2017/04/29 20:36:31 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int free_void(t_mem_stock *list, void *ptr)
{
	int j;

	j = 0;
	while (j < 50)
	{
		if (list->list_ptr[j] == ptr)
		{
			free(list->list_ptr[j]);
			list->list_ptr[j] = NULL;
			return (1);
		}
		j++;
	}
	return (0);
}

void	mem_free_ptr(void *ptr)
{
	t_mem_stock *list;

	list = *(mem_ptr());
	while (list)
	{
		if (free_void(list, ptr))
			break ;
		list = list->next;
	}
}
