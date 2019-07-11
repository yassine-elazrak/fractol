/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:38:49 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/11 12:51:49 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_info_key_1(int s, t_init *lst)
{
	if (s == 125)
	{
		lst->im.min -= ((lst->im.max - lst->im.min) / 100);
		lst->im.max -= ((lst->im.max - lst->im.min) / 100);
	}
	else if (s == 126)
	{
		lst->im.max += ((lst->im.max - lst->im.min) / 100);
		lst->im.min += ((lst->im.max - lst->im.min) / 100);
	}
	else if (s == 34)
		lst->stop = 2;
	else if (s == 35)
		lst->stop = 0;
	else
	{
		return (0);
	}
	return (1);
}

int		ft_info_key_2(int s, t_init *lst)
{
	if (s == 123)
	{
		lst->re.max += ((lst->im.max - lst->im.min) / 100);
		lst->re.min += ((lst->im.max - lst->im.min) / 100);
	}
	else if (s == 12)
		lst->q += 2;
	else if (s == 124)
	{
		lst->re.min -= ((lst->im.max - lst->im.min) / 100);
		lst->re.max -= ((lst->im.max - lst->im.min) / 100);
	}
	else
		return (0);
	return (1);
}

int		ft_key(int key, t_init *init)
{
	if (key == 53)
	{
		mlx_destroy_window(init->ptr, init->win);
		mlx_destroy_image(init->ptr, init->img);
		free(init->cl->buffer);
		free(init->cl);
		free(init);
		exit(1);
	}
	if (ft_info_key_1(key, init) || ft_info_key_2(key, init))
		ft_change(init);
	return (0);
}
