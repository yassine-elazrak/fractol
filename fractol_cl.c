/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_cl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:35:35 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/11 15:35:04 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_01(t_cl *cl, t_init *init)
{
	cl->num_of_device = 0;
	cl->num_of_platform = 0;
	if (!(cl->buffer = (int *)malloc(sizeof(int) * 3)))
		return ;
	cl->buffer[0] = WIDTH;
	cl->buffer[1] = HEIGHT;
	cl->buffer[2] = init->max;
}

void			ft_imag_of_win(t_init *init, t_cl *cl)
{
	int			i;
	int			x;
	int			y;
	cl_uint		a;

	i = 0;
	x = 0;
	y = 0;
	a = 0;
	while (i < (WIDTH * HEIGHT))
	{
		a = cl->ptr[i];
		x = i % WIDTH;
		y = i / WIDTH;
		if ((int)a < init->max)
			init->str_img[x + y * WIDTH] = ft_rgb(255, 255, 255)
				* ((1 + cos(2 * (3.14) * a * init->q)) / 2);
		else
		{
			init->str_img[x + y * WIDTH] = ft_rgb(0, 0, 0);
		}
		i++;
	}
}

int				ft_platform_of_cl(t_cl *cl, t_init *init)
{
	int			i;
	char const	*t;

	ft_platform(cl);
	t = (const char *)ft_tab_2("tst");
	cl->context = clCreateContext(NULL, 1, &cl->device_id, NULL, NULL, &i);
	cl->queue = clCreateCommandQueue(cl->context, cl->device_id, 0, &i);
	cl->input = clCreateBuffer(cl->context,
			CL_MEM_READ_ONLY, sizeof(int) * 3, NULL, NULL);
	clEnqueueWriteBuffer(cl->queue, cl->input, CL_TRUE, 0,
			sizeof(int) * 3, cl->buffer, 0, NULL, NULL);
	cl->program = clCreateProgramWithSource(cl->context, 1, &t, NULL, &i);
	if (clBuildProgram(cl->program, 1, &cl->device_id,
				NULL, NULL, NULL) != CL_SUCCESS)
	{
		ft_putendl("error of COMPIL");
		return (1);
	}
	cl->kernel = clCreateKernel(cl->program, init->name_of_fractol, NULL);
	cl->output = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY,
			sizeof( double) * (WIDTH * HEIGHT), NULL, NULL);
	return (0);
}

void			ft_set_arg_of_kernel(t_cl *cl, t_init *init)
{
	clSetKernelArg(cl->kernel, 0, sizeof(cl->output), (void*)&cl->output);
	clSetKernelArg(cl->kernel, 1, sizeof(cl->input), (void*)&cl->input);
	clSetKernelArg(cl->kernel, 2, sizeof( double), &init->re.min);
	clSetKernelArg(cl->kernel, 3, sizeof( double), &init->re.max);
	clSetKernelArg(cl->kernel, 4, sizeof( double), &init->im.min);
	clSetKernelArg(cl->kernel, 5, sizeof( double), &init->im.max);
	if (ft_strcmp(init->name_of_fractol, "julia") == 0)
	{
		clSetKernelArg(cl->kernel, 6, sizeof( double), &init->c_r);
		clSetKernelArg(cl->kernel, 7, sizeof( double), &init->c_i);
	}
}

int				main_4(t_init *init)
{
	t_cl		*cl;
	size_t		global_work_size;

	if (!(cl = (t_cl *)malloc(sizeof(t_cl))))
		return (0);
	init->cl = cl;
	global_work_size = WIDTH * HEIGHT;
	ft_01(cl, init);
	ft_platform_of_cl(cl, init);
	ft_set_arg_of_kernel(cl, init);
	clEnqueueNDRangeKernel(cl->queue, cl->kernel, 1, NULL,
			&global_work_size, NULL, 0, NULL, NULL);
	clFinish(cl->queue);
	cl->ptr = (cl_uint *)clEnqueueMapBuffer(cl->queue, cl->output, CL_TRUE,
			CL_MAP_READ, 0, (WIDTH * HEIGHT) * sizeof(cl_uint),
			0, NULL, NULL, NULL);
	ft_imag_of_win(init, cl);
	clReleaseContext(cl->context);
	clReleaseProgram(cl->program);
	clReleaseCommandQueue(cl->queue);
	clReleaseMemObject(cl->output);
	clReleaseMemObject(cl->input);
	clReleaseKernel(cl->kernel);
	return (0);
}
