/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 06:05:45 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 17:32:39 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *rfmt, ...)
{
	va_list		arg;
	int			i;
	t_infos		*new;
	t_chkStr	*chk;

	va_start(arg, rfmt);
	i = 0;
	new = NULL;
	chk = NULL;
	new = (t_infos *)malloc(sizeof(t_infos));
	chk = (t_chkStr *)malloc(sizeof(t_chkStr));
	chk = init_chkstr(chk);
	i = check_string((char *)rfmt, arg, new, chk);
	free(chk);
	va_end(arg);
	return (i);
}

int			no_conv_spec(char *s, int c, t_chkStr *chk)
{
	int		i;

	i = 0;
	if (s[c] == '%' && s[c + 1] != '%')
		i = check_if_another_percent(s, c, chk);
	else if (s[c] == '%' && s[c + 1] == '%')
		ft_putchar('%'), i++, chk->return_val++;
	if (s[c] == '%' && s[c + 1] == ' ' && s[c + 2] == '%')
		ft_putchar('%'), i++, chk->return_val++;
	return (i);
}

int			check_if_another_percent(char *s, int c, t_chkStr *chk)
{
	int		i;

	i = 0;
	while (chk->tmp-- >= 0)
		c++, i++;
	chk->tmp += i;
	i = 0;
	if (s[c] == '%')
	{
		ft_putchar('%'), chk->return_val++, i++;
	}
	return (i);
}

void		no_conv(char *s, int c, t_infos *infos, t_chkStr *chk)
{
	if (infos->width == -1)
		chk->tmp = no_conv_spec(s, c, chk);
	if (infos->prec > 0)
		chk->tmp += ft_strlen(ft_itoa(infos->prec)) + 1;
	if (infos->width > 0)
		add_infos_no_conv(infos, chk, s, c);
	if (infos->flag[0] == ' ')
		chk->tmp = chk->tmp + 1;
}

int			check_string(char *s, va_list arg, t_infos *new, t_chkStr *chk)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			chk->tmp = detect_infos(s, i, new);
			chk->return_val += define_convert(arg, new);
			if (new->conv == 'B')
				no_conv(s, i, new, chk);
			while (chk->tmp-- > 0)
				i++;
		}
		else
			chk->return_val += write(1, &(s[i]), 1);
		i++;
	}
	free(new);
	return (chk->return_val);
}
