/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:01:12 by triou             #+#    #+#             */
/*   Updated: 2018/07/30 05:19:50 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	ft_lstrot(t_lst *lst)
{
	t_stack	*t;
	t_stack	*h;
	t_stack	*tmp;

	h = lst->head;
	t = lst->tail;
	if (h && h->prev)
	{
		tmp = h->prev;
		tmp->next = NULL;
		h->prev = NULL;
		h->next = t;
		t->prev = h;
		lst->head = tmp;
		lst->tail = h;
	}
}
