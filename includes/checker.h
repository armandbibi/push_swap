/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:03:53 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/20 17:04:36 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define TRUE		1
# define FALSE		0

typedef int			t_bool;

typedef	struct		s_stack {
	int				n;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_lst {
	t_stack			*head;
	t_stack			*tail;
}					t_lst;

typedef struct		s_nstrct {
	char			str[4];
	void			(*f)(t_lst *alst, t_lst *blst);
}					t_nstrct;

void				ft_puterr(void);
t_stack				*ft_create_elem(int n);
void				ft_readparams(int ac, char **av, int v, t_lst *alst);
void				ft_lstadd(t_lst *alst, int n);
void				ft_getargs(t_lst *alst, char *str);
t_bool				ft_isnumber(char *str);
void				ft_readstdn(t_lst *alst, t_lst *blst, t_bool v);
void				ft_dosort(char *line, t_lst *alst, t_lst *blst);
void				ft_lstprint(t_stack *alst, t_stack *blst);
void				ft_lstdel(t_stack *alst);
int					ft_atoi(const char *nptr);
void				ft_lstswap(t_stack *alst);
void				ft_lstpush(t_lst *dest, t_lst *src);
void				ft_lstrot(t_lst *lst);
void				ft_lstrotrev(t_lst *lst);
t_bool				ft_issort(t_stack *list);
void				ft_checkdb(t_stack *alst);
void				ft_sa(t_lst *alst, t_lst *blst);
void				ft_sb(t_lst *alst, t_lst *blst);
void				ft_ss(t_lst *alst, t_lst *blst);
void				ft_pa(t_lst *alst, t_lst *blst);
void				ft_pb(t_lst *alst, t_lst *blst);
void				ft_ra(t_lst *alst, t_lst *blst);
void				ft_rb(t_lst *alst, t_lst *blst);
void				ft_rr(t_lst *alst, t_lst *blst);
void				ft_rra(t_lst *alst, t_lst *blst);
void				ft_rrb(t_lst *alst, t_lst *blst);
void				ft_rrr(t_lst *alst, t_lst *blst);
#endif
