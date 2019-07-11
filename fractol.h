/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:57:11 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/11 15:21:37 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <OpenCL/opencl.h>

# define WIDTH 1600
# define HEIGHT 1600

typedef struct			s_cl
{
	cl_context			context;
	cl_command_queue	queue;
	cl_int				i;
	cl_uint				num_of_platform;
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_uint				num_of_device;
	cl_mem				output;
	cl_mem				input;
	cl_kernel			kernel;
	int					*buffer;
	cl_uint				*ptr;
	cl_program			program;
}						t_cl;

typedef struct			s_ab
{
	double				min;
	double				max;
}						t_ab;

typedef struct			s_init
{
	int					color;
	int					clr;
	double				z;
	void				*ptr;
	void				*win;
	void				*img;
	int					*str_img;
	int					r;
	int					b;
	int					g;
	t_ab				re;
	t_ab				im;
	int					max;
	double				a;
	double				d;
	double				stop;
	int					arg;
	int					q;
	int					move;
	double				mouseim;
	double				mousere;
	double				c_r;
	double				c_i;
	t_cl				*cl;
	char				*name_of_fractol;
}						t_init;

int						get_key(int key, void *param);
int						main_4(t_init *init);
int						ft_move(int x, int y, t_init *init);
int						ft_rgb(unsigned char r, unsigned char g,
						unsigned char b);
int						mouse_press(int button, int x, int y, t_init *init);
void					ft_put_pixle(int x, int y, t_init *init);
int						ft_key(int key, t_init *init);
int						kernel_2(t_init *init);
char					*ft_tab_2(char *name);
void					ft_change(t_init *init);
int						ft_platform(t_cl *cl);

#endif
