/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 05:26:34 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 17:12:05 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*define_modif_int(t_infos *infos, long long int integer)
{
	char	*ret;

	if (is_modif(infos->modif[0]) == 0 && (infos->conv == 'd'
				|| infos->conv == 'i'))
	{
		integer = (int)integer;
		ret = ft_itoa(integer);
	}
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h' && (infos->conv == 'd'
					|| infos->conv == 'i'))
			integer = (signed char)integer;
		else
			integer = (infos->conv == 'D')
				? (unsigned short)integer : (short)integer;
		ret = ft_itoa(integer);
	}
	if (infos->modif[0] == 'l' && infos->modif[1] != 'l')
		ret = ft_itoa_long(integer);
	if (infos->conv == 'D' || infos->modif[1] == 'l'
			|| infos->modif[0] == 'j' || infos->modif[0] == 'z')
		ret = ft_itoa_long(integer);
	return (ret);
}

int		define_prec_wchar(int prec)
{
	if (prec < 0)
		return (0);
	else if (prec == 0)
		return (1);
	else if (prec > 1 && prec <= 3)
		return (3);
	else if (prec <= 6)
		return (6);
	else if (prec <= 9)
		return (9);
	else if (prec <= 12)
		return (12);
	else if (prec <= 15)
		return (15);
	else if (prec <= 18)
		return (18);
	return (0);
}

void	init_var(t_wc *wc)
{
	wc->i = 0;
	wc->ret = 0;
	wc->tmp = 0;
	wc->tmp2 = 0;
}

char	*add_infos_octal_conv(t_infos *infos, char *ret, unsigned long int o)
{
	if (o == 0)
		ret = "0";
	if (infos->flag[0] == '#' && o != 0)
		ret = add_sharp_octal(ret);
	if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret))
		ret = add_prec(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = add_width(ret, infos->width, infos->flag);
	if (o == 0 && (infos->prec == -2 || infos->prec == -3)
			&& infos->flag[0] != '#')
		ret = "";
	return (ret);
}

char	*add_infos_hexa_conv(t_infos *infos, char *ret, unsigned long int x)
{
	if (x == 0)
		ret = "0";
	if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret)
			&& infos->flag[0] != '#')
		ret = add_prec_addr(ret, infos->prec);
	else if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret))
		ret = add_prec_hexa(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = add_width(ret, infos->width, infos->flag);
	if (x == 0 && (infos->prec == -2 || infos->prec == -3))
		ret = "";
	return (ret);
}
