/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:27:56 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 19:35:50 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	extend(char *str, ssize_t nb)
{
	int		len;
	size_t	puissance;
	ssize_t	result;

	result = 0;
	puissance = 1;
	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		len++;
		str++;
	}
	str--;
	while (len > 0)
	{
		result += (*str - 48) * puissance;
		puissance *= 10;
		str--;
		len--;
	}
	if (nb == -1)
		return (-1 * result);
	else
		return (result);
}

ssize_t			ft_atoi(char *str)
{
	ssize_t		nb;
	int			continuer;

	continuer = 1;
	while (continuer == 1)
	{
		if ((str[0] >= 9 && str[0] <= 13) || str[0] == 32)
			str++;
		else if (str[0] == '+' && (str[1] >= '0' && str[1] <= '9'))
		{
			continuer = 0;
			str++;
		}
		else if (str[0] == '-' && (str[1] >= '0' && str[1] <= '9'))
		{
			nb = -1;
			str++;
			continuer = 0;
		}
		else if (str[0] >= '0' && str[0] <= '9')
			continuer = 0;
		else
			return (0);
	}
	return (extend(str, nb));
}
