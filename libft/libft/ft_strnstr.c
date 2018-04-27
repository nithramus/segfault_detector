/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:22:14 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 18:00:05 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substring, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (substring[0] == '\0')
		return ((char*)str);
	while (str[i] && i < len)
	{
		while (str[i + j] == substring[j] && (i + j < len))
		{
			j++;
			if (substring[j] == '\0')
				return ((char*)&str[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
