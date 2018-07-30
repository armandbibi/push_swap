/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:56:16 by abiestro          #+#    #+#             */
/*   Updated: 2018/07/30 04:05:06 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap_ab.h"
#include <unistd.h>
#include <stdlib.h>

char    *ft_strcpy(char *dest, const char *src)
{
	size_t  len;

	len = 0;
	while ((dest[len] = src[len]))
		len++;
	return (dest);
}

static void put_str_op(t_elem_op * ops, void (*operation)(t_lst *, t_lst *))
{
	if (operation == ft_sa)
		ft_strcpy(ops->str, "sa");
	else if (operation == ft_sb)
		ft_strcpy(ops->str, "sb");
	else if (operation == ft_ss)
		ft_strcpy(ops->str, "ss");
	else if (operation == ft_pa)
		ft_strcpy(ops->str, "pa");
	else if (operation == ft_pb)
		ft_strcpy(ops->str, "pb");
	else if (operation == ft_ra)
		ft_strcpy(ops->str, "ra");
	else if (operation == ft_rb)
		ft_strcpy(ops->str, "rb");
	else if (operation == ft_rr)
		ft_strcpy(ops->str, "rr");
	else if (operation == ft_rra)
		ft_strcpy(ops->str, "rra");
	else if (operation == ft_rrb)
		ft_strcpy(ops->str, "rrb");
	else if (operation == ft_rrr)
		ft_strcpy(ops->str, "rrr");
}

static t_op	*create_op(void (*operation)(t_lst *, t_lst *), t_op *op)
{
	t_elem_op	*new;
	t_elem_op	*current;

	if (!(new = malloc(sizeof(*new))))
		exit(-1);
	put_str_op(new, operation);
	new->next = NULL;
	if (op->head == NULL)
		op->head = new;
	else
	{
		current = op->head;
		while(current ->next)
			current = current->next;
		current->next = new;
	}
	return (0);
}


void		add_op(void (*operation)(t_lst*, t_lst*), t_lst *alst, t_lst *blst, t_op *opt)
{
	create_op(operation, opt);
	operation(alst, blst);
}


void	ft_show_operation(t_op *opt)
{
	t_elem_op *tmp;

	tmp = opt->head;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}
