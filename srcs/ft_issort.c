/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:53:31 by abietro           #+#    #+#             */
/*   Updated: 2018/09/01 17:57:23 by abiestro         ###   ########.fr       */
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
