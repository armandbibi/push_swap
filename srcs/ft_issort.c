/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:53:31 by triou             #+#    #+#             */
/*   Updated: 2018/06/25 16:23:19 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_bool	ft_issort(t_stack *list)
{
	t_stack	*prev;

	while ((prev = list->prev))
	{
		if (prev->n < list->n)
			return (FALSE);
		list = list->prev;
	}
	return (TRUE);
}
