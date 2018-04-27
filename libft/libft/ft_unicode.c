/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:33 by bandre            #+#    #+#             */
/*   Updated: 2016/12/04 23:08:37 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_add(int len, char *s)
{
	int retour;
	int i;

	i = 1;
	retour = 0;
	while (len > 0)
	{
		if (s[len - 1] == '1')
			retour += i;
		i *= 2;
		len--;
	}
	return (retour);
}

static void		ft_extend(char *chain, char *s, int len, wchar_t carac)
{
	if (carac < 65536)
	{
		chain[0] = ft_add(len - 12, s) + 224;
		chain[1] = ft_add(6, &s[len - 12]) + 128;
		chain[2] = ft_add(6, &s[len - 6]) + 128;
	}
	else if (carac < 2097152)
	{
		chain[0] = ft_add(len - 18, s) + 240;
		chain[1] = ft_add(6, &s[len - 18]) + 128;
		chain[2] = ft_add(6, &s[len - 12]) + 128;
		chain[3] = ft_add(6, &s[len - 6]) + 128;
	}
}

char			*ft_unicode(wchar_t carac)
{
	char	*s;
	int		len;
	char	*chain;

	if (!(chain = ft_strnew(5)))
		return (NULL);
	s = ft_itoa_base_signed((size_t)carac, 2, 0);
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (carac < 128)
		chain[0] = ft_add(len, s);
	else if (carac < 2048)
	{
		chain[0] = ft_add(len - 6, s) + 192;
		chain[1] = ft_add(6, &s[len - 6]) + 128;
	}
	else
		ft_extend(chain, s, len, carac);
	mem_free_ptr(s);
	return (chain);
}
