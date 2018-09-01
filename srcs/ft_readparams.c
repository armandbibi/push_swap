/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readparams.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:52:17 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/27 01:53:42 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_readparams(int ac, char **av, int v, t_lst *alst)
{
	t_bool	option;

	alst->tail = NULL;
	alst->head = NULL;
	option = v - 1;
	while (v < ac)
	{
		ft_getargs(alst, av[v]);
		v++;
	}
	ft_checkdb(alst->head);
	if (option)
		ft_lstprint(alst->head, NULL);
}
