/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:05:25 by bandre            #+#    #+#             */
/*   Updated: 2016/11/10 18:22:51 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*debut;
	char	*fin;

	if (n == 0)
		return (dest);
	else if (dest < src || dest > src + n + 1)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		debut = ((char*)src);
		fin = ((char*)dest);
		while (n > 0)
		{
			fin[n - 1] = debut[n - 1];
			n--;
		}
	}
	return (dest);
}
