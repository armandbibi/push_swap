/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:51:11 by triou             #+#    #+#             */
/*   Updated: 2018/06/27 01:08:56 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_lst *alst, t_lst *blst)
{
	(void)blst;
	ft_lstrot(alst);
}

void	ft_rb(t_lst *alst, t_lst *blst)
{
	(void)alst;
	ft_lstrot(blst);
}

void	ft_rr(t_lst *alst, t_lst *blst)
{
	ft_lstrot(alst);
	ft_lstrot(blst);
}

void	ft_rra(t_lst *alst, t_lst *blst)
{
	(void)blst;
	ft_lstrotrev(alst);
}

void	ft_rrb(t_lst *alst, t_lst *blst)
{
	(void)alst;
	ft_lstrotrev(blst);
}
