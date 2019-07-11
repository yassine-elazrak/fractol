/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:39:01 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/22 18:09:51 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*to_del;

	temp = *alst;
	while (temp)
	{
		del(temp->content, temp->content_size);
		to_del = temp;
		temp = temp->next;
		free(to_del);
	}
	*alst = NULL;
}
