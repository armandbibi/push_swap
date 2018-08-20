/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fast_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 03:16:57 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/20 15:25:10 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap_ab.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void	ft_sort_3(t_lst *alst, t_lst *blst, t_op *ops)
{
	int a;
	int b;
	int c;

	a = alst->head->n;
	b = alst->head->prev->n;
	c = alst->tail->n;
	if (a > b && a > c)
	{
		add_op(ft_ra, alst, blst, ops);
		if (b > c)
			add_op(ft_sa, alst, blst, ops);
	}
	else if (a > b && a < c)
		add_op(ft_sa, alst, blst, ops);
	else if (a < b && a > c)
		add_op(ft_rra, alst, blst, ops);
	if (a < b && a < c && b > c)
	{
		add_op(ft_sa, alst, blst, ops);
		add_op(ft_ra, alst, blst, ops);
	}
}

void		algo_fast_sort(t_lst *alst, t_lst *blst, t_op *ops)
{
	int med;

	med = ft_getmed(ft_get_nbr_element(alst),
		alst->head, ft_get_nbr_element(alst) - 4);
	if (ft_get_nbr_element(alst) < 10)
	{
		while (ft_get_nbr_element(alst) != 3)
		{
			if (alst->head->n <= med)
				add_op(ft_pb, alst, blst, ops);
			else
				add_op(ft_ra, alst, blst, ops);
		}
		ft_sort_3(alst, blst, ops);
		ft_small_sort(alst, blst, ops);
	}
	else
	{
		ft_bubble_sort(alst, blst, ops);
		ft_small_sort(alst, blst, ops);
	}
	last_optimizer(ops);
	ft_show_operation(ops);
}
