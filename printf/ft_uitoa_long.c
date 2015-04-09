/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 06:20:01 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 06:03:02 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_uitoa_long(unsigned long int n)
{
	char					*ret;
	unsigned long int		temp_n;
	size_t					size_ret;
	char					sign;

	sign = 1;
	size_ret = 2;
	temp_n = n;
	while ((n = n / 10))
		size_ret++;
	n = temp_n;
	if ((ret = (char *)malloc(sizeof(char) * size_ret--)) == NULL)
		return (NULL);
	ret[size_ret--] = '\0';
	ret[size_ret--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		ret[size_ret--] = sign * (n % 10) + '0';
	return (ret);
}
