/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:57:55 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 18:29:51 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chaine1;
	unsigned char	*chaine2;
	size_t			i;

	i = 0;
	chaine1 = (unsigned char*)s1;
	chaine2 = (unsigned char*)s2;
	while (i < n)
	{
		if (chaine1[i] != chaine2[i])
			return (chaine1[i] - chaine2[i]);
		else
			i++;
	}
	return (0);
}
