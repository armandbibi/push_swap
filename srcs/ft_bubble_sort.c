/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:26:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/20 15:50:30 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap_ab.h"
#include <stdio.h>

static void		*get_rotation(t_lst *alst, int sizlst)
{
	int		high_limit;
	t_stack	*tmp;
	int		i;
	int		j;
	int		ra;
	int		rra;
	int		size;

	ra = 0;
	rra = 0;
	size = ft_get_nbr_element(alst);
	high_limit = ft_getmed(size, alst->head, 10);
	i = 0;
	j = 0;
	tmp = alst->head;
	while (tmp && i <= sizlst && ++ra)
	{
		if (tmp->n <= high_limit)
			i++;
		tmp = tmp->prev;
	}
	tmp = alst->tail;
	while (tmp && i <= sizlst && ++rra)
	{
		if (tmp->n <= high_limit)
			i++;
		tmp = tmp->next;
	}
//	if (ra <= rra)
		return (ft_ra);
//	else
		return (ft_ra);
}

static int		get_small_elements(t_lst *alst,
		t_lst *blst, int sizepack, t_op *ops)
{
	int		high_limit;
	void	(*rotate)(t_lst*, t_lst*);
	int		med_expected;
	int		bsize;

	rotate = get_rotation(alst, sizepack);
	high_limit = ft_getmed(ft_get_nbr_element(alst), alst->head, sizepack);
	med_expected = ft_getmed(ft_get_nbr_element(alst),
			alst->head, sizepack / 2);
	while (sizepack > 4)
	{
		if (alst->head->n <= high_limit)
		{
			add_op(ft_pb, alst, blst, ops);
			sizepack--;
			bsize = ft_get_nbr_element(blst);
			if (bsize > 3 && blst->head->n > med_expected)
				add_op(ft_rb, alst, blst, ops);
			rotate = get_rotation(alst, sizepack - 1);
		}
		else
			add_op(rotate, alst, blst, ops);
	}
	return (0);
}

int				ft_bubble_sort(t_lst *alst, t_lst *blst, t_op *ops)
{
	int sizepack;
	int f_divizer;
	int s_divizer;

	f_divizer = 4;
	s_divizer = 4;
	if (ft_get_nbr_element(alst) > 300)
	{
		f_divizer = 10;
		s_divizer = 30;
	}
	sizepack = ft_get_nbr_element(alst) / f_divizer;
	if (ft_get_nbr_element(alst) < 20)
		sizepack = 3;
	while (ft_get_nbr_element(alst) > sizepack)
	{
		get_small_elements(alst, blst, sizepack, ops);
		if (sizepack > 5)
			sizepack -= sizepack / s_divizer;
		if (sizepack < 3)
			sizepack = 3;
	}
	while (alst->tail)
		add_op(ft_pb, alst, blst, ops);
	return (0);
}
