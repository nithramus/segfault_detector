/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:24:22 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 20:24:25 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*chainretour;
	unsigned int	len;

	if (str && f)
	{
		len = 0;
		while (str[len])
			len++;
		chainretour = (char*)mem_stock(sizeof(char) * len + 1);
		if (chainretour == NULL)
			return (NULL);
		len = 0;
		while (str[len])
		{
			chainretour[len] = (*f)(len, str[len]);
			len++;
		}
		chainretour[len] = '\0';
		return (chainretour);
	}
	else
		return (NULL);
}
