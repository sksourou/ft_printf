/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 05:34:36 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 17:19:10 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_wchar(va_list arg, t_infos *infos)
{
	wchar_t		wc;
	int			tmp;

	(void)infos;
	wc = va_arg(arg, wchar_t);
	tmp = (int)wc;
	return (print_wchar(tmp));
}

int		convert_wchar_string(va_list arg, t_infos *infos)
{
	wchar_t		*ws;
	t_wc		wc;

	init_var(&wc);
	ws = va_arg(arg, wchar_t *);
	if (ws == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (infos->prec == -2)
		ws = L"";
	if (infos->prec > 0 || infos->prec == -2)
		add_width_prec_wchar(&wc, infos);
	else
		add_width_minus_off(&wc, infos, ws);
	if (ws[wc.i + 1] == '\0' && infos->prec != -2)
		return (print_wchar(ws[wc.i]));
	else
		add_prec_wchar(&wc, infos, ws);
	if (infos->flag[0] == '-' && infos->width > (wstrlen(ws) * 3))
		add_width_minus_on(&wc, infos, ws);
	if (wc.tmp2 > 0)
		wc.ret += wc.tmp2;
	return (wc.ret);
}

int		convert_long_int(va_list arg, t_infos *infos)
{
	long int	i;
	char		*ret;

	i = va_arg(arg, long int);
	if (i == 0)
		ret = "0";
	if (infos->modif[0] == 'h')
		i = (unsigned short)i;
	ret = ft_itoa_long(i);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_octal(va_list arg, t_infos *infos)
{
	unsigned long long int	o;
	char					*ret;

	o = va_arg(arg, unsigned long long int);
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h' && infos->conv == 'o')
			o = (unsigned char)o;
		else
			o = (unsigned short)o;
	}
	if (infos->conv == 'o' && is_modif(infos->modif[0]) == 0)
		o = (unsigned int)o;
	ret = base_octal(o);
	ret = add_infos_octal_conv(infos, ret, o);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_hexa(va_list arg, t_infos *infos)
{
	unsigned long long int	x;
	char					*ret;

	x = va_arg(arg, unsigned long long int);
	ret = (char *)malloc(sizeof(char *));
	if (infos->modif[0] == 'h')
	{
		if (infos->modif[1] == 'h')
			x = (unsigned char)x;
		else
			x = (unsigned short)x;
	}
	ret = choose_hexa_conv(infos, ret, x);
	ret = add_infos_hexa_conv(infos, ret, x);
	ft_putstr(ret);
	return (ft_strlen(ret));
}
