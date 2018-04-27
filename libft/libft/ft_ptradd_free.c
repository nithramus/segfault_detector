/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptradd_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:58:55 by bandre            #+#    #+#             */
/*   Updated: 2017/04/02 18:41:37 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_ptradd_free(void **list, void *add)
{
	int		i;
	void	**new;

	i = 0;
	while (list[i])
		i++;
	if (!(new = (void**)mem_stock(sizeof(void*) * (i + 2))))
		return (NULL);
	i = 0;
	while (list[i])
	{
		new[i] = list[i];
		i++;
	}
	new[i] = add;
	new[i + 1] = NULL;
	mem_free_ptr(list);
	return (new);
}
