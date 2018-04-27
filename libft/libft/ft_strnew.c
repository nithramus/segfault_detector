/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:10:41 by bandre            #+#    #+#             */
/*   Updated: 2017/03/21 00:29:21 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*chainretour;
	size_t	i;

	i = 0;
	chainretour = (char*)mem_stock(size + 1);
	if (chainretour == NULL)
		return (NULL);
	while (i < (size + 1))
	{
		chainretour[i] = '\0';
		i++;
	}
	return (chainretour);
}
