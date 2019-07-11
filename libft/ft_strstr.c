/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:00:48 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/08 18:43:50 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s2 == '\0');
}

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*s;

	s = (char *)s1;
	if (ft_strcmp(s2, "") == 0)
		return (s);
	while (*s)
	{
		if (*s == *s2 && cmp(s, s2))
			return (s);
		s++;
	}
	return (0);
}
