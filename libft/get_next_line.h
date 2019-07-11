/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 09:29:03 by yelazrak          #+#    #+#             */
/*   Updated: 2019/05/25 19:05:54 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 12

typedef struct		s_line
{
	int				fd;
	char			*str1;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);
#endif
