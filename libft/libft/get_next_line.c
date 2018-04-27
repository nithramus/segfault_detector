/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:04:14 by bandre            #+#    #+#             */
/*   Updated: 2016/11/28 14:59:05 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*put_line(t_list **elem, int *pos, char **line)
{
	char	*n;
	t_list	*elem_avant;

	while ((*elem)->next && (elem_avant = *elem))
	{
		ft_strcat(*line, &((const char*)(*elem)->content)[*pos]);
		*elem = (*elem)->next;
		mem_free_ptr(elem_avant->content);
		mem_free_ptr(elem_avant);
		*pos = 0;
	}
	if ((n = ft_strchr(&((char*)(*elem)->content)[*pos], '\n')) && n)
	{
		ft_strncat(*line, &((const char*)(*elem)->content)[*pos],
				(n - &((char*)(*elem)->content)[*pos]));
		*pos = (n - &((char*)(*elem)->content)[0]) + 1;
	}
	else
	{
		ft_strcat(*line, &((const char*)(*elem)->content)[*pos]);
		mem_free_ptr((*elem)->content);
		mem_free_ptr(*elem);
		*elem = NULL;
	}
	return (*line);
}

static t_list	*add_read(int fd, int *ret, int cont, t_list *firstelem)
{
	char	buff[BUFF_SIZE + 1];
	t_list	*elemnext;

	*ret = read(fd, buff, BUFF_SIZE);
	while (*ret > 0 && cont == 1)
	{
		buff[*ret] = '\0';
		if (ft_strchr(buff, '\n') != NULL)
			cont = 0;
		if (!firstelem)
		{
			firstelem = ft_lstnew(buff, *ret + 1);
			elemnext = firstelem;
		}
		else
		{
			elemnext->next = ft_lstnew(buff, *ret + 1);
			elemnext = elemnext->next;
		}
		if (cont)
			*ret = read(fd, buff, BUFF_SIZE);
	}
	if (*ret < 0)
		return (NULL);
	return (firstelem);
}

static int		need_new_read(int fd, t_list **firstelem, int n)
{
	t_list	*elem;
	int		ret;
	int		cont;
	t_list	*anelem;

	anelem = NULL;
	cont = 1;
	elem = *firstelem;
	if (elem)
	{
		if (ft_strchr((char*)(&elem->content + n), '\n') != NULL)
			return (1);
	}
	if (elem == NULL)
	{
		elem = add_read(fd, &ret, cont, anelem);
		if (elem)
			*firstelem = elem;
	}
	else
		elem->next = add_read(fd, &ret, cont, anelem);
	return (ret);
}

static int		get_next(const int fd, char **line, t_list **firstelem, int *n)
{
	char			line2;
	int				len;
	t_list			*elem;

	if (need_new_read(fd, firstelem, *n) == -1)
		return (-1);
	line2 = '\0';
	*line = &line2;
	if (!*firstelem)
		return (0);
	if ((*firstelem)->next || ((char*)(*firstelem)->content)[*n] != '\0')
	{
		elem = *firstelem;
		len = elem->content_size;
		while ((elem = elem->next) && elem)
			len += elem->content_size;
		if (!(*line = ft_strnew(len + 1)))
			return (-1);
		put_line(firstelem, n, line);
	}
	else
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_listchain	*first = NULL;
	int					ret;

	if (first)
		if (first->fd != fd)
		{
			mem_free_ptr(first->firstelem);
			mem_free_ptr(first);
			first = NULL;
		}
	if (!first)
	{
		first = (t_listchain*)mem_stock(sizeof(t_listchain));
		if (!first)
			return (-1);
		first->n = 0;
		first->fd = fd;
		first->firstelem = NULL;
	}
	if ((ret = get_next(fd, line, &first->firstelem, &first->n)) && ret == 0)
	{
		mem_free_ptr(first);
		first = NULL;
	}
	return (ret);
}
