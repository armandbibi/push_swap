/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brut_force.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:51:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/20 20:42:06 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap_ab.h"
#include <limits.h>
#include <unistd.h>

static void		*get_next_one(t_lst *blst, int *big)
{
	int			i;
	int			rank;
	int			max;
	t_stack		*tmp;

	i = 0;
	rank = 0;
	tmp = blst->head;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->n > max)
		{
			rank = i;
			max = tmp->n;
		}
		i++;
		tmp = tmp->prev;
	}
	*big = max;
	if (rank < ft_getmed(ft_get_nbr_element(blst),
				blst->head, ft_get_nbr_element(blst) / 2))
		return (ft_rb);
	else
		return (ft_rrb);
}

static int		get_an_other(t_lst *blst, int *i, int rank, int bigger)
{
	t_stack *tmp;

	(void)rank;
	*i = INT_MIN;
	tmp = blst->head;
	while (tmp)
	{
		if (tmp->n < bigger && tmp->n > *i)
		{
			*i = tmp->n;
		}
		tmp = tmp->prev;
	}
	return (1);
}

int				ft_opti_second_value(t_lst *alst, t_lst *blst,
		t_op *ops, int *flag)
{
	void	(*rotation)(t_lst*, t_lst*);
	int		bigest_one;
	int		second_one;
	int		third_one;

	rotation = get_next_one(blst, &bigest_one);
	get_an_other(blst, &second_one, 2, bigest_one);
	get_an_other(blst, &third_one, 2, bigest_one);
	if (ft_get_nbr_element(blst) > 3 && *flag == 10)
	{
		*flag = 0;
		return (1);
	}
	else if (blst->head->n == second_one && *flag == 0)
	{
		*flag = 5;
		add_op(ft_pa, alst, blst, ops);
		add_op(ft_ra, alst, blst, ops);
		return (1);
	}
	return (0);
}

int				ft_small_sort(t_lst *alst, t_lst *blst, t_op *ops)
{
	void	(*rotation)(t_lst*, t_lst*);
	int		bigest_one;
	int		flag;

	flag = 0;
	rotation = get_next_one(blst, &bigest_one);
	while (ft_get_nbr_element(blst))
	{
		if (blst->head->n == bigest_one)
		{
			add_op(ft_pa, alst, blst, ops);
			if (flag == 5 || flag == 6)
				add_op(ft_rra, alst, blst, ops);
			rotation = get_next_one(blst, &bigest_one);
			flag = 10;
		}
		else if (ft_opti_second_value(alst, blst, ops, &flag) != 0)
			;
		else
			add_op(rotation, alst, blst, ops);
	}
	return (0);
}
