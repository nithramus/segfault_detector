/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:40:53 by bandre            #+#    #+#             */
/*   Updated: 2016/11/10 16:32:46 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenmem_stock(int n)
{
	int len;

	len = 1;
	if (n < 0)
		len = 2;
	while (n < -9 || n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	complete(int i, char *chainretour, int n)
{
	if (n >= -9)
		chainretour[i] = -n + '0';
	else
	{
		complete(i - 1, chainretour, n / 10);
		chainretour[i] = -(n % 10) + '0';
	}
}

char		*ft_itoa(int n)
{
	char	*chainretour;
	int		i;

	i = lenmem_stock(n);
	chainretour = (char*)mem_stock(i + 1);
	if (chainretour == NULL)
		return (NULL);
	chainretour[0] = '-';
	if (n > 0)
	{
		n = (-1) * n;
	}
	complete(i - 1, chainretour, n);
	chainretour[i] = '\0';
	return (chainretour);
}
