/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:54:34 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 18:30:18 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*debut;
	char	*fin;
	size_t	i;

	i = 0;
	debut = (char*)src;
	fin = (char*)dest;
	while (i < n)
	{
		fin[i] = debut[i];
		i++;
	}
	return (dest);
}
