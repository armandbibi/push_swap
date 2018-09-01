/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readstdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:50:59 by triou             #+#    #+#             */
/*   Updated: 2018/09/01 17:28:18 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"

void	ft_readstdn(t_lst *alst, t_lst *blst, t_bool v)
{
	char	*line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line))
	{
		ft_dosort(line, alst, blst);
		if (v)
			ft_lstprint(alst->head, blst->head);
		free(line);
		line = NULL;
	}
	free(line);
}
