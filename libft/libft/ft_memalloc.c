/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memem_stock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:58:06 by bandre            #+#    #+#             */
/*   Updated: 2017/03/21 00:17:43 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*mem;
	unsigned	i;
	char		*t;

	i = 0;
	mem = (void*)mem_stock(size);
	if (mem == NULL)
		return (NULL);
	t = mem;
	while (i < size)
	{
		t[i] = 0;
		i++;
	}
	return (mem);
}
