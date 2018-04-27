/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:45:17 by bandre            #+#    #+#             */
/*   Updated: 2016/12/05 20:25:30 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*gestion_ioux(int len, char *string_zero, t_param list, char *s)
{
	char *tmp;

	tmp = ft_strchr(s, '-');
	list.precision = (tmp) ? list.precision + 1 : list.precision;
	if (len < list.precision)
	{
		if (!(string_zero = ft_strnew(list.precision - len + 1)))
			return (NULL);
		while (len != list.precision)
		{
			string_zero[list.precision - len - 1] = '0';
			list.precision--;
		}
		tmp = s;
		s = ft_strjoin(string_zero, tmp);
		mem_free_ptr(tmp);
		if (ft_strchr(s, '-') && s)
		{
			tmp = ft_strchr(s, '-');
			s[0] = '-';
			*tmp = '0';
		}
		mem_free_ptr(string_zero);
	}
	return (s);
}

char		*ft_gestion_precision(t_param list, char *tmp)
{
	int		len;
	char	*string_zero;
	char	*s;

	s = tmp;
	string_zero = NULL;
	len = ft_strlen(s);
	if (ft_strchr("idDoOuUxX", list.specifier))
		return (gestion_ioux(len, string_zero, list, s));
	if (list.specifier == 's' || list.specifier == 'S')
	{
		len = ft_strlen(s);
		if (len > list.precision && list.precision != -1)
			s[list.precision] = '\0';
		return (s);
	}
	return (s);
}
