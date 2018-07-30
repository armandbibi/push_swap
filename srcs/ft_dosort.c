/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dosort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:30:48 by triou             #+#    #+#             */
/*   Updated: 2018/07/29 23:18:56 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

static inline void	ft_initab(t_nstrct tab[11])
{
	ft_strcpy(tab[0].str, "sa");
	ft_strcpy(tab[1].str, "sb");
	ft_strcpy(tab[2].str, "ss");
	ft_strcpy(tab[3].str, "pa");
	ft_strcpy(tab[4].str, "pb");
	ft_strcpy(tab[5].str, "ra");
	ft_strcpy(tab[6].str, "rb");
	ft_strcpy(tab[7].str, "rr");
	ft_strcpy(tab[8].str, "rra");
	ft_strcpy(tab[9].str, "rrb");
	ft_strcpy(tab[10].str, "rrr");
	tab[0].f = &ft_sa;
	tab[1].f = &ft_sb;
	tab[2].f = &ft_ss;
	tab[3].f = &ft_pa;
	tab[4].f = &ft_pb;
	tab[5].f = &ft_ra;
	tab[6].f = &ft_rb;
	tab[7].f = &ft_rr;
	tab[8].f = &ft_rra;
	tab[9].f = &ft_rrb;
	tab[10].f = &ft_rrr;
}

void				ft_dosort(char *line, t_lst *alst, t_lst *blst)
{
	t_nstrct	tab[11];
	int			i;

	ft_initab(tab);
	i = 0;
	while (i < 11)
	{
		if (ft_strequ(tab[i].str, line))
		{
			tab[i].f(alst, blst);
			return ;
		}
		i++;
	}
	ft_puterr();
}
