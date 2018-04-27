/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:59:11 by bandre            #+#    #+#             */
/*   Updated: 2017/02/01 19:59:18 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_ptradd(void **list, void *add)
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
	return (new);
}
