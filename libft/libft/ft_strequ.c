/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnequ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:49:22 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 19:43:47 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *str1, char const *str2)
{
	size_t i;

	if (str1 && str2)
	{
		i = 0;
		while (str1[i] || str2[i])
		{
			if (str1[i] != str2[i])
				return (0);
			else
				i++;
		}
		return (1);
	}
	else
		return (0);
}
