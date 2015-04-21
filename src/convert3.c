/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 17:55:01 by sksourou          #+#    #+#             */
/*   Updated: 2015/03/05 21:08:54 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_binary(va_list arg, t_infos *infos)
{
	unsigned long int		bin;
	char					*ret;

	if (infos->conv == 'b' || infos->flag[0] != 'l')
		bin = va_arg(arg, int);
	else
		bin = va_arg(arg, unsigned long int);
	ret = base_binary(bin);
	ft_putstr(ret);
	return (ft_strlen(ret));
}
