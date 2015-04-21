/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@studentfr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 21:10:06 by sksourou          #+#    #+#             */
/*   Updated: 2015/03/05 21:13:27 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_colors(char *s, int c, t_infos *infos)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * 4 + 1);
	infos->color = 0;
	while (s[c] != '[')
		c++;
	while (s[c + 1] != ']')
		tmp[i++] = s[++c];
	define_colors(tmp, infos);
	return (3 + ft_strlen(tmp));
}

void	define_colors(char *s, t_infos *infos)
{
	if (ft_strcmp(s, "E_RED") == 0)
		infos->color = E_RED;
	if (ft_strcmp(s, "E_BLUE") == 0)
		infos->color = E_BLUE;
	if (ft_strcmp(s, "E_GREEN") == 0)
		infos->color = E_GREEN;
	if (ft_strcmp(s, "E_MAGENTA") == 0)
		infos->color = E_MAGENTA;
	if (ft_strcmp(s, "E_CYAN") == 0)
		infos->color = E_CYAN;
	if (ft_strcmp(s, "E_END") == 0)
		infos->color = E_END;
}
