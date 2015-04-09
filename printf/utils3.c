/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 16:49:21 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 17:19:27 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*choose_hexa_conv(t_infos *infos, char *ret, unsigned long int x)
{
	if (infos->conv == 'x')
	{
		ret = base_hexa(x, 0);
		if (infos->flag[0] == '#' && x != 0)
			ret = add_sharp_hexa(ret, 0);
	}
	else
	{
		ret = base_hexa(x, 1);
		if (infos->flag[0] == '#' && x != 0)
			ret = add_sharp_hexa(ret, 1);
	}
	return (ret);
}

void	add_infos_no_conv(t_infos *infos, t_chkStr *chk, char *s, int c)
{
	int		len;
	char	*str;

	len = 0;
	str = search_char(s, c);
	len = (str != NULL) ? (int)ft_strlen(str) : 1;
	if (infos->flag[0] != '-')
	{
		if (infos->flag[0] != '0')
			while (infos->width-- > len)
				ft_putchar(' '), chk->return_val++;
		else if (infos->flag[0] == '0')
			while (infos->width-- > len)
				ft_putchar('0'), chk->return_val++;
		if (str == NULL && check_if_another_percent(s, c, chk) == 1)
			str = NULL;
	}
	if (str != NULL)
		ft_putstr(str), chk->return_val++;
	if (infos->flag[0] == '-')
		while (infos->width - (int)ft_strlen(str) > 0)
			ft_putchar(' '), chk->return_val++, infos->width--;
	chk->tmp += ft_strlen(ft_itoa(infos->width));
}

char	*choose_unicode_mask(int lenmask, char **tab, char *bin)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = lenmask - 1;
	if (lenmask <= 7)
		tmp = ft_strrev(tab[0]);
	else if (lenmask > 7 && lenmask <= 11)
		tmp = ft_strrev(tab[1]);
	else if (lenmask > 11 && lenmask <= 16)
		tmp = ft_strrev(tab[2]);
	else
		tmp = ft_strrev(tab[3]);
	while (tmp[i] && bin[j])
	{
		if (tmp[i] == 'x')
			tmp[i] = bin[j--];
		i++;
	}
	tmp = ft_strrev(tmp);
	return (tmp);
}
