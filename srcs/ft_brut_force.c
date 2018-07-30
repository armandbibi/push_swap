/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brut_force.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:47:27 by abiestro          #+#    #+#             */
/*   Updated: 2018/07/30 07:09:08 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap_ab.h"

static void		*get_next_one(t_lst *blst, int *big)
{
	int			i;
	int			rank;
	int			max;
	t_stack		*tmp;

	i = 0;
	rank = 0;
	tmp = blst->head;
	max = 0;
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
	if (rank > ft_getmed(ft_get_nbr_element(blst),
				blst->head, ft_get_nbr_element(blst) / 2))
		return (ft_rrb);
	else
		return (ft_rb);
}

int				ft_small_sort(t_lst *alst, t_lst *blst, t_op *ops)
{
	void	(*rotation)(t_lst*, t_lst*);
	int		bigest_one;

	rotation = get_next_one(blst, &bigest_one);
	while (ft_get_nbr_element(blst))
	{
		if (blst->head->n == bigest_one)
		{
			add_op(ft_pa, alst, blst, ops);
			rotation = get_next_one(blst, &bigest_one);
		}
		else
			add_op(rotation, alst, blst, ops);
	}
	return (0);
}
