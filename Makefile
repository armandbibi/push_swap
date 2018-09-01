# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 08:57:44 by abiestro          #+#    #+#              #
#    Updated: 2018/09/01 17:52:48 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra 
SDIR	= srcs
IDIR	= includes
ODIR	= objs
LDIR	= libft
LIB		= ft
ITEMS 	= ft_atoi \
		ft_puterr \
		ft_create_elem \
		ft_dosort \
		ft_getargs \
		ft_isnumber \
		ft_issort \
		ft_lstadd \
		ft_lstdel \
		ft_lstprint \
		ft_lstpush \
		ft_lstrot \
		ft_lstrotrev \
		ft_lstswap \
		ft_readparams \
		ft_readstdn \
		get_next_line \
		instructs \
		instructs2 \
		instructs3 \
		ft_checkdb \
		algo_fast_sort \
		ft_bubble_sort \
		quick_sort \
		ft_get_nbr_elements \
		ft_brut_force \
		ft_optimisation \
		opti_past_sort \
		ft_operator_controls

OBJS	= $(addprefix $(ODIR)/, $(ITEMS:=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -c srcs/push_swap.c -o objs/push_swap.o  -I $(IDIR) -I $(LDIR)
	$(CC) $(CFLAGS) -c srcs/checker.c -o objs/checker.o  -I $(IDIR) -I $(LDIR)
	@$(MAKE) -C $(LDIR)
	@$(CC) $(CFLAGS) -o checker $^ -L$(LDIR) -l$(LIB) objs/checker.o
	@echo "\033[1;34mChecker \033[1;35mhas been created \033[1;5;32msuccessfully.\033[0m"
	@$(CC) $(CFLAGS) -o push_swap $^  -L$(LDIR) -l$(LIB) objs/push_swap.o
	@echo "\033[1;34mChecker \033[1;35mhas been created \033[1;5;32msuccessfully.\033[0m"

$(OBJS) : | $(ODIR)

$(ODIR):
	mkdir $(ODIR)

$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(IDIR) -I$(LDIR)

clean :
	@$(MAKE) -C $(LDIR) clean
	@rm -rf $(ODIR)

fclean : clean
	@$(MAKE) -C $(LDIR) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
