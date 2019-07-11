/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacetab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:08:04 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/10 17:02:20 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spacetab(char *s)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	j = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			j--;
		i++;
	}
	t = ft_strnew(j);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		else
			t[j++] = s[i++];
	}
	return (t);
}
