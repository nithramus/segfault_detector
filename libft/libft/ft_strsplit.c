/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:15:07 by bandre            #+#    #+#             */
/*   Updated: 2016/11/11 17:16:40 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occurences(char const *str, char c)
{
	int i;
	int compteur;

	compteur = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			compteur++;
			i++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (compteur);
}

static int	len_occurence(char const *str, char c, int i)
{
	int len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static void	put_occurence(char const *str, char c, int *i, char *string)
{
	int k;

	k = 0;
	while (str[*i] != c && str[*i])
	{
		string[k] = str[*i];
		*i = *i + 1;
		k++;
	}
	string[k] = '\0';
}

static char	**fextend(char const *str, char **tab, char c, int i)
{
	int j;

	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			tab[j] = (char*)mem_stock(len_occurence(str, c, i) + 1);
			if (tab[j] == NULL)
				return (NULL);
			else
			{
				put_occurence(str, c, &i, tab[j]);
				j++;
			}
		}
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *str, char c)
{
	int		i;
	char	**tab;
	int		nbroccu;

	if (str)
	{
		i = 0;
		nbroccu = occurences(str, c);
		tab = (char**)mem_stock((nbroccu + 1) * sizeof(char**));
		if (tab == NULL)
			return (NULL);
		return (fextend(str, tab, c, i));
	}
	else
		return (NULL);
}
