/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 23:07:45 by bandre            #+#    #+#             */
/*   Updated: 2016/12/05 23:09:50 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*list_minus(int len, t_param list, char *s, char *string_zero)
{
	char *tmp;

	tmp = s;
	while (len != list.width)
	{
		string_zero[list.width - len - 1] = ' ';
		list.width--;
	}
	s = ft_strjoin(tmp, string_zero);
	mem_free_ptr(tmp);
	return (s);
}

char	*list_zero(int len, t_param list, char *string_zero, char *s)
{
	char *tmp;

	tmp = s;
	while (len != list.width)
	{
		string_zero[list.width - len - 1] = '0';
		list.width--;
	}
	if (!(s = ft_strjoin(string_zero, tmp)))
		return (NULL);
	mem_free_ptr(tmp);
	tmp = NULL;
	if (list.diese && list.specifier == 'x')
	{
		tmp = ft_strchr(s, 'x');
		*tmp = '0';
		s[1] = 'x';
	}
	if ((tmp = ft_strchr(s, '-')))
		s[0] = '-';
	else if ((tmp = ft_strchr(s, '+')))
		s[0] = '+';
	if (tmp)
		*tmp = '0';
	return (s);
}

char	*ft_gestion_attrib_moins(t_param list, char *tmp)
{
	int		len;
	char	*string_zero;
	char	*s;

	s = tmp;
	len = ft_strlen(s);
	if (len < list.width)
	{
		if (!(string_zero = ft_strnew(list.width - len + 1)))
			return (NULL);
		if (list.minus)
			s = list_minus(len, list, s, string_zero);
		else if (list.use_zero && list.precision <= 0)
			s = list_zero(len, list, string_zero, s);
		else
		{
			list.width++;
			while ((list.width--) && len != list.width)
				string_zero[list.width - len - 1] = ' ';
			s = ft_strjoin(string_zero, tmp);
			mem_free_ptr(tmp);
		}
		mem_free_ptr(string_zero);
	}
	return (s);
}

char	*ft_gestion_attrib_plus(t_param list, char *s)
{
	char chain_zero[2];
	char *tmp;

	tmp = s;
	chain_zero[1] = '\0';
	if (list.plus && ft_strchr("idD", list.specifier))
	{
		if (s[0] != '-')
		{
			chain_zero[0] = '+';
			tmp = ft_strjoin(chain_zero, s);
			mem_free_ptr(s);
		}
	}
	else if (list.space && s[0] != '-' && ft_strchr("idD", list.specifier))
	{
		chain_zero[0] = ' ';
		tmp = ft_strjoin(chain_zero, s);
		mem_free_ptr(s);
	}
	return (tmp);
}

char	*ft_gestion_attrib_diese(t_param list, char *s)
{
	char chain[3];
	char *tmp;

	tmp = s;
	if (!list.diese)
		return (s);
	if (ft_strchr("xX", list.specifier) && s[0] == '0')
		return (s);
	chain[0] = '\0';
	chain[1] = '\0';
	chain[2] = '\0';
	if (list.specifier == 'p')
		chain[0] = '0';
	if ((list.specifier == 'x' || list.specifier == 'X') && s[0] != '\0')
	{
		chain[0] = '0';
		chain[1] = list.specifier;
	}
	else if ((list.specifier == 'o' || list.specifier == 'O') && s[0] != '0')
		chain[0] = '0';
	else if (list.specifier == 'p')
		chain[1] = 'x';
	tmp = ft_strjoin(chain, s);
	mem_free_ptr(s);
	return (tmp);
}
