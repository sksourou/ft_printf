/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 06:10:16 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 14:36:13 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_chkStr	*init_chkstr(t_chkStr *chk)
{
	t_chkStr *tmp;

	tmp = chk;
	tmp->return_val = 0;
	tmp->tmp = 0;
	return (tmp);
}

int			detect_infos(char *s, int c, t_infos *new)
{
	int		i;

	i = 0;
	new->flag = search_flag(s, c);
	if (new->flag[0] != '\0')
		i += ft_strlen(new->flag);
	new->width = search_width(s, c);
	if (new->width > 0)
		i += ft_strlen(ft_itoa(new->width));
	new->prec = search_prec(s, c);
	if (new->prec > 0)
		i += ft_strlen(ft_itoa(new->prec)) + 1;
	if (new->prec == -2)
		i += 1;
	if (new->prec == -3)
		i += 2;
	new->conv = search_conv(s, c);
	if (new->conv != 'B')
		i += 1;
	new->modif = search_modif(s, c, new->conv);
	if (new->modif[0] != '\0')
		i += ft_strlen(new->modif);
	return (i);
}

int			define_convert(va_list arg, t_infos *infos)
{
	int		val;

	val = 0;
	if (infos->conv == 'd' || infos->conv == 'i')
		val = convert_int(arg, infos);
	if (infos->conv == 'D')
		val = convert_long_int(arg, infos);
	if (infos->conv == 's' && infos->modif[0] != 'l')
		val = convert_string(arg, infos);
	if (infos->conv == 'c' && infos->modif[0] != 'l')
		val = convert_char(arg, infos);
	if (infos->conv == 'C' || (infos->conv == 'c' && infos->modif[0] == 'l'))
		val = convert_wchar(arg, infos);
	if (infos->conv == 'p')
		val = convert_pointer(arg, infos);
	if (infos->conv == 'S' || (infos->conv == 's' && infos->modif[0] == 'l'))
		val = convert_wchar_string(arg, infos);
	if (infos->conv == 'u' || infos->conv == 'U')
		val = convert_unsigned(arg, infos);
	if (infos->conv == 'o' || infos->conv == 'O')
		val = convert_octal(arg, infos);
	if (infos->conv == 'x' || infos->conv == 'X')
		val = convert_hexa(arg, infos);
	return (val);
}
