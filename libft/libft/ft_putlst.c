/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:25:34 by bandre            #+#    #+#             */
/*   Updated: 2016/11/11 17:46:07 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *firstelem)
{
	size_t	i;
	char	*c;

	i = 0;
	while (firstelem)
	{
		i = 0;
		c = (char*)firstelem;
		while (i < firstelem->content_size)
		{
			ft_putchar(c[i]);
			i++;
		}
		firstelem = firstelem->next;
	}
}
