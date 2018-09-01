/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:13:22 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/27 02:16:15 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	ft_lstpush(t_lst *dest, t_lst *src)
{
	t_stack	*d;
	t_stack	*s;
	t_stack	*tmp;

	d = dest->head;
	if ((s = src->head))
	{
		if ((tmp = s->prev))
			tmp->next = NULL;
		if ((s->prev = d))
			d->next = s;
		dest->head = s;
		src->head = tmp;
		if (!s->prev)
			dest->tail = dest->head;
		if (!tmp)
			src->tail = NULL;
	}
}
