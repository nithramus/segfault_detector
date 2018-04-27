/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:37:40 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 18:35:04 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	value;
	size_t	i;
	char	*pointeur;

	i = 0;
	value = (unsigned char)c;
	pointeur = str;
	while (i < n)
	{
		pointeur[i] = value;
		i++;
	}
	return (str);
}
