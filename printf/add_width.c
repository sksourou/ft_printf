/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:55:52 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 15:27:56 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_width(char *s, int width, char *flag)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * width + 1);
	if (flag[0] == '-' || flag[1] == '-')
		ret = add_flag_minus(s, width);
	else
	{
		if (flag[0] == '0' && s[0] != '0')
			ret = add_flag_zero(s, width);
		else
		{
			while ((size_t)i < width - ft_strlen(s))
				ret[i++] = ' ';
			while (s[j])
				ret[i++] = s[j++];
		}
	}
	return (ret);
}

char	*add_width_0x(char *s, int width, char *flag)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * width + 1);
	i = 0;
	if (flag[0] == '0' || flag[0] == '-')
	{
		while (*s)
			ret[i++] = *s++;
		while (i < width)
			if (flag[0] == '-')
				ret[i++] = ' ';
			else
				ret[i++] = '0';
	}
	else
	{
		while ((size_t)i < width - ft_strlen(s))
			ret[i++] = ' ';
		while (*s)
			ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

void	add_width_prec_wchar(t_wc *wc, t_infos *infos)
{
	wc->tmp = define_prec_wchar(infos->prec - 1);
	if (infos->width >= 0 && wc->tmp >= 0)
	{
		while (infos->width > wc->tmp++)
		{
			if (infos->flag[0] == '0')
				ft_putchar('0'), wc->tmp2++;
			else
				ft_putchar(' '), wc->tmp2++;
		}
	}
}

void	add_width_minus_off(t_wc *wc, t_infos *infos, wchar_t *ws)
{
	if (infos->width > 0 && infos->flag[0] != '-')
	{
		while (infos->width-- > (wstrlen(ws) * 3))
		{
			if (infos->flag[0] == '0')
				ft_putchar('0'), wc->tmp2++;
			else
				ft_putchar(' '), wc->tmp2++;
		}
	}
}

void	add_width_minus_on(t_wc *wc, t_infos *infos, wchar_t *ws)
{
	if (infos->flag[0] == '-' && infos->width > (wstrlen(ws) * 3))
	{
		while (infos->width - (wstrlen(ws) * 3) > 0)
		{
			if (infos->flag[1] == '0')
				ft_putchar('0'), wc->tmp2++;
			else
				ft_putchar(' '), wc->tmp2++;
			infos->width--;
		}
	}
}
