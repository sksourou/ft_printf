/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 21:13:29 by sksourou          #+#    #+#             */
/*   Updated: 2015/03/09 00:10:37 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long int	ft_atoi_long(char *s)
{
	unsigned int				digit;
	long long int				positive;
	long long int				value;

	value = 0;
	digit = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n'
			|| *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	positive = (*s == '-' ? -1 : 1);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '0')
		s++;
	if (ft_strlen(s) > 19)
		return (positive == 1 ? -1 : 0);
	while (ft_isdigit(*s) && *s)
	{
		digit = (long long int)(*s - '0');
		value = (value * 10) + digit;
		s++;
	}
	return (value * positive);
}
