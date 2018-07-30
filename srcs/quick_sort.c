/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:54:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/07/29 23:01:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <sys/types.h>

static inline void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static size_t		ft_partition(int *tab, ssize_t start, ssize_t end)
{
	int		pivot;
	ssize_t	tmp;
	ssize_t	i;

	pivot = tab[end];
	i = start;
	tmp = start;
	while (i < end)
	{
		if (tab[i] < pivot)
		{
			ft_swap(&tab[i], &tab[tmp]);
			tmp++;
		}
		i++;
	}
	if (tab[tmp] > pivot)
		ft_swap(&tab[end], &tab[tmp]);
	return (tmp);
}

static void			ft_quicksort(int *tab, ssize_t start, ssize_t end)
{
	size_t	index;

	if (end <= start)
		return ;
	index = ft_partition(tab, start, end);
	ft_quicksort(tab, start, index - 1);
	ft_quicksort(tab, index + 1, end);
}

int					ft_getmed(size_t count, t_stack *list, int rank)
{
	int *tab;
	int	i;
	int	med;

	if (rank > (int)count || rank < 0)
		return (-1);
	if (!(tab = (int *)malloc(count * sizeof(*tab))))
		ft_puterr();
	i = 0;
	while (list)
	{
		tab[i] = list->n;
		list = list->prev;
		i++;
	}
	ft_quicksort(tab, 0, count - 1);
	med = tab[rank];
	free(tab);
	return (med);
}
