/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:00:33 by triou             #+#    #+#             */
/*   Updated: 2018/06/25 16:21:57 by triou            ###   ########.fr       */
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
