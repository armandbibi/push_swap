/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 21:14:05 by abiestro          #+#    #+#             */
/*   Updated: 2018/07/29 23:23:58 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_get_nbr_element(t_lst *alst)
{
	t_stack		*tmp;
	int			compteur;

	compteur = 0;
	tmp = alst->head;
	while (tmp)
	{
		tmp = tmp->prev;
		compteur++;
	}
	return (compteur);
}
