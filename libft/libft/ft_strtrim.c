/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:57:22 by bandre            #+#    #+#             */
/*   Updated: 2016/11/08 20:25:07 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	unsigned int	start;
	unsigned int	i;
	char			*chainretour;

	if (str)
	{
		start = 0;
		while (str[start] == ' ' || str[start] == '\n' || str[start] == '\t')
			start++;
		i = start;
		while (str[i] != '\0')
			i++;
		while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\0') && i > start)
			i--;
		chainretour = ft_strsub(str, start, (i - start + 1));
		return (chainretour);
	}
	else
		return (NULL);
}
