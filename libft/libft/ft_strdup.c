/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:16:18 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 18:04:41 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*chaineretour;

	chaineretour = (char*)mem_stock(sizeof(char) * (ft_strlen(str) + 1));
	if (!chaineretour)
		return (NULL);
	i = 0;
	while (str[i])
	{
		chaineretour[i] = str[i];
		i++;
	}
	chaineretour[i] = '\0';
	return (chaineretour);
}
