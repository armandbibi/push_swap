/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:56:49 by abietro           #+#    #+#             */
/*   Updated: 2018/09/01 17:55:20 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void		ft_getargs(t_lst *alst, char *str)
{
	char	**tab;
	char	**cpy;

	if (!(tab = ft_strsplit(str, ' ')))
		ft_puterr();
	cpy = tab;
	while (*tab)
	{
		if (!ft_isnumber(*tab))
			ft_puterr();
		ft_lstadd(alst, ft_atoi(*tab));
		free(*tab);
		tab++;
	}
	free(cpy);
}
