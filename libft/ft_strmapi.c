/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:25:01 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/08 12:06:40 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *p, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*t;
	char			*s;

	s = (char *)p;
	i = 0;
	if (p && f)
	{
		if (!(t = ft_strdup(s)))
			return (NULL);
		while (t[i])
		{
			t[i] = f(i, t[i]);
			i++;
		}
		return (t);
	}
	return (NULL);
}
