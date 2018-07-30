/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:51:31 by triou             #+#    #+#             */
/*   Updated: 2018/06/23 15:48:54 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

t_stack	*ft_create_elem(int n)
{
	t_stack	*elem;

	if (!(elem = (t_stack *)malloc(sizeof(*elem))))
		ft_puterr();
	elem->n = n;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}
