/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 05:18:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 14:21:24 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_int(va_list arg, t_infos *infos)
{
	long long int	integer;
	char			*ret;

	integer = va_arg(arg, long long int);
	if (integer == 0)
		ret = "0";
	ret = define_modif_int(infos, integer);
	ret = add_flag_integer(infos->flag, ret);
	if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret))
		ret = add_prec(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = add_width(ret, infos->width, infos->flag);
	if (integer == 0 && (infos->prec == -2 || infos->prec == -3))
		ret = "";
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_unsigned(va_list arg, t_infos *infos)
{
	unsigned long int	u;
	char				*ret;

	u = va_arg(arg, unsigned long int);
	if (infos->modif[0] == 'h' && infos->conv == 'u')
	{
		if (infos->modif[1] == 'h' && infos->conv == 'u')
			u = (unsigned char)u;
		else
			u = (unsigned short)u;
	}
	if (infos->conv == 'u' && is_modif(infos->modif[0]) == 0)
		ret = ft_uitoa((unsigned int)u);
	else
		ret = ft_uitoa_long((unsigned long int)u);
	if (u == 0)
		ret = "0";
	if (infos->prec > 0 && (size_t)infos->prec > ft_strlen(ret))
		ret = add_prec(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = add_width(ret, infos->width, infos->flag);
	if (u == 0 && (infos->prec == -2 || infos->prec == -3))
		ret = "";
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_string(va_list arg, t_infos *infos)
{
	char	*string;
	int		i;

	i = 0;
	string = va_arg(arg, char *);
	if (string == 0)
		string = "(null)";
	else if (string == '\0' && infos->width != 0)
	{
		while (i++ < infos->width)
			ft_putchar('0');
		return (i - 1);
	}
	if (infos->prec == -2 || infos->prec == -3)
		string = "";
	if (infos->prec > 0)
		string = add_prec_string(string, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(string))
		string = add_width(string, infos->width, infos->flag);
	ft_putstr(string);
	return (ft_strlen(string));
}

int		convert_pointer(va_list arg, t_infos *infos)
{
	unsigned long int	addr;
	char				*ret;

	addr = va_arg(arg, unsigned long int);
	ret = base_hexa(addr, 0);
	if (addr == 0 && (infos->prec == -2 || infos->prec == -3))
		ret = "";
	ret = add_0x_addr(ret);
	if (infos->prec > 0)
		ret = add_prec_hexa(ret, infos->prec);
	if (infos->width > 0 && (size_t)infos->width > ft_strlen(ret))
		ret = add_width_0x(ret, infos->width, infos->flag);
	ft_putstr(ret);
	return (ft_strlen(ret));
}

int		convert_char(va_list arg, t_infos *infos)
{
	unsigned int	c;
	int				i;
	char			*ret;

	c = va_arg(arg, unsigned int);
	c = (char)c;
	i = 0;
	if (c <= 126)
	{
		if (infos->width > 0)
		{
			ret = (char *)malloc(sizeof(char) * infos->width);
			while (i++ < infos->width - 1)
				if (infos->flag[0] == '0')
					ret[i] = '0';
				else
					ret[i] = ' ';
			ret[i++] = c;
			ret[i] = '\0', ft_putstr(ret);
			return (i);
		}
		ft_putchar(c);
		return (1);
	}
	return (0);
}
