/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:55:52 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 14:32:09 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*base_binary(int n)
{
	char			*ret;
	int				i;
	int				tmp;

	tmp = n;
	i = 0;
	while (tmp >= 2)
	{
		tmp = tmp / 2;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret)
	{
		ret[i + 1] = '\0';
		while (i >= 0)
		{
			tmp = n % 2;
			ret[i] = 48 + tmp;
			n = n / 2;
			i--;
		}
	}
	return (ret);
}

int		base_decimal(char *bin)
{
	int		tab[7];
	int		i;
	int		j;
	int		ret;

	i = 1;
	j = 0;
	tab[0] = 1;
	ret = 0;
	while (i < 8)
	{
		tab[i] = tab[i - 1] * 2;
		i++;
	}
	while (j < 8)
	{
		if (bin[j] == '1')
			ret += tab[i - 1];
		i--;
		j++;
	}
	return (ret);
}

char	*base_hexa(unsigned long long int n, int spec)
{
	char				*ret;
	int					i;
	unsigned long int	tmp;

	tmp = n;
	i = 0;
	while (tmp > 16)
		tmp = tmp / 16, i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret)
	{
		ret[i + 1] = '\0';
		while (i >= 0)
		{
			tmp = n % 16;
			if (spec == 0)
				ret[i] = hexa_value(tmp);
			if (spec == 1)
				ret[i] = hexa_value_maj(tmp);
			n = n / 16, i--;
		}
	}
	return (ret);
}

char	*base_octal(unsigned long long int n)
{
	char				*ret;
	int					i;
	unsigned long int	tmp;

	tmp = n;
	i = 0;
	while (tmp > 7)
	{
		tmp = tmp / 8;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret)
	{
		ret[i + 1] = '\0';
		while (i >= 0)
		{
			tmp = n % 8;
			ret[i] = 48 + tmp;
			n = n / 8;
			i--;
		}
	}
	return (ret);
}
