/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:15:26 by abiestro          #+#    #+#             */
/*   Updated: 2018/07/30 00:39:47 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap_ab.h"

int		ft_opti_bubble(t_lst *alst, t_lst *blst,
		void (*rotate)(t_lst*, t_lst *), int sizepack, t_op *opt)
{
	int bsize;

	bsize = ft_get_nbr_element(blst);
	if (bsize > 3 && blst->head->n > sizepack)
	{
		if (rotate == ft_ra)
			add_op(ft_rr, alst, blst, opt);
		else
			add_op(ft_rb, alst, blst, opt);
		return (0);
	}
	return (1);
}
