/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:45:47 by yelazrak          #+#    #+#             */
/*   Updated: 2019/03/31 15:47:58 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char			*src;
	unsigned char	a;

	src = (char *)str;
	a = (unsigned char)c;
	while (n--)
	{
		*src++ = a;
	}
	return (str);
}
