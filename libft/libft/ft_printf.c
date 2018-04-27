/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:14:32 by bandre            #+#    #+#             */
/*   Updated: 2016/12/06 01:33:51 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *line, ...)
{
	va_list		ap;
	int			i;
	int			len;
	int			ret;

	i = 0;
	len = 0;
	va_start(ap, line);
	while (line[i])
	{
		ret = 0;
		if (line[i] != '%')
		{
			ft_putchar(line[i]);
			i++;
			len++;
		}
		else
			ret = ft_gestionspe(line, &i, ap);
		if (ret < 0)
			return (-1);
		len += ret;
	}
	va_end(ap);
	return (len);
}
