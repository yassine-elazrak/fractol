/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:29 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/11 00:08:52 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_tab1(char **t)
{
	char	*p;
	int		i;
	int		j;
	int		a;

	i = 0;
	j = 0;
	while (t[i])
		j += ft_strlen(t[i++]);
	p = ft_strnew(j);
	i = 0;
	j = 0;
	while (t[i])
	{
		a = ft_strlen(t[i]);
		ft_memcpy(p + j, t[i], a);
		j += a;
		i++;
	}
	return (p);
}
