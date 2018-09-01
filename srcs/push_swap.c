/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:00:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/01 17:09:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap_ab.h"
#include "libft.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_lst		alst;
	t_lst		blst;
	t_bool		v;
	t_op		ops;

	blst.head = NULL;
	blst.tail = NULL;
	ops.head = NULL;
	if (ac < 2 || ((v = ft_strequ("-v", av[1])) && ac < 3))
		return (0);
	ft_readparams(ac, av, v + 1, &alst);
	if (ft_issort(alst.head))
		;
	else
		algo_fast_sort(&alst, &blst, &ops);
	ft_lstdel(alst.head);
	ft_lstdel(blst.head);
	return (0);
}
