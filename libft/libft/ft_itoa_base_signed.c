/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:34:21 by bandre            #+#    #+#             */
/*   Updated: 2016/12/05 18:54:49 by bandre           ###   ########.fr       */
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

char		*ft_itoa_base_signed(ssize_t value, int base, int maj)
{
	int		len;
	int		i;
	ssize_t	stock;
	char	*chaine;

	stock = value;
	len = (value < 0) ? 2 : 1;
	while (stock /= base)
		len++;
	if (!(chaine = (char*)mem_stock((sizeof(chaine) * len) + 1)))
		return (NULL);
	chaine[0] = '-';
	chaine[len] = '\0';
	i = (value < 0) ? 2 : 1;
	value = (value > 0) ? (-1) * value : value;
	while (len >= i)
	{
		chaine[len - 1] = ft_base(-(value % base), maj);
		value /= base;
		len--;
	}
	return (chaine);
}
