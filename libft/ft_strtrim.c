/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:47:20 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/09 18:47:45 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while ((s[j - 1] == '\t' || s[j - 1] == '\n' || s[j - 1] == ' '))
	{
		j--;
	}
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
	{
		j--;
		i++;
	}
	if (j <= 0)
		j = 0;
	t = ft_strsub(s, i, j);
	return (t);
}
