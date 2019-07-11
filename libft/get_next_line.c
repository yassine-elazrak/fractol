/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:49:37 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/24 21:06:00 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_line		*ft_alstnew(int fd)
{
	t_line *new;

	new = (t_line *)malloc(sizeof(t_line));
	new->fd = fd;
	new->next = NULL;
	new->str1 = ft_strnew(0);
	return (new);
}

static t_line		*ft_search(t_line **alst, int fd)
{
	t_line *temp;
	t_line *new;

	temp = *alst;
	if (*alst)
	{
		while (temp)
		{
			if (temp->fd == fd)
				return (temp);
			temp = temp->next;
		}
		new = ft_alstnew(fd);
		new->next = *alst;
		*alst = new;
		return (*alst);
	}
	*alst = ft_alstnew(fd);
	new = *alst;
	return (*alst);
}

static int			ft_freeline(t_line **alst, char **line)
{
	t_line	*lst;
	int		k;
	char	*tmp;

	lst = *alst;
	k = 0;
	while ((lst)->str1[k] != '\n' && (lst)->str1[k] != '\0')
		k++;
	if (ft_strlen(lst->str1) != 0)
	{
		if ((lst)->str1[k] == '\0')
		{
			*line = ft_strdup(lst->str1);
			free(lst->str1);
			lst->str1 = ft_strnew(0);
			return (1);
		}
		tmp = lst->str1;
		*line = ft_strsub(lst->str1, 0, k);
		lst->str1 = ft_strdup(lst->str1 + k + 1);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static t_line	*temp;
	t_line			*alst;
	char			buff[BUFF_SIZE + 1];
	int				j;
	char			*tmp;

	alst = ft_search(&temp, fd);
	if (read(fd, buff, 0) < 0 || line == NULL)
		return (-1);
	while ((j = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[j] = '\0';
		tmp = alst->str1;
		alst->str1 = ft_strjoin(alst->str1, buff);
		ft_strdel(&tmp);
		if (ft_strchr((alst)->str1, '\n') != NULL)
			break ;
	}
	return (ft_freeline(&alst, line));
}
