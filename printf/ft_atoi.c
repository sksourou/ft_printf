/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 08:42:02 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/19 23:09:54 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_atoi(char const *s)
{
	unsigned int	digit;
	int				positive;
	int				value;

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
		digit = (int)(*s - '0');
		value = (value * 10) + digit;
		s++;
	}
	return (value * positive);
}
