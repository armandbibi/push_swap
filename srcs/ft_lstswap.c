/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:55:27 by triou             #+#    #+#             */
/*   Updated: 2018/06/26 18:36:06 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstswap(t_stack *alst)
{
	t_stack *prev;
	int		tmp;

	if (alst && alst->prev)
	{
		prev = alst->prev;
		tmp = prev->n;
		prev->n = alst->n;
		alst->n = tmp;
	}
}
