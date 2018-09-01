/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:38:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/27 00:44:30 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_lst *alst, t_lst *blst)
{
	(void)blst;
	ft_lstswap(alst->head);
}

void	ft_sb(t_lst *alst, t_lst *blst)
{
	(void)alst;
	ft_lstswap(blst->head);
}

void	ft_ss(t_lst *alst, t_lst *blst)
{
	ft_lstswap(alst->head);
	ft_lstswap(blst->head);
}

void	ft_pa(t_lst *alst, t_lst *blst)
{
	ft_lstpush(alst, blst);
}

void	ft_pb(t_lst *alst, t_lst *blst)
{
	ft_lstpush(blst, alst);
}
