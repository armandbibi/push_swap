/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_past_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 02:36:03 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/18 15:18:07 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap_ab.h"
#include "libft.h"

static t_elem_op	*opti_s(t_elem_op *lst)
{
	t_elem_op	*tmp;
	t_elem_op	*tmp2;

	tmp2 = lst;
	tmp = lst->next;
	while (tmp && ((ft_strequ(lst->str, "sa") && (ft_strequ(tmp->str, "ra")
			|| ft_strequ(tmp->str, "rra"))) || (ft_strequ(lst->str, "sb")
			&& (ft_strequ(tmp->str, "rb") || ft_strequ(tmp->str, "rrb")))))
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp && ((ft_strequ(tmp->str, "sb") && ft_strequ(lst->str, "sa"))
				|| (ft_strequ(tmp->str, "sa") && ft_strequ(lst->str, "sb"))))
	{
		tmp2->next = tmp->next;
		ft_strcpy(lst->str, "ss");
		free(tmp);
	}
	return (lst->next);
}

static t_elem_op	*opti_r(t_elem_op *lst)
{
	t_elem_op	*tmp;
	t_elem_op	*tmp2;

	tmp2 = lst;
	tmp = lst->next;
	while (tmp && ((ft_strequ(lst->str, "ra") && (ft_strequ(tmp->str, "sa")
			|| ft_strequ(tmp->str, "rra"))) || (ft_strequ(lst->str, "rb")
			&& (ft_strequ(tmp->str, "sb") || ft_strequ(tmp->str, "rrb")))))
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp && ((ft_strequ(tmp->str, "rb") && ft_strequ(lst->str, "ra"))
				|| (ft_strequ(tmp->str, "ra") && ft_strequ(lst->str, "rb"))))
	{
		ft_strcpy(lst->str, "rr");
		tmp2->next = tmp->next;
		free(tmp);
	}
	return (lst->next);
}

static t_elem_op	*opti_rr(t_elem_op *lst)
{
	t_elem_op	*tmp;
	t_elem_op	*tmp2;

	tmp2 = lst;
	tmp = lst->next;
	while (tmp && ((ft_strequ(lst->str, "rra") && (ft_strequ(tmp->str, "sa")
			|| ft_strequ(tmp->str, "ra"))) || (ft_strequ(lst->str, "rrb")
			&& (ft_strequ(tmp->str, "sb") || ft_strequ(tmp->str, "rb")))))
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp && ((ft_strequ(tmp->str, "rrb") && ft_strequ(lst->str, "rra"))
				|| (ft_strequ(tmp->str, "rra") && ft_strequ(lst->str, "rrb"))))
	{
		ft_strcpy(lst->str, "rrr");
		tmp2->next = tmp->next;
		free(tmp);
	}
	return (lst->next);
}

void				last_optimizer(t_op *ops)
{
	t_elem_op *lst;

	lst = ops->head;
	while (lst && lst->next)
	{
		if (ft_strequ(lst->str, "sa") || ft_strequ(lst->str, "sb"))
			lst = opti_s(lst);
		else if (ft_strequ(lst->str, "ra") || ft_strequ(lst->str, "rb"))
			lst = opti_r(lst);
		else if (ft_strequ(lst->str, "rra") || ft_strequ(lst->str, "rrb"))
			lst = opti_rr(lst);
		else
			lst = lst->next;
	}
}
