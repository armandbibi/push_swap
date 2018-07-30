/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:56:49 by triou             #+#    #+#             */
/*   Updated: 2018/06/27 01:48:29 by triou            ###   ########.fr       */
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
