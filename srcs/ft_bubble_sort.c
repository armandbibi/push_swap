/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:26:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/20 20:39:57 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap_ab.h"
#include <stdio.h>

static int		get_small_elements(t_lst *alst,
		t_lst *blst, int sizepack, t_op *ops)
{
	int		high_limit;
	void	(*rotate)(t_lst*, t_lst*);
	int		med_expected;
	int		bsize;

	rotate = ft_ra;
	high_limit = ft_getmed(ft_get_nbr_element(alst), alst->head, sizepack);
	med_expected = ft_getmed(ft_get_nbr_element(alst),
			alst->head, sizepack / 2);
	while (sizepack > 3)
	{
		if (alst->head->n < high_limit)
		{
			add_op(ft_pb, alst, blst, ops);
			sizepack--;
			bsize = ft_get_nbr_element(blst);
			if (bsize > 3 && blst->head->n > med_expected)
				add_op(ft_rb, alst, blst, ops);
		}
		else
			add_op(rotate, alst, blst, ops);
	}
	return (0);
}

int				ft_bubble_sort(t_lst *alst, t_lst *blst, t_op *ops)
{
	int sizepack;
	int s_divizer;
	int count;

	sizepack = ft_get_nbr_element(alst) / 4;
	s_divizer = 3;
	if (ft_get_nbr_element(alst) > 300)
	{
		sizepack = ft_get_nbr_element(alst) / 8;
		s_divizer = 3;
	}
	if (ft_get_nbr_element(alst) < 20)
		sizepack = 3;
	while ((count = ft_get_nbr_element(alst)) > sizepack)
	{
		get_small_elements(alst, blst, sizepack, ops);
		if (sizepack > 5)
			sizepack -= s_divizer;
		if (sizepack < 4)
			sizepack = 4;
	}
	while (alst->tail)
		add_op(ft_pb, alst, blst, ops);
	return (0);
}
