/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:41:15 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 14:26:26 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_sharp_octal(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*add_sharp_hexa(char *s, int spec)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 3);
	i = 0;
	ret[i++] = '0';
	if (spec == 1)
		ret[i++] = 'X';
	else
		ret[i++] = 'x';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*add_plus(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = '+';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*add_space(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = ' ';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}

char	*add_flag_integer(char *flag, char *s)
{
	if ((flag[0] == ' ' && flag[1] == '+')
			|| (flag[0] == '+' && flag[1] == ' '))
		s = add_plus(s);
	if (flag[0] == '+' && s[0] != '-' && flag[1] == '\0')
		s = add_plus(s);
	if (flag[0] == ' ' && flag[1] != '+' && flag[1] != '0' && s[0] != '-')
		s = add_space(s);
	if (flag[0] == ' ' && flag[1] == '0')
	{
		s = add_sharp_octal(s);
		s = add_space(s);
	}
	if (flag[0] == '+' && flag[1] == '0')
	{
		if (s[0] == '0')
			s = add_sharp_octal(s);
		s = add_plus(s);
	}
	return (s);
}
