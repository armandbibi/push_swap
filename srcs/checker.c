/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:51:25 by triou             #+#    #+#             */
/*   Updated: 2018/07/26 17:18:30 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap_ab.h"
#include "libft.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_lst	alst;
	t_lst	blst;
	t_bool	v;

	blst.head = NULL;
	blst.tail = NULL;
	if (ac < 2 || ((v = ft_strequ("-v", av[1])) && ac < 3))
		return (0);
	ft_readparams(ac, av, v + 1, &alst);
	ft_readstdn(&alst, &blst, v);
	if (!blst.head && ft_issort(alst.head))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lstdel(alst.head);
	ft_lstdel(blst.head);
	return (0);
}
