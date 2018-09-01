/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:43:17 by abietro           #+#    #+#             */
/*   Updated: 2018/09/01 17:53:50 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "checker.h"

int			ft_atoi(const char *nptr)
{
	int			sign;
	long long	digit;

	sign = (*nptr == '-') ? -1 : 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	digit = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit *= 10;
		digit += *nptr++ - '0';
	}
	if ((sign < 0 && -digit < INT_MIN) || (sign > 0 && digit > INT_MAX))
		ft_puterr();
	if (digit > INT_MAX || digit < INT_MIN)
		ft_puterr();
	return (sign * digit);
}
