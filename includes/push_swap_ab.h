/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ab.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 03:30:10 by abiestro          #+#    #+#             */
/*   Updated: 2018/07/30 02:42:17 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_AB_H
# define PUSH_SWAP_AB_H
#include <stdio.h>

typedef struct	s_elem_op
{
	char str[8];
	struct s_elem_op *next;
}				t_elem_op;

typedef struct	s_op
{
	t_elem_op	*head;
}				t_op;

void    ft_show_operation(t_op *opt);
void    add_op(void (*operation)(t_lst*, t_lst*), t_lst *alst, t_lst *blst, t_op *opt);
void    algo_fast_sort(t_lst *alst, t_lst *blst, t_op *ops);
int		ft_bubble_sort(t_lst *alst, t_lst *blst, t_op *ops);
int		ft_algo_sort_ten(t_lst *alst, t_lst *blst);
int		ft_small_sort(t_lst *alst, t_lst *blst, t_op *ops);
int		ft_get_nbr_element(t_lst *alst);
int		ft_getmed(size_t count, t_stack *list, int rank);
int		ft_opti_bubble(t_lst *alst, t_lst *blst, void (*rotate)(t_lst*, t_lst*), int sizepack, t_op *opt);
void    last_optimizer(t_op *ops);
#endif
