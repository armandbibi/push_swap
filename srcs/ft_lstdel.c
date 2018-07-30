/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:35:28 by triou             #+#    #+#             */
/*   Updated: 2018/06/25 13:37:46 by triou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	ft_lstdel(t_stack *alst)
{
	t_stack	*tmp;

	while (alst)
	{
		tmp = alst;
		alst = alst->prev;
		free(tmp);
	}
}
