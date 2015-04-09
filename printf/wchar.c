/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:32:26 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 17:18:08 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_wchar(int value)
{
	char	*bin;
	int		ret;

	ret = 0;
	bin = base_binary(value);
	if ((int)ft_strlen(bin) <= 7)
	{
		write(1, &value, 1);
		ret++;
	}
	else
		ret = mask_unicode(bin, ft_strlen(bin));
	return (ret);
}

int		mask_unicode(char *bin, int lenmask)
{
	char	*tab[4];
	char	*tmp;
	int		ret;
	int		i;

	tab[0] = "0xxxxxxx";
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	tmp = (char *)malloc(sizeof(char *));
	i = 0;
	tmp = choose_unicode_mask(lenmask, tab, bin);
	while (tmp[i++])
		if (tmp[i] == 'x')
			tmp[i] = '0';
	ret = split_binary(tmp, (ft_strlen(tmp) / 8));
	return (ret);
}

int		split_binary(char *bin, int nbdiv)
{
	int		i;
	int		j;
	int		ct;
	int		div;
	char	*ret[8];

	i = 0;
	ct = 0;
	div = 8;
	while (ct < nbdiv)
	{
		j = 0;
		ret[ct] = (char *)malloc(sizeof(char) * 8 + 1);
		while (i < div)
			ret[ct][j++] = bin[i++];
		ret[ct][j] = '\0';
		ct++;
		div = div + 8;
	}
	return (display_wchar(ret, (ct - 1)));
}

int		display_wchar(char **tab, int nb)
{
	int		tmp[nb];
	int		i;

	i = -1;
	while (++i <= nb)
		tmp[i] = base_decimal(tab[i]);
	i = 0;
	while (i <= nb)
	{
		write(1, &(tmp[i]), 1);
		i++;
	}
	return (i);
}
