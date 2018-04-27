/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:23 by bandre            #+#    #+#             */
/*   Updated: 2016/11/09 14:16:29 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dlen;
	size_t rdlen;

	dlen = ft_strlen(dst);
	rdlen = dlen;
	if (dlen >= size)
		return (size + ft_strlen(src));
	i = 0;
	while (dlen < (size - 1) && src[i])
	{
		dst[dlen] = src[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return (rdlen + ft_strlen(src));
}
