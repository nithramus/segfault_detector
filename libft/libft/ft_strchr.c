/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:31:03 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 18:26:38 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	carac;

	carac = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == carac)
			return ((char*)&str[i]);
		i++;
	}
	if (str[i] == carac)
		return ((char*)&str[i]);
	return (NULL);
}
