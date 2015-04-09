/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 06:01:41 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 06:02:04 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strrev(char const *s)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = ft_strlen(s) - 1;
	j = 0;
	while (i >= 0)
		ret[j++] = s[i--];
	ret[j] = '\0';
	return (ret);
}
