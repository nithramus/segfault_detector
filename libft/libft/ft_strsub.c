/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 23:03:41 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 19:45:07 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	unsigned long	end;
	char			*retour;
	int				j;

	if (str)
	{
		j = 0;
		end = start + len;
		retour = (char*)mem_stock(len + 1);
		if (retour == NULL)
			return (NULL);
		while (start < end)
		{
			retour[j] = str[start];
			j++;
			start++;
		}
		retour[j] = '\0';
		return (retour);
	}
	else
		return (NULL);
}
