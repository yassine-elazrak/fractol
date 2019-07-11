/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:43:34 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/09 18:48:16 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[0] != c && s[0] != '\0')
		j++;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				j++;
		}
		i++;
	}
	return (j);
}

static int	ft_len(char const *s, char c, int a)
{
	int i;

	i = 0;
	while (s[a] && s[a] != c)
	{
		a++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(t = (char **)malloc(sizeof(char *) * (word(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			l = ft_len(s, c, i);
			if (!(t[j++] = ft_strsub(s, i, l)))
				return (NULL);
			i += l;
		}
		else
			i++;
	}
	t[word(s, c)] = NULL;
	return (t);
}
