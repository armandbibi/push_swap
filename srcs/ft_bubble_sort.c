/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:26:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/07/30 06:16:27 by abiestro         ###   ########.fr       */
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
	high_limit = ft_getmed(size, alst->head, sizlst);
	i = 0;
	j = 0;
	tmp = alst->head;
	while (i <= sizlst)
	{
		if (tmp->n <= high_limit)
			i++;
		tmp = tmp->prev;
		ra++;
	}
	tmp = alst->tail;
	while (j <= sizlst)
	{
		if (tmp->n <= high_limit)
			j++;
		tmp = tmp->next;
		rra++;
	}
	if (ra <= rra)
		return (ft_ra);
	else
		return (ft_rra);
}

static int		get_small_elements(t_lst *alst,
		t_lst *blst, int sizepack, t_op *ops)
{
	int		high_limit;
	void	(*rotate)(t_lst*, t_lst*);
	int		med_expected;

	rotate = get_rotation(alst, sizepack);
	high_limit = ft_getmed(ft_get_nbr_element(alst), alst->head, sizepack);
	med_expected = ft_getmed(ft_get_nbr_element(alst),
			alst->head, sizepack / 2);
	while (sizepack)
	{
		if (alst->head->n <= high_limit)
		{
			add_op(ft_pb, alst, blst, ops);
			sizepack--;
			int bsize = ft_get_nbr_element(blst);
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
	int i;

	i = 0;
	sizepack = ft_get_nbr_element(alst) / 4 + 2;
	if (ft_get_nbr_element(alst) < 20)
		sizepack = 3;
	while (ft_get_nbr_element(alst) > sizepack)
	{
		i += get_small_elements(alst, blst, sizepack, ops);
		if (sizepack > 5)
			sizepack -= sizepack / 4;
		if (sizepack < 3)
			sizepack = 3;
	}
	while (alst->tail)
	{
		add_op(ft_pb, alst, blst, ops);
		i++;
	}
	return (i);
}
