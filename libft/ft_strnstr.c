/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:01:36 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/08 14:20:45 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s, const char *s2, size_t n)
{
	char	*s1;
	size_t	i;

	s1 = (char *)s;
	i = ft_strlen(s2);
	if (ft_strcmp(s2, "") == 0)
		return (s1);
	while (n > 0 && *s1 && n >= i)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, i) == 0)
		{
			return (s1);
		}
		s1++;
		n--;
	}
	return (0);
}
