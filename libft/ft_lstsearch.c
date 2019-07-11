/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:25:44 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/11 14:16:12 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstsearch(t_list **alst, t_list *data, int i)
{
	t_list	*temp;
	int		j;

	j = 1;
	temp = *alst;
	if (i == 0)
	{
		data->next = temp;
		*alst = data;
		return (*alst);
	}
	while (temp)
	{
		if (j == i)
		{
			data->next = temp->next;
			temp->next = data;
			return (*alst);
		}
		temp = temp->next;
		j++;
	}
	return (NULL);
}
