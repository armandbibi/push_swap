/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:01:35 by triou             #+#    #+#             */
/*   Updated: 2018/09/01 17:50:44 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 666

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_line
{
	int				fd;
	char			*data;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
