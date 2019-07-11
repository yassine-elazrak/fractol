/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:45:01 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/11 15:43:55 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char			*ft_tab_2(char *name)
{
	char		*line;
	int			fd;
	char		*str;
	char		*tmp;

	str = ft_strnew(0);
	if ((0 > (fd = open(name, O_RDONLY))))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
	}
	close(fd);
	return (str);
}

int				ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned char	color[4];

	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = 0;
	return (*(int *)color);
}

void			ft_00(t_init *init)
{
	init->z = 1;
	init->re.max = 2;
	init->re.min = -2;
	init->im.max = 2;
	init->im.min = -2;
	init->max = 30;
	init->a = 0;
	init->b = 0;
	init->c_r = 0;
	init->c_i = 0;
	init->mouseim = 0;
	init->mousere = 0;
	init->arg = 0;
	init->stop = 2;
	init->q = 11;
}

int				ft_get_name_of_fractal(char *name, int argc, t_init *init)
{
	if (ft_strcmp(name, "mandlebrot") == 0 && argc == 2)
		init->name_of_fractol = ft_strdup("mandlebrot");
	else if (ft_strcmp(name, "julia") == 0 && argc == 2)
		init->name_of_fractol = ft_strdup("julia");
	else if (ft_strcmp(name, "burning_ship") == 0 && argc == 2)
		init->name_of_fractol = ft_strdup("burning_ship");
	else
	{
		ft_putendl("usage:");
		ft_putendl("                  mandlebrot");
		ft_putendl("                  julia");
		ft_putendl("                  burning_ship");
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	int				s_l;
	int				bpp;
	int				end;
	t_init			*init;

	if (argc != 2)
		return (0);
	if (!(init = (t_init *)malloc(sizeof(t_init))))
		exit(0);
	ft_00(init);
	if ((ft_get_name_of_fractal(argv[1], argc, init) == 0))
		return (0);
	init->ptr = mlx_init();
	init->win = mlx_new_window(init->ptr, WIDTH, HEIGHT, "fractol");
	init->img = mlx_new_image(init->ptr, WIDTH, HEIGHT);
	init->str_img = (int*)mlx_get_data_addr(init->img, &bpp, &s_l, &end);
	main_4(init);
	mlx_put_image_to_window(init->ptr, init->win, init->img, 0, 0);
	mlx_hook(init->win, 2, 0, ft_key, init);
	mlx_hook(init->win, 6, 0, ft_move, init);
	mlx_mouse_hook(init->win, mouse_press, init);
	mlx_loop(init->ptr);
	return (0);
}
