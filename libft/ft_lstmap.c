/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:08:50 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/08 14:13:52 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*temp;
	t_list	*temp2;

	if (!lst || !f)
		return (NULL);
	temp = lst;
	list = f(lst);
	temp2 = list;
	while (temp->next)
	{
		temp2->next = f(temp->next);
		temp2 = temp2->next;
		temp = temp->next;
	}
	return (list);
}
