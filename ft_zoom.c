/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:50:57 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/11 12:42:18 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_change(t_init *init)
{
	mlx_clear_window(init->ptr, init->win);
	ft_bzero(init->str_img, 4 * HEIGHT * WIDTH);
	main_4(init);
	mlx_put_image_to_window(init->ptr, init->win, init->img, 0, 0);
}

double		ft_zoom(double a, double b, double k)
{
	return (a + ((b - a) * k));
}

void		ft_displyzoom(t_init *init, double zoom)
{
	init->re.min = ft_zoom(init->mousere, init->re.min, zoom);
	init->im.min = ft_zoom(init->mouseim, init->im.min, zoom);
	init->re.max = ft_zoom(init->mousere, init->re.max, zoom);
	init->im.max = ft_zoom(init->mouseim, init->im.max, zoom);
}

int			mouse_press(int button, int x, int y, t_init *init)
{
	init->mousere = x / (WIDTH / (init->re.max - init->re.min)) + init->re.min;
	init->mouseim = y / (HEIGHT / (init->im.max - init->im.min)) + init->im.min;
	if (button == 5)
	{
		init->max += 1;
		ft_displyzoom(init, 0.9);
		ft_change(init);
		return (0);
	}
	if (button == 4)
	{
		if (init->max > 30)
			init->max -= 1;
		ft_displyzoom(init, 1 / 0.9);
		ft_change(init);
		return (0);
	}
	return (0);
}

int			ft_move(int x, int y, t_init *init)
{
	if (init->stop == 0)
		return (0);
	init->c_i = y / (HEIGHT / (init->im.max - init->im.min)) + init->im.min;
	init->c_r = x / (WIDTH / (init->re.max - init->re.min)) + init->re.min;
	ft_change(init);
	return (0);
}
