/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:00:04 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/25 14:06:12 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dst;

	if (!(dst = ft_strnew(ft_strlen(s))))
		return (0);
	ft_strcpy(dst, s);
	return (dst);
}
