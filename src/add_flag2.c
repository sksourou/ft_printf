/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 23:56:08 by sksourou          #+#    #+#             */
/*   Updated: 2015/03/05 20:57:08 by sksourou         ###   ########.fr       */
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

void	add_colors(int code_color)
{
	if (code_color == 1)
		ft_putstr(RED);
	if (code_color == 2)
		ft_putstr(GREEN);
	if (code_color == 3)
		ft_putstr(BLUE);
	if (code_color == 4)
		ft_putstr(MAGENTA);
	if (code_color == 5)
		ft_putstr(CYAN);
	if (code_color == 6)
		ft_putstr(END);
}
