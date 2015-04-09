/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:55:52 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 15:21:48 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_prec_string(char *s, int prec)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + prec) + 1);
	if (prec == -1)
		while ((size_t)i < ft_strlen(s))
			ret[i++] = ' ';
	else if (ft_strlen(s) < (size_t)prec)
		while (*s)
			ret[i++] = *s++;
	else if ((size_t)prec < ft_strlen(s))
		while (i < prec)
			ret[i++] = *s++;
	else
	{
		while ((size_t)i < (prec - ft_strlen(s)))
			ret[i++] = '0';
		while (*s)
			ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*add_prec(char *s, int prec)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * prec + 1);
	i = 0;
	if (s[0] == '-')
	{
		ret[i++] = '-';
		while ((size_t)i <= (prec - ft_strlen(s) + 1))
			ret[i++] = '0';
		while (*s++)
			ret[i++] = *s;
	}
	else
	{
		while ((size_t)i < (prec - ft_strlen(s)))
			ret[i++] = '0';
		while (*s)
			ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*add_prec_addr(char *s, int prec)
{
	char	*ret;
	int		i;
	int		len;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + prec) + 1);
	i = 0;
	len = ft_strlen(s);
	if (prec == -1)
	{
		ret[0] = '0';
		ret[1] = 'x';
		ret[2] = '\0';
		return (ret);
	}
	while (i < prec - len)
		ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*add_prec_hexa(char *s, int prec)
{
	char	*ret;
	int		i;
	int		len;
	int		j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + prec) + 1);
	i = 2;
	j = 2;
	if (prec == -1)
	{
		ret[0] = '0';
		ret[1] = 'x';
		ret[2] = '\0';
		return (ret);
	}
	len = ft_strlen(s);
	ret[0] = '0';
	ret[1] = 'x';
	while (i < (prec - len) + 4)
		ret[i++] = '0';
	while (s[j])
		ret[i++] = s[j++];
	ret[i] = '\0';
	return (ret);
}

void	add_prec_wchar(t_wc *wc, t_infos *infos, wchar_t *ws)
{
	if (infos->prec > 0)
	{
		if (infos->prec > 1)
			while (wc->ret < infos->prec - 1)
				wc->ret += print_wchar(ws[wc->i++]);
		else if (infos->prec == 1)
		{
			while (wc->ret < infos->prec)
				wc->ret += print_wchar(ws[wc->i++]);
		}
	}
	else
		while (ws[wc->i])
			wc->ret += print_wchar(ws[wc->i++]);
}
