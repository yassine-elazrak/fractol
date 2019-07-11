/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:39:31 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/08 14:33:03 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*t;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s && f)
	{
		while (s[i])
			i++;
		if (!(t = (char *)malloc(sizeof(char) * (1 + i))))
			return (0);
		while (j < i)
		{
			t[j] = (*f)(*(s));
			j++;
			s++;
		}
		t[j] = '\0';
		return (t);
	}
	return (NULL);
}
