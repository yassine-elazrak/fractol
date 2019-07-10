/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:57:11 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/10 16:34:14 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "libft/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <OpenCL/opencl.h>


# define  iteration_max 50;
# define  WIDTH 800
# define HEIGHT 800

typedef struct s_ab
{
	  double min;
	  double max;
}				t_ab;


typedef struct s_init
{
	int color;
	int clr;
	double  z;
	void	*ptr;
	void	*win;
	void	*img;
	int	*str_img;
	int r;
	int b;
	int g;

	t_ab	Re;
	t_ab 	Im;

	int			max;
  	double a;
  	double d;
	double stop;
  	int arg;
	  int q;
  	int move;

	double mouseIm;
	double mouseRe;
	double c_r;
  	double c_i;
char *name_of_fractol;
}				t_init;


typedef struct s_z
{
	  double x;
	  double y;
}				t_z;


typedef struct s_cl
{
	cl_context context;
    cl_command_queue queue;
    cl_int  i;
    cl_uint num_of_platform;
    cl_platform_id platform_id;
    cl_device_id  device_id;
    cl_uint   num_of_device;
    cl_mem  output;
    cl_mem  input;
	 cl_kernel kernel;
    int *buffer;
	cl_double *tab_2;
	cl_mem tab;
	cl_uint *ptr;
    cl_program  program;  
}					t_cl;


//void	ft_print(t_cor *lst,t_init *init);
int		get_key(int key,void *param);
int main_4(t_init *init);
int	ft_move(int x, int y, t_init *init);
//int		ft_rgb(int b,int g,int r);
int	mouse_press(int button,int x, int y, t_init *init);
void	ft_put_pixle(int x,int y,t_init *init);
int  ft_key(int key,t_init *init);
int kernel_2(t_init *init);




#endif
