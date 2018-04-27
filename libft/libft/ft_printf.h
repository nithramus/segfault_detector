/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:04:15 by bandre            #+#    #+#             */
/*   Updated: 2016/12/06 00:10:18 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <wchar.h>
# include <limits.h>
# include <string.h>
# include <inttypes.h>

typedef struct	s_listparam
{
	int			minus;
	int			plus;
	int			space;
	int			diese;
	int			use_zero;
	int			width;
	int			precision;
	char		specifier;
	char		longueur;
}				t_param;

int				ft_printf(char *line, ...);
int				ft_gestionspe(char *line, int *i, va_list ap);
int				ft_affichage(t_param list, va_list ap);
char			*ft_unicode(wchar_t carac);
char			*ft_gestion_attrib_diese(t_param list, char *s);
char			*ft_gestion_precision(t_param list, char *s);
char			*ft_gestion_attrib_plus(t_param list, char *s);
char			*ft_gestion_attrib_moins(t_param list, char *s);
char			*ft_casp(t_param list, char *s);
t_param			initparam(void);
char			*specifier_s(t_param list, va_list ap);
char			*specifier_uox(t_param list, va_list ap, int base, int m);
char			*specifier_c(t_param *list, va_list ap, int *value);
char			*specifier_s(t_param list, va_list ap);
char			*specifier_i(t_param list, va_list ap);
#endif
