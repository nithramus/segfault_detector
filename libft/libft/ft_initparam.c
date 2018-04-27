/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initparam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:49:02 by bandre            #+#    #+#             */
/*   Updated: 2016/12/04 17:52:49 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param		initparam(void)
{
	t_param param;

	param.minus = 0;
	param.plus = 0;
	param.space = 0;
	param.diese = 0;
	param.use_zero = 0;
	param.width = 0;
	param.precision = -1;
	param.specifier = 0;
	param.longueur = 0;
	return (param);
}
