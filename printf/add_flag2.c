/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:56:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 06:15:52 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_flag_minus(char *s, int width)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * width + 1);
	i = 0;
	while (*s)
		ret[i++] = *s++;
	while (i < width)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

char	*add_flag_zero(char *s, int width)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * width + 1);
	i = 0;
	j = 0;
	if (s[j] == '-')
	{
		j = j + 1;
		ret[i++] = '-';
		while ((size_t)i <= width - ft_strlen(s))
			ret[i++] = '0';
	}
	else
	{
		while ((size_t)i < width - ft_strlen(s))
			ret[i++] = '0';
	}
	while (s[j])
		ret[i++] = s[j++];
	ret[i] = '\0';
	return (ret);
}
