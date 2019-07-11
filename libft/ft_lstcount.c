/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:20:35 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/09 21:06:13 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount(t_list *alst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = alst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
