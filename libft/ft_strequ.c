/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:56:49 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/08 14:23:11 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s2) <= ft_strlen(s1) ? ft_strlen(s1) : ft_strlen(s2);
	if (ft_strncmp(s1, s2, i) == 0)
		return (1);
	return (0);
}
