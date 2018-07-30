/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:17:07 by triou             #+#    #+#             */
/*   Updated: 2018/06/27 01:17:08 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	ft_lstrotrev(t_lst *lst)
{
	t_stack	*t;
	t_stack	*h;
	t_stack	*tmp;

	h = lst->head;
	t = lst->tail;
	if (h && h->prev)
	{
		tmp = t->next;
		t->next = NULL;
		tmp->prev = NULL;
		h->next = t;
		t->prev = h;
		lst->head = t;
		lst->tail = tmp;
	}
}
