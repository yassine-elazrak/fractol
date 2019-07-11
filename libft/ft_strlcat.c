/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:51:16 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/08 14:19:50 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t s;
	size_t d;
	size_t j;

	j = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = d;
	if (size <= d)
		s += size;
	else
	{
		while (i < (size - 1) && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		s += d;
	}
	return (s);
}
