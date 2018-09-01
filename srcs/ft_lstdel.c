/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:35:28 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/25 13:37:46 by abiestro         ###   ########.fr       */
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
