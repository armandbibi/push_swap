/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:46:49 by triou             #+#    #+#             */
/*   Updated: 2018/06/27 02:02:04 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstadd(t_lst *alst, int n)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!alst->tail)
	{
		alst->head = ft_create_elem(n);
		alst->tail = alst->head;
		return ;
	}
	tmp = alst->tail;
	new = ft_create_elem(n);
	new->next = tmp;
	tmp->prev = new;
	alst->tail = new;
}
