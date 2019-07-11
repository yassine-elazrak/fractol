/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:56:16 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/06 14:46:42 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char *dst;
	char *src;

	dst = (char *)s1;
	src = (char *)s2;
	if (dst > src)
	{
		while (n--)
		{
			dst[n] = src[n];
		}
	}
	else
		ft_memcpy(s1, s2, n);
	return (dst);
}
