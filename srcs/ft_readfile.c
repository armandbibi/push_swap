/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:36:38 by triou             #+#    #+#             */
/*   Updated: 2018/07/29 23:07:42 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "checker.h"

void	ft_init_instructs(char tab[11])
{
	ft_init_str(tab[0].str, "sa");
	ft_init_str(tab[1].str, "sb");
	ft_init_str(tab[2].str, "ss");
	ft_init_str(tab[3].str, "pa");
	ft_init_str(tab[4].str, "pb");
	ft_init_str(tab[5].str, "ra");
	ft_init_str(tab[6].str, "rb");
	ft_init_str(tab[7].str, "rr");
	ft_init_str(tab[8].str, "rra");
	ft_init_str(tab[9].str, "rrb");
	ft_init_str(tab[10].str, "rrr");
}

t_bool	ft_readfile(char **av)
{
	int				fd;
	char			*line;
	t_instruct		tab[11];

	if (!(fd = open(argv[1 + VERBOSE], O_RDONLY)))
		return (FALSE);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		;
	}
}
