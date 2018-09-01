/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:42:53 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/25 15:47:45 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	ft_lstprint(t_stack *alst, t_stack *blst)
{
	ft_putstr("A => ");
	while (alst)
	{
		ft_putnbr(alst->n);
		ft_putchar(' ');
		alst = alst->prev;
	}
	ft_putstr("\nB => ");
	while (blst)
	{
		ft_putnbr(blst->n);
		ft_putchar(' ');
		blst = blst->prev;
	}
	ft_putchar('\n');
}
