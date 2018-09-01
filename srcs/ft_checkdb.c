/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:00:33 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/01 17:54:21 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checkdb(t_stack *alst)
{
	t_stack *cpy;

	while (alst->prev)
	{
		cpy = alst->prev;
		while (cpy)
		{
			if (cpy->n == alst->n)
				ft_puterr();
			cpy = cpy->prev;
		}
		alst = alst->prev;
	}
}
