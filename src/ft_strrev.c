/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 06:01:41 by sksourou          #+#    #+#             */
/*   Updated: 2015/03/09 00:12:49 by sksourou         ###   ########.fr       */
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
