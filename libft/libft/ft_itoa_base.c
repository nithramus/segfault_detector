/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:34:21 by bandre            #+#    #+#             */
/*   Updated: 2016/12/04 20:45:05 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_base(int value, int maj)
{
	if (value <= 9)
		return ((char)value + '0');
	else if (maj == 1)
		return ((char)value - 10 + 'A');
	else
		return ((char)value - 10 + 'a');
}

char		*ft_itoa_base(size_t value, int base, int maj)
{
	int		len;
	int		i;
	size_t	stock;
	char	*chaine;

	stock = value;
	len = 1;
	while (stock /= base)
		len++;
	if (!(chaine = (char*)mem_stock((sizeof(char) * len) + 1)))
		return (NULL);
	chaine[len] = '\0';
	i = 1;
	while (len >= i)
	{
		chaine[len - 1] = ft_base((value % base), maj);
		value /= base;
		len--;
	}
	return (chaine);
}
