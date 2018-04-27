/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cassupp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:25:52 by bandre            #+#    #+#             */
/*   Updated: 2016/12/13 20:25:54 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_casp(t_param list, char *s)
{
	if (list.specifier == 'i' || list.specifier == 'd' || list.specifier == 'o'
			|| list.specifier == 'O' || list.specifier == 'x' ||
			list.specifier == 'X' || list.specifier == 'u' ||
			list.specifier == 'U' || list.specifier == 'D')
		if (list.precision == 0 && ft_strlen(s) == 1 && s[0] == '0')
			s[0] = '\0';
	return (s);
}
