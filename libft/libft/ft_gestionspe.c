/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:14:32 by bandre            #+#    #+#             */
/*   Updated: 2017/03/21 01:08:22 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			recup_flag(char *line, t_param *param, int *i)
{
	if (line[*i] == '#')
		param->diese = 1;
	else if (line[*i] == '-')
		param->minus = 1;
	else if (line[*i] == '+')
		param->plus = 1;
	else if (line[*i] == '0')
		param->use_zero = 1;
	else if (line[*i] == ' ')
		param->space += 1;
	else
		return (0);
	return (1);
}

int			recup_width(char *line, t_param *param, int *i)
{
	int width;
	int precision;

	width = ft_atoi(&line[*i]);
	if (width != 0)
	{
		while (line[*i] >= '0' && line[*i] <= '9')
			(*i)++;
	}
	param->width = width;
	if (line[*i] == '.')
	{
		(*i)++;
		precision = ft_atoi(&line[*i]);
		param->precision = precision;
		while (line[*i] >= '0' && line[*i] <= '9')
			(*i)++;
	}
	return (1);
}

int			recup_long(char *line, t_param *param, int *i)
{
	if (ft_strchr("jzlh", line[*i]))
	{
		if (line[*i + 1] == 'l')
		{
			param->longueur = 't';
			(*i)++;
		}
		else if (line[*i + 1] == 'h')
		{
			param->longueur = 'w';
			(*i)++;
		}
		else
			param->longueur = line[*i];
		(*i)++;
	}
	return (1);
}

int			recup_spe(char *line, t_param *param, int *i)
{
	if (ft_strchr("sSidDoOuUxXcC%", line[*i]))
	{
		param->specifier = line[*i];
		(*i)++;
	}
	else if (line[*i] == 'p')
	{
		param->specifier = 'p';
		param->longueur = 'z';
		param->diese = 1;
		(*i)++;
	}
	else
	{
		ft_putchar('%');
		return (0);
	}
	return (1);
}

int			ft_gestionspe(char *line, int *i, va_list ap)
{
	t_param		list;
	int			retour;

	list = initparam();
	(*i)++;
	while (recup_flag(line, &list, i))
		(*i)++;
	recup_width(line, &list, i);
	recup_long(line, &list, i);
	retour = recup_spe(line, &list, i);
	if (retour == 0)
		return (0);
	retour = ft_affichage(list, ap);
	return (retour);
}
