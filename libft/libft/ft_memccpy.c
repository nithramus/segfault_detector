/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:59:11 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 18:31:33 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
		if (debut[i] == c)
			return ((void*)&fin[i + 1]);
		i++;
	}
	return (NULL);
}
