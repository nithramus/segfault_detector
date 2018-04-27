/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:40:41 by bandre            #+#    #+#             */
/*   Updated: 2017/03/21 01:08:45 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specifier_c(t_param *list, va_list ap, int *value)
{
	char *s;

	s = NULL;
	if (list->longueur == 0)
	{
		if (!(s = ft_strnew(2)))
			return (NULL);
		s[0] = (char)va_arg(ap, int);
	}
	else
		s = ft_unicode(va_arg(ap, wchar_t));
	if (s)
		if (!*s)
		{
			list->width -= 1;
			list->space = 0;
			*value = 1;
		}
	return (s);
}

char	*specifier_pourcent(t_param *list)
{
	char *s;

	s = ft_strnew(2);
	if (!s)
		return (NULL);
	list->space = 0;
	s[0] = '%';
	return (s);
}

int		ft_end(t_param list, char *s, int value)
{
	if (!s)
		return (-1);
	s = ft_casp(list, s);
	if (!(s = ft_gestion_attrib_diese(list, s)))
		return (-1);
	if (!(s = ft_gestion_precision(list, s)))
		return (-1);
	if (!(s = ft_gestion_attrib_plus(list, s)))
		return (-1);
	if (!(s = ft_gestion_attrib_moins(list, s)))
		return (-1);
	value = ft_strlen(s) + value;
	ft_putstr(s);
	mem_free_ptr(s);
	return (value);
}

int		ft_affichage(t_param list, va_list ap)
{
	char	*s;
	int		value;

	value = 0;
	s = NULL;
	if (ft_strchr("DOUCS", list.specifier))
		list.longueur = 'l';
	if (ft_strchr("idD", list.specifier))
		s = specifier_i(list, ap);
	if (list.specifier == 'u' || list.specifier == 'U')
		s = specifier_uox(list, ap, 10, 0);
	else if (list.specifier == 'o' || list.specifier == 'O')
		s = specifier_uox(list, ap, 8, 0);
	else if (list.specifier == 'x' || list.specifier == 'p')
		s = specifier_uox(list, ap, 16, 0);
	else if (list.specifier == 'X')
		s = specifier_uox(list, ap, 16, 1);
	else if (list.specifier == 'c' || list.specifier == 'C')
		s = specifier_c(&list, ap, &value);
	else if (list.specifier == 'S' || list.specifier == 's')
		s = specifier_s(list, ap);
	else if (list.specifier == '%')
		s = specifier_pourcent(&list);
	return (ft_end(list, s, value));
}
