/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:20:56 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/11 19:46:18 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_rempli(char *t, int i, unsigned int r, int x)
{
	unsigned int n;

	n = r;
	i--;
	while (i >= x)
	{
		t[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (t);
}

char			*ft_itoa(int a)
{
	char			*t;
	int				i;
	int				x;
	unsigned int	n;

	i = 0;
	x = (a < 0) ? 1 : 0;
	if (a == 0)
		return (ft_strdup("0"));
	if (a < 0)
	{
		n = a * -1;
		i = len(n) + 1;
		if (!(t = ft_strnew(i)))
			return (0);
		t[0] = '-';
	}
	else
	{
		n = a;
		i = len(n);
		if (!(t = ft_strnew(i)))
			return (0);
	}
	return (ft_rempli(t, i, n, x));
}
