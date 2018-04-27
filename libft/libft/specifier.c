/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:09:08 by bandre            #+#    #+#             */
/*   Updated: 2016/12/05 19:57:41 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*specifier_i(t_param list, va_list ap)
{
	char *s;

	s = NULL;
	if (list.longueur == 0)
		s = ft_itoa_base_signed((long long int)(va_arg(ap, int)), 10, 0);
	else if (list.longueur == 'w')
		s = ft_itoa_base_signed((char)(va_arg(ap, int)), 10, 0);
	else if (list.longueur == 'h')
		s = ft_itoa_base_signed((short int)va_arg(ap, int), 10, 0);
	else if (list.longueur == 'l')
		s = ft_itoa_base_signed((ssize_t)va_arg(ap, long int), 10, 0);
	else if (list.longueur == 't')
		s = ft_itoa_base_signed((ssize_t)va_arg(ap, long long int), 10, 0);
	else if (list.longueur == 'z')
		s = ft_itoa_base_signed(va_arg(ap, ssize_t), 10, 0);
	else if (list.longueur == 'j')
		s = ft_itoa_base_signed((ssize_t)va_arg(ap, intmax_t), 10, 0);
	return (s);
}

char		*specifier_uox(t_param list, va_list ap, int base, int m)
{
	char *s;

	s = NULL;
	if (list.longueur == 0)
		s = ft_itoa_base((size_t)va_arg(ap, unsigned int), base, m);
	else if (list.longueur == 'w')
		s = ft_itoa_base((unsigned char)va_arg(ap, unsigned int), base, m);
	else if (list.longueur == 'h')
		s = ft_itoa_base((unsigned short int)va_arg(ap, unsigned int), base, m);
	else if (list.longueur == 'l')
		s = ft_itoa_base((size_t)va_arg(ap, unsigned long int), base, m);
	else if (list.longueur == 't')
		s = ft_itoa_base((size_t)va_arg(ap, unsigned long long int), base, m);
	else if (list.longueur == 'z')
		s = ft_itoa_base((size_t)va_arg(ap, size_t), base, m);
	else if (list.longueur == 'j')
		s = ft_itoa_base((size_t)va_arg(ap, uintmax_t), base, m);
	return (s);
}

static char	*cas_s(va_list ap)
{
	char *s;
	char *new;

	s = va_arg(ap, char*);
	if (!s)
	{
		s = ft_strnew(sizeof(char) * 7);
		if (!s)
			return (NULL);
		ft_strcpy(s, "(null)");
		return (s);
	}
	new = ft_strnew(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, s);
	return (new);
}

static char	*cas_ls(wchar_t *wchar)
{
	char	*new;
	char	*s;
	char	*uni;
	int		i;

	i = 0;
	if (!(s = ft_strnew(1)))
		return (NULL);
	while (wchar[i] != L'\0')
	{
		uni = ft_unicode(wchar[i]);
		new = ft_strjoin(s, uni);
		mem_free_ptr(s);
		mem_free_ptr(uni);
		if (new)
			s = new;
		else
			return (NULL);
		i++;
	}
	return (s);
}

char		*specifier_s(t_param list, va_list ap)
{
	char	*s;
	wchar_t	*wchar;

	if (list.longueur == 0 && list.specifier == 's')
		return (cas_s(ap));
	wchar = va_arg(ap, wchar_t*);
	if (!wchar)
	{
		s = ft_strnew(sizeof(char) * 7);
		if (!s)
			return (NULL);
		ft_strcpy(s, "(null)");
		return (s);
	}
	return (cas_ls(wchar));
}
