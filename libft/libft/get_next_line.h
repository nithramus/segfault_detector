/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:47:36 by bandre            #+#    #+#             */
/*   Updated: 2016/12/09 01:57:00 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_listchain
{
	int					fd;
	t_list				*firstelem;
	struct s_listchain	*next;
	int					n;
}						t_listchain;

int						get_next_line(const int fd, char **line);

#endif
