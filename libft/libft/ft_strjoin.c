/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:24:49 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 22:50:33 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*chainretour;
	unsigned int	i;

	if (str1 && str2)
	{
		i = -1;
		len1 = ft_strlen(str1);
		len2 = ft_strlen(str2);
		chainretour = (char*)mem_stock((len1 + len2 + 1) * sizeof(char));
		if (chainretour == NULL)
			return (NULL);
		while (++i < len1 || i < len2)
		{
			if (i < len1)
				chainretour[i] = str1[i];
			if (i < len2)
				chainretour[i + len1] = str2[i];
		}
		chainretour[len1 + len2] = '\0';
		return (chainretour);
	}
	else
		return (NULL);
}
